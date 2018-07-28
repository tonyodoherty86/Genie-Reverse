
/**
 * @file    Engine\RGE\GameWorld.hpp
 * @author  Yvan Burrie
 * @date    2018/07/04
 * @version 1.0
 */

#define RGE_WORLD_DIFFICULTY_LEVEL_EXISTS TRUE

class RGE_Game_World
{
public:
    /**
     * Offset: 0
     */
    //struct vfptr{
        /**
         * Offset: 164.
         */
        //void *load_unit_groups;
    //}
    //*table;

    /* TODO: unknown structures */

    /**
     * Offset: 4
     */
    void *unk4;

    /**
     * Offset: 8
     */
    void *unk8;

    /**
     * Offset: 12
     */
    void *unk12;

    /* Timers and conditions */

    /**
     * Offset: 16
     */
    time_t world_time;

    /**
     * Offset: 20
     */
    time_t old_world_time;

    /**
     * Offset: 24
     */
    time_t world_time_delta;

    /**
     * Offset: 28
     */
    float timer;

    /**
     * (aka saved_time)
     * Offset: 32.
     */
    time_t old_time;

    /**
     * Offset: 36.
     */
    float game_speed;

    /**
     * Offset: 40, 41, 42.
     */
    char temp_pause,
         game_state,
         game_end_condition;

    /* Update indexes */
    int sound_update_index,
        sprite_update_index;

    /* World Map */
    class RGE_Map *map;

    /* World Sounds */
    short sound_num;
    class RGE_Sound **sounds;

    /* World Sprites */
    short sprite_num;
    class RGE_Sprite **sprites;

    /* World Players */
    short player_num;
    class RGE_Player **players;

    /* World Master-Players */
    int master_player_num;
    class RGE_Master_Player **master_players;

    /* World Effects */
    class RGE_Effects *effects;

    /* World Terrains */
    int terrain_num;
    int terrain_size;
    float **terrains;

    /* World Commands */
    class RGE_Command *commands;

    /* World Scenario */
    class RGE_Scenario *scenario;

    /* TODO: ?? */
    void *unk112;
    int unk116;

    // 118
    // unit_groups ???
    /* World Color-Tables */
    int color_table_num;
    class RGE_Color_Table **color_tables;

    /* World incremental object-IDs */
    int next_object_id;

    /**
     * Offset: 132 (AOC).
     */
    int next_reusable_object_id = -1;

    /* World Scenario properties */
    int scenario_object_id;
    char scenario_object_flag;

    unsigned int random_seed;// 144 ???

    /**
     * Offset: 148 (AOC).
     */
    int curr_player;

    /**
     * Offset: 152, 156 (AOC).
     */
    float map_view_x,
          map_view_y;

    float unk160;/* TODO */

    TSound_Driver *sound_driver;

    /**
     * Offset: 168 (AOC).
     */
    float world_time_delta_seconds;

    class RGE_Static_Object **objectsValue;
    int numberObjectsValue;
    int maxNumberObjectsValue;
    class RGE_Static_Object **negativeObjectsValue;
    int numberNegativeObjectsValue;
    int maxNumberNegativeObjectsValue;

#if RGE_WORLD_PLAY_BOOK_EXISTS
    /**
     * This field was removed in AOK.
     */
    class AIPlayBook *playbook;
#endif

    /**
     * Index of Campaign, Campaign-Player, Campaign-Scenario.
     * Offset (AOC): 196, 200, 204.
     */
    int campaign,
        campaign_player,
        campaign_scenario;

    /**
     * Offset: 208 (AOC).
     */
    int player_turn;

    /**
     * Offset: 212 (AOC).
     */
    time_t player_time_delta[RGE_PLAYERS_COUNT];

    /**
     * Below are objects-lists that provide the recyclage and reusability of each type of object for memory-management purposes.
     */
    class RGE_Object_List
        *reusable_static_objects,
        *reusable_animated_objects,
        *reusable_moving_objects,
        *reusable_action_objects,
        *reusable_combat_objects,
        *reusable_missile_objects;

#if RGE_DOPPLEGANGER_OBJECT_EXISTS
    class RGE_Object_List
        *reusable_doppleganger_objects;
#endif

    /**
     *
     */
    unsigned int maximumComputerPlayerUpdateTime,
                 availableComputerPlayerUpdateTime;

    /**
     * Offset: 284.
     */
    int currentUpdateComputerPlayer = -1;

    // 476
    // int unitGroups_count
    // 480
    // unitGroupsUsage // unit groups counter

    /* TODO */
    int unk_aok_01;
    int unk_aok_02;
    int unk_aok_03;
    int unk_aok_04;
    int unk_aok_05;
    int unk_aok_06;
    int unk_aok_07;
    int unk_aok_08;
    int unk_aok_09;
    int unk_aok_10;
    int unk_aok_11;
    int unk_aok_12;
    int unk_aok_13;
    int unk_aok_14;
    int unk_aok_15;
    int unk_aok_16;
    int unk_aok_17;
    int unk_aok_18;
    int unk_aok_19;
    int unk_aok_20;
    int unk_aok_21;
    int unk_aok_22;
    int unk_aok_23;
    int unk_aok_24;
    int unk_aok_25;
    int unk_aok_26;
    int unk_aok_27;
    int unk_aok_28;

    /* TODO: Added in AOK.
     * Used when reading RGE_Action_Object structures.
     */
    class RGE_Task_List **actors;
    int actors_num;

#if RGE_WORLD_DIFFICULTY_LEVEL_EXISTS
    /**
     * Offset: 404.
     */
    int difficultyLevelValue = -1;
#endif

    /**
     * Offset: 408.
     */
    int teamsLock;

    RGE_Game_World();

    ~RGE_Game_World();

    void reset_object_count();
    void pause(char flag);
    void set_map_visible(char flag);
    void set_map_fog(char flag);

    char init_player_type(int infile, short index, char type);
    char init_player(int infile);
    void terrain_tables_init(int infile);
    void color_table_init(int infile);
    void init_sounds(int infile, TSound_Driver *sound_dvr);
    void init_sprites(int infile);
    void scenario_init(int infile, RGE_Game_World *world);
    void scenario_init(RGE_Game_World *world);
    void map_init(int infile, TSound_Driver *sound_dvr);
    void effects_init(int infile);
    void master_player_init(int infile);
    void command_init(int infile, TCommunications_Handler *com_hand);
    void world_init(int infile, TSound_Driver *sound_dvr, TCommunications_Handler *com_hand);
    char init(char *base_name, TSound_Driver *sound_dvr, TCommunications_Handler *com_hand);

    void turn_sound_off();
    void reset_communications(TCommunications_Handler *com_hand);
    void reset_player_visible_maps();
    void del_game_info();

    void load_player(int infile, char type, short index);
    char load_world(int infile1);
    char load_game(char *name);

    void set_game_speed(float new_speed);

    void setup_gaia();
    void setup_players(RGE_Player_Info *info);
    void setup_player_colors(RGE_Player_Info *info);
    void setup_player_colors();

    char new_game(RGE_Player_Info *info, int myPlayerNum);
    char new_scenario(RGE_Player_Info *info, int random_seed_in);
    char new_random_game(RGE_Player_Info *info);

    void update_sounds(time_t time);
    void update_sprites(time_t time);
    char update();

    int is_player_turn(int player_id);
    time_t get_accum_time_delta(int player_id);
    char get_game_state();
    char check_game_state();

    void save(int outfile);
    char save_game(char *name);
    void base_save(int outfile);
    void base_save(char *name);

    char save_scenario(char *filename);
    char load_scenario(char *scenario, RGE_Player_Info *info);
    char load_scenario(RGE_Player_Info *info);
    void scenario_make_player(short index, char player_type, char info_type, char master_player_id, char *name);
    void scenario_make_map(int infile);
    void load_scenario1(int infile, RGE_Player_Info *info);
    void load_scenario2(int infile, RGE_Player_Info *info);
    void load_scenario3(int infile, RGE_Player_Info *info);
    void load_scenario4(int infile, RGE_Player_Info *info);
    void load_scenario5(int infile, RGE_Player_Info *info);
    void load_scenario6(int infile, RGE_Player_Info *info);
    void load_scenario7(int infile, RGE_Player_Info *info);
    void load_scenario8(int infile, RGE_Player_Info *info);
#if ENGINE_AOK
    void load_scenario9(int infile, RGE_Player_Info *info);
    void load_scenario10(int infile, RGE_Player_Info *info);
    void load_scenario11(int infile, RGE_Player_Info *info);
#endif

    void selectNextComputerPlayer(int cPType);
    void useComputerPlayerUpdateTime(time_t usedTime);
    int computerPlayerUpdateTimeAvailable();
    int objectGroupOnTile(int ownerID, int groupID, int x, int y, int *objectCount);
    int difficultyLevel();
    static RGE_Scenario *get_scenario_info(char *filename);
    int maxNumberObjects();
    int maxNumberNegativeObjects();
    int numberObjects();
    int numberNegativeObjects();
    RGE_Static_Object *object(int oID);
    RGE_Static_Object *object_ptr(int oID);
    int get_next_object_id();
    int get_next_reusable_object_id();
    RGE_Static_Object **addObject(RGE_Static_Object *newObject);
    int removeObject(int oID);

    RGE_Map *initializePathingSystem();

    bool recycle_object_out_of_game(
        char object_type,
        RGE_Static_Object *obj);

    RGE_Static_Object *recycle_object_in_to_game(char object_type);
    void update_mutual_allies();
};
