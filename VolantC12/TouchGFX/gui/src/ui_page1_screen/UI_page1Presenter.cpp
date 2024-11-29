#include <gui/ui_page1_screen/UI_page1View.hpp>
#include <gui/ui_page1_screen/UI_page1Presenter.hpp>

UI_page1Presenter::UI_page1Presenter(UI_page1View& v)
    : view(v)
{

}

void UI_page1Presenter::activate()
{

}

void UI_page1Presenter::deactivate()
{

}

void UI_page1Presenter::change_screen(uint8_t screen)
{
	osMessageQueueReset(screen2_pres_queue);
	for (uint8_t i = 0; i < NUM_FIELDS; i++) {
		uint8_t buf = arr[i];
		osMessageQueuePut(screen2_pres_queue, &buf, 0, 0);
	}

	view.change_screen(screen);
}

void UI_page1Presenter::update_ui(void* screen)
{
	ui_t* ui = (ui_t*) screen;
	//uint8_t buf;

	//if(osMessageQueueGet(screen1_pres_queue, &buf, NULL, 0) == osOK) {
		//TouchGFX_4_23_2_tutorial_after_generating_code_step_4 : add the 2 lines of code like change_the_name
		
		float turb_dir_value = *(const float*)ui->turb_dir_value;
		view.update_turb_dir_value(turb_dir_value);
		float turb_cmd_value = *(const float*)ui->turb_cmd_value;
		view.update_turb_cmd_value(turb_cmd_value);
		float wind_dir_value = *(const float*)ui->wind_dir_value; //good
		view.update_wind_dir_value(wind_dir_value);
		float speed_value = *(const float*)ui->speed_value; //good
		view.update_speed_value(speed_value);
		float tsr_value = *(const float*)ui->tsr_value; //good
		view.update_tsr_value(tsr_value);
		float gear_ratio_value = *(const float*)ui->gear_ratio_value;
		view.update_gear_ratio_value(gear_ratio_value);
		float rotor_speed_value = *(const float*)ui->rotor_speed_value; //bad
		view.update_rotor_speed_value(rotor_speed_value);
		float rotor_rops_cmd_value = *(const float*)ui->rotor_rops_cmd_value;
		view.update_rotor_rops_cmd_value(rotor_rops_cmd_value);
		float pitch_value = *(const float*)ui->pitch_value; //good
		view.update_pitch_value(pitch_value);
		float efficiency_value = *(const float*)ui->efficiency_value;
		view.update_efficiency_value(efficiency_value);
		float wind_speed_value = *(const float*)ui->wind_speed_value; //good
		view.update_wind_speed_value(wind_speed_value);
		float pitch_cmd_value = *(const float*)ui->pitch_cmd_value;
		view.update_pitch_cmd_value(pitch_cmd_value);
		float debug_log_value_value = *(const float*)ui->debug_log_value_value;
		view.update_debug_log_value_value(debug_log_value_value);
		float fps_counter_value = *(const float*)ui->fps_counter_value; //good
		view.update_fps_counter_value(fps_counter_value);

		//float change_the_name = *(const float*)ui->change_the_name;
		//view.update_change_the_name(change_the_name);
	//}


}
