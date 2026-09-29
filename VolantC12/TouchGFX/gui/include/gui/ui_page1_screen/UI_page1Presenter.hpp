#ifndef UI_PAGE1PRESENTER_HPP
#define UI_PAGE1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

extern "C" {
	/* ui.h ne depend que de <stdint.h> : il fournit ui_t sur la cible ET sur
	 * le simulateur PC. screen_tasks.h tire du RTOS/HAL STM32 (cmsis_os2.h,
	 * main.h, fdcan.h) qui n'existe pas sur PC : on ne l'inclut donc que pour
	 * le build cible (SIMULATOR n'est defini que par le build simulateur). */
	#include "..\..\..\..\..\STM32CubeIDE\Application\User\application\ui.h"
#ifndef SIMULATOR
	#include "..\..\..\..\..\STM32CubeIDE\Application\User\application\screen_tasks.h"
#endif
}

class UI_page1View;

class UI_page1Presenter : public touchgfx::Presenter, public ModelListener
{
public:
    UI_page1Presenter(UI_page1View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~UI_page1Presenter() {}

    virtual void change_screen(uint8_t screen);

    virtual void update_ui(volatile void* screen);

private:
    UI_page1Presenter();

    UI_page1View& view;
};

#endif // UI_PAGE1PRESENTER_HPP
