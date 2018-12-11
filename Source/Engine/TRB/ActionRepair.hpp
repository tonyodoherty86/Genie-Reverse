#pragma once

/**
 * @file    Engine\TRB\ActionRepair.hpp
 * @author  Yvan Burrie
 * @date    2018/06/27
 * @version 1.0
 */

#include <RGE/Action.hpp>

class TRIBE_Action_Repair : public RGE_Action
{
public:

    char save_target_command_flag;

    TRIBE_Action_Repair(
        int infile,
        RGE_Action_Object *obj_in,
        int do_setup);

    TRIBE_Action_Repair(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        RGE_Static_Object *target_obj_in);

    TRIBE_Action_Repair(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        float x, float y, float z);

    ~TRIBE_Action_Repair();

    bool setup(
        int infile,
        RGE_Action_Object *obj_in);

    void save(int outfile);

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

    void meet_target();
};
