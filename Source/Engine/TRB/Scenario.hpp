#pragma once

/**
 * @file    Engine\TRB\Scenario.hpp
 * @author  Yvan Burrie
 * @date    2018/02/27
 * @version 1.0
 */

#include <RGE/Scenario.hpp>

class T_Scenario;
class RGE_Static_Object;
class RGE_Game_World;
class TRIBE_Player;

#define TRIBE_SCENARIO_SP_VICTORY_COUNT 12

struct Player_Start_Info
{
    int Gold;
    int Wood;
    int Food;
    int Stone;
};

struct Victory_StartInfo
{
    int MP_Conquest;
    int MP_Ruins;
    int MP_Artifacts;
    int MP_Discoveries;
    int MP_Exploration;
    int MP_Gold;
};

struct SP_Victory_Info
{
    int ObjType;
    int AllFlag;
    int PlayerID;
    int DestObjID;
    float x1;
    float y1;
    float x2;
    float y2;
    int VictoryType;
    int Amount;
    int AttribType;
    int obj_ID;
    int dest_obj_ID;
    RGE_Static_Object *obj;
    RGE_Static_Object *dest_obj;
};

struct Friendliness
{
    int Attitude[16];
};

class T_Scenario : public RGE_Scenario
{
public:

    Player_Start_Info player_info[RGE_SCN_PROFILE_COUNT];

    Victory_StartInfo victory;

    SP_Victory_Info sp_victory[RGE_SCN_PROFILE_COUNT][TRIBE_SCENARIO_SP_VICTORY_COUNT];

    Friendliness Opponent[RGE_SCN_PROFILE_COUNT];

    int AlliedVictory[RGE_SCN_PROFILE_COUNT];

    int victory_all_flag,
        is_multi_player_flag,
        which_player;

    int DisabledTechnology[RGE_SCN_PROFILE_COUNT][20];

    int ScenarioOptions[3];

    int PlayerAge[RGE_SCN_PROFILE_COUNT];

    int mp_victory_type,
        victory_score,
        victory_time;

    T_Scenario(RGE_Game_World *w);

    ~T_Scenario();

    T_Scenario(int infile, RGE_Game_World *w);

    void save(int outfile);

    void InitializePlayerValues();
    void ClearDisabledTechnologies();
    void InitializeAIInformation();

    void Set_victory_all_flag(int i);
    int Get_victory_all_flag();
    void SetMPVictory(int i);
    int GetMPVictory();
    void SetVictoryScore(int i);
    int GetVictoryScore();
    void SetVictoryTime(int i);
    int GetVictoryTime();
    void SetSPWhich(int i);
    int GetSPWhich();

    void InitializeVictoryValues();
    void ClearSPVictoryCondition(int which);
    void InitializeFriendlinessValues();

    void Set_player_attitude(int which, int opponent, int attitude);
    int Get_player_attitude(int which, int opponent);
    void Set_player_Gold(int which, int g);
    void Set_player_Wood(int which, int w);
    void Set_player_Food(int which, int f);
    void Set_player_Stone(int which, int s);
    void Set_player_Info(int which, Player_Start_Info *i);
    void Set_Multi_Conquest(int c);
    void Set_Multi_Ruins(int r);
    void Set_Multi_Artifacts(int a);
    void Set_Multi_Discoveries(int d);
    void Set_Multi_Exploration(int e);
    void Set_Multi_Gold(int g);
    void SetSPRectangle(int VicID, float x1, float y1, float x2, float y2);
    void SetSPObjectType(int VicID, int ObjType);
    void SetSPPlayerID(int VicID, int PlayerID);
    void SetSPAllFlag(int VicID, int AllFlag);
    void SetSPAttribType(int VicID, int AttribType);
    void SetSPVictoryType(int VicID, int VictoryType);
    void SetSPObject(int VicID, RGE_Static_Object *obj);
    void SetSPDestObjectID(int VicID, RGE_Static_Object *dest_obj);
    void SetSPAmount(int VicID, int Amount);
    void SetPlayerAlliedVictory(int which, int OnOff);
    void SetDisabledTechnology(int PlayerId, int which, int tf);
    void SetScenarioOption(int option, int value);
    void SetPlayerAge(int which, int val);
    int Get_player_Gold(int which);
    int Get_player_Wood(int which);
    int Get_player_Food(int which);
    int Get_player_Stone(int which);
    T_Scenario *Get_player_Info(int which);
    int Get_Multi_Conquest();
    int Get_Multi_Ruins();
    int Get_Multi_Artifacts();
    int Get_Multi_Discoveries();
    int Get_Multi_Exploration();
    int Get_Multi_Gold();
    void GetSPRectangle(int VicID, float *x1, float *y1, float *x2, float *y2);
    int GetSPObjectType(int VicID);
    int GetSPPlayerID(int VicID);
    int GetSPAllFlag(int VicID);
    int GetSPAttribType(int VicID);
    int GetSPAmount(int VicID);
    int GetSPVictoryType(int VicID);
    RGE_Static_Object *GetSPDestObjectID(int VicID);
    RGE_Static_Object *GetSPObject(int VicID);
    int GetPlayerAlliedVictory(int which);
    int GetDisabledTechnology(int PlayerId, int which);
    int GetScenarioOption(int option);
    int GetPlayerAge(int which);

    void update();

    void SaveAttributesIntoPlayers();
    void Save_victory_conditions_into_players(int SaveAttributes);

    RGE_Static_Object *get_object_pointer(int obj_ID);
    static int get_object_ID(RGE_Static_Object *obj);

    void WriteDisabledTechnologiesToMainSystem();

    int any_sp_victory();
    void set_player_tech(TRIBE_Player *player);
};

class TRIBE_Scenario_Header : public RGE_Scenario_Header
{
public:

    int any_sp_victory,
        active_player_count;

    TRIBE_Scenario_Header(T_Scenario *scenario_info);
    TRIBE_Scenario_Header(int infile);

    unsigned int get_size();

    void save(int outfile);
};
