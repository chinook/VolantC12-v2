/*
 * screen_tasks.c
 *
 *  Created on: Mar. 3, 2024
 *      Author: Gabriel
 */

#include "screen_tasks.h"


#define QUEUE_SIZE			(50)


/* Variables used by the Model object */
volatile uint8_t desired_screen = 0;
volatile uint8_t active_screen_index = 0;
volatile ui_t screen1;
volatile ui_t screen2;

/**
 * Array used to reset the message queue in order
 * to refresh all containers on the screen when
 * there is a screen change request.
 */
volatile uint8_t arr[NUM_FIELDS] = {0x1, 0x2, 0x4, 0x8, 0x10, 0x20};

/* Screen1 data variables */
volatile float mast_angle 	= 10.1;
volatile float pitch 		= 10.1;
volatile float wind_speed 	= 10.1;
volatile float wind_dir 	= 10.1;
volatile float wheel_rpm 	= 10.1;
volatile float turbine_rpm 	= 10.1;

/* Screen2 data variables */
volatile float power 		= 10.01;
volatile float efficiency 	= 10.01;
volatile float tsr 			= 10.01;

/**
 * Message queues shared between the screen tasks
 * and the Presenter objects.
 */
osMessageQueueId_t screen1_pres_queue;
osMessageQueueId_t screen2_pres_queue;

/**
 * Message queues shared between the screen tasks
 * and the ISR.
 */
osMessageQueueId_t screen1_isr_queue;
osMessageQueueId_t screen2_isr_queue;

/* Private functions */
static void init_screen1(void);
static void init_screen2(void);

/**
 * @brief Task for processing data for screen 1.
 *
 * It initializes screen1 and its associated message queue,
 * then enters an infinite loop where it waits for messages
 * from the ISR queue. Upon receiving a message, it processes
 * the data accordingly and forwards it to the presentation
 * layer queue for display.
 *
 * @param Unused
 * @return None
 */
void screen1_task(void* arg)
{
	uint8_t buf = 0;
	init_screen1();

	while (1) {
		osDelay(1);
		if (osMessageQueueGet(screen1_isr_queue, &buf, 0, 0) == osOK) {
			switch (buf) {
			case MAST_ANGLE_FLAG:
				/* Process data from the ISR */
				mast_angle = canRx_mast_angle;
				break;
			case PITCH_FLAG:
				/* Process data from the ISR */
				pitch = canRx_pitch;
				break;
			case WIND_SP_FLAG:
				/* Process data from the ISR */
				wind_speed = canRx_wind_speed;
				break;
			case WIND_DIR_FLAG:
				/* Process data from the ISR */
				wind_dir = canRx_wind_dir;
				break;
			case WHEEL_RPM_FLAG:
				/* Process data from the ISR */
				wheel_rpm = canRx_wheel_rpm;
				break;
			case TURB_RPM_FLAG:
				/* Process data from the ISR */
				turbine_rpm = canRx_turbine_rpm;
				break;
			default:
				buf = 0;
				break;
			}

			if (buf) {
				osMessageQueuePut(screen1_pres_queue, &buf, 0, 2);
				buf = 0;
			}
		}
	}
}

/**
 * @brief Task for processing data for screen 2.
 *
 * It initializes screen2 and its associated message queue,
 * then enters an infinite loop where it waits for messages
 * from the ISR queue. Upon receiving a message, it processes
 * the data accordingly and forwards it to the presentation
 * layer queue for display.
 *
 * @param Unused
 * @return None
 */
void screen2_task(void* arg)
{
	uint8_t buf = 0;
	float eff_power = 0.0;
	init_screen2();

	while (1) {
		osDelay(1);
		if (osMessageQueueGet(screen2_isr_queue, &buf, 0, 0) == osOK) {
			switch (buf) {
			case POWER_FLAG:
				/* Process data from the ISR */
				power = canRx_turbine_rpm * canRx_torque * 2 * 3.14159 / 60;
				break;
			case EFF_FLAG:
				/* Process data from the ISR */
				eff_power 	= canRx_turbine_rpm * canRx_torque * 2 * 3.14159 / 60;
				efficiency	= eff_power / canRx_wind_speed;
				break;
			case TSR_FLAG:
				/* Process data from the ISR */
				tsr = canRx_turbine_rpm * 3.14159 * 0.5 / canRx_wind_speed;

				// Other calcul
//				rotor_speed_omega 	= canRx_turbine_rpm * PI / 30;
//				wind_speed_ms		= 0.51444 * canRx_wind_speed;
//				tsr 				= (PALE_RADIUS * rotor_speed_omega) / wind_speed_ms;

				break;
			default:
				buf = 0;
				break;
			}

			if (buf) {
				osMessageQueuePut(screen2_pres_queue, &buf, 0, 2);
				buf = 0;
			}
		}
	}
}

/* Task used for development */
void test_task(void* arg)
{
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

	turbine_rpm = 2000;
	power = 0;

	while (1) {
		osDelay(300);

		mast_angle++;
		pitch--;
		wind_speed++;
		wind_dir--;
		wheel_rpm++;
		turbine_rpm--;

		power++;
		efficiency--;
		tsr++;

		osMessageQueuePut(screen1_isr_queue, &mast_angle_flag, 0, 0);
		osMessageQueuePut(screen1_isr_queue, &pitch_flag, 0, 0);
		osMessageQueuePut(screen1_isr_queue, &wind_sp_flag, 0, 0);
		osMessageQueuePut(screen1_isr_queue, &wind_dir_flag, 0, 0);
		osMessageQueuePut(screen1_isr_queue, &wheel_rpm_flag, 0, 0);
		osMessageQueuePut(screen1_isr_queue, &turb_rpm_flag, 0, 0);

		osMessageQueuePut(screen2_isr_queue, &power_flag, 0, 0);
		osMessageQueuePut(screen2_isr_queue, &eff_flag, 0, 0);
		osMessageQueuePut(screen2_isr_queue, &tsr_flag, 0, 0);

	}
}

/**
 * @brief Initializes the message queues for communication
 * between the screen1 task and the page1Presenter object,
 * as well as between the screen1 task and the ISR. Additionally,
 * it binds the data variables with their respective fields
 * on the screen (data#).
 *
 * @param None
 * @retval None
 */
static void init_screen1(void)
{
	screen1_pres_queue = osMessageQueueNew(QUEUE_SIZE, sizeof(char), NULL);
	screen1_isr_queue = osMessageQueueNew(QUEUE_SIZE, sizeof(char), NULL);

	/* Bind the variables to the proper data field */
	screen1.data1 = &mast_angle;
	screen1.data2 = &pitch;
	screen1.data3 = &wind_speed;
	screen1.data4 = &wind_dir;
	screen1.data5 = &wheel_rpm;
	screen1.data6 = &turbine_rpm;
}

/**
 * @brief Initializes the message queues for communication
 * between the screen2 task and the page2Presenter object,
 * as well as between the screen1 task and the ISR. Additionally,
 * it binds the data variables with their respective fields
 * on the screen (data#).
 *
 * @param None
 * @retval None
 */
static void init_screen2(void)
{
	screen2_pres_queue = osMessageQueueNew(QUEUE_SIZE, sizeof(char), NULL);
	screen2_isr_queue = osMessageQueueNew(QUEUE_SIZE, sizeof(char), NULL);

	/* Bind the variables to the proper data field */
	screen2.data1 = &power;
	screen2.data2 = &efficiency;
	screen2.data3 = &tsr;

}
