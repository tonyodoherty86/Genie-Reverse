#pragma once

/**
 * @file    Engine\RGE\GameInfo.hpp
 * @author  Yvan Burrie
 * @date    2018/08/09
 * @version 1.0
 */

#include "IDA.h"

class RGE_Person_Info;
class RGE_Campaign;
class RGE_Campaign_Info;

class RGE_Game_Info
{
public:

    int current_person;
    int people_num;
    RGE_Person_Info **people_info;

    int campaign_num;
    RGE_Campaign **campaigns;

    char save_filename[260];

    RGE_Game_Info(char *filename);
    ~RGE_Game_Info();

    void save(char *filename);

    void find_campaigns();

    char add_new_person(char *name);
    char set_current_person(int num);
    char set_current_campaign(int num);
    char set_current_scenario(int num);
    int get_people_list(char ***list, int *current_player);
    int get_campaign_list(char ***list, int *current_campaign);
    int get_scenario_list(char ***list, int *current_scenario);
    int get_current_scenario();
    int get_current_campaign();
    int get_current_player();
    RGE_Person_Info *get_current_player_name();

    void notify_of_scenario_complete();

    int open_scenario();

    void remove_player(int id);
};

/*  */

class RGE_Person_Info
{
public:

    char name[255];

    int current_campaign;
    int campaign_info_num;
    RGE_Campaign_Info **campaign_info;

    int campaign_num;
    RGE_Campaign **campaigns;

    RGE_Person_Info(int infile, RGE_Campaign **in_campaigns, int in_campaign_num);
    RGE_Person_Info(char *in_name, RGE_Campaign **in_campaigns, int in_campaign_num);
    ~RGE_Person_Info();

    void save(int outfile);

    void rehook_campaigns(RGE_Campaign **in_campaigns, int in_campaign_num);

    RGE_Person_Info *get_name();
    char set_current_campaign(int num);
    int get_current_campaign();
    int get_current_scenario();
    char set_current_scenario(int num);
    int get_scenario_list(char ***list, int *current_scenario);

    void notify_of_scenario_complete();

    int open_scenario();
};

/* Below are components used for recording a user's Campaign progress. */

class RGE_Campaign_Info
{
public:

    char campaign_name[255];

    int current_scenario;
    int scenario_num;
    struct RGE_Scenario_Info *scenario_info;
    int last_scenario;

    RGE_Campaign *campaign;

    RGE_Campaign_Info(int infile, RGE_Campaign **campaigns, int campaign_num);
    RGE_Campaign_Info(RGE_Campaign *new_campaign);
    ~RGE_Campaign_Info();

    void save(int outfile);

    void rehook_campaigns(RGE_Campaign **campaigns, int campaign_num);

    char set_current_scenario(int num);
    bool verify_campaign_name(char *in_campaign_name);
    int get_scenario_list(char ***list, int *curr_scenario);
    int get_current_scenario();

    void notify_of_scenario_complete();

    int open_scenario();
};

struct RGE_Scenario_Info
{
    char scenario_status;
};

class RGE_Scenario_Header;

/* Below are components needed when selecting or retrieving a scenario. */

class RGE_Scenario_File_Info
{
public:

    char filename[260];
    int scenario_num;
    struct RGE_Scenario_File_Entry *scenarios;

    RGE_Scenario_File_Info(char *in_filename);

    ~RGE_Scenario_File_Info();

    void save();

    void reload_scenarios();

    char *get_scenario_name(int id);

    RGE_Scenario_Header *get_scenario_info(int id);
};

struct RGE_Scenario_File_Entry
{
    int time;
    RGE_Scenario_Header *scenario_header;
    char name[260];
};

/* Below are components needed for initializing a World. */

struct RGE_Player_Info
{
    char name[RGE_PLAYERS_COUNT][65];
    char type[RGE_PLAYERS_COUNT];
    char tribe[RGE_PLAYERS_COUNT];
    short color[RGE_PLAYERS_COUNT];
    int player_id_hash[RGE_PLAYERS_COUNT];
    short player_num;
    char *scenario;
    struct RGE_Map_Gen_Info *map_info;
    short map_type;
    short map_width;
    short map_height;
    short ai_info;
    char campaign;
};

struct RGE_Info_Line
{
    float clump_num;
    short percent_of_tiles_covered;
    short percent_updown;
    short min_elevation;
    short max_elevation;
    short terrain_type;
    short terrain_base;
    char obj_id;
};

struct RGE_Map_Gen_Info
{
    short base_terrain;
    RGE_Info_Line land;
    RGE_Info_Line elevation[20];
    short elevation_num;
    RGE_Info_Line terrain[20];
    short terrain_num;
    RGE_Info_Line objects[20];
    short objects_num;
    short player_num;
    short player_x[RGE_PLAYERS_COUNT];
    short player_y[RGE_PLAYERS_COUNT];
    short player_connect[RGE_PLAYERS_COUNT];
    short player_base_land[RGE_PLAYERS_COUNT];
    short space_between_islands_or_edge;
};
