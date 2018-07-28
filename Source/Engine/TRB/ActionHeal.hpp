
/**
 * @file    Engine\TRB\ActionHeal.hpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

class TRIBE_Action_Heal : public RGE_Action
{
public:

    TRIBE_Action_Heal(
        int infile,
        RGE_Action_Object *obj_in);

    TRIBE_Action_Heal(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        RGE_Static_Object *target_obj_in);

    TRIBE_Action_Heal(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        float x,
        float y,
        float z);

    ~TRIBE_Action_Heal();

    void first_in_stack(char first_time);

    void set_state(char new_state);

    bool update();

    int work(
        RGE_Static_Object *obj_in,
        float x,
        float y,
        float z);
};
