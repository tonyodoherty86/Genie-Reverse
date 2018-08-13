
RGE_Master_Static_Object::RGE_Master_Static_Object(
    RGE_Master_Static_Object *other_object,
    bool do_setup)
{
    if( do_setup ){
        this->setup(
            other_object);
    }
}

RGE_Master_Static_Object::RGE_Master_Static_Object(
    int infile,
    RGE_Sprite **sprites,
    RGE_Sound **sounds,
    bool do_setup = true)
{
    if( do_setup ){
        this->setup(
            infile,
            sprites,
            sounds);
    }
}

bool RGE_Master_Static_Object::setup(
    RGE_Master_Static_Object *other_object)
{
    RGE_Master_Static_Object *v2; // esi@1
    RGE_Master_Static_Object *v3; // edi@1
    short v4; // ax@1
    char *v5; // edx@1
    char *v6; // ebp@1
    char *v7; // ecx@1
    char *v8; // eax@1
    char v9; // al@3
    int v10; // ecx@4
    int v11; // eax@5
    RGE_Master_Static_Object *other_objecta; // [sp+14h] [bp+4h]@1

    v2 = this;
    v3 = other_object;

    this->recyclable                   = other_object->recyclable;
    this->string_id                    = other_object->string_id;
    this->string_id2                   = other_object->string_id2;
    this->id                           = other_object->id;
    this->copy_id                      = other_object->id;
    this->object_group                 = other_object->object_group;
    this->sprite                       = other_object->sprite;
    this->death_sprite                 = other_object->death_sprite;
    this->undead_sprite                = other_object->undead_sprite;
    this->undead_flag                  = other_object->undead_flag;
    this->hp                           = other_object->hp;
    this->los                          = other_object->los;
    this->obj_max                      = other_object->obj_max;
    this->radius_x                     = other_object->radius_x;
    this->radius_y                     = other_object->radius_y;
    this->radius_z                     = other_object->radius_z;
    this->created_sound                = other_object->created_sound;
    this->death_spawn_obj_id           = other_object->death_spawn_obj_id;
    this->sort_number                  = other_object->sort_number;
    this->can_be_built_on              = other_object->can_be_built_on;
    this->button_pict                  = other_object->button_pict;
    this->hide_in_scenario_editor      = other_object->hide_in_scenario_editor;
    this->portrait_pict                = other_object->portrait_pict;
    this->available                    = other_object->available;
    this->tile_req1                    = other_object->tile_req1;
    this->tile_req2                    = other_object->tile_req2;
    this->center_tile_req1             = other_object->center_tile_req1;
    this->center_tile_req2             = other_object->center_tile_req2;
    this->construction_radius_x        = other_object->construction_radius_x;
    this->construction_radius_y        = other_object->construction_radius_y;
    this->elevation_flag               = other_object->elevation_flag;
    this->fog_flag                     = other_object->fog_flag;
    this->terrain                      = other_object->terrain;
    this->movement_type                = other_object->movement_type;
    this->attribute_max_amount         = other_object->attribute_max_amount;
    this->attribute_rot                = other_object->attribute_rot;
    this->area_effect_object_level     = other_object->area_effect_object_level;
    this->combat_level                 = other_object->combat_level;
    this->select_level                 = other_object->select_level;
    this->map_draw_level               = other_object->map_draw_level;
    this->unit_level                   = other_object->unit_level;
    this->multiple_attribute_mod       = other_object->multiple_attribute_mod;
    this->selected_sound               = other_object->selected_sound;
    this->death_sound                  = other_object->death_sound;
    this->attack_reaction              = other_object->attack_reaction;
    this->convert_terrain_flag         = other_object->convert_terrain_flag;
    this->map_color                    = other_object->map_color;
    this->help_string_id               = other_object->help_string_id;
    this->help_page_id                 = other_object->help_page_id;
    this->hotkey_id                    = other_object->hotkey_id;
    this->track_as_resource            = other_object->track_as_resource;
    this->create_doppleganger_on_death = other_object->create_doppleganger_on_death;
    this->resource_group               = other_object->resource_group;
    this->draw_flag                    = other_object->draw_flag;
    this->draw_color                   = other_object->draw_color;
    this->outline_radius_x             = other_object->outline_radius_x;
    this->outline_radius_y             = other_object->outline_radius_y;
    this->outline_radius_z             = other_object->outline_radius_z;

    v5 = this->attribute_flag;
    v6 = (char *)this->attribute_amount_held;
    v7 = (char *)this->attribute_type_held;
    v8 = (char *)((char *)other_object - (char *)v2);
    other_objecta = (RGE_Master_Static_Object *)3;
    do
    {
        v6 += 4;
        *(_WORD *)v7 = *(_WORD *)&v7[(_DWORD)v8];
        *((_DWORD *)v6 - 1) = *(_DWORD *)&v6[(_DWORD)v8 - 4];
        *v5 = v5[(_DWORD)v8];
        v7 += 2;
        ++v5;
        other_objecta = (RGE_Master_Static_Object *)((char *)other_objecta - 1);
    }
    while( other_objecta );
    v9 = v3->damage_sprite_num;
    v2->damage_sprite_num = v9;
    if( v9 )
    {
        v2->damage_sprites = (RGE_Damage_Sprite_Info *)calloc((unsigned __int8)v9, 8u);
        v10 = 0;
        if( v2->damage_sprite_num )
        {
            do
            {
                v11 = (signed short)v10++;
                v2->damage_sprites[v11].sprite = v3->damage_sprites[v11].sprite;
                v2->damage_sprites[v11].damage_percent = v3->damage_sprites[v11].damage_percent;
                v2->damage_sprites[v11].flag = v3->damage_sprites[v11].flag;
            }
            while( (signed short)v10 < v2->damage_sprite_num );
        }
    }
    else
    {
        v2->damage_sprites = 0;
    }
    v2->name = 0;
    getstring(&v2->name, v3->name);

    return true;
}

bool RGE_Master_Static_Object::setup(
    int infile,
    RGE_Sprite **sprites,
    RGE_Sound **sounds)
{
    short name_length;
    rge_read(infile, &name_length, 2);

    rge_read(infile, &this->id, 2);

    rge_read(infile, &this->string_id, 2);
    rge_read(infile, &this->string_id2, 2);
    rge_read(infile, &this->object_group, 2);

    rge_read(infile, &sprite_num, 2);
    rge_read(infile, &death_sprite_num, 2);
    rge_read(infile, &undead_sprite_num, 2);

    rge_read(infile, &this->undead_flag, 1);
    rge_read(infile, &this->hp, 2);
    rge_read(infile, &this->los, 4);
    rge_read(infile, &this->obj_max, 1);
    rge_read(infile, &this->radius_x, 4);
    rge_read(infile, &this->radius_y, 4);
    rge_read(infile, &this->radius_z, 4);
    rge_read(infile, &created_sound_num, 2);
    rge_read(infile, &this->death_spawn_obj_id, 2);
    rge_read(infile, &this->sort_number, 1);
    rge_read(infile, &this->can_be_built_on, 1);
    rge_read(infile, &this->button_pict, 2);
    rge_read(infile, &this->hide_in_scenario_editor, 1);
    rge_read(infile, &this->portrait_pict, 2);
    rge_read(infile, &this->available, 1);
    rge_read(infile, &this->tile_req1, 2);
    rge_read(infile, &this->tile_req2, 2);
    rge_read(infile, &this->center_tile_req1, 2);
    rge_read(infile, &this->center_tile_req2, 2);
    rge_read(infile, &this->construction_radius_x, 4);
    rge_read(infile, &this->construction_radius_y, 4);
    rge_read(infile, &this->elevation_flag, 1);
    rge_read(infile, &this->fog_flag, 1);
    rge_read(infile, &this->terrain, 2);
    rge_read(infile, &this->movement_type, 1);
    rge_read(infile, &this->attribute_max_amount, 2);
    rge_read(infile, &this->attribute_rot, 4);
    rge_read(infile, &this->area_effect_object_level, 1);
    rge_read(infile, &this->combat_level, 1);
    rge_read(infile, &this->select_level, 1);
    rge_read(infile, &this->map_draw_level, 1);
    rge_read(infile, &this->unit_level, 1);
    rge_read(infile, &this->multiple_attribute_mod, 4);
    rge_read(infile, &this->map_color, 1);
    rge_read(infile, &this->help_string_id, 4);
    rge_read(infile, &this->help_page_id, 4);
    rge_read(infile, &this->hotkey_id, 4);
    rge_read(infile, &this->recyclable, 1);
    rge_read(infile, &this->track_as_resource, 1);
    rge_read(infile, &this->create_doppleganger_on_death, 1);
    rge_read(infile, &this->resource_group, 1);

    if( save_game_version >= 7.04 ){
        rge_read(infile, &this->draw_flag, 1);
        rge_read(infile, &this->draw_color, 1);
        rge_read(infile, &this->outline_radius_x, 4);
        rge_read(infile, &this->outline_radius_y, 4);
        rge_read(infile, &this->outline_radius_z, 4);
    }else{
        this->draw_flag = 0;
        this->draw_color = 0;
        this->outline_radius_x = this->radius_x;
        this->outline_radius_y = this->radius_y;
        this->outline_radius_z = this->radius_z;
    }
    v12 = v6->attribute_amount_held;
    data = v6->attribute_flag;
    v13 = v6->attribute_type_held;
    v36 = 3;
    do
    {
        rge_read((int)v13, (int)v6, v5, v13, 2);
        rge_read((int)v13, (int)v6, v5, v12, 4);
        rge_read((int)v13, (int)v6, v5, data, 1);
        ++v13;
        ++v12;
        v14 = v36 == 1;
        data = (char *)data + 1;
        --v36;
    }
    while( !v14 );
    v15 = &v6->damage_sprite_num;

    rge_read(infile, &this->damage_sprite_num, 1);
    if( this->damage_sprite_num ){
        this->damage_sprites = new RGE_Damage_Sprite_Info[this->damage_sprite_num];
        v16 = 0;
        if( *v15 )
        {
            do
            {
                rge_read(infile, &temp_damage_sprite, 2);
                v15 = (char *)(8 * v16);
                rge_read(infile, &this->damage_sprites->damage_percent + (unsigned int)v15, 2);
                rge_read(infile, &this->damage_sprites->flag + (unsigned int)v15, 1);
                if( temp_damage_sprite < 0 )
                    v17 = 0;
                else
                    v17 = sprites[temp_damage_sprite];
                ++v16;
                *(RGE_Sprite **)((char *)&v6->damage_sprites->sprite + (unsigned int)v15) = v17;
            }
            while( v16 < v6->damage_sprite_num );
        }
    }else{
        this->damage_sprites = nullptr;
    }
    rge_read(infile, &selected_sound_num, 2);
    rge_read(infile, &death_sound_num, 2);

    rge_read(infile, &this->attack_reaction, 1);
    rge_read(infile, &this->convert_terrain_flag, 1);

    if( name_length > 0 ){
        this->name = char[name_length];
        rge_read(infile, &this->name, name_length);
    }else{
        this->name = nullptr;
    }

#if RGE_MASTER_STATIC_OBJECT_COPY_ID_EXISTS
    if( save_game_version >= 7.12 ){
        rge_read(infile, &this->copy_id, 2);
    }
#endif

    if( selected_sound_num >= 0 ){
        this->selected_sound = sounds[selected_sound_num];
    }else{
        this->selected_sound = nullptr;
    }

    if( death_sound_num >= 0 ){
        this->death_sound = sounds[death_sound_num];
    }else{
        this->death_sound = nullptr;
    }

    if( created_sound_num >= 0 ){
        this->created_sound = sounds[created_sound_num];
    }else{
        this->created_sound = nullptr;
    }

    if( sprite_num >= 0 ){
        this->sprite = sprites[sprite_num];
    }else{
        this->sprite = nullptr;
    }

    if( death_sprite_num >= 0 ){
        this->death_sprite = sprites[death_sprite_num];
    }else{
        this->death_sprite = nullptr;
    }

    if( undead_sprite_num >= 0 ){
        this->undead_sprite = sprites[undead_sprite_num];
    }else{
        this->undead_sprite = nullptr;
    }

    return true;
}

RGE_Master_Static_Object::~RGE_Master_Static_Object()
{
    RGE_Master_Static_Object *v1; // esi@1
    char *v2; // eax@1

    v1 = this;
    v2 = this->name;
    if( v2 )
    {
        free(v2);
        v1->name = 0;
    }
    if( v1->damage_sprites )
    {
        free(v1->damage_sprites);
        v1->damage_sprites = 0;
    }
}

RGE_Static_Object *RGE_Master_Static_Object::make_new_obj(
    RGE_Player *owner,
    float x,
    float y,
    float z)
{
    if( this->recyclable ){

        RGE_Static_Object *v6 = owner->world->recycle_object_in_to_game(this->master_type);

        return v6->recycle_in_to_game(
            this,
            owner,
            x,
            y,
            z);
    }
    return RGE_Static_Object::RGE_Static_Object(
        this,
        owner,
        x,
        y,
        z,
        true);
}

RGE_Master_Static_Object *RGE_Master_Static_Object::make_new_master()
{
    return RGE_Master_Static_Object::RGE_Master_Static_Object(this, true);
}

void RGE_Master_Static_Object::copy_obj(
    RGE_Master_Static_Object *source)
{
    RGE_Master_Static_Object *v2; // esi@1
    char *v3; // ebx@1
    short *v4; // eax@3
    char *v5; // ecx@3
    signed int v6; // edx@3
    RGE_Master_Static_Object *v7; // eax@5
    signed int v8; // edx@5
    char *v9; // eax@7
    RGE_Damage_Sprite_Info *v10; // eax@12
    char v11; // cl@12
    signed int v12; // eax@12
    char available2; // [sp+13h] [bp-Dh]@1
    short copy_id2; // [sp+14h] [bp-Ch]@1
    char hide_in_scenario_editor2; // [sp+18h] [bp-8h]@1
    short object_type2; // [sp+1Ch] [bp-4h]@1

    v2 = this;
    object_type2 = this->id;
    v3 = (char *)&this->name;
    hide_in_scenario_editor2 = this->hide_in_scenario_editor;
    copy_id2 = this->copy_id;
    available2 = this->available;
    if( this->name )
        free(this->name);
    v2->master_type = source->master_type;
    *(_DWORD *)v3 = source->name;
    v2->string_id = source->string_id;
    v2->string_id2 = source->string_id2;
    v2->id = source->id;
    v2->copy_id = source->copy_id;
    v2->object_group = source->object_group;
    v2->sprite = source->sprite;
    v2->death_sprite = source->death_sprite;
    v2->undead_sprite = source->undead_sprite;
    v2->undead_flag = source->undead_flag;
    v2->hp = source->hp;
    v2->los = source->los;
    v2->obj_max = source->obj_max;
    v2->radius_x = source->radius_x;
    v2->radius_y = source->radius_y;
    v2->radius_z = source->radius_z;
    v2->selected_sound = source->selected_sound;
    v2->created_sound = source->created_sound;
    v2->death_sound = source->death_sound;
    v2->death_spawn_obj_id = source->death_spawn_obj_id;
    v2->sort_number = source->sort_number;
    v2->can_be_built_on = source->can_be_built_on;
    v2->button_pict = source->button_pict;
    v2->hide_in_scenario_editor = source->hide_in_scenario_editor;
    v2->portrait_pict = source->portrait_pict;
    v2->available = source->available;
    v2->tile_req1 = source->tile_req1;
    v2->tile_req2 = source->tile_req2;
    v2->center_tile_req1 = source->center_tile_req1;
    v2->center_tile_req2 = source->center_tile_req2;
    v2->construction_radius_x = source->construction_radius_x;
    v2->construction_radius_y = source->construction_radius_y;
    v2->elevation_flag = source->elevation_flag;
    v2->fog_flag = source->fog_flag;
    v2->terrain = source->terrain;
    v2->movement_type = source->movement_type;
    v4 = v2->attribute_type_held;
    v5 = (char *)((char *)source - (char *)v2);
    v6 = 3;
    do
    {
        *v4 = *(short *)((char *)v4 + (_DWORD)v5);
        ++v4;
        --v6;
    }
    while( v6 );
    v7 = (RGE_Master_Static_Object *)((char *)v2 + 112);
    v8 = 3;
    do
    {
        v7->vfptr = *(RGE_Master_Static_ObjectVtbl **)&v5[(_DWORD)v7];
        v7 = (RGE_Master_Static_Object *)((char *)v7 + 4);
        --v8;
    }
    while( v8 );
    v2->attribute_max_amount = source->attribute_max_amount;
    v2->attribute_rot = source->attribute_rot;
    v2->multiple_attribute_mod = source->multiple_attribute_mod;
    v9 = v2->attribute_flag;
    do
    {
        *v9 = v5[(_DWORD)v9];
        ++v9;
    }
    while( (unsigned int)&v9[-136 - (_DWORD)v2] < 3 );
    v2->area_effect_object_level = source->area_effect_object_level;
    v2->combat_level = source->combat_level;
    v2->select_level = source->select_level;
    v2->map_draw_level = source->map_draw_level;
    v2->unit_level = source->unit_level;
    v2->map_color = source->map_color;
    v2->attack_reaction = source->attack_reaction;
    v2->convert_terrain_flag = source->convert_terrain_flag;
    v2->damage_sprite_num = source->damage_sprite_num;
    v2->damage_sprites = source->damage_sprites;
    v2->help_string_id = source->help_string_id;
    v2->help_page_id = source->help_page_id;
    v2->hotkey_id = source->hotkey_id;
    v2->recyclable = source->recyclable;
    v2->track_as_resource = source->track_as_resource;
    v2->create_doppleganger_on_death = source->create_doppleganger_on_death;
    v2->resource_group = source->resource_group;
    v2->draw_flag = source->draw_flag;
    v2->draw_color = source->draw_color;
    v2->outline_radius_x = source->outline_radius_x;
    v2->outline_radius_y = source->outline_radius_y;
    v2->outline_radius_z = source->outline_radius_z;
    if( source->hide_in_scenario_editor == 1 )
        v2->copy_id = copy_id2;
    v2->hide_in_scenario_editor = hide_in_scenario_editor2;
    source->hide_in_scenario_editor = 1;
    if( v2->damage_sprite_num )
    {
        v10 = (RGE_Damage_Sprite_Info *)calloc(v2->damage_sprite_num, 8u);
        v11 = v2->damage_sprite_num;
        v2->damage_sprites = v10;
        v12 = 0;
        if( v11 )
        {
            do
            {
                v2->damage_sprites[v12].sprite = source->damage_sprites[v12].sprite;
                v2->damage_sprites[v12].damage_percent = source->damage_sprites[v12].damage_percent;
                v2->damage_sprites[v12].flag = source->damage_sprites[v12].flag;
                ++v12;
            }
            while( v12 < v2->damage_sprite_num );
        }
    }
    else
    {
        v2->damage_sprites = 0;
    }
    *(_DWORD *)v3 = 0;
    getstring(&v2->name, source->name);
    v2->id = object_type2;
    v2->available = available2;
}

//----- (004534A0) --------------------------------------------------------
void RGE_Master_Static_Object::modify(float amount, char flag)
{
    switch ( flag )
    {
        case 0:
            this->hp = (signed __int64)amount;
            break;
        case 1:
            this->los = amount;
            break;
        case 2:
            this->obj_max = (signed __int64)amount;
            break;
        case 3:
            this->radius_x = amount;
            break;
        case 4:
            this->radius_y = amount;
            break;
        case 0xE:
            this->attribute_max_amount = (signed __int64)amount;
            break;
        default:
            return;
    }
}

//----- (00453540) --------------------------------------------------------
void RGE_Master_Static_Object::modify_delta(float amount, char flag)
{
    switch ( flag )
    {
        case 0:
            this->hp += (signed __int64)amount;
            break;
        case 1:
            this->los = amount + this->los;
            break;
        case 2:
            this->obj_max += (signed __int64)amount;
            break;
        case 3:
            this->radius_x = amount + this->radius_x;
            break;
        case 4:
            this->radius_y = amount + this->radius_y;
            break;
        case 0xE:
            this->attribute_max_amount += (signed __int64)amount;
            break;
        default:
            return;
    }
}

//----- (004535F0) --------------------------------------------------------
void RGE_Master_Static_Object::modify_percent(float amount, char flag)
{
    switch ( flag )
    {
        case 0:
            this->hp = (signed __int64)((double)this->hp * amount);
            break;
        case 1:
            this->los = amount * this->los;
            break;
        case 2:
            this->obj_max = (signed __int64)((double)this->obj_max * amount);
            break;
        case 3:
            this->radius_x = amount * this->radius_x;
            break;
        case 4:
            this->radius_y = amount * this->radius_y;
            break;
        case 0xE:
            this->attribute_max_amount = (signed __int64)((double)this->attribute_max_amount * amount);
            break;
        default:
            return;
    }
}

//----- (004536D0) --------------------------------------------------------
void __fastcall RGE_Master_Static_Object::save(int a2, int outfile)
{
    RGE_Master_Static_Object *v3; // ebx@1
    signed int v4; // ecx@1
    int v5; // eax@1
    RGE_Sound *v6; // eax@3
    int v7; // eax@5
    RGE_Sprite *v8; // eax@7
    int v9; // eax@9
    RGE_Sprite *v10; // eax@11
    char *v11; // edi@13
    bool v12; // zf@15
    int v13; // ecx@16
    int v14; // esi@18
    float *v15; // ebp@18
    short *v16; // edi@18
    char v17; // al@20
    signed short v18; // bp@21
    int v19; // edi@22
    int name_size; // [sp+10h] [bp-20h]@1
    int temp_sprite; // [sp+14h] [bp-1Ch]@1
    int temp_death_sprite; // [sp+18h] [bp-18h]@1
    int temp_undead_sprite; // [sp+1Ch] [bp-14h]@1
    int created_sound_num; // [sp+20h] [bp-10h]@1
    int v25; // [sp+24h] [bp-Ch]@18
    int selected_sound_num; // [sp+28h] [bp-8h]@1
    int death_sound_num; // [sp+2Ch] [bp-4h]@1
    char *outfilea; // [sp+34h] [bp+4h]@18

    v3 = this;
    v4 = -1;
    v5 = (int)&v3->created_sound->play_at_update_count;
    name_size = 0;
    temp_sprite = -1;
    temp_death_sprite = -1;
    temp_undead_sprite = -1;
    created_sound_num = -1;
    death_sound_num = -1;
    selected_sound_num = -1;
    if( v5 )
    {
        LOWORD(v5) = *(_WORD *)(v5 + 12);
        created_sound_num = v5;
    }
    v6 = v3->selected_sound;
    if( v6 )
    {
        LOWORD(a2) = v6->id;
        selected_sound_num = a2;
    }
    v7 = (int)&v3->death_sound->play_at_update_count;
    if( v7 )
    {
        LOWORD(v7) = *(_WORD *)(v7 + 12);
        death_sound_num = v7;
    }
    v8 = v3->sprite;
    if( v8 )
    {
        LOWORD(a2) = v8->id;
        temp_sprite = a2;
    }
    v9 = (int)v3->death_sprite;
    if( v9 )
    {
        LOWORD(v9) = *(_WORD *)(v9 + 114);
        temp_death_sprite = v9;
    }
    v10 = v3->undead_sprite;
    if( v10 )
    {
        LOWORD(a2) = v10->id;
        temp_undead_sprite = a2;
    }
    v11 = v3->name;
    do
    {
        if( !v4 )
            break;
        v12 = *v11++ == 0;
        --v4;
    }
    while( !v12 );
    v13 = ~v4 - 1;
    name_size = v13;
    if( (signed short)v13 > 0 )
        name_size = v13 + 1;
    v14 = outfile;
    rge_write(outfile, &v3->master_type, 1);
    rge_write(outfile, &name_size, 2);
    rge_write(outfile, &v3->id, 2);
    rge_write(outfile, &v3->string_id, 2);
    rge_write(outfile, &v3->string_id2, 2);
    rge_write(outfile, &v3->object_group, 2);
    rge_write(outfile, &temp_sprite, 2);
    rge_write(outfile, &temp_death_sprite, 2);
    rge_write(outfile, &temp_undead_sprite, 2);
    rge_write(outfile, &v3->undead_flag, 1);
    rge_write(outfile, &v3->hp, 2);
    rge_write(outfile, &v3->los, 4);
    rge_write(outfile, &v3->obj_max, 1);
    rge_write(outfile, &v3->radius_x, 4);
    rge_write(outfile, &v3->radius_y, 4);
    rge_write(outfile, &v3->radius_z, 4);
    rge_write(outfile, &created_sound_num, 2);
    rge_write(outfile, &v3->death_spawn_obj_id, 2);
    rge_write(outfile, &v3->sort_number, 1);
    rge_write(outfile, &v3->can_be_built_on, 1);
    rge_write(outfile, &v3->button_pict, 2);
    rge_write(outfile, &v3->hide_in_scenario_editor, 1);
    rge_write(outfile, &v3->portrait_pict, 2);
    rge_write(outfile, &v3->available, 1);
    rge_write(outfile, &v3->tile_req1, 2);
    rge_write(outfile, &v3->tile_req2, 2);
    rge_write(outfile, &v3->center_tile_req1, 2);
    rge_write(outfile, &v3->center_tile_req2, 2);
    rge_write(outfile, &v3->construction_radius_x, 4);
    rge_write(outfile, &v3->construction_radius_y, 4);
    rge_write(outfile, &v3->elevation_flag, 1);
    rge_write(outfile, &v3->fog_flag, 1);
    rge_write(outfile, &v3->terrain, 2);
    rge_write(outfile, &v3->movement_type, 1);
    rge_write(outfile, &v3->attribute_max_amount, 2);
    rge_write(outfile, &v3->attribute_rot, 4);
    rge_write(outfile, &v3->area_effect_object_level, 1);
    rge_write(outfile, &v3->combat_level, 1);
    rge_write(outfile, &v3->select_level, 1);
    rge_write(outfile, &v3->map_draw_level, 1);
    rge_write(outfile, &v3->unit_level, 1);
    rge_write(outfile, &v3->multiple_attribute_mod, 4);
    rge_write(outfile, &v3->map_color, 1);
    rge_write(outfile, &v3->help_string_id, 4);
    rge_write(outfile, &v3->help_page_id, 4);
    rge_write(outfile, &v3->hotkey_id, 4);
    rge_write(outfile, &v3->recyclable, 1);
    rge_write(outfile, &v3->track_as_resource, 1);
    rge_write(outfile, &v3->create_doppleganger_on_death, 1);
    rge_write(outfile, &v3->resource_group, 1);
    rge_write(outfile, &v3->draw_flag, 1);
    rge_write(outfile, &v3->draw_color, 1);
    rge_write(outfile, &v3->outline_radius_x, 4);
    rge_write(outfile, &v3->outline_radius_y, 4);
    rge_write(outfile, &v3->outline_radius_z, 4);
    outfilea = v3->attribute_flag;
    v15 = v3->attribute_amount_held;
    v16 = v3->attribute_type_held;
    v25 = 3;
    do
    {
        rge_write(v14, v16, 2);
        rge_write(v14, v15, 4);
        rge_write(v14, outfilea, 1);
        ++v16;
        ++v15;
        v12 = v25 == 1;
        ++outfilea;
        --v25;
    }
    while( !v12 );
    rge_write(v14, &v3->damage_sprite_num, 1);
    v17 = v3->damage_sprite_num;
    if( v17 )
    {
        v18 = 0;
        if( v17 )
        {
            do
            {
                v19 = v18;
                rge_write(v14, &v3->damage_sprites[v19].sprite->id, 2);
                rge_write(v14, &v3->damage_sprites[v19].damage_percent, 2);
                rge_write(v14, &v3->damage_sprites[v19].flag, 1);
                ++v18;
            }
            while( v18 < v3->damage_sprite_num );
        }
    }
    rge_write(v14, &selected_sound_num, 2);
    rge_write(v14, &death_sound_num, 2);
    rge_write(v14, &v3->attack_reaction, 1);
    rge_write(v14, &v3->convert_terrain_flag, 1);
    if( (_WORD)name_size )
        rge_write(v14, v3->name, (signed short)name_size);
    rge_write(v14, &v3->copy_id, 2);
}

//----- (00453C40) --------------------------------------------------------
char RGE_Master_Static_Object::check_placement(RGE_Player *player, float col, float row, int *obstructionObject, char check_vis, char check_flat, char check_overlay, char construction_radius_flag, char can_be_built_on_flag, short check_objects)
{
    RGE_Master_Static_Object *v11; // ebp@1
    RGE_Game_World *v12; // eax@1
    RGE_Map *v13; // ebx@1
    char v15; // c0@4
    signed __int64 v16; // rax@8
    short v17; // si@8
    int v18; // ebx@10
    signed __int64 v19; // rax@11
    short v20; // cx@11
    char result; // al@13
    RGE_Master_Static_Object *v22; // edx@15
    short v23; // bp@15
    _BYTE *v24; // ecx@19
    int v25; // esi@19
    short v26; // ax@20
    signed int v27; // eax@26
    int v28; // ecx@28
    RGE_Tile **v29; // esi@28
    int v30; // edi@28
    short v31; // ax@29
    signed int v32; // ecx@35
    _BYTE *v33; // ecx@37
    int v34; // esi@37
    short v35; // ax@38
    RGE_Tile **v36; // esi@45
    int v37; // edi@45
    short v38; // ax@46
    short v39; // ax@55
    short v40; // bp@56
    int v41; // edi@57
    int v42; // esi@58
    short v43; // ax@64
    int v44; // esi@82
    signed __int64 v45; // rax@82
    int v46; // edx@93
    int v47; // edi@94
    int v48; // ecx@94
    RGE_Object_Node **v49; // ebp@97
    RGE_Object_Node *v50; // edx@98
    RGE_Static_Object *v51; // ecx@99
    RGE_Master_Static_Object *v52; // eax@103
    double v53; // st7@109
    double v54; // st6@109
    char req_terr2; // [sp+13h] [bp-41h]@15
    RGE_Master_Static_Object *v56; // [sp+14h] [bp-40h]@1
    RGE_Map *map; // [sp+18h] [bp-3Ch]@1
    int x2; // [sp+1Ch] [bp-38h]@8
    int x2a; // [sp+1Ch] [bp-38h]@82
    short edge_y2; // [sp+20h] [bp-34h]@10
    short edge_y1; // [sp+24h] [bp-30h]@10
    float ty2; // [sp+28h] [bp-2Ch]@4
    short ty2a; // [sp+28h] [bp-2Ch]@8
    signed short ty2b; // [sp+28h] [bp-2Ch]@82
    float ty1; // [sp+2Ch] [bp-28h]@4
    signed short ty1a; // [sp+2Ch] [bp-28h]@10
    int x1; // [sp+30h] [bp-24h]@8
    int x1a; // [sp+30h] [bp-24h]@82
    float rx; // [sp+34h] [bp-20h]@2
    float ry; // [sp+38h] [bp-1Ch]@2
    float tx2; // [sp+3Ch] [bp-18h]@4
    float tx2a; // [sp+3Ch] [bp-18h]@8
    signed int v73; // [sp+40h] [bp-14h]@5
    int edge_x1; // [sp+44h] [bp-10h]@10
    signed int v75; // [sp+48h] [bp-Ch]@7
    short req_x1; // [sp+4Ch] [bp-8h]@17
    float *terrain_table; // [sp+50h] [bp-4h]@1
    float check_visa; // [sp+68h] [bp+14h]@103
    float rz2; // [sp+6Ch] [bp+18h]@103
    float construction_radius_flaga; // [sp+74h] [bp+20h]@4
    char construction_radius_flagb; // [sp+74h] [bp+20h]@15
    char construction_radius_flagc; // [sp+74h] [bp+20h]@54
    float construction_radius_flagd; // [sp+74h] [bp+20h]@103
    int check_objectsa; // [sp+7Ch] [bp+28h]@93

    v11 = this;
    v12 = player->world;
    v13 = v12->map;
    v56 = this;
    terrain_table = v12->terrains[this->terrain];
    map = v12->map;
    if( construction_radius_flag )
    {
        rx = this->construction_radius_x;
        ry = this->construction_radius_y;
    }
    else
    {
        rx = this->radius_x;
        ry = this->radius_y;
    }
    construction_radius_flaga = col - rx;
    ty1 = row - ry;
    tx2 = rx + col - 0.001;
    ty2 = ry + row - 0.001;
    if( v15 )
        return 7;
    v73 = v13->map_width;
    if( (double)v73 <= tx2 )
        return 7;
    if( ty1 < 0.0 )
        return 7;
    v75 = v13->map_height;
    if( (double)v75 <= ty2 )
        return 7;
    x1 = (signed __int64)construction_radius_flaga;
    x2 = (signed __int64)tx2;
    LODWORD(tx2a) = (signed __int64)ty1;
    v16 = (signed __int64)ty2;
    v17 = this->center_tile_req1;
    ty2a = v16;
    if( v17 >= 0 || this->center_tile_req2 >= 0 )
    {
        v19 = (signed __int64)col;
        v20 = *((_BYTE *)&v13->map_row_offset[(signed short)(signed __int64)row][(signed short)v19] + 5) & 0x1F;
        if( v20 != v17 && v20 != v11->center_tile_req2 )
            return 1;
        LOWORD(v18) = (signed __int64)col;
        edge_y1 = (signed __int64)row;
        LOWORD(edge_x1) = (signed __int64)col;
        ty1a = (signed __int64)col;
        edge_y2 = (signed __int64)row;
    }
    else
    {
        v18 = (signed __int64)construction_radius_flaga;
        ty1a = x2;
        edge_x1 = (signed __int64)construction_radius_flaga;
        edge_y1 = LOWORD(tx2a);
        edge_y2 = v16;
    }
    v22 = v56;
    construction_radius_flagb = 0;
    req_terr2 = 0;
    v23 = v56->tile_req1;
    if( v23 >= 0 || v56->tile_req2 >= 0 )
    {
        req_x1 = v18 - 1;
        if( (signed short)(edge_y1 - 1) >= 0 && (signed short)v18 <= ty1a )
        {
            v24 = (char *)&map->map_row_offset[(signed short)(edge_y1 - 1)][(signed short)v18] + 5;
            v25 = ty1a - (signed short)v18 + 1;
            do
            {
                v26 = *v24 & 0x1F;
                if( v26 == v23 )
                    construction_radius_flagb = 1;
                if( v26 == v56->tile_req2 )
                    req_terr2 = 1;
                v24 += 24;
                --v25;
            }
            while( v25 );
            v22 = v56;
        }
        v27 = (signed short)(ty1a + 1);
        if( v27 < v73 && edge_y1 <= edge_y2 )
        {
            v28 = v27;
            v29 = &map->map_row_offset[edge_y1];
            v30 = edge_y2 - edge_y1 + 1;
            do
            {
                v31 = *((_BYTE *)&(*v29)[v28] + 5) & 0x1F;
                if( v31 == v23 )
                {
                    LOWORD(v18) = edge_x1;
                    construction_radius_flagb = 1;
                }
                if( v31 == v56->tile_req2 )
                    req_terr2 = 1;
                ++v29;
                --v30;
            }
            while( v30 );
            v22 = v56;
        }
        v32 = (signed short)(edge_y2 + 1);
        if( v32 < v75 && ty1a >= (signed short)v18 )
        {
            v33 = (char *)&map->map_row_offset[v32][ty1a] + 5;
            v34 = ty1a - (signed short)v18 + 1;
            do
            {
                v35 = *v33 & 0x1F;
                if( v35 == v23 )
                    construction_radius_flagb = 1;
                if( v35 == v22->tile_req2 )
                    req_terr2 = 1;
                v33 -= 24;
                --v34;
            }
            while( v34 );
        }
        if( req_x1 >= 0 && edge_y2 >= edge_y1 )
        {
            v36 = &map->map_row_offset[edge_y2];
            v37 = edge_y2 - edge_y1 + 1;
            do
            {
                v38 = *((_BYTE *)&(*v36)[req_x1] + 5) & 0x1F;
                if( v38 == v23 )
                    construction_radius_flagb = 1;
                if( v38 == v56->tile_req2 )
                    req_terr2 = 1;
                --v36;
                --v37;
            }
            while( v37 );
        }
        if( !construction_radius_flagb && !req_terr2 )
            return 1;
    }
    construction_radius_flagc = 0;
    if( (signed short)x1 <= (signed short)x2 )
    {
        v39 = LOWORD(tx2a);
        do
        {
            v40 = v39;
            if( v39 <= ty2a )
            {
                v41 = (signed short)x1;
                while( 1 )
                {
                    v42 = v40;
                    if( terrain_table[*((_BYTE *)&map->map_row_offset[v42][v41] + 5) & 0x1F] <= 0.0 )
                        return 2;
                    if( check_vis
                        && (rge_base_game->prog_mode == 7 || RGE_Visible_Map::get_visible(player->visible, (signed short)x1, v40)) )
                    {
                        construction_radius_flagc = 1;
                    }
                    if( check_flat )
                    {
                        v43 = map->map_row_offset[v42][v41].tile_type;
                        if( v56->elevation_flag == 1 )
                        {
                            if( map->map_row_offset[v42][v41].tile_type && v43 != 5 && v43 != 7 && v43 != 6 && v43 != 8 )
                                return 3;
                        }
                        else if( v56->elevation_flag == 2 && map->map_row_offset[v42][v41].tile_type )
                        {
                            return 3;
                        }
                    }
                    if( ++v40 > ty2a )
                    {
                        v39 = LOWORD(tx2a);
                        break;
                    }
                }
            }
            LOWORD(x1) = x1 + 1;
        }
        while( (signed short)x1 <= (signed short)x2 );
    }
    if( check_vis != 1 || construction_radius_flagc )
    {
        if( rx > 0.0 || ry > 0.0 )
        {
            x1a = (signed __int64)(col - 3.0);
            v44 = (signed __int64)(row - 3.0);
            x2a = (signed __int64)(col - -3.0);
            v45 = (signed __int64)(row - -3.0);
            ty2b = v45;
            if( (signed short)(signed __int64)(col - 3.0) < 0 )
                x1a = 0;
            if( (signed short)(signed __int64)(col - -3.0) >= map->map_width )
                LOWORD(x2a) = LOWORD(map->map_width) - 1;
            if( (signed short)v44 < 0 )
                v44 = 0;
            if( (signed short)v45 >= map->map_height )
                ty2b = LOWORD(map->map_height) - 1;
            if( (_BYTE)check_objects
                && (can_be_built_on_flag || v56->radius_z > 0.0)
                && (v46 = v44, check_objectsa = v44, (signed short)v44 <= ty2b) )
            {
                v47 = x1a;
                v48 = (signed short)x1a;
                while( (signed short)v47 > (signed short)x2a )
                {
LABEL_118:
                    check_objectsa = ++v46;
                    if( (signed short)v46 > ty2b )
                        goto LABEL_119;
                    v47 = x1a;
                }
                v49 = &map->map_row_offset[(signed short)v46][v48].objects.list;
                while( 1 )
                {
                    v50 = *v49;
                    if( *v49 )
                        break;
LABEL_116:
                    v49 += 6;
                    if( (signed short)++v47 > (signed short)x2a )
                    {
                        v46 = check_objectsa;
                        v48 = (signed short)x1a;
                        goto LABEL_118;
                    }
                }
                while( 1 )
                {
                    v51 = v50->node;
                    if( v50->node->object_state < 7u
                        && (!can_be_built_on_flag || v51->master_obj->can_be_built_on != 1 || v56->can_be_built_on) )
                    {
                        v52 = v51->master_obj;
                        construction_radius_flagd = v52->radius_x;
                        rz2 = v52->radius_y;
                        check_visa = v52->radius_z;
                        if( construction_radius_flagd > 0.0
                            && rz2 > 0.0
                            && (check_visa > 0.0 && v56->radius_z > 0.0 || check_visa <= 0.0 && v56->radius_z <= 0.0) )
                        {
                            v53 = v51->world_y - row;
                            v54 = v51->world_x - col;
                            if( v53 < 0.0 )
                                v53 = -v53;
                            if( v54 < 0.0 )
                                v54 = -v54;
                            if( v54 < construction_radius_flagd + rx && v53 < rz2 + ry )
                                break;
                        }
                    }
                    v50 = v50->next;
                    if( !v50 )
                        goto LABEL_116;
                }
                if( obstructionObject )
                    *obstructionObject = v51->id;
                result = 6;
            }
            else
            {
LABEL_119:
                result = 0;
            }
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        result = 5;
    }
    return result;
}

//----- (004543C0) --------------------------------------------------------
void RGE_Master_Static_Object::make_available(char on_off_flag)
{
    this->available = on_off_flag;
}

//----- (004543D0) --------------------------------------------------------
char RGE_Master_Static_Object::alignment(float *col, float *row, RGE_Game_World *world, char center_flag)
{
    float *v5; // esi@1
    RGE_Map *v6; // eax@1
    float *v7; // edi@1
    double v8; // st6@1
    double v10; // st7@1
    char v11; // c0@1
    double v12; // st4@2
    double v13; // st6@2
    double v14; // st5@2
    double v15; // st6@2
    double v16; // st5@4
    double v17; // rtt@5
    double v18; // rt0@5
    double v19; // st4@7
    double v20; // st3@7
    double v21; // st4@7
    char v23; // c0@20
    unsigned __int8 v25; // c0@21
    unsigned __int8 v26; // c3@21
    double v27; // st7@22
    unsigned __int8 v29; // c0@26
    unsigned __int8 v30; // c3@26
    char result; // al@27
    double v32; // st6@27
    double v33; // st7@27
    double v34; // st6@28
    double v35; // st7@28
    double v36; // st6@29
    double v37; // st7@29
    float map_w; // [sp+8h] [bp-8h]@1
    float map_h; // [sp+Ch] [bp-4h]@1
    float *cola; // [sp+14h] [bp+4h]@1
    float *colb; // [sp+14h] [bp+4h]@10
    float *colc; // [sp+14h] [bp+4h]@22
    float dx1; // [sp+18h] [bp+8h]@1
    float dx1a; // [sp+18h] [bp+8h]@20
    float dy1; // [sp+1Ch] [bp+Ch]@1
    float dy1a; // [sp+1Ch] [bp+Ch]@23
    float dx2; // [sp+20h] [bp+10h]@20

    v5 = col;
    v6 = world->map;
    v7 = row;
    *(float *)&cola = *col - this->radius_x;
    v8 = *row + this->radius_y;
    dx1 = *row - this->radius_y;
    dy1 = *v5 + this->radius_x;
    map_w = (double)v6->map_width - 0.0000099999997;
    v10 = v8;
    map_h = (double)v6->map_height - 0.0000099999997;
    if( v11 )
    {
        v12 = dy1 - *(float *)&cola;
        v13 = *v5 - *(float *)&cola;
        *(float *)&cola = 0.0;
        v14 = v13;
        v15 = v12;
        *v5 = v14;
    }
    else
    {
        v15 = dy1;
    }
    v16 = dx1;
    if( dx1 < 0.0 )
    {
        v17 = -v16;
        v18 = v10 - v16;
        v16 = 0.0;
        v10 = v18;
        *v7 = *v7 + v17;
    }
    if( v15 < map_w )
    {
        v21 = *(float *)&cola;
    }
    else
    {
        v19 = map_w - v15;
        v20 = *v5 + v19;
        v15 = map_w;
        v21 = *(float *)&cola + v19;
        *v5 = v20;
    }
    if( v10 >= map_h )
    {
        *(float *)&colb = map_h - v10;
        v16 = v16 + *(float *)&colb;
        v10 = map_h;
        *v7 = *v7 + *(float *)&colb;
    }
    if( center_flag )
    {
        if( v21 < 0.0 )
            v21 = -v21;
        if( v16 < 0.0 )
            v16 = -v16;
        if( v15 < 0.0 )
            v15 = -v15;
        if( v10 < 0.0 )
            v10 = -v10;
        dx1a = v16 - (double)(signed short)(signed __int64)v16;
        dx2 = 1.0 - (v10 - (double)(signed short)(signed __int64)v10);
        if( v23 )
        {
            v27 = *v5;
        }
        else if( v25 | v26 )
        {
            dy1a = 1.0 - (v15 - (double)(signed short)(signed __int64)v15);
            v27 = *v5 - (1.0 - dy1a);
        }
        else
        {
            *(float *)&colc = v21 - (double)(signed short)(signed __int64)v21;
            v27 = 1.0 - *(float *)&colc + *v5;
        }
        if( dx2 + dx1a < 1.0 )
        {
            v36 = v27;
            v37 = *v7;
            *v5 = v36;
            result = 1;
            *v7 = v37;
        }
        else if( v29 | v30 )
        {
            result = 1;
            v34 = v27;
            v35 = *v7 - (1.0 - dx2);
            *v5 = v34;
            *v7 = *(float *)&v35;
        }
        else
        {
            result = 1;
            v32 = v27;
            v33 = 1.0 - dx1a + *v7;
            *v5 = v32;
            *v7 = *(float *)&v33;
        }
    }
    else
    {
        result = 1;
    }
    return result;
}

//----- (00454690) --------------------------------------------------------
char RGE_Master_Static_Object::alignment_box(RGE_Game_World *world, float col, float row, short *x1, short *y1, short *x2, short *y2, short *x3, short *y3, short *x4, short *y4)
{
    RGE_Master_Static_Object *v12; // esi@1
    float tx; // ST08_4@1
    RGE_Map *v14; // eax@1
    short v15; // di@1
    double v16; // st6@1
    double v17; // st7@1
    signed __int64 v18; // rax@1
    double v19; // st6@1
    double v20; // ST0C_8@1
    double v21; // st5@1
    double v22; // st4@1
    double v23; // st3@1
    double v24; // st2@1
    double v25; // st4@1
    float cola; // [sp+14h] [bp+8h]@1

    v12 = this;
    tx = col - (double)(signed short)(signed __int64)col + this->radius_x;
    v14 = world->map;
    v15 = v14->tile_half_height;
    v16 = row - (double)(signed short)(signed __int64)row + this->radius_y;
    v17 = (double)v14->tile_half_width;
    cola = v16;
    v18 = (signed __int64)((v16 + tx) * v17);
    v19 = (double)v15;
    v20 = cola - -1.0;
    *x1 = v18;
    *y1 = (signed __int64)((v20 - tx) * v19);
    v21 = tx - (v12->radius_x + v12->radius_x);
    *x2 = (signed __int64)((cola + v21) * v17);
    *y2 = (signed __int64)((v20 - v21) * v19);
    v22 = cola - (v12->radius_y + v12->radius_y);
    v23 = v22 - -1.0;
    *x3 = (signed __int64)((v22 + v21) * v17);
    *y3 = (signed __int64)((v22 - -1.0 - v21) * v19);
    v24 = v22;
    v25 = v12->radius_x + v12->radius_x + v21;
    *x4 = (signed __int64)((v24 + v25) * v17);
    *y4 = (signed __int64)((v23 - v25) * v19);
    return 1;
}

//----- (004547F0) --------------------------------------------------------
void RGE_Master_Static_Object::draw(TDrawArea *render_area, short x, short y, RGE_Color_Table *player_color, int facet, int frame, int draw_frame, char frame_color)
{
    RGE_Sprite *v9; // ecx@1
    short v10; // di@2
    short v11; // bx@2
    int v12; // ebp@2
    float v13; // edx@3
    RGE_Map *v14; // esi@3
    short x1; // [sp+Eh] [bp-Eh]@3
    float rx1; // [sp+10h] [bp-Ch]@3
    float ry1; // [sp+14h] [bp-8h]@3
    float ya; // [sp+18h] [bp-4h]@1

    ya = *(float *)&this;
    v9 = this->sprite;
    if( v9 )
    {
        v10 = y;
        v11 = x;
        v12 = y;
        RGE_Sprite::draw(v9, facet, frame, x, y, x, y, player_color, render_area, 10);
        if( draw_frame )
        {
            v13 = *(float *)(LODWORD(ya) + 172);
            v14 = rge_base_game->world->map;
            ry1 = *(float *)(LODWORD(ya) + 176);
            ya = -ry1;
            rx1 = v13;
            RGE_Map::get_point(v14, &x1, (short *)&draw_frame, v13, ya, 0.0, v11, v10);
            RGE_Map::get_point(v14, (short *)&facet, (short *)&frame, rx1, ry1, 0.0, v11, v10);
            rx1 = -rx1;
            RGE_Map::get_point(v14, (short *)&player_color, (short *)&render_area, rx1, ry1, 0.0, v11, v10);
            RGE_Map::get_point(v14, &x, &y, rx1, ya, 0.0, v11, v10);
            DClipInfo_List::AddGDINode(
                SDI_List,
                1,
                v12,
                x1,
                (signed short)draw_frame,
                (signed short)facet,
                (signed short)frame,
                (signed short)player_color,
                (signed short)render_area,
                x,
                y,
                10,
                (unsigned __int8)frame_color,
                SDI_Object_ID);
        }
    }
}

//----- (00454950) --------------------------------------------------------
int RGE_Master_Static_Object::get_help_message()
{
    return this->help_string_id;
}

//----- (00454960) --------------------------------------------------------
int RGE_Master_Static_Object::get_help_page()
{
    return this->help_page_id;
}

//----- (00454970) --------------------------------------------------------
int RGE_Master_Static_Object::get_hotkey()
{
    return this->hotkey_id;
}

//----- (00454980) --------------------------------------------------------
signed __int64 __stdcall RGE_Master_Static_Object::calc_base_damage_ability(RGE_Master_Combat_Object *attacker)
{
    double v2; // st7@1
    int v3; // edx@1
    char *v4; // ecx@2
    double v5; // st6@3

    v2 = 0.0;
    v3 = attacker->weapon_num;
    if( v3 > 0 )
    {
        v4 = (char *)&attacker->weapon->value;
        do
        {
            v5 = (double)*(_WORD *)v4;
            if( v5 > 0.0 )
                v2 = v2 + v5;
            v4 += 4;
            --v3;
        }
        while( v3 );
    }
    if( v2 < 1.0 )
        v2 = 1.0;
    return (signed __int64)v2;
}
