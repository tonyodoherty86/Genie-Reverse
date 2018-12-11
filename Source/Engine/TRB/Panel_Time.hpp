#pragma once

/**
 * @file    Engine\TRB\PanelTime.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

#include <Panel.hpp>

class TRIBE_World;
class TRIBE_Player;

class TRIBE_Panel_Time : public TPanel
{
public:

    void *font;
    unsigned int color1;
    unsigned int color2;
    int clock_type;
    int old_clock_type;
    int clock_format;
    int old_clock_format;

    int player_id;

    TRIBE_World *world;

    TRIBE_Player *player;

    time_t start_real_time,
           game_time,
           last_game_time,
           display_time,
           last_display_time;

    void *image_clip_region;

    TDrawArea *ImageBuffer;

    RECT ImageRect,
         UsedImageRect,
         UsedScreenRect;

    int ImageTextActive;
    int LastIBWidth;
    int LastIBHeight;

    TRIBE_Panel_Time( TDrawArea *render_area_in, TPanel *parent_in );

    ~TRIBE_Panel_Time();

    void startup();
    void set_clock_type( int clock_type_in, int player_id_in );
    int get_clock_type();
    int get_player_id();
    void draw();
    void get_true_render_rect( RECT *drawRect );
    int handle_idle();
    void *render_to_image_buffer();
};

//typedef TTextPanel::Style Time_Line_Panel::Style;

//typedef TTextPanel::BevelType Time_Line_Panel::BevelType;

struct Special_Events
{
    int time_slice;

    int X_line_pos,
        Y_line_pos;

    int intermediate_y_line_segment;

    char player_id;

    char player_color;

    char event;

    int pop_total;

    int interger_value_1,
        interger_value_2;

    int start_x,
        start_y;

    int start_txt_x1,
        start_txt_y1,
        start_txt_x2,
        start_txt_y2;

    int text_length1;
    char text1[50];
    int text_length2;
    char text2[50];

    int icon_flag;

    Special_Events *next;
};


class Time_Line_Panel : public TEasy_Panel
{
public:

    void *axis_font;

    int axis_font_wid,
        axis_font_hgt;

    void *body_font;

    int body_font_wid,
        body_font_hgt;

    TTextPanel::Style text_style;

    unsigned int text_color1,
                 text_color2;

    unsigned int highlightTextColor1;
    unsigned int highlightTextColor2;

    int text_wid,
        text_hgt;

    TShape *background_pic;

    short background_pic_wid,
          background_pic_hgt;

    int fill_back;
    char back_color;
    int outline;
    char outline_color;
    int sorted;
    int bevel_type;

    char bevel_color1,
         bevel_color2,
         bevel_color3,
         bevel_color4,
         bevel_color5,
         bevel_color6;

    TShape *special_events_pic;

    short special_events_pic_wid,
          special_events_pic_hgt;

    int X_start_line_pos;
    int Y_start_line_pos;
    int X_line_pos;
    int Y_line_pos;
    int X_line_max_width;
    int Y_line_max_length;
    int X_axis_length;
    int Y_axis_length;
    float bar_thickness;
    int pop_reading_rate;
    float time_slice_drop_rate;
    int total_slices_to_drop;
    char drop_flag;
    int num_entries_page;
    int num_history_entries;
    Special_Events *time_slice_events;
    char timeline_flag;
    TTextPanel *legend_entry_text[3];

    Time_Line_Panel();

    ~Time_Line_Panel();

    signed int create_timeline(TPanel *parent_panel_in, Time_Line_Panel **a3, int y_in, int a5, int a6, int a7, int a8, int a9, int a10, int a11);

    int setup(
        TDrawArea *render_area_in,
        TPanel *parent_panel_in,
        int x_in,
        int y_in,
        int wid_in,
        int hgt_in,
        void *axis_font_in,
        int axis_font_wid_in,
        int axis_font_hgt_in,
        void *body_font_in,
        int body_font_wid_in,
        int body_font_hgt_in,
        char *back_pic_in,
        char *special_event_pic_in,
        int fill_back_in,
        char back_color_in,
        int outline_in,
        char outline_color_in );

    void set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6);
    int set_background(char *file_name);
    int set_background(char *file_name, int resource_id);
    int set_special_events(char *file_name);
    int set_special_events(char *file_name, int resource_id);
    void set_axis_font(void *font_in, int font_wid_in, int font_hgt_in);
    void set_body_font(void *font_in, int font_wid_in, int font_hgt_in);
    void set_back_color(int use_back_color_flag_in, char back_color_in);
    void draw_border();
    void init_timeline();
    void add_pop_total_special_event(int sample_time_slice, int sample_pop_total, int sample_x_line_pos, int time_flag);
    void record_special_event(char player_id, TRIBE_History_Info *history, char player_color, int time_slice, int x_line_pos, int y_line_pos, int intermediate_y_line_segment);
    int calculate_icon_location(Special_Events *event_ptr, short icon_number, char history_type);

    void draw();
    void draw_axis();
    void draw_special_events();
    void draw_background();
    void draw_civilization_names();
    void draw_timeline();
    void draw_icon(Special_Events *event_ptr, short icon_number, char history_type);
    void draw_legend();
};
