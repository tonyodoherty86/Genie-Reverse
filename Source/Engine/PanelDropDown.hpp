
/**
 * @file    Engine\TRB\PanelDropDown.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

class TDropDownPanel : public TPanel
{
public:

    TTextPanel *val_panel;
    TButtonPanel *btn_panel;
    TListPanel *list_panel;
    TScrollBarPanel *scbar_panel;

    enum DropdownMode
    {
        ModeNone  = 0x00,
        ModeValue = 0x01,
        ModeList  = 0x02,
    }
    mode;

    short val_num;
    int val_wid;
    int val_hgt;
    int btn_wid;
    int btn_hgt;
    int list_wid;
    int list_hgt;
    int scbar_wid;
    int scbar_arrow_hgt;
    int scbar_tab_hgt;
    char list_is_above;
    int font_hgt;
    int outline_color;

    enum DrawStyle
    {
        DrawStyleNormal     = 0x00,
        DrawStyleLeftButton = 0x01,
    }
    draw_style;

    int draw_val_rect;

    TDropDownPanel();

    ~TDropDownPanel();

    void setup(
        TDrawArea *render_area_in,
        TPanel *parent_panel_in,
        void *font_in,
        int font_wid_in,
        int font_hgt_in,
        int fill_back_in,
        char back_color_in,
        int outline_in,
        int outline_color_in,
        int x_in,
        int y_in,
        int wid_in,
        int hgt_in,
        short val_len_in,
        short val_num_in,
        int btn_wid_in,
        int btn_hgt_in,
        char *btn_pic_in,
        int list_wid_in,
        int list_hgt_in,
        char **list_in,
        int list_num_lines_in,
        int scbar_wid_in,
        char *scbar_back_pic_in,
        char *scbar_up_pic_in,
        char *scbar_down_pic_in,
        char *scbar_tab_pic_in,
        int scbar_arrow_hgt_in,
        int scbar_tab_hgt_in);

    int handle_mouse_down(int mouse_button_in, int x, int y, int ctrl_key, int shift_key);
    int handle_mouse_move(int x, int y, int ctrl_key, int shift_key);
    int handle_mouse_up(int mouse_button_in, int x, int y, int ctrl_key, int shift_key);
    int handle_key_down(int key, int count, int alt_key, int ctrl_key, int shift_key);

    enum ActionType
    {
        ActionItem  = 0x00,
        ActionList  = 0x01,
        ActionValue = 0x02,
    };
    int action(TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2);

    void set_rect(int x_in, int y_in, int wid_in, int hgt_in);
    void set_val_text_color(unsigned int text_color1_in, unsigned int text_color2_in);
    void set_draw_style(DrawStyle draw_style_in);
    void set_draw_val_rect(int draw_val_rect_in);
    void set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6);
    void set_buttons(TShape *button_shape_in, int btn_frame_in, int scbar_back_frame_in, int scbar_up_frame_in, int scbar_down_frame_in, int scbar_tab_frame_in);
    void set_mode(DropdownMode mode_in);
    int numberLines();
    int currentLineNumber();
    void setCurrentLineNumber(int line_num_in);
    void setCurrentLineId(int id_in);
    char *currentLine();
    void set_tab_order(TPanel *prev_panel, TPanel *next_panel);
    void set_sorted(int sorted_in);
    int get_sorted();
    void set_line(int line_in);
    void *append_line(char *text_in, int id_in);
    void *append_line(int string_id_in, int id_in);
    void *insert_line(int line_in, char *text_in, int id_in);
    void *insert_line(int line_in, int string_id_in, int id_in);
    int delete_line(int line_in);
    int get_line();
    int get_line(int id_in);
    int get_line(char *text_in);
    char *get_text();
    char *get_text(int line_in);
    int get_id();
    int get_id(int line_in);
    void empty_list();
};
