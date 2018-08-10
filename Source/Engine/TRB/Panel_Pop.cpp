
/**
 * @file    Engine\TRB\Panel_Pop.cpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

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

    int pop,
        max_pop;

    char mode;

    float timer;

    void *image_clip_region;

    TDrawArea *ImageBuffer;

    RECT ImageRect,
         UsedImageRect,
         UsedScreenRect;

    int ImageTextActive;

    int LastIBWidth,
        LastIBHeight;

    TRIBE_Panel_Pop(TDrawArea *render_area_in, TPanel *parent_in);

    ~TRIBE_Panel_Pop();

    void startup();
    int get_player_id();
    void draw();
    void get_true_render_rect(RECT *drawRect);
    int handle_idle();
    void *render_to_image_buffer();
};
