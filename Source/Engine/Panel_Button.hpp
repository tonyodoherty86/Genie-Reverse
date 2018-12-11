#pragma once

#include "Panel.hpp"

/**
 * @file    Engine\ButtonPanel.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

class TButtonPanel : public TPanel
{
public:

    int id[9];
    int id2[9];

    enum ButtonType
    {
        Normal = 0x01,
        Radio  = 0x02,
        State  = 0x03,
    }
    buttonTypeValue;

    /**
     * DrawType
     */
    int drawTypeValue;

    enum NotifyType
    {
        NotifyAction  = 0x01,
        NotifyCommand = 0x02,
    }
    notifyTypeValue;

    TDigital *sound;

    TShape *pic[9];

    short pic_index[9];
    int auto_pic_pos;
    int pic_x,
        pic_y;
    int all_hot;
    int draw_reverse;
    char *text1[9],
         *text2[9];
    int text_x,
        text_y;
    void *font;
    int font_wid,
        font_hgt;
    short num_states,
          cur_state;
    int is_down;

    TButtonPanel **radio_buttons;

    short num_radio_buttons;

    unsigned int button_down_time,
                 text_color1[9],
                 text_color2[9],
                 highlight_text_color1[9],
                 highlight_text_color2[9];

    int hotkey,
        hotkey_shift;

    int bevel_type;

    char bevel_color1,
         bevel_color2,
         bevel_color3,
         bevel_color4,
         bevel_color5,
         bevel_color6;

    int key_down;
    int disabled;
    int sound_number;

    TButtonPanel();

    ~TButtonPanel();

    int setup(
        TDrawArea *render_area_in,
        TPanel *parent_panel_in,
        int x_in,
        int y_in,
        int wid_in,
        int hgt_in,
        TPanel *a8,
        TDigital *sound_in,
        TPanel *notifyTypeIn,
        int id_in);

    ButtonType buttonType();
    int drawType();
    NotifyType notifyType();
    int setDrawType(int draw_type);
    void setButtonType(ButtonType buttonTypeIn);
    void set_picture_info(TShape *pic_in, short pic_index_in, int pic_x_in, int pic_y_in, int all_hot_in, int auto_pic_pos_in);
    void set_text_info(char *text_in, void *font_in, int font_wid_in, int font_hgt_in, int text_x_in, int text_y_in);
    void set_text_info(int string_id_in, void *font_in, int font_wid_in, int font_hgt_in, int text_x_in, int text_y_in);
    void set_text_pos(int text_x_in, int text_y_in);
    void set_radio_info(TButtonPanel **buttons_in, short button_count_in);
    void set_state_info(short num_states_in);
    void set_id(short state_in, int id_in, int id2_in);
    void set_picture(short state_in, TShape *pic_in, short pic_index_in);
    void set_text(short state_in, char *text_in);
    void set_text(short state_in, char *text1_in, char *text2_in);
    void set_text(short state_in, int string_id_in);
    void set_text(short state_in, int string_id1_in, int string_id2_in);
    void set_font(void *font_in, int font_wid_in, int font_hgt_in);
    void set_text_color(int state, unsigned int text_color1_in, unsigned int text_color2_in);
    void set_highlight_text_color(int state, unsigned int text_color1_in, unsigned int text_color2_in);
    void set_sound(TDigital *sound_in);
    void set_radio_button();
    void set_state(short state_in);
    void set_state_by_id(int id_in);
    void set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6);
    void set_disabled(int val);
    void set_rect(int x_in, int y_in, int wid_in, int hgt_in);

    int get_state();
    int get_id();
    int get_id2();
    int get_text(short state_in, char **text1_in, char **text2_in);
    void get_text_color(short state_in, unsigned int *color1, unsigned int *color2);

    void draw();

    int handle_mouse_down(int mouse_button_in, int x, int y, int ctrl_key, int shift_key);
    int mouse_left_dbl_click_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_down_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_move_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_up_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_right_dbl_click_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_right_down_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_right_move_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_right_up_action(int x, int y, int ctrl_key, int shift_key);
    int handle_key_down(int key, int count, int alt_key, int ctrl_key, int shift_key);
    int key_down_action(int key, short count, int alt_key, int ctrl_key, int shift_key);

    int wnd_proc(HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

    int char_action(int key, short count);
    int hit_button(int x, int y);
    void do_action();
    void do_right_action(int shift_key);

    void reset();

    void set_sound_number(int sound_number_in);
    void stop_sound_system();
    int restart_sound_system();
};

//typedef int TButtonPanel::DrawType(HDC, LPCSTR, int, LPRECT, UINT);

//typedef TTextPanel::Action TButtonPanel::ActionType;
//typedef TTextPanel::BevelType TButtonPanel::BevelType;
