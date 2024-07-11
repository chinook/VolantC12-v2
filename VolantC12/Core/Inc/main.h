/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32u5xx_hal.h"

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
#define BOUTON_7_Pin GPIO_PIN_15
#define BOUTON_7_GPIO_Port GPIOA
#define BOUTON_7_EXTI_IRQn EXTI15_IRQn
#define BOUTON_6_Pin GPIO_PIN_8
#define BOUTON_6_GPIO_Port GPIOA
#define BOUTON_6_EXTI_IRQn EXTI8_IRQn
#define BOUTON_5_Pin GPIO_PIN_5
#define BOUTON_5_GPIO_Port GPIOB
#define BOUTON_5_EXTI_IRQn EXTI5_IRQn
#define LCD_DISP_RESET_Pin GPIO_PIN_7
#define LCD_DISP_RESET_GPIO_Port GPIOH
#define CTP_RST_Pin GPIO_PIN_3
#define CTP_RST_GPIO_Port GPIOE
#define USR_LED_1_Pin GPIO_PIN_5
#define USR_LED_1_GPIO_Port GPIOE
#define USB_PWR_EN_Pin GPIO_PIN_8
#define USB_PWR_EN_GPIO_Port GPIOG
#define USB_OVERCURRENT_Pin GPIO_PIN_0
#define USB_OVERCURRENT_GPIO_Port GPIOJ
#define BOUTON_1_Pin GPIO_PIN_2
#define BOUTON_1_GPIO_Port GPIOG
#define BOUTON_1_EXTI_IRQn EXTI2_IRQn
#define R_RST_Pin GPIO_PIN_4
#define R_RST_GPIO_Port GPIOF
#define BOUTON_9_Pin GPIO_PIN_4
#define BOUTON_9_GPIO_Port GPIOA
#define BOUTON_9_EXTI_IRQn EXTI4_IRQn
#define BOUTON_8_Pin GPIO_PIN_0
#define BOUTON_8_GPIO_Port GPIOB
#define BOUTON_8_EXTI_IRQn EXTI0_IRQn
#define R_CS_Pin GPIO_PIN_1
#define R_CS_GPIO_Port GPIOG
#define BOUTON_2_Pin GPIO_PIN_10
#define BOUTON_2_GPIO_Port GPIOB
#define BOUTON_2_EXTI_IRQn EXTI10_IRQn
#define BOUTON_10_Pin GPIO_PIN_3
#define BOUTON_10_GPIO_Port GPIOA
#define BOUTON_10_EXTI_IRQn EXTI3_IRQn
#define BOUTON_4_Pin GPIO_PIN_6
#define BOUTON_4_GPIO_Port GPIOA
#define BOUTON_4_EXTI_IRQn EXTI6_IRQn
#define BOUTON_3_Pin GPIO_PIN_7
#define BOUTON_3_GPIO_Port GPIOA
#define BOUTON_3_EXTI_IRQn EXTI7_IRQn
#define R_INT_Pin GPIO_PIN_4
#define R_INT_GPIO_Port GPIOC

/* USER CODE BEGIN Private defines */
#define PALE_RADIUS 0.918
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
