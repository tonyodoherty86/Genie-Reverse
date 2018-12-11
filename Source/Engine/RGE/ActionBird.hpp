#pragma once

#include "Action.hpp"

/**
 * @file    Engine\RGE\ActionBird.hpp
 * @author  Yvan Burrie
 * @date    2018/06/30
 * @version 1.0
 */

class RGE_Action_Bird : public RGE_Action
{
public:

    RGE_Action_Bird(
        int infile,
        RGE_Action_Object *obj_in);

    RGE_Action_Bird(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        float x,
        float y,
        float z);

    ~RGE_Action_Bird();

    void first_in_stack(
        char first_time);

    void set_state(
        char new_state);

    bool update();
};
