
/**
 * @file    Engine\TRB\World.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

class TRIBE_World : RGE_Game_World
{
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
