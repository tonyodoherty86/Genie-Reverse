
/**
 * @file    Engine\RGE\MasterActionObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Master_Action_Object : public RGE_Master_Moving_Object
{
public:

    class RGE_Task_List *tasks;
    short default_task;

    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    char task_by_group;

    RGE_Sound *command_sound;
    RGE_Sound *move_sound;

    char run_pattern;

    RGE_Master_Action_Object(RGE_Master_Action_Object *other_object, int do_setup);
    RGE_Master_Action_Object(int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup);
    RGE_Master_Action_Object(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id, int do_setup);

    int setup(RGE_Master_Action_Object *other_object);
    int setup(int infile, RGE_Sprite **sprites, RGE_Sound **sounds);
    int setup(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id);

    ~RGE_Master_Action_Object();

    void make_new_obj(RGE_Player *owner, float x, float y, float z);
    void make_new_master();

    class RGE_Task *get_task(short task_id);
    class RGE_Task *getTaskByTaskID(int t);

    void copy_obj(RGE_Master_Static_Object *source);

    void modify(float amount, char flag);
    void modify_delta(float amount, char flag);
    void modify_percent(float amount, char flag);

    void save(int outfile);

    void play_command_sound();
    void play_move_sound();
};
