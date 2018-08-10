
/**
 * @file    Engine\TRB\PanelScreenGame.hpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

struct TRIBE_Port_Info
{
    short player_id;

    TRIBE_Player *player;

    TRIBE_Building_Object *port;

    short money;
};

struct TRIBE_Anim_Pal_Table
{
    char red, green, blue;
};

class TRIBE_Screen_Game : public TScreenPanel
{
public:

    TShape *game_screen_pic,
           *button_border1_pic,
           *button_other_pic,
           *button_border2_pic,
           *button_border3_pic,
           *button_cmd_pic,
           *button_tech_pic,
           *button_unit_pic,
           *button_bldg_pics[5],
           *more_cancel_pic;

    short more_frame,
          cancel_frame,
          unselect_frame;

    class TRIBE_Main_View *main_view;
    class TRIBE_Diamond_Map_View *map_view;

    TRIBE_Panel_Inven *inven_panel;
    TRIBE_Panel_Object *object_panel;
    TRIBE_Panel_Button *button_panel[17];

    TMessagePanel *text_line_panel;

    TTextPanel *quit_message_panel;

    TRIBE_Panel_Time *time_panel,
                     *countdown_clock[10];

    TRIBE_Panel_Pop *pop_panel;

    TMessagePanel *message_panel,
                  *message_panel2,
                  *message_panel3,
                  *message_panel4,
                  *message_panel5,
                  *message_panel6,
                  *chat_panel[RGE_PLAYERS_COUNT - 1];

    RGE_Panel_Tool_Box *tool_box;

    TTextPanel *age_panel,
               *pause_text,
               *fps_panel;

    TMessagePanel *score_panel[RGE_PLAYERS_COUNT - 1];

    TTextPanel *log_text;

    TScrollBarPanel *log_scrollbar;

    TRIBE_World *world;

    unsigned int update_interval;
    time_t last_update_time;
    unsigned int map_redraw_interval;
    time_t last_map_redraw_time;

    RGE_Static_Object *game_obj;

    short sel_count;

    Item_Avail *tech_list,
               *make_list,
               *bldg_list;

    Trade_Avail *trade_list;

    short item_cnt;
    short start_item;
    short last_item;

    TRIBE_Port_Info port_info[RGE_PLAYERS_COUNT];

    unsigned int terrain_sound_interval;
    time_t last_terrain_sound_time;
    RGE_Sound *terrain_sound;
    int terrain_playing;
    time_t terrain_sound_start_time;
    int anim_pal;
    unsigned int anim_pal_interval;
    time_t last_anim_pal_time;

    short last_anim_pal_index,
          last_anim_pal_index2,
          last_anim_pal_index3;

    TRIBE_Anim_Pal_Table anim_pal_table[7],
                         anim_pal_table2[16],
                         anim_pal_table3[12];

    int mouse_last_x,
        mouse_last_y;

    int save_age;
    int save_culture;
    int save_screen_width;
    time_t game_over_time;
    int showing_game_over;
    int chat_line;
    unsigned int view_interval;
    time_t last_view_time;
    int player_quit;
    int cheat_code_entry;
    char cheat_code_entry_str[52];
    int view_town_center_hotkey;
    int work_hotkey;
    int move_hotkey;
    int attack_hotkey;
    int ungroup_hotkey;
    int watch_hotkey;
    int select_building_hotkey[8];
    int reset_after_update;
    unsigned int score_interval;
    unsigned int last_score_time;
    int watch_mode;
    int game_ended;
    TDigital *game_over_sound;
    unsigned int last_game_speed_change;
    unsigned int last_pause_change;

    TRIBE_Screen_Game();

    ~TRIBE_Screen_Game();

    void set_redraw(TPanel::RedrawMode redraw_mode);
    void set_overlapped_redraw(TPanel *redraw_panel, TPanel *calling_panel, TPanel::RedrawMode redraw_mode);
    void set_map_buttons_redraw(TPanel::RedrawMode redraw_mode);
    int handle_size(int win_wid, int win_hgt);
    int handle_paint();
    int handle_idle();
    void handle_game_update();
    int wnd_proc(void *hwnd, unsigned int msg, unsigned int wParam, int lParam);
    int handle_mouse_down(int mouse_button_in, int x, int y, int ctrl_key, int shift_key);
    int handle_user_command(unsigned int wParam, int lParam);
    void handle_pause();
    void handle_resume();
    void handleChatReceived(int line_no);
    void display_system_message(char *msg);
    int key_down_action(int key, int count, int alt_key, int ctrl_key, int shift_key);
    int char_action(int key, short count);
    int action(TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2);
    void do_button_action(int action_in, int action2_in, int right_btn);
    void game_mode_changed(int old_mode, int new_mode);
    void player_changed(int old_player_id, int new_player_id);
    void object_changed();
    void age_changed();
    void show_timings(char *str1, char *str2);
    void show_comm(char *str, char *str2, char *str3, char *str4, char *str5, char *str6);
    void show_ai(char *str, char *str2, char *str3, char *str4, char *str5, char *str6);
    void show_message(TMessagePanel::MessageType message_type, char *str, char font_color_in, char back_color_in);
    void reset_buttons();
    void setup_buttons();
    void disable_unused_buttons();
    char *calc_text_msg(char *msg_str, Item_Avail *item, int button_action_id, int message_string_id);
    short calc_button_loc(char button_loc);
    void set_button(
        TShape *buttons,
        short button,
        short pic_index,
        int id,
        int id2,
        int help_string_id,
        int help_page_id,
        int hotkey,
        char *color_table,
        char *text2,
        char *text_msg,
        int make_disabled);
    void reset_clocks();
    void reset_score_display();
    void draw();
    void handle_anim_pal();
    void handle_terrain_sound();
    void handle_mouse_pointing_at();

    void command_add_attribute(int attr_id);
    void command_ai_info();
    void command_attack();
    void command_build();
    void command_building(int id);
    void command_cancel();
    void command_cancel_building();
    void command_chat();
    void command_quick_chat();
    void command_comm_info();
    void command_convert();
    void command_diplomacy();
    void command_fog_of_war();
    void command_fps();
    void command_game_speed(int increase_speed);
    void command_group();
    void command_group_by_number(int id);
    void command_heal();
    void command_repair();
    void command_score(int show);
    void command_select_group(int id, int unsel_prior);
    void command_menu();
    void command_more();
    void command_move();
    void command_outline();
    void command_pause();
    void command_player(int id);
    void command_quick_build();
    void command_quit();
    void command_research(int id);
    void command_save_game();
    void command_save_scenario();
    void command_select_building(int id);
    void command_stop();
    void command_tool_box();
    void command_trade();
    void command_trade_with(int id);
    void command_train(int id, short train_count);
    void command_ungroup();
    void command_unload();
    void command_unselect();
    void command_view_selected();
    void command_view_tribe();
    void command_visibility();
    void command_work();
    void command_formation(int formationID);
    void command_stand_ground();
    void command_attack_ground();
    void command_trade_attribute(int attribute);
    void command_tab_selected(int forward);

    int any_selected_have_action();
    void set_focus(int have_focus_in);
    void stop_sound_system();
};

int scr_game_score_compare(void *arg1, void *arg2);
