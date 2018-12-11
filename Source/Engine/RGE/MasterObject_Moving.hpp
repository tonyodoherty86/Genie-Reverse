#pragma once

/**
 * @file    Engine\RGE\MasterMovingObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

#include "MasterObject_Animated.hpp"

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object
{
public:

    RGE_Sprite *move_sprite;
    RGE_Sprite *run_sprite;

    float turn_speed;

    char size_class;

    short obj_trail_id;
    char obj_trail_options;
    float obj_trail_spacing;

    char move_algorithem;

    RGE_Master_Moving_Object(RGE_Master_Moving_Object *other_object, int do_setup);
    RGE_Master_Moving_Object(int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup);
    RGE_Master_Moving_Object(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id, int do_setup);

    int setup(RGE_Master_Moving_Object *other_object);
    int setup(int infile, RGE_Sprite **sprites, RGE_Sound **sounds);
    int setup(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id);

    ~RGE_Master_Moving_Object();

    void make_new_obj(RGE_Player *owner, float x, float y, float z);
    void make_new_master();

    void copy_obj(RGE_Master_Static_Object *source);

    void modify(float amount, char flag);
    void modify_delta(float amount, char flag);
    void modify_percent(float amount, char flag);

    void save(int outfile);
};
