
/**
 * @file    Engine\TRB\BuildingObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */

class TRIBE_Building_Object : public TRIBE_Combat_Object
{
public:

    struct Production_Queue_Record *production_queue;
    short production_queue_size;
    short production_queue_count;
    char production_queue_enabled;
    RGE_Action_List *production_queue_actions;
    char production_queue_change_flag;
    char production_queue_auto_paused;
    short production_queue_need_attr;

    float build_pts;

    int unique_build_id;

    char culture;

    char built;

    int DoppleInstalled;

    unsigned int PriorMap1,
                 PriorMap2,
                 PriorMap3;

    int PriorTurn1,
        PriorTurn2,
        PriorTurn3;

    TRIBE_Building_Object(TRIBE_Master_Building_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int uID, int do_setup);
    TRIBE_Building_Object(TRIBE_Master_Building_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup);
    TRIBE_Building_Object(int infile, RGE_Game_World *gworld, int do_setup);

    ~TRIBE_Building_Object();

    void recycle_out_of_game();

    int setup(TRIBE_Master_Building_Object *tobj, RGE_Player *obj_owner, float x, float y, float z);
    int setup(int infile, RGE_Game_World *gworld);

    void take_building_attribute_from_owner();
    void give_building_attribute_to_owner();

    void destroy_obj();

    char heal(float healing);

    void set_object_state(char new_object_state);

    void rehook();

    char update();

    int explore_terrain(RGE_Player *whos, char explore_type, int Override_LOS);

    void save(int outfile);

    void change_ownership(RGE_Player *new_owner);

    void modify(float amount, char flag);

    void transform(TRIBE_Master_Building_Object *obj);
    int check(TRIBE_Building_Object **checks);

    void connect();
    void connect2();

    void lay_down_impassable_terrain();
    void lay_down_passable_terrain();

    void cancel_object();
    void cancel_build();
    char build(float build_amount);

    int work_status(short *work_type, short *work_target, short *progress, char *name, short name_size);
    short get_construction_progress();

    void copy_obj(RGE_Master_Static_Object *source);

    void damage(int weapon_num, RGE_Armor_Weapon_Info *damage, float attack_modifier, RGE_Player *attacking_player, RGE_Static_Object *attacking_object);

    void add_to_production_queue(short master_id, short unit_count);
    void remove_from_production_queue(short master_id, short unit_count);
    void advance_production_queue();
    void empty_production_queue();
    void enable_production_queue(int enabled);
    void update_production_queue();
    int production_queue_status(short *master_id, short *progress);

    void stop();
};

struct Production_Queue_Record
{
    short master_id;
    short unit_count;
};
