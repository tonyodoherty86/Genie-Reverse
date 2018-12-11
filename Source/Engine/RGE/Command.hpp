#pragma once

/**
 * @file    Engine\RGE\Command.hpp
 * @author  Yvan Burrie
 * @date    2018/03/09
 * @version 1.0
 */

#include "Path.hpp"

class RGE_Game_World;
class TCommunications_Handler;
class RGE_Static_Object;;

class RGE_Command
{
public:

    // 4
    RGE_Game_World *world;

    char *last_order;
    int last_order_size;
    int last_order_time;
#if ENGINE_AOK
    // 40
    short spawnIdsUsed;
    // 44
    int validCommandSent;
    // 48
    int commandedSpawnIds[40];
    // 208
    char lastTimeCommandedSpawnsCount[RGE_PLAYERS_COUNT];
    // 220
    int lastTimeCommandedSpawnIds[RGE_PLAYERS_COUNT][40];
    // 1660
#endif
    // 9664
    TCommunications_Handler *com_hand;

    RGE_Command(RGE_Game_World *gworld, TCommunications_Handler *com_handler);

    ~RGE_Command();

    void reset_communications(TCommunications_Handler *com_hand_in);

    RGE_Static_Object *get_obj(struct RGE_Obj_Info info);

    void do_commands();
    void do_command(void *order);
    void do_command_order(struct RGE_Command_Order *order);
    void do_command_stop(struct RGE_Command_Stop *order);
#if ENGINE_ROR
    void do_command_pause(struct RGE_Command_Pause *order);
#endif
    void do_command_work(struct RGE_Command_Order *order, int a4);
    void do_command_move(struct RGE_Command_Order *order);
    void do_command_create(struct RGE_Command_Create *order);
    void do_command_add_attribute(struct RGE_Command_Add_Attribute *order);
    void do_command_give_attribute(struct RGE_Command_Give_Attribute *order);
    void do_command_formation(struct RGE_Command_Formation *fCommand);
    void do_command_create_group(struct RGE_Command_Create_Group *gCommand);
    void do_command_ai_order(struct RGE_Command_AI_Order *aiOrder);
    void do_command_destroy_group(struct RGE_Command_Destroy_Group *gCommand);
#if ENGINE_ROR
    void do_command_group_ai_order(struct RGE_Command_Group_AI_Order *aiOrder);
    void do_command_resign(struct RGE_Command_Resign *order);
    void do_command_add_waypoint(struct RGE_Command_Add_Waypoint *wOrder);
    void do_command_group_waypoint(struct RGE_Command_Group_Waypoint *order);
    void do_command_add_to_group(struct RGE_Command_Add_To_Group *gCommand);
    void do_command_remove_from_group(struct RGE_Command_Remove_From_Group *gCommand);
#endif
    char duplicate_check_command_order(RGE_Command_Order *order);
    char duplicate_check_command_stop(RGE_Command_Stop *order);
    char close_check_for_duplicate_orders(char *order);
    char check_for_duplicate_orders(char *order, int order_size);

    void submit(void *order, int order_size);

    void command_order(RGE_Static_Object **unit, short unit_count, RGE_Static_Object *target, float location_x, float location_y);
    void command_stop(RGE_Static_Object **unit, short unit_count);
    void command_stop(int playerID, int *unitID, int numUnits);
#if ENGINE_ROR
    void command_pause(int playerID, int *unitID, int numUnits);
#endif
    void command_work(RGE_Static_Object **unit, short unit_count, RGE_Static_Object *target, float location_x, float location_y);
    void command_work(int playerID, int *unitID, int numUnits, int targetID, int targetPlayerID, float xLoc, float yLoc);
    void command_move(RGE_Static_Object **unit, short unit_count, RGE_Static_Object *target, float location_x, float location_y);
    void command_move(int playerID, int *unitID, int numUnits, int targetID, int targetPlayerID, float xLoc, float yLoc);
    void command_create(short obj_catagory, short player_id, float location_x, float location_y, float location_z);
    void command_add_attribute(int player_id, int attr_id, float attr_amount);
    void command_give_attribute(int player_id, int to_player_id, int attr_id, float attr_amount);
    void command_formation(RGE_Static_Object **unit, int unitCount, int formationID);
    void command_create_group(int playerID, int groupCommander, int *units, int unitCount, float range);
    void command_ai_order(int playerID, int issuer, int recipient, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, char immediate, char inFront, char priority);
    void command_destroy_group(int playerID, int groupCommander);
#if ENGINE_ROR
    void command_add_to_group(int playerID, int groupCommander, int newUnit, float range);
    void command_remove_from_group(int playerID, int commander, int unit);
    void command_group_ai_order(int playerID, int issuer, RGE_Static_Object **recipient, short recipient_count, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, char immediate, char inFront, char priority);
    void command_resign(int player_id, int comm_player_id, int dropped);
    void command_add_waypoint(int playerID, int recipient, XYZBYTEPoint *waypoint, int numWaypoints);
    void command_add_waypoint(int playerID, int recipient, char x, char y, char z);
    void command_group_waypoint(RGE_Static_Object **unit, short unit_count, char location_x, char location_y);
#endif
};

struct RGE_Obj_Info
{
    int id;
};

struct RGE_Command_Order
{
    char command;
    struct RGE_Obj_Info target;
    char unit_num;
    float location_x,
          location_y;
};

struct RGE_Command_Stop
{
    char command;
    char unit_num;
};

struct RGE_Command_Pause
{
    char command;
    char unit_num;
};

struct RGE_Command_Add_Attribute
{
    char command;
    char player_id;
    char attr_id;
    float attr_amount;
};

struct RGE_Command_Formation
{
    char command;
    int unitNum;
    int formationID;
};

struct RGE_Command_AI_Order
{
    char command;
    char player_id;
    char issuer;
    int recipient;
    short orderType;
    char orderPriority;
    int target;
    char targetOwner;
    float targetX,
          targetY,
          targetZ,
          range;
    char immediate;
    char inFront;
};

struct RGE_Command_Group_AI_Order
{
    char command;
    char player_id;
    char issuer;
    char recipient_count;
    short orderType;
    char orderPriority;
    int target;
    char targetOwner;
    float targetX,
          targetY,
          targetZ,
          range;
    char immediate;
    char inFront;
};

struct RGE_Command_Resign
{
    char command;
    char player_id;
    char comm_player_id;
    char dropped;
};

struct RGE_Command_Add_Waypoint
{
    char command;
    char player_id;
    int recipient;
    char numberWaypoints;
    XYZBYTEPoint waypoint[5];
};

struct RGE_Command_Group_Waypoint
{
    char command;
    char unit_num;
    char x,
         y;
};

struct RGE_Command_Create_Group
{
    char command;
    char player_id;
    int groupCommander;
    float groupRange;
    int unitsToGroup[25];
    char numberUnitsToGroup;
};

struct RGE_Command_Add_To_Group
{
    char command;
    char player_id;
    int groupCommander;
    float groupRange;
    int newUnit;
};

struct RGE_Command_Remove_From_Group
{
    char command;
    char player_id;
    int groupCommander;
    int unit;
};

struct RGE_Command_Destroy_Group
{
    char command;
    char player_id;
    int groupCommander;
};

struct RGE_Command_Give_Attribute
{
    char command;
    char player_id;
    char to_player_id;
    char attr_id;
    float attr_amount;
};

struct RGE_Command_Create
{
    char command;
    short obj_catagory;
    char player_id;
    float location_x,
          location_y,
          location_z;
};
