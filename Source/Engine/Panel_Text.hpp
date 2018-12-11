#pragma once

#include "Panel.hpp"

/**
 * @file    Engine\TextPanel.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

class TTextPanel : public TPanel
{
public:

    struct TextNode
    {
        char *text;
        char *text2;
        int id;
        TextNode *next_node;
    }
    *list;

    short num_lines;
    short draw_lines;
    short top_line;
    short bot_line;
    short cur_line;
    short cur_col;

    void *font;

    int font_wid,
        font_hgt;

    enum Alignment
    {
        AlignCenter           = 0x00,
        AlignLeft             = 0x01,
        AlignRight            = 0x02,
        AlignTop              = 0x03,
        AlignBottom           = 0x04,
        AlignHorizontalScroll = 0x05,
        AlignWordwrap         = 0x06,
    }
    vert_align,
    horz_align;

    int word_wrap;

    enum Style
    {
        NormalStyle   = 0x00,
        BeveledStyle  = 0x01,
        ChiseledStyle = 0x02,
    }
    text_style;

    unsigned int text_color1,
                 text_color2,
                 highlightTextColor1,
                 highlightTextColor2;

    TScrollBarPanel *scbar_panel;
    int auto_scbar;
    short fixed_len;

    int text_wid,
        text_hgt;

    TShape *back_pic;

    short back_pic_wid,
          back_pic_hgt;

    int fill_back;
    char back_color;
    int outline;
    char outline_color;
    int sorted;
    int second_column_pos;
    int full_width;
    int scbar_width;
    int scbar_active;
    int bevel_type;

    char bevel_color1,
         bevel_color2,
         bevel_color3,
         bevel_color4,
         bevel_color5,
         bevel_color6;

    void *clip_rgn2;
    int border_size;
    int spacer_size;

    TTextPanel();

    ~TTextPanel();

    int setup(
        TDrawArea *render_area_in,
        TPanel *parent_panel_in,
        int x_in,
        int y_in,
        int wid_in,
        int hgt_in,
        void *font_in,
        int font_wid_in,
        int font_hgt_in,
        char *back_pic_in,
        int fill_back_in,
        char back_color_in,
        int outline_in,
        char outline_color_in,
        short fixed_len_in,
        char *text_in );

    int setup(
        TDrawArea *render_area_in,
        TPanel *parent_panel_in,
        int x_in,
        int y_in,
        int wid_in,
        int hgt_in,
        void *font_in,
        int font_wid_in,
        int font_hgt_in,
        char *back_pic_in,
        int fill_back_in,
        char back_color_in,
        int outline_in,
        char outline_color_in,
        short fixed_len_in,
        int string_id_in );

    int setup(
        TDrawArea *render_area_in,
        TPanel *parent_panel_in,
        int x_in,
        int y_in,
        int wid_in,
        int hgt_in,
        void *font_in,
        int font_wid_in,
        int font_hgt_in,
        char *back_pic_in,
        int fill_back_in,
        char back_color_in,
        int outline_in,
        char outline_color_in,
        short fixed_len_in,
        char **text_in,
        int num_lines_in );

    void set_rect(int x_in, int y_in, int wid_in, int hgt_in);
    void set_scrollbar(TScrollBarPanel *scbar_panel_in, int auto_scbar_in);
    static signed int char_type(char *c);
    void set_text(char *text_in);
    int word_wrap_append(char *text_in);
    void set_text(int string_id_in);
    void set_text(char **text_in, short num_lines_in);
    void set_font(void *font_in, int font_wid_in, int font_hgt_in);
    void set_alignment(Alignment vert_align_in, Alignment horz_align_in);
    void set_word_wrap(int word_wrap_in);
    void set_style(Style text_style_in);
    void set_text_color(unsigned int text_color1_in, unsigned int text_color2_in);
    void set_highlight_text_color(unsigned int text_color1_in, unsigned int text_color2_in);
    void set_fill_back(int fill_back_in, char back_color_in);
    void set_back_pic(char *back_pic_in);
    void set_outline(int outline_in, char outline_color_in);
    void set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6);
    void set_spacer_size(int size_in);
    void set_active(int activ_in);
    void calc_draw_info(int update_scbar);
    void scroll(char scroll_type, short scroll_val, int update_scbar);
    int key_down_action(int key, int count, int alt_key, int ctrl_key, int shift_key);
    int action(TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2);
    void draw();
    void draw_background();
    void draw_border();
    void draw_line(void *dc, short draw_row, short text_line, unsigned int color1, unsigned int color2);
    void calc_line_pos(void *dc, short draw_row, short text_line, RECT *line_rect, int *cursor_x_offset);
    int mouse_left_down_action(int x, int y, int ctrl_key, int shift_key);
    int numberLines();
    int numberDrawLines();
    int currentLineNumber();
    void setCurrentLineNumber(int v);
    char *currentLine();
    void set_line(int line_in);
    void set_line_by_id(int id_in);
    void *append_line(char *text_in, int id_in);
    void *append_line(char *text_in, char *text2_in, int id_in);
    void *append_line(int string_id_in, int id_in);
    void *append_line(int string_id_in, int string_id2_in, int id_in);
    void *insert_line(int line_in, char *text_in, int id_in);
    void *insert_line(int line_in, char *text_in, char *text2_in, int id_in);
    void *insert_line(int line_in, int string_id_in, int id_in);
    void *insert_line(int line_in, int string_id_in, int string_id2_in, int id_in);
    void *change_line(int line_in, char *text_in, char *text2_in, int id_in);
    void *change_line(int line_in, int string_id_in, int string_id2_in, int id_in);
    int delete_line(int line_in);
    int get_line();
    int get_line(int id_in);
    int get_line(char *text_in);
    char *get_text();
    char *get_text(int line_in);
    char *get_text2();
    char *get_text2(int line_in);
    int get_id();
    int get_id(int line_in);
    void empty_list();
    void free_text();
    void set_second_column_pos(int val);
    int get_text_rect(RECT *rect);
};
