/*
 * ui.h
 *
 *  Created on: Mar. 3, 2024
 *      Author: Gabriel
 */

#ifndef APPLICATION_USER_APPLICATION_UI_H_
#define APPLICATION_USER_APPLICATION_UI_H_

#include <stdint.h>


#define UI_FIELDS		6


/**
 * @brief Structure representing the UI elements
 * used for displaying data on the screen. Each
 * element is represented by a volatile pointer to
 * const void, allowing for the representation of
 * various data types.
 *
 */

//TouchGFX_4_23_2_tutorial_after_generating_code_step_1 : add a variable like change_the_name
typedef struct ui {
	volatile const void* turb_dir_value;
	volatile const void* turb_cmd_value;
	volatile const void* wind_dir_value;
	volatile const void* speed_value;
	volatile const void* tsr_value;
	volatile const void* gear_ratio_value;
	volatile const void* rotor_speed_value;
	volatile const void* rotor_rops_cmd_value;
	volatile const void* pitch_value;
	volatile const void* efficiency_value;
	volatile const void* wind_speed_value;
	volatile const void* pitch_cmd_value;
	volatile const void* debug_log_value_value;
	volatile const void* fps_counter_value;
	
	volatile const void* change_the_name;
} ui_t;



#endif /* APPLICATION_USER_APPLICATION_UI_H_ */
