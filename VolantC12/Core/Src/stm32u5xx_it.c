/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32u5xx_it.c
  * @brief   Interrupt Service Routines.
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32u5xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "../../STM32CubeIDE/Application/User/application/screen_tasks.h"
//#include <string.h>
//#include "fdcan.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

//uint8_t mast_angle_flag = MAST_ANGLE_FLAG;
//uint8_t pitch_flag = PITCH_FLAG;
//uint8_t wind_sp_flag = WIND_SP_FLAG;
//uint8_t wind_dir_flag = WIND_DIR_FLAG;
//uint8_t wheel_rpm_flag = WHEEL_RPM_FLAG;
//uint8_t turb_rpm_flag = TURB_RPM_FLAG;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern FDCAN_HandleTypeDef hfdcan1;
extern GPU2D_HandleTypeDef hgpu2d;
extern LTDC_HandleTypeDef hltdc;
extern TIM_HandleTypeDef htim2;

/* USER CODE BEGIN EV */
extern volatile uint8_t desired_screen;
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
   while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/******************************************************************************/
/* STM32U5xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32u5xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles EXTI Line3 interrupt.
  */
//void EXTI3_IRQHandler(void) // PA3
//{
//  /* USER CODE BEGIN EXTI3_IRQn 0 */
//  if (desired_screen) {
//	desired_screen = 0;
//  } else {
//	desired_screen = 1;
//  }
//  /* USER CODE END EXTI3_IRQn 0 */
//  HAL_GPIO_EXTI_IRQHandler(SCREEN_CHANGE_Pin);
////  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
//  /* USER CODE BEGIN EXTI3_IRQn 1 */
//
//  /* USER CODE END EXTI3_IRQn 1 */
//}

/**
  * @brief This function handles EXTI Line6 interrupt.
  */
//void EXTI6_IRQHandler(void) // PA6
//{
//  /* USER CODE BEGIN EXTI6_IRQn 0 */
//
//  /* USER CODE END EXTI6_IRQn 0 */
//  HAL_GPIO_EXTI_IRQHandler(CTP_INT_Pin);
////  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
//  /* USER CODE BEGIN EXTI6_IRQn 1 */
//
//  /* USER CODE END EXTI6_IRQn 1 */
//}

/**
  * @brief This function handles FDCAN1 interrupt 0.
  */
void FDCAN1_IT0_IRQHandler(void)
{
  /* USER CODE BEGIN FDCAN1_IT0_IRQn 0 */

  /* USER CODE END FDCAN1_IT0_IRQn 0 */
  HAL_FDCAN_IRQHandler(&hfdcan1);
  /* USER CODE BEGIN FDCAN1_IT0_IRQn 1 */

  /* USER CODE END FDCAN1_IT0_IRQn 1 */
}

/**
  * @brief This function handles FDCAN1 interrupt 1.
  */
void FDCAN1_IT1_IRQHandler(void)
{
  /* USER CODE BEGIN FDCAN1_IT1_IRQn 0 */

  /* USER CODE END FDCAN1_IT1_IRQn 0 */
  HAL_FDCAN_IRQHandler(&hfdcan1);
  /* USER CODE BEGIN FDCAN1_IT1_IRQn 1 */

  /* USER CODE END FDCAN1_IT1_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles GPU2D global interrupt.
  */
void GPU2D_IRQHandler(void)
{
  /* USER CODE BEGIN GPU2D_IRQn 0 */

  /* USER CODE END GPU2D_IRQn 0 */
  HAL_GPU2D_IRQHandler(&hgpu2d);
  /* USER CODE BEGIN GPU2D_IRQn 1 */

  /* USER CODE END GPU2D_IRQn 1 */
}

/**
  * @brief This function handles GPU2D Error interrupt.
  */
void GPU2D_ER_IRQHandler(void)
{
  /* USER CODE BEGIN GPU2D_ER_IRQn 0 */

  /* USER CODE END GPU2D_ER_IRQn 0 */
  HAL_GPU2D_ER_IRQHandler(&hgpu2d);
  /* USER CODE BEGIN GPU2D_ER_IRQn 1 */

  /* USER CODE END GPU2D_ER_IRQn 1 */
}

/**
  * @brief This function handles LCD-TFT global interrupt.
  */
void LTDC_IRQHandler(void)
{
  /* USER CODE BEGIN LTDC_IRQn 0 */

  /* USER CODE END LTDC_IRQn 0 */
  HAL_LTDC_IRQHandler(&hltdc);
  /* USER CODE BEGIN LTDC_IRQn 1 */

  /* USER CODE END LTDC_IRQn 1 */
}

/* USER CODE BEGIN 1 */

FDCAN_TxHeaderTypeDef pTxHeader;
uint32_t txMailbox;

void SendCAN(uint8_t id, uint8_t* data)
{
	pTxHeader.Identifier = id;
	pTxHeader.IdType = FDCAN_STANDARD_ID;
	pTxHeader.TxFrameType = FDCAN_DATA_FRAME;
	pTxHeader.DataLength = 4;
	pTxHeader.FDFormat = FDCAN_CLASSIC_CAN;
	pTxHeader.TxEventFifoControl = FDCAN_NO_TX_EVENTS;

	if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &pTxHeader, data) != HAL_OK)
	{
		Error_Handler();
	}
}

void EXTI0_IRQHandler(void) // PB0
{
	static float test4 = 0.0f;
	test4 += 0.1f;
	memcpy(&canRx_wind_dir, &test4, sizeof(float));
	static int wind_dir_flag = WIND_DIR_FLAG;
	osMessageQueuePut(screen1_isr_queue, &wind_dir_flag, 0, 0);
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

//void EXTI1_IRQHandler(void)
//{
//	static float test6 = 0.0f;
//	test6 += 0.1f;
//	memcpy(&canRx_turbine_rpm, &test6, sizeof(float));
//	static int turb_rpm_flag = TURB_RPM_FLAG;
//	osMessageQueuePut(screen1_isr_queue, &turb_rpm_flag, 0, 0);
//  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
//}

void EXTI2_IRQHandler(void) // PG2 - TOP LEFT - LEFT
{
//	static float test6 = 0.0f;
//	test6 += 0.1f;
//	memcpy(&canRx_turbine_rpm, &test6, sizeof(float));
//	static int turb_rpm_flag = TURB_RPM_FLAG;
//	osMessageQueuePut(screen1_isr_queue, &turb_rpm_flag, 0, 0);
	if (!HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_2))
	{
		uint32_t dir_left = MOTOR_DIRECTION_LEFT;
		SendCAN(MARIO_PITCH_MANUAL_CMD, (uint8_t*)&dir_left);
	}
	else
	{
		uint32_t dir_stop = MOTOR_DIRECTION_STOP;
		SendCAN(MARIO_PITCH_MANUAL_CMD, (uint8_t*)&dir_stop);
	}
  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
}

void EXTI5_IRQHandler(void) // PB5 - TOP LEFT RIGHT
{
//	static float test5 = 0.0f;
//	test5 += 0.1f;
//	memcpy(&canRx_wheel_rpm, &test5, sizeof(float));
//	static int wheel_rpm_flag = WHEEL_RPM_FLAG;
//	osMessageQueuePut(screen1_isr_queue, &wheel_rpm_flag, 0, 0);
	/*
	if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5))
	{
		uint32_t dir_right = MOTOR_DIRECTION_RIGHT;
		SendCAN(MARIO_PITCH_MANUAL_CMD, (uint8_t*)&dir_right);
	}
	else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5))
	{
		uint32_t dir_stop = MOTOR_DIRECTION_STOP;
		SendCAN(MARIO_PITCH_MANUAL_CMD, (uint8_t*)&dir_stop);
	}
	*/
	if (!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5))
	{
		uint32_t dir_right = MOTOR_DIRECTION_RIGHT;
		SendCAN(MARIO_PITCH_MANUAL_CMD, (uint8_t*)&dir_right);
	}
	else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5))
	{
		uint32_t dir_stop = MOTOR_DIRECTION_STOP;
		SendCAN(MARIO_PITCH_MANUAL_CMD, (uint8_t*)&dir_stop);
	}

	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);
}

uint8_t pb3_value = 0;
uint8_t pb3_update = 0;

void EXTI3_IRQHandler(void) // PA3
{
//	static float test6 = 0.0f;
//	test6 += 0.1f;
//	memcpy(&canRx_turbine_rpm, &test6, sizeof(float));
//	static int turb_rpm_flag = TURB_RPM_FLAG;
//	osMessageQueuePut(screen1_isr_queue, &turb_rpm_flag, 0, 0);


  HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
}

void EXTI4_IRQHandler(void) // PA4
{
//	static float test6 = 0.0f;
//	test6 += 0.1f;
//	memcpy(&canRx_turbine_rpm, &test6, sizeof(float));
//	static int turb_rpm_flag = TURB_RPM_FLAG;
//	osMessageQueuePut(screen1_isr_queue, &turb_rpm_flag, 0, 0);

	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

void EXTI6_IRQHandler(void) // PB6
{
//	static float test3 = 0.0f;
//		test3 += 0.1f;
//		memcpy(&canRx_wind_speed, &test3, sizeof(float));
//		static int wind_sp_flag = WIND_SP_FLAG;
//		osMessageQueuePut(screen1_isr_queue, &wind_sp_flag, 0, 0);
//
//	static float test4 = 0.0f;
//	test4 += 0.1f;
//	memcpy(&canRx_wind_dir, &test4, sizeof(float));
//	static int wind_dir_flag = WIND_DIR_FLAG;
//	osMessageQueuePut(screen1_isr_queue, &wind_dir_flag, 0, 0);

	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_6);
}

void EXTI7_IRQHandler(void) // PA7
{
//	static float test3 = 0.0f;
//		test3 += 0.1f;
//		memcpy(&canRx_wind_speed, &test3, sizeof(float));
//		static int wind_sp_flag = WIND_SP_FLAG;
//		osMessageQueuePut(screen1_isr_queue, &wind_sp_flag, 0, 0);
//
//	static float test4 = 0.0f;
//	test4 += 0.1f;
//	memcpy(&canRx_wind_dir, &test4, sizeof(float));
//	static int wind_dir_flag = WIND_DIR_FLAG;
//	osMessageQueuePut(screen1_isr_queue, &wind_dir_flag, 0, 0);

	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_7);
}

void EXTI8_IRQHandler(void) // BOUTON 6 - Milieu droit - PA8 - ok
{
	static float test3 = 0.0f;
	test3 += 0.1f;
	memcpy(&canRx_wind_speed, &test3, sizeof(float));
	static int wind_sp_flag = WIND_SP_FLAG;
	osMessageQueuePut(screen1_isr_queue, &wind_sp_flag, 0, 0);

	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
}

void EXTI10_IRQHandler(void) // PB10
{
//	static float test2 = 0.0f;
//	test2 += 0.1f;
//	memcpy(&canRx_pitch, &test2, sizeof(float));
//	static int pitch_flag = PITCH_FLAG;
//	osMessageQueuePut(screen1_isr_queue, &pitch_flag, 0, 0);

	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_10);
}

void EXTI15_IRQHandler(void) // BOUTON 7 - Range bas, gauche, premier bouton - PA15
{
	// static float test1 = 0.0f;
	// test1 += 0.1f;
	// memcpy(&canRx_mast_angle, &test1, sizeof(float));
	// static int mast_angle_flag = MAST_ANGLE_FLAG;
	// osMessageQueuePut(screen1_isr_queue, &mast_angle_flag, 0, 0);



	pb3_value = 1;
	pb3_update = 1;
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
}


/* USER CODE END 1 */
