
/**
 * @file    Engine\RGE\MasterCombatObject.cpp
 * @author  Yvan Burrie
 * @date    2018/07/07
 * @version 1.0
 */

RGE_Master_Combat_Object::RGE_Master_Combat_Object(
    RGE_Master_Combat_Object *other_object,
    bool do_setup)
{
    RGE_Master_Action_Object::RGE_Master_Action_Object(
        other_object,
        false);

    if( do_setup ){
        RGE_Master_Combat_Object::setup(
            other_object);
    }
}

RGE_Master_Combat_Object::RGE_Master_Combat_Object(
    int infile,
    RGE_Sprite **sprites,
    RGE_Sound **sounds,
    bool do_setup)
{
    RGE_Master_Action_Object::RGE_Master_Action_Object(
        infile,
        sprites,
        sounds,
        false);

    if( do_setup ){
        RGE_Master_Combat_Object::setup(
            infile,
            sprites,
            sounds);
    }
}

bool RGE_Master_Combat_Object::setup(
    RGE_Master_Combat_Object *other_object)
{
    if( this->weapon_num > 0 ){
        this->weapon = new RGE_Armor_Weapon_Info[this->weapon_num];
        memcpy(this->weapon, other_object->weapon, sizeof(RGE_Armor_Weapon_Info) * this->weapon_num);
    }else{
        this->weapon = nullptr;
    }
    if( this->armor_num > 0 ){
        this->armor = new RGE_Armor_Weapon_Info[this->armor_num];
        memcpy(this->armor, other_object->armor, sizeof(RGE_Armor_Weapon_Info) * this->armor_num);
    }else{
        this->armor = nullptr;
    }
    this->fight_sprite          = other_object->fight_sprite;
    this->base_armor            = other_object->base_armor;
    this->defense_terrain_bonus = other_object->defense_terrain_bonus;
    this->weapon_range          = other_object->weapon_range;
    this->area_effect_range     = other_object->area_effect_range;
    this->speed_of_attack       = other_object->speed_of_attack;
    this->missile_id            = other_object->missile_id;
    this->base_hit_chance       = other_object->base_hit_chance;
    this->break_off_combat      = other_object->break_off_combat;
    this->fire_missile_at_frame = other_object->fire_missile_at_frame;
    this->weapon_offset_x       = other_object->weapon_offset_x;
    this->weapon_offset_y       = other_object->weapon_offset_y;
    this->weapon_offset_z       = other_object->weapon_offset_z;
    this->area_effect_level     = other_object->area_effect_level;
    this->minimum_weapon_range  = other_object->minimum_weapon_range;
    this->orig_armor            = other_object->orig_armor;
    this->orig_weapon           = other_object->orig_weapon;
    this->orig_weapon_range     = other_object->orig_weapon_range;
    this->orig_speed_of_attack  = other_object->orig_speed_of_attack;

    return true;
}

bool RGE_Master_Combat_Object::setup(
    int infile,
    RGE_Sprite **sprites,
    RGE_Sound **sounds)
{
    RGE_Master_Action_Object::setup(
        infile,
        sprites,
        sounds);

#if RGE_MASTER_COMBAT_OBJECT_BASE_ARMOR_CAST
    if( save_game_version >= 11.52 ){
        rge_read(infile, &this->base_armor, 2);
    }else{
        rge_read(infile, &this->base_armor, 1);
    }
#else
    rge_read(infile, &this->base_armor, 1);
#endif

    rge_read(infile, &this->weapon_num, 2);
    if( this->weapon_num > 0 ){
        this->weapon = new RGE_Armor_Weapon_Info[this->weapon_num];
        rge_read(infile, &this->weapon, sizeof(RGE_Armor_Weapon_Info) * this->weapon_num);
    }else{
        this->weapon = nullptr;
    }

    rge_read(infile, &this->armor_num, 2);
    if( this->armor_num > 0 ){
        this->armor = new RGE_Armor_Weapon_Info[this->armor_num];
        rge_read(infile, &this->armor, sizeof(RGE_Armor_Weapon_Info) * this->armor_num);
    }else{
        this->armor = nullptr;
    }

    rge_read(infile, &this->defense_terrain_bonus, 2);

    rge_read(infile, &this->weapon_range, 4);

    rge_read(infile, &this->area_effect_range, 4);

    rge_read(infile, &this->speed_of_attack, 4);

    rge_read(infile, &this->missile_id, 2);

    rge_read(infile, &this->base_hit_chance, 2);

    rge_read(infile, &this->break_off_combat, 1);

    rge_read(infile, &this->fire_missile_at_frame, 2);

    rge_read(infile, &this->weapon_offset_x, 4);
    rge_read(infile, &this->weapon_offset_y, 4);
    rge_read(infile, &this->weapon_offset_z, 4);

    rge_read(infile, &this->area_effect_level, 1);

    rge_read(infile, &this->minimum_weapon_range, 4);

    if( save_game_version >= 10.36 ){
        rge_read(infile, &this->garrison_recovery, 4);
    }else{
        this->garrison_recovery = 0.0;
    }

    short sprite_id = -1;
    rge_read(infile, &sprite_id, 2);
    if( sprite_id >= 0 ){
        this->fight_sprite = sprites[sprite_id];
    }else{
        this->fight_sprite = nullptr;
    }

    if( save_game_version >= 7.01 ){
        rge_read(infile, &this->orig_armor, 2);
        rge_read(infile, &this->orig_weapon, 2);
        rge_read(infile, &this->orig_weapon_range, 4);
        rge_read(infile, &this->orig_speed_of_attack, 4);
    }else{
        v4->orig_armor = (unsigned __int8)*v6;
        if( *v9 > 0 )
        {
            v14 = *v9;
            v15 = &v4->armor->value;
            do
            {
                if( *v15 > v4->orig_armor )
                    v4->orig_armor = *v15;
                v15 += 2;
                --v14;
            }
            while( v14 );
        }
        v16 = v4->weapon_num;
        v4->orig_weapon = 0;
        if( v16 > 0 )
        {
            v17 = v16;
            v18 = &v4->weapon->value;
            do
            {
                if( *v18 > v4->orig_weapon )
                    v4->orig_weapon = *v18;
                v18 += 2;
                --v17;
            }
            while( v17 );
        }
        this->orig_weapon_range    = this->weapon_range;
        this->orig_speed_of_attack = this->speed_of_attack;
    }

    return true;
}

bool RGE_Master_Combat_Object::setup(
    int infile,
    RGE_Master **masters)
{
    RGE_Master_Action_Object::setup(
        infile,
        masters);

    RGE_Master_Combat_Object *other_master = masters[this->copy_id];
    if( other_master &&
        other_master->master_type == RGE_MASTER_COMBAT_OBJECT_TYPE ){
        // TODO: copy other stuff
    }

#if RGE_MASTER_COMBAT_OBJECT_BASE_ARMOR_CAST
    if( save_game_version >= 11.52 ){
        rge_read(infile, &this->base_armor, 2);
    }else{
        rge_read(infile, &this->base_armor, 1);
    }
#else
    rge_read(infile, &this->base_armor, 1);
#endif

    rge_read(infile, &this->weapon_num, 2);
    if( this->weapon_num > 0 ){
        this->weapon = new RGE_Armor_Weapon_Info[this->weapon_num];
        rge_read(infile, &this->weapon, sizeof(RGE_Armor_Weapon_Info) * this->weapon_num);
    }else{
        this->weapon = nullptr;
    }

    rge_read(infile, &this->armor_num, 2);
    if( this->armor_num > 0 ){
        this->armor = new RGE_Armor_Weapon_Info[this->armor_num];
        rge_read(infile, &this->armor, sizeof(RGE_Armor_Weapon_Info) * this->armor_num);
    }else{
        this->armor = nullptr;
    }

    rge_read(infile, &this->speed_of_attack, 4);

    rge_read(infile, &this->weapon_range, 4);// TODO: overwritten

    rge_read(infile, &this->base_hit_chance, 2);

    rge_read(infile, &this->missile_id, 2);

    rge_read(infile, &this->defense_terrain_bonus, 2);

    rge_read(infile, &this->weapon_range, 4);

    rge_read(infile, &this->area_effect_range, 4);

    rge_read(infile, &this->minimum_weapon_range, 4);

    return true;
}

RGE_Master_Combat_Object::~RGE_Master_Combat_Object()
{
    if( this->weapon ){
        free(this->weapon);
        this->weapon = nullptr;
    }
    if( this->armor ){
        free(this->armor);
        this->armor = nullptr;
    }
    RGE_Master_Action_Object::~RGE_Master_Action_Object();
}

RGE_Combat_Object *RGE_Master_Combat_Object::make_new_obj(RGE_Player *owner, float x, float y, float z)
{
    if( this->recyclable ){

        RGE_Static_Object *recycled_obj = owner->world->recycle_object_in_to_game(this->master_type);

        if( recycled_obj != nullptr ){
            return recycled_obj->recycle_in_to_game(recycled_obj, this, owner, x, y, z)
        }
    }
    return new RGE_Combat_Object(this, owner, x, y, z, true);
}

RGE_Master_Combat_Object *RGE_Master_Combat_Object::make_new_master()
{
    return new RGE_Master_Combat_Object(this, true);
}

void RGE_Master_Combat_Object::copy_obj(RGE_Master_Combat_Object *source)
{
    RGE_Master_Combat_Object *v2; // ebx@1
    RGE_Armor_Weapon_Info *v3; // eax@1
    short v4; // ax@3
    RGE_Armor_Weapon_Info *v5; // eax@4
    unsigned int v6; // ecx@4
    short v7; // ax@8
    RGE_Armor_Weapon_Info *v8; // eax@9
    unsigned int v9; // ecx@9

    v2 = this;

    RGE_Master_Action_Object::copy_obj(source);

    v2->fight_sprite = (RGE_Sprite *)source[1].death_sound;
    v3 = v2->weapon;
    v2->base_armor = source[1].death_spawn_obj_id;
    v2->weapon_num = source[1].portrait_pict;
    if( v3 )
        free(v3);
    v4 = v2->weapon_num;
    if( v4 <= 0 )
    {
        v2->weapon = 0;
    }
    else
    {
        v5 = (RGE_Armor_Weapon_Info *)calloc(v4, 4u);
        v6 = 4 * v2->weapon_num;
        v2->weapon = v5;
        qmemcpy(v5, *(const void **)&source[1].tile_req1, v6);
    }
    v2->armor_num = *(_WORD *)&source[1].sort_number;
    if( v2->armor )
        free(v2->armor);
    v7 = v2->armor_num;
    if( v7 <= 0 )
    {
        v2->armor = 0;
    }
    else
    {
        v8 = (RGE_Armor_Weapon_Info *)calloc(v7, 4u);
        v9 = 4 * v2->armor_num;
        v2->armor = v8;
        qmemcpy(v8, *(const void **)&source[1].button_pict, v9);
    }
    v2->defense_terrain_bonus = source[1].center_tile_req1;
    v2->weapon_range = source[1].construction_radius_x;
    v2->area_effect_range = source[1].construction_radius_y;
    v2->speed_of_attack = *(float *)&source[1].movement_type;
    v2->missile_id = source[1].attribute_type_held[1];
    v2->base_hit_chance = source[1].attribute_type_held[2];
    v2->break_off_combat = LOBYTE(source[1].attribute_amount_held[0]);
    v2->fire_missile_at_frame = HIWORD(source[1].attribute_amount_held[0]);
    v2->weapon_offset_x = source[1].attribute_amount_held[1];
    v2->weapon_offset_y = source[1].attribute_amount_held[2];
    v2->weapon_offset_z = *(float *)&source[1].attribute_max_amount;
    v2->area_effect_level = source[1].elevation_flag;
    v2->minimum_weapon_range = source[1].attribute_rot;
    v2->orig_armor = LOWORD(source[1].multiple_attribute_mod);
    v2->orig_weapon = HIWORD(source[1].multiple_attribute_mod);
    v2->orig_weapon_range = *(float *)&source[1].attribute_flag[0];
    v2->orig_speed_of_attack = *(float *)&source[1].combat_level;
}

void RGE_Master_Combat_Object::modify(float amount, char flag)
{
    switch( flag ){

    case RGE_Master_Combat_Object::ModifyFlag::ArmorValue:
        v3 = (signed __int64)amount;
        HIDWORD(v3) = this->armor;
        if( HIDWORD(v3) )
        {
            v4 = this->armor_num;
            v5 = BYTE1(v3);
            goto LABEL_6;
        }
        break;

    case RGE_Master_Combat_Object::ModifyFlag::WeaponValue:
        v3 = (signed __int64)amount;
        HIDWORD(v3) = this->weapon;
        if( this->weapon ){
            v5 = BYTE1(v3);
LABEL_6:
            if( v5 < this->weapon_num ){
                this->weapon[v5]->value = (unsigned char)amount;
            }
        }
        break;

    case RGE_Master_Combat_Object::ModifyFlag::AttackSpeed:
        this->speed_of_attack = amount;
        break;

    case RGE_Master_Combat_Object::ModifyFlag::BaseHitChance:
        this->base_hit_chance = (short)amount;
        break;

    case RGE_Master_Combat_Object::ModifyFlag::WeaponRange:
        this->weapon_range = amount;
        break;

    case RGE_Master_Combat_Object::ModifyFlag::BaseArmor:
        this->base_armor = (short)amount;
        break;

    case RGE_Master_Combat_Object::ModifyFlag::MissileId:
        this->missile_id = (short)amount;
        break;

    case RGE_Master_Combat_Object::ModifyFlag::DefenseTerrainBonus:
        this->defense_terrain_bonus = (short)amount;
        break;

    default:
        RGE_Master_Action_Object::modify(amount, flag);
        break;
    }
}

void RGE_Master_Combat_Object::modify_delta(float amount, char flag)
{
    signed __int64 v3; // rax@2
    RGE_Armor_Weapon_Info *v4; // edi@2
    signed int v5; // esi@3
    int v6; // ecx@4
    signed int v7; // esi@9
    int v8; // ecx@10

    switch( flag ){

    case 8:
        v3 = (signed __int64)amount;
        v4 = this->armor;
        if( v4 )
        {
            v5 = this->armor_num;
            WORD2(v3) = 0;
            if( v5 > 0 )
            {
                v6 = 0;
                do
                {
                    if( v4[v6].type == BYTE1(v3) )
                        goto LABEL_14;
                    ++WORD2(v3);
                    v6 = WORD2(v3);
                }
                while( WORD2(v3) < v5 );
            }
        }
        break;

    case 9:
        v3 = (signed __int64)amount;
        v4 = this->weapon;
        if( v4 )
        {
            v7 = this->weapon_num;
            WORD2(v3) = 0;
            if( v7 > 0 )
            {
                v8 = 0;
                while( v4[v8].type != BYTE1(v3) )
                {
                    ++WORD2(v3);
                    v8 = WORD2(v3);
                    if( WORD2(v3) >= v7 )
                        return;
                }
LABEL_14:
                v4[WORD2(v3)].value += (unsigned __int8)v3;
            }
        }
        break;

    case 6:
        this->turn_speed += amount;
        break;

    case 0xA:
        this->speed_of_attack += amount;
        break;

    case 0xB:
        this->base_hit_chance += (short)amount;
        break;

    case 0xC:
        this->weapon_range += amount;
        break;

    case 0xF:
        this->base_armor += (short)amount;
        break;

    case 0x10:
        this->missile_id += (short)amount;
        break;

    case 0x12:
        this->defense_terrain_bonus = (short)amount;
        break;

    default:
        RGE_Master_Action_Object::modify_delta(amount, flag);
        break;
    }
}

void RGE_Master_Combat_Object::modify_percent(float amount, char flag)
{
    switch( flag ){

    case 6:
        this->turn_speed *= amount;
        break;

    case 0xA:
        this->speed_of_attack *= amount;
        break;

    case 0xB:
        this->base_hit_chance *= amount;
        break;

    case 0xC:
        this->weapon_range *= amount;
        break;

    case 0xF:
        this->base_armor = (signed __int64)((double)this->missile_id * amount);// TODO: wtf
        break;

    case 0x10:
        this->missile_id *= amount;
        break;

    case 0x12:
        this->defense_terrain_bonus *= amount;
        break;

    case 8:
    case 9:
        return;

    default:
        RGE_Master_Action_Object::modify_percent(amount, flag);
        break;
    }
}

void RGE_Master_Combat_Object::save(int outfile)
{
    RGE_Master_Action_Object::save(outfile);

    short sprite_id = -1
    if( this->fight_sprite ){
        sprite_id = this->fight_sprite->id;
    }
    rge_write(outfile, &this->base_armor, 1);

    rge_write(outfile, &this->weapon_num, 2);

    if( this->weapon ){
        rge_write(outfile, &this->weapon, sizeof(RGE_Armor_Weapon_Info) * this->weapon_num);
    }

    rge_write(outfile, &this->armor_num, 2);
    if( this->armor ){
        rge_write(outfile, &this->armor, sizeof(RGE_Armor_Weapon_Info) * this->armor_num);
    }

    rge_write(outfile, &this->defense_terrain_bonus, 2);

    rge_write(outfile, &this->weapon_range, 4);

    rge_write(outfile, &this->area_effect_range, 4);

    rge_write(outfile, &this->speed_of_attack, 4);

    rge_write(outfile, &this->missile_id, 2);

    rge_write(outfile, &this->base_hit_chance, 2);

    rge_write(outfile, &this->break_off_combat, 1);

    rge_write(outfile, &this->fire_missile_at_frame, 2);

    rge_write(outfile, &this->weapon_offset_x, 4);
    rge_write(outfile, &this->weapon_offset_y, 4);
    rge_write(outfile, &this->weapon_offset_z, 4);

    rge_write(outfile, &this->area_effect_level, 1);

    rge_write(outfile, &this->minimum_weapon_range, 4);

    rge_write(outfile, &sprite_id, 2);

    rge_write(outfile, &this->orig_armor, 2);
    rge_write(outfile, &this->orig_weapon, 2);
    rge_write(outfile, &this->orig_weapon_range, 4);
    rge_write(outfile, &this->orig_speed_of_attack, 4);
}

double RGE_Master_Combat_Object::calc_base_damage_ability(RGE_Master_Combat_Object *attacker)
{
    double v2; // st7@1
    RGE_Armor_Weapon_Info *v3; // edi@1
    RGE_Armor_Weapon_Info *v4; // eax@4
    int v5; // edx@4
    double v6; // st6@8
    int v8; // [sp+10h] [bp-8h]@2
    RGE_Master_Combat_Object *attackera; // [sp+1Ch] [bp+4h]@3

    v2 = 0.0;
    v3 = attacker->weapon;
    if( attacker->weapon_num > 0 )
    {
        v8 = attacker->weapon_num;
        do
        {
            attackera = (RGE_Master_Combat_Object *)this->base_armor;
            if( this->armor_num > 0 )
            {
                v4 = this->armor;
                v5 = this->armor_num;
                do
                {
                    if( v4->type == v3->type )
                        attackera = (RGE_Master_Combat_Object *)v4->value;
                    ++v4;
                    --v5;
                }
                while( v5 );
            }
            v6 = (double)v3->value - (double)(signed int)attackera;
            if( v6 > 0.0 )
                v2 = v2 + v6;
            ++v3;
            --v8;
        }
        while( v8 );
    }
    if( v2 < 1.0 )
        v2 = 1.0;
    return (signed __int64)v2;
}
