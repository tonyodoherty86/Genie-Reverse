
/**
 * @file    Engine\RGE\DopplegangerObject.cpp
 * @author  Yvan Burrie
 * @date    2018/07/02
 * @version 1.0
 */

RGE_Doppleganger_Object::RGE_Doppleganger_Object(
    RGE_Master_Doppleganger_Object *tobj,
    RGE_Player *obj_owner,
    float x,
    float y,
    float z,
    bool do_setup,
    RGE_Static_Object *obj_to_dopple)
{
    RGE_Animated_Object::RGE_Animated_Object(
        tobj,
        obj_owner,
        x,
        y,
        z,
        false);
    
    if( do_setup ){
        this->setup(
            tobj,
            obj_owner,
            x,
            y,
            z);
    }

    if( this->doppled_object     = obj_to_dopple ){
        this->doppled_master_obj = obj_to_dopple->master_obj;
        this->doppled_player     = obj_to_dopple->owner->id;
        this->doppledObjectID    = obj_to_dopple->id;
        this->sprite             = obj_to_dopple->sprite;
        this->facet              = obj_to_dopple->facet;
        this->draw_color         = obj_to_dopple->owner->color_table;
        this->map_draw_level     = obj_to_dopple->master_obj->map_draw_level;

        this->sprite_list->use_sprite_list(obj_to_dopple->sprite_list->copy_sprite_list());

        if( this->map_draw_level == 3 ){
            this->map_color = obj_to_dopple->master_obj->map_color;
        }else{
            this->map_color = obj_to_dopple->owner->color_table->map_color;
        }
        if( this->doppled_object->object_state >= RGE_Static_Object::State::Unk7 ){
            this->doppled_object  = nullptr;
            this->doppledObjectID = -1;
        }
    }else{
        RGE_Static_Object::destroy_obj();
    }
    this->validate();
}

void __userpurge RGE_Doppleganger_Object::RGE_Doppleganger_Object(RGE_Doppleganger_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld, int do_setup)
{
    int v5; // edi@1
    RGE_Doppleganger_Object *v6; // esi@1
    int v7; // ebp@1
    bool v8; // zf@1

    v5 = infile;
    v6 = this;
    RGE_Animated_Object::RGE_Animated_Object((RGE_Animated_Object *)&this->vfptr, a2, infile, gworld, 0);
    v7 = (int)&v6->doppled_player;
    v8 = do_setup == 0;
    v6->doppled_object = 0;
    v6->draw_color = 0;
    v6->doppled_master_obj = 0;
    v6->doppled_player = 0;
    v6->MapAddress = 0;
    v6->LastMapValue = 0;
    v6->CantSeeBits = 0;
    v6->map_draw_level = 0;
    v6->map_color = 0;
    v6->doppledObjectID = -1;
    if( !v8 )
        RGE_Doppleganger_Object::setup(v6, v7, v5, gworld);
    rge_read(v7, v5, v5, &infile, 4);
    v6->doppled_object = (RGE_Static_Object *)infile;
    v6->doppledObjectID = -1;
    rge_read(v7, v5, v5, &v6->map_draw_level, 1);
    rge_read(v7, v5, v5, &v6->map_color, 4);
    rge_read(v7, v5, v5, &infile, 4);
    v6->doppled_master_obj = (RGE_Master_Static_Object *)infile;
    rge_read(v7, v5, v5, &v6->doppled_player, 4);
    if( save_game_version >= 7.0599999 )
        rge_read(v7, v5, v5, &v6->CantSeeBits, 4);
}

void __thiscall RGE_Doppleganger_Object::recycle_in_to_game(RGE_Master_Static_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, RGE_Static_Object *obj_to_dopple)
{
    RGE_Doppleganger_Object *v7; // esi@1
    RGE_Active_Sprite_Node *v8; // eax@2
    RGE_Static_Object *v9; // edi@2
    char v10; // al@2
    char v11; // dl@3
    unsigned __int32 **v12; // ecx@5
    RGE_Static_ObjectVtbl *v13; // edx@6
    RGE_Static_ObjectVtbl *v14; // eax@7

    v7 = this;
    this->doppled_object = 0;
    this->draw_color = 0;
    this->doppled_master_obj = 0;
    this->doppled_player = 0;
    this->MapAddress = 0;
    this->LastMapValue = 0;
    this->CantSeeBits = 0;
    this->map_draw_level = 0;
    this->map_color = 0;
    this->doppledObjectID = -1;
    RGE_Animated_Object::recycle_in_to_game((RGE_Animated_Object *)&this->vfptr, tobj, obj_owner, x, y, z);
    v7->type = 25;
    v7->doppled_object = obj_to_dopple;
    if( obj_to_dopple )
    {
        v7->doppled_master_obj = obj_to_dopple->master_obj;
        v7->doppled_player = obj_to_dopple->owner->id;
        v7->doppledObjectID = obj_to_dopple->id;
        v7->sprite = obj_to_dopple->sprite;
        v8 = RGE_Active_Sprite_List::copy_sprite_list(obj_to_dopple->sprite_list);
        RGE_Active_Sprite_List::use_sprite_list(v7->sprite_list, v8);
        v9 = v7->doppled_object;
        v7->facet = v9->facet;
        v7->draw_color = v9->owner->color_table;
        v10 = v9->master_obj->map_draw_level;
        v7->map_draw_level = v10;
        if( v10 == 3 )
            v11 = v9->master_obj->map_color;
        else
            v11 = v9->owner->color_table->map_color;
        v7->map_color = v11;
        v12 = (&unified_map_offsets)[(unsigned int)(signed __int64)y];
        v7->LastMapValue = 0;
        v7->CantSeeBits = 0;
        v7->MapAddress = (unsigned int *)&v12[(unsigned __int64)(signed __int64)x];
        if( v9->object_state >= 7u )
        {
            v13 = v7->vfptr;
            v7->doppled_object = 0;
            v7->doppledObjectID = -1;
            (*(void (__thiscall **)(RGE_Doppleganger_Object *))&v13[1].gap4[4])(v7);
            return;
        }
    }
    else
    {
        v14 = v7->vfptr;
        v7->doppledObjectID = -1;
        v7->doppled_master_obj = 0;
        v7->doppled_player = 0;
        v14->destroy_obj((RGE_Static_Object *)v7);
    }
    (*(void (__thiscall **)(RGE_Doppleganger_Object *))&v7->vfptr[1].gap4[4])(v7);
}

int __thiscall RGE_Doppleganger_Object::setup(RGE_Master_Doppleganger_Object *tobj, RGE_Player *obj_owner, float x, float y, float z)
{
    RGE_Doppleganger_Object *v6; // esi@1

    v6 = this;
    RGE_Animated_Object::setup(
        (RGE_Animated_Object *)&this->vfptr,
        (RGE_Master_Animated_Object *)&tobj->vfptr,
        obj_owner,
        x,
        y,
        z);
    v6->type = 25;
    v6->MapAddress = (unsigned int *)&(&unified_map_offsets)[(unsigned int)(signed __int64)y][(unsigned __int64)(signed __int64)x];
    v6->LastMapValue = 0;
    v6->CantSeeBits = 0;
    return 1;
}

bool RGE_Doppleganger_Object::setup(int infile, RGE_Game_World *gworld)
{
    RGE_Doppleganger_Object *v4; // esi@1
    double v5; // st7@1

    v4 = this;
    
    RGE_Animated_Object::setup(infile, gworld);

    v5 = v4->world_y;
    this->MapAddress = (unsigned int *)&(&unified_map_offsets)[(unsigned int)(signed __int64)v5][(unsigned __int64)(signed __int64)v4->world_x];
    this->LastMapValue = 0;
    this->CantSeeBits = 0;

    return true;
}

void __thiscall RGE_Doppleganger_Object::rehook()
{
    RGE_Doppleganger_Object *v1; // esi@1
    RGE_Static_Object *v2; // ecx@1
    RGE_Static_Object *v3; // eax@2
    RGE_Player *v4; // edx@3
    int v5; // eax@4
    RGE_Player *v6; // ecx@4
    signed int v7; // eax@6
    RGE_Player *v8; // ecx@7
    RGE_Static_ObjectVtbl *v9; // eax@9

    v1 = this;
    RGE_Static_Object::rehook((RGE_Static_Object *)&this->vfptr);
    v2 = v1->doppled_object;
    if( (signed int)v2 < 0 )
    {
        v1->doppled_object = 0;
        v5 = -1 - (_DWORD)v2;
        v6 = v1->owner;
        v1->doppledObjectID = -1;
        v4 = v6->world->players[v5];
        goto LABEL_5;
    }
    v3 = RGE_Static_Object::get_object_pointer((RGE_Static_Object *)&v1->vfptr, (int)v1->doppled_object);
    v1->doppled_object = v3;
    if( v3 )
    {
        v1->doppledObjectID = v3->id;
        v4 = v3->owner;
LABEL_5:
        v1->draw_color = v4->color_table;
    }
    v7 = (signed int)v1->doppled_master_obj;
    if( v7 < 0 || (v8 = v1->owner->world->players[v1->doppled_player], v7 >= v8->master_object_num) )
    {
        v9 = v1->vfptr;
        v1->doppled_master_obj = 0;
        v9->destroy_obj((RGE_Static_Object *)v1);
    }
    else
    {
        v1->doppled_master_obj = v8->master_objects[v7];
    }
}

bool RGE_Doppleganger_Object::update()
{
    RGE_Doppleganger_Object *v1; // esi@1
    char v2; // bl@1
    RGE_Static_Object *v3; // eax@1
    unsigned int v4; // edi@5
    RGE_Player *v5; // eax@6
    RGE_Player *v6; // ecx@11
    unsigned int v7; // eax@11
    unsigned int *v8; // ecx@12

    v1 = this;
    v2 = RGE_Animated_Object::update();
    v3 = v1->doppled_object;
    if( v3 ){
        if( v3->object_state < 7u )
            goto LABEL_5;
        v1->doppled_object = 0;
    }
    v1->doppledObjectID = -1;
LABEL_5:
    v4 = *v1->MapAddress;
    if( v4 != v1->LastMapValue )
    {
        v5 = v1->owner;
        if( v4 & v5->mutualVisibleMask && v1->object_state < 3u )
        {
            if( DDlogf )
                fprintf(DDlogf, aDieDop_DIdDOwn, v5->world->world_time, v1->id, v5->id);
            v1->vfptr->destroy_obj((RGE_Static_Object *)v1);
        }
        v6 = v1->owner;
        v7 = v4 & v6->nonMutualVisibleMask;
        if( v4 & v6->nonMutualVisibleMask )
        {
            v8 = v6->RemoveVisibleBits;
            do
            {
                if( (v7 & 1) == 1 )
                    v1->CantSeeBits |= *v8;
                ++v8;
                v7 >>= 1;
            }
            while( v7 );
        }
        v1->LastMapValue = v4;
    }
    return v2;
}

void __thiscall RGE_Doppleganger_Object::save(int outfile)
{
    int v2; // edi@1
    RGE_Doppleganger_Object *v3; // esi@1
    RGE_Static_Object *v4; // eax@1
    RGE_Master_Static_Object *v5; // eax@4

    v2 = outfile;
    v3 = this;
    RGE_Animated_Object::save((RGE_Animated_Object *)&this->vfptr, outfile);
    v4 = v3->doppled_object;
    if( v4 )
        outfile = v4->id;
    else
        outfile = -1 - v3->doppled_player;
    rge_write(outfile, &outfile, 4);
    rge_write(outfile, &v3->map_draw_level, 1);
    rge_write(outfile, &v3->map_color, 4);
    v5 = v3->doppled_master_obj;
    if( v5 )
        outfile = v5->id;
    else
        outfile = -1;
    rge_write(outfile, &outfile, 4);
    rge_write(outfile, &v3->doppled_player, 4);
    if( save_game_version >= 7.0599999 )
        rge_write(outfile, &v3->CantSeeBits, 4);
}

void __thiscall RGE_Doppleganger_Object::validate()
{
    RGE_Doppleganger_Object *v1; // esi@1
    RGE_Object_Node *i; // edi@1
    RGE_Static_Object *v3; // eax@2
    RGE_Player *v4; // edx@7
    short v5; // cx@7

    v1 = this;
    for( i = this->owner->world->map->map_row_offset[(unsigned __int64)(signed __int64)this->world_y][(unsigned __int64)(signed __int64)this->world_x].objects.list;
                i;
                i = i->next )
    {
        v3 = i->node;
        if( i->node
            && v3->type == 25
            && v3->id != v1->id
            && v3[1].objects == (RGE_Object_List *)v1->doppledObjectID
            && v3->object_state == 2 )
        {
            v4 = v3->owner;
            v5 = v1->owner->id;
            if( v4->id == v5 )
            {
                v3->vfptr->destroy_obj(i->node);
            }
            else
            {
                v3[1].tile = (unsigned int)v3[1].tile | (1 << v5);
                v1->CantSeeBits |= 1 << LOBYTE(v4->id);
            }
        }
    }
}
