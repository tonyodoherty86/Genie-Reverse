
/**
 * @file    Engine\RGE\ActiveSprite.hpp
 * @author  Yvan Burrie
 * @date    2018/02/20
 * @version 1.0
 */

class RGE_Active_Sprite
{
public:

    RGE_Sprite *sprite;

    char type;

    int offset_x;
    int offset_y;

    RGE_Active_Sprite(RGE_Sprite *new_sprite);
    RGE_Active_Sprite(int infile, RGE_Sprite **sprites);

    ~RGE_Active_Sprite();

    void set_offset(int x, int y);

    void save(int outfile);

    void draw(short facet, int x, int y, int sx, int sy, RGE_Color_Table *player_color, TDrawArea *draw_area);
    void normal_draw(short facet, int x, int y, RGE_Color_Table *player_color, TDrawArea *draw_area);
    void shadow_draw(short facet, int x, int y, RGE_Color_Table *player_color, TDrawArea *draw_area, char flag);

    short what_frame();
    char is_animating();
    char frame_passed(short passed_frame);
    char looped();
    short get_facetindex(short facet);
    int get_frame(short *min_x, short *min_y, short *max_x, short *max_y, int facet);
    char get_lowest_draw_level();

    int check_for_shadows();
};

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite
{
public:

    short frame;
    float animate_interval;
    float animate_last;
    short last_frame;
    char frame_changed;
    char frame_looped;
    char animate_flag;

    RGE_Active_Animated_Sprite(RGE_Sprite *new_sprite);
    RGE_Active_Animated_Sprite(int infile, RGE_Sprite **sprites);

    ~RGE_Active_Animated_Sprite();

    void save(int outfile);

    void update(float time, float speed);

    void draw(short facet, int x, int y, int sx, int sy, RGE_Color_Table *player_color, TDrawArea *draw_area);
    void normal_draw(short facet, int x, int y, RGE_Color_Table *player_color, TDrawArea *draw_area);
    void shadow_draw(short facet, int x, int y, RGE_Color_Table *player_color, TDrawArea *draw_area, char flag);

    short what_frame();
    signed int is_animating();
    void set_frame(short new_frame);
    bool frame_passed(short passed_frame);
    char looped();
    short get_facetindex(short facet);
    int get_frame(short *min_x, short *min_y, short *max_x, short *max_y, int facet);

    void setToFirstFrame();
};
