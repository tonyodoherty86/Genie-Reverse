
/**
 * @file    Engine\RGE\ActionList.hpp
 * @author  Yvan Burrie
 * @date    2018/02/20
 * @version 1.0
 */

class RGE_Action_List
{
public:

    RGE_Action_Object *obj;
    struct RGE_Action_Node *list;

    RGE_Action_List(RGE_Action_Object *obj_in);

    ~RGE_Action_List();

    void load(int infile);

    void rehook();

    void save(int outfile);

    void delete_list();

    void create_action(int infile, short action_type);

    void create_task_action(RGE_Task *task, RGE_Static_Object *target_obj, float target_x, float target_y, float target_z);

    char inside_obj_update();

    char update();

    void add_action(RGE_Action *action);
    void add_action_at_end(RGE_Action *action);
    void add_action_at_end_of_action_queue(RGE_Action *action);
    void remove_action();
    bool have_action();

    int action_stop();
    int action_move_to(RGE_Static_Object *obj_in, float x, float y, float z);
    int action_work(RGE_Static_Object *obj_in, float x, float y, float z);
    int attack_response(RGE_Static_Object *attacker);
    int relation_response(int player_id, int relation);

    RGE_Action *get_action();
    RGE_Task *get_task();

    void copy_obj(RGE_Master_Action_Object *source);
    void copy_obj_sprites(RGE_Master_Action_Object *source, RGE_Task *task, RGE_Task *new_task);

    void get_action_name(char *action_name);
};

struct RGE_Action_Node
{
    RGE_Action *action;
    RGE_Action_Node *next;
};
