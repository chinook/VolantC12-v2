/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    fdcan.h
  * @brief   This file contains all the function prototypes for
  *          the fdcan.c file
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
#ifndef __FDCAN_H__
#define __FDCAN_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/


/* USER CODE BEGIN Includes */
#include "stm32u5xx_hal.h"
#include "chinook_can_ids.h"
#include "../../STM32CubeIDE/Application/User/application/screen_tasks.h"
#include <string.h>

float 	canRx_mast_angle;
float 	canRx_pitch;
float 	canRx_wind_speed;
float 	canRx_wind_dir;
float 	canRx_wheel_rpm;
float 	canRx_turbine_rpm;

extern float	canRx_torque;

extern float 	canRx_power;
extern float 	canRx_efficiency;
extern float 	canRx_tsr;

/* USER CODE END Includes */

extern FDCAN_HandleTypeDef hfdcan1;

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_FDCAN1_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __FDCAN_H__ */

