
/**
 * @file    Engine\ScrollBarPanel.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

class TScrollBarPanel : public TPanel
{
public:

    TPanel *list_panel;

    int list_len;
    int one_step;
    int page_step;
    int list_num;

    TShape *button_pics;

    int back_frame,
        up_frame,
        down_frame,
        tab_frame,
        arrowSize,
        tabSize,
        tab_y,
        tab_min_y,
        tab_max_y,
        tab_mouse_y,
        tab_x,
        tab_min_x,
        tab_max_x,
        tab_mouse_x;

    enum ItemType
    {
        ItemNone   = 0x00,
        ItemUp     = 0x01,
        ItemDown   = 0x02,
        ItemTab    = 0x03,
        ItemTop    = 0x04,
        ItemBottom = 0x05,
    };
    char item_down;
    int item_is_down;
    int item_x,
        item_y;
    char item_mode;
    unsigned int item_last_time,
                 item_hold_interval,
                 item_down_interval;

    RECT up_rect,
         down_rect,
         tab_rect,
         top_rect,
         bottom_rect;

    enum Orientation
    {
        Vertical   = 0x00,
        Horizontal = 0x01,
    }
    orientationValue;

    int bevel_type;
    char bevel_color1,
         bevel_color2,
         bevel_color3,
         bevel_color4,
         bevel_color5,
         bevel_color6;

    TScrollBarPanel();

    ~TScrollBarPanel();

    int setup(TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, char *back_pic_in, char *up_pic_in, char *down_pic_in, char *tab_pic_in, int arrowSizeIn, int tabSizeIn, TPanel *list_panel_in, int list_len_in, TScrollBarPanel::Orientation orientation);

    void set_rect(int x_in, int y_in, int wid_in, int hgt_in);
    void calc_item_rects();
    void set_tab_pos(int list_num_in);
    void set_list_len(int list_len_in, int list_num_in);
    void set_buttons(TShape *button_pics_in, int back_frame_in, int up_frame_in, int down_frame_in, int tab_frame_in);
    void set_bevel_info(int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6);

    int handle_idle();

    int mouse_left_down_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_move_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_up_action(int x, int y, int ctrl_key, int shift_key);

    enum ActionType
    {
        ActionUp       = 0x00,
        ActionDown     = 0x01,
        ActionPrior    = 0x02,
        ActionNext     = 0x03,
        ActionPosition = 0x04,
        ActionEnd      = 0x05,
        ActionChange   = 0x06,
    };
    void scroll(TScrollBarPanel::ActionType action, int val);

    void draw();
    void draw_border(int button, int down, RECT *rect);
    void draw_border(int button, int down, int x1, int y1, int x2, int y2);
    void draw_back_pic();
    void draw_button_pic(int frame, int down, RECT *rect);
};
