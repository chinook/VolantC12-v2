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
	uint8_t buf;

	if (osMessageQueueGet(screen1_pres_queue, &buf, NULL, 0) == osOK) {
		float angle = *(const float*)ui->data1;
		view.update_mast_angle(angle);
		float pitch = *(const float*)ui->data2;
		view.update_pitch(pitch);
		float speed = *(const float*)ui->data3;
		view.update_wind_speed(speed);
		float dir = *(const float*)ui->data4;
		view.update_wind_dir(dir);
		float wrpm = *(const float*)ui->data5;
		view.update_wheel_rpm(wrpm);
		float rpm = *(const float*)ui->data6;
		view.update_turb_rpm(rpm);
	}


}
