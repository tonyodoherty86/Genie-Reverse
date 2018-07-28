
void TRIBE_Player::TRIBE_Player(int infile, TRIBE_World *gworld, char this_id)
{
    int v4; // edi@1
    TRIBE_Player *v5; // esi@1
    TRIBE_Player_Tech *v6; // eax@1
    TRIBE_Player_Tech *v7; // eax@2
    TRIBE_History_Info *v8; // eax@5
    TRIBE_History_Info *v9; // eax@6
    TRIBE_History_Info *v10; // eax@7
    TribeMainDecisionAIModule *v11; // eax@18
    TribeMainDecisionAIModule *v12; // eax@19

    v4 = infile;
    v5 = this;
    RGE_Player::RGE_Player((RGE_Player *)&this->vfptr, infile, (RGE_Game_World *)&gworld->vfptr, this_id);
    v5->playerAI = 0;
    v5->vfptr = (RGE_PlayerVtbl *)&TRIBE_Player::`vftable';
    rge_read((int)gworld, v4, v4, &v5->type, 1);
    rge_read((int)gworld, v4, v4, &v5->update_count, 4);
    rge_read((int)gworld, v4, v4, &v5->updateCountNeedHelp, 4);
    rge_read((int)gworld, v4, v4, &v5->fog_update, 4);
    rge_read((int)gworld, v4, v4, &v5->update_time, 4);
    v6 = (TRIBE_Player_Tech *)operator new(0x10u);
    *(_DWORD *)&this_id = v6;
    if( v6 )
        v7 = TRIBE_Player_Tech::TRIBE_Player_Tech(v6, infile, infile, (int)gworld->tech, (int)v5, 0);
    else
        v7 = 0;
    v5->tech_tree = v7;
    if( save_game_version <= 5.0 )
    {
        v5->update_history_count = 0;
        v10 = (TRIBE_History_Info *)operator new(0x14u);
        *(_DWORD *)&this_id = v10;
        if( v10 )
        {
            TRIBE_History_Info::TRIBE_History_Info(v10, (int)gworld, -1);
            goto LABEL_10;
        }
    }
    else
    {
        rge_read((int)gworld, infile, infile, &v5->update_history_count, 4);
        v8 = (TRIBE_History_Info *)operator new(0x14u);
        *(_DWORD *)&this_id = v8;
        if( v8 )
        {
            TRIBE_History_Info::TRIBE_History_Info(v8, (int)gworld, infile);
            goto LABEL_10;
        }
    }
    v9 = 0;
LABEL_10:
    v5->history = v9;
    if( save_game_version < 5.3000002 )
    {
        LODWORD(v5->ruin_held_time) = -1082130432;
        LODWORD(v5->artifact_held_time) = -1082130432;
    }
    else
    {
        rge_read((int)gworld, infile, infile, &v5->ruin_held_time, 4);
        rge_read((int)gworld, infile, infile, &v5->artifact_held_time, 4);
    }
    if( v5->type == 3 )
    {
        *(_DWORD *)&this_id = 1;
        if( save_game_version >= 7.0300002 )
            rge_read(1, infile, infile, &this_id, 4);
        if( TCommunications_Handler::IsHost(comm) == 1 && this_id == 1 )
        {
            v11 = (TribeMainDecisionAIModule *)operator new(0x125C8u);
            if( v11 )
                TribeMainDecisionAIModule::TribeMainDecisionAIModule(v11, v5->id, v5->name, v5, infile);
            else
                v12 = 0;
            v5->playerAI = v12;
        }
        v5->computerPlayerValue = 1;
    }
}
// 576870: using guessed type int (__thiscall *TRIBE_Player::`vftable')(void *Memory, unsigned int __flags);
// 58EBCC: using guessed type float save_game_version;

//----- (00511E00) --------------------------------------------------------
TRIBE_Player *TRIBE_Player::`scalar deleting destructor'(unsigned int __flags)
{
    TRIBE_Player *v2; // esi@1

    v2 = this;
    TRIBE_Player::~TRIBE_Player(this);
    if( __flags & 1 )
        operator delete(v2);
    return v2;
}

//----- (00511E20) --------------------------------------------------------
void TRIBE_Player::TRIBE_Player(TRIBE_World *gworld, RGE_Master_Player *prototype, char this_id, char *new_name, char m_player_id, char computerPlayer, char flag, char *buildListName, char *cityPlanName, char *ruleSetName)
{
    TRIBE_Player *v11; // esi@1
    Visible_Resource_Manager *v12; // eax@1
    Visible_Resource_Manager *v13; // eax@2
    TribeMainDecisionAIModule *v14; // eax@7
    TribeMainDecisionAIModule *v15; // eax@8
    RGE_Object_List *v16; // eax@12
    RGE_Object_List *v17; // edi@12
    RGE_Object_List *v18; // eax@15
    RGE_Object_List *v19; // edi@15
    RGE_Object_List *v20; // eax@18
    RGE_Object_List *v21; // edi@18
    RGE_Visible_Map *v22; // eax@21
    RGE_Visible_Map *v23; // eax@22
    int i; // edi@25
    int v25; // eax@29
    unsigned int v26; // edx@29
    TRIBE_History_Info *v27; // eax@29
    TRIBE_History_Info *v28; // eax@30
    TRIBE_Player_Tech *v29; // eax@32
    TRIBE_Player_Tech *v30; // eax@33

    v11 = this;
    RGE_Player::RGE_Player(
        (RGE_Player *)&this->vfptr,
        (RGE_Game_World *)&gworld->vfptr,
        prototype,
        this_id,
        new_name,
        m_player_id,
        0);
    v11->playerAI = 0;
    v11->vfptr = (RGE_PlayerVtbl *)&TRIBE_Player::`vftable';
    v12 = (Visible_Resource_Manager *)operator new(0x14u);
    if( v12 )
        Visible_Resource_Manager::Visible_Resource_Manager(v12, (RGE_Player *)&v11->vfptr, 5);
    else
        v13 = 0;
    v11->VR_List = v13;
    if( computerPlayer )
    {
        v11->type = 3;
        v11->computerPlayerValue = 1;
        if( TCommunications_Handler::IsHost(comm) == 1 )
        {
            v14 = (TribeMainDecisionAIModule *)operator new(0x125C8u);
            if( v14 )
                TribeMainDecisionAIModule::TribeMainDecisionAIModule(
                    v14,
                    0,
                    v11->id,
                    v11->name,
                    v11,
                    buildListName,
                    cityPlanName,
                    ruleSetName);
            else
                v15 = 0;
            v11->playerAI = v15;
        }
    }
    else
    {
        v11->type = 1;
    }
    if( flag )
    {
        v16 = (RGE_Object_List *)operator new(0xCu);
        v17 = v16;
        if( v16 )
        {
            RGE_Object_List::RGE_Object_List(v16);
            v17->vfptr = (RGE_Object_ListVtbl *)&TRIBE_Object_List::`vftable';
        }
        else
        {
            v17 = 0;
        }
        v11->objects = v17;
        v18 = (RGE_Object_List *)operator new(0xCu);
        v19 = v18;
        if( v18 )
        {
            RGE_Object_List::RGE_Object_List(v18);
            v19->vfptr = (RGE_Object_ListVtbl *)&TRIBE_Object_List::`vftable';
        }
        else
        {
            v19 = 0;
        }
        v11->sleeping_objects = v19;
        v20 = (RGE_Object_List *)operator new(0xCu);
        v21 = v20;
        if( v20 )
        {
            RGE_Object_List::RGE_Object_List(v20);
            v21->vfptr = (RGE_Object_ListVtbl *)&TRIBE_Object_List::`vftable';
        }
        else
        {
            v21 = 0;
        }
        v11->doppleganger_objects = v21;
        TRIBE_Player::new_victory(v11);
        v22 = (RGE_Visible_Map *)operator new(0x38u);
        if( v22 )
            RGE_Visible_Map::RGE_Visible_Map(v22, gworld->map, (RGE_Player *)&v11->vfptr);
        else
            v23 = 0;
        v11->visible = v23;
    }
    for( i = 1; i < v11->world->player_num; ++i )
    {
        if( i != v11->id )
            RGE_Player::set_relation((RGE_Player *)&v11->vfptr, i, 3);
    }
    v11->update_count = 0;
    v11->update_history_count = 0;
    v11->updateCountNeedHelp = 0;
    v25 = debug_rand(aCMsdevWorkAg_3, 320);
    v26 = (signed int)(3 * v25 + ((unsigned __int64)(-6442254327i64 * v25) >> 32)) >> 14;
    LODWORD(v11->update_time) = 0;
    v11->fog_update = v26 + (v26 >> 31) + 3;
    v27 = (TRIBE_History_Info *)operator new(0x14u);
    if( v27 )
        TRIBE_History_Info::TRIBE_History_Info(v27, (int)gworld, -1);
    else
        v28 = 0;
    v11->history = v28;
    v29 = (TRIBE_Player_Tech *)operator new(0x10u);
    if( v29 )
        v30 = TRIBE_Player_Tech::TRIBE_Player_Tech(v29, gworld->tech, (RGE_Player *)&v11->vfptr, 1);
    else
        v30 = 0;
    v11->tech_tree = v30;
    LODWORD(v11->ruin_held_time) = -1082130432;
    LODWORD(v11->artifact_held_time) = -1082130432;
}
// 576870: using guessed type int (__thiscall *TRIBE_Player::`vftable')(void *Memory, unsigned int __flags);
// 57699C: using guessed type void (__thiscall *TRIBE_Object_List::`vftable')(TRIBE_Object_List *this, unsigned __int8 object_type, int infile, struct RGE_Game_World *);

//----- (005120F0) --------------------------------------------------------
void TRIBE_Player::~TRIBE_Player()
{
    TRIBE_Player *v1; // esi@1
    TRIBE_Player_Tech *v2; // edi@1
    TribeMainDecisionAIModule *v3; // ecx@3
    TRIBE_History_Info *v4; // edi@5

    v1 = this;
    this->vfptr = (RGE_PlayerVtbl *)&TRIBE_Player::`vftable';
    v2 = this->tech_tree;
    if( v2 )
    {
        TRIBE_Player_Tech::~TRIBE_Player_Tech(v2);
        operator delete(v2);
        v1->tech_tree = 0;
    }
    v3 = v1->playerAI;
    if( v3 )
    {
        ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
        v1->playerAI = 0;
    }
    v4 = v1->history;
    if( v4 )
    {
        TRIBE_History_Info::~TRIBE_History_Info(v1->history);
        operator delete(v4);
        v1->history = 0;
    }
    RGE_Player::~RGE_Player((RGE_Player *)&v1->vfptr);
}
// 576870: using guessed type int (__thiscall *TRIBE_Player::`vftable')(void *Memory, unsigned int __flags);

//----- (005121A0) --------------------------------------------------------
TRIBE_Building_Object *TRIBE_Player::make_scenario_obj(float world_x, float world_y, float world_z, short master_id, char state, float new_angle)
{
    TRIBE_Player *v7; // ebp@1
    TRIBE_Building_Object *v8; // esi@1
    int v9; // edi@1
    RGE_Master_Static_Object *v10; // ecx@1
    int v11; // eax@2
    unsigned __int8 v12; // al@6

    v7 = this;
    v8 = 0;
    v9 = master_id;
    v10 = this->master_objects[v9];
    if( v10 )
    {
        v11 = ((int (__stdcall *)(TRIBE_Player *, _DWORD, _DWORD, _DWORD))v10->vfptr->make_new_obj)(
                        v7,
                        LODWORD(world_x),
                        LODWORD(world_y),
                        LODWORD(world_z));
        v8 = (TRIBE_Building_Object *)v11;
        if( (unsigned __int8)state < 7u )
        {
            if( (unsigned __int8)state <= 2u )
            {
                v12 = *(_BYTE *)(*(_DWORD *)(v11 + 8) + 4);
                if( v12 <= 0x1Eu || v12 >= 0x5Au )
                    v8->facet = (signed __int64)new_angle;
                else
                    ((void (__thiscall *)(TRIBE_Building_Object *, _DWORD))v8->vfptr->new_angle)(v8, LODWORD(new_angle));
            }
            else
            {
                (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 108))(v11);
            }
        }
        else
        {
            (*(void (__thiscall **)(int))(*(_DWORD *)v11 + 104))(v11);
        }
        if( v7->master_objects[v9]->master_type == 80 && state == 2 )
            TRIBE_Building_Object::build(v8, 10000.0);
    }
    return v8;
}

//----- (00512250) --------------------------------------------------------
void TRIBE_Player::save(int outfile)
{
    TRIBE_Player *v2; // esi@1
    int v3; // edi@1

    v2 = this;
    color_log(22, 22, 2);
    v3 = outfile;
    RGE_Player::save((RGE_Player *)&v2->vfptr, outfile);
    color_log(22, 36, 2);
    rge_write(v3, &v2->type, 1);
    rge_write(v3, &v2->update_count, 4);
    rge_write(v3, &v2->updateCountNeedHelp, 4);
    rge_write(v3, &v2->fog_update, 4);
    rge_write(v3, &v2->update_time, 4);
    TRIBE_Player_Tech::save(v2->tech_tree, v3);
    rge_write(v3, &v2->update_history_count, 4);
    TRIBE_History_Info::save(v2->history, v3);
    rge_write(v3, &v2->ruin_held_time, 4);
    rge_write(v3, &v2->artifact_held_time, 4);
    color_log(22, 76, 2);
    if( v2->computerPlayerValue == 1 )
    {
        if( v2->playerAI && TCommunications_Handler::IsHost(comm) == 1 )
        {
            outfile = 1;
            rge_write(v3, &outfile, 4);
            ((void (__stdcall *)(int))v2->playerAI->vfptr[1].__vecDelDtor)(v3);
            color_log(22, 95, 2);
            return;
        }
        outfile = 0;
        rge_write(v3, &outfile, 4);
    }
    color_log(22, 95, 2);
}

//----- (005123B0) --------------------------------------------------------
void TRIBE_Player::update()
{
    TRIBE_Player *v1; // esi@1
    double v2; // st7@1
    double v3; // st7@2
    int v4; // edx@2
    float *v5; // ecx@3
    float *v6; // ecx@9
    float *v7; // ecx@11
    int v8; // eax@13
    int v9; // eax@15
    RGE_Object_Node *v10; // ecx@18
    int v11; // eax@19
    float *v12; // ecx@32
    int v13; // eax@34
    int v14; // edi@34
    unsigned int v15; // ebx@34
    RGE_Game_World *v16; // ecx@36

    v1 = this;
    v2 = this->world->world_time_delta_seconds + this->update_time;
    this->update_time = v2;
    if( v2 > 1.0 )
    {
        do
        {
            v3 = v1->update_time - 1.0;
            v4 = v1->update_history_count + 1;
            v1->update_history_count = v4;
            v1->update_time = v3;
            if( v4 >= 15 )
            {
                v5 = v1->attributes;
                v1->update_history_count = v4 - 15;
                if( v5[11] >= 0.0 )
                    TRIBE_History_Info::add_history_entry(v1->history, 0, (signed __int64)v5[11]);
                else
                    TRIBE_History_Info::add_history_entry(v1->history, 0, 0);
            }
            if( RGE_Base_Game::fullVisibility(rge_base_game) )
                *((_DWORD *)v1->attributes + 22) = 1120403456;
            else
                v1->attributes[22] = RGE_Visible_Map::percentExplored(v1->visible) * 100.0;
            v1->attributes[44] = v1->attributes[20] - (v1->attributes[19] - v1->attributes[11]);
            v6 = v1->attributes;
            if( v6[44] < 0.0 )
                *((_DWORD *)v6 + 44) = 0;
            v1->attributes[9] = v1->attributes[10] + v1->attributes[9];
            v7 = v1->attributes;
            if( v7[9] > 100.0 )
                *((_DWORD *)v7 + 9) = 1120403456;
            v8 = v1->update_count;
            if( v8 > 0 )
                v1->update_count = v8 - 1;
            v9 = v1->updateCountNeedHelp;
            if( v9 > 0 )
                v1->updateCountNeedHelp = v9 - 1;
            if( v1->id > 0 )
            {
                v10 = v1->objects->list;
                if( !v10 )
                    goto LABEL_43;
                do
                {
                    v11 = v10->node->master_obj->object_group;
                    if( v11 != 11
                        && v11 != 30
                        && v11 != 27
                        && v11 != 1
                        && v11 != 21
                        && v11 != 20
                        && v11 != 2
                        && v11 != 37
                        && v10->node->object_state == 2 )
                    {
                        break;
                    }
                    v10 = v10->next;
                }
                while( v10 );
                if( !v10 )
                {
LABEL_43:
                    (*(void (__thiscall **)(TRIBE_Player *, signed int))&v1->vfptr->gap4[0])(v1, 2);
                    *((_DWORD *)v1->attributes + 45) = 0;
                }
            }
        }
        while( v1->update_time > 1.0 );
    }
    RGE_Player::update((RGE_Player *)&v1->vfptr);
    *v1->attributes = *v1->attributes
                                    - v1->world->world_time_delta_seconds * v1->attributes[33] * v1->attributes[11] * 0.016666668;
    v12 = v1->attributes;
    if( *v12 < 0.0 )
        *(_DWORD *)v12 = 0;
    v13 = debug_rand(aCMsdevWorkAg_3, 607);
    v14 = debug_random_on;
    v15 = v13;
    global_save_debug_random_on1 = debug_random_on;
    debug_random_on = 0;
    if( v1->playerAI && TCommunications_Handler::ComputerPlayerGameStart(comm) == 1 )
    {
        v16 = v1->world;
        if( v16->currentUpdateComputerPlayer == -1 )
            RGE_Game_World::selectNextComputerPlayer(v16, 3);
        ((void (__stdcall *)(_DWORD))v1->playerAI->vfptr->update)(0);
    }
    debug_random_on = v14;
    debug_srand(aCMsdevWorkAg_3, 631, v15);
    if( MouseSystem )
        TMousePointer::Poll(MouseSystem);
}
// 62C4D4: using guessed type int debug_random_on;
// 86BC90: using guessed type int global_save_debug_random_on1;

//----- (00512630) --------------------------------------------------------
void TRIBE_Player::scenario_save(int outfile)
{
    TRIBE_Player *v2; // esi@1

    v2 = this;
    RGE_Player::scenario_save((RGE_Player *)&this->vfptr, outfile);
    rge_write(outfile, v2->attributes, 4);
    rge_write(outfile, v2->attributes + 1, 4);
    rge_write(outfile, v2->attributes + 3, 4);
    rge_write(outfile, v2->attributes + 2, 4);
}

//----- (00512690) --------------------------------------------------------
void TRIBE_Player::scenario_load(TRIBE_Player *this@<ecx>, int a2@<ebp>, char *a3@<edi>, int infile, int *player_id_hash, float version)
{
    TRIBE_Player *v6; // esi@1
    TRIBE_Player_Tech *v7; // edi@1
    int i; // edi@3
    RGE_Master_Static_Object *v9; // ecx@4
    TRIBE_Player_Tech *v10; // eax@10
    TRIBE_Player_Tech *v11; // eax@13
    TRIBE_Player_Tech *v12; // eax@14

    v6 = this;
    RGE_Player::scenario_load((RGE_Player *)&this->vfptr, a3, infile, player_id_hash, version);
    v7 = v6->tech_tree;
    if( v7 )
    {
        TRIBE_Player_Tech::~TRIBE_Player_Tech(v6->tech_tree);
        operator delete(v7);
    }
    for( i = 0; i < v6->master_object_num; ++i )
    {
        v9 = v6->master_objects[i];
        if( v9 )
            RGE_Master_Static_Object::make_available(v9, 0);
    }
    if( version > 1.06 )
    {
        rge_read(a2, i, infile, v6->attributes, 4);
        rge_read(a2, i, infile, v6->attributes + 1, 4);
        rge_read(a2, i, infile, v6->attributes + 3, 4);
        rge_read(a2, i, infile, v6->attributes + 2, 4);
    }
    *((_DWORD *)v6->attributes + 30) = 0;
    *((_DWORD *)v6->attributes + 21) = 0;
    if( version > 1.03 )
    {
        v11 = (TRIBE_Player_Tech *)operator new(0x10u);
        if( v11 )
            v12 = TRIBE_Player_Tech::TRIBE_Player_Tech(v11, (TRIBE_Tech *)v6->world[1].vfptr, (RGE_Player *)&v6->vfptr, 0);
        else
            v12 = 0;
        v6->tech_tree = v12;
        if( v6->tribe_effect < 0
            || TRIBE_Game::fullTechTree((TRIBE_Game *)rge_base_game)
            || T_Scenario::GetScenarioOption((T_Scenario *)v6->world->scenario, 2) )
        {
            TRIBE_Effects::do_tech_effect((TRIBE_Effects *)v6->world->effects, 210, (RGE_Player *)&v6->vfptr);
        }
        else
        {
            TRIBE_Effects::do_tech_effect((TRIBE_Effects *)v6->world->effects, v6->tribe_effect, (RGE_Player *)&v6->vfptr);
        }
        if( rge_base_game->game_mode != 7 )
            T_Scenario::set_player_tech((T_Scenario *)v6->world->scenario, v6);
        TRIBE_Player_Tech::check_for_new_tech(v6->tech_tree);
    }
    else
    {
        v10 = (TRIBE_Player_Tech *)operator new(0x10u);
        if( v10 )
            v6->tech_tree = TRIBE_Player_Tech::TRIBE_Player_Tech(v10, i, infile, (int)v6->world[1].vfptr, (int)v6, 1);
        else
            v6->tech_tree = 0;
    }
}

//----- (005128A0) --------------------------------------------------------
void TRIBE_Player::load(TRIBE_Player *this@<ecx>, int a2@<edi>, int infile)
{
    int v3; // ebx@1
    TRIBE_Player *v4; // esi@1
    char *v5; // ebp@1
    int v6; // edi@1
    RGE_Master_Static_Object **v7; // eax@2
    int v8; // ecx@2
    RGE_Visible_Map *v9; // eax@8
    RGE_Visible_Map *v10; // eax@9
    Visible_Resource_Manager *v11; // eax@11
    Visible_Resource_Manager *v12; // eax@12
    RGE_Object_List *v13; // eax@14
    RGE_Object_List *v14; // edi@14
    RGE_Game_World *v15; // ST10_4@17
    RGE_Object_List *v16; // eax@17
    RGE_Object_List *v17; // edi@17
    RGE_Object_List *v18; // ecx@18
    RGE_Game_World *v19; // edx@20
    RGE_Object_List *v20; // eax@20
    RGE_Object_List *v21; // eax@21
    RGE_Object_List *v22; // ecx@21

    v3 = infile;
    v4 = this;
    v5 = (char *)&this->master_object_num;
    rge_read((int)&this->master_object_num, a2, infile, &this->master_object_num, 2);
    v6 = 0;
    if( *(_WORD *)v5 <= 0 )
    {
        v4->master_objects = 0;
    }
    else
    {
        v7 = (RGE_Master_Static_Object **)calloc(*(_WORD *)v5, 4u);
        v8 = *(_WORD *)v5;
        v4->master_objects = v7;
        rge_read((int)v5, 0, v3, v7, 4 * v8);
        if( *(_WORD *)v5 > 0 )
        {
            do
            {
                if( v4->master_objects[(signed short)v6] )
                {
                    rge_read((int)v5, v6, v3, &infile, 1);
                    TRIBE_Player::load_master_object(v4, (int)v5, v3, v6, infile, v4->world->sprites, v4->world->sounds);
                }
                ++v6;
            }
            while( (signed short)v6 < *(_WORD *)v5 );
        }
    }
    v9 = (RGE_Visible_Map *)operator new(0x38u);
    if( v9 )
        RGE_Visible_Map::RGE_Visible_Map(v9, v6, v3, v4->world);
    else
        v10 = 0;
    v4->visible = v10;
    v11 = (Visible_Resource_Manager *)operator new(0x14u);
    if( v11 )
        Visible_Resource_Manager::Visible_Resource_Manager(v11, v3, (RGE_Player *)&v4->vfptr);
    else
        v12 = 0;
    v4->VR_List = v12;
    v13 = (RGE_Object_List *)operator new(0xCu);
    v14 = v13;
    if( v13 )
    {
        RGE_Object_List::RGE_Object_List(v13);
        v14->vfptr = (RGE_Object_ListVtbl *)&TRIBE_Object_List::`vftable';
    }
    else
    {
        v14 = 0;
    }
    v15 = v4->world;
    v4->objects = v14;
    RGE_Object_List::load_list(v14, -1, v3, v15);
    v16 = (RGE_Object_List *)operator new(0xCu);
    v17 = v16;
    if( v16 )
    {
        RGE_Object_List::RGE_Object_List(v16);
        v17->vfptr = (RGE_Object_ListVtbl *)&TRIBE_Object_List::`vftable';
        v18 = v17;
    }
    else
    {
        v18 = 0;
    }
    v19 = v4->world;
    v4->sleeping_objects = v18;
    RGE_Object_List::load_list(v18, -1, v3, v19);
    v20 = (RGE_Object_List *)operator new(0xCu);
    if( v20 )
    {
        RGE_Object_List::RGE_Object_List(v20);
        v22 = v21;
    }
    else
    {
        v22 = 0;
    }
    v4->doppleganger_objects = v22;
    if( save_game_version >= 7.0900002 )
        RGE_Object_List::load_list(v22, -1, v3, v4->world);
}
// 57699C: using guessed type void (__thiscall *TRIBE_Object_List::`vftable')(TRIBE_Object_List *this, unsigned __int8 object_type, int infile, struct RGE_Game_World *);
// 58EBCC: using guessed type float save_game_version;

//----- (00512A90) --------------------------------------------------------
void TRIBE_Player::load_master_object(TRIBE_Player *this@<ecx>, int a2@<ebp>, int infile, short index, char type, RGE_Sprite **sprites, RGE_Sound **sounds)
{
    TRIBE_Player *v7; // esi@1
    TRIBE_Master_Tree_Object *v8; // eax@5
    RGE_Master_Static_Object *v9; // eax@6
    TRIBE_Master_Building_Object *v10; // eax@7
    RGE_Master_Static_Object *v11; // eax@8
    TRIBE_Master_Combat_Object *v12; // eax@10

    v7 = this;
    if( type == 70 )
    {
        v12 = (TRIBE_Master_Combat_Object *)operator new(0x164u);
        if( v12 )
        {
            TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(v12, infile, sprites, sounds, 1);
            goto LABEL_13;
        }
LABEL_12:
        v9 = 0;
        goto LABEL_13;
    }
    if( type != 80 )
    {
        if( type != 90 )
        {
            RGE_Player::load_master_object((RGE_Player *)&this->vfptr, a2, infile, index, type, sprites, sounds);
            return;
        }
        v8 = (TRIBE_Master_Tree_Object *)operator new(0xB8u);
        if( v8 )
        {
            TRIBE_Master_Tree_Object::TRIBE_Master_Tree_Object(v8, infile, sprites, sounds, 1);
LABEL_13:
            v7->master_objects[index] = v9;
            return;
        }
        goto LABEL_12;
    }
    v10 = (TRIBE_Master_Building_Object *)operator new(0x17Cu);
    if( v10 )
    {
        TRIBE_Master_Building_Object::TRIBE_Master_Building_Object(v10, infile, sprites, sounds, 1);
        v7->master_objects[index] = v11;
    }
    else
    {
        v7->master_objects[index] = 0;
    }
}

//----- (00512BF0) --------------------------------------------------------
void TRIBE_Player::tech_cost(short tech_id, short *inv_1, short *inv_amt_1, short *inv_2, short *inv_amt_2, short *inv_3, short *inv_amt_3)
{
    TRIBE_Player_Tech::tech_cost(this->tech_tree, tech_id, inv_1, inv_amt_1, inv_2, inv_amt_2, inv_3, inv_amt_3);
}

//----- (00512C30) --------------------------------------------------------
void TRIBE_Player::obj_cost(short obj_id, char **name, short *inv_1, short *inv_amt_1, short *inv_2, short *inv_amt_2, short *inv_3, short *inv_amt_3, float modifier)
{
    short *v10; // ebp@1
    TRIBE_Player *v11; // edi@1
    char *v12; // ebx@1
    char v13; // al@1
    int v14; // edx@1
    RGE_Master_Static_Object *v15; // esi@1
    short v16; // ax@6
    float *v17; // ecx@7
    signed __int64 v18; // rax@9
    short v19; // ax@12
    float *v20; // ecx@13
    signed __int64 v21; // rax@15
    short v22; // ax@18
    short v23; // si@19
    float *v24; // ecx@19
    signed __int64 v25; // rax@21
    short *v26; // eax@30
    char obj_ida; // [sp+14h] [bp+4h]@1

    v10 = inv_3;
    v11 = this;
    v12 = 0;
    *inv_1 = -1;
    *inv_amt_1 = 0;
    *inv_2 = -1;
    *inv_amt_2 = 0;
    *inv_3 = -1;
    *inv_amt_3 = 0;
    v13 = TRIBE_Player::check_obj_cost(this, obj_id, 0, 1.0, 0);
    v14 = obj_id;
    obj_ida = v13;
    v15 = v11->master_objects[v14];
    if( !v15 || v15->master_type < 0x46u )
        return;
    if( name )
        *name = v15->name;
    if( LOBYTE(v15[1].damage_sprites) )
    {
        v16 = *(_WORD *)&v15[1].map_color;
        *inv_1 = v16;
        if( v16 >= 0 )
        {
            LOWORD(v10) = (signed __int64)((double)*(_WORD *)&v15[1].convert_terrain_flag * modifier);
            *inv_amt_1 = (signed short)v10;
            v17 = &v11->attributes[*inv_1];
            if( (double)(signed short)v10 > *v17 && obj_ida )
            {
                v18 = (signed __int64)*v17;
                v12 = (char *)v10 - v18;
                *inv_amt_1 = v18;
            }
            v10 = inv_3;
        }
    }
    if( BYTE2(v15[1].help_string_id) )
    {
        v19 = HIWORD(v15[1].damage_sprites);
        *inv_2 = v19;
        if( v19 >= 0 )
        {
            LOWORD(v10) = (signed __int64)((double)LOWORD(v15[1].help_string_id) * modifier);
            *inv_amt_2 = (signed short)v10;
            v20 = &v11->attributes[*inv_2];
            if( (double)(signed short)v10 > *v20 && obj_ida )
            {
                v21 = (signed __int64)*v20;
                v12 = &v12[(_DWORD)((_DWORD)v10 - v21)];
                *inv_amt_2 = v21;
            }
            v10 = inv_3;
        }
    }
    if( LOBYTE(v15[1].hotkey_id) )
    {
        v22 = v15[1].help_page_id;
        *v10 = v22;
        if( v22 >= 0 )
        {
            v23 = (signed __int64)((double)HIWORD(v15[1].help_page_id) * modifier);
            *inv_amt_3 = v23;
            v24 = &v11->attributes[*v10];
            if( (double)v23 > *v24 )
            {
                if( obj_ida )
                {
                    v25 = (signed __int64)*v24;
                    LOWORD(v12) = v23 - v25 + (_WORD)v12;
                    *inv_amt_3 = v25;
                }
            }
        }
    }
    if( (signed short)v12 > 0 )
    {
        if( *inv_1 == 3 || *inv_1 == -1 )
        {
            v26 = inv_amt_1;
            *inv_1 = 3;
        }
        else
        {
            if( *inv_2 != 3 && *inv_2 != -1 )
            {
                if( *v10 == 3 || *v10 == -1 )
                {
                    *v10 = 3;
                    *inv_amt_3 = (signed short)v12;
                }
                goto LABEL_33;
            }
            v26 = inv_amt_2;
            *inv_2 = 3;
        }
        *v26 += (signed short)v12;
    }
LABEL_33:
    if( *inv_amt_1 <= 0 )
        *inv_1 = -1;
    if( *inv_amt_2 <= 0 )
        *inv_2 = -1;
    if( *inv_amt_3 <= 0 )
        *v10 = -1;
}

//----- (00512EC0) --------------------------------------------------------
RGE_Static_Object *TRIBE_Player::find_obj(short obj_id, RGE_Static_Object *after_obj)
{
    signed int v3; // esi@2
    RGE_Object_Node *i; // edx@2
    RGE_Static_Object *v5; // eax@3
    RGE_Object_Node *v6; // ecx@11
    RGE_Static_Object *v7; // eax@12
    RGE_Static_Object *result; // eax@16

    if( after_obj )
    {
        v3 = 0;
        for( i = this->objects->list; i; i = i->next )
        {
            v5 = i->node;
            if( i->node )
            {
                if( v3 )
                {
                    if( v5->master_obj->id == obj_id && v5->object_state <= 2u )
                        return i->node;
                }
                else if( v5 == after_obj )
                {
                    v3 = 1;
                }
            }
        }
    }
    v6 = this->objects->list;
    if( v6 )
    {
        while( 1 )
        {
            v7 = v6->node;
            if( v6->node )
            {
                if( v7->master_obj->id == obj_id && v7->object_state == 2 )
                    break;
            }
            v6 = v6->next;
            if( !v6 )
                return 0;
        }
        result = v6->node;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00512F60) --------------------------------------------------------
RGE_Static_Object *TRIBE_Player::make_new_object(int obj_id, float x, float y, float z, int build_all_the_way)
{
    TRIBE_Player *v6; // edi@1
    RGE_Static_Object *v7; // esi@1
    short v8; // ax@6

    v6 = this;
    v7 = RGE_Player::make_new_object((RGE_Player *)&this->vfptr, obj_id, x, y, z, build_all_the_way);
    if( v7 )
    {
        if( build_all_the_way )
        {
            TRIBE_World::check_destructables((TRIBE_World *)v6->world, v6->id, obj_id, x, y, 0);
            if( v7->master_obj->master_type == 80 )
                TRIBE_Building_Object::build((TRIBE_Building_Object *)v7, 10000.0);
        }
        if( rge_base_game->prog_mode == 7 )
        {
            v8 = v7->master_obj->object_group;
            if( v8 == 5 || v8 == 33 )
                ((void (__stdcall *)(RGE_Sprite *, signed int))v7->sprite_list->vfptr->set_frame)(v7->sprite, 5);
        }
    }
    return v7;
}

//----- (00513000) --------------------------------------------------------
void TRIBE_Player::interface_tech_avail(Item_Avail **list, short *list_num, short obj_cat)
{
    TRIBE_Player *v4; // ebp@1
    short v5; // bx@1
    Tech_Tree **v6; // ecx@1
    TRIBE_Player_Tech *v7; // eax@1
    int v8; // edx@1
    Tech_Tree *v9; // esi@1
    short *v10; // ecx@2
    short *v11; // eax@2
    Item_Avail **v12; // edi@7
    TRIBE_Player_Tech *v13; // ecx@10
    short v14; // bx@10
    bool v15; // zf@10
    bool v16; // sf@10
    int v17; // eax@12
    int v18; // esi@13
    Item_Avail *v19; // eax@13
    Item_Avail *v20; // ecx@13
    Item_Avail *v21; // edx@13
    short inv_amt_1; // [sp+12h] [bp-12h]@13
    short inv_2; // [sp+14h] [bp-10h]@13
    short inv_amt_2; // [sp+16h] [bp-Eh]@13
    short inv_3; // [sp+18h] [bp-Ch]@13
    short inv_amt_3; // [sp+1Ah] [bp-Ah]@13
    int v27; // [sp+1Ch] [bp-8h]@13
    Tech_Tree *base_tech; // [sp+20h] [bp-4h]@1

    v4 = this;
    v5 = 0;
    v6 = (Tech_Tree **)this->world[1].vfptr;
    v7 = v4->tech_tree;
    LOWORD(v8) = v7->tech_player_tree_num;
    v9 = *v6;
    base_tech = *v6;
    if( (signed short)v8 > 0 )
    {
        v10 = &v9->build_obj_id;
        v11 = &v7->tech_player_tree->state;
        v8 = (signed short)v8;
        do
        {
            if( *v11 == 1 && *v10 == obj_cat )
                ++v5;
            v11 += 4;
            v10 += 30;
            --v8;
        }
        while( v8 );
    }
    v12 = list;
    if( *list )
    {
        free(*list);
        *v12 = 0;
    }
    *list_num = v5;
    if( v5 )
    {
        *v12 = (Item_Avail *)calloc(v5, 0x28u);
        v13 = v4->tech_tree;
        v14 = 0;
        v15 = v13->tech_player_tree_num == 0;
        v16 = v13->tech_player_tree_num < 0;
        list_num = 0;
        if( !v16 && !v15 )
        {
            do
            {
                if( v13->tech_player_tree[v14].state == 1 )
                {
                    v17 = (int)&v9[v14];
                    if( v9[v14].build_obj_id == obj_cat )
                    {
                        v18 = (signed short)list_num;
                        (*v12)[v18].id = v14;
                        (*v12)[v18].pict = *(_WORD *)(v17 + 36);
                        (*v12)[v18].name = *(char **)v17;
                        TRIBE_Player_Tech::tech_cost(
                            v4->tech_tree,
                            v14,
                            (short *)&list,
                            &inv_amt_1,
                            &inv_2,
                            &inv_amt_2,
                            &inv_3,
                            &inv_amt_3);
                        (*v12)[v18].inventory_item_1 = (signed short)list;
                        v19 = *v12;
                        v27 = inv_amt_1;
                        v19[v18].inventory_cost_1 = (double)inv_amt_1;
                        (*v12)[v18].inventory_item_2 = inv_2;
                        v20 = *v12;
                        v27 = inv_amt_2;
                        v20[v18].inventory_cost_2 = (double)inv_amt_2;
                        (*v12)[v18].inventory_item_3 = inv_3;
                        v21 = *v12;
                        v27 = inv_amt_3;
                        v21[v18].inventory_cost_3 = (double)inv_amt_3;
                        (*v12)[v18].help_string_id = TRIBE_Player_Tech::get_help_message(v4->tech_tree, v14);
                        (*v12)[v18].help_page_id = TRIBE_Player_Tech::get_help_page(v4->tech_tree, v14);
                        v9 = base_tech;
                        list_num = (short *)((char *)list_num + 1);
                    }
                }
                v13 = v4->tech_tree;
                ++v14;
            }
            while( v14 < v13->tech_player_tree_num );
        }
    }
}

//----- (005131C0) --------------------------------------------------------
void TRIBE_Player::interface_item_avail(Item_Avail **list, short *list_num, short obj_cat)
{
    TRIBE_Player *v4; // ebp@1
    short v5; // bx@1
    short v6; // si@1
    short v7; // ax@1
    RGE_Master_Static_Object **v8; // ecx@2
    int v9; // edx@2
    RGE_Master_Static_Object *v10; // eax@3
    RGE_Object_List *v11; // eax@12
    RGE_Object_Node *i; // eax@12
    Item_Avail **v13; // edi@18
    short v14; // dx@21
    int v15; // eax@21
    bool v16; // zf@21
    bool v17; // sf@21
    int v18; // ebx@22
    RGE_Master_Static_Object *v19; // ecx@22
    int v20; // esi@26
    Item_Avail *v21; // eax@26
    Item_Avail *v22; // ecx@26
    Item_Avail *v23; // edx@26
    short *v24; // eax@26
    unsigned __int8 v25; // of@27
    int v26; // esi@30
    Item_Avail *v27; // edx@30
    Item_Avail *v28; // eax@30
    Item_Avail *v29; // ecx@30
    short inv_amt_1; // [sp+12h] [bp-16h]@26
    short inv_2; // [sp+14h] [bp-14h]@26
    short inv_amt_2; // [sp+16h] [bp-12h]@26
    short inv_3; // [sp+18h] [bp-10h]@26
    short inv_amt_3; // [sp+1Ah] [bp-Eh]@26
    int tribe_flag; // [sp+1Ch] [bp-Ch]@1
    int index; // [sp+20h] [bp-8h]@21
    int v37; // [sp+24h] [bp-4h]@26

    v4 = this;
    v5 = 0;
    v6 = 0;
    v7 = this->master_object_num;
    tribe_flag = 0;
    if( v7 > 0 )
    {
        v8 = this->master_objects;
        v9 = v7;
        do
        {
            v10 = *v8;
            if( *v8 && v10->master_type >= 0x46u && v10->available && *(_WORD *)&v10[1].recyclable == obj_cat )
                ++v6;
            ++v8;
            --v9;
        }
        while( v9 );
    }
    if( obj_cat == 118 && v4->attributes[48] == 0.0 && !*(_BYTE *)(*((_DWORD *)v4->master_objects + 109) + 82) )
    {
        v11 = v4->objects;
        tribe_flag = 1;
        for( i = v11->list; i; i = i->next )
        {
            if( i->node->master_obj->id == 109 )
                tribe_flag = 0;
        }
    }
    if( (_WORD)tribe_flag )
        ++v6;
    v13 = list;
    if( *list )
    {
        free(*list);
        *v13 = 0;
    }
    *list_num = v6;
    if( v6 )
    {
        *v13 = (Item_Avail *)calloc(v6, 0x28u);
        v14 = 0;
        v15 = 0;
        v16 = v4->master_object_num == 0;
        v17 = v4->master_object_num < 0;
        list_num = 0;
        index = 0;
        if( !v17 && !v16 )
        {
            do
            {
                v18 = (signed short)v15;
                v19 = v4->master_objects[v18];
                if( v19 && v19->master_type >= 0x46u && v19->available && *(_WORD *)&v19[1].recyclable == obj_cat )
                {
                    v20 = v14;
                    (*v13)[v20].id = v15;
                    (*v13)[v20].pict = v4->master_objects[v18]->button_pict;
                    (*v13)[v20].name = v4->master_objects[v18]->name;
                    TRIBE_Player::obj_cost(v4, v15, 0, (short *)&list, &inv_amt_1, &inv_2, &inv_amt_2, &inv_3, &inv_amt_3, 1.0);
                    (*v13)[v20].inventory_item_1 = (signed short)list;
                    v21 = *v13;
                    v37 = inv_amt_1;
                    v21[v20].inventory_cost_1 = (double)inv_amt_1;
                    (*v13)[v20].inventory_item_2 = inv_2;
                    v22 = *v13;
                    v37 = inv_amt_2;
                    v22[v20].inventory_cost_2 = (double)inv_amt_2;
                    (*v13)[v20].inventory_item_3 = inv_3;
                    v23 = *v13;
                    v37 = inv_amt_3;
                    v23[v20].inventory_cost_3 = (double)inv_amt_3;
                    (*v13)[v20].help_string_id = RGE_Master_Static_Object::get_help_message(v4->master_objects[v18]);
                    (*v13)[v20].help_page_id = RGE_Master_Static_Object::get_help_page(v4->master_objects[v18]);
                    v24 = (short *)((char *)list_num + 1);
                    list_num = v24;
                    v14 = (signed short)v24;
                    v15 = index;
                }
                v25 = __OFSUB__((_WORD)++v15, v4->master_object_num);
                v17 = (signed short)(v15 - v4->master_object_num) < 0;
                index = v15;
            }
            while( v17 ^ v25 );
            v5 = 0;
        }
        if( (_WORD)tribe_flag != v5 )
        {
            v26 = v14;
            (*v13)[v26].id = 109;
            (*v13)[v26].pict = *(_WORD *)(*((_DWORD *)v4->master_objects + 109) + 76);
            (*v13)[v26].name = *(char **)(*((_DWORD *)v4->master_objects + 109) + 8);
            TRIBE_Player::obj_cost(v4, 109, 0, (short *)&list, &inv_amt_1, &inv_2, &inv_amt_2, &inv_3, &inv_amt_3, 1.0);
            (*v13)[v26].inventory_item_1 = (signed short)list;
            v27 = *v13;
            *(_DWORD *)&obj_cat = inv_amt_1;
            v27[v26].inventory_cost_1 = (double)inv_amt_1;
            (*v13)[v26].inventory_item_2 = inv_2;
            v28 = *v13;
            *(_DWORD *)&obj_cat = inv_amt_2;
            v28[v26].inventory_cost_2 = (double)inv_amt_2;
            (*v13)[v26].inventory_item_3 = inv_3;
            v29 = *v13;
            *(_DWORD *)&obj_cat = inv_amt_3;
            v29[v26].inventory_cost_3 = (double)inv_amt_3;
            (*v13)[v26].help_string_id = RGE_Master_Static_Object::get_help_message(v4->master_objects[109]);
            (*v13)[v26].help_page_id = RGE_Master_Static_Object::get_help_page(v4->master_objects[109]);
        }
    }
}

//----- (005134F0) --------------------------------------------------------
void TRIBE_Player::interface_trade_avail(Trade_Avail **list, short *list_num)
{
    RGE_Game_World *v3; // eax@1
    signed int v4; // edx@1
    signed int v5; // ebp@1
    RGE_Object_Node *v6; // esi@3
    RGE_Static_Object **v7; // ebx@4
    Trade_Avail *v8; // eax@14
    RGE_Static_Object **v9; // edx@15
    signed int v10; // esi@15
    RGE_Static_Object *v11; // ecx@16
    RGE_Player *v12; // edi@16
    int i; // [sp+10h] [bp-188h]@1
    TRIBE_Player *v14; // [sp+14h] [bp-184h]@1
    RGE_Static_Object *dock_list[96]; // [sp+18h] [bp-180h]@4

    v3 = this->world;
    v4 = 1;
    v5 = 0;
    v14 = this;
    for( i = 1; v4 < v3->player_num; i = ++v4 )
    {
        if( v4 != this->id )
        {
            v6 = v3->players[v4]->objects->list;
            if( v6 )
            {
                v7 = &dock_list[v5];
                do
                {
                    if( v6->node->master_obj->id == 45
                        && RGE_Visible_Map::get_visible(
                                 v14->visible,
                                 (signed short)(signed __int64)v6->node->world_x,
                                 (signed short)(signed __int64)v6->node->world_y) )
                    {
                        ++v5;
                        *v7 = v6->node;
                        ++v7;
                    }
                    v6 = v6->next;
                }
                while( v6 );
                v4 = i;
                this = v14;
            }
        }
        v3 = this->world;
    }
    if( *list )
    {
        free(*list);
        *list = 0;
    }
    *list_num = v5;
    if( v5 )
    {
        v8 = (Trade_Avail *)calloc(v5, 0xCu);
        *list = v8;
        if( v5 > 0 )
        {
            v9 = dock_list;
            v10 = v5;
            do
            {
                v11 = *v9;
                ++v8;
                ++v9;
                --v10;
                v12 = v11->owner;
                v8[-1].dock = v11;
                v8[-1].player = v12;
                v8[-1].inventory = v11->attribute_amount_held;
            }
            while( v10 );
        }
    }
}

//----- (00513600) --------------------------------------------------------
char TRIBE_Player::command_make_building(short obj_id, float x, float y)
{
    short v4; // di@1
    TRIBE_Player *v5; // esi@1
    RGE_Master_Static_Object *v6; // eax@1
    char result; // al@5
    int list_num; // [sp+8h] [bp-4h]@4

    v4 = obj_id;
    v5 = this;
    v6 = this->master_objects[obj_id];
    if( v6
        && (v6->available || obj_id == 109)
        && RGE_Player::get_selected_objects_to_command(
                 (RGE_Player *)&this->vfptr,
                 (RGE_Static_Object ***)&obj_id,
                 (short *)&list_num,
                 4,
                 4,
                 -1,
                 -1) )
    {
        (*(void (**)(void))(**((_DWORD **)v5->master_objects + 118) + 44))();
        TRIBE_Command::command_build((TRIBE_Command *)v5->world->commands, (RGE_Static_Object **)obj_id, list_num, v4, x, y);
        free((void *)obj_id);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00513690) --------------------------------------------------------
char TRIBE_Player::command_make_wall(short obj_id, int x1, int y1, int x2, int y2)
{
    short v6; // di@1
    TRIBE_Player *v7; // esi@1
    RGE_Master_Static_Object *v8; // eax@1
    char result; // al@4
    int list_num; // [sp+8h] [bp-4h]@3

    v6 = obj_id;
    v7 = this;
    v8 = this->master_objects[obj_id];
    if( v8
        && v8->available
        && RGE_Player::get_selected_objects_to_command(
                 (RGE_Player *)&this->vfptr,
                 (RGE_Static_Object ***)&obj_id,
                 (short *)&list_num,
                 4,
                 4,
                 -1,
                 -1) )
    {
        (*(void (**)(void))(**((_DWORD **)v7->master_objects + 118) + 44))();
        TRIBE_Command::command_build_wall(
            (TRIBE_Command *)v7->world->commands,
            (RGE_Static_Object **)obj_id,
            list_num,
            v6,
            x1,
            y1,
            x2,
            y2);
        free((void *)obj_id);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00513720) --------------------------------------------------------
char TRIBE_Player::command_building_make_tech(short tech_id)
{
    RGE_Static_Object *v2; // eax@1
    char result; // al@3

    v2 = this->selected_obj;
    if( v2 && v2->master_obj->master_type == 80 )
    {
        TRIBE_Command::command_research((TRIBE_Command *)this->world->commands, v2, tech_id);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00513750) --------------------------------------------------------
char TRIBE_Player::command_building_cancel()
{
    RGE_Static_Object *v1; // eax@1
    RGE_Master_Static_Object *v2; // edx@3
    char v3; // bl@3
    char result; // al@6

    v1 = this->selected_obj;
    if( v1
        && (TRIBE_Player *)v1->owner == this
        && ((v2 = v1->master_obj, v3 = v2->master_type, v3 == 80) || v3 == 70)
        && v2->object_group != 1 )
    {
        TRIBE_Command::command_cancel_build((TRIBE_Command *)this->world->commands, this->selected_obj);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00513790) --------------------------------------------------------
char TRIBE_Player::command_delete_object(RGE_Static_Object *obj)
{
    char v2; // dl@3
    char result; // al@5

    if( obj && (TRIBE_Player *)obj->owner == this && ((v2 = obj->master_obj->master_type, v2 == 80) || v2 == 70) )
    {
        TRIBE_Command::command_cancel_build((TRIBE_Command *)this->world->commands, obj);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (005137D0) --------------------------------------------------------
char TRIBE_Player::command_trade_attribute(int attribute)
{
    TRIBE_Player *v2; // esi@1
    char result; // al@2
    RGE_Static_Object **list; // [sp+4h] [bp-8h]@1
    int list_num; // [sp+8h] [bp-4h]@1

    v2 = this;
    if( RGE_Player::get_selected_objects_to_command(
                 (RGE_Player *)&this->vfptr,
                 &list,
                 (short *)&list_num,
                 4,
                 -1,
                 -1,
                 5) )
    {
        ((void (*)(void))(*list)->vfptr->play_command_sound)();
        TRIBE_Command::command_trade_attribute((TRIBE_Command *)v2->world->commands, list, list_num, attribute);
        free(list);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00513840) --------------------------------------------------------
char TRIBE_Player::command_trade_attribute(int unitID, int attribute)
{
    TRIBE_Command::command_trade_attribute((TRIBE_Command *)this->world->commands, unitID, this->id, attribute);
    return 1;
}

//----- (00513860) --------------------------------------------------------
char TRIBE_Player::command_attack_ground(float x, float y)
{
    TRIBE_Player *v3; // esi@1
    char result; // al@2
    RGE_Static_Object **list; // [sp+4h] [bp-8h]@1
    int list_num; // [sp+8h] [bp-4h]@1

    v3 = this;
    if( RGE_Player::get_selected_objects_to_command(
                 (RGE_Player *)&this->vfptr,
                 &list,
                 (short *)&list_num,
                 4,
                 -1,
                 -1,
                 4) )
    {
        ((void (*)(void))(*list)->vfptr->play_command_sound)();
        TRIBE_Command::command_attack_ground((TRIBE_Command *)v3->world->commands, list, list_num, x, y);
        free(list);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (005138D0) --------------------------------------------------------
char TRIBE_Player::command_give_attribute(int to_player_id, int attr_id, float attr_amount, float attr_cost)
{
    char result; // al@3

    if( attr_id == -1 || attr_amount == 0.0 )
    {
        result = 0;
    }
    else
    {
        ((void (__thiscall *)(RGE_Command *, _DWORD, int, int, _DWORD, _DWORD))this->world->commands->vfptr[1].~RGE_Command)(
            this->world->commands,
            this->id,
            to_player_id,
            attr_id,
            LODWORD(attr_amount),
            LODWORD(attr_cost));
        result = 1;
    }
    return result;
}

//----- (00513920) --------------------------------------------------------
char TRIBE_Player::command_building_make_obj(short obj_id)
{
    RGE_Static_Object *v2; // eax@1
    char result; // al@3

    v2 = this->selected_obj;
    if( v2 && v2->master_obj->master_type == 80 )
    {
        TRIBE_Command::command_make((TRIBE_Command *)this->world->commands, v2, obj_id);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00513950) --------------------------------------------------------
char TRIBE_Player::command_make_repair(RGE_Static_Object *obj)
{
    RGE_Static_Object *v2; // esi@1
    TRIBE_Player *v3; // edi@1
    TRIBE_Player *v4; // eax@1
    RGE_Master_Static_Object *v5; // eax@3
    TRIBE_Player *v6; // eax@6
    RGE_Master_Static_Object *v7; // ecx@9
    short v8; // ax@9
    int v9; // eax@16
    char result; // al@18
    int list_num; // [sp+1Ch] [bp-4h]@15

    v2 = obj;
    v3 = this;
    v4 = (TRIBE_Player *)obj->owner;
    if( ((v4 == this || (*(int (__stdcall **)(_DWORD))&this->vfptr->gap4[24])(v4->id))
         && (v5 = v2->master_obj, v5->master_type == 80)
         && (double)v5->hp > v2->hp
         && v2->object_state < 3u
         || ((v6 = (TRIBE_Player *)v2->owner, v6 == v3)
            || (*(int (__thiscall **)(TRIBE_Player *, _DWORD))&v3->vfptr->gap4[24])(v3, v6->id)
            && (*(int (__stdcall **)(_DWORD))&v2->owner->vfptr->gap4[24])(v3->id))
         && ((v7 = v2->master_obj, v8 = v7->object_group, v8 == 2) || v8 == 20 || v8 == 21 || v8 == 22)
         && (double)v7->hp > v2->hp
         && v2->object_state < 3u)
        && RGE_Player::get_selected_objects_to_command(
                 (RGE_Player *)&v3->vfptr,
                 (RGE_Static_Object ***)&obj,
                 (short *)&list_num,
                 4,
                 4,
                 -1,
                 -1) )
    {
        v9 = (*((int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD))obj->vfptr->__vecDelDtor + 47))(v2, 0, 0, 0);
        if( v9 )
            (*(void (__thiscall **)(int))(*(_DWORD *)v9 + 44))(v9);
        TRIBE_Command::command_repair((TRIBE_Command *)v3->world->commands, (RGE_Static_Object **)obj, list_num, v2);
        free(obj);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00513A80) --------------------------------------------------------
char TRIBE_Player::command_make_unload(float x, float y)
{
    TRIBE_Player *v3; // esi@1
    char result; // al@2
    RGE_Static_Object **list; // [sp+4h] [bp-8h]@1
    int list_num; // [sp+8h] [bp-4h]@1

    v3 = this;
    if( RGE_Player::get_selected_objects_to_command(
                 (RGE_Player *)&this->vfptr,
                 &list,
                 (short *)&list_num,
                 4,
                 -1,
                 -1,
                 7) )
    {
        ((void (*)(void))(*list)->vfptr->play_command_sound)();
        TRIBE_Command::command_unload((TRIBE_Command *)v3->world->commands, list, list_num, x, y);
        free(list);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00513AF0) --------------------------------------------------------
char TRIBE_Player::check_obj_cost(short obj_id, short *attribute_needed, float modifier, int ignore_pop)
{
    short *v5; // ebx@1
    double v6; // st7@1
    float *v7; // esi@3
    RGE_Master_Static_Object *v8; // eax@6
    signed int v9; // edi@8
    int v10; // edx@8
    int v11; // ecx@9
    float obj_ida; // [sp+14h] [bp+4h]@10
    char inventory_cost; // [sp+18h] [bp+8h]@4

    v5 = attribute_needed;
    v6 = this->attributes[3];
    if( attribute_needed )
        *attribute_needed = -1;
    v7 = this->attributes;
    if( v7[29] >= 1.0 )
    {
        inventory_cost = 1;
    }
    else
    {
        v6 = 0.0;
        inventory_cost = 0;
    }
    v8 = this->master_objects[obj_id];
    if( v8 && v8->master_type >= 0x46u )
    {
        v9 = 0;
        v10 = (int)&v8[1].convert_terrain_flag;
        while( 1 )
        {
            v11 = *(_WORD *)(v10 - 2);
            if( v11 >= 0 )
            {
                obj_ida = (double)*(_WORD *)v10 * modifier;
                if( v11 == 4 && !ignore_pop && v7[11] >= (double)v7[32] )
                {
                    if( !v5 )
                        return 0;
                    *v5 = 32;
                    return 0;
                }
                if( inventory_cost )
                {
                    if( v11 == 3 )
                    {
                        v6 = v6 - obj_ida;
                        if( v6 < 0.0 )
                        {
                            if( !v5 )
                                return 0;
                            *v5 = 3;
                            return 0;
                        }
                    }
                }
                if( v7[v11] < (double)obj_ida && (v11 != 4 || !ignore_pop) )
                {
                    if( !*(_BYTE *)(v10 + 2) || v6 + v7[v11] < obj_ida )
                    {
                        if( !v5 )
                            return 0;
                        *v5 = v11;
                        return 0;
                    }
                    v6 = v6 - (obj_ida - v7[v11]);
                }
            }
            ++v9;
            v10 += 6;
            if( v9 >= 3 )
                return 1;
        }
    }
    if( v5 )
        *v5 = -1;
    return 0;
}

char TRIBE_Player::pay_obj_cost(short obj_id, float modifier, int ignore_pop)
{
    TRIBE_Player *v4; // edi@1
    signed int v5; // ebx@2
    RGE_Damage_Sprite_Info **v6; // esi@2
    int v7; // eax@3
    float *v8; // ecx@7
    int v9; // edx@7
    double v10; // st7@7
    char result; // al@11

    v4 = this;
    if( TRIBE_Player::check_obj_cost(this, obj_id, 0, modifier, ignore_pop) )
    {
        v5 = 3;
        v6 = &v4->master_objects[obj_id][1].damage_sprites;
        do
        {
            v7 = *((_WORD *)v6 - 2);
            if( v7 >= 0 && *(_BYTE *)v6 && (!ignore_pop || v7 != 4) )
            {
                v8 = v4->attributes;
                v9 = v7;
                v10 = (double)*((_WORD *)v6 - 1) * modifier;
                if( v10 <= v8[v7] )
                {
                    v8[v9] = v8[v9] - v10;
                }
                else
                {
                    v8[3] = v8[3] - (v10 - v8[v9]);
                    LODWORD(v4->attributes[v9]) = 0;
                }
            }
            v6 = (RGE_Damage_Sprite_Info **)((char *)v6 + 6);
            --v5;
        }
        while( v5 );
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00513D00) --------------------------------------------------------
void TRIBE_Player::reimburse_obj_cost(short obj_id)
{
    RGE_Master_Static_Object *v2; // eax@1
    int v3; // eax@2
    signed int v4; // esi@2
    float *v5; // edx@5

    v2 = this->master_objects[obj_id];
    if( v2->master_type >= 0x46u )
    {
        v3 = (int)&v2[1].map_color;
        v4 = 3;
        do
        {
            if( *(_WORD *)v3 >= 0 )
            {
                if( *(_BYTE *)(v3 + 4) )
                {
                    v5 = &this->attributes[*(_WORD *)v3];
                    *v5 = (double)*(_WORD *)(v3 + 2) + *v5;
                }
            }
            v3 += 6;
            --v4;
        }
        while( v4 );
    }
}

//----- (00513D60) --------------------------------------------------------
char TRIBE_Player::check_tech_cost(short tech_id, short *attribute_needed)
{
    return TRIBE_Player_Tech::check_tech_cost(this->tech_tree, tech_id, attribute_needed);
}

//----- (00513D80) --------------------------------------------------------
char TRIBE_Player::pay_tech_cost(short tech_id)
{
    return TRIBE_Player_Tech::start_research(this->tech_tree, tech_id, 1u, 0);
}

//----- (00513DA0) --------------------------------------------------------
void TRIBE_Player::tech_abling(int tech_id, char able_flag)
{
    if( able_flag )
        TRIBE_Player_Tech::enable(this->tech_tree, tech_id);
    else
        TRIBE_Player_Tech::disable(this->tech_tree, tech_id);
}

//----- (00513DD0) --------------------------------------------------------
void TRIBE_Player::rev_tech(int age)
{
    TRIBE_Player *v2; // esi@1
    double v3; // st7@2

    v2 = this;
    switch ( age )
    {
        case 25:
            v3 = this->attributes[25];
            goto LABEL_5;
        case 23:
            TRIBE_Player_Tech::disable(this->tech_tree, (signed __int64)this->attributes[23]);
            TRIBE_Player_Tech::rev_tech(v2->tech_tree, (signed __int64)v2->attributes[25]);
            TRIBE_Player_Tech::enable(v2->tech_tree, (signed __int64)v2->attributes[23]);
            v3 = v2->attributes[23];
            goto LABEL_5;
        case 24:
            TRIBE_Player_Tech::disable(this->tech_tree, (signed __int64)this->attributes[23]);
            TRIBE_Player_Tech::disable(v2->tech_tree, (signed __int64)v2->attributes[24]);
            TRIBE_Player_Tech::rev_tech(v2->tech_tree, (signed __int64)v2->attributes[25]);
            TRIBE_Player_Tech::enable(v2->tech_tree, (signed __int64)v2->attributes[23]);
            TRIBE_Player_Tech::rev_tech(v2->tech_tree, (signed __int64)v2->attributes[23]);
            TRIBE_Player_Tech::enable(v2->tech_tree, (signed __int64)v2->attributes[24]);
            v3 = v2->attributes[24];
LABEL_5:
            TRIBE_Player_Tech::do_tech(v2->tech_tree, (signed __int64)v3);
            break;
        case 1:
            TRIBE_Player_Tech::disable(this->tech_tree, (signed __int64)this->attributes[23]);
            TRIBE_Player_Tech::disable(v2->tech_tree, (signed __int64)v2->attributes[24]);
            TRIBE_Player_Tech::rev_tech(v2->tech_tree, (signed __int64)v2->attributes[25]);
            TRIBE_Player_Tech::enable(v2->tech_tree, (signed __int64)v2->attributes[23]);
            TRIBE_Player_Tech::rev_tech(v2->tech_tree, (signed __int64)v2->attributes[23]);
            TRIBE_Player_Tech::enable(v2->tech_tree, (signed __int64)v2->attributes[24]);
            TRIBE_Player_Tech::rev_tech(v2->tech_tree, (signed __int64)v2->attributes[24]);
            break;
        default:
            return;
    }
}

//----- (00513FD0) --------------------------------------------------------
void TRIBE_Player::add_population_entry()
{
    TRIBE_Player *v1; // esi@1
    float *v2; // ecx@1

    v1 = this;
    v2 = this->attributes;
    if( v2[11] >= 0.0 )
        TRIBE_History_Info::add_history_entry(v1->history, 0, (signed __int64)v2[11]);
    else
        TRIBE_History_Info::add_history_entry(v1->history, 0, 0);
}

//----- (00514010) --------------------------------------------------------
void TRIBE_Player::random_start()
{
    TRIBE_Player *v1; // esi@1
    RGE_Object_List *v2; // ecx@1
    int v3; // ecx@2
    unsigned int v4; // edx@2
    signed int v5; // edi@2
    int v6; // ecx@2
    unsigned int v7; // edx@2
    float v8; // ST2C_4@3
    float v9; // ST28_4@3
    int v10; // ecx@4
    unsigned int v11; // edx@4
    int v12; // ecx@4
    unsigned int v13; // edx@4
    TRIBE_Building_Object *v14; // ebp@6
    char v15; // bl@7
    int v16; // eax@8
    unsigned int v17; // eax@8
    int v18; // ST6C_4@8
    int v19; // eax@8
    float v20; // ST68_4@8
    unsigned int v21; // eax@8
    int v22; // ST74_4@8
    float v23; // ST6C_4@8
    RGE_Map *v24; // ecx@9
    RGE_Static_Object *v25; // edi@17
    signed int v26; // ebx@22
    RGE_Static_Object *v27; // edi@26
    RGE_Static_ObjectVtbl *v28; // ebp@28
    RGE_Game_World *v29; // eax@31
    signed int v30; // ebx@33
    int v31; // edi@35
    int v32; // eax@37
    char found_ally; // [sp+5Fh] [bp-19h]@1
    float h1; // [sp+60h] [bp-18h]@2
    float w1; // [sp+64h] [bp-14h]@2
    float h; // [sp+68h] [bp-10h]@8
    float w; // [sp+6Ch] [bp-Ch]@8
    signed int v38; // [sp+70h] [bp-8h]@6
    int (__thiscall *w2)(TRIBE_Player *, signed int); // [sp+74h] [bp-4h]@23

    v1 = this;
    found_ally = 0;
    v2 = this->objects;
    if( v2->list )
    {
        v25 = RGE_Object_List::find_by_master_id(v2, 109, 0.0, 0.0, 0, 0, 0);
        if( !v25 )
            v25 = v1->objects->list->node;
        RGE_Player::set_map_loc((RGE_Player *)&v1->vfptr, (signed __int64)v25->world_x, (signed __int64)v25->world_y);
        RGE_Player::set_view_loc((RGE_Player *)&v1->vfptr, v25->world_x, v25->world_y);
    }
    else
    {
        v3 = (v1->world->map->map_height - 30) * debug_rand(aCMsdevWorkAg_3, 1585);
        v4 = (signed int)(v3 + ((unsigned __int64)(-2147418109i64 * v3) >> 32)) >> 14;
        h1 = (double)(signed int)(v4 + (v4 >> 31) + 15) - -0.5;
        v5 = 1;
        v6 = (v1->world->map->map_width - 30) * debug_rand(aCMsdevWorkAg_3, 1586);
        v7 = (signed int)(v6 + ((unsigned __int64)(-2147418109i64 * v6) >> 32)) >> 14;
        w1 = (double)(signed int)(v7 + (v7 >> 31) + 15) - -0.5;
        do
        {
            v8 = h1 - -0.5;
            v9 = w1 - -0.5;
            if( !(unsigned __int8)(*(int (__stdcall **)(TRIBE_Player *, _DWORD, _DWORD, _DWORD, _DWORD, signed int, signed int, signed int, signed int, signed int))(**((_DWORD **)v1->master_objects + 109) + 32))(
                                                             v1,
                                                             LODWORD(v9),
                                                             LODWORD(v8),
                                                             0,
                                                             0,
                                                             1,
                                                             1,
                                                             1,
                                                             1,
                                                             1) )
                break;
            v10 = (v1->world->map->map_height - 30) * debug_rand(aCMsdevWorkAg_3, 1585);
            v11 = (signed int)(v10 + ((unsigned __int64)(-2147418109i64 * v10) >> 32)) >> 14;
            h1 = (double)(signed int)(v11 + (v11 >> 31) + 15) - -0.5;
            v12 = (v1->world->map->map_width - 30) * debug_rand(aCMsdevWorkAg_3, 1586);
            v13 = (signed int)(v12 + ((unsigned __int64)(-2147418109i64 * v12) >> 32)) >> 14;
            ++v5;
            w1 = (double)(signed int)(v13 + (v13 >> 31) + 15) - -0.5;
        }
        while( v5 < 5000 );
        if( v5 < 5000 )
        {
            v14 = (TRIBE_Building_Object *)(*(int (__stdcall **)(TRIBE_Player *, float, float, _DWORD))(**((_DWORD **)v1->master_objects + 109)
                                                                                                                                                                                                + 24))(
                                                                             v1,
                                                                             COERCE_FLOAT(LODWORD(w1)),
                                                                             COERCE_FLOAT(LODWORD(h1)),
                                                                             0);
            RGE_Player::set_map_loc((RGE_Player *)&v1->vfptr, (signed __int64)w1, (signed __int64)h1);
            RGE_Player::set_view_loc((RGE_Player *)&v1->vfptr, w1, h1);
            TRIBE_Building_Object::build(v14, 10000.0);
            v38 = 3;
            do
            {
                v15 = 1;
                do
                {
                    v16 = debug_rand(aCMsdevWorkAg_3, 1606);
                    v17 = (signed int)(6 * v16 + ((unsigned __int64)(-12884508654i64 * v16) >> 32)) >> 14;
                    v18 = v17 + (v17 >> 31) - 3;
                    v19 = debug_rand(aCMsdevWorkAg_3, 1607);
                    v20 = (double)v18;
                    v21 = (signed int)(6 * v19 + ((unsigned __int64)(-12884508654i64 * v19) >> 32)) >> 14;
                    v22 = v21 + (v21 >> 31) - 3;
                    h = v20 - (double)debug_rand(aCMsdevWorkAg_3, 1608) * -0.000030518509 + h1;
                    v23 = (double)v22;
                    w = v23 - (double)debug_rand(aCMsdevWorkAg_3, 1609) * -0.000030518509 + w1;
                    if( h >= 0.0 )
                    {
                        v24 = v1->world->map;
                        if( (double)v24->map_height > h
                            && w >= 0.0
                            && (double)v24->map_width > w
                            && !(unsigned __int8)(*(int (__stdcall **)(TRIBE_Player *, float, float, _DWORD, _DWORD, signed int, signed int, signed int, signed int, signed int))(**((_DWORD **)v1->master_objects + 83) + 32))(
                                                                         v1,
                                                                         COERCE_FLOAT(LODWORD(w)),
                                                                         COERCE_FLOAT(LODWORD(h)),
                                                                         0,
                                                                         0,
                                                                         1,
                                                                         1,
                                                                         1,
                                                                         1,
                                                                         1) )
                        {
                            (*(void (__stdcall **)(TRIBE_Player *, float, float, _DWORD))(**((_DWORD **)v1->master_objects + 83) + 24))(
                                v1,
                                COERCE_FLOAT(LODWORD(w)),
                                COERCE_FLOAT(LODWORD(h)),
                                0);
                            v15 = 0;
                        }
                    }
                }
                while( v15 );
                --v38;
            }
            while( v38 );
        }
    }
    if( RGE_Base_Game::multiplayerGame(rge_base_game) || RGE_Base_Game::randomGame(rge_base_game) )
    {
        v26 = 1;
        if( v1->world->player_num > 1 )
        {
            w2 = *(int (__thiscall **)(TRIBE_Player *, signed int))&v1->vfptr->gap4[24];
            do
            {
                if( w2(v1, v26) && v26 != v1->id )
                {
                    v27 = RGE_Object_List::find_by_master_id(v1->objects, 109, 0.0, 0.0, 0, 0, 0);
                    if( v27 || (v27 = v1->objects->list->node) != 0 )
                    {
                        v28 = v27->vfptr;
                        v27->vfptr->explore_terrain(v27, v1->world->players[v26], 0, -1);
                        v28->unexplore_terrain(v27, v1->world->players[v26], 0, -1);
                    }
                    ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))v1->world->players[v26]->vfptr->make_new_object)(
                        112,
                        LODWORD(v1->view_x),
                        LODWORD(v1->view_y),
                        0,
                        0);
                    found_ally = 1;
                }
                ++v26;
            }
            while( v26 < v1->world->player_num );
        }
    }
    v29 = v1->world;
    if( v29->curr_player == v1->id )
    {
        if( found_ally )
        {
            v30 = 1;
            if( v29->player_num > 1 )
            {
                do
                {
                    if( v30 != v1->id )
                    {
                        v31 = 1;
                        do
                        {
                            if( RGE_Base_Game::playerID(rge_base_game, v31) == v30 )
                            {
                                v32 = (*(int (__thiscall **)(TRIBE_Player *, signed int))&v1->vfptr->gap4[24])(v1, v30);
                                TChat::setInChatGroup(chat, v31, v32);
                            }
                            ++v31;
                        }
                        while( v31 < 9 );
                    }
                    ++v30;
                }
                while( v30 < v1->world->player_num );
            }
        }
    }
}

//----- (00514510) --------------------------------------------------------
void TRIBE_Player::objectCost(int id, int unused1, ResourceItem *ri, int unused2)
{
    ResourceItem *v5; // esi@1
    short inv_1; // [sp+6h] [bp-Ah]@1
    short inv_amt_2; // [sp+8h] [bp-8h]@1
    short inv_2; // [sp+Ah] [bp-6h]@1
    short inv_amt_3; // [sp+Ch] [bp-4h]@1
    short inv_3; // [sp+Eh] [bp-2h]@1

    TRIBE_Player::obj_cost(this, id, 0, &inv_1, (short *)&id, &inv_2, &inv_amt_2, &inv_3, &inv_amt_3, 1.0);
    v5 = ri;
    ResourceItem::incrementValue(ri, inv_1, (signed short)id);
    ResourceItem::incrementValue(v5, inv_2, inv_amt_2);
    ResourceItem::incrementValue(v5, inv_3, inv_amt_3);
}

//----- (00514590) --------------------------------------------------------
int TRIBE_Player::objectCostByType(int id)
{
    short inv_amt_3; // [sp+2h] [bp-Ah]@1
    short inv_amt_2; // [sp+4h] [bp-8h]@1
    short inv_3; // [sp+6h] [bp-6h]@1
    short inv_2; // [sp+8h] [bp-4h]@1
    short inv_1; // [sp+Ah] [bp-2h]@1

    TRIBE_Player::obj_cost(this, id, 0, &inv_1, (short *)&id, &inv_2, &inv_amt_2, &inv_3, &inv_amt_3, 1.0);
    return inv_amt_2 + inv_amt_3 + (signed short)id;
}

//----- (005145E0) --------------------------------------------------------
void TRIBE_Player::researchCost(int id, int unused1, ResourceItem *ri, int unused2)
{
    ResourceItem *v5; // esi@1
    short inv_1; // [sp+6h] [bp-Ah]@1
    short inv_amt_2; // [sp+8h] [bp-8h]@1
    short inv_2; // [sp+Ah] [bp-6h]@1
    short inv_amt_3; // [sp+Ch] [bp-4h]@1
    short inv_3; // [sp+Eh] [bp-2h]@1

    TRIBE_Player_Tech::tech_cost(this->tech_tree, id, &inv_1, (short *)&id, &inv_2, &inv_amt_2, &inv_3, &inv_amt_3);
    v5 = ri;
    ResourceItem::incrementValue(ri, inv_1, (signed short)id);
    ResourceItem::incrementValue(v5, inv_2, inv_amt_2);
    ResourceItem::incrementValue(v5, inv_3, inv_amt_3);
}

//----- (00514660) --------------------------------------------------------
BOOL TRIBE_Player::objectAvailable(int id)
{
    RGE_Master_Static_Object *v2; // eax@1

    v2 = this->master_objects[id];
    return v2 && v2->available || id == 109;
}

//----- (00514690) --------------------------------------------------------
BOOL TRIBE_Player::researchAvailable(int id)
{
    return this->tech_tree->tech_player_tree[id].state == 1;
}

//----- (005146B0) --------------------------------------------------------
BOOL TRIBE_Player::researchEverAvailable(int id)
{
    short v2; // ax@1

    v2 = TRIBE_Player_Tech::get_tech_state(this->tech_tree, id);
    return v2 != 3 && v2 != -1;
}

//----- (005146E0) --------------------------------------------------------
short TRIBE_Player::researchState(int id)
{
    return TRIBE_Player_Tech::get_tech_state(this->tech_tree, id);
}

//----- (00514720) --------------------------------------------------------
char *TRIBE_Player::aiStatus(int sNum)
{
    TRIBE_Player *v2; // esi@1
    TribeMainDecisionAIModule *v3; // eax@1
    RGE_Game_World *v4; // eax@2
    int v5; // ecx@2
    RGE_Player *v6; // eax@3
    int v7; // eax@4
    RGE_Game_World *v8; // edi@4
    char *v9; // esi@4
    int v10; // ebx@4
    int v11; // ebp@4
    char *v12; // eax@4
    char *result; // eax@4
    int v14; // ST64_4@7
    int v15; // ST60_4@7
    char *v16; // ST5C_4@7
    char *v17; // ST58_4@7
    char *v18; // ST54_4@7
    char *v19; // ST50_4@7
    char *v20; // eax@7
    int v21; // ST64_4@9
    int v22; // eax@9
    TribeMainDecisionAIModule *v23; // ecx@9
    char *v24; // ST60_4@9
    int v25; // ST5C_4@9
    int v26; // eax@9
    TribeMainDecisionAIModule *v27; // ecx@9
    char *v28; // ST58_4@9
    int v29; // ST54_4@9
    int v30; // eax@9
    TribeMainDecisionAIModule *v31; // ecx@9
    char *v32; // ST50_4@9
    int v33; // ST4C_4@9
    int v34; // eax@9
    TribeMainDecisionAIModule *v35; // ecx@9
    char *v36; // ST48_4@9
    int v37; // ST44_4@9
    int v38; // eax@9
    TribeMainDecisionAIModule *v39; // ecx@9
    char *v40; // ST40_4@9
    int v41; // ST3C_4@9
    int v42; // eax@9
    TribeMainDecisionAIModule *v43; // ecx@9
    char *v44; // ST38_4@9
    int v45; // ST34_4@9
    int v46; // eax@9
    TribeMainDecisionAIModule *v47; // ecx@9
    char *v48; // ST30_4@9
    int v49; // ST2C_4@9
    int v50; // eax@9
    TribeMainDecisionAIModule *v51; // ecx@9
    char *v52; // eax@9
    int v53; // ST64_4@11
    int v54; // ST60_4@11
    int v55; // ST5C_4@11
    int v56; // ST58_4@11
    int v57; // ST54_4@11
    int v58; // eax@11
    TribeMainDecisionAIModule *v59; // ecx@11
    char *v60; // ST50_4@11
    int v61; // ST4C_4@11
    int v62; // ST48_4@11
    int v63; // eax@11
    TribeMainDecisionAIModule *v64; // ecx@11
    char *v65; // ST44_4@11
    int v66; // ST40_4@11
    int v67; // ST3C_4@11
    int v68; // eax@11
    TribeMainDecisionAIModule *v69; // ecx@11
    char *v70; // ST38_4@11
    int v71; // ST34_4@11
    int v72; // ST30_4@11
    int v73; // eax@11
    TribeMainDecisionAIModule *v74; // ecx@11
    char *v75; // eax@11
    int v76; // ST64_4@13
    int v77; // ST60_4@13
    int v78; // ST5C_4@13
    int v79; // ST58_4@13
    int v80; // ST54_4@13
    int v81; // ST50_4@13
    int v82; // ST4C_4@13
    int v83; // eax@13
    int v84; // ST64_4@15
    int v85; // ST60_4@15
    int v86; // ST5C_4@15
    int v87; // ST58_4@15
    int v88; // ST54_4@15
    int v89; // ST50_4@15
    int v90; // ST4C_4@15
    int v91; // ST48_4@15
    int v92; // ST44_4@15
    int v93; // ST40_4@15
    int v94; // ST3C_4@15
    int v95; // ST38_4@15
    int v96; // ST34_4@15
    int v97; // ST30_4@15
    int v98; // ST2C_4@15
    int v99; // ST28_4@15
    int v100; // ST24_4@15
    int v101; // ST20_4@15
    int v102; // ST1C_4@15
    int v103; // ST18_4@15
    int v104; // ST14_4@15
    int v105; // ST10_4@15
    int v106; // ST0C_4@15
    int v107; // eax@15
    RGE_Game_World *v108; // edi@17
    int v109; // ST78_4@17
    int v110; // ecx@17
    int v111; // ebp@17
    char *v112; // ST64_4@17
    int v113; // ST58_4@17
    int v114; // ST54_4@17
    int v115; // ST50_4@17
    char *v116; // eax@17
    int sNuma; // [sp+18h] [bp+4h]@17

    v2 = this;
    v3 = this->playerAI;
    if( v3 )
    {
        switch ( sNum )
        {
            case 1:
                v14 = BuildAIModule::buildListLength((BuildAIModule *)&v3->buildAI.vfptr);
                v15 = BuildAIModule::numberItemsIntoBuildList((BuildAIModule *)&v2->playerAI->buildAI.vfptr);
                v16 = BuildAIModule::lastBuildItemRequested((BuildAIModule *)&v2->playerAI->buildAI.vfptr);
                v17 = BuildAIModule::nextBuildItemRequested((BuildAIModule *)&v2->playerAI->buildAI.vfptr);
                v18 = BuildAIModule::currentBuildItemRequested((BuildAIModule *)&v2->playerAI->buildAI.vfptr);
                v19 = ConstructionAIModule::constructionPlanName((ConstructionAIModule *)&v2->playerAI->constructionAI.vfptr);
                v20 = BuildAIModule::buildListName((BuildAIModule *)&v2->playerAI->buildAI.vfptr);
                sprintf(v2->aiStatusInformationValue, aBuildListSCity, v20, v19, v18, v17, v16, v15, v14);
                result = v2->aiStatusInformationValue;
                break;
            case 2:
                v21 = TribeTacticalAIModule::resourceDifference(&v3->tacticalAI, 3);
                v22 = TribeTacticalAIModule::neededResource(&v2->playerAI->tacticalAI, 3);
                v23 = v2->playerAI;
                v24 = TribeResourceAIModule::resourceName(v22);
                v25 = TribeTacticalAIModule::resourceDifference(&v2->playerAI->tacticalAI, 2);
                v26 = TribeTacticalAIModule::neededResource(&v2->playerAI->tacticalAI, 2);
                v27 = v2->playerAI;
                v28 = TribeResourceAIModule::resourceName(v26);
                v29 = TribeTacticalAIModule::resourceDifference(&v2->playerAI->tacticalAI, 1);
                v30 = TribeTacticalAIModule::neededResource(&v2->playerAI->tacticalAI, 1);
                v31 = v2->playerAI;
                v32 = TribeResourceAIModule::resourceName(v30);
                v33 = TribeTacticalAIModule::resourceDifference(&v2->playerAI->tacticalAI, 0);
                v34 = TribeTacticalAIModule::neededResource(&v2->playerAI->tacticalAI, 0);
                v35 = v2->playerAI;
                v36 = TribeResourceAIModule::resourceName(v34);
                v37 = TribeTacticalAIModule::neededResourceAmount(&v2->playerAI->tacticalAI, 3);
                v38 = TribeTacticalAIModule::neededResource(&v2->playerAI->tacticalAI, 3);
                v39 = v2->playerAI;
                v40 = TribeResourceAIModule::resourceName(v38);
                v41 = TribeTacticalAIModule::neededResourceAmount(&v2->playerAI->tacticalAI, 2);
                v42 = TribeTacticalAIModule::neededResource(&v2->playerAI->tacticalAI, 2);
                v43 = v2->playerAI;
                v44 = TribeResourceAIModule::resourceName(v42);
                v45 = TribeTacticalAIModule::neededResourceAmount(&v2->playerAI->tacticalAI, 1);
                v46 = TribeTacticalAIModule::neededResource(&v2->playerAI->tacticalAI, 1);
                v47 = v2->playerAI;
                v48 = TribeResourceAIModule::resourceName(v46);
                v49 = TribeTacticalAIModule::neededResourceAmount(&v2->playerAI->tacticalAI, 0);
                v50 = TribeTacticalAIModule::neededResource(&v2->playerAI->tacticalAI, 0);
                v51 = v2->playerAI;
                v52 = TribeResourceAIModule::resourceName(v50);
                sprintf(
                    v2->aiStatusInformationValue2,
                    aNeedresSDSDSDS,
                    v52,
                    v49,
                    v48,
                    v45,
                    v44,
                    v41,
                    v40,
                    v37,
                    v36,
                    v33,
                    v32,
                    v29,
                    v28,
                    v25,
                    v24,
                    v21);
                result = v2->aiStatusInformationValue2;
                break;
            case 3:
                v53 = TribeTacticalAIModule::numberBoats(&v3->tacticalAI);
                v54 = TribeTacticalAIModule::numberSoldiers(&v2->playerAI->tacticalAI);
                v55 = TribeTacticalAIModule::numberCivilians(&v2->playerAI->tacticalAI);
                v56 = TribeTacticalAIModule::desiredGathererCount(&v2->playerAI->tacticalAI, 3);
                v57 = TribeTacticalAIModule::actualGathererCount(&v2->playerAI->tacticalAI, 3);
                v58 = TribeTacticalAIModule::neededResource(&v2->playerAI->tacticalAI, 3);
                v59 = v2->playerAI;
                v60 = TribeResourceAIModule::resourceName(v58);
                v61 = TribeTacticalAIModule::desiredGathererCount(&v2->playerAI->tacticalAI, 2);
                v62 = TribeTacticalAIModule::actualGathererCount(&v2->playerAI->tacticalAI, 2);
                v63 = TribeTacticalAIModule::neededResource(&v2->playerAI->tacticalAI, 2);
                v64 = v2->playerAI;
                v65 = TribeResourceAIModule::resourceName(v63);
                v66 = TribeTacticalAIModule::desiredGathererCount(&v2->playerAI->tacticalAI, 1);
                v67 = TribeTacticalAIModule::actualGathererCount(&v2->playerAI->tacticalAI, 1);
                v68 = TribeTacticalAIModule::neededResource(&v2->playerAI->tacticalAI, 1);
                v69 = v2->playerAI;
                v70 = TribeResourceAIModule::resourceName(v68);
                v71 = TribeTacticalAIModule::desiredGathererCount(&v2->playerAI->tacticalAI, 0);
                v72 = TribeTacticalAIModule::actualGathererCount(&v2->playerAI->tacticalAI, 0);
                v73 = TribeTacticalAIModule::neededResource(&v2->playerAI->tacticalAI, 0);
                v74 = v2->playerAI;
                v75 = TribeResourceAIModule::resourceName(v73);
                sprintf(
                    v2->aiStatusInformationValue3,
                    aGatActDesSDDSD,
                    v75,
                    v72,
                    v71,
                    v70,
                    v67,
                    v66,
                    v65,
                    v62,
                    v61,
                    v60,
                    v57,
                    v56,
                    v55,
                    v54,
                    v53);
                result = v2->aiStatusInformationValue3;
                break;
            case 4:
                v76 = TribeTacticalAIModule::strategicNumber(&v3->tacticalAI, 158);
                v77 = TribeTacticalAIModule::strategicNumber(&v2->playerAI->tacticalAI, 119);
                v78 = TribeTacticalAIModule::strategicNumber(&v2->playerAI->tacticalAI, 159);
                v79 = TribeTacticalAIModule::strategicNumber(&v2->playerAI->tacticalAI, 118);
                v80 = TribeTacticalAIModule::strategicNumber(&v2->playerAI->tacticalAI, 157);
                v81 = TribeTacticalAIModule::strategicNumber(&v2->playerAI->tacticalAI, 120);
                v82 = TribeTacticalAIModule::strategicNumber(&v2->playerAI->tacticalAI, 156);
                v83 = TribeTacticalAIModule::strategicNumber(&v2->playerAI->tacticalAI, 117);
                sprintf(v2->aiStatusInformationValue4, aPersSpecBlFood, v83, v82, v81, v80, v79, v78, v77, v76);
                result = v2->aiStatusInformationValue4;
                break;
            case 5:
                v84 = DiplomacyAIModule::stance(&v3->diplomacyAI, 8, 2);
                v85 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 8, 1);
                v86 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 8, 0);
                v87 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 7, 2);
                v88 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 7, 1);
                v89 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 7, 0);
                v90 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 6, 2);
                v91 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 6, 1);
                v92 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 6, 0);
                v93 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 5, 2);
                v94 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 5, 1);
                v95 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 5, 0);
                v96 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 4, 2);
                v97 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 4, 1);
                v98 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 4, 0);
                v99 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 3, 2);
                v100 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 3, 1);
                v101 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 3, 0);
                v102 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 2, 2);
                v103 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 2, 1);
                v104 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 2, 0);
                v105 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 1, 2);
                v106 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 1, 1);
                v107 = DiplomacyAIModule::stance(&v2->playerAI->diplomacyAI, 1, 0);
                sprintf(
                    v2->aiStatusInformationValue5,
                    aDipP1DDDP2DDDP,
                    v107,
                    v106,
                    v105,
                    v104,
                    v103,
                    v102,
                    v101,
                    v100,
                    v99,
                    v98,
                    v97,
                    v96,
                    v95,
                    v94,
                    v93,
                    v92,
                    v91,
                    v90,
                    v89,
                    v88,
                    v87,
                    v86,
                    v85,
                    v84);
                result = v2->aiStatusInformationValue5;
                break;
            case 6:
                v108 = this->world;
                v109 = v3->tacticalAI.attackEnabledValue;
                v110 = this->world->players[this->world->currentUpdateComputerPlayer][1].position_checksum;
                v111 = *(_DWORD *)(v110 + 74856);
                sNuma = *(_DWORD *)(v110 + 74860);
                v112 = TribeTacticalAIModule::updateAreaName((TribeTacticalAIModule *)(v110 + 70764));
                v113 = v108->currentUpdateComputerPlayer;
                v114 = BYTE1(v108[1].game_speed);
                v115 = TribeTacticalAIModule::strategicNumber(&v2->playerAI->tacticalAI, 104) / 60;
                v116 = TribeStrategyAIModule::ruleSetName(&v2->playerAI->strategyAI);
                sprintf(v2->aiStatusInformationValue6, aPerSAttenabDAt, v116, v109, v115, v114, v113, sNuma, v111, v112);
                result = v2->aiStatusInformationValue6;
                break;
            default:
                result = aInvalidStatusL;
                break;
        }
    }
    else
    {
        v4 = this->world;
        v5 = v4->currentUpdateComputerPlayer;
        if( v5 != -1 && (v6 = v4->players[v5]) != 0 )
        {
            v7 = v6[1].position_checksum;
            v8 = v2->world;
            v9 = v2->aiStatusInformationValue;
            v10 = *(_DWORD *)(v7 + 74856);
            v11 = *(_DWORD *)(v7 + 74860);
            v12 = TribeTacticalAIModule::updateAreaName((TribeTacticalAIModule *)(v7 + 70764));
            sprintf(v9, aConcpDCurcpDAv, BYTE1(v8[1].game_speed), v8->currentUpdateComputerPlayer, v11, v10, v12);
            result = v9;
        }
        else
        {
            result = aInvalidCurrent;
        }
    }
    return result;
}

//----- (00514F90) --------------------------------------------------------
void TRIBE_Player::kickAI(int m)
{
    TribeMainDecisionAIModule *v2; // ecx@1

    v2 = this->playerAI;
    if( v2 )
        TribeMainDecisionAIModule::kick(v2, m);
}

//----- (00514FB0) --------------------------------------------------------
int TRIBE_Player::strategicNumber(int sN)
{
    TribeMainDecisionAIModule *v2; // eax@1
    int result; // eax@2

    v2 = this->playerAI;
    if( v2 )
        result = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, sN);
    else
        result = -1;
    return result;
}

//----- (00514FE0) --------------------------------------------------------
void TRIBE_Player::logMessage(char *textIn, ...)
{
    char textOut[1024]; // [sp+4h] [bp-400h]@2
    va_list va; // [sp+410h] [bp+Ch]@1

    va_start(va, textIn);
    if( this->playerAI )
    {
        vsprintf(textOut, textIn, va);
        AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, textOut);
    }
}

//----- (00515040) --------------------------------------------------------
int TRIBE_Player::sendAICommand@<eax>(TRIBE_Player *this@<ecx>, double a2@<st0>, int caller, int mType, int p1, int p2, int p3)
{
    TribeMainDecisionAIModule *v7; // ecx@1
    int result; // eax@2

    v7 = this->playerAI;
    if( v7 )
        result = TribeMainDecisionAIModule::processAICommand(v7, a2, caller, mType, p1, p2, p3);
    else
        result = 0;
    return result;
}

//----- (00515070) --------------------------------------------------------
RGE_Object_Node *TRIBE_Player::addObject(RGE_Static_Object *obj, int sleepFlag, int dopple_flag)
{
    TRIBE_Player *v4; // esi@1
    RGE_Object_Node *v5; // ebx@1
    TribeMainDecisionAIModule *v6; // ecx@2
    int v7; // eax@4

    v4 = this;
    v5 = RGE_Player::addObject((RGE_Player *)&this->vfptr, obj, sleepFlag, dopple_flag);
    if( obj->master_obj->object_group != 11 )
    {
        v6 = v4->playerAI;
        if( v6 )
        {
            if( obj->id >= 0 )
            {
                (*(void (__stdcall **)(RGE_Static_Object *))&v6->vfptr[1].gap4[0])(obj);
                v7 = 1;
                if( v4->world->game_state == 2 )
                    v7 = 0;
                TribeBuildAIModule::addItem(&v4->playerAI->buildAI, obj, v7);
            }
        }
    }
    return v5;
}

//----- (005150E0) --------------------------------------------------------
void TRIBE_Player::removeObject(RGE_Static_Object *obj, int sleepFlag, int dopple_flag, RGE_Object_Node *node)
{
    TRIBE_Player *v5; // esi@1
    TribeMainDecisionAIModule *v6; // ecx@1

    v5 = this;
    RGE_Player::removeObject((RGE_Player *)&this->vfptr, obj, sleepFlag, dopple_flag, node);
    v6 = v5->playerAI;
    if( v6 && obj->master_obj->object_group != 11 && obj->id >= 0 )
        ((void (__stdcall *)(int))v6->vfptr[1].setLogHistory)(obj->id);
}

//----- (00515130) --------------------------------------------------------
void TRIBE_Player::buildObject(int bi, int oi, float x, float y, int ui)
{
    TRIBE_Player *v6; // edi@1
    int *v7; // esi@1

    v6 = this;
    v7 = (int *)calloc(1u, 4u);
    *v7 = bi;
    TRIBE_Command::command_build((TRIBE_Command *)v6->world->commands, v6->id, v7, 1, oi, x, y, ui);
    free(v7);
}

//----- (00515180) --------------------------------------------------------
void TRIBE_Player::cancelBuild(int reason, int blockerID, int blockerType, float x, float y, int uniqueID, int builderID)
{
    TribeMainDecisionAIModule *v8; // eax@1

    v8 = this->playerAI;
    if( v8 )
        TribeBuildAIModule::cancelBuildItem(&v8->buildAI, reason, blockerID, blockerType, x, y, uniqueID, builderID);
}

//----- (005151C0) --------------------------------------------------------
void TRIBE_Player::registerBuild(RGE_Static_Object *obj, int uniqueID)
{
    TribeMainDecisionAIModule *v3; // eax@1

    v3 = this->playerAI;
    if( v3 )
        TribeBuildAIModule::addBuiltItem(&v3->buildAI, obj, uniqueID);
}

//----- (005151F0) --------------------------------------------------------
void TRIBE_Player::trainUnit(int uType, int bID, int uniqueID)
{
    TRIBE_Command::command_make((TRIBE_Command *)this->world->commands, this->id, bID, uType, uniqueID);
}

//----- (00515220) --------------------------------------------------------
void TRIBE_Player::cancelTrain(int reason, int uType, int location, int uniqueID)
{
    TribeMainDecisionAIModule *v5; // eax@1

    v5 = this->playerAI;
    if( v5 )
        TribeBuildAIModule::cancelTrainUnit(&v5->buildAI, reason, uType, location, uniqueID);
}

//----- (00515250) --------------------------------------------------------
void TRIBE_Player::registerTrain(int uType, int location, int uniqueID, int gameID)
{
    TribeMainDecisionAIModule *v5; // eax@1

    v5 = this->playerAI;
    if( v5 )
        TribeBuildAIModule::addTrainedUnit(&v5->buildAI, uType, location, uniqueID, gameID);
}

//----- (00515280) --------------------------------------------------------
void TRIBE_Player::research(int rType, int bID, int uniqueID)
{
    TRIBE_Command::command_research((TRIBE_Command *)this->world->commands, this->id, bID, rType, uniqueID);
}

//----- (005152B0) --------------------------------------------------------
void TRIBE_Player::cancelResearch(int reason, int rType, int location, int uniqueID)
{
    TribeMainDecisionAIModule *v5; // eax@1

    v5 = this->playerAI;
    if( v5 )
        TribeBuildAIModule::cancelResearch(&v5->buildAI, reason, rType, location, uniqueID);
}

//----- (005152E0) --------------------------------------------------------
void TRIBE_Player::registerResearch(int rType, int location, int uniqueID)
{
    TribeMainDecisionAIModule *v4; // eax@1

    v4 = this->playerAI;
    if( v4 )
        TribeBuildAIModule::addResearch(&v4->buildAI, rType, location, uniqueID);
}

//----- (00515310) --------------------------------------------------------
void TRIBE_Player::taskTrader(int tID, int oID, int ownerID, float x, float y)
{
    TRIBE_Player *v6; // edi@1
    int *v7; // esi@1

    v6 = this;
    v7 = (int *)calloc(1u, 4u);
    *v7 = tID;
    RGE_Command::command_work(v6->world->commands, v6->id, v7, 1, oID, ownerID, x, y);
    free(v7);
}

//----- (00515360) --------------------------------------------------------
void TRIBE_Player::taskResourceGatherer(int gID, int oID, int ownerID, float x, float y)
{
    TRIBE_Player *v6; // edi@1
    int *v7; // esi@1

    v6 = this;
    v7 = (int *)calloc(1u, 4u);
    *v7 = gID;
    RGE_Command::command_work(v6->world->commands, v6->id, v7, 1, oID, ownerID, x, y);
    free(v7);
}

//----- (005153B0) --------------------------------------------------------
void TRIBE_Player::setDiplomaticStance(int playerNum, int rType)
{
    TRIBE_Command::command_relation((TRIBE_Command *)this->world->commands, this->id, playerNum, rType);
}

//----- (005153D0) --------------------------------------------------------
void TRIBE_Player::loadAIInformation(char *bL, char *cP, char *rS, int mood, int mapType)
{
    TRIBE_Player *v6; // ebx@1
    int v7; // ST30_4@12
    int v8; // ST2C_4@12
    int v9; // eax@12
    int v10; // ST30_4@15
    int v11; // ST2C_4@15
    int v12; // eax@15
    RGE_Map *v13; // eax@19
    AIModuleVtbl *v14; // edx@19
    RGE_Map *v15; // eax@21
    int v16; // esi@29
    int i; // esi@29
    RGE_PlayerVtbl *v18; // edi@32
    int v19; // esi@37
    RGE_PlayerVtbl *v20; // edi@38
    int (__thiscall *v21)(TRIBE_Player *, int); // ebp@38
    RGE_Game_World *v22; // ecx@44
    char *v23; // edx@44
    char *v24; // [sp+1Ch] [bp-430h]@19
    int v25; // [sp+20h] [bp-42Ch]@19
    int v26; // [sp+24h] [bp-428h]@19
    char *v27; // [sp+30h] [bp-41Ch]@5
    int save_debug_random_on; // [sp+44h] [bp-408h]@1
    int saveRand; // [sp+48h] [bp-404h]@1
    char buildListName[256]; // [sp+4Ch] [bp-400h]@10
    char ruleSetName[256]; // [sp+14Ch] [bp-300h]@10
    char randomString[256]; // [sp+24Ch] [bp-200h]@10
    char noneString[256]; // [sp+34Ch] [bp-100h]@10

    v6 = this;
    saveRand = debug_rand(aCMsdevWorkAg_3, 2147);
    save_debug_random_on = debug_random_on;
    global_save_debug_random_on2 = debug_random_on;
    debug_random_on = 0;
    if( !v6->playerAI )
        goto LABEL_47;
    switch ( TRIBE_Game::mapType((TRIBE_Game *)rge_base_game) )
    {
        case 0:
            AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aWeHaveAnAllWat);
            break;
        case 1:
            AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aWeHaveAMostlyW);
            break;
        case 2:
            v27 = aWeHaveALandAnd;
            goto LABEL_9;
        case 3:
            AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aWeHaveAMostlyL);
            break;
        case 4:
            AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aWeHaveAnAllLan);
            break;
        default:
            v27 = aWeDonTHaveASpe;
LABEL_9:
            AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, v27);
            break;
    }
    (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(10101, noneString, 256);
    (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(10107, randomString, 256);
    strcpy(buildListName, message_in);
    strcpy(ruleSetName, message_in);
    if( bL )
    {
        if( !strcmp(bL, randomString) )
        {
            do
            {
                v7 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
                v8 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
                v9 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
                TRIBE_Player::intelligentBuildListAndRulesSelection(v6, buildListName, ruleSetName, v9, v8, v7);
                AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aLoadingRandomG, buildListName);
            }
            while( !((int (__thiscall *)(int, char *, TRIBE_Player *))v6->playerAI->buildAI.vfptr[1].setLogHistory)(
                                 (int)&v6->playerAI->buildAI,
                                 buildListName,
                                 v6) );
        }
        else
        {
            AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aLoadingBuildLi, bL);
            ((void (__thiscall *)(int, char *, TRIBE_Player *))v6->playerAI->buildAI.vfptr[1].setLogHistory)(
                (int)&v6->playerAI->buildAI,
                bL,
                v6);
        }
    }
    else
    {
        do
        {
            v10 = TRIBE_Game::mapSize((TRIBE_Game *)rge_base_game);
            v11 = TRIBE_Game::victoryType((TRIBE_Game *)rge_base_game);
            v12 = TRIBE_Game::mapType((TRIBE_Game *)rge_base_game);
            TRIBE_Player::intelligentBuildListAndRulesSelection(v6, buildListName, ruleSetName, v12, v11, v10);
            AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aLoadingDefault, buildListName);
        }
        while( !((int (__thiscall *)(_DWORD, _DWORD, _DWORD))v6->playerAI->buildAI.vfptr[1].setLogHistory)(
                             &v6->playerAI->buildAI,
                             buildListName,
                             v6) );
    }
    if( cP )
    {
        if( strcmp(cP, randomString) )
        {
            AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aLoadingCityPla, cP);
            v13 = v6->world->map;
            v14 = v6->playerAI->constructionAI.vfptr;
            v26 = v13->map_height;
            v25 = v13->map_width;
            v24 = cP;
            goto LABEL_22;
        }
        AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aLoadingNoCityP);
    }
    else
    {
        AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aLoadingNoCityP);
    }
    v15 = v6->world->map;
    v14 = v6->playerAI->constructionAI.vfptr;
    v26 = v15->map_height;
    v25 = v15->map_width;
    v24 = aNone_2;
LABEL_22:
    (*(void (__stdcall **)(char *, int, int, _DWORD, _DWORD, _DWORD))&v14[1].gap4[0])(v24, v25, v26, 0, 0, 0);
    if( !rS || !strcmp(rS, randomString) )
    {
        if( !strcmp(ruleSetName, aRandomgamespec) )
        {
            AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aRuleSetHasBeen);
        }
        else
        {
            AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aLoadingRando_1, ruleSetName);
            TribeStrategyAIModule::loadRules(&v6->playerAI->strategyAI, ruleSetName);
        }
    }
    else
    {
        AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aLoadingRuleSet, rS);
        TribeStrategyAIModule::loadRules(&v6->playerAI->strategyAI, rS);
    }
    v16 = RGE_Base_Game::difficulty(rge_base_game);
    AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aSettingDifficu, v16);
    TribeStrategyAIModule::setDifficultyLevel(&v6->playerAI->strategyAI, v16);
    TribeMainDecisionAIModule::updateBuildAIWithObjects(v6->playerAI);
    for( i = 1; i < v6->world->player_num; ++i )
    {
        if( i == v6->id )
        {
            DiplomacyAIModule::setStance(&v6->playerAI->diplomacyAI, i, 0, 0);
            DiplomacyAIModule::setStance(&v6->playerAI->diplomacyAI, i, 2, 100);
        }
        else
        {
            v18 = v6->vfptr;
            if( (*(int (__thiscall **)(TRIBE_Player *, int))&v6->vfptr->gap4[20])(v6, i) )
            {
                DiplomacyAIModule::setStance(&v6->playerAI->diplomacyAI, i, 0, 74);
                DiplomacyAIModule::setStance(&v6->playerAI->diplomacyAI, i, 2, 24);
            }
            else if( (*(int (__thiscall **)(TRIBE_Player *, int))&v18->gap4[24])(v6, i) )
            {
                DiplomacyAIModule::setStance(&v6->playerAI->diplomacyAI, i, 0, 24);
                DiplomacyAIModule::setStance(&v6->playerAI->diplomacyAI, i, 2, 74);
            }
        }
    }
    v19 = 1;
    if( v6->world->player_num > 1 )
    {
        v20 = v6->vfptr;
        v21 = *(int (__thiscall **)(TRIBE_Player *, int))&v6->vfptr->gap4[20];
        do
        {
            if( v21(v6, v19) || (*(int (__thiscall **)(TRIBE_Player *, int))&v20->gap4[24])(v6, v19) )
                DiplomacyAIModule::setChangeable(&v6->playerAI->diplomacyAI, v19, 0);
            else
                DiplomacyAIModule::setChangeable(&v6->playerAI->diplomacyAI, v19, 1);
            ++v19;
        }
        while( v19 < v6->world->player_num );
    }
    EmotionalAIModule::setOverallState(&v6->playerAI->emotionalAI, mood);
    v22 = v6->world;
    v23 = v22->scenario->scenario_name;
    if( v23 && strlen(v22->scenario->scenario_name) != 0 )
        TribeInformationAIModule::loadLearnInfo(&v6->playerAI->informationAI, v23);
LABEL_47:
    debug_random_on = save_debug_random_on;
    debug_srand(aCMsdevWorkAg_3, 2301, saveRand);
}
// 62C4D4: using guessed type int debug_random_on;
// 86BC94: using guessed type int global_save_debug_random_on2;

//----- (005159D0) --------------------------------------------------------
void TRIBE_Player::notify(int caller, int recipient, int mType, int p1, int p2, int p3)
{
    TRIBE_Player *v7; // esi@1
    RGE_Game_World *v8; // ecx@3
    int v9; // eax@4
    int v10; // ebx@4
    RGE_Game_World *v11; // edi@4
    unsigned int v12; // ebp@4
    RGE_Sound *v13; // ecx@5
    RGE_Base_GameVtbl *v14; // edx@10
    int v15; // eax@14
    int v16; // edi@14
    unsigned int v17; // ebx@14
    signed int v18; // [sp-14h] [bp-28h]@10
    int v19; // [sp-10h] [bp-24h]@10
    RGE_Static_Object *attackingObject; // [sp+10h] [bp-4h]@3

    v7 = this;
    switch ( mType )
    {
        case 513:
            if( !this->update_count )
            {
                v8 = this->world;
                v7->update_count = 20;
                attackingObject = RGE_Game_World::object(v8, p1);
                if( attackingObject )
                {
                    v9 = debug_rand(aCMsdevWorkAg_3, 2336);
                    v10 = debug_random_on;
                    debug_random_on = 0;
                    global_save_debug_random_on3 = v10;
                    v11 = v7->world;
                    v12 = v9;
                    if( v11->curr_player == v7->id )
                    {
                        v13 = v11->sounds[(signed short)(signed __int64)v7->attributes[26]];
                        if( v13 )
                            RGE_Sound::play(v13, 1);
                        TRIBE_Game::add_notification_loc(
                            (TRIBE_Game *)rge_base_game,
                            (signed __int64)attackingObject->world_x,
                            (signed __int64)attackingObject->world_y);
                    }
                    debug_random_on = v10;
                    debug_srand(aCMsdevWorkAg_3, 2353, v12);
                }
            }
            break;
        case 524:
            if( p1 == 615 )
            {
                v14 = rge_base_game->vfptr;
                v19 = this->id;
                v18 = 3;
                goto LABEL_13;
            }
            break;
        case 519:
            v14 = rge_base_game->vfptr;
            v19 = this->id;
            v18 = 1;
            goto LABEL_13;
        case 518:
            v14 = rge_base_game->vfptr;
            v19 = this->id;
            v18 = 2;
LABEL_13:
            ((void (__stdcall *)(signed int, int, _DWORD, _DWORD, _DWORD))v14->notification)(v18, v19, 0, 0, 0);
            break;
        default:
            break;
    }
    v15 = debug_rand(aCMsdevWorkAg_3, 2377);
    v16 = debug_random_on;
    v17 = v15;
    global_save_debug_random_on4 = debug_random_on;
    debug_random_on = 0;
    if( v7->playerAI )
        ((void (__thiscall *)(TRIBE_Player *, int, int, int, int, int, int))v7->vfptr[1].sendUnitAIOrder)(
            v7,
            caller,
            recipient,
            mType,
            p1,
            p2,
            p3);
    debug_random_on = v16;
    debug_srand(aCMsdevWorkAg_3, 2390, v17);
}

void TRIBE_Player::notifyAI(TRIBE_Player *this@<ecx>, double a2@<st0>, int callerID, int recipientID, int mType, int p1, int p2, int p3)
{
    TRIBE_Player *v8; // esi@1
    RGE_Static_Object *v9; // eax@1
    RGE_Static_Object *v10; // ebp@1
    TacticalAIGroup *v11; // eax@12
    TacticalAIGroup *v12; // edi@12
    int v13; // eax@14
    RGE_Static_Object *v14; // eax@22

    v8 = this;
    v9 = RGE_Game_World::object(this->world, callerID);
    v10 = v9;
    if( mType == 522 || mType == 114 || mType == 116 || v9 && RGE_Static_Object::unitAI(v9) )
    {
        if( mType > 505 )
        {
            switch ( mType )
            {
                case 514:
                    if( p1 == 605 || p1 == 623 )
                    {
                        if( TribeInformationAIModule::fullyExploredZone(&v8->playerAI->informationAI, callerID)
                            && TribeInformationAIModule::closestUnexploredTile(
                                     &v8->playerAI->informationAI,
                                     callerID,
                                     v10->world_x,
                                     v10->world_y,
                                     (float *)&p2,
                                     (float *)&p1) == (RGE_Static_Object *)1 )
                        {
                            TribeTacticalAIModule::taskExplorer(&v8->playerAI->tacticalAI, callerID, *(float *)&p2, *(float *)&p1);
                        }
                        else
                        {
                            TribeTacticalAIModule::detask(&v8->playerAI->tacticalAI, callerID);
                        }
                    }
                    break;
                case 521:
                    v14 = RGE_Game_World::object(v8->world, p1);
                    if( v14 )
                        DiplomacyAIModule::changeStance(&v8->playerAI->diplomacyAI, v14->owner->id, 0, 10);
                    break;
                case 522:
                    TribeMainDecisionAIModule::tributeNotify(v8->playerAI, callerID, p1, p2);
                    break;
                case 513:
                    goto LABEL_25;
                case 525:
                    TribeInformationAIModule::addImportantObject(&v8->playerAI->informationAI, a2, p1);
                    break;
                default:
                    return;
            }
        }
        else if( mType == 505 )
        {
            if( p1 == 605 )
            {
                v11 = TribeTacticalAIModule::groupUnitIsIn(&v8->playerAI->tacticalAI, callerID);
                v12 = v11;
                if( v11 )
                {
                    if( TacticalAIGroup::type(v11) == 107 )
                    {
                        v13 = TacticalAIGroup::id(v12);
                        TribeTacticalAIModule::removeGroup(&v8->playerAI->tacticalAI, v13);
                    }
                }
            }
        }
        else if( mType == 114 || mType == 116 )
        {
LABEL_25:
            (*(void (__thiscall **)(int, int, int, int, int, int, int))&v8->playerAI->tacticalAI.vfptr[1].gap4[0])(
                (int)&v8->playerAI->tacticalAI,
                callerID,
                recipientID,
                mType,
                p1,
                p2,
                p3);
        }
    }
}

int TRIBE_Player::intelligentCivSelection(int mapType, int gameType, int mapSize)
{
    return 0;
}

void TRIBE_Player::intelligentBuildListAndRulesSelection(char *b, char *r, int mapType, int gameType, int mapSize)
{
    TRIBE_Player *v6; // ebp@1
    int v7; // eax@20
    signed int v8; // ecx@52
    signed int v9; // eax@54
    int v10; // ecx@57
    signed int v11; // edi@64
    signed int v12; // ebx@64
    signed int v13; // esi@64
    bool v14; // sf@184
    unsigned __int8 v15; // of@184
    int *v16; // eax@185
    signed int v17; // ecx@185
    signed int v18; // esi@189
    int *v19; // eax@189
    signed int v20; // ecx@189
    int v21; // ebx@190
    int v22; // edx@191
    signed int v23; // ebx@191
    int v24; // esi@191
    signed int v25; // eax@191
    int *v26; // ecx@191
    unsigned int v27; // ecx@209
    char v28; // dl@209
    char *v29; // edi@209
    char *v30; // esi@209
    int v31; // ecx@209
    int v32; // esi@209
    int v33; // edi@211
    int v34; // esi@214
    int v35; // eax@216
    int v36; // eax@217
    int v37; // ebx@219
    int v38; // ST0C_4@222
    signed int v39; // eax@222
    signed int v40; // eax@222
    signed int v41; // eax@222
    signed int v42; // eax@222
    int v43; // eax@222
    int v44; // eax@227
    int v45; // esi@227
    int v46; // edx@227
    int v47; // eax@228
    int v48; // esi@228
    int v49; // ST0C_4@228
    signed int v50; // eax@229
    int v51; // esi@229
    signed int v52; // ecx@229
    signed __int64 v53; // rax@229
    int v54; // eax@230
    int v55; // eax@231
    int v56; // eax@232
    int v57; // esi@232
    int v58; // ST0C_4@232
    int v59; // eax@233
    int v60; // eax@250
    int v61; // ebx@250
    int v62; // esi@250
    int v63; // edi@250
    int v64; // ST0C_4@264
    int v65; // ST0C_4@264
    int v66; // eax@266
    TribeMainDecisionAIModule *v67; // ecx@266
    int mostBuiltUnit1; // [sp+14h] [bp-300h]@49
    int difficultyLevel; // [sp+18h] [bp-2FCh]@2
    int buildLists[125]; // [sp+1Ch] [bp-2F8h]@2
    int mostBuiltUnit2; // [sp+210h] [bp-104h]@49
    char tempString[256]; // [sp+214h] [bp-100h]@209

    v6 = this;
    if( this->playerAI )
    {
        difficultyLevel = RGE_Base_Game::difficulty(rge_base_game);
        memset(buildLists, 0, sizeof(buildLists));
        switch ( v6->master_player_id )
        {
            case 1:
                TRIBE_Player::setupEgyptian(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 2:
                TRIBE_Player::setupGreek(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 3:
                TRIBE_Player::setupBabylonian(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 4:
                TRIBE_Player::setupAssyrian(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 5:
                TRIBE_Player::setupMinoan(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 6:
                TRIBE_Player::setupHittite(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 7:
                TRIBE_Player::setupPhoenician(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 8:
                TRIBE_Player::setupSumerian(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 9:
                TRIBE_Player::setupPersian(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 0xA:
                TRIBE_Player::setupShang(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 0xB:
                TRIBE_Player::setupYamato(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 0xC:
                TRIBE_Player::setupChoson(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 0xD:
                TRIBE_Player::setupRoman(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 0xE:
                TRIBE_Player::setupCarthaginian(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 0xF:
                TRIBE_Player::setupPalmyran(v6, buildLists, mapType, gameType, mapSize);
                break;
            case 0x10:
                TRIBE_Player::setupMacedonian(v6, buildLists, mapType, gameType, mapSize);
                break;
            default:
                break;
        }
        if( !TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) )
        {
            v7 = v6->master_player_id - 1;
            if( v7 == 3 || v6->master_player_id == 1 || v7 == 1 || v7 == 4 || v7 == 8 || v7 == 6 || v7 == 7 || v7 == 10 )
            {
                if( !mapType )
                {
                    if( dword_886C44 <= 0 )
                    {
                        buildLists[13] = 0;
                        buildLists[14] = 0;
                    }
                    else if( dword_886C48 )
                    {
                        buildLists[13] += 100;
                        buildLists[14] += 100;
                    }
                    else
                    {
                        buildLists[13] += 300;
                        buildLists[14] += 300;
                    }
                }
                if( mapType == 1 )
                {
                    if( dword_886C44 <= 0 )
                    {
                        buildLists[13] = 0;
                        buildLists[14] = 0;
                    }
                    else if( dword_886C48 )
                    {
                        buildLists[13] += 75;
                        buildLists[14] += 75;
                    }
                    else
                    {
                        buildLists[13] += 250;
                        buildLists[14] += 250;
                    }
                }
                if( mapType == 2 || mapType == 6 || mapType == 8 )
                {
                    if( dword_886C44 <= 0 )
                    {
                        buildLists[13] = 0;
                        buildLists[14] = 0;
                    }
                    else if( dword_886C48 )
                    {
                        buildLists[13] += 50;
                        buildLists[14] += 50;
                    }
                    else
                    {
                        buildLists[13] += 200;
                        buildLists[14] += 200;
                    }
                }
            }
        }
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 201, 1);
        if( !TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) )
        {
            mostBuiltUnit1 = -1;
            mostBuiltUnit2 = -1;
            TribeInformationAIModule::loadUnitHistory(&v6->playerAI->informationAI, (int)v6, 25);
            TribeInformationAIModule::unitsThatAreMostBuilt(&v6->playerAI->informationAI, &mostBuiltUnit1, &mostBuiltUnit2);
            switch ( mostBuiltUnit1 )
            {
                case 0:
                    buildLists[6] += 25;
                    buildLists[7] += 25;
                    break;
                case 1:
                    buildLists[6] += 30;
                    buildLists[7] += 30;
                    break;
                case 2:
                    v8 = buildLists[18] + 20;
                    buildLists[17] += 20;
                    buildLists[18] += 20;
                    buildLists[3] += 40;
                    buildLists[4] += 40;
                    goto LABEL_64;
                case 3:
                    buildLists[0] += 40;
                    buildLists[17] -= 60;
                    v8 = buildLists[18] - 60;
                    buildLists[1] += 20;
                    buildLists[19] += 20;
                    buildLists[20] += 20;
                    buildLists[18] -= 60;
                    goto LABEL_64;
                case 4:
                    buildLists[6] += 15;
                    buildLists[7] += 15;
                    v9 = 20;
                    goto LABEL_61;
                case 5:
                    buildLists[6] += 15;
                    buildLists[7] += 15;
                    buildLists[0] += 10;
                    buildLists[1] += 10;
                    break;
                case 6:
                    buildLists[6] += 15;
                    buildLists[7] += 15;
                    break;
                case 7:
                case 10:
                    v10 = buildLists[20] - 60;
                    buildLists[19] -= 60;
                    goto LABEL_62;
                case 8:
                    buildLists[19] += 40;
                    buildLists[20] += 40;
                    if( dword_886C44 > 0 )
                    {
                        buildLists[13] += 50;
                        buildLists[14] += 50;
                    }
                    break;
                case 9:
                    v9 = 100;
LABEL_61:
                    v10 = v9 + buildLists[20];
                    buildLists[19] += v9;
LABEL_62:
                    buildLists[20] = v10;
                    break;
                default:
                    break;
            }
        }
        v8 = buildLists[18];
LABEL_64:
        v11 = buildLists[51];
        v12 = buildLists[50];
        mostBuiltUnit1 = 0;
        v13 = buildLists[41];
        do
        {
            switch ( mostBuiltUnit1 )
            {
                case 0:
                    if( buildLists[19] > 0 )
                        buildLists[19] /= 3;
                    if( buildLists[20] > 0 )
                        buildLists[20] /= 3;
                    if( buildLists[21] > 0 )
                        buildLists[21] /= 3;
                    break;
                case 1:
                    if( buildLists[6] > 0 )
                        buildLists[6] /= 3;
                    if( buildLists[7] > 0 )
                        buildLists[7] /= 3;
                    if( buildLists[8] > 0 )
                        buildLists[8] /= 3;
                    if( buildLists[59] > 0 )
                        buildLists[59] /= 3;
                    if( buildLists[58] > 0 )
                        buildLists[58] /= 3;
                    if( buildLists[54] > 0 )
                        buildLists[54] /= 3;
                    if( buildLists[55] > 0 )
                        buildLists[55] /= 3;
                    if( buildLists[104] > 0 )
                        buildLists[104] /= 3;
                    break;
                case 2:
                    if( buildLists[16] > 0 )
                        buildLists[16] /= 3;
                    if( buildLists[49] > 0 )
                        buildLists[49] /= 3;
                    if( buildLists[108] > 0 )
                        buildLists[108] /= 3;
                    break;
                case 3:
                    if( buildLists[46] > 0 )
                        buildLists[46] /= 3;
                    if( buildLists[53] > 0 )
                        buildLists[53] /= 3;
                    if( buildLists[17] > 0 )
                        buildLists[17] /= 3;
                    if( v8 > 0 )
                        v8 /= 3;
                    if( buildLists[99] > 0 )
                        buildLists[99] /= 3;
                    if( buildLists[102] > 0 )
                        buildLists[102] /= 3;
                    if( buildLists[109] > 0 )
                        buildLists[109] /= 3;
                    if( v8 > 0 )
                        v8 /= 3;
                    break;
                case 4:
                    if( buildLists[3] > 0 )
                        buildLists[3] /= 3;
                    if( buildLists[4] > 0 )
                        buildLists[4] /= 3;
                    if( buildLists[5] > 0 )
                        buildLists[5] /= 3;
                    if( buildLists[9] > 0 )
                        buildLists[9] /= 3;
                    if( buildLists[10] > 0 )
                        buildLists[10] /= 3;
                    if( buildLists[11] > 0 )
                        buildLists[11] /= 3;
                    if( buildLists[12] > 0 )
                        buildLists[12] /= 3;
                    if( buildLists[42] > 0 )
                        buildLists[42] /= 3;
                    if( buildLists[44] > 0 )
                        buildLists[44] /= 3;
                    if( buildLists[45] > 0 )
                        buildLists[45] /= 3;
                    if( buildLists[47] > 0 )
                        buildLists[47] /= 3;
                    if( buildLists[48] > 0 )
                        buildLists[48] /= 3;
                    if( buildLists[56] > 0 )
                        buildLists[56] /= 3;
                    if( buildLists[74] > 0 )
                        buildLists[74] /= 3;
                    if( buildLists[98] > 0 )
                        buildLists[98] /= 3;
                    if( buildLists[103] > 0 )
                        buildLists[103] /= 3;
                    if( buildLists[112] > 0 )
                        buildLists[112] /= 3;
                    if( buildLists[113] > 0 )
                        buildLists[113] /= 3;
                    break;
                case 5:
                    if( v13 > 0 )
                        v13 /= 3;
                    if( buildLists[0] > 0 )
                        buildLists[0] /= 3;
                    if( buildLists[1] > 0 )
                        buildLists[1] /= 3;
                    if( buildLists[2] > 0 )
                        buildLists[2] /= 3;
                    if( v13 > 0 )
                        v13 /= 3;
                    if( v12 > 0 )
                        v12 /= 3;
                    if( v11 > 0 )
                        v11 /= 3;
                    if( buildLists[72] > 0 )
                        buildLists[72] /= 3;
                    if( buildLists[73] > 0 )
                        buildLists[73] /= 3;
                    if( v12 > 0 )
                        v12 /= 3;
                    if( v11 > 0 )
                        v11 /= 3;
                    if( buildLists[80] > 0 )
                        buildLists[80] /= 3;
                    if( buildLists[81] > 0 )
                        buildLists[81] /= 3;
                    if( buildLists[82] > 0 )
                        buildLists[82] /= 3;
                    if( buildLists[107] > 0 )
                        buildLists[107] /= 3;
                    break;
                case 6:
                    if( buildLists[40] > 0 )
                        buildLists[40] /= 3;
                    if( buildLists[57] > 0 )
                        buildLists[57] /= 3;
                    if( buildLists[114] > 0 )
                        buildLists[114] /= 3;
                    if( buildLists[84] > 0 )
                        buildLists[84] /= 3;
                    break;
                default:
                    break;
            }
            v15 = __OFSUB__(mostBuiltUnit1 + 1, 7);
            v14 = mostBuiltUnit1++ - 6 < 0;
        }
        while( v14 ^ v15 );
        buildLists[18] = v8;
        buildLists[51] = v11;
        buildLists[50] = v12;
        buildLists[41] = v13;
        v16 = buildLists;
        v17 = 125;
        do
        {
            if( *v16 < 0 )
                *v16 = 0;
            ++v16;
            --v17;
        }
        while( v17 );
        v18 = 0;
        v19 = buildLists;
        v20 = 125;
        do
        {
            v21 = *v19;
            ++v19;
            v18 += v21;
            --v20;
        }
        while( v20 );
        v22 = debug_rand(aCMsdevWorkAg_3, 3137) % v18;
        v23 = 0;
        v24 = 0;
        v25 = 0;
        v26 = buildLists;
        while( 1 )
        {
            v24 += *v26;
            if( v24 > v22 )
                break;
            ++v25;
            ++v26;
            if( v25 >= 125 )
                goto LABEL_196;
        }
        v23 = v25;
LABEL_196:
        (*(void (__stdcall **)(int, char *, signed int))&rge_base_game->vfptr->gap8[24])(v23 + 158000, b, 256);
        switch ( v23 )
        {
            case 13:
            case 14:
            case 15:
                TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 59, 4);
                TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 60, 10);
                ++dword_886C34;
                ++dword_886C48;
                goto LABEL_209;
            case 19:
            case 20:
            case 21:
                computerPlayerSetup = (int *)((char *)computerPlayerSetup + 1);
                break;
            case 60:
            case 61:
            case 62:
            case 63:
            case 64:
            case 65:
            case 66:
            case 67:
            case 68:
            case 69:
            case 70:
            case 71:
            case 75:
            case 76:
            case 77:
            case 78:
            case 79:
            case 83:
            case 85:
            case 86:
            case 87:
            case 88:
            case 89:
            case 90:
            case 91:
            case 92:
            case 93:
            case 94:
            case 95:
            case 96:
            case 97:
            case 100:
            case 101:
            case 105:
            case 106:
            case 110:
            case 111:
            case 115:
            case 116:
            case 121:
            case 122:
            case 123:
            case 124:
                ++dword_886C48;
                goto LABEL_209;
            case 72:
            case 73:
                ++dword_886C44;
                ++dword_886C2C;
                goto LABEL_209;
            case 74:
                ++dword_886C44;
                ++dword_886C28;
                goto LABEL_209;
            case 6:
            case 7:
            case 8:
            case 43:
            case 54:
            case 55:
            case 58:
            case 59:
            case 104:
                ++dword_886C1C;
                break;
            case 0:
            case 1:
            case 2:
            case 41:
            case 50:
            case 51:
            case 80:
            case 81:
            case 82:
            case 107:
                ++dword_886C2C;
                break;
            case 16:
            case 49:
            case 108:
                ++dword_886C20;
                break;
            case 17:
            case 18:
            case 46:
            case 52:
            case 53:
            case 99:
            case 102:
            case 109:
                ++dword_886C24;
                break;
            case 40:
            case 57:
            case 84:
            case 114:
                ++dword_886C30;
                break;
            default:
                ++dword_886C28;
                break;
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
            case 30:
            case 31:
            case 32:
            case 33:
            case 34:
            case 35:
            case 36:
            case 37:
            case 38:
            case 39:
            case 117:
            case 118:
            case 119:
            case 120:
                break;
        }
        ++dword_886C44;
LABEL_209:
        (*(void (__stdcall **)(int, char *, signed int))&rge_base_game->vfptr->gap8[24])(
            v6->master_player_id + 10230,
            tempString,
            256);
        AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aIAmTheSCivCult, tempString, v6->master_player_id - 1);
        AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aSelectedABestB, b);
        v27 = strlen(aRandomgamespec) + 1;
        v28 = v27;
        v27 >>= 2;
        qmemcpy(r, aRandomgamespec, 4 * v27);
        v30 = &aRandomgamespec[4 * v27];
        v29 = &r[4 * v27];
        v31 = v28 & 3;
        qmemcpy(v29, v30, v31);
        v32 = (int)&v30[v31];
        AIModule::logCommonHistory((AIModule *)&v6->playerAI->vfptr, aSettingAiPerso);
        switch ( (_BYTE)gameType )
        {
            case 0:
            case 1:
                TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 54, 5);
                TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 55, 5);
                goto LABEL_211;
            case 2:
            case 3:
            case 4:
            case 5:
                v66 = TribeStrategyAIModule::rule(&v6->playerAI->strategyAI, 1);
                v67 = v6->playerAI;
                if( v66 <= 0 )
                {
                    TribeStrategyAIModule::setRule(&v67->strategyAI, 0, 50);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 2, 50);
                }
                else
                {
                    TribeStrategyAIModule::setRule(&v67->strategyAI, 0, 50);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 1, 25);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 2, 25);
                }
                v33 = mapType;
                if( mapType > 1 )
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 3, 5);
                TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 42, 2);
                TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 61, 2);
                if( v32 != 2 )
                {
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 38, mapSize + 1);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 36, 1);
                    if( v32 == 3 )
                        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 54, 1);
                    else
                        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 54, 5);
                    if( v32 == 4 )
                        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 55, 1);
                    else
                        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 55, 5);
                }
                break;
            default:
LABEL_211:
                v33 = mapType;
                break;
        }
        if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 4, 10);
        v34 = 60 * (debug_rand(aCMsdevWorkAg_3, 3642) % 12 + 28);
        switch ( v23 )
        {
            case 0:
            case 3:
            case 11:
            case 12:
            case 13:
            case 19:
            case 47:
            case 48:
            case 51:
            case 55:
            case 57:
            case 72:
            case 74:
            case 75:
            case 78:
            case 81:
            case 85:
            case 88:
            case 90:
            case 94:
            case 96:
            case 100:
            case 105:
            case 110:
            case 115:
                ++dword_886C3C;
                v34 = 60 * (debug_rand(aCMsdevWorkAg_3, 3672) % 6 + 20);
                break;
            case 10:
            case 41:
            case 43:
            case 44:
            case 45:
            case 50:
            case 58:
            case 113:
                ++dword_886C38;
                v35 = debug_rand(aCMsdevWorkAg_3, 3684);
                v34 = 60 * ((((unsigned __int64)v35 >> 32) ^ abs(v35) & 3) - ((unsigned __int64)v35 >> 32) + 11);
                break;
            case 9:
            case 56:
                v36 = debug_rand(aCMsdevWorkAg_3, 3689);
                v34 = 60 * ((((unsigned __int64)v36 >> 32) ^ abs(v36) & 1) - ((unsigned __int64)v36 >> 32) + 5);
                ++dword_886C38;
                break;
            default:
                ++dword_886C40;
                break;
        }
        v37 = difficultyLevel;
        if( !difficultyLevel && !(debug_rand(aCMsdevWorkAg_3, 3699) % 3) )
            v34 -= 300;
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 104, v34);
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 16, 2);
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 26, 10);
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 93, 1);
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 99, 4);
        v38 = debug_rand(aCMsdevWorkAg_3, 3712) % 3 != 0;
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 188, v38);
        v39 = debug_rand(aCMsdevWorkAg_3, 3718);
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 195, v39 % 40 + 10);
        v40 = debug_rand(aCMsdevWorkAg_3, 3722);
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 189, v40 % 70 + 30);
        v41 = debug_rand(aCMsdevWorkAg_3, 3726);
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 198, v37 * (v41 % 5 + 5));
        v42 = debug_rand(aCMsdevWorkAg_3, 3730);
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 199, v37 * (v42 % 10 + 10));
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 161, 4);
        v43 = mapSize;
        if( v33 )
        {
            if( v33 == 1 )
                v43 = mapSize - 1;
        }
        else
        {
            v43 = mapSize - 2;
        }
        switch ( v43 )
        {
            case 4294967294:
            case 4294967295:
                v44 = debug_rand(aCMsdevWorkAg_3, 3746);
                TribeStrategyAIModule::setRule(
                    &v6->playerAI->strategyAI,
                    73,
                    (((unsigned __int64)v44 >> 32) ^ abs(v44) & 1) - ((unsigned __int64)v44 >> 32) + 14);
                v45 = TribeStrategyAIModule::rule(&v6->playerAI->strategyAI, 73);
                v46 = v45 + (unsigned __int8)((char)debug_rand(aCMsdevWorkAg_3, 3748) % -4) + 1;
                goto LABEL_235;
            case 0:
                v47 = debug_rand(aCMsdevWorkAg_3, 3751);
                TribeStrategyAIModule::setRule(
                    &v6->playerAI->strategyAI,
                    73,
                    (((unsigned __int64)v47 >> 32) ^ abs(v47) & 1) - ((unsigned __int64)v47 >> 32) + 15);
                v48 = TribeStrategyAIModule::rule(&v6->playerAI->strategyAI, 73);
                v49 = v48 + (unsigned __int8)((char)debug_rand(aCMsdevWorkAg_3, 3753) % -4) + 1;
                TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 74, v49);
                break;
            case 1:
                v50 = debug_rand(aCMsdevWorkAg_3, 3756);
                TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 73, v50 % 3 + 16);
                v51 = TribeStrategyAIModule::rule(&v6->playerAI->strategyAI, 73);
                LODWORD(v53) = debug_rand(aCMsdevWorkAg_3, 3758);
                v52 = 5;
                v53 = (signed int)v53;
                goto LABEL_234;
            case 2:
                v54 = debug_rand(aCMsdevWorkAg_3, 3761);
                TribeStrategyAIModule::setRule(
                    &v6->playerAI->strategyAI,
                    73,
                    (((unsigned __int64)v54 >> 32) ^ abs(v54) & 1) - ((unsigned __int64)v54 >> 32) + 17);
                v51 = TribeStrategyAIModule::rule(&v6->playerAI->strategyAI, 73);
                LODWORD(v53) = debug_rand(aCMsdevWorkAg_3, 3763);
                v52 = 6;
                v53 = (signed int)v53;
                goto LABEL_234;
            case 3:
                v55 = debug_rand(aCMsdevWorkAg_3, 3766);
                TribeStrategyAIModule::setRule(
                    &v6->playerAI->strategyAI,
                    73,
                    (((unsigned __int64)v55 >> 32) ^ abs(v55) & 1) - ((unsigned __int64)v55 >> 32) + 18);
                v51 = TribeStrategyAIModule::rule(&v6->playerAI->strategyAI, 73);
                LODWORD(v53) = debug_rand(aCMsdevWorkAg_3, 3768);
                v52 = 7;
                v53 = (signed int)v53;
                goto LABEL_234;
            case 4:
                v56 = debug_rand(aCMsdevWorkAg_3, 3771);
                TribeStrategyAIModule::setRule(
                    &v6->playerAI->strategyAI,
                    73,
                    (((unsigned __int64)v56 >> 32) ^ abs(v56) & 3) - ((unsigned __int64)v56 >> 32) + 18);
                v57 = TribeStrategyAIModule::rule(&v6->playerAI->strategyAI, 73);
                v58 = v57 + (unsigned __int8)((char)debug_rand(aCMsdevWorkAg_3, 3773) % -8) + 1;
                TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 74, v58);
                break;
            default:
                v59 = debug_rand(aCMsdevWorkAg_3, 3777);
                TribeStrategyAIModule::setRule(
                    &v6->playerAI->strategyAI,
                    73,
                    (((unsigned __int64)v59 >> 32) ^ abs(v59) & 1) - ((unsigned __int64)v59 >> 32) + 18);
                v51 = TribeStrategyAIModule::rule(&v6->playerAI->strategyAI, 73);
                LODWORD(v53) = debug_rand(aCMsdevWorkAg_3, 3779);
                v52 = 9;
                v53 = (signed int)v53;
LABEL_234:
                v46 = v51 + (unsigned __int64)(v53 % v52) + 1;
LABEL_235:
                TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 74, v46);
                break;
        }
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 208, 1);
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 209, 1);
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 210, 1);
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 223, 1);
        if( v33 )
        {
            switch ( v33 )
            {
                case 1:
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 212, 2);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 213, 5);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 214, 2);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 224, 4);
                    break;
                case 2:
                case 6:
                case 5:
                case 8:
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 212, 1);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 213, 4);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 214, 1);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 224, 3);
                    break;
                case 3:
                case 4:
                case 7:
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 212, 0);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 213, 0);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 214, 0);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 224, 0);
                    break;
            }
        }
        else
        {
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 212, 3);
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 213, 6);
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 214, 2);
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 224, 6);
        }
        if( allowAIToCheat )
        {
            v60 = 0;
            v61 = 0;
            v62 = 0;
            v63 = 0;
            if( !difficultyLevel )
            {
                v60 = 2000;
                v62 = 2000;
                v63 = 2000;
                v61 = 2000;
            }
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 138, v60);
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 139, v62);
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 140, v63);
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 141, v61);
            v37 = difficultyLevel;
        }
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 168, 0);
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 162, 0);
        if( v37 >= 3 )
        {
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 194, 0);
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 47, 1);
        }
        else
        {
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 194, 1);
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 47, 2);
        }
        if( v37 )
        {
            switch ( v37 )
            {
                case 1:
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 186, 180);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 186, 150);
                    break;
                case 2:
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 186, 180);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 186, 100);
                    break;
                case 3:
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 186, 180);
                    TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 186, 50);
                    break;
            }
        }
        else
        {
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 186, 180);
            TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 186, 200);
        }
        v64 = debug_rand(aCMsdevWorkAg_3, 3920) % 6 < 5;
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 181, v64);
        v65 = debug_rand(aCMsdevWorkAg_3, 3926) % 3 < 1;
        TribeStrategyAIModule::setRule(&v6->playerAI->strategyAI, 182, v65);
    }
}

void TRIBE_Player::setupEgyptian(int *b, int mapType, int gameType, int mapSize)
{
    this->playerAI->logCommonHistory(aSettingUpAsEgy);

    if( rge_base_game->deathMatch() == 1 )
    {
        if( mapType &&
             mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[25] = 60;
                b[63] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[25] = 80;
                b[63] = 20;
            }
            else
            {
                b[25] = 100;
            }
        }
        else
        {
            b[63] = 100;
        }
    }
    else if( rge_base_game->difficulty() >= 1 )
    {
        b[3] = 10;
        b[9] = 10;
        b[10] = 10;
        b[17] = 40;
        b[18] = 40;
        b[46] = 100;
        b[19] = 50;
        b[20] = 50;
        b[47] = 100;
        b[80] = 100;
        b[81] = 30;
        b[82] = 20;

        switch( mapType )
        {
        case 0:
        case 1:
            b[83] = 200;
            break;

        case 2:
        case 5:
        case 6:
        case 8:
            b[83] = 100;
            break;
        }
        if( mapType &&
             mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )

        }
        else
        {

        }
    }
    else
    {
        b[35] = 100;
    }
}

//----- (00517CD0) --------------------------------------------------------
void TRIBE_Player::setupGreek(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsGre);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[26] = 60;
                b[64] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[26] = 80;
                b[64] = 20;
            }
            else
            {
                b[26] = 100;
            }
        }
        else
        {
            b[64] = 100;
        }
    }
    else if( RGE_Base_Game::difficulty(rge_base_game) >= 1 )
    {
        b[6] = 30;
        b[11] = 30;
        b[20] = 30;
        b[9] = 10;
        b[10] = 10;
        b[3] = 70;
        b[4] = 50;
        b[7] = 20;
        b[19] = 50;
        b[48] = 100;
        b[84] = 100;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
            {
                b[85] = 100;
                b[86] = 100;
            }
        }
        else
        {
            b[85] = 200;
            b[86] = 200;
        }
    }
    else
    {
        b[36] = 100;
    }
}

//----- (00517E10) --------------------------------------------------------
void TRIBE_Player::setupBabylonian(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsBab);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[23] = 60;
                b[61] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[23] = 80;
                b[61] = 20;
            }
            else
            {
                b[23] = 100;
            }
        }
        else
        {
            b[61] = 100;
        }
    }
    else
    {
        b[1] = 10;
        b[6] = 10;
        b[9] = 10;
        b[11] = 10;
        *b = 20;
        b[19] = 40;
        b[20] = 40;
        b[16] = 30;
        b[42] = 100;
        b[43] = 100;
        b[3] = 20;
        b[10] = 20;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
                b[77] = 30;
        }
        else
        {
            b[77] = 60;
        }
    }
}

//----- (00517F30) --------------------------------------------------------
void TRIBE_Player::setupAssyrian(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsAss);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[22] = 60;
                b[60] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[22] = 80;
                b[60] = 20;
            }
            else
            {
                b[22] = 100;
            }
        }
        else
        {
            b[60] = 100;
        }
    }
    else if( RGE_Base_Game::difficulty(rge_base_game) >= 1 )
    {
        b[3] = 10;
        b[7] = 10;
        b[9] = 10;
        b[10] = 10;
        b[20] = 10;
        b[72] = 80;
        b[73] = 80;
        b[74] = 80;
        b[16] = 40;
        b[11] = 40;
        b[6] = 20;
        b[19] = 20;
        b[40] = 100;
        b[41] = 100;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
            {
                b[75] = 50;
                b[76] = 50;
            }
        }
        else
        {
            b[75] = 100;
            b[76] = 100;
        }
    }
    else
    {
        b[34] = 100;
    }
}

//----- (00518090) --------------------------------------------------------
void TRIBE_Player::setupMinoan(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsMin);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[28] = 60;
                b[66] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[28] = 80;
                b[66] = 20;
            }
            else
            {
                b[28] = 100;
            }
        }
        else
        {
            b[66] = 100;
        }
    }
    else if( RGE_Base_Game::difficulty(rge_base_game) >= 1 )
    {
        b[4] = 10;
        b[6] = 10;
        b[9] = 10;
        b[10] = 10;
        b[11] = 10;
        *b = 60;
        b[1] = 80;
        b[3] = 20;
        b[51] = 100;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
            {
                b[88] = 100;
                b[89] = 100;
            }
        }
        else
        {
            b[88] = 200;
            b[89] = 200;
        }
    }
    else
    {
        b[37] = 100;
    }
}

//----- (005181C0) --------------------------------------------------------
void TRIBE_Player::setupHittite(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsHit);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[27] = 60;
                b[65] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[27] = 80;
                b[65] = 20;
            }
            else
            {
                b[27] = 100;
            }
        }
        else
        {
            b[65] = 100;
        }
    }
    else
    {
        b[4] = 40;
        b[18] = 40;
        b[16] = 80;
        b[49] = 100;
        b[50] = 100;
        b[3] = 30;
        b[6] = 20;
        b[9] = 10;
        b[10] = 10;
        b[11] = 10;
        b[17] = 20;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
            {
                b[87] = 80;
                *b = 10;
            }
        }
        else
        {
            b[87] = 160;
            *b = 20;
        }
    }
}

//----- (005182E0) --------------------------------------------------------
void TRIBE_Player::setupPhoenician(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsPho);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[30] = 60;
                b[68] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[30] = 80;
                b[68] = 20;
            }
            else
            {
                b[30] = 100;
            }
        }
        else
        {
            b[68] = 100;
        }
    }
    else
    {
        b[3] = 10;
        b[4] = 10;
        b[9] = 10;
        b[10] = 10;
        b[11] = 10;
        b[17] = 70;
        b[18] = 70;
        *b = 20;
        b[6] = 20;
        b[19] = 20;
        b[1] = 40;
        b[20] = 30;
        b[53] = 100;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
                b[92] = 100;
        }
        else
        {
            b[92] = 200;
        }
    }
}

//----- (00518400) --------------------------------------------------------
void TRIBE_Player::setupSumerian(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsSum);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[32] = 60;
                b[70] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[32] = 80;
                b[70] = 20;
            }
            else
            {
                b[32] = 100;
            }
        }
        else
        {
            b[70] = 100;
        }
    }
    else if( RGE_Base_Game::difficulty(rge_base_game) >= 1 )
    {
        b[3] = 10;
        b[9] = 10;
        b[10] = 10;
        b[11] = 10;
        b[4] = 20;
        b[17] = 20;
        b[16] = 30;
        b[57] = 100;
        b[58] = 100;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
            {
                b[94] = 100;
                b[95] = 100;
            }
        }
        else
        {
            b[94] = 200;
            b[95] = 200;
        }
    }
    else
    {
        b[38] = 100;
    }
}

//----- (00518540) --------------------------------------------------------
void TRIBE_Player::setupPersian(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsPer);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[29] = 60;
                b[67] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[29] = 80;
                b[67] = 20;
            }
            else
            {
                b[29] = 100;
            }
        }
        else
        {
            b[67] = 100;
        }
    }
    else
    {
        b[6] = 10;
        b[9] = 10;
        b[10] = 10;
        b[17] = 60;
        b[18] = 60;
        b[1] = 40;
        b[11] = 40;
        b[20] = 40;
        *b = 20;
        b[16] = 20;
        b[7] = 50;
        b[19] = 20;
        b[52] = 100;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
            {
                b[90] = 100;
                b[91] = 100;
            }
        }
        else
        {
            b[90] = 200;
            b[91] = 200;
        }
    }
}

//----- (00518670) --------------------------------------------------------
void TRIBE_Player::setupShang(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsSha);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[31] = 60;
                b[69] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[31] = 80;
                b[69] = 20;
            }
            else
            {
                b[31] = 100;
            }
        }
        else
        {
            b[69] = 100;
        }
    }
    else
    {
        *b = 10;
        b[3] = 10;
        b[9] = 10;
        b[10] = 10;
        b[6] = 50;
        b[7] = 50;
        b[56] = 50;
        b[11] = 30;
        b[20] = 30;
        b[1] = 20;
        b[16] = 20;
        b[19] = 20;
        b[54] = 100;
        b[55] = 100;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
                b[93] = 80;
        }
        else
        {
            b[93] = 160;
        }
    }
}

//----- (005187A0) --------------------------------------------------------
void TRIBE_Player::setupYamato(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsYam);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[33] = 60;
                b[71] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[33] = 80;
                b[71] = 20;
            }
            else
            {
                b[33] = 100;
            }
        }
        else
        {
            b[71] = 100;
        }
    }
    else if( RGE_Base_Game::difficulty(rge_base_game) >= 1 )
    {
        b[3] = 10;
        b[4] = 10;
        b[9] = 10;
        b[10] = 10;
        b[6] = 50;
        b[7] = 50;
        *b = 20;
        b[1] = 20;
        b[16] = 40;
        b[11] = 20;
        b[59] = 100;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
            {
                b[96] = 100;
                b[97] = 100;
            }
        }
        else
        {
            b[96] = 200;
            b[97] = 200;
        }
    }
    else
    {
        b[39] = 100;
    }
}

//----- (005188F0) --------------------------------------------------------
void TRIBE_Player::setupChoson(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsCho);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[24] = 60;
                b[62] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[24] = 80;
                b[62] = 20;
            }
            else
            {
                b[24] = 100;
            }
        }
        else
        {
            b[62] = 100;
        }
    }
    else
    {
        b[1] = 10;
        b[16] = 10;
        b[3] = 10;
        b[7] = 30;
        b[9] = 30;
        b[10] = 30;
        *b = 20;
        b[6] = 20;
        b[11] = 70;
        b[19] = 50;
        b[20] = 90;
        b[44] = 100;
        b[45] = 100;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
            {
                b[78] = 100;
                b[79] = 100;
            }
        }
        else
        {
            b[78] = 200;
            b[79] = 200;
        }
    }
}

//----- (00518A20) --------------------------------------------------------
void TRIBE_Player::setupRoman(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsRom);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[120] = 60;
                b[124] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[120] = 80;
                b[124] = 20;
            }
            else
            {
                b[120] = 100;
            }
        }
        else
        {
            b[124] = 100;
        }
    }
    else
    {
        *b = 10;
        b[6] = 10;
        b[9] = 10;
        b[10] = 10;
        b[19] = 10;
        b[20] = 10;
        b[3] = 20;
        b[4] = 20;
        b[11] = 80;
        b[112] = 100;
        b[113] = 60;
        b[114] = 80;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
            {
                b[115] = 100;
                b[116] = 100;
            }
        }
        else
        {
            b[115] = 200;
            b[116] = 200;
        }
    }
}

//----- (00518B50) --------------------------------------------------------
void TRIBE_Player::setupCarthaginian(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsCar);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[117] = 60;
                b[121] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[117] = 80;
                b[121] = 20;
            }
            else
            {
                b[117] = 100;
            }
        }
        else
        {
            b[121] = 100;
        }
    }
    else
    {
        *b = 10;
        b[1] = 10;
        b[16] = 10;
        b[7] = 10;
        b[9] = 10;
        b[10] = 10;
        b[11] = 10;
        b[17] = 60;
        b[18] = 60;
        b[3] = 70;
        b[98] = 80;
        b[99] = 80;
        b[4] = 50;
        b[6] = 30;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
            {
                b[100] = 100;
                b[101] = 100;
            }
        }
        else
        {
            b[100] = 200;
            b[101] = 200;
        }
    }
}

//----- (00518C90) --------------------------------------------------------
void TRIBE_Player::setupPalmyran(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsPal);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[119] = 60;
                b[123] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[119] = 80;
                b[123] = 20;
            }
            else
            {
                b[119] = 100;
            }
        }
        else
        {
            b[123] = 100;
        }
    }
    else
    {
        b[3] = 40;
        b[6] = 40;
        *b = 30;
        b[7] = 10;
        b[9] = 10;
        b[10] = 10;
        b[11] = 10;
        b[1] = 30;
        b[107] = 80;
        b[108] = 80;
        b[109] = 80;
        b[16] = 60;
        b[4] = 20;
        b[17] = 60;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
            {
                b[110] = 100;
                b[111] = 100;
            }
        }
        else
        {
            b[110] = 200;
            b[111] = 200;
        }
    }
}

//----- (00518DD0) --------------------------------------------------------
void TRIBE_Player::setupMacedonian(int *b, int mapType, int gameType, int mapSize)
{
    AIModule::logCommonHistory((AIModule *)&this->playerAI->vfptr, aSettingUpAsMac);
    if( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
    {
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 )
            {
                b[118] = 60;
                b[122] = 40;
            }
            else if( mapType == 5 || mapType == 8 )
            {
                b[118] = 80;
                b[122] = 20;
            }
            else
            {
                b[118] = 100;
            }
        }
        else
        {
            b[122] = 100;
        }
    }
    else
    {
        b[3] = 40;
        b[4] = 40;
        *b = 10;
        b[6] = 30;
        b[7] = 30;
        b[17] = 30;
        b[104] = 80;
        b[102] = 80;
        b[103] = 80;
        b[1] = 10;
        b[16] = 20;
        if( mapType && mapType != 1 )
        {
            if( mapType == 2 || mapType == 6 || mapType == 8 || mapType == 5 )
            {
                b[105] = 100;
                b[106] = 100;
            }
        }
        else
        {
            b[105] = 200;
            b[106] = 200;
        }
    }
}

//----- (00518F00) --------------------------------------------------------
void TRIBE_Player::logStatus(_iobuf *out, int firstTime)
{
    TRIBE_Player *v3; // esi@1
    char *v4; // eax@5
    char *v5; // eax@5
    char *v6; // ST28_4@5
    int v7; // eax@6
    int v8; // eax@6
    int v9; // eax@6
    int v10; // eax@6
    int v11; // eax@6
    int v12; // eax@6
    int v13; // eax@6
    int v14; // eax@6
    int v15; // eax@6
    int v16; // eax@6
    int v17; // eax@6
    int v18; // eax@6
    TribeMainDecisionAIModule *v19; // eax@6
    int v20; // ST28_4@7
    int v21; // ST24_4@7
    char *v22; // ST20_4@7
    char *v23; // eax@7
    int v24; // ST28_4@7
    int v25; // ST24_4@7
    int v26; // ST20_4@7
    int v27; // ST1C_4@7
    int v28; // ST18_4@7
    int v29; // ST14_4@7
    int v30; // ST10_4@7
    int v31; // ST0C_4@7
    int v32; // eax@7
    int v33; // eax@7
    char tempString[256]; // [sp+Ch] [bp-100h]@3

    v3 = this;
    if( out )
    {
        fprintf(out, aPlayerD_1, this->id);
        if( firstTime == 1 )
        {
            (*(void (__stdcall **)(int, char *, signed int))&rge_base_game->vfptr->gap8[24])(
                v3->master_player_id + 10230,
                tempString,
                256);
            if( v3->playerAI )
            {
                fprintf(out, aComputerPlayer, tempString);
                v4 = BuildAIModule::buildListName((BuildAIModule *)&v3->playerAI->buildAI.vfptr);
                fprintf(out, aBuildListS_, v4);
                v5 = ConstructionAIModule::constructionPlanName((ConstructionAIModule *)&v3->playerAI->constructionAI.vfptr);
                fprintf(out, aCityPlanS_, v5);
                v6 = TribeStrategyAIModule::ruleSetName(&v3->playerAI->strategyAI);
                fprintf(out, aVcFileS_, v6);
            }
            else
            {
                fprintf(out, aHumanPlayerS_, tempString);
            }
        }
        fprintf(out, aPoints);
        v7 = RGE_Victory_Conditions::get_victory_points_group(v3->victory_conditions, 0);
        fprintf(out, aCombatD_, v7);
        v8 = RGE_Victory_Conditions::get_victory_points_group(v3->victory_conditions, 1);
        fprintf(out, aEconomyD_, v8);
        v9 = RGE_Victory_Conditions::get_victory_points_group(v3->victory_conditions, 2);
        fprintf(out, aReligionD_, v9);
        v10 = RGE_Victory_Conditions::get_victory_points_group(v3->victory_conditions, 3);
        fprintf(out, aScienceD_, v10);
        v11 = RGE_Victory_Conditions::get_victory_points_id(v3->victory_conditions, 22);
        fprintf(out, aSurvivalD_, v11);
        v12 = RGE_Victory_Conditions::get_victory_points_id(v3->victory_conditions, 23);
        fprintf(out, aWonderD_, v12);
        v13 = RGE_Victory_Conditions::get_victory_points(v3->victory_conditions);
        fprintf(out, aTotalD_, v13);
        fprintf(out, aPopulationD_, (unsigned int)(signed __int64)v3->attributes[11]);
        v14 = RGE_Victory_Conditions::get_attribute_id(v3->victory_conditions, 0);
        fprintf(out, aKillsD_, v14);
        v15 = RGE_Victory_Conditions::get_attribute_id(v3->victory_conditions, 2);
        fprintf(out, aKillRatioD_, v15);
        v16 = RGE_Victory_Conditions::get_attribute_id(v3->victory_conditions, 1);
        fprintf(out, aRazingsD_, v16);
        fprintf(out, aFoodD_, (unsigned int)(signed __int64)*v3->attributes);
        fprintf(out, aGoldD_, (unsigned int)(signed __int64)v3->attributes[3]);
        fprintf(out, aStoneD_, (unsigned int)(signed __int64)v3->attributes[2]);
        fprintf(out, aWoodD_, (unsigned int)(signed __int64)v3->attributes[1]);
        v17 = RGE_Victory_Conditions::get_attribute_id(v3->victory_conditions, 17);
        fprintf(out, aTechnologyD_, v17);
        v18 = RGE_Victory_Conditions::get_attribute_id(v3->victory_conditions, 7);
        fprintf(out, aExplorationD_, v18);
        v19 = v3->playerAI;
        if( v19 )
        {
            v20 = BuildAIModule::buildListLength((BuildAIModule *)&v19->buildAI.vfptr);
            v21 = BuildAIModule::numberItemsIntoBuildList((BuildAIModule *)&v3->playerAI->buildAI.vfptr);
            v22 = BuildAIModule::lastBuildItemRequested((BuildAIModule *)&v3->playerAI->buildAI.vfptr);
            v23 = BuildAIModule::currentBuildItemRequested((BuildAIModule *)&v3->playerAI->buildAI.vfptr);
            fprintf(out, aBuildAiLastSLa, v23, v22, v21, v20);
            v24 = TribeTacticalAIModule::neededResource(&v3->playerAI->tacticalAI, 3);
            v25 = TribeTacticalAIModule::neededResource(&v3->playerAI->tacticalAI, 2);
            v26 = TribeTacticalAIModule::neededResource(&v3->playerAI->tacticalAI, 1);
            v27 = TribeTacticalAIModule::neededResource(&v3->playerAI->tacticalAI, 0);
            v28 = TribeTacticalAIModule::desiredNumberGatherers(&v3->playerAI->tacticalAI);
            v29 = TribeTacticalAIModule::numberGatherers(&v3->playerAI->tacticalAI);
            v30 = TribeTacticalAIModule::desiredNumberCivilianExplorers(&v3->playerAI->tacticalAI);
            v31 = TribeTacticalAIModule::numberCivilianExplorers(&v3->playerAI->tacticalAI);
            v32 = TribeTacticalAIModule::numberCivilians(&v3->playerAI->tacticalAI);
            fprintf(out, aCiviliansTotal, v32, v31, v30, v29, v28, v27, v26, v25, v24);
            v33 = TribeTacticalAIModule::numberSoldiers(&v3->playerAI->tacticalAI);
            fprintf(out, aNumberSoldiers, v33);
        }
    }
}

//----- (005192F0) --------------------------------------------------------
void TRIBE_Player::trackUnitGather(int unitID, int attributeID, int amount)
{
    TribeMainDecisionAIModule *v4; // eax@1

    v4 = this->playerAI;
    if( v4 )
        TribeTacticalAIModule::trackUnitGather(&v4->tacticalAI, unitID, attributeID, amount);
}

//----- (00519320) --------------------------------------------------------
void TRIBE_Player::get_achievement(char achievement, char *info)
{
    unsigned __int64 v3; // st7@3
    double v4; // st7@7

    switch ( achievement )
    {
        case 0:
            strcpy(info, this->name);
            return;
        case 1:
            *(double *)&v3 = this->attributes[19] - this->attributes[11];
            goto LABEL_11;
        case 2:
            sprintf(info, a4_f, this->attributes[20]);
            return;
        case 3:
            sprintf(info, a4_f, this->attributes[11]);
            return;
        case 4:
            sprintf(info, a5_f, this->attributes[3]);
            return;
        case 5:
            v4 = RGE_Visible_Map::percentExplored(this->visible);
            sprintf(info, a3_f, v4 * 100.0);
            return;
        case 6:
            *(double *)&v3 = this->attributes[19];
            goto LABEL_11;
        case 7:
            sprintf(info, a4_f4_f4_f, this->attributes[7], this->attributes[13], this->attributes[14]);
            break;
        case 8:
            *(double *)&v3 = this->attributes[21];
LABEL_11:
            sprintf(info, a4_f, (_DWORD)v3, (_DWORD)(v3 >> 32));
            break;
        default:
            return;
    }
}

void TRIBE_Player::load_victory(int infile, int *player_id_hash, char version_control)
{
    TRIBE_Player *v6; // esi@1
    TRIBE_Victory_Conditions *v7; // eax@1
    RGE_Victory_Conditions *v8; // eax@2

    v6 = this;
    v7 = (TRIBE_Victory_Conditions *)operator new(0x20u);
    if( v7 )
        TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(
            v7,
            a2,
            a3,
            (RGE_Player *)&v6->vfptr,
            infile,
            player_id_hash,
            version_control);
    else
        v8 = 0;
    v6->victory_conditions = v8;
}

void TRIBE_Player::new_victory()
{
    TRIBE_Player *v1; // esi@1
    TRIBE_Victory_Conditions *v2; // eax@1
    RGE_Victory_Conditions *v3; // eax@2

    v1 = this;
    v2 = (TRIBE_Victory_Conditions *)operator new(0x20u);
    if( v2 )
    {
        TRIBE_Victory_Conditions::TRIBE_Victory_Conditions(v2, (RGE_Player *)&v1->vfptr);
        v1->victory_conditions = v3;
    }
    else
    {
        v1->victory_conditions = 0;
    }
}

void TRIBE_Player::add_attribute_num(short attribute, float amount, char earned)
{
    TRIBE_Player *v4; // esi@1
    RGE_Game_World *v5; // ecx@5

    v4 = this;
    if( attribute == 3 && earned )
        this->attributes[49] = amount + this->attributes[49];
    if( attribute == 50 )
    {
        v5 = this->world;
        v4->allied_LOS_Enable = 1;
        RGE_Game_World::update_mutual_allies(v5);
    }
    RGE_Player::add_attribute_num((RGE_Player *)&v4->vfptr, attribute, amount, earned);
}

void TRIBE_Player::analyize_selected_objects()
{
    signed int v1; // esi@1
    bool v2; // zf@1
    signed int v3; // edi@2
    char *v4; // edx@2
    int v5; // eax@4
    int v6; // eax@6
    unsigned int v7; // eax@10
    int v8; // eax@12
    unsigned int v9; // eax@16

    v1 = 0;
    PriestCount = 0;
    v2 = this->sel_count == 0;
    this->sel_object_properties = 0;
    if( !v2 )
    {
        v3 = 0;
        v4 = (char *)this->sel_list;
        do
        {
            if( v3 >= this->sel_count )
                break;
            v5 = *(_DWORD *)v4;
            if( *(_DWORD *)v4 )
            {
                if( *(_WORD *)(*(_DWORD *)(v5 + 12) + 74) == this->id )
                {
                    v6 = *(_WORD *)(*(_DWORD *)(v5 + 8) + 20);
                    if( v6 >= 0 && v6 < tribe_group_properties_num )
                    {
                        if( v6 == 18 )
                        {
                            this->sel_object_properties |= 0x16u;
                            ++PriestCount;
                            PriestId = *(_DWORD *)(*(_DWORD *)v4 + 4);
                            if( *(float *)(*(_DWORD *)v4 + 68) >= 100.0 )
                            {
                                v7 = this->sel_object_properties;
                                LOBYTE(v7) = v7 | 0x80;
                                this->sel_object_properties = v7;
                            }
                        }
                        else
                        {
                            this->sel_object_properties |= (unsigned int)(&tribe_group_properties)[v6];
                        }
                    }
                    v8 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)v4 + 8) + 16);
                    if( v8 == 79 || v8 == 199 || v8 == 69 || v8 == 278 )
                    {
                        v9 = this->sel_object_properties;
                        LOBYTE(v9) = v9 | 1;
                        this->sel_object_properties = v9;
                    }
                }
                ++v3;
            }
            ++v1;
            v4 += 4;
        }
        while( v1 < 25 );
    }
}

int TRIBE_Player::get_mouse_pointer_action_vars(int Obj_id, int *newFacet, int *text_id)
{
    TRIBE_Player *v4; // edi@1
    RGE_Static_Object *v5; // eax@1
    int *v6; // ebx@1
    RGE_Static_Object *v7; // ecx@1
    int v8; // esi@1
    signed int v9; // ebp@1
    RGE_Player *v10; // eax@3
    signed int v11; // ecx@3
    RGE_Master_Static_Object *v12; // eax@4
    char *v13; // edi@12
    void *v14; // ecx@12
    int v15; // edx@14
    signed int v16; // eax@19
    char *v17; // edx@20
    unsigned int v18; // eax@28
    signed int v19; // esi@28
    int result; // eax@45
    signed __int64 v21; // rax@60
    signed __int64 v22; // rax@66
    int ObjectType; // [sp+10h] [bp-1Ch]@3
    int ObjPlayer; // [sp+14h] [bp-18h]@3
    RGE_Static_Object *thisObj; // [sp+18h] [bp-14h]@1
    int MaxHp; // [sp+1Ch] [bp-10h]@3
    int MstrObjId; // [sp+20h] [bp-Ch]@3
    int RtClickTable; // [sp+24h] [bp-8h]@12
    TRIBE_Player *v29; // [sp+28h] [bp-4h]@1

    v4 = this;
    v29 = this;
    v5 = RGE_Game_World::object(this->world, Obj_id);
    v6 = newFacet;
    v7 = v5;
    v8 = 0;
    v9 = 0;
    *newFacet = 0;
    thisObj = v5;
    *text_id = 0;
    if( v5 )
    {
        if( v5->type == 25 )
        {
            v10 = v5[1].owner;
            v11 = (signed int)v7[1].sprite;
            ObjPlayer = v11;
            ObjectType = LOWORD(v10->checksum);
            MstrObjId = LOWORD(v10->currentUpdatePathingAttemptsValue);
            MaxHp = HIWORD(v10->master_objects);
        }
        else
        {
            v12 = v5->master_obj;
            ObjectType = v12->object_group;
            ObjPlayer = v7->owner->id;
            MstrObjId = v12->id;
            v11 = v7->owner->id;
            MaxHp = v12->hp;
        }
        if( v11 >= 0 && v11 < v4->world->player_num )
        {
            v4->vfptr->analyize_selected_objects((RGE_Player *)v4);
            if( MstrObjId == 158 || MstrObjId == 163 )
                v9 = 50;
            while( 1 )
            {
                if( v4->sel_count && v4->sel_object_properties )
                {
                    RtClickTable = 1;
                    v13 = (char *)rge_base_game[1].vfptr;
                    v14 = rge_base_game[1].player_game_info;
                }
                else
                {
                    RtClickTable = 0;
                    v13 = rge_base_game[1].scenario_info->filename;
                    v14 = rge_base_game[1].prog_info;
                }
                v15 = ObjectType;
                if( ObjectType >= 0 && ObjectType < (signed int)v14 && *(_DWORD *)&v13[44 * ObjectType] == ObjectType )
                    v8 = (int)&v13[44 * ObjectType];
                if( !v8 )
                {
                    v16 = 0;
                    if( (signed int)v14 > 0 )
                    {
                        v17 = v13;
                        while( *(_DWORD *)v17 != ObjectType )
                        {
                            ++v16;
                            v17 += 44;
                            if( v16 >= (signed int)v14 )
                                goto LABEL_25;
                        }
                        v8 = (int)&v13[44 * v16];
LABEL_25:
                        v6 = newFacet;
                        v15 = ObjectType;
                    }
                    if( !v8 )
                        break;
                }
                switch ( v29->unitDiplomacy[ObjPlayer] )
                {
                    case 0:
                        v18 = *(_DWORD *)(v8 + 12);
                        v19 = *(_DWORD *)(v8 + 16);
                        break;
                    case 1:
                        v18 = *(_DWORD *)(v8 + 4);
                        v19 = *(_DWORD *)(v8 + 8);
                        break;
                    case 2:
                        v18 = *(_DWORD *)(v8 + 20);
                        v19 = *(_DWORD *)(v8 + 24);
                        break;
                    case 3:
                        v18 = *(_DWORD *)(v8 + 28);
                        v19 = *(_DWORD *)(v8 + 32);
                        break;
                    case 4:
                        v18 = *(_DWORD *)(v8 + 36);
                        v19 = *(_DWORD *)(v8 + 40);
                        break;
                    default:
                        v18 = -1;
                        v19 = -1;
                        break;
                }
                if( v18 == -1 )
                    break;
                while( 2 )
                {
                    switch ( v18 )
                    {
                        case 1u:
                        case 8u:
                            if( v29->sel_object_properties & 1 && thisObj->object_state <= 2u )
                            {
                                *v6 = 4;
                                *text_id = v9 + v19;
                            }
                            else if( v18 == 8 )
                            {
                                v9 = 50;
                                v18 = 7;
                                goto LABEL_43;
                            }
                            break;
                        case 6u:
                        case 9u:
                            if( v29->sel_object_properties & 0x40 )
                            {
                                *v6 = 3;
                                *text_id = v9 + v19;
                            }
                            else if( v18 == 9 )
                            {
                                v9 = 50;
                                v18 = 1;
LABEL_43:
                                if( v18 <= 9 )
                                    continue;
                                goto LABEL_44;
                            }
                            break;
                        case 0u:
                            *v6 = 0;
                            *text_id = v9 + v19;
                            break;
                        case 2u:
                            if( v29->sel_object_properties & 2 )
                                goto LABEL_62;
                            break;
                        case 3u:
                            if( v29->sel_object_properties & 4 )
                            {
                                *v6 = 5;
                                *text_id = v9 + v19;
                            }
                            break;
                        case 4u:
                            if( v29->sel_object_properties & 0x10 && (PriestCount != 1 || Obj_id != PriestId) )
                            {
                                v21 = (signed __int64)thisObj->hp;
                                if( (signed int)v21 > 0 && (signed int)v21 < MaxHp )
                                {
LABEL_62:
                                    *v6 = 5;
                                    *text_id = v9 + v19;
                                }
                            }
                            break;
                        case 5u:
                            if( v29->sel_object_properties & 0x20 )
                            {
                                if( !thisObj->object_state )
                                    v9 = 50;
                                v22 = (signed __int64)thisObj->hp;
                                if( (signed int)v22 > 0 && (signed int)v22 < MaxHp )
                                {
                                    *v6 = 3;
                                    *text_id = v9 + v19;
                                }
                            }
                            break;
                        case 7u:
                            if( v29->sel_object_properties & 0x80
                                && (v15 != 18 || v29->attributes[27] != 0.0)
                                && (v15 != 3 || v29->attributes[28] != 0.0 && MstrObjId != 109 && MstrObjId != 276) )
                            {
                                *v6 = 5;
                                *text_id = v9 + v19;
                            }
                            break;
                        default:
LABEL_44:
                            *v6 = 0;
                            *text_id = 0;
                            break;
                    }
                    break;
                }
                result = 1;
                if( RtClickTable != 1 )
                    return result;
                v8 = 0;
                if( *v6 || *text_id )
                    return result;
                v29->sel_object_properties = 0;
                v4 = v29;
            }
        }
    }
    return 0;
}

//----- (00519AF0) --------------------------------------------------------
void TRIBE_Gaia::TRIBE_Gaia(TRIBE_Gaia *this@<ecx>, int a2@<ebp>, int infile, TRIBE_World *gworld, char this_id)
{
    TRIBE_Gaia *v5; // esi@1
    int v6; // edi@1

    v5 = this;
    v6 = infile;
    TRIBE_Player::TRIBE_Player((TRIBE_Player *)&this->vfptr, infile, gworld, this_id);
    v5->vfptr = (RGE_PlayerVtbl *)&TRIBE_Gaia::`vftable';
    v5->type = 2;
    rge_read(a2, v6, v6, &v5->update_time, 4);
    rge_read(a2, v6, v6, &v5->update_nature, 4);
    rge_read(a2, v6, v6, &v5->animal_max, 4);
    rge_read(a2, v6, v6, &v5->last_count, 4);
}
// 5769A0: using guessed type int (__thiscall *TRIBE_Gaia::`vftable')(void *Memory, unsigned int __flags);

//----- (00519BA0) --------------------------------------------------------
TRIBE_Gaia *TRIBE_Gaia::`vector deleting destructor'(TRIBE_Gaia *this, unsigned int __flags)
{
    TRIBE_Gaia *v2; // esi@1

    v2 = this;
    TRIBE_Gaia::~TRIBE_Gaia(this);
    if( __flags & 1 )
        operator delete(v2);
    return v2;
}

//----- (00519BD0) --------------------------------------------------------
void TRIBE_Gaia::TRIBE_Gaia(TRIBE_Gaia *this, TRIBE_World *gworld, RGE_Master_Player *prototype, char this_id, char *new_name, char m_player_id)
{
    TRIBE_Gaia *v6; // esi@1

    v6 = this;
    TRIBE_Player::TRIBE_Player(
        (TRIBE_Player *)&this->vfptr,
        gworld,
        prototype,
        this_id,
        new_name,
        m_player_id,
        0,
        1,
        0,
        0,
        0);
    v6->vfptr = (RGE_PlayerVtbl *)&TRIBE_Gaia::`vftable';
    v6->type = 2;
    LODWORD(v6->update_time) = 0;
    v6->update_nature = 29;
    v6->animal_max = 0;
    v6->last_count = 0;
}
// 5769A0: using guessed type int (__thiscall *TRIBE_Gaia::`vftable')(void *Memory, unsigned int __flags);

//----- (00519C40) --------------------------------------------------------
void TRIBE_Gaia::save(TRIBE_Gaia *this, int outfile)
{
    TRIBE_Gaia *v2; // esi@1

    v2 = this;
    TRIBE_Player::save((TRIBE_Player *)&this->vfptr, outfile);
    rge_write(outfile, &v2->update_time, 4);
    rge_write(outfile, &v2->update_nature, 4);
    rge_write(outfile, &v2->animal_max, 4);
    rge_write(outfile, &v2->last_count, 4);
}

//----- (00519CA0) --------------------------------------------------------
void TRIBE_Gaia::update()
{
    unsigned __int8 v2; // c0@1
    unsigned __int8 v3; // c3@1
    double v4; // st7@2
    int v5; // eax@2

    this->update_time = this->world->world_time_delta_seconds + this->update_time;
    if( !(v2 | v3) )
    {
        do
        {
            v4 = this->update_time - 1.0;
            v5 = this->update_nature + 1;
            this->update_nature = v5;
            this->update_time = v4;
            if( v5 == 30 )
                this->update_nature = 0;
        }
        while( this->update_time > 1.0 );
    }
    RGE_Player::update((RGE_Player *)&this->vfptr);
}

void TRIBE_Gaia::load_master_object(int infile, short index, char type, RGE_Sprite **sprites, RGE_Sound **sounds)
{
    TRIBE_Player::load_master_object((TRIBE_Player *)&this->vfptr, a2, infile, index, type, sprites, sounds);
}

void TRIBE_Player::scenario_postload(int infile, int *player_id_hash, float version)
{
    TRIBE_Player *v5; // esi@1
    RGE_Game_World *v6; // ecx@2

    v5 = this;
    RGE_Player::scenario_postload((RGE_Player *)&this->vfptr, a2, infile, player_id_hash, version);
    if( v5->attributes[50] > 0.0 )
    {
        v6 = v5->world;
        v5->allied_LOS_Enable = 1;
        RGE_Game_World::update_mutual_allies(v6);
    }
}
