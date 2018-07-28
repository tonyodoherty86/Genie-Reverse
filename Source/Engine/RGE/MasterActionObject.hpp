
/**
 * @file    Engine\RGE\MasterActionObject.hpp
 * @author  Yvan Burrie
 * @date    2018/07/07
 * @version 1.0
 */

#ifndef RGE_MASTER_ACTION_OBJECT_TYPE
    #define RGE_MASTER_ACTION_OBJECT_TYPE 40
#endif

class RGE_Task;

class RGE_Master_Action_Object : public RGE_Master_Moving_Object
{
public:

    char master_type = RGE_MASTER_ACTION_OBJECT_TYPE;

    class RGE_Task_List *tasks;

    short default_task = -1;

    float search_radius = 0.0;

    float work_rate = 0.0;

    short drop_site;
    short backup_drop_site;
    char task_by_group;

    RGE_Sound *command_sound,
              *move_sound;

    char run_pattern;

    RGE_Master_Action_Object(
        RGE_Master_Action_Object *other_object,
        bool do_setup);

    RGE_Master_Action_Object(
        int infile,
        RGE_Sprite **sprites,
        RGE_Sound **sounds,
        bool do_setup);

    bool setup(
        RGE_Master_Action_Object *other_object);

    bool setup(
        int infile,
        RGE_Sprite **sprites,
        RGE_Sound **sounds);

    ~RGE_Master_Action_Object();

    void make_new_obj(
        RGE_Player *owner,
        float x,
        float y,
        float z);

    void make_new_master();

    RGE_Task *get_task(
        short task_id);

    RGE_Task *getTaskByTaskID(
        int t);

    void copy_obj(
        RGE_Master_Static_Object *source);

    enum ModifyFlag
    {

    };

    void modify(
        float amount,
        char flag);

    void modify_delta(
        float amount,
        char flag);

    void modify_percent(
        float amount,
        char flag);

    void save(
        int outfile);

    void play_command_sound(),
         play_move_sound();
};
