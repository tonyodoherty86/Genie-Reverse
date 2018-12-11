#pragma once

/**
 * @file    Engine\RGE\ActionMissile.hpp
 * @author  Yvan Burrie
 * @date    2018/06/30
 * @version 1.0
 */

#include "Action.hpp"

class RGE_Action_Missile : public RGE_Action
{
public:

    RGE_Action_Missile(
        int infile,
        RGE_Action_Object *obj_in);

    RGE_Action_Missile(
        RGE_Action_Object *obj_in,
        RGE_Static_Object *launcher,
        RGE_Static_Object *target,
        float x,
        float y,
        float z);

    ~RGE_Action_Missile();

    void first_in_stack(
        char first_time);

    void intercept(
        float *tx,
        float *ty,
        float *tz);

    void set_state(
        char new_state);

    bool update();

    void save(
        int outfile);
};
