
/**
 * @file    Engine\RGE\Player.hpp
 * @author  Yvan Burrie
 * @date    2018/02/27
 * @version 1.0
 */

class RGE_Player;

#define RGE_PLAYER_MASTER_CATEGORIES_COUNTER 900
#define RGE_PLAYER_MASTER_GROUPS_COUNTER 100
class RGE_Tile_List
{
public:

    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    struct RGE_Tile_List_Node *list;

    RGE_Tile_List(int Initial_Size);
    ~RGE_Tile_List();

    void add_node(int col, int row);
    void del_list();
    void get_list_info(RGE_Tile_List_Node **theList, int *list_size);
    int get_new_count();
};

struct RGE_Tile_List_Node
{
    int col;
    int row;
};

class RGE_Player
{
public:

    int computerPlayerValue;
    int pathingAttemptCapValue;
    int pathingDelayCapValue;
    int currentUpdatePathingAttemptsValue;

    int checksum;
    int position_checksum;
    int action_checksum;
    char checksum_created_this_update;

    int line_ratio;
    int column_ratio;
    int min_column_distance;
    int column_to_line_distance;
    int auto_formations;
    float formation_influence_distance;
    int break_auto_formations_by_speed;

    float pending_debits[4],
          escrow_amounts[4],
          escrow_percents[4];

    short master_object_num;
    class RGE_Master_Static_Object **master_objects;

    class RGE_Object_List *objects,
                          *sleeping_objects,
                          *doppleganger_objects;

    /* Offset: 132 */
    class RGE_Victory_Conditions *victory_conditions;

    /* Offset: 136 */
    class RGE_Visible_Map *visible;

    class RGE_Game_World *world;

    class RGE_Doppleganger_Creator *doppleganger_creator;

    void *unkown_structure;/* TODO */

    char *name;
    int id;
    char type;
    char culture;
    char game_status;
    char resigned;

    unsigned int attribute_num;
    float *attributes;

    RGE_Tile_List tile_list;
    int unk1;/* TODO */
    RGE_Tile_List diam_tile_list;
    int unk2;/* TODO */

    char *relations;
    int unitDiplomacy[RGE_PLAYERS_COUNT];
    int mutualAlly[RGE_PLAYERS_COUNT];

    unsigned int mutualExploredMask,
                 mutualVisibleMask,
                 nonMutualVisibleMask,
                 RemoveVisibleBits[RGE_PLAYERS_COUNT];

    int allied_LOS_Enable;
    char allied_victory;

    char master_player_id;

    int unk3;/* TODO */

    RGE_Color_Table *color_table;

    int tribe_effect;

    int unk4;/* TODO */

    class Visible_Resource_Manager *VR_List;

    float view_x,
          view_y;
    short map_x,
          map_y;
    struct XYFloatPoint *last_view;
    short last_view_num;

    short selected_start_col,
          selected_start_row,
          selected_end_col,
          selected_end_row;

    short replacement_terrain;

    float scroll_vector_x,
          scroll_vector_y,
          scroll_end_x,
          scroll_end_y,
          scroll_start_x,
          scroll_start_y,
          scroll_total_distance,
          scroll_distance;

    int gap1[4];/* TODO */

    class RGE_Static_Object *selected_obj;
    class RGE_Static_Object *sel_list[40];
    unsigned int sel_object_properties;
    int sel_count;
    char groups_used[127];

    short master_categories_count[RGE_PLAYER_MASTER_CATEGORIES_COUNTER],
          master_groups_count[RGE_PLAYER_MASTER_GROUPS_COUNTER],
          built_master_categories_count[RGE_PLAYER_MASTER_CATEGORIES_COUNTER],
          built_master_groups_count[RGE_PLAYER_MASTER_GROUPS_COUNTER];

    short total_units_count,
          total_buildings_ount,
          trained_units_count,
          built_buildings_count;

    int easiest_reaction_percent,
        easier_reaction_percent;

    char task_ungrouped_soldiers;

    RGE_Player(int infile, RGE_Game_World *gworld, char this_id);
    RGE_Player(RGE_Game_World *gworld, RGE_Master_Player *prototype, char this_id, char *new_name, char m_player_id, char flag);

    ~RGE_Player();

    int strategicNumber(int __formal);
    int sendAICommand(int __formal, int a3, int a4, int a5, int a6);
    int objectCostByType(int __formal);
    void set_game_status(char new_status);
    void do_resign(int dropped);
    char get_resigned();
    char *aiStatus(int sNum);
    int computerPlayer();

    int isEnemy(int playerNum);
    int isAlly(int playerNum);
    int isNeutral(int playerNum);
    int isAllNeutral();

    void sendUnitAIOrder(int issuer, int recipient, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, int immediate, int inFront, int priority);
    void processAIOrder(int issuer, int recipient, int orderType, int target, int targetOwner, float targetX, float targetY, float targetZ, float range, int immediate, int inFront, int priority);
    void sendGameOrder(RGE_Static_Object *unit, RGE_Static_Object *target, float targetX, float targetY);

    void sendAddWaypointCommand(int recipient, XYZBYTEPoint *waypoint, int numWaypoints);
    void processAddWaypointCommand(int recipient, XYZBYTEPoint *waypoint, int numWaypoints);
    void sendPlayCommand(int recipient, int target, int playID);
    void sendPlayCommand(int recipient, int *groupUnits, int groupCount, int target, int playID);

    int pathingAttemptCap();
    void setPathingAttemptCap(int v);
    int pathingDelayCap();
    void setPathingDelayCap(int v);
    int currentUpdatePathingAttempts();
    int availablePathingAttempts(int numWaitDelays);
    void incrementPathingAttempts();

    void sendChatMessage(int playerID, int copySelf, char *textIn, ...);

    RGE_Static_Object *make_scenario_obj(float world_x, float world_y, float world_z, short master_id, char state, float new_angle);
    void scenario_save(int outfile);
    void scenario_load(int infile, int *player_id_hash, float version);
    void scenario_postsave(int outfile);
    void scenario_postload(int infile, int *player_id_hash, float version);

    void load(int infile);
    void load_master_object(int infile, short index, char type, RGE_Sprite **sprites, RGE_Sound **sounds);
    void load_info(int infile);

    int get_checksum();
    char get_checksums(int *new_checksum, int *new_position_checksum, int *new_action_checksum);
    int create_checksum();

    void new_attribute_num(short attribute, float amount);
    void add_attribute_num(short attribute, float amount, char earned);

    void make_available(short obj_category, char on_off_flag);

    void update();
    void update_dopplegangers();

    void save(int outfile);
    void save2(int outfile);
    void save_info(int outfile);

    void set_map_loc(short x, short y);
    void set_view_loc(float x, float y);

    void destroy_objects();

    void set_color_table(char new_table);

    void victory_if_game_on();
    void loss_if_game_on();
    void win_game_now();

    bool check_victory_conditions();
    char check_ally_group(int *count);
    char check_victory();

    void modify_tobj(short obj_id, short group, float amount, int flag);
    void modify_tobj_delta(short obj_id, short group, float amount, int flag);
    void modify_tobj_percent(short obj_id, short group, float amount, int flag);

    void copy_obj(short dest, short source);

    void set_allied_victory(char flag);
    char get_allied_victory();

    char relation(int player_id);
    void set_relation(int player_id, int relation);

    RGE_Static_Object *make_new_object(int obj_id, float x, float y, float z, int build_all_the_way);

    void reset_selected();
    int select_object(RGE_Static_Object *obj);
    int select_one_object(RGE_Static_Object *obj, int play_sound);
    void unselect_object();
    void unselect_one_object(RGE_Static_Object *obj);
    void unselect_one_object(short index);
    int group_objects(int id);
    int select_group(int id);
    int own_selected();
    int is_category_selected(short object_category);
    int is_group_selected(short object_group);
    char unit_level_selected();
    int get_select_level();
    char get_selected_objects_to_command(RGE_Static_Object ***list_in, short *list_num_in, int min_select_level, short object_group, short object_id, short unit_level);
    void update_selected();
    void select_area(short col1, short row1, short col2, short row2);
    void unselect_area();
    void ungroup_objects();
    int get_mouse_pointer_action_vars(int Obj_id, int *newFacet, int *text_id);

    char command_make_move(RGE_Static_Object *obj, float x, float y);
    char command_make_work(RGE_Static_Object *obj, float x, float y);
    char command_make_do(RGE_Static_Object *obj, float x, float y);
    char command_stop();
    char command_place_object(short obj_id, float x, float y, float z);
    char command_add_attribute(int attr_id, float attr_amount);
    char command_give_attribute(int to_player_id, int attr_id, float attr_amount);
    char command_formation(int formationID);
    char command_stand_ground();
    char command_create_group(int commander, int *groupList, int groupLength, float range);
    char command_add_to_group(int commander, int unitID, float range);
    char command_remove_from_group(int commander, int unitID);
    char command_destroy_group(int unitID);
    char command_resign(int comm_player_id, int dropped);
    char command_add_waypoint(float x, float y, float z);

    struct RGE_Object_Node *addObject(RGE_Static_Object *obj, int sleep_flag, int dopple_flag);
    void removeObject(RGE_Static_Object *obj, int sleep_flag, int dopple_flag, RGE_Object_Node *node);

    void set_map_visible();
    void remake_visible_map();

    void load_victory(int infile, int *player_id_hash, char version_control);
    void new_victory();
};
