#pragma once

/**
 * @file    Engine\TRB\RmmDbController.hpp
 * @author  Yvan Burrie
 * @date    2018/06/24
 * @version 1.0
 */

#include <RGE/RmmDbController.hpp>

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller
{
public:

    TRIBE_RMM_Database_Controller(
        char *land_file,
        char *terrain_file,
        char *object_file,
        char *map_file);

    TRIBE_RMM_Database_Controller(
        int infile);

    char init(RGE_Map *in_map, RGE_Game_World *in_world, char type, int player_num, int fixed_position);
    char de_init();

    void add_land_module(char fixed_positions);
    void add_terrain_module();
    void add_object_module();
    void add_elevation_module();
    void add_shallows_module();

    char generate();
};
