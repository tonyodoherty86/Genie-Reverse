
/**
 * @file    Engine\RGE\StaticObject.hpp
 * @author  Yvan Burrie
 * @date    2018/07/07
 * @version 1.0
 */

#ifndef RGE_STATIC_OBJECT_TYPE
    #define RGE_STATIC_OBJECT_TYPE 10
#endif

#ifndef RGE_STATIC_OBJECT_WORKER_NUM_LONG_CAST
    #define RGE_STATIC_OBJECT_WORKER_NUM_LONG_CAST FALSE
#endif

#ifndef RGE_STATIC_OBJECT_ACTIVE_SPRITES_FLAG_PARSED
    #define RGE_STATIC_OBJECT_ACTIVE_SPRITES_FLAG_PARSED FALSE
#endif

#ifndef RGE_STATIC_OBJECT_ALREADY_COLLIDED_EXISTS
    #define RGE_STATIC_OBJECT_ALREADY_COLLIDED_EXISTS FALSE
#endif

class RGE_Check_List;

class RGE_Static_Object
{
public:

    /**
     * The Identity of this Static-Object for its list.
     * Offset: 4.
     */
    int id = 0;

    /**
     * The Master-Object which this Object derived from.
     * Offset: 8.
     */
    RGE_Master_Static_Object *master_obj;

    /**
     * The Player which this Object belongs to.
     * Offset: 12.
     */
    RGE_Player *owner;

    /**
     * The idle or standing Sprite this Object will draw.
     * Offset: 16.
     */
    RGE_Sprite *sprite;

    /**
     * The backup Sprite this Object will draw.
     * Offset: 20.
     */
    RGE_Sprite *old_sprite;

    /**
     * Offset: 24.
     */
    class RGE_Active_Sprite_List *sprite_list;

    /**
     * Offset: 28.
     */
    RGE_Tile *tile;

    /**
     * Offset: 32.
     */
    RGE_Static_Object *inside_obj;

    /**
     * Offset: 36.
     */
    RGE_Object_List *objects;

    /**
     * The coordinates this Object is drawn on the screen.
     * Offset: 40, 42, 44, 46.
     */
    short screen_x_offset = 0,
          screen_y_offset = 0,
          shadow_x_offset = 0,
          shadow_y_offset = 0;

    /**
     * The Hit-Points this Object currently has.
     * Offset: 48.
     */
    float hp = 0.0;

    /**
     * The current percent of damage this Object should have.
     * Offset: 52.
     */
    char curr_damage_percent = 0;

    /**
     * The current Facet of this Object's Sprite.
     * Offset: 53.
     */
    char facet = -1;

    /**
     * Determines whether this Object is currently selected.
     * Offset: 54.
     */
    bool selected = false;

    /**
     * Determines the current Unit-Group this Object belongs to.
     * Offset: 55.
     */
    char selected_group;

    /**
     * The coordinates this Object is located on the map.
     * Offset for AOC07260809: 56, 60, 64.
     */
    float world_x = -1.0,
          world_y = -1.0,
          world_z = -1.0;

    /**
     * The current amount of whatever attribute.
     * Offset: 68.
     */
    float attribute_amount_held = 0.0;

    /**
     * Specifies whether the Object is existing, alive, dead, etc.
     */
    enum State
    {
        Ready   = 0,
        Founded = 1,
        Alive   = 2,
        Dying   = 3,
        Unk4    = 4,/* TODO */
        Unk5    = 5,/* TODO */
        Unk6    = 6,/* TODO */
        Unk7    = 7,/* TODO */
    };

    /**
     * Offset: 72.
     */
    char object_state = State::Ready;

    /**
     * Offset: 73.
     */
    bool sleep_flag;

    /**
     * Offset: 74.
     */
    bool dopple_flag;

    /**
     * Offset: 75.
     */
    char goto_sleep_flag;

    /**
     * Offset: 76.
     */
    short attribute_type_held;

    /**
     * Offset: 78.
     */
    char type = RGE_STATIC_OBJECT_TYPE;

    /**
     * Offset: 79.
     */
#if RGE_STATIC_OBJECT_WORKER_NUM_LONG_CAST
    int worker_num;
#else
    char worker_num;
#endif

#if RGE_STATIC_OBJECT_DAMAGE_PERCENT_EXISTS
    /**
     * Offset: 104.
     */
    char damage_timer;
#endif

    RGE_Object_Node *player_object_node;

    /* TODO: ManagedArray<int> */
    ManagedArray pathingGroupMembers,
                 groupMembers;

    UnitAIModule *unitAIValue;

    int groupCommanderValue = -1;

    int zoneMapIndex = -1;

    float groupRangeValue = 5.0;

    char inObstructionMapValue;

    char lastInObstructionMapValue;

    /**
     * Offset: 118.
     */
    bool underAttackValue;

    // int GroupId; // Offset (AOC): 120 ??????

    /**
     * Offset (AOC): 124.
     */
    bool alreadyCollided;

    RGE_Static_Object(
        RGE_Master_Static_Object *tobj,
        RGE_Player *obj_owner,
        float x,
        float y,
        float z,
        bool do_setup);

    RGE_Static_Object(
        int infile,
        RGE_Game_World *gworld,
        bool do_setup);

    ~RGE_Static_Object();

    void recycle_in_to_game(
        RGE_Master_Static_Object *tobj,
        RGE_Player *obj_owner,
        float x,
        float y,
        float z);

    void recycle_out_of_game();

    bool setup(
        RGE_Master_Static_Object *tobj,
        RGE_Player *obj_owner,
        float x,
        float y,
        float z);

    bool setup(
        int infile,
        RGE_Game_World *gworld);

    double getSpeed();

    void change_unique_id();

    RGE_Object_List *create_object_list();

    RGE_Active_Sprite_List *create_sprite_list();

    void get_starting_attribute();
    void give_attribute_to_owner();
    void take_attribute_from_owner();

    void draw(                      TDrawArea *render_area, short x, short y, RGE_Color_Table *draw_color);
    void shadow_draw(               TDrawArea *render_area, short x, short y, int flag);
    void normal_draw(               TDrawArea *render_area, int x, int y);
    void draw_front_frame(          TDrawArea *render_area, int x, int y);
    void draw_back_frame(           TDrawArea *render_area, short x, short y);
    void capture_frame(             TDrawArea *render_area, short x, short y);
    void capture_square_frame(      TDrawArea *render_area, short x, short y);
    void capture_frame_3d_cube(     TDrawArea *render_area, short x, short y);
    void capture_frame_3d_square(   TDrawArea *render_area, short x, short y);
    void draw_frame_3d_square_back( TDrawArea *render_area, short x, short y);
    void draw_frame_3d_square_front(TDrawArea *render_area, short x, short y);
    void draw_frame_3d_cube_back(   TDrawArea *render_area, short x, short y);
    void draw_frame_3d_cube_front(  TDrawArea *render_area, short x, short y);
    void draw_frame(                TDrawArea *render_area, short x, short y);

    bool update();

    void check_damage_sprites();
    RGE_Static_Object *spawn_death_obj();
    void rehook();
    RGE_Static_Object *get_object_pointer(int obj_id);
    RGE_Sprite *get_sprite_pointer(short sprite_id);

    void save(int outfile);

    double teleport(float x, float y, float z);

    void new_sprite(RGE_Sprite *nsprite);
    void add_overlay_sprite(RGE_Sprite *nsprite, char order);
    void remove_overlay_sprite(RGE_Sprite *nsprite);
    void change_ownership(RGE_Player *new_owner);

    void modify(        float amount, char flag);
    void modify_delta(  float amount, char flag);
    void modify_percent(float amount, char flag);

    void transform(RGE_Master_Static_Object *obj);
    void copy_obj(RGE_Master_Static_Object *source);
    void destroy_obj();
    void die_die_die();
    void remove_visible_resource();
    void create_doppleganger_when_dying();
    void set_object_state(char new_object_state);
    RGE_Static_Object *check_object_bounds();
    double get_terrain_speed(char terrain);
    char is_moving();
    bool is_dying();
    int get_frame(short *min_x, short *min_y, short *max_x, short *max_y);
    bool more_room();
    void enter_obj(RGE_Static_Object *target);
    void exit_obj();
    LOSTBL **get_los_table();
    int explore_terrain(RGE_Player *whos, char explore_type, int Override_LOS);
    void unexplore_terrain(RGE_Player *whos, char explore_type, int Override_LOS);
    void damage(int weapon_num, RGE_Armor_Weapon_Info *damage, float attack_modifier, RGE_Player *attacking_player, RGE_Static_Object *attackingObject);
    double calculateDamage(int weapon_num, RGE_Armor_Weapon_Info *damage, float attack_modifier, RGE_Player *attacking_player, RGE_Static_Object *attackingObject);
    void rotate(int amount);
    void set_attribute(short attr_type, float attr_amount);
    void set_attribute_amount(float attr_amount, char delta, char check_max);
    char heal(float healing);
    void set_being_worked_on(RGE_Action_Object *work_obj, short action_type, char attack_flag);
    void release_being_worked_on(RGE_Static_Object *caller);
    int inRange(RGE_Static_Object *obj, float range);
    long double distance_to_object(RGE_Static_Object *obj);
    long double distance_to_position(float x, float y, float z);
    char hit_test(int draw_x, int draw_y, short mouse_x, short mouse_y, int check_radius);
    char box_hit_test(int draw_x, int draw_y, short start_x, short start_y, short end_x, short end_y);
    void set_location(float x, float y, float z);
    char drop_held_objects(int dropZone);
    char find_drop_location(int dropZone, float *x, float *y, RGE_Master_Static_Object *m_obj, RGE_Static_Object *obj, float drop_x, float drop_y, float radius_x, float radius_y);
    RGE_Check_List *make_object_bounds_list(float delta);
    int boundToFacet(float tX, float tY, int numberBindingFacets);
    int numberFacets();
    char underAttack();
    void setUnderAttack(char v);
    int addToObstructionMap(int obMapCode);
    int removeFromObstructionMap(int obMapCode);
    void changeInfluenceMap(InfluenceMap *iMap, int increment, int usePercentCoverage, int useLOS);
    RGE_Check_List *objectCollisionList(float delta);
    void logDebug(char *textIn, ...);
    UnitAIModule *unitAI();
    char lookupZone(XYPoint p);
    char lookupZone(int x, int y);
    char currentZone();
    int withinRangeOfZoneAtPoint(char zone, float range, XYPoint *point);
    int withinRangeOfZone(char zone, float range);
    int findClosestPointInTerrainType(XYPoint p, XYPoint *rVal, int type1, int type2, int range);
    int isGroupCommander();
    bool inGroup();
    int unitIsInGroup(int uID);
    int createGroup(int *units, int count, int commander, float range);
    int commanderCreateGroup(int *units, int count, int commander, float range);
    int addToGroup(int unit, float range);
    RGE_Static_Object *commanderAddToGroup(int unit, float range);
    int removeFromGroup(int unit);
    int commanderRemoveFromGroup(int uID);
    int destroyGroup();
    int commanderDestroyGroup();
    void addToPathingGroup(int uID);
    void removeAllFromPathingGroup();
    void remove_shadows();
    void set_sleep_flag(char flag_in);
    int get_action_checksum();
    int get_waypoint_checksum();

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
    Path *findAvoidancePath(XYZPoint *avoid, float a3, int a4);

    virtual bool can_attack();
    virtual int canRepair();
    virtual int inAttackRange(RGE_Static_Object *obj);
    double calc_attack_modifier(RGE_Static_Object *obj);
    double rateOfFire();
    virtual double damageCapability();
    double damageCapability(RGE_Static_Object *obj);
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

class RGE_Check_List
{
public:

    RGE_Check_List();

    ~RGE_Check_List();

    void add_node(RGE_Static_Object *obj, float dx, float dy, char flag1);

    /**
     * Offset: 0.
     */
    struct RGE_Check_Node *list;
};

/**
 * Size: 20.
 * Align: 4.
 */
struct RGE_Check_Node
{
    /**
     * Offset: 0.
     */
    RGE_Static_Object *node;

    /**
     * Offset: 4, 8.
     */
    float dx, dy;

    /**
     * Offset: 12.
     */
    char flag;

    /**
     * Offset: 16.
     */
    RGE_Check_Node *next;
};
