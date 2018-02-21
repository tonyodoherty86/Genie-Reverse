
/**
 * @file    Engine\RGE\DopplegangerObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Doppleganger_Object : public RGE_Animated_Object
{
public:

    RGE_Static_Object *doppled_object;
    RGE_Color_Table *draw_color;
    RGE_Master_Static_Object *doppled_master_obj;

    int doppled_player;

    unsigned int *MapAddress;
    unsigned int LastMapValue;
    unsigned int CantSeeBits;

    char map_draw_level;
    char map_color;

    int doppledObjectID;

    RGE_Doppleganger_Object(RGE_Master_Doppleganger_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup, RGE_Static_Object *obj_to_dopple);

    ~RGE_Doppleganger_Object();

    RGE_Doppleganger_Object(int infile, RGE_Game_World *gworld, int do_setup);

    void recycle_in_to_game(RGE_Master_Static_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, RGE_Static_Object *obj_to_dopple);

    int setup(RGE_Master_Doppleganger_Object *tobj, RGE_Player *obj_owner, float x, float y, float z);
    int setup(int infile, RGE_Game_World *gworld);

    void rehook();

    char update();

    void save(int outfile);

    void validate();
};
