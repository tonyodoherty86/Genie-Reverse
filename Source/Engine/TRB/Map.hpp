#pragma once

/**
 * @file    Engine\TRB\Map.hpp
 * @author  Yvan Burrie
 * @date    2018/02/27
 * @version 1.0
 */

#include "RGE/Map.hpp"

class TRIBE_Map;
class RGE_Player_Info;
class TRIBE_Game;
class RGE_Map_Gen_Info;
class RGE_Static_Object;

struct TRIBE_Cliff_Info
{
    int info[4];
};

struct TRIBE_Master_Cliff_Info
{
    int id;
    int facet;
    int id2;
    int facet2;
    TRIBE_Cliff_Info info;
    float offset_x,
          offset_y;
};

class TRIBE_Map : public RGE_Map
{
public:

    TRIBE_Game *Game;

    RGE_Player *rge_player;

    RGE_Game_World *rge_game_world;

    RGE_Map_Gen_Info *rge_map_gen_information;

    char *zones;

    int old_cliff_x;
    int old_cliff_y;
    int safe_cliff_x;
    int safe_cliff_y;
    int old_cliff_direction;

    TRIBE_Master_Cliff_Info cliff_master_table[256];

    TRIBE_Map(int infile, RGE_Sound **sound, char setup);
    TRIBE_Map(char *border_tbl, char *overlay_tbl, char *terrain_tbl, char *map_tbl, short TileWid, short TileHgt, short ElevHgt, RGE_Sound **sound);

    ~TRIBE_Map();

    void save(int outfile);

    void map_generate(RGE_Player *owner, RGE_Game_World *gworld, RGE_Player_Info *player_info, char *zone_terrain);
    void map_generate(RGE_Player_Info *player_info);

    void data_load_random_map(int infile);
    void load_random_map(char *rmm_map_file, char *rmm_land_file, char *rmm_terr_file, char *rmm_obj_file);

    void check_tile_for_forest_change(short x, short y, RGE_Game_World *world);
    void change_terrain(short map_col, short map_row, char new_terrain, RGE_Game_World *world);

    char do_terrain_brush(int x, int y, int brush_size, char terrain_id);
    char do_terrain_brush_stroke(int x1, int y1, int x2, int y2, int brush_size, int terrain_id);
    char do_elevation_brush_stroke(int x1, int y1, int x2, int y2, int brush_size, int elevation_height);

    void setup_cliff_type(int r, int d, int l, int u, int id, int facet, int id2, int facet2, float offset_x, float offset_y);
    RGE_Static_Object *find_cliff(int x, int y);
    TRIBE_Cliff_Info *get_cliff_info(TRIBE_Cliff_Info *result, RGE_Static_Object *obj);
    bool check_cliff_valid(TRIBE_Cliff_Info info);
    RGE_Static_Object *make_new_cliff(int x, int y, TRIBE_Cliff_Info info);
    void remove_cliff_edge(int x, int y, int direction);
    int reverse_cliff_direction(int direction);
    int add_cliff_edge(int x, int y, int direction, int facing, int save_direction);
    void delete_cliff(int x, int y);
    char do_cliff_brush(int x, int y, char cliff_id, char delete_cliff_flag);
    char do_cliff_brush_stroke(int x1, int y1, int x2, int y2, int cliff_id, int delete_cliff);
    char water(char terrain);
    void clean_borders(int x1, int y1, int x2, int y2, char terrain_id);
    char do_terrain_brush_check(int x, int y);
    void tribe_clean_elevation(int x1, int y1, int x2, int y2);
    void tribe_clean_terrain(int x1, int y1, int x2, int y2, char check_terrain, char replacement_terrain);
};
