
/**
 * @file    Engine\TRB\Panel_Screen_ScenarioEditor.hpp
 * @author  Yvan Burrie
 * @date    2018/08/09
 * @version 1.0
 */

class TRIBE_Screen_Sed : public TScreenPanel
{
public:

    int is_multi_player;
    int set_player_first_flag;

    RGE_Static_Object *SelectedObject,
                      *DestinationObject;

    float px1, py1, px2, py2;

    int CurrentVictory,
        CurrentPlayer;

    enum SELECT_REGION_e
    {
        SELECT_OFF         = 0x00,
        SELECT_OBJECT      = 0x01,
        SELECT_DEST_OBJECT = 0x02,
        SELECT_AREA        = 0x03,
    }
    SelectRegionFlag;

    enum ScenarioMode
    {
        ScenarioModeNone         = 0x00,
        ScenarioModeMap          = 0x01,
        ScenarioModeTerrain      = 0x02,
        ScenarioModePlayers      = 0x03,
        ScenarioModeUnits        = 0x04,
        ScenarioModeDiplomacy    = 0x05,
        ScenarioModeVictory      = 0x06,
        ScenarioModeVictoryMulti = 0x07,
        ScenarioModeOptions      = 0x08,
        ScenarioModeMessages     = 0x09,
        ScenarioModeCinematics   = 0x0A,
        ScenarioModeSave         = 0x0B,
    }
    scenario_mode;

    enum MapType
    {
        MapTypeNone   = 0x00,
        MapTypeBlank  = 0x01,
        MapTypeRandom = 0x02,
        MapTypeSeed   = 0x03,
    }
    map_type;

    enum VictoryType
    {
        VictoryTypeNone     = 0x00,
        VictoryTypeStandard = 0x01,
        VictoryTypeConquest = 0x02,
        VictoryTypeScore    = 0x03,
        VictoryTypeTime     = 0x04,
        VictoryTypeCustom   = 0x05,
    }
    mp_victory_type;

    enum BrushSize
    {
        BrushSizeNone      = 0x00,
        BrushSizeVerySmall = 0x01,
        BrushSizeSmall     = 0x02,
        BrushSizeMedium    = 0x03,
        BrushSizeLarge     = 0x04,
        BrushSizeXLarge    = 0x05,
    }
    brush_size;

    enum PaintType
    {
        PaintTypeNone      = 0x00,
        PaintTypeTerrain   = 0x01,
        PaintTypeElevation = 0x02,
        PaintTypeCliffs    = 0x03,
    }
    paint_type;

    short player_num;

    enum MessageType
    {
        MessageTypeNone         = 0x00,
        MessageTypeDescription  = 0x01,
        MessageTypeInstructions = 0x02,
        MessageTypeVictory      = 0x03,
        MessageTypeFailure      = 0x04,
    }
    message_type;

    char need_to_save_flag,
         valid_save_spot_flag;

    TShape *background_pic;

    TRIBE_Main_View *main_view;

    RGE_Diamond_Map_View *map_view;

    TMessagePanel *message_panel;
    TPanel *bottom_panel;

    TButtonPanel *scenario_mode_button[10],
                 *menu_button,
                 *help_button,
                 *map_type_button[3];

    TTextPanel *map_type_text[3];
    TTextPanel *map_type_label;
    TTextPanel *default_terrain_label;
    TDropDownPanel *default_terrain_drop;
    TTextPanel *map_size_label;
    TDropDownPanel *map_size_drop;
    TTextPanel *map_style_label;
    TDropDownPanel *map_style_drop;
    TTextPanel *random_seed_label;
    TEditPanel *random_seed_input;
    TTextPanel *random_seed_used_label;
    TTextPanel *random_seed_used_text;
    TButtonPanel *generate_map_button;
    TTextPanel *map_generating_text;
    TTextPanel *brush_size_label;
    TButtonPanel *brush_size_button[5];
    TTextPanel *brush_size_button_label[5];
    TTextPanel *paint_type_label;
    TButtonPanel *paint_type_button[3];
    TTextPanel *paint_type_button_label[3];
    TTextPanel *paint_terrain_label;
    TListPanel *paint_terrain_list;
    TScrollBarPanel *paint_terrain_scrollbar;
    TListPanel *paint_elevation_list;
    TScrollBarPanel *paint_elevation_scrollbar;
    TTextPanel *player_label;

    TDropDownPanel *player_list,
                   *player_number_list,
                   *player_advance_civilization_drop;

    TButtonPanel *player_advance_civilization_button;
    TTextPanel *player_inven_label[5];
    TEditPanel *player_inven_input[5];
    TTextPanel *player_setting_label[2];
    TTextPanel *player_starting_age_label;

    TDropDownPanel *player_setting_drop[2],
                   *BuildList,
                   *CityLayout,
                   *AiRules;

    TTextPanel *player_build_text,
               *player_city_text,
               *AiRules_text;

    TDropDownPanel *unit_player_list;
    TButtonPanel *unit_mode_select[4];
    TTextPanel *unit_mode_select_label[4];
    TListPanel *unit_list;
    TScrollBarPanel *unit_scrollbar;

    struct List_Info
    {
        char text[100];
        short id;
    }
    *unit_list_info;

    TShape *button_unit_pics,
           *button_bldg_pics[5];

    TRIBE_Scenario_Editor_Panel_Object *object_panel;

    short unit_list_size;

    TButtonPanel *victory_cond_on[6],
                 *victory_and_or[2];

    TTextPanel *victory_condition_label,
               *victory_amount_label,
               *victory_long_label,
               *victory_text_and_or[2],
               *victory_label_conquest,
               *victory_label_explore,
               *victory_label_explore_percent,
               *victory_label_ruins,
               *victory_label_artifacts,
               *victory_label_discoveries,
               *victory_label_gold;

    TEditPanel *victory_condition_explore,
               *victory_condition_ruins,
               *victory_condition_artifacts,
               *victory_condition_discoveries,
               *victory_condition_gold;

    TTextPanel *victory_cond_type_label[5];
    TButtonPanel *victory_cond_type[5];
    TTextPanel *victory_score_label;
    TDropDownPanel *victory_score;
    TTextPanel *victory_time_label;
    TDropDownPanel *victory_time;
    TButtonPanel *victory_button[12];

    TDropDownPanel *victory_drop_down,
                   *victory_object_list,
                   *victory_player_list,
                   *victory_enemy_player_list,
                   *victory_attribute_list,
                   *victory_ages_list,
                   *victory_tech_list;

    TButtonPanel *victory_button_set_object,
                 *victory_button_set_destination,
                 *victory_button_go_to_dest;

    TTextPanel *victory_condition_text,
               *victory_condition_type,
               *victory_amount_text,
               *victory_which_enemy_text;

    TEditPanel *victory_amount_input;

    TScrollBarPanel *victory_object_scrollbar;
    TEditPanel *message_input;
    TButtonPanel *message_button[5];
    TTextPanel *message_button_label[5];
    int current_message;
    TTextPanel *cinematic_label[4];
    TDropDownPanel *cinematic_input[4];
    TTextPanel *options_label[1];
    TButtonPanel *options_button[1];
    TDropDownPanel *options_player_list;
    TTextPanel *options_disable_tech_text;
    TButtonPanel *options_disable_button[16];
    TTextPanel *options_disable_text[16];
    TTextPanel *Diplomacy_opponent_label[8];
    TTextPanel *Diplomacy_player_text[8];
    TDropDownPanel *Diplomacy_player_list;
    TTextPanel *Diplomacy_status_label[4];
    TButtonPanel *Diplomacy_friend_box[8][3];
    TButtonPanel *Diplomacy_AlliedVictory[8];

    TRIBE_World *world;

    time_t update_interval;
    time_t last_update_time;
    time_t map_redraw_interval;
    time_t last_map_redraw_time;
    int changed_system_colors;
    unsigned int save_text_color;
    unsigned int save_window_color;

    TRIBE_Screen_Sed(char *scenario_name_in, int is_multi_player_in);

    ~TRIBE_Screen_Sed();

    void set_panel_info();
    void set_string(char *text, int text_id, int max_size);
    int create_button(TPanel *parent, TButtonPanel **button, int text_id, int ButtonSelectFlag);
    int create_button(TPanel *parent, TButtonPanel **button, char *text1, char *text2, char *text3, char *text4);
    int create_text(TPanel *parent, TTextPanel **text_panel, int text_id);
    int create_text(TPanel *parent, TTextPanel **text_panel, char *text);
    int create_input(TPanel *parent, TInputPanel **input_panel, char *value, short max_len, TInputPanel::FormatType format_type);
    int create_edit(TPanel *parent, TEditPanel **edit_panel, char *value, short max_len, TEditPanel::FormatType format_type, int enable_ime, int turn_ime_on);
    char *create_drop_down(TPanel *parent, TDropDownPanel **drop_panel);
    int SetupListOfTerrain(TListPanel *list);
    char *create_list(TPanel *parent, TListPanel **list_panel, TScrollBarPanel **scrollbar_panel);

    void set_scenario_mode(ScenarioMode new_mode);
    void set_paint_object_mode();
    void set_map_type(MapType new_val, int activate_panels);
    void set_mp_victory_type(VictoryType new_val, int activate_panels);
    void set_brush_size(BrushSize new_val);
    void set_paint_type(PaintType new_val, int activate_panels);
    void set_terrain(short val);
    void set_elevation(short val);
    void set_player(int val, char save_player, char load_player);
    void set_player_active(short player_num_in, int active_in);
    void set_unit_player(int val);
    void set_unit(short val);
    void set_message_type(MessageType new_val, int activate_panels);
    int handle_size(int win_wid, int win_hgt);
    int handle_idle();
    int key_down_action(int key, short count, int alt_key, int ctrl_key, int shift_key);
    int action(TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2);
    void draw();
    void command_cancel();
    int command_menu();
    void command_new();
    int command_new_map(char *scenario_name_in, int is_multi_player_in, int random_seed_in, int width, int height, int display_in);
    void command_open();
    void command_outline();
    void command_player(int id);
    void command_quit();
    void command_save(char kill_menu, char quit_after_save);
    void command_save_as(char quit_after_save);
    char *scenario_get_default_name();
    void command_quick_save();
    char *scenario_save_defaulted();
    char need_to_save();
    void set_focus(int have_focus_in);
    void SaveDisabledItemsInScenario();
    void LoadDisabledItemsFromScenario();
    void save_info_in_scenario();
    void save_multi_victory_cond_in_scenario();
    void save_victory_cond_in_scenario(int which);
    void load_victory_cond_from_scenario(int which);
    void load_multi_victory_cond_from_scenario();
    void save_diplomacy_in_scenario(int which);
    void load_diplomacy_from_scenario(int which);
    void activate_victory_proper_fields(int TypeOfVictory, int activate);
    void init_module_variables();
    void create_all_buttons_etc();
    void position_panels();
    void activate_victory_panel(int activate);
    int MakeFileList(TDropDownPanel *drop_down, char *dir, char *extension, char append_none, char append_random);
    int Set_player_advance_civilization_text(int newmode);
    void SavePlayerActiveStatus();
    int create_check_box(TPanel *parent, TButtonPanel **button);
    int create_radio_button(TPanel *parent, TButtonPanel **button);
};

int TRIBE_Screen_Sed_unit_list_compare(void *arg1, void *arg2);
