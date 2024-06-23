#ifndef UI_PAGE2VIEW_HPP
#define UI_PAGE2VIEW_HPP

#include <gui_generated/ui_page2_screen/UI_page2ViewBase.hpp>
#include <gui/ui_page2_screen/UI_page2Presenter.hpp>

class UI_page2View : public UI_page2ViewBase
{
public:
    UI_page2View();
    virtual ~UI_page2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void change_screen(uint8_t screen);
    virtual void update_power(float power);
    virtual void update_efficiency(float eff);
    virtual void update_tsr(float tsr);
protected:
};

#endif // UI_PAGE2VIEW_HPP
