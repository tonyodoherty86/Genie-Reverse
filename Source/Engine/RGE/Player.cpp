
/**
 * @file    Engine\RGE\Player.cpp
 * @author  Yvan Burrie
 * @date    2018/07/05
 * @version 1.0
 */

RGE_Player::RGE_Player(
    int infile,
    RGE_Game_World *gworld,
    char this_id)
{
    this->computerPlayerValue = 0;
    this->pathingAttemptCapValue = 5;
    this->pathingDelayCapValue = 10;

    this->tile_list->RGE_Tile_List(400);
    this->diam_tile_list->RGE_Tile_List(400);

    this->id = this_id;
    this->pathingAttemptCapValue = pathingCapValue;
    this->world = gworld;
    this->reset_selected();
    this->doppleganger_creator = new RGE_Doppleganger_Creator(this, 100);
    this->relations = new char[this->player_num];
    rge_read(infile, this->relations, this->world->player_num);
    rge_read(infile, this->unitDiplomacy, 4 * RGE_PLAYERS_COUNT);

    if( save_game_version >= 4.01 ){
        rge_read(infile, &this->allied_LOS_Enable, 4);
    }else{
        this->allied_LOS_Enable = 0;
    }
    rge_read(infile, &this->allied_victory, 1);
    rge_read(infile, &index, 2);
    if( index > 0 ){
        v12 = (char *)calloc(index, 1u);
        v13 = index;
        this->name = v12;
        rge_read(0, infile, infile, v12, v13);
    }else{
        this->name = NULL;
    }

    rge_read(infile, &this->attribute_num, 2);
    if( this->attribute_num > 0 ){
        this->attributes = new float[this->attribute_num];
        rge_read(infile, this->attributes, 4 * this->attribute_num);
    }else{
        this->attributes = nullptr;
    }
    rge_read(infile, &this->view_x, 4);
    rge_read(infile, &this->view_y, 4);
    rge_read(infile, &this->map_x, 2);
    rge_read(infile, &this->map_y, 2);
    rge_read(infile, &this->culture, 1);
    rge_read(infile, &this->master_player_id, 1);
    rge_read(infile, &this->game_status, 1);
    rge_read(infile, &this->resigned, 1);
    rge_read(infile, &table, 1);
    this->set_color_table(table);
    rge_read(infile, v5, 4);
    rge_read(infile, &this->pathingDelayCapValue, 4);

    this->checksum_created_this_update = 0;
    this->checksum = 0;
}

RGE_Player::RGE_Player(
    RGE_Game_World *gworld,
    RGE_Master_Player *prototype,
    char this_id,
    char *new_name,
    char m_player_id,
    char flag)
{
    RGE_Player *v7; // ebp@1
    short v8; // si@1
    short v9; // cx@3
    short v10; // ax@10
    RGE_Master_Static_Object **v11; // eax@11
    short v12; // di@11
    bool v13; // zf@11
    bool v14; // sf@11
    int v15; // esi@12
    RGE_Master_Static_Object *v16; // ecx@12
    RGE_Object_List *v17; // eax@17
    RGE_Object_List *v18; // eax@18
    RGE_Object_List *v19; // eax@20
    RGE_Object_List *v20; // eax@21
    RGE_Object_List *v21; // eax@23
    RGE_Object_List *v22; // eax@24
    RGE_Visible_Map *v23; // eax@26
    RGE_Visible_Map *v24; // eax@27
    RGE_Doppleganger_Creator *v25; // eax@30
    RGE_Doppleganger_Creator *v26; // eax@31
    short v27; // ax@33
    float *v28; // eax@34
    unsigned int v29; // ecx@34
    RGE_Game_World *v30; // edx@36
    RGE_Map *v31; // ecx@36
    float y; // ST04_4@36
    float x; // ST00_4@36
    int v34; // eax@36

    v7 = this;
    v8 = 0;
    this->computerPlayerValue = 0;
    this->pathingAttemptCapValue = 5;
    this->pathingDelayCapValue = 10;
    RGE_Tile_List::RGE_Tile_List(&this->tile_list, 400);
    RGE_Tile_List::RGE_Tile_List(&v7->diam_tile_list, 400);
    v7->pathingAttemptCapValue = pathingCapValue;
    v7->master_player_id = m_player_id;
    v7->type = 0;
    v7->world = gworld;
    v7->id = (unsigned __int8)this_id;
    RGE_Player::reset_selected(v7);
    v7->name = 0;
    if( new_name )
        getstring(&v7->name, new_name);
    v7->relations = (char *)calloc(1u, v7->world->player_num);
    memset(v7->unitDiplomacy, 0xFFu, sizeof(v7->unitDiplomacy));
    v9 = 0;
    if( v7->world->player_num > 0 )
    {
        do
        {
            v7->relations[v9] = 1;
            if( v9 == v7->id )
            {
                v7->unitDiplomacy[v9] = 1;
            }
            else if( v9 )
            {
                v7->unitDiplomacy[v9] = 3;
            }
            else
            {
                v7->unitDiplomacy[0] = 0;
            }
            ++v9;
        }
        while( v9 < v7->world->player_num );
    }
    v7->mutualExploredMask = 0;
    v7->mutualVisibleMask = 0;
    v7->nonMutualVisibleMask = 0;
    v7->allied_LOS_Enable = 0;
    v7->allied_victory = 0;
    v10 = prototype->master_object_num;
    v7->master_object_num = v10;
    if( v10 > 0 )
    {
        v11 = (RGE_Master_Static_Object **)calloc(v10, 4u);
        v12 = 0;
        v13 = v7->master_object_num == 0;
        v14 = v7->master_object_num < 0;
        v7->master_objects = v11;
        if( !v14 && !v13 )
        {
            do
            {
                v15 = v12;
                v16 = prototype->master_objects[v15];
                if( v16 )
                    v7->master_objects[v15] = (RGE_Master_Static_Object *)((int (*)(void))v16->vfptr->make_new_master)();
                ++v12;
            }
            while( v12 < v7->master_object_num );
            v8 = 0;
        }
    }
    if( flag )
    {
        v17 = (RGE_Object_List *)operator new(0xCu);
        if( v17 )
            RGE_Object_List::RGE_Object_List(v17);
        else
            v18 = 0;
        v7->objects = v18;
        v19 = (RGE_Object_List *)operator new(0xCu);
        if( v19 )
            RGE_Object_List::RGE_Object_List(v19);
        else
            v20 = 0;
        v7->sleeping_objects = v20;
        v21 = (RGE_Object_List *)operator new(0xCu);
        if( v21 )
            RGE_Object_List::RGE_Object_List(v21);
        else
            v22 = 0;
        v7->doppleganger_objects = v22;
        RGE_Player::new_victory(v7);
        v23 = (RGE_Visible_Map *)operator new(0x38u);
        if( v23 )
        {
            RGE_Visible_Map::RGE_Visible_Map(v23, gworld->map, v7);
            v7->visible = v24;
        }
        else
        {
            v7->visible = 0;
        }
    }
    else
    {
        v7->objects = 0;
        v7->sleeping_objects = 0;
        v7->doppleganger_objects = 0;
        v7->victory_conditions = 0;
        v7->visible = 0;
    }
    v25 = (RGE_Doppleganger_Creator *)operator new(0x1Cu);
    if( v25 )
        RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(v25, v7, 100);
    else
        v26 = 0;
    v7->doppleganger_creator = v26;
    v27 = prototype->attribute_num;
    v7->attribute_num = v27;
    if( v27 <= v8 )
    {
        v7->attributes = 0;
    }
    else
    {
        v28 = (float *)calloc(v27, 4u);
        v29 = 4 * v7->attribute_num;
        v7->attributes = v28;
        qmemcpy(v28, prototype->attributes, v29);
    }
    v30 = v7->world;
    v7->culture = prototype->culture;
    v31 = v30->map;
    y = (double)(v31->map_height / 2);
    x = (double)(v31->map_width / 2);
    RGE_Player::set_view_loc(v7, x, y);
    RGE_Player::set_map_loc(v7, v7->world->map->map_width / 2, v7->world->map->map_height / 2);
    v7->game_status = 0;
    v7->resigned = 0;
    v7->color_table = 0;
    v34 = prototype->tribe_effect;
    v7->tribe_effect = v34;
    if( flag && v34 >= 0 )
    {
        LOWORD(v34) = v7->tribe_effect;
        ((void (__stdcall *)(int, RGE_Player *))v7->world->effects->vfptr->do_effect)(v34, v7);
    }
    v7->checksum = 0;
    v7->checksum_created_this_update = 0;
}

RGE_Player::~RGE_Player()
{
    RGE_Player *v1; // esi@1
    RGE_Object_List *v2; // edi@1
    RGE_Object_List *v3; // edi@3
    RGE_Object_List *v4; // edi@5
    RGE_Victory_Conditions *v5; // edi@7
    short v6; // ax@9
    short v7; // di@10
    RGE_Master_Static_Object *v8; // ecx@11
    RGE_Visible_Map *v9; // edi@15
    RGE_Doppleganger_Creator *v10; // edi@17
    Visible_Resource_Manager *v11; // edi@19

    v1 = this;
    v2 = this->objects;
    if( v2 )
    {
        RGE_Object_List::~RGE_Object_List(v2);
        operator delete(v2);
    }
    v3 = v1->sleeping_objects;
    if( v3 )
    {
        RGE_Object_List::~RGE_Object_List(v1->sleeping_objects);
        operator delete(v3);
    }
    v4 = v1->doppleganger_objects;
    if( v4 )
    {
        RGE_Object_List::~RGE_Object_List(v1->doppleganger_objects);
        operator delete(v4);
    }
    v5 = v1->victory_conditions;
    if( v5 )
    {
        RGE_Victory_Conditions::~RGE_Victory_Conditions(v1->victory_conditions);
        operator delete(v5);
    }
    free(v1->relations);
    v6 = v1->master_object_num;
    v1->relations = 0;
    if( v6 > 0 )
    {
        v7 = 0;
        if( v6 > 0 )
        {
            do
            {
                v8 = v1->master_objects[v7];
                if( v8 )
                    ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
                ++v7;
            }
            while( v7 < v1->master_object_num );
        }
        free(v1->master_objects);
        v1->master_objects = 0;
        v1->master_object_num = 0;
    }
    v9 = v1->visible;
    if( v9 )
    {
        RGE_Visible_Map::~RGE_Visible_Map(v1->visible);
        operator delete(v9);
    }
    v10 = v1->doppleganger_creator;
    if( v10 )
    {
        RGE_Doppleganger_Creator::~RGE_Doppleganger_Creator(v1->doppleganger_creator);
        operator delete(v10);
    }
    v11 = v1->VR_List;
    if( v11 )
    {
        Visible_Resource_Manager::~Visible_Resource_Manager(v1->VR_List);
        operator delete(v11);
    }
    if( v1->name )
    {
        free(v1->name);
        v1->name = 0;
    }
    if( v1->attribute_num > 0 )
    {
        free(v1->attributes);
        v1->attribute_num = 0;
    }
    RGE_Tile_List::~RGE_Tile_List(&v1->diam_tile_list);
    RGE_Tile_List::~RGE_Tile_List(&v1->tile_list);
}

int RGE_Player::strategicNumber()
{
    return -1;
}

int RGE_Player::sendAICommand()
{
    return 0;
}

int RGE_Player::objectCostByType()
{
    return -1;
}

void RGE_Player::set_game_status(
    char new_status)
{
    char v2; // dl@2

    if( new_status != this->game_status )
    {
        v2 = this->resigned;
        if( !v2 || new_status == 2 )
        {
            this->game_status = new_status;
            if( new_status == 2 && !v2 )
                ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
                    6,
                    this->id,
                    0,
                    0,
                    0);
        }
    }
}

void RGE_Player::do_resign(
    int dropped)
{
    RGE_Player *v2; // esi@1
    RGE_PlayerVtbl *v3; // eax@1
    char v4; // bl@1

    v2 = this;
    v3 = this->vfptr;
    v4 = this->resigned;
    this->resigned = 1;
    (*(void (__stdcall **)(signed int))&v3->gap4[0])(2);
    if( !v4 )
        rge_base_game->notification(
            5,
            v2->id,
            dropped,
            0,
            0);
}

char RGE_Player::get_resigned()
{
    return this->resigned;
}

char *RGE_Player::aiStatus(
    int sNum)
{
    return 0;
}

int RGE_Player::computerPlayer()
{
    return this->computerPlayerValue;
}

bool RGE_Player::isEnemy(
    int playerNum)
{
    return
        playerNum != this->id &&
        playerNum > 0 &&
        playerNum < this->world->player_num &&
        this->relations[playerNum] == 3;
}

bool RGE_Player::isAlly(
    int playerNum)
{
    if( playerNum == this->id ){
        return true;
    }
    return
        playerNum > 0 &&
        playerNum < this->world->player_num &&
        this->relations[playerNum] == 0;
}

bool RGE_Player::isNeutral(
    int playerNum)
{
    return
        playerNum != this->id &&
        playerNum > 0 &&
        playerNum < this->world->player_num &&
        this->relations[playerNum] == 1;
}

bool RGE_Player::isAllNeutral()
{
    RGE_Player *v1; // esi@1
    signed int v2; // edi@1
    int result; // eax@5

    v1 = this;
    v2 = 1;
    if( this->world->player_num <= 1 )
    {
        result = 1;
    }
    else
    {
        while( v2 == v1->id || v1->vfptr->isNeutral(v1, v2) )
        {
            if( ++v2 >= v1->world->player_num )
                return 1;
        }
        result = 0;
    }
    return result;
}

void RGE_Player::sendUnitAIOrder(
    int issuer,
    int recipient,
    int orderType,
    int target,
    int targetOwner,
    float targetX,
    float targetY,
    float targetZ,
    float range,
    int immediate,
    int inFront,
    int priority)
{
    this->world->commands->command_ai_order(
        issuer,
        issuer,
        recipient,
        orderType,
        target,
        targetOwner,
        targetX,
        targetY,
        targetZ,
        range,
        immediate,
        inFront,
        priority);
}

void RGE_Player::processAIOrder(
    int issuer,
    int recipient,
    int orderType,
    int target,
    int targetOwner,
    float targetX,
    float targetY,
    float targetZ,
    float range,
    int immediate,
    int inFront,
    int priority)
{
    RGE_Static_Object *v13; // eax@1
    RGE_Static_Object *v14; // esi@1
    UnitAIModule *v15; // eax@3

    v13 = this->world->object(recipient);
    v14 = v13;
    if( v13 )
    {
        if( RGE_Static_Object::unitAI(v13) )
        {
            v15 = RGE_Static_Object::unitAI(v14);
            (*(void (**)(UnitAIModule *, int, int, int, int, _DWORD, _DWORD, _DWORD, _DWORD, int, int, int))&v15->vfptr->gap4[12])(
                v15,
                issuer,
                orderType,
                target,
                targetOwner,
                LODWORD(targetX),
                LODWORD(targetY),
                LODWORD(targetZ),
                LODWORD(range),
                immediate,
                inFront,
                priority);
        }
    }
}

void RGE_Player::sendGameOrder(RGE_Static_Object *unit, RGE_Static_Object *target, float targetX, float targetY)
{
    RGE_Command::command_order(this->world->commands, &unit, 1, target, targetX, targetY);
}

void RGE_Player::sendAddWaypointCommand(
    int recipient,
    XYZBYTEPoint *waypoint,
    int numWaypoints)
{
    this->world->commands->command_add_waypoint(
        this->id,
        recipient,
        waypoint,
        numWaypoints);
}

void RGE_Player::processAddWaypointCommand(
    int recipient,
    XYZBYTEPoint *waypoint,
    int numWaypoints)
{
    RGE_Static_Object *v4; // eax@1
    RGE_Static_Object *v5; // edi@1
    int v6; // ebx@2
    XYZBYTEPoint *v7; // esi@3
    int (*v8)(RGE_Static_Object *, XYZBYTEPoint *, int); // ebp@3

    v4 = RGE_Game_World::object(this->world, recipient);
    v5 = v4;
    if( v4 )
    {
        v6 = numWaypoints;
        if( numWaypoints > 0 )
        {
            v7 = waypoint;
            v8 = v4->vfptr->addUserDefinedWaypoint;
            do
            {
                v8(v5, v7, 1);
                ++v7;
                --v6;
            }
            while( v6 );
        }
    }
}

void RGE_Player::sendPlayCommand(
    int recipient,
    int target,
    int playID)
{
    RGE_Player *v4; // esi@1
    RGE_PlayerVtbl *v5; // ebp@1
    int v6; // edi@3
    int *v7; // ecx@3
    int v8; // edx@3
    signed int v9; // ebx@3
    int selectedUnits[25]; // [sp+10h] [bp-64h]@3

    v4 = this;
    v5 = this->vfptr;
    ((void (__stdcall *)(int))this->vfptr->command_destroy_group)(recipient);
    if( AIPlayBook::play(v4->world->playbook, playID) )
    {
        v6 = 0;
        v7 = selectedUnits;
        v8 = (int)v4->sel_list;
        v9 = 25;
        do
        {
            if( *(_DWORD *)v8 )
            {
                ++v6;
                *v7 = *(_DWORD *)(*(_DWORD *)v8 + 4);
                ++v7;
            }
            v8 += 4;
            --v9;
        }
        while( v9 );
        if( v6 )
        {
            ((void (__fastcall *)(RGE_Player *, int, int, int *, int, signed int))v5->command_create_group)(
                v4,
                v8,
                recipient,
                selectedUnits,
                v6,
                0x40000000);
            ((void (*)(RGE_Player *, _DWORD, int, signed int, int, int, signed int, signed int, signed int, signed int, signed int, _DWORD, signed int))v5->sendUnitAIOrder)(
                v4,
                v4->id,
                recipient,
                726,
                target,
                playID,
                -1082130432,
                -1082130432,
                -1082130432,
                -1082130432,
                1,
                0,
                100);
        }
    }
    else
    {
        ((void (*)(RGE_Player *, _DWORD, int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, signed int))v5->sendUnitAIOrder)(
            v4,
            v4->id,
            recipient,
            727,
            -1,
            -1,
            -1082130432,
            -1082130432,
            -1082130432,
            -1082130432,
            1,
            0,
            100);
    }
}

void RGE_Player::sendPlayCommand(
    int recipient,
    int *groupUnits,
    int groupCount,
    int target,
    int playID)
{
    this->command_destroy_group(recipient);

    if( this->world->playbook->play(playID) ){

        if( groupCount ){

            this->command_create_group(
                this,
                recipient,
                groupUnits,
                groupCount,
                0x40000000);

            this->sendUnitAIOrder(
                this,
                this->id,
                recipient,
                726,
                target,
                playID,
                -1082130432,
                -1082130432,
                -1082130432,
                -1082130432,
                1,
                0,
                100);
        }
    }else{

        this->sendUnitAIOrder(
            this,
            this->id,
            recipient,
            727,
            -1,
            -1,
            -1082130432,
            -1082130432,
            -1082130432,
            -1082130432,
            1,
            0,
            100);
    }
}

int RGE_Player::pathingAttemptCap()
{
    return this->pathingAttemptCapValue;
}

void RGE_Player::setPathingAttemptCap(int v)
{
    this->pathingAttemptCapValue = v;
}

int RGE_Player::pathingDelayCap()
{
    return this->pathingDelayCapValue;
}

void RGE_Player::setPathingDelayCap(int v)
{
    this->pathingDelayCapValue = v;
}

int RGE_Player::currentUpdatePathingAttempts()
{
    return this->currentUpdatePathingAttemptsValue;
}

int RGE_Player::availablePathingAttempts(int numWaitDelays)
{
    int v2; // eax@1
    int result; // eax@3
    int v4; // eax@4

    v2 = this->pathingDelayCapValue;
    if( v2 == -1 || numWaitDelays <= v2 )
    {
        v4 = this->pathingAttemptCapValue;
        if( v4 == -1 )
            result = 1;
        else
            result = this->currentUpdatePathingAttemptsValue < v4;
    }
    else
    {
        result = 1;
    }
    return result;
}

void RGE_Player::incrementPathingAttempts()
{
    this->currentUpdatePathingAttemptsValue++;
}

void RGE_Player::sendChatMessage(
    int playerID,
    int copySelf,
    char *textIn, ...)
{
    va_list va;
    va_start(va, textIn);
    char textOut[1025];
    vsprintf(textOut, textIn, va);
    if( strlen(textOut) != 0 ){
        for( int i = 1; i <= RGE_Base_Game::numberPlayers(rge_base_game); i++ ){
            if( rge_base_game->playerID(i) == playerID ){
                this->world->commands->com_hand->SendChatMsg(this->id, i, textOut);
            }
        }
        if( copySelf == 1 &&
            playerID != this->id ){
            for( int j = 1; j <= rge_base_game->numberPlayers(); j++ ){
                if( this->id == rge_base_game->playerID(j) ){
                    this->world->commands->com_hand->SendChatMsg(this->id, j, textOut);
                }
            }
        }
    }
}

RGE_Static_Object *RGE_Player::make_scenario_obj(
    float world_x,
    float world_y,
    float world_z,
    short master_id,
    char state,
    float new_angle)
{
    int v7; // esi@1
    RGE_Master_Static_Object *v8; // eax@1

    v7 = 0;
    v8 = this->master_objects[master_id];

    if( this->master_objects[master_id] ){
        v7 = this->master_objects[master_id]->make_new_obj(
             v8,
             this,
             LODWORD(world_x),
             LODWORD(world_y),
             LODWORD(world_z));

        if( (unsigned __int8)state >= RGE_Static_Object::State::Unk7 ){
            (*(void (**)(int))(*(_DWORD *)v7 + 104))(v7);
            return (RGE_Static_Object *)v7;
        }
        if( state > RGE_Static_Object::State::Alive ){
            (*(void (**)(int))(*(_DWORD *)v7 + 108))(v7);
            return (RGE_Static_Object *)v7;
        }
        (*(void (**)(int, _DWORD))(*(_DWORD *)v7 + 180))(v7, LODWORD(new_angle));
    }
    return (RGE_Static_Object *)v7;
}

void RGE_Player::scenario_load(
    int infile,
    int *player_id_hash,
    float version)
{
    int v6; // ebp@2
    int v7; // ebx@6
    int v8; // eax@6
    int v9; // edi@18
    bool v10; // zf@18
    bool v11; // sf@18
    int *v12; // ecx@24
    int v13; // eax@24
    int v14; // eax@26

    if( version <= 1.05 ){
        return;
    }
    v6 = infile;
    short count;
    rge_read(infile, &count, 2);
    if( count > 0 ){
        a2 = (char *)calloc(count, 1u);
        rge_read(v6, (int)a2, v6, a2, count);
        if( this->name )
            free(a2);
        else
            this->name = a2;
    }
    rge_read(v6, (int)a2, v6, &this->view_x, 4);
    rge_read(v6, (int)a2, v6, &this->view_y, 4);
    rge_read(v6, (int)a2, v6, &this->map_x, 2);
    rge_read(v6, (int)a2, v6, &this->map_y, 2);
    v7 = 0;
    v8 = rge_base_game->prog_mode;
    int has_team = 0;
    if( rge_base_game->prog_mode != 7 ){
        a2 = (char *)1;
        while( rge_base_game->playerID((int)a2) != this->id
                 || comm->GetPlayerHumanity((unsigned int)a2) != 2
                 && comm->GetPlayerHumanity((unsigned int)a2) != 4 )
        {
            if( (signed int)++a2 >= 9 )
                goto LABEL_15;
        }
        if( RGE_Base_Game::playerTeam(rge_base_game, (int)--a2) > 1 ){
            v7 = 1;
            has_team = 1;
        }
    }
    LABEL_15:
    if( version > 1.0 ){
        char temp_byte;
        rge_read(infile, &temp_byte, 1);
        if( v7 == 0 ){
            this->allied_victory = temp_byte;
        }
    }
    v9 = 0;
    v10 = this->attribute_num == 0;
    v11 = this->attribute_num < 0;
    this->allied_LOS_Enable = 0;
    if( this->attribute_num > 0 ){
        rge_read(infile, this->attributes, 116);
    }
    short player_count;
    rge_read(infile, &player_count, 2);
    if( player_count > 0 )
    {
        while( 1 )
        {
            rge_read(infile, &infile, 1);
            if( !v7 )
            {
                v12 = &player_id_hash[(signed short)v9];
                v13 = *v12;
                if( *v12 < this->world->player_num && v13 >= 0 )
                {
                    this->relations[v13] = infile;
                    v14 = *v12;
                    if( *v12 )
                    {
                        if( (_WORD)v9 == this->id )
                        {
                            this->unitDiplomacy[v14] = 1;
                        }
                        else if( (_BYTE)infile )
                        {
                            if( (_BYTE)infile == 1 )
                                this->unitDiplomacy[v14] = 3;
                            else
                                this->unitDiplomacy[v14] = 4;
                        }
                        else
                        {
                            this->unitDiplomacy[v14] = 2;
                        }
                    }
                    else
                    {
                        this->unitDiplomacy[0] = 0;
                    }
                }
            }
            if( (signed short)++v9 >= player_count )
                break;
            v7 = has_team;
        }
    }
    if( version > 1.08 ){
        rge_read(infile, this->unitDiplomacy, 4 * RGE_PLAYERS_COUNT);
    }
    if( this->victory_conditions ){
        delete this->victory_conditions;
    }
    this->load_victory(v6, player_id_hash, false);
}

void RGE_Player::scenario_postsave(
    int outfile)
{
    unsigned int count;
    count = strlen(this->name) + 1;
    rge_write(outfile, &count, 2);
    rge_write(outfile, this->name, (signed short)count);
    rge_write(outfile, &this->view_x, 4);
    rge_write(outfile, &this->view_y, 4);
    rge_write(outfile, &this->map_x, 2);
    rge_write(outfile, &this->map_y, 2);
    rge_write(outfile, &this->allied_victory, 1);
    rge_write(outfile, &this->world->player_num, 2);
    rge_write(outfile, this->relations, this->world->player_num);
    rge_write(outfile, this->unitDiplomacy, 4 * RGE_PLAYERS_COUNT);

    this->victory_conditions->save(outfile);
}

void RGE_Player::scenario_postload(
    int infile,
    int *player_id_hash,
    float version)
{
    int v5; // ebp@1
    RGE_Player *v6; // esi@1
    bool v7; // c0@17
    bool v8; // c3@17
    int v9; // edi@20
    int *v10; // ebx@20
    short v11; // ax@23
    RGE_Victory_Conditions *v12; // edi@39
    char temp_byte; // [sp+13h] [bp-9h]@15
    short count; // [sp+14h] [bp-8h]@1
    short player_count; // [sp+16h] [bp-6h]@20
    int has_team; // [sp+18h] [bp-4h]@5

    v5 = infile;
    v6 = this;
    rge_read(infile, (int)a2, infile, &count, 2);
    if( count > 0 )
    {
        a2 = (char *)calloc(count, 1u);
        rge_read(infile, a2, count);
        if( this->name )
            free(a2);
        else
            this->name = a2;
    }
    rge_read(infile, &this->view_x, 4);
    rge_read(infile, &this->view_y, 4);
    rge_read(infile, &this->map_x, 2);
    rge_read(infile, &this->map_y, 2);
    has_team = 0;
    if( rge_base_game->prog_mode != 7 )
    {
        a2 = (char *)1;
        while( RGE_Base_Game::playerID(rge_base_game, (int)a2) != this->id
                 || TCommunications_Handler::GetPlayerHumanity(comm, (unsigned int)a2) != 2
                 && TCommunications_Handler::GetPlayerHumanity(comm, (unsigned int)a2) != 4 )
        {
            if( (signed int)++a2 >= 9 )
                goto LABEL_14;
        }
        if( RGE_Base_Game::playerTeam(rge_base_game, (int)--a2) > 1 )
            has_team = 1;
    }
LABEL_14:
    if( version > 1.0 )
    {
        rge_read(infile, &temp_byte, 1);
        if( !has_team )
            this->allied_victory = temp_byte;
    }
    v7 = version < 1.06;
    v8 = version == 1.06;
    this->allied_LOS_Enable = 0;
    if( (v7 || v8) && this->attribute_num > 0 )
        rge_read(infile, this->attributes, 116);
    rge_read(infile, &player_count, 2);
    v9 = 0;
    v10 = player_id_hash;
    if( player_count > 0 )
    {
        do
        {
            rge_read(v5, v9, v5, &infile, 1);
            if( !has_team )
            {
                v11 = v10 ? LOWORD(v10[(signed short)v9]) : (_WORD)v9;
                if( v11 < this->world->player_num && v11 >= 0 )
                {
                    this->relations[v11] = infile;
                    if( v11 )
                    {
                        if( v11 == this->id )
                        {
                            this->unitDiplomacy[v11] = 1;
                        }
                        else if( (_BYTE)infile )
                        {
                            if( (_BYTE)infile == 1 )
                                this->unitDiplomacy[v11] = 3;
                            else
                                this->unitDiplomacy[v11] = 4;
                        }
                        else
                        {
                            this->unitDiplomacy[v11] = 2;
                        }
                    }
                    else
                    {
                        this->unitDiplomacy[0] = 0;
                    }
                }
            }
            v10 = player_id_hash;
            ++v9;
        }
        while( (signed short)v9 < player_count );
    }
    if( version >= 1.08 )
        rge_read(v5, v9, v5, this->unitDiplomacy, 36);
    v12 = this->victory_conditions;
    if( v12 )
    {
        RGE_Victory_Conditions::~RGE_Victory_Conditions(this->victory_conditions);
        operator delete(v12);
    }
    if( version >= 1.09 ){
        this->load_victory(v6, v5, v10, false);
    }else{
        this->load_victory(v6, v5, v10, true);
    }
}

void RGE_Player::load(
    int infile)
{
    int v3; // ebx@1
    RGE_Player *v4; // esi@1
    char *v5; // ebp@1
    int v6; // edi@1
    RGE_Master_Static_Object **v7; // eax@2
    int v8; // ecx@2
    RGE_Visible_Map *v9; // eax@8
    RGE_Visible_Map *v10; // eax@9
    Visible_Resource_Manager *v11; // eax@11
    Visible_Resource_Manager *v12; // eax@12
    RGE_Object_List *v13; // eax@14
    RGE_Object_List *v14; // eax@15
    RGE_Game_World *v15; // ecx@17
    RGE_Object_List *v16; // eax@17
    RGE_Object_List *v17; // eax@18
    RGE_Object_List *v18; // eax@20
    RGE_Object_List *v19; // eax@21
    RGE_Object_List *v20; // ecx@23
    RGE_Game_World *v21; // ST10_4@23

    v3 = infile;
    v4 = this;
    v5 = (char *)&this->master_object_num;
    rge_read((int)&this->master_object_num, a2, infile, &this->master_object_num, 2);
    v6 = 0;
    if( *(_WORD *)v5 <= 0 )
    {
        this->master_objects = 0;
    }
    else
    {
        v7 = (RGE_Master_Static_Object **)calloc(*(_WORD *)v5, 4u);
        v8 = *(_WORD *)v5;
        this->master_objects = v7;
        rge_read((int)v5, 0, v3, v7, 4 * v8);
        if( *(_WORD *)v5 > 0 )
        {
            do
            {
                if( this->master_objects[(signed short)v6] )
                {
                    rge_read((int)v5, v6, v3, &infile, 1);
                    RGE_Player::load_master_object(v4, (int)v5, v3, v6, infile, this->world->sprites, this->world->sounds);
                }
                ++v6;
            }
            while( (signed short)v6 < *(_WORD *)v5 );
        }
    }
    v9 = (RGE_Visible_Map *)operator new(0x38u);
    if( v9 )
        RGE_Visible_Map::RGE_Visible_Map(v9, v6, v3, this->world);
    else
        v10 = 0;
    this->visible = v10;
    v11 = (Visible_Resource_Manager *)operator new(0x14u);
    if( v11 )
        Visible_Resource_Manager::Visible_Resource_Manager(v11, v3, v4);
    else
        v12 = 0;
    this->VR_List = v12;
    v13 = (RGE_Object_List *)operator new(0xCu);
    if( v13 )
        RGE_Object_List::RGE_Object_List(v13);
    else
        v14 = 0;
    v15 = this->world;
    this->objects = v14;
    RGE_Object_List::load_list(v14, (int)v5, v3, v15);
    v16 = (RGE_Object_List *)operator new(0xCu);
    if( v16 )
        RGE_Object_List::RGE_Object_List(v16);
    else
        v17 = 0;
    this->sleeping_objects = v17;
    v18 = (RGE_Object_List *)operator new(0xCu);
    if( v18 )
        RGE_Object_List::RGE_Object_List(v18);
    else
        v19 = 0;
    v20 = this->sleeping_objects;
    v21 = this->world;
    this->doppleganger_objects = v19;
    RGE_Object_List::load_list(v20, (int)v5, v3, v21);
    if( save_game_version >= 7.0900002 ){
        this->doppleganger_objects->load_list((int)v5, v3, this->world);
    }
}

void RGE_Player::load_master_object(
    int infile,
    short index,
    char type,
    RGE_Sprite **sprites,
    RGE_Sound **sounds)
{
    RGE_Static_Object *obj;

    switch ( type ){

    case RGE_STATIC_OBJECT_TYPE:
        obj = new RGE_Master_Static_Object(
            infile,
            sprites,
            sounds,
            true);
        break;

    case RGE_ANIMATED_OBJECT_TYPE:
        obj = new RGE_Master_Animated_Object(
            infile,
            sprites,
            sounds,
            true);
        break;

    case RGE_MOVING_OBJECT_TYPE:
        obj = new RGE_Master_Moving_Object(
            infile,
            sprites,
            sounds,
            true);
        break;

    case RGE_DOPPLEGANGER_OBJECT_TYPE:
        obj = new RGE_Master_Doppleganger_Object(
            infile,
            sprites,
            sounds,
            true);
        break;

    case RGE_ACTION_OBJECT_TYPE:
        obj = new RGE_Master_Action_Object(
            infile,
            sprites,
            sounds,
            true);
        break;

    case RGE_COMBAT_OBJECT_TYPE:
        obj = new RGE_Master_Combat_Object(
            infile,
            sprites,
            sounds,
            true);
        break;

    case RGE_MISSILE_OBJECT_TYPE:
        obj = new RGE_Master_Missile_Object(
            infile,
            sprites,
            sounds,
            true);
        break;

    default:
        return;
    }

    this->master_objects[index] = obj;
}

void RGE_Player::load_info(
    int infile)
{
    int player_id = 0;

    this->load_victory(
        infile,
        player_id,
        true);

    this->objects             ->rehook_list();
    this->sleeping_objects    ->rehook_list();
    this->doppleganger_objects->rehook_list();
}

int RGE_Player::get_checksum()
{
    if( this->checksum_created_this_update == false ){
        this->create_checksum();
    }
    return this->checksum;
}

bool RGE_Player::get_checksums(
    int *new_checksum,
    int *new_position_checksum,
    int *new_action_checksum)
{
    if( this->checksum_created_this_update == false ){
        this->create_checksum();
    }
    *new_checksum          = this->checksum;
    *new_position_checksum = this->position_checksum;
    *new_action_checksum   = this->action_checksum;

    return true;
}

int RGE_Player::create_checksum()
{
    RGE_Player *v1; // ebx@1
    RGE_Object_List *v2; // eax@1
    int v3; // esi@1
    int v4; // ebp@1
    int v5; // esi@1
    float *v6; // edi@2
    signed __int64 v7; // rax@3
    bool v8; // zf@3
    RGE_Object_Node *i; // edi@4
    int v10; // ebp@5
    int v11; // esi@6
    int num3; // [sp+10h] [bp-18h]@1
    int num1; // [sp+14h] [bp-14h]@1
    float temp_position_checksum; // [sp+18h] [bp-10h]@1
    int v16; // [sp+1Ch] [bp-Ch]@2
    int num2; // [sp+20h] [bp-8h]@1

    v1 = this;
    v2 = this->sleeping_objects;
    v3 = this->id;
    this->checksum_created_this_update = 1;
    this->action_checksum = 0;
    v4 = 0;
    v5 = this->doppleganger_objects->number_of_objects + v2->number_of_objects + v3;
    num1 = 0;
    num2 = 0;
    num3 = 0;
    temp_position_checksum = 0.0;
    if( this->attribute_num > 0 )
    {
        v6 = this->attributes;
        v16 = this->attribute_num;
        do
        {
            v7 = (signed __int64)*v6;
            ++v6;
            v8 = v16 == 1;
            num1 += v7;
            --v16;
        }
        while( !v8 );
    }
    for( i = this->objects->list; i; i = i->next )
    {
        v10 = num2
                + i->node->master_obj->id
                + (unsigned __int64)(signed __int64)i->node->attribute_amount_held
                + i->node->object_state;
        v4 = i->node->vfptr->get_waypoint_checksum(i->node) + v10;
        num2 = v4;
        ++num3;
        temp_position_checksum = i->node->world_z + i->node->world_x + temp_position_checksum + i->node->world_y;
        v1->action_checksum += ((int (*)(void))i->node->vfptr->get_action_checksum)();
    }
    v11 = num1 + ((v4 + ((num3 + (v5 << 8)) << 8)) << 8);
    v1->checksum = v11;
    v1->position_checksum = (signed __int64)temp_position_checksum;
    return v11;
}

void RGE_Player::new_attribute_num(
    short attribute,
    float amount)
{
    if( attribute >= 0 &&
        attribute < this->attribute_num ){
        this->attributes[attribute] = amount;
    }
}

void RGE_Player::add_attribute_num(
    short attribute,
    float amount,
    char earned)
{
    if( attribute >= 0 &&
        attribute < this->attribute_num ){
        this->attributes[attribute] = amount + this->attributes[attribute];
    }
}

void RGE_Player::make_available(
    short obj_category,
    char on_off_flag)
{
    if( this->master_objects[obj_category] ){
        this->master_objects[obj_category]->make_available(on_off_flag);
    }
}

void RGE_Player::update()
{
    RGE_Player *v1; // esi@1
    RGE_Object_List *v2; // ecx@3
    Visible_Resource_Manager *v3; // ecx@5

    v1 = this;
    if( MouseSystem )
        TMousePointer::Poll(MouseSystem);
    v2 = v1->objects;
    v1->currentUpdatePathingAttemptsValue = 0;
    RGE_Object_List::update(v2);
    RGE_Player::update_selected(v1);
    if( RGE_Victory_Conditions::update(v1->victory_conditions) == 1 )
        (*(void (**)(RGE_Player *, signed int))&v1->vfptr->gap4[0])(v1, 2);
    v3 = v1->VR_List;
    v1->checksum_created_this_update = 0;
    if( v3 )
        Visible_Resource_Manager::Process_New_Tiles(v3, &v1->tile_list);
}

void RGE_Player::update_dopplegangers()
{
    if( MouseSystem ){
        MouseSystem->Poll();
    }
    this->doppleganger_objects->update();
    this->doppleganger_creator->perform_doppleganger_checks();
}

void RGE_Player::save(
    int outfile)
{
    rge_write(outfile, &this->type, 1);
    rge_write(outfile, this->relations, this->world->player_num);
    rge_write(outfile, this->unitDiplomacy, 4 * RGE_PLAYERS_COUNT);
    rge_write(outfile, &this->allied_LOS_Enable, 4);
    rge_write(outfile, &this->allied_victory, 1);
    size_t index = strlen(this->name) + 1;
    rge_write(outfile, &index, 2);
    if( index > 0 ){
        rge_write(outfile, this->name, index);
    }
    rge_write(outfile, &this->attribute_num, 2);
    if( this->attribute_num > 0 ){
        rge_write(outfile, this->attributes, 4 * this->attribute_num);
    }
    rge_write(outfile, &this->view_x, 4);
    rge_write(outfile, &this->view_y, 4);
    rge_write(outfile, &this->map_x, 2);
    rge_write(outfile, &this->map_y, 2);
    rge_write(outfile, &this->culture, 1);
    rge_write(outfile, &this->master_player_id, 1);
    rge_write(outfile, &this->game_status, 1);
    rge_write(outfile, &this->resigned, 1);
    char table;
    if( this->color_table ){
        table = this->color_table->id;
    }else{
        table = 0;
    }
    rge_write(outfile, &table, 1);
    rge_write(outfile, &this->pathingAttemptCapValue, 4);
    rge_write(outfile, &this->pathingDelayCapValue, 4);
}

void RGE_Player::save2(
    int outfile)
{
    /* save master-objects: */
    rge_write(outfile, &this->master_object_num, 2);
    for( int i = 0; i < this->master_object_num; i++ ){
        if( this->master_objects[i] ){
            rge_write(outfile, 1, 4);
        }else{
            rge_write(outfile, 0, 4);
        }
    }
    for( int j = 0; j < this->master_object_num; j++ ){
        if( this->master_objects[j] ){
            this->master_objects[j]->save(outfile);
        }
    }

    /* save visible-map: */
    this->visible->save(outfile);

    /* save visible-resources: */
    this->VR_List->save(outfile);

    /* save objects: */
    this->objects             ->save(outfile);
    this->sleeping_objects    ->save(outfile);
    this->doppleganger_objects->save(outfile);
}

void RGE_Player::save_info(
    int outfile)
{
    /* save victory-conditions: */
    this->victory_conditions->save(outfile);
}

void RGE_Player::set_map_loc(
    short x,
    short y)
{
    this->map_x = x;
    this->map_y = y;
}

void RGE_Player::set_view_loc(
    float x,
    float y)
{
    double v3; // st7@3
    double v4; // st7@7

    this->view_x = x;
    this->view_y = y;
    if( x >= 0.0 )
    {
        v3 = (double)(this->world->map->map_width - 1);
        if( x > v3 )
            this->view_x = v3;
    }
    else
    {
        LODWORD(this->view_x) = 0;
    }
    if( y >= 0.0 )
    {
        v4 = (double)(this->world->map->map_height - 1);
        if( y > v4 )
            this->view_y = v4;
    }
    else
    {
        LODWORD(this->view_y) = 0;
    }
}

//----- (00470580) --------------------------------------------------------
void RGE_Player::destroy_objects()
{
    RGE_Object_Node *i; // esi@1

    for( i = this->objects->list; i; i = i->next )
        ((void (*)(void))i->node->vfptr->destroy_obj)();
}

//----- (004705A0) --------------------------------------------------------
void RGE_Player::set_color_table(char new_table)
{
    this->color_table = this->world->color_tables[(unsigned __int8)new_table];
}

//----- (004705C0) --------------------------------------------------------
void RGE_Player::victory_if_game_on()
{
    if( !this->game_status )
        (*(void (__stdcall **)(_DWORD))&this->vfptr->gap4[0])(1);
}

//----- (004705E0) --------------------------------------------------------
void RGE_Player::loss_if_game_on()
{
    if( !this->game_status )
        (*(void (__stdcall **)(_DWORD))&this->vfptr->gap4[0])(2);
}

//----- (00470600) --------------------------------------------------------
void RGE_Player::win_game_now()
{
    RGE_Player *v1; // esi@1
    int i; // edi@1
    RGE_Player *v3; // ecx@6

    v1 = this;
    RGE_Player::victory_if_game_on(this);
    for( i = 1; i < v1->world->player_num; ++i )
    {
        if( i != v1->id )
        {
            if( !v1->allied_victory
                || RGE_Player::relation(v1, i)
                || RGE_Player::relation(v1->world->players[i], v1->id)
                || (v3 = v1->world->players[i], !v3->allied_victory) )
            {
                RGE_Player::loss_if_game_on(v1->world->players[i]);
            }
            else
            {
                RGE_Player::victory_if_game_on(v3);
            }
        }
    }
}

//----- (00470690) --------------------------------------------------------
bool RGE_Player::check_victory_conditions()
{
    bool result; // al@2

    if( this->game_status == 2 )
        result = 1;
    else
        result = RGE_Victory_Conditions::victory_achieved(this->victory_conditions);
    return result;
}

//----- (004706B0) --------------------------------------------------------
char RGE_Player::check_ally_group(int *count)
{
    int *v2; // ebp@1
    RGE_Player *v3; // esi@1
    char v4; // bl@1
    RGE_Game_World *v5; // eax@2
    signed int v6; // edi@2
    int *counta; // [sp+14h] [bp+4h]@1

    v2 = count;
    v3 = this;
    v4 = 1;
    counta = (int *)*count;
    if( this->game_status != 2 )
    {
        *v2 = 0;
        v5 = this->world;
        v6 = 1;
        if( v5->player_num > 1 )
        {
            while( v3->relations[v6]
                     || !RGE_Player::relation(v5->players[v6], v3->id) && v3->world->players[v6]->allied_victory )
            {
                ++v6;
                ++*v2;
                v5 = v3->world;
                if( v6 >= v5->player_num )
                    goto LABEL_9;
            }
            v4 = 0;
        }
    }
LABEL_9:
    if( (signed int)counta >= 0 && (int *)*v2 != counta )
        v4 = 0;
    return v4;
}

//----- (00470750) --------------------------------------------------------
char RGE_Player::check_victory()
{
    RGE_Player *v1; // esi@1
    char v2; // bl@3
    RGE_Game_World *v3; // eax@4
    signed int v4; // edi@4
    RGE_Game_World *v5; // eax@13
    signed int v6; // edi@13
    int count; // [sp+Ch] [bp-4h]@1

    v1 = this;
    count = -1;
    if( this->game_status != 2 && RGE_Victory_Conditions::victory_achieved(this->victory_conditions) )
    {
        v2 = 0;
        if( v1->allied_victory )
        {
            v3 = v1->world;
            v4 = 1;
            if( v3->player_num > 1 )
            {
                while( v4 != v1->id && v1->relations[v4] || RGE_Player::check_ally_group(v3->players[v4], &count) )
                {
                    v3 = v1->world;
                    if( ++v4 >= v3->player_num )
                        goto LABEL_11;
                }
                v2 = 1;
            }
LABEL_11:
            if( v1->allied_victory )
            {
                if( v2 )
                    return v1->game_status;
                v5 = v1->world;
                v6 = 1;
                if( v5->player_num > 1 )
                {
                    while( v1->relations[v6] || RGE_Player::check_victory_conditions(v5->players[v6]) )
                    {
                        v5 = v1->world;
                        if( ++v6 >= v5->player_num )
                            goto LABEL_19;
                    }
                    v2 = 1;
                }
            }
        }
LABEL_19:
        if( !v2 )
        {
            (*(void (**)(RGE_Player *, signed int))&v1->vfptr->gap4[0])(v1, 1);
            v1->world->game_end_condition = 2;
        }
    }
    return v1->game_status;
}

//----- (00470840) --------------------------------------------------------
void RGE_Player::modify_tobj(short obj_id, short group, float amount, int flag)
{
    RGE_Player *v5; // ebx@1
    unsigned int v6; // edi@2
    RGE_Object_List *v7; // eax@3
    RGE_Object_Node *j; // esi@4
    int v9; // ecx@10
    int v10; // esi@11
    RGE_Master_Static_Object *v11; // eax@11
    RGE_Object_List *v12; // eax@13
    RGE_Object_Node *i; // edi@14
    int obj_ida; // [sp+14h] [bp+4h]@10

    v5 = this;
    if( obj_id < 0 )
    {
        if( group >= 0 )
        {
            v9 = 0;
            obj_ida = 0;
            if( v5->master_object_num > 0 )
            {
                do
                {
                    v10 = (signed short)v9;
                    v11 = v5->master_objects[v10];
                    if( v11 && v11->object_group == group )
                    {
                        v12 = v5->objects;
                        if( v12 )
                        {
                            for( i = v12->list; i; i = i->next )
                            {
                                if( i->node->master_obj == v5->master_objects[v10] )
                                    ((void (__stdcall *)(_DWORD, int))i->node->vfptr->modify)(LODWORD(amount), flag);
                            }
                        }
                        ((void (__stdcall *)(_DWORD, int))v5->master_objects[v10]->vfptr->modify)(LODWORD(amount), flag);
                        v9 = obj_ida;
                    }
                    obj_ida = ++v9;
                }
                while( (signed short)v9 < v5->master_object_num );
            }
        }
    }
    else
    {
        v6 = obj_id;
        if( this->master_objects[v6] )
        {
            v7 = this->objects;
            if( v7 )
            {
                for( j = v7->list; j; j = j->next )
                {
                    if( j->node->master_obj == v5->master_objects[v6] )
                        ((void (__stdcall *)(_DWORD, int))j->node->vfptr->modify)(LODWORD(amount), flag);
                }
            }
            ((void (__stdcall *)(_DWORD, int))v5->master_objects[v6]->vfptr->modify)(LODWORD(amount), flag);
        }
    }
}

//----- (00470940) --------------------------------------------------------
void RGE_Player::modify_tobj_delta(short obj_id, short group, float amount, int flag)
{
    RGE_Player *v5; // ebx@1
    unsigned int v6; // edi@2
    RGE_Object_List *v7; // eax@3
    RGE_Object_Node *j; // esi@4
    int v9; // ecx@10
    int v10; // esi@11
    RGE_Master_Static_Object *v11; // eax@11
    RGE_Object_List *v12; // eax@13
    RGE_Object_Node *i; // edi@14
    int obj_ida; // [sp+14h] [bp+4h]@10

    v5 = this;
    if( obj_id < 0 )
    {
        if( group >= 0 )
        {
            v9 = 0;
            obj_ida = 0;
            if( v5->master_object_num > 0 )
            {
                do
                {
                    v10 = (signed short)v9;
                    v11 = v5->master_objects[v10];
                    if( v11 && v11->object_group == group )
                    {
                        v12 = v5->objects;
                        if( v12 )
                        {
                            for( i = v12->list; i; i = i->next )
                            {
                                if( i->node->master_obj == v5->master_objects[v10] )
                                    ((void (__stdcall *)(_DWORD, int))i->node->vfptr->modify_delta)(LODWORD(amount), flag);
                            }
                        }
                        ((void (__stdcall *)(_DWORD, int))v5->master_objects[v10]->vfptr->modify_delta)(LODWORD(amount), flag);
                        v9 = obj_ida;
                    }
                    obj_ida = ++v9;
                }
                while( (signed short)v9 < v5->master_object_num );
            }
        }
    }
    else
    {
        v6 = obj_id;
        if( this->master_objects[v6] )
        {
            v7 = this->objects;
            if( v7 )
            {
                for( j = v7->list; j; j = j->next )
                {
                    if( j->node->master_obj == v5->master_objects[v6] )
                        ((void (__stdcall *)(_DWORD, int))j->node->vfptr->modify_delta)(LODWORD(amount), flag);
                }
            }
            ((void (__stdcall *)(_DWORD, int))v5->master_objects[v6]->vfptr->modify_delta)(LODWORD(amount), flag);
        }
    }
}

//----- (00470A40) --------------------------------------------------------
void RGE_Player::modify_tobj_percent(short obj_id, short group, float amount, int flag)
{
    RGE_Player *v5; // ebx@1
    unsigned int v6; // edi@2
    RGE_Object_List *v7; // eax@3
    RGE_Object_Node *j; // esi@4
    int v9; // ecx@10
    int v10; // esi@11
    RGE_Master_Static_Object *v11; // eax@11
    RGE_Object_List *v12; // eax@13
    RGE_Object_Node *i; // edi@14
    int obj_ida; // [sp+14h] [bp+4h]@10

    v5 = this;
    if( obj_id < 0 )
    {
        if( group >= 0 )
        {
            v9 = 0;
            obj_ida = 0;
            if( v5->master_object_num > 0 )
            {
                do
                {
                    v10 = (signed short)v9;
                    v11 = v5->master_objects[v10];
                    if( v11 && v11->object_group == group )
                    {
                        v12 = v5->objects;
                        if( v12 )
                        {
                            for( i = v12->list; i; i = i->next )
                            {
                                if( i->node->master_obj == v5->master_objects[v10] )
                                    ((void (__stdcall *)(_DWORD, int))i->node->vfptr->modify_percent)(LODWORD(amount), flag);
                            }
                        }
                        ((void (__stdcall *)(_DWORD, int))v5->master_objects[v10]->vfptr->modify_percent)(LODWORD(amount), flag);
                        v9 = obj_ida;
                    }
                    obj_ida = ++v9;
                }
                while( (signed short)v9 < v5->master_object_num );
            }
        }
    }
    else
    {
        v6 = obj_id;
        if( this->master_objects[v6] )
        {
            v7 = this->objects;
            if( v7 )
            {
                for( j = v7->list; j; j = j->next )
                {
                    if( j->node->master_obj == v5->master_objects[v6] )
                        ((void (__stdcall *)(_DWORD, int))j->node->vfptr->modify_percent)(LODWORD(amount), flag);
                }
            }
            ((void (__stdcall *)(_DWORD, int))v5->master_objects[v6]->vfptr->modify_percent)(LODWORD(amount), flag);
        }
    }
}

//----- (00470B40) --------------------------------------------------------
void RGE_Player::copy_obj(short dest, short source)
{
    RGE_Player *v3; // ebx@1
    RGE_Master_Static_Object **v4; // eax@1
    int v5; // edi@1
    int v6; // ebp@2
    RGE_Object_List *v7; // eax@3
    RGE_Object_Node *i; // esi@4
    RGE_Master_Static_Object **v9; // eax@5

    v3 = this;
    v4 = this->master_objects;
    v5 = dest;
    if( v4[v5] )
    {
        v6 = source;
        if( v4[v6] )
        {
            v7 = this->objects;
            if( v7 )
            {
                for( i = v7->list; i; i = i->next )
                {
                    v9 = v3->master_objects;
                    if( i->node->master_obj == v9[v5] )
                        ((void (__stdcall *)(_DWORD))i->node->vfptr->copy_obj)(v9[v6]);
                }
            }
            (*((void (__stdcall **)(_DWORD))&v3->master_objects[v5]->vfptr->__vecDelDtor + 1))(v3->master_objects[v6]);
        }
    }
}

//----- (00470BB0) --------------------------------------------------------
void RGE_Player::set_allied_victory(char flag)
{
    this->allied_victory = flag;
}

//----- (00470BC0) --------------------------------------------------------
char RGE_Player::get_allied_victory()
{
    return this->allied_victory;
}

//----- (00470BD0) --------------------------------------------------------
char RGE_Player::relation(int player_id)
{
    return this->relations[player_id];
}

//----- (00470BE0) --------------------------------------------------------
void RGE_Player::set_relation(int player_id, int relation)
{
    RGE_Object_Node *i; // esi@10

    this->relations[player_id] = relation;
    if( player_id )
    {
        if( player_id == this->id )
        {
            this->unitDiplomacy[player_id] = 1;
        }
        else if( (_BYTE)relation )
        {
            if( (_BYTE)relation == 1 )
                this->unitDiplomacy[player_id] = 3;
            else
                this->unitDiplomacy[player_id] = 4;
        }
        else
        {
            this->unitDiplomacy[player_id] = 2;
        }
    }
    else
    {
        this->unitDiplomacy[0] = 0;
    }
    for( i = this->objects->list; i; i = i->next )
        ((void (__stdcall *)(int, _DWORD))i->node->vfptr->notify_of_relation)(player_id, relation);
}

//----- (00470C70) --------------------------------------------------------
RGE_Static_Object *RGE_Player::make_new_object(int obj_id, float x, float y, float z, int build_all_the_way)
{
    RGE_Master_Static_Object *v6; // eax@2
    RGE_Static_Object *result; // eax@3

    if( obj_id >= 0 && (v6 = this->master_objects[obj_id]) != 0 )
        result = (RGE_Static_Object *)((int (*)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD))v6->vfptr->make_new_obj)(
                                                                        v6,
                                                                        this,
                                                                        LODWORD(x),
                                                                        LODWORD(y),
                                                                        LODWORD(z));
    else
        result = 0;
    return result;
}

//----- (00470CB0) --------------------------------------------------------
void RGE_Player::reset_selected()
{
    char *v1; // edi@1

    this->selected_start_col = -1;
    this->selected_start_row = -1;
    this->selected_end_col = -1;
    this->selected_end_row = -1;
    this->replacement_terrain = -1;
    this->replacement_overlay = -1;
    this->replacement_overlay_shape = -1;
    this->sel_count = 0;
    this->selected_obj = 0;
    memset(this->sel_list, 0, sizeof(this->sel_list));
    memset(this->groups_used, 0, 0x7Cu);
    v1 = &this->groups_used[124];
    *(_WORD *)v1 = 0;
    v1[2] = 0;
}

//----- (00470D20) --------------------------------------------------------
int RGE_Player::select_object(RGE_Static_Object *obj)
{
    RGE_Player *v2; // edi@1
    int result; // eax@1
    char v4; // bl@2
    RGE_Object_Node *i; // esi@3
    RGE_Static_Object *v6; // eax@4

    v2 = this;
    result = RGE_Player::select_one_object(this, obj, 1);
    if( result )
    {
        v4 = obj->selected_group;
        if( (unsigned __int8)v4 > 0xAu )
        {
            for( i = v2->objects->list; i; i = i->next )
            {
                v6 = i->node;
                if( i->node != obj && v6->selected_group == v4 && !RGE_Player::select_one_object(v2, v6, 0) )
                    break;
            }
        }
        v2->selected_obj = obj;
        result = 1;
    }
    return result;
}

//----- (00470D80) --------------------------------------------------------
int RGE_Player::select_one_object(RGE_Static_Object *obj, int play_sound)
{
    RGE_Player *v3; // eax@1
    short v4; // dx@1
    short v5; // si@2
    short v6; // cx@4
    RGE_Sound *v7; // ecx@11
    RGE_Player *v8; // edx@12
    int result; // eax@15

    v3 = this;
    v4 = this->sel_count;
    if( v4 >= 25 )
        goto LABEL_19;
    v5 = -1;
    if( this->sel_list[v4] )
    {
        v6 = 0;
        if( v4 > 0 )
        {
            while( v3->sel_list[v6] )
            {
                if( ++v6 >= v4 )
                    goto LABEL_9;
            }
            v5 = v6;
        }
    }
    else
    {
        v5 = this->sel_count;
    }
LABEL_9:
    if( v5 == -1 )
    {
LABEL_19:
        result = 0;
    }
    else
    {
        v3->sel_list[v5] = obj;
        ++v3->sel_count;
        v3->selected_obj = obj;
        obj->selected = 1;
        if( play_sound )
        {
            v7 = obj->master_obj->selected_sound;
            if( v7 )
            {
                v8 = obj->owner;
                if( v8 == v3 || !v8->id )
                    RGE_Sound::play(v7, 1);
            }
        }
        result = 1;
    }
    return result;
}

//----- (00470E30) --------------------------------------------------------
void RGE_Player::unselect_object()
{
    short v1; // si@2
    short v2; // di@2
    RGE_Static_Object *v3; // edx@4

    if( this->sel_count > 0 )
    {
        v1 = 0;
        this->selected_obj = 0;
        v2 = 0;
        do
        {
            if( v2 >= this->sel_count )
                break;
            v3 = this->sel_list[v1];
            if( v3 )
            {
                v3->selected = 0;
                ++v2;
                this->sel_list[v1] = 0;
            }
            ++v1;
        }
        while( v1 < 25 );
        this->sel_count = 0;
    }
}

//----- (00470E80) --------------------------------------------------------
void RGE_Player::unselect_one_object(RGE_Static_Object *obj)
{
    short v2; // di@1
    short v3; // dx@2
    short v4; // si@2
    RGE_Static_Object *v5; // eax@4

    v2 = this->sel_count;
    if( v2 > 0 )
    {
        v3 = 0;
        v4 = 0;
        while( v4 < v2 )
        {
            v5 = this->sel_list[v3];
            if( v5 )
            {
                if( v5 == obj )
                {
                    RGE_Player::unselect_one_object(this, v3);
                    return;
                }
                ++v4;
            }
            if( ++v3 >= 25 )
                return;
        }
    }
}

//----- (00470ED0) --------------------------------------------------------
void RGE_Player::unselect_one_object(short index)
{
    RGE_Static_Object *v2; // esi@1
    int v3; // edx@2
    RGE_Static_Object *v4; // edx@5
    short v5; // ax@5
    short v6; // ax@7

    v2 = this->sel_list[index];
    if( v2 )
    {
        v2->selected = 0;
        v3 = this->sel_count;
        if( index < v3 - 1 )
        {
            this->sel_list[index] = (RGE_Static_Object *)*((_DWORD *)&this->selected_obj + v3);
            *((_DWORD *)&this->selected_obj + this->sel_count) = 0;
        }
        else
        {
            this->sel_list[index] = 0;
        }
        v4 = this->selected_obj;
        v5 = --this->sel_count;
        if( v4 == v2 )
        {
            this->selected_obj = 0;
            if( v5 > 0 )
            {
                v6 = 0;
                while( !this->sel_list[v6] )
                {
                    if( ++v6 >= 25 )
                        return;
                }
                this->selected_obj = this->sel_list[v6];
            }
        }
    }
}

//----- (00470F80) --------------------------------------------------------
int RGE_Player::group_objects(int id)
{
    RGE_Player *v2; // edx@1
    signed short v4; // ax@4
    char v5; // bl@7
    RGE_Object_Node *i; // ecx@10
    signed short v7; // ax@15
    RGE_Object_Node *j; // eax@22
    short v9; // si@26
    short v10; // di@26
    RGE_Static_Object *v11; // eax@28
    char ida; // [sp+10h] [bp+4h]@11

    v2 = this;
    if( !this->sel_count )
        return 0;
    if( id == -1 )
    {
        v4 = 11;
        while( this->groups_used[v4] )
        {
            if( ++v4 >= 127 )
            {
                v5 = -1;
                goto LABEL_9;
            }
        }
        v5 = v4;
        this->groups_used[v4] = 1;
LABEL_9:
        if( v4 == 127 )
        {
            memset(&this->groups_used[1], 0, 0x7Cu);
            *(_WORD *)&this->groups_used[125] = 0;
            for( i = this->objects->list; i; i = i->next )
            {
                v5 = i->node->selected_group;
                ida = i->node->selected_group;
                if( v5 && !v2->groups_used[(unsigned __int8)ida] )
                    v2->groups_used[(unsigned __int8)ida] = 1;
            }
            v7 = 1;
            while( v2->groups_used[v7] )
            {
                if( ++v7 >= 127 )
                    goto LABEL_20;
            }
            v5 = v7;
            v2->groups_used[v7] = 1;
LABEL_20:
            if( v7 == 127 )
                return 0;
        }
    }
    else
    {
        v5 = id;
        for( j = this->objects->list; j; j = j->next )
        {
            if( j->node->selected_group == (_BYTE)id )
                j->node->selected_group = 0;
        }
    }
    v9 = 0;
    v10 = 0;
    do
    {
        if( v10 >= v2->sel_count )
            break;
        v11 = v2->sel_list[v9];
        if( v11 )
        {
            if( v11->owner == v2 )
            {
                ++v10;
                v11->selected_group = v5;
            }
        }
        ++v9;
    }
    while( v9 < 25 );
    return 1;
}

//----- (004710C0) --------------------------------------------------------
BOOL RGE_Player::select_group(int id)
{
    RGE_Player *v2; // edi@1
    signed int v3; // ebp@1
    RGE_Object_Node *i; // esi@1
    RGE_Static_Object *v5; // eax@2

    v2 = this;
    v3 = 1;
    for( i = this->objects->list; i; i = i->next )
    {
        v5 = i->node;
        if( i->node->selected_group == (_BYTE)id )
        {
            if( v3 )
            {
                if( !RGE_Player::select_one_object(v2, v5, 1) )
                    return v3 == 0;
                v3 = 0;
            }
            else if( !RGE_Player::select_one_object(v2, v5, 0) )
            {
                return v3 == 0;
            }
        }
    }
    return v3 == 0;
}

//----- (00471120) --------------------------------------------------------
int RGE_Player::own_selected()
{
    short v1; // dx@1
    short v2; // si@1
    RGE_Static_Object *v3; // eax@3

    v1 = 0;
    v2 = 0;
    while( v2 < this->sel_count )
    {
        v3 = this->sel_list[v1];
        if( v3 )
        {
            ++v2;
            if( v3->owner == this )
                return 1;
        }
        if( ++v1 >= 25 )
            return 0;
    }
    return 0;
}

//----- (00471170) --------------------------------------------------------
int RGE_Player::is_category_selected(short object_category)
{
    short v2; // dx@1
    short v3; // si@1
    RGE_Static_Object *v4; // eax@3

    v2 = 0;
    v3 = 0;
    while( v3 < this->sel_count )
    {
        v4 = this->sel_list[v2];
        if( v4 )
        {
            ++v3;
            if( v4->master_obj->id == object_category )
                return 1;
        }
        if( ++v2 >= 25 )
            return 0;
    }
    return 0;
}

//----- (004711D0) --------------------------------------------------------
int RGE_Player::is_group_selected(short object_group)
{
    short v2; // dx@1
    short v3; // si@1
    RGE_Static_Object *v4; // eax@3

    v2 = 0;
    v3 = 0;
    while( v3 < this->sel_count )
    {
        v4 = this->sel_list[v2];
        if( v4 )
        {
            ++v3;
            if( v4->master_obj->object_group == object_group )
                return 1;
        }
        if( ++v2 >= 25 )
            return 0;
    }
    return 0;
}

//----- (00471230) --------------------------------------------------------
char RGE_Player::unit_level_selected()
{
    char result; // al@1
    short v2; // si@1
    short v3; // di@1
    RGE_Static_Object *v4; // edx@3

    result = 0;
    v2 = 0;
    v3 = 0;
    while( v3 < this->sel_count )
    {
        v4 = this->sel_list[v2];
        if( v4 )
        {
            if( v3 && v4->master_obj->unit_level != result )
                return 0;
            ++v3;
            result = v4->master_obj->unit_level;
        }
        if( ++v2 >= 25 )
            return result;
    }
    return result;
}

//----- (00471290) --------------------------------------------------------
int RGE_Player::get_select_level(RGE_Static_Object *a2)
{
    unsigned __int8 v2; // bl@1
    short v3; // dx@1
    short v4; // si@1
    int select_level; // [sp+Ch] [bp-4h]@0

    v2 = -1;
    v3 = 0;
    v4 = 0;
    do
    {
        if( v4 >= this->sel_count )
            break;
        a2 = this->sel_list[v3];
        if( a2 )
        {
            a2 = (RGE_Static_Object *)a2->master_obj;
            LOBYTE(a2) = BYTE1(a2[1].id);
            if( (unsigned __int8)a2 < v2 )
                v2 = (unsigned __int8)a2;
            ++v4;
        }
        ++v3;
    }
    while( v3 < 25 );
    LOBYTE(select_level) = v2;
    LOBYTE(a2) = v2 == -1;
    return select_level & (unsigned int)(&a2[-1].underAttackValue + 1);
}

char RGE_Player::get_selected_objects_to_command(
    RGE_Static_Object ***list_in,
    short *list_num_in,
    int min_select_level,
    short object_group,
    short object_id,
    short unit_level)
{
    RGE_Player *v7; // esi@1
    signed int v8; // ebp@1
    short v9; // bx@1
    short v10; // ax@1
    char result; // al@2
    RGE_Static_Object **v12; // edi@5
    RGE_Static_Object *v13; // edx@7
    RGE_Master_Static_Object *v14; // ecx@10
    char v15; // cl@18
    int v16; // ecx@20
    int j; // [sp+10h] [bp-8h]@5
    RGE_Static_Object **list; // [sp+14h] [bp-4h]@3

    v7 = this;
    v8 = 0;
    *list_in = 0;
    v9 = 0;
    *list_num_in = 0;
    v10 = this->sel_count;
    if( v10 )
    {
        list = (RGE_Static_Object **)calloc(4u, v10);
        if( (_WORD)min_select_level == -1 )
            min_select_level = 4;
        j = 0;
        v12 = v7->sel_list;
        do
        {
            if( j >= v7->sel_count )
                break;
            v13 = *v12;
            if( *v12 )
            {
                if( v13->object_state == 2 && v13->owner == v7 )
                {
                    v14 = v13->master_obj;
                    if( (v14->select_level >= (signed short)min_select_level || !v7->id)
                        && (object_group == -1 || v14->object_group == (unsigned __int8)object_group)
                        && (object_id == -1 || v14->id == (unsigned __int8)object_id)
                        && (unit_level == -1 || v14->unit_level == (_BYTE)unit_level) )
                    {
                        v15 = v14->master_type;
                        if( (unsigned __int8)v15 >= 0x28u && v15 != 90 )
                        {
                            v16 = v9++;
                            list[v16] = v13;
                        }
                    }
                }
                ++j;
            }
            ++v8;
            ++v12;
        }
        while( v8 < 25 );
        if( v9 )
        {
            *list_in = list;
            *list_num_in = v9;
            result = 1;
        }
        else
        {
            free(list);
            result = 0;
        }
    }
    else
    {
        result = 0;
    }
    return result;
}

void RGE_Player::update_selected()
{
    short v1; // si@1
    RGE_Player *v2; // edi@1
    short v3; // bp@1
    RGE_Static_Object *v4; // eax@3

    v1 = 0;
    v2 = this;
    v3 = 0;
    do
    {
        if( v3 >= v2->sel_count )
            break;
        v4 = v2->sel_list[v1];
        if( v4 )
        {
            if( v4->object_state >= 7u || v4->inside_obj )
                RGE_Player::unselect_one_object(v2, v1);
            else
                ++v3;
        }
        ++v1;
    }
    while( v1 < 25 );
}

void RGE_Player::select_area(
    short col1,
    short row1,
    short col2,
    short row2)
{
    this->selected_start_col = col1;
    this->selected_start_row = row1;
    this->selected_end_col   = col2;
    this->selected_end_row   = row2;
}

void RGE_Player::unselect_area()
{
    this->selected_start_col = -1;
    this->selected_start_row = -1;
    this->selected_end_col   = -1;
    this->selected_end_row   = -1;
}

//----- (004714E0) --------------------------------------------------------
void RGE_Player::ungroup_objects()
{
    signed int v1; // esi@1
    signed int v2; // edi@1
    char *v3; // edx@1

    v1 = 0;
    v2 = 0;
    v3 = (char *)this->sel_list;
    do
    {
        if( v2 >= this->sel_count )
            break;
        if( *(_DWORD *)v3 )
        {
            ++v2;
            *(_BYTE *)(*(_DWORD *)v3 + 55) = 0;
        }
        ++v1;
        v3 += 4;
    }
    while( v1 < 25 );
}

int RGE_Player::get_mouse_pointer_action_vars(
    int Obj_id,
    int *newFacet,
    int *text_id)
{
    *newFacet = 0;
    *text_id = 0;
    return 0;
}

bool RGE_Player::command_make_move(
    RGE_Static_Object *obj,
    float x,
    float y)
{
    RGE_Player *v4; // esi@1
    char result; // al@2
    RGE_Static_Object **list; // [sp+4h] [bp-8h]@1
    int list_num; // [sp+8h] [bp-4h]@1

    v4 = this;
    if( this->get_selected_objects_to_command(&list, (short *)&list_num, -1, -1, -1, -1) ){
        (*list)->play_move_sound();
        this->world->commands->command_move(list, list_num, obj, x, y);
        free(list);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004715D0) --------------------------------------------------------
bool RGE_Player::command_make_work(RGE_Static_Object *obj, float x, float y)
{
    RGE_Player *v4; // ebx@1
    int v5; // eax@2
    signed int v6; // edi@5
    void (*v7)(RGE_Player *, int, int, int, int, int, float, float, float, float, int, int, int); // ebp@6
    float v8; // ST20_4@7
    char result; // al@8
    RGE_Static_Object **list; // [sp+40h] [bp-8h]@1
    int list_num; // [sp+44h] [bp-4h]@1

    v4 = this;
    if( RGE_Player::get_selected_objects_to_command(this, &list, (short *)&list_num, -1, -1, -1, -1) )
    {
        v5 = ((int (__stdcall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD))(*list)->vfptr->get_command_master)(
                     obj,
                     LODWORD(x),
                     LODWORD(y),
                     0);
        if( v5 )
            (*(void (**)(int))(*(_DWORD *)v5 + 44))(v5);
        RGE_Command::command_work(v4->world->commands, list, list_num, obj, x, y);
        if( obj )
        {
            v6 = 0;
            if( (signed short)list_num > 0 )
            {
                v7 = v4->vfptr->sendUnitAIOrder;
                do
                {
                    v8 = obj->master_obj->los * 0.5;
                    ((void (*)(RGE_Player *, _DWORD, int, signed int, int, _DWORD, _DWORD, _DWORD, signed int, _DWORD, _DWORD, _DWORD, signed int))v7)(
                        v4,
                        v4->id,
                        list[v6++]->id,
                        701,
                        obj->id,
                        obj->owner->id,
                        LODWORD(obj->world_x),
                        LODWORD(obj->world_y),
                        1065353216,
                        LODWORD(v8),
                        0,
                        0,
                        100);
                }
                while( v6 < (signed short)list_num );
            }
        }
        free(list);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004716D0) --------------------------------------------------------
bool RGE_Player::command_make_do(RGE_Static_Object *obj, float x, float y)
{
    RGE_Player *v4; // ebp@1
    int v5; // eax@2
    char result; // al@4
    RGE_Static_Object **list; // [sp+10h] [bp-8h]@1
    int list_num; // [sp+14h] [bp-4h]@1

    v4 = this;
    if( RGE_Player::get_selected_objects_to_command(this, &list, (short *)&list_num, -1, -1, -1, -1) )
    {
        v5 = ((int (__stdcall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD))(*list)->vfptr->get_command_master)(
                     obj,
                     LODWORD(x),
                     LODWORD(y),
                     0);
        if( v5 )
            (*(void (**)(int))(*(_DWORD *)v5 + 44))(v5);
        RGE_Command::command_order(v4->world->commands, list, list_num, obj, x, y);
        free(list);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00471760) --------------------------------------------------------
bool RGE_Player::command_stop()
{
    RGE_Player *v1; // esi@1
    char result; // al@2
    RGE_Static_Object **list; // [sp+4h] [bp-8h]@1
    int list_num; // [sp+8h] [bp-4h]@1

    v1 = this;
    if( RGE_Player::get_selected_objects_to_command(this, &list, (short *)&list_num, 3, -1, -1, -1) )
    {
        ((void (*)(void))(*list)->vfptr->play_command_sound)();
        RGE_Command::command_stop(v1->world->commands, list, list_num);
        free(list);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (004717D0) --------------------------------------------------------
bool RGE_Player::command_place_object(short obj_id, float x, float y, float z)
{
    char result; // al@3

    if( obj_id != -1 && this->master_objects[obj_id] )
    {
        RGE_Command::command_create(this->world->commands, obj_id, this->id, x, y, z);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

//----- (00471820) --------------------------------------------------------
bool RGE_Player::command_add_attribute(int attr_id, float attr_amount)
{
    char result; // al@3

    if( attr_id == -1 || attr_amount == 0.0 )
    {
        result = 0;
    }
    else
    {
        RGE_Command::command_add_attribute(this->world->commands, this->id, attr_id, attr_amount);
        result = 1;
    }
    return result;
}

//----- (00471860) --------------------------------------------------------
bool RGE_Player::command_give_attribute(int to_player_id, int attr_id, float attr_amount)
{
    char result; // al@4

    if( attr_id == -1 || attr_amount == 0.0 || attr_amount > (double)this->attributes[attr_id] )
    {
        result = 0;
    }
    else
    {
        ((void (*)(RGE_Command *, _DWORD, int, int, _DWORD))this->world->commands->vfptr->command_give_attribute)(
            this->world->commands,
            this->id,
            to_player_id,
            attr_id,
            LODWORD(attr_amount));
        result = 1;
    }
    return result;
}

//----- (004718C0) --------------------------------------------------------
bool RGE_Player::command_formation(int formationID)
{
    int v2; // edi@1
    RGE_Player *v3; // esi@1
    char result; // al@4
    RGE_Static_Object **list; // [sp+8h] [bp-4h]@3

    v2 = formationID;
    v3 = this;
    if( formationID >= 0
        && formationID <= 5
        && RGE_Player::get_selected_objects_to_command(this, &list, (short *)&formationID, -1, -1, -1, -1) )
    {
        ((void (*)(void))(*list)->vfptr->play_command_sound)();
        RGE_Command::command_formation(v3->world->commands, list, (signed short)formationID, v2);
        free(list);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

bool RGE_Player::command_stand_ground()
{
    if( !this->get_selected_objects_to_command(&list, (short *)&listNum, -1, -1, -1, -1) ){
        return false;
    }
    (*list)->play_command_sound();

    this->world->commands->command_group_ai_order(
        this->id,
        this->id,
        list,
        listNum,
        725,
        -1,
        -1,
        -1.0,
        -1.0,
        -1.0,
        1.0,
        1,
        0,
        100);

    free(list);

    return true;
}

bool RGE_Player::command_create_group(
    int commander,
    int *groupList,
    int groupLength,
    float range)
{
    this->world->commands->command_create_group(
        this->id,
        commander,
        groupList,
        groupLength,
        range);

    return true;
}

bool RGE_Player::command_add_to_group(
    int commander,
    int unitID,
    float range)
{
    this->world->commands->command_add_to_group(
        this->id,
        commander,
        unitID,
        range);

    return true;
}

bool RGE_Player::command_remove_from_group(
    int commander,
    int unitID)
{
    this->world->commands->command_remove_from_group(
        this->id,
        commander,
        unitID);

    return true;
}

bool RGE_Player::command_destroy_group(
    int unitID)
{
    this->world->commands->command_destroy_group(
        this->id,
        unitID);

    return true;
}

bool RGE_Player::command_resign(
    int comm_player_id,
    int dropped)
{
    if( this->game_status ){
        return false;
    }
    this->world->commands->command_resign(
        this->id,
        comm_player_id,
        dropped);

    return true;
}

bool RGE_Player::command_add_waypoint(
    float x,
    float y,
    float z)
{
    if( this->get_selected_objects_to_command(&list, (short *)&list_num, -1, -1, -1, -1) ){
        (*list)->play_command_sound();
        this->world->commands->command_group_waypoint(list, list_num, x, y);
        free(list);

        return true;
    }

    return false;
}

RGE_Object_Node *RGE_Player::addObject(
    RGE_Static_Object *obj,
    int sleep_flag,
    int dopple_flag)
{
    RGE_Player *v4; // esi@1
    RGE_Static_Object *v5; // edi@2
    RGE_Object_List *v6; // ecx@4
    RGE_Object_Node *v7; // eax@2
    RGE_Object_Node *v8; // ebx@7

    v4 = this;
    if( sleep_flag )
    {
        v5 = obj;
        v7 = RGE_Object_List::add_node(this->sleeping_objects, obj);
    }
    else
    {
        v5 = obj;
        if( dopple_flag )
            v6 = this->doppleganger_objects;
        else
            v6 = this->objects;
        v7 = RGE_Object_List::add_node(v6, obj);
    }
    v8 = v7;
    ((void (__stdcall *)(RGE_Static_Object *))v4->world->vfptr->addObject)(v5);
    return v8;
}

void RGE_Player::removeObject(
    RGE_Static_Object *obj,
    int sleep_flag,
    int dopple_flag,
    RGE_Object_Node *node)
{
    switch( true ){

    case sleep_flag != 0:
        this->sleeping_objects->remove_node(obj, node);
        break;

    case dopple_flag != 0:
        this->doppleganger_objects->remove_node(obj, node);
        break;

    default:
        this->objects->remove_node(obj, node);
        break;
    }
    this->world->removeObject(obj->id);
}

void RGE_Player::set_map_visible()
{
    this->visible->set_all(1);
}

void RGE_Player::remake_visible_map()
{
    if( this->visible ){
        delete this->visible;
    }
    this->visible = RGE_Visible_Map(this->world->map, this);
}

void RGE_Player::load_victory(
    int infile,
    int *player_id_hash,
    bool version_control)
{
    this->victory_conditions = new RGE_Victory_Conditions(
        infile,
        player_id_hash,
        version_control);
}

void RGE_Player::new_victory()
{
    this->victory_conditions = new RGE_Victory_Conditions(this);
}

void RGE_Tile_List::add_node(int col, int row)
{
    if( this->num_active >= this->list_size ){
        RGE_Tile_List_Node *list_node = new RGE_Tile_List_Node[2 * this->list_size];
        memcpy(list_node, this->list, 8 * this->list_size);
        free(this->list);
        this->list = list_node;
        this->list_size *= 2;
    }
    this->list[this->num_active].col = col;
    this->list[this->num_active].row = row;

    this->num_active++;
    this->new_count++;
}

void RGE_Tile_List::del_list()
{
    this->num_active = 0;
    this->new_count = 0;
    if( this->collapse_list ){
        free(this->list);
        this->list_size = 8;
        this->list = new RGE_Tile_List_Node[8];
        this->collapse_list = 0;
    }
}

RGE_Tile_List::RGE_Tile_List(int Initial_Size)
{
    this->list = new RGE_Tile_List_Node[Initial_Size];
    this->list_size = Initial_Size;
    this->num_active = 0;
    this->new_count = 0;
    this->collapse_list = 0;
}

RGE_Tile_List::~RGE_Tile_List()
{
    if( this->list )
        free(this->list);
}

void RGE_Tile_List::get_list_info(
    RGE_Tile_List_Node **theList,
    int *list_size)
{
    *theList = this->list;
    *list_size = this->num_active;
}

int RGE_Tile_List::get_new_count()
{
    int result = this->new_count;
    this->new_count = 0;
    return result;
}
