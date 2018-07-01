
RGE_Object_List::RGE_Object_List()
{
    this->list = nullptr;
    this->number_of_objects = 0;
}

RGE_Object_List::~RGE_Object_List()
{
    RGE_Object_List *v1; // edi@1
    RGE_Object_Node *v2; // eax@1
    RGE_Object_Node *v3; // esi@2
    RGE_Static_Object *v4; // eax@2
    RGE_Object_Node *v5; // esi@6

    v1 = this;
    v2 = this->list;
    this->vfptr = (RGE_Object_ListVtbl *)&RGE_Object_List::`vftable';
    if( v2 )
    {
        do
        {
            v3 = v2->next;
            v4 = v2->node;
            if( v4 )
                v4->vfptr->__vecDelDtor(v4, 1u);
            v2 = v3;
        }
        while ( v3 );
    }
    if( v1->list )
    {
        do
        {
            v5 = v1->list->next;
            free(v5);
            v1->list = v5;
        }
        while ( v5 );
    }
    v1->number_of_objects = 0;
}

void RGE_Object_List::removeAllObjects()
{
    RGE_Object_List *v1; // ebx@1
    RGE_Object_Node *v2; // eax@1
    RGE_Object_Node *v3; // esi@2
    RGE_Static_Object *v4; // eax@2

    v1 = this;
    v2 = this->list;
    if( v2 )
    {
        do
        {
            v3 = v2->next;
            v4 = v2->node;
            if( v4 )
                v4->vfptr->__vecDelDtor(v4, 1u);
            v2 = v3;
        }
        while ( v3 );
    }
    v1->list = nullptr;
    v1->number_of_objects = 0;
}

RGE_Object_Node *RGE_Object_List::add_node(RGE_Static_Object *obj)
{
    RGE_Object_List *v2; // esi@1
    RGE_Object_Node *result; // eax@1
    RGE_Object_Node *v4; // ecx@1
    RGE_Object_Node *v5; // ecx@1

    v2 = this;
    result = (RGE_Object_Node *)calloc(1u, 0x10u);
    v4 = v2->list;
    result->prev = 0;
    result->next = v4;
    v5 = v2->list;
    if( v5 )
        v5->prev = result;
    result->node = obj;
    ++v2->number_of_objects;
    v2->list = result;
    return result;
}

//----- (00462F70) --------------------------------------------------------
void RGE_Object_List::remove_node(RGE_Static_Object *obj, RGE_Object_Node *node)
{
    RGE_Object_List *v3; // esi@1
    RGE_Object_Node *v4; // eax@1
    RGE_Object_Node *v5; // ecx@8
    RGE_Object_Node *v6; // ecx@11

    v3 = this;
    v4 = this->list;
    if( !v4 )
        return;
    if( node )
    {
        v4 = node;
        goto LABEL_8;
    }
    if( v4->node == obj )
    {
LABEL_8:
        v5 = v4->prev;
        if( v5 )
            v5->next = v4->next;
        else
            v3->list = v4->next;
        v6 = v4->next;
        if( v6 )
            v6->prev = v4->prev;
        free(v4);
        --v3->number_of_objects;
        return;
    }
    while ( 1 )
    {
        v4 = v4->next;
        if( !v4 )
            break;
        if( v4->node == obj )
            goto LABEL_8;
    }
}

//----- (00462FD0) --------------------------------------------------------
void RGE_Object_List::invert()
{
    RGE_Object_Node *v1; // eax@1
    RGE_Object_Node *i; // edx@1

    v1 = this->list;
    for( i = 0; v1; v1 = this->list )
    {
        this->list = v1->next;
        v1->next = i;
        if( i )
            i->prev = v1;
        i = v1;
        v1->prev = 0;
    }
    this->list = i;
}

//----- (00463000) --------------------------------------------------------
void RGE_Object_List::draw(TDrawArea *render_area, int x, int y, char fogged_tile)
{
    RGE_Object_Node *v5; // edi@1
    RGE_Static_Object *v6; // ecx@2
    RGE_Player *v7; // eax@3
    char v8; // bl@3
    RGE_Master_Static_Object *v9; // esi@3
    RGE_Object_Node *v10; // eax@18
    RGE_Object_List *i; // [sp+4h] [bp-4h]@1

    v5 = this->list;
    for( i = this; v5; v5 = v5->next )
    {
        v6 = v5->node;
        if( v5->node )
        {
            v7 = v6->owner;
            v8 = 1;
            v9 = (RGE_Master_Static_Object *)v7->color_table;
            switch( v6->master_obj->fog_flag )
            {
                case 0:
                    if( fogged_tile )
                        goto LABEL_5;
                    break;
                default:
                    break;
                case 2:
                    if( fogged_tile && v6->object_state > 2u )
                        goto LABEL_5;
                    break;
                case 3:
                    v8 = 0;
                    if( fogged_tile && v7->world->players[v7->world->curr_player]->mutualAlly[v7->id] )
                    {
                        v9 = v6[1].master_obj;
                        v8 = 1;
                    }
                    break;
                case 4:
                    if( fogged_tile )
                    {
                        if( i->number_of_objects > 1 )
                        {
                            v10 = i->list;
                            if( v10 )
                            {
                                while ( v10->node->type != 25 )
                                {
                                    v10 = v10->next;
                                    if( !v10 )
                                        goto LABEL_6;
                                }
LABEL_5:
                                v8 = 0;
                            }
                        }
                    }
                    break;
            }
LABEL_6:
            if( v8 )
                (*(void (__stdcall **)(TDrawArea *, _DWORD, _DWORD, RGE_Master_Static_Object *))&v6->vfptr->gap4[8])(
                    render_area,
                    x,
                    y,
                    v9);
        }
    }
}

//----- (00463100) --------------------------------------------------------
void RGE_Object_List::shadow_draw(TDrawArea *render_area, int x, int y, int flag, char fog_flag)
{
    RGE_Object_Node *v6; // esi@1
    RGE_Static_Object *v7; // ecx@3

    v6 = this->list;
    if( fog_flag )
    {
        for( ; v6; v6 = v6->next )
        {
            v7 = v6->node;
            if( v6->node )
            {
                if( v7->master_obj->fog_flag )
                    (*(void (__stdcall **)(TDrawArea *, _DWORD, _DWORD, _DWORD))&v7->vfptr->gap4[12])(render_area, x, y, flag);
            }
        }
    }
    else
    {
        for( ; v6; v6 = v6->next )
        {
            if( v6->node )
                (*(void (__stdcall **)(TDrawArea *, _DWORD, _DWORD, _DWORD))&v6->node->vfptr->gap4[12])(render_area, x, y, flag);
        }
    }
}

//----- (00463180) --------------------------------------------------------
void RGE_Object_List::normal_draw(TDrawArea *render_area, int x, int y, char fog_flag)
{
    RGE_Object_Node *v5; // edi@1
    RGE_Object_Node *v6; // esi@1
    RGE_Static_Object *v7; // ecx@3
    RGE_Object_Node *v8; // esi@13

    v5 = RGE_Object_List::sort(this);
    v6 = v5;
    if( fog_flag )
    {
        if( !v5 )
            return;
        do
        {
            v7 = v6->node;
            if( v6->node && v7->master_obj->fog_flag )
                (*(void (__stdcall **)(TDrawArea *, _DWORD, _DWORD))&v7->vfptr->gap4[16])(render_area, x, y);
            v6 = v6->next;
        }
        while ( v6 );
    }
    else
    {
        if( !v5 )
            return;
        do
        {
            if( v6->node )
                (*(void (__stdcall **)(TDrawArea *, _DWORD, _DWORD))&v6->node->vfptr->gap4[16])(render_area, x, y);
            v6 = v6->next;
        }
        while ( v6 );
    }
    if( v5 )
    {
        do
        {
            v8 = v5->next;
            free(v5);
            v5 = v8;
        }
        while ( v8 );
    }
}

//----- (00463210) --------------------------------------------------------
void RGE_Object_List::update()
{
    RGE_Object_Node *v1; // esi@1
    int v2; // ebx@1
    RGE_Object_Node *v3; // edi@2

    v1 = this->list;
    v2 = 0;
    if( v1 )
    {
        do
        {
            v3 = v1->next;
            if( v1->node )
            {
                if( (unsigned __int8)(*(int (**)(void))&v1->node->vfptr->gap4[32])() )
                    (*(void (**)(void))&v1->node->vfptr->gap4[4])();
                if( ++v2 > 9 )
                {
                    v2 = 0;
                    if( MouseSystem )
                        TMousePointer::Poll(MouseSystem);
                }
            }
            v1 = v3;
        }
        while ( v3 );
    }
}

//----- (00463260) --------------------------------------------------------
RGE_Object_Node *RGE_Object_List::sort()
{
    RGE_Object_Node *v1; // ebx@1
    RGE_Object_Node *result; // eax@1
    RGE_Object_Node **v3; // esi@2
    char i; // dl@2
    char v5; // cl@3
    RGE_Object_Node *v6; // eax@7
    RGE_Object_Node *sorted; // [sp+4h] [bp-4h]@1

    v1 = this->list;
    result = 0;
    for( sorted = 0; v1; result = sorted )
    {
        v3 = &sorted;
        for( i = v1->node->master_obj->sort_number; result; result = result->next )
        {
            v5 = result->node->master_obj->sort_number;
            if( (unsigned __int8)v5 < (unsigned __int8)i
                || v5 == i && result->node->screen_y_offset > v1->node->screen_y_offset )
            {
                break;
            }
            v3 = &result->next;
        }
        v6 = (RGE_Object_Node *)calloc(1u, 0x10u);
        v6->next = *v3;
        if( *v3 )
        {
            v6->prev = (*v3)->prev;
            (*v3)->prev = v6;
        }
        v6->node = v1->node;
        *v3 = v6;
        v1 = v1->next;
    }
    return result;
}

//----- (004632E0) --------------------------------------------------------
RGE_Static_Object *RGE_Object_List::find_by_group(int id)
{
    RGE_Static_Object *result; // eax@1

    result = (RGE_Static_Object *)&this->list->node;
    if( result )
    {
        while ( !result->vfptr || *(_WORD *)(*(_DWORD *)&result->vfptr->gap4[4] + 20) != id )
        {
            result = (RGE_Static_Object *)result->id;
            if( !result )
                return result;
        }
        result = (RGE_Static_Object *)result->vfptr;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00463310) --------------------------------------------------------
RGE_Static_Object *RGE_Object_List::find_by_group(int id, float x, float y, char certain_state, char object_state, RGE_Static_Object *zone_obj)
{
    RGE_Static_Object *v7; // ebx@1
    RGE_Object_List *v8; // esi@1
    signed int v9; // ebp@4
    RGE_Object_Node *v10; // edi@6
    RGE_Static_Object *v11; // esi@7
    double v12; // st6@15
    double v13; // st7@15
    float diff_x; // ST18_4@15
    double v16; // st7@15
    char v17; // c3@15
    RGE_Static_Object *found_obj; // [sp+4h] [bp-4h]@6
    RGE_Static_Object *zone_obja; // [sp+20h] [bp+18h]@6

    v7 = zone_obj;
    v8 = this;
    if( x > -1.0 && y > -1.0 && zone_obj )
        v9 = (unsigned __int8)RGE_Static_Object::lookupZone(zone_obj, (signed __int64)x, (signed __int64)y);
    else
        v9 = -1;
    v10 = v8->list;
    found_obj = 0;
    *(float *)&zone_obja = -1.0;
    if( v10 )
    {
        while ( 1 )
        {
            v11 = v10->node;
            if( v10->node && v11->master_obj->object_group == id && (!certain_state || v11->object_state == object_state) )
            {
                if( x == -1.0 || y == -1.0 )
                    return v10->node;
                if( v9 <= -1
                    || (unsigned __int8)RGE_Static_Object::lookupZone(
                                                                v7,
                                                                (signed __int64)v11->world_x,
                                                                (signed __int64)v11->world_y) == v9 )
                {
                    v12 = x - v10->node->world_x;
                    v13 = y - v10->node->world_y;
                    diff_x = v12;
                    v16 = v12 * diff_x + v13 * v13;
                    if( v17 || *(float *)&zone_obja > v16 )
                    {
                        *(float *)&zone_obja = v16;
                        found_obj = v10->node;
                    }
                }
            }
            v10 = v10->next;
            if( !v10 )
                return found_obj;
        }
    }
    return 0;
}

//----- (00463490) --------------------------------------------------------
RGE_Static_Object *RGE_Object_List::find_by_id(int id)
{
    RGE_Static_Object *result; // eax@1

    result = (RGE_Static_Object *)&this->list->node;
    if( result )
    {
        while ( !result->vfptr || *(_DWORD *)&result->vfptr->gap4[0] != id )
        {
            result = (RGE_Static_Object *)result->id;
            if( !result )
                return result;
        }
        result = (RGE_Static_Object *)result->vfptr;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004634C0) --------------------------------------------------------
RGE_Static_Object *RGE_Object_List::find_by_master_id(int id, float x, float y, char certain_state, char object_state, RGE_Static_Object *zone_obj)
{
    RGE_Static_Object *v7; // ebx@1
    RGE_Object_List *v8; // esi@1
    signed int v9; // ebp@4
    RGE_Object_Node *v10; // edi@6
    RGE_Static_Object *v11; // esi@7
    double v12; // st6@15
    double v13; // st7@15
    float diff_x; // ST18_4@15
    double v16; // st7@15
    char v17; // c3@15
    RGE_Static_Object *found_obj; // [sp+4h] [bp-4h]@6
    RGE_Static_Object *zone_obja; // [sp+20h] [bp+18h]@6

    v7 = zone_obj;
    v8 = this;
    if( x > -1.0 && y > -1.0 && zone_obj )
        v9 = (unsigned __int8)RGE_Static_Object::lookupZone(zone_obj, (signed __int64)x, (signed __int64)y);
    else
        v9 = -1;
    v10 = v8->list;
    found_obj = 0;
    *(float *)&zone_obja = -1.0;
    if( v10 )
    {
        while ( 1 )
        {
            v11 = v10->node;
            if( v10->node && v11->master_obj->id == id && (!certain_state || v11->object_state == object_state) )
            {
                if( x == -1.0 || y == -1.0 )
                    return v10->node;
                if( v9 <= -1
                    || (unsigned __int8)RGE_Static_Object::lookupZone(
                                                                v7,
                                                                (signed __int64)v11->world_x,
                                                                (signed __int64)v11->world_y) == v9 )
                {
                    v12 = x - v10->node->world_x;
                    v13 = y - v10->node->world_y;
                    diff_x = v12;
                    v16 = v12 * diff_x + v13 * v13;
                    if( v17 || *(float *)&zone_obja > v16 )
                    {
                        *(float *)&zone_obja = v16;
                        found_obj = v10->node;
                    }
                }
            }
            v10 = v10->next;
            if( !v10 )
                return found_obj;
        }
    }
    return 0;
}

//----- (00463640) --------------------------------------------------------
RGE_Static_Object *RGE_Object_List::find_by_master_ids(int id1, int id2, float x, float y, char certain_state, char object_state, RGE_Static_Object *zone_obj)
{
    RGE_Static_Object *v8; // ebx@1
    RGE_Object_List *v9; // esi@1
    signed int v10; // ebp@4
    RGE_Object_Node *v11; // edi@6
    RGE_Static_Object *v12; // esi@7
    int v13; // eax@7
    double v14; // st6@16
    double v15; // st7@16
    float diff_x; // ST18_4@16
    double v18; // st7@16
    char v19; // c3@16
    RGE_Static_Object *found_obj; // [sp+14h] [bp-4h]@6
    RGE_Static_Object *zone_obja; // [sp+34h] [bp+1Ch]@6

    v8 = zone_obj;
    v9 = this;
    if( zone_obj && x > -1.0 && y > -1.0 )
        v10 = (unsigned __int8)RGE_Static_Object::lookupZone(zone_obj, (signed __int64)x, (signed __int64)y);
    else
        v10 = -1;
    v11 = v9->list;
    found_obj = 0;
    *(float *)&zone_obja = -1.0;
    if( v11 )
    {
        while ( 1 )
        {
            v12 = v11->node;
            v13 = v11->node->master_obj->id;
            if( v11->node && (v13 == id1 || v13 == id2) && (!certain_state || v12->object_state == object_state) )
            {
                if( x == -1.0 && y == -1.0 )
                    return v11->node;
                if( v10 <= -1
                    || (unsigned __int8)RGE_Static_Object::lookupZone(
                                                                v8,
                                                                (signed __int64)v12->world_x,
                                                                (signed __int64)v12->world_y) == v10 )
                {
                    v14 = x - v11->node->world_x;
                    v15 = y - v11->node->world_y;
                    diff_x = v14;
                    v18 = v14 * diff_x + v15 * v15;
                    if( v19 || *(float *)&zone_obja > v18 )
                    {
                        *(float *)&zone_obja = v18;
                        found_obj = v11->node;
                    }
                }
            }
            v11 = v11->next;
            if( !v11 )
                return found_obj;
        }
    }
    return 0;
}

//----- (004637C0) --------------------------------------------------------
RGE_Static_Object *RGE_Object_List::find_by_type(char type, float x, float y, char certain_state, char object_state)
{
    RGE_Object_Node *v6; // edx@1
    RGE_Static_Object *v7; // esi@1
    char v8; // bl@2
    RGE_Static_Object *v9; // ecx@3
    double v10; // st6@9
    double v11; // st7@9
    double v13; // st7@9
    char v14; // c3@9
    float dist; // [sp+8h] [bp-4h]@1
    float object_statea; // [sp+20h] [bp+14h]@9

    v6 = this->list;
    v7 = 0;
    dist = -1.0;
    if( v6 )
    {
        v8 = object_state;
        while ( 1 )
        {
            v9 = v6->node;
            if( v6->node && v9->type == type && (!certain_state || v9->object_state == v8) )
            {
                if( x == -1.0 && y == -1.0 )
                    return v6->node;
                v10 = x - v9->world_x;
                v11 = y - v9->world_y;
                object_statea = v10;
                v13 = v10 * object_statea + v11 * v11;
                if( v14 || dist > v13 )
                {
                    dist = v13;
                    v7 = v6->node;
                }
            }
            v6 = v6->next;
            if( !v6 )
                return v7;
        }
    }
    return 0;
}

void RGE_Object_List::save(int outfile)
{
    RGE_Object_Node *v2; // esi@1
    char finished; // [sp+Bh] [bp-1h]@1

    v2 = this->list;
    for( finished = 0; v2; v2 = v2->next )
    {
        if( v2->node )
            (*(void (__stdcall **)(int))&v2->node->vfptr->gap4[44])(outfile);
    }
    rge_write(outfile, &finished, 1);
}

void RGE_Object_List::load_list(int infile, RGE_Game_World *world)
{
    RGE_Game_World *v4; // ebx@1
    RGE_Object_List *i; // edi@1

    RGE_Object_Node *sub_node = this->list;

    while( true ){
        rge_read(infile, &obj_type, 1);
        if( obj_type == 0 ){
            break;
        }
        sub_node = new RGE_Object_Node;
        this->load(obj_type, infile, world)
    }
    this->invert();
}

void RGE_Object_List::rehook_list()
{
    RGE_Object_Node *i; // esi@1

    for( i = this->list; i; i = i->next )
        (*(void (**)(void))&i->node->vfptr->gap4[40])();
}

RGE_Static_Object *RGE_Object_List::load(
    char object_type,
    int infile,
    RGE_Game_World *world)
{
    switch( object_type ){

    case RGE_STATIC_OBJECT_TYPE:
        return new RGE_Static_Object(
            infile,
            world,
            true);

    case RGE_ANIMATED_OBJECT_TYPE:
        return new RGE_Animated_Object(
            infile,
            world,
            true);

    case RGE_DOPPLEGANGER_OBJECT_TYPE:
        return RGE_Doppleganger_Object(
            infile,
            world,
            true);

    case RGE_MOVING_OBJECT_TYPE:
        return new RGE_Moving_Object(
            infile,
            world,
            true);

    case RGE_ACTION_OBJECT_TYPE:
        return new RGE_Action_Object(
            infile,
            world,
            true);

    case RGE_COMBAT_OBJECT_TYPE:
        return new RGE_Combat_Object(
            infile,
            world,
            true);

    case RGE_MISSILE_OBJECT_TYPE:
        return new RGE_Missile_Object(
            infile,
            world,
            true);

    default:
        return;
    }
}
