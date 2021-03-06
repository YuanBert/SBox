
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  ** This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether 
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * COPYRIGHT(c) 2018 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_hal.h"
#include "can.h"
#include "tim.h"
#include "gpio.h"

/* USER CODE BEGIN Includes */
#include "adc.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
#define MQ_ALARM_VALUE    1228
uint8_t gCanBroadcastFrameFlag;
uint8_t CanFlag;
uint8_t CAN_DATA0,CAN_DATA1,CAN_DATA2,CAN_DATA3,CAN_DATA4,CAN_DATA5,CAN_DATA6,CAN_DATA7;//数据
uint8_t tim4Flag;
uint16_t tim4Cnt;
uint8_t MQALARMBUF[3] = {0xA3,0x00,0x00};

uint8_t tim5Flag;
uint16_t tim5Cnt;
uint16_t MQ_AD_Value = 0;
uint16_t Tempture_Value = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_NVIC_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
   uint8_t IData[7] = {0};
   uint8_t AckData[8] = {0};
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  
  /* Initialize interrupts */
  MX_NVIC_Init();
  /* USER CODE BEGIN 2 */
  CANInit();
  BSP_LOCKInit();
  HAL_TIM_Base_Start_IT(&htim4);
  HAL_TIM_Base_Start_IT(&htim5);
  
  gCanBroadcastFrameFlag = 0;
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */
     if(MQ_AD_Value > MQ_ALARM_VALUE)
     {
       MQALARMBUF[1] = MQ_AD_Value >> 8;
       MQALARMBUF[2] = MQ_AD_Value;
       CanWriteData(CANID, MQALARMBUF, 3);
       MQ_AD_Value = 0;
     }
     /* 处理广播指令 */
    if(1 == gCanBroadcastFrameFlag)
    {
      gCanBroadcastFrameFlag = 0;
      IData[4] = 0xFF;
      IData[5] = 0xFF;
      IData[6] = 0xFF;
      CanWriteData(CANID, IData, 7);
    }
  
  /* 对接收到的数据进行处理 */
    if(1 == CanFlag)
    {
      CanFlag = 0;
      if(0 == CAN_DATA0)
      {
        BSP_LOCKWriteCtrlBuffer(CAN_DATA0,CAN_DATA1,CAN_DATA2,CAN_DATA3,CAN_DATA4);
        CAN_DATA0 = 0;
        CAN_DATA1 = 0;
        CAN_DATA2 = 0;
        CAN_DATA3 = 0;
        CAN_DATA4 = 0;
        BSP_LOCKCheckCtrlBuffer();
      }
      if(0xA2 == CAN_DATA0)
      {
          if(0x0A == CAN_DATA1)
          {
            HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8|GPIO_PIN_10,GPIO_PIN_SET);
          }
          else if(0x0B == CAN_DATA1)
          {
            HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8|GPIO_PIN_10,GPIO_PIN_RESET);
          }
          AckData[0] = 0xAA;
          CanWriteData(CANID,AckData,1);
          CAN_DATA0 = 0;
          CAN_DATA1 = 0;
          AckData[0] = 0;
      }
    }  
   
    /* 检测储物以及锁的状态时候有更新，并进行上报状态的改变 */
    BSP_LOCKUpdateOfGoodsState();
    BSP_LOCKSendGoodsChangedMessage();
    BSP_LOCKUpdateOfLockPinsState();
    BSP_LOCKSendPinsChangedMessage();
    
    
    /* 定时器4处理 */
    if(tim4Flag)
    {
      tim4Flag = 0;
//      BSP_LOCKUpdateOfGoodsState();
//      BSP_LOCKSendGoodsChangedMessage();
//      BSP_LOCKUpdateOfLockPinsState();
//      BSP_LOCKSendPinsChangedMessage();
    }
    
    if(1 == tim5Flag)
    {
      tim5Flag = 0;
  //    IData[4] = 0xFF;
  //    IData[5] = 0xFF;
  //    IData[6] = 0xFF;
  //    CanWriteData(CANID, IData, 7);
          /*  获取ID*/
  //		CANID = 0;
  //		if(GPIO_PIN_SET == GetAddrBit3Val)
  //		{
  //			CANID |= 0x08;
  //		}
  //		if(GPIO_PIN_SET == GetAddrBit2Val)
  //		{
  //			CANID |= 0x04;
  //		}
  //		if(GPIO_PIN_SET == GetAddrBit1Val)
  //		{
  //			CANID |= 0x02;
  //		}
  //		if(GPIO_PIN_SET == GetAddrBit0Val)
  //		{
  //			CANID |= 0x01;
  //		}
      /* 获取烟雾报警器的数值 */
//      MQALARMBUF[1] = MQ_AD_Value >> 8;
//      MQALARMBUF[2] = MQ_AD_Value;
//      CanWriteData(CANID, MQALARMBUF, 3);
      /* 震动报警 */
//      MQALARMBUF[0] = 0xA4;
//      MQALARMBUF[1] = MQ_AD_Value >> 8;
//      MQALARMBUF[2] = MQ_AD_Value;
//      CanWriteData(CANID, MQALARMBUF, 3);
      
      HAL_ADC_Start(&hadc2);
      HAL_ADC_PollForConversion(&hadc2,50);
      if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc2),HAL_ADC_STATE_REG_EOC))
      {
        MQ_AD_Value = HAL_ADC_GetValue(&hadc2);
      }
      /* 温度传感器的数值 */
      HAL_ADC_Start(&hadc1);
      HAL_ADC_PollForConversion(&hadc1,50);
      if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1),HAL_ADC_STATE_REG_EOC))
      {
        Tempture_Value = HAL_ADC_GetValue(&hadc1);
      }
      
    }  
  
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;
  
    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }
    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/**
  * @brief NVIC Configuration.
  * @retval None
  */
static void MX_NVIC_Init(void)
{
  /* USB_LP_CAN1_RX0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(USB_LP_CAN1_RX0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USB_LP_CAN1_RX0_IRQn);
  /* TIM4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(TIM4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(TIM4_IRQn);
  /* TIM5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(TIM5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(TIM5_IRQn);
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(htim);
  /* NOTE : This function Should not be modified, when the callback is needed,
            the __HAL_TIM_PeriodElapsedCallback could be implemented in the user file
   */
	if(htim4.Instance == htim->Instance)
	{
		tim4Cnt++;
		if(tim4Cnt > 499)
		{
			tim4Flag = 1;
			tim4Cnt = 0;
		}
	}
	
	if(htim5.Instance == htim->Instance)
	{
		tim5Cnt++;
		if(tim5Cnt > 99)
		{
			tim5Flag = 1;
			tim5Cnt = 0;
		}
	}
	
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
