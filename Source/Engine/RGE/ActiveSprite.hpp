#pragma once

/**
 * @file    Engine\RGE\ActiveSprite.hpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

#define RGE_ACTIVE_SPRITE_TYPE 1

class RGE_Sprite;
class RGE_Color_Table;
class TDrawArea;

class RGE_Active_Sprite
{
public:

    RGE_Sprite *sprite;

    char type = RGE_ACTIVE_SPRITE_TYPE;

    int offset_x = 0,
        offset_y = 0;

    RGE_Active_Sprite(RGE_Sprite *new_sprite);
    RGE_Active_Sprite(int infile, RGE_Sprite **sprites);

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

#define RGE_ACTIVE_ANIMATED_SPRITE_TYPE 2

class RGE_Active_Animated_Sprite : public RGE_Active_Sprite
{
public:

    char type = RGE_ACTIVE_ANIMATED_SPRITE_TYPE;

    short frame = 0;

    float animate_interval;
    float animate_last;

    short last_frame;

    bool frame_changed = false,
         frame_looped = false;

    char animate_flag = 0;

    RGE_Active_Animated_Sprite(RGE_Sprite *new_sprite);
    RGE_Active_Animated_Sprite(int infile, RGE_Sprite **sprites);

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
