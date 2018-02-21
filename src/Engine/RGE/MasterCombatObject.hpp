
/**
 * @file    Engine\RGE\MasterCombatObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Master_Combat_Object : public RGE_Master_Action_Object
{
public:
    RGE_Sprite *fight_sprite;

    char base_armor;
    short armor_num;
    struct RGE_Armor_Weapon_Info *armor;
    short weapon_num;
    struct RGE_Armor_Weapon_Info *weapon;

    short defense_terrain_bonus;
    float weapon_range;

    float area_effect_range;
    char area_effect_level;

    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
    char break_off_combat;
    short fire_missile_at_frame;

    float weapon_offset_x;
    float weapon_offset_y;
    float weapon_offset_z;

    float minimum_weapon_range;

    short orig_armor;
    short orig_weapon;
    float orig_weapon_range;
    float orig_speed_of_attack;

    RGE_Master_Combat_Object(RGE_Master_Combat_Object *other_object, int do_setup);
    RGE_Master_Combat_Object(int infile, RGE_Sprite **sprites, RGE_Sound **sounds, int do_setup);
    RGE_Master_Combat_Object(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id, int do_setup);

    int setup(RGE_Master_Combat_Object *other_object);
    int setup(int infile, RGE_Sprite **sprites, RGE_Sound **sounds);
    int setup(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds, short in_id);

    ~RGE_Master_Combat_Object();

    void make_new_obj(RGE_Player *owner, float x, float y, float z);
    void make_new_master();

    void copy_obj(RGE_Master_Static_Object *source);

    void modify(float amount, char flag);
    void modify_delta(float amount, char flag);
    void modify_percent(float amount, char flag);

    void save(int outfile);

    //signed __int64 calc_base_damage_ability(RGE_Master_Combat_Object *attacker);
};

struct RGE_Armor_Weapon_Info
{
    short type;
    short value;
};
