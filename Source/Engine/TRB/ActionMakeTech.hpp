#pragma once

/**
 * @file    Engine\TRB\ActionMakeTech.cpp
 * @author  Yvan Burrie
 * @date    2018/06/27
 * @version 1.0
 */

#include <RGE/Action.hpp>

class TRIBE_Action_Make_Tech : public RGE_Action
{
public:

    short tech_id;

    int unique_id;

    TRIBE_Action_Make_Tech(
        int infile,
        RGE_Action_Object *obj_in);

    TRIBE_Action_Make_Tech(
        RGE_Action_Object *obj_in,
        short id,
        int uID);

    ~TRIBE_Action_Make_Tech();


    void save(int outfile);

    void first_in_stack(char first_time);

    void set_state(char new_state);

    bool update();

    int stop();

    void get_info(
        short *id,
        short *progress,
        char *name,
        short name_size);
};
