
/**
 * @file    Engine\RGE\TaskList.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Task_List
{
public:

    class RGE_Task **list;
    short list_num;

    RGE_Task_List();

    ~RGE_Task_List();

    void copy(RGE_Task_List *other_list);

    void load(int infile, RGE_Sprite **sprites, RGE_Sound **sounds);
    void load(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds);

    void save(int outfile);

    void delete_list();

    static void create_task(short task_type, short index);

    RGE_Task *get_target_task(RGE_Action_Object *obj, RGE_Static_Object *target_obj, float target_x, float target_y, float target_z);

    static bool is_attack_task(RGE_Task *task);

    static int check_task(RGE_Task *task, RGE_Action_Object *obj, RGE_Static_Object *target_obj);
};
