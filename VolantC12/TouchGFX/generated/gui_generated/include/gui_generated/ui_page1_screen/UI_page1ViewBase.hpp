/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef UI_PAGE1VIEWBASE_HPP
#define UI_PAGE1VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/ui_page1_screen/UI_page1Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/canvas/Shape.hpp>
#include <touchgfx/widgets/canvas/PainterRGB888.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class UI_page1ViewBase : public touchgfx::View<UI_page1Presenter>
{
public:
    UI_page1ViewBase();
    virtual ~UI_page1ViewBase();
    virtual void setupScreen();
    virtual void handleKeyEvent(uint8_t key);

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::Shape<4> background;
    touchgfx::PainterRGB888 backgroundPainter;
    touchgfx::Container header_page1_container;
    touchgfx::BoxWithBorder header_p1_box;
    touchgfx::TextArea page1_num_text;
    touchgfx::Container mast_angle_container;
    touchgfx::BoxWithBorder mast_angle_box;
    touchgfx::TextArea mast_angle_title;
    touchgfx::TextAreaWithOneWildcard mast_angle_text;
    touchgfx::Container pitch_container;
    touchgfx::BoxWithBorder pitch_box;
    touchgfx::TextArea pitch_title;
    touchgfx::TextAreaWithOneWildcard pitch_text;
    touchgfx::Container wind_speed_container;
    touchgfx::BoxWithBorder wind_speed_box;
    touchgfx::TextArea wind_speed_title;
    touchgfx::TextAreaWithOneWildcard wind_speed_text;
    touchgfx::Container wind_dir_container;
    touchgfx::BoxWithBorder wind_dir_box;
    touchgfx::TextArea wind_dir_title;
    touchgfx::TextAreaWithOneWildcard wind_dir_text;
    touchgfx::Container wheel_rpm_container;
    touchgfx::BoxWithBorder wheel_rpm_box;
    touchgfx::TextArea wheel_rpm_title;
    touchgfx::TextAreaWithOneWildcard wheel_rpm_text;
    touchgfx::Container turb_rpm_container;
    touchgfx::BoxWithBorder turb_rpm_box;
    touchgfx::TextArea turb_rpm_title;
    touchgfx::TextAreaWithOneWildcard turb_rpm_text;

    /*
     * Wildcard Buffers
     */
    static const uint16_t MAST_ANGLE_TEXT_SIZE = 7;
    touchgfx::Unicode::UnicodeChar mast_angle_textBuffer[MAST_ANGLE_TEXT_SIZE];
    static const uint16_t PITCH_TEXT_SIZE = 7;
    touchgfx::Unicode::UnicodeChar pitch_textBuffer[PITCH_TEXT_SIZE];
    static const uint16_t WIND_SPEED_TEXT_SIZE = 7;
    touchgfx::Unicode::UnicodeChar wind_speed_textBuffer[WIND_SPEED_TEXT_SIZE];
    static const uint16_t WIND_DIR_TEXT_SIZE = 7;
    touchgfx::Unicode::UnicodeChar wind_dir_textBuffer[WIND_DIR_TEXT_SIZE];
    static const uint16_t WHEEL_RPM_TEXT_SIZE = 7;
    touchgfx::Unicode::UnicodeChar wheel_rpm_textBuffer[WHEEL_RPM_TEXT_SIZE];
    static const uint16_t TURB_RPM_TEXT_SIZE = 7;
    touchgfx::Unicode::UnicodeChar turb_rpm_textBuffer[TURB_RPM_TEXT_SIZE];

private:

    /*
     * Canvas Buffer Size
     */
    static const uint32_t CANVAS_BUFFER_SIZE = 12000;
    uint8_t canvasBuffer[CANVAS_BUFFER_SIZE];

};

#endif // UI_PAGE1VIEWBASE_HPP
