
/**
 * @file    Engine\TRB\Command.hpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */

class TRIBE_Command : public RGE_Command
{
public:

    TRIBE_Command(TRIBE_World *world, TCommunications_Handler *com_hand);

    ~TRIBE_Command();

    void do_command(void *order);
    void do_command_tribe_create(struct RGE_Command_Create *order);
    void do_command_make(struct TRIBE_Command_Make *order);
    void do_command_research(struct TRIBE_Command_Research *order);
    void do_command_build(struct TRIBE_Command_Build *order);
#if ENGONE_ROR
    void do_command_build_wall(struct TRIBE_Command_Build_Wall *order);
    void place_line_of_walls(TRIBE_Player *player, TRIBE_Master_Building_Object *master_obj, int unique_id, int x1, int y1, int x2, int y2, RGE_Static_Object **first_wall);
#endif
    void do_command_explore(struct TRIBE_Command_Explore *order);
    void do_command_game(struct TRIBE_Command_Game *order);
#if ENGONE_ROR
    void do_command_cancel_build(struct TRIBE_Command_Cancel_Build *order);
    void do_command_attack_ground(struct TRIBE_Command_Attack_Ground *order);
    void do_command_give_attribute(struct TRIBE_Command_Give_Attribute *order);
    void do_command_trade_attribute(struct TRIBE_Command_Trade_Attribute *order);
    void do_command_repair(struct TRIBE_Command_Repair *order);
    void do_command_unload(struct TRIBE_Command_Unload *order);
    void do_command_queue(struct TRIBE_Command_Queue *order);
#endif
    void command_make(RGE_Static_Object *unit, short obj_id);
    void command_make(int playerID, int buildingID, int objID, int uniqueID);
    void command_research(RGE_Static_Object *unit, short tech_id);
    void command_research(int playerID, int buildingID, int techID, int uniqueID);
    void command_build(RGE_Static_Object **unit, short list_num, short obj_id, float location_x, float location_y);
    void command_build(int playerID, int *unitID, int numUnits, int objectID, float xLoc, float yLoc, int uniqueID);
#if ENGINE_ROR
    void command_build_wall(RGE_Static_Object **unit, short list_num, short obj_id, int x1, int y1, int x2, int y2);
#endif
    void command_explore(int playerID, int *unitID, int numUnits, float x, float y);
    void command_allied_victory(short player, char flag);
    void command_relation(short player, short target_player, short relation);
    void command_game_speed(float gamespeed);
#if ENGINE_ROR
    void command_save_game();
#endif
    void command_inventory(short player, short inventory, float amount);
    void command_upgrade_town(short player);
    void command_quick_build(short quick_build);
#if ENGINE_ROR
    void command_shared_los(short player);
    void command_cancel_build(RGE_Static_Object *unit);
    void command_attack_ground(RGE_Static_Object **unit, short list_num, float x, float y);
    void command_cheat(short player, short cheat_code);
    void command_give_attribute(int player_id, int to_player_id, int attr_id, float attr_amount, float attr_cost);
    void command_trade_attribute(RGE_Static_Object **unit, short list_num, int attribute);
    void command_trade_attribute(int unitID, int playerID, int attribute);
    void command_repair(RGE_Static_Object **unit, short unit_count, RGE_Static_Object *target);
    void command_unload(RGE_Static_Object **unit, short list_num, float x, float y);
    void command_queue(RGE_Static_Object *bldg_obj, short train_id, short train_count);
#endif
};

struct TRIBE_Command_Make
{
    char command;
    int unit_id;
    char unit_player_id;
    short obj_id;
    int unique_id;
};

struct TRIBE_Command_Research
{
    char command;
    int unit_id;
    char unit_player_id;
    short tech_id;
    int unique_id;
};

struct TRIBE_Command_Build
{
    char command;
    char unit_num;
    char unit_player_id;
    float location_x,
          location_y;
    short obj_id;
    int unique_id;
};

struct TRIBE_Command_Build_Wall
{
    char command;
    char unit_num;
    char unit_player_id;
    char x1,
         y1,
         x2,
         y2;
    short obj_id;
    int unique_id;
};

struct TRIBE_Command_Explore
{
    char command;
    char numUnits;
    char unit_player_id;
    float targetXPosition,
          targetYPosition;
};

struct TRIBE_Command_Game
{
    char command;
    char game_command;
    short var1;
    short var2;
    float var3;
    short var4;
};

struct TRIBE_Command_Cancel_Build
{
    char command;
    int unit_id;
};

struct TRIBE_Command_Attack_Ground
{
    char command;
    char unit_num;
    float location_x,
          location_y;
};

struct TRIBE_Command_Give_Attribute
{
    char command;
    char player_id;
    char to_player_id;
    char attr_id;
    float attr_amount;
    float attr_cost;
};

struct TRIBE_Command_Trade_Attribute
{
    char command;
    char unit_num;
    int attribute;
};

struct TRIBE_Command_Repair
{
    char command;
    char unit_num;
    RGE_Obj_Info target;
};

struct TRIBE_Command_Unload
{
    char command;
    char unit_num;
    float location_x,
          location_y;
};

struct TRIBE_Command_Queue
{
    char command;
    int bldg_id;
    short train_id,
          train_count;
};
