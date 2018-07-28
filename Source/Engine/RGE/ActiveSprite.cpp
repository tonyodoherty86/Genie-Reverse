
/**
 * @file    Engine\RGE\ActiveSprite.cpp
 * @author  Yvan Burrie
 * @date    2018/06/25
 * @version 1.0
 */

RGE_Active_Sprite::RGE_Active_Sprite(RGE_Sprite *new_sprite)
{
    this->sprite = new_sprite;
}

RGE_Active_Sprite::RGE_Active_Sprite(int infile, RGE_Sprite **sprites)
{
    short sprite_id = -1;
    rge_read(infile, &sprite_id, 2);
    if( sprite_id >= 0 ){
        this->sprite = sprites[sprite_id];
    }else{
        this->sprite = nullptr;
    }
    rge_read(infile, &this->offset_x, 4);
    rge_read(infile, &this->offset_y, 4);
}

void RGE_Active_Sprite::set_offset(int x, int y)
{
    this->offset_x = x;
    this->offset_y = y;
}

void RGE_Active_Sprite::save(int outfile)
{
    rge_write(outfile, &this->type, 1);
    rge_write(outfile, &this->sprite->id, 2);
    rge_write(outfile, &this->offset_x, 4);
    rge_write(outfile, &this->offset_y, 4);
}

void RGE_Active_Sprite::draw(
    short facet,
    int x, int y,
    int sx, int sy,
    RGE_Color_Table *player_color,
    TDrawArea *draw_area)
{
    this->sprite->draw(
        facet,
        0,
        this->offset_x + x,
        this->offset_y + y,
        this->offset_x + sx,
        this->offset_y + sy,
        player_color,
        draw_area,
        0);
}

void RGE_Active_Sprite::normal_draw(
    short facet,
    int x, int y,
    RGE_Color_Table *player_color,
    TDrawArea *draw_area)
{
    this->sprite->normal_draw(
        facet,
        0,
        this->offset_x + x,
        this->offset_y + y,
        player_color,
        draw_area);
}

void RGE_Active_Sprite::shadow_draw(
    short facet,
    int x, int y,
    RGE_Color_Table *player_color,
    TDrawArea *draw_area,
    char flag)
{
    this->sprite->shadow_draw(
        facet,
        0,
        this->offset_x + x,
        this->offset_y + y,
        player_color,
        draw_area,
        flag);
}

short RGE_Active_Sprite::what_frame()
{
    return 0;
}

char RGE_Active_Sprite::is_animating()
{
    return 0;
}

char RGE_Active_Sprite::frame_passed(short passed_frame)
{
    return 0;
}

char RGE_Active_Sprite::looped()
{
    return 0;
}

short RGE_Active_Sprite::get_facetindex(short facet)
{
    int facet_index = 0;

    this->sprite->get_facetindex(facet, 0, &facet_index);

    return facet_index;
}

int RGE_Active_Sprite::get_frame(short *min_x, short *min_y, short *max_x, short *max_y, int facet)
{
    return this->sprite->get_frame(min_x, min_y, max_x, max_y, facet, 0);
}

char RGE_Active_Sprite::get_lowest_draw_level()
{
    if( this->sprite ){
        return this->sprite->get_lowest_draw_level();
    }else{
        return RGE_SPRITE_HIGHEST_DRAW_LEVEL;
    }
}

int RGE_Active_Sprite::check_for_shadows()
{
    if( this->sprite ){
        return this->sprite->check_for_shadows();
    }else{
        return 0;
    }
}

RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(RGE_Sprite *new_sprite)
{
    RGE_Active_Sprite::RGE_Active_Sprite(new_sprite);

    this->animate_interval = this->sprite->duration;
    if( this->animate_interval < 0.001 ){
        this->animate_interval = 0.001;
    }
    if( this->flag & 4 ){
        float tot_time = this->sprite->frame_num * this->sprite->duration + this->sprite->pause_between_loops;
        double v7 = rand() * tot_time * 0.000030518509;
        this->frame = v7 / this->sprite->duration;
        if( this->frame >= this->sprite->frame_num ){
            this->frame = this->sprite->frame_num - 1;
            this->animate_interval = v7 - this->frame * this->sprite->duration;
        }
        this->last_frame = this->frame;
    }else{
        this->frame = 0;
    }
    this->animate_flag = 1;
}

RGE_Active_Animated_Sprite::RGE_Active_Animated_Sprite(int infile, RGE_Sprite **sprites)
{
    RGE_Active_Sprite::RGE_Active_Sprite(infile, sprites);

    rge_read(infile, &this->frame, 2);
    rge_read(infile, &this->animate_interval, 4);
    rge_read(infile, &this->animate_last, 4);
    rge_read(infile, &this->last_frame, 2);
    rge_read(infile, &this->frame_changed, 1);
    rge_read(infile, &this->frame_looped, 1);
    rge_read(infile, &this->animate_flag, 1);
}

void RGE_Active_Animated_Sprite::save(int outfile)
{
    RGE_Active_Sprite::save(outfile);

    rge_write(outfile, &this->frame, 2);
    rge_write(outfile, &this->animate_interval, 4);
    rge_write(outfile, &this->animate_last, 4);
    rge_write(outfile, &this->last_frame, 2);
    rge_write(outfile, &this->frame_changed, 1);
    rge_write(outfile, &this->frame_looped, 1);
    rge_write(outfile, &this->animate_flag, 1);
}

void RGE_Active_Animated_Sprite::update(float time, float speed)
{
    this->frame_changed = false;
    this->frame_looped  = false;

    if( this->sprite == nullptr ||
        this->animate_flag == 0 ){
        goto LABEL_23;
    }
    if( this->frame >= this->sprite->frame_num ){
        this->frame = this->sprite->frame_num - 1;
    }
    if( !(this->sprite->flag & 1) ){
        goto LABEL_23;
    }
    this->frame_changed = true;
    this->last_frame = this->frame;

    this->animate_last += time;
    double v10 = this->animate_last / this->animate_interval;
    this->animate_last -= v10 * this->animate_interval;

    if( this->sprite->base_speed == 0.0 || speed > 0.0 ){
        this->frame += v10;
        if( this->frame >= this->sprite->frame_num ){
            this->frame_looped = true;
        }
    }
    if( this->sprite->base_speed == 0.0 || speed == 0.0 ){
        this->animate_interval = this->sprite->duration;
    }else{
        this->animate_interval = this->sprite->duration * this->sprite->base_speed / speed;
    }
    if( this->animate_interval < 0.001 ){
        this->animate_interval = 0.001;
    }
    if( this->frame_looped ){
        if( this->sprite->pause_between_loops <= 0.0 ||
            this->animate_flag == 2 ){

            this->animate_flag = 1;

            for( short i = this->sprite->frame_num; this->frame >= i; i = this->sprite->frame_num ){
                this->frame -= i;
            }
        }else{
            this->animate_flag = 2;

            this->animate_interval = this->sprite->pause_between_loops - (double)(this->frame - (signed int)this->sprite->frame_num) * this->sprite->duration;

            this->frame_looped = false;

            this->frame = this->sprite->frame_num - 1;
        }
        LABEL_23:
        if( this->frame_looped &&
            this->sprite->flag & 8 ){

            this->animate_flag = 0;

            this->frame = this->sprite->frame_num - 1;
        }
    }
}

void RGE_Active_Animated_Sprite::draw(
    short facet,
    int x, int y,
    int sx, int sy,
    RGE_Color_Table *player_color,
    TDrawArea *draw_area)
{
    this->sprite->draw(
        facet,
        this->frame,
        x, y,
        sx, sy,
        player_color,
        draw_area,
        0);

    if( this->frame_changed ){
        if( fog_next_shape == 0 ){
            this->sprite->play_sound(this->last_frame, this->frame, facet);
        }
        this->frame_changed = false;
    }
}

void RGE_Active_Animated_Sprite::normal_draw(
    short facet,
    int x, int y,
    RGE_Color_Table *player_color,
    TDrawArea *draw_area)
{
    this->sprite->normal_draw(facet, this->frame, x, y, player_color, draw_area);

    if( this->frame_changed ){
        this->sprite->play_sound(this->last_frame, this->frame, facet);
        this->frame_changed = false;
    }
}

void RGE_Active_Animated_Sprite::shadow_draw(
    short facet,
    int x, int y,
    RGE_Color_Table *player_color,
    TDrawArea *draw_area,
    char flag)
{
    this->sprite->shadow_draw(
        facet,
        this->frame,
        x, y,
        player_color,
        draw_area,
        flag);
}

short RGE_Active_Animated_Sprite::what_frame()
{
    return this->frame;
}

int RGE_Active_Animated_Sprite::is_animating()
{
    int result;

    if( !this->animate_flag || (result = 1, !(this->sprite->flag & 1)) ){
        result = 0;
    }
    return result;
}

void RGE_Active_Animated_Sprite::set_frame(short new_frame)
{
    this->frame = new_frame;
}

bool RGE_Active_Animated_Sprite::frame_passed(short passed_frame)
{
    return this->frame_changed && (this->frame_looped || this->frame >= passed_frame && this->last_frame < passed_frame);
}

char RGE_Active_Animated_Sprite::looped()
{
    return this->frame_looped;
}

short RGE_Active_Animated_Sprite::get_facetindex(short facet)
{
    int facet_index = 0;

    this->sprite->get_facetindex(facet, this->frame, &facet_index);

    return facet_index;
}

int RGE_Active_Animated_Sprite::get_frame(short *min_x, short *min_y, short *max_x, short *max_y, int facet)
{
    return this->sprite->get_frame(min_x, min_y, max_x, max_y, facet, this->frame);
}

void RGE_Active_Animated_Sprite::setToFirstFrame()
{
    this->frame_changed = 1;
    this->last_frame = this->frame;
    this->frame = 0;
}
