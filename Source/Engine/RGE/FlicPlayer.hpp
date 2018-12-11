#pragma once

class TDrawArea;
class RGBQUAD;

/**
 * @file    Engine\RGE\FlicPlayer.hpp
 * @author  Yvan Burrie
 * @date    2018/08/07
 * @version 1.0
 */

struct FlicHead
{
    int size;
    unsigned short type;
    short frames;
    short width;
    short height;
    short depth;
    short flags;
    int speed;
    short reserved1;
    int created;
    int creator;
    int updated;
    int updater;

    short aspect_dx,
          aspect_dy;

    char reserved2[38];

    char *oframe1,
         *oframe2;

    char reserved3[40];
};

class RGE_Flic_Player
{
public:

    char *flic_buffer;
    int flic_handle;
    FlicHead flichead;
    TDrawArea *drawarea;
    int drawarea_width;
    int flic_width;
    char *window_buffer;
    char *save_buffer;
    char *chunk;

    int x1, y1, x2, y2;

    int flic_size_x,
        flic_size_y;

    RGE_Flic_Player( char *filename );

    RGE_Flic_Player( int handle );

    ~RGE_Flic_Player();

    void palette( RGBQUAD *palette );

    int resolution();
    int time_delay();
    short frames();
    void start();
    void reset();
    char draw(TDrawArea *drawarea_in, int flic_x, int flic_y);
    void literal();
    void delta_flc();
    void delta_fli();
    void black();
    void byte_run();
};
