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
float turb_dir_value 			= 0;
float turb_cmd_value 			= 0;
float wind_dir_value 			= 0;
float speed_value 				= 0;
float tsr_value 				= 0;
float gear_ratio_value 			= 0;
float rotor_speed_value 		= 0;
float rotor_rops_cmd_value 		= 0;
float pitch_value		 		= 0;
float efficiency_value 			= 0;
float wind_speed_value 			= 0;
float pitch_cmd_value	 		= 0;
float debug_log_1_value 		= 0;
float debug_log_2_value 		= 0;
float debug_log_3_value 		= 0;
float debug_log_4_value 		= 0;
float fps_counter_value 		= 0;

float change_the_name 			= 0;


float can_refresh_turb_dir_value 			= 0;
float can_refresh_turb_cmd_value 			= 0;
float can_refresh_wind_dir_value 			= 0;
float can_refresh_speed_value 				= 0;
float can_refresh_tsr_value 				= 0;
float can_refresh_gear_ratio_value 			= 0;
float can_refresh_rotor_speed_value 		= 0;
float can_refresh_rotor_rops_cmd_value 		= 0;
float can_refresh_pitch_value		 		= 0;
float can_refresh_efficiency_value 			= 0;
float can_refresh_wind_speed_value 			= 0;
float can_refresh_pitch_cmd_value	 		= 0;
float can_refresh_debug_log_1_value 		= 0;
float can_refresh_debug_log_2_value 		= 0;
float can_refresh_debug_log_3_value 		= 0;
float can_refresh_debug_log_4_value 		= 0;
float can_refresh_fps_counter_value 		= 0;

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

//GPIO_PIN_SET == pas appuyé
//GPIO_PIN_RESET == appuyé
//h = haut, m = milieu, b = bas, g = gauche et d = droit
uint8_t flag_bouton_hgg = 0; 	//PG2
uint8_t flag_bouton_hg = 0; 	//PB10
uint8_t flag_bouton_hd = 0;		//PA7
uint8_t flag_bouton_hdd = 0;	//PA6

uint8_t flag_bouton_mg = 0;		//PB5
uint8_t flag_bouton_md = 0;		//PA8

uint8_t flag_bouton_bgg = 0;	//PA15
uint8_t flag_bouton_bg = 0;		//PB0
uint8_t flag_bouton_bd = 0;		//PA4
uint8_t flag_bouton_bdd = 0;	//PA3

uint8_t status_bouton_hgg = 0;
uint8_t status_bouton_hg = 0;
uint8_t status_bouton_hd = 0;
uint8_t status_bouton_hdd = 0;
uint8_t status_bouton_mg = 0;
uint8_t status_bouton_md = 0;
uint8_t status_bouton_bgg = 0;
uint8_t status_bouton_bg = 0;
uint8_t status_bouton_bd = 0;
uint8_t status_bouton_bdd = 0;


uint8_t check_button_status(uint8_t *flag_bouton_x, const GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN_X);
uint32_t compile_button_status_to_ONE_can_data();

uint8_t round_robin_traitement_buttons = 0;
void traitement_boutons() {
	status_bouton_hgg = check_button_status(&flag_bouton_hgg, GPIOG, GPIO_PIN_2);
	status_bouton_hg = check_button_status(&flag_bouton_hg,  GPIOB, GPIO_PIN_10);
	status_bouton_hd = check_button_status(&flag_bouton_hd,  GPIOA, GPIO_PIN_7);
	status_bouton_hdd = check_button_status(&flag_bouton_hdd, GPIOA, GPIO_PIN_6);
	status_bouton_mg = check_button_status(&flag_bouton_mg,  GPIOB, GPIO_PIN_5);
	status_bouton_md = check_button_status(&flag_bouton_md,  GPIOA, GPIO_PIN_8);
	status_bouton_bgg = check_button_status(&flag_bouton_bgg, GPIOA, GPIO_PIN_15);
	status_bouton_bg = check_button_status(&flag_bouton_bg,  GPIOB, GPIO_PIN_0);
	status_bouton_bd = check_button_status(&flag_bouton_bd,  GPIOA, GPIO_PIN_4);
	status_bouton_bdd = check_button_status(&flag_bouton_bdd, GPIOA, GPIO_PIN_3);
	uint32_t data = compile_button_status_to_ONE_can_data();
	SendCAN(CAN_ID_STATUS_BUTTONS, (uint8_t*)&data);
}

uint8_t check_button_status(uint8_t *flag_bouton_x, const GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN_X) {
	uint8_t cmd = CAN_STATUS_UNPRESS;
	if (*flag_bouton_x == 1) {
		if (HAL_GPIO_ReadPin(GPIOx, GPIO_PIN_X) == GPIO_PIN_RESET) { //bouton est appuyé par le pilote
			cmd = CAN_STATUS_PRESS;
		} else {
			*flag_bouton_x = 0;
		}
	}
	return cmd;
}

uint32_t compile_button_status_to_ONE_can_data() {
	uint32_t data = 0;
	if (status_bouton_hgg == CAN_STATUS_PRESS) data += CAN_BIT_POSITION_BUTTON_HGG;
	if (status_bouton_hg  == CAN_STATUS_PRESS) data += CAN_BIT_POSITION_BUTTON_HG;
	if (status_bouton_hd  == CAN_STATUS_PRESS) data += CAN_BIT_POSITION_BUTTON_HD;
	if (status_bouton_hdd == CAN_STATUS_PRESS) data += CAN_BIT_POSITION_BUTTON_HDD;
	if (status_bouton_mg  == CAN_STATUS_PRESS) data += CAN_BIT_POSITION_BUTTON_MG;
	if (status_bouton_md  == CAN_STATUS_PRESS) data += CAN_BIT_POSITION_BUTTON_MD;
	if (status_bouton_bgg == CAN_STATUS_PRESS) data += CAN_BIT_POSITION_BUTTON_BGG;
	if (status_bouton_bg  == CAN_STATUS_PRESS) data += CAN_BIT_POSITION_BUTTON_BG;
	if (status_bouton_bd  == CAN_STATUS_PRESS) data += CAN_BIT_POSITION_BUTTON_BD;
	if (status_bouton_bdd == CAN_STATUS_PRESS) data += CAN_BIT_POSITION_BUTTON_BDD;
	return data;
}

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
int test_screen_refresh_rate = 0;

void screen1_task(void* arg)
{
	init_screen1();



	while (1) {


		if (timer7_1ms_flag == 1);
			timer7_1ms_flag = 0;

			//keep it it's magic but it doesn't work without it : the more you add osMessageQueuePut the less the refresh rate is. One is 500FPS
			volatile uint8_t buf = POWER_FLAG;
			osMessageQueuePut(screen1_pres_queue, &buf, 0, 2);

			if(timer7_1ms_counter % 4 == 0) {
				traitement_boutons();
			}

			//tests refresh du CAN
			if(timer7_1ms_counter % 1000 == 0) { //1sec
				fps_counter_value = fps_counter_value_temps;
				fps_counter_value_temps = 0;

				can_refresh_turb_dir_value 			= canRx_refresh_turb_dir_value;
				can_refresh_turb_cmd_value 			= canRx_refresh_turb_cmd_value;
				can_refresh_wind_dir_value 			= canRx_refresh_wind_dir_value;
				can_refresh_speed_value 			= canRx_refresh_speed_value;
				can_refresh_tsr_value 				= canRx_refresh_tsr_value;
				can_refresh_gear_ratio_value 		= canRx_refresh_gear_ratio_value;
				can_refresh_rotor_speed_value 		= canRx_refresh_rotor_speed_value;
				can_refresh_rotor_rops_cmd_value 	= canRx_refresh_rotor_rops_cmd_value;
				can_refresh_pitch_value		 		= canRx_refresh_pitch_value;
				can_refresh_efficiency_value 		= canRx_refresh_efficiency_value;
				can_refresh_wind_speed_value 		= canRx_refresh_wind_speed_value;
				can_refresh_pitch_cmd_value	 		= canRx_refresh_pitch_cmd_value;
				can_refresh_debug_log_1_value 		= canRx_refresh_debug_log_1_value;
				can_refresh_debug_log_2_value 		= canRx_refresh_debug_log_2_value;
				can_refresh_debug_log_3_value 		= canRx_refresh_debug_log_3_value;
				can_refresh_debug_log_4_value 		= canRx_refresh_debug_log_4_value;

				canRx_refresh_turb_dir_value 		= 100000;
				canRx_refresh_turb_cmd_value 		= 100000;
				canRx_refresh_wind_dir_value 		= 100000;
				canRx_refresh_speed_value 			= 100000;
				canRx_refresh_tsr_value 			= 100000;
				canRx_refresh_gear_ratio_value 		= 100000;
				canRx_refresh_rotor_speed_value 	= 100000;
				canRx_refresh_rotor_rops_cmd_value 	= 100000;
				canRx_refresh_pitch_value 			= 100000;
				canRx_refresh_efficiency_value 		= 100000;
				canRx_refresh_wind_speed_value 		= 100000;
				canRx_refresh_pitch_cmd_value 		= 100000;
				canRx_refresh_debug_log_1_value 	= 100000;
				canRx_refresh_debug_log_2_value 	= 100000;
				canRx_refresh_debug_log_3_value 	= 100000;
				canRx_refresh_debug_log_4_value 	= 100000;


			}

			//tests refresh de l'écran
			//test_refresh_rate += 1000;
			if(test_screen_refresh_rate >= 90000) test_screen_refresh_rate = 0;

			if(timer7_1ms_counter % 8 == 0) { //each 8 ms
				fps_counter_value_temps++; //fps counter

				turb_dir_value 			= canRx_turb_dir_value 			+ can_refresh_turb_dir_value 		+ test_screen_refresh_rate;
				turb_cmd_value 			= canRx_turb_cmd_value 			+ can_refresh_turb_cmd_value 		+ test_screen_refresh_rate;
				wind_dir_value 			= canRx_wind_dir_value 			+ can_refresh_wind_dir_value 		+ test_screen_refresh_rate;
				speed_value 			= canRx_speed_value 			+ can_refresh_speed_value 			+ test_screen_refresh_rate;
				tsr_value 				= canRx_tsr_value 				+ can_refresh_tsr_value 			+ test_screen_refresh_rate;
				gear_ratio_value 		= canRx_gear_ratio_value 		+ can_refresh_gear_ratio_value 		+ test_screen_refresh_rate;
				rotor_speed_value 		= canRx_rotor_speed_value 		+ can_refresh_rotor_speed_value 	+ test_screen_refresh_rate;
				rotor_rops_cmd_value 	= canRx_rotor_rops_cmd_value 	+ can_refresh_rotor_rops_cmd_value 	+ test_screen_refresh_rate;
				pitch_value 			= canRx_pitch_value 			+ can_refresh_pitch_value 			+ test_screen_refresh_rate;
				efficiency_value 		= canRx_efficiency_value	 	+ can_refresh_efficiency_value 		+ test_screen_refresh_rate;
				wind_speed_value 		= canRx_wind_speed_value 		+ can_refresh_wind_speed_value 		+ test_screen_refresh_rate;
				pitch_cmd_value 		= canRx_pitch_cmd_value 		+ can_refresh_pitch_cmd_value 		+ test_screen_refresh_rate;
				debug_log_1_value		= canRx_debug_log_1_value 		+ can_refresh_debug_log_1_value 	+ test_screen_refresh_rate;
				debug_log_2_value 		= canRx_debug_log_2_value 		+ can_refresh_debug_log_2_value 	+ test_screen_refresh_rate;
				debug_log_3_value 		= canRx_debug_log_3_value 		+ can_refresh_debug_log_3_value 	+ test_screen_refresh_rate;
				debug_log_4_value 		= canRx_debug_log_4_value 		+ can_refresh_debug_log_4_value 	+ test_screen_refresh_rate;
			}


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
				//power = canRx_turbine_rpm * canRx_torque * 2 * 3.14159 / 60;
				break;
			case EFF_FLAG:
				/* Process data from the ISR */
				//eff_power 	= canRx_turbine_rpm * canRx_torque * 2 * 3.14159 / 60;
				//efficiency	= eff_power / canRx_wind_speed;
				break;
			case TSR_FLAG:
				/* Process data from the ISR */
				//tsr = canRx_turbine_rpm * 3.14159 * 0.5 / canRx_wind_speed;

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
