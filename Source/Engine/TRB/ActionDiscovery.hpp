
/**
 * @file    Engine\TRB\ActionDiscovery.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

class TRIBE_Action_Discovery_Artifact : public RGE_Action
{
public:

    char *flags;

    TRIBE_Action_Discovery_Artifact(
        int infile,
        RGE_Action_Object *obj_in);

    TRIBE_Action_Discovery_Artifact(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        RGE_Static_Object *target_obj_in);

    TRIBE_Action_Discovery_Artifact(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        float x,
        float y,
        float z);

    ~TRIBE_Action_Discovery_Artifact();

    void save(
        int outfile);

    void first_in_stack(
        char first_time);

    void set_state(
        char new_state);

    bool update();

    void check_objects();
};
