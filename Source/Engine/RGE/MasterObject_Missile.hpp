#pragma once

/**
 * @file    Engine\RGE\MasterMissileObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

#include "MasterObject_Combat.hpp"

class RGE_Master_Missile_Object : public RGE_Master_Combat_Object
{
public:
    char missile_type;
    char targetting_type;
    char missile_hit_info;
    char missile_die_info;
    char area_effect_specials;

    float ballistics_ratio;

    RGE_Master_Missile_Object(RGE_Master_Missile_Object *other_object, int do_setup);
    RGE_Master_Missile_Object(int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup);
    RGE_Master_Missile_Object(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id, int do_setup);

    int setup(RGE_Master_Missile_Object *other_object);
    int setup(int infile, RGE_Sprite **sprites, RGE_Sound **sounds);
    int setup(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id);

    ~RGE_Master_Missile_Object();

    void make_new_obj(RGE_Player *owner, float x, float y, float z);
    void make_new_master();

    void copy_obj(RGE_Master_Static_Object *source);

    void modify(float amount, char flag);
    void modify_delta(float amount, char flag);
    void modify_percent(float amount, char flag);

    void save(int outfile);
};
