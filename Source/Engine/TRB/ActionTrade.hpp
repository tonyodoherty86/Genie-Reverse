#pragma once

/**
 * @file    Engine\TRB\ActionTrade.hpp
 * @author  Yvan Burrie
 * @date    2018/06/27
 * @version 1.0
 */

#include <RGE/Action.hpp>

class TRIBE_Action_Trade : public RGE_Action
{
public:

    float pick_up_x,
          pick_up_y;

    TRIBE_Action_Trade(
        int infile,
        RGE_Action_Object *obj_in);

    TRIBE_Action_Trade(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        RGE_Static_Object *target_obj_in);

    TRIBE_Action_Trade(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        float x, float y, float z);

    ~TRIBE_Action_Trade();

    void save(int outfile);

    void first_in_stack(char first_time);

    void set_state(char new_state);

    bool update();

    RGE_Sprite *get_move_sprite();
    RGE_Sprite *get_wait_sprite();

    int stop();

    int move_to(
        RGE_Static_Object *obj_in,
        float x, float y, float z);

    int work(
        RGE_Static_Object *obj_in,
        float x, float y, float z);
};
