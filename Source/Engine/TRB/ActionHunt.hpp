#pragma once

/**
 * @file    Engine\TRB\ActionHunt.hpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

#include <RGE/Action.hpp>

class TRIBE_Action_Hunt : public RGE_Action
{
public:

    int targetType;

    TRIBE_Action_Hunt(
        int infile,
        RGE_Action_Object *obj_in);

    TRIBE_Action_Hunt(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        RGE_Static_Object *target_obj_in);

    TRIBE_Action_Hunt(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        float x,
        float y,
        float z);

    ~TRIBE_Action_Hunt();

    void save(int outfile);

    void first_in_stack(char first_time);

    void set_state(char new_state);

    bool update();

    RGE_Sprite *get_move_sprite();
    RGE_Sprite *get_wait_sprite();

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
};
