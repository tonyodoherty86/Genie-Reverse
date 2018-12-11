#pragma once

#include "SoundDriver.hpp"

/**
 * @file    Engine\Music.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

typedef int MCI_PLAY_PARMS;

class TMusic_System
{
public:

    char path[260];

    char music_type;

    TSound_Driver *sound_system;

    void *instance;
    void *window;

    int device_open;
    unsigned int device_id;

    MCI_PLAY_PARMS play_info;
    char playing_track;
    char file_name[261];

    int start_track;
    int end_track;
    int make_cur_track;
    unsigned int set_pos;
    int loop;
    int current_track;
    int track_count;

    int notify_waiting;

    int start_volume;
    int volume;

    int unk1;

    int paused;
    int auto_paused;

    int inactivated;

    int fade_out;
    unsigned int fade_time;
    int fading_track;
    int fade_volume;
    unsigned int last_fade_time;

    int mixer_open;
    void *mixer_handle;
    MIXERLINEA mixer_line_info;
    MIXERLINECONTROLSA mixer_line_controls;
    MIXERCONTROLA mixer_volume_control;
    MIXERCONTROLDETAILS mixer_volume_details;
    MIXERCONTROLDETAILS_UNSIGNED mixer_volume_value;

    void *midi_window;

    unsigned int last_check_time;

    TMusic_System(char music_type_in, void *instance_in, void *window_in, TSound_Driver *sound_system_in, char *path_in);

    ~TMusic_System();

    int open_device();
    void close_device();
    int open_mixer();
    void close_mixer();
    int set_music_type(char music_type_in);
    void set_fade_out(int fade_out_in, unsigned int fade_time_in);
    void set_volume(int volume_in, int permanent);
    int play_track(int track_in, int loop_in, unsigned int set_pos_in);
    int play_file(char *file_name_in, int loop_in, unsigned int set_pos_in);
    int play_tracks(int start_track_in, int end_track_in, int loop_in, int make_cur_track_in, unsigned int set_pos_in);
    int play(int start_track_in, int end_track_in, char *file_name_in, int make_cur_track_in, unsigned int set_pos_in);
    int pause_play();
    int resume_play();
    int stop_track();
    int stop_playing();
    int fade_track();
    void start_fade();
    void do_fade();
    void end_fade();
    unsigned int handle_messages(HWND *wnd, UINT msg, WPARAM wparam, LPARAM lparam);
    void after_end_track();
    int get_play_info(char *music_type_in, int *track_from_in, int *track_to_in, int *cur_track_in, char *music_file_in, int *loop_in, unsigned int *pos_in);
};
