#pragma once

/**
 * @file    Engine\RGE\RmmShallows.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

#include "RmmBase.hpp"

class RGE_RMM_Shallows_Generator : public RGE_Random_Map_Module
{
public:

    RGE_Shallows_Info info;

    RGE_RMM_Shallows_Generator(
        RGE_Map *in_map,
        RGE_Random_Map_Module *parent_module,
        RGE_Shallows_Info *in_info);

    char generate();

    void make_tribe_connections(int point1, int point2);
};
