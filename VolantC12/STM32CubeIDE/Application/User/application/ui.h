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
 * The data fields are placed as follows:
 * ----------------
 *| data1 | data2 |
 *|----------------
 *| data3 | data4 |
 *|----------------
 *| data5 | data6 |
 *|----------------
 */
typedef struct ui {
	volatile const void* data1;
	volatile const void* data2;
	volatile const void* data3;
	volatile const void* data4;
	volatile const void* data5;
	volatile const void* data6;
} ui_t;



#endif /* APPLICATION_USER_APPLICATION_UI_H_ */
