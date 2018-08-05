
int TRIBE_Tech::TRIBE_Tech(int handle, int a4)
{
    int v4; // ebp@0
    int v6; // [sp+0h] [bp-10h]@1
    short j; // [sp+4h] [bp-Ch]@4
    short k; // [sp+4h] [bp-Ch]@7
    short data; // [sp+8h] [bp-8h]@10
    short i; // [sp+Ch] [bp-4h]@2

    v6 = a1;
    *(_DWORD *)(a1 + 8) = a4;
    rge_read(v4, a2, handle, (void *)(a1 + 4), 2);
    if( (signed int)*(_WORD *)(v6 + 4) <= 0 )
    {
        *(_DWORD *)v6 = 0;
    }
    else
    {
        *(_DWORD *)v6 = calloc(0x3Cu, *(_WORD *)(v6 + 4));
        for( i = 0; i < (signed int)*(_WORD *)(v6 + 4); ++i )
        {
            for( j = 0; j < 4; ++j )
                rge_read(v4, a2, handle, (void *)(60 * i + *(_DWORD *)v6 + 2 * j + 4), 2);
            for( k = 0; k < 3; ++k )
            {
                rge_read(v4, a2, handle, (void *)(60 * i + *(_DWORD *)v6 + 2 * k + 14), 2);
                rge_read(v4, a2, handle, (void *)(60 * i + *(_DWORD *)v6 + 2 * k + 20), 2);
                rge_read(v4, a2, handle, (void *)(60 * i + *(_DWORD *)v6 + k + 26), 1);
            }
            rge_read(v4, a2, handle, (void *)(*(_DWORD *)v6 + 60 * i + 12), 2);
            rge_read(v4, a2, handle, (void *)(*(_DWORD *)v6 + 60 * i + 40), 2);
            rge_read(v4, a2, handle, (void *)(*(_DWORD *)v6 + 60 * i + 42), 2);
            rge_read(v4, a2, handle, (void *)(*(_DWORD *)v6 + 60 * i + 44), 2);
            rge_read(v4, a2, handle, (void *)(*(_DWORD *)v6 + 60 * i + 30), 2);
            rge_read(v4, a2, handle, (void *)(*(_DWORD *)v6 + 60 * i + 32), 2);
            rge_read(v4, a2, handle, (void *)(*(_DWORD *)v6 + 60 * i + 34), 2);
            rge_read(v4, a2, handle, (void *)(*(_DWORD *)v6 + 60 * i + 36), 2);
            rge_read(v4, a2, handle, (void *)(*(_DWORD *)v6 + 60 * i + 38), 1);
            rge_read(v4, a2, handle, (void *)(*(_DWORD *)v6 + 60 * i + 48), 4);
            rge_read(v4, a2, handle, (void *)(*(_DWORD *)v6 + 60 * i + 52), 4);
            rge_read(v4, a2, handle, (void *)(*(_DWORD *)v6 + 60 * i + 56), 4);
            rge_read(v4, a2, handle, &data, 2);
            if( data <= 0 )
            {
                *(_DWORD *)(*(_DWORD *)v6 + 60 * i) = 0;
            }
            else
            {
                *(_DWORD *)(*(_DWORD *)v6 + 60 * i) = calloc(1u, data);
                rge_read(v4, a2, handle, *(void **)(*(_DWORD *)v6 + 60 * i), data);
            }
        }
    }
    return v6;
}

void TRIBE_Tech::~TRIBE_Tech()
{
    TRIBE_Tech *v1; // [sp+0h] [bp-8h]@1
    signed int i; // [sp+4h] [bp-4h]@2

    v1 = this;
    if( this->tech_tree )
    {
        for( i = 0; i < v1->tech_tree_num; ++i )
        {
            if( v1->tech_tree[i].name )
                free(v1->tech_tree[i].name);
        }
        free(v1->tech_tree);
        v1->tech_tree = 0;
    }
}

//----- (0050BF9C) --------------------------------------------------------
char TRIBE_Tech::do_tech(short a2, struct RGE_Player *a3)
{
    int v3; // edx@2

    if( this->tech_tree[a2].effect >= 0 )
    {
        v3 = 60 * a2;
        LOWORD(v3) = *(short *)((char *)&this->tech_tree->effect + v3);
        this->world->effects->vfptr->do_effect(this->world->effects, v3, a3);
    }
    return 1;
}

void TRIBE_Tech::save( int handle )
{
    rge_write(handle, &this->tech_tree_num, 2);

    for( short i = 0; i < this->tech_tree_num; i++ ){

        for( short j = 0; j < 4; j++ ){
            rge_write(handle, &this->tech_tree[i].pre_reqs[j], 2);
        }

        for( short k = 0; k < 3; k++ ){
            rge_write(handle, &this->tech_tree[i].attribute[k], 2);
            rge_write(handle, &this->tech_tree[i].attribute_cost[k], 2);
            rge_write(handle, &this->tech_tree[i].attribute_used[k], 1);
        }
        rge_write(handle, &this->tech_tree[i].pre_reqs_required, 2);
        rge_write(handle, &this->tech_tree[i].build_obj_id, 2);
        rge_write(handle, &this->tech_tree[i].string_id, 2);
        rge_write(handle, &this->tech_tree[i].string_id2, 2);
        rge_write(handle, &this->tech_tree[i].research, 2);
        rge_write(handle, &this->tech_tree[i].effect, 2);
        rge_write(handle, &this->tech_tree[i].track, 2);
        rge_write(handle, &this->tech_tree[i].icon, 2);
        rge_write(handle, &this->tech_tree[i].button_location, 1);
        rge_write(handle, &this->tech_tree[i].help_string_id, 4);
        rge_write(handle, &this->tech_tree[i].help_page_id, 4);
        rge_write(handle, &this->tech_tree[i].hotkey_id, 4);

        if( this->tech_tree[i].name ){
            data = strlen(this->tech_tree[i].name) + 1;
        }else{
            data = 0;
        }
        rge_write(handle, &data, 2);
        if( data > 0 ){
            rge_write(handle, this->tech_tree[i].name, data);
        }
    }
}

//----- (0050C2FA) --------------------------------------------------------
int TRIBE_Tech::get_help_message(short a2)
{
    int result; // eax@3

    if( a2 >= 0 && a2 <= this->tech_tree_num )
        result = this->tech_tree[a2].help_string_id;
    else
        result = -1;
    return result;
}

//----- (0050C333) --------------------------------------------------------
int TRIBE_Tech::get_help_page(short a2)
{
    int result; // eax@3

    if( a2 >= 0 && a2 <= this->tech_tree_num )
        result = this->tech_tree[a2].help_page_id;
    else
        result = -1;
    return result;
}

//----- (0050C36C) --------------------------------------------------------
int TRIBE_Tech::get_hotkey(short a2)
{
    int result; // eax@3

    if( a2 >= 0 && a2 <= this->tech_tree_num )
        result = this->tech_tree[a2].hotkey_id;
    else
        result = -1;
    return result;
}

//----- (0050C3A5) --------------------------------------------------------
TRIBE_Player_Tech *TRIBE_Player_Tech::TRIBE_Player_Tech(int handle, int a4, int a5, int a6)
{
    int v6; // ebp@0
    TRIBE_Player_Tech *v8; // [sp+0h] [bp-8h]@1
    short i; // [sp+4h] [bp-4h]@2
    short j; // [sp+4h] [bp-4h]@9

    v8 = a1;
    rge_read(v6, a2, handle, &a1->tech_player_tree_num, 2);
    v8->base_tech = (TRIBE_Tech *)a4;
    v8->owner = (RGE_Player *)a5;
    if( v8->tech_player_tree_num > 0 )
    {
        v8->tech_player_tree = (Tech_Player_Tree *)calloc(8u, v8->tech_player_tree_num);
        for( i = 0; i < v8->tech_player_tree_num; ++i )
        {
            if( save_game_version > 7.0300002 )
                rge_read(v6, a2, handle, &v8->tech_player_tree[i], 4);
            else
                rge_read(v6, a2, handle, &v8->tech_player_tree[i], 2);
            rge_read(v6, a2, handle, &v8->tech_player_tree[i].state, 2);
        }
        if( (_BYTE)a6 )
        {
            for( j = 0; j < v8->tech_player_tree_num; ++j )
            {
                if( v8->tech_player_tree[j].state == 3 )
                {
                    v8->tech_player_tree[j].state = 1;
                    TRIBE_Player_Tech::do_tech(v8, j);
                }
            }
            TRIBE_Player_Tech::check_for_new_tech(v8);
        }
    }
    return v8;
}
// 58EBCC: using guessed type float save_game_version;

//----- (0050C4FC) --------------------------------------------------------
TRIBE_Player_Tech *TRIBE_Player_Tech::TRIBE_Player_Tech(TRIBE_Tech *a2, RGE_Player *a3, char a4)
{
    TRIBE_Player_Tech *v5; // [sp+0h] [bp-4h]@1

    v5 = this;
    this->base_tech = a2;
    this->owner = a3;
    this->tech_player_tree_num = a2->tech_tree_num;
    if( this->tech_player_tree_num > 0 )
        this->tech_player_tree = (Tech_Player_Tree *)calloc(8u, this->tech_player_tree_num);
    if( a4 )
        TRIBE_Player_Tech::check_for_new_tech(v5);
    return v5;
}

//----- (0050C562) --------------------------------------------------------
TRIBE_Player_Tech *TRIBE_Player_Tech::~TRIBE_Player_Tech()
{
    TRIBE_Player_Tech *result; // eax@1
    TRIBE_Player_Tech *v2; // [sp+0h] [bp-4h]@1

    v2 = this;
    result = this;
    if( this->tech_player_tree )
    {
        free(this->tech_player_tree);
        result = v2;
        v2->tech_player_tree = 0;
    }
    return result;
}

//----- (0050C58C) --------------------------------------------------------
short TRIBE_Player_Tech::get_tech_state(short a2)
{
    return this->tech_player_tree[a2].state;
}

//----- (0050C5A7) --------------------------------------------------------
char TRIBE_Player_Tech::undo_tech(short a2)
{
    char result; // al@2

    if( this->tech_player_tree[a2].state < 1 )
    {
        result = 0;
    }
    else
    {
        this->tech_player_tree[a2].state = 0;
        TRIBE_Player_Tech::check_for_new_tech(this);
        result = 1;
    }
    return result;
}

//----- (0050C5E5) --------------------------------------------------------
char TRIBE_Player_Tech::do_tech(short a2)
{
    char result; // al@9
    TRIBE_Player_Tech *v3; // [sp+0h] [bp-4h]@1

    v3 = this;
    if( this->tech_player_tree[a2].state >= 3 || this->tech_player_tree[a2].state <= -1 )
    {
        result = 0;
    }
    else
    {
        this->tech_player_tree[a2].state = 3;
        TRIBE_Tech::do_tech(this->base_tech, a2, this->owner);
        TRIBE_Player_Tech::check_for_new_tech(v3);
        switch ( a2 )
        {
            case 101:
                TRIBE_History_Info::add_history_event(*(TRIBE_History_Info **)&v3->owner[3].groups_used[62], 0);
                break;
            case 102:
                TRIBE_History_Info::add_history_event(*(TRIBE_History_Info **)&v3->owner[3].groups_used[62], 1);
                break;
            case 103:
                TRIBE_History_Info::add_history_event(*(TRIBE_History_Info **)&v3->owner[3].groups_used[62], 2);
                break;
        }
        result = 1;
    }
    return result;
}

//----- (0050C6AD) --------------------------------------------------------
char TRIBE_Player_Tech::research(short a2, float a3)
{
    char result; // al@3

    if( this->tech_player_tree[a2].state == 2 )
    {
        this->tech_player_tree[a2].research_done = this->tech_player_tree[a2].research_done + a3;
        if( (double)this->base_tech->tech_tree[a2].research > this->tech_player_tree[a2].research_done )
        {
            result = 1;
        }
        else
        {
            TRIBE_Player_Tech::do_tech(this, a2);
            result = 0;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0050C730) --------------------------------------------------------
void TRIBE_Player_Tech::tech_cost(short a2, short *a3, short *a4, short *a5, short *a6, short *a7, short *a8)
{
    TRIBE_Player_Tech *v8; // [sp+10h] [bp-10h]@1
    Tech_Tree *v9; // [sp+14h] [bp-Ch]@1
    short v10; // [sp+18h] [bp-8h]@1
    char v11; // [sp+1Ch] [bp-4h]@1

    v8 = this;
    v9 = &this->base_tech->tech_tree[a2];
    v10 = 0;
    *a3 = -1;
    *a4 = 0;
    *a5 = -1;
    *a6 = 0;
    *a7 = -1;
    *a8 = 0;
    v11 = TRIBE_Player_Tech::check_tech_cost(this, a2, 0);
    if( v8->owner->attributes[29] < 1.0 )
        v11 = 0;
    if( v9->attribute_used[0] )
    {
        *a3 = v9->attribute[0];
        if( *a3 >= 0 )
        {
            *a4 = v9->attribute_cost[0];
            if( (double)*a4 > v8->owner->attributes[*a3] )
            {
                if( v11 )
                {
                    v10 = *a4 - (unsigned __int64)(signed __int64)v8->owner->attributes[*a3];
                    *a4 = (signed __int64)v8->owner->attributes[*a3];
                }
            }
        }
    }
    if( v9->attribute_used[1] )
    {
        *a5 = v9->attribute[1];
        if( *a5 >= 0 )
        {
            *a6 = v9->attribute_cost[1];
            if( (double)*a6 > v8->owner->attributes[*a5] )
            {
                if( v11 )
                {
                    v10 += *a6 - (unsigned __int64)(signed __int64)v8->owner->attributes[*a5];
                    *a6 = (signed __int64)v8->owner->attributes[*a5];
                }
            }
        }
    }
    if( v9->attribute_used[2] )
    {
        *a7 = v9->attribute[2];
        if( *a7 >= 0 )
        {
            *a8 = v9->attribute_cost[2];
            if( (double)*a8 > v8->owner->attributes[*a7] )
            {
                if( v11 )
                {
                    v10 += *a8 - (unsigned __int64)(signed __int64)v8->owner->attributes[*a7];
                    *a8 = (signed __int64)v8->owner->attributes[*a7];
                }
            }
        }
    }
    if( v10 > 0 )
    {
        if( *a3 != 3 && *a3 != -1 )
        {
            if( *a5 != 3 && *a5 != -1 )
            {
                if( *a7 == 3 || *a7 == -1 )
                {
                    *a7 = 3;
                    *a8 = v10;
                }
            }
            else
            {
                *a5 = 3;
                *a6 += v10;
            }
        }
        else
        {
            *a3 = 3;
            *a4 += v10;
        }
    }
    if( *a4 <= 0 )
        *a3 = -1;
    if( *a6 <= 0 )
        *a5 = -1;
    if( *a8 <= 0 )
        *a7 = -1;
}

//----- (0050CA9E) --------------------------------------------------------
char TRIBE_Player_Tech::check_tech_cost(short a2, short *a3)
{
    signed int i; // [sp+8h] [bp-18h]@5
    int v5; // [sp+Ch] [bp-14h]@7
    Tech_Tree *v6; // [sp+10h] [bp-10h]@1
    float v7; // [sp+14h] [bp-Ch]@1
    float v8; // [sp+18h] [bp-8h]@9
    char v9; // [sp+1Ch] [bp-4h]@2

    v6 = &this->base_tech->tech_tree[a2];
    v7 = this->owner->attributes[3];
    if( this->owner->attributes[29] >= 1.0 )
    {
        v9 = 1;
    }
    else
    {
        v7 = 0.0;
        v9 = 0;
    }
    if( this->tech_player_tree[a2].state == 1 )
    {
        for( i = 0; ; ++i )
        {
            if( i >= 3 )
                return 1;
            v5 = v6->attribute[i];
            if( v5 >= 0 && v6->attribute_used[i] )
            {
                v8 = (double)v6->attribute_cost[i];
                if( v9 )
                {
                    if( v5 == 3 )
                    {
                        v7 = v7 - v8;
                        if( v7 < 0.0 )
                        {
                            if( a3 )
                                *a3 = 3;
                            return 0;
                        }
                    }
                }
                if( this->owner->attributes[v5] < (double)v8 )
                {
                    if( v7 + this->owner->attributes[v5] < v8 )
                    {
                        if( a3 )
                            *a3 = v5;
                        return 0;
                    }
                    v7 = v7 - (v8 - this->owner->attributes[v5]);
                }
            }
        }
    }
    if( a3 )
        *a3 = -1;
    return 0;
}

//----- (0050CC25) --------------------------------------------------------
char TRIBE_Player_Tech::start_research(short a2, unsigned __int8 a3, short *a4)
{
    char result; // al@12
    TRIBE_Player_Tech *v5; // [sp+4h] [bp-14h]@1
    signed int i; // [sp+8h] [bp-10h]@3
    int v7; // [sp+Ch] [bp-Ch]@5
    Tech_Tree *v8; // [sp+10h] [bp-8h]@1
    float v9; // [sp+14h] [bp-4h]@7

    v5 = this;
    v8 = &this->base_tech->tech_tree[a2];
    if( TRIBE_Player_Tech::check_tech_cost(this, a2, a4) )
    {
        if( a3 )
        {
            for( i = 0; i < 3; ++i )
            {
                v7 = v8->attribute[i];
                if( v7 >= 0 && v8->attribute_used[i] )
                {
                    v9 = (double)v8->attribute_cost[i];
                    if( v5->owner->attributes[v7] >= (double)v9 )
                    {
                        v5->owner->attributes[v7] = v5->owner->attributes[v7] - v9;
                    }
                    else
                    {
                        v5->owner->attributes[3] = v5->owner->attributes[3] - (v9 - v5->owner->attributes[v7]);
                        LODWORD(v5->owner->attributes[v7]) = 0;
                    }
                }
            }
            v5->tech_player_tree[a2].state = 2;
        }
        result = 1;
    }
    else
    {
        if( a4 )
            *a4 = -1;
        result = 0;
    }
    return result;
}

//----- (0050CD73) --------------------------------------------------------
char TRIBE_Player_Tech::cancel_research(short a2, unsigned __int8 a3)
{
    char result; // al@9
    short i; // [sp+Ch] [bp-8h]@3
    Tech_Tree *v5; // [sp+10h] [bp-4h]@1

    v5 = &this->base_tech->tech_tree[a2];
    if( this->tech_player_tree[a2].state == 2 )
    {
        if( a3 )
        {
            for( i = 0; i < 3; ++i )
            {
                if( v5->attribute[i] >= 0 )
                {
                    if( v5->attribute_used[i] )
                        this->owner->attributes[v5->attribute[i]] = (double)v5->attribute_cost[i]
                                                                                                            + this->owner->attributes[v5->attribute[i]];
                }
            }
        }
        this->tech_player_tree[a2].state = 1;
        LODWORD(this->tech_player_tree[a2].research_done) = 0;
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (0050CE68) --------------------------------------------------------
char TRIBE_Player_Tech::check_for_new_tech()
{
    TRIBE_Player_Tech *v2; // [sp+4h] [bp-20h]@1
    Tech_Tree *v3; // [sp+8h] [bp-1Ch]@1
    short i; // [sp+Ch] [bp-18h]@1
    short j; // [sp+10h] [bp-14h]@5
    unsigned __int8 v6; // [sp+14h] [bp-10h]@5
    short v7; // [sp+18h] [bp-Ch]@5
    short v8; // [sp+1Ch] [bp-8h]@1

    v2 = this;
    v8 = 0;
    v3 = this->base_tech->tech_tree;
    for( i = 0; i < v2->tech_player_tree_num; ++i )
    {
        if( v2->tech_player_tree[i].state >= 2 || v2->tech_player_tree[i].state <= -1 )
        {
            if( v2->tech_player_tree[i].state == 2 )
                ++v8;
        }
        else
        {
            ++v8;
            v6 = 0;
            v7 = 0;
            for( j = 0; j < 4; ++j )
            {
                if( v3[i].pre_reqs[j] >= 0 )
                {
                    ++v7;
                    if( v2->tech_player_tree[v3[i].pre_reqs[j]].state == 3 )
                        ++v6;
                }
            }
            if( v6 < v3[i].pre_reqs_required )
            {
                if( v2->tech_player_tree[i].state > 0 )
                    v2->tech_player_tree[i].state = 0;
            }
            else if( (double)v3[i].research > v2->tech_player_tree[i].research_done )
            {
                if( v2->tech_player_tree[i].state < 1 )
                    v2->tech_player_tree[i].state = 1;
            }
            else
            {
                TRIBE_Player_Tech::do_tech(v2, i);
                --v8;
            }
        }
    }
    if( !v8 && v2->owner->attributes[39] == 0.0 )
        *((_DWORD *)v2->owner->attributes + 39) = 1065353216;
    return 1;
}

//----- (0050D07A) --------------------------------------------------------
void TRIBE_Player_Tech::save(int handle)
{
    TRIBE_Player_Tech *v2; // [sp+0h] [bp-8h]@1
    short i; // [sp+4h] [bp-4h]@1

    v2 = this;
    rge_write(handle, &this->tech_player_tree_num, 2);
    for( i = 0; i < v2->tech_player_tree_num; ++i )
    {
        rge_write(handle, &v2->tech_player_tree[i], 4);
        rge_write(handle, &v2->tech_player_tree[i].state, 2);
    }
}

//----- (0050D0FA) --------------------------------------------------------
short TRIBE_Player_Tech::get_progress(short a2)
{
    signed short v3; // [sp+8h] [bp-4h]@2

    if( this->tech_player_tree[a2].state == 2 )
    {
        v3 = (signed __int64)(this->tech_player_tree[a2].research_done
                                                * 100.0
                                                / (double)this->base_tech->tech_tree[a2].research);
    }
    else if( this->tech_player_tree[a2].state == 3 )
    {
        v3 = 100;
    }
    else
    {
        v3 = 0;
    }
    return v3;
}

//----- (0050D178) --------------------------------------------------------
char *TRIBE_Player_Tech::get_name(short a2)
{
    return this->base_tech->tech_tree[a2].name;
}

//----- (0050D197) --------------------------------------------------------
short TRIBE_Player_Tech::get_string_id(short a2)
{
    return this->base_tech->tech_tree[a2].string_id;
}

//----- (0050D1B8) --------------------------------------------------------
short TRIBE_Player_Tech::get_string_id2(short a2)
{
    return this->base_tech->tech_tree[a2].string_id2;
}

//----- (0050D1D9) --------------------------------------------------------
char TRIBE_Player_Tech::get_button_location(short a2)
{
    return this->base_tech->tech_tree[a2].button_location;
}

//----- (0050D1F9) --------------------------------------------------------
void TRIBE_Player_Tech::do_rev_tech(short a2)
{
    TRIBE_Player_Tech *v2; // [sp+0h] [bp-Ch]@1
    signed int i; // [sp+4h] [bp-8h]@1
    int v4; // [sp+8h] [bp-4h]@3

    v2 = this;
    for( i = 0; i < 4; ++i )
    {
        v4 = v2->base_tech->tech_tree[a2].pre_reqs[i];
        if( v4 >= 0 && v2->tech_player_tree[v4].state < 3 && v2->tech_player_tree[v4].state >= 0 )
            TRIBE_Player_Tech::do_rev_tech(v2, v4);
    }
    TRIBE_Player_Tech::do_tech(v2, a2);
}

//----- (0050D281) --------------------------------------------------------
char TRIBE_Player_Tech::rev_tech(short a2)
{
    TRIBE_Player_Tech *v3; // [sp+0h] [bp-Ch]@1
    signed int j; // [sp+4h] [bp-8h]@3
    signed int i; // [sp+8h] [bp-4h]@1

    v3 = this;
    TRIBE_Player_Tech::do_tech(this, a2);
    for( i = 0; i < v3->tech_player_tree_num; ++i )
    {
        for( j = 0; j < 4; ++j )
        {
            if( v3->base_tech->tech_tree[i].pre_reqs[j] == a2 )
                TRIBE_Player_Tech::do_rev_tech(v3, i);
        }
    }
    return 1;
}

//----- (0050D306) --------------------------------------------------------
void TRIBE_Player_Tech::disable(short a2)
{
    signed int i; // [sp+4h] [bp-4h]@2

    if( a2 >= 0 )
    {
        if( this->tech_player_tree[a2].state != 3 )
            this->tech_player_tree[a2].state = -1;
    }
    else
    {
        for( i = 0; i < this->tech_player_tree_num; ++i )
        {
            if( this->tech_player_tree[i].state != 3 )
                this->tech_player_tree[i].state = -1;
        }
    }
}

//----- (0050D383) --------------------------------------------------------
void TRIBE_Player_Tech::enable(short a2)
{
    signed int i; // [sp+4h] [bp-4h]@2

    if( a2 >= 0 )
    {
        if( this->tech_player_tree[a2].state == -1 )
            this->tech_player_tree[a2].state = 0;
    }
    else
    {
        for( i = 0; i < this->tech_player_tree_num; ++i )
        {
            if( this->tech_player_tree[i].state == -1 )
                this->tech_player_tree[i].state = 0;
        }
    }
}

//----- (0050D400) --------------------------------------------------------
int TRIBE_Player_Tech::get_help_message(short a2)
{
    return TRIBE_Tech::get_help_message(this->base_tech, a2);
}

//----- (0050D41D) --------------------------------------------------------
int TRIBE_Player_Tech::get_help_page(short a2)
{
    return TRIBE_Tech::get_help_page(this->base_tech, a2);
}

//----- (0050D43A) --------------------------------------------------------
int TRIBE_Player_Tech::get_hotkey(short a2)
{
    return TRIBE_Tech::get_hotkey(this->base_tech, a2);
}
