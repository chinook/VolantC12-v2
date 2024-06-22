/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/ui_page2_screen/UI_page2ViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

UI_page2ViewBase::UI_page2ViewBase()
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    background.setPosition(0, 0, 800, 480);
    background.setOrigin(0.0f, 0.0f);
    background.setScale(1.0f, 1.0f);
    background.setAngle(0.0f);
    backgroundPainter.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
    background.setPainter(backgroundPainter);
    const touchgfx::AbstractShape::ShapePoint<float> backgroundPoints[4] = { { 0.0f, 0.0f }, { 800.0f, 0.0f }, { 800.0f, 480.0f }, { 0.0f, 480.0f } };
    background.setShape(backgroundPoints);
    add(background);

    header_page2_container.setPosition(0, 0, 800, 48);
    header_p2_box.setPosition(0, 0, 800, 48);
    header_p2_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    header_p2_box.setBorderColor(touchgfx::Color::getColorFromRGB(50, 82, 123));
    header_p2_box.setBorderSize(2);
    header_page2_container.add(header_p2_box);

    page2_num_text.setXY(718, 9);
    page2_num_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    page2_num_text.setLinespacing(0);
    page2_num_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_1F1N));
    header_page2_container.add(page2_num_text);

    add(header_page2_container);

    power_container.setPosition(0, 48, 400, 144);
    power_box.setPosition(0, 0, 400, 144);
    power_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    power_box.setBorderColor(touchgfx::Color::getColorFromRGB(50, 82, 123));
    power_box.setBorderSize(2);
    power_container.add(power_box);

    power_title.setXY(10, 111);
    power_title.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    power_title.setLinespacing(0);
    power_title.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CG1O));
    power_container.add(power_title);

    power_text.setPosition(100, 32, 195, 61);
    power_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    power_text.setLinespacing(0);
    Unicode::snprintf(power_textBuffer, POWER_TEXT_SIZE, "%s", touchgfx::TypedText(T_POWER_TEXT).getText());
    power_text.setWildcard(power_textBuffer);
    power_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_4N8U));
    power_container.add(power_text);

    add(power_container);

    efficiency_container.setPosition(400, 48, 400, 144);
    efficiency_box.setPosition(0, 0, 400, 144);
    efficiency_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    efficiency_box.setBorderColor(touchgfx::Color::getColorFromRGB(50, 82, 123));
    efficiency_box.setBorderSize(2);
    efficiency_container.add(efficiency_box);

    efficiency_title.setXY(10, 111);
    efficiency_title.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    efficiency_title.setLinespacing(0);
    efficiency_title.setTypedText(touchgfx::TypedText(T___SINGLEUSE_V5U8));
    efficiency_container.add(efficiency_title);

    efficiency_text.setPosition(75, 32, 245, 61);
    efficiency_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    efficiency_text.setLinespacing(0);
    Unicode::snprintf(efficiency_textBuffer, EFFICIENCY_TEXT_SIZE, "%s", touchgfx::TypedText(T_EFFICIENCY_TEXT).getText());
    efficiency_text.setWildcard(efficiency_textBuffer);
    efficiency_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_DIBQ));
    efficiency_container.add(efficiency_text);

    add(efficiency_container);

    tsr_container.setPosition(0, 192, 400, 144);
    tsr_box.setPosition(0, 0, 400, 144);
    tsr_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    tsr_box.setBorderColor(touchgfx::Color::getColorFromRGB(50, 82, 123));
    tsr_box.setBorderSize(2);
    tsr_container.add(tsr_box);

    tsr_title.setXY(10, 111);
    tsr_title.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    tsr_title.setLinespacing(0);
    tsr_title.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QAY6));
    tsr_container.add(tsr_title);

    tsr_text.setPosition(100, 32, 195, 61);
    tsr_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    tsr_text.setLinespacing(0);
    Unicode::snprintf(tsr_textBuffer, TSR_TEXT_SIZE, "%s", touchgfx::TypedText(T_TSR_TEXT).getText());
    tsr_text.setWildcard(tsr_textBuffer);
    tsr_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_MU00));
    tsr_container.add(tsr_text);

    add(tsr_container);

    empty4_container.setPosition(400, 192, 400, 144);
    empty4_box.setPosition(0, 0, 400, 144);
    empty4_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    empty4_box.setBorderColor(touchgfx::Color::getColorFromRGB(50, 82, 123));
    empty4_box.setBorderSize(2);
    empty4_container.add(empty4_box);

    empty4_title.setXY(10, 111);
    empty4_title.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    empty4_title.setLinespacing(0);
    empty4_title.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Y1FV));
    empty4_title.setVisible(false);
    empty4_container.add(empty4_title);

    empty4_text.setPosition(110, 32, 185, 61);
    empty4_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    empty4_text.setLinespacing(0);
    empty4_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_LEP2));
    empty4_text.setVisible(false);
    empty4_container.add(empty4_text);

    add(empty4_container);

    empty5_container.setPosition(0, 336, 400, 144);
    empty5_box.setPosition(0, 0, 400, 144);
    empty5_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    empty5_box.setBorderColor(touchgfx::Color::getColorFromRGB(50, 82, 123));
    empty5_box.setBorderSize(2);
    empty5_container.add(empty5_box);

    empty5_title.setXY(10, 111);
    empty5_title.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    empty5_title.setLinespacing(0);
    empty5_title.setTypedText(touchgfx::TypedText(T___SINGLEUSE_9JZ7));
    empty5_title.setVisible(false);
    empty5_container.add(empty5_title);

    empty5_text.setPosition(110, 32, 185, 61);
    empty5_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    empty5_text.setLinespacing(0);
    empty5_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VJH6));
    empty5_text.setVisible(false);
    empty5_container.add(empty5_text);

    add(empty5_container);

    empty6_container.setPosition(400, 336, 400, 144);
    empty6_box.setPosition(0, 0, 400, 144);
    empty6_box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    empty6_box.setBorderColor(touchgfx::Color::getColorFromRGB(50, 82, 123));
    empty6_box.setBorderSize(2);
    empty6_container.add(empty6_box);

    empty6_title.setXY(10, 111);
    empty6_title.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    empty6_title.setLinespacing(0);
    empty6_title.setTypedText(touchgfx::TypedText(T___SINGLEUSE_T5F8));
    empty6_title.setVisible(false);
    empty6_container.add(empty6_title);

    empty6_text.setPosition(110, 32, 185, 61);
    empty6_text.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    empty6_text.setLinespacing(0);
    empty6_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_DTB9));
    empty6_text.setVisible(false);
    empty6_container.add(empty6_text);

    add(empty6_container);
}

UI_page2ViewBase::~UI_page2ViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void UI_page2ViewBase::setupScreen()
{

}

void UI_page2ViewBase::handleKeyEvent(uint8_t key)
{
    if(0 == key)
    {
        //show_ui_page1
        //When hardware button 0 clicked change screen to UI_page1
        //Go to UI_page1 with no screen transition
        application().gotoUI_page1ScreenNoTransition();
    
    }
}
