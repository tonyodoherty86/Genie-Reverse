
/**
 * @file    Engine\RGE\RmmLand.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class RGE_RMM_Land_Generator : public RGE_Random_Map_Module
{
public:

    RGE_Land_Info info;

    RGE_RMM_Land_Generator(
        RGE_Map *in_map,
        RGE_Random_Map_Module *parent_module,
        RGE_Land_Info *in_info);

    char generate();

    char check_terrain_and_zone(char target, char land_num, int x, int y);

    char chance(int x, int y, int land_type);

    char base_land_generate();
};
