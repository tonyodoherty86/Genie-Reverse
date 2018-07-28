
/**
 * @file    Engine\RGE\ObjectList.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

class RGE_Object_List
{
public:

    struct RGE_Object_Node *list;

    short number_of_objects;

    RGE_Object_List();

    ~RGE_Object_List();

    void removeAllObjects();

    RGE_Object_Node *add_node(RGE_Static_Object *obj);
    void remove_node(RGE_Static_Object *obj, RGE_Object_Node *node);

    void invert();

    void draw(TDrawArea *render_area, int x, int y, char fogged_tile);
    void shadow_draw(TDrawArea *render_area, int x, int y, int flag, char fog_flag);
    void normal_draw(TDrawArea *render_area, int x, int y, char fog_flag);

    void update();

    RGE_Object_Node *sort();

    RGE_Static_Object *find_by_group(int id);
    RGE_Static_Object *find_by_group(int id, float x, float y, char certain_state, char object_state, RGE_Static_Object *zone_obj);
    RGE_Static_Object *find_by_id(int id);
    RGE_Static_Object *find_by_master_id(int id, float x, float y, char certain_state, char object_state, RGE_Static_Object *zone_obj);
    RGE_Static_Object *find_by_master_ids(int id1, int id2, float x, float y, char certain_state, char object_state, RGE_Static_Object *zone_obj);
    RGE_Static_Object *find_by_type(char type, float x, float y, char certain_state, char object_state);

    void save(int outfile);

    void load_list(int infile, RGE_Game_World *world);

    RGE_Static_Object *load(char object_type, int infile, RGE_Game_World *world);

    void rehook_list();
};

struct RGE_Object_Node
{
    RGE_Static_Object *node;

    RGE_Object_Node *next,
                    *prev;

    char centered;
};
