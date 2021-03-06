#pragma once

class MouseClickInfo;

/**
 * @file    Engine\TRB\Game.hpp
 * @author  Yvan Burrie
 * @date    2018/08/09
 * @version 1.0
 */

/**
 * AOC off_636C50
 */

#include <RGE/Game.hpp>

class TRIBE_Game: public RGE_Base_Game
{
public:

    enum MapSize
    {
        Tiny      = 0x00,
        Small     = 0x01,
        Medium    = 0x02,
        Large     = 0x03,
        Huge      = 0x04,
        Humongous = 0x05,
    };

    enum MapType
    {
        AllWater     = 0x00,
        MostlyWater  = 0x01,
        WaterAndLand = 0x02,
        MostlyLand   = 0x03,
        AllLand      = 0x04,
        Continental  = 0x05,
        Lake         = 0x06,
        Hilly        = 0x07,
        Isthmas      = 0x08,
    };

    enum VictoryType
    {
        VictoryDefault     = 0x00,
        VictoryConquest    = 0x01,
        VictoryExplore     = 0x02,
        VictoryRuins       = 0x03,
        VictoryArtifacts   = 0x04,
        VictoryDiscoveries = 0x05,
        VictoryGold        = 0x06,
        VictoryTime        = 0x07,
        VictoryScore       = 0x08,
        VictoryStandard    = 0x09,
    };

    enum ResourceLevel
    {
        DefaultResources  = 0x00,
        LowResource       = 0x01,
        MediumResources   = 0x02,
        HighResources     = 0x03,
        VeryHighResources = 0x04,
    };

    enum Age
    {
        DefaultAge = 0x00,
        NomadAge   = 0x01,
        StoneAge   = 0x02,
        ToolAge    = 0x03,
        BronzeAge  = 0x04,
        IronAge    = 0x05,
    };

    MouseClickInfo *MouseRightClickTable;
    int MouseRightClickTableSize;
    MouseClickInfo *MouseLeftClickTable;
    int MouseLeftClickTableSize;

    int queue_is_waiting_on_pop_counter[RGE_PLAYERS_COUNT];

    int random_civ[RGE_PLAYERS_COUNT];

    struct TRIBE_Game_Options
    {
        MapSize mapSizeValue;
        MapType mapTypeValue;

        int animalsValue;
        int predatorsValue;
        VictoryType victoryTypeValue;
        int victoryAmountValue;

        char civilizationValue[RGE_PLAYERS_COUNT];
        int scenarioPlayerValue[RGE_PLAYERS_COUNT];
        char playerColorValue[RGE_PLAYERS_COUNT];
        char computerNameValue[RGE_PLAYERS_COUNT];

        char allowTradingValue;
        char longCombatValue;
        char randomizePositionsValue;
        char fullTechTreeValue;

        ResourceLevel resourceLevelValue;

        Age startingAgeValue;

        char startingUnitsValue;
        char deathMatchValue;
        char popLimitValue;
    }
    tribe_game_options;

    char testing_scenario[260];

    enum Type
    {
        RANDOM_MAP        = 0x00,
        REGICIDE          = 0x01,
        DEATH_MATCH       = 0x02,
        SCENARIO          = 0x03,
        CAMPAIGN          = 0x04,
        KING_OF_THE_HILL  = 0x05,
        WONDER_RACE       = 0x06,
        DEFEND_THE_WONDER = 0x07,
        TURBO_RANDOM_MAP  = 0x08,
    };

    /**
     * Offset: 5189.
     */
    Type type;

    HWND *video_window;
    int cur_video = -1;
    WNDPROC (*old_video_wnd_proc)();
    int video_paused;
    unsigned int last_video_time;
    int video_setup;
    int video_double_size;
    int video_changed_res;
    int video_hi_color;
    int video_save_res_wid;
    int video_save_res_hgt;
    void *video_save_palette;
    int started_menu_music;
    int show_object_id;

    class TRIBE_Screen_Game *game_screen;

    int notification_loc_x[5] = { -1, -1, -1, -1, -1 },
        notification_loc_y[5] = { -1, -1, -1, -1, -1 };

    int current_notification_loc      = -1,
        current_notification_recalled = -1;

    char startup_scenario[260];
    char startup_game[260];
    unsigned int auto_exit_time;
    char save_game_name[260];
    char load_game_name[260];
    char timing_text2[256];
    int save_humanity[RGE_PLAYERS_COUNT];
    char quick_start_game;
    int random_start_value;
    char computerNameUsed[18][10];
    void *handleIdleLock;
    int inHandleIdle;

    TRIBE_Game( RGE_Prog_Info *prog_info_in, bool do_setup = true );

    ~TRIBE_Game();

    bool close_game_screens( bool close_main_game_screen );

    bool setup();

    bool setup_cmd_options();

    bool setup_palette();

    TDigital **setup_sounds();
    static void create_world();
    void set_game_mode(int new_mode, int new_sub_mode);
    void set_player(short new_player_id);
    void set_save_game_name(char *file_name);
    void set_load_game_name(char *file_name);
    char *get_string(int string_id, char *str, int max_len);
    char *get_string2(int string_type, int id, int id2, char *str, int max_len);
    TPanel *get_view_panel();
    TPanel *get_map_panel();
    char *get_save_game_name();
    char *get_load_game_name();
    void new_scenario_header(int infile);
    void new_scenario_header(RGE_Scenario *scenario_info);
    void new_scenario_info(int infile);
    void show_error_message(int error_code_in);
    void show_status_message(char *messageIn, char *info_file, int info_id);
    void show_status_message(int string_id, char *info_file, int info_id);
    void close_status_message();
    int start_video(int video_num, char *video_file);

    void stop_video(char goto_next_video);
    void start_campaign_menu();
    void start_menu();
    void quit_game();
    void restart_game();
    int load_db_files();
    RGE_Game_World *load_game_data();
    int save_game(char *fileName);
    int save_scenario(char *fileName);
    void calc_timing_text();

    void show_timings();
    void show_comm();
    void show_ai();

    void notification(int notify_type, int val1, int val2, int val3, int val4);
    int start_game(int skip_startup_screens);
    int test_scenario(char *scenario_file);
    int start_scenario(char *scenario_file);
    int load_game(char *fileName);
    void do_game_over();
    char *create_game(int not_used);
    int create_game_screen();
    bool processCheatCode( int playerID, char *text );
    void let_game_begin();
    int start_scenario_editor(char *scenario_name_in, int is_multi_player_in);
    void send_game_options();
    void receive_game_options();
    void set_tribe_options(TRIBE_Game_Options *options);
    void get_tribe_options(TRIBE_Game_Options *options);
    MapSize mapSize(){ return this->tribe_game_options.mapSizeValue; };
    void setMapSize( MapSize v );
    MapType mapType(){ return this->tribe_game_options.mapTypeValue; };
    void setMapType( MapType v ){ this->tribe_game_options.mapTypeValue = v; };
    int animals(){ return this->tribe_game_options.animalsValue; };
    void setAnimals( int v ){ this->tribe_game_options.animalsValue = v; };
    int predators(){ return this->tribe_game_options.predatorsValue; };
    void setPredators( int v ){ this->tribe_game_options.predatorsValue = v; };
    VictoryType victoryType(){ return this->tribe_game_options.victoryTypeValue; };
    int victoryAmount(){ return this->tribe_game_options.victoryAmountValue; };
    void setVictoryType( VictoryType victory_type_in, int amount_in ){
        this->tribe_game_options.victoryTypeValue = victory_type_in;
        this->tribe_game_options.victoryAmountValue = amount_in; };
    int civilization( int player_num ){ return this->tribe_game_options.civilizationValue[player_num]; };
    void setCivilization( int player_num, int civilization ){ this->tribe_game_options.civilizationValue[player_num] = civilization; };
    int scenarioPlayer( int player_num ){ return this->tribe_game_options.scenarioPlayerValue[player_num]; };
    void setScenarioPlayer( int player_num, int scenario_player ){ this->tribe_game_options.scenarioPlayerValue[player_num] = scenario_player; };
    int playerColor( int player_num ){ return this->tribe_game_options.playerColorValue[player_num]; };
    void setPlayerColor( int player_num, int color ){ this->tribe_game_options.playerColorValue[player_num] = color; };
    int computerName( int player_num ){ return this->tribe_game_options.computerNameValue[player_num]; };
    void setComputerName( int player_num, int val ){ this->tribe_game_options.computerNameValue[player_num] = val; };
    int allowTrading(){ return this->tribe_game_options.allowTradingValue; };
    int longCombat(){ return this->tribe_game_options.longCombatValue; };
    int randomizePositions(){ return this->tribe_game_options.randomizePositionsValue; };
    int fullTechTree(){ return this->tribe_game_options.fullTechTreeValue; };
    ResourceLevel resourceLevel(){ return this->tribe_game_options.resourceLevelValue; };
    Age startingAge(){ return this->tribe_game_options.startingAgeValue; };
    int startingUnits(){ return this->tribe_game_options.startingUnitsValue; };
    char deathMatch(){ return this->tribe_game_options.deathMatchValue; };
    char popLimit(){ return RGE_Base_Game::multiplayerGame() ? this->tribe_game_options.popLimitValue : 50; };
    char quickStartGame(){ return this->quick_start_game; };
    int randomStartValue(){ return this->random_start_value; };
    void setAllowTrading( int val ){ this->tribe_game_options.allowTradingValue = val; };
    void setLongCombat( int val ){ this->tribe_game_options.longCombatValue = val; };
    void setRandomizePositions( int val ){ this->tribe_game_options.randomizePositionsValue = val; };
    void setFullTechTree( int val ){ this->tribe_game_options.fullTechTreeValue = val; };
    void setResourceLevel( ResourceLevel val ){ this->tribe_game_options.resourceLevelValue = val; };
    void setStartingAge( Age val ){ this->tribe_game_options.startingAgeValue = val; };
    void setStartingUnits( int val ){ this->tribe_game_options.startingUnitsValue = val; };
    void setDeathMatch( char val ){ this->tribe_game_options.deathMatchValue = val; };
    void setPopLimit( char val ){ this->tribe_game_options.popLimitValue = val; };
    void setQuickStartGame( char val ){ this->quick_start_game = val; };
    void setRandomStartValue( int val ){ this->random_start_value = val; };

    char *gameSummary();

    static RGE_Base_Game *hWnd_proc(HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_idle();
    int handle_query_new_palette(HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    int handle_activate(HWND *hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    bool action_user_command(unsigned int val1, unsigned int val2);
    bool action_key_down(unsigned int key, int repeat_count, int ctrl_key, int alt_key, int shift_key);
    bool action_close();
    char *game_over_msg();
    int get_achievement_info(char achievement, char **info);
    int randomComputerName(int civ);
    void resetRandomComputerName();
    int video_wnd_proc(HWND *hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    void SetClickTables(MouseClickInfo *RC, int RCS, MouseClickInfo *LC, int LCS);
    void set_interface_messages();
    int setup_video_system();
    void shutdown_video_system();
    void disconnect_multiplayer_game();
    void add_notification_loc(int x, int y);
    void goto_notification_loc();
};

int video_sub_wnd_proc(
    HWND *hWnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam);

/*
struct TRIBE_Game::receive_game_options::combined_options
{
    RGE_Base_Game::RGE_Game_Options rge_options;
    TRIBE_Game::TRIBE_Game_Options tribe_options;
};

struct TRIBE_Game::send_game_options::combined_options
{
    RGE_Base_Game::RGE_Game_Options rge_options;
    TRIBE_Game::TRIBE_Game_Options tribe_options;
};
*/
