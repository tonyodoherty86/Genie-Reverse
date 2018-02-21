
/**
 * @file    Engine\RGE\ActionObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/20
 * @version 1.0
 */

class RGE_Action;

class RGE_Action_Object : public RGE_Moving_Object
{
public:

    char waiting;

    class RGE_Action_List *actions;

    char command_flag;

    int lastActionValue;
    int lastActionStateValue;

    RGE_Action_Object(int infile, RGE_Game_World *gworld, int do_setup);

    ~RGE_Action_Object();

    void recycle_out_of_game();

    int setup(RGE_Master_Action_Object *tobj, RGE_Player *obj_owner, float x, float y, float z);
    int setup(int infile, RGE_Game_World *gworld);

    void create_action_list();

    void rehook();

    void save(int outfile);

    void transform(RGE_Master_Static_Object *obj);
    void destroy_obj();
    void do_command(RGE_Static_Object *obj, float x, float y, float z);
    void move_to(RGE_Static_Object *obj, float x, float y, float z);
    void work(RGE_Static_Object *obj, float x, float y, float z);
    void work2(RGE_Static_Object *obj, float x, float y, float z, char work_flag);
    void play_command_sound();
    void play_move_sound();

    RGE_Master_Static_Object *get_command_master(RGE_Static_Object *obj, float x, float y, float z);

    void set_task(short task_id);
    void setTaskByTaskID(int t);
    void set_action(RGE_Action *action);
    void set_only_action(RGE_Action *action);
    void set_end_action(RGE_Action *action);

    void stop();

    char update();

    void change_ownership(RGE_Player *new_owner);

    void copy_obj(RGE_Master_Static_Object *source);

    bool have_action();

    RGE_Static_Object *get_target_obj();

    RGE_Task *getTask(RGE_Static_Object *target, float targetX, float targetY, float targetZ);

    char actionState();
    int get_action_checksum();

    RGE_Action_Object(RGE_Master_Action_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup);
};
