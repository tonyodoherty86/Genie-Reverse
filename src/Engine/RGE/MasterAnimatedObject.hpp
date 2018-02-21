
/**
 * @file    Engine\RGE\MasterAnimatedObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Master_Animated_Object : public RGE_Master_Static_Object
{
public:

    float speed;

    RGE_Master_Animated_Object(RGE_Master_Animated_Object *other_object, int do_setup);
    RGE_Master_Animated_Object(int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup);
    RGE_Master_Animated_Object(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id, int do_setup);

    int setup(RGE_Master_Animated_Object *other_object);
    int setup(int infile, RGE_Sprite **sprites, RGE_Sound **sounds);
    int setup(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id);

    ~RGE_Master_Animated_Object();

    void make_new_obj(RGE_Player *owner, float x, float y, float z);
    void make_new_master();
    void copy_obj(RGE_Master_Static_Object *source);

    void modify(float amount, char flag);
    void modify_delta(float amount, char flag);
    void modify_percent(float amount, char flag);

    void save(int outfile);
};
