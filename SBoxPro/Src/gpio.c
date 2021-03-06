/**
  ******************************************************************************
  * File Name          : gpio.c
  * Description        : This file provides code for the configuration
  *                      of all used GPIO pins.
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
#include "gpio.h"
/* USER CODE BEGIN 0 */
#define NEWVERSION 1
#include "can.h"
extern uint8_t CANID;

static uint8_t NeedHandBufferFlag;

uint8_t CtrlBuffer[23][5]= {0};

static uint8_t LockGoodsStateChangedBuffer[23][2] = {0};
static uint8_t LockPinsStateChangedBuffer[23][2] = {0};

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, LOCK_CTRL11_Pin|LOCK_CTRL1_Pin|LOCK_CTRL12_Pin|LOCK_CTRL13_Pin 
                          |LOCK_CTRL14_Pin, GPIO_PIN_SET);
   HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8|GPIO_PIN_10,GPIO_PIN_RESET);
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, LOCK_CTRL10_Pin|LOCK_CTRL9_Pin|LOCK_CTRL8_Pin|LOCK_CTRL3_Pin 
                          |LOCK_CTRL22_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LOCK_CTRL7_Pin|LOCK_CTRL6_Pin|LOCK_CTRL4_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LOCK_CTRL5_GPIO_Port, LOCK_CTRL5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LOCK_CTRL2_Pin|LOCK_CTRL15_Pin|LOCK_CTRL16_Pin|LOCK_CTRL17_Pin 
                          |LED1_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, LOCK_CTRL18_Pin|LOCK_CTRL19_Pin|LOCK_CTRL20_Pin|LOCK_CTRL21_Pin, GPIO_PIN_SET);

  /*Configure GPIO pins : PEPin PEPin PEPin PEPin 
                           PEPin PEPin PEPin PEPin 
                           PEPin PEPin */
  GPIO_InitStruct.Pin = LOCK_ADDR4_Pin|LOCK_ADDR3_Pin|LOCK_ADDR2_Pin|LOCK_ADDR1_Pin|LOCK_ADDR0_Pin 
                          |LOCK_STATE2_Pin|LOCK_STATE1_Pin|LOCK_STATE12_Pin|LOCK_STATE13_Pin 
                          |LOCK_STATE14_Pin|LOCK_VibrationSensor_Pin|GPIO_PIN_0;//|GPIO_PIN_8|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PEPin PEPin PEPin PEPin 
                           PEPin */
  GPIO_InitStruct.Pin = LOCK_CTRL11_Pin|LOCK_CTRL1_Pin|LOCK_CTRL12_Pin|LOCK_CTRL13_Pin 
                          |LOCK_CTRL14_Pin | GPIO_PIN_8|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin 
                           PCPin PCPin PCPin PCPin 
                           PCPin PCPin PCPin */
  GPIO_InitStruct.Pin = LOCK_STATE11_Pin|LOCK_STATE10_Pin|LOCK_STATE9_Pin|LOCK_STATE8_Pin 
                          |LOCK_STATE4_Pin|LOCK_STATE22_Pin|LOCK_GOODS_22_Pin|LOCK_GOODS_21_Pin 
                          |LOCK_GOODS_16_Pin|LOCK_GOODS_15_Pin|LOCK_GOODS_14_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PCPin PCPin PCPin PCPin 
                           PCPin */
  GPIO_InitStruct.Pin = LOCK_CTRL10_Pin|LOCK_CTRL9_Pin|LOCK_CTRL8_Pin|LOCK_CTRL3_Pin 
                          |LOCK_CTRL22_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = LOCK_CTRL7_Pin|LOCK_CTRL6_Pin|LOCK_CTRL5_Pin|LOCK_CTRL4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin PAPin 
                           PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = LOCK_STATE7_Pin|LOCK_STATE6_Pin|LOCK_STATE5_Pin|LOCK_GOODS_20_Pin 
                          |LOCK_GOODS_19_Pin|LOCK_GOODS_18_Pin|LOCK_GOODS_17_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin 
                           PBPin PBPin PBPin PBPin 
                           PBPin */
  GPIO_InitStruct.Pin = LOCK_STATE3_Pin|LOCK_STATE15_Pin|LOCK_STATE16_Pin|LOCK_STATE17_Pin 
                          |LOCK_GOODS_5_Pin|LOCK_GOODS_4_Pin|LOCK_GOODS_3_Pin|LOCK_GOODS_2_Pin 
                          |LOCK_GOODS_1_Pin | GPIO_PIN_9|LOCK_ADDR5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin 
                           PBPin PBPin */
  GPIO_InitStruct.Pin = LOCK_CTRL2_Pin|LOCK_CTRL15_Pin|LOCK_CTRL16_Pin|LOCK_CTRL17_Pin 
                          |LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin */
  GPIO_InitStruct.Pin = LOCK_CTRL18_Pin|LOCK_CTRL19_Pin|LOCK_CTRL20_Pin|LOCK_CTRL21_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : PDPin PDPin PDPin PDPin 
                           PDPin PDPin PDPin PDPin 
                           PDPin PDPin PDPin PDPin */
  GPIO_InitStruct.Pin = LOCK_STATE18_Pin|LOCK_STATE19_Pin|LOCK_STATE20_Pin|LOCK_STATE21_Pin 
                          |LOCK_GOODS_13_Pin|LOCK_GOODS_12_Pin|LOCK_GOODS_11_Pin|LOCK_GOODS_10_Pin 
                          |LOCK_GOODS_9_Pin|LOCK_GOODS_8_Pin|LOCK_GOODS_7_Pin|LOCK_GOODS_6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
LOCKERRORCODE BSP_LOCKInit(void)
{
	LOCKERRORCODE state = LOCK_OK;
#if 0 == NEWVERSION
	HAL_GPIO_WritePin(LOCK_CTRL1_GPIO_Port,LOCK_CTRL1_Pin,GPIO_PIN_SET);
#endif
	HAL_GPIO_WritePin(LOCK_CTRL2_GPIO_Port,LOCK_CTRL2_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL3_GPIO_Port,LOCK_CTRL3_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL4_GPIO_Port,LOCK_CTRL4_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL5_GPIO_Port,LOCK_CTRL5_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL6_GPIO_Port,LOCK_CTRL6_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL7_GPIO_Port,LOCK_CTRL7_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL8_GPIO_Port,LOCK_CTRL8_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL9_GPIO_Port,LOCK_CTRL9_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL10_GPIO_Port,LOCK_CTRL10_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL11_GPIO_Port,LOCK_CTRL11_Pin,GPIO_PIN_SET);
#if 0 == NEWVERSION
	HAL_GPIO_WritePin(LOCK_CTRL12_GPIO_Port,LOCK_CTRL12_Pin,GPIO_PIN_SET);
#endif
	HAL_GPIO_WritePin(LOCK_CTRL13_GPIO_Port,LOCK_CTRL13_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL14_GPIO_Port,LOCK_CTRL14_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL15_GPIO_Port,LOCK_CTRL15_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL16_GPIO_Port,LOCK_CTRL16_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL17_GPIO_Port,LOCK_CTRL17_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL18_GPIO_Port,LOCK_CTRL18_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL19_GPIO_Port,LOCK_CTRL19_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL20_GPIO_Port,LOCK_CTRL20_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL21_GPIO_Port,LOCK_CTRL21_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(LOCK_CTRL22_GPIO_Port,LOCK_CTRL22_Pin,GPIO_PIN_SET);

	return state;
}

LOCKERRORCODE BSP_LOCKUpdateOfGoodsState()
{
	LOCKERRORCODE state = LOCK_OK;
#if 0 == NEWVERSION        
	if(LockGoodsStateChangedBuffer[1][0] != GetLockGoods1State)
	{
		LockGoodsStateChangedBuffer[1][1] = 1;
	}
#endif	
	if(LockGoodsStateChangedBuffer[2][0] != GetLockGoods2State)
	{
		LockGoodsStateChangedBuffer[2][1] = 1;
	}

	if(LockGoodsStateChangedBuffer[3][0] != GetLockGoods3State)
	{
		LockGoodsStateChangedBuffer[3][1] = 1;
	}

	if(LockGoodsStateChangedBuffer[4][0] != GetLockGoods4State)
	{
		LockGoodsStateChangedBuffer[4][1] = 1;
	}

	if(LockGoodsStateChangedBuffer[5][0] != GetLockGoods5State)
	{
		LockGoodsStateChangedBuffer[5][1] = 1;
	}
	if(LockGoodsStateChangedBuffer[6][0] != GetLockGoods6State)
	{
		LockGoodsStateChangedBuffer[6][1] = 1;
	}
	if(LockGoodsStateChangedBuffer[7][0] != GetLockGoods7State)
	{
		LockGoodsStateChangedBuffer[7][1] = 1;
	}
	if(LockGoodsStateChangedBuffer[8][0] != GetLockGoods8State)
	{
		LockGoodsStateChangedBuffer[8][1] = 1;
	}
	if(LockGoodsStateChangedBuffer[9][0] != GetLockGoods9State)
	{
		LockGoodsStateChangedBuffer[9][1] = 1;
	}
	if(LockGoodsStateChangedBuffer[10][0] != GetLockGoods10State)
	{
		LockGoodsStateChangedBuffer[10][1] = 1;
	}
	if(LockGoodsStateChangedBuffer[11][0] != GetLockGoods11State)
	{
		LockGoodsStateChangedBuffer[11][1] = 1;
	}
#if 0 == NEWVERSION
	if(LockGoodsStateChangedBuffer[12][0] != GetLockGoods12State)
	{
		LockGoodsStateChangedBuffer[12][1] = 1;
	}
#endif
	if(LockGoodsStateChangedBuffer[13][0] != GetLockGoods13State)
	{
		LockGoodsStateChangedBuffer[13][1] = 1;
	}

	if(LockGoodsStateChangedBuffer[14][0] != GetLockGoods14State)
	{
		LockGoodsStateChangedBuffer[14][1] = 1;
	}

	if(LockGoodsStateChangedBuffer[15][0] != GetLockGoods15State)
	{
		LockGoodsStateChangedBuffer[15][1] = 1;
	}
	if(LockGoodsStateChangedBuffer[16][0] != GetLockGoods16State)
	{
		LockGoodsStateChangedBuffer[16][1] = 1;
	}
	if(LockGoodsStateChangedBuffer[17][0] != GetLockGoods17State)
	{
		LockGoodsStateChangedBuffer[17][1] = 1;
	}
	if(LockGoodsStateChangedBuffer[18][0] != GetLockGoods18State)
	{
		LockGoodsStateChangedBuffer[18][1] = 1;
	}
	if(LockGoodsStateChangedBuffer[19][0] != GetLockGoods19State)
	{
		LockGoodsStateChangedBuffer[19][1] = 1;
	}
	if(LockGoodsStateChangedBuffer[20][0] != GetLockGoods20State)
	{
		LockGoodsStateChangedBuffer[20][1] = 1;
	}
	if(LockGoodsStateChangedBuffer[21][0] != GetLockGoods21State)
	{
		LockGoodsStateChangedBuffer[21][1] = 1;
	}
	if(LockGoodsStateChangedBuffer[22][0] != GetLockGoods22State)
	{
		LockGoodsStateChangedBuffer[22][1] = 1;
	}


#if 0 == NEWVERSION
	LockGoodsStateChangedBuffer[1][0] = GetLockGoods1State;
#endif
	LockGoodsStateChangedBuffer[2][0] = GetLockGoods2State;
	LockGoodsStateChangedBuffer[3][0] = GetLockGoods3State;
	LockGoodsStateChangedBuffer[4][0] = GetLockGoods4State;
	LockGoodsStateChangedBuffer[5][0] = GetLockGoods5State;
	LockGoodsStateChangedBuffer[6][0] = GetLockGoods6State;
	LockGoodsStateChangedBuffer[7][0] = GetLockGoods7State;
	LockGoodsStateChangedBuffer[8][0] = GetLockGoods8State;
	LockGoodsStateChangedBuffer[9][0] = GetLockGoods9State;
	LockGoodsStateChangedBuffer[10][0] = GetLockGoods10State;
	LockGoodsStateChangedBuffer[11][0] = GetLockGoods11State;
#if 0 == NEWVERSION
	LockGoodsStateChangedBuffer[12][0] = GetLockGoods12State;
#endif
	LockGoodsStateChangedBuffer[13][0] = GetLockGoods13State;
	LockGoodsStateChangedBuffer[14][0] = GetLockGoods14State;
	LockGoodsStateChangedBuffer[15][0] = GetLockGoods15State;
	LockGoodsStateChangedBuffer[16][0] = GetLockGoods16State;
	LockGoodsStateChangedBuffer[17][0] = GetLockGoods17State;
	LockGoodsStateChangedBuffer[18][0] = GetLockGoods18State;
	LockGoodsStateChangedBuffer[19][0] = GetLockGoods19State;
	LockGoodsStateChangedBuffer[20][0] = GetLockGoods20State;
	LockGoodsStateChangedBuffer[21][0] = GetLockGoods21State;
	LockGoodsStateChangedBuffer[22][0] = GetLockGoods22State;

	return state;
}

LOCKERRORCODE BSP_LOCKSendGoodsChangedMessage(void)
{
	LOCKERRORCODE state = LOCK_OK;
	uint8_t messageData[7];	
	uint8_t i = 0;
  uint8_t a = 0;
  
	for(i = 1; i < 23; i++)
	{
		if(1 == LockGoodsStateChangedBuffer[i][1])
		{
      a = i;
			messageData[0] = 0;
			messageData[1] = 0;
			messageData[2] = 0;
			messageData[3] = 0;
#if 1 == NEWVERSION
      if(a < 12)
      {
         a -= 1;
      }
      else
      {
        a -= 2;
      }
#endif
			messageData[4] = a;
			messageData[5] = LockPinsStateChangedBuffer[i][0];
			/* 如果有物体在储物柜则上报逻辑1，否则返回0 */
			if(0 == LockGoodsStateChangedBuffer[i][0])
			{
				messageData[6] = 1;
			}
			else
			{
				messageData[6] = 0;
			}
			
			CanWriteData(CANID,messageData,7);
			//state = BSP_CanSendDatas(CanId, i, LockPinsStateChangedBuffer[i][0], LockGoodsStateChangedBuffer[i][0]);
			LockGoodsStateChangedBuffer[i][1] = 0;
		}
		
	}

	return state;
}


LOCKERRORCODE BSP_LOCKUpdateOfLockPinsState(void)
{
	LOCKERRORCODE state = LOCK_OK;
#if 0 == NEWVERSION
	if(LockPinsStateChangedBuffer[1][0] != GetLockPins1State)
	{
		LockPinsStateChangedBuffer[1][1] = 1;
	}
#endif
	if(LockPinsStateChangedBuffer[2][0] != GetLockPins2State)
	{
		LockPinsStateChangedBuffer[2][1] = 1;
	}
	if(LockPinsStateChangedBuffer[3][0] != GetLockPins3State)
	{
		LockPinsStateChangedBuffer[3][1] = 1;
	}
	if(LockPinsStateChangedBuffer[4][0] != GetLockPins4State)
	{
		LockPinsStateChangedBuffer[4][1] = 1;
	}
	if(LockPinsStateChangedBuffer[5][0] != GetLockPins5State)
	{
		LockPinsStateChangedBuffer[5][1] = 1;
	}
	if(LockPinsStateChangedBuffer[6][0] != GetLockPins6State)
	{
		LockPinsStateChangedBuffer[6][1] = 1;
	}
	if(LockPinsStateChangedBuffer[7][0] != GetLockPins7State)
	{
		LockPinsStateChangedBuffer[7][1] = 1;
	}
	if(LockPinsStateChangedBuffer[8][0] != GetLockPins8State)
	{
		LockPinsStateChangedBuffer[8][1] = 1;
	}
	if(LockPinsStateChangedBuffer[9][0] != GetLockPins9State)
	{
		LockPinsStateChangedBuffer[9][1] = 1;
	}
	if(LockPinsStateChangedBuffer[10][0] != GetLockPins10State)
	{
		LockPinsStateChangedBuffer[10][1] = 1;
	}
	
	if(LockPinsStateChangedBuffer[11][0] != GetLockPins11State)
	{
		LockPinsStateChangedBuffer[11][1] = 1;
	}
#if 0 == NEWVERSION
	if(LockPinsStateChangedBuffer[12][0] != GetLockPins12State)
	{
		LockPinsStateChangedBuffer[12][1] = 1;
	}
#endif
	if(LockPinsStateChangedBuffer[13][0] != GetLockPins13State)
	{
		LockPinsStateChangedBuffer[13][1] = 1;
	}
	if(LockPinsStateChangedBuffer[14][0] != GetLockPins14State)
	{
		LockPinsStateChangedBuffer[14][1] = 1;
	}
	if(LockPinsStateChangedBuffer[15][0] != GetLockPins15State)
	{
		LockPinsStateChangedBuffer[15][1] = 1;
	}
	if(LockPinsStateChangedBuffer[16][0] != GetLockPins16State)
	{
		LockPinsStateChangedBuffer[16][1] = 1;
	}
	if(LockPinsStateChangedBuffer[17][0] != GetLockPins17State)
	{
		LockPinsStateChangedBuffer[17][1] = 1;
	}
	if(LockPinsStateChangedBuffer[18][0] != GetLockPins18State)
	{
		LockPinsStateChangedBuffer[18][1] = 1;
	}
	if(LockPinsStateChangedBuffer[19][0] != GetLockPins19State)
	{
		LockPinsStateChangedBuffer[19][1] = 1;
	}
	if(LockPinsStateChangedBuffer[20][0] != GetLockPins20State)
	{
		LockPinsStateChangedBuffer[20][1] = 1;
	}
	if(LockPinsStateChangedBuffer[21][0] != GetLockPins21State)
	{
		LockPinsStateChangedBuffer[21][1] = 1;
	}
	if(LockPinsStateChangedBuffer[22][0] != GetLockPins22State)
	{
		LockPinsStateChangedBuffer[22][1] = 1;
	}
#if 0 == NEWVERSION
	LockPinsStateChangedBuffer[1][0] = GetLockPins1State;
#endif
	LockPinsStateChangedBuffer[2][0] = GetLockPins2State;
	LockPinsStateChangedBuffer[3][0] = GetLockPins3State;
	LockPinsStateChangedBuffer[4][0] = GetLockPins4State;
	LockPinsStateChangedBuffer[5][0] = GetLockPins5State;
	LockPinsStateChangedBuffer[6][0] = GetLockPins6State;
	LockPinsStateChangedBuffer[7][0] = GetLockPins7State;
	LockPinsStateChangedBuffer[8][0] = GetLockPins8State;
	LockPinsStateChangedBuffer[9][0] = GetLockPins9State;
	LockPinsStateChangedBuffer[10][0] = GetLockPins10State;
	LockPinsStateChangedBuffer[11][0] = GetLockPins11State;
#if 0 == NEWVERSION
	LockPinsStateChangedBuffer[12][0] = GetLockPins12State;
#endif
	LockPinsStateChangedBuffer[13][0] = GetLockPins13State;
	LockPinsStateChangedBuffer[14][0] = GetLockPins14State;
	LockPinsStateChangedBuffer[15][0] = GetLockPins15State;
	LockPinsStateChangedBuffer[16][0] = GetLockPins16State;
	LockPinsStateChangedBuffer[17][0] = GetLockPins17State;
	LockPinsStateChangedBuffer[18][0] = GetLockPins18State;
	LockPinsStateChangedBuffer[19][0] = GetLockPins19State;
	LockPinsStateChangedBuffer[20][0] = GetLockPins20State;
	LockPinsStateChangedBuffer[21][0] = GetLockPins21State;
	LockPinsStateChangedBuffer[22][0] = GetLockPins22State;
	return state;
}
LOCKERRORCODE BSP_LOCKSendPinsChangedMessage(void)
{
	LOCKERRORCODE state = LOCK_OK;
	uint8_t messageData[7];	
	uint8_t i = 0;
  uint8_t a = 0;
	for(i = 1; i < 23; i++)
	{
		if(1 == LockPinsStateChangedBuffer[i][1])
		{
			messageData[0] = 0;
			messageData[1] = 0;
			messageData[2] = 0;
			messageData[3] = 0;
      a = i;
#if 1 == NEWVERSION
      if(a < 12)
      {
         a -= 1;
      }
      else
      {
        a -= 2;
      }
#endif
			messageData[4] = a;
			messageData[5] = LockPinsStateChangedBuffer[i][0];
			messageData[6] = LockGoodsStateChangedBuffer[i][0];
			CanWriteData(CANID,messageData,7);
			//state = BSP_CanSendDatas(CanId, i, LockPinsStateChangedBuffer[i][0], LockGoodsStateChangedBuffer[i][0]);
			LockPinsStateChangedBuffer[i][1] = 0;
		}
		
	}

	return state;

}
LOCKERRORCODE BSP_LOCKWriteCtrlPin(uint8_t nBoxNumber, CtrlState nCtrlState)
{
	LOCKERRORCODE state = LOCK_OK;
	uint8_t LockStatus;
	uint8_t IDdata[7];
	
	if(nBoxNumber > 22)
	{
		state = LOCK_ERROR;
		return state;
	}
    
  IDdata[0] = 0;//CtrlBuffer[nBoxNumber][0];
	IDdata[1] = 0;//CtrlBuffer[nBoxNumber][1];
	IDdata[2] = 0;//CtrlBuffer[nBoxNumber][2];
	IDdata[3] = 0;//CtrlBuffer[nBoxNumber][3];
  IDdata[4] = nBoxNumber;
  
#if 1 == NEWVERSION
  if(nBoxNumber < 11)
  {
    IDdata[4] = nBoxNumber - 1;
  }
  else
  {
    IDdata[4] = nBoxNumber - 2;
  }
#endif
  
	switch (nBoxNumber)
		{
		case 1:
      LockStatus = GetLockPins1State;
			HAL_GPIO_WritePin(LOCK_CTRL1_GPIO_Port,LOCK_CTRL1_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL1_GPIO_Port,LOCK_CTRL1_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods1State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
			
		case 2:
      LockStatus = GetLockPins2State;
			HAL_GPIO_WritePin(LOCK_CTRL2_GPIO_Port,LOCK_CTRL2_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL2_GPIO_Port,LOCK_CTRL2_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods2State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
			
		case 3:
      LockStatus = GetLockPins3State;
			HAL_GPIO_WritePin(LOCK_CTRL3_GPIO_Port,LOCK_CTRL3_Pin,GPIO_PIN_RESET);	
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL3_GPIO_Port,LOCK_CTRL3_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods3State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
		case 4:
      LockStatus = GetLockPins4State;
			HAL_GPIO_WritePin(LOCK_CTRL4_GPIO_Port,LOCK_CTRL4_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL4_GPIO_Port,LOCK_CTRL4_Pin,GPIO_PIN_SET);
            if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods4State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
			
		case 5:
      LockStatus = GetLockPins5State;
			HAL_GPIO_WritePin(LOCK_CTRL5_GPIO_Port,LOCK_CTRL5_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL5_GPIO_Port,LOCK_CTRL5_Pin,GPIO_PIN_SET);  
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods5State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
			
		case 6:
            LockStatus = GetLockPins6State;
			HAL_GPIO_WritePin(LOCK_CTRL6_GPIO_Port,LOCK_CTRL6_Pin,GPIO_PIN_RESET);	
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL6_GPIO_Port,LOCK_CTRL6_Pin,GPIO_PIN_SET);	
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods6State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;		
		case 7:
            LockStatus = GetLockPins7State;
			HAL_GPIO_WritePin(LOCK_CTRL7_GPIO_Port,LOCK_CTRL7_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL7_GPIO_Port,LOCK_CTRL7_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods7State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
			
		case 8:
            LockStatus = GetLockPins8State;
			HAL_GPIO_WritePin(LOCK_CTRL8_GPIO_Port,LOCK_CTRL8_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL8_GPIO_Port,LOCK_CTRL8_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods8State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
			
		case 9:
            LockStatus = GetLockPins9State;
			HAL_GPIO_WritePin(LOCK_CTRL9_GPIO_Port,LOCK_CTRL9_Pin,GPIO_PIN_RESET);	
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL9_GPIO_Port,LOCK_CTRL9_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods9State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
		case 10:
            LockStatus = GetLockPins10State;
			HAL_GPIO_WritePin(LOCK_CTRL10_GPIO_Port,LOCK_CTRL10_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL10_GPIO_Port,LOCK_CTRL10_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods10State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
		case 11:
            LockStatus = GetLockPins11State;
			HAL_GPIO_WritePin(LOCK_CTRL11_GPIO_Port,LOCK_CTRL11_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL11_GPIO_Port,LOCK_CTRL11_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods11State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
			
		case 12:
            LockStatus = GetLockPins12State;
			HAL_GPIO_WritePin(LOCK_CTRL12_GPIO_Port,LOCK_CTRL12_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL12_GPIO_Port,LOCK_CTRL12_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods12State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
			
		case 13:
            LockStatus = GetLockPins13State;
			HAL_GPIO_WritePin(LOCK_CTRL13_GPIO_Port,LOCK_CTRL13_Pin,GPIO_PIN_RESET);	
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL13_GPIO_Port,LOCK_CTRL13_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods13State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
		case 14:
            LockStatus = GetLockPins14State;
			HAL_GPIO_WritePin(LOCK_CTRL14_GPIO_Port,LOCK_CTRL14_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL14_GPIO_Port,LOCK_CTRL14_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods14State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
			
		case 15:
            LockStatus = GetLockPins15State;
			HAL_GPIO_WritePin(LOCK_CTRL15_GPIO_Port,LOCK_CTRL15_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL15_GPIO_Port,LOCK_CTRL15_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods15State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
			
		case 16:
            LockStatus = GetLockPins16State;
			HAL_GPIO_WritePin(LOCK_CTRL16_GPIO_Port,LOCK_CTRL16_Pin,GPIO_PIN_RESET);	
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL16_GPIO_Port,LOCK_CTRL16_Pin,GPIO_PIN_SET);	
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods16State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;		
		case 17:
            LockStatus = GetLockPins17State;
			HAL_GPIO_WritePin(LOCK_CTRL17_GPIO_Port,LOCK_CTRL17_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL17_GPIO_Port,LOCK_CTRL17_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods17State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
			
		case 18:
            LockStatus = GetLockPins18State;
			HAL_GPIO_WritePin(LOCK_CTRL18_GPIO_Port,LOCK_CTRL18_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL18_GPIO_Port,LOCK_CTRL18_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods18State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
			
		case 19:
            LockStatus = GetLockPins19State;
			HAL_GPIO_WritePin(LOCK_CTRL19_GPIO_Port,LOCK_CTRL19_Pin,GPIO_PIN_RESET);	
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL19_GPIO_Port,LOCK_CTRL19_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods19State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
		case 20:
            LockStatus = GetLockPins20State;
			HAL_GPIO_WritePin(LOCK_CTRL20_GPIO_Port,LOCK_CTRL20_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL20_GPIO_Port,LOCK_CTRL20_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods20State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;			
		case 21:
            LockStatus = GetLockPins21State;
			HAL_GPIO_WritePin(LOCK_CTRL21_GPIO_Port,LOCK_CTRL21_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL21_GPIO_Port,LOCK_CTRL21_Pin,GPIO_PIN_SET);
			if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods21State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;
				
		case 22:
            LockStatus = GetLockPins22State;
			HAL_GPIO_WritePin(LOCK_CTRL22_GPIO_Port,LOCK_CTRL22_Pin,GPIO_PIN_RESET);
			HAL_Delay(10);
			HAL_GPIO_WritePin(LOCK_CTRL22_GPIO_Port,LOCK_CTRL22_Pin,GPIO_PIN_SET);
            if(1 == LockStatus)
            {
                IDdata[5] = LockStatus;
                IDdata[6] = GetLockGoods22State;
                CanWriteData(CANID, IDdata, 7);
            }
			break;

		default:
			
			break;
		}
	return state;
}


LOCKERRORCODE BSP_LOCKWriteCtrlBuffer(uint8_t ID0,uint8_t ID1,uint8_t ID2, uint8_t ID3,uint8_t nBoxNumber)
{
	LOCKERRORCODE state = LOCK_OK;
	if(nBoxNumber > 22)
	{
		state = LOCK_ERROR;
		return state;
	}
#if 1 == NEWVERSION
  if(nBoxNumber < 11)
  {
    nBoxNumber += 1;
  }
  else
  {
    nBoxNumber += 2;
  }
#endif  
	CtrlBuffer[nBoxNumber][0] = ID0;
	CtrlBuffer[nBoxNumber][1] = ID1;
	CtrlBuffer[nBoxNumber][2] = ID2;
	CtrlBuffer[nBoxNumber][3] = ID3;
	CtrlBuffer[nBoxNumber][4] = 1;
	NeedHandBufferFlag = 1;
	return state;
}

LOCKERRORCODE BSP_LOCKCheckCtrlBuffer(void)
{
	LOCKERRORCODE state = LOCK_OK;
//	uint8_t IDdata[5];
	if(0 == NeedHandBufferFlag)
	{
		return state;
	}

	uint8_t i = 0;
	for(i = 1; i < 23; i++)
	{
		if(1 == CtrlBuffer[i][4])
		{
			CtrlBuffer[i][4] = 0;
			BSP_LOCKWriteCtrlPin(i,CtrlOpen);
			//返回状态，不加编号信息信息
//			IDdata[0] = CtrlBuffer[i][0];
//			IDdata[1] = CtrlBuffer[i][1];
//			IDdata[2] = CtrlBuffer[i][2];
//			IDdata[3] = CtrlBuffer[i][3];
//			IDdata[4] = CtrlBuffer[i][4];
//			
//			CanWriteData(CANID, IDdata, 5);
		}
		
	}
	NeedHandBufferFlag = 0;
	return state;
}

/* USER CODE END 2 */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
