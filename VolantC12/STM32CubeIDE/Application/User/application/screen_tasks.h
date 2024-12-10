/*
 * steering_tasks.h
 *
 *  Created on: Mar. 3, 2024
 *      Author: Gabriel
 */

#ifndef APPLICATION_USER_APPLICATION_SCREEN_TASKS_H_
#define APPLICATION_USER_APPLICATION_SCREEN_TASKS_H_

#include "cmsis_os2.h"
#include "ui.h"
#include "main.h"
#include <stdlib.h>
#include "fdcan.h"


/* Flags used to identify the fields on the screen 1 */
#define MAST_ANGLE_FLAG		(0x1)
#define PITCH_FLAG			(0x2)
#define WIND_SP_FLAG		(0x4)
#define WIND_DIR_FLAG		(0x8)
#define WHEEL_RPM_FLAG		(0x10)
#define TURB_RPM_FLAG		(0x20)

/* Flags used to identify the fields on the screen 2 */
#define POWER_FLAG			(0x1)
#define EFF_FLAG			(0x2)
#define TSR_FLAG			(0x4)
#define DATA4_FLAG			(0x8)  /* empty */
#define DATA5_FLAG			(0x10) /* empty */
#define DATA6_FLAG			(0x20) /* empty */

/* Number of data fields on every screen */
#define NUM_FIELDS			0x6

/**
 * Array used to reset the message queue in order
 * to refresh all containers on the screen when
 * there is a screen change request.
 */
extern volatile uint8_t arr[NUM_FIELDS];

/* Global variables used by the Model object */
extern volatile uint8_t desired_screen;
extern volatile uint8_t active_screen_index;
extern volatile ui_t screen1;
extern volatile ui_t screen2;

//h = haut, m = milieu, b = bas, g = gauche et d = droit
extern uint8_t flag_bouton_hgg; 	//PG2
extern uint8_t flag_bouton_hg; 		//PB10
extern uint8_t flag_bouton_hd;		//PA7
extern uint8_t flag_bouton_hdd;		//PA6

extern uint8_t flag_bouton_mg;		//PB5
extern uint8_t flag_bouton_md;		//PA8

extern uint8_t flag_bouton_bgg;		//PA15
extern uint8_t flag_bouton_bg;		//PB0
extern uint8_t flag_bouton_bd;		//PA4
extern uint8_t flag_bouton_bdd;		//PA3

/**
 * Message queues shared between the screen tasks
 * and the Presenter objects.
 */
extern osMessageQueueId_t screen1_pres_queue;
extern osMessageQueueId_t screen2_pres_queue;

/**
 * Message queues shared between the screen tasks
 * and the ISR.
 */
extern osMessageQueueId_t screen1_isr_queue;
extern osMessageQueueId_t screen2_isr_queue;


/* Tasks */
void screen1_task(void* arg);
void screen2_task(void* arg);

/* Task used for development */
void test_task(void* arg);


#endif /* APPLICATION_USER_APPLICATION_SCREEN_TASKS_H_ */
