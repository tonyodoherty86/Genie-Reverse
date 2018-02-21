
/**
 * @file    Engine\RGE\MasterPlayer.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Master_Player
{
public:

    char name[20];

    short master_object_num;
    class RGE_Master_Static_Object **master_objects;

    short attribute_num;
    float *attributes;

    char culture;
    char type;

    short tribe_effect;
    short bonus_effect;

    RGE_Master_Player(_iobuf *infile);
    RGE_Master_Player(int infile);

    ~RGE_Master_Player();

    void finish_init(int infile, RGE_Sprite **sprites, RGE_Sound **sounds);

    void load_master_object(int infile, char obj_type, RGE_Sprite **sprites, RGE_Sound **sounds, short index);

    void create_master_object_space(short count);

    void load_object(_iobuf *infile, char obj_type, RGE_Sprite **sprites, RGE_Sound **sounds, short index);

    void save(int outfile);
};
