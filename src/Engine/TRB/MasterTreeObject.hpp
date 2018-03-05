
/**
 * @file    Engine\TRB\MasterTreeObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/27
 * @version 1.0
 */

class TRIBE_Master_Tree_Object : public RGE_Master_Static_Object
{
public:

    TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object *other_object, int do_setup);

    ~TRIBE_Master_Tree_Object();

    TRIBE_Master_Tree_Object(int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup);
    TRIBE_Master_Tree_Object(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, __int16 in_id, int do_setup);

    void make_new_obj(RGE_Player *owner, float x, float y, float z);
    void make_new_master();
};
