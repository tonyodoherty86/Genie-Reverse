
/**
 * @file    Engine\RGE\Sound.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

class RGE_Sound
{
public:

    short play_at_update_count;

    short sound_num;

    struct RGE_Sound_Info *sounds;

    unsigned int cache_time = 30000;

    short id;

    RGE_Sound(_iobuf *infile, short in_id);
    RGE_Sound(int infile, TSound_Driver *sound);

    ~RGE_Sound();

    void save(int outfile);

    void restart_sound(TSound_Driver *sound);

    void update(unsigned int curr_time);

    void set_cache_time(unsigned int new_cache_time);

    void play_at_update();

    void update_play();

    void play(int add_to_play_list);

    char *get_file_name();

    void stop();

    int is_playing();
};

struct RGE_Sound_Info
{
    char name[13];

    int resource_id;

    short percent;

    TDigital *digital_sound;

    char loaded;

    unsigned int time;
};
