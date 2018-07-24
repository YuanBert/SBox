/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H__
#define __MAIN_H__

/* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define LOCK_ADDR3_Pin GPIO_PIN_2
#define LOCK_ADDR3_GPIO_Port GPIOE
#define LOCK_ADDR2_Pin GPIO_PIN_3
#define LOCK_ADDR2_GPIO_Port GPIOE
#define LOCK_ADDR1_Pin GPIO_PIN_4
#define LOCK_ADDR1_GPIO_Port GPIOE
#define LOCK_ADDR0_Pin GPIO_PIN_5
#define LOCK_ADDR0_GPIO_Port GPIOE
#define LOCK_CTRL11_Pin GPIO_PIN_6
#define LOCK_CTRL11_GPIO_Port GPIOE
#define LOCK_STATE11_Pin GPIO_PIN_13
#define LOCK_STATE11_GPIO_Port GPIOC
#define LOCK_CTRL10_Pin GPIO_PIN_14
#define LOCK_CTRL10_GPIO_Port GPIOC
#define LOCK_STATE10_Pin GPIO_PIN_15
#define LOCK_STATE10_GPIO_Port GPIOC
#define LOCK_CTRL9_Pin GPIO_PIN_0
#define LOCK_CTRL9_GPIO_Port GPIOC
#define LOCK_STATE9_Pin GPIO_PIN_1
#define LOCK_STATE9_GPIO_Port GPIOC
#define LOCK_CTRL8_Pin GPIO_PIN_2
#define LOCK_CTRL8_GPIO_Port GPIOC
#define LOCK_STATE8_Pin GPIO_PIN_3
#define LOCK_STATE8_GPIO_Port GPIOC
#define LOCK_CTRL7_Pin GPIO_PIN_1
#define LOCK_CTRL7_GPIO_Port GPIOA
#define LOCK_STATE7_Pin GPIO_PIN_2
#define LOCK_STATE7_GPIO_Port GPIOA
#define LOCK_CTRL6_Pin GPIO_PIN_3
#define LOCK_CTRL6_GPIO_Port GPIOA
#define LOCK_STATE6_Pin GPIO_PIN_4
#define LOCK_STATE6_GPIO_Port GPIOA
#define LOCK_CTRL5_Pin GPIO_PIN_5
#define LOCK_CTRL5_GPIO_Port GPIOA
#define LOCK_STATE5_Pin GPIO_PIN_6
#define LOCK_STATE5_GPIO_Port GPIOA
#define LOCK_CTRL4_Pin GPIO_PIN_7
#define LOCK_CTRL4_GPIO_Port GPIOA
#define LOCK_STATE4_Pin GPIO_PIN_4
#define LOCK_STATE4_GPIO_Port GPIOC
#define LOCK_CTRL3_Pin GPIO_PIN_5
#define LOCK_CTRL3_GPIO_Port GPIOC
#define LOCK_STATE3_Pin GPIO_PIN_0
#define LOCK_STATE3_GPIO_Port GPIOB
#define LOCK_CTRL2_Pin GPIO_PIN_1
#define LOCK_CTRL2_GPIO_Port GPIOB
#define LOCK_STATE2_Pin GPIO_PIN_7
#define LOCK_STATE2_GPIO_Port GPIOE
#define LOCK_CTRL1_Pin GPIO_PIN_8
#define LOCK_CTRL1_GPIO_Port GPIOE
#define LOCK_STATE1_Pin GPIO_PIN_9
#define LOCK_STATE1_GPIO_Port GPIOE
#define LOCK_CTRL12_Pin GPIO_PIN_10
#define LOCK_CTRL12_GPIO_Port GPIOE
#define LOCK_STATE12_Pin GPIO_PIN_11
#define LOCK_STATE12_GPIO_Port GPIOE
#define LOCK_CTRL13_Pin GPIO_PIN_12
#define LOCK_CTRL13_GPIO_Port GPIOE
#define LOCK_STATE13_Pin GPIO_PIN_13
#define LOCK_STATE13_GPIO_Port GPIOE
#define LOCK_CTRL14_Pin GPIO_PIN_14
#define LOCK_CTRL14_GPIO_Port GPIOE
#define LOCK_STATE14_Pin GPIO_PIN_15
#define LOCK_STATE14_GPIO_Port GPIOE
#define LOCK_CTRL15_Pin GPIO_PIN_10
#define LOCK_CTRL15_GPIO_Port GPIOB
#define LOCK_STATE15_Pin GPIO_PIN_11
#define LOCK_STATE15_GPIO_Port GPIOB
#define LOCK_CTRL16_Pin GPIO_PIN_12
#define LOCK_CTRL16_GPIO_Port GPIOB
#define LOCK_STATE16_Pin GPIO_PIN_13
#define LOCK_STATE16_GPIO_Port GPIOB
#define LOCK_CTRL17_Pin GPIO_PIN_14
#define LOCK_CTRL17_GPIO_Port GPIOB
#define LOCK_STATE17_Pin GPIO_PIN_15
#define LOCK_STATE17_GPIO_Port GPIOB
#define LOCK_CTRL18_Pin GPIO_PIN_8
#define LOCK_CTRL18_GPIO_Port GPIOD
#define LOCK_STATE18_Pin GPIO_PIN_9
#define LOCK_STATE18_GPIO_Port GPIOD
#define LOCK_CTRL19_Pin GPIO_PIN_10
#define LOCK_CTRL19_GPIO_Port GPIOD
#define LOCK_STATE19_Pin GPIO_PIN_11
#define LOCK_STATE19_GPIO_Port GPIOD
#define LOCK_CTRL20_Pin GPIO_PIN_12
#define LOCK_CTRL20_GPIO_Port GPIOD
#define LOCK_STATE20_Pin GPIO_PIN_13
#define LOCK_STATE20_GPIO_Port GPIOD
#define LOCK_CTRL21_Pin GPIO_PIN_14
#define LOCK_CTRL21_GPIO_Port GPIOD
#define LOCK_STATE21_Pin GPIO_PIN_15
#define LOCK_STATE21_GPIO_Port GPIOD
#define LOCK_CTRL22_Pin GPIO_PIN_6
#define LOCK_CTRL22_GPIO_Port GPIOC
#define LOCK_STATE22_Pin GPIO_PIN_7
#define LOCK_STATE22_GPIO_Port GPIOC
#define LOCK_GOODS_22_Pin GPIO_PIN_8
#define LOCK_GOODS_22_GPIO_Port GPIOC
#define LOCK_GOODS_21_Pin GPIO_PIN_9
#define LOCK_GOODS_21_GPIO_Port GPIOC
#define LOCK_GOODS_20_Pin GPIO_PIN_8
#define LOCK_GOODS_20_GPIO_Port GPIOA
#define LOCK_GOODS_19_Pin GPIO_PIN_9
#define LOCK_GOODS_19_GPIO_Port GPIOA
#define LOCK_GOODS_18_Pin GPIO_PIN_10
#define LOCK_GOODS_18_GPIO_Port GPIOA
#define LOCK_GOODS_17_Pin GPIO_PIN_15
#define LOCK_GOODS_17_GPIO_Port GPIOA
#define LOCK_GOODS_16_Pin GPIO_PIN_10
#define LOCK_GOODS_16_GPIO_Port GPIOC
#define LOCK_GOODS_15_Pin GPIO_PIN_11
#define LOCK_GOODS_15_GPIO_Port GPIOC
#define LOCK_GOODS_14_Pin GPIO_PIN_12
#define LOCK_GOODS_14_GPIO_Port GPIOC
#define LOCK_GOODS_13_Pin GPIO_PIN_0
#define LOCK_GOODS_13_GPIO_Port GPIOD
#define LOCK_GOODS_12_Pin GPIO_PIN_1
#define LOCK_GOODS_12_GPIO_Port GPIOD
#define LOCK_GOODS_11_Pin GPIO_PIN_2
#define LOCK_GOODS_11_GPIO_Port GPIOD
#define LOCK_GOODS_10_Pin GPIO_PIN_3
#define LOCK_GOODS_10_GPIO_Port GPIOD
#define LOCK_GOODS_9_Pin GPIO_PIN_4
#define LOCK_GOODS_9_GPIO_Port GPIOD
#define LOCK_GOODS_8_Pin GPIO_PIN_5
#define LOCK_GOODS_8_GPIO_Port GPIOD
#define LOCK_GOODS_7_Pin GPIO_PIN_6
#define LOCK_GOODS_7_GPIO_Port GPIOD
#define LOCK_GOODS_6_Pin GPIO_PIN_7
#define LOCK_GOODS_6_GPIO_Port GPIOD
#define LOCK_GOODS_5_Pin GPIO_PIN_3
#define LOCK_GOODS_5_GPIO_Port GPIOB
#define LOCK_GOODS_4_Pin GPIO_PIN_4
#define LOCK_GOODS_4_GPIO_Port GPIOB
#define LOCK_GOODS_3_Pin GPIO_PIN_5
#define LOCK_GOODS_3_GPIO_Port GPIOB
#define LOCK_GOODS_2_Pin GPIO_PIN_6
#define LOCK_GOODS_2_GPIO_Port GPIOB
#define LOCK_GOODS_1_Pin GPIO_PIN_7
#define LOCK_GOODS_1_GPIO_Port GPIOB
#define LED1_Pin GPIO_PIN_8
#define LED1_GPIO_Port GPIOB
#define LED2_Pin GPIO_PIN_9
#define LED2_GPIO_Port GPIOB
#define LOCK_VibrationSensor_Pin GPIO_PIN_1
#define LOCK_VibrationSensor_GPIO_Port GPIOE
#define MQ_A0_Pin GPIO_PIN_0
#define MQ_A0_GPIO_Port GPIOA

/* ########################## Assert Selection ############################## */
/**
  * @brief Uncomment the line below to expanse the "assert_param" macro in the 
  *        HAL drivers code
  */
/* #define USE_FULL_ASSERT    1U */

/* USER CODE BEGIN Private defines */
typedef enum {
	LOCK_OK = 0U,
	LOCK_ERROR,
	LOCK_TIMEOUT,
	LOCK_OTHERERROR
}LOCKERRORCODE;
 
typedef enum{
	LockLocked = 0U,
	LockReleased
}LockState;

typedef enum{
	BoxEmpty = 0U,
	BoxFull
}BoxState;

typedef enum{
	CtrlOpen = 0U,
	CtrlClose
}CtrlState;

/* USER CODE END Private defines */

#ifdef __cplusplus
 extern "C" {
#endif
void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)
#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
