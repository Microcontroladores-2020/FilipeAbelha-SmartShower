/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define GPIO_OUT_LED1A_Pin GPIO_PIN_1
#define GPIO_OUT_LED1A_GPIO_Port GPIOA
#define GPIO_OUT_LED1B_Pin GPIO_PIN_2
#define GPIO_OUT_LED1B_GPIO_Port GPIOA
#define GPIO_OUT_LED1C_Pin GPIO_PIN_3
#define GPIO_OUT_LED1C_GPIO_Port GPIOA
#define GPIO_OUT_LED1D_Pin GPIO_PIN_4
#define GPIO_OUT_LED1D_GPIO_Port GPIOA
#define GPIO_OUT_LED1E_Pin GPIO_PIN_5
#define GPIO_OUT_LED1E_GPIO_Port GPIOA
#define GPIO_OUT_LED1F_Pin GPIO_PIN_6
#define GPIO_OUT_LED1F_GPIO_Port GPIOA
#define GPIO_OUT_LED1G_Pin GPIO_PIN_7
#define GPIO_OUT_LED1G_GPIO_Port GPIOA
#define GPIO_OUT_LED1H_Pin GPIO_PIN_4
#define GPIO_OUT_LED1H_GPIO_Port GPIOC
#define GPIO_OUT_LED2A_Pin GPIO_PIN_5
#define GPIO_OUT_LED2A_GPIO_Port GPIOC
#define GPIO_OUT_LED2B_Pin GPIO_PIN_0
#define GPIO_OUT_LED2B_GPIO_Port GPIOB
#define GPIO_OUT_LED2C_Pin GPIO_PIN_1
#define GPIO_OUT_LED2C_GPIO_Port GPIOB
#define GPIO_OUT_LED2D_Pin GPIO_PIN_2
#define GPIO_OUT_LED2D_GPIO_Port GPIOB
#define GPIO_OUT_LED2E_Pin GPIO_PIN_10
#define GPIO_OUT_LED2E_GPIO_Port GPIOB
#define GPIO_OUT_LED2F_Pin GPIO_PIN_12
#define GPIO_OUT_LED2F_GPIO_Port GPIOB
#define GPIO_OUT_LED2G_Pin GPIO_PIN_13
#define GPIO_OUT_LED2G_GPIO_Port GPIOB
#define GPIO_OUT_LED2H_Pin GPIO_PIN_14
#define GPIO_OUT_LED2H_GPIO_Port GPIOB
#define GPIO_OUT_POTENTIOMETER_Pin GPIO_PIN_10
#define GPIO_OUT_POTENTIOMETER_GPIO_Port GPIOA
#define GPIO_IN_WATER_FLUX_Pin GPIO_PIN_11
#define GPIO_IN_WATER_FLUX_GPIO_Port GPIOA
#define GPIO_IN_IR_RECEIVER_Pin GPIO_PIN_12
#define GPIO_IN_IR_RECEIVER_GPIO_Port GPIOA
#define GPIO_IN_TEMPERATURE_Pin GPIO_PIN_13
#define GPIO_IN_TEMPERATURE_GPIO_Port GPIOA
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
