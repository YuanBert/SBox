/**
  ******************************************************************************
  * File Name          : gpio.h
  * Description        : This file contains all the functions prototypes for 
  *                      the gpio  
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
#ifndef __gpio_H
#define __gpio_H
#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
#define GetLockGoods1State 		HAL_GPIO_ReadPin(LOCK_GOODS_1_GPIO_Port, LOCK_GOODS_1_Pin)
#define GetLockGoods2State 		HAL_GPIO_ReadPin(LOCK_GOODS_2_GPIO_Port, LOCK_GOODS_2_Pin)
#define GetLockGoods3State 		HAL_GPIO_ReadPin(LOCK_GOODS_3_GPIO_Port, LOCK_GOODS_3_Pin)
#define GetLockGoods4State 		HAL_GPIO_ReadPin(LOCK_GOODS_4_GPIO_Port, LOCK_GOODS_4_Pin)
#define GetLockGoods5State 		HAL_GPIO_ReadPin(LOCK_GOODS_5_GPIO_Port, LOCK_GOODS_5_Pin)
#define GetLockGoods6State 		HAL_GPIO_ReadPin(LOCK_GOODS_6_GPIO_Port, LOCK_GOODS_6_Pin)
#define GetLockGoods7State 		HAL_GPIO_ReadPin(LOCK_GOODS_7_GPIO_Port, LOCK_GOODS_7_Pin)
#define GetLockGoods8State 		HAL_GPIO_ReadPin(LOCK_GOODS_8_GPIO_Port, LOCK_GOODS_8_Pin)
#define GetLockGoods9State 		HAL_GPIO_ReadPin(LOCK_GOODS_9_GPIO_Port, LOCK_GOODS_9_Pin)
#define GetLockGoods10State 	HAL_GPIO_ReadPin(LOCK_GOODS_10_GPIO_Port, LOCK_GOODS_10_Pin)
#define GetLockGoods11State 	HAL_GPIO_ReadPin(LOCK_GOODS_11_GPIO_Port, LOCK_GOODS_11_Pin)
#define GetLockGoods12State 	HAL_GPIO_ReadPin(LOCK_GOODS_12_GPIO_Port, LOCK_GOODS_12_Pin)
#define GetLockGoods13State 	HAL_GPIO_ReadPin(LOCK_GOODS_13_GPIO_Port, LOCK_GOODS_13_Pin)
#define GetLockGoods14State 	HAL_GPIO_ReadPin(LOCK_GOODS_14_GPIO_Port, LOCK_GOODS_14_Pin)
#define GetLockGoods15State 	HAL_GPIO_ReadPin(LOCK_GOODS_15_GPIO_Port, LOCK_GOODS_15_Pin)
#define GetLockGoods16State 	HAL_GPIO_ReadPin(LOCK_GOODS_16_GPIO_Port, LOCK_GOODS_16_Pin)
#define GetLockGoods17State 	HAL_GPIO_ReadPin(LOCK_GOODS_17_GPIO_Port, LOCK_GOODS_17_Pin)
#define GetLockGoods18State 	HAL_GPIO_ReadPin(LOCK_GOODS_18_GPIO_Port, LOCK_GOODS_18_Pin)
#define GetLockGoods19State 	HAL_GPIO_ReadPin(LOCK_GOODS_19_GPIO_Port, LOCK_GOODS_19_Pin)
#define GetLockGoods20State 	HAL_GPIO_ReadPin(LOCK_GOODS_20_GPIO_Port, LOCK_GOODS_20_Pin)
#define GetLockGoods21State 	HAL_GPIO_ReadPin(LOCK_GOODS_21_GPIO_Port, LOCK_GOODS_21_Pin)
#define GetLockGoods22State 	HAL_GPIO_ReadPin(LOCK_GOODS_22_GPIO_Port, LOCK_GOODS_22_Pin)


#define GetLockPins1State		HAL_GPIO_ReadPin(LOCK_STATE1_GPIO_Port, LOCK_STATE1_Pin)
#define GetLockPins2State		HAL_GPIO_ReadPin(LOCK_STATE2_GPIO_Port, LOCK_STATE2_Pin)
#define GetLockPins3State		HAL_GPIO_ReadPin(LOCK_STATE3_GPIO_Port, LOCK_STATE3_Pin)
#define GetLockPins4State		HAL_GPIO_ReadPin(LOCK_STATE4_GPIO_Port, LOCK_STATE4_Pin)
#define GetLockPins5State		HAL_GPIO_ReadPin(LOCK_STATE5_GPIO_Port, LOCK_STATE5_Pin)
#define GetLockPins6State		HAL_GPIO_ReadPin(LOCK_STATE6_GPIO_Port, LOCK_STATE6_Pin)
#define GetLockPins7State		HAL_GPIO_ReadPin(LOCK_STATE7_GPIO_Port, LOCK_STATE7_Pin)
#define GetLockPins8State		HAL_GPIO_ReadPin(LOCK_STATE8_GPIO_Port, LOCK_STATE8_Pin)
#define GetLockPins9State		HAL_GPIO_ReadPin(LOCK_STATE9_GPIO_Port, LOCK_STATE9_Pin)
#define GetLockPins10State		HAL_GPIO_ReadPin(LOCK_STATE10_GPIO_Port, LOCK_STATE10_Pin)
#define GetLockPins11State		HAL_GPIO_ReadPin(LOCK_STATE11_GPIO_Port, LOCK_STATE11_Pin)
#define GetLockPins12State		HAL_GPIO_ReadPin(LOCK_STATE12_GPIO_Port, LOCK_STATE12_Pin)
#define GetLockPins13State		HAL_GPIO_ReadPin(LOCK_STATE13_GPIO_Port, LOCK_STATE13_Pin)
#define GetLockPins14State		HAL_GPIO_ReadPin(LOCK_STATE14_GPIO_Port, LOCK_STATE14_Pin)
#define GetLockPins15State		HAL_GPIO_ReadPin(LOCK_STATE15_GPIO_Port, LOCK_STATE15_Pin)
#define GetLockPins16State		HAL_GPIO_ReadPin(LOCK_STATE16_GPIO_Port, LOCK_STATE16_Pin)
#define GetLockPins17State		HAL_GPIO_ReadPin(LOCK_STATE17_GPIO_Port, LOCK_STATE17_Pin)
#define GetLockPins18State		HAL_GPIO_ReadPin(LOCK_STATE18_GPIO_Port, LOCK_STATE18_Pin)
#define GetLockPins19State		HAL_GPIO_ReadPin(LOCK_STATE19_GPIO_Port, LOCK_STATE19_Pin)
#define GetLockPins20State		HAL_GPIO_ReadPin(LOCK_STATE20_GPIO_Port, LOCK_STATE20_Pin)
#define GetLockPins21State		HAL_GPIO_ReadPin(LOCK_STATE21_GPIO_Port, LOCK_STATE21_Pin)
#define GetLockPins22State		HAL_GPIO_ReadPin(LOCK_STATE22_GPIO_Port, LOCK_STATE22_Pin)
/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
LOCKERRORCODE BSP_LOCKInit(void);
LOCKERRORCODE BSP_LOCKUpdateOfGoodsState(void);
LOCKERRORCODE BSP_LOCKSendGoodsChangedMessage(void);
LOCKERRORCODE BSP_LOCKUpdateOfLockPinsState(void);
LOCKERRORCODE BSP_LOCKSendPinsChangedMessage(void);
LOCKERRORCODE BSP_LOCKWriteCtrlPin(uint8_t nBoxNumber, CtrlState nCtrlState);

LOCKERRORCODE BSP_LOCKWriteCtrlBuffer(uint8_t ID0,uint8_t ID1,uint8_t ID2, uint8_t ID3,uint8_t nBoxNumber);
LOCKERRORCODE BSP_LOCKCheckCtrlBuffer(void);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ pinoutConfig_H */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
