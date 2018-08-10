
/**
 * @file    Engine\RGE\Game.hpp
 * @author  Yvan Burrie
 * @date    2018/08/08
 * @version 1.0
 */

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

    HINSTANCE *instance, *prev_instance;

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

    /**
     * Offset: 2196.
     */
    int full_screen;

    /**
     * Offset: 2200.
     */
    int fixed_window_size;

    /**
     * Offset: 2204.
     */
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

    /**
     * Offset: 3396.
     */
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

/**
 * This defines the hard-coded number of timings used by the game.
 */
#define RGE_GAME_TIMINGS_COUNTER 30

struct RGE_Timing_Info
{
    time_t accum_time,
           last_time,
           start_time;

    int include_in_total;

    int is_summary;

    time_t last_single_time,
           max_time,
           last_max_time;
};

class RGE_Base_Game
{
public:

    RGE_Game_Info *player_game_info;

    RGE_Scenario_File_Info *scenario_info;

    /**
     * Offset: 40.
     */
    RGE_Prog_Info *prog_info;

    /**
     * Offset: 44.
     */
    HWND *prog_window;

    /**
     * Offset: 48, 52.
     */
    int prog_ready  = 0,
        prog_active = 1;

    void *prog_palette;
    void *prog_mutex;

    int window_style;

    int random_game_seed      = -1,
        random_map_seed       = -1,
        save_random_game_seed = -1,
        save_random_map_seed  = -1;

    int screen_saver_enabled = 0,
        low_power_enabled    = 0;

    enum ErrorCode
    {
        None               = 0,
        SetupFailed        = 1,

        RegistryFailed     = 14,
        DebugLogFailed     = 15,
    };

    int error_code = ErrorCode::None;

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
    int comm_speed = 1;

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
    int is_mouse_on = 1;
    int windows_mouse = 1;
    void *mouse_cursor;

    int input_enabled = 0;
    HWND *input_disabled_window;

    short font_num;
    struct RGE_Font *fonts;

    char work_dir[261];
    char string_dll_name[261];

    /**
     * Offset: 1060.
     */
    class RGE_Game_World *world;

    int render_all = 1;

    short master_obj_id    = -1,
          terrain_id       = -1,
          elevation_height = -1;

    short brush_size = 1;

    char timing_text[256];

    size_t frame_count             = 0,
           world_update_count      = 0,
           view_update_count       = 0,
           last_frame_count        = 0,
           last_world_update_count = 0,
           last_view_update_count  = 0;

    size_t fps              = 0,
           world_update_fps = 0,
           view_update_fps  = 0;

    RGE_Timing_Info timings[RGE_GAME_TIMINGS_COUNTER];

    int do_show_timings,
        do_show_comm,
        do_show_ai;

    time_t last_view_time;

    struct RGE_Game_Options
    {
        float versionValue;
        char scenarioGameValue;
        char scenarioNameValue[128];
        char singlePlayerGameValue;
        char multiplayerGameValue;

        char mapXSizeValue,
             mapYSizeValue,
             mapZSizeValue;

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

    int save_check_for_cd = 1;

    int playerIDValue[RGE_PLAYERS_COUNT];

    int display_selected_ids;

    int countdown_timer[RGE_PLAYERS_COUNT];

    int auto_paused;
    int save_paused;
    int non_user_pause;
    int rollover = 1;

    float game_speed = -1.0;

#if ENGINE_AOC
    #define RGE_GAME_SINGLE_PLAYER_DIFFICULTY 3
#else
    #define RGE_GAME_SINGLE_PLAYER_DIFFICULTY 2
#endif
    int single_player_difficulty = RGE_GAME_SINGLE_PLAYER_DIFFICULTY;

    char pathFindingValue;

    char resigned[RGE_PLAYERS_COUNT];

    TDrawArea *map_save_area;

    RGE_Base_Game( RGE_Prog_Info *prog_info_in, bool do_setup );

    bool setup();

    void set_prog_mode( int new_mode );

    static TPanel *get_view_panel();
    static TPanel *get_map_panel();

    ~RGE_Base_Game();

    virtual bool processCheatCode( int playerID, char *text ){ return false; };

    virtual bool handle_message( MSG *msg ){ return true; };

    virtual bool action_update(){ return true; };
    virtual bool action_mouse_move(
        int x,
        int y,
        int left_btn,
        int right_btn,
        int ctrl_key,
        int shift_key)
    {   return true; };
    virtual bool action_key_down(
        unsigned int key,
        int repeat_count,
        int ctrl_key,
        int alt_key,
        int shift_key)
    {   return true; };
    virtual bool action_user_command(
        unsigned int val1,
        unsigned int val2)
    {   return true; };
    virtual bool action_command(
        unsigned int val1,
        unsigned int val2)
    {   return true; };
    virtual bool action_music_done(){ return true; };
    virtual bool action_activate(){ return true; };
    virtual bool action_deactivate(){ return true; };
    virtual bool action_init_menu(){ return true; };
    virtual bool action_exit_menu(){ return true; };
    virtual bool action_size(){ return true; };
    virtual bool action_close(){ return true; };

    void reset_timings();
    void add_to_timing( int id, time_t time );
    void increment_world_update_count();
    void increment_view_update_count();
    void set_last_single_time( int id, time_t time );

    time_t get_last_time( int id );
    time_t get_last_single_time( int id );
    time_t get_accum_time( int id );
    time_t get_max_time( int id );
    time_t get_last_max_time( int id );
    time_t get_last_world_update_count();
    time_t get_last_view_update_count();
    time_t get_world_update_count();
    time_t get_view_update_count();

    int get_error_code();

    char *get_string( int text_id );
    char *get_string( int string_id, char *str, int max_len );
    char *get_string( int string_type, int id, char *str, int max_len );
    char *get_string2( int string_type, int id, int id2, char *str, int max_len );

    class RGE_Scenario *get_scenario_info( char *scenario_file, int from_campaign );
    class RGE_Scenario_Header *get_scenario_header( char *scenario_file, int from_campaign );

    void write_scenario_header( int outfile );
    void new_scenario_header( int infile );
    void new_scenario_header( RGE_Scenario *scenario_info );
    void new_scenario_info( int infile );
    void get_campaign_info( int *campaign, int *campaign_player, int *campaign_scenario );
    bool set_campaign_info( int campaign, int campaign_player, int campaign_scenario );
    void set_campaign_win();

    unsigned int run();

    bool setup_cmd_options();
    bool setup_class();
    HWND setup_main_window();
    bool setup_graphics_system();
    bool setup_palette();
    bool setup_mouse();
    bool setup_chat();
    bool setup_registry();
    bool setup_debugging_log();
    bool setup_comm();
    bool reset_comm();
    bool setup_sound_system();
    bool setup_music_system();
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
    void set_player(short new_player_id);
    int get_paused();
    RGE_Font *get_font(int font_id);
    TShape **get_shape(int shape_id);
    TDigital **get_sound(int sound_id);
    void request_pause();
    void set_paused(int paused_in, int non_user_pause_in);
    void get_mouse_info(
        WPARAM wParam,
        LPARAM lParam,
        POINT *point,
        int *left_btn,
        int *right_btn,
        int *ctrl_key,
        int *shift_key);
    void get_mouse_pos(POINT *point);
    RGE_Game_World *get_player();
    void draw_window();
    void mouse_on();
    void mouse_off();
    void set_windows_mouse(int val);
    void set_mouse_cursor(void *val);
    void set_mouse_facet(int facet);

    RGE_Base_Game *wnd_proc(      HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_idle();
    int handle_mouse_move(        HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_key_down(          HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_user_command(      HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_command(           HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_music_done(        HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_paint(             HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_activate(          HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_init_menu(         HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_exit_menu(         HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_size(              HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_palette_changed(   HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_query_new_palette( HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_close(             HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
    int handle_destroy(           HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam );

    void calc_timings();
    void calc_timing_text();
    void show_timings();
    void show_comm();
    void show_ai();

    void send_game_options();
    void receive_game_options();
    void set_game_options( RGE_Game_Options *options );
    void get_game_options( RGE_Game_Options *options );
    double version(){ return this->rge_game_options.versionValue; };
    int scenarioGame(){ return this->rge_game_options.scenarioGameValue; };
    bool randomGame(){ return this->rge_game_options.scenarioGameValue == 0; };
    int campaignGame(){ return this->campaignGameValue; };
    int savedGame(){ return this->savedGameValue; };
    char *scenarioName(){ return this->rge_game_options.scenarioNameValue; };
    int singlePlayerGame(){ return this->rge_game_options.singlePlayerGameValue; };
    int multiplayerGame(){ return this->rge_game_options.multiplayerGameValue; };
    int mapXSize(){ return this->rge_game_options.mapXSizeValue; };
    int mapYSize(){ return this->rge_game_options.mapYSizeValue; };
    int mapZSize(){ return this->rge_game_options.mapZSizeValue; };
    int allowCheatCodes(){ return this->rge_game_options.allowCheatCodesValue; };
    int cheatNotification(){ return this->rge_game_options.cheatNotificationValue; };
    int fullVisibility(){ return this->rge_game_options.fullVisibilityValue; };
    int fogOfWar(){ return this->rge_game_options.fogOfWarValue; };
    int coloredChat(){ return this->rge_game_options.coloredChatValue; };
    int gameDeveloperMode(){ return this->rge_game_options.gameDeveloperModeValue; };
    int playerHasCD( int player_num ){ return this->rge_game_options.playerCDAndVersionValue[player_num] & 1; };
    int playerVersion( int player_num ){ return this->rge_game_options.playerCDAndVersionValue[player_num] >> 1; };
    char *playerVersionString( int player_num );
    char playerCDAndVersion( int player_num ){ return this->rge_game_options.playerCDAndVersionValue[player_num]; };
    int difficulty(){ return this->rge_game_options.difficultyValue; };
    int numberPlayers(){ return this->rge_game_options.numberPlayersValue; };
    int playerTeam( int player_num ){ return this->rge_game_options.playerTeamValue[player_num]; };
    char pathFinding(){ return this->pathFindingValue; };
    char mpPathFinding(){ return this->rge_game_options.mpPathFindingValue; };

    static char *gameSummary();

    void find_campaigns(){ this->player_game_info->find_campaigns(); };

    void setScenarioGame( int v ){ this->rge_game_options.scenarioGameValue = v; };
    void setVersion( float val ){ this->rge_game_options.versionValue = val; };
    void setScenarioName( char *n );
    void setCampaignGame( int v ){ this->campaignGameValue = v; };
    void setSavedGame( int v ){ this->savedGameValue = v; };
    void setSinglePlayerGame( int v );
    void setMultiplayerGame( int v );
    void setMapSize( int x, int y, int z );
    void setAllowCheatCodes( int v ){ this->rge_game_options.allowCheatCodesValue = v; };
    void setCheatNotification( int v ){ this->rge_game_options.cheatNotificationValue = v; };
    void setFullVisibility( int v ){ this->rge_game_options.fullVisibilityValue = v; };
    void setFogOfWar( int v ){ this->rge_game_options.fogOfWarValue = v; };
    void setColoredChat( int v ){ this->rge_game_options.coloredChatValue = v; };
    void setNumberPlayers( int v );
    void setGameDeveloperMode( int v );
    void setPlayerHasCD( int player_num, int has_cd );
    void setPlayerVersion( int player_num, char player_version );
    void setPlayerCDAndVersion( int player_num, char val );
    void setDifficulty( int difficulty );
    void setPlayerTeam( int player_num, int team );
    void setPathFinding( char val );
    void setMpPathFinding( char val );
    void set_map_visible( char flag );
    void set_map_fog( char flag );
#if ENGINE_AOC
    void setGameSpeed( float v );
    void setMPGameSpeed( float v );
    void lockSpeedOff();
    void lockTeamsOff();
#endif

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

    virtual bool play_video( char *file_name ){ return false; };
    bool play_sound( int sound_id );
#if ENGINE_AOC
    bool play_sound( int sound_id, int sound_in, short loop_count );
#endif

    double get_game_speed(){ return this->game_speed; };
    void set_game_speed( float val ){ this->game_speed = val; };
    int get_single_player_difficulty(){ return this->single_player_difficulty; };
    void set_single_player_difficulty(int val){ this->single_player_difficulty = val; };

    void setup_map_save_area();
    void reload_scenarios_info();
    void set_render_all();
};

int rge_base_game_wnd_proc(
    HWND *hWnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam);

int enum_wnd_proc(
    HWND *hWnd,
    LPARAM lParam);

int enum_child_proc(
    HWND *hWnd,
    LPARAM lParam);

int enum_thread_proc(
    HWND *hWnd,
    LPARAM lParam);

int close_thread_windows(
    HWND *hWnd,
    LPARAM lParam);

int close_child_windows(
    HWND *hWnd,
    LPARAM lParam);

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
