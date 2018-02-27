
/**
 * @file    Engine\RGE\BaseGame.hpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */

class RGE_Base_Game;

/**
 * This defines the hard-coded number of players.
 * Many people have been enthusiastic on having more than 9 players.
 * Modders claim it would be very difficult to do so because the number is hard-coded frequently throughout the build.
 * Finally, this definition will override the traditional 9 player limit!
 */
#define RGE_PLAYERS_COUNT 9

/**
 * This defines the hard-coded number of timings used by the game.
 */
#define RGE_GAME_TIMINGS_COUNTER 30

struct RGE_Timing_Info
{
    unsigned int accum_time;
    unsigned int last_time;
    unsigned int start_time;
    int include_in_total;
    int is_summary;
    unsigned int last_single_time;
    unsigned int max_time;
    unsigned int last_max_time;
};

class RGE_Base_Game
{
public:

    class RGE_Game_Info *player_game_info;
    class RGE_Scenario_File_Info *scenario_info;

    struct RGE_Prog_Info *prog_info;
    HWND *prog_window;
    int prog_ready;
    int prog_active;
    void *prog_palette;
    void *prog_mutex;
    int window_style;

    int random_game_seed      = -1,
        random_map_seed       = -1,
        save_random_game_seed = -1,
        save_random_map_seed  = -1;

    int screen_saver_enabled;
    int low_power_enabled;
    int error_code;
    int is_timer;

    TDrawSystem *draw_system;
    TDrawArea *draw_area;

    char outline_type;
    int custom_mouse;

    short shape_num;
    TShape **shapes;

    TSound_Driver *sound_system;
    TMusic_System *music_system;
    short sound_num;
    TDigital **sounds;
    char save_music_type;
    int save_music_track_from;
    int save_music_track_to;
    int save_music_cur_track;
    char save_music_file[260];
    int save_music_loop;
    unsigned int save_music_pos;

    int gap3[4];/* TODO */

    TCommunications_Handler *comm_handler;
    int comm_syncstop;
    int comm_droppackets;
    int comm_syncmsg;
    int comm_stepmode;
    int comm_speed;

    TDebuggingLog *debugLog;
    int log_comm;

    int gap2[1];/* TODO */

    TRegistry *registry;

    int prog_mode;
    int game_mode;
    int sub_game_mode;
    int paused;

    TMousePointer *mouse_pointer;
    int erase_mouse;
    int mouse_blit_sync;
    int is_mouse_on;
    int windows_mouse;
    void *mouse_cursor;

    int input_enabled;
    void *input_disabled_window;

    short font_num;
    struct RGE_Font *fonts;

    char work_dir[261];
    char string_dll_name[261];

    class RGE_Game_World *world;

    int render_all;

    short master_obj_id;
    short terrain_id;
    short elevation_height;

    short brush_size;

    char timing_text[256];

    unsigned int frame_count;
    unsigned int world_update_count;
    unsigned int view_update_count;
    unsigned int last_frame_count;
    unsigned int last_world_update_count;
    unsigned int last_view_update_count;
    unsigned int fps;
    unsigned int world_update_fps;
    unsigned int view_update_fps;

    RGE_Timing_Info timings[RGE_GAME_TIMINGS_COUNTER];
    int do_show_timings;
    int do_show_comm;
    int do_show_ai;

    unsigned int last_view_time;

    struct RGE_Game_Options
    {
        float versionValue;
        char scenarioGameValue;
        char scenarioNameValue[128];
        char singlePlayerGameValue;
        char multiplayerGameValue;
        char mapXSizeValue;
        char mapYSizeValue;
        char mapZSizeValue;
        char allowCheatCodesValue;
        char mpPathFindingValue;
        char cheatNotificationValue;
        char fullVisibilityValue;
        char fogOfWarValue;
        char coloredChatValue;
        char numberPlayersValue;
        char gameDeveloperModeValue;
        char playerCDAndVersionValue[RGE_PLAYERS_COUNT];
        char difficultyValue;
        char playerTeamValue[RGE_PLAYERS_COUNT];
    }
    rge_game_options;

    int campaignGameValue;
    int savedGameValue;

    int quick_build;

    int save_check_for_cd;

    int playerIDValue[RGE_PLAYERS_COUNT];
    int display_selected_ids;

    int countdown_timer[RGE_PLAYERS_COUNT];
    int auto_paused;
    int save_paused;
    int non_user_pause;
    int rollover;

    float game_speed = -1.0;

    int single_player_difficulty;

    char pathFindingValue;

    char resigned[RGE_PLAYERS_COUNT];

    TDrawArea *map_save_area;

    /* Contructor */
    RGE_Base_Game(RGE_Prog_Info *prog_info_in, int do_setup);

    int setup();

    void set_prog_mode(int new_mode);

    static TPanel *get_view_panel();
    static TPanel *get_map_panel();

    /* Destructor */
    ~RGE_Base_Game();

    static int processCheatCode(int __formal, char *a3);
    static int handle_message(MSG *msg);
    static int action_update();
    static int action_mouse_move(int x, int y, int left_btn, int right_btn, int ctrl_key, int shift_key);
    static int action_key_down(unsigned int key, int repeat_count, int ctrl_key, int alt_key, int shift_key);
    static int action_user_command(unsigned int val1, unsigned int val2);
    static int action_command(unsigned int val1, unsigned int val2);
    static int action_music_done();
    static int action_activate();
    static int action_deactivate();
    static int action_init_menu();
    static int action_exit_menu();
    static int action_size();
    static int action_close();

    void reset_timings();
    void add_to_timing(int id, unsigned int time);
    void increment_world_update_count();
    void increment_view_update_count();
    void set_last_single_time(int id, unsigned int time);

    unsigned int get_last_time(int id);
    unsigned int get_last_single_time(int id);
    unsigned int get_accum_time(int id);
    unsigned int get_max_time(int id);
    unsigned int get_last_max_time(int id);
    unsigned int get_last_world_update_count();
    unsigned int get_last_view_update_count();
    unsigned int get_world_update_count();
    unsigned int get_view_update_count();

    int get_error_code();

    static char *get_string(int text_id);/* TODO: check if this should static */
    char *get_string(int string_id, char *str, int max_len);
    char *get_string(int string_type, int id, char *str, int max_len);
    char *get_string2(int string_type, int id, int id2, char *str, int max_len);

    class RGE_Scenario *get_scenario_info(char *scenario_file, int from_campaign);
    class RGE_Scenario_Header *get_scenario_header(char *scenario_file, int from_campaign);
    void write_scenario_header(int outfile);
    void new_scenario_header(int infile);
    void new_scenario_header(RGE_Scenario *scenario_info);
    void new_scenario_info(int infile);
    void get_campaign_info(int *campaign, int *campaign_player, int *campaign_scenario);
    bool set_campaign_info(int campaign, int campaign_player, int campaign_scenario);

    void set_campaign_win();
    unsigned int run();
    int setup_cmd_options();
    int setup_class();
    HWND setup_main_window();
    void setup_graphics_system();
    int setup_palette();
    void setup_mouse();
    int setup_chat();
    int setup_registry();
    void setup_debugging_log();
    void setup_comm();
    int reset_comm();
    int setup_sound_system();
    int setup_music_system();
    TShape **setup_shapes();
    TDigital **setup_sounds();
    RGE_Font *setup_fonts();
    void setup_blank_screen();
    void setup_timings();
    void stop_sound_system();
    int restart_sound_system();
    void stop_music_system();
    int restart_music_system();
    void shutdown_music_system();
    void *make_font(void *dc, int string_id, int strike_out);
    void *make_font(void *dc, char *face_name, int point_size, int wgt, int strike_out);
    char check_for_cd(int num_players);
    bool check_expiration();
    int check_multi_copies();
    int check_paint();
    void clear_window();
    void create_world();
    void close();
    bool create_dialog(TPanel **dialog_ptr, TPanel *new_dialog);
    void delete_dialog(TPanel **dialog_ptr);
    void set_game_mode(int new_mode, int new_sub_mode);
    void set_player(__int16 new_player_id);
    int get_paused();
    RGE_Font *get_font(int font_id);
    TShape **get_shape(int shape_id);
    TDigital **get_sound(int sound_id);
    void request_pause();
    void set_paused(int paused_in, int non_user_pause_in);
    void get_mouse_info(WPARAM wParam, LPARAM lParam, POINT *point, int *left_btn, int *right_btn, int *ctrl_key, int *shift_key);
    void get_mouse_pos(POINT *point);
    RGE_Game_World *get_player();
    void draw_window();
    void mouse_on();
    void mouse_off();
    void set_windows_mouse(int val);
    void set_mouse_cursor(void *val);
    void set_mouse_facet(int facet);

    static RGE_Base_Game *wnd_proc(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);

    int handle_idle();
    int handle_mouse_move(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_key_down(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_user_command(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_command(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_music_done(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_paint(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_activate(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_init_menu(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_exit_menu(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    unsigned int handle_size(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_palette_changed(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_query_new_palette(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_close(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_destroy(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);

    void calc_timings();
    void calc_timing_text();
    void show_timings();
    void show_comm();
    void show_ai();

    void send_game_options();
    void receive_game_options();
    void set_game_options(RGE_Base_Game::RGE_Game_Options *options);
    void get_game_options(RGE_Base_Game::RGE_Game_Options *options);
    double version();
    int scenarioGame();
    int randomGame();
    int campaignGame();
    int savedGame();
    char *scenarioName();
    int singlePlayerGame();
    int multiplayerGame();
    int mapXSize();
    int mapYSize();
    int mapZSize();
    int allowCheatCodes();
    int cheatNotification();
    int fullVisibility();
    int fogOfWar();
    int coloredChat();
    int gameDeveloperMode();
    int playerHasCD(int player_num);
    unsigned int playerVersion(int player_num);
    char *playerVersionString(int player_num);
    char playerCDAndVersion(int player_num);
    int difficulty();
    int numberPlayers();
    int playerTeam(int player_num);

    char pathFinding();
    char mpPathFinding();

    static char *gameSummary();

    void find_campaigns();

    void setScenarioGame(int v);
    void setVersion(float val);
    void setScenarioName(char *n);
    void setCampaignGame(int v);
    void setSavedGame(int v);
    void setSinglePlayerGame(int v);
    void setMultiplayerGame(int v);
    void setMapSize(int x, int y, int z);
    void setAllowCheatCodes(int v);
    void setCheatNotification(int v);
    void setFullVisibility(int v);
    void setFogOfWar(int v);
    void setColoredChat(int v);
    void setNumberPlayers(int v);
    void setGameDeveloperMode(int v);
    void setPlayerHasCD(int player_num, int has_cd);
    void setPlayerVersion(int player_num, char player_version);
    void setPlayerCDAndVersion(int player_num, char val);
    void setDifficulty(int difficulty);
    void setPlayerTeam(int player_num, int team);
    void setPathFinding(char val);
    void setMpPathFinding(char val);
    void set_map_visible(char flag);
    void set_map_fog(char flag);

    void turn_world_sound_off();

    int campaign_open_scenario();

    int GetChecksum(int player);
    char GetWorldChecksums(int *new_checksum, int *new_position_checksum, int *new_action_checksum);
    int GetWorldChecksum();

    void disable_input();
    void enable_input();

    void set_screen_size(int wid, int hgt);

    bool check_prog_argument(char *argument);

    RGE_Scenario_Header *get_scenario_checksum(char *scenario_file);
    bool check_scenario_checksum(char *scenario, int checksum);

    void dump_memory_usage(char *file_name);

    int playerID(int player_index);
    void setPlayerID(int player_index, int player_id);

    void reset_countdown_timer(int in_countdown_player_id);
    void set_countdown_timer(int in_countdown_player_id, int in_countdown_timer);
    void get_countdown_timer(int out_countdown_player_id, int *out_countdown_timer);

    bool play_video(char *file_name);
    bool play_sound(int sound_id);
#if ENGINE_AOC
    bool play_sound(int sound_id, int sound_in, __int16 loop_count);
#endif // ENGINE_AOC
    double get_game_speed();
    void set_game_speed(float val);
    int get_single_player_difficulty();
    void set_single_player_difficulty(int val);
    void setup_map_save_area();
    void reload_scenarios_info();
    void set_render_all();
};

int rge_base_game_wnd_proc(HWND *wnd, UINT msg, WPARAM wParam, LPARAM lParam);

int enum_wnd_proc(HWND *hwnd, LPARAM lParam);
int enum_child_proc(HWND *hwnd, LPARAM lParam);
int enum_thread_proc(HWND *hwnd, LPARAM lParam);
int close_thread_windows(HWND *hwnd, LPARAM lParam);
int close_child_windows(HWND *hwnd, LPARAM lParam);

void debug_random_reset();
void debug_random_write();
int debug_rand(char *source_name, int source_line);
void debug_srand(char *source_name, int source_line, unsigned int seed);
unsigned int debug_timeGetTime();

struct RGE_Font
{
    void *font;
    int font_wid;
    int font_hgt;
};

struct RGE_Prog_Info
{
    char prog_name[101];
    char prog_version[21];
    char prog_title[121];
    char world_db_file[261];
    char game_data_file[261];
    char vol_name[261];
    unsigned int vol_ser_num;
    int verify_cd;
    int max_players_per_cd;

    HINSTANCE *instance,
              *prev_instance;

    char registry_key[256];
    char cmd_line[256];
    int show_wnd_flag;
    char icon_name[41];
    char menu_name[41];
    char pal_file[261];
    char cursor_file[261];

    int max_players;

    int check_expiration;
    short expire_month,
          expire_day,
          expire_year;

    unsigned int update_interval;

    int check_multi_copies;
    int skip_startup;
    int full_screen;
    int fixed_window_size;

    int use_dir_draw,
        use_sys_mem,
        use_music,
        use_sound,
        use_cd_audio,
        use_ima,
        use_midi,
        use_wave_music;

    int fast_view;
    int auto_scroll;
    int unk0;/* TODO */
    int mouse_scroll_edge;
    unsigned int mouse_scroll_interval;
    float mouse_scroll_max_dist;
    unsigned int key_scroll_interval;
    float key_scroll_max_dist,
         key_scroll_object_move;

    short interface_style;
    int unk1;/* TODO */
    int unk2;/* TODO */
    int unk3;/* TODO */
    int unk4;/* TODO */
    int main_wid;
    int unk5;/* TODO */
    int main_hgt;

    GUID game_guid,
         zone_guid;

    char data_dir[261],
         graphics_dir[261],
         save_dir[261],
         scenario_dir[261],
         campaign_dir[261],
         sounds_dir[261],
         resource_dir[261],
         ai_dir[261],
         avi_dir[261];
};
