#pragma once

/**
 * @file    Engine\PanelScrollText.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

#include "Panel_Text.hpp"

class TScrollTextPanel : public TTextPanel
{
    enum ActionType
    {
        ActionDone = 0x01,
    };

    int scroll;
    time_t last_time;
    int speed;
    int done;

    TScrollTextPanel(
        TPanel *parent_in,
        TDrawArea *render_area_in,
        int x,
        int y,
        int wid,
        int hgt,
        int speed_in,
        void *font_in,
        int font_wid_in,
        int font_hgt_in,
        char *text_in );

    ~TScrollTextPanel();

    void set_text( char *text_in );

    int handle_idle();

    void draw();

    void draw_scrolled_line(
        void *dc,
        short draw_row,
        short text_line,
        unsigned int color1,
        unsigned int color2 );
};
