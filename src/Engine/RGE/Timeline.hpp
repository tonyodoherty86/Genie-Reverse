
/**
 * @file    Engine\RGE\Timeline.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Timeline
{
public:

    RGE_Game_World *world;

    struct RGE_Time_Entry *time_list;
    short list_num;
    short avail_id;

    float old_time = -1.0;

    RGE_Timeline(int infile, RGE_Game_World *gworld);
    RGE_Timeline(RGE_Game_World *gworld);

    ~RGE_Timeline();

    void save(int outfile);

    void update();

    void mock_update(float time);

    short find_id(RGE_Static_Object *obj);

    RGE_Time_Entry *add(float time);
    RGE_Time_Entry *add_attack(float time, RGE_Static_Object *obj, RGE_Static_Object *target);
    RGE_Time_Entry *add_create(float time, short obj_id, char player, float x, float y, float z);
    RGE_Time_Entry *add_move(float time, RGE_Static_Object *obj, float x, float y, float z);
    RGE_Time_Entry *add_delete(float time, RGE_Static_Object *obj);

    void sub(RGE_Time_Entry *entry);
};

struct RGE_Time_Entry
{
    float time;
    char command;
    short obj_type;
    char player;
    float x;
    float y;
    float z;
    short task;
    class RGE_Static_Object *this_obj;
    short this_obj_id;
    class RGE_Static_Object *target_obj;
    short target_obj_id;
    struct RGE_Time_Entry *next;
};
