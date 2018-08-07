
/**
 * @file    Engine\RGE\MainView.hpp
 * @author  Yvan Burrie
 * @date    2018/08/07
 * @version 1.0
 */

struct RGE_Pick_Info
{
    float x, y;

    short scr_x,
          scr_y;

    RGE_Static_Object *object;

    RGE_Tile *tile;
};

class RGE_Main_View : public RGE_View
{
public:

    TPanel *map_view;

    unsigned int last_mouse_scroll_time;
    int mouse_scrolling;
    int mouse_last_x,
        mouse_last_y;
    unsigned int last_key_scroll_time;
    int key_scrolling;

    RGE_Player *save_player;

    RGE_Main_View();

    ~RGE_Main_View();

    int handle_idle();
    int do_auto_scroll();
    int handle_keys();
    int handle_mouse_up(int mouse_button_in, int x, int y, int ctrl_key, int shift_key);
    int mouse_move_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_down_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_move_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_left_up_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_right_down_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_right_move_action(int x, int y, int ctrl_key, int shift_key);
    int mouse_right_up_action(int x, int y, int ctrl_key, int shift_key);
    int start_scroll_view(char scroll_action_in, int x, int y, int ctrl_key, int shift_key);
    int handle_scroll_view(int x, int y);
    void draw();
    int command_place_object(int x, int y, int reset_mode);
    int command_make_do(int x, int y, int work_on_tile, short action_type);
    char pick1(char pick_mode_in, char select_level, int x, int y, RGE_Pick_Info *pick_info, RGE_Static_Object *last_picked_object, int pick_dopples);
    int pick_objects1(int x, int y, RGE_Static_Object **object_list, int max_objects);
    RGE_Static_Object *pick_best_target(int x, int y, int *attacking_in, short action_type);
    int command_make_move(int x, int y);
    int command_make_work(int x, int y);
    int command_place_multi_object(int x1, int y1, int x2, int y2, int reset_mode);
    char get_help_info(char **string, int *page, int x, int y);
    void fixup_pick_info(RGE_Pick_Info *pick_info);
    void reset_display_object_selection(int reset_type);
};
