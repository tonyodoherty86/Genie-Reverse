#pragma once

#include "Panel_Text.hpp"


/**
 * @file    Engine\InputPanel.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

class TInputPanel : public TTextPanel
{
public:

    enum ActionType
    {
        ActionEnter  = 0x00,
        ActionEscape = 0x01,
        ActionTab    = 0x02,
    };

    char caret_color;
    unsigned int caret_interval;
    unsigned int caret_last_time;
    int draw_caret;

    TDigital *overLengthSound;

    enum FormatType
    {
        FormatText        = 0x00,
        FormatNumber      = 0x01,
        FormatInteger     = 0x02,
        FormatUnsignedInt = 0x03,
        FormatFile        = 0x04,
        FormatFileNoExt   = 0x05,
        FormatPath        = 0x06,
        FormatMultiLine   = 0x07,
        FormatPercent     = 0x08,
    }
    format_type;

    char *input_buffer;
    char *input_buffer1;
    char *input_buffer2;

    short input_len;
    short max_len;
    int insert_mode;
    short input_pos;

    TInputPanel();

    ~TInputPanel();

    int setup(TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, void *font_in, int font_wid_in, int font_hgt_in, char *back_pic_in, int fill_back_in, char back_color_in, int outline_in, char outline_color_in, char caret_color_in, short max_len_in, TDigital *overLengthSoundIn, char *text_in, TInputPanel::FormatType format_type_in);

    void set_focus(int have_focus_in);
    void set_format(TInputPanel::FormatType format_type_in);
    int handle_idle();
    int char_action(int key, short count);
    int key_down_action(int key, short count, int alt_key, int ctrl_key, int shift_key);
    void draw();
    void set_text(char *text_in);
    char *get_input_buffer();
    int append_character(int c);
    int insert_character(int c);
    int delete_character();
    int backspace_character();
    int paste();
    void reformat();
    void calc_input_pos();
    void calc_cur_line_col();
    int is_blank();
    char *get_trimmed_str(char *str, int str_len);
};
