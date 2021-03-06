
/**
 * @file    Engine\RGE\Sound.cpp
 * @author  Yvan Burrie
 * @date    2018/07/04
 * @version 1.0
 */

RGE_Sound::RGE_Sound(int infile, TSound_Driver *sound)
{
    int v4; // ebp@1
    RGE_Sound *v5; // esi@1
    short *v6; // edi@1
    signed int v7; // ebx@1
    RGE_Sound_Info *v8; // eax@2
    bool v9; // zf@2
    bool v10; // sf@2
    int v11; // edi@3
    TDigital *v12; // eax@4
    TDigital *v13; // eax@5

    v4 = infile;
    v5 = this;
    rge_read(infile, a2, infile, &this->id, 2);
    rge_read(v4, a2, v4, v5, 2);
    v6 = &v5->sound_num;
    rge_read(v4, (int)&v5->sound_num, v4, &v5->sound_num, 2);
    rge_read(v4, (int)&v5->sound_num, v4, &v5->cache_time, 4);
    v7 = 0;
    if( v5->sound_num <= 0 )
    {
        v5->sounds = 0;
    }
    else
    {
        v8 = (RGE_Sound_Info *)calloc(v5->sound_num, 0x24u);
        v9 = *v6 == 0;
        v10 = *v6 < 0;
        v5->sounds = v8;
        if( !v10 && !v9 )
        {
            v11 = 0;
            do
            {
                rge_read(infile, v11 * 36, infile, &v5->sounds[v11], 13);
                rge_read(infile, v11 * 36, infile, &v5->sounds[v11].resource_id, 4);
                rge_read(infile, v11 * 36, infile, &v5->sounds[v11].percent, 2);
                v12 = (TDigital *)operator new(0x3Cu);
                if( v12 )
                    TDigital::TDigital(v12, sound, v5->sounds[v11].name, v5->sounds[v11].resource_id);
                else
                    v13 = 0;
                ++v7;
                v5->sounds[v11].digital_sound = v13;
                v5->sounds[v11].loaded = 2;
                ++v11;
            }
            while( v7 < v5->sound_num );
        }
    }
}

RGE_Sound::RGE_Sound()
{
    this->play_at_update_count = 0;
    this->sound_num = 0;
    this->sounds = 0;
}

RGE_Sound::~RGE_Sound()
{
    RGE_Sound *v1; // esi@1
    RGE_Sound_Info *v2; // eax@1
    signed int v3; // ebx@2
    int v4; // edi@3
    RGE_Sound_Info *v5; // ecx@4
    TDigital *v6; // ebp@4

    v1 = this;
    v2 = this->sounds;
    this->play_at_update_count = 0;
    if( v2 )
    {
        v3 = 0;
        if( this->sound_num > 0 )
        {
            v4 = 0;
            do
            {
                v1->sounds[v4].name[0] = 0;
                v5 = v1->sounds;
                v6 = v5[v4].digital_sound;
                if( v6 )
                {
                    TDigital::~TDigital(v5[v4].digital_sound);
                    operator delete(v6);
                    v1->sounds[v4].digital_sound = 0;
                }
                ++v3;
                ++v4;
            }
            while( v3 < v1->sound_num );
        }
        free(v1->sounds);
        v1->sounds = 0;
        v1->sound_num = 0;
    }
}

void RGE_Sound::save(int outfile)
{
    RGE_Sound *v2; // edi@1
    short v3; // si@1
    signed int v4; // ebp@2
    int v5; // esi@3

    v2 = this;
    rge_write(outfile, &this->id, 2);
    rge_write(outfile, v2, 2);
    rge_write(outfile, &v2->sound_num, 2);
    rge_write(outfile, &v2->cache_time, 4);
    v3 = v2->sound_num;
    if( v3 > 0 )
    {
        v4 = 0;
        if( v3 > 0 )
        {
            v5 = 0;
            do
            {
                rge_write(outfile, &v2->sounds[v5], 13);
                rge_write(outfile, &v2->sounds[v5].resource_id, 4);
                rge_write(outfile, &v2->sounds[v5].percent, 2);
                ++v4;
                ++v5;
            }
            while( v4 < v2->sound_num );
        }
    }
}

void RGE_Sound::restart_sound(TSound_Driver *sound)
{
    RGE_Sound *v2; // esi@1
    signed int v3; // ebx@1
    int v4; // edi@2
    RGE_Sound_Info *v5; // eax@3
    TDigital *v6; // ebp@3
    TDigital *v7; // eax@6
    TDigital *v8; // eax@7

    v2 = this;
    v3 = 0;
    if( this->sound_num > 0 )
    {
        v4 = 0;
        do
        {
            v5 = v2->sounds;
            v6 = v5[v4].digital_sound;
            if( v6 )
            {
                TDigital::~TDigital(v5[v4].digital_sound);
                operator delete(v6);
            }
            if( sound )
            {
                v7 = (TDigital *)operator new(0x3Cu);
                if( v7 )
                {
                    TDigital::TDigital(v7, sound, v2->sounds[v4].name, v2->sounds[v4].resource_id);
                    v2->sounds[v4].digital_sound = v8;
                }
                else
                {
                    v2->sounds[v4].digital_sound = 0;
                }
            }
            else
            {
                v2->sounds[v4].digital_sound = 0;
            }
            ++v3;
            v2->sounds[v4].loaded = 2;
            ++v4;
        }
        while( v3 < v2->sound_num );
    }
}

void RGE_Sound::update(time_t curr_time)
{
    RGE_Sound *v2; // esi@1
    short v3; // ax@1
    signed int v4; // ebp@3
    int v5; // edi@4
    int v6; // eax@5

    v2 = this;
    v3 = this->sound_num;
    if( v3 > 0 )
    {
        if( this->cache_time )
        {
            v4 = 0;
            if( v3 > 0 )
            {
                v5 = 0;
                do
                {
                    v6 = (int)&v2->sounds[v5];
                    if( *(_BYTE *)(v6 + 28) == 1 && curr_time - *(_DWORD *)(v6 + 32) > v2->cache_time )
                    {
                        TDigital::unload(*(TDigital **)(v6 + 24));
                        v2->sounds[v5].loaded = 2;
                    }
                    ++v4;
                    ++v5;
                }
                while( v4 < v2->sound_num );
            }
        }
    }
}

void RGE_Sound::set_cache_time(time_t new_cache_time)
{
    this->cache_time = new_cache_time;
}

void RGE_Sound::play_at_update()
{
    this->play_at_update_count++;
}

void RGE_Sound::update_play()
{
    if( this->play_at_update_count > 0 ){
        this->play(true);
        this->play_at_update_count = 0;
    }
}

void RGE_Sound::play(bool add_to_play_list)
{
    RGE_Sound *v2; // edi@1
    int v3; // eax@2
    int v4; // esi@2
    int v5; // edx@2
    int v6; // eax@2
    RGE_Sound_Info *v7; // ebx@3
    short *v8; // ecx@3
    int v9; // esi@7
    TDigital *v10; // ecx@7
    int v11; // eax@7
    int v12; // ebx@19
    char s[256]; // [sp+10h] [bp-100h]@9

    v2 = this;
    if( this->sound_num > 0 )
    {
        v3 = debug_rand(aCMsdevWorkA_58, 221);
        v4 = v2->sound_num;
        v5 = 100 * v3 / 0x7FFF;
        v6 = 0;
        if( v4 > 0 )
        {
            v7 = v2->sounds;
            v8 = &v7->percent;
            while( 1 )
            {
                v5 -= *v8;
                if( v5 <= 0 )
                    break;
                ++v6;
                v8 += 18;
                if( v6 >= v4 )
                    return;
            }
            v9 = v6;
            v10 = v7[v6].digital_sound;
            v11 = (int)&v7[v6];
            if( v10 )
            {
                if( do_draw_log )
                {
                    sprintf(s, aS_0, v11);
                    if( safe_draw_log )
                        write_draw_log2(s);
                    else
                        write_draw_log(s);
                }
                if( add_to_play_list )
                    TDigital::add_to_play_list(v2->sounds[v9].digital_sound);
                else
                    TDigital::play(v2->sounds[v9].digital_sound);
                if( do_draw_log )
                {
                    if( safe_draw_log )
                        write_draw_log2(::s);
                    else
                        write_draw_log(::s);
                }
                v2->sounds[v9].loaded = 1;
                v12 = debug_timeGetTime_on;
                debug_timeGetTime_on = 0;
                v2->sounds[v9].time = debug_timeGetTime();
                debug_timeGetTime_on = v12;
            }
        }
    }
}

char *RGE_Sound::get_file_name()
{
    RGE_Sound *v1; // edi@1
    int v2; // eax@2
    int v3; // esi@2
    int v4; // edx@2
    int v5; // eax@2
    RGE_Sound_Info *v6; // edi@3
    short *v7; // ecx@3
    char *result; // eax@6
    TDigital *v9; // eax@7

    v1 = this;
    if( this->sound_num <= 0 )
        goto LABEL_12;
    v2 = debug_rand(aCMsdevWorkA_58, 284);
    v3 = v1->sound_num;
    v4 = 100 * v2 / 0x7FFF;
    v5 = 0;
    if( v3 <= 0 )
        goto LABEL_12;
    v6 = v1->sounds;
    v7 = &v6->percent;
    while( 1 )
    {
        v4 -= *v7;
        if( v4 <= 0 )
            break;
        ++v5;
        v7 += 18;
        if( v5 >= v3 )
            return 0;
    }
    v9 = v6[v5].digital_sound;
    if( v9 )
        result = v9->sound_file;
    else
LABEL_12:
        result = 0;
    return result;
}

void RGE_Sound::stop()
{
    RGE_Sound *v1; // esi@1
    short v2; // ax@1
    signed int v3; // ebx@2
    int v4; // edi@3
    TDigital *v5; // ecx@4

    v1 = this;
    v2 = this->sound_num;
    if( v2 > 0 )
    {
        v3 = 0;
        if( v2 > 0 )
        {
            v4 = 0;
            do
            {
                v5 = v1->sounds[v4].digital_sound;
                if( v5 )
                {
                    if( TDigital::is_playing(v5) )
                        TDigital::stop(v1->sounds[v4].digital_sound);
                }
                ++v3;
                ++v4;
            }
            while( v3 < v1->sound_num );
        }
    }
}

int RGE_Sound::is_playing()
{
    RGE_Sound *v1; // esi@1
    short v2; // ax@1
    signed int v3; // ebx@2
    int v4; // edi@3
    TDigital *v5; // ecx@4
    int result; // eax@7

    v1 = this;
    v2 = this->sound_num;
    if( v2 <= 0 || (v3 = 0, v2 <= 0) )
    {
        result = 0;
    }
    else
    {
        v4 = 0;
        while( 1 )
        {
            v5 = v1->sounds[v4].digital_sound;
            if( v5 )
            {
                if( TDigital::is_playing(v5) )
                    break;
            }
            ++v3;
            ++v4;
            if( v3 >= v1->sound_num )
                return 0;
        }
        result = 1;
    }
    return result;
}
