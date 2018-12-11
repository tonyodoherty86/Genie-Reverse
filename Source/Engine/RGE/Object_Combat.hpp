#pragma once

#include "Object_Action.hpp"
#include "IDA.h"

class RGE_Master_Combat_Object;
class VISIBLE_UNIT_REC;


/**
 * @file    Engine\RGE\CombatObject.hpp
 * @author  Yvan Burrie
 * @date    2018/07/07
 * @version 1.0
 */

#ifndef RGE_COMBAT_OBJECT_TYPE
    #define RGE_COMBAT_OBJECT_TYPE 50
#endif

#ifndef RGE_COMBAT_OBJECT_CAPTURE_FLAG_EXISTS
    #define RGE_COMBAT_OBJECT_CAPTURE_FLAG_EXISTS TRUE
#endif

#ifndef RGE_COMBAT_OBJECT_FORMATION_EXISTS
    #define RGE_COMBAT_OBJECT_FORMATION_EXISTS TRUE
#endif

#ifndef RGE_COMBAT_OBJECT_VISIBILITY_INFO_EXISTS
    #define RGE_COMBAT_OBJECT_VISIBILITY_INFO_EXISTS TRUE
#endif

#ifndef RGE_COMBAT_OBJECT_ATTACK_COUNT_EXISTS
    #define RGE_COMBAT_OBJECT_ATTACK_COUNT_EXISTS TRUE
#endif

class RGE_Combat_Object : public RGE_Action_Object
{
public:

    char type = RGE_COMBAT_OBJECT_TYPE;

    RGE_Master_Combat_Object *master_obj;

    VISIBLE_UNIT_REC *VUR_Ptrs[RGE_PLAYERS_COUNT];

    unsigned int Unified_Map_Value;

#if RGE_COMBAT_OBJECT_VISIBILITY_INFO_EXISTS
    /**
     * Offset: 312.
     */
    char multi_unified_point;

    /**
     * Offset: 313.
     */
    char large_radius;
#endif

#if RGE_COMBAT_OBJECT_ATTACK_COUNT_EXISTS
    /**
     * Offset: 316.
     */
    int attack_count;
#endif

    /**
     * Offset: 320.
     */
    float attack_timer;

#if RGE_COMBAT_OBJECT_CAPTURE_FLAG_EXISTS
    /**
     * Offset: 324.
     */
    char capture_flag;
#endif

#if RGE_COMBAT_OBJECT_FORMATION_EXISTS
    /**
     * Offset: 325, 326, 327.
     */
    char formation_id,
         formation_row,
         formation_col;
#endif

    RGE_Combat_Object(
        RGE_Master_Combat_Object *tobj,
        RGE_Player *obj_owner,
        float x,
        float y,
        float z,
        bool do_setup);

    RGE_Combat_Object(
        int infile,
        RGE_Game_World *gworld,
        bool do_setup);

    ~RGE_Combat_Object();

    bool setup(
        RGE_Master_Combat_Object *tobj,
        RGE_Player *obj_owner,
        float x,
        float y,
        float z);

    bool setup(
        int infile,
        RGE_Game_World *gworld);

    void save(
        int outfile);

    void stop();

    double calc_attack_modifier(RGE_Static_Object *target);
    char area_attack(float x, float y, float z, RGE_Combat_Object *attacker, RGE_Static_Object *ignore_object);
    char attack(RGE_Static_Object *target, RGE_Combat_Object *attacker);
    char attack(float target_x, float target_y, float target_z, RGE_Combat_Object *attacker);
    char do_attack(RGE_Static_Object *target, RGE_Combat_Object *attacker, float x, float y, float z);
    void damage(int weapon_num, RGE_Armor_Weapon_Info *damage, float attack_modifier, RGE_Player *attacking_player, RGE_Static_Object *attackingObject);
    double calculateDamage(int weapon_num, RGE_Armor_Weapon_Info *damage, float attack_modifier, RGE_Player *attacking_player, RGE_Static_Object *attackingObject);

    bool can_attack();

    void reset_attack_timer();
    void get_armor(short *cur_armor_in, short *orig_armor_in);
    void get_weapon(short *cur_weapon_in, short *orig_weapon_in);
    void get_weapon_range(float *cur_weapon_range_in, float *orig_weapon_range_in);
    void get_speed_of_attack(float *cur_speed_of_attack_in, float *orig_speed_of_attack_in);
    void release_being_worked_on(RGE_Static_Object *caller);
    void enter_obj(RGE_Static_Object *target);

    bool update();

    void copy_obj(RGE_Master_Static_Object *source2);
    void notify(int caller, int recipient, int mType, int p1, int p2, int p3);
    RGE_Static_Object *attack(int targetID, int unconditional);
    int attack(float x, float y, float z, int unconditional);
    int moveTo(int targetID, int unconditional);
    RGE_Static_Object *moveTo(int targetID, float minRange, int unconditional);
    int moveTo(float x, float y, float z, float minRange, int unconditional);
    int moveAwayFrom(int targetID, int unconditional);
    RGE_Static_Object *gather(int targetID, int unconditional);
    int explore(int tX, int tY, int unconditional);
    RGE_Static_Object *enter(int targetID, int unconditional);
    int transport(float tX, float tY, float tZ, int unconditional);
    int unload(int unconditional, float x, float y, float z);
    int stopAction();
    int pause();
    double rateOfFire();
    double damageCapability();
    double damageCapability(RGE_Static_Object *attackingUnit);
    int inAttackRange(RGE_Static_Object *target);
    double weaponRange();
    double minimumWeaponRange();
    int currentTargetID();
    double currentTargetX();
    double currentTargetY();
    double currentTargetZ();
    double teleport(float x, float y, float z);
};
