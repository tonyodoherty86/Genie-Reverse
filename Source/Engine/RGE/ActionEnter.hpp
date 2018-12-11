#pragma once

/**
 * @file    Engine\RGE\ActionEnter.hpp
 * @author  Yvan Burrie
 * @date    2018/06/30
 * @version 1.0
 */

#include "Action.hpp"

class RGE_Action_Enter : public RGE_Action
{
public:

    RGE_Action_Enter(
        int infile,
        RGE_Action_Object *obj_in);

    RGE_Action_Enter(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        RGE_Static_Object *target_obj_in);

    ~RGE_Action_Enter();

    void first_in_stack(
        char first_time);

    void set_state(
        char new_state);

    bool update();
};
