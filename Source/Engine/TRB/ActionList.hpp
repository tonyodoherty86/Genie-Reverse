#pragma once
#include <RGE/ActionList.hpp>
#include <cstdint>


/**
 * @file    Engine\TRB\ActionList.hpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */

class TRIBE_Action_List : public RGE_Action_List
{
public:

    TRIBE_Action_List(RGE_Action_Object *obj_in);

    void create_action(int infile, int16_t action_type);
    void create_task_action(RGE_Task *task, RGE_Static_Object *target_obj, float target_x, float target_y, float target_z);

    void get_action_name(char *action_name);
};
