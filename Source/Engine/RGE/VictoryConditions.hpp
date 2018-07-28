
/**
 * @file    Engine\RGE\VictoryConditions.hpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

class RGE_Victory_Conditions
{
public:

    struct RGE_Victory_Entry *victory_list;
    int list_num;

    RGE_Player *player;

    char victory;

    struct RGE_Victory_Point_Entry *victory_point_list;
    int point_list_num;

    int tot_victory_points;

    RGE_Victory_Conditions(RGE_Player *in_player, int infile, int *player_id_hash, char version_control);
    RGE_Victory_Conditions(RGE_Player *in_Player);

    ~RGE_Victory_Conditions();

    void save(int outfile);

    void check_for_victory();

    char update();
    void update_for_object(RGE_Static_Object *obj);

    void handle_point_condition(RGE_Victory_Point_Entry *node);
    void handle_condition(RGE_Victory_Entry *node);
    void handle_capture(RGE_Victory_Entry *node);
    void handle_create(RGE_Victory_Entry *node);
    void handle_create_in_area(RGE_Victory_Entry *node);
    void handle_destroy(RGE_Victory_Entry *node);
    void handle_destroy_multiple(RGE_Victory_Entry *node);
    void handle_destroy_all(RGE_Victory_Entry *node);
    void handle_destroy_player(RGE_Victory_Entry *node);
    void handle_bring_area(RGE_Victory_Entry *node);
    void handle_bring_object(RGE_Victory_Entry *node);
    void handle_attribute(RGE_Victory_Entry *node);
    void handle_explore(RGE_Victory_Entry *node);
    void handle_victory_points(RGE_Victory_Entry *node);

    RGE_Victory_Entry *add(char v_group, char alliance);
    char add_capture(char v_group, RGE_Static_Object *obj, char alliance);
    char add_create(char v_group, int obj_type, int number, char alliance);
    char add_create(char v_group, int obj_type, int number, float x0, float y0, float x1, float y1, char alliance);
    char add_destroy(char v_group, RGE_Static_Object *obj);
    char add_destroy(char v_group, int obj_type, int num, RGE_Player *player);
    char add_destroy(char v_group, int obj_type, RGE_Player *player);
    char add_destroy(char v_group, RGE_Player *player);
    char add_bring(char v_group, RGE_Static_Object *obj, RGE_Static_Object *target);
    char add_bring(char v_group, RGE_Static_Object *obj, float x0, float y0, float x1, float y1);
    char add_attributes(char v_group, int attribute, int count, char alliance);
    char add_explore(char v_group, int count, char alliance);
    char add_victory_points(char v_group, int count, char alliance);

    void sub(RGE_Victory_Entry *entry);

    void destroy_all();

    char condition_info(int condition, char **description, char *type);
    static char *condition_description(RGE_Victory_Entry *node);
    RGE_Victory_Entry *condition_raw_info(int condition);
    int condition_number(int condition);

    bool victory_achieved();
    char remove_condition(int condition);

    RGE_Victory_Point_Entry *add_point(char id, char group);
    void sub_point(RGE_Victory_Point_Entry *entry);
    char add_points_attribute_amount(char group, char id, int attribute, int count, int points);
    char add_points_attribute_first(char group, char id, int attribute, int count, int points);
    char add_points_highest_attribute(char group, char id, int attribute, int count, int points);
    char add_points_high_attribute_once(char group, char id, int attribute, int count, int points);
    char add_points_high_attribute_amount(char group, char id, int attribute, int count, int points);

    void handle_points_attribute_amount(RGE_Victory_Point_Entry *node);
    void handle_points_attribute_first(RGE_Victory_Point_Entry *node);
    void handle_points_highest_attribute(RGE_Victory_Point_Entry *node);
    void handle_points_high_attribute_once(RGE_Victory_Point_Entry *node);
    void handle_points_high_attribute_amount(RGE_Victory_Point_Entry *node);

    int get_victory_points();
    int get_victory_points_group(char group);
    int get_victory_points_id(char id);
    int get_attribute_id(char id);
};

struct RGE_Victory_Entry
{
    char command;

    int obj_type;

    RGE_Player *target_player;

    float x0, y0, x1, y1;

    int number;

    int count;

    RGE_Static_Object *this_obj;

    RGE_Static_Object *target_obj;

    char victory_group;

    char ally_flag;

    char state;

    char checked_flag;

    RGE_Victory_Entry *next;
};

struct RGE_Victory_Point_Entry
{
    char command;

    char state;

    char id;

    char group;

    int attribute;

    int amount;

    int points;

    int curr_points;

    float curr_attribute_amount;

    RGE_Victory_Point_Entry *next;
};
