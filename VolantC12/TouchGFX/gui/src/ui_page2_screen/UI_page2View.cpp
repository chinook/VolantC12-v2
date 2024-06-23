#include <gui/ui_page2_screen/UI_page2View.hpp>

UI_page2View::UI_page2View()
{

}

void UI_page2View::setupScreen()
{
    UI_page2ViewBase::setupScreen();
}

void UI_page2View::tearDownScreen()
{
    UI_page2ViewBase::tearDownScreen();
}

void UI_page2View::change_screen(uint8_t screen)
{
	UI_page2ViewBase::handleKeyEvent(screen);
}

void UI_page2View::update_power(float power)
{
	Unicode::snprintfFloat(power_textBuffer, POWER_TEXT_SIZE, "%.2f", power);
	power_text.invalidate();
}

void UI_page2View::update_efficiency(float eff)
{
	Unicode::snprintfFloat(efficiency_textBuffer, EFFICIENCY_TEXT_SIZE, "%.2f", eff);
	efficiency_text.invalidate();
}

void UI_page2View::update_tsr(float tsr)
{
	Unicode::snprintfFloat(tsr_textBuffer, TSR_TEXT_SIZE, "%.2f", tsr);
	tsr_text.invalidate();
}
