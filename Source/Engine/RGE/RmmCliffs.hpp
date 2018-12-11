#pragma once

/**
 * @file    Engine\RGE\RmmCliffs.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

#include "RmmBase.hpp"

class RGE_RMM_Cliffs_Generator : public RGE_Random_Map_Module
{
public:

    RGE_Cliffs_Info info;

    Map_Stack valid_cliff_sites;

    RGE_RMM_Cliffs_Generator(
        RGE_Map *in_map,
        RGE_Random_Map_Module *parent_module,
        RGE_Cliffs_Info cliff_info);

    char generate();

    void setup_cliff_maps();

    void generate_cliff();

    char check_for_valid_cliff_site(int direction, int *x, int *y, int valid_height);

    void invalidate_cliff_area(int x, int y, int radius);
};
