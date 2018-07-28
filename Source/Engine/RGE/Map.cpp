
/**
 * @file    Engine\RGE\Map.cpp
 * @author  Yvan Burrie
 * @date    2018/07/05
 * @version 1.0
 */

RGE_Map::RGE_Map(
    int infile,
    RGE_Sound **sounds,
    bool setup)
{
    /* Normally, the entire RGE_Map structure is read to whatever its size. */

    rge_read(infile, &this->map, 4);

    rge_read(infile, &this->map_width, 4);
    rge_read(infile, &this->map_height, 4);

    for( int contour_id = 0; contour_id < RGE_MAP_CONTOURS_COUNT; contour_id++ ){
        rge_read(infile, &this->tilesizes[contour_id], sizeof(RGE_Tile_Size));
    }
    for( int terr_id = 0; terr_id < RGE_MAP_TERRAINS_COUNT; terr_id++ ){
        rge_read(infile, &this->terrain_types[terr_id], sizeof(RGE_Tile_Set));
    }
#if RGE_MAP_OVERLAY_TYPES_EXIST
    for( int over_id = 0; over_id < RGE_MAP_OVERLAYS_COUNT; over_id++ ){
        rge_read(infile, &this->overlay_types[over_id], sizeof(RGE_Overlay_Set));
    }
#endif
    for( int bord_id = 0; bord_id < RGE_MAP_BORDERS_COUNT; bord_id++ ){
        rge_read(infile, &this->border_types[bord_id], sizeof(RGE_Border_Set));
    }

    rge_read(infile, &this->map_row_offset, 4);

#if RGE_MAP_MIN_MAX_EXISTS // >= AOK_A
    rge_read(infile, &this->map_min_x, 4);
    rge_read(infile, &this->map_min_y, 4);
    rge_read(infile, &this->map_max_x, 4);
    rge_read(infile, &this->map_max_y, 4);
#endif
#if RGE_MAP_MAX_PLUS_ONE_EXISTS // >= AOK
    rge_read(infile, &this->map_max_x_plus_one, 4);
    rge_read(infile, &this->map_max_y_plus_one, 4);
#endif

    rge_read(infile, &this->num_terrain, 2);
#if RGE_MAP_OVERLAY_TYPES_EXIST
    rge_read(infile, &this->num_overlay, 2);
#endif
    rge_read(infile, &this->num_borders, 2);
    rge_read(infile, &this->max_terrain, 2);

    rge_read(infile, &this->tile_width, 2);
    rge_read(infile, &this->tile_height, 2);

    rge_read(infile, &this->tile_half_height, 2);
    rge_read(infile, &this->tile_half_width, 2);
    rge_read(infile, &this->elev_height, 2);

    rge_read(infile, &this->cur_row, 2);
    rge_read(infile, &this->cur_col, 2);

    rge_read(infile, &this->block_beg_row, 2);
    rge_read(infile, &this->block_end_row, 2);
    rge_read(infile, &this->block_beg_col, 2);
    rge_read(infile, &this->block_end_col, 2);

#if RGE_SEARCH_MAP_EXISTS
    rge_read(infile, &this->search_map, 4);
    rge_read(infile, &this->search_map_rows, 4);
#endif

    rge_read(infile, &this->any_frame_change, 1);
    rge_read(infile, &this->map_visible_flag, 1);
    rge_read(infile, &this->fog_flag, 1);

#if ENGINE_AOK
    rge_read(infile, &this->UMV_data_list_used, 1);
    rge_read(infile, &this->UMV_data_list_size, 4);
    rge_read(infile, &this->UMV_data_GUID, 4);
    rge_read(infile, &this->UMV_data_points, 4);
    rge_read(infile, &this->OB_manager, 4);
    rge_read(infile, &this->unk_1, 4);
#endif

    rge_read(infile, &this->random_map, 4);
    rge_read(infile, &this->game_world, 4);
    rge_read(infile, &this->map_zones, 4);
    rge_read(infile, &this->unified_vis_map, 4);
    rge_read(infile, &this->unit_manager, 4);

    this->game_world = rge_base_game->world;

    this->load_terrain_types(sounds);
    this->load_border_types(sounds);
    this->init_tile_sizes();

    if( setup ){
        this->data_load_random_map(infile);
    }
}

RGE_Map::RGE_Map(
    char *border_tbl,
    char *terrain_tbl,
    char *map_tbl,
    short TileWid,
    short TileHgt,
    short ElevHgt,
    RGE_Sound **sounds)
{
    this->game_world = rge_base_game->world;

    this->tile_width       = TileWid;
    this->tile_half_width  = TileWid / 2;
    this->tile_height      = TileHgt;
    this->tile_half_height = TileHgt / 2;
    this->elev_height      = ElevHgt;

    short delta_value = 100;

    this->set_tile_size(0x00, this->tile_width, this->tile_height, 0);
    this->set_tile_size(0x01, this->tile_width, this->elev_height, -delta_value);
    this->set_tile_size(0x02, this->tile_width, this->tile_height + this->elev_height, delta_value);
    this->set_tile_size(0x03, this->tile_width, this->tile_height, -delta_value);
    this->set_tile_size(0x04, this->tile_width, this->tile_height, -delta_value);
    this->set_tile_size(0x05, this->tile_width, this->elev_height, -delta_value);
    this->set_tile_size(0x06, this->tile_width, this->tile_height + this->elev_height, delta_value);
    this->set_tile_size(0x07, this->tile_width, this->elev_height, -delta_value);
    this->set_tile_size(0x08, this->tile_width, this->tile_height + this->elev_height, delta_value);
    this->set_tile_size(0x09, this->tile_width, this->elev_height, -delta_value);
    this->set_tile_size(0x0A, this->tile_width, this->tile_height + this->elev_height, delta_value);
    this->set_tile_size(0x0B, this->tile_width, this->tile_height, -delta_value);
    this->set_tile_size(0x0C, this->tile_width, this->tile_height, -delta_value);
    this->set_tile_size(0x0D, this->tile_width, this->elev_height, -delta_value);
    this->set_tile_size(0x0E, this->tile_width, this->tile_height + this->elev_height, delta_value);
    this->set_tile_size(0x0F, this->tile_width, this->tile_height, delta_value);
    this->set_tile_size(0x10, this->tile_width, this->tile_height, delta_value);
    this->set_tile_size(0x11, this->tile_half_width, this->tile_height, 0);
    this->set_tile_size(0x12, this->tile_half_width, this->tile_height, 0);

    this->num_terrain = 0;
    this->max_terrain = 0;

    this->fog_flag = 1;

    v9 = (int)&this->terrain_types[0].rows;
    v10 = 32;
    do
    {
        *(_WORD *)(v9 + 218) = 0;
        *(_WORD *)v9 = 0;
        *(_WORD *)(v9 + 2) = 0;
        v11 = (_WORD *)(v9 + 128);
        v12 = 30;
        do
        {
            *(v11 - 30) = 0;
            *v11 = 0;
            ++v11;
            --v12;
        }
        while( v12 );
        v13 = (void *)(v9 + 4);
        v9 += 408;
        memset(v13, 0, 0x40u);
        *(_DWORD *)(v9 - 562) = 0;
        *(_DWORD *)(v9 - 558) = 0;
        --v10;
    }
    while( v10 );
    v14 = &this->border_types[15].sound;
    v15 = 16;
    do
    {
        *(v14 - 1) = 0;
        *v14 = 0;
        v14 -= 360;
        --v15;
    }
    while( v15 );

    this->load_terrain_types(terrain_tbl, sounds);
    this->load_border_types(border_tbl, sounds);
}

RGE_Map::~RGE_Map()
{
    if( this->map_zones ){
        delete this->map_zones;
    }
    if( this->random_map ){
        delete this->random_map;
    }
    if( this->map ){
        free(this->map);
    }
    if( this->search_map ){
        free(this->search_map);
    }
    if( this->map_row_offset ){
        free(this->map_row_offset);
    }
    if( this->search_map_rows ){
        free(this->search_map_rows);
    }
    for( int terr_id = 0; terr_id < RGE_MAP_TERRAINS_COUNT; terr_id++ ){
        delete this->terrain_types[terr_id].shape;
    }
#if RGE_MAP_OVERLAY_TYPES_EXIST
    for( int over_id = 0; over_id < RGE_MAP_OVERLAYS_COUNT; over_id++ ){
        delete this->overlay_types[over_id].shape;
    }
#endif
    for( int bord_id = 0; bord_id < RGE_MAP_BORDERS_COUNT; bord_id++ ){
        delete this->border_types[bord_id].shape;
    }
    if( this->unified_vis_map ){
        delete this->unified_vis_map;
    }
    if( this->unit_manager ){
        delete this->unit_manager;
    }
}

void RGE_Map::init_tile_sizes()
{
    this->tile_width       = 64;
    this->tile_height      = 32;
    this->tile_half_width  = 32;
    this->tile_half_height = 16;
    this->elev_height      = 16;

    this->set_tile_size(0, 64, 32, 0);
    this->set_tile_size(1, v1->tile_width, v1->elev_height, -8);
    this->set_tile_size(2, v1->tile_width, v1->tile_height + v1->elev_height, 8);
    this->set_tile_size(3, v1->tile_width, v1->tile_height, -8);
    this->set_tile_size(4, v1->tile_width, v1->tile_height, -8);
    this->set_tile_size(5, v1->tile_width, v1->elev_height, -8);
    this->set_tile_size(6, v1->tile_width, v1->tile_height + v1->elev_height, 8);
    this->set_tile_size(7, v1->tile_width, v1->elev_height, -8);
    this->set_tile_size(8, v1->tile_width, v1->tile_height + v1->elev_height, 8);
    this->set_tile_size(9, v1->tile_width, v1->elev_height, -8);
    this->set_tile_size(10, v1->tile_width, v1->tile_height + v1->elev_height, 8);
    this->set_tile_size(11, v1->tile_width, v1->tile_height, -8);
    this->set_tile_size(12, v1->tile_width, v1->tile_height, -8);
    this->set_tile_size(13, v1->tile_width, v1->elev_height, -8);
    this->set_tile_size(14, v1->tile_width, v1->tile_height + v1->elev_height, 8);
    this->set_tile_size(15, v1->tile_width, v1->tile_height, 8);
    this->set_tile_size(16, v1->tile_width, v1->tile_height, 8);
    this->set_tile_size(17, v1->tile_half_width, v1->tile_height, 0);
    this->set_tile_size(18, v1->tile_half_width, v1->tile_height, 0);
}

void RGE_Map::data_load_random_map(int infile)
{
    this->random_map = new RGE_RMM_Database_Controller(infile);
}

void RGE_Map::set_map_visible(char flag)
{
    this->map_visible_flag = flag;
}

void RGE_Map::set_map_fog(char flag)
{
    this->fog_flag = flag;
}

void RGE_Map::clear_map(
    RGE_Player *player,
    RGE_Game_World *world,
    char new_terrain,
    int width,
    int height)
{
    this->new_map(width, height);

    if( world ){
        world->reset_object_count();
    }
    this->set_terrain(
        player,
        world,
        0,
        0,
        width - 1,
        height - 1,
        new_terrain,
        1,
        0);

    if( world ){
        world->reset_player_visible_maps();
    }
}

void RGE_Map::new_map(int width, int height)
{
    int v3; // edi@1
    RGE_Map *v4; // esi@1
    RGE_Game_World *v5; // eax@4
    int v6; // ebx@5
    int i; // edi@5
    RGE_Player **v8; // eax@6
    RGE_Player *v9; // eax@7
    int v10; // edx@18
    int v11; // eax@18
    RGE_Tile *v12; // eax@18
    size_t v13; // ST08_4@18
    char *v14; // eax@18
    size_t v15; // edx@18
    char **v16; // eax@18
    int v17; // ecx@18
    int v18; // eax@18
    int v19; // ebp@20
    int v20; // edi@21
    int v21; // ecx@22
    int v22; // eax@23
    RGE_Zone_Map_List *v23; // edi@25
    RGE_Zone_Map_List *v24; // eax@27
    RGE_Zone_Map_List *v25; // eax@28
    RGE_Unified_Visible_Map *v26; // edi@30
    RGE_Unified_Visible_Map *v27; // eax@32
    RGE_Unified_Visible_Map *v28; // eax@33
    Visible_Unit_Manager *v29; // edi@35
    Visible_Unit_Manager *v30; // eax@37
    Visible_Unit_Manager *v31; // eax@38

    v4 = this;

    if( width <= 0 || height <= 0 ){
        return;
    }
    if( this->map ){
        if( this->game_world ){
            for( int pid = 0; pid < this->game_world->player_num; pid++ ){
                if( this->game_world->players &&
                    this->game_world->players[pid] ){
                    this->game_world->players[pid]->objects->removeAllObjects();
                    this->game_world->players[pid]->sleeping_objects->removeAllObjects();
                    this->game_world->players[pid]->doppleganger_objects->removeAllObjects();
                }
            }
        }
        delete this->map;
    }

    if( this->search_map )
        free(v4->search_map);
    if( v4->map_row_offset )
        free(v4->map_row_offset);
    if( v4->search_map_rows )
        free(v4->search_map_rows);

    this->map_height = height;
    this->map_width  = width;

    this->world_width  = this->tile_width  * width;
    this->world_height = this->tile_height * height;

    this->map = new RGE_Tile[width * height];

    this->search_map = new char[width * height];

    v15 = v4->map_height + 1;
    v4->map_row_offset = (RGE_Tile **)calloc(v15, 4u);
    v16 = (char **)calloc(v4->map_height + 1, 4u);
    v17 = v4->map_height;
    v4->search_map_rows = v16;
    v18 = 0;
    if( v17 > 0 )
    {
        do
        {
            v4->map_row_offset[v18] = &v4->map[v4->map_width * v18];
            v4->search_map_rows[v18] = &v4->search_map[v4->map_width * v18];
            ++v18;
        }
        while( v18 < v4->map_height );
    }
    v19 = 0;
    v4->map_row_offset[v4->map_height] = v4->map;
    for( v4->search_map_rows[v4->map_height] = v4->search_map; v19 < v4->map_height; ++v19 )
    {
        v20 = 0;
        if( v4->map_width > 0 )
        {
            v21 = 0;
            do
            {
                v22 = (int)&v4->map_row_offset[v19][v21].screen_xpos;
                ++v21;
                ++v20;
                *(_BYTE *)(v22 + 5) = *(_BYTE *)(v22 + 5) & 0x1F | 0x20;
            }
            while( v20 < v4->map_width );
        }
    }
    RGE_Map::set_map_screen_pos(v4, 0, 0, v4->map_width - 1, v4->map_height - 1);
    v23 = v4->map_zones;
    if( v23 )
    {
        RGE_Zone_Map_List::~RGE_Zone_Map_List(v4->map_zones);
        operator delete(v23);
    }
    v24 = (RGE_Zone_Map_List *)operator new(0xCu);
    if( v24 )
        RGE_Zone_Map_List::RGE_Zone_Map_List(v24, v4);
    else
        v25 = 0;
    v26 = v4->unified_vis_map;
    v4->map_zones = v25;
    if( v26 )
    {
        RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map(v26);
        operator delete(v26);
    }
    v27 = (RGE_Unified_Visible_Map *)operator new(0xCu);
    if( v27 )
        RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(v27, width, height);
    else
        v28 = 0;
    v29 = v4->unit_manager;
    v4->unified_vis_map = v28;
    if( v29 )
    {
        Visible_Unit_Manager::~Visible_Unit_Manager(v29);
        operator delete(v29);
    }
    v30 = (Visible_Unit_Manager *)operator new(0x24u);
    if( v30 )
        Visible_Unit_Manager::Visible_Unit_Manager(v30, v4->game_world->player_num, 64);
    else
        v31 = 0;
    v4->unit_manager = v31;
}

void RGE_Map::clear_map(char terrain, char elev)
{
    int i; // ebp@1
    int v4; // esi@2
    char v6; // bl@3

    for( int i = 0; i < this->map_height; ++i ){
        v4 = 0;
        for( RGE_Tile *j = this->map_row_offset[i]; v4 < this->map_width; v4++ ){
            v6 = *((_BYTE *)j + 5);
            j->tile_type = 0;
            *((_BYTE *)j + 6) = 0;
            j->screen_xpos = 0;
            *((_BYTE *)j + 5) = 32 * elev | terrain & 0x1F;
            j->screen_ypos = 0;
            j->last_drawn_as = 0;
            j->last_drawn_shape = -1;
            j->draw_as = 0;
            j->draw_attribute = 0;
            j->last_drawn_shape2 = -1;
            ++j;
        }
    }

    this->set_map_screen_pos(
        0,
        0,
        this->map_width - 1,
        this->map_height - 1);
}

void RGE_Map::request_redraw(int x1, int y1, int x2, int y2, char attribute)
{
    int v6; // esi@1
    int v7; // edi@1
    RGE_Map *v8; // ebx@1
    int v9; // eax@3
    int v10; // ecx@3
    int v11; // edx@7
    int v12; // ebx@8
    int v13; // ebp@17
    char *v14; // eax@19
    int v15; // edx@19
    RGE_Map *v16; // [sp+10h] [bp-4h]@1

    v6 = x1;
    v7 = x2;
    v8 = this;
    v16 = this;
    if( x1 > x2 )
    {
        v6 = x2;
        v7 = x1;
    }
    v9 = y1;
    v10 = y2;
    if( y1 > y2 )
    {
        v9 = y2;
        y2 = y1;
        v10 = y1;
    }
    if( v7 >= 0 && v10 >= 0 )
    {
        v11 = v8->map_width;
        if( v6 < v11 )
        {
            v12 = v8->map_height;
            if( v9 < v12 )
            {
                if( v6 < 0 )
                    v6 = 0;
                if( v9 < 0 )
                    v9 = 0;
                if( v7 >= v11 )
                    v7 = v11 - 1;
                if( v10 >= v12 )
                {
                    y2 = v12 - 1;
                    v10 = v12 - 1;
                }
                v13 = v9;
                if( v9 <= v10 )
                {
                    do
                    {
                        if( v6 <= v7 )
                        {
                            v14 = &v16->map_row_offset[v13][v6].draw_attribute;
                            v15 = v7 - v6 + 1;
                            do
                            {
                                *(v14 - 3) = -52;
                                *v14 = attribute;
                                v14 += 24;
                                --v15;
                            }
                            while( v15 );
                        }
                        ++v13;
                    }
                    while( v13 <= y2 );
                }
            }
        }
    }
}

void RGE_Map::clear_map_view_info()
{
    int i; // esi@1
    int v2; // edx@2
    char *v3; // eax@3

    for( i = 0; i < this->map_height; ++i ){
        v2 = 0;
        if( this->map_width > 0 ){
            v3 = &this->map_row_offset[i]->last_drawn_shape;
            do{
                *(v3 - 1) = 0;
                *v3 = -1;
                v3[1] = 0;
                v3[2] = 0;
                v3[3] = -1;
                v3 += 24;
                ++v2;
            }
            while( v2 < this->map_width );
        }
    }
}

void RGE_Map::coordinate_map()
{
    this->set_map_screen_pos(
        0,
        0,
        this->map_width - 1,
        this->map_height - 1);
}

void RGE_Map::set_map_screen_pos(int x1, int y1, int x2, int y2)
{
    int v5; // esi@1
    int v6; // edi@6
    int v7; // ebx@10
    int v8; // edx@19
    char *v9; // eax@20
    int v10; // edx@21
    int y1a; // [sp+18h] [bp+8h]@19

    v5 = x1;
    if( x1 >= 0 )
    {
        if( x1 <= this->map_width - 1 )
            goto LABEL_6;
        x1 = this->map_width - 1;
    }
    else
    {
        x1 = 0;
    }
    v5 = x1;
LABEL_6:
    v6 = y1;
    if( y1 >= 0 )
    {
        if( y1 > this->map_height - 1 )
            v6 = this->map_height - 1;
    }
    else
    {
        v6 = 0;
    }
    v7 = x2;
    if( x2 >= 0 )
    {
        if( x2 > this->map_width - 1 )
            v7 = this->map_width - 1;
    }
    else
    {
        v7 = 0;
    }
    if( y2 >= 0 )
    {
        if( y2 > this->map_height - 1 )
            y2 = this->map_height - 1;
    }
    else
    {
        y2 = 0;
    }
    if( v6 <= y2 )
    {
        v8 = 24 * v5;
        y1a = 24 * v5;
        do
        {
            v9 = (char *)this->map_row_offset[v6] + v8;
            if( v5 <= v7 )
            {
                do
                {
                    *(_WORD *)v9 = this->tile_half_width * (v6 + v5);
                    v10 = (unsigned __int8)v9[4];
                    *((_WORD *)v9 + 1) = this->tile_half_height * (v6 - v5) - this->elev_height * ((unsigned __int8)v9[5] >> 5);
                    switch ( 0 )
                    {
                        case 2:
                        case 6:
                        case 8:
                        case 10:
                        case 14:
                        case 15:
                        case 16:
                            *((_WORD *)v9 + 1) -= this->elev_height;
                            break;
                        default:
                            break;
                    }
                    v9 += 24;
                    ++v5;
                }
                while( v5 <= v7 );
                v5 = x1;
                v8 = y1a;
            }
            ++v6;
        }
        while( v6 <= y2 );
    }
}

void RGE_Map::scenario_save(int outfile)
{
    RGE_Map *v2; // ebx@1
    int v3; // esi@1
    int *v4; // ebx@1
    int v5; // eax@1
    int v6; // ecx@1
    bool v7; // zf@1
    bool v8; // sf@1
    int v9; // edi@2
    int v10; // ebp@3
    int v11; // eax@3
    int v12; // eax@4
    RGE_Tile **v13; // edx@4
    unsigned __int8 v14; // of@6
    char height_info; // [sp+Ah] [bp-Ah]@4
    char overlay_info; // [sp+Bh] [bp-9h]@4
    int y; // [sp+Ch] [bp-8h]@1
    RGE_Map *v18; // [sp+10h] [bp-4h]@1

    v2 = this;
    v3 = outfile;
    v18 = this;
    rge_write(outfile, &this->map_width, 4);
    v4 = &v2->map_height;
    rge_write(v3, v4, 4);
    v5 = *v4;
    v6 = 0;
    v7 = *v4 == 0;
    v8 = *v4 < 0;
    y = 0;
    if( !v8 && !v7 )
    {
        do
        {
            v9 = 0;
            if( v5 > 0 )
            {
                v10 = (signed short)v6;
                v11 = 0;
                do
                {
                    v12 = v11;
                    v13 = v18->map_row_offset;
                    LOBYTE(outfile) = *((_BYTE *)&v13[v10][v12] + 5) & 0x1F;
                    height_info = *((_BYTE *)&v13[v10][v12] + 5) >> 5;
                    overlay_info = 0;
                    rge_write(v3, &outfile, 1);
                    rge_write(v3, &height_info, 1);
                    rge_write(v3, &overlay_info, 1);
                    v11 = (signed short)++v9;
                }
                while( (signed short)v9 < *v4 );
                v6 = y;
            }
            v5 = *v4;
            v14 = __OFSUB__((signed short)++v6, *v4);
            v8 = (signed short)v6 - *v4 < 0;
            y = v6;
        }
        while( v8 ^ v14 );
    }
}

void RGE_Map::scenario_load(int infile, char *zone_terrain)
{
    int v3; // ebp@1
    RGE_Map *v4; // edi@1
    int v5; // eax@1
    int v6; // ecx@1
    int v7; // esi@2
    int v8; // ebx@3
    _BYTE *v9; // eax@4
    int v10; // edx@7
    int v11; // eax@7
    char height_info; // [sp+Ah] [bp-12h]@4
    char overlay_info; // [sp+Bh] [bp-11h]@4
    int x; // [sp+Ch] [bp-10h]@2
    int y; // [sp+10h] [bp-Ch]@1
    int h; // [sp+14h] [bp-8h]@1
    int w; // [sp+18h] [bp-4h]@1

    v3 = infile;
    v4 = this;
    rge_read(infile, (int)this, infile, &w, 4);
    rge_read(v3, (int)v4, v3, &h, 4);
    RGE_Map::new_map(v4, w, h);
    v5 = v4->map_height;
    v6 = 0;
    y = 0;
    if( v5 > 0 )
    {
        do
        {
            v7 = 0;
            x = 0;
            if( v5 > 0 )
            {
                v8 = (signed short)v6;
                do
                {
                    rge_read(v3, (int)v4, v3, &infile, 1);
                    rge_read(v3, (int)v4, v3, &height_info, 1);
                    rge_read(v3, (int)v4, v3, &overlay_info, 1);
                    *((_BYTE *)&v4->map_row_offset[v8][v7] + 5) ^= (*((_BYTE *)&v4->map_row_offset[v8][v7] + 5) ^ infile) & 0x1F;
                    v9 = (char *)&v4->map_row_offset[v8][v7] + 5;
                    *v9 = *v9 & 0x1F | 32 * height_info;
                    v7 = (signed short)++x;
                }
                while( (signed short)x < v4->map_height );
                v6 = y;
            }
            v5 = v4->map_height;
            y = ++v6;
        }
        while( (signed short)v6 < v5 );
    }
    LOWORD(v5) = LOWORD(v4->map_height) - 1;
    LOWORD(v6) = LOWORD(v4->map_width) - 1;
    RGE_Map::set_elev(v4, 0, 0, v6, v5, 0, 0, 0);
    LOWORD(v10) = LOWORD(v4->map_height) - 1;
    LOWORD(v11) = LOWORD(v4->map_width) - 1;
    RGE_Map::set_terrain(v4, 0, 0, 0, 0, v11, v10, 0, 0, 0);
}

RGE_Tile **RGE_Map::give_up_map_offsets()
{
    return this->map_row_offset;
}

int RGE_Map::get_map_width()
{
    return this->map_width;
}

int RGE_Map::get_map_height()
{
    return this->map_height;
}

char RGE_Map::postclean_elevation(int x1, int y1, int x2, int y2, char elevation_height)
{
    int v7; // ebp@1
    short v8; // dx@1
    int v9; // eax@1
    int v10; // ebp@1
    int v11; // edx@3
    int v12; // edi@5
    int v13; // esi@7
    int v14; // ebx@9
    int v15; // edx@10
    char *v16; // esi@11
    signed short v17; // di@12
    char v18; // al@14
    int v19; // ebp@18
    int v20; // ebx@24
    int v21; // ebp@45
    int v22; // ebx@51
    char was_bad; // [sp+11h] [bp-23h]@1
    int index2; // [sp+14h] [bp-20h]@11
    int index1; // [sp+18h] [bp-1Ch]@9
    short v27; // [sp+1Ch] [bp-18h]@1
    RGE_Map *v28; // [sp+20h] [bp-14h]@1
    short offset1; // [sp+24h] [bp-10h]@1
    short offset3; // [sp+28h] [bp-Ch]@1
    short offset2; // [sp+2Ch] [bp-8h]@1
    int v32; // [sp+30h] [bp-4h]@10
    unsigned __int8 y1a; // [sp+3Ch] [bp+8h]@14

    LOWORD(a2) = this->map_width;
    offset1 = -1 - a2;
    v27 = this->map_width;
    v7 = a2;
    v8 = 1 - a2;
    v9 = x1;
    v10 = -v7;
    v28 = this;
    offset2 = v10;
    offset3 = v8;
    was_bad = 0;
    if( x1 > 0 )
        v9 = x1-- - 1;
    v11 = y1;
    if( y1 > 0 )
        v11 = y1 - 1;
    v12 = x2;
    if( x2 < this->map_width - 1 )
        v12 = x2++ + 1;
    v13 = y2;
    if( y2 < this->map_height - 1 )
        v13 = y2++ + 1;
    v14 = v11;
    index1 = v11;
    if( v11 > v13 )
        return was_bad;
    v15 = 24 * v9;
    v32 = 24 * v9;
    do
    {
        index2 = v9;
        v16 = (char *)this->map_row_offset[v14] + v15;
        if( v9 > v12 )
            goto LABEL_72;
        v17 = (unsigned __int8)elevation_height;
        while( 1 )
        {
            BYTE1(v15) = 0;
            y1a = v16[5];
            v18 = 0;
            LOBYTE(v15) = y1a >> 5;
            if( y1a >> 5 >= v17 )
            {
                if( (unsigned __int8)v15 > v17 )
                {
                    --v15;
                    if( v14 > 0 && (unsigned __int8)v16[24 * (signed short)v10 + 5] >> 5 < (signed short)v15 )
                        v18 = 1;
                    v21 = v28->map_height - 1;
                    if( v14 < v21 && (unsigned __int8)v16[24 * v27 + 5] >> 5 < (signed short)v15 )
                        v18 = 1;
                    if( index2 > 0 && (unsigned __int8)*(v16 - 19) >> 5 < (signed short)v15 )
                        v18 = 1;
                    v22 = v28->map_width - 1;
                    if( index2 < v22 && (unsigned __int8)v16[29] >> 5 < (signed short)v15 )
                        v18 = 1;
                    if( index1 > 0 )
                    {
                        if( index2 > 0 && (unsigned __int8)v16[24 * offset1 + 5] >> 5 < (signed short)v15 )
                            v18 = 1;
                        if( index2 < v22 && (unsigned __int8)v16[24 * offset3 + 5] >> 5 < (signed short)v15 )
                            v18 = 1;
                    }
                    if( index1 < v21 )
                    {
                        if( index2 > 0 && (unsigned __int8)v16[24 * (signed short)(v27 - 1) + 5] >> 5 < (signed short)v15 )
                            v18 = 1;
                        if( index2 < v22 && (unsigned __int8)v16[24 * (signed short)(v27 + 1) + 5] >> 5 < (signed short)v15 )
                        {
LABEL_67:
                            v18 = 1;
                            goto LABEL_68;
                        }
                    }
                }
            }
            else
            {
                ++v15;
                if( v14 > 0 && (unsigned __int8)v16[24 * (signed short)v10 + 5] >> 5 > (signed short)v15 )
                    v18 = 1;
                v19 = v28->map_height - 1;
                if( v14 < v19 && (unsigned __int8)v16[24 * v27 + 5] >> 5 > (signed short)v15 )
                    v18 = 1;
                if( index2 > 0 && (unsigned __int8)*(v16 - 19) >> 5 > (signed short)v15 )
                    v18 = 1;
                v20 = v28->map_width - 1;
                if( index2 < v20 && (unsigned __int8)v16[29] >> 5 > (signed short)v15 )
                    v18 = 1;
                if( index1 > 0 )
                {
                    if( index2 > 0 && (unsigned __int8)v16[24 * offset1 + 5] >> 5 > (signed short)v15 )
                        v18 = 1;
                    if( index2 < v20 && (unsigned __int8)v16[24 * offset3 + 5] >> 5 > (signed short)v15 )
                        v18 = 1;
                }
                if( index1 < v19 )
                {
                    if( index2 > 0 && (unsigned __int8)v16[24 * (signed short)(v27 - 1) + 5] >> 5 > (signed short)v15 )
                        v18 = 1;
                    if( index2 < v20 && (unsigned __int8)v16[24 * (signed short)(v27 + 1) + 5] >> 5 > (signed short)v15 )
                        goto LABEL_67;
                }
            }
LABEL_68:
            if( v18 )
            {
                was_bad = 1;
                v16[5] = y1a & 0x1F | 32 * v15;
            }
            v12 = x2;
            v16 += 24;
            if( ++index2 > x2 )
                break;
            v17 = (unsigned __int8)elevation_height;
            LOWORD(v10) = offset2;
            v14 = index1;
        }
        v15 = v32;
        LOWORD(v10) = offset2;
        v14 = index1;
        v9 = x1;
        this = v28;
LABEL_72:
        index1 = ++v14;
    }
    while( v14 <= y2 );
    return was_bad;
}

void RGE_Map::preclean_elevation(int x1, int y1, int x2, int y2, char elevation_height)
{
    RGE_Map *v7; // esi@1
    int v8; // eax@1
    int v9; // ecx@1
    int v10; // ebp@4
    int v11; // edx@8
    int v12; // esi@11
    signed short v13; // cx@14
    signed short v14; // ax@14
    int v15; // ebp@17
    int v16; // edi@23
    char v17; // dl@40
    char change_flag; // [sp+13h] [bp-45h]@2
    int index2; // [sp+14h] [bp-44h]@11
    int index1; // [sp+18h] [bp-40h]@10
    RGE_Map *v21; // [sp+1Ch] [bp-3Ch]@1
    signed short place4; // [sp+20h] [bp-38h]@14
    signed short place6; // [sp+24h] [bp-34h]@14
    signed short place8; // [sp+28h] [bp-30h]@14
    signed short place1; // [sp+2Ch] [bp-2Ch]@14
    short offset1; // [sp+30h] [bp-28h]@1
    int offset2; // [sp+34h] [bp-24h]@1
    signed short place3; // [sp+38h] [bp-20h]@14
    short offset3; // [sp+3Ch] [bp-1Ch]@1
    signed short place5; // [sp+40h] [bp-18h]@14
    short offset5; // [sp+44h] [bp-14h]@1
    short v32; // [sp+48h] [bp-10h]@1
    signed short place7; // [sp+4Ch] [bp-Ch]@14
    short offset7; // [sp+50h] [bp-8h]@1
    int v35; // [sp+54h] [bp-4h]@1

    v7 = this;
    LOWORD(a2) = this->map_width;
    v21 = this;
    v32 = a2;
    offset1 = -1 - a2;
    offset2 = -a2;
    offset3 = 1 - a2;
    offset5 = a2 + 1;
    offset7 = a2 - 1;
    v8 = x1;
    v9 = 24 * x1;
    v35 = 24 * x1;
    do
    {
        change_flag = 0;
        if( v8 > 0 )
        {
            --v8;
            v9 -= 24;
            x1 = v8;
            v35 = v9;
        }
        v10 = y1;
        if( y1 > 0 )
            v10 = y1-- - 1;
        if( x2 < v7->map_width - 1 )
            ++x2;
        v11 = y2;
        if( y2 < v7->map_height - 1 )
            v11 = y2++ + 1;
        for( index1 = v10; v10 <= v11; index1 = v10 )
        {
            index2 = v8;
            v12 = (int)&v7->map_row_offset[v10]->screen_xpos + v9;
            if( v8 <= x2 )
            {
                while( 1 )
                {
                    v13 = 0;
                    place1 = 0;
                    place3 = 0;
                    place4 = 0;
                    place5 = 0;
                    place6 = 0;
                    place7 = 0;
                    place8 = 0;
                    v14 = (unsigned __int8)(*(_BYTE *)(v12 + 5) >> 5);
                    if( v10 > 0 && (unsigned __int8)(*(_BYTE *)(v12 + 24 * (signed short)offset2 + 5) >> 5) > v14 )
                        v13 = 1;
                    v15 = v21->map_height - 1;
                    if( index1 < v15 && (unsigned __int8)(*(_BYTE *)(v12 + 24 * v32 + 5) >> 5) > v14 )
                        place6 = 1;
                    if( index2 > 0 && (unsigned __int8)(*(_BYTE *)(v12 - 19) >> 5) > v14 )
                        place8 = 1;
                    v16 = v21->map_width - 1;
                    if( index2 < v16 && (unsigned __int8)(*(_BYTE *)(v12 + 29) >> 5) > v14 )
                        place4 = 1;
                    if( index1 > 0 )
                    {
                        if( index2 > 0 && (unsigned __int8)(*(_BYTE *)(v12 + 24 * offset1 + 5) >> 5) > v14 )
                            place1 = 1;
                        if( index2 < v16 && (unsigned __int8)(*(_BYTE *)(v12 + 24 * offset3 + 5) >> 5) > v14 )
                            place3 = 1;
                    }
                    if( index1 < v15 )
                    {
                        if( index2 > 0 && (unsigned __int8)(*(_BYTE *)(v12 + 24 * offset7 + 5) >> 5) > v14 )
                            place7 = 1;
                        if( index2 < v16 && (unsigned __int8)(*(_BYTE *)(v12 + 24 * offset5 + 5) >> 5) > v14 )
                            place5 = 1;
                    }
                    v17 = 0;
                    if( v13 && place6 )
                        v17 = 1;
                    if( place4 && place8 )
                        v17 = 1;
                    if( v17 )
                    {
                        if( v14 < (unsigned __int8)elevation_height )
                        {
                            *(_BYTE *)(v12 + 5) = *(_BYTE *)(v12 + 5) & 0x1F ^ 32 * (v14 + 1);
                        }
                        else
                        {
                            if( place1 )
                                *(_BYTE *)(v12 + 24 * offset1 + 5) = *(_BYTE *)(v12 + 24 * offset1 + 5) & 0x1F | 32 * v14;
                            if( v13 )
                                *(_BYTE *)(v12 + 24 * (signed short)offset2 + 5) = *(_BYTE *)(v12 + 24 * (signed short)offset2 + 5) & 0x1F | 32 * v14;
                            if( place3 )
                                *(_BYTE *)(v12 + 24 * offset3 + 5) = *(_BYTE *)(v12 + 24 * offset3 + 5) & 0x1F | 32 * v14;
                            if( place4 )
                                *(_BYTE *)(v12 + 29) = *(_BYTE *)(v12 + 29) & 0x1F | 32 * v14;
                            if( place5 )
                                *(_BYTE *)(v12 + 24 * offset5 + 5) = *(_BYTE *)(v12 + 24 * offset5 + 5) & 0x1F | 32 * v14;
                            if( place6 )
                                *(_BYTE *)(v12 + 24 * v32 + 5) = *(_BYTE *)(v12 + 24 * v32 + 5) & 0x1F | 32 * v14;
                            if( place7 )
                                *(_BYTE *)(v12 + 24 * offset7 + 5) = *(_BYTE *)(v12 + 24 * offset7 + 5) & 0x1F | 32 * v14;
                            if( place8 )
                                *(_BYTE *)(v12 - 19) = *(_BYTE *)(v12 - 19) & 0x1F | 32 * v14;
                        }
                        change_flag = 1;
                    }
                    v12 += 24;
                    if( ++index2 > x2 )
                        break;
                    v10 = index1;
                }
                v11 = y2;
                v8 = x1;
                v9 = v35;
                v10 = index1;
            }
            v7 = v21;
            ++v10;
        }
    }
    while( change_flag );
}

void RGE_Map::clean_elevation(int x1, int y1, int x2, int y2, int elevation_height)
{
    int v7; // edi@1
    int v8; // esi@3
    int v9; // eax@5
    int v10; // ebx@5
    int v11; // eax@7
    int v12; // ebp@7
    int v13; // eax@14
    int v14; // eax@16
    int v15; // eax@19
    int v16; // esi@21
    signed short v17; // bp@22
    signed short v18; // ax@22
    int v19; // edi@25
    int v20; // edx@31
    char v21; // cl@48
    signed short v22; // dx@51
    char change_flag; // [sp+13h] [bp-45h]@10
    signed short place2; // [sp+14h] [bp-44h]@22
    signed short place5; // [sp+18h] [bp-40h]@22
    signed short place6; // [sp+1Ch] [bp-3Ch]@22
    signed short place7; // [sp+20h] [bp-38h]@22
    signed short place8; // [sp+24h] [bp-34h]@22
    int index2; // [sp+28h] [bp-30h]@21
    signed short place3; // [sp+2Ch] [bp-2Ch]@22
    signed short place4; // [sp+30h] [bp-28h]@22
    int index1; // [sp+34h] [bp-24h]@18
    RGE_Map *v33; // [sp+38h] [bp-20h]@1
    short offset1; // [sp+3Ch] [bp-1Ch]@1
    int offset2; // [sp+40h] [bp-18h]@1
    short offset3; // [sp+44h] [bp-14h]@1
    short offset5; // [sp+48h] [bp-10h]@1
    short v38; // [sp+4Ch] [bp-Ch]@1
    short offset7; // [sp+50h] [bp-8h]@1
    int i; // [sp+54h] [bp-4h]@19
    int x1a; // [sp+5Ch] [bp+4h]@10
    int y1a; // [sp+60h] [bp+8h]@10
    int x2a; // [sp+64h] [bp+Ch]@10
    int y2a; // [sp+68h] [bp+10h]@10

    LOWORD(a2) = this->map_width;
    offset1 = -1 - a2;
    offset2 = -a2;
    v7 = x1;
    offset3 = 1 - a2;
    v38 = this->map_width;
    v33 = this;
    offset5 = a2 + 1;
    offset7 = a2 - 1;
    if( x1 < 0 )
        v7 = 0;
    v8 = y1;
    if( y1 < 0 )
        v8 = 0;
    v9 = this->map_width;
    v10 = x2;
    if( x2 >= this->map_width )
        v10 = this->map_width - 1;
    v11 = this->map_height;
    v12 = y2;
    if( y2 >= this->map_height )
        v12 = this->map_height - 1;
    while( 1 )
    {
        v7 -= 2;
        v8 -= 2;
        v10 += 2;
        v12 += 2;
        change_flag = 0;
        x1a = v7;
        y1a = v8;
        x2a = v10;
        y2a = v12;
        if( v7 < 0 )
        {
            v7 = 0;
            x1a = 0;
        }
        if( v8 < 0 )
        {
            v8 = 0;
            y1a = 0;
        }
        v13 = this->map_width;
        if( v10 >= this->map_width )
        {
            v10 = v13 - 1;
            x2a = v13 - 1;
        }
        v14 = this->map_height;
        if( v12 >= v14 )
        {
            v12 = v14 - 1;
            y2a = v14 - 1;
        }
        this->preclean_elevation(elevation_height, v7, v8, v10, v12, elevation_height);
        index1 = v8;
        if( v8 <= v12 )
        {
            v15 = 24 * v7;
            for( i = 24 * v7; ; v15 = i )
            {
                index2 = v7;
                v16 = (int)&this->map_row_offset[index1]->screen_xpos + v15;
                if( v7 <= v10 )
                {
                    do
                    {
                        v17 = 0;
                        place2 = 0;
                        place3 = 0;
                        place4 = 0;
                        place5 = 0;
                        place6 = 0;
                        place7 = 0;
                        place8 = 0;
                        v18 = (unsigned __int8)(*(_BYTE *)(v16 + 5) >> 5);
                        if( index1 > 0 && (unsigned __int8)(*(_BYTE *)(v16 + 24 * (signed short)offset2 + 5) >> 5) > v18 )
                            place2 = 1;
                        v19 = v33->map_height - 1;
                        if( index1 < v19 && (unsigned __int8)(*(_BYTE *)(v16 + 24 * v38 + 5) >> 5) > v18 )
                            place6 = 1;
                        if( index2 > 0 && (unsigned __int8)(*(_BYTE *)(v16 - 19) >> 5) > v18 )
                            place8 = 1;
                        v20 = v33->map_width - 1;
                        if( index2 < v20 && (unsigned __int8)(*(_BYTE *)(v16 + 29) >> 5) > v18 )
                            place4 = 1;
                        if( index1 > 0 )
                        {
                            if( index2 > 0 && (unsigned __int8)(*(_BYTE *)(v16 + 24 * offset1 + 5) >> 5) > v18 )
                                v17 = 1;
                            if( index2 < v20 && (unsigned __int8)(*(_BYTE *)(v16 + 24 * offset3 + 5) >> 5) > v18 )
                                place3 = 1;
                        }
                        if( index1 < v19 )
                        {
                            if( index2 > 0 && (unsigned __int8)(*(_BYTE *)(v16 + 24 * offset7 + 5) >> 5) > v18 )
                                place7 = 1;
                            if( index2 < v20 && (unsigned __int8)(*(_BYTE *)(v16 + 24 * offset5 + 5) >> 5) > v18 )
                                place5 = 1;
                        }
                        v21 = 0;
                        if( v17 )
                        {
                            if( place3 && !place2 )
                            {
                                v22 = place4;
LABEL_62:
                                v21 = 1;
                                goto LABEL_64;
                            }
                            v22 = place4;
                            if( place4 && !place3 || place7 && !place8 || place6 && !place7 )
                                goto LABEL_62;
                            if( place5 && !place6 && !place4 )
                                v21 = 1;
                        }
                        else
                        {
                            v22 = place4;
                        }
LABEL_64:
                        if( place3
                            && !v21
                            && (place5 && !v22 || place6 && !place5
                                                                 || v17 && !place2
                                                                 || place8 && !v17
                                                                 || place7 && !place8 && !place6) )
                        {
                            v21 = 1;
                        }
                        if( place5
                            && !v21
                            && (place7 && !place6
                             || place8 && !place7
                             || place3 && !v22
                             || place2 && !place3
                             || v17 && !place2 && !place8) )
                        {
                            v21 = 1;
                        }
                        if( place7 )
                        {
                            if( v21 )
                                goto LABEL_107;
                            if( v17 && !place8 || place2 && !v17 || place5 && !place6 || v22 && !place5 || place3 && !v22 && !place2 )
                                v21 = 1;
                        }
                        if( v21 )
                        {
LABEL_107:
                            if( v18 < (unsigned __int8)elevation_height )
                            {
                                *(_BYTE *)(v16 + 5) = *(_BYTE *)(v16 + 5) & 0x1F ^ 32 * (v18 + 1);
                            }
                            else
                            {
                                if( v17 )
                                {
                                    v22 = place4;
                                    *(_BYTE *)(v16 + 24 * offset1 + 5) = *(_BYTE *)(v16 + 24 * offset1 + 5) & 0x1F | 32 * v18;
                                }
                                if( place2 )
                                {
                                    *(_BYTE *)(v16 + 24 * (signed short)offset2 + 5) = *(_BYTE *)(v16 + 24 * (signed short)offset2 + 5) & 0x1F | 32 * v18;
                                    v22 = place4;
                                }
                                if( place3 )
                                {
                                    v22 = place4;
                                    *(_BYTE *)(v16 + 24 * offset3 + 5) = *(_BYTE *)(v16 + 24 * offset3 + 5) & 0x1F | 32 * v18;
                                }
                                if( v22 )
                                    *(_BYTE *)(v16 + 29) = *(_BYTE *)(v16 + 29) & 0x1F | 32 * v18;
                                if( place5 )
                                    *(_BYTE *)(v16 + 24 * offset5 + 5) = *(_BYTE *)(v16 + 24 * offset5 + 5) & 0x1F | 32 * v18;
                                if( place6 )
                                    *(_BYTE *)(v16 + 24 * v38 + 5) = *(_BYTE *)(v16 + 24 * v38 + 5) & 0x1F | 32 * v18;
                                if( place7 )
                                    *(_BYTE *)(v16 + 24 * offset7 + 5) = *(_BYTE *)(v16 + 24 * offset7 + 5) & 0x1F | 32 * v18;
                                if( place8 )
                                    *(_BYTE *)(v16 - 19) = *(_BYTE *)(v16 - 19) & 0x1F | 32 * v18;
                            }
                            change_flag = 1;
                        }
                        v16 += 24;
                        ++index2;
                    }
                    while( index2 <= x2a );
                }
                if( ++index1 > y2a )
                    break;
                v7 = x1a;
                v10 = x2a;
            }
            v7 = x1a;
            v8 = y1a;
            v10 = x2a;
            v12 = y2a;
        }
        if( RGE_Map::postclean_elevation(v33, elevation_height, v7, v8, v10, v12, elevation_height) )
            change_flag = 1;
        if( !change_flag )
            break;
        this = v33;
    }
    RGE_Map::set_elev(v33, v7, v8, v10, v12, 0, 0, 0);
}

void RGE_Map::clean_terrain(int x1, int y1, int x2, int y2, char replacement_terrain)
{
    RGE_Map *v7; // ebp@1
    int v8; // edx@1
    int v9; // eax@5
    int v10; // eax@7
    int v11; // ecx@7
    char v12; // bl@9
    int v13; // eax@12
    int v14; // esi@20
    int v15; // edi@21
    signed short v16; // dx@23
    signed short v17; // bp@23
    int v18; // esi@26
    int v19; // ecx@32
    char v20; // al@50
    signed short v21; // cx@65
    bool v22; // sf@119
    unsigned __int8 v23; // of@119
    int index2; // [sp+10h] [bp-44h]@21
    signed short place2; // [sp+14h] [bp-40h]@23
    signed short place4; // [sp+18h] [bp-3Ch]@23
    int index1; // [sp+1Ch] [bp-38h]@19
    signed short place5; // [sp+20h] [bp-34h]@23
    signed short place1; // [sp+24h] [bp-30h]@23
    signed short place6; // [sp+28h] [bp-2Ch]@23
    signed short place3; // [sp+2Ch] [bp-28h]@23
    RGE_Map *v32; // [sp+30h] [bp-24h]@1
    int pass_index; // [sp+34h] [bp-20h]@18
    int offset2; // [sp+38h] [bp-1Ch]@1
    short v35; // [sp+3Ch] [bp-18h]@1
    short offset1; // [sp+40h] [bp-14h]@1
    short offset3; // [sp+44h] [bp-10h]@1
    short offset7; // [sp+48h] [bp-Ch]@1
    short offset5; // [sp+4Ch] [bp-8h]@1
    int v40; // [sp+50h] [bp-4h]@20
    char replacement_terraina; // [sp+68h] [bp+14h]@10

    v7 = this;
    v8 = x1;
    LOWORD(a2) = this->map_width;
    v35 = a2;
    offset1 = -1 - a2;
    offset2 = -a2;
    v32 = this;
    offset3 = 1 - a2;
    offset5 = a2 + 1;
    offset7 = a2 - 1;
    if( x1 < 0 )
    {
        v8 = 0;
        x1 = 0;
    }
    if( y1 < 0 )
        y1 = 0;
    v9 = this->map_width;
    if( x2 >= v9 )
        x2 = v9 - 1;
    v10 = this->map_height;
    v11 = y2;
    if( y2 >= v10 )
    {
        v11 = v10 - 1;
        y2 = v10 - 1;
    }
    v12 = replacement_terrain;
    do
    {
        replacement_terraina = 0;
        if( v8 > 0 )
            x1 = --v8;
        v13 = y1;
        if( y1 > 0 )
            v13 = y1-- - 1;
        if( x2 < v7->map_width - 1 )
            ++x2;
        if( v11 < v7->map_height - 1 )
            y2 = ++v11;
        pass_index = 0;
        do
        {
            index1 = v13;
            if( v13 > v11 )
                goto LABEL_119;
            v14 = 24 * v8;
            v40 = 24 * v8;
            do
            {
                index2 = v8;
                v15 = (int)&v7->map_row_offset[v13]->screen_xpos + v14;
                if( v8 > x2 )
                    goto LABEL_117;
                do
                {
                    if( (*(_BYTE *)(v15 + 5) & 0x1F) == v12 )
                        goto LABEL_115;
                    v16 = 0;
                    v17 = 0;
                    place1 = 0;
                    place2 = 0;
                    place3 = 0;
                    place4 = 0;
                    place5 = 0;
                    place6 = 0;
                    if( index1 > 0 && (*(_BYTE *)(v15 + 24 * (signed short)offset2 + 5) & 0x1F) == v12 )
                        place2 = 1;
                    v18 = v32->map_height - 1;
                    if( index1 < v18 && (*(_BYTE *)(v15 + 24 * v35 + 5) & 0x1F) == v12 )
                        place6 = 1;
                    if( index2 > 0 && (*(_BYTE *)(v15 - 19) & 0x1F) == v12 )
                        v16 = 1;
                    v19 = v32->map_width - 1;
                    if( index2 < v19 && (*(_BYTE *)(v15 + 29) & 0x1F) == v12 )
                        place4 = 1;
                    if( pass_index == 1 )
                    {
                        if( index1 > 0 )
                        {
                            if( index2 > 0 && (*(_BYTE *)(v15 + 24 * offset1 + 5) & 0x1F) == v12 )
                                place1 = 1;
                            if( index2 < v19 && (*(_BYTE *)(v15 + 24 * offset3 + 5) & 0x1F) == v12 )
                                place3 = 1;
                        }
                        if( index1 < v18 )
                        {
                            if( index2 > 0 && (*(_BYTE *)(v15 + 24 * offset7 + 5) & 0x1F) == v12 )
                                v17 = 1;
                            if( index2 < v19 && (*(_BYTE *)(v15 + 24 * offset5 + 5) & 0x1F) == v12 )
                                place5 = 1;
                        }
                    }
                    v20 = 0;
                    if( !pass_index )
                    {
                        if( place2 && place6 || place4 && v16 )
                            goto LABEL_112;
                        goto LABEL_113;
                    }
                    if( place1 )
                    {
                        if( place3 && !place2 || place4 && !place3 || v17 && !v16 || place6 && !v17 )
                        {
                            v21 = place5;
                            v20 = 1;
                        }
                        else
                        {
                            v21 = place5;
                            if( place5 && !place6 && !place4 )
                                v20 = 1;
                        }
                    }
                    else
                    {
                        v21 = place5;
                    }
                    if( place3
                        && !v20
                        && (place1 && !place2 || v16 && !place1 || v21 && !place4 || place6 && !v21 || v17 && !v16 && !place6) )
                    {
                        v20 = 1;
                    }
                    if( v21
                        && !v20
                        && (place3 && !place4 || place2 && !place3 || v17 && !place6 || v16 && !v17 || place1 && !v16 && !place2) )
                    {
                        v20 = 1;
                    }
                    if( !v17 )
                        goto LABEL_113;
                    if( !v20 )
                    {
                        if( place1 && !v16 || place2 && !place1 || v21 && !place6 || place4 && !v21 || place3 && !place4 && !place2 )
LABEL_112:
                            v20 = 1;
LABEL_113:
                        if( !v20 )
                            goto LABEL_115;
                    }
                    RGE_Map::set_terrain(v32, v32->game_world, index2, index1, v12, 0, 0);
                    replacement_terraina = 1;
LABEL_115:
                    v15 += 24;
                    ++index2;
                }
                while( index2 <= x2 );
                v8 = x1;
                v11 = y2;
                v7 = v32;
                v13 = index1;
                v14 = v40;
LABEL_117:
                index1 = ++v13;
            }
            while( v13 <= v11 );
            v13 = y1;
LABEL_119:
            v23 = __OFSUB__(pass_index + 1, 2);
            v22 = pass_index++ - 1 < 0;
        }
        while( v22 ^ v23 );
    }
    while( replacement_terraina );
}

int RGE_Map::clean_border_tile(int this_terrain, int other_terrain, int (*matrix)[32])
{
    return -1;
}

char RGE_Map::do_terrain_brush(int x, int y, int brush_size, char terrain_id)
{
    RGE_Map *v5; // edi@1
    int v6; // ebx@1
    int v7; // esi@1
    int v8; // ebp@1
    int v9; // eax@1
    bool v10; // sf@1
    int v11; // ecx@3
    int v12; // ecx@7
    int xa; // [sp+14h] [bp+4h]@1
    int brush_sizea; // [sp+1Ch] [bp+Ch]@1

    v5 = this;
    v6 = brush_size + x;
    v7 = x - brush_size;
    v8 = y - brush_size;
    v9 = y + brush_size;
    v10 = x - brush_size < 0;
    xa = x - brush_size;
    brush_sizea = y + brush_size;
    if( v10 )
    {
        xa = 0;
        v7 = 0;
    }
    v11 = this->map_width;
    if( v6 >= v11 )
        v6 = v11 - 1;
    if( v8 < 0 )
        v8 = 0;
    v12 = v5->map_height;
    if( v9 >= v12 )
    {
        brush_sizea = v12 - 1;
        v9 = v12 - 1;
    }
    for( ; v8 <= v9; ++v8 )
    {
        if( v7 <= v6 )
        {
            do
                RGE_Map::set_terrain(v5, v5->game_world, v7++, v8, terrain_id, 0, 0);
            while( v7 <= v6 );
            v7 = xa;
            v9 = brush_sizea;
        }
    }
    return 1;
}

char RGE_Map::do_terrain_brush_stroke(int x1, int y1, int x2, int y2, int brush_size, int terrain_id)
{
    RGE_Map *v7; // esi@1
    int v8; // eax@3
    int v9; // eax@7
    double v10; // st7@9
    double v11; // st6@9
    double v12; // st5@9
    double v13; // st7@9
    char (*v14)(RGE_Map *, int, int, int, char); // edi@9
    int index; // [sp+20h] [bp-24h]@9
    double x; // [sp+24h] [bp-20h]@9
    double y; // [sp+2Ch] [bp-18h]@9
    int brush_sizea; // [sp+5Ch] [bp+18h]@1

    v7 = this;
    brush_sizea = brush_size >> 1;
    if( x1 < 0 )
        x1 = 0;
    v8 = this->map_width;
    if( x2 >= v8 )
        x2 = v8 - 1;
    if( y1 < 0 )
        y1 = 0;
    v9 = this->map_height;
    if( y2 >= v9 )
        y2 = v9 - 1;
    v10 = (double)(x2 - x1);
    v11 = (double)(y2 - y1);
    index = (signed __int64)sqrt(v10 * v10 + v11 * v11);
    v12 = v10;
    v13 = (double)index;
    v14 = this->vfptr->do_terrain_brush;
    x = (double)x1;
    y = (double)y1;
    v14(this, x1, y1, brush_sizea, terrain_id);
    if( index > 0 )
    {
        do
        {
            x = x + v12 / v13;
            y = y + v11 / v13;
            ((void (__fastcall *)(RGE_Map *, _DWORD, _DWORD, _DWORD, int, int))v14)(
                v7,
                (unsigned __int64)(signed __int64)x >> 32,
                (signed __int64)x,
                (signed __int64)y,
                brush_sizea,
                terrain_id);
            --index;
        }
        while( index );
    }
    if( (double)x2 != x || (double)y2 != y )
        v14(v7, x2, y2, brush_sizea, terrain_id);
    return 1;
}

char RGE_Map::do_elevation_brush(int x, int y, int brush_size, char elevation_height)
{
    int v5; // edi@1
    int v6; // ebp@1
    int v7; // edx@1
    int v8; // eax@1
    bool v9; // sf@1
    int v10; // esi@3
    int v11; // esi@7
    int v12; // esi@11
    int v13; // edi@11
    RGE_Tile *v14; // eax@12
    char v15; // bl@12
    int v16; // eax@12
    int x2; // [sp+10h] [bp-4h]@1
    int xa; // [sp+18h] [bp+4h]@9
    int brush_sizea; // [sp+20h] [bp+Ch]@1

    v5 = brush_size + x;
    v6 = x - brush_size;
    v7 = y - brush_size;
    v8 = y + brush_size;
    x2 = brush_size + x;
    v9 = x - brush_size < 0;
    brush_sizea = y + brush_size;
    if( v9 )
        v6 = 0;
    v10 = this->map_width;
    if( v5 >= v10 )
    {
        v5 = v10 - 1;
        x2 = v10 - 1;
    }
    if( v7 < 0 )
        v7 = 0;
    v11 = this->map_height;
    if( v8 >= v11 )
    {
        v8 = v11 - 1;
        brush_sizea = v11 - 1;
    }
    for( xa = v7; xa <= v8; ++xa )
    {
        if( v6 <= v5 )
        {
            v12 = v6;
            v13 = v5 - v6 + 1;
            do
            {
                v14 = this->map_row_offset[xa];
                v15 = *((_BYTE *)&v14[v12] + 5);
                v16 = (int)&v14[v12].screen_xpos;
                ++v12;
                --v13;
                *(_BYTE *)(v16 + 5) = 32 * elevation_height | v15 & 0x1F;
            }
            while( v13 );
            v8 = brush_sizea;
            v5 = x2;
        }
    }
    return 1;
}

char RGE_Map::do_elevation_brush_stroke(int x1, int y1, int x2, int y2, int brush_size, int elevation_height)
{
    RGE_Map *v7; // edi@1
    int v8; // esi@1
    int v9; // eax@3
    int v10; // eax@7
    double v11; // st7@9
    double v12; // st6@9
    double v13; // st5@9
    double v14; // st7@9
    char (*v15)(RGE_Map *, int, int, int, char); // ebx@9
    int v16; // edx@15
    int v17; // ebx@15
    int v18; // eax@18
    int v19; // ecx@18
    int index; // [sp+20h] [bp-24h]@9
    double x; // [sp+24h] [bp-20h]@9
    double y; // [sp+2Ch] [bp-18h]@9

    v7 = this;
    v8 = brush_size >> 1;
    if( x1 < 0 )
        x1 = 0;
    v9 = this->map_width;
    if( x2 >= v9 )
        x2 = v9 - 1;
    if( y1 < 0 )
        y1 = 0;
    v10 = this->map_height;
    if( y2 >= v10 )
        y2 = v10 - 1;
    v11 = (double)(x2 - x1);
    v12 = (double)(y2 - y1);
    index = (signed __int64)sqrt(v11 * v11 + v12 * v12);
    v13 = v11;
    v14 = (double)index;
    v15 = this->vfptr->do_elevation_brush;
    x = (double)x1;
    y = (double)y1;
    v15(this, x1, y1, brush_size >> 1, elevation_height);
    if( index > 0 )
    {
        do
        {
            x = x + v13 / v14;
            y = y + v12 / v14;
            ((void (__fastcall *)(RGE_Map *, _DWORD, _DWORD, _DWORD, int, int))v15)(
                v7,
                (unsigned __int64)(signed __int64)x >> 32,
                (signed __int64)x,
                (signed __int64)y,
                v8,
                elevation_height);
            --index;
        }
        while( index );
    }
    if( (double)x2 != x || (double)y2 != y )
        v15(v7, x2, y2, v8, elevation_height);
    if( x1 >= x2 )
    {
        v17 = v8 + x1;
        v16 = x2 - v8;
    }
    else
    {
        v16 = x1 - v8;
        v17 = v8 + x2;
    }
    if( y1 >= y2 )
    {
        v19 = v8 + y1;
        v18 = y2 - v8;
    }
    else
    {
        v18 = y1 - v8;
        v19 = v8 + y2;
    }
    RGE_Map::clean_elevation(v7, v18, v16, v18, v17, v19, elevation_height);
    return 1;
}

char __stdcall RGE_Map::do_cliff_brush(int x, int y, char cliff_id, char delete_cliff)
{
    return 0;
}

char RGE_Map::do_cliff_brush_stroke(int x1, int y1, int x2, int y2, int cliff_id, int delete_cliff)
{
    RGE_Map *v7; // esi@1
    int v8; // eax@3
    int v9; // eax@7
    double v10; // st7@9
    double v11; // st6@9
    double v12; // st5@9
    double v13; // st7@9
    char (*v14)(RGE_Map *, int, int, char, char); // edi@9
    int index; // [sp+20h] [bp-24h]@9
    double x; // [sp+24h] [bp-20h]@9
    double y; // [sp+2Ch] [bp-18h]@9

    v7 = this;
    if( x1 < 0 )
        x1 = 0;
    v8 = this->map_width;
    if( x2 >= v8 )
        x2 = v8 - 1;
    if( y1 < 0 )
        y1 = 0;
    v9 = this->map_height;
    if( y2 >= v9 )
        y2 = v9 - 1;
    v10 = (double)(x2 - x1);
    v11 = (double)(y2 - y1);
    index = (signed __int64)sqrt(v10 * v10 + v11 * v11);
    v12 = v10;
    v13 = (double)index;
    v14 = this->vfptr->do_cliff_brush;
    x = (double)x1;
    y = (double)y1;
    v14(this, x1, y1, cliff_id, delete_cliff);
    if( index > 0 )
    {
        do
        {
            x = x + v12 / v13;
            y = y + v11 / v13;
            ((void (__fastcall *)(RGE_Map *, _DWORD, _DWORD, _DWORD, int, int))v14)(
                v7,
                (unsigned __int64)(signed __int64)x >> 32,
                (signed __int64)x,
                (signed __int64)y,
                cliff_id,
                delete_cliff);
            --index;
        }
        while( index );
    }
    if( (double)x2 != x || (double)y2 != y )
        v14(v7, x2, y2, cliff_id, delete_cliff);
    return 1;
}

void RGE_Map::map_generate2(RGE_Game_World *gworld, int new_width, int new_height, int type, int player_num)
{
    RGE_Map *v6; // esi@1
    RGE_Game_World *v7; // eax@1
    char v8; // bl@1
    int v9; // edi@1
    int v10; // eax@3

    v6 = this;
    v7 = this->game_world;
    v8 = v7->game_state;
    v7->game_state = 3;
    v9 = rge_base_game->random_map_seed;
    if( v9 == -1 )
        v9 = debug_rand(aCMsdevWorkA_31, 1486);
    rge_base_game->save_random_map_seed = v9;
    TDebuggingLog::Log(L, aRandomMapSeedD, v9);
    debug_srand(aCMsdevWorkA_31, 1498, v9);
    RGE_Map::clear_map(v6, 0, gworld, 0, new_width, new_height);
    debug_srand(aCMsdevWorkA_31, 1501, v9);
    ((void (__stdcall *)(RGE_Map *, RGE_Game_World *, _DWORD, int, signed int))v6->random_map->vfptr[5].generate)(
        v6,
        gworld,
        type,
        player_num,
        1);
    debug_srand(aCMsdevWorkA_31, 1504, v9);
    ((void (*)(void))v6->random_map->vfptr->generate)();
    ((void (*)(void))v6->random_map->vfptr[6].generate)();
    v10 = debug_rand(aCMsdevWorkA_31, 1509);
    TDebuggingLog::Log(L, aAfterRandomMap, v10);
    v6->game_world->game_state = v8;
}

void RGE_Map::load_map(int infile)
{
    int v3; // edi@1
    RGE_Map *v4; // ebx@1
    RGE_Zone_Map_List *v5; // esi@1
    int v6; // ebp@1
    RGE_Zone_Map_List *v7; // eax@3
    RGE_Zone_Map_List *v8; // eax@4
    int v9; // eax@7
    RGE_Tile *v10; // esi@8
    char v11; // al@9
    char v12; // cl@9
    int v13; // eax@13
    int v14; // ecx@14
    int v15; // edx@15
    int v16; // eax@15
    int x; // [sp+10h] [bp-1Ch]@8
    int y; // [sp+14h] [bp-18h]@7
    int ya; // [sp+14h] [bp-18h]@13
    int h; // [sp+18h] [bp-14h]@1
    int w; // [sp+1Ch] [bp-10h]@1
    int v22; // [sp+28h] [bp-4h]@3

    v3 = infile;
    v4 = this;
    rge_read(a2, infile, infile, &w, 4);
    rge_read(a2, v3, v3, &h, 4);
    RGE_Map::new_map(v4, w, h);
    v5 = v4->map_zones;
    v6 = 0;
    if( v5 )
    {
        RGE_Zone_Map_List::~RGE_Zone_Map_List(v4->map_zones);
        operator delete(v5);
    }
    v7 = (RGE_Zone_Map_List *)operator new(0xCu);
    v22 = 0;
    if( v7 )
        RGE_Zone_Map_List::RGE_Zone_Map_List(v7, v3, v3, v4);
    else
        v8 = 0;
    v22 = -1;
    v4->map_zones = v8;
    rge_read(0, v3, v3, &v4->map_visible_flag, 1);
    rge_read(0, v3, v3, &v4->fog_flag, 1);
    if( save_game_version < 7.0 )
    {
        rge_read(0, v3, v3, v4->map, 24 * v4->map_height * v4->map_width);
        v13 = 0;
        for( ya = 0; v13 < v4->map_height; ya = v13 )
        {
            v14 = 0;
            if( v4->map_width > 0 )
            {
                v15 = v13;
                v16 = 0;
                do
                {
                    ++v14;
                    ++v16;
                    *((_DWORD *)&v4->map_row_offset[v15][v16] - 2) = 0;
                }
                while( v14 < v4->map_width );
                v13 = ya;
            }
            ++v13;
        }
    }
    else
    {
        v9 = 0;
        for( y = 0; v9 < v4->map_height; y = v9 )
        {
            x = 0;
            v10 = v4->map_row_offset[v9];
            if( v4->map_width > 0 )
            {
                do
                {
                    rge_read(v6, v3, v3, v10, 2);
                    v6 = (int)&v10->tile_type;
                    rge_read((int)&v10->tile_type, v3, v3, &v10->screen_ypos, 2);
                    rge_read((int)&v10->tile_type, v3, v3, &v10->tile_type, 1);
                    rge_read((int)&v10->tile_type, v3, v3, &infile, 1);
                    *((_BYTE *)v10 + 5) ^= (*((_BYTE *)v10 + 5) ^ infile) & 0x1F;
                    rge_read((int)&v10->tile_type, v3, v3, &infile, 1);
                    *((_BYTE *)v10 + 5) = *((_BYTE *)v10 + 5) & 0x1F | 32 * infile;
                    rge_read((int)&v10->tile_type, v3, v3, &infile, 1);
                    *((_BYTE *)v10 + 6) ^= (*((_BYTE *)v10 + 6) ^ infile) & 0xF;
                    rge_read((int)&v10->tile_type, v3, v3, &infile, 1);
                    v11 = 16 * infile;
                    v12 = *((_BYTE *)v10 + 6) & 0xF;
                    v10->last_drawn_as = 0;
                    v10->last_drawn_shape = -1;
                    *((_BYTE *)v10 + 6) = v12 | v11;
                    v10->objects.list = 0;
                    v10->objects.number_of_objects = 0;
                    v10->draw_as = 0;
                    v10->draw_attribute = 0;
                    v10->last_drawn_shape2 = -1;
                    ++v10;
                    ++x;
                }
                while( x < v4->map_width );
                v9 = y;
                v6 = 0;
            }
            ++v9;
        }
    }
    RGE_Unified_Visible_Map::load(v4->unified_vis_map, v3);
}
// 58EBCC: using guessed type float save_game_version;

//----- (00457C50) --------------------------------------------------------
void RGE_Map::save_map(int outfile)
{
    RGE_Map *v2; // ebx@1
    int v3; // edi@1
    char *v4; // ebp@1
    int *v5; // esi@1
    int v6; // eax@2
    int v7; // ebp@3
    RGE_Tile *v8; // esi@3
    char *v9; // [sp+10h] [bp-10h]@1
    int y; // [sp+14h] [bp-Ch]@2
    RGE_Map *v11; // [sp+18h] [bp-8h]@1
    int *v12; // [sp+1Ch] [bp-4h]@1

    v2 = this;
    v3 = outfile;
    v4 = (char *)&this->map_width;
    v11 = this;
    v9 = (char *)&this->map_width;
    rge_write(outfile, &this->map_width, 4);
    v5 = &v2->map_height;
    v12 = &v2->map_height;
    rge_write(v3, &v2->map_height, 4);
    RGE_Zone_Map_List::save(v2->map_zones, v3);
    rge_write(v3, &v2->map_visible_flag, 1);
    rge_write(v3, &v2->fog_flag, 1);
    if( save_game_version < 7.0 )
    {
        rge_write(v3, v2->map, 24 * *(_DWORD *)v4 * *v5);
    }
    else
    {
        v6 = 0;
        y = 0;
        if( *v5 > 0 )
        {
            do
            {
                v7 = 0;
                v8 = v2->map_row_offset[v6];
                if( *(_DWORD *)v9 > 0 )
                {
                    do
                    {
                        rge_write(v3, v8, 2);
                        rge_write(v3, &v8->screen_ypos, 2);
                        rge_write(v3, &v8->tile_type, 1);
                        LOBYTE(outfile) = *((_BYTE *)v8 + 5) & 0x1F;
                        rge_write(v3, &outfile, 1);
                        LOBYTE(outfile) = *((_BYTE *)v8 + 5) >> 5;
                        rge_write(v3, &outfile, 1);
                        LOBYTE(outfile) = *((_BYTE *)v8 + 6) & 0xF;
                        rge_write(v3, &outfile, 1);
                        LOBYTE(outfile) = *((_BYTE *)v8 + 6) >> 4;
                        rge_write(v3, &outfile, 1);
                        ++v8;
                        ++v7;
                    }
                    while( v7 < *(_DWORD *)v9 );
                    v6 = y;
                    v2 = v11;
                }
                y = ++v6;
            }
            while( v6 < *v12 );
        }
    }
    RGE_Unified_Visible_Map::save(v2->unified_vis_map, v3);
}
// 58EBCC: using guessed type float save_game_version;

//----- (00457DF0) --------------------------------------------------------
void RGE_Map::save(int outfile)
{
    RGE_Map *v2; // ebx@1
    RGE_Map *v3; // eax@1
    RGE_Map *v4; // ebp@1
    int v5; // eax@1
    int v6; // edx@1
    signed int v7; // esi@1
    int v8; // eax@7
    signed int v9; // esi@7

    v2 = this;
    v3 = (RGE_Map *)calloc(1u, 0x8DD0u);
    v4 = v3;
    qmemcpy(v3, v2, sizeof(RGE_Map));
    v5 = (int)&v2->terrain_types[0].sound;
    v6 = (char *)v4 - (char *)v2;
    v7 = 32;
    do
    {
        if( *(_BYTE *)(v5 - 36) )
        {
            if( *(_DWORD *)v5 )
                *(_DWORD *)(v6 + v5) = *(_WORD *)(*(_DWORD *)v5 + 12);
            else
                *(_DWORD *)(v6 + v5) = -1;
        }
        v5 += 408;
        --v7;
    }
    while( v7 );
    v8 = (int)&v2->border_types[0].sound;
    v9 = 16;
    do
    {
        if( *(_DWORD *)v8 && *(_BYTE *)(v8 - 36) )
            *(_DWORD *)(v8 + v6) = *(_WORD *)(*(_DWORD *)v8 + 12);
        else
            *(_DWORD *)(v8 + v6) = -1;
        v8 += 1440;
        --v9;
    }
    while( v9 );
    rge_write(outfile, v4, 36304);
    RGE_RMM_Database_Controller::save(v2->random_map, outfile);
    free(v4);
}

//----- (00457EB0) --------------------------------------------------------
void RGE_Map::load_terrain_types(RGE_Sound **sounds)
{
    char *v2; // esi@1
    signed int v3; // ebp@1
    TShape *v4; // eax@3
    TShape *v5; // eax@4
    int v6; // eax@8
    char *filename2; // [sp+10h] [bp-10h]@1
    int v8; // [sp+1Ch] [bp-4h]@3

    filename2 = 0;
    v2 = (char *)&this->terrain_types[31].resource_id;
    v3 = 32;
    do
    {
        if( *(v2 - 28) )
        {
            addstring(&filename2, v2 - 13, a_shp);
            v4 = (TShape *)operator new(0x20u);
            v8 = 0;
            if( v4 )
                TShape::TShape(v4, filename2, *(_DWORD *)v2);
            else
                v5 = 0;
            v8 = -1;
            *((_DWORD *)v2 + 1) = v5;
            if( !TShape::is_loaded(v5) )
                *(v2 - 28) = 0;
            v6 = *((_DWORD *)v2 + 2);
            if( v6 < 0 )
                *((_DWORD *)v2 + 2) = 0;
            else
                *((_DWORD *)v2 + 2) = sounds[v6];
        }
        v2 -= 408;
        --v3;
    }
    while( v3 );
    if( filename2 )
        free(filename2);
}

//----- (00457F80) --------------------------------------------------------
void RGE_Map::load_terrain_types(char *terrain_table, RGE_Sound **sounds)
{
    RGE_Map *v3; // ebp@1
    char *v4; // eax@1
    signed int v5; // ecx@1
    _iobuf *v6; // eax@3
    _iobuf *v7; // edi@3
    short v8; // ax@4
    int v9; // ebx@6
    int v10; // ebp@9
    int v11; // esi@9
    int v12; // eax@10
    int v13; // esi@11
    RGE_Sound *v14; // eax@14
    int v15; // ecx@16
    signed __int64 v16; // rax@17
    float v17; // ecx@19
    short border_num; // [sp+10h] [bp-5Ch]@6
    short border; // [sp+12h] [bp-5Ah]@12
    short sound_id; // [sp+14h] [bp-58h]@6
    short low_color; // [sp+16h] [bp-56h]@6
    short med_color; // [sp+18h] [bp-54h]@6
    short hi_color; // [sp+1Ah] [bp-52h]@6
    short lt_cliff_color; // [sp+1Ch] [bp-50h]@6
    short rt_cliff_color; // [sp+1Eh] [bp-4Eh]@6
    short impassable_terrain; // [sp+20h] [bp-4Ch]@6
    short passable_terrain; // [sp+22h] [bp-4Ah]@6
    short row; // [sp+24h] [bp-48h]@6
    short col; // [sp+26h] [bp-46h]@6
    short is_animated; // [sp+28h] [bp-44h]@6
    short animation_frames; // [sp+2Ah] [bp-42h]@6
    short terrain_to_draw; // [sp+2Ch] [bp-40h]@6
    short random; // [sp+2Eh] [bp-3Eh]@6
    float interval; // [sp+30h] [bp-3Ch]@6
    _iobuf *infile; // [sp+34h] [bp-38h]@3
    int v36; // [sp+38h] [bp-34h]@9
    float pause_between_loops; // [sp+3Ch] [bp-30h]@6
    int v38; // [sp+40h] [bp-2Ch]@5
    int resource_id; // [sp+44h] [bp-28h]@6
    RGE_Map *v40; // [sp+48h] [bp-24h]@1
    char name[13]; // [sp+4Ch] [bp-20h]@6
    char pict_name[13]; // [sp+5Ch] [bp-10h]@6

    v3 = this;
    v40 = this;
    v4 = &this->terrain_types[31].loaded;
    v5 = 32;
    do
    {
        *v4 = 0;
        v4 -= 408;
        --v5;
    }
    while( v5 );
    v6 = fopen(terrain_table, Mode);
    v7 = v6;
    infile = v6;
    if( v6 )
    {
        fscanf(v6, aHd, &v3->num_terrain);
        v8 = v3->num_terrain - 1;
        if( v8 >= 0 )
        {
            v38 = v8 + 1;
            do
            {
                v9 = 0;
                if( fscanf(
                             v7,
                             aHdSSDHdHdHdHdH,
                             &terrain_table,
                             name,
                             pict_name,
                             &resource_id,
                             &random,
                             &med_color,
                             &hi_color,
                             &low_color,
                             &sound_id,
                             &is_animated,
                             &animation_frames,
                             &interval,
                             &pause_between_loops,
                             &terrain_to_draw,
                             &row,
                             &col,
                             &lt_cliff_color,
                             &rt_cliff_color,
                             &impassable_terrain,
                             &passable_terrain,
                             &border_num) != -1
                    && (signed short)terrain_table < 32
                    && (signed short)terrain_table >= 0 )
                {
                    v36 = 19;
                    v10 = (int)&v3->terrain_types[(signed short)terrain_table].loaded;
                    v11 = v10 + 70;
                    do
                    {
                        v12 = fscanf(infile, aHdHd, v11, v11 + 2);
                        *(_WORD *)(v11 + 4) = v9;
                        LOWORD(v12) = *(_WORD *)(v11 + 2) * *(_WORD *)v11;
                        v9 += v12;
                        v11 += 6;
                        --v36;
                    }
                    while( v36 );
                    v13 = 0;
                    if( border_num > 0 )
                    {
                        do
                        {
                            fscanf(infile, aHdHd, &terrain_table, &border);
                            ++v13;
                            *(_WORD *)(v10 + 2 * (signed short)terrain_table + 190) = border;
                        }
                        while( (signed short)v13 < border_num );
                    }
                    if( sound_id < 0 )
                        v14 = 0;
                    else
                        v14 = sounds[sound_id];
                    *(_DWORD *)(v10 + 36) = v14;
                    *(_BYTE *)(v10 + 42) = low_color;
                    *(_BYTE *)(v10 + 41) = med_color;
                    *(_BYTE *)(v10 + 40) = hi_color;
                    *(_BYTE *)(v10 + 43) = lt_cliff_color;
                    *(_BYTE *)(v10 + 44) = rt_cliff_color;
                    *(_BYTE *)(v10 + 46) = impassable_terrain;
                    *(_BYTE *)(v10 + 45) = passable_terrain;
                    convert_us(name);
                    strcpy((char *)(v10 + 2), name);
                    strcpy((char *)(v10 + 15), pict_name);
                    v15 = resource_id;
                    *(_DWORD *)(v10 + 64) = 0;
                    *(_DWORD *)(v10 + 28) = v15;
                    *(_BYTE *)v10 = 1;
                    *(_WORD *)(v10 + 186) = row;
                    *(_WORD *)(v10 + 188) = col;
                    *(_BYTE *)(v10 + 47) = is_animated;
                    *(_WORD *)(v10 + 48) = animation_frames;
                    if( interval == 0.0 )
                        LOWORD(v16) = 0;
                    else
                        v16 = (signed __int64)(pause_between_loops / interval);
                    *(_WORD *)(v10 + 50) = v16;
                    v7 = infile;
                    *(float *)(v10 + 52) = interval;
                    v17 = pause_between_loops;
                    *(_WORD *)(v10 + 60) = 0;
                    *(float *)(v10 + 56) = v17;
                    *(_WORD *)(v10 + 62) = 0;
                    *(_BYTE *)(v10 + 68) = 0;
                    *(_BYTE *)(v10 + 69) = 0;
                    *(_WORD *)(v10 + 184) = terrain_to_draw;
                    v3 = v40;
                }
                --v38;
            }
            while( v38 );
        }
    }
    fclose(v7);
}

//----- (00458280) --------------------------------------------------------
void RGE_Map::load_border_types(RGE_Sound **sounds)
{
    char *v2; // esi@1
    signed int v3; // ebp@1
    TShape *v4; // eax@3
    TShape *v5; // eax@4
    int v6; // eax@8
    char *filename2; // [sp+10h] [bp-10h]@1
    int v8; // [sp+1Ch] [bp-4h]@3

    filename2 = 0;
    v2 = (char *)&this->border_types[15].resource_id;
    v3 = 16;
    do
    {
        if( *(v2 - 28) )
        {
            addstring(&filename2, v2 - 13, a_shp);
            v4 = (TShape *)operator new(0x20u);
            v8 = 0;
            if( v4 )
                TShape::TShape(v4, filename2, *(_DWORD *)v2);
            else
                v5 = 0;
            v8 = -1;
            *((_DWORD *)v2 + 1) = v5;
            if( !TShape::is_loaded(v5) )
                *(v2 - 28) = 0;
            v6 = *((_DWORD *)v2 + 2);
            if( v6 < 0 )
                *((_DWORD *)v2 + 2) = 0;
            else
                *((_DWORD *)v2 + 2) = sounds[v6];
        }
        v2 -= 1440;
        --v3;
    }
    while( v3 );
    if( filename2 )
        free(filename2);
}

//----- (00458350) --------------------------------------------------------
void RGE_Map::load_border_types(char *border_table, RGE_Sound **sounds)
{
    RGE_Map *v3; // edi@1
    signed int v4; // ecx@1
    char *v5; // eax@1
    _iobuf *v6; // eax@3
    _iobuf *v7; // ebp@3
    short v8; // ax@4
    int v9; // ebx@6
    int v10; // edx@9
    int v11; // ebp@9
    int v12; // esi@9
    _WORD *v13; // edi@11
    int v14; // esi@11
    int v15; // eax@12
    int v16; // ecx@12
    bool v17; // zf@13
    RGE_Sound *v18; // eax@15
    int v19; // ecx@17
    signed __int64 v20; // rax@18
    short sound_id; // [sp+10h] [bp-58h]@6
    short low_color; // [sp+12h] [bp-56h]@6
    short med_color; // [sp+14h] [bp-54h]@6
    short hi_color; // [sp+16h] [bp-52h]@6
    short is_animated; // [sp+18h] [bp-50h]@6
    short animation_frames; // [sp+1Ah] [bp-4Eh]@6
    short tile_flag; // [sp+1Ch] [bp-4Ch]@6
    short underlay_terrain; // [sp+1Eh] [bp-4Ah]@6
    short border_style; // [sp+20h] [bp-48h]@6
    short random; // [sp+22h] [bp-46h]@6
    RGE_TOB_Picts (*i)[12]; // [sp+24h] [bp-44h]@9
    float interval; // [sp+28h] [bp-40h]@6
    int v33; // [sp+2Ch] [bp-3Ch]@11
    int v34; // [sp+30h] [bp-38h]@9
    float pause_between_loops; // [sp+34h] [bp-34h]@6
    _iobuf *infile; // [sp+38h] [bp-30h]@3
    int v37; // [sp+3Ch] [bp-2Ch]@5
    int resource_id; // [sp+40h] [bp-28h]@6
    RGE_Map *v39; // [sp+44h] [bp-24h]@1
    char name[13]; // [sp+48h] [bp-20h]@6
    char pict_name[13]; // [sp+58h] [bp-10h]@6

    v3 = this;
    v39 = this;
    v4 = 16;
    v5 = &v39->border_types[15].loaded;
    do
    {
        *v5 = 0;
        v5 -= 1440;
        --v4;
    }
    while( v4 );
    v6 = fopen(border_table, Mode);
    v7 = v6;
    infile = v6;
    if( v6 )
    {
        fscanf(v6, aHd, &v3->num_borders);
        v8 = v3->num_borders - 1;
        if( v8 >= 0 )
        {
            v37 = v8 + 1;
            do
            {
                v9 = 0;
                if( fscanf(
                             v7,
                             aHdSSDHdHdHdH_1,
                             &border_table,
                             name,
                             pict_name,
                             &resource_id,
                             &random,
                             &med_color,
                             &hi_color,
                             &low_color,
                             &sound_id,
                             &is_animated,
                             &animation_frames,
                             &interval,
                             &pause_between_loops,
                             &tile_flag,
                             &underlay_terrain,
                             &border_style) != -1
                    && (signed short)border_table < 16
                    && (signed short)border_table >= 0 )
                {
                    v34 = 19;
                    v10 = (signed short)border_table;
                    v11 = (int)&v3->border_types[v10].loaded;
                    v12 = (int)v3->border_types[v10].borders;
                    for( i = v3->border_types[v10].borders; ; v12 = (int)i )
                    {
                        v13 = (_WORD *)v12;
                        v14 = v12 + 2;
                        v33 = 12;
                        do
                        {
                            fscanf(infile, aHdHd, v13, v14);
                            v15 = v33;
                            LOWORD(v16) = *(_WORD *)v14 * *v13;
                            *(_WORD *)(v14 + 2) = v9;
                            v9 += v16;
                            v13 += 3;
                            v14 += 6;
                            v33 = v15 - 1;
                        }
                        while( v15 != 1 );
                        v17 = v34 == 1;
                        ++i;
                        --v34;
                        if( v17 )
                            break;
                    }
                    if( sound_id < 0 )
                        v18 = 0;
                    else
                        v18 = sounds[sound_id];
                    *(_DWORD *)(v11 + 36) = v18;
                    *(_BYTE *)(v11 + 42) = low_color;
                    *(_BYTE *)(v11 + 41) = med_color;
                    *(_BYTE *)(v11 + 40) = hi_color;
                    convert_us(name);
                    strcpy((char *)(v11 + 2), name);
                    strcpy((char *)(v11 + 15), pict_name);
                    v19 = resource_id;
                    *(_BYTE *)v11 = 1;
                    *(_DWORD *)(v11 + 28) = v19;
                    *(_BYTE *)(v11 + 43) = is_animated;
                    *(_WORD *)(v11 + 44) = animation_frames;
                    if( interval == 0.0 )
                        LOWORD(v20) = 0;
                    else
                        v20 = (signed __int64)(pause_between_loops / interval);
                    *(_WORD *)(v11 + 46) = v20;
                    *(float *)(v11 + 48) = interval;
                    *(float *)(v11 + 52) = pause_between_loops;
                    *(_WORD *)(v11 + 56) = 0;
                    *(_WORD *)(v11 + 58) = 0;
                    *(_DWORD *)(v11 + 60) = 0;
                    *(_BYTE *)(v11 + 64) = 0;
                    *(_BYTE *)(v11 + 65) = 0;
                    v3 = v39;
                    *(_BYTE *)(v11 + 1434) = tile_flag;
                    *(_WORD *)(v11 + 1436) = underlay_terrain;
                    *(_WORD *)(v11 + 1438) = border_style;
                    v7 = infile;
                }
                --v37;
            }
            while( v37 );
        }
    }
    fclose(v7);
}

//----- (00458600) --------------------------------------------------------
void RGE_Map::load_terrain_obj_types(char *terr_obj_tbl)
{
    RGE_Map *v2; // esi@1
    FILE *v3; // eax@1
    FILE *v4; // edi@1
    int v5; // edx@2
    short flag; // [sp+Ah] [bp-Ah]@2
    short density; // [sp+Ch] [bp-8h]@2
    short obj_id; // [sp+Eh] [bp-6h]@2
    int num; // [sp+10h] [bp-4h]@2

    v2 = this;
    v3 = fopen(terr_obj_tbl, Mode);
    v4 = v3;
    if( v3 )
    {
        fscanf(v3, aHd, &num);
        while( fscanf(v4, aHdHdHdHd_1, &terr_obj_tbl, &obj_id, &density, &flag) != -1 )
        {
            if( v2->terrain_types[(signed short)terr_obj_tbl].loaded )
            {
                LOWORD(v5) = v2->terrain_types[(signed short)terr_obj_tbl].num_obj_type;
                if( (signed short)v5 < 30 )
                {
                    num = v5;
                    v2->terrain_types[0].obj_types[(signed short)v5 + 204 * (signed short)terr_obj_tbl] = obj_id;
                    v2->terrain_types[0].obj_density[(signed short)num + 204 * (signed short)terr_obj_tbl] = density;
                    v2->terrain_types[(signed short)terr_obj_tbl].obj_placement_flag[(signed short)num] = flag;
                    ++v2->terrain_types[(signed short)terr_obj_tbl].num_obj_type;
                }
            }
        }
    }
    fclose(v4);
}

//----- (00458760) --------------------------------------------------------
void RGE_Map::delete_objects_on_tile(RGE_Player *obj_owner, RGE_Game_World *gworld, int x, int y, int no_delete_start, int no_delete_end)
{
    RGE_Object_Node *v7; // eax@5
    RGE_Static_Object *v8; // ecx@6
    RGE_Object_Node *v9; // esi@6
    int v10; // eax@6

    if( x >= 0 && x < this->map_width && y >= 0 && y < this->map_height )
    {
        v7 = this->map_row_offset[y][x].objects.list;
        if( v7 )
        {
            do
            {
                v8 = v7->node;
                v9 = v7->next;
                v10 = v7->node->master_obj->id;
                if( v8->owner == obj_owner && (v10 < no_delete_start || v10 > no_delete_end) )
                {
                    if( v8 )
                        ((void (__stdcall *)(_DWORD))v8->vfptr->__vecDelDtor)(1);
                }
                v7 = v9;
            }
            while( v9 );
        }
    }
}

//----- (004587D0) --------------------------------------------------------
void RGE_Map::delete_all_objects_on_tile(int x, int y)
{
    RGE_Object_Node *v3; // eax@5
    RGE_Object_Node *v4; // esi@6
    RGE_Static_Object *v5; // eax@6

    if( x >= 0 && x < this->map_width && y >= 0 && y < this->map_height )
    {
        v3 = this->map_row_offset[y][x].objects.list;
        if( v3 )
        {
            do
            {
                v4 = v3->next;
                v5 = v3->node;
                if( v5 )
                    v5->vfptr->__vecDelDtor(v5, 1u);
                v3 = v4;
            }
            while( v4 );
        }
    }
}

//----- (00458820) --------------------------------------------------------
void RGE_Map::create_terrain_object(RGE_Player *obj_owner, RGE_Game_World *gworld, short row, short col, short old_terrain, int delete_obj, int no_delete_start, int no_delete_end)
{
    RGE_Map *v9; // ebx@1
    int v10; // eax@1
    short v11; // dx@1
    int v12; // ecx@1
    RGE_Object_Node *v13; // eax@2
    RGE_Static_Object *v14; // ecx@3
    RGE_Object_Node *v15; // ebp@3
    short v16; // di@3
    RGE_Player *v17; // edx@3
    int v18; // eax@3
    short v19; // ax@11
    int v20; // eax@22
    short *v21; // ecx@22
    short v22; // ax@23
    short v23; // bp@24
    RGE_Master_Static_Object *v24; // edi@24
    int v25; // eax@26
    int v26; // ebx@26
    double v27; // st7@30
    float v28; // ST3C_4@31
    float v29; // ST38_4@31
    signed int v30; // eax@34
    RGE_Master_Static_ObjectVtbl *v31; // esi@37
    bool v32; // zf@41
    float y; // [sp+28h] [bp-10h]@1
    float x; // [sp+2Ch] [bp-Ch]@1
    int v35; // [sp+30h] [bp-8h]@1
    short end_i; // [sp+34h] [bp-4h]@1
    char *old_terraina; // [sp+4Ch] [bp+14h]@22
    int delete_obja; // [sp+50h] [bp+18h]@22
    int no_delete_starta; // [sp+54h] [bp+1Ch]@22
    unsigned __int8 no_delete_enda; // [sp+58h] [bp+20h]@24

    v9 = this;
    x = 0.0;
    y = 0.0;
    v10 = 51 * RGE_Map::get_terrain(this, col, row);
    v11 = v9->terrain_types[8 * v10 / 0x198u].num_obj_type;
    v12 = (int)v9 + 8 * v10;
    v35 = (int)v9 + 8 * v10;
    end_i = v11;
    if( v11 > 0 )
    {
        v13 = v9->map_row_offset[row][col].objects.list;
        if( v13 )
        {
            do
            {
                v14 = v13->node;
                v15 = v13->next;
                v16 = v13->node->master_obj->id;
                v17 = v13->node->owner;
                v18 = v13->node->master_obj->id;
                if( v17 == obj_owner && (v18 < no_delete_start || v18 > no_delete_end) )
                {
                    if( old_terrain >= 0 )
                    {
                        v19 = v9->terrain_types[old_terrain].num_obj_type;
                        if( v19 >= 0 )
                        {
                            do
                            {
                                if( v9->terrain_types[0].obj_types[204 * old_terrain + v19] == v16 )
                                    break;
                                --v19;
                            }
                            while( v19 >= 0 );
                            if( v19 >= 0 )
                            {
                                if( delete_obj )
                                {
                                    if( v14 )
                                        ((void (__stdcall *)(signed int))v14->vfptr->__vecDelDtor)(1);
                                }
                                else
                                {
                                    ((void (*)(void))v14->vfptr->destroy_obj)();
                                }
                            }
                        }
                    }
                    else if( delete_obj )
                    {
                        if( v14 )
                            ((void (__stdcall *)(signed int))v14->vfptr->__vecDelDtor)(1);
                    }
                    else
                    {
                        ((void (*)(void))v14->vfptr->destroy_obj)();
                    }
                }
                v13 = v15;
            }
            while( v15 );
            v12 = v35;
            v11 = end_i;
        }
        if( v11 > 0 )
        {
            v20 = v12 + 514;
            v21 = (short *)(v12 + 454);
            old_terraina = (char *)v20;
            delete_obja = (int)v21;
            no_delete_starta = v11;
            while( 1 )
            {
                v22 = *(v21 - 30);
                if( v22 != -1 )
                {
                    v23 = *v21;
                    v24 = obj_owner->master_objects[v22];
                    no_delete_enda = *old_terraina;
                    if( v24 )
                    {
                        if( v23 > 0 )
                            break;
                    }
                }
LABEL_41:
                ++v21;
                v32 = no_delete_starta == 1;
                delete_obja = (int)v21;
                ++old_terraina;
                --no_delete_starta;
                if( v32 )
                    return;
            }
            v25 = no_delete_enda;
            v26 = v23;
            while( 1 )
            {
                if( v25 )
                {
                    if( v25 != 1 )
                        goto LABEL_33;
                    v27 = (double)row - -0.5;
                    x = (double)col - -0.5;
                }
                else
                {
                    v28 = (double)col;
                    x = v28 - (double)debug_rand(aCMsdevWorkA_31, 2067) * -0.000030518509;
                    v29 = (double)row;
                    v27 = v29 - (double)debug_rand(aCMsdevWorkA_31, 2068) * -0.000030518509;
                }
                y = v27;
LABEL_33:
                if( v23 < 1000 )
                    v30 = 1000 * debug_rand(aCMsdevWorkA_31, 2080) / 0x7FFF < v26;
                else
                    v30 = 1;
                if( v30 )
                {
                    v31 = v24->vfptr;
                    if( !v24->vfptr->check_placement(
                                    v24,
                                    obj_owner,
                                    COERCE_FLOAT(LODWORD(x)),
                                    COERCE_FLOAT(LODWORD(y)),
                                    0,
                                    0,
                                    1,
                                    0,
                                    1,
                                    0,
                                    1) )
                        ((void (*)(RGE_Master_Static_Object *, RGE_Player *, float, float, _DWORD))v31->make_new_obj)(
                            v24,
                            obj_owner,
                            COERCE_FLOAT(LODWORD(x)),
                            COERCE_FLOAT(LODWORD(y)),
                            0);
                }
                v23 -= 1000;
                v26 -= 1000;
                if( v23 <= 0 )
                {
                    v21 = (short *)delete_obja;
                    goto LABEL_41;
                }
                v25 = no_delete_enda;
            }
        }
    }
}

//----- (00458B40) --------------------------------------------------------
int RGE_Map::clear_terrain_object(RGE_Game_World *gworld, short row, short col, short old_terrain, int delete_obj, int no_delete_start, int no_delete_end)
{
    RGE_Map *v8; // ebx@1
    signed short v9; // bp@1
    RGE_Tile *v10; // ecx@1
    RGE_Object_Node *v11; // esi@1
    RGE_Static_Object *v12; // ecx@2
    RGE_Master_Static_Object *v13; // edi@2
    int v14; // edx@2
    short v15; // ax@9
    RGE_Object_Node *rowa; // [sp+1Ch] [bp+8h]@1
    RGE_Object_Node *list; // [sp+20h] [bp+Ch]@2

    v8 = this;
    v9 = -1;
    RGE_Map::get_terrain(this, col, row);
    v10 = v8->map_row_offset[row];
    v11 = v10[col].objects.list;
    rowa = v10[col].objects.list;
    if( v11 )
    {
        while( 1 )
        {
            v12 = v11->node;
            list = v11->next;
            v13 = v11->node->master_obj;
            v14 = v13->id;
            if( v14 >= no_delete_start && v14 <= no_delete_end )
                goto LABEL_21;
            if( old_terrain < 0 )
            {
                if( delete_obj )
                {
                    if( v12 )
                        ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
                }
                else
                {
                    ((void (*)(void))v12->vfptr->destroy_obj)();
                }
                goto LABEL_21;
            }
            v9 = v13->id;
            v15 = v8->terrain_types[old_terrain].num_obj_type;
            if( v15 >= 0 )
            {
                do
                {
                    if( v8->terrain_types[0].obj_types[204 * old_terrain + v15] == v9 )
                        break;
                    --v15;
                }
                while( v15 >= 0 );
                v11 = rowa;
                if( v15 >= 0 )
                    break;
            }
            if( (unsigned __int8)((int (*)(RGE_Master_Static_Object *, RGE_Player *, _DWORD, _DWORD, _DWORD, _DWORD, signed int, signed int, signed int, _DWORD, _DWORD))v13->vfptr->check_placement)(
                                                            v13,
                                                            v12->owner,
                                                            LODWORD(v12->world_x),
                                                            LODWORD(v12->world_y),
                                                            0,
                                                            0,
                                                            1,
                                                            1,
                                                            1,
                                                            0,
                                                            0) )
            {
                v12 = v11->node;
                if( delete_obj )
                {
                    if( v12 )
                        ((void (__stdcall *)(signed int))v12->vfptr->__vecDelDtor)(1);
                    goto LABEL_21;
                }
LABEL_20:
                ((void (*)(void))v12->vfptr->destroy_obj)();
            }
LABEL_21:
            v11 = list;
            rowa = list;
            if( !list )
                return v9;
        }
        if( delete_obj )
        {
            if( v12 )
                ((void (__stdcall *)(_DWORD))v12->vfptr->__vecDelDtor)(1);
            goto LABEL_21;
        }
        goto LABEL_20;
    }
    return v9;
}

//----- (00458C90) --------------------------------------------------------
void RGE_Map::place_terrain_object(RGE_Player *obj_owner, RGE_Game_World *gworld, short row, short col, int obj_type_id, int FillFlag)
{
    short v7; // bp@1
    RGE_Map *v8; // edi@1
    int v9; // eax@1
    int v10; // ecx@1
    int v11; // esi@1
    int v12; // eax@1
    int v13; // edx@1
    int v14; // eax@4
    RGE_Master_Static_Object *v15; // esi@5
    char v16; // dl@5
    double v17; // st7@11
    float v18; // ST3C_4@12
    float v19; // ST60_4@12
    signed int v20; // eax@14
    RGE_Master_Static_ObjectVtbl *v21; // edi@17
    double v22; // st7@25
    float v23; // ST48_4@26
    float v24; // ST48_4@26
    bool v25; // sf@29
    unsigned __int8 v26; // of@29
    char obj_flag; // [sp+2Fh] [bp-2Dh]@5
    float y; // [sp+30h] [bp-2Ch]@13
    float ya; // [sp+30h] [bp-2Ch]@27
    float x; // [sp+34h] [bp-28h]@11
    float xa; // [sp+34h] [bp-28h]@25
    RGE_Map *obj_density; // [sp+38h] [bp-24h]@5
    int v33; // [sp+3Ch] [bp-20h]@8
    _WORD *v34; // [sp+40h] [bp-1Ch]@2
    int i; // [sp+44h] [bp-18h]@1
    int terrain; // [sp+48h] [bp-14h]@1
    RGE_Map *v37; // [sp+4Ch] [bp-10h]@1
    int v38; // [sp+50h] [bp-Ch]@1
    int end_i; // [sp+58h] [bp-4h]@1

    v7 = row;
    v8 = this;
    v37 = this;
    v9 = RGE_Map::get_terrain(this, col, row);
    v10 = v9;
    terrain = v9;
    v11 = v8->terrain_types[v9].num_obj_type;
    v12 = (int)v8 + 408 * v9;
    v13 = 0;
    v38 = v12;
    end_i = v11;
    i = 0;
    if( v11 > 0 )
    {
        v34 = (_WORD *)(v12 + 394);
        while( 1 )
        {
            v14 = *v34;
            if( v14 != -1 )
            {
                v15 = obj_owner->master_objects[v14];
                LOWORD(v8) = v8->terrain_types[0].obj_density[v13 + 204 * v10];
                v16 = *(_BYTE *)(v13 + v38 + 514);
                obj_density = v8;
                obj_flag = v16;
                if( v15 )
                {
                    if( FillFlag )
                    {
                        if( v15 && FillFlag == 1 )
                        {
                            if( v16 )
                            {
                                v22 = (double)v7 - -0.5;
                                xa = (double)col - -0.5;
                            }
                            else
                            {
                                v23 = (double)col;
                                xa = v23 - (double)debug_rand(aCMsdevWorkA_31, 2223) * -0.000030518509;
                                v24 = (double)v7;
                                v22 = v24 - (double)debug_rand(aCMsdevWorkA_31, 2224) * -0.000030518509;
                            }
                            ya = v22;
                            if( !v15->vfptr->check_placement(
                                            v15,
                                            obj_owner,
                                            COERCE_FLOAT(LODWORD(xa)),
                                            COERCE_FLOAT(LODWORD(ya)),
                                            0,
                                            0,
                                            1,
                                            0,
                                            1,
                                            0,
                                            1) )
                            {
                                ((void (*)(RGE_Master_Static_Object *, RGE_Player *, float, float, _DWORD))v15->vfptr->make_new_obj)(
                                    v15,
                                    obj_owner,
                                    COERCE_FLOAT(LODWORD(xa)),
                                    COERCE_FLOAT(LODWORD(ya)),
                                    0);
                                return;
                            }
                            v7 = row;
                        }
                    }
                    else if( (signed short)v8 > 0 )
                    {
                        v33 = (signed short)v8;
                        while( 1 )
                        {
                            if( v16 )
                            {
                                v17 = (double)v7 - -0.5;
                                x = (double)col - -0.5;
                            }
                            else
                            {
                                v18 = (double)col;
                                x = v18 - (double)debug_rand(aCMsdevWorkA_31, 2196) * -0.000030518509;
                                v19 = (double)v7;
                                v17 = v19 - (double)debug_rand(aCMsdevWorkA_31, 2197) * -0.000030518509;
                            }
                            y = v17;
                            if( (signed short)v8 < 1000 )
                                v20 = 1000 * debug_rand(aCMsdevWorkA_31, 2210) / 0x7FFF < v33;
                            else
                                v20 = 1;
                            if( v20 )
                            {
                                v21 = v15->vfptr;
                                if( !v15->vfptr->check_placement(
                                                v15,
                                                obj_owner,
                                                COERCE_FLOAT(LODWORD(x)),
                                                COERCE_FLOAT(LODWORD(y)),
                                                0,
                                                0,
                                                1,
                                                0,
                                                1,
                                                0,
                                                1) )
                                    ((void (*)(RGE_Master_Static_Object *, RGE_Player *, float, float, _DWORD))v21->make_new_obj)(
                                        v15,
                                        obj_owner,
                                        COERCE_FLOAT(LODWORD(x)),
                                        COERCE_FLOAT(LODWORD(y)),
                                        0);
                                v8 = obj_density;
                                v7 = row;
                            }
                            v8 = (RGE_Map *)((char *)v8 - 1000);
                            obj_density = v8;
                            v33 -= 1000;
                            if( (signed short)v8 <= 0 )
                                break;
                            v16 = obj_flag;
                        }
                    }
                }
            }
            v13 = i + 1;
            v26 = __OFSUB__(i + 1, end_i);
            v25 = i++ + 1 - end_i < 0;
            ++v34;
            if( !(v25 ^ v26) )
                return;
            v10 = terrain;
            v8 = v37;
        }
    }
}

//----- (00458FD0) --------------------------------------------------------
void RGE_Map::create_terrain_objects(RGE_Player *obj_owner, RGE_Game_World *gworld)
{
    RGE_Map *v3; // edi@1
    short v4; // bx@1
    short v5; // si@2

    v3 = this;
    v4 = 0;
    if( this->map_height > 0 )
    {
        do
        {
            v5 = 0;
            if( v3->map_width > 0 )
            {
                do
                    RGE_Map::create_terrain_object(v3, obj_owner, gworld, v4, v5++, -1, 0, -1, -1);
                while( v5 < v3->map_width );
            }
            ++v4;
        }
        while( v4 < v3->map_height );
    }
}

//----- (00459020) --------------------------------------------------------
void RGE_Map::set_tile_size(char tile_type, short width, short height, short y_delta)
{
    char *v5; // eax@1

    v5 = (char *)this + 6 * (unsigned __int8)tile_type;
    *((_WORD *)&this->vfptr + 3 * ((unsigned __int8)tile_type + 4)) = width;
    *((_WORD *)v5 + 13) = height;
    *((_WORD *)v5 + 14) = y_delta;
}

//----- (00459060) --------------------------------------------------------
void RGE_Map::tile_map_coords(short x, short y, RGE_Tile *tile, float *offset_x, float *offset_y)
{
    double v6; // st7@1
    double v7; // st6@1
    double v8; // st5@3
    double v9; // st5@7
    char v11; // c0@7
    double v12; // st4@9
    double v13; // st5@9
    double v14; // st4@9
    double v15; // st7@33
    double v16; // st5@33
    double z; // [sp+0h] [bp-10h]@1
    double v18; // [sp+8h] [bp-8h]@1

    z = 0.0;
    v6 = (double)x / (double)this->tile_width;
    v18 = (double)y;
    v7 = v18 / (double)this->tile_height;
    switch ( tile->tile_type )
    {
        case 1:
            if( v6 <= 0.5 )
                v8 = v7 + v7 - (0.5 - v6 + 0.5 - v6);
            else
                v8 = v7 + v7 - (v6 - 0.5 + v6 - 0.5);
            goto LABEL_32;
        case 2:
            if( v6 <= 0.5 )
                goto LABEL_26;
            v8 = v6 * -0.5 - (v7 - 0.5);
            goto LABEL_32;
        case 3:
            v9 = 1.0 - v6;
            if( v11 )
            {
                v8 = v9 * 0.5 - (v7 - 0.5);
            }
            else
            {
                v12 = v9;
                v13 = v7 + v7;
                v14 = v12 + v12 - 1.0;
LABEL_31:
                v8 = v13 + v14;
            }
            goto LABEL_32;
        case 4:
            if( (1.0 - v6) * 0.5 >= v18 )
                goto LABEL_27;
            v8 = v6 * 0.5 - (v7 - 0.5);
            goto LABEL_32;
        case 0xA:
            if( v7 >= 1.0 )
            {
                z = -1.0;
            }
            else
            {
                v8 = -v7;
LABEL_32:
                z = v8;
            }
            break;
        case 0xB:
            if( v6 > 0.5 )
                goto LABEL_19;
            v8 = 0.5 - v6 + 0.5 - v6;
            goto LABEL_32;
        case 0xC:
            if( v6 <= 0.5 )
                goto LABEL_19;
            v8 = v6 - 0.5 + v6 - 0.5;
            goto LABEL_32;
        case 0:
        case 9:
LABEL_19:
            z = 0.0;
            break;
        case 0xD:
            if( v6 <= 0.5 )
                v8 = 0.5 - v6 + v7 + 0.5 - v6 + v7;
            else
                v8 = v6 - 0.5 + v7 + v6 - 0.5 + v7;
            goto LABEL_32;
        case 0xE:
            if( v6 > 0.5 )
                goto LABEL_26;
            goto LABEL_29;
        case 0xF:
            if( v18 > 1.0 - v6 * 0.5 )
                goto LABEL_26;
            goto LABEL_27;
        case 8:
LABEL_26:
            v8 = (1.0 - v6) * -0.5 - (v7 - 0.5);
            goto LABEL_32;
        case 7:
LABEL_27:
            v13 = v7 + v7;
            v14 = v6 + v6 - 1.0;
            goto LABEL_31;
        case 0x10:
            if( v18 > 1.0 - (1.0 - v6) * 0.5 )
                goto LABEL_29;
            goto LABEL_30;
        case 6:
LABEL_29:
            v8 = v6 * -0.5 - (v7 - 0.5);
            goto LABEL_32;
        case 5:
LABEL_30:
            v14 = v7 + v7;
            v13 = 1.0 - (v6 + v6);
            goto LABEL_31;
        default:
            break;
    }
    v15 = v6 + v6;
    v16 = (v15 - (1.0 - (v7 + v7)) + z) * 0.5;
    *offset_y = v16;
    *offset_x = v15 - v16;
}

//----- (004593A0) --------------------------------------------------------
bool RGE_Map::check_map_coords(short mapcol, short maprow)
{
    return mapcol >= 0 && mapcol < this->map_width && maprow >= 0 && maprow < this->map_height;
}

//----- (004593D0) --------------------------------------------------------
unsigned __int8 RGE_Map::get_elev(short mapcol, short maprow)
{
    unsigned __int8 result; // al@1

    result = *((_BYTE *)&this->map_row_offset[maprow][mapcol] + 5) >> 5;
    if( result > 8u )
        result = 0;
    return result;
}

//----- (00459400) --------------------------------------------------------
unsigned __int8 RGE_Map::get_terrain(short mapcol, short maprow)
{
    RGE_Tile *v3; // edx@1
    unsigned __int8 result; // al@1
    char *v5; // ecx@2

    v3 = this->map_row_offset[maprow];
    result = *((_BYTE *)&v3[mapcol] + 5) & 0x1F;
    if( result > 0x20u
        || (v5 = (char *)this + 408 * (*((_BYTE *)&v3[mapcol] + 5) & 0x1F), !v5[140]) && *((_WORD *)v5 + 162) < 0 )
    {
        result = 0;
    }
    return result;
}

//----- (00459460) --------------------------------------------------------
unsigned __int8 RGE_Map::get_border(short mapcol, short maprow)
{
    RGE_Tile *v3; // edx@1
    unsigned __int8 result; // al@1

    v3 = this->map_row_offset[maprow];
    result = *((_BYTE *)&v3[mapcol] + 6) & 0xF;
    if( result > 0x10u || !this->border_types[*((_BYTE *)&v3[mapcol] + 6) & 0xF].loaded )
        result = 0;
    return result;
}

//----- (004594B0) --------------------------------------------------------
void RGE_Map::set_terrain_passablity(int mapcol1, short maprow1, int mapcol2, short maprow2, char passabilty)
{
    short v6; // dx@1
    short v7; // si@1
    RGE_Map *v8; // ebp@1
    int v9; // ecx@3
    int v10; // eax@3
    int v11; // edx@16
    int v12; // ecx@16
    RGE_Tile *v13; // eax@17
    char v14; // dl@17
    int v15; // eax@17
    int v16; // edi@17
    int v17; // esi@17
    char v18; // bl@18
    bool v19; // zf@22
    int v20; // [sp+10h] [bp-4h]@14
    int maprow1a; // [sp+1Ch] [bp+8h]@14
    int maprow2a; // [sp+24h] [bp+10h]@16

    v6 = maprow2;
    v7 = maprow1;
    v8 = this;
    if( maprow1 > maprow2 )
    {
        v6 = maprow1;
        v7 = maprow2;
    }
    LOWORD(v9) = mapcol1;
    v10 = mapcol2;
    if( (signed short)mapcol1 > (signed short)mapcol2 )
    {
        v10 = mapcol1;
        v9 = mapcol2;
        mapcol2 = mapcol1;
        mapcol1 = v9;
    }
    if( v7 < 0 )
        v7 = 0;
    if( v6 >= v8->map_height )
        v6 = LOWORD(v8->map_height) - 1;
    if( (signed short)v9 < 0 )
    {
        LOWORD(v9) = 0;
        mapcol1 = 0;
    }
    if( (signed short)v10 >= v8->map_width )
    {
        LOWORD(v10) = LOWORD(v8->map_width) - 1;
        mapcol2 = v10;
    }
    if( v7 <= v6 )
    {
        maprow1a = v7;
        v20 = v6 - v7 + 1;
        do
        {
            if( (signed short)v9 <= (signed short)v10 )
            {
                v11 = (signed short)v9;
                v12 = (signed short)v9;
                maprow2a = (signed short)v10 - v11 + 1;
                do
                {
                    v13 = v8->map_row_offset[maprow1a];
                    v14 = *((_BYTE *)&v13[v12] + 5);
                    v15 = (int)&v13[v12].screen_xpos;
                    v16 = v14 & 0x1F;
                    v17 = v14 & 0x1F;
                    if( passabilty )
                        v18 = *(&v8->terrain_types[0].passable_terrain + 24 * (v16 + 16 * v17));
                    else
                        v18 = *(&v8->terrain_types[0].impassable_terrain + 24 * (v16 + 16 * v17));
                    ++v12;
                    *(_BYTE *)(v15 + 5) = v14 ^ (v14 ^ v18) & 0x1F;
                    --maprow2a;
                }
                while( maprow2a );
                LOWORD(v9) = mapcol1;
                LOWORD(v10) = mapcol2;
            }
            v19 = v20 == 1;
            ++maprow1a;
            --v20;
        }
        while( !v19 );
    }
}

//----- (004595E0) --------------------------------------------------------
void RGE_Map::set_elev(int mapcol1, int maprow1, int mapcol2, int maprow2, short elev, short delta, short set_flag)
{
    RGE_Map *v8; // ebx@1
    int v9; // eax@1
    int v10; // edi@3
    int v11; // edx@3
    int v12; // eax@7
    int v13; // eax@11
    int v14; // eax@15
    int v15; // ecx@15
    int v16; // ebp@16
    int v17; // esi@18
    int v18; // edi@18
    int v19; // ecx@19
    short v20; // ax@19
    unsigned __int8 v21; // al@23
    int v22; // ebp@32
    int v23; // esi@34
    int v24; // edi@34
    int v25; // eax@35
    int v26; // ebp@50
    int v27; // esi@51
    int i; // esi@51
    bool v29; // zf@57
    bool v30; // sf@57
    unsigned __int8 v31; // of@57
    int v32; // esi@59
    int v33; // ebp@59
    int v34; // [sp+10h] [bp-8h]@48
    RGE_Player *cur_player; // [sp+14h] [bp-4h]@1
    int eleva; // [sp+2Ch] [bp+14h]@16
    int elevb; // [sp+2Ch] [bp+14h]@50
    int elevc; // [sp+2Ch] [bp+14h]@59
    int deltaa; // [sp+30h] [bp+18h]@48
    int set_flaga; // [sp+34h] [bp+1Ch]@32
    int set_flagb; // [sp+34h] [bp+1Ch]@47

    v8 = this;
    cur_player = this->game_world->players[this->game_world->curr_player];
    v9 = maprow2;
    if( (signed short)maprow1 > (signed short)maprow2 )
    {
        maprow2 = maprow1;
        maprow1 = v9;
    }
    v10 = mapcol1;
    v11 = mapcol2;
    if( (signed short)mapcol1 > (signed short)mapcol2 )
    {
        mapcol1 = mapcol2;
        mapcol2 = v10;
        v11 = v10;
        v10 = mapcol1;
    }
    if( (signed short)maprow1 < 0 )
        maprow1 = 0;
    v12 = (signed short)maprow2;
    if( (signed short)maprow2 >= this->map_height )
    {
        LOWORD(v12) = LOWORD(this->map_height) - 1;
        maprow2 = v12;
    }
    if( (signed short)v10 < 0 )
    {
        mapcol1 = 0;
        v10 = 0;
    }
    v13 = (signed short)v11;
    if( (signed short)v11 >= this->map_width )
    {
        LOWORD(v13) = LOWORD(this->map_width) - 1;
        mapcol2 = v13;
        v11 = v13;
    }
    if( !(_BYTE)set_flag )
        goto LABEL_38;
    if( delta )
    {
        v14 = maprow1;
        v15 = maprow2;
        if( (signed short)maprow1 > (signed short)maprow2 )
            goto LABEL_39;
        v16 = (signed short)maprow1;
        eleva = (signed short)maprow2 - (signed short)maprow1 + 1;
        do
        {
            if( (signed short)v10 <= (signed short)v11 )
            {
                v17 = (signed short)v10;
                v18 = (signed short)v11 - (signed short)v10 + 1;
                do
                {
                    v19 = (int)&v8->map_row_offset[v16][v17].screen_xpos;
                    v20 = delta + (unsigned __int8)(*(_BYTE *)(v19 + 5) >> 5);
                    if( v20 >= 0 )
                    {
                        if( v20 > 255 )
                            LOBYTE(v20) = -1;
                    }
                    else
                    {
                        LOBYTE(v20) = 0;
                    }
                    v21 = *(_BYTE *)(v19 + 5) & 0x1F | 32 * v20;
                    *(_BYTE *)(v19 + 5) = v21;
                    if( (unsigned __int8)(v21 >> 5) > 8u )
                        *(_BYTE *)(v19 + 5) = v21 & 0x1F;
                    ++v17;
                    --v18;
                }
                while( v18 );
                v11 = mapcol2;
                v10 = mapcol1;
            }
            ++v16;
            --eleva;
        }
        while( eleva );
        goto LABEL_38;
    }
    if( (unsigned __int8)elev > 8u )
        LOBYTE(elev) = 8;
    v14 = maprow1;
    v15 = maprow2;
    if( (signed short)maprow1 <= (signed short)maprow2 )
    {
        v22 = (signed short)maprow1;
        set_flaga = (signed short)maprow2 - (signed short)maprow1 + 1;
        do
        {
            if( (signed short)v10 <= (signed short)v11 )
            {
                v23 = (signed short)v10;
                v24 = (signed short)v11 - (signed short)v10 + 1;
                do
                {
                    v25 = (int)&v8->map_row_offset[v22][v23].screen_xpos;
                    ++v23;
                    --v24;
                    *(_BYTE *)(v25 + 5) = 32 * elev | *(_BYTE *)(v25 + 5) & 0x1F;
                }
                while( v24 );
                v11 = mapcol2;
                v10 = mapcol1;
            }
            ++v22;
            --set_flaga;
        }
        while( set_flaga );
LABEL_38:
        v14 = maprow1;
        v15 = maprow2;
    }
LABEL_39:
    if( (signed short)v14 > 0 )
        maprow1 = --v14;
    if( (signed short)v15 < v8->map_height - 1 )
        maprow2 = ++v15;
    if( (signed short)v10 > 0 )
        mapcol1 = --v10;
    if( (signed short)v11 < v8->map_width - 1 )
        mapcol2 = ++v11;
    set_flagb = v14;
    if( (signed short)v14 <= (signed short)v15 )
    {
        deltaa = (signed short)v14;
        v34 = (signed short)v14;
        do
        {
            if( (signed short)v10 <= (signed short)v11 )
            {
                elevb = (signed short)v10;
                v26 = (signed short)v10;
                do
                {
                    v27 = (int)&v8->map_row_offset[v34][v26].screen_xpos;
                    *(_BYTE *)(v27 + 4) = RGE_Map::get_tile_type(v8, v10, v10, set_flagb);
                    for( i = *(_DWORD *)(v27 + 16); i; i = *(_DWORD *)(i + 4) )
                        (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD))(**(_DWORD **)i + 52))(
                            *(_DWORD *)(*(_DWORD *)i + 56),
                            *(_DWORD *)(*(_DWORD *)i + 60),
                            0);
                    if( v8->game_world->game_state != 3 )
                        RGE_Tile_List::add_node(&cur_player->diam_tile_list, elevb, deltaa);
                    ++v10;
                    ++v26;
                    ++elevb;
                }
                while( (signed short)v10 <= (signed short)mapcol2 );
                LOWORD(v11) = mapcol2;
                v10 = mapcol1;
            }
            ++deltaa;
            LOWORD(v15) = maprow2;
            v31 = __OFSUB__(set_flagb + 1, (_WORD)maprow2);
            v29 = (_WORD)set_flagb + 1 == (_WORD)maprow2;
            v30 = (signed short)(set_flagb++ + 1 - maprow2) < 0;
            ++v34;
        }
        while( (unsigned __int8)(v30 ^ v31) | v29 );
        LOWORD(v14) = maprow1;
    }
    v32 = (signed short)v15;
    v33 = (signed short)v11;
    elevc = (signed short)v14;
    RGE_Map::set_map_screen_pos(v8, (signed short)v10, (signed short)v14, (signed short)v11, (signed short)v15);
    RGE_Map::request_redraw(v8, (signed short)v10, elevc, v33, v32, 0);
}

//----- (00459900) --------------------------------------------------------
void RGE_Map::set_terrain(RGE_Game_World *gworld, short mapcol, short maprow, char terrain, int no_delete_start, int no_delete_end)
{
    RGE_Map *v7; // esi@1
    RGE_Tile *v8; // eax@1
    char v9; // cl@2
    int v10; // eax@5
    short old_terrain; // [sp+10h] [bp-Ch]@1
    RGE_Player *obj_owner; // [sp+14h] [bp-8h]@1
    RGE_Player *cur_player; // [sp+18h] [bp-4h]@1

    v7 = this;
    obj_owner = *gworld->players;
    cur_player = this->game_world->players[this->game_world->curr_player];
    v8 = this->map_row_offset[maprow];
    old_terrain = *((_BYTE *)&v8[mapcol] + 5) & 0x1F;
    if( old_terrain != (unsigned __int8)terrain
        && (v9 = *((_BYTE *)&v8[mapcol] + 5), *((_BYTE *)&v8[mapcol] + 5) = v9 ^ (v9 ^ terrain) & 0x1F, obj_owner) )
    {
        RGE_Map::request_redraw(v7, mapcol, maprow, mapcol, maprow, 0);
        if( gworld->game_state != 3 )
            RGE_Tile_List::add_node(&cur_player->diam_tile_list, mapcol, maprow);
        v10 = RGE_Map::clear_terrain_object(v7, gworld, maprow, mapcol, old_terrain, 1, no_delete_start, no_delete_end);
        RGE_Map::place_terrain_object(v7, obj_owner, gworld, maprow, mapcol, v10, 0);
        RGE_Map::get_border_type(v7, mapcol, maprow);
    }
    else
    {
        RGE_Map::get_border_type(v7, mapcol, maprow);
    }
}

//----- (00459A00) --------------------------------------------------------
void RGE_Map::set_terrain_absolute(RGE_Game_World *gworld, short mapcol, short maprow, char terrain, int no_delete_start, int no_delete_end)
{
    RGE_Map *v7; // esi@1
    RGE_Tile *v8; // ebp@1
    int v9; // eax@2
    RGE_Player *obj_owner; // [sp+10h] [bp-4h]@1

    v7 = this;
    obj_owner = *gworld->players;
    v8 = &this->map_row_offset[maprow][mapcol];
    *((_BYTE *)v8 + 5) ^= (*((_BYTE *)v8 + 5) ^ terrain) & 0x1F;
    if( obj_owner )
    {
        v9 = RGE_Map::clear_terrain_object(this, gworld, maprow, mapcol, -1, 1, no_delete_start, no_delete_end);
        RGE_Map::place_terrain_object(v7, obj_owner, gworld, maprow, mapcol, v9, 1);
    }
    RGE_Map::get_border_type(v7, mapcol, maprow);
}

//----- (00459A90) --------------------------------------------------------
void RGE_Map::set_terrain(RGE_Player *obj_owner, RGE_Game_World *gworld, int mapcol1, int maprow1, int mapcol2, int maprow2, char terrain, char set_flag, int delete_obj)
{
    RGE_Map *v10; // edi@1
    short v11; // ax@3
    int v12; // eax@5
    int v13; // eax@7
    int v14; // eax@15
    int v15; // ebp@19
    int v16; // esi@19
    int v17; // edx@20
    int v18; // ebx@20
    int v19; // ecx@20
    short v20; // bp@21
    _BYTE *v21; // esi@22
    short v22; // cx@24
    short maprow; // [sp+14h] [bp-10h]@19
    int v24; // [sp+1Ch] [bp-8h]@20

    v10 = this;
    if( (unsigned __int8)terrain >= this->num_terrain )
        return;
    if( !this->terrain_types[(unsigned __int8)terrain].loaded )
    {
        v11 = this->terrain_types[(unsigned __int8)terrain].terrain_to_draw;
        if( v11 <= -1 || this->terrain_types[v11].loaded != 1 )
            return;
    }
    v12 = maprow2;
    if( (signed short)maprow1 > (signed short)maprow2 )
    {
        maprow2 = maprow1;
        maprow1 = v12;
    }
    v13 = mapcol2;
    if( (signed short)mapcol1 > (signed short)mapcol2 )
    {
        mapcol2 = mapcol1;
        mapcol1 = v13;
    }
    if( (signed short)maprow1 < 0 )
        maprow1 = 0;
    if( (signed short)maprow2 >= this->map_height )
    {
        LOWORD(v13) = LOWORD(this->map_height) - 1;
        maprow2 = v13;
    }
    if( (signed short)mapcol1 < 0 )
        mapcol1 = 0;
    v14 = (signed short)mapcol2;
    if( (signed short)mapcol2 >= this->map_width )
    {
        LOWORD(v14) = LOWORD(this->map_width) - 1;
        mapcol2 = v14;
    }
    if( !set_flag && !obj_owner )
    {
        v16 = mapcol1;
        v17 = mapcol2;
LABEL_35:
        v15 = maprow1;
        goto LABEL_36;
    }
    v15 = maprow1;
    v16 = mapcol1;
    maprow = maprow1;
    if( (signed short)maprow1 <= (signed short)maprow2 )
    {
        v17 = mapcol2;
        v18 = (signed short)mapcol1;
        v19 = 4 * (signed short)maprow1;
        v24 = 4 * (signed short)maprow1;
        do
        {
            v20 = v16;
            if( (signed short)v16 <= (signed short)v17 )
            {
                v21 = (char *)&(*(RGE_Tile **)((char *)v10->map_row_offset + v19))[v18] + 5;
                do
                {
                    if( *((_WORD *)&v10->vfptr + 3 * (*(v21 - 1) + 68 * (unsigned __int8)terrain + 35)) > 0 )
                    {
                        v22 = *v21 & 0x1F;
                        if( v22 != (unsigned __int8)terrain && set_flag )
                            *v21 ^= (*v21 ^ terrain) & 0x1F;
                        if( obj_owner )
                            RGE_Map::create_terrain_object(v10, obj_owner, gworld, maprow, v20, v22, delete_obj, -1, -1);
                    }
                    v17 = mapcol2;
                    ++v20;
                    v21 += 24;
                }
                while( v20 <= (signed short)mapcol2 );
                v19 = v24;
                v18 = (signed short)mapcol1;
                v16 = mapcol1;
            }
            v19 += 4;
            ++maprow;
            v24 = v19;
        }
        while( maprow <= (signed short)maprow2 );
        goto LABEL_35;
    }
    v17 = mapcol2;
LABEL_36:
    if( (signed short)v15 > 0 )
        maprow1 = --v15;
    if( (signed short)maprow2 < v10->map_height - 1 )
        ++maprow2;
    if( (signed short)v16 > 0 )
        mapcol1 = --v16;
    if( (signed short)v17 < v10->map_width - 1 )
        mapcol2 = ++v17;
    if( (signed short)maprow1 <= (signed short)maprow2 )
    {
        do
        {
            if( (signed short)v16 <= (signed short)v17 )
            {
                do
                {
                    RGE_Map::get_border_type(v10, v16, v15);
                    LOWORD(v16) = v16 + 1;
                }
                while( (signed short)v16 <= (signed short)mapcol2 );
            }
            LOWORD(v16) = mapcol1;
            LOWORD(v17) = mapcol2;
            LOWORD(v15) = v15 + 1;
        }
        while( (signed short)v15 <= (signed short)maprow2 );
    }
    RGE_Map::request_redraw(
        v10,
        (signed short)v16,
        (signed short)maprow1,
        (signed short)v17,
        (signed short)maprow2,
        0);
}

char RGE_Map::get_tile_type(short map_col, short map_row)
{
    short v4; // bx@3
    int v5; // edx@4
    RGE_Tile **v6; // esi@5
    int v7; // eax@5
    int v8; // ebp@5
    short v9; // cx@16
    short v10; // bx@24
    char result; // al@35
    short ecl; // [sp+10h] [bp-24h]@5
    int v13; // [sp+14h] [bp-20h]@2
    int etr; // [sp+18h] [bp-1Ch]@2
    short etra; // [sp+18h] [bp-1Ch]@14
    int v16; // [sp+1Ch] [bp-18h]@4
    short etl; // [sp+20h] [bp-14h]@11
    short et; // [sp+24h] [bp-10h]@7
    short eb; // [sp+28h] [bp-Ch]@18
    int v20; // [sp+2Ch] [bp-8h]@13
    short ech; // [sp+30h] [bp-4h]@5
    int map_cola; // [sp+38h] [bp+4h]@21
    int ebl; // [sp+3Ch] [bp+8h]@28

    if( map_col < 0 )
        return 0;
    v13 = map_col;
    etr = this->map_width;
    if( map_col >= this->map_width )
        return 0;
    v4 = map_row;
    if( map_row < 0 )
        return 0;
    v5 = map_row;
    v16 = this->map_height;
    if( map_row >= this->map_height )
        return 0;
    v6 = this->map_row_offset;
    v7 = map_col;
    v8 = (int)&v6[map_row][v7].screen_xpos;
    LOWORD(a2) = (unsigned __int8)(*(_BYTE *)(v8 + 5) >> 5);
    ech = a2 + 1;
    ecl = a2 - 1;
    if( map_row > 0 )
    {
        if( map_col < etr - 1 )
        {
            v4 = map_row;
            et = (unsigned __int8)(*((_BYTE *)&v6[map_row - 1][v7 + 1] + 5) >> 5);
            goto LABEL_10;
        }
        v4 = map_row;
    }
    et = (unsigned __int8)(*(_BYTE *)(v8 + 5) >> 5);
LABEL_10:
    if( v4 <= 0 )
        etl = (unsigned __int8)(*(_BYTE *)(v8 + 5) >> 5);
    else
        etl = (unsigned __int8)(*((_BYTE *)&v6[map_row - 1][v7] + 5) >> 5);
    v20 = etr - 1;
    if( map_col >= etr - 1 )
        etra = (unsigned __int8)(*(_BYTE *)(v8 + 5) >> 5);
    else
        etra = (unsigned __int8)(*(_BYTE *)(v8 + 29) >> 5);
    v9 = map_col;
    if( map_col <= 0 || map_row >= v16 - 1 )
        eb = (unsigned __int8)(*(_BYTE *)(v8 + 5) >> 5);
    else
        eb = (unsigned __int8)(*((_BYTE *)&v6[map_row + 1][v7] - 19) >> 5);
    if( map_col <= 0 )
        map_cola = a2;
    else
        LOWORD(map_cola) = (unsigned __int8)(*(_BYTE *)(v8 - 19) >> 5);
    if( map_row >= v16 - 1 )
        v10 = (unsigned __int8)(*(_BYTE *)(v8 + 5) >> 5);
    else
        v10 = (unsigned __int8)(*((_BYTE *)&v6[map_row + 1][v7] + 5) >> 5);
    if( map_row <= 0 || v9 <= 0 )
        ebl = a2;
    else
        LOWORD(ebl) = (unsigned __int8)(*((_BYTE *)&v6[map_row - 1][v7] - 19) >> 5);
    if( v5 < v16 - 1 && v13 < v20 )
        LOWORD(a2) = (unsigned __int8)(*((_BYTE *)&v6[v5 + 1][v7 + 1] + 5) >> 5);
    if( etl == ech && etra == ech )
        return 14;
    if( (_WORD)map_cola == ech && v10 == ech )
        return 13;
    if( etl == ech && (_WORD)map_cola == ech )
        return 16;
    if( etra == ech && v10 == ech )
        return 15;
    if( etl == ech )
        return 6;
    if( etra == ech )
        return 8;
    if( (_WORD)map_cola == ech )
        return 5;
    if( v10 == ech )
        return 7;
    if( et == ech )
    {
        if( (_WORD)map_cola != ecl || v10 != ecl )
            result = 10;
        else
            result = 2;
        return result;
    }
    if( eb == ech )
    {
        if( etl != ecl || etra != ecl )
            result = 9;
        else
            result = 1;
        return result;
    }
    if( (_WORD)ebl == ech )
    {
        if( etra != ecl || v10 != ecl )
            result = 11;
        else
            result = 3;
        return result;
    }
    if( (_WORD)a2 != ech )
        return 0;
    if( etl != ecl || (_WORD)map_cola != ecl )
        result = 12;
    else
        result = 4;
    return result;
}

//----- (0045A030) --------------------------------------------------------
void RGE_Map::get_border_type(short map_col, short map_row)
{
    RGE_Map *v3; // edi@1
    int v4; // ecx@2
    int v5; // ecx@4
    RGE_Tile **v6; // esi@5
    int v7; // eax@5
    char v8; // bl@5
    int v9; // ebp@25
    char v10; // si@33
    unsigned __int8 v11; // al@33
    int v12; // ecx@41
    short v13; // ax@41
    int v14; // edx@44
    char v15; // dl@46
    short v16; // bx@55
    char v17; // cl@57
    short v18; // di@61
    char v19; // dl@83
    int ter_top; // [sp+10h] [bp-28h]@6
    int ter_lft; // [sp+14h] [bp-24h]@12
    int ter_rgt; // [sp+18h] [bp-20h]@15
    int ter_bot; // [sp+1Ch] [bp-1Ch]@9
    RGE_Tile *tile; // [sp+20h] [bp-18h]@5
    int ter_top_lft; // [sp+24h] [bp-14h]@19
    int ter_bot_lft; // [sp+28h] [bp-10h]@8
    int ter_bot_rgt; // [sp+2Ch] [bp-Ch]@2
    int v28; // [sp+30h] [bp-8h]@14
    int ter_cur; // [sp+34h] [bp-4h]@5
    char map_cola; // [sp+3Ch] [bp+4h]@54

    v3 = this;
    if( map_col < 0 )
        return;
    v4 = this->map_width;
    ter_bot_rgt = map_col;
    if( map_col >= v4 )
        return;
    if( map_row < 0 )
        return;
    v5 = map_row;
    if( map_row >= v3->map_height )
        return;
    v6 = v3->map_row_offset;
    v7 = map_col;
    tile = &v6[map_row][v7];
    v8 = *((_BYTE *)tile + 5) & 0x1F;
    LOBYTE(ter_cur) = *((_BYTE *)tile + 5) & 0x1F;
    if( map_row <= 0 )
        LOBYTE(ter_top) = v8;
    else
        LOBYTE(ter_top) = *((_BYTE *)&v6[map_row - 1][v7] + 5) & 0x1F;
    ter_bot_lft = v3->map_height - 1;
    if( map_row >= ter_bot_lft )
        LOBYTE(ter_bot) = v8;
    else
        LOBYTE(ter_bot) = *((_BYTE *)&v6[map_row + 1][v7] + 5) & 0x1F;
    if( map_col <= 0 )
        LOBYTE(ter_lft) = v8;
    else
        LOBYTE(ter_lft) = *((_BYTE *)&v6[map_row][v7] - 19) & 0x1F;
    v28 = v3->map_width - 1;
    if( ter_bot_rgt >= v28 )
        LOBYTE(ter_rgt) = v8;
    else
        LOBYTE(ter_rgt) = *((_BYTE *)&v6[map_row][v7 + 1] + 5) & 0x1F;
    if( map_row <= 0 || map_col <= 0 )
        LOBYTE(ter_top_lft) = v8;
    else
        LOBYTE(ter_top_lft) = *((_BYTE *)&v6[map_row - 1][v7] - 19) & 0x1F;
    if( map_row <= 0 || ter_bot_rgt >= v28 )
        LOBYTE(map_row) = v8;
    else
        LOBYTE(map_row) = *((_BYTE *)&v6[map_row - 1][v7 + 1] + 5) & 0x1F;
    v9 = ter_bot_lft;
    if( v5 >= ter_bot_lft || map_col <= 0 )
        LOBYTE(ter_bot_lft) = v8;
    else
        LOBYTE(ter_bot_lft) = *((_BYTE *)&v6[v5 + 1][v7] - 19) & 0x1F;
    if( v5 >= v9 || ter_bot_rgt >= v28 )
        LOBYTE(ter_bot_rgt) = v8;
    else
        LOBYTE(ter_bot_rgt) = *((_BYTE *)&v6[v5 + 1][v7 + 1] + 5) & 0x1F;
    v10 = ter_cur;
    RGE_Map::check_for_border(v3, ter_cur, (char *)&ter_top);
    RGE_Map::check_for_border(v3, v10, (char *)&ter_bot);
    RGE_Map::check_for_border(v3, v10, (char *)&ter_lft);
    RGE_Map::check_for_border(v3, v10, (char *)&ter_rgt);
    RGE_Map::check_for_border(v3, v10, (char *)&ter_top_lft);
    RGE_Map::check_for_border(v3, v10, (char *)&map_row);
    RGE_Map::check_for_border(v3, v10, (char *)&ter_bot_lft);
    RGE_Map::check_for_border(v3, v10, (char *)&ter_bot_rgt);
    v11 = ter_top;
    if( (_BYTE)ter_top == v8 )
    {
        v11 = ter_bot;
        if( (_BYTE)ter_bot == v8 )
        {
            v11 = ter_lft;
            if( (_BYTE)ter_lft == v8 )
            {
                v11 = ter_rgt;
                if( (_BYTE)ter_rgt == v8 )
                {
                    v11 = ter_top_lft;
                    if( (_BYTE)ter_top_lft == v8 )
                    {
                        v11 = map_row;
                        if( (_BYTE)map_row == v8 )
                        {
                            v11 = ter_bot_lft;
                            if( (_BYTE)ter_bot_lft == v8 )
                            {
                                v11 = ter_bot_rgt;
                                if( (_BYTE)ter_bot_rgt == v8 )
                                {
                                    *((_BYTE *)tile + 6) = 0;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    v12 = (int)v3->terrain_types[(unsigned __int8)v10].borders;
    v13 = *(_WORD *)(v12 + 2 * v11);
    if( v13 == -1 || v13 < 0 || v13 >= 16 || (v14 = (int)v3 + 1440 * v13, !*(_BYTE *)(v14 + 13196)) )
    {
        *((_BYTE *)tile + 6) = 0;
        return;
    }
    if( *(_WORD *)(v14 + 14634) != 1 )
    {
        v16 = *(_WORD *)(v12 + 2 * (unsigned __int8)ter_top);
        if( v16 != v13 || *(_WORD *)(v12 + 2 * (unsigned __int8)ter_lft) != v13 )
        {
            if( v16 != v13 || *(_WORD *)(v12 + 2 * (unsigned __int8)ter_rgt) != v13 )
            {
                v18 = *(_WORD *)(v12 + 2 * (unsigned __int8)ter_bot);
                if( v18 == v13 )
                {
                    if( *(_WORD *)(v12 + 2 * (unsigned __int8)ter_lft) == v13 )
                    {
                        v17 = 3;
                        goto LABEL_83;
                    }
                    if( v18 == v13 && *(_WORD *)(v12 + 2 * (unsigned __int8)ter_rgt) == v13 )
                    {
                        v17 = 4;
                        goto LABEL_83;
                    }
                }
                if( v16 == v13 )
                {
                    v17 = 9;
                }
                else if( v18 == v13 )
                {
                    v17 = 10;
                }
                else if( *(_WORD *)(v12 + 2 * (unsigned __int8)ter_lft) == v13 )
                {
                    v17 = 11;
                }
                else if( *(_WORD *)(v12 + 2 * (unsigned __int8)ter_rgt) == v13 )
                {
                    v17 = 12;
                }
                else if( *(_WORD *)(v12 + 2 * (unsigned __int8)ter_top_lft) == v13 )
                {
                    v17 = 5;
                }
                else if( *(_WORD *)(v12 + 2 * (unsigned __int8)map_row) == v13 )
                {
                    v17 = 6;
                }
                else if( *(_WORD *)(v12 + 2 * (unsigned __int8)ter_bot_lft) == v13 )
                {
                    v17 = 7;
                }
                else
                {
                    if( *(_WORD *)(v12 + 2 * (unsigned __int8)ter_bot_rgt) != v13 )
                    {
                        *((_BYTE *)tile + 6) = 0;
                        return;
                    }
                    v17 = 8;
                }
            }
            else
            {
                v17 = 2;
            }
        }
        else
        {
            v17 = 1;
        }
LABEL_83:
        v19 = *((_BYTE *)tile + 6);
        *((_BYTE *)tile + 6) = 16 * v17 | v13 & 0xF;
        return;
    }
    v15 = 0;
    if( *(_WORD *)(v12 + 2 * (unsigned __int8)ter_top) == v13 )
        v15 = 1;
    if( *(_WORD *)(v12 + 2 * (unsigned __int8)ter_bot) == v13 )
        v15 += 2;
    if( *(_WORD *)(v12 + 2 * (unsigned __int8)ter_lft) == v13 )
        v15 += 4;
    if( *(_WORD *)(v12 + 2 * (unsigned __int8)ter_rgt) == v13 )
        v15 += 8;
    map_cola = *((_BYTE *)tile + 6);
    *((_BYTE *)tile + 6) = 16 * v15 | v13 & 0xF;
}

void RGE_Map::check_for_border(char cur_ter, char *bor_ter)
{
    short v3; // ax@2

    if( *bor_ter != cur_ter )
    {
        v3 = this->terrain_types[0].borders[(unsigned __int8)*bor_ter + 204 * (unsigned __int8)cur_ter];
        if( v3 == -1 || v3 < 0 || v3 >= 16 || !this->border_types[v3].loaded )
            *bor_ter = cur_ter;
    }
}

void RGE_Map::update(unsigned int world_time)
{
    RGE_Map *v2; // ebp@1
    int v3; // edx@2
    int v4; // esi@3
    double v5; // st7@4
    short v6; // di@5
    signed short v7; // cx@5
    signed __int64 v8; // rax@5
    int v9; // ecx@13
    int v10; // eax@14
    int v11; // esi@14
    double v12; // st7@15
    short v13; // di@16
    signed short v14; // cx@16
    signed __int64 v15; // rax@16
    int i; // [sp+8h] [bp-10h]@2
    int ia; // [sp+8h] [bp-10h]@13
    float cur_time; // [sp+Ch] [bp-Ch]@2

    v2 = this;
    if( world_time - last_world_time >= 0x64 )
    {
        v3 = 0;
        i = 0;
        cur_time = (double)world_time * 0.001;
        if( this->num_terrain > 0 )
        {
            do
            {
                v4 = (int)&v2->terrain_types[(signed short)v3].loaded;
                if( v2->terrain_types[(signed short)v3].is_animated )
                {
                    v5 = cur_time - v2->terrain_types[(signed short)v3].animate_last;
                    if( v5 >= v2->terrain_types[(signed short)v3].interval )
                    {
                        v8 = (signed __int64)(v5 / v2->terrain_types[(signed short)v3].interval);
                        v6 = *(_WORD *)(v4 + 48);
                        v7 = v6 + *(_WORD *)(v4 + 50);
                        WORD2(v8) = *(_WORD *)(v4 + 60) + v8;
                        if( SWORD2(v8) >= v7 )
                            SWORD2(v8) %= v7;
                        *(_WORD *)(v4 + 60) = WORD2(v8);
                        if( SWORD2(v8) >= v6 )
                            WORD2(v8) = v6 - 1;
                        if( *(_WORD *)(v4 + 62) != WORD2(v8) )
                        {
                            *(_WORD *)(v4 + 62) = WORD2(v8);
                            *(_BYTE *)(v4 + 68) = 1;
                            v2->any_frame_change = 1;
                        }
                        v3 = i;
                        *(float *)(v4 + 64) = cur_time - (v5 - (double)(signed short)v8 * *(float *)(v4 + 52));
                    }
                }
                i = ++v3;
            }
            while( (signed short)v3 < v2->num_terrain );
        }
        v9 = 0;
        ia = 0;
        if( v2->num_borders > 0 )
        {
            do
            {
                v10 = (signed short)v9;
                v11 = (int)&v2->border_types[v10].loaded;
                if( v2->border_types[v10].is_animated )
                {
                    v12 = cur_time - v2->border_types[v10].animate_last;
                    if( v12 >= v2->border_types[v10].interval )
                    {
                        v15 = (signed __int64)(v12 / v2->border_types[v10].interval);
                        v13 = *(_WORD *)(v11 + 44);
                        v14 = v13 + *(_WORD *)(v11 + 46);
                        WORD2(v15) = *(_WORD *)(v11 + 56) + v15;
                        if( SWORD2(v15) >= v14 )
                            SWORD2(v15) %= v14;
                        *(_WORD *)(v11 + 56) = WORD2(v15);
                        if( SWORD2(v15) >= v13 )
                            WORD2(v15) = v13 - 1;
                        if( *(_WORD *)(v11 + 58) != WORD2(v15) )
                        {
                            *(_WORD *)(v11 + 58) = WORD2(v15);
                            *(_BYTE *)(v11 + 64) = 1;
                            v2->any_frame_change = 1;
                        }
                        v9 = ia;
                        *(float *)(v11 + 60) = cur_time - (v12 - (double)(signed short)v15 * *(float *)(v11 + 48));
                    }
                }
                ia = ++v9;
            }
            while( (signed short)v9 < v2->num_borders );
        }
        last_world_time = world_time;
    }
}

void RGE_Map::get_point(short *screen_x, short *screen_y, float x, float y, float z, short x_offset, short y_offset)
{
    *screen_x = x_offset + (unsigned __int64)(signed __int64)((y + x) * (double)this->tile_half_width);
    *screen_y = (unsigned __int64)(signed __int64)((y - -1.0 - x - z) * (double)this->tile_half_height) + y_offset - 16;
}
