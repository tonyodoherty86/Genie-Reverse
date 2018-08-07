
/**
 * @file    Engine\RGE\MasterCombatObject.hpp
 * @author  Yvan Burrie
 * @date    2018/07/07
 * @version 1.0
 */

#ifndef RGE_MASTER_COMBAT_OBJECT_TYPE
    #define RGE_MASTER_COMBAT_OBJECT_TYPE 50
#endif

#ifndef RGE_MASTER_COMBAT_OBJECT_BASE_ARMOR_CAST
    #define RGE_MASTER_COMBAT_OBJECT_BASE_ARMOR_CAST TRUE
#endif

#ifndef RGE_MASTER_COMBAT_OBJECT_GARRISON_RECOVERY_EXISTS
    #define RGE_MASTER_COMBAT_OBJECT_GARRISON_RECOVERY_EXISTS TRUE
#endif

class RGE_Master_Combat_Object : public RGE_Master_Action_Object
{
public:

    char master_type = RGE_MASTER_COMBAT_OBJECT_TYPE;

    RGE_Sprite *fight_sprite;

#if RGE_MASTER_COMBAT_OBJECT_BASE_ARMOR_CAST
    short base_armor;
#else
    char base_armor;
#endif

    short armor_num;
    struct RGE_Armor_Weapon_Info *armor;

    short weapon_num;
    struct RGE_Armor_Weapon_Info *weapon;

    short defense_terrain_bonus = -1;

    float weapon_range;

    float area_effect_range;

    char area_effect_level;

    float speed_of_attack;

    short missile_id;

    short base_hit_chance;

    char break_off_combat;

    short fire_missile_at_frame;

    float weapon_offset_x,
          weapon_offset_y,
          weapon_offset_z;

    float minimum_weapon_range;

    short orig_armor;
    short orig_weapon;
    float orig_weapon_range;
    float orig_speed_of_attack;

#if RGE_MASTER_COMBAT_OBJECT_GARRISON_RECOVERY_EXISTS
    float garrison_recovery = 0.0;
#endif

    RGE_Master_Combat_Object(
        RGE_Master_Combat_Object *other_object,
        bool do_setup);

    RGE_Master_Combat_Object(
        int infile,
        RGE_Sprite **sprites,
        RGE_Sound **sounds,
        bool do_setup);

    bool setup(
        RGE_Master_Combat_Object *other_object);

    bool setup(
        int infile,
        RGE_Sprite **sprites,
        RGE_Sound **sounds);

    ~RGE_Master_Combat_Object();

    void make_new_obj(
        RGE_Player *owner,
        float x,
        float y,
        float z);

    void make_new_master();

    void copy_obj(
        RGE_Master_Static_Object *source);

    enum ModifyFlag
    {
        TurnSpeed           = 6,
        ArmorValue          = 8,
        WeaponValue         = 9,
        AttackSpeed         = 10,
        BaseHitChance       = 11,
        WeaponRange         = 12,
        BaseArmor           = 15,
        MissileId           = 16,
        DefenseTerrainBonus = 18,
    };

    void modify(
        float amount,
        char flag);

    void modify_delta(
        float amount,
        char flag);

    void modify_percent(
        float amount,
        char flag);

    void save(
        int outfile);

    double calc_base_damage_ability(
        RGE_Master_Combat_Object *attacker);
};

struct RGE_Armor_Weapon_Info
{
    short type;

    short value;
};
