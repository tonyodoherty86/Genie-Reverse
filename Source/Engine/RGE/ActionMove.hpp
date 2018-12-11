#pragma once

/**
 * @file    Engine\RGE\ActionMove.hpp
 * @author  Yvan Burrie
 * @date    2018/06/27
 * @version 1.0
 */

#include "Action.hpp"

class RGE_Action_Move_To : public RGE_Action
{
public:

    float range;

    RGE_Action_Move_To(
        int infile,
        RGE_Action_Object *obj_in);

    RGE_Action_Move_To(
        RGE_Action_Object *obj_in,
        float x, float y, float z,
        float range_in,
        RGE_Sprite *sprite_in);

    RGE_Action_Move_To(
        RGE_Action_Object *obj_in,
        RGE_Static_Object *target_obj_in,
        float range_in,
        RGE_Sprite *sprite_in);

    ~RGE_Action_Move_To();

    void save(int outfile);

    void first_in_stack(char first_time);

    void set_state(char new_state);

    bool update();

    bool is_in_range();
};
