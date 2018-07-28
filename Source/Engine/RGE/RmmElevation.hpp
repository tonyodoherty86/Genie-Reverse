
/**
 * @file    Engine\RGE\RmmElevation.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class RGE_RMM_Elevation_Generator : public RGE_Random_Map_Module
{
public:

    RGE_Elevation_Info info;

    RGE_RMM_Elevation_Generator(RGE_Map *in_map, RGE_Random_Map_Module *parent_module, RGE_Elevation_Info *in_info);

    char generate();

    char check_start_elevation(int x, int y, char base_terrain, char base_elevation, char spacing);
    char check_elevation(char target, int x, int y, int spacing, char base_terrain, char base_elevation);

    void generate_modifiers();
    double fig_chance(int count, int x, int y);
    int count_map_tiles(char terrain);
    void link_stack_randomly(Map_Stack *loc_stack);
    void remove_area_from_lists(int x, int y, int spacing);
    char base_elevation_generate(RGE_Elevation_Info_Line info_line);
};
