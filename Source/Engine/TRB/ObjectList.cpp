
/**
 * @file    Engine\TRB\ObjectList.cpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

RGE_Static_Object *TRIBE_Object_List::load(
    char object_type,
    int infile,
    RGE_Game_World *world)
{
    switch( object_type ){

    case TRIBE_COMBAT_OBJECT_TYPE:
        return new TRIBE_Combat_Object(
            infile,
            world,
            true);

    case TRIBE_BUILDING_OBJECT_TYPE:
        return new TRIBE_Building_Object(
            infile,
            world,
            true);

    default:
        return RGE_Object_List::load(
            object_type,
            infile,
            world);
    }
}
