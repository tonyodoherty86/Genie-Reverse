#pragma once

/**
 * @file    Engine\RGE\RmmBase.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class RGE_Map;

class RGE_Random_Map_Module
{
public:

    RGE_Random_Map_Module *parent;

    struct RGE_Random_Map_Module_List *list;

    RGE_Map *map;

    struct RGE_Tile **map_row_offset;

    int map_width,
        map_height;

    float schedule;

    char *search_map;
    char **search_map_rows;

    struct Map_Stack *stack_array;
    struct Map_Stack **stack_offsets;

    RGE_Random_Map_Module(RGE_Map *in_map, RGE_Random_Map_Module *parent_module, char resources_needed);
    ~RGE_Random_Map_Module();

    double get_schedule();

    char generate();

    char add_module(RGE_Random_Map_Module *module);
    char remove_module(RGE_Random_Map_Module *module);

    void create_shared_resources();
    void destroy_shared_resources();

    void update_child_resources();
    void update_resources();
    void update_child_map_info();
    void update_map_info(RGE_Map *new_map);

    void share_resources(
        char **search_map_pointer,
        char ***search_map_rows_pointer,
        Map_Stack **stack_array_pointer,
        Map_Stack ***stack_offsets_pointer);

    static void init_stack(Map_Stack *stack);
    static void deinit_stack(Map_Stack *stack);
    void push_stack(Map_Stack *stack, int x, int y, float cost, float tot_cost);
    static Map_Stack *pop_stack(Map_Stack *stack, int *x, int *y, float *cost);
    static void add_stack_node(Map_Stack *stack, Map_Stack *new_stack);
    static void remove_stack_node(Map_Stack *stack);
    void clear_stack();
    static bool check_stack(Map_Stack *stack);
    static void randomize_stack(Map_Stack *stack);

    char find_path(int x, int y, int *end_x, int *end_y, float *terrain);
    char find_path(Map_Stack *path_stack, int x, int y, int *end_x, int *end_y, float *terrain);
};

struct RGE_Random_Map_Module_List
{
    RGE_Random_Map_Module *module;

    RGE_Random_Map_Module_List *next;
};

struct Map_Stack
{
    int x, y;

    float cost,
          tot_cost;

    Map_Stack *next,
              *prev;
};

struct RGE_Land_Info_Line
{
    int land_size;

    int terrain_type;

    int x, y;

    int base_size;

    int area;

    char zone;

    int clumpiness_factor;

    int wall_1_avoidance_line,
        wall_2_avoidance_line,
        wall_3_avoidance_line,
        wall_4_avoidance_line;

    char wall_fade;
};

struct RGE_Land_Info
{
    RGE_Land_Info_Line land[99];

    int land_num;

    char base_terrain;

    int wall_1_avoidance_line,
        wall_2_avoidance_line,
        wall_3_avoidance_line,
        wall_4_avoidance_line;

    char wall_fade;
};

struct RGE_Terrain_Info_Line
{
    int terrain_size;

    int terrain_generated;

    int terrain_type;

    int clumps;

    int spacing;

    int base_terrain_type;

    int clumpiness_factor;

    int avoid_hot_spots;
};

struct RGE_Terrain_Hot_Spots
{
    int x, y;

    int radius;

    int fade;
};

struct RGE_Terrain_Info
{
    RGE_Terrain_Info_Line terrain[99];
    int terrain_num;

    RGE_Terrain_Hot_Spots hot_spots[99];
    int hot_spot_num;
};

struct RGE_Object_Info_Line
{
    int obj_id;

    int terrain;

    char group_flag;

    char scale_flag;

    int object_number_per_group;

    int object_number_varience;

    int number_of_groups;

    int group_area;

    int player_id;

    int land_id;

    int land_inner_radius,
        land_outer_radius;

    int object_exclusion_zone;
};

struct RGE_Land_Point_Info_Line
{
    int x, y;

    int id;

    int player_id;
};

struct RGE_Object_Info
{
    RGE_Object_Info_Line objects[99];
    int object_num;

    RGE_Land_Point_Info_Line lands[99];
    int land_num;
};

struct RGE_Elevation_Info_Line
{
    int elevation_size;

    int elevation;

    int clumps;

    int spacing;

    int base_elevation;

    int base_terrain_type;
};

struct RGE_Elevation_Hot_Spots
{
    int x, y;

    int radius;

    int fade;
};

struct RGE_Elevation_Info
{
    RGE_Elevation_Info_Line elevation[99];
    int elevation_num;

    RGE_Elevation_Hot_Spots hot_spots[99];
    int hot_spot_num;
};

struct RGE_Cliffs_Hot_Spots
{
    int x, y;

    int radius;
};

struct RGE_Cliffs_Info
{
    int number_of_cliffs;
    int number_of_cliffs_variance;
    int average_cliff_size;
    int cliff_size_variance;
    int cliff_terrain_spacing;
    int cliff_to_cliff_spacing;

    RGE_Cliffs_Hot_Spots hot_spots[99];
    int hot_spot_num;
};

struct RGE_Shallows_Info_Line
{
    int x, y;
};

struct RGE_Shallows_Info
{
    RGE_Shallows_Info_Line shallows[99];
    int shallows_num;
};

struct RGE_Land_Data
{
    int map_edge_buffer[4];

    int map_edge_fade;

    int land_placement_edge;

    int base_terrain;

    int grown_land_percent;

    int id;

    int land_num;

    struct RGE_Land_Data_Entry *land;
};

struct RGE_Land_Data_Entry
{
    int land_id;

    char terrain_type;

    int land_avoidance_tiles;

    int base_square_radius;

    char zone;

    char placement_type;

    int x, y;

    char amount_of_land_used_percent;

    char by_player_flag;

    int radius;

    int fade;

    int clumpiness_factor;
};

struct RGE_Terrain_Data
{
    int terrain_num;
    struct RGE_Terrain_Data_Entry *terrain;
};

struct RGE_Terrain_Data_Entry
{
    int terrain_percent;

    int terrain_type;

    int clumps;

    int spacing;

    int base_terrain_type;

    int clumpiness_factor;
};

struct RGE_Object_Data
{
    int object_num;
    struct RGE_Object_Data_Entry *objects;
};

struct RGE_Object_Data_Entry
{
    int obj_id;

    int terrain;

    char group_flag;

    char scale_flag;

    int object_number_per_group;

    int object_number_varience;

    int number_of_groups;

    int group_area;

    int player_id;

    int land_id;

    int land_inner_radius,
        land_outer_radius;
};

struct RGE_Elevation_Data
{
    int elevation_num;
    struct RGE_Elevation_Data_Entry *elevation;
};

struct RGE_Elevation_Data_Entry
{
    int elevation_percent;

    int elevation;

    int clumps;

    int spacing;

    int base_terrain_type;

    int base_elevation_type;
};

struct RGE_Map_Data
{
    int map_num;
    struct RGE_Map_Data_Entry *maps;
};

struct RGE_Map_Data_Entry
{
    int map_id;

    RGE_Land_Data land_info;
    RGE_Terrain_Data terrain_info;
    RGE_Object_Data object_info;
    RGE_Elevation_Data elevation_info;
};
