/*
 * screen_tasks.c
 *
 *  Created on: Mar. 3, 2024
 *      Author: Gabriel
 */

#include "screen_tasks.h"
#include "tim.h"
#include "main.h"



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
volatile float turb_dir_value 			= 0;
volatile float turb_cmd_value 			= 0;
volatile float wind_dir_value 			= 0;
volatile float speed_value 				= 0;
volatile float tsr_value 				= 0;
volatile float gear_ratio_value 		= 0;
volatile float rotor_speed_value 		= 0;
volatile float rotor_rops_cmd_value 	= 0;
volatile float pitch_value		 		= 0;
volatile float efficiency_value 		= 0;
volatile float wind_speed_value 		= 0;
volatile float pitch_cmd_value	 		= 0;
volatile float debug_log_value_value 	= 0;
volatile float fps_counter_value 		= 0;

volatile float change_the_name 			= 0;


volatile float refresh_can_mast_angle;
volatile float refresh_can_pitch;
volatile float refresh_can_wind_speed;
volatile float refresh_can_wind_dir;
volatile float refresh_can_wheel_rpm;
volatile float refresh_can_turbine_rpm;

volatile float fps_counter_value_temps;


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
int test_refresh_rate = 0;

void screen1_task(void* arg)
{
	init_screen1();

	while (1) {
		//tests refresh du CAN
		if(timer7_1ms_counter % 1000 == 0) { //1sec
			fps_counter_value = fps_counter_value_temps;
			fps_counter_value_temps = 0;

			refresh_can_mast_angle = canRx_mast_angle_temps;
			refresh_can_pitch = canRx_pitch_temps;
			refresh_can_wind_speed = canRx_wind_speed_temps;
			refresh_can_wind_dir = canRx_wind_dir_temps;
			refresh_can_wheel_rpm = canRx_wheel_rpm_temps;
			refresh_can_turbine_rpm = canRx_turbine_rpm_temps;

			canRx_mast_angle_temps = 100000;
			canRx_pitch_temps = 100000;
			canRx_wind_speed_temps = 100000;
			canRx_wind_dir_temps = 100000;
			canRx_wheel_rpm_temps = 100000;
			canRx_turbine_rpm_temps = 100000;
		}

		//tests refresh de l'écran
		//test_refresh_rate += 1000;
		if(test_refresh_rate >= 90000) test_refresh_rate = 0;

		if(timer7_1ms_counter % 8 == 0) { //each 8 ms
			fps_counter_value_temps++; //fps counter

			turb_dir_value = test_refresh_rate;
			turb_cmd_value = test_refresh_rate;
			wind_dir_value = canRx_wind_dir + test_refresh_rate + refresh_can_wind_dir;
			speed_value = canRx_wheel_rpm + test_refresh_rate + refresh_can_wheel_rpm;
			tsr_value = canRx_mast_angle + test_refresh_rate + refresh_can_mast_angle;
			gear_ratio_value = test_refresh_rate;
			rotor_speed_value = canRx_turbine_rpm + test_refresh_rate + refresh_can_turbine_rpm;
			rotor_rops_cmd_value = test_refresh_rate;
			pitch_value = canRx_pitch + test_refresh_rate + refresh_can_pitch;
			efficiency_value = test_refresh_rate;
			wind_speed_value = canRx_wind_speed + test_refresh_rate + refresh_can_wind_speed;
			pitch_cmd_value = test_refresh_rate;
			debug_log_value_value = test_refresh_rate;
		}

		//keep it it's magic but it doesn't work without it : the more you add osMessageQueuePut the less the refresh rate is. One is 500FPS
		volatile uint8_t buf = POWER_FLAG;
		osMessageQueuePut(screen1_pres_queue, &buf, 0, 2);
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

	//TouchGFX_4_23_2_tutorial_after_generating_code_step_5 : add the 2 lines of code like change_the_name
	screen1.turb_dir_value = &turb_dir_value;
	screen1.turb_cmd_value = &turb_cmd_value;
	screen1.wind_dir_value = &wind_dir_value;
	screen1.speed_value = &speed_value;
	screen1.tsr_value = &tsr_value;
	screen1.rotor_speed_value = &rotor_speed_value;
	screen1.gear_ratio_value = &gear_ratio_value;
	screen1.rotor_rops_cmd_value = &rotor_rops_cmd_value;
	screen1.pitch_value = &pitch_value;
	screen1.efficiency_value = &efficiency_value;
	screen1.wind_speed_value = &wind_speed_value;
	screen1.pitch_cmd_value = &pitch_cmd_value;
	screen1.debug_log_1_value = &debug_log_1_value;
	screen1.debug_log_2_value = &debug_log_2_value;
	screen1.debug_log_3_value = &debug_log_3_value;
	screen1.debug_log_4_value = &debug_log_4_value;
	screen1.fps_counter_value = &fps_counter_value;

	screen1.change_the_name = &change_the_name;
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
	//screen2.data1 = &power;
	//screen2.data2 = &efficiency;
	//screen2.data3 = &tsr;

}
