
/**
 * @file    Engine\RGE\GameWorld.cpp
 * @author  Yvan Burrie
 * @date    2018/07/04
 * @version 1.0
 */

#define RGE_WORLD_DATABASE_VERSION "VER 3.7"

#define RGE_WORLD_RECORD_VERSION "VER 3.7"

#define RGE_WORLD_SAVE_VERSION 11.76

float save_game_version = RGE_WORLD_SAVE_VERSION;

int world_update_counter;

RGE_Game_World::RGE_Game_World()
{
    this->objectsValue = 0;
    this->numberObjectsValue = 0;
    this->maxNumberObjectsValue = 10000;
    this->negativeObjectsValue = 0;
    this->numberNegativeObjectsValue = 0;
    this->maxNumberNegativeObjectsValue = 1000;

    this->maximumComputerPlayerUpdateTime   = 2;
    this->availableComputerPlayerUpdateTime = 2;

    world_update_counter = 0;

    this->objectsValue         = new RGE_Static_Object[this->maxNumberObjectsValue];
    this->negativeObjectsValue = new RGE_Static_Object[this->maxNumberNegativeObjectsValue];

    VIS_UNIT_objectsValue = this->objectsValue;

    this->playbook = 0;
    this->sound_num = 0;
    this->sounds = 0;
    this->sprite_num = 0;
    this->sprites = 0;
    this->player_num = 0;
    this->players = 0;
    this->master_player_num = 0;
    this->master_players = 0;
    this->terrain_num = 0;
    this->terrains = 0;
    this->color_table_num = 0;
    this->color_tables = 0;
    this->commands = 0;
    this->scenario = 0;
    this->effects = 0;
    this->map = 0;
    this->world_time = 0;
    this->old_world_time = 0;
    this->world_time_delta = 0;
    this->world_time_delta_seconds = 0.0;
    this->timer = 0.0;
    this->old_time = 0;
    this->game_speed = 0.0;
    this->temp_pause = 0;
    this->next_object_id = 0;
    this->random_seed = 14;
    this->curr_player = 1;
    this->sound_driver = 0;
    this->game_state = 2;
    this->game_end_condition = 0;
    this->sound_update_index = 0;
    this->sprite_update_index = 0;
    this->player_turn = 0;

    memset(this->player_time_delta, 0, sizeof(this->player_time_delta));

    this->reusable_static_objects       = new RGE_Object_List;
    this->reusable_animated_objects     = new RGE_Object_List;
    this->reusable_moving_objects       = new RGE_Object_List;
    this->reusable_action_objects       = new RGE_Object_List;
    this->reusable_combat_objects       = new RGE_Object_List;
    this->reusable_missile_objects      = new RGE_Object_List;
    this->reusable_doppleganger_objects = new RGE_Object_List;

    this->scenario_object_flag = 0;

    if( !DVlogf ){
        DVlogf = fopen(aCAoewvlog_txt, aW_1);
    }
}

RGE_Game_World::~RGE_Game_World()
{
    if( this->commands ){
        delete this->commands
    }

    this->del_game_info());

    if( this->reusable_static_objects ){
        delete this->reusable_static_objects;
    }
    if( this->reusable_animated_objects ){
        delete this->reusable_animated_objects;
    }
    if( this->reusable_moving_objects ){
        delete this->reusable_moving_objects;
    }
    if( this->reusable_action_objects ){
        delete this->reusable_action_objects;
    }
    if( this->reusable_combat_objects ){
        delete this->reusable_combat_objects;
    }
    if( this->reusable_missile_objects ){
        delete this->reusable_missile_objects;
    }
    if( this->reusable_doppleganger_objects ){
        delete this->reusable_doppleganger_objects;
    }
    if( this->master_players ){
        for( int i = 0; i < this->master_player_num; i++ ){
            if( this->master_players[i] ){
                delete this->master_players[i];
            }
        }
        delete this->master_players;
    }
    if( this->effects ){
        delete this->effects;
    }
    if( this->map ){
        delete this->map;
    }
    if( this->sprites ){
        for( int j = 0; j < this->sprite_num; j++ ){
            if( this->sprites[j] ){
                delete this->sprites[j];
            }
        }
        delete this->sprites;
    }
    if( this->sounds ){
        for( int k = 0; k < this->sound_num; k++ ){
            if( this->sounds[k] ){
                delete this->sounds[k];
            }
        }
        delete this->sounds;
    }
    if( this->terrains ){
        for( int l = 0; l < this->terrain_num; l++ ){
            if( this->terrains[l] ){
                delete this->terrains[l];
            }
        }
        delete this->terrains;
    }
    if( this->color_tables ){
        for( int m = 0; m < this->color_table_num; m++ ){
            if( this->color_tables[m] ){
                delete this->color_tables[m];
            }
        }
        delete this->color_tables;
    }
    if( this->objectsValue ){
        delete this->objectsValue;
        delete VIS_UNIT_objectsValue;
    }
    if( this->negativeObjectsValue ){
        delete this->negativeObjectsValue;
    }
    if( logStatusFile ){
        fclose(logStatusFile);
        delete logStatusFile;
    }
    if( this->playbook ){
        delete this->playbook;
    }
    if( DVlogf ){
        fclose(DVlogf);
        delete DVlogf;
    }
}

void RGE_Game_World::reset_object_count()
{
    this->world_time = 0;
    this->old_world_time = 0;
    this->world_time_delta = 0;
    this->world_time_delta_seconds = 0.0;
    this->timer = 0.0;
    this->old_time = 0;
    this->temp_pause = 0;
    this->next_object_id = 0;
    this->player_turn = 0;

    memset(this->player_time_delta, 0, sizeof(this->player_time_delta));
}

void RGE_Game_World::pause(char flag)
{
    if( flag ){
        for( int i = 0; i < this->sound_num; i++ ){
            this->sounds[i]->stop();
        }
    }
}

void RGE_Game_World::set_map_visible(char flag)
{
    if( this->map ){
        this->map->set_map_visible(flag);
    }
}

void RGE_Game_World::set_map_fog(char flag)
{
    if( this->map ){
        this->map->set_map_fog(flag);
    }
}

bool RGE_Game_World::init_player_type(int infile, short index, char type)
{
    switch( type ){

    case 0:
        this->master_players[index] = new RGE_Master_Player(infile);
        this->master_players[index]->finish_init(
            infile,
            this->sprites,
            this->sounds);
        return true;

    default:
        return false;
    }
}

bool RGE_Game_World::init_player(int infile)
{
    rge_read(infile, &this->master_player_num, 2);

    if( this->master_player_num > 0 ){
        this->master_players = new RGE_Master_Player[this->master_player_num];
    }
    for( int i = 0; i < this->master_player_num; i++ ){

        char pl_type;

        rge_read(infile, &pl_type, 1);

        this->init_player_type(infile, i, pl_type);
    }
    return true;
}

void RGE_Game_World::terrain_tables_init(int infile)
{
    RGE_Game_World *v3; // esi@1
    char *v4; // ebx@1
    short *v5; // edi@1
    float **v6; // eax@3
    int v7; // ecx@3
    signed int i; // ebx@3

    v3 = this;
    v4 = (char *)&this->terrain_num;
    rge_read(infile, &this->terrain_num, 2);
    v5 = &v3->terrain_size;
    rge_read(infile, (int)&v3->terrain_size, infile, &v3->terrain_size, 2);
    if( *(_WORD *)v4 > 0 && *v5 > 0 )
    {
        v6 = (float **)calloc(*(_WORD *)v4, 4u);
        v7 = *(_WORD *)v4;
        v3->terrains = v6;
        rge_read(infile, (int)v5, infile, v6, 4 * v7);
        for( i = 0; i < v3->terrain_num; ++i )
        {
            if( v3->terrains[i] )
            {
                v3->terrains[i] = (float *)calloc(*v5, 4u);
                rge_read(infile, (int)v5, infile, v3->terrains[i], 4 * *v5);
            }
        }
    }
}

void RGE_Game_World::color_table_init(int infile)
{
    RGE_Game_World *v3; // ebx@1
    char *v4; // edi@1
    RGE_Color_Table **v5; // eax@2
    signed int v6; // esi@2
    bool v7; // zf@2
    bool v8; // sf@2
    RGE_Color_Table *v9; // eax@3
    RGE_Color_Table *v10; // eax@4

    v3 = this;
    v4 = (char *)&this->color_table_num;
    rge_read(a2, (int)&this->color_table_num, infile, &this->color_table_num, 2);
    if( *(_WORD *)v4 > 0 )
    {
        v5 = (RGE_Color_Table **)calloc(*(_WORD *)v4, 4u);
        v6 = 0;
        v7 = *(_WORD *)v4 == 0;
        v8 = *(_WORD *)v4 < 0;
        v3->color_tables = v5;
        if( !v8 && !v7 )
        {
            do
            {
                v9 = (RGE_Color_Table *)operator new(0x128u);
                if( v9 )
                    RGE_Color_Table::RGE_Color_Table(v9, -1, infile);
                else
                    v10 = 0;
                v3->color_tables[++v6 - 1] = v10;
            }
            while( v6 < *(_WORD *)v4 );
        }
    }
}

void RGE_Game_World::init_sounds(int infile, TSound_Driver *sound_dvr)
{
    RGE_Game_World *v3; // edi@1
    char *v4; // ebx@1
    RGE_Sound **v5; // eax@1
    signed int v6; // esi@1
    bool v7; // zf@1
    bool v8; // sf@1
    RGE_Sound *v9; // eax@2
    RGE_Sound *v10; // eax@3

    v3 = this;
    v4 = (char *)&this->sound_num;
    rge_read(infile, (int)this, infile, &this->sound_num, 2);
    v5 = (RGE_Sound **)calloc(*(_WORD *)v4, 4u);
    v6 = 0;
    v7 = *(_WORD *)v4 == 0;
    v8 = *(_WORD *)v4 < 0;
    v3->sounds = v5;
    if( !v8 && !v7 )
    {
        do
        {
            v9 = (RGE_Sound *)operator new(0x10u);
            if( v9 )
                RGE_Sound::RGE_Sound(v9, (int)v3, infile, v3->sound_driver);
            else
                v10 = 0;
            v3->sounds[++v6 - 1] = v10;
        }
        while( v6 < *(_WORD *)v4 );
    }
}

void RGE_Game_World::init_sprites(int infile)
{
    /* read sprites counter */
    rge_read(infile, &this->sprite_num, 2);

    /* allocate sprites array */
    this->sprites = new RGE_Sprite[this->sprite_num];

    /* read sprites pointers */
    rge_read(infile, &this->sprites, sizeof(void) * this->sprite_num);

    /* read each sprite */
    for( int i = 0; i < this->sprite_num; i++ ){
        if( this->sprites[i] ){
            this->sprites[i] = new RGE_Sprite(infile, this->sounds, this->color_tables);
        }
    }
    /* hook each sprite to set pointers of sub-pictures */
    for( int j = 0; j < this->sprite_num; j++ ){
        if( this->sprites[j] ){
            this->sprites[j]->rehook(this->sprites);
        }
    }
}

void RGE_Game_World::scenario_init(int infile, RGE_Game_World *world)
{
    this->scenario = new RGE_Scenario(infile, world);
}

void RGE_Game_World::scenario_init(RGE_Game_World *world)
{
    this->scenario = new RGE_Scenario(world);
}

void RGE_Game_World::map_init(int infile, TSound_Driver *sound_dvr)
{
    this->map = new RGE_Map(infile, this->sounds, true);
}

void RGE_Game_World::effects_init(int infile)
{
    this->effects = RGE_Effects(infile);
}

void RGE_Game_World::master_player_init(int infile)
{
    this->init_player(infile);
}

void RGE_Game_World::command_init(int infile, TCommunications_Handler *com_hand)
{
    this->commands = new RGE_Command(this, com_hand);
}

void RGE_Game_World::world_init(int infile, TSound_Driver *sound_dvr, TCommunications_Handler *com_hand)
{
    this->terrain_tables_init(infile);
    this->color_table_init(infile);
    this->init_sounds(infile, sound_dvr);
    this->init_sprites(infile);
    this->map_init(infile, sound_dvr);
    this->effects_init(infile);
    this->master_player_init(infile);
    this->command_init(infile, com_hand);
}

char RGE_Game_World::init(char *base_name, TSound_Driver *sound_dvr, TCommunications_Handler *com_hand)
{
    this->sound_driver = sound_dvr;

    this->next_object_id = 0;

    int file = rge_open(base_name, 0x8000);
    if( file == -1 ){
        return false;
    }
    char version[8];
    rge_read(file, version, 8);

    switch( 0 ){

    case strcmp(version, RGE_WORLD_DATABASE_VERSION):
        this->world_init(file, sound_dvr, com_hand);
        rge_close(file);
        return true;

    default:
        rge_close(file);
        return false;
    }
}

void RGE_Game_World::turn_sound_off()
{
    for( int i = 0; i < this->sound_num; i++ ){
        this->sounds[i]->stop();
    }
}

void RGE_Game_World::reset_communications(TCommunications_Handler *com_hand)
{
    this->commands->reset_communications(com_hand);
}

void RGE_Game_World::reset_player_visible_maps()
{
    for( int i = 0; i < this->player_num; i++ ){
        if( this->players[i] ){
            this->players[i]->remake_visible_map();
        }
    }
}

void RGE_Game_World::del_game_info()
{
    world_update_counter = 0;

    this->game_state = 2;
    this->game_end_condition = 0;

    this->reusable_static_objects      ->removeAllObjects();
    this->reusable_animated_objects    ->removeAllObjects();
    this->reusable_moving_objects      ->removeAllObjects();
    this->reusable_action_objects      ->removeAllObjects();
    this->reusable_combat_objects      ->removeAllObjects();
    this->reusable_missile_objects     ->removeAllObjects();
    this->reusable_doppleganger_objects->removeAllObjects();

    this->next_reusable_object_id = -1;
    this->campaign = -1;
    this->campaign_player = -1;
    this->campaign_scenario = -1;
    this->difficultyLevelValue = -1;

    this->next_object_id = 0;

    for( int j = 0; j < this->maxNumberObjectsValue; j++ ){
        this->objectsValue[v4] = 0;
    }
    for( int i = 0; i < this->maxNumberNegativeObjectsValue; i++ ){
        this->negativeObjectsValue[i] = 0;
    }

    this->turn_sound_off();

    if( this->scenario ){
        delete this->scenario;
    }
    if( this->player_num > 0 && this->players ){
        for( int v8 = 0; v8 < this->player_num; v8++ ){
            if( this->players[v8] ){
                this->players[v8]->destroy_objects();
            }
        }
    }
    if( this->player_num > 0 && this->players ){
        for( int v11 = 0; v11 < this->player_num; v11++ ){
            if( this->players[v11] ){
                delete this->players[v11];
                this->players[v11] = 0;
            }
        }
        this->player_num = 0;
        free(this->players);
        this->players = nullptr;
    }
    this->next_object_id = 0;
    this->sound_update_index = 0;
    this->sprite_update_index = 0;
    this->player_turn = 0;

    memset(this->player_time_delta, 0, sizeof(this->player_time_delta));
}

bool RGE_Game_World::load_player(int infile, char type, short index)
{
    switch( type ){

    case 0:
        this->players[index] = new RGE_Player(infile, this, index);
        return this->players[index]->load(infile);

    default:
        return false;
    }
}

bool RGE_Game_World::load_world(int infile)
{
    char game_state;
    this->game_state = 2;
    this->game_end_condition = 0;

    rge_read(infile, &this->world_time, 4);
    rge_read(infile, &this->old_world_time, 4);
    rge_read(infile, &this->world_time_delta, 4);
    rge_read(infile, &this->world_time_delta_seconds, 4);
    rge_read(infile, &this->timer, 4);
    rge_read(infile, &this->game_speed, 4);
    rge_read(infile, &this->temp_pause, 1);
    rge_read(infile, &this->next_object_id, 4);
    rge_read(infile, &this->next_reusable_object_id, 4);
    rge_read(infile, &this->random_seed, 4);
    rge_read(infile, &this->curr_player, 2);
    rge_read(infile, &this->player_num, 2);
    rge_read(infile, &game_state, 1);
    rge_read(infile, &this->campaign, 4);
    rge_read(infile, &this->campaign_player, 4);
    rge_read(infile, &this->campaign_scenario, 4);
    rge_read(infile, &this->player_turn, 4);

    for( int i = 0; i < RGE_PLAYERS_COUNT; i++ ){
        rge_read(infile, &this->player_time_delta[i], 4);
    }

    this->old_time = 0;

    this->map->load_map(infile);

    this->initializePathingSystem();

    this->currentUpdateComputerPlayer = -1;

    if( this->player_num > 0 ){
        this->players = new RGE_Player[this->player_num];
    }

    for( int player_id = 0; player_id < this->player_num; player_id++ ){

        char type;

        rge_read(infile, &type, 1);

        if( this->load_player(infile, type, player_id) == false ){
            return false;
        }
    }
    this->update_mutual_allies();

    this->map->unified_vis_map->suppress_updates(1);

    for( int n = 0; n < this->player_num; n++ ){
        this->players[i]->load_info(infile);
    }
    this->map->unified_vis_map->suppress_updates(0);

    this->scenario_init(infile, this);

#if RGE_WORLD_DIFFICULTY_LEVEL_EXISTS
    if( save_game_version >= 7.16 ){
        rge_read(infile, &this->difficultyLevelValue, 4);
    }else{
        this->difficultyLevelValue = -1;
    }
#endif

    if( rge_base_game->singlePlayerGame() ){
        this->game_speed = rge_base_game->get_game_speed();
    }
    this->game_state = game_state;

    return true;
}

bool RGE_Game_World::load_game(char *name)
{
    world_update_counter = 0;

    this->del_game_info();

    char tempname[300];
    sprintf(tempname, aSS, rge_base_game->prog_info->save_dir, name);
    int file = rge_open(tempname, 0x8000);
    if( file == -1 ){
        return false;
    }

    char version[8];
    rge_read(file, version, 8);

    rge_read(file, &save_game_version, 4);

    switch( true ){

    case strcmp(version, "VER 8.6") == 0:
        bool res = this->load_world(file);
        rge_close(file);
        return res;

    default:
        rge_close(file);
        return false;
    }
}

void RGE_Game_World::set_game_speed(float new_speed)
{
    this->game_speed = new_speed;
}

char *new_name = "GAIA";

void RGE_Game_World::setup_gaia()
{
    this->players = new RGE_Player(this, this->master_players[0], 0, new_name, 0, true);
}

void RGE_Game_World::setup_players(RGE_Player_Info *info)
{
    RGE_Game_World *v2; // edi@1
    signed int v3; // ebx@1
    int v4; // esi@2
    RGE_Player *v5; // eax@3
    char v6; // dl@4
    RGE_Player *v7; // eax@4
    signed int index; // [sp+8h] [bp-10h]@1

    v2 = this;
    v3 = 1;
    index = 1;
    if( this->player_num > 1 )
    {
        do
        {
            v4 = (signed short)v3;
            if( info->name[8][(signed short)v3 + 64] != -1 )
            {
                v5 = (RGE_Player *)operator new(0x220u);
                if( v5 )
                {
                    v6 = info->type[(signed short)v3 + 8];
                    v3 = index;
                    RGE_Player::RGE_Player(v5, v2, v2->master_players[v6], index, (char *)info + 64 * v4 + v4 - 65, v6, 1);
                }
                else
                {
                    v7 = 0;
                }
                v2->players[v4] = v7;
            }
            index = ++v3;
        }
        while( (signed short)v3 < v2->player_num );
    }
}

void RGE_Game_World::setup_player_colors(RGE_Player_Info *info)
{
    RGE_Game_World *this; // esi@1
    signed int v3; // ebx@1
    signed int v4; // edi@3
    char *v5; // ebp@3
    char *v6; // ebp@4
    signed int i; // edi@11
    char v8; // al@13
    char *colors_used; // [sp+10h] [bp-Ch]@3
    char *players_done; // [sp+14h] [bp-8h]@3
    int info_player_num; // [sp+18h] [bp-4h]@1

    this = this;
    v3 = -1;
    RGE_Player::set_color_table(*this->players, 7);
    info_player_num = info->player_num;
    if( info_player_num > this->player_num + 1 )
        info_player_num = this->player_num + 1;
    v4 = 1;
    v5 = (char *)calloc(this->color_table_num, 1u);
    colors_used = v5;
    players_done = (char *)calloc(this->player_num, 1u);
    if( this->player_num > 1 )
    {
        v6 = (char *)info->color;
        do
        {
            if( v4 - 1 < info_player_num && *(_WORD *)v6 >= 0 && !colors_used[*(_WORD *)v6] )
            {
                this->players[v4]->set_color_table(*v6);
                colors_used[*(_WORD *)v6] = 1;
                players_done[v4] = 1;
            }
            ++v4;
            v6 += 2;
        }
        while( v4 < this->player_num );
        v5 = colors_used;
    }
    for( i = 1; i < this->player_num; ++i )
    {
        if( !players_done[i] )
        {
            do
            {
                do
                    v8 = v5[v3++ + 1];
                while( v8 == 1 );
            }
            while( this->color_tables[v3]->type != 1 );
            this->players[i]->set_color_table(v3);
            v5[v3] = 1;
        }
    }
    free(v5);
    free(players_done);
}

void RGE_Game_World::setup_player_colors()
{
    RGE_Game_World *v1; // edi@1
    signed int v2; // esi@1
    signed int v3; // ebp@1
    _BYTE *v4; // ebx@1
    char v5; // al@2

    v1 = this;
    v2 = -1;
    this->players[0]->set_color_table(7);
    v3 = 1;
    v4 = calloc(v1->color_table_num, 1u);
    if( v1->player_num > 1 )
    {
        while( 1 )
        {
            do
                v5 = v4[v2++ + 1];
            while( v5 == 1 );
            if( v1->color_tables[v2]->type == 1 )
            {
                RGE_Player::set_color_table(v1->players[v3], v2);
                v4[v2] = 1;
                if( ++v3 >= v1->player_num )
                    break;
            }
        }
    }
    free(v4);
}

char RGE_Game_World::new_game(RGE_Player_Info *info, int myPlayerNum)
{
    RGE_Game_World *v3; // esi@1
    RGE_Game_WorldVtbl *v4; // edi@1
    int v5; // eax@2
    int v6; // eax@5
    RGE_Player_Info *v7; // ebp@5
    int v8; // eax@5
    short v9; // ax@5
    int v10; // eax@5
    int v11; // eax@5
    signed int v12; // ebx@5
    PLAYERHUMANITY v13; // eax@6
    int v14; // edi@8
    signed int v15; // ebp@9
    PLAYERHUMANITY v16; // eax@11
    int v17; // edi@14
    int v18; // eax@14
    int v19; // edi@15
    signed int v20; // ebx@21
    signed int v21; // ebp@27
    PLAYERHUMANITY v22; // eax@28
    int v23; // edi@30
    int v24; // eax@30
    int v25; // edi@31
    signed int v26; // edi@35
    char *v27; // eax@38
    signed int v28; // ebx@38
    RGE_Game_WorldVtbl *v29; // eax@40
    RGE_Player *v30; // ecx@44
    int v31; // eax@49
    signed int v32; // edi@49
    RGE_Player *v33; // ecx@51
    char v35; // [sp+29h] [bp-105h]@39
    int team; // [sp+2Ah] [bp-104h]@8
    char randomString[256]; // [sp+2Eh] [bp-100h]@49

    v3 = this;
    world_update_counter = 0;
    PathingSystem::zeroObstructionMap(&pathSystem);
    PathingSystem::zeroObstructionMap(&aiPathSystem);
    v3->currentUpdateComputerPlayer = -1;
    memset(&computerPlayerSetup, 0, 0x34u);
    v4 = v3->vfptr;
    v3->vfptr->del_game_info(v3);
    debug_random_reset();
    debug_timeGetTime_cnt = 0;
    debug_timeGetTime_time = 0;
    v3->game_state = 3;
    v3->curr_player = myPlayerNum;
    if( RGE_Base_Game::multiplayerGame(rge_base_game) )
    {
        v5 = TCommunications_Handler::GetRandomSeed(v3->commands->com_hand);
    }
    else
    {
        v5 = rge_base_game->random_game_seed;
        if( v5 == -1 )
            v5 = debug_rand(aCMsdevWorkAge1, 1289);
    }
    v3->random_seed = v5;
    debug_srand(aCMsdevWorkAge1, 1292, v5);
    rge_base_game->save_random_game_seed = v3->random_seed;
    v6 = debug_rand(aCMsdevWorkAge1, 1295);
    v3->random_seed = v6;
    TDebuggingLog::Log(L, aWorldNew_gameR, v6);
    v7 = info;
    v3->player_num = info->player_num + 1;
    RGE_Map::new_map(v3->map, info->map_width, info->map_height);
    v8 = debug_rand(aCMsdevWorkAge1, 1302);
    v3->random_seed = v8;
    TDebuggingLog::Log(L, aWorldAfter_new, v8);
    v9 = info->player_num + 1;
    v3->player_num = v9;
    v3->players = (RGE_Player **)calloc(4u, v9);
    v4->setup_gaia(v3);
    v10 = debug_rand(aCMsdevWorkAge1, 1312);
    v3->random_seed = v10;
    TDebuggingLog::Log(L, aWorldAfter_gai, v10);
    v4->setup_players(v3, info);
    v11 = debug_rand(aCMsdevWorkAge1, 1318);
    v3->random_seed = v11;
    TDebuggingLog::Log(L, aWorldAfter_pla, v11);
    v12 = 1;
    do
    {
        v13 = TCommunications_Handler::GetPlayerHumanity(v3->commands->com_hand, v12);
        if( v13 == 2 || v13 == 4 )
        {
            v14 = RGE_Base_Game::playerTeam(rge_base_game, v12 - 1);
            team = v14;
            if( v14 > 1 )
            {
                v15 = 1;
                while( 1 )
                {
                    v16 = TCommunications_Handler::GetPlayerHumanity(v3->commands->com_hand, v15);
                    if( (v16 == 2 || v16 == 4) && RGE_Base_Game::playerTeam(rge_base_game, v15 - 1) == v14 )
                    {
                        v17 = RGE_Base_Game::playerID(rge_base_game, v12);
                        v18 = RGE_Base_Game::playerID(rge_base_game, v15);
                        if( v17 != v18 )
                        {
                            v19 = v17;
                            RGE_Player::set_relation(v3->players[v19], v18, 0);
                            RGE_Player::set_allied_victory(v3->players[v19], 1);
                        }
                    }
                    if( ++v15 >= 9 )
                        break;
                    v14 = team;
                }
                v7 = info;
            }
        }
        ++v12;
    }
    while( v12 < 9 );
    if( RGE_Base_Game::randomGame(rge_base_game) && !RGE_Base_Game::campaignGame(rge_base_game) )
    {
        v20 = 1;
        do
        {
            if( (TCommunications_Handler::GetPlayerHumanity(v3->commands->com_hand, v20) == 4
                 || all_cp == 1
                 || all_cp == 2 && v20 > 1)
                && RGE_Base_Game::playerTeam(rge_base_game, v20 - 1) == 1 )
            {
                v21 = 1;
                do
                {
                    v22 = TCommunications_Handler::GetPlayerHumanity(v3->commands->com_hand, v21);
                    if( v22 == 4 || v22 == 2 )
                    {
                        v23 = RGE_Base_Game::playerID(rge_base_game, v20);
                        v24 = RGE_Base_Game::playerID(rge_base_game, v21);
                        if( v23 != v24 )
                        {
                            v25 = v23;
                            RGE_Player::set_relation(v3->players[v25], v24, 1);
                            RGE_Player::set_allied_victory(v3->players[v25], 1);
                        }
                    }
                    ++v21;
                }
                while( v21 < 9 );
            }
            ++v20;
        }
        while( v20 < 9 );
        v7 = info;
    }
    v26 = 0;
    v3->world_time = 0;
    v3->old_world_time = 0;
    v3->world_time_delta = 0;
    v3->old_time = 0;
    if( RGE_Base_Game::singlePlayerGame(rge_base_game) )
        v3->game_speed = RGE_Base_Game::get_game_speed(rge_base_game);
    else
        LODWORD(v3->game_speed) = 1065353216;
    v3->temp_pause = 0;
    LODWORD(v3->world_time_delta_seconds) = 0;
    v27 = v7->scenario;
    v28 = 0;
    if( v27 )
    {
        v35 = ((int (*)(RGE_Game_World *, char *, RGE_Player_Info *))v3->vfptr->load_scenario)(v3, v27, v7);
    }
    else
    {
        v29 = v3->vfptr;
        if( v7->campaign )
        {
            v35 = (*((int (**)(RGE_Game_World *, RGE_Player_Info *))&v29->scenario_make_map + 1))(v3, v7);
        }
        else
        {
            v35 = v29->new_random_game(v3, v7);
            v28 = 1;
        }
    }
    RGE_Game_World::initializePathingSystem(v3);
    if( v3->player_num > 0 )
    {
        do
        {
            v30 = v3->players[v26];
            if( v30 )
                ((void (*)(void))v30->vfptr->random_start)();
            ++v26;
        }
        while( v26 < v3->player_num );
    }
    if( v35 )
        v3->game_state = 0;
    v31 = debug_rand(aCMsdevWorkAge1, 1458);
    v3->random_seed = v31;
    TDebuggingLog::Log(L, aWorldEnd_of_ne, v31);
    (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(10107, randomString, 256);
    v32 = 1;
    if( v28 == 1 && v3->player_num > 1 )
    {
        do
        {
            v33 = v3->players[v32];
            if( v33 )
                ((void (__stdcall *)(char *, char *, char *, _DWORD, _DWORD))v33->vfptr->loadAIInformation)(
                    randomString,
                    randomString,
                    randomString,
                    0,
                    info->map_type);
            ++v32;
        }
        while( v32 < v3->player_num );
    }
    return v35;
}

char RGE_Game_World::new_scenario(RGE_Player_Info *info, int random_seed_in)
{
    RGE_Game_World *v3; // esi@1
    RGE_Game_WorldVtbl *v4; // ebp@1
    int v5; // eax@1
    short v6; // ax@3
    char *v7; // eax@3
    signed int i; // edi@7
    char random_seed_ina; // [sp+18h] [bp+8h]@4

    v3 = this;
    v4 = this->vfptr;
    world_update_counter = 0;
    ((void (*)(void))v4->del_game_info)();
    v5 = random_seed_in;
    v3->curr_player = 0;
    if( !random_seed_in )
        v5 = TCommunications_Handler::GetRandomSeed(v3->commands->com_hand);
    v3->random_seed = v5;
    debug_srand(aCMsdevWorkAge1, 1493, v5);
    RGE_Map::new_map(v3->map, info->map_width, info->map_height);
    RGE_Map::clear_map(v3->map, info->map_info->base_terrain, 1);
    v6 = info->player_num + 1;
    v3->player_num = v6;
    v3->players = (RGE_Player **)calloc(4u, v6);
    v4->setup_gaia(v3);
    v4->setup_players(v3, info);
    v3->world_time = 0;
    v3->old_world_time = 0;
    v3->world_time_delta = 0;
    v3->old_time = 0;
    LODWORD(v3->game_speed) = 1065353216;
    v3->temp_pause = 0;
    LODWORD(v3->world_time_delta_seconds) = 0;
    v7 = info->scenario;
    if( v7 )
    {
        random_seed_ina = v4->load_scenario(v3, (RGE_Player_Info *)v7);
    }
    else
    {
        v4->setup_player_colors(v3);
        (*(void (**)(RGE_Game_World *, RGE_Game_World *))&v4->gapF0[0])(v3, v3);
        random_seed_ina = 1;
    }
    if( random_seed_ina )
    {
        for( i = 0; i < v3->player_num; RGE_Player::set_map_visible(v3->players[i++]) )
            ;
    }
    return random_seed_ina;
}

char RGE_Game_World::new_random_game(RGE_Player_Info *info)
{
    RGE_Game_World *v2; // esi@1
    RGE_Game_WorldVtbl *v3; // edi@1
    int v4; // eax@1
    int v5; // eax@1
    int v6; // eax@1
    int v7; // eax@1
    short v8; // bp@1
    signed int v9; // ebx@1
    short v10; // di@2
    RGE_Player *v11; // ecx@3
    int v12; // eax@7

    v2 = this;
    world_update_counter = 0;
    v3 = this->vfptr;
    ((void (__stdcall *)(RGE_Player_Info *))this->vfptr->setup_player_colors)(info);
    (*(void (**)(RGE_Game_World *, RGE_Game_World *))&v3->gapF0[0])(v2, v2);
    v4 = debug_rand(aCMsdevWorkAge1, 1554);
    v2->random_seed = v4;
    TDebuggingLog::Log(L, aWorldBefore_ma, v4);
    v5 = v2->player_num - 1;
    LOBYTE(v5) = info->map_type;
    ((void (__stdcall *)(RGE_Game_World *, signed int, signed int, int, int))v2->map->vfptr->map_generate2)(
        v2,
        -1,
        -1,
        v5,
        v2->player_num - 1);
    RGE_Game_World::initializePathingSystem(v2);
    v6 = debug_rand(aCMsdevWorkAge1, 1562);
    v2->random_seed = v6;
    TDebuggingLog::Log(L, aWorldAfter_map, v6);
    v7 = debug_rand(aCMsdevWorkAge1, 1570);
    v2->random_seed = v7;
    TDebuggingLog::Log(L, aWorldAfter_p_2, v7);
    v8 = v2->curr_player;
    v2->curr_player = -1;
    v9 = 3;
    do
    {
        v10 = 0;
        ++world_update_counter;
        if( v2->player_num > 0 )
        {
            do
            {
                v11 = v2->players[v10];
                if( v11 )
                    ((void (*)(void))v11->vfptr->update)();
                ++v10;
            }
            while( v10 < v2->player_num );
        }
        --v9;
    }
    while( v9 );
    v2->curr_player = v8;
    v12 = debug_rand(aCMsdevWorkAge1, 1585);
    v2->random_seed = v12;
    TDebuggingLog::Log(L, aWorldAfter_p_0, v12);
    return 1;
}

void RGE_Game_World::update_sounds(time_t time)
{
    if( this->sound_update_index >= this->sound_num ){
        this->sound_update_index = 0;
    }
    this->sounds[this->sound_update_index]->update(time);
    this->sound_update_index++;
}

void RGE_Game_World::update_sprites(time_t time)
{
    if( this->sprite_update_index >= this->sprite_num ){
        this->sprite_update_index = 0;
    }
    if( this->sprites[this->sprite_update_index] ){
        this->sprites[this->sprite_update_index]->update(time);
    }
    this->sprite_update_index++;
}

char RGE_Game_World::update()
{
    RGE_Game_World *v1; // esi@1
    char v2; // bl@1
    unsigned int v3; // edi@1
    int v4; // ebp@1
    unsigned int v5; // eax@1
    unsigned int v7; // edi@5
    unsigned int v8; // ecx@6
    unsigned int v9; // eax@7
    char v10; // cl@12
    unsigned int v11; // edi@12
    int v12; // eax@17
    RGE_Master_Static_Object **v13; // edx@19
    signed int v14; // ebp@19
    unsigned int *v15; // edi@20
    signed int v16; // edi@26
    unsigned int i; // ebp@26
    RGE_Player *v18; // eax@27
    signed int j; // edi@30
    RGE_Player *v20; // eax@31
    int v21; // ecx@34
    int v22; // eax@34
    signed int v23; // edi@37
    FILE *v24; // ebx@41
    RGE_Person_Info *v25; // eax@42
    int v26; // ecx@43
    int v27; // ebp@43
    signed int v28; // edi@43
    bool v29; // zf@44
    bool v30; // sf@44
    unsigned __int8 v31; // of@44
    signed int k; // edi@49
    RGE_Player *v33; // ecx@50
    RGE_Player *v34; // eax@58
    char fileName[256]; // [sp+18h] [bp-100h]@42

    v1 = this;
    v2 = 0;
    this->availableComputerPlayerUpdateTime = this->maximumComputerPlayerUpdateTime;
    v3 = debug_timeGetTime();
    v4 = TCommunications_Handler::DoCycle(v1->commands->com_hand, v1->world_time);
    v5 = debug_timeGetTime();
    RGE_Base_Game::add_to_timing(rge_base_game, 14, v5 - v3);
    if( !v4 )
    {
        v1->world_time_delta = 0;
        return v1->game_state;
    }
    visible_combats = 0;
    debug_random_on = 1;
    debug_timeGetTime_on = 1;
    if( do_fixed_update )
        v4 = fixed_update_time;
    debug_srand(aCMsdevWorkAge1, 1698, v1->random_seed);
    v7 = debug_timeGetTime();
    RGE_Game_World::update_sounds(v1, v7);
    RGE_Game_World::update_sprites(v1, v7);
    if( v4 == -1 )
    {
        v8 = v1->old_time;
        if( v8 )
        {
            v9 = v7 - v8;
        }
        else
        {
            v2 = 1;
            v9 = 0;
        }
        if( v9 > 0x64 )
            v9 = 100;
    }
    else
    {
        v9 = v4;
    }
    v10 = v1->temp_pause;
    v1->old_time = v7;
    v11 = v1->world_time;
    v1->old_world_time = v11;
    if( v10 )
    {
        if( v4 != -1 )
            v1->world_time = v11 + (unsigned __int64)(signed __int64)((double)v9 * v1->game_speed);
        v1->temp_pause = 0;
    }
    else
    {
        v1->world_time = v11 + (unsigned __int64)(signed __int64)((double)v9 * v1->game_speed);
    }
    v12 = v1->world_time - v1->old_world_time;
    v1->world_time_delta = v12;
    if( v12 || v2 )
    {
        RGE_Command::do_commands(v1->commands);
        RGE_Scenario::update(v1->scenario, v13);
        v14 = 0;
        v1->world_time_delta_seconds = (double)v1->world_time_delta * 0.001;
        ++world_update_counter;
        if( v1->player_num > 0 )
        {
            v15 = v1->player_time_delta;
            do
            {
                if( v1->players[v14] )
                {
                    *v15 += v1->world_time_delta;
                    ((void (*)(void))v1->players[v14]->vfptr->update)();
                    RGE_Tile_List::del_list(&v1->players[v14]->tile_list);
                }
                ++v14;
                ++v15;
            }
            while( v14 < v1->player_num );
        }
        if( MouseSystem )
            TMousePointer::Poll(MouseSystem);
        v16 = 0;
        for( i = debug_rand(aCMsdevWorkAge1, 1762); v16 < v1->player_num; ++v16 )
        {
            v18 = v1->players[v16];
            if( v18 )
                RGE_Object_List::update(v18->doppleganger_objects);
        }
        for( j = 0; j < v1->player_num; ++j )
        {
            v20 = v1->players[j];
            if( v20 )
                RGE_Doppleganger_Creator::perform_doppleganger_checks(v20->doppleganger_creator);
        }
        debug_srand(aCMsdevWorkAge1, 1782, i);
        v1->player_time_delta[v1->player_turn] = 0;
        v21 = v1->player_num;
        v22 = v1->player_turn + 1;
        v1->player_turn = v22;
        if( v22 >= v21 )
            v1->player_turn = 0;
        v1->vfptr->check_game_state(v1);
    }
    v1->random_seed = debug_rand(aCMsdevWorkAge1, 1818);
    debug_random_on = 0;
    debug_timeGetTime_on = 0;
    TCommunications_Handler::LastWorldRandom(v1->commands->com_hand, v1->random_seed);
    v23 = 1;
    if( logStatusOn == 1 )
    {
        if( v1->game_state == 1 )
        {
LABEL_55:
            if( logStatusOn == 1 && logStatusFile )
            {
                fprintf(logStatusFile, aGameOver);
                if( v1->player_num > 1 )
                {
                    do
                    {
                        v34 = v1->players[v23];
                        if( v34 )
                        {
                            if( v34->game_status == 1 )
                                fprintf(logStatusFile, aPlayerDWon_, v23);
                            else
                                fprintf(logStatusFile, aPlayerDLost_, v23);
                        }
                        ++v23;
                    }
                    while( v23 < v1->player_num );
                }
                fclose(logStatusFile);
                logStatusFile = 0;
            }
            return v1->game_state;
        }
        if( v1->world_time - lastStatusLogTime > 0x7530 || !lastStatusLogTime )
        {
            v24 = logStatusFile;
            if( !logStatusFile )
            {
                v25 = RGE_Game_Info::get_current_player_name(rge_base_game->player_game_info);
                sprintf(fileName, aAilogS_log, v25);
                v24 = fopen(fileName, aA_0);
                logStatusFile = v24;
                if( !v24 )
                    return v1->game_state;
            }
            v26 = 0;
            v27 = 0;
            v28 = v1->world_time / 0x3E8;
            if( v28 > 59 )
            {
                v26 = v28 / 60;
                v31 = __OFSUB__(v28 / 60, 59);
                v29 = v28 / 60 == 59;
                v30 = v28 / 60 - 59 < 0;
                v28 %= 60;
                if( !((unsigned __int8)(v30 ^ v31) | v29) )
                {
                    v27 = v26 / 60;
                    v26 %= 60;
                }
            }
            if( lastStatusLogTime )
                fprintf(v24, aStatusLogAtGam, v27, v26, v28);
            else
                v1->vfptr->logStatus(v1, v24, 1);
            for( k = 1; k < v1->player_num; ++k )
            {
                v33 = v1->players[k];
                if( v33 )
                    ((void (__stdcall *)(FILE *, _DWORD))v33->vfptr->logStatus)(logStatusFile, lastStatusLogTime == 0);
            }
            v23 = 1;
            lastStatusLogTime = v1->world_time + 1;
        }
    }
    if( v1->game_state == 1 )
        goto LABEL_55;
    return v1->game_state;
}

bool RGE_Game_World::is_player_turn(int player_id)
{
    return this->player_turn == player_id;
}

time_t RGE_Game_World::get_accum_time_delta(int player_id)
{
    return this->player_time_delta[player_id];
}

char RGE_Game_World::get_game_state()
{
    return this->game_state;
}

char RGE_Game_World::check_game_state()
{
    RGE_Game_World *v1; // esi@1
    int v2; // edi@1
    signed int v3; // ebx@1
    int v4; // ebp@1
    int v5; // eax@2
    int v6; // eax@3
    RGE_Player **v7; // eax@9
    signed int v8; // edi@16
    signed int v9; // edi@23
    int v10; // eax@27
    int games_won; // [sp+10h] [bp-Ch]@1
    int games_lost; // [sp+14h] [bp-8h]@1
    int games_on; // [sp+18h] [bp-4h]@1

    v1 = this;
    v2 = 1;
    v3 = 0;
    v4 = 0;
    games_on = 0;
    games_won = 0;
    for( games_lost = 0; v2 < v1->player_num; ++v2 )
    {
        v5 = (unsigned __int8)RGE_Player::check_victory(v1->players[v2]);
        if( v5 )
        {
            v6 = v5 - 1;
            if( v6 )
            {
                if( v6 == 1 )
                    ++games_lost;
            }
            else
            {
                ++games_won;
            }
        }
        else
        {
            ++games_on;
            if( v4 > 0 && v3 )
            {
                v7 = v1->players;
                if( !v7[v2]->allied_victory || RGE_Player::relation(v7[v4], v2) || RGE_Player::relation(v1->players[v2], v4) )
                    v3 = -1;
            }
            else
            {
                v4 = v2;
                v3 = 1;
            }
        }
    }
    if( games_won <= 0 )
    {
        if( RGE_Scenario::Get_conquest_victory(v1->scenario) && (games_lost > 0 && v3 > 0 || !games_on) )
        {
            v9 = 1;
            v1->game_state = 1;
            while( v9 < v1->player_num )
                RGE_Player::victory_if_game_on(v1->players[v9++]);
            v1->game_end_condition = 1;
        }
    }
    else
    {
        v8 = 1;
        v1->game_state = 1;
        while( v8 < v1->player_num )
            RGE_Player::loss_if_game_on(v1->players[v8++]);
    }
    if( v1->game_state == 1 )
    {
        v10 = v1->campaign;
        if( v10 >= 0 )
        {
            if( RGE_Base_Game::set_campaign_info(rge_base_game, v10, v1->campaign_player, v1->campaign_scenario) )
            {
                if( v1->players[v1->curr_player]->game_status == 1 )
                {
                    RGE_Base_Game::set_campaign_win(rge_base_game);
                    return v1->game_state;
                }
            }
            else
            {
                v1->campaign = -1;
            }
        }
    }
    return v1->game_state;
}

void RGE_Game_World::save(int outfile)
{
    save_game_version = RGE_WORLD_SAVE_VERSION;

    rge_write(outfile, &this->world_time, 4);
    rge_write(outfile, &this->old_world_time, 4);
    rge_write(outfile, &this->world_time_delta, 4);
    rge_write(outfile, &this->world_time_delta_seconds, 4);
    rge_write(outfile, &this->timer, 4);
    rge_write(outfile, &this->game_speed, 4);
    rge_write(outfile, &this->temp_pause, 1);
    rge_write(outfile, &this->next_object_id, 4);
    rge_write(outfile, &this->next_reusable_object_id, 4);
    rge_write(outfile, &this->random_seed, 4);
    rge_write(outfile, &this->curr_player, 2);
    rge_write(outfile, &this->player_num, 2);
    rge_write(outfile, &this->game_state, 1);
    rge_write(outfile, &this->campaign, 4);
    rge_write(outfile, &this->campaign_player, 4);
    rge_write(outfile, &this->campaign_scenario, 4);
    rge_write(outfile, &this->player_turn, 4);

    for( int p_id = 0; p_id < RGE_PLAYERS_COUNT; p_id++ ){
        rge_write(outfile, this->player_time_delta[p_id], 4);
    }

    this->map->save_map(outfile);

    for( int i = 0; i < this->player_num; i++ ){
        this->players[i]->save(outfile);
        this->players[i]->save2(outfile);
    }

    for( int j = 0; j < this->player_num; j++ ){
        this->players[j]->save_info(outfile);
    }

    this->scenario->save)(outfile);

#if RGE_WORLD_DIFFICULTY_LEVEL_EXISTS
    int world_difficulty = this->difficultyLevelValue;
    if( world_difficulty == -1 ){
        world_difficulty = rge_base_game->difficulty();
    }
    rge_write(outfile, world_difficulty, 4);
#endif
}

char RGE_Game_World::save_game(char *name)
{
    RGE_Game_World *v2; // edi@1
    int v3; // eax@1
    int v4; // esi@1
    char result; // al@3
    char tempname[300]; // [sp+8h] [bp-12Ch]@1

    LODWORD(save_game_version) = 1088904233;
    v2 = this;
    sprintf(tempname, aSS, rge_base_game->prog_info->save_dir, name);
    v3 = rge_open(tempname, 33545, 384);
    v4 = v3;
    if( v3 == -1 )
    {
        result = 0;
    }
    else
    {
        rge_write_error = 0;
        rge_write(v3, aVer8_6, 8);
        rge_write(v4, &save_game_version, 4);
        v2->vfptr->save(v2, v4);
        rge_close(v4);
        if( rge_write_error )
        {
            _unlink(tempname);
            result = 0;
        }
        else
        {
            result = 1;
        }
    }
    return result;
}

void RGE_Game_World::base_save(int outfile)
{
    /* write header version: */
    rge_write(outfile, "VER 3.7", 8);

    /* write terrain-tables: */
    rge_write(outfile, &this->terrain_num, 2);
    rge_write(outfile, &this->terrain_size, 2);
    if( this->terrain_num > 0 &&
        this->terrain_size > 0 ){
        rge_write(outfile, this->terrains, 4 * this->terrain_num);
        for( int i = 0; i < this->terrain_num; i++ ){
            if( this->terrains[i] ){
                rge_write(outfile, this->terrains[i], 4 * this->terrain_size);
            }
        }
    }

    /* write color-tables: */
    rge_write(outfile, &this->color_table_num, 2);
    for( int color_table_id = 0; color_table_id < this->color_table_num; color_table_id++ ){
        this->color_tables[color_table_id]->save(outfile);
    }

    /* write sounds: */
    rge_write(outfile, &this->sound_num, 2);
    for( int sound_id = 0; sound_id < this->sound_num; sound_id++ ){
        this->sounds[sound_id]->save(outfile);
    }

    /* write sprites: */
    rge_write(outfile, &this->sprite_num, 2);
    rge_write(outfile, this->sprites, 4 * this->sprite_num);
    for( int sprite_id = 0; sprite_id < this->sprite_num; sprite_id++ ){
        if( this->sprites[sprite_id] ){
            this->sprites[sprite_id]->save(outfile);
        }
    }

    /* write map: */
    this->map->save(outfile);

    /* write effects: */
    this->effects->save(outfile);

    /* write master-players: */
    rge_write(outfile, &this->master_player_num, 2);
    for( int m_player_id = 0; m_player_id < this->master_player_num; m_player_id++ ){
        this->master_players[m_player_id]->save(outfile);
    }
}

void RGE_Game_World::base_save(char *name)
{
    RGE_Game_World *v2; // edi@1
    int v3; // eax@1
    int v4; // esi@1

    v2 = this;
    v3 = rge_open(name, 33545, 384);
    v4 = v3;
    if( v3 != -1 )
    {
        v2->vfptr->base_save(v2, v3);
        rge_close(v4);
    }
}

//----- (00543A00) --------------------------------------------------------
char RGE_Game_World::save_scenario(char *filename)
{
    RGE_Game_World *v2; // ebp@1
    int v3; // esi@1
    char v4; // cl@1
    char *v5; // eax@1
    RGE_Base_Game *v6; // edx@3
    int v7; // esi@3
    signed int i; // edi@7
    int v9; // edi@9
    bool v10; // zf@9
    bool v11; // sf@9
    RGE_Player **v12; // ecx@12
    RGE_Player *v13; // edx@12
    int v14; // ecx@12
    RGE_Object_Node *j; // eax@12
    int k; // eax@16
    RGE_Object_Node *l; // edi@20
    RGE_Static_Object *v18; // ecx@22
    char v19; // al@22
    RGE_Object_Node *m; // edi@28
    RGE_Static_Object *v21; // ecx@30
    char v22; // al@30
    int v23; // ecx@36
    signed int n; // edi@37
    char result; // al@40
    float obj_angle; // [sp+Ch] [bp-268h]@24
    int count; // [sp+10h] [bp-264h]@12
    int index; // [sp+14h] [bp-260h]@9
    int scenario_player_num; // [sp+18h] [bp-25Ch]@1
    char scenario_name[300]; // [sp+1Ch] [bp-258h]@3
    char kill_name[300]; // [sp+148h] [bp-12Ch]@2

    v2 = this;
    scenario_player_num = this->player_num;
    v3 = 0;
    v4 = *filename;
    v5 = filename;
    do
    {
        v5[kill_name - filename] = v4;
        v4 = v5[1];
        ++v3;
        ++v5;
    }
    while( v4 != 46 );
    v6 = rge_base_game;
    kill_name[v3] = 0;
    sprintf(scenario_name, aSS_scn, v6->prog_info->scenario_dir, kill_name);
    _unlink(scenario_name);
    sprintf(scenario_name, aSS, rge_base_game->prog_info->scenario_dir, filename);
    v7 = rge_open(scenario_name, 33537, 384);
    if( v7 == -1 )
    {
        result = 0;
    }
    else
    {
        rge_write_error = 0;
        if( RGE_Base_Game::check_prog_argument(rge_base_game, aTrial) == 1 )
            rge_write_uncompressed(v7, a1_10, 4);
        else
            rge_write_uncompressed(v7, a1_11, 4);
        RGE_Base_Game::write_scenario_header(rge_base_game, v7);
        rge_write(v7, &v2->next_object_id, 4);
        ((void (__stdcall *)(int))v2->scenario->vfptr->save)(v7);
        RGE_Map::scenario_save(v2->map, v7);
        rge_write(v7, &scenario_player_num, 4);
        for( i = 1; i < v2->player_num; ((void (__stdcall *)(int))v2->players[i++]->vfptr->scenario_save)(v7) )
            ;
        v9 = 0;
        v10 = v2->player_num == 0;
        v11 = v2->player_num < 0;
        index = 0;
        if( !v11 && !v10 )
        {
            while( 1 )
            {
                v12 = v2->players;
                count = 0;
                v13 = v12[v9];
                v14 = (int)&v12[v9];
                for( j = v13->objects->list; j; j = j->next )
                {
                    if( j->node->master_obj->master_type != 25 )
                        ++count;
                }
                for( k = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)v14 + 44) + 4); k; k = *(_DWORD *)(k + 4) )
                {
                    if( *(_BYTE *)(*(_DWORD *)(*(_DWORD *)k + 8) + 4) != 25 )
                        ++count;
                }
                rge_write(v7, &count, 4);
                for( l = v2->players[v9]->objects->list; l; l = l->next )
                {
                    if( l->node->master_obj->master_type != 25 )
                    {
                        rge_write(v7, &l->node->world_x, 4);
                        rge_write(v7, &l->node->world_y, 4);
                        rge_write(v7, &l->node->world_z, 4);
                        rge_write(v7, &l->node->id, 4);
                        rge_write(v7, &l->node->master_obj->id, 2);
                        rge_write(v7, &l->node->object_state, 1);
                        v18 = l->node;
                        v19 = l->node->master_obj->master_type;
                        if( (unsigned __int8)v19 <= 0x1Eu || (unsigned __int8)v19 >= 0x5Au )
                        {
                            LODWORD(obj_angle) = v18->facet;
                            obj_angle = (double)SLODWORD(obj_angle);
                        }
                        else
                        {
                            obj_angle = *(float *)&v18[1].old_sprite;
                        }
                        rge_write(v7, &obj_angle, 4);
                    }
                }
                for( m = v2->players[index]->sleeping_objects->list; m; m = m->next )
                {
                    if( m->node->master_obj->master_type != 25 )
                    {
                        rge_write(v7, &m->node->world_x, 4);
                        rge_write(v7, &m->node->world_y, 4);
                        rge_write(v7, &m->node->world_z, 4);
                        rge_write(v7, &m->node->id, 4);
                        rge_write(v7, &m->node->master_obj->id, 2);
                        rge_write(v7, &m->node->object_state, 1);
                        v21 = m->node;
                        v22 = m->node->master_obj->master_type;
                        if( (unsigned __int8)v22 <= 0x1Eu || (unsigned __int8)v22 >= 0x5Au )
                        {
                            LODWORD(obj_angle) = v21->facet;
                            obj_angle = (double)SLODWORD(obj_angle);
                        }
                        else
                        {
                            obj_angle = *(float *)&v21[1].old_sprite;
                        }
                        rge_write(v7, &obj_angle, 4);
                    }
                }
                v23 = v2->player_num;
                if( ++index >= v23 )
                    break;
                v9 = index;
            }
        }
        rge_write(v7, &scenario_player_num, 4);
        for( n = 1; n < v2->player_num; this->players[n++]->scenario_postsave(outfile) )
            ;
        rge_close(v7);
        if( rge_write_error )
        {
            _unlink(scenario_name);
            result = 0;
        }
        else
        {
            result = 1;
        }
    }
    return result;
}

char RGE_Game_World::load_scenario(char *scenario, RGE_Player_Info *info)
{
    RGE_Game_World *v3; // edi@1
    int v4; // eax@2
    int v5; // ebx@2
    RGE_Game_WorldVtbl *v6; // esi@4
    void *v8; // esi@8
    RGE_Game_WorldVtbl *v9; // esi@10
    RGE_Game_WorldVtbl *v10; // esi@12
    RGE_Game_WorldVtbl *v11; // esi@14
    RGE_Game_WorldVtbl *v12; // esi@16
    RGE_Game_WorldVtbl *v13; // esi@18
    RGE_Game_WorldVtbl *v14; // esi@20
    RGE_Game_WorldVtbl *v15; // esi@24
    int header_size; // [sp+10h] [bp-134h]@7
    int version; // [sp+14h] [bp-130h]@3
    char scenario_name[300]; // [sp+18h] [bp-12Ch]@1

    world_update_counter = 0;
    v3 = this;
    sprintf(scenario_name, aSS, rge_base_game->prog_info->scenario_dir, scenario);
    if( scenario )
    {
        v4 = rge_open(scenario_name, 0x8000);
        v5 = v4;
        if( v4 != -1 )
        {
            rge_read_uncompressed(v4, &version, 4);
            if( version == *(_DWORD *)a1_01 )
            {
                v6 = v3->vfptr;
                v3->vfptr->load_scenario1(v3, v5, info);
                v6->setup_player_colors(v3, info);
                return 1;
            }
            if( version == *(_DWORD *)a1_02 )
                goto LABEL_10;
            if( version == *(_DWORD *)a1_03 )
            {
                rge_read_uncompressed(v5, &header_size, 4);
                if( header_size <= 0 )
                {
LABEL_10:
                    v9 = v3->vfptr;
                    v3->vfptr->load_scenario2(v3, v5, info);
                    v9->setup_player_colors(v3, info);
                    return 1;
                }
                v8 = malloc(header_size);
                if( v8 )
                {
                    rge_read_uncompressed(v5, v8, header_size);
                    free(v8);
                    goto LABEL_10;
                }
            }
            else
            {
                if( version == *(_DWORD *)a1_04 )
                {
                    v10 = v3->vfptr;
                    v3->vfptr->load_scenario3(v3, v5, info);
                    v10->setup_player_colors(v3, info);
                    return 1;
                }
                if( version == *(_DWORD *)a1_05 )
                {
                    v11 = v3->vfptr;
                    v3->vfptr->load_scenario4(v3, v5, info);
                    v11->setup_player_colors(v3, info);
                    return 1;
                }
                if( version == *(_DWORD *)a1_06 )
                {
                    v12 = v3->vfptr;
                    v3->vfptr->load_scenario5(v3, v5, info);
                    v12->setup_player_colors(v3, info);
                    return 1;
                }
                if( version == *(_DWORD *)a1_07 )
                {
                    v13 = v3->vfptr;
                    v3->vfptr->load_scenario6(v3, v5, info);
                    v13->setup_player_colors(v3, info);
                    return 1;
                }
                if( version == *(_DWORD *)a1_08 )
                {
                    v14 = v3->vfptr;
                    v3->vfptr->load_scenario7(v3, v5, info);
                    v14->setup_player_colors(v3, info);
                    return 1;
                }
                if( version == *(_DWORD *)a1_09 || version == *(_DWORD *)a1_11 || version == *(_DWORD *)a1_10 )
                {
                    v15 = v3->vfptr;
                    v3->vfptr->load_scenario8(v3, v5, info);
                    v15->setup_player_colors(v3, info);
                    return 1;
                }
            }
            rge_close(v5);
        }
    }
    return 0;
}

char RGE_Game_World::load_scenario(RGE_Player_Info *info)
{
    RGE_Game_World *v2; // esi@1
    int v3; // ebx@1
    RGE_Player_Info *v4; // ebp@3
    RGE_Game_WorldVtbl *v5; // edi@3
    void *v6; // eax@7
    void *v7; // edi@7
    int header_size; // [sp+10h] [bp-8h]@6
    int version; // [sp+14h] [bp-4h]@2

    world_update_counter = 0;
    v2 = this;
    v3 = RGE_Base_Game::campaign_open_scenario(rge_base_game);
    if( v3 == -1 )
        return 0;
    rge_read_uncompressed(v3, &version, 4);
    if( version == *(_DWORD *)a1_01 )
    {
        v4 = info;
        v5 = v2->vfptr;
        v2->vfptr->load_scenario1(v2, v3, info);
LABEL_24:
        v5->setup_player_colors(v2, v4);
        RGE_Base_Game::get_campaign_info(rge_base_game, &v2->campaign, &v2->campaign_player, &v2->campaign_scenario);
        return 1;
    }
    if( version == *(_DWORD *)a1_02 )
        goto LABEL_9;
    if( version == *(_DWORD *)a1_03 )
    {
        rge_read_uncompressed(v3, &header_size, 4);
        if( header_size > 0 )
        {
            v6 = malloc(header_size);
            v7 = v6;
            if( v6 )
            {
                rge_read_uncompressed(v3, v6, header_size);
                free(v7);
                goto LABEL_9;
            }
            goto LABEL_25;
        }
LABEL_9:
        v4 = info;
        v5 = v2->vfptr;
        v2->vfptr->load_scenario2(v2, v3, info);
        goto LABEL_24;
    }
    if( version == *(_DWORD *)a1_04 )
    {
        v4 = info;
        v5 = v2->vfptr;
        v2->vfptr->load_scenario3(v2, v3, info);
        goto LABEL_24;
    }
    if( version == *(_DWORD *)a1_05 )
    {
        v4 = info;
        v5 = v2->vfptr;
        v2->vfptr->load_scenario4(v2, v3, info);
        goto LABEL_24;
    }
    if( version == *(_DWORD *)a1_06 )
    {
        v4 = info;
        v5 = v2->vfptr;
        v2->vfptr->load_scenario5(v2, v3, info);
        goto LABEL_24;
    }
    if( version == *(_DWORD *)a1_07 )
    {
        v4 = info;
        v5 = v2->vfptr;
        v2->vfptr->load_scenario6(v2, v3, info);
        goto LABEL_24;
    }
    if( version == *(_DWORD *)a1_08 )
    {
        v4 = info;
        v5 = v2->vfptr;
        v2->vfptr->load_scenario7(v2, v3, info);
        goto LABEL_24;
    }
    if( version == *(_DWORD *)a1_09 || version == *(_DWORD *)a1_11 || version == *(_DWORD *)a1_10 )
    {
        v4 = info;
        v5 = v2->vfptr;
        v2->vfptr->load_scenario8(v2, v3, info);
        goto LABEL_24;
    }
LABEL_25:
    rge_close(v3);
    return 0;
}

void RGE_Game_World::scenario_make_player(
    short index,
    char player_type,
    char info_type,
    char master_player_id,
    char *name)
{
    switch( info_type ){

    case RGE_PLAYER_TYPE:
        this->players[index] = new RGE_Player(
            this,
            this->master_players[master_player_id],
            index,
            name,
            master_player_id,
            true);
        break;
    }
}

void RGE_Game_World::scenario_make_map(int infile)
{
    this->map->scenario_load(infile, 0);
}

void RGE_Game_World::load_scenario1(int infile, RGE_Player_Info *info)
{
    int v4; // ebp@1
    RGE_Game_World *v5; // esi@1
    RGE_Game_WorldVtbl *v6; // edi@1
    signed int v7; // edx@1
    int v8; // eax@3
    char *v9; // ecx@4
    int v10; // edi@5
    int v11; // edi@6
    int v12; // eax@8
    int i; // edi@8
    signed int v14; // edi@10
    int j; // ebx@11
    int v16; // ecx@13
    RGE_Player **v17; // eax@14
    int v18; // edx@15
    int v19; // edi@18
    int *v20; // ebx@19
    RGE_Player *v21; // ecx@22
    int v22; // edi@25
    bool v23; // zf@25
    bool v24; // sf@25
    unsigned __int8 v25; // of@25
    RGE_Player **v26; // eax@27
    int v27; // ecx@28
    int *v28; // ebp@28
    int v29; // edi@28
    RGE_PlayerVtbl *v30; // ebx@28
    int v31; // ST14_4@28
    char *v32; // ST10_4@28
    char *v33; // ST0C_4@28
    char *v34; // eax@28
    int v35; // edx@29
    char data; // [sp+2Fh] [bp-5Dh]@9
    int scenario_player_num; // [sp+30h] [bp-5Ch]@8
    int count; // [sp+34h] [bp-58h]@11
    int id; // [sp+38h] [bp-54h]@12
    float obj_angle; // [sp+3Ch] [bp-50h]@12
    int obj_state; // [sp+40h] [bp-4Ch]@12
    int master_id; // [sp+44h] [bp-48h]@12
    float world_z; // [sp+48h] [bp-44h]@12
    float world_y; // [sp+4Ch] [bp-40h]@12
    float world_x; // [sp+50h] [bp-3Ch]@12
    int obj_id; // [sp+54h] [bp-38h]@1
    char rem[13]; // [sp+58h] [bp-34h]@18
    int player_id_hash[9]; // [sp+68h] [bp-24h]@2

    v4 = infile;
    v5 = this;
    rge_read(infile, a2, infile, &obj_id, 4);
    v6 = v5->vfptr;
    v5->vfptr->scenario_init(v5, v4, v5);
    v6->scenario_make_map(v5, v4);
    v7 = v5->player_num;
    if( v7 > 0 )
    {
        do
            memset(player_id_hash, 0xFFu, sizeof(player_id_hash));
        while( v7 > 10 );
    }
    v8 = 0;
    if( v7 > 0 )
    {
        v9 = (char *)info->player_id_hash;
        do
        {
            v10 = *(_DWORD *)v9;
            v9 += 4;
            player_id_hash[v10] = v8++;
        }
        while( v8 < v7 );
    }
    v11 = 0;
    if( v7 > 0 )
    {
        do
            RGE_Player::remake_visible_map(v5->players[v11++]);
        while( v11 < v5->player_num );
    }
    rge_read(v4, v11, v4, &scenario_player_num, 4);
    v12 = scenario_player_num;
    for( i = 0; i < scenario_player_num; ++i )
    {
        rge_read(v4, i, v4, &infile, 1);
        rge_read(v4, i, v4, &data, 1);
        v12 = scenario_player_num;
    }
    v14 = 0;
    if( v12 > 0 )
    {
        do
        {
            rge_read(v4, v14, v4, &count, 4);
            for( j = 0; j < count; ++j )
            {
                rge_read(v4, v14, v4, &world_x, 4);
                rge_read(v4, v14, v4, &world_y, 4);
                rge_read(v4, v14, v4, &world_z, 4);
                rge_read(v4, v14, v4, &id, 4);
                rge_read(v4, v14, v4, &master_id, 2);
                rge_read(v4, v14, v4, &obj_state, 1);
                rge_read(v4, v14, v4, &obj_angle, 4);
                if( v14 < v5->player_num )
                {
                    v16 = player_id_hash[v14];
                    if( v16 >= 0 )
                    {
                        v17 = v5->players;
                        if( v17[v14] )
                        {
                            v18 = id;
                            v5->scenario_object_flag = 1;
                            v5->scenario_object_id = v18;
                            ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, int, int, _DWORD))v17[v16]->vfptr->make_scenario_obj)(
                                LODWORD(world_x),
                                LODWORD(world_y),
                                LODWORD(world_z),
                                master_id,
                                obj_state,
                                LODWORD(obj_angle));
                            v5->scenario_object_flag = 0;
                        }
                    }
                }
            }
            ++v14;
        }
        while( v14 < scenario_player_num );
    }
    v5->next_object_id = obj_id;
    rge_read(v4, v14, v4, rem, 13);
    v19 = 1;
    if( scenario_player_num > 1 )
    {
        v20 = &player_id_hash[1];
        do
        {
            if( v19 >= v5->player_num || *v20 <= -1 || (v21 = v5->players[*v20]) == 0 )
                v21 = *v5->players;
            ((void (__stdcall *)(int, int *, signed int))v21->vfptr->scenario_load)(v4, player_id_hash, 1065353216);
            ++v19;
            ++v20;
        }
        while( v19 < scenario_player_num );
    }
    rge_close(v4);
    v22 = 1;
    v25 = __OFSUB__(v5->player_num, 1);
    v23 = v5->player_num == 1;
    v24 = (signed short)(v5->player_num - 1) < 0;
    info = (RGE_Player_Info *)1;
    if( !((unsigned __int8)(v24 ^ v25) | v23) )
    {
        do
        {
            if( v22 >= scenario_player_num )
                break;
            v26 = v5->players;
            if( v26[v22] )
            {
                v27 = player_id_hash[v22];
                v28 = &player_id_hash[v22];
                v29 = v22 - 1;
                v30 = v26[v27]->vfptr;
                v31 = RGE_Scenario::GetPlayerPosture(v5->scenario, v29);
                v32 = RGE_Scenario::Get_player_AI(v5->scenario, v29, 1);
                v33 = RGE_Scenario::Get_CityPlan(v5->scenario, v29, 1);
                v34 = RGE_Scenario::Get_BuildList(v5->scenario, v29, 1);
                v30->loadAIInformation(v5->players[*v28], v34, v33, v32, v31, -1);
                v22 = (int)info;
            }
            v35 = v5->player_num;
            info = (RGE_Player_Info *)++v22;
        }
        while( v22 < v35 );
    }
}

void RGE_Game_World::load_scenario2(int infile, RGE_Player_Info *info)
{
    int v4; // esi@1
    RGE_Game_World *v5; // ebp@1
    RGE_Game_WorldVtbl *v6; // edi@1
    signed int v7; // edx@1
    int v8; // eax@3
    char *v9; // ecx@4
    int v10; // edi@5
    int v11; // edi@6
    int v12; // eax@8
    int *v13; // edi@8
    int i; // ebx@12
    int v15; // eax@14
    int v16; // edx@15
    int v17; // edi@18
    int *v18; // ebx@19
    RGE_Player *v19; // ecx@22
    int j; // edi@25
    RGE_Player **v21; // ecx@27
    int v22; // eax@28
    RGE_PlayerVtbl *v23; // ebx@29
    int v24; // ST14_4@29
    char *v25; // ST10_4@29
    char *v26; // ST0C_4@29
    char *v27; // eax@29
    char data; // [sp+2Fh] [bp-5Dh]@9
    int scenario_player_num; // [sp+30h] [bp-5Ch]@8
    int count; // [sp+34h] [bp-58h]@12
    int id; // [sp+38h] [bp-54h]@13
    float obj_angle; // [sp+3Ch] [bp-50h]@13
    int obj_state; // [sp+40h] [bp-4Ch]@13
    int master_id; // [sp+44h] [bp-48h]@13
    float world_z; // [sp+48h] [bp-44h]@13
    float world_y; // [sp+4Ch] [bp-40h]@13
    float world_x; // [sp+50h] [bp-3Ch]@13
    int obj_id; // [sp+54h] [bp-38h]@1
    char rem[13]; // [sp+58h] [bp-34h]@18
    int player_id_hash[9]; // [sp+68h] [bp-24h]@2

    v4 = infile;
    v5 = this;
    world_update_counter = 0;
    rge_read((int)this, a2, infile, &obj_id, 4);
    v6 = v5->vfptr;
    v5->vfptr->scenario_init(v5, v4, v5);
    v6->scenario_make_map(v5, v4);
    v7 = v5->player_num;
    if( v7 > 0 )
    {
        do
            memset(player_id_hash, 0xFFu, sizeof(player_id_hash));
        while( v7 > 10 );
    }
    v8 = 0;
    if( v7 > 0 )
    {
        v9 = (char *)info->player_id_hash;
        do
        {
            v10 = *(_DWORD *)v9;
            v9 += 4;
            player_id_hash[v10] = v8++;
        }
        while( v8 < v7 );
    }
    v11 = 0;
    if( v7 > 0 )
    {
        do
            RGE_Player::remake_visible_map(v5->players[v11++]);
        while( v11 < v5->player_num );
    }
    rge_read((int)v5, v11, v4, &scenario_player_num, 4);
    v12 = scenario_player_num;
    v13 = 0;
    if( scenario_player_num > 0 )
    {
        do
        {
            rge_read((int)v5, (int)v13, v4, &infile, 1);
            rge_read((int)v5, (int)v13, v4, &data, 1);
            v12 = scenario_player_num;
            v13 = (int *)((char *)v13 + 1);
        }
        while( (signed int)v13 < scenario_player_num );
    }
    info = 0;
    if( v12 > 0 )
    {
        v13 = player_id_hash;
        do
        {
            rge_read((int)v5, (int)v13, v4, &count, 4);
            for( i = 0; i < count; ++i )
            {
                rge_read((int)v5, (int)v13, v4, &world_x, 4);
                rge_read((int)v5, (int)v13, v4, &world_y, 4);
                rge_read((int)v5, (int)v13, v4, &world_z, 4);
                rge_read((int)v5, (int)v13, v4, &id, 4);
                rge_read((int)v5, (int)v13, v4, &master_id, 2);
                rge_read((int)v5, (int)v13, v4, &obj_state, 1);
                rge_read((int)v5, (int)v13, v4, &obj_angle, 4);
                if( *v13 >= 0 )
                {
                    v15 = (int)&v5->players[*v13];
                    if( *(_DWORD *)v15 )
                    {
                        v16 = id;
                        v5->scenario_object_flag = 1;
                        v5->scenario_object_id = v16;
                        (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int, _DWORD))(**(_DWORD **)v15 + 96))(
                            LODWORD(world_x),
                            LODWORD(world_y),
                            LODWORD(world_z),
                            master_id,
                            obj_state,
                            LODWORD(obj_angle));
                        v5->scenario_object_flag = 0;
                    }
                }
            }
            ++v13;
            info = (RGE_Player_Info *)((char *)info + 1);
        }
        while( (signed int)info < scenario_player_num );
    }
    v5->next_object_id = obj_id;
    rge_read((int)v5, (int)v13, v4, rem, 13);
    v17 = 1;
    if( scenario_player_num > 1 )
    {
        v18 = &player_id_hash[1];
        do
        {
            if( v17 >= v5->player_num || *v18 <= -1 || (v19 = v5->players[*v18]) == 0 )
                v19 = *v5->players;
            ((void (__stdcall *)(int, int *, signed int))v19->vfptr->scenario_load)(v4, player_id_hash, 1065604874);
            ++v17;
            ++v18;
        }
        while( v17 < scenario_player_num );
    }
    rge_close(v4);
    for( j = 1; j < v5->player_num; ++j )
    {
        if( j >= scenario_player_num )
            break;
        v21 = v5->players;
        if( v21[j] )
        {
            v22 = player_id_hash[j];
            if( v22 > -1 )
            {
                v23 = v21[v22]->vfptr;
                v24 = RGE_Scenario::GetPlayerPosture(v5->scenario, j - 1);
                v25 = RGE_Scenario::Get_player_AI(v5->scenario, j - 1, 1);
                v26 = RGE_Scenario::Get_CityPlan(v5->scenario, j - 1, 1);
                v27 = RGE_Scenario::Get_BuildList(v5->scenario, j - 1, 1);
                v23->loadAIInformation(v5->players[player_id_hash[j]], v27, v26, v25, v24, -1);
            }
        }
    }
}

void RGE_Game_World::load_scenario3(int infile, RGE_Player_Info *info)
{
    int v4; // esi@1
    RGE_Game_World *v5; // ebp@1
    void *v6; // eax@2
    RGE_Game_WorldVtbl *v7; // edi@5
    signed int v8; // edx@5
    int v9; // eax@7
    char *v10; // ecx@8
    int v11; // edi@9
    int v12; // edi@10
    int v13; // eax@12
    int *v14; // edi@12
    int i; // ebx@16
    int v16; // eax@18
    int v17; // edx@19
    int v18; // edi@22
    int *v19; // ebx@23
    RGE_Player *v20; // ecx@26
    int j; // edi@29
    RGE_Player **v22; // ecx@31
    int v23; // eax@32
    RGE_PlayerVtbl *v24; // ebx@33
    int v25; // ST14_4@33
    char *v26; // ST10_4@33
    char *v27; // ST0C_4@33
    char *v28; // eax@33
    char data; // [sp+2Fh] [bp-61h]@13
    int scenario_player_num; // [sp+30h] [bp-60h]@12
    int header_size; // [sp+34h] [bp-5Ch]@1
    int count; // [sp+38h] [bp-58h]@16
    int id; // [sp+3Ch] [bp-54h]@17
    float obj_angle; // [sp+40h] [bp-50h]@17
    int obj_state; // [sp+44h] [bp-4Ch]@17
    int master_id; // [sp+48h] [bp-48h]@17
    float world_z; // [sp+4Ch] [bp-44h]@17
    float world_y; // [sp+50h] [bp-40h]@17
    float world_x; // [sp+54h] [bp-3Ch]@17
    int obj_id; // [sp+58h] [bp-38h]@5
    char rem[13]; // [sp+5Ch] [bp-34h]@22
    int player_id_hash[9]; // [sp+6Ch] [bp-24h]@6

    v4 = infile;
    v5 = this;
    world_update_counter = 0;
    rge_read_uncompressed(infile, &header_size, 4);
    if( header_size > 0 )
    {
        v6 = malloc(header_size);
        a2 = v6;
        if( !v6 )
        {
            rge_close(v4);
            return;
        }
        rge_read_uncompressed(v4, v6, header_size);
        free(a2);
    }
    rge_read((int)v5, (int)a2, v4, &obj_id, 4);
    v7 = v5->vfptr;
    v5->vfptr->scenario_init(v5, v4, v5);
    v7->scenario_make_map(v5, v4);
    v8 = v5->player_num;
    if( v8 > 0 )
    {
        do
            memset(player_id_hash, 0xFFu, sizeof(player_id_hash));
        while( v8 > 10 );
    }
    v9 = 0;
    if( v8 > 0 )
    {
        v10 = (char *)info->player_id_hash;
        do
        {
            v11 = *(_DWORD *)v10;
            v10 += 4;
            player_id_hash[v11] = v9++;
        }
        while( v9 < v8 );
    }
    v12 = 0;
    if( v8 > 0 )
    {
        do
            RGE_Player::remake_visible_map(v5->players[v12++]);
        while( v12 < v5->player_num );
    }
    rge_read((int)v5, v12, v4, &scenario_player_num, 4);
    v13 = scenario_player_num;
    v14 = 0;
    if( scenario_player_num > 0 )
    {
        do
        {
            rge_read((int)v5, (int)v14, v4, &infile, 1);
            rge_read((int)v5, (int)v14, v4, &data, 1);
            v13 = scenario_player_num;
            v14 = (int *)((char *)v14 + 1);
        }
        while( (signed int)v14 < scenario_player_num );
    }
    info = 0;
    if( v13 > 0 )
    {
        v14 = player_id_hash;
        do
        {
            rge_read((int)v5, (int)v14, v4, &count, 4);
            for( i = 0; i < count; ++i )
            {
                rge_read((int)v5, (int)v14, v4, &world_x, 4);
                rge_read((int)v5, (int)v14, v4, &world_y, 4);
                rge_read((int)v5, (int)v14, v4, &world_z, 4);
                rge_read((int)v5, (int)v14, v4, &id, 4);
                rge_read((int)v5, (int)v14, v4, &master_id, 2);
                rge_read((int)v5, (int)v14, v4, &obj_state, 1);
                rge_read((int)v5, (int)v14, v4, &obj_angle, 4);
                if( *v14 >= 0 )
                {
                    v16 = (int)&v5->players[*v14];
                    if( *(_DWORD *)v16 )
                    {
                        v17 = id;
                        v5->scenario_object_flag = 1;
                        v5->scenario_object_id = v17;
                        (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int, _DWORD))(**(_DWORD **)v16 + 96))(
                            LODWORD(world_x),
                            LODWORD(world_y),
                            LODWORD(world_z),
                            master_id,
                            obj_state,
                            LODWORD(obj_angle));
                        v5->scenario_object_flag = 0;
                    }
                }
            }
            ++v14;
            info = (RGE_Player_Info *)((char *)info + 1);
        }
        while( (signed int)info < scenario_player_num );
    }
    v5->next_object_id = obj_id;
    rge_read((int)v5, (int)v14, v4, rem, 13);
    v18 = 1;
    if( scenario_player_num > 1 )
    {
        v19 = &player_id_hash[1];
        do
        {
            if( v18 >= v5->player_num || *v19 <= -1 || (v20 = v5->players[*v19]) == 0 )
                v20 = *v5->players;
            ((void (__stdcall *)(int, int *, signed int))v20->vfptr->scenario_load)(v4, player_id_hash, 1065688760);
            ++v18;
            ++v19;
        }
        while( v18 < scenario_player_num );
    }
    rge_close(v4);
    for( j = 1; j < v5->player_num; ++j )
    {
        if( j >= scenario_player_num )
            break;
        v22 = v5->players;
        if( v22[j] )
        {
            v23 = player_id_hash[j];
            if( v23 > -1 )
            {
                v24 = v22[v23]->vfptr;
                v25 = RGE_Scenario::GetPlayerPosture(v5->scenario, j - 1);
                v26 = RGE_Scenario::Get_player_AI(v5->scenario, j - 1, 1);
                v27 = RGE_Scenario::Get_CityPlan(v5->scenario, j - 1, 1);
                v28 = RGE_Scenario::Get_BuildList(v5->scenario, j - 1, 1);
                v24->loadAIInformation(v5->players[player_id_hash[j]], v28, v27, v26, v25, -1);
            }
        }
    }
}

void RGE_Game_World::load_scenario4(int infile, RGE_Player_Info *info)
{
    int v4; // esi@1
    RGE_Game_World *v5; // ebp@1
    void *v6; // eax@2
    RGE_Game_WorldVtbl *v7; // edi@5
    signed int v8; // edx@5
    int v9; // eax@7
    char *v10; // ecx@8
    int v11; // edi@9
    int v12; // edi@10
    int v13; // eax@12
    int v14; // edi@12
    int *v15; // ebx@13
    RGE_Player *v16; // ecx@16
    int *v17; // edi@20
    int i; // ebx@21
    int v19; // eax@23
    int v20; // edx@24
    int j; // edi@27
    RGE_Player **v22; // ecx@29
    int v23; // eax@30
    RGE_PlayerVtbl *v24; // ebx@31
    int v25; // ST14_4@31
    char *v26; // ST10_4@31
    char *v27; // ST0C_4@31
    char *v28; // eax@31
    int header_size; // [sp+2Ch] [bp-4Ch]@1
    int count; // [sp+30h] [bp-48h]@21
    int id; // [sp+34h] [bp-44h]@22
    float obj_angle; // [sp+38h] [bp-40h]@22
    int obj_state; // [sp+3Ch] [bp-3Ch]@22
    int master_id; // [sp+40h] [bp-38h]@22
    float world_z; // [sp+44h] [bp-34h]@22
    float world_y; // [sp+48h] [bp-30h]@22
    float world_x; // [sp+4Ch] [bp-2Ch]@22
    int obj_id; // [sp+50h] [bp-28h]@5
    int player_id_hash[9]; // [sp+54h] [bp-24h]@6

    world_update_counter = 0;
    v4 = infile;
    v5 = this;
    rge_read_uncompressed(infile, &header_size, 4);
    if( header_size > 0 )
    {
        v6 = malloc(header_size);
        a2 = v6;
        if( !v6 )
        {
            rge_close(v4);
            return;
        }
        rge_read_uncompressed(v4, v6, header_size);
        free(a2);
    }
    rge_read((int)v5, (int)a2, v4, &obj_id, 4);
    v7 = v5->vfptr;
    v5->vfptr->scenario_init(v5, v4, v5);
    v7->scenario_make_map(v5, v4);
    v8 = v5->player_num;
    if( v8 > 0 )
    {
        do
            memset(player_id_hash, 0xFFu, sizeof(player_id_hash));
        while( v8 > 10 );
    }
    v9 = 0;
    if( v8 > 0 )
    {
        v10 = (char *)info->player_id_hash;
        do
        {
            v11 = *(_DWORD *)v10;
            v10 += 4;
            player_id_hash[v11] = v9++;
        }
        while( v9 < v8 );
    }
    v12 = 0;
    if( v8 > 0 )
    {
        do
            RGE_Player::remake_visible_map(v5->players[v12++]);
        while( v12 < v5->player_num );
    }
    rge_read((int)v5, v12, v4, &infile, 4);
    v13 = infile;
    v14 = 1;
    if( infile > 1 )
    {
        v15 = &player_id_hash[1];
        do
        {
            if( v14 >= v5->player_num || *v15 <= -1 || (v16 = v5->players[*v15]) == 0 )
                v16 = *v5->players;
            ((void (__stdcall *)(int, int *, signed int))v16->vfptr->scenario_load)(v4, player_id_hash, 1065688760);
            v13 = infile;
            ++v14;
            ++v15;
        }
        while( v14 < infile );
    }
    info = 0;
    if( v13 > 0 )
    {
        v17 = player_id_hash;
        do
        {
            rge_read((int)v5, (int)v17, v4, &count, 4);
            for( i = 0; i < count; ++i )
            {
                rge_read((int)v5, (int)v17, v4, &world_x, 4);
                rge_read((int)v5, (int)v17, v4, &world_y, 4);
                rge_read((int)v5, (int)v17, v4, &world_z, 4);
                rge_read((int)v5, (int)v17, v4, &id, 4);
                rge_read((int)v5, (int)v17, v4, &master_id, 2);
                rge_read((int)v5, (int)v17, v4, &obj_state, 1);
                rge_read((int)v5, (int)v17, v4, &obj_angle, 4);
                if( *v17 >= 0 )
                {
                    v19 = (int)&v5->players[*v17];
                    if( *(_DWORD *)v19 )
                    {
                        v20 = id;
                        v5->scenario_object_flag = 1;
                        v5->scenario_object_id = v20;
                        (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int, _DWORD))(**(_DWORD **)v19 + 96))(
                            LODWORD(world_x),
                            LODWORD(world_y),
                            LODWORD(world_z),
                            master_id,
                            obj_state,
                            LODWORD(obj_angle));
                        v5->scenario_object_flag = 0;
                    }
                }
            }
            ++v17;
            info = (RGE_Player_Info *)((char *)info + 1);
        }
        while( (signed int)info < infile );
    }
    v5->next_object_id = obj_id;
    rge_close(v4);
    for( j = 1; j < v5->player_num; ++j )
    {
        if( j >= infile )
            break;
        v22 = v5->players;
        if( v22[j] )
        {
            v23 = player_id_hash[j];
            if( v23 > -1 )
            {
                v24 = v22[v23]->vfptr;
                v25 = RGE_Scenario::GetPlayerPosture(v5->scenario, j - 1);
                v26 = RGE_Scenario::Get_player_AI(v5->scenario, j - 1, 1);
                v27 = RGE_Scenario::Get_CityPlan(v5->scenario, j - 1, 1);
                v28 = RGE_Scenario::Get_BuildList(v5->scenario, j - 1, 1);
                v24->loadAIInformation(v5->players[player_id_hash[j]], v28, v27, v26, v25, -1);
            }
        }
    }
}

void RGE_Game_World::load_scenario5(int infile, RGE_Player_Info *info)
{
    int v4; // esi@1
    RGE_Game_World *v5; // ebp@1
    void *v6; // eax@2
    RGE_Game_WorldVtbl *v7; // edi@5
    signed int v8; // edx@5
    int v9; // eax@7
    char *v10; // ecx@8
    int v11; // edi@9
    int v12; // edi@10
    int v13; // eax@12
    int *v14; // edi@12
    int *v15; // ebx@13
    RGE_Player *v16; // ecx@16
    int i; // ebx@21
    int v18; // eax@23
    int v19; // edx@24
    int v20; // edi@27
    int *v21; // ebx@28
    RGE_Player *v22; // ecx@31
    int j; // edi@34
    RGE_Player **v24; // ecx@36
    int v25; // eax@37
    RGE_PlayerVtbl *v26; // ebx@38
    int v27; // ST14_4@38
    char *v28; // ST10_4@38
    char *v29; // ST0C_4@38
    char *v30; // eax@38
    int header_size; // [sp+2Ch] [bp-4Ch]@1
    int count; // [sp+30h] [bp-48h]@21
    int id; // [sp+34h] [bp-44h]@22
    float obj_angle; // [sp+38h] [bp-40h]@22
    int obj_state; // [sp+3Ch] [bp-3Ch]@22
    int master_id; // [sp+40h] [bp-38h]@22
    float world_z; // [sp+44h] [bp-34h]@22
    float world_y; // [sp+48h] [bp-30h]@22
    float world_x; // [sp+4Ch] [bp-2Ch]@22
    int obj_id; // [sp+50h] [bp-28h]@5
    int player_id_hash[9]; // [sp+54h] [bp-24h]@6

    world_update_counter = 0;
    v4 = infile;
    v5 = this;
    rge_read_uncompressed(infile, &header_size, 4);
    if( header_size > 0 )
    {
        v6 = malloc(header_size);
        a2 = v6;
        if( !v6 )
        {
            rge_close(v4);
            return;
        }
        rge_read_uncompressed(v4, v6, header_size);
        free(a2);
    }
    rge_read((int)v5, (int)a2, v4, &obj_id, 4);
    v7 = v5->vfptr;
    v5->vfptr->scenario_init(v5, v4, v5);
    v7->scenario_make_map(v5, v4);
    v8 = v5->player_num;
    if( v8 > 0 )
    {
        do
            memset(player_id_hash, 0xFFu, sizeof(player_id_hash));
        while( v8 > 10 );
    }
    v9 = 0;
    if( v8 > 0 )
    {
        v10 = (char *)info->player_id_hash;
        do
        {
            v11 = *(_DWORD *)v10;
            v10 += 4;
            player_id_hash[v11] = v9++;
        }
        while( v9 < v8 );
    }
    v12 = 0;
    if( v8 > 0 )
    {
        do
            RGE_Player::remake_visible_map(v5->players[v12++]);
        while( v12 < v5->player_num );
    }
    rge_read((int)v5, v12, v4, &infile, 4);
    v13 = infile;
    v14 = (int *)1;
    if( infile > 1 )
    {
        v15 = &player_id_hash[1];
        do
        {
            if( (signed int)v14 >= v5->player_num || *v15 <= -1 || (v16 = v5->players[*v15]) == 0 )
                v16 = *v5->players;
            ((void (__stdcall *)(int, int *, signed int))v16->vfptr->scenario_load)(v4, player_id_hash, 1065856532);
            v13 = infile;
            v14 = (int *)((char *)v14 + 1);
            ++v15;
        }
        while( (signed int)v14 < infile );
    }
    info = 0;
    if( v13 > 0 )
    {
        v14 = player_id_hash;
        do
        {
            rge_read((int)v5, (int)v14, v4, &count, 4);
            for( i = 0; i < count; ++i )
            {
                rge_read((int)v5, (int)v14, v4, &world_x, 4);
                rge_read((int)v5, (int)v14, v4, &world_y, 4);
                rge_read((int)v5, (int)v14, v4, &world_z, 4);
                rge_read((int)v5, (int)v14, v4, &id, 4);
                rge_read((int)v5, (int)v14, v4, &master_id, 2);
                rge_read((int)v5, (int)v14, v4, &obj_state, 1);
                rge_read((int)v5, (int)v14, v4, &obj_angle, 4);
                if( *v14 >= 0 )
                {
                    v18 = (int)&v5->players[*v14];
                    if( *(_DWORD *)v18 )
                    {
                        v19 = id;
                        v5->scenario_object_flag = 1;
                        v5->scenario_object_id = v19;
                        (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int, _DWORD))(**(_DWORD **)v18 + 96))(
                            LODWORD(world_x),
                            LODWORD(world_y),
                            LODWORD(world_z),
                            master_id,
                            obj_state,
                            LODWORD(obj_angle));
                        v5->scenario_object_flag = 0;
                    }
                }
            }
            ++v14;
            info = (RGE_Player_Info *)((char *)info + 1);
        }
        while( (signed int)info < infile );
    }
    v5->next_object_id = obj_id;
    rge_read((int)v5, (int)v14, v4, &infile, 4);
    v20 = 1;
    if( infile > 1 )
    {
        v21 = &player_id_hash[1];
        do
        {
            if( v20 >= v5->player_num || *v21 <= -1 || (v22 = v5->players[*v21]) == 0 )
                v22 = *v5->players;
            ((void (__stdcall *)(int, int *, signed int))v22->vfptr->scenario_postload)(v4, player_id_hash, 1065856532);
            ++v20;
            ++v21;
        }
        while( v20 < infile );
    }
    rge_close(v4);
    for( j = 1; j < v5->player_num; ++j )
    {
        if( j >= infile )
            break;
        v24 = v5->players;
        if( v24[j] )
        {
            v25 = player_id_hash[j];
            if( v25 > -1 )
            {
                v26 = v24[v25]->vfptr;
                v27 = RGE_Scenario::GetPlayerPosture(v5->scenario, j - 1);
                v28 = RGE_Scenario::Get_player_AI(v5->scenario, j - 1, 1);
                v29 = RGE_Scenario::Get_CityPlan(v5->scenario, j - 1, 1);
                v30 = RGE_Scenario::Get_BuildList(v5->scenario, j - 1, 1);
                v26->loadAIInformation(v5->players[player_id_hash[j]], v30, v29, v28, v27, -1);
            }
        }
    }
}

void RGE_Game_World::load_scenario6(int infile, RGE_Player_Info *info)
{
    int v4; // esi@1
    RGE_Game_World *v5; // ebp@1
    void *v6; // eax@2
    RGE_Game_WorldVtbl *v7; // edi@5
    signed int v8; // edx@5
    int v9; // eax@7
    char *v10; // ecx@8
    int v11; // edi@9
    int v12; // edi@10
    int v13; // eax@12
    int *v14; // edi@12
    int *v15; // ebx@13
    RGE_Player *v16; // ecx@16
    int i; // ebx@21
    int v18; // eax@23
    int v19; // edx@24
    int v20; // edi@27
    int *v21; // ebx@28
    RGE_Player *v22; // ecx@31
    int j; // edi@34
    RGE_Player **v24; // ecx@36
    int v25; // eax@37
    RGE_PlayerVtbl *v26; // ebx@38
    int v27; // ST14_4@38
    char *v28; // ST10_4@38
    char *v29; // ST0C_4@38
    char *v30; // eax@38
    int header_size; // [sp+2Ch] [bp-4Ch]@1
    int count; // [sp+30h] [bp-48h]@21
    int id; // [sp+34h] [bp-44h]@22
    float obj_angle; // [sp+38h] [bp-40h]@22
    int obj_state; // [sp+3Ch] [bp-3Ch]@22
    int master_id; // [sp+40h] [bp-38h]@22
    float world_z; // [sp+44h] [bp-34h]@22
    float world_y; // [sp+48h] [bp-30h]@22
    float world_x; // [sp+4Ch] [bp-2Ch]@22
    int obj_id; // [sp+50h] [bp-28h]@5
    int player_id_hash[9]; // [sp+54h] [bp-24h]@6

    world_update_counter = 0;
    v4 = infile;
    v5 = this;
    rge_read_uncompressed(infile, &header_size, 4);
    if( header_size > 0 )
    {
        v6 = malloc(header_size);
        a2 = v6;
        if( !v6 )
        {
            rge_close(v4);
            return;
        }
        rge_read_uncompressed(v4, v6, header_size);
        free(a2);
    }
    rge_read((int)v5, (int)a2, v4, &obj_id, 4);
    v7 = v5->vfptr;
    v5->vfptr->scenario_init(v5, v4, v5);
    v7->scenario_make_map(v5, v4);
    v8 = v5->player_num;
    if( v8 > 0 )
    {
        do
            memset(player_id_hash, 0xFFu, sizeof(player_id_hash));
        while( v8 > 10 );
    }
    v9 = 0;
    if( v8 > 0 )
    {
        v10 = (char *)info->player_id_hash;
        do
        {
            v11 = *(_DWORD *)v10;
            v10 += 4;
            player_id_hash[v11] = v9++;
        }
        while( v9 < v8 );
    }
    v12 = 0;
    if( v8 > 0 )
    {
        do
            RGE_Player::remake_visible_map(v5->players[v12++]);
        while( v12 < v5->player_num );
    }
    rge_read((int)v5, v12, v4, &infile, 4);
    v13 = infile;
    v14 = (int *)1;
    if( infile > 1 )
    {
        v15 = &player_id_hash[1];
        do
        {
            if( (signed int)v14 >= v5->player_num || *v15 <= -1 || (v16 = v5->players[*v15]) == 0 )
                v16 = *v5->players;
            ((void (__stdcall *)(int, int *, signed int))v16->vfptr->scenario_load)(v4, player_id_hash, 1065940419);
            v13 = infile;
            v14 = (int *)((char *)v14 + 1);
            ++v15;
        }
        while( (signed int)v14 < infile );
    }
    info = 0;
    if( v13 > 0 )
    {
        v14 = player_id_hash;
        do
        {
            rge_read((int)v5, (int)v14, v4, &count, 4);
            for( i = 0; i < count; ++i )
            {
                rge_read((int)v5, (int)v14, v4, &world_x, 4);
                rge_read((int)v5, (int)v14, v4, &world_y, 4);
                rge_read((int)v5, (int)v14, v4, &world_z, 4);
                rge_read((int)v5, (int)v14, v4, &id, 4);
                rge_read((int)v5, (int)v14, v4, &master_id, 2);
                rge_read((int)v5, (int)v14, v4, &obj_state, 1);
                rge_read((int)v5, (int)v14, v4, &obj_angle, 4);
                if( *v14 >= 0 )
                {
                    v18 = (int)&v5->players[*v14];
                    if( *(_DWORD *)v18 )
                    {
                        v19 = id;
                        v5->scenario_object_flag = 1;
                        v5->scenario_object_id = v19;
                        (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int, _DWORD))(**(_DWORD **)v18 + 96))(
                            LODWORD(world_x),
                            LODWORD(world_y),
                            LODWORD(world_z),
                            master_id,
                            obj_state,
                            LODWORD(obj_angle));
                        v5->scenario_object_flag = 0;
                    }
                }
            }
            ++v14;
            info = (RGE_Player_Info *)((char *)info + 1);
        }
        while( (signed int)info < infile );
    }
    v5->next_object_id = obj_id;
    rge_read((int)v5, (int)v14, v4, &infile, 4);
    v20 = 1;
    if( infile > 1 )
    {
        v21 = &player_id_hash[1];
        do
        {
            if( v20 >= v5->player_num || *v21 <= -1 || (v22 = v5->players[*v21]) == 0 )
                v22 = *v5->players;
            ((void (__stdcall *)(int, int *, signed int))v22->vfptr->scenario_postload)(v4, player_id_hash, 1065940419);
            ++v20;
            ++v21;
        }
        while( v20 < infile );
    }
    rge_close(v4);
    for( j = 1; j < v5->player_num; ++j )
    {
        if( j >= infile )
            break;
        v24 = v5->players;
        if( v24[j] )
        {
            v25 = player_id_hash[j];
            if( v25 > -1 )
            {
                v26 = v24[v25]->vfptr;
                v27 = RGE_Scenario::GetPlayerPosture(v5->scenario, j - 1);
                v28 = RGE_Scenario::Get_player_AI(v5->scenario, j - 1, 1);
                v29 = RGE_Scenario::Get_CityPlan(v5->scenario, j - 1, 1);
                v30 = RGE_Scenario::Get_BuildList(v5->scenario, j - 1, 1);
                v26->loadAIInformation(v5->players[player_id_hash[j]], v30, v29, v28, v27, -1);
            }
        }
    }
}

void RGE_Game_World::load_scenario7(int infile, RGE_Player_Info *info)
{
    int v4; // esi@1
    RGE_Game_World *v5; // ebp@1
    void *v6; // eax@2
    RGE_Game_WorldVtbl *v7; // edi@5
    signed int v8; // edx@5
    int v9; // eax@7
    char *v10; // ecx@8
    int v11; // edi@9
    int v12; // edi@10
    int v13; // eax@12
    int *v14; // edi@12
    int *v15; // ebx@13
    RGE_Player *v16; // ecx@16
    int i; // ebx@21
    int v18; // eax@23
    int v19; // edx@24
    int v20; // edi@27
    int *v21; // ebx@28
    RGE_Player *v22; // ecx@31
    int j; // edi@34
    RGE_Player **v24; // ecx@36
    int v25; // eax@37
    RGE_PlayerVtbl *v26; // ebx@38
    int v27; // ST14_4@38
    char *v28; // ST10_4@38
    char *v29; // ST0C_4@38
    char *v30; // eax@38
    int header_size; // [sp+2Ch] [bp-4Ch]@1
    int count; // [sp+30h] [bp-48h]@21
    int id; // [sp+34h] [bp-44h]@22
    float obj_angle; // [sp+38h] [bp-40h]@22
    int obj_state; // [sp+3Ch] [bp-3Ch]@22
    int master_id; // [sp+40h] [bp-38h]@22
    float world_z; // [sp+44h] [bp-34h]@22
    float world_y; // [sp+48h] [bp-30h]@22
    float world_x; // [sp+4Ch] [bp-2Ch]@22
    int obj_id; // [sp+50h] [bp-28h]@5
    int player_id_hash[9]; // [sp+54h] [bp-24h]@6

    world_update_counter = 0;
    v4 = infile;
    v5 = this;
    rge_read_uncompressed(infile, &header_size, 4);
    if( header_size > 0 )
    {
        v6 = malloc(header_size);
        a2 = v6;
        if( !v6 )
        {
            rge_close(v4);
            return;
        }
        rge_read_uncompressed(v4, v6, header_size);
        free(a2);
    }
    rge_read((int)v5, (int)a2, v4, &obj_id, 4);
    v7 = v5->vfptr;
    v5->vfptr->scenario_init(v5, v4, v5);
    v7->scenario_make_map(v5, v4);
    v8 = v5->player_num;
    if( v8 > 0 )
    {
        do
            memset(player_id_hash, 0xFFu, sizeof(player_id_hash));
        while( v8 > 10 );
    }
    v9 = 0;
    if( v8 > 0 )
    {
        v10 = (char *)info->player_id_hash;
        do
        {
            v11 = *(_DWORD *)v10;
            v10 += 4;
            player_id_hash[v11] = v9++;
        }
        while( v9 < v8 );
    }
    v12 = 0;
    if( v8 > 0 )
    {
        do
            RGE_Player::remake_visible_map(v5->players[v12++]);
        while( v12 < v5->player_num );
    }
    rge_read((int)v5, v12, v4, &infile, 4);
    v13 = infile;
    v14 = (int *)1;
    if( infile > 1 )
    {
        v15 = &player_id_hash[1];
        do
        {
            if( (signed int)v14 >= v5->player_num || *v15 <= -1 || (v16 = v5->players[*v15]) == 0 )
                v16 = *v5->players;
            ((void (__stdcall *)(int, int *, signed int))v16->vfptr->scenario_load)(v4, player_id_hash, 1066024305);
            v13 = infile;
            v14 = (int *)((char *)v14 + 1);
            ++v15;
        }
        while( (signed int)v14 < infile );
    }
    info = 0;
    if( v13 > 0 )
    {
        v14 = player_id_hash;
        do
        {
            rge_read((int)v5, (int)v14, v4, &count, 4);
            for( i = 0; i < count; ++i )
            {
                rge_read((int)v5, (int)v14, v4, &world_x, 4);
                rge_read((int)v5, (int)v14, v4, &world_y, 4);
                rge_read((int)v5, (int)v14, v4, &world_z, 4);
                rge_read((int)v5, (int)v14, v4, &id, 4);
                rge_read((int)v5, (int)v14, v4, &master_id, 2);
                rge_read((int)v5, (int)v14, v4, &obj_state, 1);
                rge_read((int)v5, (int)v14, v4, &obj_angle, 4);
                if( *v14 >= 0 )
                {
                    v18 = (int)&v5->players[*v14];
                    if( *(_DWORD *)v18 )
                    {
                        v19 = id;
                        v5->scenario_object_flag = 1;
                        v5->scenario_object_id = v19;
                        (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int, _DWORD))(**(_DWORD **)v18 + 96))(
                            LODWORD(world_x),
                            LODWORD(world_y),
                            LODWORD(world_z),
                            master_id,
                            obj_state,
                            LODWORD(obj_angle));
                        v5->scenario_object_flag = 0;
                    }
                }
            }
            ++v14;
            info = (RGE_Player_Info *)((char *)info + 1);
        }
        while( (signed int)info < infile );
    }
    v5->next_object_id = obj_id;
    rge_read((int)v5, (int)v14, v4, &infile, 4);
    v20 = 1;
    if( infile > 1 )
    {
        v21 = &player_id_hash[1];
        do
        {
            if( v20 >= v5->player_num || *v21 <= -1 || (v22 = v5->players[*v21]) == 0 )
                v22 = *v5->players;
            ((void (__stdcall *)(int, int *, signed int))v22->vfptr->scenario_postload)(v4, player_id_hash, 1066024305);
            ++v20;
            ++v21;
        }
        while( v20 < infile );
    }
    rge_close(v4);
    for( j = 1; j < v5->player_num; ++j )
    {
        if( j >= infile )
            break;
        v24 = v5->players;
        if( v24[j] )
        {
            v25 = player_id_hash[j];
            if( v25 > -1 )
            {
                v26 = v24[v25]->vfptr;
                v27 = RGE_Scenario::GetPlayerPosture(v5->scenario, j - 1);
                v28 = RGE_Scenario::Get_player_AI(v5->scenario, j - 1, 1);
                v29 = RGE_Scenario::Get_CityPlan(v5->scenario, j - 1, 1);
                v30 = RGE_Scenario::Get_BuildList(v5->scenario, j - 1, 1);
                v26->loadAIInformation(v5->players[player_id_hash[j]], v30, v29, v28, v27, -1);
            }
        }
    }
}

void RGE_Game_World::load_scenario8(int infile, RGE_Player_Info *info)
{
    int v4; // esi@1
    RGE_Game_World *v5; // ebp@1
    void *v6; // eax@2
    RGE_Game_WorldVtbl *v7; // edi@5
    signed int v8; // edx@5
    int v9; // eax@7
    char *v10; // ecx@8
    int v11; // edi@9
    int v12; // edi@10
    int v13; // eax@12
    int *v14; // edi@12
    int *v15; // ebx@13
    RGE_Player *v16; // ecx@16
    int i; // ebx@21
    int v18; // eax@23
    int v19; // edx@24
    int v20; // edi@27
    int *v21; // ebx@28
    RGE_Player *v22; // ecx@31
    int j; // edi@34
    RGE_Player **v24; // ecx@36
    int v25; // eax@37
    RGE_PlayerVtbl *v26; // ebx@38
    int v27; // ST14_4@38
    char *v28; // ST10_4@38
    char *v29; // ST0C_4@38
    char *v30; // eax@38
    int header_size; // [sp+2Ch] [bp-4Ch]@1
    int count; // [sp+30h] [bp-48h]@21
    int id; // [sp+34h] [bp-44h]@22
    float obj_angle; // [sp+38h] [bp-40h]@22
    int obj_state; // [sp+3Ch] [bp-3Ch]@22
    int master_id; // [sp+40h] [bp-38h]@22
    float world_z; // [sp+44h] [bp-34h]@22
    float world_y; // [sp+48h] [bp-30h]@22
    float world_x; // [sp+4Ch] [bp-2Ch]@22
    int obj_id; // [sp+50h] [bp-28h]@5
    int player_id_hash[RGE_PLAYERS_COUNT];

    world_update_counter = 0;
    v4 = infile;
    v5 = this;
    rge_read_uncompressed(infile, &header_size, 4);
    if( header_size > 0 )
    {
        v6 = malloc(header_size);
        a2 = v6;
        if( !v6 )
        {
            rge_close(v4);
            return;
        }
        rge_read_uncompressed(v4, v6, header_size);
        free(a2);
    }
    rge_read((int)v5, (int)a2, v4, &obj_id, 4);
    v7 = v5->vfptr;
    v5->vfptr->scenario_init(v5, v4, v5);
    v7->scenario_make_map(v5, v4);
    v8 = v5->player_num;
    if( v8 > 0 )
    {
        do
            memset(player_id_hash, 0xFFu, sizeof(player_id_hash));
        while( v8 > 10 );
    }
    v9 = 0;
    if( v8 > 0 )
    {
        v10 = (char *)info->player_id_hash;
        do
        {
            v11 = *(_DWORD *)v10;
            v10 += 4;
            player_id_hash[v11] = v9++;
        }
        while( v9 < v8 );
    }
    v12 = 0;
    if( v8 > 0 )
    {
        do
            RGE_Player::remake_visible_map(v5->players[v12++]);
        while( v12 < v5->player_num );
    }
    rge_read((int)v5, v12, v4, &infile, 4);
    v13 = infile;
    v14 = (int *)1;
    if( infile > 1 )
    {
        v15 = &player_id_hash[1];
        do
        {
            if( (signed int)v14 >= v5->player_num || *v15 <= -1 || (v16 = v5->players[*v15]) == 0 )
                v16 = *v5->players;
            ((void (__stdcall *)(int, int *, signed int))v16->vfptr->scenario_load)(v4, player_id_hash, 1066275963);
            v13 = infile;
            v14 = (int *)((char *)v14 + 1);
            ++v15;
        }
        while( (signed int)v14 < infile );
    }
    info = 0;
    if( v13 > 0 )
    {
        v14 = player_id_hash;
        do
        {
            rge_read((int)v5, (int)v14, v4, &count, 4);
            for( i = 0; i < count; ++i )
            {
                rge_read((int)v5, (int)v14, v4, &world_x, 4);
                rge_read((int)v5, (int)v14, v4, &world_y, 4);
                rge_read((int)v5, (int)v14, v4, &world_z, 4);
                rge_read((int)v5, (int)v14, v4, &id, 4);
                rge_read((int)v5, (int)v14, v4, &master_id, 2);
                rge_read((int)v5, (int)v14, v4, &obj_state, 1);
                rge_read((int)v5, (int)v14, v4, &obj_angle, 4);
                if( *v14 >= 0 )
                {
                    v18 = (int)&v5->players[*v14];
                    if( *(_DWORD *)v18 )
                    {
                        v19 = id;
                        v5->scenario_object_flag = 1;
                        v5->scenario_object_id = v19;
                        (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, int, int, _DWORD))(**(_DWORD **)v18 + 96))(
                            LODWORD(world_x),
                            LODWORD(world_y),
                            LODWORD(world_z),
                            master_id,
                            obj_state,
                            LODWORD(obj_angle));
                        v5->scenario_object_flag = 0;
                    }
                }
            }
            ++v14;
            info = (RGE_Player_Info *)((char *)info + 1);
        }
        while( (signed int)info < infile );
    }
    v5->next_object_id = obj_id;
    rge_read((int)v5, (int)v14, v4, &infile, 4);
    v20 = 1;
    if( infile > 1 )
    {
        v21 = &player_id_hash[1];
        do
        {
            if( v20 >= v5->player_num || *v21 <= -1 || (v22 = v5->players[*v21]) == 0 )
                v22 = *v5->players;
            ((void (__stdcall *)(int, int *, signed int))v22->vfptr->scenario_postload)(v4, player_id_hash, 1066275963);
            ++v20;
            ++v21;
        }
        while( v20 < infile );
    }
    rge_close(v4);

    for( int j = 1; j < this->player_num && j < infile; j++ ){

        if( this->players[j] && player_id_hash[j] > -1 ){

            this->players[player_id_hash[j]]->loadAIInformation(
                this->scenario->Get_BuildList(j - 1, 1),
                this->scenario->Get_CityPlan(j - 1, 1),
                this->scenario->Get_player_AI(j - 1, 1),
                this->scenario->GetPlayerPosture(j - 1),
                -1);
        }
    }
}

void RGE_Game_World::selectNextComputerPlayer(int cPType)
{
    RGE_Game_World *v2; // ebp@1
    int v3; // ecx@1
    int v4; // esi@2
    int v5; // eax@2
    RGE_Player **v6; // edx@3
    int v7; // esi@8
    int v8; // edx@8
    int v9; // edi@8

    v2 = this;
    v3 = this->currentUpdateComputerPlayer;
    if( this->currentUpdateComputerPlayer == -1 )
    {
        v4 = v2->player_num;
        v5 = 0;
        if( this->player_num > 0 )
        {
            v6 = this->players;
            while( (*v6)->type != cPType )
            {
                ++v5;
                ++v6;
                if( v5 >= v4 )
                    return;
            }
            this->currentUpdateComputerPlayer = v5;
        }
    }else{
        v7 = this->player_num;
        v8 = v3;
        v9 = 0;
        if( v3 < v7 )
        {
            while( v9 < v7 )
            {
                if( v2->players[v8]->type == cPType && v8 != v3 )
                {
                    this->currentUpdateComputerPlayer = v8;
                    return;
                }
                v8 = (v8 + 1) % v2->player_num;
                ++v9;
                if( v8 >= v7 )
                    return;
            }
        }
    }
}

void RGE_Game_World::useComputerPlayerUpdateTime(unsigned int usedTime)
{
    if( this->availableComputerPlayerUpdateTime >= usedTime ){
        this->availableComputerPlayerUpdateTime -= usedTime;
    }else{
        this->availableComputerPlayerUpdateTime = 0;
    }
}

bool RGE_Game_World::computerPlayerUpdateTimeAvailable()
{
    return this->availableComputerPlayerUpdateTime > 0;
}

int RGE_Game_World::objectGroupOnTile(int ownerID, int groupID, int x, int y, int *objectCount)
{
    RGE_Map *v6; // esi@3
    RGE_Object_Node *v7; // eax@5
    RGE_Static_Object *v8; // ecx@6

    if( x < 0 || y < 0 || (v6 = this->map, x >= v6->map_width) || y >= v6->map_height )
    {
        *objectCount = 0;
    }
    else
    {
        *objectCount = v6->map_row_offset[y][x].objects.number_of_objects;
        v7 = this->map->map_row_offset[y][x].objects.list;
        if( v7 )
        {
            while( 1 )
            {
                v8 = v7->node;
                if( !v7->node )
                    break;
                if( (ownerID == -1 || v8->owner->id == ownerID) && v8->master_obj->object_group == groupID )
                    return v8->id;
                v7 = v7->next;
                if( !v7 )
                    return -1;
            }
        }
    }
    return -1;
}

int RGE_Game_World::difficultyLevel()
{
    if( this->difficultyLevelValue == -1 ){
        this->difficultyLevelValue = rge_base_game->difficulty(rge_base_game);
    }
    return this->difficultyLevelValue;
}

RGE_Scenario *RGE_Game_World::get_scenario_info(char *filename)
{
    return nullptr;
}

int RGE_Game_World::maxNumberObjects()
{
    return this->maxNumberObjectsValue;
}

int RGE_Game_World::maxNumberNegativeObjects()
{
    return this->maxNumberNegativeObjectsValue;
}

int RGE_Game_World::numberObjects()
{
    return this->numberObjectsValue;
}

int RGE_Game_World::numberNegativeObjects()
{
    return this->numberNegativeObjectsValue;
}

RGE_Static_Object *RGE_Game_World::object(int oID)
{
    if( oID >= 0 || -oID >= this->maxNumberNegativeObjectsValue ){
        if( oID <= -1 || oID >= this->maxNumberObjectsValue ){
            return nullptr;
        }else{
            return this->objectsValue[oID];
        }
    }else{
        return this->negativeObjectsValue[-oID];
    }
}

RGE_Static_Object *RGE_Game_World::object_ptr(int oID)
{
    return this->object(oID);
}

int RGE_Game_World::get_next_object_id()
{
    if( this->scenario_object_flag ){
        return this->scenario_object_id;
    }else{
        int v1 = this->maxNumberObjectsValue - 1;
        if( v1 >= this->next_object_id ){
            do{
                if( this->objectsValue[this->next_object_id] == nullptr )
                    break;
                this->next_object_id ++;
            }
            while( v1 >= this->next_object_id );
        }
        return this->next_object_id++;
    }
}

int RGE_Game_World::get_next_reusable_object_id()
{
    if( this->scenario_object_flag ){
        if( this->next_reusable_object_id > this->scenario_object_id ){
            this->next_reusable_object_id = this->scenario_object_id - 1;
        }
        return this->scenario_object_id;
    }else{
        return this->next_reusable_object_id--;
    }
}

RGE_Static_Object **RGE_Game_World::addObject(RGE_Static_Object *newObject)
{
    RGE_Static_Object *v2; // edx@1
    int v3; // eax@1
    RGE_Game_World *v4; // esi@1
    int v5; // ecx@2
    int v6; // ebp@3
    RGE_Static_Object **result; // eax@5
    struct RGE_Static_Object **v8; // ebx@5
    int j; // eax@6
    RGE_Static_Object **v10; // eax@11
    RGE_Static_Object *v11; // ecx@11
    int v12; // edi@14
    int v13; // eax@14
    int v14; // ebp@15
    RGE_Static_Object **v15; // ebx@17
    int i; // eax@18

    v2 = newObject;
    v3 = newObject->id;
    v4 = this;
    if( v3 < 0 )
    {
        v12 = -v3;
        v13 = this->maxNumberNegativeObjectsValue;
        if( v13 - 1 < v12 )
        {
            v14 = 2 * v13;
            if( 2 * v13 < v12 )
                v14 = (signed __int64)((double)v12 * 1.1);
            result = (RGE_Static_Object **)operator new(4 * v14);
            v15 = result;
            if( !result )
                return result;
            for( i = 0; i < v4->maxNumberNegativeObjectsValue; v15[i - 1] = v4->negativeObjectsValue[i - 1] )
                ++i;
            if( i < v14 )
                memset(&v15[i], 0, 4 * (v14 - i));
            operator delete(v4->negativeObjectsValue);
            v2 = newObject;
            v4->negativeObjectsValue = v15;
            v4->maxNumberNegativeObjectsValue = v14;
        }
        v4->negativeObjectsValue[v12] = v2;
        ++v4->numberNegativeObjectsValue;
        return (RGE_Static_Object **)1;
    }
    v5 = this->maxNumberObjectsValue;
    if( v5 - 1 >= v3 )
        goto LABEL_11;
    v6 = 2 * v5;
    if( 2 * v5 < v3 )
        v6 = (signed __int64)((double)newObject->id * 1.1);
    result = (RGE_Static_Object **)operator new(4 * v6);
    v8 = result;
    if( result )
    {
        for( j = 0; j < v4->maxNumberObjectsValue; v8[j - 1] = v4->objectsValue[j - 1] )
            ++j;
        if( j < v6 )
            memset(&v8[j], 0, 4 * (v6 - j));
        operator delete(v4->objectsValue);
        v2 = newObject;
        v4->objectsValue = v8;
        VIS_UNIT_objectsValue = v8;
        v4->maxNumberObjectsValue = v6;
LABEL_11:
        v10 = &v4->objectsValue[v2->id];
        v11 = *v10;
        *v10 = v2;
        ++v4->numberObjectsValue;
        if( v11 && v4->scenario_object_flag )
        {
            v4->scenario_object_flag = 0;
            RGE_Static_Object::change_unique_id(v11);
            return (RGE_Static_Object **)1;
        }
        return (RGE_Static_Object **)1;
    }
    return result;
}

bool RGE_Game_World::removeObject(int oID)
{
    if( oID >= 0 || -oID >= this->maxNumberNegativeObjectsValue ){
        if( oID <= -1 || oID >= this->maxNumberObjectsValue ){
            return false;
        }else{
            this->objectsValue[oID] = 0;
            return true;
        }
    }else{
        this->negativeObjectsValue[-oID] = 0;
        return true;
    }
}

void RGE_Game_World::initializePathingSystem()
{
    if( this->map ){

        pathSystem->initialize(
            this->map->map_width,
            this->map->map_height,
            this->map,
            this);

        aiPathSystem->initialize(
            this->map->map_width,
            this->map->map_height,
            this->map,
            this);
    }
}

bool RGE_Game_World::recycle_object_out_of_game(
    char object_type,
    RGE_Static_Object *obj)
{
    switch( object_type ){

    case RGE_STATIC_OBJECT_TYPE:
        this->reusable_static_objects->add_node(obj);
        return true;

    case RGE_ANIMATED_OBJECT_TYPE:
        this->reusable_animated_objects->add_node(obj);
        return true;

#if RGE_DOPPLEGANGER_SYSTEM_EXISTS
    case RGE_DOPPLEGANGER_OBJECT_TYPE:
        this->reusable_doppleganger_objects->add_node(obj);
        return true;
#endif

    case RGE_MOVING_OBJECT_TYPE:
        this->reusable_moving_objects->add_node(obj);
        return true;

    case RGE_ACTION_OBJECT_TYPE:
        this->reusable_action_objects->add_node(obj);
        return true;

    case RGE_COMBAT_OBJECT_TYPE:
        this->reusable_combat_objects->add_node(obj);
        return true;

    case RGE_MISSILE_OBJECT_TYPE:
        this->reusable_missile_objects->add_node(obj);
        return true;

    default:
        return false;
    }
}

RGE_Static_Object *RGE_Game_World::recycle_object_in_to_game(char object_type)
{
    RGE_Static_Object *v2; // esi@1
    RGE_Object_List *v3; // ecx@2
    RGE_Static_Object **v4; // eax@2
    RGE_Static_Object *v5; // esi@3
    RGE_Static_Object *result; // eax@3
    RGE_Object_List *v7; // ecx@4
    RGE_Static_Object **v8; // eax@4
    RGE_Static_Object *v9; // esi@5
    RGE_Object_List *v10; // ecx@6
    RGE_Static_Object **v11; // eax@6
    RGE_Static_Object *v12; // esi@7
    RGE_Object_List *v13; // ecx@8
    RGE_Static_Object **v14; // eax@8
    RGE_Static_Object *v15; // esi@9
    RGE_Object_List *v16; // ecx@10
    RGE_Static_Object **v17; // eax@10
    RGE_Static_Object *v18; // esi@11
    RGE_Object_List *v19; // ecx@12
    RGE_Static_Object **v20; // eax@12
    RGE_Static_Object *v21; // esi@13
    RGE_Object_List *v22; // ecx@14
    RGE_Static_Object **v23; // eax@14

    v2 = 0;
    switch( object_type )
    {
        case 0xA:
            v3 = this->reusable_static_objects;
            v4 = &v3->list->node;
            if( !v4 )
                goto LABEL_16;
            v5 = *v4;
            RGE_Object_List::remove_node(v3, *v4, 0);
            result = v5;
            break;
        case 0x14:
            v7 = this->reusable_animated_objects;
            v8 = &v7->list->node;
            if( !v8 )
                goto LABEL_16;
            v9 = *v8;
            RGE_Object_List::remove_node(v7, *v8, 0);
            result = v9;
            break;
        case 0x1E:
            v10 = this->reusable_moving_objects;
            v11 = &v10->list->node;
            if( !v11 )
                goto LABEL_16;
            v12 = *v11;
            RGE_Object_List::remove_node(v10, *v11, 0);
            result = v12;
            break;
        case 0x28:
            v13 = this->reusable_action_objects;
            v14 = &v13->list->node;
            if( !v14 )
                goto LABEL_16;
            v15 = *v14;
            RGE_Object_List::remove_node(v13, *v14, 0);
            result = v15;
            break;
        case 0x32:
            v16 = this->reusable_combat_objects;
            v17 = &v16->list->node;
            if( !v17 )
                goto LABEL_16;
            v18 = *v17;
            RGE_Object_List::remove_node(v16, *v17, 0);
            result = v18;
            break;
        case 0x3C:
            v19 = this->reusable_missile_objects;
            v20 = &v19->list->node;
            if( !v20 )
                goto LABEL_16;
            v21 = *v20;
            RGE_Object_List::remove_node(v19, *v20, 0);
            result = v21;
            break;
        case 0x19:
            v22 = this->reusable_doppleganger_objects;
            v23 = &v22->list->node;
            if( v23 )
            {
                v2 = *v23;
                RGE_Object_List::remove_node(v22, *v23, 0);
            }
            goto LABEL_16;
        default:
LABEL_16:
            result = v2;
            break;
    }
    return result;
}

void RGE_Game_World::update_mutual_allies()
{
    RGE_Game_World *v1; // esi@1
    signed int v2; // ebp@1
    signed int i; // edx@1
    signed int v4; // eax@2
    int *v5; // eax@4
    signed int v6; // edi@4
    signed int v7; // ecx@10
    signed int v8; // ebx@10
    signed int j; // edi@10
    signed int v10; // eax@12
    RGE_Player **v11; // edx@14
    RGE_Player *v12; // ecx@14
    RGE_Player *v13; // edx@16
    RGE_Player *v14; // edx@16
    signed int v15; // eax@20
    signed int v16; // ecx@20
    int v17; // edx@21
    signed int v18; // ebp@23
    signed int v19; // edi@26
    RGE_Player **v20; // eax@27
    RGE_Player *v21; // ecx@28
    RGE_PlayerVtbl **v22; // eax@30
    int v23; // ebx@38
    signed int v24; // edi@39
    signed int v25; // edi@44
    signed int v26; // edi@49
    int v27; // eax@55
    int v28; // eax@57
    int index; // [sp+10h] [bp-Ch]@22
    int pNum; // [sp+14h] [bp-8h]@20

    v1 = this;
    fprintf(DVlogf, aUpdatingPlayer, this->world_time);
    v2 = 0;
    for( i = 0; i < v1->player_num; ++i )
    {
        v1->players[i]->mutualExploredMask = 0;
        v1->players[i]->mutualVisibleMask = 0;
        v4 = 220;
        v1->players[i]->nonMutualVisibleMask = 0;
        do
        {
            v4 += 4;
            *(_DWORD *)((char *)v1->players[i] + v4 - 4) = 0;
        }
        while( v4 < 256 );
        v5 = v1->players[i]->mutualAlly;
        v6 = 0;
        do
        {
            if( v6 == i )
            {
                *v5 = 1;
                v1->players[i]->mutualVisibleMask = 1 << i;
                v1->players[i]->mutualExploredMask = 1 << (i + 16);
            }
            else
            {
                *v5 = 0;
            }
            ++v6;
            ++v5;
        }
        while( v6 < 9 );
    }
    v7 = v1->player_num;
    v8 = 1;
    for( j = 1; j < v7; ++j )
    {
        if( v1->players[j]->allied_LOS_Enable == 1 )
        {
            v10 = 1;
            if( v7 > 1 )
            {
                do
                {
                    if( v10 != j )
                    {
                        v11 = v1->players;
                        v12 = v11[j];
                        if( !v12->relations[v10] && !v11[v10]->relations[j] )
                        {
                            v12->mutualAlly[v10] = 1;
                            v13 = v1->players[j];
                            v13->mutualVisibleMask |= 1 << v10;
                            v14 = v1->players[j];
                            v14->mutualExploredMask |= 1 << (v10 + 16);
                        }
                    }
                    ++v10;
                }
                while( v10 < v1->player_num );
                v2 = 0;
            }
        }
        v7 = v1->player_num;
    }
    v15 = v1->player_num;
    v16 = 0;
    pNum = 0;
    if( v15 > 0 )
    {
        v17 = 0;
        do
        {
            index = 1;
            if( v15 > 1 )
            {
                v18 = 224;
                do
                {
                    if( v8 != v16 && !*(_DWORD *)((char *)v1->players[v17] + v18 - 48) )
                    {
                        v19 = 1;
                        if( v15 > 1 )
                        {
                            do
                            {
                                v20 = v1->players;
                                if( !v20[v17]->mutualAlly[v19] )
                                {
                                    v21 = v20[v19];
                                    if( *(_DWORD *)((char *)v21 + v18 - 48) == 1 && v21->mutualAlly[v17] == 1 )
                                    {
                                        v20[v17]->nonMutualVisibleMask |= 1 << v8;
                                        v22 = (RGE_PlayerVtbl **)((char *)&v1->players[v17]->vfptr + v18);
                                        v8 = index;
                                        *v22 = (RGE_PlayerVtbl *)((1 << v19) | (unsigned int)*v22);
                                    }
                                }
                                ++v19;
                            }
                            while( v19 < v1->player_num );
                            v16 = pNum;
                        }
                    }
                    v15 = v1->player_num;
                    ++v8;
                    v18 += 4;
                    index = v8;
                }
                while( v8 < v15 );
                v8 = 1;
            }
            v15 = v1->player_num;
            ++v16;
            ++v17;
            pNum = v16;
        }
        while( v16 < v15 );
        v2 = 0;
    }
    if( v1->player_num > 0 )
    {
        v23 = 0;
        do
        {
            fprintf(DVlogf, aPlayerD, v2);
            fprintf(
                DVlogf,
                aMutualexplored,
                v1->players[v23]->mutualExploredMask,
                v1->players[v23]->mutualVisibleMask,
                v1->players[v23]->nonMutualVisibleMask);
            fprintf(DVlogf, aAllied_los_ena, v1->players[v23]->allied_LOS_Enable, v1->players[v23]->allied_victory);
            fprintf(DVlogf, aUnitdiplomacy);
            v24 = 136;
            do
            {
                fprintf(DVlogf, aD_3, *(RGE_PlayerVtbl **)((char *)&v1->players[v23]->vfptr + v24));
                if( v24 >= 168 )
                    fprintf(DVlogf, asc_58EE54);
                else
                    fprintf(DVlogf, asc_584EE4);
                v24 += 4;
            }
            while( v24 < 172 );
            fprintf(DVlogf, aMututalally);
            v25 = 172;
            do
            {
                fprintf(DVlogf, aD_3, *(RGE_PlayerVtbl **)((char *)&v1->players[v23]->vfptr + v25));
                if( v25 >= 204 )
                    fprintf(DVlogf, asc_58EE54);
                else
                    fprintf(DVlogf, asc_584EE4);
                v25 += 4;
            }
            while( v25 < 208 );
            fprintf(DVlogf, aRemovevisibleb);
            v26 = 220;
            do
            {
                fprintf(DVlogf, a8_8x, *(RGE_PlayerVtbl **)((char *)&v1->players[v23]->vfptr + v26));
                if( v26 >= 252 )
                    fprintf(DVlogf, asc_58EE54);
                else
                    fprintf(DVlogf, asc_584EE4);
                v26 += 4;
            }
            while( v26 < 256 );
            ++v2;
            ++v23;
        }
        while( v2 < v1->player_num );
    }
    v27 = ((int (*)(void))rge_base_game->vfptr->get_view_panel)();
    if( v27 )
        (*(void (**)(int, signed int))(*(_DWORD *)v27 + 32))(v27, 2);
    v28 = ((int (*)(void))rge_base_game->vfptr->get_map_panel)();
    if( v28 )
        (*(void (**)(int, signed int))(*(_DWORD *)v28 + 32))(v28, 2);
}
