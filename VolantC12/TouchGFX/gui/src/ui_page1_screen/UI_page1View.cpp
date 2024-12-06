#include <gui/ui_page1_screen/UI_page1View.hpp>

UI_page1View::UI_page1View()
{

}

void UI_page1View::setupScreen()
{
    UI_page1ViewBase::setupScreen();
}

void UI_page1View::tearDownScreen()
{
    UI_page1ViewBase::tearDownScreen();
}

void UI_page1View::change_screen(uint8_t screen)
{
	UI_page1ViewBase::handleKeyEvent(screen);
}

//TouchGFX_4_23_2_tutorial_after_generating_code_step_3 : add the function like update_change_the_name

void UI_page1View::update_turb_dir_value(float turb_dir_value_temps)
{
	Unicode::snprintfFloat(turb_dir_valueBuffer, TURB_DIR_VALUE_SIZE, "%.1f", turb_dir_value_temps);
	turb_dir_value.invalidate();
}

void UI_page1View::update_turb_cmd_value(float turb_cmd_value_temps)
{
	Unicode::snprintfFloat(turb_cmd_valueBuffer, TURB_CMD_VALUE_SIZE, "%.1f", turb_cmd_value_temps);
	turb_cmd_value.invalidate();
}

void UI_page1View::update_wind_dir_value(float wind_dir_value_temps)
{
	Unicode::snprintfFloat(wind_dir_valueBuffer, WIND_DIR_VALUE_SIZE, "%.1f", wind_dir_value_temps);
	wind_dir_value.invalidate();
}

void UI_page1View::update_speed_value(float speed_value_temps)
{
	Unicode::snprintfFloat(speed_valueBuffer, SPEED_VALUE_SIZE, "%.2f", speed_value_temps);
	speed_value.invalidate();
}

void UI_page1View::update_tsr_value(float tsr_value_temps)
{
	Unicode::snprintfFloat(tsr_valueBuffer, TSR_VALUE_SIZE, "%.2f", tsr_value_temps);
	tsr_value.invalidate();
}

void UI_page1View::update_gear_ratio_value(float gear_ratio_value_temps)
{
	Unicode::snprintfFloat(gear_ratio_valueBuffer, GEAR_RATIO_VALUE_SIZE, "%.1f", gear_ratio_value_temps);
	gear_ratio_value.invalidate();
}

void UI_page1View::update_rotor_speed_value(float rotor_speed_value_temps)
{
	Unicode::snprintfFloat(rotor_speed_valueBuffer, ROTOR_SPEED_VALUE_SIZE, "%.0f", rotor_speed_value_temps);
	rotor_speed_value.invalidate();
}

void UI_page1View::update_rotor_rops_cmd_value(float rotor_rops_cmd_value_temps)
{
	Unicode::snprintfFloat(rotor_rops_cmd_valueBuffer, ROTOR_ROPS_CMD_VALUE_SIZE, "%.0f", rotor_rops_cmd_value_temps);
	rotor_rops_cmd_value.invalidate();
}

void UI_page1View::update_pitch_value(float pitch_value_temps)
{
	Unicode::snprintfFloat(pitch_valueBuffer, PITCH_VALUE_SIZE, "%.3f", pitch_value_temps);
	pitch_value.invalidate();
}

void UI_page1View::update_efficiency_value(float efficiency_value_temps)
{
	Unicode::snprintfFloat(efficiency_valueBuffer, EFFICIENCY_VALUE_SIZE, "%.2f", efficiency_value_temps);
	efficiency_value.invalidate();
}

void UI_page1View::update_wind_speed_value(float wind_speed_value_temps)
{
	Unicode::snprintfFloat(wind_speed_valueBuffer, WIND_SPEED_VALUE_SIZE, "%.1f", wind_speed_value_temps);
	wind_speed_value.invalidate();
}

void UI_page1View::update_pitch_cmd_value(float pitch_cmd_value_temps)
{
	Unicode::snprintfFloat(pitch_cmd_valueBuffer, PITCH_CMD_VALUE_SIZE, "%.3f", pitch_cmd_value_temps);
	pitch_cmd_value.invalidate();
}

void UI_page1View::update_debug_log_1_value(float debug_log_1_value_temps)
{
	Unicode::snprintfFloat(debug_log_1_valueBuffer, DEBUG_LOG_1_VALUE_SIZE, "%.18f", debug_log_1_value_temps);
	debug_log_1_value.invalidate();
}

void UI_page1View::update_debug_log_2_value(float debug_log_2_value_temps)
{
	Unicode::snprintfFloat(debug_log_2_valueBuffer, DEBUG_LOG_2_VALUE_SIZE, "%.18f", debug_log_2_value_temps);
	debug_log_2_value.invalidate();
}

void UI_page1View::update_debug_log_3_value(float debug_log_3_value_temps)
{
	Unicode::snprintfFloat(debug_log_3_valueBuffer, DEBUG_LOG_3_VALUE_SIZE, "%.18f", debug_log_3_value_temps);
	debug_log_3_value.invalidate();
}

void UI_page1View::update_debug_log_4_value(float debug_log_4_value_temps)
{
	Unicode::snprintfFloat(debug_log_4_valueBuffer, DEBUG_LOG_4_VALUE_SIZE, "%.18f", debug_log_4_value_temps);
	debug_log_4_value.invalidate();
}

void UI_page1View::update_fps_counter_value(float fps_counter_value_temps)
{
	Unicode::snprintfFloat(fps_counter_valueBuffer, FPS_COUNTER_VALUE_SIZE, "%.0f", fps_counter_value_temps);
	fps_counter_value.invalidate();
}


void UI_page1View::update_change_the_name(float change_the_name_temps)
{
	Unicode::snprintfFloat(change_the_nameBuffer, CHANGE_THE_NAME_SIZE, "%.0f", change_the_name_temps);
	change_the_name.invalidate();
	//Unicode::snprintfFloat(change_the_nameBuffer, CHANGE_THE_NAME_SIZE, "%.1f", change_the_name);
	//change_the_name.invalidate();
}
