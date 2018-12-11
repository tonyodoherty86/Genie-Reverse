#pragma once

/**
 * @file    Engine\RGE\Scenario.hpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */


class RGE_Timeline;
class RGE_Game_World;
class RGE_Static_Object;
#define RGE_SCN_PROFILE_COUNT 16
#define RGE_SCN_TEXT_LENGTH 224

struct PlayerName
{
    char Name[256];
};

class RGE_Scenario
{
public:

    RGE_Timeline *time_line;

    RGE_Game_World *world;

    char victory_conquest;

    PlayerName player_name[RGE_SCN_PROFILE_COUNT];

    char *scenario_name;
    char *description;
    char *hints;
    char *win_message;
    char *loss_message;
    char *historicle_notes;

    char TempText1[RGE_SCN_TEXT_LENGTH];
    char TempText2[RGE_SCN_TEXT_LENGTH];
    char TempText3[RGE_SCN_TEXT_LENGTH];

    char *BuildList[RGE_SCN_PROFILE_COUNT];
    char *CityPlan[RGE_SCN_PROFILE_COUNT];
    char *AiRules[RGE_SCN_PROFILE_COUNT];

    char *BuildListFile[RGE_SCN_PROFILE_COUNT];
    char *CityPlanFile[RGE_SCN_PROFILE_COUNT];
    char *AiRulesFile[RGE_SCN_PROFILE_COUNT];

    int BuildListFileSize[RGE_SCN_PROFILE_COUNT];
    int CityPlanFileSize[RGE_SCN_PROFILE_COUNT];
    int AiRulesFileSize[RGE_SCN_PROFILE_COUNT];

    char Cine_PreGame[RGE_SCN_TEXT_LENGTH];
    char Cine_Victory[RGE_SCN_TEXT_LENGTH];
    char Cine_Loss[RGE_SCN_TEXT_LENGTH];
    char Mission_Bmp[RGE_SCN_TEXT_LENGTH];

    float Version;

    int PlayerPosture[RGE_SCN_PROFILE_COUNT];
    int PlType[RGE_SCN_PROFILE_COUNT];
    int PlCivilization[RGE_SCN_PROFILE_COUNT];
    int PlActive[RGE_SCN_PROFILE_COUNT];

    class TPicture *mission_picture;

    RGE_Scenario(RGE_Game_World *w);
    RGE_Scenario(int infile, RGE_Game_World *w);

    ~RGE_Scenario();

    void InitializeTextValues();

    void Set_scenario_name(char *str);
    void Set_description(char *str);
    void Set_Cine_PreGame(char *str);
    void Set_Cine_Victory(char *str);
    void Set_Cine_Loss(char *str);
    void Set_Mission_Bmp(char *str);
    void Set_BuildList(int which_player, char *str, int WithExtension);
    void Set_CityPlan(int which_player, char *str, int WithExtension);
    void Set_player_AI(int which_player, char *str, int WithExtension);
    void Set_Version(float ver);
    void Set_player_Type(int which, int t);
    void Set_player_Civ(int which, int c);
    void Set_player_Active(int which, int val);
    void SetPlayerName(int which, char *Name);

    char *Get_scenario_name();
    char *Get_description();
    char *Get_Cine_PreGame();
    char *Get_Cine_Victory();
    char *Get_Cine_Loss();
    char *Get_Mission_Bmp();
    char *Get_BuildList(int which_player, int WithExtension);
    char *Get_CityPlan(int which_player, int WithExtension);
    static double Get_Version();
    char *Get_player_AI(int which_player, int WithExtension);
    int GetPlayerPosture(int which);
    struct PlayerName *GetPlayerName(int which);
    int Get_player_Type(int which);
    int Get_player_Civ(int which);
    int Get_player_Active(int which);

    static RGE_Static_Object *get_object_pointer(int obj_ID);

    void update();

    void save(int outfile);

    int active_player_count();
    int any_player_count();
    int computer_player_count();

    void Set_conquest_victory(char flag);
    char Get_conquest_victory();

    void add_description(char *new_text);

    void Set_message(char *str, int message);
    char *Get_message(int message);
};

class RGE_Scenario_Header
{
public:

    int error_code;
    int version;
    unsigned int checksum;
    char *description;

    RGE_Scenario_Header(RGE_Scenario *scenario_info);
    RGE_Scenario_Header(int infile);

    ~RGE_Scenario_Header();

    unsigned int get_size();

    void save(int outfile);
};
