
/**
 * @file    Engine\TRB\TaskList.hpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */

class TRIBE_Task_List : public RGE_Task_List
{
public:

    RGE_Task *get_target_task(RGE_Action_Object *obj, RGE_Static_Object *target_obj, float target_x, float target_y, float target_z);

    static int is_attack_task(RGE_Task *task);
};
