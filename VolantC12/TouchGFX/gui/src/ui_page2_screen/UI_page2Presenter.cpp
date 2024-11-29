#include <gui/ui_page2_screen/UI_page2View.hpp>
#include <gui/ui_page2_screen/UI_page2Presenter.hpp>

UI_page2Presenter::UI_page2Presenter(UI_page2View& v)
    : view(v)
{

}

void UI_page2Presenter::activate()
{

}

void UI_page2Presenter::deactivate()
{

}

void UI_page2Presenter::change_screen(uint8_t screen)
{
	/*osMessageQueueReset(screen1_pres_queue);
	for (uint8_t i = 0; i < NUM_FIELDS; i++) {
		uint8_t buf = arr[i];
		osMessageQueuePut(screen1_pres_queue, &buf, 0, 0);
	}

	view.change_screen(screen); */
}

void UI_page2Presenter::update_ui(void* screen)
{
	/*
	ui_t* ui = (ui_t*)screen;
	uint8_t buf;

	if (osMessageQueueGet(screen2_pres_queue, &buf, NULL, 0) == osOK) {
		switch (buf) {
		case POWER_FLAG: {
			//float power = *(const float*)ui->data1;
			//view.update_power(power);
			break;
		}
		case EFF_FLAG: {
			//float eff = *(const float*)ui->data2;
			//view.update_efficiency(eff);
			break;
		}
		case TSR_FLAG: {
			//float tsr = *(const float*)ui->data3;
			//view.update_tsr(tsr);
			break;
		}
		default:
			break;
		}
	}*/
}
