
/**
 * @file    Engine\RGE\Sprite.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

#define RGE_SPRITE_EDITOR_FLAG_EXISTS 1

class RGE_Sprite
{
public:
    char pict_name[13];

    int resource_id;

    char loaded;

    RGE_Color_Table **color_tables;

    TShape *shape;

    int last_time;
    int delta_time;

    char color_flag;
    char draw_level;

    short color_table;

    char transparent_picking_flag;

    short box_x1;
    short box_y1;
    short box_x2;
    short box_y2;

    short draw_list_num;
    struct RGE_Picture_List *draw_list;

    RGE_Sound *main_sound;

    char micro_man_sound;

    struct RGE_Sound_List *sound_list;

    char name[21];

    short frame_num;
    short facet_num;

    float base_speed;
    float duration;
    float pause_between_loops;

    char flag;

    short id;

    char mirror_flag;

#if RGE_SPRITE_EDITOR_FLAG_EXISTS
    char editor_flag;
#endif

    RGE_Sprite(short in_id);
    RGE_Sprite(int infile, RGE_Sound **sounds, RGE_Color_Table **c_tables);
    ~RGE_Sprite();

    void rehook(RGE_Sprite **sprites);

    void save(int outfile);

    void load_facets(RGE_Sprite **sprites);

    void play_sound(short frame1, short frame2, short facet);

    char get_facetindex(int facet, int frame, int *facetindex);

    void do_draw(int facet, int frame, int x, int y, RGE_Color_Table *player_color, TDrawArea *draw_area, char min_draw_level);
    int draw(int facet, int frame, int x, int y, int sx, int sy, RGE_Color_Table *player_color, TDrawArea *draw_area, char min_draw_level);
    char normal_draw(int facet, int frame, int x, int y, RGE_Color_Table *player_color, TDrawArea *draw_area);
    char shadow_draw(int facet, int frame, int x, int y, RGE_Color_Table *player_color, TDrawArea *draw_area, char flag);

    int get_size(int *xmin, int *ymin, int *xmax, int *ymax, int facet);
    int get_frame(short *min_x, short *min_y, short *max_x, short *max_y, int facet, int frame);
    int get_frame_min_max(short *min_x, short *min_y, short *max_x, short *max_y, int facet, int frame, short pic_x, short pic_y);
    char get_lowest_draw_level();

    char hit_test(short x, short y, int facet, int frame);
    char shape_hit_test(short x, short y, int facet, int frame);

    void make_active_sprite();

    int check_for_shadows();

    void update(unsigned int curr_time);
};

struct RGE_Picture_List
{
    short picture_num;

    RGE_Sprite *sprite;

    short offset_x;
    short offset_y;

    short facet;
};

struct RGE_Sound_List
{
    RGE_Sound *sound[3];

    short frame[3];
};
