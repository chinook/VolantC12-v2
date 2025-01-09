/*
 * chinook_can_ids.h
 *
 *  Created on May 24 2022 by Marc
 *
 *  Updated on A2024 by Thomas Maitre
 *  CAN IDs for 4 PCBs : backplane, mario, drivemotor, volantV2
 */

#ifndef INC_CHINOOK_CAN_IDS_H_
#define INC_CHINOOK_CAN_IDS_H_

//
// CONSTANTS, COMMANDS, STATES and VALUES shared by boards
// 0x?0 -> ? = group
// Emergency = 0x0X
// Mario = 0x1X
// Drive motor = 0x2X
// Volant CMD = 0x3X
// Mario to Volant infos = 0x4X


// Emergency 0x0X
#define CAN_ID_CMD_MARIO_ROPS  0x00	 //CMD
#define CAN_ID_CMD_VOLANT_MANUAL_ROPS 0x01	 //CMD
	#define ROPS_DISABLE 0 				//CONST
	#define ROPS_ENABLE 1 				//CONST
#define CAN_ID_STATE_DRIVEMOTOR_ROPS  0x02 	//STATE for mario
	#define ROPS_OFF 0	 				//CONST
	#define ROPS_IN_PROGRESS 2 			//CONST
	#define ROPS_DONE 4 				//CONST
	#define ROPS_MOTOR_STALL 8 			//CONST


// Motor modes
#define CAN_ID_CMD_MARIO_PITCH_MODE  0x11		//CMD mario to drive motor
#define CAN_ID_CMD_MARIO_MAST_MODE	 0x12 		//CMD mario to drive motor
#define CAN_ID_STATE_DRIVEMOTOR_PITCH_MODE 0x21 //VALUE for mario
#define CAN_ID_STATE_DRIVEMOTOR_MAST_MODE  0x22 //VALUE for mario
	#define MOTOR_MODE_MANUAL 0 		//CONST
	#define MOTOR_MODE_AUTOMATIC 2		//CONST

// Manual motor control
#define CAN_ID_CMD_MARIO_PITCH_DIRECTION  0x13	//CMD mario to drive motor
#define CAN_ID_CMD_MARIO_MAST_DIRECTION	  0x14 	//CMD mario to drive motor
	#define MOTOR_DIRECTION_LEFT  0		//CONST
	#define MOTOR_DIRECTION_STOP  2		//CONST
	#define MOTOR_DIRECTION_RIGHT 4		//CONST
#define CAN_ID_DRIVEMOTOR_PITCH_MOVE_DONE 0x23 	//need to be removed

// motor SPEED in % 0 to 100
#define CAN_ID_CMD_MARIO_PITCH_SPEED  0x15	//CMD mario to drive motor
#define CAN_ID_CMD_MARIO_MAST_SPEED	  0x16 	//CMD mario to drive motor

// Automatic motor control
// nothing for now


// INFO errors for motors
#define DRIVEMOTOR_PITCH_FAULT_STALL 0x24 //INFO for mario
#define DRIVEMOTOR_MAST_FAULT_STALL 0x25 //INFO for mario
	//CONST TO DO

// STATUS buttons Volant to Mario IDs 0x3X //one ID in which each bit in the data are a button
#define CAN_ID_STATUS_BUTTONS 	0x30 //CMD volant to mario
	#define CAN_STATUS_PRESS 	1					//CONST
	#define CAN_STATUS_UNPRESS 	0					//CONST
	#define CAN_BIT_POSITION_BUTTON_HGG 	1		//CONST
	#define CAN_BIT_POSITION_BUTTON_HG 		2		//CONST
	#define CAN_BIT_POSITION_BUTTON_HD 		4		//CONST
	#define CAN_BIT_POSITION_BUTTON_HDD 	8		//CONST
	#define CAN_BIT_POSITION_BUTTON_MG 		16		//CONST
	#define CAN_BIT_POSITION_BUTTON_MD 		32		//CONST
	#define CAN_BIT_POSITION_BUTTON_BGG 	64		//CONST
	#define CAN_BIT_POSITION_BUTTON_BG 		128		//CONST
	#define CAN_BIT_POSITION_BUTTON_BD 		256		//CONST
	#define CAN_BIT_POSITION_BUTTON_BDD 	512		//CONST


// INFO Mario to Volant IDs 0x4X -> refer in volant files to: TouchGFX_4_23_2_tutorial_after_generating_code_step
#define CAN_ID_MARIO_VAL_TURB_DIR 			0x40
#define CAN_ID_MARIO_VAL_TURB_CMD 			0x41
#define CAN_ID_MARIO_VAL_WIND_DIR 			0x42
#define CAN_ID_MARIO_VAL_SPEED 				0x43
#define CAN_ID_MARIO_VAL_TSR 				0x44
#define CAN_ID_MARIO_VAL_GEAR_RATIO 		0x45
#define CAN_ID_MARIO_VAL_ROTOR_SPEED 		0x46
#define CAN_ID_MARIO_VAL_ROTOR_ROPS_CMD 	0x47
#define CAN_ID_MARIO_VAL_PITCH 				0x48
#define CAN_ID_MARIO_VAL_EFFICIENCY 		0x49
#define CAN_ID_MARIO_VAL_WIND_SPEED 		0x4A
#define CAN_ID_MARIO_VAL_PITCH_CMD 			0x4B
#define CAN_ID_MARIO_VAL_DEBUG_LOG_1 		0x4C
#define CAN_ID_MARIO_VAL_DEBUG_LOG_2 		0x4D
#define CAN_ID_MARIO_VAL_DEBUG_LOG_3 		0x4E
#define CAN_ID_MARIO_VAL_DEBUG_LOG_4 		0x4F



// FIFO0 - Priority filter
#define FIFO0_RX_FILTER_MASK_HIGH 0xFFFF
#define FIFO0_RX_FILTER_MASK_LOW  0xFFE0

#define MARIO_FIFO0_RX_FILTER_ID_HIGH 0x40
#define MARIO_FIFO0_RX_FILTER_ID_LOW  0x40

#define DRIVEMOTOR_FIFO0_RX_FILTER_ID_HIGH 0x0000
#define DRIVEMOTOR_FIFO0_RX_FILTER_ID_LOW  0x0060

#define BACKPLANE_FIFO0_RX_FILTER_ID_HIGH 0x0000
#define BACKPLANE_FIFO0_RX_FILTER_ID_LOW  0x0080

//FIFO1 - Low priority filter
#define FIFO1_RX_FILTER_MASK_HIGH 0xFFFF
#define FIFO1_RX_FILTER_MASK_LOW  0xFFE0

#define FIFO1_RX_FILTER_ID_HIGH 0x40
#define FIFO1_RX_FILTER_ID_LOW  0x41

#define DRIVEMOTOR_FIFO1_RX_FILTER_ID_HIGH 0x0000
#define DRIVEMOTOR_FIFO1_RX_FILTER_ID_LOW  0x0070



#endif /* INC_CHINOOK_CAN_IDS_H_ */
