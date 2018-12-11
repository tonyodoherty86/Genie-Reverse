#pragma once

/**
 * @file    Engine\TRB\Panel_Button.hpp
 * @author  Yvan Burrie
 * @date    2018/08/08
 * @version 1.0
 */

#include <Panel_Button.hpp>

class TRIBE_Panel_Button : public TButtonPanel
{
public:

    int display_garrison;

    int garrsion_number;

    char tribe_button_type;

    TShape *border_pic;

    char *color_table;

    int border_frame;

    char text_msg[256];

    int in_use;

    TRIBE_Panel_Button(
        TDrawArea *render_area_in,
        TPanel *parent_panel_in,
        TDigital *sound_in,
        void *font_in,
        int font_wid_in,
        int font_hgt_in,
        TShape *border_pic_in);

    ~TRIBE_Panel_Button();

    void set_text_msg(char *text_msg_in);
    int is_inside(int x, int y);
    void draw();
    void set_display_garrison(int value);
    void set_garrison_number(int value);
    int get_garrison_number();
};
