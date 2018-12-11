#pragma once

/**
 * @file    Engine\ListPanel.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

#include "Panel_Text.hpp"

class TListPanel : public TTextPanel
{
public:

    int auto_track;
    unsigned int mouse_scroll_last_time;
    unsigned int mouse_scroll_interval;
    int mouse_scroll_up;
    int mouse_scroll_down;
    int drawHighlightBar;

    TListPanel();

    ~TListPanel();

    void set_auto_track(int auto_track_in);
    void set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6);
    int handle_idle();
    int mouse_move_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_down_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_move_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_up_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_dbl_click_action(int x, int y, int ctrl_key, int shift_key);
    char *item_at(int x, int y);
    void goto_item(int x, int y);
    int key_down_action(int key, short count, int alt_key, int ctrl_key, int shift_key);
    int char_action(int key, short count);
    int action(TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2);
    void scroll_cur_line(char scroll_type, short scroll_val, int update_scrollbar);
    void draw();
    void draw_highlight_bar();
    void setDrawHighlightBar(int v);
    void set_focus(int have_focus_in);
};
