
TRIBE_World::TRIBE_World()
{
    TRIBE_World *v1; // esi@1
    TribeAIPlayBook *v2; // eax@1
    AIPlayBook *v3; // eax@2

    v1 = this;
    RGE_Game_World::RGE_Game_World();
    v1->controllingComputerPlayer = -1;
    v1->tech = 0;
    v1->victory_type = 0;
    v1->artifact_count = 0;
    v1->ruin_count = 0;
    v1->sent_zone_score = 0;
    v1->countdown_victory = 0;
    LODWORD(v1->countdown_clock) = 0;
    v1->score_displayed = 0;
    v2 = (TribeAIPlayBook *)operator new(0x50u);
    if( v2 )
        TribeAIPlayBook::TribeAIPlayBook(v2);
    else
        v3 = 0;
    v1->playbook = v3;
    if( v3 )
        AIPlayBook::loadPlays(v3, aDataAoe_ply);
}

void TRIBE_World::data_load_players_type(short id, short type, _iobuf *infile)
{
    TRIBE_World *v4; // esi@1
    TRIBE_Master_Player *v5; // eax@3
    RGE_Master_Player *v6; // eax@4

    v4 = this;
    if( type == 1 )
    {
        v5 = (TRIBE_Master_Player *)operator new(0x2Cu);
        if( v5 )
            TRIBE_Master_Player::TRIBE_Master_Player(v5, infile);
        else
            v6 = 0;
        v4->master_players[id] = v6;
    }
    else
    {
        RGE_Game_World::data_load_players_type((RGE_Game_World *)&this->vfptr, id, type, infile);
    }
}

void TRIBE_World::data_load_map(char *border_file, char *overlay_file, char *terrain_file, char *map_file, short tile_width, short tile_height, short elev_height, RGE_Sound **sounds, char *terr_obj_file)
{
    TRIBE_World *v10; // esi@1
    TRIBE_Map *v11; // eax@1
    RGE_Map *v12; // eax@2

    v10 = this;
    v11 = (TRIBE_Map *)operator new(0xB5F8u);
    if( v11 )
        TRIBE_Map::TRIBE_Map(
            v11,
            border_file,
            overlay_file,
            terrain_file,
            map_file,
            tile_width,
            tile_height,
            elev_height,
            sounds);
    else
        v12 = 0;
    v10->map = v12;
    RGE_Map::load_terrain_obj_types(v12, terr_obj_file);
}

bool TRIBE_World::init_player_type(int infile, short index, char type)
{
    TRIBE_World *v5; // esi@1
    char result; // al@2
    TRIBE_Master_Player *v7; // eax@3
    RGE_Master_Player *v8; // eax@4
    int v9; // ecx@6

    v5 = this;
    if( type == 1 )
    {
        v7 = (TRIBE_Master_Player *)operator new(0x2Cu);
        if( v7 )
            TRIBE_Master_Player::TRIBE_Master_Player(v7, a2, infile);
        else
            v8 = 0;
        v9 = index;
        v5->master_players[v9] = v8;
        ((void (__stdcall *)(int, RGE_Sprite **, RGE_Sound **))v5->master_players[v9]->vfptr->finish_init)(
            infile,
            v5->sprites,
            v5->sounds);
        result = 1;
    }
    else
    {
        result = RGE_Game_World::init_player_type((RGE_Game_World *)&this->vfptr, a2, infile, index, type);
    }
    return result;
}

void TRIBE_World::map_init(int infile, TSound_Driver *sound_dvr)
{
    TRIBE_World *v3; // esi@1
    TRIBE_Map *v4; // eax@1
    RGE_Map *v5; // eax@2

    v3 = this;
    v4 = (TRIBE_Map *)operator new(0xB5F8u);
    if( v4 )
        TRIBE_Map::TRIBE_Map(v4, infile, v3->sounds, 1);
    else
        v5 = 0;
    v3->map = v5;
}

void TRIBE_World::command_init(int infile, TCommunications_Handler *com_hand)
{
    TRIBE_World *v3; // esi@1
    TRIBE_Command *v4; // eax@1
    RGE_Command *v5; // eax@2

    v3 = this;
    v4 = (TRIBE_Command *)operator new(0x18u);
    if( v4 )
        TRIBE_Command::TRIBE_Command(v4, v3, com_hand);
    else
        v5 = 0;
    v3->commands = v5;
}

void TRIBE_World::scenario_init(int infile, RGE_Game_World *world)
{
    TRIBE_World *v4; // esi@1
    T_Scenario *v5; // eax@1
    RGE_Scenario *v6; // eax@2

    v4 = this;
    v5 = (T_Scenario *)operator new(0x514Cu);
    if( v5 )
        T_Scenario::T_Scenario(v5, a2, infile, world);
    else
        v6 = 0;
    v4->scenario = v6;
}

void TRIBE_World::scenario_init()
{
    TRIBE_World *v2; // esi@1
    T_Scenario *v3; // eax@1
    RGE_Scenario *v4; // eax@2

    v2 = this;
    v3 = (T_Scenario *)operator new(0x514Cu);
    if( v3 )
        T_Scenario::T_Scenario(v3, world);
    else
        v4 = 0;
    v2->scenario = v4;
}

void TRIBE_World::effects_init(int infile)
{
    TRIBE_World *v2; // esi@1
    TRIBE_Effects *v3; // eax@1
    RGE_Effects *v4; // eax@2

    v2 = this;
    v3 = (TRIBE_Effects *)operator new(0xCu);
    if( v3 )
        TRIBE_Effects::TRIBE_Effects(v3, infile);
    else
        v4 = 0;
    v2->effects = v4;
}

void TRIBE_World::world_init(int infile, TSound_Driver *sound_dvr, TCommunications_Handler *com_hand)
{
    TRIBE_World *v4; // esi@1
    void *v5; // eax@1
    int v6; // eax@2

    v4 = this;
    RGE_Game_World::world_init((RGE_Game_World *)&this->vfptr, infile, sound_dvr, com_hand);
    v5 = operator new(0xCu);
    if( v5 )
        v6 = TRIBE_Tech::TRIBE_Tech((int)v5, infile, infile, (int)v4);
    else
        v6 = 0;
    v4->tech = (TRIBE_Tech *)v6;
    v4->victory_type = 0;
    v4->artifact_count = 0;
    v4->ruin_count = 0;
    v4->countdown_victory = 0;
    LODWORD(v4->countdown_clock) = 0;
    v4->score_displayed = 0;
}

char TRIBE_World::init(char *base_name, TSound_Driver *sound_dvr, TCommunications_Handler *com_hand)
{
    return RGE_Game_World::init((RGE_Game_World *)&this->vfptr, base_name, sound_dvr, com_hand);
}

void TRIBE_World::base_save(int outfile)
{
    TRIBE_World *v2; // esi@1

    v2 = this;
    RGE_Game_World::base_save((RGE_Game_World *)&this->vfptr, outfile);
    TRIBE_Tech::save(v2->tech, outfile);
}

void TRIBE_World::save(int outfile)
{
    TRIBE_World *v2; // esi@1

    v2 = this;
    RGE_Game_World::save((RGE_Game_World *)&this->vfptr, outfile);
    rge_write(outfile, &v2->victory_type, 4);
    rge_write(outfile, &v2->artifact_count, 4);
    rge_write(outfile, &v2->ruin_count, 4);
    rge_write(outfile, &v2->countdown_victory, 1);
    rge_write(outfile, &v2->countdown_clock, 4);
    rge_write(outfile, &v2->score_displayed, 1);
    rge_write(outfile, &v2->controllingComputerPlayer, 1);
}

void TRIBE_World::load_player(int infile, char type, short index)
{
    TRIBE_World *v5; // esi@1
    TRIBE_Gaia *v6; // eax@5
    int v7; // edi@5
    short v8; // bx@5
    RGE_Player *v9; // eax@6
    TRIBE_Player *v10; // eax@7
    int v11; // ecx@10

    v5 = this;
    if( type == 1 )
        goto LABEL_7;
    if( type != 2 )
    {
        if( type != 3 )
        {
            RGE_Game_World::load_player((RGE_Game_World *)&this->vfptr, infile, type, index);
            return;
        }
LABEL_7:
        v10 = (TRIBE_Player *)operator new(0x848u);
        v7 = infile;
        v8 = index;
        if( v10 )
        {
            TRIBE_Player::TRIBE_Player(v10, infile, v5, index);
            goto LABEL_10;
        }
LABEL_9:
        v9 = 0;
        goto LABEL_10;
    }
    v6 = (TRIBE_Gaia *)operator new(0x858u);
    v7 = infile;
    v8 = index;
    if( !v6 )
        goto LABEL_9;
    TRIBE_Gaia::TRIBE_Gaia(v6, a2, infile, v5, index);
LABEL_10:
    v11 = v8;
    v5->players[v11] = v9;
    ((void (__stdcall *)(int))v5->players[v11]->vfptr->load)(v7);
}

void TRIBE_World::setup_gaia()
{
    TRIBE_World *v1; // esi@1
    TRIBE_Gaia *v2; // eax@1
    RGE_Player *v3; // eax@2

    v1 = this;
    v2 = (TRIBE_Gaia *)operator new(0x858u);
    if( v2 )
        TRIBE_Gaia::TRIBE_Gaia(v2, v1, *v1->master_players, 0, new_name, 0);
    else
        v3 = 0;
    *v1->players = v3;
}

void TRIBE_World::setup_players(RGE_Player_Info *info)
{
    TRIBE_World *v2; // edi@1
    signed int v3; // esi@1
    char *v4; // ebp@2
    char v5; // al@3
    TRIBE_Player *v6; // eax@6
    TRIBE_Player *v7; // eax@8
    RGE_Player *v8; // eax@9

    v2 = this;
    v3 = 1;
    if( this->player_num > 1 )
    {
        v4 = info->name[1];
        while ( 1 )
        {
            v5 = info->name[8][v3 + 64];
            if( !v5 )
                break;
            if( v5 == 4 )
            {
                if( useComputerPlayers )
                {
                    v7 = (TRIBE_Player *)operator new(0x848u);
                    if( v7 )
                    {
                        TRIBE_Player::TRIBE_Player(
                            v7,
                            v2,
                            v2->master_players[info->type[v3 + 8]],
                            v3,
                            v4 - 65,
                            info->type[v3 + 8],
                            1,
                            1,
                            0,
                            0,
                            0);
LABEL_13:
                        v2->players[v3] = v8;
                        goto LABEL_14;
                    }
                }
                else
                {
                    v6 = (TRIBE_Player *)operator new(0x848u);
                    if( v6 )
                    {
LABEL_11:
                        TRIBE_Player::TRIBE_Player(
                            v6,
                            v2,
                            v2->master_players[info->type[v3 + 8]],
                            v3,
                            v4 - 65,
                            info->type[v3 + 8],
                            0,
                            1,
                            0,
                            0,
                            0);
                        goto LABEL_13;
                    }
                }
LABEL_12:
                v8 = 0;
                goto LABEL_13;
            }
LABEL_14:
            ++v3;
            v4 += 65;
            if( v3 >= v2->player_num )
                return;
        }
        v6 = (TRIBE_Player *)operator new(0x848u);
        if( v6 )
            goto LABEL_11;
        goto LABEL_12;
    }
}

void TRIBE_World::check_destructables(short player_id, short obj_id, float col, float row, char delete_flag)
{
    short v6; // bx@1
    RGE_Master_Static_Object *v7; // eax@1
    short v8; // bp@4
    signed short v9; // si@4
    short v10; // di@4
    signed __int64 v11; // rax@4
    int v12; // edx@6
    RGE_Map *v13; // ecx@6
    int v14; // edx@13
    RGE_Object_Node **v15; // ebp@15
    int v16; // edi@15
    RGE_Object_Node *v17; // eax@16
    RGE_Static_Object *v18; // ecx@17
    RGE_Object_Node *v19; // esi@17
    RGE_Master_Static_Object *v20; // eax@17
    double v21; // st7@19
    double v22; // st5@19
    bool v23; // zf@32
    int v24; // [sp+10h] [bp-20h]@13
    TRIBE_World *v25; // [sp+14h] [bp-1Ch]@1
    float rx; // [sp+18h] [bp-18h]@2
    float ry; // [sp+1Ch] [bp-14h]@2
    int v28; // [sp+20h] [bp-10h]@13
    int v29; // [sp+24h] [bp-Ch]@13
    int v30; // [sp+2Ch] [bp-4h]@13
    int player_ida; // [sp+34h] [bp+4h]@4
    int x1; // [sp+38h] [bp+8h]@4

    v25 = this;
    v6 = obj_id;
    v7 = this->players[player_id]->master_objects[obj_id];
    if( v7 )
    {
        rx = v7->radius_x;
        ry = v7->radius_y;
        if( rx > 0.0 || ry > 0.0 )
        {
            v8 = (signed __int64)(col - 3.0);
            player_ida = (signed __int64)(col - 3.0);
            v9 = (signed __int64)(row - 3.0);
            v10 = (signed __int64)(col - -3.0);
            x1 = (signed __int64)(col - -3.0);
            v11 = (signed __int64)(row - -3.0);
            if( v8 < 0 )
            {
                player_ida = 0;
                v8 = 0;
            }
            v12 = v10;
            v13 = this->map;
            if( v10 >= v13->map_width )
            {
                LOWORD(v12) = LOWORD(v13->map_width) - 1;
                x1 = v12;
                v10 = LOWORD(v13->map_width) - 1;
            }
            if( v9 < 0 )
                v9 = 0;
            if( (signed short)v11 >= v13->map_height )
                LOWORD(v11) = LOWORD(v13->map_height) - 1;
            if( v9 <= (signed short)v11 )
            {
                v29 = v8;
                HIDWORD(v11) = 24 * v8;
                v30 = 24 * v8;
                v24 = v9;
                v28 = (signed short)v11 - v9 + 1;
                do
                {
                    if( v8 <= v10 )
                    {
                        v15 = (RGE_Object_Node **)((char *)&v25->map->map_row_offset[v24]->objects.list + v14);
                        v16 = v10 - v29 + 1;
                        do
                        {
                            v17 = *v15;
                            if( *v15 )
                            {
                                do
                                {
                                    v18 = v17->node;
                                    v19 = v17->next;
                                    v20 = v17->node->master_obj;
                                    if( v20->id != v6 && v20->can_be_built_on )
                                    {
                                        v21 = v18->world_y - row;
                                        v22 = v18->world_x - col;
                                        if( v21 < 0.0 )
                                            v21 = -v21;
                                        if( v22 < 0.0 )
                                            v22 = -v22;
                                        if( v22 < v20->radius_x + rx && v21 < v20->radius_y + ry )
                                        {
                                            if( delete_flag )
                                            {
                                                if( v18 )
                                                    ((void (__stdcall *)(signed int))v18->vfptr->__vecDelDtor)(1);
                                            }
                                            else
                                            {
                                                ((void (*)(void))v18->vfptr->destroy_obj)();
                                            }
                                        }
                                    }
                                    v17 = v19;
                                }
                                while ( v19 );
                            }
                            v15 += 6;
                            --v16;
                        }
                        while ( v16 );
                        v8 = player_ida;
                        v10 = x1;
                        v14 = v30;
                    }
                    v23 = v28 == 1;
                    ++v24;
                    --v28;
                }
                while ( !v23 );
            }
        }
    }
}

void TRIBE_World::scenario_make_player(short index, char player_type, char info_type, char master_player_id, char *name)
{
    TRIBE_World *v6; // esi@1
    TRIBE_Player *v7; // eax@2
    short v8; // di@2
    TRIBE_Player *v9; // eax@5
    RGE_Player *v10; // eax@6

    v6 = this;
    if( !info_type )
    {
        v7 = (TRIBE_Player *)operator new(0x848u);
        v8 = index;
        if( v7 )
            goto LABEL_8;
        goto LABEL_9;
    }
    if( info_type != 4 )
    {
        v7 = (TRIBE_Player *)operator new(0x848u);
        v8 = index;
        if( v7 )
        {
LABEL_8:
            TRIBE_Player::TRIBE_Player(
                v7,
                v6,
                v6->master_players[(unsigned __int8)player_type],
                v8,
                name,
                player_type,
                0,
                1,
                0,
                0,
                0);
            goto LABEL_10;
        }
LABEL_9:
        v10 = 0;
        goto LABEL_10;
    }
    v9 = (TRIBE_Player *)operator new(0x848u);
    v8 = index;
    if( !v9 )
        goto LABEL_9;
    TRIBE_Player::TRIBE_Player(
        v9,
        v6,
        v6->master_players[(unsigned __int8)player_type],
        index,
        name,
        player_type,
        1,
        1,
        0,
        0,
        0);
LABEL_10:
    v6->players[v8] = v10;
}

char TRIBE_World::load_world(int infile)
{
    TRIBE_World *v3; // esi@1
    char result; // al@1

    v3 = this;
    result = RGE_Game_World::load_world(infile);
    if( result != true ){
        return false;
    }
        if( save_game_version < 5.5999999 )
            v3->victory_type = 0;
        else
            rge_read(a2, infile1, infile1, &v3->victory_type, 4);
        if( save_game_version < 5.3000002 )
        {
            v3->artifact_count = 0;
            v3->ruin_count = 0;
        }
        else
        {
            rge_read(a2, infile1, infile1, &v3->artifact_count, 4);
            rge_read(a2, infile1, infile1, &v3->ruin_count, 4);
        }
        if( save_game_version < 5.4000001 )
        {
            v3->countdown_victory = 0;
            LODWORD(v3->countdown_clock) = 0;
        }
        else
        {
            rge_read(a2, infile1, infile1, &v3->countdown_victory, 1);
            rge_read(a2, infile1, infile1, &v3->countdown_clock, 4);
        }
        if( save_game_version < 6.5999999 )
            v3->score_displayed = 0;
        else
            rge_read(a2, infile1, infile1, &v3->score_displayed, 1);
        if( save_game_version < 6.9699998 )
        {
            v3->controllingComputerPlayer = 2;
        }
        else
        {
            rge_read(a2, infile1, infile1, &v3->controllingComputerPlayer, 1);
        }
    }
    return true;
}

char TRIBE_World::new_game(int a2@<eax>, int a3@<ebx>, int a4@<ebp>, int a5@<edi>, int a6@<esi>, RGE_Player_Info *info, int myPlayerNum)
{
    void *v8; // esp@1
    TRIBE_World *v9; // ebp@1
    int v10; // esi@1
    char v11; // bl@1
    RGE_Base_GameVtbl *v12; // eax@10
    const char *v13; // eax@16
    const char *v14; // eax@23
    RGE_Base_GameVtbl *v15; // edx@25
    const char *v16; // eax@35
    TRIBE_Game::Age v17; // eax@36
    RGE_Base_GameVtbl *v18; // edx@37
    const char *v19; // eax@41
    TRIBE_Game::ResourceLevel v20; // eax@41
    RGE_Base_GameVtbl *v21; // edx@41
    const char *v22; // eax@44
    RGE_Base_GameVtbl *v23; // esi@44
    RGE_Base_GameVtbl *v24; // eax@44
    bool v25; // zf@44
    RGE_Base_GameVtbl *v26; // eax@44
    const char *v27; // eax@47
    int v28; // eax@47
    RGE_Base_GameVtbl *v29; // edx@47
    const char *v30; // eax@50
    int v31; // eax@50
    RGE_Base_GameVtbl *v32; // edx@50
    const char *v33; // eax@53
    int v34; // eax@54
    RGE_Base_GameVtbl *v35; // edx@54
    const char *v36; // eax@55
    const char *v37; // eax@57
    int v38; // eax@58
    RGE_Base_GameVtbl *v39; // esi@58
    const char *v40; // eax@61
    char v41; // al@61
    const char *v42; // eax@61
    int v43; // edi@66
    T_Scenario *v44; // ecx@67
    T_Scenario *v45; // ecx@68
    T_Scenario *v46; // ecx@69
    T_Scenario *v47; // ecx@70
    __int32 v48; // eax@76
    signed int i; // esi@78
    T_Scenario *v50; // ecx@87
    T_Scenario *v51; // ecx@88
    signed int v52; // esi@88
    int v53; // edi@88
    RGE_RMM_Object_Generator *v54; // eax@90
    RGE_RMM_Object_Generator *v55; // eax@91
    T_Scenario *v56; // ecx@93
    int v57; // eax@93
    int v58; // edi@94
    RGE_Player **v59; // edx@95
    int v60; // esi@95
    RGE_Object_Node *j; // ecx@96
    int v62; // eax@101
    int v63; // eax@103
    int v64; // edi@104
    RGE_Player **v65; // edx@105
    int v66; // esi@105
    RGE_Object_Node *k; // ecx@106
    int v68; // eax@111
    int v69; // ebx@113
    int v70; // eax@114
    RGE_Player **v71; // esi@115
    int v72; // edi@115
    RGE_Object_Node *l; // ecx@116
    short v74; // dx@117
    int v75; // ebx@122
    int v76; // STAC_4@123
    RGE_RMM_Object_Generator *v77; // ebx@123
    int v78; // esi@132
    RGE_Player **v79; // ecx@133
    int v80; // edx@133
    RGE_Object_Node *v81; // eax@134
    RGE_Player **v82; // edx@141
    RGE_Object_Node *m; // eax@142
    short v84; // cx@143
    signed int n; // esi@151
    signed int ii; // esi@154
    signed int kk; // esi@158
    RGE_Player *v88; // eax@159
    float amount; // STB0_4@159
    signed int jj; // esi@161
    __int32 v91; // eax@163
    int v92; // eax@164
    signed int ll; // eax@166
    signed int mm; // eax@169
    signed int nn; // eax@172
    signed int i1; // eax@175
    __int32 v97; // eax@177
    int v98; // eax@178
    signed int i2; // esi@180
    signed int i3; // esi@183
    signed int i4; // esi@186
    signed int i5; // esi@189
    signed int v103; // esi@192
    float v104; // STB0_4@197
    signed int v106; // [sp+A8h] [bp-1330h]@10
    char *v107; // [sp+ACh] [bp-132Ch]@10
    int v108; // [sp+B8h] [bp-1320h]@1
    int v109; // [sp+BCh] [bp-131Ch]@1
    int v110; // [sp+C0h] [bp-1318h]@1
    RGE_RMM_Object_Generator *v111; // [sp+C4h] [bp-1314h]@0
    RGE_RMM_Object_Generator *v112; // [sp+C4h] [bp-1314h]@91
    int v113; // [sp+C8h] [bp-1310h]@0
    char v114; // [sp+CCh] [bp-130Ch]@22
    char *v115; // [sp+D0h] [bp-1308h]@23
    char *v116; // [sp+D4h] [bp-1304h]@23
    char *v117; // [sp+D8h] [bp-1300h]@23
    char *v118; // [sp+DCh] [bp-12FCh]@23
    int *v119; // [sp+E0h] [bp-12F8h]@23
    int v120; // [sp+E4h] [bp-12F4h]@23
    char *v121; // [sp+E8h] [bp-12F0h]@23
    char *v122; // [sp+ECh] [bp-12ECh]@23
    int v123; // [sp+F0h] [bp-12E8h]@23
    char *v124; // [sp+F4h] [bp-12E4h]@23
    signed int v125; // [sp+F8h] [bp-12E0h]@23
    int v126; // [sp+FCh] [bp-12DCh]@23
    char *v127; // [sp+100h] [bp-12D8h]@23
    char *v128; // [sp+104h] [bp-12D4h]@23
    int *v129; // [sp+108h] [bp-12D0h]@23
    int v130; // [sp+10Ch] [bp-12CCh]@23
    char *v131; // [sp+110h] [bp-12C8h]@23
    char *v132; // [sp+114h] [bp-12C4h]@23
    char *v133; // [sp+118h] [bp-12C0h]@23
    int v134; // [sp+11Ch] [bp-12BCh]@23
    char *v135; // [sp+120h] [bp-12B8h]@23
    char *v136; // [sp+124h] [bp-12B4h]@23
    char v137; // [sp+130h] [bp-12A8h]@42
    char v138; // [sp+134h] [bp-12A4h]@41
    char v139; // [sp+140h] [bp-1298h]@34
    char v140; // [sp+1CCh] [bp-120Ch]@61
    char v141; // [sp+1D0h] [bp-1208h]@61
    char v142; // [sp+1E0h] [bp-11F8h]@53
    char v143; // [sp+1F0h] [bp-11E8h]@50
    char v144; // [sp+1F8h] [bp-11E0h]@47
    char Format; // [sp+208h] [bp-11D0h]@44
    char v146; // [sp+214h] [bp-11C4h]@44
    char v147; // [sp+220h] [bp-11B8h]@44
    char v148; // [sp+230h] [bp-11A8h]@41
    char Dest; // [sp+240h] [bp-1198h]@23
    char v150; // [sp+308h] [bp-10D0h]@44
    char new_text; // [sp+3CCh] [bp-100Ch]@10
    char v152; // [sp+3D0h] [bp-1008h]@61
    char v153; // [sp+3E0h] [bp-FF8h]@53
    char v154; // [sp+3F0h] [bp-FE8h]@50
    char v155; // [sp+3F8h] [bp-FE0h]@47
    char v156; // [sp+408h] [bp-FD0h]@44
    char v157; // [sp+420h] [bp-FB8h]@44
    char v158; // [sp+430h] [bp-FA8h]@41
    char v159; // [sp+440h] [bp-F98h]@23
    int v160; // [sp+13CCh] [bp-Ch]@1
    int (*v161)(); // [sp+13D0h] [bp-8h]@1
    int v162; // [sp+13D4h] [bp-4h]@1

    v162 = -1;
    v161 = _L43664;
    v160 = a2;
    v8 = alloca(4872);
    v110 = a3;
    v109 = a4;
    v9 = this;
    v108 = a6;
    this->score_displayed = 0;
    this->controllingComputerPlayer = -1;
    v10 = 0;
    v11 = RGE_Game_World::new_game((RGE_Game_World *)&this->vfptr, info, myPlayerNum);
    BYTE3(v113) = v11;
    while ( v10 < v9->player_num )
        RGE_Base_Game::reset_countdown_timer(rge_base_game, v10++);
    if( !RGE_Base_Game::campaignGame(rge_base_game) && RGE_Base_Game::randomGame(rge_base_game)
        || TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game) )
    {
        if( !RGE_Base_Game::campaignGame(rge_base_game) && RGE_Base_Game::randomGame(rge_base_game) )
            RGE_Scenario::Set_scenario_name(v9->scenario, message_in);
        switch ( TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game) )
        {
            case 0:
            case 9:
                v107 = &new_text;
                v12 = rge_base_game->vfptr;
                v106 = 9820;
                goto LABEL_14;
            case 1:
                v107 = &new_text;
                v12 = rge_base_game->vfptr;
                v106 = 9823;
                goto LABEL_14;
            case 7:
                v107 = &new_text;
                v12 = rge_base_game->vfptr;
                v106 = 9821;
                goto LABEL_14;
            case 8:
                v107 = &new_text;
                v12 = rge_base_game->vfptr;
                v106 = 9822;
LABEL_14:
                (*(void (__stdcall **)(signed int, char *, signed int))&v12->gap8[24])(v106, v107, 4096);
                break;
            default:
                break;
        }
        switch ( TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game) )
        {
            case 0:
                v13 = (const char *)((int (__stdcall *)(signed int))rge_base_game->vfptr->get_string)(10611);
                goto LABEL_22;
            case 1:
                v13 = (const char *)((int (__stdcall *)(signed int))rge_base_game->vfptr->get_string)(10612);
                goto LABEL_22;
            case 2:
                v13 = (const char *)((int (__stdcall *)(signed int))rge_base_game->vfptr->get_string)(10613);
                goto LABEL_22;
            case 3:
                v13 = (const char *)((int (__stdcall *)(signed int))rge_base_game->vfptr->get_string)(10614);
                goto LABEL_22;
            case 4:
                v13 = (const char *)((int (__stdcall *)(signed int))rge_base_game->vfptr->get_string)(10615);
                goto LABEL_22;
            case 5:
                v13 = (const char *)((int (__stdcall *)(signed int))rge_base_game->vfptr->get_string)(10616);
LABEL_22:
                strcpy(&v114, v13);
                break;
            default:
                break;
        }
        v14 = (const char *)((int (__stdcall *)(signed int, char *, int, int, int, int, RGE_RMM_Object_Generator *, int, _DWORD, char *, char *, char *, char *, int *, int, char *, char *, int, char *, signed int, int, char *, char *, int *, int, char *, char *, char *, int, char *))rge_base_game->vfptr->get_string)(
                                                    9690,
                                                    &v114,
                                                    a5,
                                                    v108,
                                                    v109,
                                                    v110,
                                                    v111,
                                                    v113,
                                                    *(_DWORD *)&v114,
                                                    v115,
                                                    v116,
                                                    v117,
                                                    v118,
                                                    v119,
                                                    v120,
                                                    v121,
                                                    v122,
                                                    v123,
                                                    v124,
                                                    v125,
                                                    v126,
                                                    v127,
                                                    v128,
                                                    v129,
                                                    v130,
                                                    v131,
                                                    v132,
                                                    v133,
                                                    v134,
                                                    v135);
        sprintf(&Dest, v14);
        v136 = &Dest;
        v135 = &v159;
        sprintf(&v159, aSS_5, &v159, &Dest);
        if( RGE_Base_Game::randomGame(rge_base_game) )
        {
            switch ( TRIBE_Game::mapType((TRIBE_Game *)rge_base_game) )
            {
                case 0:
                    v136 = (char *)10602;
                    v15 = rge_base_game->vfptr;
                    goto LABEL_34;
                case 1:
                    v136 = (char *)10603;
                    v15 = rge_base_game->vfptr;
                    goto LABEL_34;
                case 2:
                    v136 = (char *)10604;
                    v15 = rge_base_game->vfptr;
                    goto LABEL_34;
                case 3:
                    v136 = (char *)10605;
                    v15 = rge_base_game->vfptr;
                    goto LABEL_34;
                case 4:
                    v136 = (char *)10606;
                    v15 = rge_base_game->vfptr;
                    goto LABEL_34;
                case 5:
                    v136 = (char *)10607;
                    v15 = rge_base_game->vfptr;
                    goto LABEL_34;
                case 6:
                    v136 = (char *)10608;
                    v15 = rge_base_game->vfptr;
                    goto LABEL_34;
                case 7:
                    v136 = (char *)10609;
                    v15 = rge_base_game->vfptr;
                    goto LABEL_34;
                case 8:
                    v136 = (char *)10610;
                    v15 = rge_base_game->vfptr;
LABEL_34:
                    strcpy(&v139, (const char *)((int (__stdcall *)(char *))v15->get_string)(v136));
                    break;
                default:
                    break;
            }
            v136 = &v139;
            v135 = (char *)9654;
            v16 = (const char *)((int (__stdcall *)(signed int))rge_base_game->vfptr->get_string)(9654);
            sprintf(&Dest, v16, v136);
            v136 = &Dest;
            v135 = &v159;
            sprintf(&v159, aSS_5, &v159, &Dest);
        }
        v17 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game);
        if( v17 )
        {
            v136 = (char *)256;
            v18 = rge_base_game->vfptr;
            if( v17 == 1 )
            {
                v135 = &v139;
                v134 = 4206;
            }
            else
            {
                v135 = &v139;
                v134 = v17 + 4199;
            }
        }
        else
        {
            v136 = (char *)256;
            v135 = &v139;
            v18 = rge_base_game->vfptr;
            v134 = 4327;
        }
        (*(void (__cdecl **)(int, char *, char *))&v18->gap8[24])(v134, v135, v136);
        v133 = &v138;
        v132 = (char *)9700;
        v19 = (const char *)((int (__cdecl *)(signed int, char *))rge_base_game->vfptr->get_string)(9700, &v138);
        sprintf(&v148, v19, v132);
        v132 = &v148;
        v131 = &v158;
        sprintf(&v158, aSS_5, &v158, &v148);
        v20 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game);
        v132 = (char *)256;
        v21 = rge_base_game->vfptr;
        if( v20 )
        {
            v131 = &v137;
            v130 = v20 + 9701;
        }
        else
        {
            v131 = &v137;
            v130 = 4327;
        }
        (*(void (__cdecl **)(int, char *, char *, char *))&v21->gap8[24])(v130, v131, v132, v133);
        v129 = (int *)&v136;
        v128 = (char *)9701;
        v22 = (const char *)((int (__cdecl *)(signed int, char **))rge_base_game->vfptr->get_string)(9701, &v136);
        sprintf(&v147, v22, v128);
        v128 = &v147;
        v127 = &v157;
        sprintf(&v157, aSS_5, &v157, &v147);
        RGE_Base_Game::difficulty(rge_base_game);
        v128 = (char *)256;
        v127 = (char *)&v135;
        v23 = rge_base_game->vfptr;
        v126 = RGE_Base_Game::difficulty(rge_base_game) + 11216;
        (*(void (**)(RGE_Base_Game *))&v23->gap8[24])(rge_base_game);
        v125 = 256;
        v124 = &v146;
        v24 = rge_base_game->vfptr;
        v123 = 9696;
        (*(void (__cdecl **)(signed int, char *, signed int, int, char *, char *, int *))&v24->gap8[24])(
            9696,
            &v146,
            256,
            v126,
            v127,
            v128,
            v129);
        v122 = (char *)&v129;
        sprintf(&v150, &Format, &v129);
        v122 = &v150;
        v121 = &v156;
        sprintf(&v156, aSS_5, &v156, &v150);
        v25 = TRIBE_Game::randomizePositions((TRIBE_Game *)rge_base_game) == 0;
        v26 = rge_base_game->vfptr;
        v122 = (char *)256;
        v121 = (char *)&v129;
        if( v25 )
            v120 = 4003;
        else
            v120 = 4004;
        (*(void (__cdecl **)(int, char *, char *, int, char *, signed int))&v26->gap8[24])(
            v120,
            v121,
            v122,
            v123,
            v124,
            v125);
        v119 = &v126;
        v118 = (char *)9705;
        v27 = (const char *)((int (__cdecl *)(signed int, int *))rge_base_game->vfptr->get_string)(9705, &v126);
        sprintf(&v144, v27, v118);
        v118 = &v144;
        v117 = &v155;
        sprintf(&v155, aSS_5, &v155, &v144);
        v28 = RGE_Base_Game::fullVisibility(rge_base_game);
        v29 = rge_base_game->vfptr;
        if( v28 )
            v118 = (char *)4003;
        else
            v118 = (char *)4004;
        strcpy((char *)&v124, (const char *)((int (__cdecl *)(char *, int *))v29->get_string)(v118, v119));
        v117 = (char *)&v124;
        v116 = (char *)9656;
        v30 = (const char *)((int (__cdecl *)(signed int, char **))rge_base_game->vfptr->get_string)(9656, &v124);
        sprintf(&v143, v30, v116);
        v116 = &v143;
        v115 = &v154;
        sprintf(&v154, aSS_5, &v154, &v143);
        v31 = TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game);
        v116 = (char *)256;
        v32 = rge_base_game->vfptr;
        v115 = (char *)&v123;
        if( v31 )
            *(_DWORD *)&v114 = 4003;
        else
            *(_DWORD *)&v114 = 4004;
        (*(void (__cdecl **)(_DWORD, char *, char *, char *))&v32->gap8[24])(*(_DWORD *)&v114, v115, v116, v117);
        v33 = (const char *)((int (__cdecl *)(signed int, int *))rge_base_game->vfptr->get_string)(9708, &v120);
        sprintf(&v142, v33);
        sprintf(&v153, aSS_5, &v153, &v142);
        if( RGE_Base_Game::multiplayerGame(rge_base_game) )
        {
            v34 = RGE_Base_Game::allowCheatCodes(rge_base_game);
            v35 = rge_base_game->vfptr;
            if( v34 )
                v36 = (const char *)((int (__stdcall *)(signed int, int))v35->get_string)(4003, v113);
            else
                v36 = (const char *)((int (__stdcall *)(signed int, int))v35->get_string)(4004, v113);
            strcpy((char *)&v120, v36);
            v37 = (const char *)((int (__cdecl *)(signed int, int *))rge_base_game->vfptr->get_string)(9659, &v120);
            sprintf(&v142, v37);
            sprintf(&v153, aSS_5, &v153, &v142);
        }
        v38 = RGE_Base_Game::multiplayerGame(rge_base_game);
        v39 = rge_base_game->vfptr;
        if( v38 )
            RGE_Base_Game::mpPathFinding(rge_base_game);
        else
            RGE_Base_Game::pathFinding(rge_base_game);
        (*(void (**)(RGE_Base_Game *))&v39->gap8[24])(rge_base_game);
        v40 = (const char *)((int (__cdecl *)(signed int, _DWORD))rge_base_game->vfptr->get_string)(9713, &v116);
        sprintf(&v141, v40);
        sprintf(&v152, aSS_5, &v152, &v141);
        v41 = TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
        v42 = (const char *)((int (__cdecl *)(signed int, _DWORD))rge_base_game->vfptr->get_string)(
                                                    9712,
                                                    (unsigned __int8)v41);
        sprintf(&v140, v42);
        sprintf(&new_text, aSS_5, &new_text, &v140);
        RGE_Scenario::add_description(v9->scenario, &new_text);
    }
    if( v11 )
    {
        v9->victory_type = 4;
        v9->countdown_victory = 0;
        LODWORD(v9->countdown_clock) = 0;
        if( !RGE_Base_Game::campaignGame(rge_base_game) && RGE_Base_Game::randomGame(rge_base_game)
            || TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game) )
        {
            T_Scenario::Set_victory_all_flag((T_Scenario *)v9->scenario, 0);
            T_Scenario::Set_Multi_Conquest((T_Scenario *)v9->scenario, 0);
            T_Scenario::Set_Multi_Ruins((T_Scenario *)v9->scenario, 0);
            T_Scenario::Set_Multi_Artifacts((T_Scenario *)v9->scenario, 0);
            T_Scenario::Set_Multi_Discoveries((T_Scenario *)v9->scenario, 0);
            T_Scenario::Set_Multi_Exploration((T_Scenario *)v9->scenario, 0);
            T_Scenario::Set_Multi_Gold((T_Scenario *)v9->scenario, 0);
            v43 = TRIBE_Game::victoryAmount((TRIBE_Game *)rge_base_game);
            switch ( TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game) )
            {
                case 0:
                case 9:
                    v44 = (T_Scenario *)v9->scenario;
                    v9->victory_type = 0;
                    T_Scenario::Set_Multi_Conquest(v44, 1);
                    break;
                case 1:
                    v45 = (T_Scenario *)v9->scenario;
                    v9->victory_type = 1;
                    T_Scenario::Set_Multi_Conquest(v45, 1);
                    break;
                case 7:
                    v46 = (T_Scenario *)v9->scenario;
                    v9->victory_type = 2;
                    T_Scenario::Set_Multi_Conquest(v46, 1);
                    break;
                case 8:
                    v47 = (T_Scenario *)v9->scenario;
                    v9->victory_type = 3;
                    T_Scenario::Set_Multi_Conquest(v47, 1);
                    break;
                case 3:
                    T_Scenario::Set_Multi_Ruins((T_Scenario *)v9->scenario, v43);
                    break;
                case 4:
                    T_Scenario::Set_Multi_Artifacts((T_Scenario *)v9->scenario, v43);
                    break;
                case 5:
                    T_Scenario::Set_Multi_Discoveries((T_Scenario *)v9->scenario, v43);
                    break;
                case 2:
                    T_Scenario::Set_Multi_Exploration((T_Scenario *)v9->scenario, v43);
                    break;
                case 6:
                    T_Scenario::Set_Multi_Gold((T_Scenario *)v9->scenario, v43);
                    break;
                default:
                    break;
            }
            T_Scenario::Save_victory_conditions_into_players((T_Scenario *)v9->scenario, 0);
            v48 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game) - 7;
            if( v48 )
            {
                if( v48 == 1 )
                {
                    for ( i = 1;
                                i < v9->player_num;
                                RGE_Victory_Conditions::add_victory_points(v9->players[i++]->victory_conditions, 0, v43, 1) )
                    {
                        ;
                    }
                }
            }
            else
            {
                v9->countdown_victory = 1;
                v9->countdown_clock = (double)v43;
            }
        }
        else if( RGE_Base_Game::campaignGame(rge_base_game) || RGE_Base_Game::scenarioGame(rge_base_game) )
        {
            switch ( T_Scenario::GetMPVictory((T_Scenario *)v9->scenario) )
            {
                case 0:
                    v9->victory_type = 0;
                    break;
                case 1:
                    v9->victory_type = 1;
                    break;
                case 3:
                    v50 = (T_Scenario *)v9->scenario;
                    v9->victory_type = 2;
                    v9->countdown_victory = 1;
                    v9->countdown_clock = (double)T_Scenario::GetVictoryTime(v50);
                    break;
                case 2:
                    v51 = (T_Scenario *)v9->scenario;
                    v9->victory_type = 3;
                    v52 = 1;
                    v53 = T_Scenario::GetVictoryScore(v51);
                    while ( v52 < v9->player_num )
                        RGE_Victory_Conditions::add_victory_points(v9->players[v52++]->victory_conditions, 0, v53, 1);
                    break;
                default:
                    break;
            }
        }
        v54 = (RGE_RMM_Object_Generator *)operator new(0x1920u);
        v162 = 0;
        if( v54 )
        {
            RGE_RMM_Object_Generator::RGE_RMM_Object_Generator(v54, v9->map, 0, (RGE_Game_World *)&v9->vfptr, 0, 0);
            v112 = v55;
        }
        else
        {
            v112 = 0;
        }
        v56 = (T_Scenario *)v9->scenario;
        v162 = -1;
        v57 = T_Scenario::Get_Multi_Artifacts(v56);
        if( v57 > 0 )
        {
            v58 = 0;
            if( v9->player_num > 0 )
            {
                v59 = v9->players;
                v60 = v9->player_num;
                do
                {
                    for ( j = (*v59)->objects->list; j; j = j->next )
                    {
                        if( j->node->master_obj->id == 159 )
                            ++v58;
                    }
                    ++v59;
                    --v60;
                }
                while ( v60 );
            }
            v62 = v57 - v58;
            if( v62 > 0 )
                RGE_RMM_Object_Generator::add_quick_obj(v112, 159, v62, 0);
        }
        v63 = T_Scenario::Get_Multi_Discoveries((T_Scenario *)v9->scenario);
        if( v63 > 0 )
        {
            v64 = 0;
            if( v9->player_num > 0 )
            {
                v65 = v9->players;
                v66 = v9->player_num;
                do
                {
                    for ( k = (*v65)->objects->list; k; k = k->next )
                    {
                        if( k->node->master_obj->id == 10 )
                            ++v64;
                    }
                    ++v65;
                    --v66;
                }
                while ( v66 );
            }
            v68 = v63 - v64;
            if( v68 > 0 )
                RGE_RMM_Object_Generator::add_quick_obj(v112, 10, v68, 0);
        }
        v69 = T_Scenario::Get_Multi_Ruins((T_Scenario *)v9->scenario);
        if( v69 <= 0 )
            goto LABEL_203;
        v70 = 0;
        if( v9->player_num > 0 )
        {
            v71 = v9->players;
            v72 = v9->player_num;
            do
            {
                for ( l = (*v71)->objects->list; l; l = l->next )
                {
                    v74 = l->node->master_obj->id;
                    if( v74 == 158 || v74 == 163 )
                        ++v70;
                }
                ++v71;
                --v72;
            }
            while ( v72 );
        }
        v75 = v69 - v70;
        if( v75 <= 0 )
        {
LABEL_203:
            v77 = v112;
        }
        else
        {
            v76 = v75;
            v77 = v112;
            RGE_RMM_Object_Generator::add_quick_obj(v112, 158, v76, 0);
        }
        if( RGE_Base_Game::campaignGame(rge_base_game) || !RGE_Base_Game::randomGame(rge_base_game) )
        {
            v78 = v9->player_num;
            v9->artifact_count = 0;
            if( v78 > 0 )
            {
                v79 = v9->players;
                v80 = v78;
                do
                {
                    v81 = (*v79)->objects->list;
                    if( v81 )
                    {
                        do
                        {
                            if( v81->node->master_obj->id == 159 )
                                ++v9->artifact_count;
                            v81 = v81->next;
                        }
                        while ( v81 );
                        v77 = v112;
                    }
                    ++v79;
                    --v80;
                }
                while ( v80 );
            }
            v9->ruin_count = 0;
            if( v78 > 0 )
            {
                v82 = v9->players;
                do
                {
                    for ( m = (*v82)->objects->list; m; m = m->next )
                    {
                        v84 = m->node->master_obj->id;
                        if( v84 == 158 || v84 == 163 )
                            ++v9->ruin_count;
                    }
                    ++v82;
                    --v78;
                }
                while ( v78 );
            }
        }
        else
        {
            if( v9->victory_type == 3 || debug_rand(aCMsdevWorkA_30, 909) % 100 < 50 )
            {
                RGE_RMM_Object_Generator::add_quick_obj(v77, 159, 5, v9->map->map_width / 5);
                v9->artifact_count = 5;
            }
            if( debug_rand(aCMsdevWorkA_30, 916) % 100 < 50 )
            {
                RGE_RMM_Object_Generator::add_quick_obj(v77, 158, 5, v9->map->map_width / 5);
                v9->ruin_count = 5;
            }
        }
        v77->vfptr->generate((RGE_Random_Map_Module *)v77);
        if( v77 )
        {
            RGE_Random_Map_Module::~RGE_Random_Map_Module((RGE_Random_Map_Module *)&v77->vfptr);
            operator delete(v77);
        }
    }
    if( !TRIBE_Game::allowTrading((TRIBE_Game *)rge_base_game) )
    {
        for ( n = 1;
                    n < v9->player_num;
                    ((void (__stdcall *)(signed int, RGE_Player *))v9->effects->vfptr->do_effect)(105, v9->players[n++]) )
        {
            ;
        }
    }
    if( TRIBE_Game::longCombat((TRIBE_Game *)rge_base_game) == 1 )
    {
        for ( ii = 1;
                    ii < v9->player_num;
                    ((void (__stdcall *)(signed int, RGE_Player *))v9->effects->vfptr->do_effect)(100, v9->players[ii++]) )
        {
            ;
        }
    }
    if( TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game)
        || T_Scenario::GetScenarioOption((T_Scenario *)v9->scenario, 2) )
    {
        for ( jj = 1;
                    jj < v9->player_num;
                    ((void (__stdcall *)(signed int, RGE_Player *))v9->effects->vfptr->do_effect)(210, v9->players[jj++]) )
        {
            ;
        }
    }
    else
    {
        for ( kk = 1; kk < v9->player_num; ++kk )
        {
            v88 = v9->players[kk];
            amount = *(float *)&v88;
            LOWORD(v88) = v88->tribe_effect;
            ((void (__stdcall *)(RGE_Player *, float))v9->effects->vfptr->do_effect)(v88, COERCE_FLOAT(LODWORD(amount)));
        }
    }
    v91 = TRIBE_Game::resourceLevel((TRIBE_Game *)rge_base_game) - 1;
    if( v91 )
    {
        v92 = v91 - 1;
        if( v92 )
        {
            if( v92 == 1 )
            {
                for ( ll = 1; ll < v9->player_num; *((_DWORD *)v9->players[ll - 1]->attributes + 2) = 1144750080 )
                {
                    *(_DWORD *)v9->players[++ll - 1]->attributes = 1148846080;
                    *((_DWORD *)v9->players[ll - 1]->attributes + 1) = 1148846080;
                    *((_DWORD *)v9->players[ll - 1]->attributes + 3) = 0;
                }
            }
        }
        else
        {
            for ( mm = 1; mm < v9->player_num; *((_DWORD *)v9->players[mm - 1]->attributes + 2) = 1132068864 )
            {
                *(_DWORD *)v9->players[++mm - 1]->attributes = 1140457472;
                *((_DWORD *)v9->players[mm - 1]->attributes + 1) = 1140457472;
                *((_DWORD *)v9->players[mm - 1]->attributes + 3) = 0;
            }
        }
    }
    else
    {
        for ( nn = 1; nn < v9->player_num; *((_DWORD *)v9->players[nn - 1]->attributes + 2) = 1120403456 )
        {
            *(_DWORD *)v9->players[++nn - 1]->attributes = 1128792064;
            *((_DWORD *)v9->players[nn - 1]->attributes + 1) = 1128792064;
            *((_DWORD *)v9->players[nn - 1]->attributes + 3) = 0;
        }
    }
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) )
    {
        for ( i1 = 1; i1 < v9->player_num; *((_DWORD *)v9->players[i1 - 1]->attributes + 2) = 1167867904 )
        {
            *(_DWORD *)v9->players[++i1 - 1]->attributes = 1184645120;
            *((_DWORD *)v9->players[i1 - 1]->attributes + 1) = 1184645120;
            *((_DWORD *)v9->players[i1 - 1]->attributes + 3) = 1176256512;
        }
    }
    v97 = TRIBE_Game::startingAge((TRIBE_Game *)rge_base_game) - 3;
    if( v97 )
    {
        v98 = v97 - 1;
        if( v98 )
        {
            if( v98 == 1 )
            {
                for ( i2 = 1; i2 < v9->player_num; TRIBE_Player::rev_tech((TRIBE_Player *)v9->players[i2++], 24) )
                    ;
            }
        }
        else
        {
            for ( i3 = 1; i3 < v9->player_num; TRIBE_Player::rev_tech((TRIBE_Player *)v9->players[i3++], 23) )
                ;
        }
    }
    else
    {
        for ( i4 = 1; i4 < v9->player_num; TRIBE_Player::rev_tech((TRIBE_Player *)v9->players[i4++], 25) )
            ;
    }
    if( RGE_Base_Game::check_prog_argument(rge_base_game, aNofoodcap) )
    {
        for ( i5 = 1; i5 < v9->player_num; RGE_Player::new_attribute_num(v9->players[i5++], 31, 5000.0) )
        {
            RGE_Player::new_attribute_num(v9->players[i5], 32, 50.0);
            RGE_Player::new_attribute_num(v9->players[i5], 33, 0.0);
            RGE_Player::new_attribute_num(v9->players[i5], 30, 500.0);
        }
    }
    else
    {
        v103 = 1;
        if( RGE_Base_Game::check_prog_argument(rge_base_game, aSystem2) )
        {
            if( v9->player_num > 1 )
            {
                do
                {
                    RGE_Player::new_attribute_num(v9->players[v103], 32, 50.0);
                    RGE_Player::new_attribute_num(v9->players[v103++], 33, 0.0);
                }
                while ( v103 < v9->player_num );
            }
        }
        else if( v9->player_num > 1 )
        {
            do
            {
                v104 = (double)(unsigned __int8)TRIBE_Game::popLimit((TRIBE_Game *)rge_base_game);
                RGE_Player::new_attribute_num(v9->players[v103], 32, v104);
                RGE_Player::new_attribute_num(v9->players[v103], 33, 0.0);
                RGE_Player::new_attribute_num(v9->players[v103], 30, 500.0);
                RGE_Player::new_attribute_num(v9->players[v103], 45, 1.0);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 0, 0, 20, 2, 1);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 0, 1, 43, 1, 1);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 0, 2, 44, 1, 1);
                RGE_Victory_Conditions::add_points_high_attribute_once(v9->players[v103]->victory_conditions, 0, 3, 40, 1, 25);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 1, 4, 49, 100, 1);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 1, 9, 53, 60, 1);
                RGE_Victory_Conditions::add_points_high_attribute_amount(v9->players[v103]->victory_conditions, 1, 5, 37, 1, 1);
                RGE_Victory_Conditions::add_points_high_attribute_once(v9->players[v103]->victory_conditions, 1, 6, 37, 1, 25);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 1, 7, 22, 3, 1);
                if( !RGE_Base_Game::fullVisibility(rge_base_game) )
                    RGE_Victory_Conditions::add_points_highest_attribute(v9->players[v103]->victory_conditions, 1, 8, 22, 1, 25);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 2, 10, 41, 1, 2);
                RGE_Victory_Conditions::add_points_highest_attribute(v9->players[v103]->victory_conditions, 2, 11, 41, 1, 25);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 2, 12, 14, 1, 10);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 2, 13, 7, 1, 10);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 2, 14, 52, 1, 3);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 2, 16, 55, 1, 50);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 2, 15, 54, 1, 50);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 3, 17, 21, 1, 2);
                RGE_Victory_Conditions::add_points_highest_attribute(v9->players[v103]->victory_conditions, 3, 18, 21, 1, 50);
                RGE_Victory_Conditions::add_points_attribute_first(v9->players[v103]->victory_conditions, 3, 19, 6, 3, 25);
                RGE_Victory_Conditions::add_points_attribute_first(v9->players[v103]->victory_conditions, 3, 20, 6, 4, 25);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 4, 22, 45, 1, 100);
                RGE_Victory_Conditions::add_points_attribute_amount(v9->players[v103]->victory_conditions, 4, 23, 42, 1, 100);
                TRIBE_Player::add_population_entry((TRIBE_Player *)v9->players[v103++]);
            }
            while ( v103 < v9->player_num );
        }
    }
    return BYTE3(v113);
}

char TRIBE_World::new_scenario(RGE_Player_Info *info, int random_seed_in)
{
    TRIBE_World *v3; // esi@1
    char result; // al@1
    signed int i; // ecx@1

    v3 = this;
    result = RGE_Game_World::new_scenario((RGE_Game_World *)&this->vfptr, info, random_seed_in);
    for ( i = 1; i < v3->player_num; *((_DWORD *)v3->players[i - 1]->attributes + 2) = 1120403456 )
    {
        *(_DWORD *)v3->players[++i - 1]->attributes = 1128792064;
        *((_DWORD *)v3->players[i - 1]->attributes + 1) = 1128792064;
        *((_DWORD *)v3->players[i - 1]->attributes + 3) = 0;
    }
    return result;
}

char TRIBE_World::check_game_state()
{
    TRIBE_World *v1; // ebx@1
    char v3; // c0@5
    int v4; // ebp@6
    bool v5; // zf@6
    bool v6; // sf@6
    unsigned __int8 v7; // of@6
    int *v8; // edi@7
    int v9; // eax@7
    RGE_Player **v10; // edx@7
    int j; // esi@8
    RGE_Player *v12; // eax@12
    int v13; // edx@15
    signed int v14; // edi@16
    signed int v15; // esi@16
    RGE_Player *v16; // ecx@16
    signed int k; // edx@16
    signed int v18; // edx@24
    signed int v19; // eax@26
    int v20; // ecx@26
    int *v21; // edi@27
    int v22; // eax@29
    TRIBE_Player *v23; // ecx@29
    int v24; // esi@29
    char *v25; // ebp@31
    RGE_Player **v26; // eax@33
    RGE_Player **v27; // edx@36
    RGE_Player *v28; // eax@36
    TRIBE_Player *(*v29)[9]; // edi@43
    int v30; // ebp@44
    int v31; // esi@44
    TRIBE_Player *(*v32)[9]; // edi@45
    int v33; // ebx@45
    RGE_Player *v34; // ecx@49
    TRIBE_Player *(*v35)[9]; // eax@51
    int v36; // edx@51
    TRIBE_Player *v37; // ebp@52
    TRIBE_Player *(*v38)[9]; // eax@55
    TRIBE_Player *v39; // ebp@56
    double v40; // st7@60
    TRIBE_Player *(*v41)[9]; // eax@61
    TRIBE_Player *v42; // edx@62
    TRIBE_Player *v43; // edx@65
    TRIBE_Player *(*v44)[9]; // eax@67
    int v45; // ecx@67
    TRIBE_Player *v46; // ebp@68
    TRIBE_Player *(*v47)[9]; // eax@71
    TRIBE_Player *v48; // ebp@72
    TRIBE_Player *(*v49)[9]; // edi@77
    int v50; // ebp@78
    int v51; // esi@78
    TRIBE_Player *(*v52)[9]; // edi@79
    int v53; // ebx@79
    TRIBE_World *v54; // ecx@81
    RGE_Player *v55; // ebx@84
    TRIBE_Player *(*v56)[9]; // eax@86
    int v57; // edx@86
    TRIBE_Player *v58; // ebp@87
    TRIBE_Player *(*v59)[9]; // eax@90
    TRIBE_Player *v60; // ecx@91
    double v61; // st7@95
    TRIBE_Player *(*v62)[9]; // eax@96
    TRIBE_Player *v63; // edx@97
    TRIBE_Player *v64; // edx@100
    TRIBE_Player *(*v65)[9]; // eax@102
    int v66; // ecx@102
    TRIBE_Player *v67; // ebp@103
    TRIBE_Player *(*v68)[9]; // eax@106
    TRIBE_Player *v69; // ecx@107
    int i; // [sp+28h] [bp-1A4h]@7
    signed int ia; // [sp+28h] [bp-1A4h]@26
    TRIBE_Player *(*ib)[9]; // [sp+28h] [bp-1A4h]@43
    TRIBE_Player *(*ic)[9]; // [sp+28h] [bp-1A4h]@77
    int held_time; // [sp+2Ch] [bp-1A0h]@30
    float held_timea; // [sp+2Ch] [bp-1A0h]@49
    float held_timeb; // [sp+2Ch] [bp-1A0h]@84
    int v78; // [sp+30h] [bp-19Ch]@27
    int *v79; // [sp+30h] [bp-19Ch]@43
    int *v80; // [sp+30h] [bp-19Ch]@77
    int team_count; // [sp+34h] [bp-198h]@26
    TRIBE_World *v82; // [sp+38h] [bp-194h]@1
    int v83; // [sp+3Ch] [bp-190h]@43
    int v84; // [sp+3Ch] [bp-190h]@77
    int team_size[9]; // [sp+40h] [bp-18Ch]@6
    int player_team[9]; // [sp+64h] [bp-168h]@25
    TRIBE_Player *team_player[9][9]; // [sp+88h] [bp-144h]@29

    v1 = this;
    v82 = this;
    if( !this->game_state )
    {
        if( this->victory_type == 2 )
        {
            if( this->countdown_victory )
            {
                if( this->countdown_clock >= 1.0 )
                {
                    this->countdown_clock = this->countdown_clock
                                                                - (this->world_time_delta_seconds
                                                                 + this->world_time_delta_seconds);
                    if( v3 )
                    {
                        v4 = 1;
                        v7 = __OFSUB__(this->player_num, 1);
                        v5 = this->player_num == 1;
                        v6 = (signed short)(this->player_num - 1) < 0;
                        memset(team_size, 0xFFu, sizeof(team_size));
                        if( !((unsigned __int8)(v6 ^ v7) | v5) )
                        {
                            do
                            {
                                v8 = &team_size[v4];
                                v9 = RGE_Victory_Conditions::get_victory_points(v1->players[v4]->victory_conditions);
                                v10 = v1->players;
                                *v8 = v9;
                                i = 1;
                                if( v10[v4]->allied_victory )
                                {
                                    for ( j = 1; j < v1->player_num; ++j )
                                    {
                                        if( j != v4
                                            && !RGE_Player::relation(v1->players[v4], j)
                                            && !RGE_Player::relation(v1->players[j], v4) )
                                        {
                                            v12 = v1->players[j];
                                            if( v12->allied_victory )
                                            {
                                                *v8 += RGE_Victory_Conditions::get_victory_points(v12->victory_conditions);
                                                ++i;
                                            }
                                        }
                                    }
                                }
                                v13 = v1->player_num;
                                ++v4;
                                *v8 /= i;
                            }
                            while ( v4 < v13 );
                        }
                        v14 = v1->player_num;
                        v15 = 1;
                        v16 = 0;
                        for ( k = -1; v15 < v14; ++v15 )
                        {
                            if( team_size[v15] > k )
                            {
                                k = team_size[v15];
                                v16 = v1->players[v15];
                            }
                        }
                        if( v16 )
                        {
                            RGE_Player::win_game_now(v16);
                            v1->game_end_condition = 103;
                        }
                    }
                }
            }
        }
        if( v1->artifact_count > 0 || v1->ruin_count > 0 )
        {
            v18 = v1->player_num;
            if( v18 > 0 )
            {
                memset(team_size, 0, 4 * ((unsigned int)(4 * v18) >> 2));
                memset(player_team, 0xFFu, 4 * ((unsigned int)(4 * v18) >> 2));
            }
            v19 = 1;
            v20 = 0;
            team_count = 0;
            ia = 1;
            if( v18 > 1 )
            {
                v78 = 0;
                v21 = team_size;
                do
                {
                    if( player_team[v19] == -1 )
                    {
                        player_team[v19] = team_count;
                        v22 = *v21;
                        v23 = (TRIBE_Player *)v1->players[ia];
                        team_player[0][*v21 + v78] = v23;
                        v24 = v22 + 1;
                        LOBYTE(v22) = v23->allied_victory;
                        *v21 = v24;
                        if( (_BYTE)v22 )
                        {
                            held_time = 1;
                            if( v18 > 1 )
                            {
                                v25 = (char *)team_player + 4 * (v24 + v78);
                                do
                                {
                                    if( player_team[held_time] == -1 )
                                    {
                                        v26 = v1->players;
                                        if( v26[held_time]->allied_victory )
                                        {
                                            if( !RGE_Player::relation(v26[ia], held_time)
                                                && !RGE_Player::relation(v1->players[held_time], ia) )
                                            {
                                                v27 = v1->players;
                                                ++v24;
                                                player_team[held_time] = team_count;
                                                v25 += 4;
                                                v28 = v27[held_time];
                                                *v21 = v24;
                                                *((_DWORD *)v25 - 1) = v28;
                                            }
                                        }
                                    }
                                    ++held_time;
                                }
                                while ( held_time < v1->player_num );
                            }
                        }
                        v19 = ia;
                        ++team_count;
                        v78 += 9;
                        ++v21;
                    }
                    v18 = v1->player_num;
                    ia = ++v19;
                }
                while ( v19 < v18 );
                v20 = team_count;
            }
            if( v1->artifact_count > 0 && v20 > 0 )
            {
                v29 = team_player;
                ib = team_player;
                v79 = team_size;
                v83 = v20;
                do
                {
                    v30 = 0;
                    v31 = *v79;
                    if( *v79 > 0 )
                    {
                        v32 = ib;
                        v33 = *v79;
                        do
                        {
                            v30 += (signed __int64)(*v32)[0]->attributes[7];
                            v32 = (TRIBE_Player *(*)[9])((char *)v32 + 4);
                            --v33;
                        }
                        while ( v33 );
                        v1 = v82;
                        v29 = ib;
                    }
                    if( v30 == v1->artifact_count )
                    {
                        v34 = (RGE_Player *)(*v29)[0];
                        held_timea = (*v29)[0]->artifact_held_time;
                        if( held_timea == -1.0 )
                        {
                            if( v31 > 0 )
                            {
                                v35 = v29;
                                v36 = *v79;
                                do
                                {
                                    v37 = (*v35)[0];
                                    v35 = (TRIBE_Player *(*)[9])((char *)v35 + 4);
                                    --v36;
                                    *((_DWORD *)v37->attributes + 55) = 1065353216;
                                }
                                while ( v36 );
                            }
                            if( !v1->victory_type )
                            {
                                if( v31 > 0 )
                                {
                                    v38 = v29;
                                    do
                                    {
                                        v39 = (*v38)[0];
                                        v38 = (TRIBE_Player *(*)[9])((char *)v38 + 4);
                                        --v31;
                                        LODWORD(v39->artifact_held_time) = 1157234688;
                                    }
                                    while ( v31 );
                                }
                                rge_base_game->vfptr->notification(rge_base_game, 114, v34->id, 0, 0, 0);
                            }
                        }
                        else if( held_timea >= 1.0 && !v1->victory_type )
                        {
                            v40 = held_timea - (v1->world_time_delta_seconds + v1->world_time_delta_seconds);
                            if( v31 > 0 )
                            {
                                v41 = v29;
                                do
                                {
                                    v42 = (*v41)[0];
                                    v41 = (TRIBE_Player *(*)[9])((char *)v41 + 4);
                                    --v31;
                                    v42->artifact_held_time = v40;
                                }
                                while ( v31 );
                            }
                            if( v40 < 1.0 )
                            {
                                RGE_Player::win_game_now(v34);
                                v1->game_end_condition = 101;
                            }
                        }
                    }
                    else
                    {
                        v43 = (*v29)[0];
                        if( LODWORD((*v29)[0]->artifact_held_time) != -1082130432 )
                        {
                            if( v31 > 0 )
                            {
                                v44 = v29;
                                v45 = *v79;
                                do
                                {
                                    v46 = (*v44)[0];
                                    v44 = (TRIBE_Player *(*)[9])((char *)v44 + 4);
                                    --v45;
                                    *((_DWORD *)v46->attributes + 55) = 0;
                                }
                                while ( v45 );
                            }
                            if( !v1->victory_type )
                            {
                                if( v31 > 0 )
                                {
                                    v47 = v29;
                                    do
                                    {
                                        v48 = (*v47)[0];
                                        v47 = (TRIBE_Player *(*)[9])((char *)v47 + 4);
                                        --v31;
                                        LODWORD(v48->artifact_held_time) = -1082130432;
                                    }
                                    while ( v31 );
                                }
                                ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
                                    115,
                                    v43->id,
                                    0,
                                    0,
                                    0);
                            }
                        }
                    }
                    ++v29;
                    v5 = v83 == 1;
                    ++v79;
                    ib = v29;
                    --v83;
                }
                while ( !v5 );
            }
            if( v1->ruin_count > 0 && team_count > 0 )
            {
                v49 = team_player;
                ic = team_player;
                v80 = team_size;
                v84 = team_count;
                do
                {
                    v50 = 0;
                    v51 = *v80;
                    if( *v80 <= 0 )
                    {
                        v54 = v82;
                    }
                    else
                    {
                        v52 = ic;
                        v53 = *v80;
                        do
                        {
                            v50 += (signed __int64)(*v52)[0]->attributes[14];
                            v52 = (TRIBE_Player *(*)[9])((char *)v52 + 4);
                            --v53;
                        }
                        while ( v53 );
                        v49 = ic;
                        v54 = v82;
                    }
                    if( v50 == v54->ruin_count )
                    {
                        v55 = (RGE_Player *)(*v49)[0];
                        held_timeb = (*v49)[0]->ruin_held_time;
                        if( held_timeb == -1.0 )
                        {
                            if( v51 > 0 )
                            {
                                v56 = v49;
                                v57 = *v80;
                                do
                                {
                                    v58 = (*v56)[0];
                                    v56 = (TRIBE_Player *(*)[9])((char *)v56 + 4);
                                    --v57;
                                    *((_DWORD *)v58->attributes + 54) = 1065353216;
                                }
                                while ( v57 );
                            }
                            if( !v54->victory_type )
                            {
                                if( v51 > 0 )
                                {
                                    v59 = v49;
                                    do
                                    {
                                        v60 = (*v59)[0];
                                        v59 = (TRIBE_Player *(*)[9])((char *)v59 + 4);
                                        --v51;
                                        LODWORD(v60->ruin_held_time) = 1157234688;
                                    }
                                    while ( v51 );
                                }
                                rge_base_game->vfptr->notification(rge_base_game, 116, v55->id, 0, 0, 0);
                            }
                        }
                        else if( held_timeb >= 1.0 && !v54->victory_type )
                        {
                            v61 = held_timeb - (v54->world_time_delta_seconds + v54->world_time_delta_seconds);
                            if( v51 > 0 )
                            {
                                v62 = v49;
                                do
                                {
                                    v63 = (*v62)[0];
                                    v62 = (TRIBE_Player *(*)[9])((char *)v62 + 4);
                                    --v51;
                                    v63->ruin_held_time = v61;
                                }
                                while ( v51 );
                            }
                            if( v61 < 1.0 )
                            {
                                RGE_Player::win_game_now(v55);
                                v82->game_end_condition = 102;
                            }
                        }
                    }
                    else
                    {
                        v64 = (*v49)[0];
                        if( LODWORD((*v49)[0]->ruin_held_time) != -1082130432 )
                        {
                            if( v51 > 0 )
                            {
                                v65 = v49;
                                v66 = *v80;
                                do
                                {
                                    v67 = (*v65)[0];
                                    v65 = (TRIBE_Player *(*)[9])((char *)v65 + 4);
                                    --v66;
                                    *((_DWORD *)v67->attributes + 54) = 0;
                                }
                                while ( v66 );
                            }
                            if( !v82->victory_type )
                            {
                                if( v51 > 0 )
                                {
                                    v68 = v49;
                                    do
                                    {
                                        v69 = (*v68)[0];
                                        v68 = (TRIBE_Player *(*)[9])((char *)v68 + 4);
                                        --v51;
                                        LODWORD(v69->ruin_held_time) = -1082130432;
                                    }
                                    while ( v51 );
                                }
                                ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
                                    117,
                                    v64->id,
                                    0,
                                    0,
                                    0);
                            }
                        }
                    }
                    ++v49;
                    v5 = v84 == 1;
                    ++v80;
                    ic = v49;
                    --v84;
                }
                while ( !v5 );
                v1 = v82;
            }
        }
    }
    return RGE_Game_World::check_game_state((RGE_Game_World *)&v1->vfptr);
}

int TRIBE_World::get_achievement(char achievement, char **info)
{
    TRIBE_World *v3; // edi@1
    signed int i; // esi@1
    TRIBE_Player *v5; // ecx@2

    v3 = this;
    for ( i = 1; i < v3->player_num; ++i )
    {
        v5 = (TRIBE_Player *)v3->players[i];
        if( v5 )
            TRIBE_Player::get_achievement(v5, achievement, info[i]);
    }
    return v3->player_num;
}

void TRIBE_World::send_cheat(short cheat_code)
{
    TRIBE_Command::command_cheat((TRIBE_Command *)this->commands, this->curr_player, cheat_code);
}

void TRIBE_World::cheat(short player, short cheat_code)
{
    TRIBE_World *v3; // esi@1
    RGE_Static_Object *v4; // eax@4
    RGE_Static_Object *v5; // eax@7
    RGE_Static_Object *v6; // eax@33
    RGE_Static_Object *v7; // eax@38
    signed int v8; // ebp@44
    RGE_Object_Node *i; // edi@48
    RGE_Static_Object *v10; // ecx@49
    RGE_Object_Node *j; // esi@55
    RGE_Static_Object *v12; // ecx@56
    int v13; // edi@63
    RGE_Object_Node *k; // esi@66
    RGE_Static_Object *v15; // ecx@67
    RGE_Static_Object *v16; // eax@72
    int v17; // eax@74
    int v18; // eax@74
    int v19; // eax@75

    v3 = this;
    if( RGE_Base_Game::allowCheatCodes(rge_base_game) )
    {
        switch ( cheat_code )
        {
            case 0:
                if( player > 0 )
                {
                    v4 = RGE_Object_List::find_by_master_id(v3->players[player]->objects, 109, -1.0, -1.0, 1, 2, 0);
                    if( v4 )
                        TRIBE_Command::command_make((TRIBE_Command *)v3->commands, v4, 274);
                }
                break;
            case 1:
                if( player > 0 )
                {
                    v5 = RGE_Object_List::find_by_master_id(v3->players[player]->objects, 109, -1.0, -1.0, 1, 2, 0);
                    if( v5 )
                        TRIBE_Command::command_make((TRIBE_Command *)v3->commands, v5, 248);
                }
                break;
            case 2:
                if( player > 0 )
                    ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(127, v3->players[player]);
                break;
            case 3:
                if( player > 0 )
                    ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(128, v3->players[player]);
                break;
            case 4:
                if( player > 0 )
                    ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(129, v3->players[player]);
                break;
            case 5:
                ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(130, *v3->players);
                break;
            case 6:
                if( player > 0 )
                    ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(131, v3->players[player]);
                break;
            case 7:
                if( player > 0 )
                    ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(132, v3->players[player]);
                break;
            case 8:
                if( player > 0 )
                    ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(133, v3->players[player]);
                break;
            case 9:
                if( player > 0 )
                    ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(134, v3->players[player]);
                break;
            case 10:
                if( player > 0 )
                    ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(135, v3->players[player]);
                break;
            case 11:
                if( player > 0 )
                    ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(136, v3->players[player]);
                break;
            case 12:
                if( player > 0 )
                    ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(137, v3->players[player]);
                break;
            case 13:
                if( player > 0 )
                    ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(138, v3->players[player]);
                break;
            case 14:
                if( player > 0 )
                {
                    v6 = RGE_Object_List::find_by_master_id(v3->players[player]->objects, 109, -1.0, -1.0, 1, 2, 0);
                    if( v6 )
                        TRIBE_Command::command_make((TRIBE_Command *)v3->commands, v6, 386);
                }
                break;
            case 15:
                if( player > 0 )
                    ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(215, v3->players[player]);
                break;
            case 16:
                if( player > 0 )
                {
                    v7 = RGE_Object_List::find_by_master_id(v3->players[player]->objects, 109, -1.0, -1.0, 1, 2, 0);
                    if( v7 )
                        TRIBE_Command::command_make((TRIBE_Command *)v3->commands, v7, 397);
                }
                break;
            case 17:
                if( player > 0 )
                    RGE_Object_List::find_by_master_id(v3->players[player]->objects, 109, -1.0, -1.0, 1, 2, 0);
                break;
            case 18:
                ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(216, *v3->players);
                break;
            case 19:
                ((void (__stdcall *)(signed int, _DWORD))v3->effects->vfptr->do_effect)(217, *v3->players);
                break;
            case 100:
                v8 = 1;
                for ( die_die_die = 1; v8 < v3->player_num; ++v8 )
                {
                    if( v8 != player
                        || !(*(int (__stdcall **)(signed int))&v3->players[player]->vfptr->gap4[24])(v8)
                        || !(*(int (__stdcall **)(_DWORD))&v3->players[v8]->vfptr->gap4[24])(player) )
                    {
                        for ( i = v3->players[v8]->objects->list; i; i = i->next )
                        {
                            v10 = i->node;
                            if( i->node->object_state < 3u && v10->master_obj->object_group != 1 )
                                ((void (*)(void))v10->vfptr->die_die_die)();
                        }
                    }
                }
                break;
            case 101:
                for ( j = v3->players[player]->objects->list; j; j = j->next )
                {
                    v12 = j->node;
                    if( j->node->object_state < 3u && v12->master_obj->object_group != 1 )
                        ((void (*)(void))v12->vfptr->die_die_die)();
                }
                break;
            case 102:
                RGE_Player::win_game_now(v3->players[player]);
                v3->game_end_condition = 104;
                break;
            case 103:
                RGE_Player::loss_if_game_on(v3->players[player]);
                break;
            case 200:
            case 201:
            case 202:
            case 203:
            case 204:
            case 205:
            case 206:
            case 207:
            case 208:
            case 209:
                v13 = cheat_code - 200;
                if( v13 != player
                    || !(*(int (__stdcall **)(int))&v3->players[player]->vfptr->gap4[24])(cheat_code - 200)
                    || !(*(int (__stdcall **)(_DWORD))&v3->players[v13]->vfptr->gap4[24])(player) )
                {
                    for ( k = v3->players[v13]->objects->list; k; k = k->next )
                    {
                        v15 = k->node;
                        if( k->node->object_state < 3u && v15->master_obj->object_group != 1 )
                            ((void (*)(void))v15->vfptr->die_die_die)();
                    }
                }
                break;
            case 220:
                v16 = RGE_Object_List::find_by_master_id(v3->players[player]->objects, 109, -1.0, -1.0, 1, 2, 0);
                if( v16 )
                    TRIBE_Command::command_make((TRIBE_Command *)v3->commands, v16, 372);
                break;
            case 230:
                RGE_Base_Game::set_map_visible(rge_base_game, 1);
                v17 = ((int (*)(void))rge_base_game->vfptr->get_view_panel)();
                (*(void (**)(int, signed int))(*(_DWORD *)v17 + 32))(v17, 2);
                v18 = ((int (*)(void))rge_base_game->vfptr->get_map_panel)();
                (*(void (**)(int, signed int))(*(_DWORD *)v18 + 32))(v18, 2);
                break;
            case 231:
                RGE_Base_Game::set_map_fog(rge_base_game, 0);
                v19 = ((int (*)(void))rge_base_game->vfptr->get_view_panel)();
                (*(void (**)(int, signed int))(*(_DWORD *)v19 + 32))(v19, 2);
                break;
            default:
                return;
        }
    }
}

void TRIBE_World::fill_in_score(TRIBE_Zone_High_Score_Info *info, int score_group)
{
    TRIBE_World *v3; // ebp@1
    signed int v4; // esi@1
    int v5; // edi@1
    TRIBE_Zone_High_Score_Info *v6; // edx@6
    int v7; // esi@6
    signed int hi_player; // [sp+10h] [bp-4h]@1
    int score_groupa; // [sp+1Ch] [bp+8h]@6

    v3 = this;
    v4 = 1;
    v5 = 0;
    for ( hi_player = 1; v4 < v3->player_num; ++v4 )
    {
        if( !RGE_Player::computerPlayer(v3->players[v4])
            && RGE_Victory_Conditions::get_victory_points_group(v3->players[v4]->victory_conditions, score_group) > v5 )
        {
            v5 = RGE_Victory_Conditions::get_victory_points_group(v3->players[v4]->victory_conditions, score_group);
            hi_player = v4;
        }
    }
    v6 = info;
    info->score = v5;
    info->civ = v3->players[hi_player]->culture;
    score_groupa = 0;
    strcpy(info->player_name, v3->players[hi_player]->name);
    v7 = 1;
    if( v3->player_num > 1 )
    {
        do
        {
            if( v7 != hi_player
                && !RGE_Player::relation(v3->players[v7], hi_player)
                && !RGE_Player::relation(v3->players[hi_player], v7) )
            {
                ++score_groupa;
            }
            ++v7;
        }
        while ( v7 < v3->player_num );
        v6 = info;
    }
    v6->num_allies = score_groupa;
}

void TRIBE_World::send_zone_score_info()
{
    TRIBE_World *v1; // ebx@1
    bool v2; // zf@2
    bool v3; // sf@2
    unsigned __int8 v4; // of@2
    signed int v5; // esi@2
    RGE_Scenario *v6; // ecx@7
    const char *v7; // edi@7
    unsigned int v8; // ecx@7
    char v9; // al@7
    char *v10; // edi@7
    const char *v11; // esi@7
    signed __int64 v12; // rax@7
    RGE_Player **v13; // edx@8
    char *v14; // ebp@8
    int v15; // edi@9
    TRIBE_Game *v16; // ecx@9
    char v17; // al@9
    TRIBE_Game *v18; // ecx@9
    char v19; // al@9
    RGE_Base_Game *v20; // ecx@9
    char v21; // al@9
    TCommunications_Handler *v22; // ecx@9
    int i; // eax@9
    RGE_Command *v24; // ecx@28
    char count; // [sp+4h] [bp-270h]@2
    int counta; // [sp+4h] [bp-270h]@7
    TRIBE_Game::TRIBE_Game_Options options; // [sp+Ch] [bp-268h]@28
    TRIBE_Zone_Info info; // [sp+78h] [bp-1FCh]@2

    v1 = this;
    if( !this->sent_zone_score )
    {
        v4 = __OFSUB__(this->player_num, 1);
        v2 = this->player_num == 1;
        v3 = (signed short)(this->player_num - 1) < 0;
        this->sent_zone_score = 1;
        info.number_of_players = 0;
        count = 0;
        v5 = 1;
        if( !((unsigned __int8)(v3 ^ v4) | v2) )
        {
            do
            {
                if( RGE_Player::computerPlayer(v1->players[v5]) )
                    ++count;
                else
                    ++info.number_of_players;
                ++v5;
            }
            while ( v5 < v1->player_num );
        }
        v6 = v1->scenario;
        info.number_of_computer_players = count;
        v7 = RGE_Scenario::Get_scenario_name(v6);
        v8 = strlen(v7) + 1;
        v9 = v8;
        v8 >>= 2;
        qmemcpy(info.scenario_name, v7, 4 * v8);
        v11 = &v7[4 * v8];
        v10 = &info.scenario_name[4 * v8];
        LOBYTE(v8) = v9;
        v12 = 274877907i64 * v1->world_time;
        qmemcpy(v10, v11, v8 & 3);
        info.game_time = HIDWORD(v12) >> 6;
        TRIBE_World::fill_in_score(v1, &info.total_score, 255);
        TRIBE_World::fill_in_score(v1, &info.religion_score, 2);
        TRIBE_World::fill_in_score(v1, &info.economy_score, 1);
        TRIBE_World::fill_in_score(v1, &info.combat_score, 0);
        TRIBE_World::fill_in_score(v1, &info.research_score, 3);
        counta = 1;
        if( v1->player_num > 1 )
        {
            v13 = v1->players;
            v14 = (char *)&info.player_info[0].score;
            do
            {
                strcpy(v14 - 16, v13[counta]->name);
                v15 = counta;
                *(_DWORD *)v14 = RGE_Victory_Conditions::get_victory_points(v13[counta]->victory_conditions);
                v16 = (TRIBE_Game *)rge_base_game;
                v14[4] = v1->players[counta]->game_status == 1;
                v17 = TRIBE_Game::civilization(v16, counta - 1);
                v18 = (TRIBE_Game *)rge_base_game;
                v14[5] = v17;
                v14[6] = v18->queue_is_waiting_on_pop_counter[counta + 8];
                v19 = TRIBE_Game::playerColor(v18, counta - 1);
                v20 = rge_base_game;
                v14[7] = v19;
                v21 = RGE_Base_Game::playerTeam(v20, counta - 1);
                v22 = comm;
                v13 = v1->players;
                v14[8] = v21;
                v14[9] = *(&v22->HoldCount + counta);
                *((_DWORD *)v14 + 3) = -1;
                *((_DWORD *)v14 + 4) = -1;
                *((_DWORD *)v14 + 5) = -1;
                for ( i = *(_DWORD *)(*(_DWORD *)&v13[counta][3].groups_used[62] + 4); i; i = *(_DWORD *)(i + 12) )
                {
                    if( *(_BYTE *)i )
                    {
                        if( *(_BYTE *)i == 1 )
                        {
                            *((_DWORD *)v14 + 4) = *(_DWORD *)(i + 8);
                        }
                        else if( *(_BYTE *)i == 2 )
                        {
                            *((_DWORD *)v14 + 5) = *(_DWORD *)(i + 8);
                        }
                    }
                    else
                    {
                        *((_DWORD *)v14 + 3) = *(_DWORD *)(i + 8);
                    }
                }
                v14 += 40;
                ++counta;
            }
            while ( v15 + 1 < v1->player_num );
        }
        info.cheats_enabled = RGE_Base_Game::allowCheatCodes(rge_base_game);
        switch ( v1->game_end_condition )
        {
            case 0:
                info.game_end_condition_code = 0;
                break;
            case 1:
                info.game_end_condition_code = 1;
                break;
            case 0x64:
                info.game_end_condition_code = 2;
                break;
            case 0x65:
                info.game_end_condition_code = 3;
                break;
            case 0x66:
                info.game_end_condition_code = 4;
                break;
            case 0x67:
                info.game_end_condition_code = 5;
                break;
            case 2:
                info.game_end_condition_code = 6;
                break;
            case 0x68:
                info.game_end_condition_code = 7;
                break;
            default:
                info.game_end_condition_code = 8;
                break;
        }
        TRIBE_Game::get_tribe_options((TRIBE_Game *)rge_base_game, &options);
        info.map_info.Map_Size = options.mapSizeValue;
        info.map_info.Map_Type = options.mapTypeValue;
        info.map_info.Victory_Condition = options.victoryTypeValue;
        info.map_info.Start_Age = options.startingAgeValue;
        info.map_info.Resources = options.resourceLevelValue;
        info.map_info.Full_Tech = options.fullTechTreeValue;
        info.map_info.Fixed_Pos = options.randomizePositionsValue;
        info.map_info.Reveal_Map = RGE_Base_Game::fullVisibility(rge_base_game);
        info.map_info.Death_Match = options.deathMatchValue;
        v24 = v1->commands;
        info.map_info.Pop_Limit = (unsigned __int8)options.popLimitValue;
        info.database_checksum = 0;
        info.code_checksum = 0;
        info.program_version = 0;
        TCommunications_Handler::SendZoneMessage(v24->com_hand, &info.number_of_players, 0x1FCu);
    }
}
