#pragma once

/**
 * @file    Engine\RGE\ActionExplore.hpp
 * @author  Yvan Burrie
 * @date    2018/06/30
 * @version 1.0
 */

#include "Action.hpp"

class RGE_Action_Explore : public RGE_Action
{
public:

    RGE_Action_Explore(
        int infile,
        RGE_Action_Object *obj_in);

    RGE_Action_Explore(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        float x,
        float y,
        float z);

    ~RGE_Action_Explore();

    void first_in_stack(
        char first_time);

    void set_state(
        char new_state);

    bool update();

    int work(
        RGE_Static_Object *obj_in,
        float x,
        float y,
        float z);
};
