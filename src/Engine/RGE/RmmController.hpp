
/**
 * @file    Engine\RGE\RmmController.hpp
 * @author  Yvan Burrie
 * @date    2018/02/18
 * @version 1.0
 */

class RGE_RMM_Controller : public RGE_Random_Map_Module
{
public:

    RGE_RMM_Controller(RGE_Map *in_map, RGE_Game_World *world, char type, int player_num);

    void add_land_module(RGE_Land_Info *info, int type, int player_num);
    void add_terrain_module(RGE_Terrain_Info *info, RGE_Land_Info *land_info, int type);
    int count_map_tiles(char terrain);
    void add_object_module(RGE_Game_World *world, RGE_Land_Info *land_info);
};
