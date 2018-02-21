
/**
 * @file    Engine\EasyPanel.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

class TEasy_Panel : public TPanel
{
public:

    int ideal_width;
    int ideal_height;
    char info_file_name[260];
    int info_id;
    TShape *background_pic;
    TShape *background_pic2;
    void *palette;
    char cursor_file[260];
    int cursor_id;
    int background_pos;
    int use_bevels;
    char bevel_color1;
    char bevel_color2;
    char bevel_color3;
    char bevel_color4;
    char bevel_color5;
    char bevel_color6;
    unsigned int text_color1;
    unsigned int text_color2;
    unsigned int focus_color1;
    unsigned int focus_color2;
    unsigned int state_color1;
    unsigned int state_color2;
    char popup_info_file_name[260];
    int popup_info_id;
    TShape *button_pics;
    RGE_Color_Table *shadow_color_table;
    int shadow_amount;
    char background_color1;
    char background_color2;
    int enable_ime;
    char help_mode;
    int stock_brush;
    void *brush;
    unsigned int brush_color;
    TDrawArea *shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;

    TEasy_Panel(char *name);

    int setup(TDrawArea *render_area_in, TPanel *parent_in, char *info_file_name_in, int resource_file_id, int full_screen, int x_in, int y_in, int wid_in, int hgt_in, int allow_shadow_area_in);

    TEasy_Panel();

    void init_vars();

    ~TEasy_Panel();

    void prepare_for_close();

    void setup_shadow_area(int force_redraw);

    void draw_setup(int clear);
    void draw();
    void draw_background(int use_background2);

    int handle_mouse_down(int mouse_button_in, int x, int y, int ctrl_key, int shift_key);

    void set_info_file(char *file_name, int resource_file_id);
    void set_ideal_size(int width, int height);
    int set_background(char *file_name, int resource_id);
    int set_background2(char *file_name, int resource_id);
    void set_background_colors(int color1, char color2);
    int set_palette(char *file_name, int resource_file_id);
    int set_cursor(char *file_name, int resource_id);
    void set_use_bevels(int use_bevels_in);
    void set_background_pos(int background_pos_in);
    void set_bevel_colors(char c1, char c2, char c3, char c4, char c5, char c6);
    void set_text_colors(unsigned int c1, unsigned int c2);
    void set_focus_colors(unsigned int c1, unsigned int c2);
    void set_state_colors(unsigned int c1, unsigned int c2);
    void set_popup_info_file(char *file_name, int resource_file_id);
    void set_button_pics(char *file_name, int resource_file_id);
    void set_shadow_amount(int val);
    void set_enable_ime(int enable_ime_in);

    char *get_info_file();
    int get_info_id();
    TShape *get_background();
    TShape *get_background2();
    void *get_palette();
    char *get_cursor();
    int get_use_bevels();
    int get_background_pos();
    void get_bevel_colors(char *c1, char *c2, char *c3, char *c4, char *c5, char *c6);
    void get_text_colors(unsigned int *c1, unsigned int *c2);
    void get_focus_colors(unsigned int *c1, unsigned int *c2);
    int get_shadow_amount();
    void get_state_colors(unsigned int *c1, unsigned int *c2);
    char *get_popup_info_file();
    int get_popup_info_id();
    TShape *get_button_pics();
    RGE_Color_Table *get_shadow_color_table();
    int get_enable_ime();

    int create_button(TPanel *parent, TButtonPanel **button, int text_id1, int text_id2, int x, int y, int width, int height, int font_num, int sound_num, int action_id);
    int create_button(TPanel *parent, TButtonPanel **button, char *text1, char *text2, int x, int y, int width, int height, int font_num, int sound_num, int action_id);
    int create_check_box(TPanel *parent, TButtonPanel **button, int x, int y, int width, int height, int sound_num, int action_id);
    int create_radio_button(TPanel *parent, TButtonPanel **button, int x, int y, int width, int height, int sound_num, int action_id);
    int create_text(TPanel *parent, TTextPanel **text_panel, int text_id, int x, int y, int width, int height, int font_num, int horz_center, int vert_center, int word_wrap);
    int create_text(TPanel *parent, TTextPanel **text_panel, char *text, int x, int y, int width, int height, int font_num, int horz_center, int vert_center, int word_wrap);
    int create_text(TPanel *parent, TTextPanel **text_panel, char **text, int line_num, int x, int y, int width, int height, int font_num, int horz_center, int vert_center);
    int create_input(TPanel *parent, TInputPanel **input_panel, char *value, short max_len, TInputPanel::FormatType format_type, int x, int y, int width, int height, int font_num);
    int create_edit(TPanel *parent, TEditPanel **edit_panel, char *value, short max_len, TEditPanel::FormatType format_type, int x, int y, int width, int height, int font_num, int enable_ime, int turn_ime_on);
    char *create_drop_down(TPanel *parent, TDropDownPanel **drop_panel, int list_width, int list_height, int x, int y, int width, int height, int font_num);
    char *create_list(TPanel *parent, TListPanel **list_panel, int x, int y, int width, int height, int font_num);
    int create_scrollbar(TPanel *parent, TScrollBarPanel **scrollbar_panel, TTextPanel *list_panel, int list_size, int x, int y, int width, int height);
    int create_auto_scrollbar(TScrollBarPanel **scrollbar_panel, TTextPanel *list_panel, int width);
    int create_vert_slider(TPanel *parent, TVerticalSliderPanel **slider_panel, int scale, int one_step, int page_step, int x, int y, int width, int height);
    int create_horz_slider(TPanel *parent, THorizontalSliderPanel **slider_panel, int scale, int one_step, int page_step, int x, int y, int width, int height);

    void position_panel(TPanel *panel, int x, int y, int width, int height);

    void set_focus(int have_focus_in);

    void popupOKDialog(int text_id, char *panel_title, int wid, int hgt);
    void popupOKDialog(char *text, char *panel_title, int wid, int hgt);
    void popupYesNoDialog(int text_id, char *panel_title, int wid, int hgt);
    void popupYesNoDialog(char *text, char *panel_title, int wid, int hgt);
    void popupYesNoCancelDialog(int text_id, char *panel_title, int wid, int hgt);
    void popupYesNoCancelDialog(char *text, char *panel_title, int wid, int hgt);

    void command_help(char *in_parent_panel, int help_string, int help_page, int x, int y);
    void command_help(char *in_parent_panel, char *help_string, int help_page, int x, int y);

    void setup_popup_help();
    void clear_popup_help();
    int command_do_popup_help(char mouse_button_in, int mouse_x, int mouse_y);
    int action(TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2);

    void set_system_colors();
};
