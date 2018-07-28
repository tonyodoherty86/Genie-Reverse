
/**
 * @file    Engine\RGE\MasterStaticObject.hpp
 * @author  Yvan Burrie
 * @date    2018/06/30
 * @version 1.0
 */

#ifndef RGE_MASTER_STATIC_OBJECT_TYPE
    #define RGE_MASTER_STATIC_OBJECT_TYPE 10
#endif

#define RGE_MASTER_STATIC_OBJECT_ATTRIBUTES_COUNT 3

class RGE_Master_Static_Object
{
public:

    char master_type = RGE_MASTER_STATIC_OBJECT_TYPE;

    char *name;

    short string_id = -1,
          string_id2 = -1;

    short id = 0;

    short copy_id = 0;

    short object_group;

    RGE_Sprite *sprite,
               *death_sprite,
               *undead_sprite;

    char undead_flag;

    short hp;

    /**
     * Line-of-Sight
     */
    float los;

    char obj_max;

    float radius_x,
          radius_y,
          radius_z;

    RGE_Sound *selected_sound,
              *created_sound,
              *death_sound;

    short death_spawn_obj_id;

    char sort_number;

    char can_be_built_on;

    short button_pict;

    char hide_in_scenario_editor;

    short portrait_pict;

    char available;

    short tile_req1,
          tile_req2;

    short center_tile_req1,
          center_tile_req2;

    float construction_radius_x,
          construction_radius_y;

    char elevation_flag;

    char fog_flag;

    short terrain = -1;

    char movement_type;

    short attribute_type_held[RGE_MASTER_STATIC_OBJECT_ATTRIBUTES_COUNT];

    float attribute_amount_held[RGE_MASTER_STATIC_OBJECT_ATTRIBUTES_COUNT];

    short attribute_max_amount;

    float attribute_rot;

    float multiple_attribute_mod;

    char attribute_flag[RGE_MASTER_STATIC_OBJECT_ATTRIBUTES_COUNT];

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

    int help_string_id = -1,
        help_page_id = -1,
        hotkey_id = -1;

    char recyclable;
    char track_as_resource;
    char create_doppleganger_on_death;
    char resource_group;

    char draw_flag;
    char draw_color;

    float outline_radius_x,
          outline_radius_y,
          outline_radius_z;

    RGE_Master_Static_Object(
        RGE_Master_Static_Object *other_object,
        bool do_setup);

    RGE_Master_Static_Object(
        int infile,
        RGE_Sprite **sprites,
        RGE_Sound **sounds,
        bool do_setup);

    bool setup(
        RGE_Master_Static_Object *other_object);

    bool setup(
        int infile,
        RGE_Sprite **sprites,
        RGE_Sound **sounds);

    ~RGE_Master_Static_Object();

    void make_new_obj(
        RGE_Player *owner,
        float x,
        float y,
        float z);

    void make_new_master();

    void copy_obj(
        RGE_Master_Static_Object *source);

    void modify(
        float amount,
        char flag);

    void modify_delta(
        float amount,
        char flag);

    void modify_percent(
        float amount,
        char flag);

    void save(int outfile);

    char check_placement(
        RGE_Player *player,
        float col,
        float row,
        int *obstructionObject,
        char check_vis,
        char check_flat,
        char check_overlay,
        char construction_radius_flag,
        char can_be_built_on_flag,
        short check_objects);

    void make_available(
        char on_off_flag);

    char alignment(
        float *col,
        float *row,
        RGE_Game_World *world,
        char center_flag);

    char alignment_box(
        RGE_Game_World *world,
        float col,
        float row,
        short *x1,
        short *y1,
        short *x2,
        short *y2,
        short *x3,
        short *y3,
        short *x4,
        short *y4);

    void draw(
        TDrawArea *render_area,
        short x,
        short y,
        RGE_Color_Table *player_color,
        int facet,
        int frame,
        int draw_frame,
        char frame_color);

    int get_help_message();
    int get_help_page();
    int get_hotkey();

    double calc_base_damage_ability(
        class RGE_Master_Combat_Object *attacker);
};
struct RGE_Damage_Sprite_Info
{
    RGE_Sprite *sprite;

    char damage_percent;

    char flag;
};
