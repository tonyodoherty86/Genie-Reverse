
/**
 * @file    Engine\RGE\RmmDbController.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module
{
public:

    RGE_Game_World *world;

    int map_type;
    int number_of_players;

    RGE_Land_Info land_info;
    RGE_Terrain_Info terrain_info;
    RGE_Object_Info object_info;
    RGE_Elevation_Info elevation_info;
    RGE_Map_Data map_info;

    RGE_RMM_Database_Controller(char *land_file, char *terrain_file, char *object_file, char *map_file);
    RGE_RMM_Database_Controller(int infile);

    ~RGE_RMM_Database_Controller();

    char save(int outfile);

    char generate();

    char init(RGE_Map *in_map, RGE_Game_World *in_world, char type, int player_num, int fixed_positions);

    char de_init();

    void calc_land_start(int land_index, int edge, int land_num, RGE_Land_Data_Entry *info);

    void add_land_module(char fixed_positions);
    void add_terrain_module();
    void add_object_module();
    void add_elevation_module();
};
