#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern volatile uint8_t desired_screen;
extern volatile uint8_t active_screen_index;
extern volatile struct ui screen1;
extern volatile struct ui screen2;

#ifdef SIMULATOR
/* Definie dans SimulatorData.cpp : alimente screen1/screen2 avec des valeurs
 * de test et fait bouger l'orientation du vent. */
void simulator_feed_screens(void);
#endif

Model::Model() : modelListener(0), curr_screen(0)
{

}

void Model::tick()
{
#ifdef SIMULATOR
	simulator_feed_screens();
#endif

	/* Delegates the screen update operation to the proper screen instance.
	 * screen1/screen2 sont volatile (partages avec l'ISR/les taches CAN sur la
	 * cible) : on garde le qualificatif volatile jusqu'au Presenter. */
	volatile void* active_screen;
	active_screen = (curr_screen == 0) ? (volatile void*)&screen1 : (volatile void*)&screen2;
	modelListener->update_ui(active_screen);

	/* Handles a page change request. This block of code
	 * needs to be placed after the update_ui function call
	 * to avoid a screen stall. */
	if (curr_screen != desired_screen) {
		curr_screen = desired_screen;
		modelListener->change_screen(curr_screen);
	}
}
