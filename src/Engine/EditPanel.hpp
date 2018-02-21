
/**
 * @file    Engine\EditPanel.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

//typedef TInputPanel::FormatType TEditPanel::FormatType;

class TEditPanel : public TPanel
{
public:

    enum FormatType{};

    void *edit_wnd;
    short fixed_len;
    char *text;
    int text_len;
    int hidden;
    void *brush;
    int stock_brush;
    int (__stdcall *old_sub_wnd_proc)();
    unsigned int text_color1;
    unsigned int text_color2;
    unsigned int highlight_text_color1;
    unsigned int highlight_text_color2;
    unsigned int back_color;
    //TEditPanel::FormatType format;
    void *font;
    int multi_line;
    RECT draw_rect;
    unsigned int draw_format;
    int auto_sel;
    int sel_len;
    int bevel_type;
    char bevel_color1;
    char bevel_color2;
    char bevel_color3;
    char bevel_color4;
    char bevel_color5;
    char bevel_color6;
    int bevel_size;
    unsigned int imc;
    int enable_ime;
    int turn_ime_on;

    TEditPanel();

    ~TEditPanel();

    int setup(TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, void *font_in, short fixed_len_in, char *text_in, TEditPanel::FormatType format_in, int auto_sel_in);

    static int pnl_sub_wnd_proc(HWND *wnd, UINT msg, WPARAM wparam, LPARAM lparam);

    void set_text(char *text_in);
    void update_text();
    char *get_text();
    char *get_input_buffer();
    char *currentLine();

    void set_active(int activ_in);
    void set_focus(int have_focus_in);
    void set_rect(int x_in, int y_in, int wid_in, int hgt_in);
    void set_redraw(TPanel::RedrawMode redraw_mode);
    void set_text_color(unsigned int val1, unsigned int val2);
    void set_highlight_text_color(unsigned int val1, unsigned int val2);
    void set_back_color(void *brush_in, unsigned int brush_color_in, char color_in);
    void set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6);
    void set_ime_info(int enable_ime_in, int turn_ime_on_in);

    void *wnd_proc(HWND *hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int sub_wnd_proc(HWND *hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

    int verify_char(int key);
    void draw();
    int is_blank();
    char *get_trimmed_str(char *str, int str_len);

    void handle_reactivate();
    int handle_mouse_down(int mouse_button_in, int x, int y, int ctrl_key, int shift_key);
};
