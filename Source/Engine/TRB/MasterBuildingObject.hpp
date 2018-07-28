
/**
 * @file    Engine\TRB\MasterBuildingObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/27
 * @version 1.0
 */

class TRIBE_Master_Building_Object;

struct TRIBE_BuildingAnnexInfo
{
    short master_id;

    float displacement_x,
          displacement_y;
};

struct TRIBE_SalvageInfo
{
    short attribute_id;

    short amount;
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object
{
public:

    RGE_Sound *construction_sound;

    RGE_Sprite *construction_sprite,
               *frozen_sprite;

    char building_connect_flag;

    short building_facet;

    char build_and_go_away;

    short on_build_make_obj,
          on_build_make_tile,
          on_build_make_overlay,
          on_build_make_tech;

#if ENGINE_AOC
    char annex_mode;
    TRIBE_BuildingAnnexInfo annexes[6];
    short annex_primary_master_id;
    short annex_transform_master_id;
    RGE_Sound *annex_sound;

    char garrison_type;
    float garrison_healing;
    float garrison_multiplier;

    TRIBE_SalvageInfo salvage_tributes[6];
#endif

    TRIBE_Master_Building_Object(TRIBE_Master_Building_Object *other_object, int do_setup);
    TRIBE_Master_Building_Object(int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup);
    TRIBE_Master_Building_Object(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id, int do_setup);

    int setup(TRIBE_Master_Building_Object *other_object);
    int setup(int infile, RGE_Sprite **sprites, RGE_Sound **sounds);
    int setup(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id);

    ~TRIBE_Master_Building_Object();

    void copy_obj(RGE_Master_Static_Object *source);

    void modify(float amount, char flag);
    void modify_delta(float amount, char flag);
    void modify_percent(float amount, char flag);

    void save(int outfile);

    void make_new_obj(RGE_Player *owner, float x, float y, float z, int uID);
    void make_new_obj(RGE_Player *owner, float x, float y, float z);
    void make_new_master();

    void draw(TDrawArea *render_area, short x, short y, RGE_Color_Table *player_color, int facet, int frame, int draw_frame, char frame_color);

    char alignment(float *col, float *row, RGE_Game_World *world, char center_flag);
};
