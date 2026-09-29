/*
 * SimulatorData.cpp
 *
 * Fichier compile UNIQUEMENT pour le simulateur PC (garde #ifdef SIMULATOR).
 *
 * Sur la cible STM32, les globals screen1 / screen2 / desired_screen /
 * active_screen_index et les valeurs derriere les pointeurs de ui_t sont
 * fournis par screen_tasks.c (rempli par le CAN). Ce fichier-la n'est pas
 * compile sur PC : on recree donc ici des definitions minimales + des valeurs
 * de test pour que le simulateur puisse tourner et qu'on voie l'UI bouger.
 *
 * Ne touche pas au comportement sur la carte (tout est sous #ifdef SIMULATOR).
 */
#ifdef SIMULATOR

#include <stdint.h>

extern "C" {
	#include "..\..\..\..\STM32CubeIDE\Application\User\application\ui.h"
}

/* Globals normalement definis dans screen_tasks.c (cible). */
volatile ui_t   screen1;
volatile ui_t   screen2;
volatile uint8_t desired_screen      = 0;
volatile uint8_t active_screen_index = 0;

/* Valeurs de test placees derriere les pointeurs de screen1/screen2. */
static float sim_turb_dir       = 0.0f;
static float sim_current_gear   = 7.0f;
static float sim_wind_dir       = 0.0f;   /* balaye -180..+180 (voir plus bas) */
static float sim_speed          = 12.3f;
static float sim_tsr            = 2.5f;
static float sim_gear_ratio     = 1.8f;
static float sim_rotor_speed    = 320.0f;
static float sim_rotor_rops_cmd = 300.0f;
static float sim_pitch          = 0.0f;
static float sim_efficiency     = 0.42f;
static float sim_wind_speed     = 8.5f;
static float sim_pitch_cmd      = 0.0f;
static float sim_debug_log_1    = 0.0f;
static float sim_debug_log_2    = 0.0f;
static float sim_debug_log_3    = 0.0f;
static float sim_debug_log_4    = 0.0f;
static float sim_fps_counter    = 60.0f;
static float sim_change_the_name= 0.0f;

static void sim_wire_pointers(volatile ui_t* s)
{
	s->turb_dir_value       = &sim_turb_dir;
	s->current_gear_value   = &sim_current_gear;
	s->wind_dir_value       = &sim_wind_dir;
	s->speed_value          = &sim_speed;
	s->tsr_value            = &sim_tsr;
	s->gear_ratio_value     = &sim_gear_ratio;
	s->rotor_speed_value    = &sim_rotor_speed;
	s->rotor_rops_cmd_value = &sim_rotor_rops_cmd;
	s->pitch_value          = &sim_pitch;
	s->efficiency_value     = &sim_efficiency;
	s->wind_speed_value     = &sim_wind_speed;
	s->pitch_cmd_value      = &sim_pitch_cmd;
	s->debug_log_1_value    = &sim_debug_log_1;
	s->debug_log_2_value    = &sim_debug_log_2;
	s->debug_log_3_value    = &sim_debug_log_3;
	s->debug_log_4_value    = &sim_debug_log_4;
	s->fps_counter_value    = &sim_fps_counter;
	s->change_the_name      = &sim_change_the_name;
}

/* Appele a chaque tick par Model::tick() (uniquement en simulateur). */
void simulator_feed_screens(void);

void simulator_feed_screens(void)
{
	static bool wired = false;
	if (!wired) {
		sim_wire_pointers(&screen1);
		sim_wire_pointers(&screen2);
		wired = true;
	}

	/* Balaye l'orientation du vent de -180 a +180 deg pour voir l'aiguille
	 * du vent (gauge1) bouger. ~0.5 deg/tick (~60 ticks/s). */
	sim_wind_dir += 0.5f;
	if (sim_wind_dir > 180.0f) {
		sim_wind_dir = -180.0f;
	}
}

#endif /* SIMULATOR */
