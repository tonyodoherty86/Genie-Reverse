
/**
 * @file    Engine\RGE\MasterDoppleObject.hpp
 * @author  Yvan Burrie
 * @date    2018/07/04
 * @version 1.0
 */

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object
{
public:

    RGE_Master_Doppleganger_Object(
        RGE_Master_Doppleganger_Object *other_object,
        bool do_setup);

    RGE_Master_Doppleganger_Object(
        int infile,
        RGE_Sprite **sprites,
        RGE_Sound **sounds,
        bool do_setup);

    ~RGE_Master_Doppleganger_Object();

    bool setup(
        RGE_Master_Doppleganger_Object *other_object);

    bool setup(
        int infile,
        RGE_Sprite **sprites,
        RGE_Sound **sounds);

    void make_new_obj(
        RGE_Player *owner,
        float x,
        float y,
        float z,
        RGE_Static_Object *obj_to_dopple);

    void make_new_master();

    void copy_obj(
        RGE_Master_Static_Object *source);

    void save(
        int outfile);
};
