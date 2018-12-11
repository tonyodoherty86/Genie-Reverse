#pragma once

/**
 * @file    Engine\TRB\MasterCombatObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/27
 * @version 1.0
 */

#include <RGE/MasterObject_Combat.hpp>

struct Attribute_Cost
{
    short type;
    short amount;
    char flag;
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object
{
public:

    Attribute_Cost build_inventory[3];
    short build_pts_required;
    short id_of_building_obj;
    char button_location;
    short orig_pierce_armor;

    TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object *other_object, int do_setup);
    TRIBE_Master_Combat_Object(int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup);
    TRIBE_Master_Combat_Object(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id, int do_setup);

    int setup(TRIBE_Master_Combat_Object *other_object);
    int setup(int infile, RGE_Sprite **sprites, RGE_Sound **sounds);
    int setup(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id);

    ~TRIBE_Master_Combat_Object();

    RGE_Task_List *create_task_list();

    void copy_obj(RGE_Master_Static_Object *source);

    void modify(float amount, char flag);
    void modify_delta(float amount, char flag);
    void modify_percent(float amount, char flag);

    void save(int outfile);

    void make_new_obj(RGE_Player *owner, float x, float y, float z);
    void make_new_master();
};
