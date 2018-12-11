#pragma once

#include <RGE/Object_Static.hpp>

/**
 * @file    Engine\TRB\TreeObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */


class TRIBE_Master_Tree_Object;

class TRIBE_Tree_Object : public RGE_Static_Object
{
public:

    TRIBE_Tree_Object(TRIBE_Master_Tree_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup);

    ~TRIBE_Tree_Object();

    TRIBE_Tree_Object(int infile, RGE_Game_World *gworld, int do_setup);

    void set_object_state(char new_object_state);
};
