#pragma once

/**
 * @file    Engine\Digital.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

#include "SoundDriver.hpp"

typedef void WAVEFORMATEX;

class TDigital
{
public:

    TSound_Driver *sound_system;

    TDigital *owner;

    char loaded;
    char failed;

    char sound_file[13];

    int resource_id;

    int volume;

    unsigned int pitch;

    int pan;
    int loop;

    char *wave_data;

    WAVEFORMATEX *wave_info;

    IDirectSoundBuffer *sound_buffer;

    unsigned int data_size;

    TDigital(TSound_Driver *in_sound_system, char *file_name, int res_id);
    TDigital(TDigital *first);

    ~TDigital();

    void init_vars();

    void exit();

    int load(char *file_name, int res_id);
    void unload();

    IDirectSoundBuffer *play();
    void stop();

    void set_loop(short loop_count);
    void set_volume(int in_vol);
    void set_pitch(unsigned int in_pitch);
    void set_pan(int in_pan);

    int is_playing();

    int add_to_play_list();
};
