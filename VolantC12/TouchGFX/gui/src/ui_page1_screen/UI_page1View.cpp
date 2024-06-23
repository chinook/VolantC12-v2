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

void UI_page1View::update_mast_angle(float angle)
{
//	angle = 10;
	Unicode::snprintfFloat(mast_angle_textBuffer, MAST_ANGLE_TEXT_SIZE, "%.1f", angle);
	mast_angle_text.invalidate();
}

void UI_page1View::update_pitch(float pitch)
{
	Unicode::snprintfFloat(pitch_textBuffer, PITCH_TEXT_SIZE, "%.1f", pitch);
	pitch_text.invalidate();
}

void UI_page1View::update_wind_speed(float speed)
{
	Unicode::snprintfFloat(wind_speed_textBuffer, WIND_SPEED_TEXT_SIZE, "%.1f", speed);
	wind_speed_text.invalidate();
}

void UI_page1View::update_wind_dir(float dir)
{
	Unicode::snprintfFloat(wind_dir_textBuffer, WIND_DIR_TEXT_SIZE, "%.1f", dir);
	wind_dir_text.invalidate();
}

void UI_page1View::update_wheel_rpm(float rpm)
{
	Unicode::snprintfFloat(wheel_rpm_textBuffer, WHEEL_RPM_TEXT_SIZE, "%.1f", rpm);
	wheel_rpm_text.invalidate();
}

void UI_page1View::update_turb_rpm(float rpm)
{
	Unicode::snprintfFloat(turb_rpm_textBuffer, TURB_RPM_TEXT_SIZE, "%.1f", rpm);
	turb_rpm_text.invalidate();
}
