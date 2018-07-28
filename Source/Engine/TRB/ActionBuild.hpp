
/**
 * @file    Engine\TRB\ActionBuild.hpp
 * @author  Yvan Burrie
 * @date    2018/06/27
 * @version 1.0
 */

class TRIBE_Action_Build : public RGE_Action
{
public:

    TRIBE_Action_Build(
        int infile,
        RGE_Action_Object *obj_in);

    TRIBE_Action_Build(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        RGE_Static_Object *target_obj_in);

    TRIBE_Action_Build(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        float x, float y, float z);

    ~TRIBE_Action_Build();

    void first_in_stack(char first_time);

    void set_state(char new_state);

    bool update();

    int stop();

    int move_to(
        RGE_Static_Object *obj_in,
        float x, float y, float z);

    int work(
        RGE_Static_Object *obj_in,
        float x, float y, float z);
};
