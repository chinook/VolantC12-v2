/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    fdcan.c
  * @brief   This file provides code for the configuration
  *          of the FDCAN instances.
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
#include "fdcan.h"

/* USER CODE BEGIN 0 */
static void configure_fdcan_filters(void);
static void process_can_message(void);

FDCAN_RxHeaderTypeDef 	rxHeader;
FDCAN_TxHeaderTypeDef 	txHeader;
uint8_t 				rxData[8U];		// 8 bytes

float	canRx_torque		= 0;

float 	canRx_turb_dir_value 		= 0;
float 	canRx_turb_cmd_value 		= 0;
float 	canRx_wind_dir_value 		= 0;
float 	canRx_speed_value 			= 0;
float 	canRx_tsr_value 			= 0;
float 	canRx_gear_ratio_value 		= 0;
float 	canRx_rotor_speed_value 	= 0;
float 	canRx_rotor_rops_cmd_value 	= 0;
float 	canRx_pitch_value 			= 0;
float 	canRx_efficiency_value 		= 0;
float 	canRx_wind_speed_value 		= 0;
float 	canRx_pitch_cmd_value 		= 0;
float 	canRx_debug_log_1_value 	= 0;
float 	canRx_debug_log_2_value 	= 0;
float 	canRx_debug_log_3_value 	= 0;
float 	canRx_debug_log_4_value 	= 0;

float 	canRx_refresh_turb_dir_value 		= 0;
float 	canRx_refresh_turb_cmd_value 		= 0;
float 	canRx_refresh_wind_dir_value 		= 0;
float 	canRx_refresh_speed_value 			= 0;
float 	canRx_refresh_tsr_value 			= 0;
float 	canRx_refresh_gear_ratio_value 		= 0;
float 	canRx_refresh_rotor_speed_value 	= 0;
float 	canRx_refresh_rotor_rops_cmd_value 	= 0;
float 	canRx_refresh_pitch_value 			= 0;
float 	canRx_refresh_efficiency_value 		= 0;
float 	canRx_refresh_wind_speed_value 		= 0;
float 	canRx_refresh_pitch_cmd_value 		= 0;
float 	canRx_refresh_debug_log_1_value 	= 0;
float 	canRx_refresh_debug_log_2_value 	= 0;
float 	canRx_refresh_debug_log_3_value 	= 0;
float 	canRx_refresh_debug_log_4_value 	= 0;

/* USER CODE END 0 */

FDCAN_HandleTypeDef hfdcan1;

/* FDCAN1 init function */
void MX_FDCAN1_Init(void)
{

  /* USER CODE BEGIN FDCAN1_Init 0 */

  /* USER CODE END FDCAN1_Init 0 */

  /* USER CODE BEGIN FDCAN1_Init 1 */

  /* USER CODE END FDCAN1_Init 1 */
  hfdcan1.Instance = FDCAN1;
  hfdcan1.Init.ClockDivider = FDCAN_CLOCK_DIV1;
  hfdcan1.Init.FrameFormat = FDCAN_FRAME_CLASSIC;
  hfdcan1.Init.Mode = FDCAN_MODE_NORMAL;
  hfdcan1.Init.AutoRetransmission = DISABLE;
  hfdcan1.Init.TransmitPause = DISABLE;
  hfdcan1.Init.ProtocolException = DISABLE;
  hfdcan1.Init.NominalPrescaler = 40;
  hfdcan1.Init.NominalSyncJumpWidth = 3;
  hfdcan1.Init.NominalTimeSeg1 = 11;
  hfdcan1.Init.NominalTimeSeg2 = 4;
  hfdcan1.Init.DataPrescaler = 1;
  hfdcan1.Init.DataSyncJumpWidth = 1;
  hfdcan1.Init.DataTimeSeg1 = 1;
  hfdcan1.Init.DataTimeSeg2 = 1;
  hfdcan1.Init.StdFiltersNbr = 0;
  hfdcan1.Init.ExtFiltersNbr = 0;
  hfdcan1.Init.TxFifoQueueMode = FDCAN_TX_FIFO_OPERATION;
  if (HAL_FDCAN_Init(&hfdcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN FDCAN1_Init 2 */

  configure_fdcan_filters();

  /* USER CODE END FDCAN1_Init 2 */

}

void HAL_FDCAN_MspInit(FDCAN_HandleTypeDef* fdcanHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};
  if(fdcanHandle->Instance==FDCAN1)
  {
  /* USER CODE BEGIN FDCAN1_MspInit 0 */

  /* USER CODE END FDCAN1_MspInit 0 */

  /** Initializes the peripherals clock
  */
    PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_FDCAN1;
    PeriphClkInit.Fdcan1ClockSelection = RCC_FDCAN1CLKSOURCE_PLL1;
    if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
    {
      Error_Handler();
    }

    /* FDCAN1 clock enable */
    __HAL_RCC_FDCAN1_CLK_ENABLE();

    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**FDCAN1 GPIO Configuration
    PB9     ------> FDCAN1_TX
    PB8     ------> FDCAN1_RX
    */
    GPIO_InitStruct.Pin = GPIO_PIN_9|GPIO_PIN_8;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.Alternate = GPIO_AF9_FDCAN1;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* FDCAN1 interrupt Init */
    HAL_NVIC_SetPriority(FDCAN1_IT0_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(FDCAN1_IT0_IRQn);
    HAL_NVIC_SetPriority(FDCAN1_IT1_IRQn, 5, 0);
    HAL_NVIC_EnableIRQ(FDCAN1_IT1_IRQn);
  /* USER CODE BEGIN FDCAN1_MspInit 1 */

  /* USER CODE END FDCAN1_MspInit 1 */
  }
}

void HAL_FDCAN_MspDeInit(FDCAN_HandleTypeDef* fdcanHandle)
{

  if(fdcanHandle->Instance==FDCAN1)
  {
  /* USER CODE BEGIN FDCAN1_MspDeInit 0 */

  /* USER CODE END FDCAN1_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_FDCAN1_CLK_DISABLE();

    /**FDCAN1 GPIO Configuration
    PB9     ------> FDCAN1_TX
    PB8     ------> FDCAN1_RX
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_9|GPIO_PIN_8);

    /* FDCAN1 interrupt Deinit */
    HAL_NVIC_DisableIRQ(FDCAN1_IT0_IRQn);
    HAL_NVIC_DisableIRQ(FDCAN1_IT1_IRQn);
  /* USER CODE BEGIN FDCAN1_MspDeInit 1 */

  /* USER CODE END FDCAN1_MspDeInit 1 */
  }
}

/* USER CODE BEGIN 1 */

/**
  * @brief
  *
  * @param Unused
  * @return None
  */
void configure_fdcan_filters(void)
{
//	/* Configure reception filter to Rx FIFO 0 */
//	FDCAN_FilterTypeDef        sFilterConfig;
//	sFilterConfig.IdType       = FDCAN_STANDARD_ID;
//	sFilterConfig.FilterIndex  = 0U;
//	sFilterConfig.FilterType   = FDCAN_FILTER_MASK;
//	sFilterConfig.FilterConfig = FDCAN_FILTER_TO_RXFIFO0;
//	sFilterConfig.FilterID1    = 0x40;	// 0x40 to
//	sFilterConfig.FilterID2    = 0x5F;	// 0x5F (inclusive)
//	if (HAL_FDCAN_ConfigFilter(&hfdcan1, &sFilterConfig) != HAL_OK)
//	{
//	  Error_Handler();
//	}

	/* Activate Rx FIFO 0 new message notification */
	if (HAL_FDCAN_ActivateNotification(&hfdcan1, FDCAN_IT_RX_FIFO0_NEW_MESSAGE, 0U) != HAL_OK)
	{
	  Error_Handler();
	}

	/**
	*  Configure global filter:
	*    - Filter all remote frames with STD and EXT ID
	*    - Reject non matching frames with STD ID and EXT ID
	*/
//	if (HAL_FDCAN_ConfigGlobalFilter(&hfdcan1,
//									 FDCAN_REJECT, FDCAN_REJECT,
//									 FDCAN_FILTER_REMOTE, FDCAN_FILTER_REMOTE) != HAL_OK)
//	{
//	  Error_Handler();
//	}
}

/**
  * @brief  Rx FIFO 0 callback.
  * @param  hfdcan pointer to an FDCAN_HandleTypeDef structure that contains
  *         the configuration information for the specified FDCAN.
  * @param  RxFifo0ITs indicates which Rx FIFO 0 interrupts are signaled.
  *         This parameter can be any combination of @arg FDCAN_Rx_Fifo0_Interrupts.
  */
void HAL_FDCAN_RxFifo0Callback(FDCAN_HandleTypeDef *hfdcan, uint32_t RxFifo0ITs)
{
  if ((RxFifo0ITs & FDCAN_IT_RX_FIFO0_NEW_MESSAGE) != 0U)
  {
    /* Retrieve Rx messages from RX FIFO0 */
    if (HAL_FDCAN_GetRxMessage(hfdcan, FDCAN_RX_FIFO0, &rxHeader, rxData) != HAL_OK)
    {
      Error_Handler();
    }

    HAL_GPIO_TogglePin(USR_LED_1_GPIO_Port, USR_LED_1_Pin);

    process_can_message();

  }
}

/**
 * @brief
 *
 * @param Unused
 * @return None
 */
void process_can_message(void)
{
	// Technically CAN data can be 8+ bytes but we only send 4-bytes data to the motor driver
	// uint32_t upper_can_data = rxData[4] | (rxData[5] << 8) | (rxData[6] << 16) | (rxData[7] << 24);
	//	uint32_t can_data = rxData[0] | (rxData[1] << 8) | (rxData[2] << 16) | (rxData[3] << 24);

	// Check if the received message data length is correct
	if (rxHeader.DataLength != 4) {
		Error_Handler();
	} else {
		switch (rxHeader.Identifier) {
	    	case CAN_ID_MARIO_VAL_TURB_DIR:
	    		if (canRx_refresh_turb_dir_value < 800000) canRx_refresh_turb_dir_value += 100000;
	    		memcpy(&canRx_turb_dir_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_TURB_CMD:
	    		if (canRx_refresh_turb_cmd_value < 800000) canRx_refresh_turb_cmd_value += 100000;
	    		memcpy(&canRx_turb_cmd_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_WIND_DIR:
	    		if (canRx_refresh_wind_dir_value < 800000) canRx_refresh_wind_dir_value += 100000;
	    		memcpy(&canRx_wind_dir_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_SPEED:
	    		if (canRx_refresh_speed_value < 800000) canRx_refresh_speed_value += 100000;
	    		memcpy(&canRx_speed_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_TSR:
	    		if (canRx_refresh_tsr_value < 800000) canRx_refresh_tsr_value += 100000;
	    		memcpy(&canRx_tsr_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_GEAR_RATIO:
	    		if (canRx_refresh_gear_ratio_value < 800000) canRx_refresh_gear_ratio_value += 100000;
	    		memcpy(&canRx_gear_ratio_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_ROTOR_SPEED:
	    		if (canRx_refresh_rotor_speed_value < 800000) canRx_refresh_rotor_speed_value += 100000;
	    		memcpy(&canRx_rotor_speed_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_ROTOR_ROPS_CMD:
	    		if (canRx_refresh_rotor_rops_cmd_value < 800000) canRx_refresh_rotor_rops_cmd_value += 100000;
	    		memcpy(&canRx_rotor_rops_cmd_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_PITCH:
	    		if (canRx_refresh_pitch_value < 800000) canRx_refresh_pitch_value += 100000;
	    		memcpy(&canRx_pitch_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_EFFICIENCY:
	    		if (canRx_refresh_efficiency_value < 800000) canRx_refresh_efficiency_value += 100000;
	    		memcpy(&canRx_efficiency_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_WIND_SPEED:
	    		if (canRx_refresh_wind_speed_value < 800000) canRx_refresh_wind_speed_value += 100000;
	    		memcpy(&canRx_wind_speed_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_PITCH_CMD:
	    		if (canRx_refresh_pitch_cmd_value < 800000) canRx_refresh_pitch_cmd_value += 100000;
	    		memcpy(&canRx_pitch_cmd_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_DEBUG_LOG_1:
	    		if (canRx_refresh_debug_log_1_value < 800000) canRx_refresh_debug_log_1_value += 100000;
	    		memcpy(&canRx_debug_log_1_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_DEBUG_LOG_2:
	    		if (canRx_refresh_debug_log_2_value < 800000) canRx_refresh_debug_log_2_value += 100000;
	    		memcpy(&canRx_debug_log_2_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_DEBUG_LOG_3:
	    		if (canRx_refresh_debug_log_3_value < 800000) canRx_refresh_debug_log_3_value += 100000;
	    		memcpy(&canRx_debug_log_3_value, rxData, sizeof(float));
	    		break;
	    	case CAN_ID_MARIO_VAL_DEBUG_LOG_4:
	    		if (canRx_refresh_debug_log_4_value < 800000) canRx_refresh_debug_log_4_value += 100000;
	    		memcpy(&canRx_debug_log_4_value, rxData, sizeof(float));
	    		break;

	    	default:
	    		// Unknown CAN ID
	    		break;
		}
	}
}

/* USER CODE END 1 */
