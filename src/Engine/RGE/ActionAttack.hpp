
/**
 * @file    Engine\RGE\ActionAttack.hpp
 * @author  Yvan Burrie
 * @date    2018/06/30
 * @version 1.0
 */

#ifndef RGE_ACTION_ATTACK_TYPE
    #define RGE_ACTION_ATTACK_TYPE 9
#endif

#define RGE_ACTION_ATTACK_COORDINATES_EXIST TRUE

class RGE_Action_Attack : public RGE_Action
{
public:

    short action_type = RGE_ACTION_ATTACK_TYPE;

    /**
     * Offset: 64, 68, 72.
     */
    RGE_Sprite *move_sprite,
               *fight_sprite,
               *wait_sprite;

    /**
     * Offset: 76, 80.
     */
    float range     = 0.0,
          min_range = 0.0;

    /**
     * Offset: 84.
     */
    short missile_id = -1;

    /**
     * Offset: 86.
     */
    short fire_missile_at_frame = 0;

    /**
     * Offset: 88.
     */
    bool need_to_attack = false;

    /**
     * Offset: 89.
     */
    bool was_same_owner = false;

    /**
     * Offset: 90.
     */
    char indirect_fire_flag = 0;

#if RGE_ACTION_ATTACK_COORDINATES_EXIST
    /**
     * Offset (AOC): 92, 96, 100.
     */
    float fight_x = -1.0,
          fight_y = -1.0,
          fight_z = -1.0;
#endif

    RGE_Action_Attack(
        int infile,
        RGE_Action_Object *obj_in);

    RGE_Action_Attack(
        RGE_Action_Object *obj_in,
        RGE_Static_Object *target_obj_in,
        RGE_Sprite *move_sprite_in,
        RGE_Sprite *fight_sprite_in,
        RGE_Sprite *wait_sprite_in,
        float range_in,
        float min_range_in,
        short missile_id_in,
        short fire_missile_at_frame_in);

    RGE_Action_Attack(
        RGE_Action_Object *obj_in,
        float x,
        float y,
        float z,
        RGE_Sprite *move_sprite_in,
        RGE_Sprite *fight_sprite_in,
        RGE_Sprite *wait_sprite_in,
        float range_in,
        float min_range_in,
        short missile_id_in,
        short fire_missile_at_frame_in);

    ~RGE_Action_Attack();

    void save(int outfile);

    void first_in_stack(char first_time);

    int stop();

    void set_state(char new_state);

    bool update();

    RGE_Static_Object *get_target_obj();
    RGE_Static_Object *get_target_obj2();

    int work(
        RGE_Static_Object *obj_in,
        float x,
        float y,
        float z);

    int ready_to_attack(
        int *rangeState);

    void do_attack();

    void copy_obj_sprites(
        RGE_Master_Action_Object *source,
        RGE_Task *task,
        RGE_Task *new_task);
};
