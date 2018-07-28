
/**
 * @file    Engine\RGE\RmmTerrain.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class RGE_RMM_Terrain_Generator : public RGE_Random_Map_Module
{
public:

    RGE_Terrain_Info info;

    RGE_Zone_Map *map_zone;

    RGE_RMM_Terrain_Generator(
        RGE_Map *in_map,
        RGE_Random_Map_Module *parent_module,
        RGE_Terrain_Info *in_info);

    char generate();

    char water(char terrain);

    void check_borders();
    char check_terrain(char target, int x, int y, int spacing, char base_terrain);
    void generate_modifiers();
    double fig_chance(int count, int x, int y, int clumpiness_factor);
    int count_map_tiles(char terrain);
    void link_stack_randomly(Map_Stack *loc_stack, char base_terrain_type);
    void remove_area_from_lists(int x, int y, int spacing);
    char base_terrain_generate(RGE_Terrain_Info_Line info_line);
};
