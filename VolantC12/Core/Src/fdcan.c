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

float 	canRx_mast_angle 	= 0.0;
float 	canRx_pitch			= 0.0;
float 	canRx_wind_speed	= 0.0;
float 	canRx_wind_dir		= 0.0;
float 	canRx_wheel_rpm		= 0.0;
float 	canRx_turbine_rpm	= 0.0;

float	canRx_torque		= 0.0;

float 	canRx_power			= 0.0;
float 	canRx_efficiency	= 0.0;
float 	canRx_tsr			= 0.0;

/* Screen 1 */
uint8_t mast_angle_flag = MAST_ANGLE_FLAG;
uint8_t pitch_flag = PITCH_FLAG;
uint8_t wind_sp_flag = WIND_SP_FLAG;
uint8_t wind_dir_flag = WIND_DIR_FLAG;
uint8_t wheel_rpm_flag = WHEEL_RPM_FLAG;
uint8_t turb_rpm_flag = TURB_RPM_FLAG;

/* Screen 2 */
uint8_t power_flag = POWER_FLAG;
uint8_t eff_flag = EFF_FLAG;
uint8_t tsr_flag = TSR_FLAG;

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
  hfdcan1.Init.NominalSyncJumpWidth = 1;
  hfdcan1.Init.NominalTimeSeg1 = 11;
  hfdcan1.Init.NominalTimeSeg2 = 4;
  hfdcan1.Init.DataPrescaler = 1;
  hfdcan1.Init.DataSyncJumpWidth = 3;
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
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
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

	switch (rxHeader.Identifier) {

	    case MARIO_MAST_ANGLE:
	    	// Check if the received message data length is correct
	    	if (rxHeader.DataLength != 4) {
	    	    Error_Handler();
	    	} else {
	    	    // Interpret the received bytes as a float
	    	    memcpy(&canRx_mast_angle, rxData, sizeof(float));
	    	    osMessageQueuePut(screen1_isr_queue, &mast_angle_flag, 0, 0);
	    	}
	        break;

	    case MARIO_PITCH_ANGLE:
	    	// Check if the received message data length is correct
			if (rxHeader.DataLength != 4) {
				Error_Handler();
			} else {
				// Interpret the received bytes as a float
				memcpy(&canRx_pitch, rxData, sizeof(float));
				osMessageQueuePut(screen1_isr_queue, &pitch_flag, 0, 0);
			}
	        break;

	    case MARIO_WIND_SPEED:
	    	// Check if the received message data length is correct
			if (rxHeader.DataLength != 4) {
				Error_Handler();
			} else {
				// Interpret the received bytes as a float
				memcpy(&canRx_wind_speed, rxData, sizeof(float));
				osMessageQueuePut(screen1_isr_queue, &wind_sp_flag, 0, 0);
			}
	        break;

	    case MARIO_WIND_DIRECTION:
	    	// Check if the received message data length is correct
			if (rxHeader.DataLength != 4) {
				Error_Handler();
			} else {
				// Interpret the received bytes as a float
				memcpy(&canRx_wind_dir, rxData, sizeof(float));
				osMessageQueuePut(screen1_isr_queue, &wind_dir_flag, 0, 0);
			}
	        break;

	    case MARIO_WHEEL_RPM:
	    	// Check if the received message data length is correct
			if (rxHeader.DataLength != 4) {
				Error_Handler();
			} else {
				// Interpret the received bytes as a float
				memcpy(&canRx_wheel_rpm, rxData, sizeof(float));
				osMessageQueuePut(screen1_isr_queue, &wheel_rpm_flag, 0, 0);
			}
	        break;

	    case MARIO_ROTOR_RPM:
	    	// Check if the received message data length is correct
			if (rxHeader.DataLength != 4) {
				Error_Handler();
			} else {
				// Interpret the received bytes as a float
				memcpy(&canRx_turbine_rpm, rxData, sizeof(float));
				osMessageQueuePut(screen1_isr_queue, &turb_rpm_flag, 0, 0);
			}
	    	break;

	    case MARIO_TIP_SPEED_RATIO:
	    	// Check if the received message data length is correct
			if (rxHeader.DataLength != 4) {
				Error_Handler();
			} else {
				// Interpret the received bytes as a float
				memcpy(&canRx_tsr, rxData, sizeof(float));
				osMessageQueuePut(screen2_isr_queue, &tsr_flag, 0, 0);
			}
	        break;

	    case MARIO_TORQUE:
	    	// Check if the received message data length is correct
			if (rxHeader.DataLength != 4) {
				Error_Handler();
			} else {
				// Interpret the received bytes as a float
				memcpy(&canRx_torque, rxData, sizeof(float));
				osMessageQueuePut(screen2_isr_queue, &eff_flag, 0, 0);
				osMessageQueuePut(screen2_isr_queue, &tsr_flag, 0, 0);
			}
			break;

	    default:
	        // Unknown CAN ID
	        break;
	}

}


/**
 * @brief For testing buttons
 *
 * @param Unused
 * @return None
 */
void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin) {

	switch (GPIO_Pin) {

		    case GPIO_PIN_3:

		    	static float test1 = 0.0f;
				test1 += 0.1f;
				memcpy(&canRx_mast_angle, &test1, sizeof(float));
				osMessageQueuePut(screen1_isr_queue, &mast_angle_flag, 0, 0);

		        break;

		    case GPIO_PIN_4:

		    	static float test2 = 0.0f;
				test2 += 0.1f;
				memcpy(&canRx_pitch, &test2, sizeof(float));
				osMessageQueuePut(screen1_isr_queue, &pitch_flag, 0, 0);

		        break;

		    case GPIO_PIN_6:

		    	static float test3 = 0.0f;
		    	test3 += 0.1f;
		    	memcpy(&canRx_wind_speed, &test3, sizeof(float));
		    	osMessageQueuePut(screen1_isr_queue, &wind_sp_flag, 0, 0);

		        break;

		    case GPIO_PIN_7:

		    	static float test4 = 0.0f;
		    	test4 += 0.1f;
		    	memcpy(&canRx_wind_dir, &test4, sizeof(float));
		    	osMessageQueuePut(screen1_isr_queue, &wind_dir_flag, 0, 0);

		        break;

		    case GPIO_PIN_8:

		    	static float test5 = 0.0f;
		    	test5 += 0.1f;
		    	memcpy(&canRx_wheel_rpm, &test5, sizeof(float));
		    	osMessageQueuePut(screen1_isr_queue, &wheel_rpm_flag, 0, 0);

		    	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_5);

		        break;

		    default:
		        break;
		}
}




/**
 * @brief
 *
 * @param Unused
 * @return None
 */

//void HAL_GPIO_EXTI_Rising_Callback(uint16_t GPIO_Pin)	//TODO: Define the GPIO buttons
//{
//	/* Prepare Tx message Header */
//	txHeader.IdType              = FDCAN_STANDARD_ID;
//	txHeader.TxFrameType         = FDCAN_DATA_FRAME;
//	txHeader.ErrorStateIndicator = FDCAN_ESI_ACTIVE;
//	txHeader.BitRateSwitch       = FDCAN_BRS_OFF;
//	txHeader.FDFormat            = FDCAN_CLASSIC_CAN;
//	txHeader.TxEventFifoControl  = FDCAN_NO_TX_EVENTS;
//	txHeader.MessageMarker       = 0U;
//
//	// Button rising edge interrupt occurred, handle it here
//	switch (GPIO_Pin) {
//		case BUTTON_PITCH_MODE:
//			txHeader.Identifier          = VOLANT_PITCH_MODE_CMD;
//			txHeader.DataLength          = 4U;
//
//			uint8_t pitch_mode = 0x71;
//
//			/* Add message to TX FIFO */
//			if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &txHeader, &pitch_mode) != HAL_OK)
//			{
//			  Error_Handler();
//			}
//
//			break;
//
//		case BUTTON_PITCH_LEFT:
//			txHeader.Identifier          = VOLANT_MANUAL_PITCH_CMD;
//			txHeader.DataLength          = 4U;
//
//			uint8_t pitch_left = 0x01;	// pitch left
//
//			/* Add message to TX FIFO */
//			if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &txHeader, &pitch_left) != HAL_OK)
//			{
//			  Error_Handler();
//			}
//
//			break;
//
//		case BUTTON_PITCH_RIGHT:
//			txHeader.Identifier          = VOLANT_MANUAL_PITCH_CMD;
//			txHeader.DataLength          = 4U;
//
//			uint8_t pitch_right = 0x80;	// pitch right TODO: Check 0x200 value, because overflow
//
//			/* Add message to TX FIFO */
//			if (HAL_FDCAN_AddMessageToTxFifoQ(&hfdcan1, &txHeader, &pitch_right) != HAL_OK)
//			{
//			  Error_Handler();
//			}
//
//			break;
//
//		//TODO: Continue the rest of the commands
//		default:
//			break;
//	}
//}

/* USER CODE END 1 */
