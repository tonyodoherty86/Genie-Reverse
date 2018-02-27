
/**
 * @file    Engine\TRB\World.hpp
 * @author  Yvan Burrie
 * @date    2018/02/27
 * @version 1.0
 */

class TRIBE_World;

struct TRIBE_Zone_High_Score_Info
{
    int score;
    char civ;
    char player_name[16];
    char num_allies;
};

struct TRIBE_Zone_Player_Info
{
    char name[16];
    int score;
    char winner;
    char civ_played;
    char civ_random;
    char player_no;
    char team_no;
    char game_outcome;
    int tool_time;
    int bronze_time;
    int iron_time;
};

struct TRIBE_Zone_Map_Info
{
    char Map_Size;
    char Map_Type;
    short Pop_Limit;
    char Victory_Condition;
    char Start_Age;
    char Resources;
    char Full_Tech;
    char Fixed_Pos;
    char Reveal_Map;
    char Death_Match;
};

struct TRIBE_Zone_Info
{
    char number_of_players;
    char number_of_computer_players;
    char scenario_name[32];
    unsigned int game_time;
    TRIBE_Zone_High_Score_Info total_score;
    TRIBE_Zone_High_Score_Info religion_score;
    TRIBE_Zone_High_Score_Info economy_score;
    TRIBE_Zone_High_Score_Info combat_score;
    TRIBE_Zone_High_Score_Info research_score;
    TRIBE_Zone_Player_Info player_info[8];
    TRIBE_Zone_Map_Info map_info;
    char cheats_enabled;
    char game_end_condition_code;
    unsigned int database_checksum;
    unsigned int code_checksum;
    unsigned int program_version;
};

class TRIBE_World : public RGE_Game_World
{
public:

    class TRIBE_Tech *tech;

    int victory_type;
    int artifact_count;
    int ruin_count;
    char countdown_victory;
    float countdown_clock;
    char score_displayed;
    char controllingComputerPlayer;
    int sent_zone_score;

    TRIBE_World();

    ~TRIBE_World();

    void data_load_players_type(short id, short type, _iobuf *infile);
    void data_load_map(char *border_file, char *overlay_file, char *terrain_file, char *map_file, short tile_width, short tile_height, short elev_height, RGE_Sound **sounds, char *terr_obj_file);
    char data_load_world(_iobuf *infile);
    char init_player_type(int infile, short index, char type);
    void map_init(int infile, TSound_Driver *sound_dvr);
    void command_init(int infile, TCommunications_Handler *com_hand);
    void scenario_init(int infile, RGE_Game_World *world);
    void scenario_init(RGE_Game_World *world);
    void effects_init(int infile);
    void world_init(int infile, TSound_Driver *sound_dvr, TCommunications_Handler *com_hand);
    char init(char *base_name, TSound_Driver *sound_dvr, TCommunications_Handler *com_hand);
    void base_save(int outfile);
    void save(int outfile);
    void load_player(int infile, char type, short index);
    void setup_gaia();
    void setup_players(RGE_Player_Info *info);
    void check_destructables(short player_id, short obj_id, float col, float row, char delete_flag);
    void scenario_make_player(short index, char player_type, char info_type, char master_player_id, char *name);
    char load_world(int infile1);
    char new_game(RGE_Player_Info *info, int myPlayerNum);
    char new_scenario(RGE_Player_Info *info, int random_seed_in);
    char check_game_state();
    int get_achievement(char achievement, char **info);
    void send_cheat(short cheat_code);
    void cheat(short player, short cheat_code);
    void fill_in_score(TRIBE_Zone_High_Score_Info *info, int score_group);
    void send_zone_score_info();
};
