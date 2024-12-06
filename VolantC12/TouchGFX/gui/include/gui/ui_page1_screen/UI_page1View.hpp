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

    //TouchGFX_4_23_2_tutorial_after_generating_code_step_2 : add a function like update_change_the_name
    virtual void change_screen(uint8_t screen);
    virtual void update_turb_dir_value(float turb_dir_value);
    virtual void update_turb_cmd_value(float turb_cmd_value);
    virtual void update_wind_dir_value(float wind_dir_value);
    virtual void update_speed_value(float speed_value);
    virtual void update_tsr_value(float tsr_value);
    virtual void update_gear_ratio_value(float gear_ratio_value);
    virtual void update_rotor_speed_value(float rotor_speed_value);
    virtual void update_rotor_rops_cmd_value(float rotor_rops_cmd_value);
    virtual void update_pitch_value(float pitch_value);
    virtual void update_efficiency_value(float efficiency_value);
    virtual void update_wind_speed_value(float wind_speed_value);
    virtual void update_pitch_cmd_value(float pitch_cmd_value);
    virtual void update_debug_log_value_value(float debug_log_1_value);
    virtual void update_debug_log_value_value(float debug_log_2_value);
    virtual void update_debug_log_value_value(float debug_log_3_value);
    virtual void update_debug_log_value_value(float debug_log_4_value);
    virtual void update_fps_counter_value(float fps_counter_value);
    
    virtual void update_change_the_name(float change_the_name);
protected:
};

#endif // UI_PAGE1VIEW_HPP
