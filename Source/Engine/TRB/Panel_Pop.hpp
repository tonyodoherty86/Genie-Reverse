#pragma once

/**
 * @file    Engine\TRB\Panel_Pop.hpp
 * @author  Yvan Burrie
 * @date    2018/08/08
 * @version 1.0
 */

#include <Panel.hpp>

class TRIBE_World;
class TRIBE_Player;

class TRIBE_Panel_Pop : public TPanel
{
public:

    void *font;

    unsigned int color1,
                 color2,
                 color3;

    int player_id;

    TRIBE_World *world;

    TRIBE_Player *player;

    int pop;
    int max_pop;
    char mode;
    float timer;
    void *image_clip_region;

    TDrawArea *ImageBuffer;

    RECT ImageRect,
         UsedImageRect,
         UsedScreenRect;

    int ImageTextActive;
    int LastIBWidth;
    int LastIBHeight;

    TRIBE_Panel_Pop(TDrawArea *render_area_in, TPanel *parent_in);

    ~TRIBE_Panel_Pop();

    void startup();
    int get_player_id();
    void draw();
    void get_true_render_rect(RECT *drawRect);
    int handle_idle();
    void *render_to_image_buffer();
};
