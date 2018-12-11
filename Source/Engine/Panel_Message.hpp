#pragma once

/**
 * @file    Engine\MessagePanel.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

#include "Panel.hpp"

class TMessagePanel : public TPanel
{
public:

    enum MessageType
    {
        InfoMessage        = 0x00,
        BadMessage         = 0x01,
        DebugMessage       = 0x02,
        ChatMessage        = 0x03,
        ColoredChatMessage = 0x04,
        RightInfoMessage   = 0x05,
    }
    message_type;

    char text[512];
    int showing_message;
    unsigned int start_time;
    int show_message_interval;
    void *font;
    int font_wid;
    int font_hgt;
    char font_color;
    char back_color;
    int index_color;
    unsigned int font_color1;
    unsigned int font_color2;

    enum JustType
    {
        TopJust    = 0x00,
        BottomJust = 0x01,
        LeftJust   = 0x02,
        RightJust  = 0x03,
        CenterJust = 0x04,
    }
    horz_just,
    vert_just;

    int word_wrap;
    void *image_clip_region;
    TDrawArea *ImageBuffer;
    RECT ImageRect;
    RECT UsedImageRect;
    RECT UsedScreenRect;
    int LastIBWidth;
    int LastIBHeight;
    int ImageTextActive;
    TShape *Icon1;
    TShape *Icon2;
    int IconFrame1;
    int IconFrame2;

    TMessagePanel(void *font_in, int font_wid_in, int font_hgt_in);

    ~TMessagePanel();

    void set_justification(TMessagePanel::JustType horz_just_in, TMessagePanel::JustType vert_just_in, int word_wrap_in);
    void show_message(TMessagePanel::MessageType message_type_in, char *text_in, char colorIn, char backColorIn, void *font_in, int font_wid_in, int font_hgt_in);
    void show_message2(TMessagePanel::MessageType message_type_in, char *text_in, unsigned int color1, unsigned int color2, void *font_in, int font_wid_in, int font_hgt_in, TShape *Icon1_in, int Frame1_in, TShape *Icon2_in, int Frame2_in);
    void remove_message();
    void draw();
    void get_true_render_rect(RECT *drawRect);
    int handle_idle();
    void *render_to_image_buffer();
    int handle_mouse_down(char mouse_button_in, int x, int y, int ctrl_key, int shift_key);
    int handle_mouse_move(int x, int y, int ctrl_key, int shift_key);
    int handle_mouse_up(char mouse_button_in, int x, int y, int ctrl_key, int shift_key);
    void set_font(void *font_in, int font_wid_in, int font_hgt_in);
};
