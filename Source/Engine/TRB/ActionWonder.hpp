#pragma once

/**
 * @file    Engine\TRB\ActionWonder.hpp
 * @author  Yvan Burrie
 * @date    2018/06/28
 * @version 1.0
 */

#include <RGE/Action.hpp>

class TRIBE_Action_Wonder : public RGE_Action
{
public:

    /**
     * Offset: 64.
     */
    float wonder_time = 2000.0;

    /**
     * Offset: 68, 69.
     */
    char wonder_warnings[2] = { 0, 0 };

    /**
     * Offset: 70.
     */
    char wonderBonus = 0;

    TRIBE_Action_Wonder(
        int infile,
        RGE_Action_Object *obj_in);

    TRIBE_Action_Wonder(
        RGE_Action_Object *obj_in);

    ~TRIBE_Action_Wonder();

    void first_in_stack(
        char first_time);

    void set_state(
        char new_state);

    bool update();
};
