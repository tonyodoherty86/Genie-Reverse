
/**
 * @file    Engine\RGE\Task.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Task
{
public:

    short task_type;

    short id;

    char is_default;

    short action_type;

    short object_group;
    short object_id;

    char combat_level;
    char combat_level_flag;

    short terrain_id;

    char owner_type;

    char holding_attr;

    char state_building;

    short attribute_type,
          attribute_type2,
          attribute_type3,
          attribute_type4;

    float work_val1;
    float work_val2;
    float work_range;

    char search_flag;
    float search_wait_time;

    short work_flag;
    short work_flag2;

    RGE_Sprite *move_sprite;
    RGE_Sprite *work_sprite;
    RGE_Sprite *work_sprite2;
    RGE_Sprite *carry_sprite;

    RGE_Sound *work_sound;
    RGE_Sound *work_sound2;

    RGE_Task(short id_in);

    ~RGE_Task();

    void copy(RGE_Task *other_task);

    void load(int infile, RGE_Sprite **sprites, RGE_Sound **sounds);
    void load(_iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds);

    void save(int outfile);
};
