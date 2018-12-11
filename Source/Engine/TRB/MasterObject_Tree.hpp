#pragma once

/**
 * @file    Engine\TRB\MasterObject_Tree.hpp
 * @author  Yvan Burrie
 * @date    2018/08/08
 * @version 1.0
 */

#include <RGE/MasterObject_Static.hpp>

class TRIBE_Master_Tree_Object : public RGE_Master_Static_Object
{
public:

    TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object *other_object, bool do_setup);

    ~TRIBE_Master_Tree_Object();

    TRIBE_Master_Tree_Object(int infile, RGE_Sprite **sprites, RGE_Sound **sounds, bool do_setup);

    void make_new_obj(RGE_Player *owner, float x, float y, float z);

    void make_new_master();
};
