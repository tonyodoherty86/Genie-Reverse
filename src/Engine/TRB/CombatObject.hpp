
/**
 * @file    Engine\TRB\CombatObject.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

/**
 * Size: 452 (ROR)
 */
class TRIBE_Combat_Object : public RGE_Combat_Object
{
public:

#ifdef ENGINE_AOK
    // 108 (TODO)
    UnitAIModule *UnitAi;
    // 332

    // 336

    // 338
    int Unk338;
    // 340
    short SalvageDecay;
    // 344
    int RaiderBuildCountdown;
    // 348
    char GarrisonedCount;
    // 349
    char TownBellUsed;
    // 352
    int TownBellTargetId;
    // 356
    int TownBellTargetType;
    // 360
    int TownBellAiActionType;
    // 364
    int TownBellSecondTargetId;
    // 368, 372
    float TownBellTargetX,
          TownBellTargetY;
    // 376, 377
    char BuilderCount,
         HealerCount;
#endif
    /*
     * @brief   Determines whether this object was derived from an non-standard master-object.
     * Offset: 378 (AOC).
     * Offset: 452 (ROR).
     */
    char own_master;
#ifdef ENGINE_AOK
    // 380
    float MissileAmounts;
    // 384
    char NextVolley;
    // 385
    char SpecialAttackAnimation;
    // 388
    int LockDownCount;

    // 396
    int BeserkerTimer;
#endif

    TRIBE_Combat_Object(TRIBE_Master_Combat_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup);
    TRIBE_Combat_Object(int infile, RGE_Game_World *gworld, int do_setup);

    ~TRIBE_Combat_Object();

    int setup(TRIBE_Master_Combat_Object *tobj, RGE_Player *obj_owner, float x, float y, float z);
    int setup(int infile, RGE_Game_World *gworld);

    void create_action_list();

    void save(int outfile);

    char update();

    void modify(float amount, char flag);
    void transform(RGE_Master_Static_Object *obj);
    void set_object_state(char new_object_state);
    void cancel_object();
    void die_die_die();
    void damage(int weapon_num, RGE_Armor_Weapon_Info *damage, float attack_modifier, RGE_Player *attacking_player, RGE_Static_Object *attackingObject);
    void change_ownership(RGE_Player *new_owner);
    double calc_attack_modifier(RGE_Static_Object *target);
    char attack(RGE_Static_Object *target, RGE_Combat_Object *attacker);
    char do_attack(RGE_Static_Object *target, RGE_Combat_Object *attacker, float x, float y, float z);
    void get_armor(short *cur_armor_in, short *orig_armor_in);
    void get_pierce_armor(short *cur_armor_in, short *orig_armor_in);
    void reposition_artifact();
    int can_debark();

    RGE_Static_Object *hunt(int targetID, int unconditional);
    RGE_Static_Object *convert(int targetID, int unconditional);
    RGE_Static_Object *heal(int targetID, int unconditional);
    RGE_Static_Object *repair(int targetID, int unconditional);
    RGE_Static_Object *build(int targetID, int unconditional);
    RGE_Static_Object *trade(int targetID, int unconditional);

    bool keepGatheringWhenObjectIsOut(int oType);
    bool produceWhenKilledBy(int oGroup);
    bool useSameZoneDropsite();

    void initUnitAI();

    int higher_check_for_cliff(RGE_Static_Object *target, int XTileInt, int YTileInt, float StartX, float StartY, float DestX, float DestY, RGE_Map *Map, RGE_Static_Object *LastCliffObject, float *AngleToTarget, int *HigherCalc);
    int higher_than_target(RGE_Static_Object *target);

    char area_attack(float x, float y, float z, RGE_Combat_Object *attacker, RGE_Static_Object *ignore_object);
    char heal(float healing);

    int canRepair();
    void do_repair(RGE_Static_Object *obj);
};
