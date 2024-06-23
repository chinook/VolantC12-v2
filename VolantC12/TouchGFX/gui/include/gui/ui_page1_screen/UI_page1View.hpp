#ifndef UI_PAGE1VIEW_HPP
#define UI_PAGE1VIEW_HPP

#include <gui_generated/ui_page1_screen/UI_page1ViewBase.hpp>
#include <gui/ui_page1_screen/UI_page1Presenter.hpp>

class UI_page1View : public UI_page1ViewBase
{
public:
    UI_page1View();
    virtual ~UI_page1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void change_screen(uint8_t screen);
    virtual void update_mast_angle(float angle);
    virtual void update_pitch(float pitch);
    virtual void update_wind_speed(float speed);
    virtual void update_wind_dir(float dir);
    virtual void update_wheel_rpm(float rpm);
    virtual void update_turb_rpm(float rpm);
protected:
};

#endif // UI_PAGE1VIEW_HPP
