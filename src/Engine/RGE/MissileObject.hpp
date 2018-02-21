
/**
 * @file    Engine\RGE\MissileObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/20
 * @version 1.0
 */

class RGE_Missile_Object : public RGE_Combat_Object
{
public:

    float max_range;

    RGE_Missile_Object(RGE_Master_Combat_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup);

    ~RGE_Missile_Object();

    RGE_Missile_Object(int infile, RGE_Game_World *gworld, int do_setup);

    int setup(RGE_Master_Combat_Object *tobj, RGE_Player *obj_owner, float x, float y, float z);
    int setup(int infile, RGE_Game_World *gworld);

    void save(int outfile);

    void init_missile(RGE_Combat_Object *launcher, RGE_Static_Object *target, float in_range);
    void init_missile(RGE_Combat_Object *launcher, float x, float y, float z, float in_range);

    bool missile_move();

    RGE_Check_List *make_object_collision_list(float delta);
};
