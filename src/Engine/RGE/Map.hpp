
/**
 * @file    Engine\RGE\Map.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Map;

struct RGE_Tile
{
    short screen_xpos;
    short screen_ypos;
    char tile_type;
    __int8 terrain_type : 5;
    __int8 height : 3;
    __int8 border_type : 4;
    __int8 border_shape : 4;
    char last_drawn_as;
    char last_drawn_shape;
    char draw_as;
    char draw_attribute;
    char last_drawn_shape2;
    int objects;
};

struct RGE_Tile_Size
{
    short width;
    short height;
    short y_delta;
};

struct RGE_TOB_Picts
{
    short count;
    short animations;
    short shape_index;
};

struct RGE_Tile_Set
{
    char loaded;
    char random;
    char name[13];
    char pict_name[13];
    int resource_id;
    TShape *shape;
    RGE_Sound *sound;
    char map_hi_color;
    char map_med_color;
    char map_low_color;
    char map_lt_cliff_color;
    char map_rt_cliff_color;
    char passable_terrain;
    char impassable_terrain;
    char is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    char frame_changed;
    char drawn;
    RGE_TOB_Picts tiles[19];
    short terrain_to_draw;
    short rows;
    short cols;
    short borders[32];
    short obj_types[30];
    short obj_density[30];
    char obj_placement_flag[30];
    short num_obj_type;
};

struct RGE_Border_Set
{
    char loaded;
    char random;
    char name[13];
    char pict_name[13];
    int resource_id;
    TShape *shape;
    RGE_Sound *sound;
    char map_hi_color;
    char map_med_color;
    char map_low_color;
    char is_animated;
    short animation_frames;
    short pause_frames;
    float interval;
    float pause_between_loops;
    short frame;
    short draw_frame;
    float animate_last;
    char frame_changed;
    char drawn;
    RGE_TOB_Picts borders[19][12];
    char draw_tile;
    short underlay_terrain;
    short border_style;
};

struct RGE_Overlay_Set : RGE_Border_Set/* TODO */
{

};

#define RGE_MAP_OVERLAY_TYPES_EXIST false

class RGE_Map
{
public:
    RGE_Tile *map;

    int map_width;
    int map_height;

    int world_width;
    int world_height;

    RGE_Tile_Size tilesizes[19];
    RGE_Tile_Set terrain_types[42];
    RGE_Border_Set border_types[16];
#if RGE_MAP_OVERLAY_TYPES_EXIST
    RGE_Overlay_Set overlay_types[16];
#endif
    RGE_Tile **map_row_offset;

    short num_terrain;
    short num_borders;
    short max_terrain;
#if RGE_MAP_OVERLAY_TYPES_EXIST
    short max_overlay;
#endif

    short tile_width;
    short tile_height;
    short tile_half_height;
    short tile_half_width;
    short elev_height;

    short cur_row;
    short cur_col;

    short block_beg_row;
    short block_end_row;
    short block_beg_col;
    short block_end_col;

    char any_frame_change;

    char *search_map;
    char **search_map_rows;

    char map_visible_flag;
    char fog_flag;

    class RGE_RMM_Database_Controller *random_map;

    class RGE_Game_World *game_world;

    class RGE_Zone_Map_List *map_zones;

    class RGE_Unified_Visible_Map *unified_vis_map;

    class Visible_Unit_Manager *unit_manager;

    RGE_Map(int infile, RGE_Sound **sounds, char setup);
    RGE_Map(char *border_tbl, char *terrain_tbl, char *map_tbl, short TileWid, short TileHgt, short ElevHgt, RGE_Sound **sounds);
    ~RGE_Map();

    void init_tile_sizes();

    void data_load_random_map(int infile);

    void load_random_map(char *rmm_map_file, char *rmm_land_file, char *rmm_terr_file, char *rmm_obj_file);

    void set_map_visible(char flag);
    void set_map_fog(char flag);

    void clear_map(RGE_Player *player, RGE_Game_World *world, char new_terrain, int width, int height);
    void new_map(int width, int height);
    void clear_map(char terrain, char elev);

    void request_redraw(int x1, int y1, int x2, int y2, char attribute);

    void clear_map_view_info();
    void coordinate_map();
    void set_map_screen_pos(int x1, int y1, int x2, int y2);

    void scenario_save(int outfile);
    void scenario_load(int infile, char *zone_terrain);

    RGE_Tile **give_up_map_offsets();

    int get_map_width();
    int get_map_height();

    char postclean_elevation(int x1, int y1, int x2, int y2, char elevation_height);
    void preclean_elevation(int x1, int y1, int x2, int y2, char elevation_height);
    void clean_elevation(int x1, int y1, int x2, int y2, int elevation_height);
    void clean_terrain(int x1, int y1, int x2, int y2, char replacement_terrain);
    static int clean_border_tile(int this_terrain, int other_terrain, int (*matrix)[32]);
    char do_terrain_brush(int x, int y, int brush_size, char terrain_id);
    char do_terrain_brush_stroke(int x1, int y1, int x2, int y2, int brush_size, int terrain_id);
    char do_elevation_brush(int x, int y, int brush_size, char elevation_height);
    char do_elevation_brush_stroke(int x1, int y1, int x2, int y2, int brush_size, int elevation_height);
    static char do_cliff_brush(int x, int y, char cliff_id, char delete_cliff);
    char do_cliff_brush_stroke(int x1, int y1, int x2, int y2, int cliff_id, int delete_cliff);
    void map_generate2(RGE_Game_World *gworld, int new_width, int new_height, int type, int player_num);

    void load_map(int infile);
    void save_map(int outfile);

    void save(int outfile);

    void load_terrain_types(RGE_Sound **sounds);
    void load_terrain_types(char *terrain_table, RGE_Sound **sounds);
    void load_border_types(RGE_Sound **sounds);
    void load_border_types(char *border_table, RGE_Sound **sounds);
    void load_terrain_obj_types(char *terr_obj_tbl);

    void delete_objects_on_tile(RGE_Player *obj_owner, RGE_Game_World *gworld, int x, int y, int no_delete_start, int no_delete_end);
    void delete_all_objects_on_tile(int x, int y);

    void create_terrain_object(RGE_Player *obj_owner, RGE_Game_World *gworld, short row, short col, short old_terrain, int delete_obj, int no_delete_start, int no_delete_end);
    int clear_terrain_object(RGE_Game_World *gworld, short row, short col, short old_terrain, int delete_obj, int no_delete_start, int no_delete_end);
    void place_terrain_object(RGE_Player *obj_owner, RGE_Game_World *gworld, short row, short col, int obj_type_id, int FillFlag);
    void create_terrain_objects(RGE_Player *obj_owner, RGE_Game_World *gworld);

    void set_tile_size(char tile_type, short width, short height, short y_delta);

    void tile_map_coords(short x, short y, RGE_Tile *tile, float *offset_x, float *offset_y);
    bool check_map_coords(short mapcol, short maprow);

    unsigned char get_elev(short mapcol, short maprow);
    unsigned char get_terrain(short mapcol, short maprow);
    unsigned char get_border(short mapcol, short maprow);

    void set_terrain_passablity(int mapcol1, short maprow1, int mapcol2, short maprow2, char passabilty);
    void set_elev(int mapcol1, int maprow1, int mapcol2, int maprow2, short elev, short delta, short set_flag);
    void set_terrain(RGE_Game_World *gworld, short mapcol, short maprow, char terrain, int no_delete_start, int no_delete_end);
    void set_terrain_absolute(RGE_Game_World *gworld, short mapcol, short maprow, char terrain, int no_delete_start, int no_delete_end);
    void set_terrain(RGE_Player *obj_owner, RGE_Game_World *gworld, int mapcol1, int maprow1, int mapcol2, int maprow2, char terrain, char set_flag, int delete_obj);

    char get_tile_type(short map_col, short map_row);
    void get_border_type(short map_col, short map_row);

    void check_for_border(char cur_ter, char *bor_ter);

    void update(unsigned int world_time);

    void get_point(short *screen_x, short *screen_y, float x, float y, float z, short x_offset, short y_offset);
};
