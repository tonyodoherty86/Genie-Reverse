#pragma once

/**
 * @file    Engine\RGE\RmmObject.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

#include "RmmBase.hpp"

class RGE_RMM_Object_Generator : public RGE_Random_Map_Module
{
public:

    RGE_Game_World *world;

    RGE_Object_Info info;

    char terrain_table[32];

    char add_terrain;

    RGE_RMM_Object_Generator(RGE_Map *in_map, RGE_Random_Map_Module *parent_module, RGE_Game_World *in_world, RGE_Object_Info *in_info, char add_terrain_objects);

    void add_quick_obj(int obj_id, int count, int er);

    char generate();
    void generate_objects(RGE_Object_Info_Line *info_line);

    void make_placement_stack(Map_Stack *stack, int x, int y, int inner_radius, int outer_radius);
    char to_close(RGE_Object_Info_Line *info_line, int x, int y);
    void set_search_area(int x, int y, int radius, char set_num);
    void remove_area_from_lists(int x, int y, int spacing);

    void place_avoid_objects(RGE_Object_Info_Line *info_line, int inner_radius);
    void place_objects(RGE_Object_Info_Line *info_line);
    void place_land_objects(RGE_Object_Info_Line *info_line, int map_x, int map_y, int inner_radius, int outer_radius, int land_id);
    void place_group(RGE_Object_Info_Line *info_line, int map_x, int map_y, RGE_Player *player);
    void place_cluster(RGE_Object_Info_Line *info_line, int map_x, int map_y, RGE_Player *player);
};
