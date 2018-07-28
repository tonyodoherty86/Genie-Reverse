
/**
 * @file    Engine\TRB\ActionConvert.hpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

class TRIBE_Action_Convert : public RGE_Action
{
public:

    TRIBE_Action_Convert(
        int infile,
        RGE_Action_Object *obj_in);

    TRIBE_Action_Convert(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        RGE_Static_Object *target_obj_in);

    TRIBE_Action_Convert(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        float x,
        float y,
        float z);

    ~TRIBE_Action_Convert();

    void save(int outfile);

    void first_in_stack(char first_time);

    void set_state(char new_state);

    bool update();

    int work(
        RGE_Static_Object *obj_in,
        float x,
        float y,
        float z);

    void martyrdom();
};
