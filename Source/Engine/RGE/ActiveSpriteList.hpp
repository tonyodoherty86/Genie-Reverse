
/**
 * @file    Engine\RGE\ActiveSpriteList.hpp
 * @author  Yvan Burrie
 * @date    2018/06/27
 * @version 1.0
 */

class RGE_Active_Sprite_List
{
public:

    struct RGE_Active_Sprite_Node *list;

    RGE_Static_Object *owner;

    RGE_Active_Sprite_List(RGE_Static_Object *owner_in);

    ~RGE_Active_Sprite_List();

    void load(int infile, RGE_Sprite **sprites);
    char load_node(int infile, char type, RGE_Sprite **sprites);

    void save(int outfile);

    void delete_list();

    struct RGE_Active_Sprite_Node *copy_sprite_list();
    void use_sprite_list(RGE_Active_Sprite_Node *temp_list);
    void add_sprite(RGE_Sprite *sprite, char order, int x, int y);
    void remove_sprite(RGE_Sprite *sprite);

    void update(float time, float speed);

    void draw(int facet, short x, short y, short sx, short sy, RGE_Color_Table *player_color, TDrawArea *draw_area);
    void normal_draw(int facet, short x, short y, RGE_Color_Table *player_color, TDrawArea *draw_area);
    void shadow_draw(int facet, short x, short y, RGE_Color_Table *player_color, TDrawArea *draw_area, int flag);

    short frame(RGE_Sprite *sprite);
    char is_animating(RGE_Sprite *sprite);
    void set_frame(RGE_Sprite *sprite, int new_frame);
    char frame_passed(RGE_Sprite *sprite, int pass_frame);
    char looped(RGE_Sprite *sprite);
    short get_facetindex(RGE_Sprite *sprite, int facet);
    char get_frame(short *min_x, short *min_y, short *max_x, short *max_y, RGE_Sprite *sprite, int facet);
    char get_lowest_draw_level();
    int check_for_shadows();
};

struct RGE_Active_Sprite_Node
{
    class RGE_Active_Sprite *node;

    char order;

    char count;

    RGE_Active_Sprite_Node *next;
};
