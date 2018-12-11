#pragma once

#include <RGE/Action.hpp>

/**
 * @file    Engine\TRB\ActionArtifact.hpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

class RGE_Player;
class TRIBE_Action_Artifact : public RGE_Action
{
public:

    TRIBE_Action_Artifact(
        int infile,
        RGE_Action_Object *obj_in);

    TRIBE_Action_Artifact(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        RGE_Static_Object *target_obj_in);

    TRIBE_Action_Artifact(
        RGE_Action_Object *obj_in,
        RGE_Task *task_in,
        float x,
        float y,
        float z);

    ~TRIBE_Action_Artifact();

    void first_in_stack(char first_time);

    void set_state(char new_state);

    bool update();

    RGE_Player *check_ownership();

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

    void reset_owner();
};
