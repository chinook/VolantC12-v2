#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern volatile uint8_t desired_screen;
extern volatile uint8_t active_screen_index;
extern volatile struct ui screen1;
extern volatile struct ui screen2;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	/* Delegates the screen update operation to the proper screen instance */
	void* active_screen;
	active_screen = (curr_screen == 0) ? (void*)&screen1 : (void*)&screen2;
	modelListener->update_ui(active_screen);

	/* Handles a page change request. This block of code
	 * needs to be placed after the update_ui function call
	 * to avoid a screen stall. */
	if (curr_screen != desired_screen) {
		curr_screen = desired_screen;
		modelListener->change_screen(curr_screen);
	}
}
