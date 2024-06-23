#ifndef UI_PAGE1PRESENTER_HPP
#define UI_PAGE1PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

extern "C" {
	#include "..\..\..\..\..\STM32CubeIDE\Application\User\application\screen_tasks.h"
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

    virtual void update_ui(void* screen);

private:
    UI_page1Presenter();

    UI_page1View& view;
};

#endif // UI_PAGE1PRESENTER_HPP
