#pragma once

/**
 * @file    Engine\RGE\Action.hpp
 * @author  Yvan Burrie
 * @date    2018/06/30
 * @version 1.0
 */

class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Task;
class RGE_Sprite;
class RGE_Action_List;
class RGE_Master_Action_Object;

#ifndef RGE_ACTION_TYPE
    #define RGE_ACTION_TYPE 0
#endif

class RGE_Action
{
public:

    /**
     * Offset: 4.
     */
    short action_type = RGE_ACTION_TYPE;

    /**
     * Offset: 8.
     */
    RGE_Action_Object *obj;

    enum State
    {
        None         = 0,
        Done         = 1,
        Wait         = 2,
        Search       = 3,
        Goto         = 4,
        Goto2        = 5, /* follow */
        Work         = 6, /* fetch */
        Work2        = 7, /* deposit */
        Return       = 8,
        Turn         = 9,
        Delay        = 10,
        Move         = 11,
        Attack       = 12,
        Failed       = 13,
        Invalidated  = 14,
        MoveNoSearch = 15,
    };

    /**
     * Offset: 12.
     */
    char state = State::None;

    /**
     * Offset: 16.
     */
    RGE_Static_Object *target_obj;

    /**
     * Offset: 20.
     */
    RGE_Static_Object *target_obj2;

    /**
     * Offset: 24.
     */
    int targetID = -1;

    /**
     * Offset: 28.
     */
    int target2ID = -1;

    /**
     * Offset: 32, 36, 40.
     */
    float target_x = -1.0,
          target_y = -1.0,
          target_z = -1.0;

    /**
     * Offset: 44.
     */
    float timer = 0.0;

    /**
     * Offset: 48.
     */
    RGE_Task *task;

    /**
     * Offset: 52.
     */
    RGE_Action_List *sub_actions;

    /**
     * Offset: 56.
     */
    RGE_Sprite *sprite;

    /**
     * Offset: 60.
     */
    char sub_action_value;

    /**
     * Offset: 61.
     */
    bool target_moved;

    RGE_Action(
        int infile,
        RGE_Action_Object *obj_in,
        bool do_setup);

    RGE_Action(
        RGE_Action_Object *obj_in,
        bool do_setup);

    ~RGE_Action();

    bool setup(
        int infile,
        RGE_Action_Object *obj_in);

    bool setup(
        RGE_Action_Object *obj_in);

    void create_action_list(RGE_Action_Object *obj_in);

    void rehook();

    void save(
        int outfile);

    short type();

    int stop();
    int move_to(RGE_Static_Object *obj_in, float x, float y, float z);
    int work(RGE_Static_Object *obj_in, float x, float y, float z);
    char attack_response(RGE_Static_Object *obj_in);
    char relation_response(int player_id, char relation);

    void set_state(char new_state);

    bool inside_obj_update();
    bool idle_update();
    bool update();

    void set_target_obj(RGE_Static_Object *new_obj);
    void set_target_obj2(RGE_Static_Object *new_obj);

    void copy_obj(RGE_Master_Action_Object *source);

    void get_state_name(char *state_name);

    double targetX(),
           targetY(),
           targetZ();

    char subAction();
    void setSubAction(char v);

    RGE_Static_Object *get_target_obj();
    RGE_Static_Object *get_target_obj2();
};
