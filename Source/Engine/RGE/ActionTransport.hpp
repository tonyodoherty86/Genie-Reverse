
/**
 * @file    Engine\RGE\ActionTransport.hpp
 * @author  Yvan Burrie
 * @date    2018/06/30
 * @version 1.0
 */

class RGE_Action_Transport : public RGE_Action
{
public:

    RGE_Action_Transport(
        int infile,
        RGE_Action_Object *obj_in);

    RGE_Action_Transport(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        float x,
        float y,
        float z);

    ~RGE_Action_Transport();

    void first_in_stack(
        char first_time);

    void set_state(
        char new_state);

    bool update();

    int stop();

    int move_to(
        RGE_Static_Object *obj_in,
        float x,
        float y,
        float z);

    int work(
        RGE_Static_Object *obj_in,
        float x,
        float y,
        float z);

    int next_to_drop_off_terrain();

    int targetZone();
};
