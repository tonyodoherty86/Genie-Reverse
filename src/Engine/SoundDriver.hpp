
/**
 * @file    Engine\SoundDriver.hpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

class TSound_Driver
{
public:

    char ready;
    char mute;

    HWND *main_wnd;

    IDirectSound *direct_sound;
    IDirectSoundBuffer *primary_buffer;

    int dsrval;

    int start_volume;
    int volume;

    char path[260];

    int mixer_open;
    void *mixer_handle;

    MIXERLINEA mixer_line_info;
    MIXERLINECONTROLSA mixer_line_controls;
    MIXERCONTROLA mixer_volume_control;
    MIXERCONTROLDETAILS mixer_volume_details;
    MIXERCONTROLDETAILS_UNSIGNED mixer_volume_value;

    class TDigital *sound_play_list[256];

    int play_list_count;

    TSound_Driver();

    TSound_Driver(HWND *wnd, char *path_in);

    ~TSound_Driver();

    void init_vars();

    int init(HWND *wnd, char *path_in);

    void exit();

    void set_path(char *path_in);

    int driver_active();

    int get_volume();
    void set_volume(int in_vol, int permanent);

    int stream_file(char *file_name, int loop, int volume);
    int set_stream_volume(int volume);
    int pause_stream();
    int resume_stream();
    int stop_stream();

    LRESULT handle_messages(HWND *wnd, UINT msg, WPARAM wparam, LPARAM lparam);

    int add_to_play_list(TDigital *sound);
    void play_list();
    void reset_play_list();

    int open_mixer();
    void close_mixer();
};
