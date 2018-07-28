
/**
 * @file    Engine\RGE\StaticObject.cpp
 * @author  Yvan Burrie
 * @date    2018/07/08
 * @version 1.0
 */

RGE_Static_Object::RGE_Static_Object(
    RGE_Master_Static_Object *tobj,
    RGE_Player *obj_owner,
    float x,
    float y,
    float z,
    bool do_setup)
{
    if( do_setup ){
        this->setup(
            tobj,
            obj_owner,
            x,
            y,
            z);
    }
}

RGE_Static_Object::RGE_Static_Object(
    int infile,
    RGE_Game_World *gworld,
    bool do_setup)
{
    if( do_setup ){
        this->setup(
            infile,
            gworld);
    }
}

RGE_Static_Object::~RGE_Static_Object()
{
    this->remove_visible_resource();

    if( this->owner ){

        if( this->object_state < RGE_Static_Object::State::Dying ){
            this->take_attribute_from_owner();
        }

        if( this->object_state < RGE_Static_Object::State::Unk7 ){
            this->owner->victory_conditions->update_for_object(this);
        }
    }

    if( this->sprite_list ){
        delete this->sprite_list;
        this->sprite_list = nullptr;
    }

    if( this->owner ){

        if( this->selected & 1 ){
            this->owner->unselect_one_object(this);
        }

        this->owner->removeObject(
            this->sleep_flag,
            this->dopple_flag,
            this->player_object_node);

        this->owner = nullptr;
    }

    if( this->tile ){
        this->tile->remove_node(this, 0);
        this->tile = nullptr;
    }

    if( this->master_obj &&
        this->master_obj->radius_z > 0.0 ){
        this->removeFromObstructionMap(2);
    }

    if( this->inside_obj ){
        this->inside_obj->remove_node(this, 0);
        this->inside_obj = nullptr;
    }

    if( this->objects ){
        RGE_Object_Node *obj_node = this->objects->list;
        if( obj_node ){
            RGE_Static_Object *obj = obj_node->node;
            while( obj ){
                obj->exit_obj();
                obj = obj_node->next;
            }
        }
        if( this->objects ){
            delete this->objects;
        }
    }

    if( this->unitAIValue ){
        delete this->unitAIValue;
        this->unitAIValue = nullptr;
    }

    if( this->groupMembers.value ){
        delete this->groupMembers.value;
        this->groupMembers.value = nullptr;
    }

    this->groupMembers.numberValue        = 0;
    this->groupMembers.desiredNumberValue = 0;
    this->groupMembers.maximumSizeValue   = 0;

    if( this->pathingGroupMembers.value ){
        delete this->pathingGroupMembers.value;
        this->pathingGroupMembers.value = nullptr;
    }

    this->pathingGroupMembers.numberValue        = 0;
    this->pathingGroupMembers.desiredNumberValue = 0;
    this->pathingGroupMembers.maximumSizeValue   = 0;
}

void RGE_Static_Object::recycle_in_to_game(
    RGE_Master_Static_Object *tobj,
    RGE_Player *obj_owner,
    float x,
    float y,
    float z)
{
    this->type                = RGE_STATIC_OBJECT_TYPE;
    this->old_sprite          = nullptr;
    this->unitAIValue         = nullptr;
    this->underAttackValue    = false;
    this->sprite              = nullptr;
    this->groupCommanderValue = -1;
    this->groupRangeValue     = 5.0;
    this->owner               = obj_owner;
    this->master_obj          = tobj;
    this->tile                = nullptr;
    this->inside_obj          = nullptr;
    this->hp                  = (double)tobj->hp;
    this->sleep_flag          = this->hp > 0.0;
    this->dopple_flag         = tobj->master_type == RGE_DOPPLEGANGER_OBJECT_TYPE;
    this->facet               = 0;
    this->screen_x_offset     = 0;
    this->screen_y_offset     = 0;
    this->shadow_x_offset     = 0;
    this->shadow_y_offset     = 0;
    this->selected            = false;
    this->selected_group      = 0;
    this->worker_num          = 0;
    this->object_state        = RGE_Static_Object::State::Alive;
    this->curr_damage_percent = 0;
    this->goto_sleep_flag     = 0;
    this->player_object_node  = nullptr;
    this->world_x             = x;
    this->world_z             = z;
    this->world_y             = y;

    this->get_starting_attribute();
    this->give_attribute_to_owner();

    this->new_sprite(this->master_obj->sprite);

    this->old_sprite = nullptr;

    this->teleport(x, y, z);

    this->player_object_node = this->owner->addObject(
        this->sleep_flag,
        this->dopple_flag);

    if( this->master_obj->created_sound &&
        this->owner->id == this->owner->world->curr_player ){
        this->master_obj->created_sound->play(true);
    }
}

void RGE_Static_Object::recycle_out_of_game()
{
    if( this->master_obj->recyclable &&
        this->owner->world->recycle_object_out_of_game(this->master_obj->master_type, this) ){

        if( this->object_state < 3u ){
            this->take_attribute_from_owner();
        }

        if( this->object_state < 7u ){
            this->owner->victory_conditions->update_for_object(this);
        }

        if( this->sprite_list ){
            this->sprite_list->delete_list();
        }

        if( this->owner ){

            if( this->selected & 1 ){
                this->owner->unselect_one_object(this);
            }

            this->owner->removeObject)(
                this->sleep_flag,
                this->dopple_flag,
                this->player_object_node);

            this->owner = nullptr;
        }

        if( this->tile )
            this->objects->remove_node(this->tile, this, (RGE_Object_Node)nullptr);
            this->tile = nullptr;
        }

        if( this->inside_obj ){
            this->inside_obj->remove_node(this, 0);
            this->inside_obj = nullptr;
        }

        if( this->objects ){
            RGE_Object_Node *obj_node = this->objects->list;
            if( obj_node ){
                RGE_Static_Object *obj = obj_node->node;
                while( obj ){
                    obj->exit_obj();
                    obj = obj_node->next;
                }
            }
            if( this->objects ){
                delete this->objects;
            }
        }

        if( this->unitAIValue ){
            delete this->unitAIValue;
            this->unitAIValue = nullptr;
        }

        if( this->master_obj &&
            this->master_obj->radius_z > 0.0 ){
            this->removeFromObstructionMap(2);
        }
        this->master_obj = nullptr;

    }else if( this ){
        delete this;
    }
}

bool RGE_Static_Object::setup(
    RGE_Master_Static_Object *tobj,
    RGE_Player *obj_owner,
    float x,
    float y,
    float z)
{
    this->master_obj          = tobj;
    this->type                = RGE_STATIC_OBJECT_TYPE;
    this->owner               = obj_owner;
    this->tile                = nullptr;
    this->inside_obj          = nullptr;
    this->objects             = this->create_object_list();
    this->hp                  = (double)this->master_obj->hp;
    this->sleep_flag          = this->hp > 0.0;
    this->dopple_flag         = this->master_obj->master_type == RGE_DOPPLEGANGER_OBJECT_TYPE;
    this->facet               = 0;
    this->screen_x_offset     = 0;
    this->screen_y_offset     = 0;
    this->shadow_x_offset     = 0;
    this->shadow_y_offset     = 0;
    this->selected            = false;
    this->selected_group      = 0;
    this->worker_num          = 0;
    this->object_state        = RGE_Static_Object::State::Alive;
    this->curr_damage_percent = 0;
    this->goto_sleep_flag     = 0;
    this->world_x             = x;
    this->world_z             = z;
    this->world_y             = y;

    this->get_starting_attribute();
    this->give_attribute_to_owner();

    if( this->master_obj->recyclable ){
        this->id = this->owner->world->get_next_reusable_object_id();
    }else{
        this->id = this->owner->world->get_next_object_id();
    }

    this->sprite_list = this->create_sprite_list();

    this->new_sprite(this->master_obj->sprite);

    this->old_sprite = nullptr;

    this->teleport(x, y, z);

    this->player_object_node = this->owner->addObject(this->sleep_flag, this->dopple_flag);

    if( this->master_obj->created_sound &&
        this->owner->id == this->owner->world->curr_player ){
        this->master_obj->created_sound->play(true);
    }

    return true;
}

bool RGE_Static_Object::setup(
    int infile,
    RGE_Game_World *gworld)
{
    int temp_int;
    int temp_float;

    int player_id;
    rge_read(infile, &player_id, 1);
    this->owner = gworld->players[player_id];

    short master_id;
    rge_read(infile, &master_id, 2);
    this->master_obj = this->owner->master_objects[master_id];

    short sprite_id;
    rge_read(infile, &sprite_id, 2);
    if( sprite_id >= 0 ){
        this->sprite = gworld->sprites[sprite_id];
    }else{
        this->sprite = nullptr;
    }
    this->old_sprite = nullptr;

    int long_val;
    rge_read(infile, &long_val, 4);
    if( long_val != -1 ){
        this->inside_obj = (RGE_Static_Object *)long_val;
    }else{
        this->inside_obj = nullptr;
    }

    rge_read(infile, &this->hp, 4);

    rge_read(infile, &this->object_state, 1);

    rge_read(infile, &this->sleep_flag, 1);

#if RGE_DOPPLEGANGER_SYSTEM_EXISTS
    if( save_game_version >= 7.09 ){
        rge_read(infile, &this->dopple_flag, 1);
    }
#endif

    rge_read(infile, &this->goto_sleep_flag, 1);

    rge_read(infile, &this->id, 4);

    rge_read(infile, &this->facet, 1);

    rge_read(infile, &this->world_x, 4);
    rge_read(infile, &this->world_y, 4);
    rge_read(infile, &this->world_z, 4);

    rge_read(infile, &this->screen_x_offset, 2);
    rge_read(infile, &this->screen_y_offset, 2);
    rge_read(infile, &this->shadow_x_offset, 2);
    rge_read(infile, &this->shadow_y_offset, 2);

    rge_read(infile, &this->selected_group, 1);

    rge_read(infile, &this->attribute_type_held, 2);
    rge_read(infile, &this->attribute_amount_held, 4);

#if RGE_STATIC_OBJECT_WORKER_NUM_LONG_CAST
    rge_read(infile, &this->worker_num, 4);
#else
    rge_read(infile, &this->worker_num, 1);
#endif

    rge_read(infile, &this->curr_damage_percent, 1);
    rge_read(infile, &this->underAttackValue, 1);

    this->tile = nullptr;

#if RGE_STATIC_OBJECT_GROUP_INFO_PARSED
    rge_read(infile, &this->groupCommanderValue, 4);
    rge_read(infile, &this->groupRangeValue, 4);
#else
    if( save_game_version < 10.85 ){
        rge_read(infile, &temp_int, 4);
        rge_read(infile, &temp_int, 4);
    }
#endif

    /* God knows what the hell this was: */
    if( save_game_version == 6.99 ){
        rge_read(infile, &temp_float, 4);
        rge_read(infile, &temp_float, 4);
        rge_read(infile, &temp_float, 4);
        rge_read(infile, &temp_int, 4);
        rge_read(infile, &temp_int, 4);
        rge_read(infile, &temp_int, 4);
    }

    rge_read(infile, &numberUnits, 4);

    if( numberUnits > 0 )
    {
        do
        {
            rge_read((int)v8, v4, v4, &tempInt, 4);
            v9 = this->groupMembers.numberValue;
            v10 = 0;
            for( temp_int = tempInt; v10 < v9; ++v10 )
            {
                if( v10 >= this->groupMembers.maximumSizeValue )
                    break;
                v8 = this->groupMembers.value;
                if( v8[v10] == tempInt )
                    goto LABEL_23;
            }
            if( v9 > this->groupMembers.maximumSizeValue - 1 )
            {
                v11 = v9 + 1;
                v8 = (int *)operator new(4 * (v9 + 1));
                if( v8 )
                {
                    for( i = 0; i < this->groupMembers.maximumSizeValue; v8[i - 1] = this->groupMembers.value[i - 1] )
                    {
                        if( i >= v11 )
                            break;
                        ++i;
                    }
                    operator delete(this->groupMembers.value);
                    this->groupMembers.value = v8;
                    this->groupMembers.maximumSizeValue = v11;
                }
            }
            this->groupMembers.value[this->groupMembers.numberValue++] = temp_int;
LABEL_23:
            ++LODWORD(temp_float);
        }
        while( SLODWORD(temp_float) < numberUnits );
    }
    rge_read((int)v8, v4, v4, &numberUnits, 4);
    temp_float = 0.0;
    if( numberUnits > 0 )
    {
        do
        {
            rge_read((int)v8, v4, v4, &temp_int, 4);
            v13 = this->pathingGroupMembers.numberValue;
            v14 = 0;
            for( tempInt = temp_int; v14 < v13; ++v14 )
            {
                if( v14 >= this->pathingGroupMembers.maximumSizeValue )
                    break;
                v8 = this->pathingGroupMembers.value;
                if( v8[v14] == temp_int )
                    goto LABEL_36;
            }
            if( v13 > this->pathingGroupMembers.maximumSizeValue - 1 )
            {
                v15 = v13 + 1;
                v8 = (int *)operator new(4 * (v13 + 1));
                if( v8 )
                {
                    for( j = 0; j < this->pathingGroupMembers.maximumSizeValue; v8[j - 1] = this->pathingGroupMembers.value[j - 1] )
                    {
                        if( j >= v15 )
                            break;
                        ++j;
                    }
                    operator delete(this->pathingGroupMembers.value);
                    this->pathingGroupMembers.value = v8;
                    this->pathingGroupMembers.maximumSizeValue = v15;
                }
            }
            this->pathingGroupMembers.value[this->pathingGroupMembers.numberValue++] = tempInt;
LABEL_36:
            ++LODWORD(temp_float);
        }
        while( SLODWORD(temp_float) < numberUnits );
    }

    if( save_game_version >= 9.11 &&
        save_game_version <= 9.62 ){
        rge_read(infile, &temp_int, 4);// (unknown group related unit ID, deprecated)
    }

    if( save_game_version >= 9.66 ){
        rge_read(infile, &this->group_id, 4);
    }

#if RGE_STATIC_OBJECT_ALREADY_COLLIDED_EXISTS
    /* read already-collided: */
    if( save_game_version >= 11.33 ){
        this->alreadyCollided = 0;
    }else{
        rge_read(infile, &this->alreadyCollided, 1);
    }
#endif

    /* read active-sprites: */
    bool active_sprites_parsed = true;
#if RGE_STATIC_OBJECT_ACTIVE_SPRITES_FLAG_PARSED
    if( save_game_version >= 11.11 ){
        rge_read(infile, &active_sprites_parsed, 1);
    }
#endif
    if( active_sprites_parsed ){
        this->sprite_list = this->create_sprite_list();
        this->sprite_list->load(infile, gworld->sprites);
    }else{
        this->sprite_list = nullptr;
    }

    /* add the object into the world: */
    this->owner->world->addObject(this);

    /* add the object as a node into whichever list appropriate: */
    switch( true ){

    case this->sleep_flag != 0:
        this->owner->sleeping_objects->add_node(this);
        break;

#if RGE_DOPPLEGANGER_SYSTEM_EXISTS
    case this->dopple_flag != 0:
        this->owner->doppleganger_objects->add_node(this);
        break;
#endif

    default:
        this->owner->objects->add_node(this);
        break;
    }

    this->objects = this->create_object_list();

    /* make sure the object is not selected: */
    this->selected = false;

    return true;
}

double RGE_Static_Object::getSpeed()
{
    return 0.0;
}

void RGE_Static_Object::change_unique_id()
{
    this->owner->removeObject(
        this->sleep_flag,
        this->dopple_flag,
        this->player_object_node);

    if( this->master_obj->recyclable ){
        this->id = this->owner->world->get_next_reusable_object_id();
    }else{
        this->id = this->owner->world->get_next_object_id();
    }
    this->player_object_node = this->owner->addObject(this->sleep_flag, this->dopple_flag);
}

RGE_Object_List *RGE_Static_Object::create_object_list()
{
    return new RGE_Object_List;
}

RGE_Active_Sprite_List *RGE_Static_Object::create_sprite_list()
{
    return new RGE_Active_Sprite_List(this);
}

void RGE_Static_Object::get_starting_attribute()
{
    RGE_Master_Static_Object *v1; // eax@1
    char *v2; // edi@1
    float *v3; // esi@1
    short *v4; // edx@1
    signed int v5; // ebx@1

    v1 = this->master_obj;
    this->attribute_type_held = -1;
    LODWORD(this->attribute_amount_held) = 0;
    v2 = v1->attribute_flag;
    v3 = v1->attribute_amount_held;
    v4 = v1->attribute_type_held;
    v5 = 3;
    do
    {
        if( !*v2 && *v4 != -1 )
        {
            this->attribute_type_held = *v4;
            this->attribute_amount_held = *v3;
        }
        ++v4;
        ++v3;
        ++v2;
        --v5;
    }
    while( v5 );
}

void RGE_Static_Object::give_attribute_to_owner()
{
    RGE_Static_Object *v1; // ebx@1
    int v2; // edi@1
    signed int v3; // esi@1
    RGE_Master_Static_Object *v4; // eax@2
    char v5; // cl@2
    short v6; // dx@4
    signed int v7; // [sp+10h] [bp-4h]@1

    v1 = this;
    v2 = 0;
    v7 = 106;
    v3 = 112;
    do
    {
        v4 = v1->master_obj;
        v5 = v4->attribute_flag[v2];
        if( (unsigned __int8)v5 >= 1u && (unsigned __int8)v5 <= 2u )
        {
            v6 = *(_WORD *)((char *)&v4->vfptr + v7);
            if( v6 >= 0 )
                ((void (__stdcall *)(short, _DWORD, _DWORD))v1->owner->vfptr->add_attribute_num)(
                    v6,
                    *(RGE_Master_Static_ObjectVtbl **)((char *)&v4->vfptr + v3),
                    0);
        }
        v3 += 4;
        ++v2;
        v7 += 2;
    }
    while( v3 < 124 );
}

void RGE_Static_Object::take_attribute_from_owner()
{
    int v1; // edi@1
    signed int v2; // ebp@1
    signed int v3; // esi@1
    RGE_Master_Static_Object *v4; // eax@2
    short v5; // dx@3
    float v6; // ST04_4@4
    RGE_Static_Object *v7; // [sp+18h] [bp-4h]@1

    v7 = this;
    v1 = 0;
    v2 = 106;
    v3 = 112;
    do
    {
        v4 = this->master_obj;
        if( v4->attribute_flag[v1] == 2 )
        {
            v5 = *(_WORD *)((char *)&v4->vfptr + v2);
            if( v5 >= 0 )
            {
                v6 = -*(float *)((char *)&v4->vfptr + v3);
                this->owner->add_attribute_num(v6, 0);
                this = v7;
            }
        }
        v3 += 4;
        ++v1;
        v2 += 2;
    }
    while( v3 < 124 );
}

void RGE_Static_Object::draw(TDrawArea *render_area, short x, short y, RGE_Color_Table *draw_color)
{
    RGE_Static_Object *v5; // esi@1
    int v6; // eax@3
    int v7; // eax@13
    int v8; // ST10_4@13
    int v9; // ST0C_4@13
    int v10; // ST08_4@13
    int v11; // ST04_4@13

    v5 = this;
    SDI_Object_ID = this->id;
    if( this->type == 25 )
    {
        if( (1 << LOBYTE(this->owner->world->curr_player)) & (unsigned int)this[1].tile )
            goto sod_exit;
        v6 = this[1].id;
        if( v6 )
            SDI_Object_ID = *(_DWORD *)(v6 + 4);
        else
            SDI_Object_ID = -1;
    }
    if( this->tile && this->object_state < 7u )
    {
        if( this->selected
            || rge_base_game->outline_type == 3
            || (this->master_obj->draw_flag & 1) == 1 && rge_base_game->prog_mode == 7 )
        {
            RGE_Static_Object::capture_frame(this, render_area, x, y);
        }
        SDI_Draw_Line = v5->shadow_y_offset + y;
        HIWORD(v7) = HIWORD(draw_color);
        LOWORD(v7) = v5->shadow_y_offset + y;
        v8 = v7;
        LOWORD(v7) = x + v5->shadow_x_offset;
        v9 = v7;
        LOWORD(v7) = y + v5->screen_y_offset;
        v10 = v7;
        LOWORD(v7) = x + v5->screen_x_offset;
        v11 = v7;
        LOWORD(v7) = v5->facet;
        ((void (__stdcall *)(int, int, int, int, int, RGE_Color_Table *, TDrawArea *))v5->sprite_list->vfptr->draw)(
            v7,
            v11,
            v10,
            v9,
            v8,
            draw_color,
            render_area);
    }
sod_exit:
    SDI_Object_ID = -1;
}

void RGE_Static_Object::shadow_draw(TDrawArea *render_area, short x, short y, int flag)
{
    int v5; // eax@1
    RGE_Color_Table *v6; // esi@3
    RGE_Color_Table *v7; // ST08_4@3

    HIWORD(v5) = HIWORD(this);
    if( this->tile )
    {
        if( this->object_state < 7u )
        {
            v6 = this->owner->color_table;
            LOWORD(v6) = y + this->shadow_y_offset;
            v7 = v6;
            LOWORD(v6) = x + this->shadow_x_offset;
            LOWORD(v5) = this->facet;
            ((void (__stdcall *)(int, RGE_Color_Table *, RGE_Color_Table *, RGE_Color_Table *, TDrawArea *, int))this->sprite_list->vfptr->shadow_draw)(
                v5,
                v6,
                v7,
                this->owner->color_table,
                render_area,
                flag);
        }
    }
}

void RGE_Static_Object::normal_draw(TDrawArea *render_area, int x, int y)
{
    RGE_Static_Object *v4; // esi@1
    bool v5; // bl@5
    RGE_Color_Table *v6; // eax@9
    RGE_Color_Table *v7; // ST08_4@9
    RGE_Color_Table *v8; // ST04_4@9

    v4 = this;
    if( this->tile && this->object_state < 7u )
    {
        v5 = this->selected || rge_base_game->outline_type == 3;
        if( v5 )
            (*(void (__stdcall **)(TDrawArea *, _DWORD, _DWORD))&this->vfptr->gap4[24])(render_area, x, y);
        v6 = v4->owner->color_table;
        LOWORD(v6) = y + v4->screen_y_offset;
        v7 = v6;
        LOWORD(v6) = x + v4->screen_x_offset;
        v8 = v6;
        LOWORD(v6) = v4->facet;
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, TDrawArea *))v4->sprite_list->vfptr->normal_draw)(
            v6,
            v8,
            v7,
            v4->owner->color_table,
            render_area);
        if( v5 )
            (*(void (**)(RGE_Static_Object *, TDrawArea *, _DWORD, _DWORD))&v4->vfptr->gap4[20])(
                v4,
                render_area,
                x,
                y);
    }
}

void RGE_Static_Object::draw_front_frame(TDrawArea *render_area, int x, int y)
{
    if( rge_base_game->game_mode == 1 ){
        this->draw_frame_3d_cube_front(render_area, x, y);
    }else{
        switch( rge_base_game->outline_type ){

        case 0:
            this->vfptr->gap4[28](render_area, x, y);
            break;

        case 1:
            this->draw_frame_3d_cube_front(render_area, x, y);
            break;

        case 2:
        case 3:
            this->draw_frame_3d_square_front(render_area, x, y);
            break;

        default:
            return;
        }
    }
}

void RGE_Static_Object::draw_back_frame(TDrawArea *render_area, short x, short y)
{
    if( rge_base_game->game_mode == 1 ){
        this->draw_frame_3d_cube_back(render_area, x, y);
    }else{
        switch( rge_base_game->outline_type ){

        case 1:
            this->draw_frame_3d_cube_back(render_area, x, y);
            break;

        case 2:
        case 3:
            this->draw_frame_3d_square_back(render_area, x, y);
            break;

        default:
            return;
        }
    }
}

void RGE_Static_Object::capture_frame(TDrawArea *render_area, short x, short y)
{
    if( SDI_Capture_Info ){
        if( rge_base_game->game_mode == 1 ){
            RGE_Static_Object::capture_frame_3d_cube(this, render_area, x, y);
        }else{
            switch( rge_base_game->outline_type ){

            case 0:
                RGE_Static_Object::capture_square_frame(this, render_area, x, y);
                break;

            case 1:
                RGE_Static_Object::capture_frame_3d_cube(this, render_area, x, y);
                break;

            case 2:
            case 3:
                RGE_Static_Object::capture_frame_3d_square(this, render_area, x, y);
                break;

            default:
                return;
            }
        }
    }
}

void RGE_Static_Object::capture_square_frame(TDrawArea *render_area, short x, short y)
{
    RGE_Static_Object *v4; // esi@1
    RGE_Sprite *v5; // eax@1
    RGE_Active_Sprite_List *v6; // ecx@2
    int v7; // ecx@4
    int v8; // ebx@4
    int v9; // edi@4
    int v10; // ST10_4@4
    signed __int64 v11; // rax@5
    signed int v12; // ebp@7
    int v13; // edi@8
    int v14; // eax@8
    short min_x; // [sp+10h] [bp-8h]@3
    short min_y; // [sp+12h] [bp-6h]@3
    short max_y; // [sp+14h] [bp-4h]@3
    short max_x; // [sp+16h] [bp-2h]@3
    int xa; // [sp+20h] [bp+8h]@4

    v4 = this;
    v5 = this->sprite;
    if( v5 )
    {
        v6 = this->sprite_list;
        if( v6 )
        {
            ((void (__stdcall *)(RGE_Sprite *, _WORD))v6->vfptr->get_facetindex)(v5, v4->facet);
            if( RGE_Static_Object::get_frame(v4, &min_x, &min_y, &max_x, &max_y) )
            {
                v7 = v4->screen_x_offset;
                v8 = x + min_x + v7 - 1;
                v9 = y + min_y + v4->screen_y_offset - 1;
                v10 = x + max_x + v7 + 1;
                xa = y + max_y + v4->screen_y_offset + 1;
                DClipInfo_List::AddGDINode(SDI_List, 4, xa, v8, v9, v10, xa, 0, 0, 0, 0, 10, 255, SDI_Object_ID);
                if( v4->object_state <= 2u )
                {
                    v11 = (signed __int64)v4->hp;
                    if( (signed int)v11 < 1 )
                        LODWORD(v11) = 0;
                    v12 = v4->master_obj->hp;
                    if( v12 > 0 )
                    {
                        v13 = v9 - 6;
                        v14 = v8 + 25 * (signed int)v11 / v12;
                        if( v14 >= v8 + 26 )
                            v14 = v8 + 25;
                        DClipInfo_List::AddGDINode(
                            SDI_List,
                            2,
                            xa,
                            v8,
                            v13,
                            v8 + 26,
                            v13 + 5,
                            v14,
                            0,
                            v14 + 1,
                            0,
                            20,
                            255,
                            SDI_Object_ID);
                    }
                }
            }
        }
    }
}

void RGE_Static_Object::capture_frame_3d_square(TDrawArea *render_area, short x, short y)
{
    RGE_Static_Object *v4; // ebp@1
    char v5; // dl@1
    RGE_Game_World *v6; // ecx@1
    RGE_Master_Static_Object *v7; // eax@1
    RGE_Map *v8; // ebx@1
    int v9; // ecx@2
    int v10; // ecx@5
    char v11; // al@15
    short v12; // dx@19
    short v13; // cx@19
    short v14; // si@19
    short v15; // di@19
    int v16; // ebx@19
    char v17; // al@20
    TShape **v18; // eax@23
    float v19; // edx@28
    RGE_Master_Static_Object *v20; // ecx@30
    int v21; // eax@30
    int v22; // ecx@31
    int v23; // esi@31
    int v24; // eax@32
    int v25; // edx@32
    TShape **v26; // eax@41
    signed int v27; // ebp@41
    signed int v28; // ecx@41
    signed int v29; // esi@43
    signed int v30; // ecx@43
    signed int v31; // ecx@43
    signed int v32; // ecx@43
    int *v33; // ebp@54
    int v34; // edi@54
    int v35; // eax@55
    short v36; // dx@55
    bool v37; // zf@55
    char draw_color; // [sp+10h] [bp-54h]@7
    int y2; // [sp+14h] [bp-50h]@19
    float rx1; // [sp+18h] [bp-4Ch]@2
    int x3; // [sp+1Ch] [bp-48h]@19
    int x4; // [sp+20h] [bp-44h]@19
    int y3; // [sp+24h] [bp-40h]@19
    float ry1; // [sp+28h] [bp-3Ch]@2
    float ya; // [sp+2Ch] [bp-38h]@19
    int y1; // [sp+30h] [bp-34h]@19
    float v47; // [sp+34h] [bp-30h]@19
    int tot_hp; // [sp+38h] [bp-2Ch]@4
    int x1; // [sp+3Ch] [bp-28h]@19
    TShape *group_num_shape; // [sp+40h] [bp-24h]@1
    int x0; // [sp+44h] [bp-20h]@28
    int y0; // [sp+48h] [bp-1Ch]@28
    int idv[6]; // [sp+4Ch] [bp-18h]@43

    v4 = this;
    v5 = rge_base_game->outline_type;
    v6 = this->owner->world;
    v7 = v4->master_obj;
    v8 = v6->map;
    group_num_shape = (TShape *)v6->map;
    if( v5 == 3 )
    {
        rx1 = v7->radius_x;
        ry1 = v7->radius_y;
        v9 = LODWORD(v7->radius_z);
    }
    else
    {
        rx1 = v7->outline_radius_x;
        ry1 = v7->outline_radius_y;
        v9 = LODWORD(v7->outline_radius_z);
    }
    tot_hp = v9;
    if( startLoggingAI == 1 )
    {
        v10 = v4->id;
        if( v4->groupCommanderValue == v10 && v10 >= 0 )
        {
            draw_color = 0;
            goto LABEL_15;
        }
    }
    if( v4->selected & 1 )
        goto LABEL_61;
    if( v5 == 3 )
    {
        draw_color = 116;
        goto LABEL_15;
    }
    if( (v7->draw_flag & 1) != 1 || rge_base_game->prog_mode != 7 )
LABEL_61:
        draw_color = -1;
    else
        draw_color = v7->draw_color;
LABEL_15:
    v11 = v4->selected;
    if( v11 & 2 )
        draw_color = 74;
    if( v11 & 4 )
        draw_color = -105;
    v12 = v4->screen_y_offset;
    v13 = v4->screen_x_offset;
    ya = -ry1;
    v14 = v12 + y;
    v15 = v13 + x;
    RGE_Map::get_point(v8, (short *)&x1, (short *)&y1, rx1, ya, 0.0, v13 + x, v12 + y);
    RGE_Map::get_point(v8, &y, (short *)&y2, rx1, ry1, 0.0, v15, v14);
    v47 = -rx1;
    RGE_Map::get_point(v8, (short *)&x3, (short *)&y3, v47, ry1, 0.0, v15, v14);
    RGE_Map::get_point(v8, (short *)&x4, &x, v47, ya, 0.0, v15, v14);
    LODWORD(v47) = (unsigned __int8)draw_color;
    v16 = v14;
    DClipInfo_List::AddGDINode(
        SDI_List,
        1,
        v14,
        (signed short)x1,
        (signed short)y1,
        y,
        (signed short)y2,
        (signed short)x3,
        (signed short)y3,
        (signed short)x4,
        x,
        10,
        (unsigned __int8)draw_color,
        SDI_Object_ID);
    if( v4->selected )
    {
        v17 = v4->selected_group;
        if( v17 )
        {
            if( (unsigned __int8)v17 < 0xAu && v4->owner->id == v4->owner->world->curr_player )
            {
                v18 = RGE_Base_Game::get_shape(rge_base_game, 0);
                if( v18 )
                    DClipInfo_List::AddDrawNode(
                        SDI_List,
                        v18[6],
                        (Shape_Info *)&v18[6][v4->selected_group],
                        v14,
                        (signed short)x4 - 6,
                        x - 8,
                        0,
                        0,
                        0,
                        30,
                        SDI_Object_ID);
            }
        }
    }
    if( (v4->selected & 1) == 1 && !(v4->master_obj->draw_flag & 2) )
    {
        LODWORD(ry1) = (signed __int64)v4->hp;
        if( SLODWORD(ry1) > 0 )
        {
            RGE_Map::get_point(
                (RGE_Map *)group_num_shape,
                (short *)&x0,
                (short *)&y0,
                rx1,
                ya,
                *(float *)&tot_hp,
                v15,
                v14);
            v19 = ry1;
            if( SLODWORD(ry1) < 1 )
            {
                ry1 = 0.0;
                v19 = 0.0;
            }
            v20 = v4->master_obj;
            v21 = v20->hp;
            tot_hp = v20->hp;
            if( v21 > 0 )
            {
                v22 = x0 - 12;
                x1 = x0 - 12;
                y2 = y0 - 1;
                v23 = x0 - 12 + 23;
                *(_DWORD *)&y = x0 - 12 + 23;
                y1 = y0 - 2;
                if( LODWORD(v19) == tot_hp )
                {
                    v24 = x0 - 12 + 23;
                    LOWORD(v25) = -1;
                    x3 = x0 - 12 + 23;
                    y3 = 1;
                    x4 = -1;
                    *(_DWORD *)&x = 0;
                }
                else
                {
                    if( v19 == 0.0 )
                    {
                        LOWORD(v24) = -1;
                        y3 = 0;
                        x3 = -1;
                        v25 = x0 - 12;
                    }
                    else
                    {
                        y3 = 1;
                        v24 = v22 + 24 * LODWORD(v19) / tot_hp;
                        x3 = v24;
                        if( (signed short)v24 >= (signed short)v23 )
                        {
                            v24 = x0 - 12 + 22;
                            x3 = x0 - 12 + 22;
                        }
                        v25 = v24 + 1;
                    }
                    x4 = v25;
                    *(_DWORD *)&x = 1;
                }
                DClipInfo_List::AddGDINode(
                    SDI_List,
                    2,
                    v16,
                    (signed short)v22,
                    (signed short)y1,
                    (signed short)v23,
                    (signed short)y2,
                    (signed short)v24,
                    (signed short)y3,
                    (signed short)v25,
                    x,
                    30,
                    SLODWORD(v47),
                    SDI_Object_ID);
            }
        }
    }
    if( rge_base_game->display_selected_ids )
    {
        v26 = RGE_Base_Game::get_shape(rge_base_game, 0);
        v27 = v4->id;
        group_num_shape = (TShape *)v26;
        v28 = v27;
        if( v27 < 0 )
            v28 = -v27;
        v29 = 0;
        idv[0] = v28 / 10000;
        v30 = 2000 * (4 * (v28 / -10000) - v28 / 10000) + v28;
        idv[1] = v30 / 1000;
        v31 = v30 + 200 * (4 * (v30 / -1000) - v30 / 1000);
        idv[2] = v31 / 100;
        v32 = v31 + 20 * (4 * (v31 / -100) - v31 / 100);
        idv[3] = v32 / 10;
        idv[4] = v32 % 10;
        if( v27 < 10000 )
            v29 = 1;
        if( v27 < 1000 )
            v29 = 2;
        if( v27 < 100 )
            v29 = 3;
        if( v27 < 10 )
            v29 = 4;
        if( v27 < 0 )
        {
            *(_DWORD *)&y = y + 7;
            DClipInfo_List::AddGDINode(
                SDI_List,
                4,
                v16,
                y + 1,
                (signed short)y2 + 3,
                y + 5,
                (signed short)y2 + 3,
                0,
                0,
                0,
                0,
                30,
                151,
                SDI_Object_ID);
        }
        if( v29 <= 4 )
        {
            v33 = &idv[v29];
            v34 = 5 - v29;
            do
            {
                v35 = *v33;
                v36 = y + 7;
                v37 = *v33 == 0;
                *(_DWORD *)&y = y + 7;
                if( v37 )
                    DClipInfo_List::AddGDINode(
                        SDI_List,
                        4,
                        v16,
                        v36 + 1,
                        (signed short)y2,
                        v36 + 5,
                        (signed short)y2 + 5,
                        0,
                        0,
                        0,
                        0,
                        30,
                        255,
                        SDI_Object_ID);
                else
                    DClipInfo_List::AddDrawNode(
                        SDI_List,
                        group_num_shape->FShape,
                        (Shape_Info *)&group_num_shape->FShape[v35],
                        v16,
                        v36,
                        (signed short)y2,
                        0,
                        0,
                        0,
                        30,
                        SDI_Object_ID);
                ++v33;
                --v34;
            }
            while( v34 );
        }
    }
}

void RGE_Static_Object::draw_frame_3d_square_back(TDrawArea *render_area, short x, short y)
{
    RGE_Static_Object *v4; // ebx@1
    RGE_Master_Static_Object *v5; // eax@1
    RGE_Map *v6; // ebp@1
    float v7; // edx@1
    float v8; // eax@1
    int v9; // edi@1
    TDrawArea *v10; // esi@2
    int v11; // eax@4
    HGDIOBJ v12; // ST18_4@6
    HGDIOBJ v13; // ST18_4@7
    short v14; // cx@8
    short v15; // bx@8
    short v16; // di@8
    float v17; // ST08_4@8
    short y1; // [sp+24h] [bp-10h]@8
    short x1; // [sp+26h] [bp-Eh]@8
    short y2; // [sp+28h] [bp-Ch]@8
    short x2; // [sp+2Ah] [bp-Ah]@8
    float rx1; // [sp+2Ch] [bp-8h]@1
    float ry1; // [sp+30h] [bp-4h]@1
    TDrawArea *render_areaa; // [sp+38h] [bp+4h]@8

    v4 = this;
    v5 = this->master_obj;
    v6 = this->owner->world->map;
    v7 = v5->outline_radius_x;
    v8 = v5->outline_radius_y;
    rx1 = v7;
    ry1 = v8;
    v9 = ((int (*)(void))rge_base_game->vfptr->get_view_panel)();
    if( v9 )
    {
        v10 = render_area;
        TDrawArea::Unlock(render_area, aStat_objDraw_f);
        if( TDrawArea::GetDc(render_area, aStat_objDraw_f) )
        {
            SelectClipRgn(render_area->DrawDc, *(HRGN *)(v9 + 136));
            if( startLoggingAI != 1 || (v11 = v4->id, v4->groupCommanderValue != v11) || v11 < 0 )
            {
                v13 = GetStockObject(6);
                SelectObject(render_area->DrawDc, v13);
            }
            else
            {
                v12 = GetStockObject(7);
                SelectObject(render_area->DrawDc, v12);
            }
            v14 = v4->screen_x_offset;
            *(float *)&render_areaa = -ry1;
            v15 = v4->screen_y_offset + y;
            v16 = v14 + x;
            RGE_Map::get_point(v6, &x1, &y1, rx1, *(float *)&render_areaa, 0.0, v14 + x, v15);
            RGE_Map::get_point(v6, &x2, &y2, rx1, ry1, 0.0, v16, v15);
            MoveToEx(v10->DrawDc, x1, y1, 0);
            LineTo(v10->DrawDc, x2, y2);
            RGE_Map::get_point(v6, &x1, &y1, rx1, *(float *)&render_areaa, 0.0, v16, v15);
            v17 = -rx1;
            RGE_Map::get_point(v6, &x2, &y2, v17, *(float *)&render_areaa, 0.0, v16, v15);
            MoveToEx(v10->DrawDc, x1, y1, 0);
            LineTo(v10->DrawDc, x2, y2);
            SelectClipRgn(v10->DrawDc, 0);
            TDrawArea::ReleaseDc(v10, aStat_objDraw_f);
        }
        TDrawArea::Lock(v10, aStat_objDraw_f, 1);
    }
}

void RGE_Static_Object::draw_frame_3d_square_front(TDrawArea *render_area, short x, short y)
{
    RGE_Static_Object *v4; // ebx@1
    RGE_Player *v5; // eax@1
    RGE_Game_World *v6; // ecx@1
    RGE_Master_Static_Object *v7; // eax@1
    RGE_Map *v8; // ebp@1
    float v9; // edx@1
    float v10; // edx@1
    RGE_Base_GameVtbl *v11; // eax@1
    TDrawArea *v12; // esi@2
    short v13; // di@2
    short v14; // bx@2
    int v15; // eax@4
    HGDIOBJ v16; // ST18_4@6
    HGDIOBJ v17; // ST18_4@7
    float v18; // ST0C_4@8
    float v19; // ST0C_4@10
    TDrawArea *v20; // ebx@10
    signed int v21; // ebp@12
    short y1; // [sp+20h] [bp-1Ch]@8
    short x1; // [sp+22h] [bp-1Ah]@8
    short y2; // [sp+24h] [bp-18h]@8
    short x2; // [sp+26h] [bp-16h]@8
    float ry1; // [sp+28h] [bp-14h]@1
    float rx1; // [sp+2Ch] [bp-10h]@1
    RGE_Static_Object *v28; // [sp+30h] [bp-Ch]@1
    TPanel *view_panel; // [sp+34h] [bp-8h]@1
    float rz2; // [sp+38h] [bp-4h]@1
    TDrawArea *render_areab; // [sp+40h] [bp+4h]@8
    TDrawArea *render_areaa; // [sp+40h] [bp+4h]@9

    v4 = this;
    v5 = this->owner;
    v28 = this;
    v6 = v5->world;
    v7 = v28->master_obj;
    v8 = v6->map;
    v9 = v7->outline_radius_x;
    ry1 = v7->outline_radius_y;
    rx1 = v9;
    v10 = v7->radius_z;
    v11 = rge_base_game->vfptr;
    rz2 = v10;
    view_panel = (TPanel *)((int (*)(void))v11->get_view_panel)();
    if( view_panel )
    {
        v12 = render_area;
        TDrawArea::Unlock(render_area, aStat_objDraw_1);
        v13 = v4->screen_x_offset + x;
        v14 = v4->screen_y_offset + y;
        if( TDrawArea::GetDc(render_area, aStat_objDraw_1) )
        {
            SelectClipRgn(render_area->DrawDc, view_panel->clip_rgn);
            if( startLoggingAI != 1 || (v15 = v28->id, v28->groupCommanderValue != v15) || v15 < 0 )
            {
                v17 = GetStockObject(6);
                SelectObject(render_area->DrawDc, v17);
            }
            else
            {
                v16 = GetStockObject(7);
                SelectObject(render_area->DrawDc, v16);
            }
            *(float *)&render_areab = -rx1;
            v18 = -ry1;
            RGE_Map::get_point(v8, &x1, &y1, *(float *)&render_areab, v18, 0.0, v13, v14);
            RGE_Map::get_point(v8, &x2, &y2, *(float *)&render_areab, ry1, 0.0, v13, v14);
            MoveToEx(v12->DrawDc, x1, y1, 0);
            LineTo(v12->DrawDc, x2, y2);
            RGE_Map::get_point(v8, &x1, &y1, rx1, ry1, 0.0, v13, v14);
            RGE_Map::get_point(v8, &x2, &y2, *(float *)&render_areab, ry1, 0.0, v13, v14);
            MoveToEx(v12->DrawDc, x1, y1, 0);
            LineTo(v12->DrawDc, x2, y2);
            SelectClipRgn(v12->DrawDc, 0);
            TDrawArea::ReleaseDc(v12, aStat_objDraw_1);
        }
        TDrawArea::Lock(v12, aStat_objDraw_1, 1);
        render_areaa = (TDrawArea *)(signed __int64)v28->hp;
        if( (signed int)render_areaa > 0 )
        {
            v19 = -ry1;
            RGE_Map::get_point(v8, &x1, &y1, rx1, v19, rz2, v13, v14);
            v20 = render_areaa;
            if( (signed int)render_areaa < 1 )
                v20 = 0;
            v21 = v28->master_obj->hp;
            if( v21 > 0 )
            {
                TDrawArea::FillRect(v12, x1 - 12, y1 - 2, x1 - 12 + 24, y1 - 1, -105);
                TDrawArea::FillRect(v12, x1 - 12, y1 - 2, 24 * (signed int)v20 / v21 + x1 - 12, y1 - 1, 74);
            }
        }
    }
}
// 62C50C: using guessed type int startLoggingAI;

//----- (004C2DF0) --------------------------------------------------------
void RGE_Static_Object::draw_frame_3d_cube_back(TDrawArea *render_area, short x, short y)
{
    RGE_Static_Object *v4; // ebx@1
    RGE_Master_Static_Object *v5; // eax@1
    RGE_Player *v6; // esi@1
    RGE_Base_GameVtbl *v7; // edx@1
    double v8; // st5@1
    double v9; // st7@1
    double v10; // st6@1
    RGE_Game_World *v11; // esi@1
    float v12; // edi@1
    RGE_Map *v13; // ebp@1
    float v14; // edi@1
    float v15; // eax@1
    int v16; // edi@1
    TDrawArea *v17; // esi@2
    int v18; // eax@4
    HGDIOBJ v19; // ST18_4@6
    HGDIOBJ v20; // ST18_4@7
    short v21; // dx@8
    short v22; // bx@8
    short v23; // di@8
    float v24; // ST08_4@8
    float v25; // ST08_4@8
    float v26; // ST0C_4@8
    short y1; // [sp+24h] [bp-24h]@8
    short x1; // [sp+26h] [bp-22h]@8
    short y2; // [sp+28h] [bp-20h]@8
    short x2; // [sp+2Ah] [bp-1Eh]@8
    float rx1; // [sp+2Ch] [bp-1Ch]@1
    float rx2; // [sp+30h] [bp-18h]@1
    float ry1; // [sp+34h] [bp-14h]@1
    float ry2; // [sp+38h] [bp-10h]@1
    float rz2; // [sp+3Ch] [bp-Ch]@1
    float rz3; // [sp+40h] [bp-8h]@1
    float rz4; // [sp+44h] [bp-4h]@1
    TDrawArea *render_areaa; // [sp+4Ch] [bp+4h]@8

    v4 = this;
    v5 = this->master_obj;
    v6 = this->owner;
    v7 = rge_base_game->vfptr;
    v8 = v5->outline_radius_y * 0.25;
    v9 = v5->outline_radius_z * 0.25;
    v10 = v5->outline_radius_z * 0.75;
    rx2 = v5->outline_radius_x * 0.25;
    v11 = v6->world;
    v12 = v5->outline_radius_x;
    ry2 = v8;
    v13 = v11->map;
    rx1 = v12;
    v14 = v5->outline_radius_y;
    v15 = v5->outline_radius_z;
    rz2 = v9;
    ry1 = v14;
    rz4 = v15;
    rz3 = v10;
    v16 = ((int (*)(void))v7->get_view_panel)();
    if( v16 )
    {
        v17 = render_area;
        TDrawArea::Unlock(render_area, 0);
        if( TDrawArea::GetDc(render_area, 0) )
        {
            SelectClipRgn(render_area->DrawDc, *(HRGN *)(v16 + 136));
            if( startLoggingAI != 1 || (v18 = v4->id, v4->groupCommanderValue != v18) || v18 < 0 )
            {
                v20 = GetStockObject(6);
                SelectObject(render_area->DrawDc, v20);
            }
            else
            {
                v19 = GetStockObject(7);
                SelectObject(render_area->DrawDc, v19);
            }
            v21 = v4->screen_x_offset;
            *(float *)&render_areaa = -ry1;
            v22 = v4->screen_y_offset + y;
            v23 = v21 + x;
            RGE_Map::get_point(v13, &x1, &y1, rx1, *(float *)&render_areaa, 0.0, v21 + x, v22);
            RGE_Map::get_point(v13, &x2, &y2, rx1, *(float *)&render_areaa, rz2, v23, v22);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, rx1, *(float *)&render_areaa, rz3, v23, v22);
            RGE_Map::get_point(v13, &x2, &y2, rx1, *(float *)&render_areaa, rz4, v23, v22);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, rx1, *(float *)&render_areaa, 0.0, v23, v22);
            RGE_Map::get_point(v13, &x2, &y2, rx2, *(float *)&render_areaa, 0.0, v23, v22);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            v24 = -rx1;
            RGE_Map::get_point(v13, &x1, &y1, v24, *(float *)&render_areaa, 0.0, v23, v22);
            v25 = -rx2;
            RGE_Map::get_point(v13, &x2, &y2, v25, *(float *)&render_areaa, 0.0, v23, v22);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, rx1, *(float *)&render_areaa, 0.0, v23, v22);
            v26 = -ry2;
            RGE_Map::get_point(v13, &x2, &y2, rx1, v26, 0.0, v23, v22);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, rx1, ry1, 0.0, v23, v22);
            RGE_Map::get_point(v13, &x2, &y2, rx1, ry2, 0.0, v23, v22);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            SelectClipRgn(v17->DrawDc, 0);
            TDrawArea::ReleaseDc(v17, 0);
        }
        TDrawArea::Lock(v17, 0, 1);
    }
}
// 62C50C: using guessed type int startLoggingAI;

//----- (004C31E0) --------------------------------------------------------
void RGE_Static_Object::draw_frame_3d_cube_front(TDrawArea *render_area, short x, short y)
{
    RGE_Static_Object *v4; // ebx@1
    RGE_Master_Static_Object *v5; // eax@1
    RGE_Player *v6; // esi@1
    RGE_Base_GameVtbl *v7; // edx@1
    double v8; // st5@1
    double v9; // st7@1
    double v10; // st6@1
    RGE_Game_World *v11; // esi@1
    float v12; // edi@1
    RGE_Map *v13; // ebp@1
    float v14; // edi@1
    float v15; // eax@1
    int v16; // edi@1
    TDrawArea *v17; // esi@2
    int v18; // eax@4
    HGDIOBJ v19; // ST18_4@6
    HGDIOBJ v20; // ST18_4@7
    short v21; // dx@8
    short v22; // di@8
    short v23; // bx@8
    short v24; // di@8
    short y1; // [sp+Ch] [bp-28h]@8
    short x1; // [sp+Eh] [bp-26h]@8
    short y2; // [sp+10h] [bp-24h]@8
    short x2; // [sp+12h] [bp-22h]@8
    float ry1; // [sp+14h] [bp-20h]@1
    float rz4; // [sp+18h] [bp-1Ch]@1
    float rx1; // [sp+1Ch] [bp-18h]@1
    float ry2; // [sp+20h] [bp-14h]@1
    float rx2; // [sp+24h] [bp-10h]@1
    float v34; // [sp+28h] [bp-Ch]@8
    float rz2; // [sp+2Ch] [bp-8h]@1
    float rz3; // [sp+30h] [bp-4h]@1
    TDrawArea *render_areaa; // [sp+38h] [bp+4h]@8
    float xa; // [sp+3Ch] [bp+8h]@8
    float ya; // [sp+40h] [bp+Ch]@8

    v4 = this;
    v5 = this->master_obj;
    v6 = this->owner;
    v7 = rge_base_game->vfptr;
    v8 = v5->outline_radius_y * 0.25;
    v9 = v5->outline_radius_z * 0.25;
    v10 = v5->outline_radius_z * 0.75;
    rx2 = v5->outline_radius_x * 0.25;
    v11 = v6->world;
    v12 = v5->outline_radius_x;
    ry2 = v8;
    v13 = v11->map;
    rx1 = v12;
    v14 = v5->outline_radius_y;
    v15 = v5->outline_radius_z;
    rz2 = v9;
    ry1 = v14;
    rz4 = v15;
    rz3 = v10;
    v16 = ((int (*)(void))v7->get_view_panel)();
    if( v16 )
    {
        v17 = render_area;
        TDrawArea::Unlock(render_area, 0);
        if( TDrawArea::GetDc(render_area, 0) )
        {
            SelectClipRgn(render_area->DrawDc, *(HRGN *)(v16 + 136));
            if( startLoggingAI != 1 || (v18 = v4->id, v4->groupCommanderValue != v18) || v18 < 0 )
            {
                v20 = GetStockObject(6);
                SelectObject(render_area->DrawDc, v20);
            }
            else
            {
                v19 = GetStockObject(7);
                SelectObject(render_area->DrawDc, v19);
            }
            v21 = v4->screen_x_offset;
            v22 = x;
            xa = -ry1;
            v23 = v4->screen_y_offset - 16 + y;
            v24 = v21 + v22;
            RGE_Map::get_point(v13, &x1, &y1, rx1, xa, rz4, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, rx2, xa, rz4, v24, v23);
            MoveToEx(render_area->DrawDc, x1, y1, 0);
            LineTo(render_area->DrawDc, x2, y2);
            *(float *)&render_areaa = -rx1;
            RGE_Map::get_point(v13, &x1, &y1, *(float *)&render_areaa, xa, rz4, v24, v23);
            v34 = -rx2;
            RGE_Map::get_point(v13, &x2, &y2, v34, xa, rz4, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, rx1, ry1, rz4, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, rx2, ry1, rz4, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, *(float *)&render_areaa, ry1, rz4, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, v34, ry1, rz4, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, rx1, ry1, rz4, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, rx1, ry2, rz4, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, rx1, xa, rz4, v24, v23);
            ya = -ry2;
            RGE_Map::get_point(v13, &x2, &y2, rx1, ya, rz4, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, *(float *)&render_areaa, ry1, rz4, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, *(float *)&render_areaa, ry2, rz4, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, *(float *)&render_areaa, xa, rz4, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, *(float *)&render_areaa, ya, rz4, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, *(float *)&render_areaa, xa, 0.0, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, *(float *)&render_areaa, ya, 0.0, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, *(float *)&render_areaa, ry1, 0.0, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, *(float *)&render_areaa, ry2, 0.0, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, rx1, ry1, 0.0, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, rx2, ry1, 0.0, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, *(float *)&render_areaa, ry1, 0.0, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, v34, ry1, 0.0, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, *(float *)&render_areaa, ry1, 0.0, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, *(float *)&render_areaa, ry1, rz2, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, *(float *)&render_areaa, ry1, rz3, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, *(float *)&render_areaa, ry1, rz4, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, *(float *)&render_areaa, xa, 0.0, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, *(float *)&render_areaa, xa, rz2, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, *(float *)&render_areaa, xa, rz3, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, *(float *)&render_areaa, xa, rz4, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, rx1, ry1, 0.0, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, rx1, ry1, rz2, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            RGE_Map::get_point(v13, &x1, &y1, rx1, ry1, rz3, v24, v23);
            RGE_Map::get_point(v13, &x2, &y2, rx1, ry1, rz4, v24, v23);
            MoveToEx(v17->DrawDc, x1, y1, 0);
            LineTo(v17->DrawDc, x2, y2);
            SelectClipRgn(v17->DrawDc, 0);
            TDrawArea::ReleaseDc(v17, 0);
        }
        TDrawArea::Lock(v17, 0, 1);
    }
}
// 62C50C: using guessed type int startLoggingAI;

//----- (004C3B30) --------------------------------------------------------
void RGE_Static_Object::draw_frame(TDrawArea *render_area, short x, short y)
{
    RGE_Static_Object *v4; // ebx@1
    RGE_Sprite *v5; // eax@1
    RGE_Active_Sprite_List *v6; // ecx@2
    int v7; // eax@4
    int v8; // edi@4
    int v9; // esi@4
    TDrawArea *v10; // ebp@4
    int v11; // esi@8
    int v12; // ebx@8
    int v13; // edi@8
    short min_x; // [sp+10h] [bp-8h]@3
    short min_y; // [sp+12h] [bp-6h]@3
    int max_y; // [sp+14h] [bp-4h]@3
    signed int render_areaa; // [sp+1Ch] [bp+4h]@7
    int tot_hp; // [sp+20h] [bp+8h]@5
    int cur_hp; // [sp+24h] [bp+Ch]@8

    v4 = this;
    v5 = this->sprite;
    if( v5 )
    {
        v6 = this->sprite_list;
        if( v6 )
        {
            ((void (__stdcall *)(RGE_Sprite *, _WORD))v6->vfptr->get_facetindex)(v5, v4->facet);
            if( RGE_Static_Object::get_frame(v4, &min_x, &min_y, (short *)&max_y + 1, (short *)&max_y) )
            {
                v7 = v4->screen_x_offset;
                v8 = x + min_x + v7 - 1;
                v9 = y + min_y + v4->screen_y_offset - 1;
                v10 = render_area;
                TDrawArea::DrawRect(
                    render_area,
                    v8,
                    v9,
                    x + SHIWORD(max_y) + v7 + 1,
                    y + (signed short)max_y + v4->screen_y_offset + 1,
                    -1);
                if( v4->object_state <= 2u )
                {
                    tot_hp = (signed __int64)v4->hp;
                    if( tot_hp < 1 )
                        tot_hp = 0;
                    render_areaa = v4->master_obj->hp;
                    if( render_areaa > 0 )
                    {
                        v11 = v9 - 6;
                        cur_hp = v11 + 5;
                        TDrawArea::DrawRect(v10, v8, v11, v8 + 26, v11 + 5, -1);
                        v12 = v8 + 24;
                        ++v11;
                        v13 = v8 + 1;
                        TDrawArea::FillRect(v10, v13, v11, v12, cur_hp - 2, 85);
                        TDrawArea::FillRect(v10, v13, v11, 25 * tot_hp / render_areaa + v13 - 1, v11 + 3, 37);
                    }
                }
            }
        }
    }
}

//----- (004C3C70) --------------------------------------------------------
char RGE_Static_Object::update()
{
    RGE_Static_Object *v1; // esi@1
    RGE_Object_Node *v2; // ST14_4@2
    RGE_PlayerVtbl *v3; // eax@2
    int v4; // ST10_4@2
    char result; // al@2
    int v6; // eax@3
    int v7; // ebx@4
    int v8; // ebp@7
    int *v9; // edi@7
    int i; // eax@8
    int *v11; // eax@12
    int v12; // edi@12
    RGE_Static_Object *v13; // eax@12
    int v14; // ecx@14
    int v15; // eax@14
    int *v16; // edx@15
    int v17; // eax@21
    RGE_Static_Object *v18; // eax@25
    RGE_Static_ObjectVtbl *v19; // edi@29
    int v20; // eax@29
    int v21; // ebp@29
    unsigned int v22; // edi@29
    RGE_Sound *v23; // ecx@29
    RGE_Master_Static_Object *v24; // ecx@35
    char v26; // c0@36
    RGE_Static_ObjectVtbl *v27; // edi@38
    signed int v28; // [sp+Ah] [bp-4h]@5

    v1 = this;
    if( this->goto_sleep_flag )
    {
        v2 = this->player_object_node;
        v3 = this->owner->vfptr;
        v4 = this->dopple_flag;
        this->goto_sleep_flag = 0;
        ((void (__stdcall *)(RGE_Static_Object *, _DWORD, int, RGE_Object_Node *))v3->removeObject)(this, 0, v4, v2);
        v1->player_object_node = (RGE_Object_Node *)((int (__stdcall *)(RGE_Static_Object *, signed int, _DWORD))v1->owner->vfptr->addObject)(
                                                                                                    v1,
                                                                                                    1,
                                                                                                    v1->dopple_flag);
        result = 0;
    }
    else
    {
        v6 = this->groupMembers.numberValue;
        if( v6 > 0 )
        {
            v7 = 0;
            if( v6 > 0 )
            {
                v28 = 4;
                do
                {
                    if( v7 > v1->groupMembers.maximumSizeValue - 1 )
                    {
                        v8 = v7 + 1;
                        v9 = (int *)operator new(v28);
                        if( v9 )
                        {
                            for( i = 0; i < v1->groupMembers.maximumSizeValue; v9[i - 1] = v1->groupMembers.value[i - 1] )
                            {
                                if( i >= v8 )
                                    break;
                                ++i;
                            }
                            operator delete(v1->groupMembers.value);
                            v1->groupMembers.value = v9;
                            v1->groupMembers.maximumSizeValue = v8;
                        }
                    }
                    v11 = v1->groupMembers.value;
                    v12 = v11[v7];
                    v13 = RGE_Game_World::object(v1->owner->world, v11[v7]);
                    if( !v13 || v13->object_state > 2u )
                    {
                        v14 = v1->groupMembers.maximumSizeValue;
                        v15 = 0;
                        if( v14 > 0 )
                        {
                            v16 = v1->groupMembers.value;
                            do
                            {
                                if( *v16 == v12 )
                                    break;
                                ++v15;
                                ++v16;
                            }
                            while( v15 < v14 );
                        }
                        if( v15 < v14 )
                        {
                            if( v15 < v14 - 1 )
                            {
                                do
                                {
                                    ++v15;
                                    v1->groupMembers.value[v15 - 1] = v1->groupMembers.value[v15];
                                }
                                while( v15 < v1->groupMembers.maximumSizeValue - 1 );
                            }
                            v17 = v1->groupMembers.numberValue - 1;
                            v1->groupMembers.numberValue = v17;
                            if( v17 < 0 )
                                v1->groupMembers.numberValue = 0;
                        }
                        --v7;
                        v28 -= 4;
                    }
                    ++v7;
                    v28 += 4;
                }
                while( v7 < v1->groupMembers.numberValue );
            }
        }
        v18 = v1->inside_obj;
        if( v18 )
        {
            LOBYTE(v18) = v18->object_state;
            if( (unsigned __int8)v18 > 2u )
                v1->vfptr->set_object_state(v1, (char)v18);
        }
        else
        {
            switch( v1->object_state )
            {
                case 2:
                    (*(void (**)(RGE_Static_Object *))&v1->vfptr->gap4[36])(v1);
                    goto LABEL_28;
                case 0:
LABEL_28:
                    if( v1->hp >= 1.0 )
                        break;
                    v19 = v1->vfptr;
                    v1->vfptr->set_object_state(v1, 3);
                    (*(void (**)(RGE_Static_Object *, RGE_Sprite *))&v19->gap4[52])(v1, v1->master_obj->death_sprite);
                    v20 = debug_rand(aCMsdevWorkA_29, 1796);
                    v21 = debug_random_on;
                    debug_random_on = 0;
                    v22 = v20;
                    v23 = v1->master_obj->death_sound;
                    if( v23 )
                    {
                        if( v1->owner->id == v1->owner->world->curr_player )
                            RGE_Sound::play(v23, 1);
                    }
                    debug_random_on = v21;
                    debug_srand(aCMsdevWorkA_29, 1806, v22);
                    return 0;
                case 3:
                case 5:
                    if( v1->attribute_type_held == -1 || v1->attribute_amount_held <= 0.0 )
                    {
                        v27 = v1->vfptr;
                        if( v1->master_obj->undead_flag )
                        {
                            v27->set_object_state(v1, 6);
                            (*(void (**)(RGE_Static_Object *, RGE_Sprite *))&v27->gap4[52])(
                                v1,
                                v1->master_obj->undead_sprite);
                            result = 0;
                        }
                        else
                        {
                            v27->set_object_state(v1, 7);
                            v27->spawn_death_obj(v1);
                            result = 0;
                        }
                        return result;
                    }
                    v24 = v1->master_obj;
                    if( v24->attribute_rot > 0.0 )
                    {
                        v1->attribute_amount_held = v1->attribute_amount_held
                                                                            - v1->owner->world->world_time_delta_seconds * v24->attribute_rot;
                        if( v26 )
                        {
                            result = 0;
                            LODWORD(v1->attribute_amount_held) = 0;
                            return result;
                        }
                    }
                    break;
                case 7:
                    v1->vfptr->set_object_state(v1, 8);
                    return 0;
                case 8:
                    return (v1->master_obj->recyclable != 0) + 1;
                default:
                    break;
            }
        }
        result = 0;
    }
    return result;
}
// 62C4D4: using guessed type int debug_random_on;

//----- (004C3F90) --------------------------------------------------------
void RGE_Static_Object::check_damage_sprites()
{
    RGE_Static_Object *v1; // esi@1
    int v2; // edi@1
    RGE_Master_Static_Object *v3; // ebp@1
    short v4; // ax@1
    char v5; // bl@2
    double v6; // st7@3
    signed __int64 v7; // rax@3
    char v8; // dl@3
    int v9; // edi@6
    char *v10; // eax@6
    int v11; // ebp@6
    unsigned __int8 v12; // cl@7
    int v13; // ebp@15
    int v14; // eax@15
    RGE_Master_Static_Object *v15; // edi@19
    double v16; // st7@19
    RGE_Master_Static_Object *v17; // edi@19
    double v18; // st7@19
    float v19; // ST10_4@19
    RGE_Master_Static_Object *v20; // edi@23
    RGE_Damage_Sprite_Info *v21; // eax@23
    char v22; // cl@23
    char new_damage_percent; // [sp+11h] [bp-17h]@3
    short y; // [sp+12h] [bp-16h]@19
    int x; // [sp+14h] [bp-14h]@3
    int curr_damage_loc; // [sp+18h] [bp-10h]@1
    int new_damage_loc; // [sp+1Ch] [bp-Ch]@1
    float rand_y; // [sp+20h] [bp-8h]@19
    float rand_x; // [sp+24h] [bp-4h]@19

    v1 = this;
    v2 = -1;
    v3 = this->master_obj;
    new_damage_loc = -1;
    curr_damage_loc = -1;
    v4 = v3->hp;
    if( v4 > 0 )
    {
        v5 = v3->damage_sprite_num;
        if( v5 )
        {
            v6 = this->hp * 100.0;
            x = v4;
            v7 = (signed __int64)(v6 / (double)v4);
            v8 = 100 - v7;
            new_damage_percent = 100 - v7;
            if( 100 - (_BYTE)v7 != this->curr_damage_percent )
            {
                if( (unsigned __int8)v8 < 0x64u && v5 )
                {
                    v9 = 0;
                    v10 = &v3->damage_sprites->damage_percent;
                    v11 = (unsigned __int8)v5;
                    do
                    {
                        v12 = *v10;
                        if( (unsigned __int8)*v10 < (unsigned __int8)v8 )
                            new_damage_loc = v9;
                        if( v12 < v1->curr_damage_percent )
                            curr_damage_loc = v9;
                        ++v9;
                        v10 += 8;
                        --v11;
                    }
                    while( v11 );
                    v2 = new_damage_loc;
                }
                if( v2 == curr_damage_loc )
                {
LABEL_29:
                    v1->curr_damage_percent = v8;
                    return;
                }
                if( v2 > -1 )
                {
                    v13 = v2;
                    v14 = (int)&v1->master_obj->damage_sprites[v2];
                    if( *(_BYTE *)(v14 + 5) )
                    {
                        if( *(_BYTE *)(v14 + 5) == 1 )
                        {
                            v15 = v1->master_obj;
                            rand_y = COERCE_FLOAT(debug_rand(aCMsdevWorkA_29, 1908));
                            v16 = (double)SLODWORD(rand_y) * v15->radius_x * 0.000061037019 - v15->radius_x;
                            LODWORD(rand_y) = (signed short)(signed __int64)v1->world_x;
                            v17 = v1->master_obj;
                            rand_x = v16 + v1->world_x - (double)SLODWORD(rand_y);
                            rand_y = COERCE_FLOAT(debug_rand(aCMsdevWorkA_29, 1909));
                            v18 = (double)SLODWORD(rand_y) * v17->radius_y * 0.000061037019 - v17->radius_y;
                            LODWORD(rand_y) = (signed short)(signed __int64)v1->world_y;
                            v19 = v1->world_z;
                            rand_y = v18 + v1->world_y - (double)SLODWORD(rand_y);
                            RGE_Map::get_point(v1->owner->world->map, (short *)&x, &y, rand_x, rand_y, v19, 0, 0);
                            RGE_Active_Sprite_List::add_sprite(
                                v1->sprite_list,
                                v1->master_obj->damage_sprites[v13].sprite,
                                90,
                                (signed short)x,
                                y);
                        }
                        else
                        {
                            if( *(_BYTE *)(v14 + 5) != 2 )
                                goto LABEL_22;
                            (*(void (**)(RGE_Static_Object *, _DWORD))&v1->vfptr->gap4[52])(v1, *(_DWORD *)v14);
                        }
                    }
                    else
                    {
                        RGE_Active_Sprite_List::add_sprite(v1->sprite_list, *(RGE_Sprite **)v14, 90, 0, 0);
                    }
                    v8 = new_damage_percent;
                }
LABEL_22:
                if( curr_damage_loc > -1 )
                {
                    v20 = v1->master_obj;
                    v21 = v20->damage_sprites;
                    v22 = v21[curr_damage_loc].flag;
                    if( (unsigned __int8)v22 <= 1u )
                    {
                        RGE_Active_Sprite_List::remove_sprite(v1->sprite_list, v21[curr_damage_loc].sprite);
                        v8 = new_damage_percent;
                    }
                    else if( v22 == 2 && (new_damage_loc < 0 || v21[new_damage_loc].flag != 2) )
                    {
                        (*(void (**)(RGE_Static_Object *, RGE_Sprite *))&v1->vfptr->gap4[52])(v1, v20->sprite);
                        v1->curr_damage_percent = new_damage_percent;
                        return;
                    }
                }
                goto LABEL_29;
            }
        }
    }
}

//----- (004C41D0) --------------------------------------------------------
RGE_Static_Object *RGE_Static_Object::spawn_death_obj()
{
    RGE_Static_Object *v1; // eax@1
    short v2; // cx@1
    RGE_Player *v3; // edx@2
    RGE_Master_Static_Object *v4; // ecx@2
    RGE_Static_Object *result; // eax@3

    v1 = this;
    v2 = this->master_obj->death_spawn_obj_id;
    if( v2 >= 0 && (v3 = v1->owner, (v4 = v3->master_objects[v2]) != 0) )
        result = (RGE_Static_Object *)((int (__stdcall *)(RGE_Player *, _DWORD, _DWORD, _DWORD))v4->vfptr->make_new_obj)(
                                                                        v3,
                                                                        LODWORD(v1->world_x),
                                                                        LODWORD(v1->world_y),
                                                                        LODWORD(v1->world_z));
    else
        result = 0;
    return result;
}

//----- (004C4210) --------------------------------------------------------
void RGE_Static_Object::rehook()
{
    RGE_Static_Object *v1; // esi@1
    RGE_Static_ObjectVtbl *v2; // edi@1
    int v3; // ST08_4@2
    RGE_Static_Object *v4; // eax@2

    v1 = this;
    v2 = this->vfptr;
    (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))&this->vfptr->gap4[48])(
        LODWORD(this->world_x),
        LODWORD(this->world_y),
        LODWORD(this->world_z));
    if( v1->inside_obj )
    {
        v3 = (int)v1->inside_obj;
        v1->inside_obj = 0;
        v4 = RGE_Static_Object::get_object_pointer(v1, v3);
        if( v4 )
            v2->enter_obj(v1, v4);
    }
}

//----- (004C4250) --------------------------------------------------------
RGE_Static_Object *RGE_Static_Object::get_object_pointer(int obj_id)
{
    int v2; // ebp@1
    RGE_Static_Object *result; // eax@1
    RGE_Static_Object *v4; // edi@1
    RGE_Player *v5; // esi@5
    unsigned __int8 v6; // bl@5
    RGE_Game_World *v7; // ecx@5
    short v8; // dx@6
    int v9; // esi@8
    unsigned __int8 obj_ida; // [sp+14h] [bp+4h]@5

    v2 = obj_id;
    result = 0;
    v4 = this;
    if( obj_id >= 0 )
    {
        result = RGE_Object_List::find_by_id(this->owner->objects, obj_id);
        if( !result )
        {
            result = RGE_Object_List::find_by_id(v4->owner->sleeping_objects, obj_id);
            if( !result )
            {
                result = RGE_Object_List::find_by_id(v4->owner->doppleganger_objects, obj_id);
                if( !result )
                {
                    v5 = v4->owner;
                    v6 = 0;
                    obj_ida = 0;
                    v7 = v5->world;
                    if( v7->player_num > 0 )
                    {
                        v8 = 0;
                        do
                        {
                            if( v8 != v5->id )
                            {
                                v9 = obj_ida;
                                result = RGE_Object_List::find_by_id(v7->players[v9]->objects, v2);
                                if( result )
                                    break;
                                result = RGE_Object_List::find_by_id(v4->owner->world->players[v9]->sleeping_objects, v2);
                                if( result )
                                    break;
                                result = RGE_Object_List::find_by_id(v4->owner->world->players[v9]->doppleganger_objects, v2);
                                if( result )
                                    break;
                            }
                            v5 = v4->owner;
                            obj_ida = ++v6;
                            v7 = v5->world;
                            v8 = v6;
                        }
                        while( v6 < v7->player_num );
                    }
                }
            }
        }
    }
    return result;
}

//----- (004C4330) --------------------------------------------------------
RGE_Sprite *RGE_Static_Object::get_sprite_pointer(short sprite_id)
{
    RGE_Game_World *v2; // eax@2
    RGE_Sprite *result; // eax@3

    if( sprite_id < 0 || (v2 = this->owner->world, sprite_id >= v2->sprite_num) )
        result = 0;
    else
        result = v2->sprites[sprite_id];
    return result;
}

//----- (004C4360) --------------------------------------------------------
void RGE_Static_Object::save(int outfile)
{
    RGE_Static_Object *v2; // esi@1
    int v3; // edi@1
    int v4; // eax@1
    RGE_Static_Object *v5; // eax@4
    int i; // ebp@7
    int *v7; // ebx@9
    int j; // eax@10
    int k; // ebp@15
    int *v10; // ebx@17
    int l; // eax@18
    int short_val; // [sp+10h] [bp-8h]@2
    int long_val; // [sp+14h] [bp-4h]@5

    v2 = this;
    v3 = outfile;
    rge_write(outfile, &this->type, 1);
    rge_write(outfile, &this->owner->id, 1);
    rge_write(outfile, &this->master_obj->id, 2);
    v4 = (int)v2->sprite;
    if( v4 )
    {
        LOWORD(v4) = *(_WORD *)(v4 + 114);
        short_val = v4;
    }
    else
    {
        short_val = -1;
    }
    rge_write(v3, &short_val, 2);
    v5 = v2->inside_obj;
    if( v5 )
        long_val = v5->id;
    else
        long_val = -1;
    rge_write(v3, &long_val, 4);
    rge_write(outfile, &this->hp, 4);
    rge_write(outfile, &this->object_state, 1);
    rge_write(outfile, &this->sleep_flag, 1);
    rge_write(outfile, &this->dopple_flag, 1);
    rge_write(outfile, &this->goto_sleep_flag, 1);
    rge_write(outfile, &this->id, 4);
    rge_write(outfile, &this->facet, 1);
    rge_write(outfile, &this->world_x, 4);
    rge_write(outfile, &this->world_y, 4);
    rge_write(outfile, &this->world_z, 4);
    rge_write(outfile, &this->screen_x_offset, 2);
    rge_write(outfile, &this->screen_y_offset, 2);
    rge_write(outfile, &this->shadow_x_offset, 2);
    rge_write(outfile, &this->shadow_y_offset, 2);
    rge_write(outfile, &this->selected_group, 1);
    rge_write(outfile, &this->attribute_type_held, 2);
    rge_write(outfile, &this->attribute_amount_held, 4);
    rge_write(outfile, &this->worker_num, 1);
    rge_write(outfile, &this->curr_damage_percent, 1);
    rge_write(outfile, &this->underAttackValue, 1);
    rge_write(outfile, &this->groupCommanderValue, 4);
    rge_write(outfile, &this->groupRangeValue, 4);
    outfile = v2->groupMembers.numberValue;
    rge_write(v3, &outfile, 4);
    for( i = 0; i < v2->groupMembers.numberValue; ++i )
    {
        if( i > v2->groupMembers.maximumSizeValue - 1 )
        {
            v7 = (int *)operator new(4 * i + 4);
            if( v7 )
            {
                for( j = 0; j < v2->groupMembers.maximumSizeValue; v7[j - 1] = v2->groupMembers.value[j - 1] )
                {
                    if( j >= i + 1 )
                        break;
                    ++j;
                }
                operator delete(v2->groupMembers.value);
                v2->groupMembers.value = v7;
                v2->groupMembers.maximumSizeValue = i + 1;
            }
        }
        outfile = v2->groupMembers.value[i];
        rge_write(v3, &outfile, 4);
    }
    outfile = v2->pathingGroupMembers.numberValue;
    rge_write(v3, &outfile, 4);
    for( k = 0; k < v2->pathingGroupMembers.numberValue; ++k )
    {
        if( k > v2->pathingGroupMembers.maximumSizeValue - 1 )
        {
            v10 = (int *)operator new(4 * k + 4);
            if( v10 )
            {
                for( l = 0; l < v2->pathingGroupMembers.maximumSizeValue; v10[l - 1] = v2->pathingGroupMembers.value[l - 1] )
                {
                    if( l >= k + 1 )
                        break;
                    ++l;
                }
                operator delete(v2->pathingGroupMembers.value);
                v2->pathingGroupMembers.value = v10;
                v2->pathingGroupMembers.maximumSizeValue = k + 1;
            }
        }
        outfile = v2->pathingGroupMembers.value[k];
        rge_write(v3, &outfile, 4);
    }
    RGE_Active_Sprite_List::save(v2->sprite_list, v3);
}

//----- (004C4680) --------------------------------------------------------
double RGE_Static_Object::teleport(float x, float y, float z)
{
    RGE_Static_Object *v4; // esi@1
    double v5; // st7@1
    RGE_Game_World *v6; // ecx@1
    RGE_Map *v7; // edi@1
    double result; // st7@2
    int v9; // ebx@7
    double v10; // st6@7
    signed int v11; // ebp@11
    double v12; // st6@11
    int v13; // edi@13
    signed __int64 v14; // rax@13
    int v15; // edi@21
    RGE_Tile *v16; // eax@21
    char v17; // al@27
    unsigned __int8 v19; // c0@37
    unsigned __int8 v20; // c3@37
    double v21; // st7@47
    double v22; // st7@51
    double v23; // st7@53
    unsigned __int8 v25; // c0@65
    unsigned __int8 v26; // c3@65
    RGE_Master_Static_Object *v27; // edi@69
    double v28; // st6@73
    short v29; // ax@76
    int ty; // [sp+18h] [bp-10h]@13
    float rx; // [sp+1Ch] [bp-Ch]@13
    float rz; // [sp+20h] [bp-8h]@1
    RGE_Map *map; // [sp+24h] [bp-4h]@1
    float xa; // [sp+2Ch] [bp+4h]@32
    float xb; // [sp+2Ch] [bp+4h]@75
    float zd; // [sp+30h] [bp+8h]@73

    v4 = this;
    v5 = 0.0;
    rz = 0.0;
    v6 = this->owner->world;
    v7 = v6->map;
    map = v6->map;
    if( v4->inside_obj )
    {
        result = 0.0;
    }
    else
    {
        if( v4->master_obj->radius_z > 0.0 )
        {
            RGE_Static_Object::removeFromObstructionMap(v4, 2);
            v5 = rz;
        }
        if( x < 0.0 )
            x = 0.0;
        v9 = v7->map_width;
        v10 = (double)v7->map_width;
        if( x >= v10 )
            x = v10 - 0.001;
        if( y < 0.0 )
            y = 0.0;
        v11 = v7->map_height;
        v12 = (double)v7->map_height;
        if( y >= v12 )
            y = v12 - 0.001;
        v13 = (signed __int64)x;
        v14 = (signed __int64)y;
        rx = x - (double)v13;
        *(float *)&ty = y - (double)(signed int)v14;
        if( v13 < v9 )
        {
            if( v13 < 0 )
                v13 = 0;
        }
        else
        {
            v13 = v9 - 1;
        }
        if( (signed int)v14 < v11 )
        {
            if( (signed int)v14 < 0 )
                LODWORD(v14) = 0;
        }
        else
        {
            LODWORD(v14) = v11 - 1;
        }
        v15 = (int)&map->map_row_offset[v14][v13].screen_xpos;
        v16 = v4->tile;
        if( (RGE_Tile *)v15 == v16 || v4->inside_obj )
        {
            v4->world_x = x;
            v4->world_y = y;
            v4->world_z = z;
        }
        else
        {
            if( v16 )
                RGE_Object_List::remove_node(&v16->objects, v4, 0);
            RGE_Object_List::add_node((RGE_Object_List *)(v15 + 12), v4);
            if( v4->tile )
                v4->vfptr->unexplore_terrain(v4, v4->owner, 0, -1);
            v4->world_z = z;
            v17 = v4->object_state;
            v4->world_x = x;
            v4->world_y = y;
            v4->tile = (RGE_Tile *)v15;
            if( v17 == 2 )
                v4->vfptr->explore_terrain(v4, v4->owner, 0, -1);
            v5 = rz;
        }
        if( v4->master_obj->radius_z > 0.0 )
        {
            RGE_Static_Object::addToObstructionMap(v4, 2);
            v5 = rz;
        }
        xa = 0.0;
        switch( *(_BYTE *)(v15 + 4) )
        {
            case 1:
                if( *(float *)&ty + rx >= 1.0 )
                    goto LABEL_57;
                v5 = *(float *)&ty;
                break;
            case 2:
                if( *(float *)&ty + rx >= 1.0 )
                    goto LABEL_44;
                v5 = rx;
                goto LABEL_68;
            case 3:
                if( v19 | v20 )
                    v5 = 1.0 - *(float *)&ty;
                else
                    v5 = 1.0 - rx;
                break;
            case 4:
                if( rx <= (double)*(float *)&ty )
                    v5 = rx;
                else
                    v5 = *(float *)&ty;
                break;
            case 5:
                v5 = 1.0 - rx;
                break;
            case 6:
LABEL_44:
                v5 = 1.0 - *(float *)&ty;
                goto LABEL_68;
            case 7:
                v5 = *(float *)&ty;
                break;
            case 8:
                v5 = rx;
                goto LABEL_68;
            case 9:
                v21 = rx - *(float *)&ty;
                if( v21 >= 0.0 )
                    goto LABEL_55;
                v5 = -v21;
                break;
            case 0xA:
                v5 = rx - *(float *)&ty;
                if( v5 <= 0.0 )
                    v5 = 0.0;
                goto LABEL_68;
            case 0xB:
                v22 = *(float *)&ty + rx;
                if( v22 >= 1.0 )
                    goto LABEL_55;
                v5 = 1.0 - v22;
                break;
            case 0xC:
                v23 = *(float *)&ty + rx;
                if( v23 <= 1.0 )
                    goto LABEL_55;
                v5 = v23 - 1.0;
                break;
            case 0:
LABEL_55:
                v5 = 0.0;
                break;
            case 0xD:
                if( *(float *)&ty + rx >= 1.0 )
                    v5 = *(float *)&ty;
                else
LABEL_57:
                    v5 = 1.0 - rx;
                break;
            case 0xE:
                if( *(float *)&ty + rx >= 1.0 )
                    v5 = rx;
                else
                    v5 = 1.0 - *(float *)&ty;
                goto LABEL_68;
            case 0xF:
                if( rx <= (double)*(float *)&ty )
                    v5 = *(float *)&ty;
                else
                    v5 = rx;
                goto LABEL_68;
            case 0x10:
                if( v25 | v26 )
                    v5 = 1.0 - rx;
                else
                    v5 = 1.0 - *(float *)&ty;
LABEL_68:
                xa = 1.0;
                break;
            default:
                break;
        }
        v27 = v4->master_obj;
        result = v5 + (double)(unsigned __int8)(*((_BYTE *)v4->tile + 5) >> 5);
        if( !v27->movement_type || v27->movement_type == 1 && result > v4->world_z )
            v4->world_z = result;
        zd = *(float *)&ty + rx;
        v4->screen_x_offset = (signed __int64)((double)map->tile_half_width * zd);
        v28 = xa + *(float *)&ty - -1.0 - rx;
        v4->screen_y_offset = (signed __int64)((v28 - v4->world_z) * (double)map->tile_half_height);
        if( v27->movement_type )
        {
            if( v27->movement_type == 1 )
            {
                v4->shadow_x_offset = (signed __int64)((double)map->tile_half_width * zd);
                xb = v28;
                v4->shadow_y_offset = (signed __int64)((xb - result) * (double)map->tile_half_height);
            }
        }
        else
        {
            v29 = v4->screen_y_offset;
            v4->shadow_x_offset = v4->screen_x_offset;
            v4->shadow_y_offset = v29;
        }
    }
    return result;
}

//----- (004C4BD0) --------------------------------------------------------
void RGE_Static_Object::new_sprite(RGE_Sprite *nsprite)
{
    RGE_Sprite *v2; // edi@1
    RGE_Static_Object *v3; // esi@1
    RGE_Sprite *v4; // eax@3
    RGE_Sprite *v5; // ecx@4
    RGE_Active_Sprite_List *v6; // ecx@6
    RGE_Sprite *v7; // ST0C_4@6
    RGE_Active_Sprite_List *v8; // ecx@6

    v2 = nsprite;
    v3 = this;
    if( !nsprite )
        v2 = this->master_obj->sprite;
    v4 = this->sprite;
    if( v4 != v2 )
    {
        v5 = this->master_obj->death_sprite;
        if( v4 != v5 || !v5 )
        {
            v6 = v3->sprite_list;
            v7 = v3->sprite;
            v3->old_sprite = v4;
            RGE_Active_Sprite_List::remove_sprite(v6, v7);
            v8 = v3->sprite_list;
            v3->sprite = v2;
            RGE_Active_Sprite_List::add_sprite(v8, v2, 60, 0, 0);
            v3->facet = 0;
        }
    }
}

//----- (004C4C20) --------------------------------------------------------
void RGE_Static_Object::add_overlay_sprite(RGE_Sprite *nsprite, char order)
{
    RGE_Active_Sprite_List::add_sprite(this->sprite_list, nsprite, order, 0, 0);
}

//----- (004C4C40) --------------------------------------------------------
void RGE_Static_Object::remove_overlay_sprite(RGE_Sprite *nsprite)
{
    RGE_Active_Sprite_List::remove_sprite(this->sprite_list, nsprite);
}

//----- (004C4C50) --------------------------------------------------------
void RGE_Static_Object::change_ownership(RGE_Player *new_owner)
{
    RGE_Static_Object *v3; // esi@1
    float hp_num; // ST2C_4@4
    RGE_Object_Node *v5; // eax@6
    RGE_Master_Static_Object *v6; // edx@6
    RGE_Master_Static_Object *v7; // ebp@6
    RGE_Sprite *v8; // ecx@6
    RGE_Sprite *v9; // eax@8
    char v10; // al@14
    float retaddr; // [sp+30h] [bp+0h]@14

    v3 = this;
    if( !new_owner->master_objects[this->master_obj->id] )
        return;
    if( this->selected & 1 )
        RGE_Player::unselect_one_object(this->owner, this);
    hp_num = v3->hp / (double)v3->master_obj->hp;
    RGE_Static_Object::take_attribute_from_owner(v3);
    if( v3->object_state == 2 )
        v3->vfptr->unexplore_terrain(v3, v3->owner, 0, -1);
    ((void (__stdcall *)(RGE_Static_Object *, _DWORD, _DWORD, RGE_Object_Node *, int))v3->owner->vfptr->removeObject)(
        v3,
        v3->sleep_flag,
        v3->dopple_flag,
        v3->player_object_node,
        a2);
    v5 = new_owner->vfptr->addObject(new_owner, v3, v3->sleep_flag, v3->dopple_flag);
    v6 = v3->master_obj;
    v3->player_object_node = v5;
    v7 = new_owner->master_objects[v6->id];
    v8 = v3->sprite;
    if( v8 == v6->sprite )
        goto LABEL_11;
    if( v8 != v6->death_sprite )
    {
        if( v8 == v6->undead_sprite )
        {
            v9 = v7->undead_sprite;
            goto LABEL_12;
        }
LABEL_11:
        v9 = v7->sprite;
        goto LABEL_12;
    }
    v9 = v7->death_sprite;
LABEL_12:
    if( v9 )
        (*(void (**)(RGE_Static_Object *, RGE_Sprite *))&v3->vfptr->gap4[52])(v3, v9);
    v3->owner = new_owner;
    v3->master_obj = v7;
    v10 = v3->object_state;
    v3->hp = (double)v7->hp * retaddr;
    if( v10 == 2 )
        v3->vfptr->explore_terrain(v3, new_owner, 0, -1);
    RGE_Static_Object::give_attribute_to_owner(v3);
    ((void (*)(RGE_Static_Object *, int, int, signed int, _DWORD, _DWORD))v3->vfptr->notify)(
        v3,
        v3->id,
        v3->id,
        523,
        new_owner->id,
        0);
}
// 4C4C50: could not find valid save-restore pair for ebp

//----- (004C4D80) --------------------------------------------------------
void RGE_Static_Object::modify(float amount, char flag)
{
    RGE_Static_Object *v3; // esi@1
    RGE_Static_ObjectVtbl *v4; // edi@5

    v3 = this;
    if( flag )
    {
        if( flag == 1 && this->tile && this->object_state == 2 )
        {
            v4 = this->vfptr;
            ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->vfptr->unexplore_terrain)(this->owner, 0, -1);
            ((void (__fastcall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD, _DWORD))v4->explore_terrain)(
                v3,
                (unsigned __int64)(signed __int64)amount >> 32,
                v3->owner,
                0,
                (signed __int64)amount);
        }
    }
    else
    {
        this->hp = (double)(signed short)(signed __int64)(amount * this->hp / (double)this->master_obj->hp);
    }
}

//----- (004C4E00) --------------------------------------------------------
void RGE_Static_Object::modify_delta(float amount, char flag)
{
    RGE_Static_Object *v3; // esi@1
    RGE_Static_ObjectVtbl *v4; // edi@5
    double v5; // st7@6

    v3 = this;
    if( flag )
    {
        if( flag == 1 && this->tile && this->object_state == 2 )
        {
            v4 = this->vfptr;
            ((void (__stdcall *)(RGE_Player *, _DWORD, signed int))this->vfptr->unexplore_terrain)(this->owner, 0, -1);
            v4->explore_terrain(v3, v3->owner, 0, (signed __int64)(v3->master_obj->los + amount));
        }
    }
    else
    {
        v5 = (double)this->master_obj->hp;
        this->hp = (double)(signed short)(signed __int64)((amount + v5) * this->hp / v5);
    }
}

//----- (004C4E90) --------------------------------------------------------
void RGE_Static_Object::modify_percent(float amount, char flag)
{
    RGE_Static_Object *v3; // esi@1
    RGE_Static_ObjectVtbl *v4; // edi@5

    v3 = this;
    if( flag )
    {
        if( flag == 1 && this->tile && this->object_state == 2 )
        {
            v4 = this->vfptr;
            ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->vfptr->unexplore_terrain)(this->owner, 0, -1);
            v4->explore_terrain(v3, v3->owner, 0, (signed __int64)(v3->master_obj->los * amount));
        }
    }
    else
    {
        this->hp = (double)(signed short)(signed __int64)(amount * this->hp);
    }
}

//----- (004C4F10) --------------------------------------------------------
void RGE_Static_Object::transform(RGE_Master_Static_Object *obj)
{
    RGE_Static_Object *v2; // esi@1
    RGE_Tile *v3; // eax@3
    RGE_Static_ObjectVtbl *v4; // edi@5
    double v5; // st7@5
    float hp_num; // [sp+1Ch] [bp-4h]@1

    v2 = this;
    hp_num = this->hp / (double)this->master_obj->hp;
    if( this->tile )
        this->vfptr->unexplore_terrain(this, this->owner, 0, -1);
    RGE_Static_Object::removeFromObstructionMap(v2, 2);
    v3 = v2->tile;
    v2->master_obj = obj;
    if( v3 )
        v2->vfptr->explore_terrain(v2, v2->owner, 0, -1);
    RGE_Static_Object::addToObstructionMap(v2, 2);
    v4 = v2->vfptr;
    (*(void (**)(RGE_Static_Object *, RGE_Sprite *))&v2->vfptr->gap4[52])(v2, obj->sprite);
    v5 = (double)obj->hp;
    v2->object_state = 0;
    v2->hp = v5 * hp_num;
    v4->set_object_state(v2, 2);
}

//----- (004C4FB0) --------------------------------------------------------
void RGE_Static_Object::copy_obj(RGE_Master_Static_Object *source)
{
    RGE_Static_Object *v2; // esi@1
    RGE_Sprite *v3; // ebx@1
    RGE_Static_ObjectVtbl *v4; // edi@3
    char v5; // al@4
    double v6; // st7@4
    RGE_Master_Static_Object *v7; // edi@6
    RGE_Sprite *v8; // eax@6
    char v9; // al@12
    double v10; // st7@12
    float hp_num; // [sp+18h] [bp-4h]@4

    v2 = this;
    v3 = 0;
    if( this->tile && this->object_state == 2 )
    {
        v4 = this->vfptr;
        ((void (__stdcall *)(RGE_Player *, _DWORD, signed int))this->vfptr->unexplore_terrain)(this->owner, 0, -1);
        ((void (__fastcall *)(RGE_Static_Object *, _DWORD, RGE_Player *, _DWORD, _DWORD))v4->explore_terrain)(
            v2,
            (unsigned __int64)(signed __int64)source->los >> 32,
            v2->owner,
            0,
            (signed __int64)source->los);
    }
    v5 = v2->object_state;
    v6 = (double)v2->master_obj->hp;
    hp_num = v2->hp / v6;
    v2->hp = v6;
    if( v5 == 2 )
        (*(void (**)(RGE_Static_Object *))&v2->vfptr->gap4[36])(v2);
    v7 = v2->master_obj;
    v8 = v2->sprite;
    if( v8 == v7->sprite )
    {
        v3 = source->sprite;
    }
    else if( v8 == v7->death_sprite )
    {
        v3 = source->death_sprite;
    }
    else if( v8 == v7->undead_sprite )
    {
        v3 = source->undead_sprite;
    }
    v9 = v2->object_state;
    v10 = (double)source->hp;
    v2->master_obj = source;
    v2->hp = v10 * hp_num;
    if( v9 == 2 )
        (*(void (**)(RGE_Static_Object *))&v2->vfptr->gap4[36])(v2);
    v2->master_obj = v7;
    if( v3 )
        (*(void (**)(RGE_Static_Object *, RGE_Sprite *))&v2->vfptr->gap4[52])(v2, v3);
}

//----- (004C5080) --------------------------------------------------------
void RGE_Static_Object::destroy_obj()
{
    RGE_Static_Object *v1; // esi@1

    v1 = this;
    if( this->object_state < 7u )
    {
        if( this->inside_obj )
            ((void (*)(void))this->vfptr->exit_obj)();
        if( v1->selected & 1 )
            RGE_Player::unselect_one_object(v1->owner, v1);
        RGE_Static_Object::set_sleep_flag(v1, 0);
        v1->vfptr->set_object_state(v1, 7);
    }
}

//----- (004C50C0) --------------------------------------------------------
void RGE_Static_Object::die_die_die()
{
    RGE_Static_Object *v1; // esi@1

    v1 = this;
    if( this->selected & 1 )
        RGE_Player::unselect_one_object(this->owner, this);
    RGE_Static_Object::set_sleep_flag(v1, 0);
    LODWORD(v1->hp) = 0;
}

//----- (004C50F0) --------------------------------------------------------
void RGE_Static_Object::remove_visible_resource()
{
    RGE_Static_Object *v1; // esi@1
    RGE_Master_Static_Object *v2; // eax@3
    unsigned int v3; // ebp@6
    unsigned int v4; // ebx@6
    unsigned int v5; // ebp@6
    int v6; // edi@7
    RGE_Master_Static_Object *v7; // eax@9
    RGE_Player *v8; // ST00_4@14
    unsigned int ExploredVal; // [sp+14h] [bp-4h]@6

    v1 = this;
    if( this->id >= 0 )
    {
        if( this->owner )
        {
            v2 = this->master_obj;
            if( v2 )
            {
                if( v2->create_doppleganger_on_death || v2->track_as_resource )
                {
                    v4 = (unsigned int)(&unified_map_offsets)[(unsigned int)(signed __int64)this->world_y][(unsigned int)(signed __int64)this->world_x];
                    v3 = v4;
                    v4 = (unsigned short)v4;
                    v5 = v3 >> 16;
                    ExploredVal = (unsigned short)v4;
                    if( v5 )
                    {
                        v6 = 0;
                        do
                        {
                            if( (v5 & 1) == 1 )
                            {
                                v7 = v1->master_obj;
                                if( v7->track_as_resource )
                                    Visible_Resource_Manager::Remove_Resource(
                                        v1->owner->world->players[v6]->VR_List,
                                        v1->id,
                                        v7->resource_group);
                                if( v1->master_obj->create_doppleganger_on_death == 1 && !(v4 & 1) && v6 > 0 )
                                {
                                    v8 = v1->owner->world->players[v6];
                                    (*(void (__stdcall **)(RGE_Player *, _DWORD, _DWORD, _DWORD, RGE_Static_Object *))(**((_DWORD **)v8->master_objects + 243) + 56))(
                                        v8,
                                        LODWORD(v1->world_x),
                                        LODWORD(v1->world_y),
                                        LODWORD(v1->world_z),
                                        v1);
                                    v4 = ExploredVal;
                                }
                            }
                            ++v6;
                            v4 >>= 1;
                            v5 >>= 1;
                            ExploredVal = v4;
                        }
                        while( v5 );
                    }
                    if( v1->master_obj->create_doppleganger_on_death == 2 )
                        RGE_Doppleganger_Creator::remove_doppleganger_check(v1->owner->doppleganger_creator, v1);
                }
            }
        }
    }
}
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (004C5210) --------------------------------------------------------
void RGE_Static_Object::create_doppleganger_when_dying()
{
    RGE_Static_Object *v1; // esi@1
    RGE_Master_Static_Object *v2; // eax@3
    unsigned int v3; // ebp@5
    unsigned int v4; // eax@5
    unsigned int v5; // ebp@5
    int v6; // edi@6
    RGE_Player *v7; // ST00_4@10
    unsigned int ExploredVal; // [sp+14h] [bp-4h]@5

    v1 = this;
    if( this->id >= 0 )
    {
        if( this->owner )
        {
            v2 = this->master_obj;
            if( v2 )
            {
                if( v2->create_doppleganger_on_death == 2 )
                {
                    v4 = (unsigned int)(&unified_map_offsets)[(unsigned int)(signed __int64)this->world_y][(unsigned int)(signed __int64)this->world_x];
                    v3 = v4;
                    v4 = (unsigned short)v4;
                    v5 = v3 >> 16;
                    ExploredVal = (unsigned short)v4;
                    if( v5 )
                    {
                        v6 = 0;
                        do
                        {
                            if( (v5 & 1) == 1 && !(v4 & 1) && v6 > 0 )
                            {
                                v7 = v1->owner->world->players[v6];
                                (*(void (__stdcall **)(RGE_Player *, _DWORD, _DWORD, _DWORD, RGE_Static_Object *))(**((_DWORD **)v7->master_objects + 243)
                                                                                                                                                                                                 + 56))(
                                    v7,
                                    LODWORD(v1->world_x),
                                    LODWORD(v1->world_y),
                                    LODWORD(v1->world_z),
                                    v1);
                                v4 = ExploredVal;
                            }
                            ++v6;
                            v4 >>= 1;
                            v5 >>= 1;
                            ExploredVal = v4;
                        }
                        while( v5 );
                    }
                    RGE_Doppleganger_Creator::add_doppleganger_check(
                        v1->owner->doppleganger_creator,
                        v1,
                        (unsigned int *)&(&unified_map_offsets)[(unsigned int)(signed __int64)v1->world_y][(unsigned __int64)(signed __int64)v1->world_x]);
                }
            }
        }
    }
}
// 886808: using guessed type unsigned __int32 **unified_map_offsets;

//----- (004C52F0) --------------------------------------------------------
void RGE_Static_Object::set_object_state(char new_object_state)
{
    RGE_Static_Object *v2; // esi@1
    char v3; // al@1
    RGE_Static_ObjectVtbl *v4; // edi@12
    signed int v5; // eax@22
    int v6; // ebx@23
    int v7; // ebp@25
    int *v8; // edi@25
    int i; // eax@26
    int v10; // ebp@32
    int *v11; // edi@32
    int j; // eax@33
    RGE_Static_Object *v13; // eax@37
    RGE_Static_Object *v14; // edi@37
    int v15; // ebp@42
    int *v16; // edi@42
    int k; // eax@43
    int v18; // ebp@50
    int *v19; // edi@50
    int l; // eax@51
    AIPlayStatus *v21; // ST10_4@57
    UnitAIModule *v22; // eax@57
    char v23; // al@60
    int newCommander; // [sp+24h] [bp-4h]@23
    RGE_Static_Object *new_object_statea; // [sp+2Ch] [bp+4h]@37

    v2 = this;
    v3 = this->object_state;
    if( v3 != new_object_state )
    {
        if( (unsigned __int8)new_object_state >= 3u && (unsigned __int8)v3 < 3u )
        {
            RGE_Static_Object::take_attribute_from_owner(this);
            if( v2->master_obj->create_doppleganger_on_death == 2 )
                v2->vfptr->create_doppleganger_when_dying(v2);
        }
        if( v2->object_state <= 3u && (unsigned __int8)new_object_state >= 7u )
            v2->vfptr->remove_visible_resource(v2);
        if( (unsigned __int8)new_object_state >= 3u && v2->object_state == 2 )
        {
            if( v2->tile )
            {
                v4 = v2->vfptr;
                v2->vfptr->unexplore_terrain(v2, v2->owner, 0, -1);
                if( v2->master_obj->los > 0.0 )
                    v4->explore_terrain(v2, v2->owner, 1, -1);
            }
        }
        if( v2->object_state < 7u && new_object_state == 7 && v2->tile && v2->master_obj->los > 0.0 )
            v2->vfptr->unexplore_terrain(v2, v2->owner, 1, -1);
        v2->object_state = new_object_state;
        if( new_object_state == 3 && v2->groupCommanderValue == v2->id )
        {
            if( v2->unitAIValue )
            {
                v5 = v2->groupMembers.numberValue;
                if( v5 > 1 )
                {
                    v6 = 0;
                    newCommander = -1;
                    if( v5 > 0 )
                    {
                        do
                        {
                            if( v6 > v2->groupMembers.maximumSizeValue - 1 )
                            {
                                v7 = v6 + 1;
                                v8 = (int *)operator new(4 * v6 + 4);
                                if( v8 )
                                {
                                    for( i = 0; i < v2->groupMembers.maximumSizeValue; v8[i - 1] = v2->groupMembers.value[i - 1] )
                                    {
                                        if( i >= v7 )
                                            break;
                                        ++i;
                                    }
                                    operator delete(v2->groupMembers.value);
                                    v2->groupMembers.value = v8;
                                    v2->groupMembers.maximumSizeValue = v7;
                                }
                            }
                            if( v2->groupMembers.value[v6] != v2->id )
                            {
                                if( v6 > v2->groupMembers.maximumSizeValue - 1 )
                                {
                                    v10 = v6 + 1;
                                    v11 = (int *)operator new(4 * v6 + 4);
                                    if( v11 )
                                    {
                                        for( j = 0; j < v2->groupMembers.maximumSizeValue; v11[j - 1] = v2->groupMembers.value[j - 1] )
                                        {
                                            if( j >= v10 )
                                                break;
                                            ++j;
                                        }
                                        operator delete(v2->groupMembers.value);
                                        v2->groupMembers.value = v11;
                                        v2->groupMembers.maximumSizeValue = v10;
                                    }
                                }
                                v13 = RGE_Game_World::object(v2->owner->world, v2->groupMembers.value[v6]);
                                v14 = v13;
                                new_object_statea = v13;
                                if( v13 && v13->object_state <= 2u && RGE_Static_Object::unitAI(v13) )
                                {
                                    if( newCommander == -1 )
                                    {
                                        if( v6 > v2->groupMembers.maximumSizeValue - 1 )
                                        {
                                            v15 = v6 + 1;
                                            v16 = (int *)operator new(4 * v6 + 4);
                                            if( v16 )
                                            {
                                                for( k = 0; k < v2->groupMembers.maximumSizeValue; v16[k - 1] = v2->groupMembers.value[k - 1] )
                                                {
                                                    if( k >= v15 )
                                                        break;
                                                    ++k;
                                                }
                                                operator delete(v2->groupMembers.value);
                                                v2->groupMembers.value = v16;
                                                v2->groupMembers.maximumSizeValue = v15;
                                            }
                                            v14 = new_object_statea;
                                        }
                                        newCommander = v2->groupMembers.value[v6];
                                    }
                                    v14->groupCommanderValue = newCommander;
                                    if( v6 > v2->groupMembers.maximumSizeValue - 1 )
                                    {
                                        v18 = v6 + 1;
                                        v19 = (int *)operator new(4 * v6 + 4);
                                        if( v19 )
                                        {
                                            for( l = 0; l < v2->groupMembers.maximumSizeValue; v19[l - 1] = v2->groupMembers.value[l - 1] )
                                            {
                                                if( l >= v18 )
                                                    break;
                                                ++l;
                                            }
                                            operator delete(v2->groupMembers.value);
                                            v2->groupMembers.value = v19;
                                            v2->groupMembers.maximumSizeValue = v18;
                                        }
                                        v14 = new_object_statea;
                                    }
                                    if( v2->groupMembers.value[v6] == newCommander )
                                    {
                                        v21 = v2->unitAIValue->playStatus;
                                        v22 = RGE_Static_Object::unitAI(v14);
                                        UnitAIModule::setPlayStatus(v22, v21);
                                    }
                                }
                            }
                            ++v6;
                        }
                        while( v6 < v2->groupMembers.numberValue );
                    }
                }
            }
        }
        if( v2->sleep_flag )
        {
            v23 = v2->object_state;
            if( v23 != 2 && v23 != 6 )
                RGE_Static_Object::set_sleep_flag(v2, 0);
        }
    }
}

//----- (004C5610) --------------------------------------------------------
RGE_Static_Object *RGE_Static_Object::check_object_bounds()
{
    RGE_Static_Object *v1; // ebx@1
    RGE_Master_Static_Object *v2; // eax@1
    int v3; // edi@3
    int v4; // esi@3
    int v5; // ebp@3
    int v6; // edx@3
    RGE_Map *v7; // eax@3
    int v8; // ecx@11
    int v9; // esi@13
    RGE_Object_Node **v10; // edi@14
    RGE_Object_Node *v11; // ecx@15
    RGE_Static_Object *v12; // edx@16
    RGE_Master_Static_Object *v13; // eax@16
    double v14; // st7@18
    char v16; // c0@18
    RGE_Static_Object *result; // eax@29
    float v18; // [sp+10h] [bp-2Ch]@18
    int x1; // [sp+14h] [bp-28h]@3
    float ry2; // [sp+18h] [bp-24h]@16
    float ry; // [sp+1Ch] [bp-20h]@1
    float rx2; // [sp+20h] [bp-1Ch]@16
    float rx; // [sp+24h] [bp-18h]@1
    int x2; // [sp+28h] [bp-14h]@3
    int y2; // [sp+2Ch] [bp-10h]@3
    int y_index; // [sp+30h] [bp-Ch]@11
    RGE_Tile **v27; // [sp+34h] [bp-8h]@12
    int v28; // [sp+38h] [bp-4h]@12

    v1 = this;
    v2 = this->master_obj;
    rx = v2->radius_x;
    ry = v2->radius_y;
    if( rx <= 0.0 && ry <= 0.0 )
        goto LABEL_34;
    v3 = (signed __int64)(this->world_x - 3.0);
    x1 = (signed __int64)(this->world_x - 3.0);
    v4 = (signed __int64)(this->world_y - 3.0);
    v5 = (signed __int64)(this->world_x - -3.0);
    x2 = (signed __int64)(this->world_x - -3.0);
    v6 = (signed __int64)(this->world_y - -3.0);
    y2 = (signed __int64)(this->world_y - -3.0);
    v7 = this->owner->world->map;
    if( (signed short)v3 < 0 )
    {
        x1 = 0;
        v3 = 0;
    }
    if( (signed short)v5 >= v7->map_width )
    {
        LOWORD(v5) = LOWORD(v7->map_width) - 1;
        LOWORD(x2) = LOWORD(v7->map_width) - 1;
    }
    if( (signed short)v4 < 0 )
        v4 = 0;
    if( (signed short)v6 >= v7->map_height )
    {
        LOWORD(v6) = LOWORD(v7->map_height) - 1;
        LOWORD(y2) = LOWORD(v7->map_height) - 1;
    }
    v8 = v4;
    y_index = v4;
    if( (signed short)v4 > (signed short)v6 )
    {
LABEL_34:
        result = 0;
    }
    else
    {
        v27 = v7->map_row_offset;
        v28 = (signed short)v3;
        while( 1 )
        {
            v9 = v3;
            if( (signed short)v3 <= (signed short)v5 )
                break;
LABEL_28:
            y_index = ++v8;
            if( (signed short)v8 > (signed short)v6 )
                return 0;
        }
        v10 = &v27[(signed short)v8][v28].objects.list;
        while( 1 )
        {
            v11 = *v10;
            if( *v10 )
                break;
LABEL_26:
            v10 += 6;
            if( (signed short)++v9 > (signed short)v5 )
            {
                v3 = x1;
                v8 = y_index;
                goto LABEL_28;
            }
        }
        while( 1 )
        {
            v12 = v11->node;
            v13 = v11->node->master_obj;
            rx2 = v13->radius_x;
            ry2 = v13->radius_y;
            if( rx2 > 0.0 && ry2 > 0.0 )
            {
                v14 = v12->world_y - v1->world_y;
                v18 = v12->world_x - v1->world_x;
                if( v16 )
                    v14 = -v14;
                if( v18 < 0.0 )
                    v18 = -v18;
                if( v14 <= ry2 + ry && v18 <= rx2 + rx )
                    break;
            }
            v11 = v11->next;
            if( !v11 )
            {
                LOWORD(v5) = x2;
                LOWORD(v6) = y2;
                goto LABEL_26;
            }
        }
        result = v11->node;
    }
    return result;
}

//----- (004C5820) --------------------------------------------------------
double RGE_Static_Object::get_terrain_speed(char terrain)
{
    return this->owner->world->terrains[this->master_obj->terrain][(unsigned __int8)terrain];
}

//----- (004C5850) --------------------------------------------------------
char RGE_Static_Object::is_moving()
{
    return 0;
}

//----- (004C5860) --------------------------------------------------------
bool RGE_Static_Object::is_dying()
{
    char v1; // al@1

    v1 = this->object_state;
    return (unsigned __int8)v1 >= 3u && v1 != 6;
}

//----- (004C5880) --------------------------------------------------------
int RGE_Static_Object::get_frame(short *min_x, short *min_y, short *max_x, short *max_y)
{
    RGE_Static_Object *v5; // eax@1
    RGE_Sprite *v6; // esi@1
    RGE_Active_Sprite_List *v7; // ecx@2
    int result; // eax@3

    v5 = this;
    v6 = this->sprite;
    if( v6 && (v7 = this->sprite_list) != 0 )
        result = (unsigned __int8)RGE_Active_Sprite_List::get_frame(v7, min_x, min_y, max_x, max_y, v6, v5->facet);
    else
        result = 0;
    return result;
}

//----- (004C58C0) --------------------------------------------------------
bool RGE_Static_Object::more_room()
{
    return this->objects->number_of_objects < this->master_obj->obj_max;
}

//----- (004C58E0) --------------------------------------------------------
void RGE_Static_Object::enter_obj(RGE_Static_Object *target)
{
    RGE_Static_Object *v2; // esi@1
    RGE_Static_Object *v3; // ecx@2

    v2 = this;
    if( RGE_Static_Object::more_room(target) )
    {
        v3 = v2->inside_obj;
        if( v3 )
            ((void (*)(void))v3->vfptr->exit_obj)();
        if( v2->tile )
        {
            v2->vfptr->unexplore_terrain(v2, v2->owner, 0, -1);
            RGE_Object_List::remove_node(&v2->tile->objects, v2, 0);
            v2->tile = 0;
        }
        RGE_Static_Object::removeFromObstructionMap(v2, 2);
        RGE_Object_List::add_node(target->objects, v2);
        v2->inside_obj = target;
        v2->world_x = target->world_x;
        v2->world_y = target->world_y;
    }
}

//----- (004C5960) --------------------------------------------------------
void RGE_Static_Object::exit_obj()
{
    RGE_Static_Object *v1; // esi@1
    RGE_Static_Object *v2; // eax@1

    v1 = this;
    v2 = this->inside_obj;
    if( v2 )
    {
        RGE_Object_List::remove_node(v2->objects, this, 0);
        v1->inside_obj = 0;
    }
}

//----- (004C5980) --------------------------------------------------------
struct LOSTBL **RGE_Static_Object::get_los_table()
{
    RGE_Player *v1; // esi@1
    struct LOSTBL **result; // eax@2
    double v3; // st7@3
    RGE_Visible_Map *v4; // ecx@3

    v1 = this->owner;
    if( v1 )
    {
        v3 = this->master_obj->los;
        v4 = v1->visible;
        result = RGE_Visible_Map::get_los_table((signed __int64)v3, 0);
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004C59B0) --------------------------------------------------------
int RGE_Static_Object::explore_terrain(RGE_Player *whos, char explore_type, int Override_LOS)
{
    RGE_Static_Object *v4; // esi@1
    signed __int64 v5; // rax@2
    RGE_Visible_Map *v6; // ebx@5
    int v7; // ecx@5
    int result; // eax@6
    RGE_Master_Static_Object *v9; // edi@7

    v4 = this;
    if( !whos )
        goto LABEL_13;
    LODWORD(v5) = Override_LOS;
    if( Override_LOS == -1 )
        v5 = (signed __int64)this->master_obj->los;
    if( (signed int)v5 <= 0 )
        goto LABEL_13;
    v6 = whos->visible;
    v7 = whos->id == whos->world->curr_player;
    if( !explore_type )
        return RGE_Visible_Map::explore_terrain(
                         v6,
                         (signed __int64)v4->world_x,
                         (signed __int64)v4->world_y,
                         v5,
                         0,
                         v7,
                         v4->id);
    v9 = v4->master_obj;
    if( v9->radius_x > 0.0 && v9->radius_y > 0.0 )
        result = RGE_Visible_Map::explore_terrain_sq(
                             v6,
                             (signed __int64)(v4->world_x - v9->radius_x),
                             (signed __int64)(v4->world_y - v9->radius_y),
                             (signed __int64)(v4->world_x + v9->radius_x - 0.0099999998),
                             (signed __int64)(v4->world_y + v9->radius_y - 0.0099999998),
                             v7,
                             v4->id);
    else
LABEL_13:
        result = 0;
    return result;
}

//----- (004C5AA0) --------------------------------------------------------
void RGE_Static_Object::unexplore_terrain(RGE_Player *whos, char explore_type, int Override_LOS)
{
    RGE_Static_Object *v4; // esi@1
    signed __int64 v5; // rax@2
    RGE_Visible_Map *v6; // ebx@5
    int v7; // ecx@5
    RGE_Master_Static_Object *v8; // edi@7

    v4 = this;
    if( whos )
    {
        LODWORD(v5) = Override_LOS;
        if( Override_LOS == -1 )
            v5 = (signed __int64)this->master_obj->los;
        if( (signed int)v5 > 0 )
        {
            v6 = whos->visible;
            v7 = whos->id == whos->world->curr_player;
            if( explore_type )
            {
                v8 = v4->master_obj;
                if( v8->radius_x > 0.0 && v8->radius_y > 0.0 )
                    RGE_Visible_Map::unexplore_terrain_sq(
                        v6,
                        (signed __int64)(v4->world_x - v8->radius_x),
                        (signed __int64)(v4->world_y - v8->radius_y),
                        (signed __int64)(v4->world_x + v8->radius_x - 0.0099999998),
                        (signed __int64)(v4->world_y + v8->radius_y - 0.0099999998),
                        v7,
                        v4->id);
            }
            else
            {
                RGE_Visible_Map::unexplore_terrain(
                    v6,
                    (signed __int64)v4->world_x,
                    (signed __int64)v4->world_y,
                    v5,
                    0,
                    v7,
                    v4->id);
            }
        }
    }
}

//----- (004C5B90) --------------------------------------------------------
void RGE_Static_Object::damage(RGE_Static_Object *this@<ecx>, double a2@<st0>, int weapon_num, RGE_Armor_Weapon_Info *damage, float attack_modifier, RGE_Player *attacking_player, RGE_Static_Object *attackingObject)
{
    RGE_Static_Object *v7; // esi@1
    double v8; // st7@1

    v7 = this;
    ((void (__stdcall *)(int, RGE_Armor_Weapon_Info *, _DWORD, RGE_Player *, RGE_Static_Object *))this->vfptr->calculateDamage)(
        weapon_num,
        damage,
        LODWORD(attack_modifier),
        attacking_player,
        attackingObject);
    v8 = v7->hp - a2;
    v7->hp = v8;
    if( v8 < 1.0 )
    {
        LODWORD(v7->hp) = 0;
        RGE_Static_Object::set_sleep_flag(v7, 0);
    }
}

//----- (004C5BE0) --------------------------------------------------------
double __stdcall RGE_Static_Object::calculateDamage(int weapon_num, RGE_Armor_Weapon_Info *damage, float attack_modifier, RGE_Player *attacking_player, RGE_Static_Object *attackingObject)
{
    int v6; // ecx@1
    double result; // st7@1
    char *v8; // eax@2
    int weapon_numa; // [sp+4h] [bp+4h]@3

    v6 = weapon_num;
    result = 0.0;
    if( weapon_num > 0 )
    {
        v8 = (char *)&damage->value;
        do
        {
            weapon_numa = *(_WORD *)v8;
            v8 += 4;
            --v6;
            result = result + (double)weapon_numa * attack_modifier;
        }
        while( v6 );
    }
    return result;
}

//----- (004C5C10) --------------------------------------------------------
void RGE_Static_Object::rotate(int amount)
{
    int v2; // edx@1
    int i; // eax@1

    v2 = this->sprite->facet_num;
    for( i = this->facet + amount; i < 0; i += v2 )
        ;
    for( ; i >= v2; i -= v2 )
        ;
    this->facet = i;
}

//----- (004C5C40) --------------------------------------------------------
void RGE_Static_Object::set_attribute(short attr_type, float attr_amount)
{
    this->attribute_type_held = attr_type;
    this->attribute_amount_held = attr_amount;
}

//----- (004C5C60) --------------------------------------------------------
void RGE_Static_Object::set_attribute_amount(float attr_amount, char delta, char check_max)
{
    double v4; // st7@5

    if( delta )
        this->attribute_amount_held = attr_amount + this->attribute_amount_held;
    else
        this->attribute_amount_held = attr_amount;
    if( check_max )
    {
        v4 = (double)this->master_obj->attribute_max_amount;
        if( v4 < this->attribute_amount_held )
            this->attribute_amount_held = v4;
    }
}

//----- (004C5CB0) --------------------------------------------------------
char RGE_Static_Object::heal(float healing)
{
    double v3; // st7@1
    char v4; // c0@1
    double v5; // st7@4
    char result; // al@5

    v3 = healing + this->hp;
    this->hp = v3;
    if( v4 && v3 < 1.0 )
        LODWORD(this->hp) = 1065353216;
    v5 = (double)this->master_obj->hp;
    if( v5 > this->hp )
    {
        result = 0;
    }
    else
    {
        this->hp = v5;
        result = 1;
    }
    return result;
}

//----- (004C5D20) --------------------------------------------------------
void RGE_Static_Object::set_being_worked_on(RGE_Action_Object *work_obj, short action_type, char attack_flag)
{
    char v4; // al@1

    v4 = this->worker_num;
    if( (unsigned __int8)v4 < 0xFAu )
        this->worker_num = v4 + 1;
    RGE_Static_Object::set_sleep_flag(this, 0);
}

//----- (004C5D40) --------------------------------------------------------
void RGE_Static_Object::release_being_worked_on(RGE_Static_Object *caller)
{
    char v2; // al@1
    char v3; // dl@4

    v2 = this->worker_num;
    if( v2 )
        this->worker_num = v2 - 1;
    if( !this->worker_num )
    {
        if( (v3 = this->object_state, v3 == 2) && this->hp >= 0.0 || v3 == 6 )
            RGE_Static_Object::set_sleep_flag(this, 1);
    }
}

//----- (004C5D80) --------------------------------------------------------
BOOL RGE_Static_Object::inRange(RGE_Static_Object *obj, float range)
{
    RGE_Static_Object *v3; // edx@1
    double v4; // st7@1
    char v6; // c0@1
    RGE_Master_Static_Object *v7; // eax@5
    RGE_Master_Static_Object *v8; // ecx@5
    double v10; // st7@5
    char v11; // c0@5
    float v13; // [sp+0h] [bp-4h]@5
    RGE_Static_Object *obja; // [sp+8h] [bp+4h]@1

    v3 = obj;
    v4 = obj->world_x - this->world_x;
    *(float *)&obja = obj->world_y - this->world_y;
    if( v6 )
        v4 = -v4;
    if( *(float *)&obja < 0.0 )
        *(float *)&obja = -*(float *)&obja;
    v7 = this->master_obj;
    v8 = v3->master_obj;
    v13 = v4 - v7->radius_x - v8->radius_x;
    v10 = *(float *)&obja - v7->radius_y - v8->radius_y;
    if( v11 )
        v13 = 0.0;
    if( v10 < 0.0 )
        v10 = 0.0;
    return range * range > v13 * v13 + v10 * v10;
}

//----- (004C5E50) --------------------------------------------------------
long double RGE_Static_Object::distance_to_object(RGE_Static_Object *obj)
{
    RGE_Static_Object *v2; // edx@1
    double v3; // st7@1
    char v5; // c0@1
    RGE_Master_Static_Object *v6; // eax@5
    RGE_Master_Static_Object *v7; // ecx@5
    double v9; // st7@5
    char v10; // c0@5
    float v12; // [sp+0h] [bp-4h]@5
    RGE_Static_Object *obja; // [sp+8h] [bp+4h]@1

    v2 = obj;
    v3 = obj->world_x - this->world_x;
    *(float *)&obja = obj->world_y - this->world_y;
    if( v5 )
        v3 = -v3;
    if( *(float *)&obja < 0.0 )
        *(float *)&obja = -*(float *)&obja;
    v6 = this->master_obj;
    v7 = v2->master_obj;
    v12 = v3 - v6->radius_x - v7->radius_x;
    v9 = *(float *)&obja - v6->radius_y - v7->radius_y;
    if( v10 )
        v12 = 0.0;
    if( v9 < 0.0 )
        v9 = 0.0;
    return sqrt(v12 * v12 + v9 * v9);
}

//----- (004C5F00) --------------------------------------------------------
long double RGE_Static_Object::distance_to_position(float x, float y, float z)
{
    double v4; // st7@1
    char v6; // c0@1
    RGE_Master_Static_Object *v7; // eax@5
    double v9; // st7@5
    char v10; // c0@5
    float xa; // [sp+4h] [bp+4h]@1
    float dY; // [sp+8h] [bp+8h]@5

    v4 = this->world_x - x;
    xa = this->world_y - y;
    if( v6 )
        v4 = -v4;
    if( xa < 0.0 )
        xa = -xa;
    v7 = this->master_obj;
    dY = v4 - v7->radius_x;
    v9 = xa - v7->radius_y;
    if( v10 )
        dY = 0.0;
    if( v9 < 0.0 )
        v9 = 0.0;
    return sqrt(dY * dY + v9 * v9);
}

//----- (004C5FA0) --------------------------------------------------------
char RGE_Static_Object::hit_test(int draw_x, int draw_y, short mouse_x, short mouse_y, int check_radius)
{
    RGE_Static_Object *v8; // ebx@1
    RGE_Sprite *v9; // eax@1
    RGE_Active_Sprite_List *v10; // ecx@2
    short v11; // ax@3
    int v12; // edi@3
    int v13; // ebp@3
    char result; // al@4
    signed short v15; // cx@5
    int v16; // esi@6
    int v17; // eax@6
    short v18; // bp@8
    short v19; // di@8
    int draw_xa; // [sp+18h] [bp+4h]@3
    int scr_x; // [sp+1Ch] [bp+8h]@3
    int scr_y; // [sp+20h] [bp+Ch]@6
    int i; // [sp+24h] [bp+10h]@3

    v8 = this;
    v9 = this->sprite;
    if( !v9 )
        goto LABEL_18;
    v10 = this->sprite_list;
    if( !v10 )
        goto LABEL_18;
    v11 = (*((int (__stdcall **)(RGE_Sprite *))&v10->vfptr->__vecDelDtor + 1))(v9);
    LOWORD(a3) = mouse_y - v8->screen_y_offset;
    LOWORD(a2) = mouse_x - v8->screen_x_offset;
    i = v11;
    v12 = a3 - draw_y;
    v13 = a2 - draw_x;
    draw_xa = v13;
    scr_x = v12;
    if( RGE_Sprite::hit_test(v8->sprite, v13, v12, v8->facet, v11) )
        return 1;
    v15 = check_radius;
    if( (_WORD)check_radius
        && (v16 = -check_radius,
                v17 = -check_radius,
                scr_y = -check_radius,
                (signed short)-(signed short)check_radius < (signed short)check_radius) )
    {
        while( (signed short)v16 >= v15 )
        {
LABEL_12:
            scr_y = ++v17;
            if( (signed short)v17 >= v15 )
                return 0;
        }
        v18 = v17 + v13;
        v19 = v16 + v12;
        while( !RGE_Sprite::hit_test(v8->sprite, v18, v19, v8->facet, i) )
        {
            ++v16;
            ++v19;
            if( (signed short)v16 >= (signed short)check_radius )
            {
                LOWORD(v13) = draw_xa;
                LOWORD(v12) = scr_x;
                v17 = scr_y;
                v15 = check_radius;
                v16 = -check_radius;
                goto LABEL_12;
            }
        }
        result = 1;
    }
    else
    {
LABEL_18:
        result = 0;
    }
    return result;
}

//----- (004C60A0) --------------------------------------------------------
char RGE_Static_Object::box_hit_test(int draw_x, int draw_y, short start_x, short start_y, short end_x, short end_y)
{
    RGE_Static_Object *v7; // esi@1
    RGE_Sprite *v8; // eax@1
    RGE_Active_Sprite_List *v9; // ecx@2
    int v10; // eax@3
    int v11; // edi@4
    int v12; // ecx@4
    int v13; // eax@4
    short v14; // bx@4
    short v16; // bp@21
    int min_x; // [sp+10h] [bp-10h]@3
    int min_y; // [sp+14h] [bp-Ch]@3
    int max_x; // [sp+18h] [bp-8h]@3
    int max_y; // [sp+1Ch] [bp-4h]@3

    v7 = this;
    v8 = this->sprite;
    if( v8 )
    {
        v9 = this->sprite_list;
        if( v9 )
        {
            ((void (__stdcall *)(RGE_Sprite *, _WORD))v9->vfptr->get_facetindex)(v8, v7->facet);
            v10 = RGE_Static_Object::get_frame(v7, (short *)&min_x, (short *)&min_y, (short *)&max_x, (short *)&max_y);
            if( v10 )
            {
                LOWORD(v10) = v7->screen_x_offset;
                LOWORD(v7) = v7->screen_y_offset;
                v11 = draw_x + v10 + min_x;
                v12 = draw_x + v10 + max_x;
                v13 = (int)v7 + draw_y + max_y;
                v14 = draw_y + (_WORD)v7 + min_y;
                if( (signed short)v11 >= start_x && (signed short)v11 <= end_x && v14 >= start_y && v14 <= end_y )
                    return 1;
                if( (signed short)v12 >= start_x
                    && (signed short)v12 <= end_x
                    && (signed short)v13 >= start_y
                    && (signed short)v13 <= end_y )
                {
                    return 1;
                }
                if( start_x >= (signed short)v11
                    && start_x <= (signed short)v12
                    && start_y >= v14
                    && start_y <= (signed short)v13 )
                {
                    return 1;
                }
                if( end_x < (signed short)v11 || end_x > (signed short)v12 )
                {
                    v16 = end_y;
                }
                else
                {
                    v16 = end_y;
                    if( end_y >= v14 && end_y <= (signed short)v13 )
                        return 1;
                }
                if( start_x < (signed short)v11 )
                {
                    if( end_x <= (signed short)v12 )
                    {
                        v16 = end_y;
                    }
                    else
                    {
                        if( start_y > v14 && start_y < (signed short)v13 )
                            return 1;
                        v16 = end_y;
                        if( end_y > v14 && end_y < (signed short)v13 )
                            return 1;
                    }
                }
                if( start_y < v14
                    && v16 > (signed short)v13
                    && (start_x > (signed short)v11 && start_x < (signed short)v12
                     || end_x > (signed short)v11 && end_x < (signed short)v12) )
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

//----- (004C6240) --------------------------------------------------------
void RGE_Static_Object::set_location(float x, float y, float z)
{
    this->world_x = x;
    this->world_y = y;
    this->world_z = z;
}

//----- (004C6270) --------------------------------------------------------
char RGE_Static_Object::drop_held_objects(int dropZone)
{
    RGE_Static_Object *v2; // ebx@1
    signed int v3; // esi@1
    RGE_Object_List *v4; // edx@1
    RGE_Master_Static_Object *v5; // eax@1
    double v6; // st7@1
    double v7; // st7@1
    RGE_Object_Node *v8; // eax@1
    float *v9; // ebp@5
    float *v10; // edi@5
    float v11; // edx@9
    RGE_Static_Object *v12; // edi@11
    RGE_Static_ObjectVtbl *v13; // ebp@11
    RGE_Master_Static_Object *v14; // edi@12
    signed int v15; // eax@12
    double v16; // st6@12
    double v17; // st5@12
    double v18; // st7@12
    char count; // [sp+Dh] [bp-B1h]@1
    RGE_Object_Node *temp; // [sp+Eh] [bp-B0h]@1
    float x; // [sp+12h] [bp-ACh]@7
    float y; // [sp+16h] [bp-A8h]@7
    RGE_Object_Node *next; // [sp+1Ah] [bp-A4h]@3
    float drop_y[10]; // [sp+1Eh] [bp-A0h]@1
    float radius_x[10]; // [sp+46h] [bp-78h]@1
    float drop_x[10]; // [sp+6Eh] [bp-50h]@1
    float radius_y[10]; // [sp+96h] [bp-28h]@1

    v2 = this;
    v3 = 1;
    v4 = this->objects;
    drop_x[0] = this->world_x;
    v5 = this->master_obj;
    count = 0;
    v6 = v5->radius_x + v5->radius_x;
    drop_y[0] = this->world_y;
    radius_x[0] = v6;
    v7 = v5->radius_y;
    v8 = v4->list;
    temp = v4->list;
    radius_y[0] = v7 + v7;
    if( v8 )
    {
        while( 1 )
        {
            next = v8->next;
            if( v3 > 0 )
            {
                v9 = &radius_y[v3];
                v10 = &radius_x[v3];
                while( !RGE_Static_Object::find_drop_location(
                                     v2,
                                     dropZone,
                                     &x,
                                     &y,
                                     v8->node->master_obj,
                                     v8->node,
                                     drop_x[0],
                                     drop_y[0],
                                     radius_x[0],
                                     radius_y[0]) )
                {
                    --v3;
                    --v10;
                    --v9;
                    if( v3 <= 0 )
                        goto LABEL_13;
                    v11 = drop_y[v3];
                    drop_x[v3 - 1] = drop_x[v3];
                    *(v9 - 1) = *v9;
                    drop_y[v3 - 1] = v11;
                    *(v10 - 1) = *v10;
                    if( v3 <= 0 )
                        goto LABEL_13;
                    v8 = temp;
                }
                v12 = temp->node;
                RGE_Static_Object::set_location(temp->node, v2->world_x, v2->world_y, v2->world_z);
                v13 = v12->vfptr;
                v12->vfptr->exit_obj(v12);
                (*(void (**)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD))&v13->gap4[48])(
                    v12,
                    LODWORD(x),
                    LODWORD(y),
                    LODWORD(v2->world_z));
                ++count;
                if( v3 < 9 )
                {
                    v14 = v12->master_obj;
                    v15 = v3++;
                    v16 = v14->radius_x + v14->radius_x;
                    v17 = v14->radius_y + v14->radius_y;
                    v18 = y;
                    drop_x[v15] = x;
                    drop_y[v15] = v18;
                    radius_x[v15] = v16;
                    radius_y[v15] = v17;
                }
            }
LABEL_13:
            temp = next;
            if( !next )
                break;
            v8 = next;
        }
    }
    return count;
}

//----- (004C6400) --------------------------------------------------------
char RGE_Static_Object::find_drop_location(int dropZone, float *x, float *y, RGE_Master_Static_Object *m_obj, RGE_Static_Object *obj, float drop_x, float drop_y, float radius_x, float radius_y)
{
    RGE_Master_Static_Object *v10; // ebx@1
    double v11; // st6@1
    double v12; // st7@1
    float *v13; // edi@1
    RGE_Static_Object *v14; // ebp@1
    double v15; // st7@6
    RGE_Map *v16; // ecx@11
    bool v17; // sf@17
    unsigned __int8 v18; // of@17
    float radius_2y; // [sp+34h] [bp-8h]@1
    signed int index; // [sp+38h] [bp-4h]@1
    float *ya; // [sp+48h] [bp+Ch]@2
    float count; // [sp+4Ch] [bp+10h]@1
    float radius_xa; // [sp+5Ch] [bp+20h]@1
    float radius_ya; // [sp+60h] [bp+24h]@1

    v10 = m_obj;
    v11 = radius_x + m_obj->radius_x;
    v12 = radius_y + m_obj->radius_y;
    v13 = y;
    v14 = this;
    radius_xa = v11;
    radius_ya = v12;
    index = 1;
    count = v11 + v11;
    radius_2y = v12 + v12;
    while( 2 )
    {
        ya = 0;
        do
        {
            switch( 4 * debug_rand(aCMsdevWorkA_29, 3898) / 0x7FFF )
            {
                case 0:
                    *x = radius_xa + drop_x;
                    *v13 = (double)debug_rand(aCMsdevWorkA_29, 3902) * radius_2y * 0.000030518509 - radius_ya + drop_y;
                    break;
                case 1:
                    *x = drop_x - radius_xa;
                    *v13 = (double)debug_rand(aCMsdevWorkA_29, 3906) * radius_2y * 0.000030518509 - radius_ya + drop_y;
                    break;
                case 2:
                    *v13 = radius_ya + drop_y;
                    v15 = (double)debug_rand(aCMsdevWorkA_29, 3910);
                    goto LABEL_8;
                case 3:
                    *v13 = drop_y - radius_ya;
                    v15 = (double)debug_rand(aCMsdevWorkA_29, 3914);
LABEL_8:
                    *x = v15 * count * 0.000030518509 - radius_xa + drop_x;
                    break;
                default:
                    break;
            }
            if( *x >= 0.0 && *v13 >= 0.0 )
            {
                v16 = v14->owner->world->map;
                if( (double)v16->map_width > *x
                    && (double)v16->map_height > *v13
                    && (dropZone == -1
                     || dropZone == (unsigned __int8)RGE_Static_Object::lookupZone(v14, (signed __int64)*x, (signed __int64)*v13))
                    && !(unsigned __int8)((int (*)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, float, _DWORD, signed int, signed int, signed int, _DWORD, signed int, signed int))v10->vfptr->check_placement)(
                                                                 v10,
                                                                 v14->owner,
                                                                 *(_DWORD *)x,
                                                                 COERCE_FLOAT(*(_DWORD *)v13),
                                                                 0,
                                                                 1,
                                                                 1,
                                                                 1,
                                                                 0,
                                                                 1,
                                                                 1)
                    && ((int (__stdcall *)(_DWORD, _DWORD, _DWORD))obj->vfptr->passableTile)(*(_DWORD *)x, *(_DWORD *)v13, 0) == 1 )
                {
                    return 1;
                }
            }
            v18 = __OFSUB__((_WORD)ya + 1, 50);
            v17 = (signed short)((_WORD)ya - 49) < 0;
            ya = (float *)((char *)ya + 1);
        }
        while( v17 ^ v18 );
        radius_xa = v10->radius_x + v10->radius_x + radius_xa;
        radius_ya = v10->radius_y + v10->radius_y + radius_ya;
        count = v10->radius_x * 4.0 + count;
        v18 = __OFSUB__(index + 1, 2);
        v17 = (signed short)(index++ - 1) < 0;
        radius_2y = v10->radius_y * 4.0 + radius_2y;
        if( v17 ^ v18 )
            continue;
        return 0;
    }
}

//----- (004C66C0) --------------------------------------------------------
void RGE_Check_List::RGE_Check_List()
{
    this->list = 0;
}

//----- (004C66D0) --------------------------------------------------------
void RGE_Check_List::~RGE_Check_List()
{
    RGE_Check_List *v1; // esi@1
    RGE_Check_Node *v2; // edi@2

    v1 = this;
    if( this->list )
    {
        do
        {
            v2 = v1->list->next;
            free(v1->list);
            v1->list = v2;
        }
        while( v2 );
    }
}

//----- (004C6700) --------------------------------------------------------
void RGE_Check_List::add_node(RGE_Static_Object *obj, float dx, float dy, char flag1)
{
    RGE_Check_List *v5; // esi@1
    RGE_Check_List *v6; // eax@1

    v5 = this;
    v6 = (RGE_Check_List *)calloc(1u, 0x14u);
    v6[4].list = v5->list;
    v6->list = (RGE_Check_Node *)obj;
    *(float *)&v6[1].list = dx;
    *(float *)&v6[2].list = dy;
    LOBYTE(v6[3].list) = flag1;
    v5->list = (RGE_Check_Node *)v6;
}

//----- (004C6740) --------------------------------------------------------
RGE_Check_List *RGE_Static_Object::make_object_bounds_list(float delta)
{
    RGE_Static_Object *v2; // edi@1
    RGE_Master_Static_Object *v3; // ecx@1
    signed short v4; // bp@4
    short v5; // bx@4
    short v6; // si@4
    RGE_Check_List *v7; // eax@4
    signed short v8; // cx@4
    RGE_Check_List *v9; // eax@5
    RGE_Check_List *v10; // edx@7
    RGE_Map *v11; // ecx@9
    int v12; // edx@16
    RGE_Object_Node **v13; // ebp@18
    int v14; // ebx@18
    RGE_Object_Node *i; // esi@19
    RGE_Static_Object *v16; // ecx@20
    RGE_Master_Static_Object *v17; // edx@21
    double v18; // st7@23
    double v19; // st7@25
    double v21; // st4@25
    char v22; // c0@25
    char v24; // c0@30
    bool v25; // zf@38
    RGE_Check_List *result; // eax@44
    RGE_Check_List *v27; // [sp+10h] [bp-4Ch]@5
    int x2; // [sp+14h] [bp-48h]@4
    char flag; // [sp+18h] [bp-44h]@26
    float dy; // [sp+1Ch] [bp-40h]@30
    float v31; // [sp+20h] [bp-3Ch]@30
    int x1; // [sp+24h] [bp-38h]@4
    int v33; // [sp+28h] [bp-34h]@16
    float rx2; // [sp+2Ch] [bp-30h]@21
    float ry2; // [sp+30h] [bp-2Ch]@21
    float ry; // [sp+34h] [bp-28h]@1
    RGE_Map *map; // [sp+38h] [bp-24h]@4
    int v38; // [sp+3Ch] [bp-20h]@16
    RGE_Check_List *check_list; // [sp+40h] [bp-1Ch]@7
    int v40; // [sp+44h] [bp-18h]@16
    float rx; // [sp+48h] [bp-14h]@1
    int v42; // [sp+4Ch] [bp-10h]@16

    v2 = this;
    v3 = this->master_obj;
    rx = v3->radius_x;
    ry = v3->radius_y;
    if( rx <= 0.0 || ry <= 0.0 || v3->radius_z <= 0.0 )
    {
        result = 0;
    }
    else
    {
        v4 = (signed __int64)(v2->world_x - 3.0);
        x1 = (signed __int64)(v2->world_x - 3.0);
        v5 = (signed __int64)(v2->world_y - 3.0);
        x2 = (signed __int64)(v2->world_x - -3.0);
        v6 = (signed __int64)(v2->world_y - -3.0);
        map = v2->owner->world->map;
        v7 = (RGE_Check_List *)operator new(4u);
        v8 = 0;
        if( v7 )
        {
            RGE_Check_List::RGE_Check_List(v7);
            v27 = v9;
            v8 = 0;
        }
        else
        {
            v27 = 0;
        }
        v10 = v27;
        check_list = v27;
        if( v4 < v8 )
        {
            LOWORD(x1) = 0;
            v4 = 0;
        }
        v11 = map;
        if( (signed short)x2 >= map->map_width )
            LOWORD(x2) = LOWORD(map->map_width) - 1;
        if( v5 < 0 )
            v5 = 0;
        if( v6 >= map->map_height )
            v6 = LOWORD(map->map_height) - 1;
        if( v5 <= v6 )
        {
            v40 = v4;
            v12 = 24 * v4;
            v42 = 24 * v4;
            v33 = v5;
            v38 = v6 - v5 + 1;
            do
            {
                if( v4 <= (signed short)x2 )
                {
                    v13 = (RGE_Object_Node **)((char *)&v11->map_row_offset[v33]->objects.list + v12);
                    v14 = (signed short)x2 - v40 + 1;
                    do
                    {
                        for( i = *v13; i; i = i->next )
                        {
                            v16 = i->node;
                            if( i->node != v2 )
                            {
                                v17 = v16->master_obj;
                                ry2 = v17->radius_y;
                                rx2 = v17->radius_x;
                                if( ry2 > 0.0 && rx2 > 0.0 )
                                {
                                    v18 = v16->world_z - v2->world_z;
                                    if( v18 >= -v17->radius_z && v18 <= v2->master_obj->radius_z )
                                    {
                                        v19 = v16->world_x - v2->world_x;
                                        v21 = v16->world_y - v2->world_y;
                                        if( v22 )
                                        {
                                            v19 = -v19;
                                            flag = 1;
                                        }
                                        else
                                        {
                                            flag = 0;
                                        }
                                        if( v21 < 0.0 )
                                        {
                                            v21 = -v21;
                                            flag += 2;
                                        }
                                        v31 = v19 - (rx2 + rx);
                                        dy = v21 - (ry2 + ry);
                                        if( v24 && dy < (double)delta && (dy >= 0.0 || v31 >= 0.0) )
                                            RGE_Check_List::add_node(v27, v16, v31, dy, flag);
                                    }
                                }
                            }
                        }
                        v13 += 6;
                        --v14;
                    }
                    while( v14 );
                    v4 = x1;
                    v11 = map;
                    v12 = v42;
                }
                v25 = v38 == 1;
                ++v33;
                --v38;
            }
            while( !v25 );
            v10 = v27;
        }
        if( !v10->list )
        {
            if( v10 )
            {
                RGE_Check_List::~RGE_Check_List(v10);
                operator delete(v27);
            }
            check_list = 0;
        }
        result = check_list;
    }
    return result;
}

//----- (004C6AA0) --------------------------------------------------------
int RGE_Static_Object::boundToFacet(float tX, float tY, int numberBindingFacets)
{
    long double v4; // st7@1
    signed int v5; // edx@1
    double v6; // st7@1
    int v7; // esi@3
    double v8; // st6@3
    RGE_Sprite *v9; // eax@4
    int v10; // ecx@5
    double v11; // st5@6
    float tYa; // [sp+8h] [bp+8h]@1
    float smallestFacetDifference; // [sp+Ch] [bp+Ch]@5

    v4 = this->world_y - tY;
    v5 = -1;
    tYa = 0.0;
    v6 = atan2(this->world_x - tX, v4);
    if( v6 < 0.0 )
        v6 = v6 - -6.2831855;
    v7 = numberBindingFacets;
    v8 = 0.0;
    if( numberBindingFacets == -1 )
    {
        v9 = this->sprite;
        v7 = v9->facet_num;
        numberBindingFacets = v9->facet_num;
    }
    v10 = 0;
    for( smallestFacetDifference = 6.2831855 / (double)numberBindingFacets; v10 < v7; ++v10 )
    {
        v11 = v6 - v8;
        if( v6 - v8 < 0.0 )
            v11 = -v11;
        if( v5 == -1 || v11 < tYa )
        {
            tYa = v11;
            v5 = v10;
        }
        v8 = v8 + smallestFacetDifference;
    }
    return v5;
}

//----- (004C6B50) --------------------------------------------------------
int RGE_Static_Object::numberFacets()
{
    RGE_Sprite *v1; // eax@1
    int result; // eax@2

    v1 = this->sprite;
    if( v1 )
        result = v1->facet_num;
    else
        result = 0;
    return result;
}

//----- (004C6B60) --------------------------------------------------------
char RGE_Static_Object::underAttack()
{
    return this->underAttackValue;
}

//----- (004C6B70) --------------------------------------------------------
void RGE_Static_Object::setUnderAttack(char v)
{
    this->underAttackValue = v;
}

//----- (004C6B80) --------------------------------------------------------
int RGE_Static_Object::addToObstructionMap(int obMapCode)
{
    RGE_Static_Object *v2; // ebp@1
    RGE_Master_Static_Object *v3; // esi@1
    int result; // eax@2
    int v5; // edi@5
    int v6; // ebx@9
    int i; // esi@10
    int obMapMinY; // [sp+10h] [bp-Ch]@7
    int obMapMaxX; // [sp+14h] [bp-8h]@9
    RGE_Static_Object *v10; // [sp+18h] [bp-4h]@1

    v2 = this;
    v10 = this;
    v3 = this->master_obj;
    if( v3->radius_z > 0.0 )
    {
        if( this->inObstructionMapValue == 1 )
        {
            result = 0;
        }
        else
        {
            v5 = (signed __int64)((this->world_x - v3->radius_x) * 4.0);
            if( v5 < 0 )
                v5 = 0;
            obMapMinY = (signed __int64)((this->world_y - v3->radius_y) * 4.0);
            if( obMapMinY < 0 )
                obMapMinY = 0;
            obMapMaxX = (signed __int64)((v3->radius_x + this->world_x) * 4.0);
            v6 = (signed __int64)((v3->radius_y + this->world_y) * 4.0);
            if( v5 < obMapMaxX )
            {
                do
                {
                    for( i = obMapMinY; i < v6; ++i )
                    {
                        if( obMapCode != 1 )
                            PathingSystem::incrementObstruction(&pathSystem, v5, i);
                        if( obMapCode )
                            PathingSystem::incrementObstruction(&aiPathSystem, v5, i);
                    }
                    ++v5;
                }
                while( v5 < obMapMaxX );
                v2 = v10;
            }
            v2->lastInObstructionMapValue = v2->inObstructionMapValue;
            v2->inObstructionMapValue = 1;
            result = 1;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004C6C90) --------------------------------------------------------
int RGE_Static_Object::removeFromObstructionMap(int obMapCode)
{
    RGE_Static_Object *v2; // ebx@1
    RGE_Master_Static_Object *v3; // esi@1
    int result; // eax@2
    int v5; // edi@5
    int v6; // ebp@9
    int i; // esi@10
    int obMapMinY; // [sp+10h] [bp-Ch]@7
    int obMapMaxX; // [sp+14h] [bp-8h]@9
    RGE_Static_Object *v10; // [sp+18h] [bp-4h]@1

    v2 = this;
    v3 = this->master_obj;
    v10 = this;
    if( v3->radius_z > 0.0 )
    {
        if( this->inObstructionMapValue )
        {
            v5 = (signed __int64)((this->world_x - v3->radius_x) * 4.0);
            if( v5 < 0 )
                v5 = 0;
            obMapMinY = (signed __int64)((this->world_y - v3->radius_y) * 4.0);
            if( obMapMinY < 0 )
                obMapMinY = 0;
            obMapMaxX = (signed __int64)((v3->radius_x + this->world_x) * 4.0);
            v6 = (signed __int64)((v3->radius_y + this->world_y) * 4.0);
            if( v5 < obMapMaxX )
            {
                do
                {
                    for( i = obMapMinY; i < v6; ++i )
                    {
                        if( obMapCode != 1 )
                            PathingSystem::decrementObstruction(&pathSystem, v5, i);
                        if( obMapCode )
                            PathingSystem::decrementObstruction(&aiPathSystem, v5, i);
                    }
                    ++v5;
                }
                while( v5 < obMapMaxX );
                v2 = v10;
            }
            v2->lastInObstructionMapValue = v2->inObstructionMapValue;
            v2->inObstructionMapValue = 0;
            result = 1;
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004C6DA0) --------------------------------------------------------
void RGE_Static_Object::changeInfluenceMap(InfluenceMap *iMap, int increment, int usePercentCoverage, int useLOS)
{
    RGE_Static_Object *v5; // esi@1
    RGE_Master_Static_Object *v6; // eax@1
    double v7; // st7@1
    int v8; // edi@2
    double v9; // st7@2
    signed __int64 v10; // rax@4
    double v11; // st7@4
    double v12; // st6@4
    RGE_Master_Static_Object *v13; // eax@4
    double v14; // rt1@5
    double v15; // st7@5
    double v16; // st5@5
    double v17; // st6@5
    double v18; // rt1@6
    int v19; // ebp@8
    int v20; // esi@9
    double v21; // st7@11
    double v22; // st6@13
    double v23; // st5@15
    double v24; // st4@17
    InfluenceMap *v25; // ecx@19
    int v26; // [sp-4h] [bp-38h]@19
    int v27[6]; // [sp+0h] [bp-34h]@19
    int v28; // [sp+4h] [bp-30h]@19
    float objectMaxX; // [sp+18h] [bp-1Ch]@7
    float objectMinY; // [sp+1Ch] [bp-18h]@7
    float objectMaxY; // [sp+20h] [bp-14h]@7
    int maxXTile; // [sp+24h] [bp-10h]@2
    int maxYTile; // [sp+28h] [bp-Ch]@4
    int minXTile; // [sp+2Ch] [bp-8h]@2
    int y; // [sp+30h] [bp-4h]@7
    int incrementa; // [sp+3Ch] [bp+8h]@9
    int useLOSa; // [sp+44h] [bp+10h]@5

    v5 = this;
    v6 = this->master_obj;
    v7 = this->world_x - v6->radius_x;
    if( useLOS )
    {
        minXTile = (signed __int64)floor(v7 - v6->los);
        maxXTile = (signed __int64)ceil(v5->master_obj->radius_x + v5->master_obj->los + v5->world_x);
        v8 = (signed __int64)floor(v5->world_y - v5->master_obj->radius_y - v5->master_obj->los);
        v9 = v5->master_obj->radius_y + v5->master_obj->los;
    }
    else
    {
        minXTile = (signed __int64)floor(v7);
        maxXTile = (signed __int64)ceil(v5->master_obj->radius_x + v5->world_x);
        v8 = (signed __int64)floor(v5->world_y - v5->master_obj->radius_y);
        v9 = v5->master_obj->radius_y;
    }
    v10 = (signed __int64)ceil(v9 + v5->world_y);
    v11 = v5->world_x;
    v12 = v5->world_y;
    maxYTile = v10;
    v13 = v5->master_obj;
    if( useLOS )
    {
        v18 = v12 - v13->radius_y - v13->los;
        v17 = v13->los + v13->radius_y + v5->world_y;
        *(float *)&useLOSa = v11 - v13->radius_x - v13->los;
        v16 = v13->los + v13->radius_x + v5->world_x;
        v15 = v18;
    }
    else
    {
        v14 = v11 - v13->radius_x;
        v15 = v12 - v13->radius_y;
        *(float *)&useLOSa = v14;
        v16 = v13->radius_x + v5->world_x;
        v17 = v13->radius_y + v5->world_y;
    }
    objectMaxX = v16;
    y = v8;
    objectMinY = v15;
    objectMaxY = v17;
    if( v8 < maxYTile )
    {
        v19 = increment;
        while( 1 )
        {
            v20 = minXTile;
            incrementa = minXTile;
            if( minXTile < maxXTile )
                break;
LABEL_25:
            y = ++v8;
            if( v8 >= maxYTile )
                return;
        }
        while( 1 )
        {
            if( usePercentCoverage )
            {
                v21 = (double)incrementa;
                if( *(float *)&useLOSa > v21 )
                    v21 = *(float *)&useLOSa;
                v22 = (double)(v20 + 1);
                if( objectMaxX < v22 )
                    v22 = objectMaxX;
                v23 = (double)y;
                if( objectMinY > v23 )
                    v23 = objectMinY;
                v24 = (double)(v8 + 1);
                if( objectMaxY < v24 )
                    v24 = objectMaxY;
                v28 = (signed __int64)((v22 - v21) * (v24 - v23) * 255.0);
                v27[0] = v8;
                v26 = v20;
                v25 = iMap;
                if( v19 != 1 )
                {
LABEL_23:
                    InfluenceMap::decrementValue(v25, v26, v27[0], v28);
                    goto LABEL_24;
                }
                InfluenceMap::incrementValue(iMap, v20, v8, v28);
            }
            else
            {
                LOBYTE(v28) = -1;
                v27[0] = v8;
                v26 = v20;
                v25 = iMap;
                if( v19 != 1 )
                    goto LABEL_23;
                InfluenceMap::incrementValue(iMap, v20, v8, -1);
            }
LABEL_24:
            incrementa = ++v20;
            if( v20 >= maxXTile )
                goto LABEL_25;
        }
    }
}

//----- (004C7030) --------------------------------------------------------
RGE_Check_List *RGE_Static_Object::objectCollisionList(float delta)
{
    RGE_Static_Object *v2; // edi@1
    RGE_Master_Static_Object *v3; // ecx@1
    RGE_Game_World *v4; // ecx@4
    RGE_Map *v5; // ebp@4
    signed __int64 v6; // rax@4
    int v7; // esi@4
    int v8; // ebx@4
    signed __int64 v9; // rax@4
    int v10; // edx@4
    int v11; // ecx@4
    int v12; // eax@6
    int v13; // eax@10
    RGE_Check_List *v14; // ebp@12
    int v15; // edx@12
    int v16; // ecx@13
    int v17; // eax@15
    RGE_Object_Node *v18; // ebx@16
    RGE_Static_Object *v19; // esi@17
    RGE_Master_Static_Object *v20; // ecx@18
    double v21; // st7@21
    RGE_Master_Static_Object *v22; // ecx@25
    RGE_Check_List *v23; // eax@34
    RGE_Check_List *v24; // eax@35
    float dz; // [sp+10h] [bp-38h]@21
    float tempRX; // [sp+14h] [bp-34h]@19
    float tempRY; // [sp+18h] [bp-30h]@19
    int minXTile; // [sp+1Ch] [bp-2Ch]@4
    RGE_Object_Node **v30; // [sp+20h] [bp-28h]@15
    int maxXTile; // [sp+24h] [bp-24h]@4
    int maxYTile; // [sp+28h] [bp-20h]@4
    int v33; // [sp+2Ch] [bp-1Ch]@15
    int yIndex; // [sp+30h] [bp-18h]@12
    RGE_Map *map; // [sp+34h] [bp-14h]@4
    int v36; // [sp+38h] [bp-10h]@13

    v2 = this;
    v3 = this->master_obj;
    if( v3->radius_x > 0.0 && v3->radius_y > 0.0 && v3->radius_z > 0.0 )
    {
        v4 = v2->owner->world;
        v5 = v4->map;
        map = v4->map;
        v6 = (signed __int64)v2->world_x;
        v7 = v6 - 3;
        v8 = v6 + 3;
        minXTile = v6 - 3;
        maxXTile = v6 + 3;
        v9 = (signed __int64)v2->world_y;
        v10 = v9 + 3;
        v11 = v9 - 3;
        maxYTile = v9 + 3;
        if( v7 < 0 )
        {
            minXTile = 0;
            v7 = 0;
        }
        v12 = v5->map_width;
        if( v8 >= v12 )
        {
            maxXTile = v12 - 1;
            v8 = v12 - 1;
        }
        if( v11 < 0 )
            v11 = 0;
        v13 = v5->map_height;
        if( v10 >= v13 )
            maxYTile = v13 - 1;
        v14 = 0;
        v15 = v11;
        yIndex = v11;
        if( v11 > maxYTile )
            return v14;
        v16 = 24 * v7;
        v36 = 24 * v7;
        while( 1 )
        {
            if( v7 > v8 )
                goto LABEL_43;
            v30 = (RGE_Object_Node **)((char *)&map->map_row_offset[v15]->objects.list + v16);
            v17 = v8 - v7 + 1;
            v33 = v8 - v7 + 1;
            do
            {
                v18 = *v30;
                if( !*v30 )
                    goto LABEL_41;
                do
                {
                    v19 = v18->node;
                    if( v18->node != v2 )
                    {
                        v20 = v19->master_obj;
                        if( v20->radius_z > 0.0 )
                        {
                            tempRX = v20->radius_x;
                            tempRY = v20->radius_y;
                            if( tempRX > 0.0 && tempRY > 0.0 )
                            {
                                v21 = v19->world_z - v2->world_z;
                                dz = v21;
                                if( (v21 <= 0.0 || dz <= (double)v2->master_obj->radius_z) && (dz >= 0.0 || dz >= -v20->radius_z) )
                                {
                                    v22 = v2->master_obj;
                                    if( v2->world_x >= (double)v19->world_x )
                                    {
                                        if( -delta > tempRX + v19->world_x - (v2->world_x - v22->radius_x) )
                                            goto LABEL_39;
                                    }
                                    else if( v19->world_x - tempRX - (v22->radius_x + v2->world_x) > delta )
                                    {
                                        goto LABEL_39;
                                    }
                                    if( v2->world_y >= (double)v19->world_y )
                                    {
                                        if( -delta > tempRY + v19->world_y - (v2->world_y - v22->radius_y) )
                                            goto LABEL_39;
                                    }
                                    else if( v19->world_y - tempRY - (v22->radius_y + v2->world_y) > delta )
                                    {
                                        goto LABEL_39;
                                    }
                                    if( !v14 )
                                    {
                                        v23 = (RGE_Check_List *)operator new(4u);
                                        if( v23 )
                                            RGE_Check_List::RGE_Check_List(v23);
                                        else
                                            v24 = 0;
                                        v14 = v24;
                                    }
                                    RGE_Check_List::add_node(v14, v19, 0.0, 0.0, 0);
                                }
                            }
                        }
                    }
LABEL_39:
                    v18 = v18->next;
                }
                while( v18 );
                v7 = minXTile;
                v17 = v33;
LABEL_41:
                --v17;
                v30 += 6;
                v33 = v17;
            }
            while( v17 );
            v8 = maxXTile;
            v15 = yIndex;
            v16 = v36;
LABEL_43:
            yIndex = ++v15;
            if( v15 > maxYTile )
                return v14;
        }
    }
    return 0;
}

//----- (004C7340) --------------------------------------------------------
void RGE_Static_Object::logDebug(char *textIn, ...)
{
    FILE *v2; // eax@4
    char textOut[1024]; // [sp+8h] [bp-400h]@6
    va_list va; // [sp+414h] [bp+Ch]@1

    va_start(va, textIn);
    if( logDebugID == -1 || logDebugID == this->id )
    {
        if( !debugOut )
        {
            v2 = fopen(aCAoeunit_txt, aW_1);
            debugOut = v2;
            if( !v2 )
                return;
            fprintf(v2, aWorldTimeLd, this->owner->world->world_time);
        }
        vsprintf(textOut, textIn, va);
        if( strlen(textOut) == 0 )
            fprintf(debugOut, aUnit5d, this->id);
        else
            fprintf(debugOut, aUnit5dS, this->id, textOut);
    }
}
// 57FA00: using guessed type int logDebugID;

//----- (004C7420) --------------------------------------------------------
UnitAIModule *RGE_Static_Object::unitAI()
{
    return this->unitAIValue;
}

//----- (004C7430) --------------------------------------------------------
char RGE_Static_Object::lookupZone(XYPoint p)
{
    int v2; // eax@3
    RGE_Zone_Map *v3; // eax@4
    char result; // al@7

    if( p.x >= 0
        && p.y >= 0
        && ((v2 = this->zoneMapIndex, v2 != -1) ? (v3 = RGE_Zone_Map_List::get_zone_map(
                                                                                                            this->owner->world->map->map_zones,
                                                                                                            v2)) : (v3 = RGE_Zone_Map_List::get_zone_map(
                                                                                                                                         this->owner->world->map->map_zones,
                                                                                                                                         this->owner->world->terrains[this->master_obj->terrain],
                                                                                                                                         this->owner->world->terrain_size,
                                                                                                                                         &this->zoneMapIndex)),
                v3) )
    {
        result = RGE_Zone_Map::get_zone_info(v3, p.x, p.y);
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004C74B0) --------------------------------------------------------
char RGE_Static_Object::lookupZone(int x, int y)
{
    int v3; // eax@3
    RGE_Zone_Map *v4; // eax@4
    char result; // al@7

    if( x >= 0
        && y >= 0
        && ((v3 = this->zoneMapIndex, v3 != -1) ? (v4 = RGE_Zone_Map_List::get_zone_map(
                                                                                                            this->owner->world->map->map_zones,
                                                                                                            v3)) : (v4 = RGE_Zone_Map_List::get_zone_map(
                                                                                                                                         this->owner->world->map->map_zones,
                                                                                                                                         this->owner->world->terrains[this->master_obj->terrain],
                                                                                                                                         this->owner->world->terrain_size,
                                                                                                                                         &this->zoneMapIndex)),
                v4) )
    {
        result = RGE_Zone_Map::get_zone_info(v4, x, y);
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004C7530) --------------------------------------------------------
char RGE_Static_Object::currentZone()
{
    RGE_Static_Object *v1; // esi@1
    int v2; // eax@1
    int *v3; // ecx@1
    RGE_Zone_Map *v4; // eax@2
    char result; // al@5

    v1 = this;
    v2 = this->zoneMapIndex;
    v3 = &this->zoneMapIndex;
    if( v2 == -1 )
        v4 = RGE_Zone_Map_List::get_zone_map(
                     v1->owner->world->map->map_zones,
                     v1->owner->world->terrains[v1->master_obj->terrain],
                     v1->owner->world->terrain_size,
                     v3);
    else
        v4 = RGE_Zone_Map_List::get_zone_map(v1->owner->world->map->map_zones, v2);
    if( v4 )
        result = RGE_Zone_Map::get_zone_info(v4, (signed __int64)v1->world_x, (signed __int64)v1->world_y);
    else
        result = 0;
    return result;
}

//----- (004C75B0) --------------------------------------------------------
int RGE_Static_Object::withinRangeOfZoneAtPoint(char zone, float range, XYPoint *point)
{
    int v4; // eax@1
    RGE_Zone_Map *v5; // eax@2
    int result; // eax@5

    v4 = this->zoneMapIndex;
    if( v4 == -1 )
        v5 = RGE_Zone_Map_List::get_zone_map(
                     this->owner->world->map->map_zones,
                     this->owner->world->terrains[this->master_obj->terrain],
                     this->owner->world->terrain_size,
                     &this->zoneMapIndex);
    else
        v5 = RGE_Zone_Map_List::get_zone_map(this->owner->world->map->map_zones, v4);
    if( v5 )
        result = RGE_Zone_Map::withinRange(v5, zone, *point, range);
    else
        result = 0;
    return result;
}

//----- (004C7630) --------------------------------------------------------
int RGE_Static_Object::withinRangeOfZone(char zone, float range)
{
    RGE_Static_Object *v3; // esi@1
    unsigned int v4; // edi@1
    signed __int64 v5; // rax@1
    int *v6; // ecx@1
    unsigned int v7; // ebx@1
    RGE_Zone_Map *v8; // eax@2
    int result; // eax@5

    v3 = this;
    v4 = (signed __int64)this->world_x;
    v5 = (signed __int64)this->world_y;
    v6 = &this->zoneMapIndex;
    v7 = v5;
    if( v3->zoneMapIndex == -1 )
        v8 = RGE_Zone_Map_List::get_zone_map(
                     v3->owner->world->map->map_zones,
                     v3->owner->world->terrains[v3->master_obj->terrain],
                     v3->owner->world->terrain_size,
                     v6);
    else
        v8 = RGE_Zone_Map_List::get_zone_map(v3->owner->world->map->map_zones, v3->zoneMapIndex);
    if( v8 )
        result = RGE_Zone_Map::withinRange(v8, zone, (XYPoint)__PAIR__(v7, v4), range);
    else
        result = 0;
    return result;
}

//----- (004C76C0) --------------------------------------------------------
int RGE_Static_Object::findClosestPointInTerrainType(XYPoint p, XYPoint *rVal, int type1, int type2, int range)
{
    int v6; // eax@1
    RGE_Zone_Map *v7; // eax@2
    int result; // eax@5

    v6 = this->zoneMapIndex;
    if( v6 == -1 )
        v7 = RGE_Zone_Map_List::get_zone_map(
                     this->owner->world->map->map_zones,
                     this->owner->world->terrains[this->master_obj->terrain],
                     this->owner->world->terrain_size,
                     &this->zoneMapIndex);
    else
        v7 = RGE_Zone_Map_List::get_zone_map(this->owner->world->map->map_zones, v6);
    if( v7 )
        result = RGE_Zone_Map::findClosestPointInTerrainType(v7, p, rVal, type1, type2, range);
    else
        result = 0;
    return result;
}

//----- (004C7740) --------------------------------------------------------
BOOL RGE_Static_Object::isGroupCommander()
{
    return this->id == this->groupCommanderValue;
}

//----- (004C7760) --------------------------------------------------------
bool RGE_Static_Object::inGroup()
{
    return this->groupMembers.numberValue > 0;
}

//----- (004C7770) --------------------------------------------------------
int RGE_Static_Object::unitIsInGroup(int uID)
{
    int v2; // edx@1
    int v3; // eax@1

    v2 = this->groupMembers.numberValue;
    v3 = 0;
    if( v2 > 0 )
    {
        while( v3 < this->groupMembers.maximumSizeValue )
        {
            if( this->groupMembers.value[v3] == uID )
                return 1;
            if( ++v3 >= v2 )
                return 0;
        }
    }
    return 0;
}

//----- (004C77B0) --------------------------------------------------------
int RGE_Static_Object::createGroup(int *units, int count, int commander, float range)
{
    RGE_Static_Object *v5; // esi@1
    int *v6; // ecx@1
    int v7; // ebp@4
    int v8; // ecx@5
    int i; // eax@5
    int v10; // ebx@10
    int *v11; // edi@10
    int j; // eax@11
    bool v13; // zf@16
    int result; // eax@17

    v5 = this;
    v6 = units;
    if( units && count )
    {
        v5->groupMembers.numberValue = 0;
        if( count > 0 )
        {
            do
            {
                v7 = *v6;
                if( *v6 >= 0 )
                {
                    v8 = v5->groupMembers.numberValue;
                    for( i = 0; i < v8; ++i )
                    {
                        if( i >= v5->groupMembers.maximumSizeValue )
                            break;
                        if( v5->groupMembers.value[i] == v7 )
                            goto LABEL_16;
                    }
                    if( v8 > v5->groupMembers.maximumSizeValue - 1 )
                    {
                        v10 = v8 + 1;
                        v11 = (int *)operator new(4 * (v8 + 1));
                        if( v11 )
                        {
                            for( j = 0; j < v5->groupMembers.maximumSizeValue; v11[j - 1] = v5->groupMembers.value[j - 1] )
                            {
                                if( j >= v10 )
                                    break;
                                ++j;
                            }
                            operator delete(v5->groupMembers.value);
                            v5->groupMembers.value = v11;
                            v5->groupMembers.maximumSizeValue = v10;
                        }
                    }
                    v5->groupMembers.value[v5->groupMembers.numberValue++] = v7;
                }
LABEL_16:
                v6 = units + 1;
                v13 = count == 1;
                ++units;
                --count;
            }
            while( !v13 );
        }
        v5->groupRangeValue = range;
        v5->groupCommanderValue = commander;
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004C78B0) --------------------------------------------------------
int RGE_Static_Object::commanderCreateGroup(int *units, int count, int commander, float range)
{
    int *v5; // ebx@1
    int *v6; // esi@4
    RGE_Static_Object *v7; // eax@5
    int result; // eax@8
    RGE_Static_Object *v9; // [sp+10h] [bp-4h]@1
    int *unitsa; // [sp+18h] [bp+4h]@4

    v5 = units;
    v9 = this;
    if( units && count )
    {
        if( count > 0 )
        {
            v6 = units;
            unitsa = (int *)count;
            do
            {
                v7 = RGE_Game_World::object(v9->owner->world, *v6);
                if( v7 )
                    RGE_Static_Object::createGroup(v7, v5, count, commander, range);
                ++v6;
                unitsa = (int *)((char *)unitsa - 1);
            }
            while( unitsa );
        }
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004C7920) --------------------------------------------------------
int RGE_Static_Object::addToGroup(int unit, float range)
{
    RGE_Static_Object *v3; // esi@1
    int result; // eax@2
    int v5; // ecx@3
    int i; // eax@3
    int v7; // ebx@8
    int *v8; // edi@8
    int j; // eax@9

    v3 = this;
    if( this->groupMembers.numberValue < 25 )
    {
        v5 = this->groupMembers.numberValue;
        for( i = 0; i < v5; ++i )
        {
            if( i >= v3->groupMembers.maximumSizeValue )
                break;
            if( v3->groupMembers.value[i] == unit )
                goto LABEL_14;
        }
        if( v5 > v3->groupMembers.maximumSizeValue - 1 )
        {
            v7 = v5 + 1;
            v8 = (int *)operator new(4 * (v5 + 1));
            if( v8 )
            {
                for( j = 0; j < v3->groupMembers.maximumSizeValue; v8[j - 1] = v3->groupMembers.value[j - 1] )
                {
                    if( j >= v7 )
                        break;
                    ++j;
                }
                operator delete(v3->groupMembers.value);
                v3->groupMembers.value = v8;
                v3->groupMembers.maximumSizeValue = v7;
            }
        }
        v3->groupMembers.value[v3->groupMembers.numberValue++] = unit;
LABEL_14:
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004C79D0) --------------------------------------------------------
RGE_Static_Object *RGE_Static_Object::commanderAddToGroup(int unit, float range)
{
    RGE_Static_Object *v3; // esi@1
    RGE_Static_Object *result; // eax@1
    signed int v5; // eax@2
    int v6; // ebx@4
    unsigned int v7; // ebp@5
    int v8; // ebx@7
    int *v9; // edi@7
    int j; // eax@8
    RGE_Static_Object *v11; // eax@13
    RGE_Static_Object *v12; // ecx@13
    int v13; // ebx@15
    int *v14; // edi@15
    int k; // eax@16
    RGE_Static_Object *v16; // eax@21
    int i; // [sp+10h] [bp-70h]@4
    RGE_Static_Object *unitObj; // [sp+18h] [bp-68h]@1
    int temp[25]; // [sp+1Ch] [bp-64h]@24

    v3 = this;
    result = RGE_Game_World::object(this->owner->world, unit);
    unitObj = result;
    if( result )
    {
        v5 = v3->groupMembers.numberValue;
        if( v5 < 25 )
        {
            v6 = 0;
            i = 0;
            if( v5 > 0 )
            {
                v7 = 1;
                do
                {
                    if( v6 > v3->groupMembers.maximumSizeValue - 1 )
                    {
                        v8 = v6 + 1;
                        v9 = (int *)operator new(v7 * 4);
                        if( v9 )
                        {
                            for( j = 0; j < v3->groupMembers.maximumSizeValue; v9[j - 1] = v3->groupMembers.value[j - 1] )
                            {
                                if( j >= v8 )
                                    break;
                                ++j;
                            }
                            operator delete(v3->groupMembers.value);
                            v3->groupMembers.value = v9;
                            v3->groupMembers.maximumSizeValue = v8;
                        }
                        v6 = i;
                    }
                    v11 = (RGE_Static_Object *)v3->groupMembers.value[v7 - 1];
                    v12 = (RGE_Static_Object *)v3->id;
                    *(RGE_Static_Object **)((char *)&unitObj + v7 * 4) = v11;
                    if( v11 != v12 )
                    {
                        if( v6 > v3->groupMembers.maximumSizeValue - 1 )
                        {
                            v13 = v6 + 1;
                            v14 = (int *)operator new(v7 * 4);
                            if( v14 )
                            {
                                for( k = 0; k < v3->groupMembers.maximumSizeValue; v14[k - 1] = v3->groupMembers.value[k - 1] )
                                {
                                    if( k >= v13 )
                                        break;
                                    ++k;
                                }
                                operator delete(v3->groupMembers.value);
                                v3->groupMembers.value = v14;
                                v3->groupMembers.maximumSizeValue = v13;
                            }
                            v6 = i;
                        }
                        v16 = RGE_Game_World::object(v3->owner->world, v3->groupMembers.value[v7 - 1]);
                        if( v16 )
                            RGE_Static_Object::addToGroup(v16, unit, range);
                    }
                    ++v6;
                    ++v7;
                    i = v6;
                }
                while( v6 < v3->groupMembers.numberValue );
            }
            temp[v6] = unit;
            RGE_Static_Object::addToGroup(v3, unit, range);
            RGE_Static_Object::createGroup(unitObj, temp, v6 + 1, v3->id, range);
            result = (RGE_Static_Object *)1;
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

//----- (004C7B60) --------------------------------------------------------
int RGE_Static_Object::removeFromGroup(int unit)
{
    int v2; // esi@1
    int v3; // eax@1
    int *v4; // edx@2
    int result; // eax@6
    int v6; // eax@9

    v2 = this->groupMembers.maximumSizeValue;
    v3 = 0;
    if( v2 > 0 )
    {
        v4 = this->groupMembers.value;
        do
        {
            if( *v4 == unit )
                break;
            ++v3;
            ++v4;
        }
        while( v3 < v2 );
    }
    if( v3 < v2 )
    {
        if( v3 < v2 - 1 )
        {
            do
            {
                ++v3;
                this->groupMembers.value[v3 - 1] = this->groupMembers.value[v3];
            }
            while( v3 < this->groupMembers.maximumSizeValue - 1 );
        }
        v6 = this->groupMembers.numberValue - 1;
        this->groupMembers.numberValue = v6;
        if( v6 < 0 )
            this->groupMembers.numberValue = 0;
        result = 1;
    }
    else
    {
        result = 0;
    }
    if( this->groupMembers.numberValue <= 0 )
        this->groupCommanderValue = -1;
    return result;
}

//----- (004C7BD0) --------------------------------------------------------
int RGE_Static_Object::commanderRemoveFromGroup(int uID)
{
    int v2; // ebx@1
    RGE_Static_Object *v3; // esi@1
    int v4; // eax@1
    int result; // eax@3
    int v6; // ebp@4
    int v7; // ebx@6
    int *v8; // edi@6
    int i; // eax@7
    RGE_Static_Object *v10; // eax@12
    int v11; // edx@14
    int v12; // ecx@14
    int *v13; // edi@15
    int v14; // ecx@21

    v2 = uID;
    v3 = this;
    v4 = this->id;
    if( uID != v4 || v4 != this->groupCommanderValue )
    {
        v6 = 0;
        if( this->groupMembers.numberValue > 0 )
        {
            do
            {
                if( v6 > v3->groupMembers.maximumSizeValue - 1 )
                {
                    v7 = v6 + 1;
                    v8 = (int *)operator new(4 * v6 + 4);
                    if( v8 )
                    {
                        for( i = 0; i < v3->groupMembers.maximumSizeValue; v8[i - 1] = v3->groupMembers.value[i - 1] )
                        {
                            if( i >= v7 )
                                break;
                            ++i;
                        }
                        operator delete(v3->groupMembers.value);
                        v3->groupMembers.value = v8;
                        v3->groupMembers.maximumSizeValue = v7;
                    }
                    v2 = uID;
                }
                v10 = RGE_Game_World::object(v3->owner->world, v3->groupMembers.value[v6]);
                if( v10 && v10->id != v3->id )
                {
                    v11 = v10->groupMembers.maximumSizeValue;
                    v12 = 0;
                    if( v11 > 0 )
                    {
                        v13 = v10->groupMembers.value;
                        do
                        {
                            if( *v13 == v2 )
                                break;
                            ++v12;
                            ++v13;
                        }
                        while( v12 < v11 );
                    }
                    if( v12 < v11 )
                    {
                        if( v12 < v11 - 1 )
                        {
                            do
                            {
                                ++v12;
                                v10->groupMembers.value[v12 - 1] = v10->groupMembers.value[v12];
                            }
                            while( v12 < v10->groupMembers.maximumSizeValue - 1 );
                        }
                        v14 = v10->groupMembers.numberValue - 1;
                        v10->groupMembers.numberValue = v14;
                        if( v14 < 0 )
                            v10->groupMembers.numberValue = 0;
                    }
                }
                ++v6;
            }
            while( v6 < v3->groupMembers.numberValue );
        }
        RGE_Static_Object::removeFromGroup(v3, v2);
        result = 1;
    }
    else
    {
        result = RGE_Static_Object::commanderDestroyGroup(this);
    }
    return result;
}

//----- (004C7CE0) --------------------------------------------------------
int RGE_Static_Object::destroyGroup()
{
    this->groupMembers.numberValue = 0;
    this->groupCommanderValue = -1;
    return 1;
}

//----- (004C7D00) --------------------------------------------------------
int RGE_Static_Object::commanderDestroyGroup()
{
    RGE_Static_Object *v1; // esi@1
    int i; // ebx@1
    int v3; // ebp@3
    int *v4; // edi@3
    int j; // eax@4
    RGE_Static_Object *v6; // eax@8

    v1 = this;
    for( i = 0; i < v1->groupMembers.numberValue; ++i )
    {
        if( i > v1->groupMembers.maximumSizeValue - 1 )
        {
            v3 = i + 1;
            v4 = (int *)operator new(4 * i + 4);
            if( v4 )
            {
                for( j = 0; j < v1->groupMembers.maximumSizeValue; v4[j - 1] = v1->groupMembers.value[j - 1] )
                {
                    if( j >= v3 )
                        break;
                    ++j;
                }
                operator delete(v1->groupMembers.value);
                v1->groupMembers.value = v4;
                v1->groupMembers.maximumSizeValue = v3;
            }
        }
        v6 = RGE_Game_World::object(v1->owner->world, v1->groupMembers.value[i]);
        if( v6 && v6->id != v1->id )
            RGE_Static_Object::destroyGroup(v6);
    }
    RGE_Static_Object::destroyGroup(v1);
    return 1;
}

//----- (004C7DB0) --------------------------------------------------------
void RGE_Static_Object::addToPathingGroup(int uID)
{
    RGE_Static_Object *v2; // esi@1
    int v3; // eax@1
    int v4; // ecx@1
    int v5; // ebx@6
    int *v6; // edi@6
    int i; // eax@7

    v2 = this;
    v3 = 0;
    v4 = this->pathingGroupMembers.numberValue;
    if( v4 > 0 )
    {
        do
        {
            if( v3 >= v2->pathingGroupMembers.maximumSizeValue )
                break;
            if( v2->pathingGroupMembers.value[v3] == uID )
                return;
            ++v3;
        }
        while( v3 < v4 );
    }
    if( v4 > v2->pathingGroupMembers.maximumSizeValue - 1 )
    {
        v5 = v4 + 1;
        v6 = (int *)operator new(4 * (v4 + 1));
        if( v6 )
        {
            for( i = 0; i < v2->pathingGroupMembers.maximumSizeValue; v6[i - 1] = v2->pathingGroupMembers.value[i - 1] )
            {
                if( i >= v5 )
                    break;
                ++i;
            }
            operator delete(v2->pathingGroupMembers.value);
            v2->pathingGroupMembers.value = v6;
            v2->pathingGroupMembers.maximumSizeValue = v5;
        }
    }
    v2->pathingGroupMembers.value[v2->pathingGroupMembers.numberValue++] = uID;
}

//----- (004C7E50) --------------------------------------------------------
void RGE_Static_Object::removeAllFromPathingGroup()
{
    RGE_Static_Object *v1; // esi@1

    v1 = this;
    if( RGE_Player::computerPlayer(this->owner) == 1 )
        v1->pathingGroupMembers.numberValue = 0;
}

//----- (004C7E70) --------------------------------------------------------
void RGE_Static_Object::remove_shadows()
{
    int v1; // edi@1

    v1 = (signed __int64)this->world_x;
    RGE_Map::request_redraw(
        this->owner->world->map,
        v1 - 2,
        (unsigned __int64)(signed __int64)this->world_y - 2,
        v1 + 1,
        (unsigned __int64)(signed __int64)this->world_y + 1,
        0);
}

//----- (004C7EB0) --------------------------------------------------------
void RGE_Static_Object::set_sleep_flag(char flag_in)
{
    RGE_Static_Object *v2; // esi@1
    RGE_Player *v3; // ecx@5
    int v4; // edx@5

    v2 = this;
    if( this->sleep_flag != flag_in )
    {
        if( flag_in )
        {
            this->goto_sleep_flag = 1;
            this->sleep_flag = flag_in;
        }
        else if( this->goto_sleep_flag )
        {
            this->sleep_flag = 0;
            this->goto_sleep_flag = 0;
        }
        else
        {
            ((void (__stdcall *)(RGE_Static_Object *, _DWORD, _DWORD, RGE_Object_Node *))this->owner->vfptr->removeObject)(
                this,
                this->sleep_flag,
                this->dopple_flag,
                this->player_object_node);
            v3 = v2->owner;
            v4 = v2->dopple_flag;
            v2->sleep_flag = 0;
            v2->player_object_node = (RGE_Object_Node *)((int (__stdcall *)(RGE_Static_Object *, _DWORD, int))v3->vfptr->addObject)(
                                                                                                        v2,
                                                                                                        0,
                                                                                                        v4);
        }
    }
}

//----- (004C7F30) --------------------------------------------------------
int RGE_Static_Object::get_action_checksum()
{
    return 0;
}

//----- (004C7F40) --------------------------------------------------------
int RGE_Static_Object::get_waypoint_checksum()
{
    return 0;
}

//----- (00405D00) --------------------------------------------------------
char RGE_Static_Object::can_attack()
{
    return 0;
}

//----- (00405D10) --------------------------------------------------------
int RGE_Static_Object::canRepair()
{
    return 0;
}

//----- (00405D20) --------------------------------------------------------
int __stdcall RGE_Static_Object::inAttackRange(RGE_Static_Object *__formal)
{
    return 0;
}

//----- (00405D30) --------------------------------------------------------
double __stdcall RGE_Static_Object::calc_attack_modifier(RGE_Static_Object *__formal)
{
    return 1.0;
}

//----- (00405D40) --------------------------------------------------------
double RGE_Static_Object::rateOfFire()
{
    return 0.0;
}

//----- (00405D50) --------------------------------------------------------
double RGE_Static_Object::damageCapability()
{
    return 0.0;
}

//----- (00405D60) --------------------------------------------------------
double __stdcall RGE_Static_Object::damageCapability(RGE_Static_Object *__formal)
{
    return 0.0;
}

//----- (00405D70) --------------------------------------------------------
double RGE_Static_Object::weaponRange()
{
    return 0.0;
}

//----- (00405D80) --------------------------------------------------------
double RGE_Static_Object::minimumWeaponRange()
{
    return 0.0;
}

//----- (00405D90) --------------------------------------------------------
int RGE_Static_Object::currentTargetID()
{
    return -1;
}

//----- (00405DA0) --------------------------------------------------------
double RGE_Static_Object::currentTargetX()
{
    return -1.0;
}

//----- (00405DB0) --------------------------------------------------------
double RGE_Static_Object::currentTargetY()
{
    return -1.0;
}

//----- (00405DC0) --------------------------------------------------------
double RGE_Static_Object::currentTargetZ()
{
    return -1.0;
}

//----- (00405DD0) --------------------------------------------------------
char __stdcall RGE_Static_Object::keepGatheringWhenObjectIsOut(int __formal)
{
    return 0;
}

//----- (00405DE0) --------------------------------------------------------
char __stdcall RGE_Static_Object::produceWhenKilledBy(int __formal)
{
    return 1;
}

//----- (00405DF0) --------------------------------------------------------
char RGE_Static_Object::useSameZoneDropsite()
{
    return 1;
}

//----- (00405E10) --------------------------------------------------------
int __stdcall RGE_Static_Object::attack(int __formal, int a3)
{
    return 0;
}

//----- (00405E20) --------------------------------------------------------
int __stdcall RGE_Static_Object::attack(float __formal, float a3, float a4, int a5)
{
    return 0;
}

//----- (00405E30) --------------------------------------------------------
int __stdcall RGE_Static_Object::moveTo(int __formal, int a3)
{
    return 0;
}

//----- (00405E40) --------------------------------------------------------
int __stdcall RGE_Static_Object::moveTo(int __formal, float a3, int a4)
{
    return 0;
}

//----- (00405E50) --------------------------------------------------------
int __stdcall RGE_Static_Object::moveTo(float __formal, float a3, float a4, float a5, int a6)
{
    return 0;
}

//----- (00405E60) --------------------------------------------------------
int __stdcall RGE_Static_Object::moveAwayFrom(int __formal, int a3)
{
    return 0;
}

//----- (00405E70) --------------------------------------------------------
int __stdcall RGE_Static_Object::hunt(int __formal, int a3)
{
    return 0;
}

//----- (00405E80) --------------------------------------------------------
int __stdcall RGE_Static_Object::gather(int __formal, int a3)
{
    return 0;
}

//----- (00405E90) --------------------------------------------------------
int __stdcall RGE_Static_Object::convert(int __formal, int a3)
{
    return 0;
}

//----- (00405EA0) --------------------------------------------------------
int __stdcall RGE_Static_Object::heal(int __formal, int a3)
{
    return 0;
}

//----- (00405EB0) --------------------------------------------------------
int __stdcall RGE_Static_Object::repair(int __formal, int a3)
{
    return 0;
}

//----- (00405EC0) --------------------------------------------------------
int __stdcall RGE_Static_Object::build(int __formal, int a3)
{
    return 0;
}

//----- (00405ED0) --------------------------------------------------------
int __stdcall RGE_Static_Object::trade(int __formal, int a3)
{
    return 0;
}

//----- (00405EE0) --------------------------------------------------------
int __stdcall RGE_Static_Object::explore(int __formal, int a3, int a4)
{
    return 0;
}

//----- (00405EF0) --------------------------------------------------------
int __stdcall RGE_Static_Object::enter(int __formal, int a3)
{
    return 0;
}

//----- (00405F00) --------------------------------------------------------
int __stdcall RGE_Static_Object::unload(int __formal, float a3, float a4, float a5)
{
    return 0;
}

//----- (00405F10) --------------------------------------------------------
int __stdcall RGE_Static_Object::transport(float __formal, float a3, float a4, int a5)
{
    return 0;
}

//----- (00405F20) --------------------------------------------------------
int RGE_Static_Object::stopAction()
{
    return 0;
}

//----- (00405F30) --------------------------------------------------------
int RGE_Static_Object::pause()
{
    return 0;
}

//----- (0041A4D0) --------------------------------------------------------
RGE_Static_Object *RGE_Static_Object::get_target_obj()
{
    return 0;
}

//----- (0041A4E0) --------------------------------------------------------
double RGE_Static_Object::getAngle()
{
    return 0.0;
}

//----- (0041A4F0) --------------------------------------------------------
double RGE_Static_Object::maximumSpeed()
{
    return 0.0;
}

//----- (0041A500) --------------------------------------------------------
int __stdcall RGE_Static_Object::passableTile(float __formal, float a3, int a4)
{
    return 0;
}

//----- (0041A510) --------------------------------------------------------
char RGE_Static_Object::facetToNextWaypoint()
{
    return -1;
}

//----- (0041A530) --------------------------------------------------------
char RGE_Static_Object::waitingToMove()
{
    return 0;
}

//----- (0041A540) --------------------------------------------------------
char RGE_Static_Object::actionState()
{
    return 0;
}

//----- (0041A550) --------------------------------------------------------
int __stdcall RGE_Static_Object::canPath(XYZPoint __formal, float a3, int a4, float *a5, int a6, int a7, int a8)
{
    return 0;
}

//----- (0041A560) --------------------------------------------------------
int __stdcall RGE_Static_Object::canPath(int __formal, float a3, float *a4, int a5, int a6, int a7)
{
    return 0;
}

//----- (0041A570) --------------------------------------------------------
int __stdcall RGE_Static_Object::canBidirectionPath(int __formal, int a3, float a4, float *a5, int a6, int a7, int a8)
{
    return 0;
}

//----- (0041A580) --------------------------------------------------------
int __stdcall RGE_Static_Object::canPathWithObstructions(int __formal, float a3, float *a4, int a5, int a6, int a7, ManagedArray<int> *a8)
{
    return 0;
}

//----- (0041A590) --------------------------------------------------------
int __stdcall RGE_Static_Object::canPathWithAdditionalPassability(XYZPoint __formal, float a3, int a4, float *a5, int a6, int a7, int a8, int a9, int a10)
{
    return 0;
}

//----- (0041A5A0) --------------------------------------------------------
int __stdcall RGE_Static_Object::findFirstTerrainAlongExceptionPath(int __formal, float *a3, float *a4)
{
    return 0;
}

//----- (0041A5B0) --------------------------------------------------------
int __stdcall RGE_Static_Object::canLinePath(XYPoint *__formal, XYPoint *a3, float a4, XYPoint *a5, int a6)
{
    return 0;
}

//----- (0041A5C0) --------------------------------------------------------
int __stdcall RGE_Static_Object::canLinePath(int __formal, int a3, int a4, int a5, float a6, int a7)
{
    return 0;
}

//----- (0041A5D0) --------------------------------------------------------
int __stdcall RGE_Static_Object::firstTileAlongLine(XYPoint *__formal, XYPoint *a3, XYPoint *a4, int a5, int a6, int a7)
{
    return 0;
}

//----- (0041A5E0) --------------------------------------------------------
XYZBYTEPoint *__stdcall RGE_Static_Object::userDefinedWaypoint(int __formal)
{
    return 0;
}

//----- (0041A5F0) --------------------------------------------------------
int __stdcall RGE_Static_Object::addUserDefinedWaypoint(XYZBYTEPoint *__formal, int a3)
{
    return 0;
}

//----- (0041A620) --------------------------------------------------------
int RGE_Static_Object::numberUserDefinedWaypoints()
{
    return 0;
}

//----- (0041A630) --------------------------------------------------------
Path *__stdcall RGE_Static_Object::findAvoidancePath(XYZPoint *__formal, float a3, int a4)
{
    return 0;
}

RGE_Master_Static_Object *RGE_Static_Object::get_command_master(RGE_Static_Object *__formal, float a3, float a4, float a5)
{
        return this->master_obj;
}
