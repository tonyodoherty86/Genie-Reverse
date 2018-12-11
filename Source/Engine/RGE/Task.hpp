#pragma once

class RGE_Sprite;
class RGE_Sound;

/**
 * @file    Engine\RGE\Task.hpp
 * @author  Yvan Burrie
 * @date    2018/07/06
 * @version 1.0
 */

class RGE_Task
{
public:

    short task_type = 1;

    short id = -1;

    bool is_default = false;

    short action_type = 0;

    short object_group = 0;
    
    short object_id = 0;

    char combat_level = 0;

    char combat_level_flag = 0;

    short terrain_id = -1;

    char owner_type = 0;

    char holding_attr = 0;

    char state_building = 0;

    short attribute_type = -1,
          attribute_type2 = -1,
          attribute_type3 = -1,
          attribute_type4 = -1;

    float work_val1 = 0.0,
          work_val2 = 0.0;

    float work_range = 0.0;

    char search_flag = 0.0;

    float search_wait_time;

    short work_flag = 0,
          work_flag2 = 0;

    RGE_Sprite *move_sprite,
               *work_sprite,
               *work_sprite2,
               *carry_sprite;

    RGE_Sound *work_sound,
              *work_sound2;

    RGE_Task(
        short id_in);

    void copy(
        RGE_Task *other_task);

    void load(
        int infile,
        RGE_Sprite **sprites,
        RGE_Sound **sounds);

    void save(
        int outfile);
};
