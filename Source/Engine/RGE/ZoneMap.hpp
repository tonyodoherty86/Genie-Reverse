#pragma once

#include "Path.hpp"

class RGE_Map;

/**
 * @file    Engine\RGE\ZoneMap.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Zone_Map
{
public:

    int numberTilesInZoneValue[257];
    char *zone_map;
    char **zone_map_rows;
    char zone_info[257];
    float *terrain_passability_rules;
    int terrain_passability_rules_num;

    RGE_Map *map;

    RGE_Zone_Map(int infile, RGE_Map *new_map);
    RGE_Zone_Map(RGE_Map *new_map, float *new_terrain_rules, int new_terrain_rules_num);

    ~RGE_Zone_Map();

    void save(int outfile);

    char do_zone_map();
    void do_zone_map_area(int x, int y, char group, char zone);

    RGE_Zone_Map *check_info(float *new_terrain_rules, int new_terrain_rules_num);

    char get_zone_info(int x, int y);

    int withinRange(XYPoint start, XYPoint goal, float range);
    int withinRange(char startZone, XYPoint goal, float range);

    int numberTilesInZone(char zone);

    int findClosestPointInTerrainType(XYPoint p, XYPoint *rVal, int type1, int type2, int range);

};

class RGE_Zone_Map_List
{
public:

    RGE_Zone_Map **zone_maps;
    int zone_map_num;
    RGE_Map *map;

    RGE_Zone_Map_List(int infile, RGE_Map *in_map);
    RGE_Zone_Map_List(RGE_Map *in_map);

    ~RGE_Zone_Map_List();

    void save(int outfile);

    int create_zone_map(float *new_terrain_rules, int new_terrain_rules_num);

    RGE_Zone_Map *get_zone_map(float *new_terrain_rules, int new_terrain_rules_num, int *zoneMapIndex);
    RGE_Zone_Map *get_zone_map(int id);

    void delete_zone_maps();
};

struct Zone_Queue
{
    int x;
    int y;
    Zone_Queue *next;
};

char zone_pop(Zone_Queue **zone_queue, Zone_Queue **zone_end, int *x, int *y);
void zone_push(Zone_Queue **zone_queue, Zone_Queue **zone_end, int x, int y);
