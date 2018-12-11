#pragma once

/**
 * @file    Engine\RGE\Campaign.hpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

struct RGE_Campaign_Header
{
    int version;

    char name[255];

    int scenario_num;
};

struct RGE_Scenario_Offset
{
    int size;

    int offset;

    char name[255];

    char file_name[255];
};

class RGE_Campaign
{
public:

    RGE_Campaign_Header campaign_header;

    RGE_Scenario_Offset *scenario_offsets;

    char filename[255];

    RGE_Campaign(char *in_filename);
    RGE_Campaign(char *campaign_filename,
                 char *campaign_name,
                 int scenario_num,
                 char **scenarios,
                 char **scenarios_name);

    ~RGE_Campaign();

    void create_file();
    int open_scenario(int scenario);
    char *get_name();
    int scenario_number();
    int scenario_info(char ***scenario_names);
    char *get_scenario_name(int num);
};
