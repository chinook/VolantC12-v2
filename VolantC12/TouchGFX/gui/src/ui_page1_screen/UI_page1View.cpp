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

/* NOTE : les widgets current_gear_value, debug_log_1..4_value et
 * change_the_name ont ete retires de la page 1 dans le Designer : ils
 * n'existent plus dans UI_page1ViewBase. Les fonctions ci-dessous les
 * ecrivaient donc dans des widgets inexistants (le code ne compilait sur
 * aucune cible). Elles sont laissees en no-op pour que le projet compile ;
 * a recabler (et a recreer les widgets dans le Designer) si ces valeurs
 * doivent etre affichees a nouveau. current_gear et debug_log restent
 * appeles par UI_page1Presenter::update_ui, sans effet pour l'instant. */
void UI_page1View::update_current_gear_value(float current_gear_value_temps)
{
	(void)current_gear_value_temps;
}

void UI_page1View::update_wind_dir_value(float wind_dir_value_temps)
{
	Unicode::snprintfFloat(wind_dir_valueBuffer, WIND_DIR_VALUE_SIZE, "%.1f", wind_dir_value_temps);
	wind_dir_value.invalidate();

	/* Aiguille de l'orientation du vent (gauge1, needle1).
	 * Mario envoie le vent dans la plage -180..+180 deg.
	 * gauge1 est configure dans le Designer avec la plage 0..180 et les
	 * angles -90..+90. On compresse donc le vent (-180..+180) sur la
	 * course de l'aiguille (-90..+90) :
	 *     valeur_gauge = vent / 2 + 90
	 *   vent = -180 -> 0   (aiguille a -90 deg)
	 *   vent =    0 -> 90  (aiguille a   0 deg)
	 *   vent = +180 -> 180 (aiguille a +90 deg)
	 * 2e argument de updateValue = duree d'animation en ticks (0 = instantane). */
	float wind_gauge = wind_dir_value_temps / 2.0f + 90.0f;
	if (wind_gauge < 0.0f)   wind_gauge = 0.0f;
	if (wind_gauge > 180.0f) wind_gauge = 180.0f;
	gauge1.updateValue((int)(wind_gauge + 0.5f), 0);
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
	(void)debug_log_1_value_temps;
}

void UI_page1View::update_debug_log_2_value(float debug_log_2_value_temps)
{
	(void)debug_log_2_value_temps;
}

void UI_page1View::update_debug_log_3_value(float debug_log_3_value_temps)
{
	(void)debug_log_3_value_temps;
}

void UI_page1View::update_debug_log_4_value(float debug_log_4_value_temps)
{
	(void)debug_log_4_value_temps;
}

void UI_page1View::update_fps_counter_value(float fps_counter_value_temps)
{
	Unicode::snprintfFloat(fps_counter_valueBuffer, FPS_COUNTER_VALUE_SIZE, "%.0f", fps_counter_value_temps);
	fps_counter_value.invalidate();
}


void UI_page1View::update_change_the_name(float change_the_name_temps)
{
	(void)change_the_name_temps;
}
