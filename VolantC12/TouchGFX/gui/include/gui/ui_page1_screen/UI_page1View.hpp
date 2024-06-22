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
protected:
};

#endif // UI_PAGE1VIEW_HPP
