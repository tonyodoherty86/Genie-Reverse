
/**
 * @file    Engine\RGE\StaticObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/20
 * @version 1.0
 */

class RGE_Static_Object
{
public:

    int id;

    RGE_Master_Static_Object *master_obj;

    RGE_Player *owner;

    RGE_Sprite *sprite,
               *old_sprite;

    class RGE_Active_Sprite_List *sprite_list;

    RGE_Tile *tile;

    RGE_Static_Object *inside_obj;

    RGE_Object_List *objects;

    short screen_x_offset,
          screen_y_offset,
          shadow_x_offset,
          shadow_y_offset;

    float hp;
    char curr_damage_percent;
    char facet;
    char selected;
    char selected_group;

    float world_x,
          world_y,
          world_z;

    float attribute_amount_held;

    char object_state;

    char sleep_flag,
         dopple_flag,
         goto_sleep_flag;

    short attribute_type_held;

    char type;

    char worker_num;

    RGE_Object_Node *player_object_node;

    /* TODO: ManagedArray<int> */
    ManagedArray pathingGroupMembers,
                 groupMembers;

    UnitAIModule *unitAIValue;

    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    char inObstructionMapValue;
    char lastInObstructionMapValue;
    char underAttackValue;

    RGE_Master_Static_Object *get_command_master(RGE_Static_Object *a2, float a3, float a4, float a5);
    RGE_Static_Object *get_target_obj();
    double getAngle();
    double maximumSpeed();
    int passableTile(float a2, float a3, int a4);
    char facetToNextWaypoint();
    char waitingToMove();
    char actionState();
    int canPath(XYZPoint a2, float a3, int a4, float *a5, int a6, int a7, int a8);
    int canPath(int a2, float a3, float *a4, int a5, int a6, int a7);
    int canBidirectionPath(int a2, int a3, float a4, float *a5, int a6, int a7, int a8);
    int canPathWithObstructions(int a2, float a3, float *a4, int a5, int a6, int a7, ManagedArray/*<int>*/ *a8);
    int canPathWithAdditionalPassability(XYZPoint a2, float a3, int a4, float *a5, int a6, int a7, int a8, int a9, int a10);
    int findFirstTerrainAlongExceptionPath(int a2, float *a3, float *a4);
    int canLinePath(XYPoint *a2, XYPoint *a3, float a4, XYPoint *a5, int a6);
    int canLinePath(int a2, int a3, int a4, int a5, float a6, int a7);
    int firstTileAlongLine(XYPoint *a2, XYPoint *a3, XYPoint *a4, int a5, int a6, int a7);
    XYZBYTEPoint *userDefinedWaypoint(int a2);
    int addUserDefinedWaypoint(XYZBYTEPoint *a2, int a3);
    int numberUserDefinedWaypoints();
    Path *findAvoidancePath(XYZPoint *a2, float a3, int a4);

    char can_attack();
    int canRepair();
    int inAttackRange(RGE_Static_Object *a2);
    double calc_attack_modifier(RGE_Static_Object *a2);
    double rateOfFire();
    double damageCapability();
    double damageCapability(RGE_Static_Object *a2);
    double weaponRange();
    double minimumWeaponRange();
    int currentTargetID();
    double currentTargetX();
    double currentTargetY();
    double currentTargetZ();

    char keepGatheringWhenObjectIsOut(int a2);
    char produceWhenKilledBy(int a2);
    char useSameZoneDropsite();

    int attack(int a2, int a3);
    int attack(float a2, float a3, float a4, int a5);
    int moveTo(int a2, int a3);
    int moveTo(int a2, float a3, int a4);
    int moveTo(float a2, float a3, float a4, float a5, int a6);
    int moveAwayFrom(int a2, int a3);
    int hunt(int a2, int a3);
    int gather(int a2, int a3);
    int convert(int a2, int a3);
    int heal(int a2, int a3);
    int repair(int a2, int a3);
    int build(int a2, int a3);
    int trade(int a2, int a3);
    int explore(int a2, int a3, int a4);
    int enter(int a2, int a3);
    int unload(int a2, float a3, float a4, float a5);
    int transport(float a2, float a3, float a4, int a5);

    int stopAction();
    int pause();
};

struct RGE_Check_List
{
    struct RGE_Check_Node *list;
};

struct RGE_Check_Node
{
    RGE_Static_Object *node;
    float dx;
    float dy;
    char flag;
    RGE_Check_Node *next;
};
