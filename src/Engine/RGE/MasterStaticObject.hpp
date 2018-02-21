
/**
 * @file    Engine\RGE\MasterStaticObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Master_Static_Object
{
public:

    char master_type;

    char *name;

    short string_id;
    short string_id2;

    short id;
    short copy_id;

    short object_group;

    RGE_Sprite *sprite;
    RGE_Sprite *death_sprite;
    RGE_Sprite *undead_sprite;
    char undead_flag;

    short hp;
    float los;
    char obj_max;

    float radius_x;
    float radius_y;
    float radius_z;

    RGE_Sound *selected_sound;
    RGE_Sound *created_sound;
    RGE_Sound *death_sound;
    short death_spawn_obj_id;

    char sort_number;
    char can_be_built_on;
    short button_pict;
    char hide_in_scenario_editor;
    short portrait_pict;
    char available;
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    char elevation_flag;
    char fog_flag;
    short terrain;
    char movement_type;
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    float attribute_rot;
    float multiple_attribute_mod;
    char attribute_flag[3];
    char area_effect_object_level;
    char combat_level;
    char select_level;
    char map_draw_level;
    char unit_level;
    char map_color;
    char attack_reaction;
    char convert_terrain_flag;

    char damage_sprite_num;
    struct RGE_Damage_Sprite_Info *damage_sprites;

    int help_string_id;
    int help_page_id;
    int hotkey_id;

    char recyclable;
    char track_as_resource;
    char create_doppleganger_on_death;
    char resource_group;

    char draw_flag;
    char draw_color;

    float outline_radius_x,
          outline_radius_y,
          outline_radius_z;

    RGE_Master_Static_Object(RGE_Master_Static_Object *other_object, int do_setup);
    RGE_Master_Static_Object(int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup);
    RGE_Master_Static_Object(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id, int do_setup);

    int setup(RGE_Master_Static_Object *other_object);
    int setup(int infile, RGE_Sprite **sprites, RGE_Sound **sounds);
    int setup(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id);

    ~RGE_Master_Static_Object();

    void make_new_obj(RGE_Player *owner, float x, float y, float z);
    void make_new_master();
    void copy_obj(RGE_Master_Static_Object *source);

    void modify(float amount, char flag);
    void modify_delta(float amount, char flag);
    void modify_percent(float amount, char flag);

    void save(int outfile);

    char check_placement(RGE_Player *player, float col, float row, int *obstructionObject, char check_vis, char check_flat, char check_overlay, char construction_radius_flag, char can_be_built_on_flag, short check_objects);
    void make_available(char on_off_flag);
    char alignment(float *col, float *row, RGE_Game_World *world, char center_flag);
    char alignment_box(RGE_Game_World *world, float col, float row, short *x1, short *y1, short *x2, short *y2, short *x3, short *y3, short *x4, short *y4);

    void draw(TDrawArea *render_area, short x, short y, RGE_Color_Table *player_color, int facet, int frame, int draw_frame, char frame_color);

    int get_help_message();
    int get_help_page();
    int get_hotkey();

    //static signed __int64 calc_base_damage_ability(RGE_Master_Combat_Object *attacker);
};
struct RGE_Damage_Sprite_Info
{
    RGE_Sprite *sprite;
    char damage_percent;
    char flag;
};
