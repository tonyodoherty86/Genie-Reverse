
/**
 * @file    Engine\RGE\DopplegangerObject.hpp
 * @author  Yvan Burrie
 * @date    2018/07/02
 * @version 1.0
 */

#ifndef RGE_DOPPLEGANGER_OBJECT_TYPE
    #define RGE_DOPPLEGANGER_OBJECT_TYPE 25
#endif

class RGE_Doppleganger_Object : public RGE_Animated_Object
{
public:

    char type = RGE_DOPPLEGANGER_OBJECT_TYPE;

    RGE_Static_Object *doppled_object;

    RGE_Color_Table *draw_color;

    RGE_Master_Static_Object *doppled_master_obj;

    int doppled_player = 0;

    unsigned int *MapAddress;

    unsigned int LastMapValue = 0;
    unsigned int CantSeeBits = 0;

    char map_draw_level = 0;
    char map_color = 0;

    int doppledObjectID = -1;

    RGE_Doppleganger_Object(
        RGE_Master_Doppleganger_Object *tobj,
        RGE_Player *obj_owner,
        float x,
        float y,
        float z,
        bool do_setup,
        RGE_Static_Object *obj_to_dopple);

    RGE_Doppleganger_Object(
        int infile,
        RGE_Game_World *gworld,
        bool do_setup);

    ~RGE_Doppleganger_Object();

    void recycle_in_to_game(
        RGE_Master_Static_Object *tobj,
        RGE_Player *obj_owner,
        float x,
        float y,
        float z,
        RGE_Static_Object *obj_to_dopple);

    bool setup(
        RGE_Master_Doppleganger_Object *tobj,
        RGE_Player *obj_owner,
        float x,
        float y,
        float z);

    bool setup(
        int infile,
        RGE_Game_World *gworld);

    void rehook();

    bool update();

    void save(
        int outfile);

    void validate();
};
