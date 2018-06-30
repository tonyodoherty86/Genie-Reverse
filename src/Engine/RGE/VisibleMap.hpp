
/**
 * @file    Engine\RGE\VisibleMap.hpp
 * @author  Yvan Burrie
 * @date    2018/06/28
 * @version 1.0
 */

class RGE_Visible_Map
{
public:

    /**
     * Offset: 0.
     */
    char **map_offsets;

    /**
     * Offset: 4.
     */
    RGE_Game_World *world;

    /**
     * Offset: 8.
     */
    RGE_Player *player;

    /**
     * Offset: 12.
     */
    RGE_Map *map;

    /**
     * Offset: 16.
     */
    char *visible_map;

    /**
     * Offset: 20, 24.
     */
    int widthValue,
        heightValue;

    /**
     * Offset: 28, 32.
     */
    int numberTilesExploredValue,
        numberTotalTilesValue;

    /**
     * Offset: 36, 40, 44, 48, 52.
     */
    unsigned int PlayerVisibleMaskValue,
                 PlayerVisibleMaskInvertValue,
                 PlayerExploredMaskValue,
                 PlayerExploredMaskInvertValue,
                 input_csum;

    /* Size: 56 (has never changed from AOE to AOC) */

    RGE_Visible_Map(
        RGE_Map *in_map,
        RGE_Player *in_player);

    RGE_Visible_Map(
        int infile,
        RGE_Game_World *theWorld);

    ~RGE_Visible_Map();

    /* Write to GAM file */
    void save(
        int outfile);

    char get_visible(int map_col, int map_row);
    void set_all(char vis_flag);
    void explore_all();
    double percentExplored();
    void recomputeExplored();

    static struct LOSTBL **get_los_table(int radius, int Square);

    int explore_terrain(int tx, int ty, int radius, int Square, int UpdateMap, int id);
    void unexplore_terrain(int tx, int ty, int radius, int Square, int UpdateMap, int id);
    int explore_terrain_sq(int tx1, int ty1, int tx2, int ty2, int UpdateMap, int id);
    void unexplore_terrain_sq(int tx1, int ty1, int tx2, int ty2, int UpdateMap, int id);

    unsigned int checksum_visible_inputs();
    int checksumVisible();
    unsigned int checksumUnifiedVisible();
};

struct LOSTBL
{
    int y_delta;
    int x_left;
    int x_right;
};

void log_map_call(int wt, int plyr, int action, int id, int x1, int y1, int x2, int y2, int sup);

void dump_vismap_log();

class RGE_Unified_Visible_Map
{
public:

    int mapWidth;
    int mapHeight;

    unsigned int *UnifiedVisibleMap;

    RGE_Unified_Visible_Map(int width, int height);
    RGE_Unified_Visible_Map(int infile, RGE_Game_World *world);

    ~RGE_Unified_Visible_Map();

    void load(int infile);

    void save(int outfile);

    void reset();

    void Set_Map_Offsets();

    static void suppress_updates(int mode);
};

class Visible_Unit_Manager
{
public:

    struct VISIBLE_UNIT_PTR **PlayerDataPtrs;
    struct VISIBLE_UNIT_REC *Return_Buffer[5];

    int Player_Count;
    int Category_Count;

    char *distanceTable;

    Visible_Unit_Manager(int Num_Players, int Num_Categories);

    ~Visible_Unit_Manager();

    void Build_Distance_Table();

    void Update_Unit_Info(int Object_Id, int player_id, int Xpos, int Ypos, int Category, unsigned int PriorUnifiedMap, unsigned int NewUnifiedMap, VISIBLE_UNIT_REC **ObjectPtrs);

    int GetVisibleUnits(int Xpos, int Ypos, int LOS, int player, int *DesiredTypes, int DesiredCount, int *PlayerListMap);
};

struct VISIBLE_UNIT_REC
{
    int object_id;
    char distance;
    char player;

    char pos_x,
         pos_y;
};

struct VISIBLE_UNIT_PTR
{
    VISIBLE_UNIT_REC *unit_list;
    short list_size;
    short used;
};

class Visible_Resource_Manager
{
public:

    struct VISIBLE_RESOURCE_REC **VR_List;

    int *VR_ListSize;
    int *VR_ListUsed;

    RGE_Player *owner;

    int num_visible_resource_lists;

    Visible_Resource_Manager(RGE_Player *list_owner, int num_lists);

    Visible_Resource_Manager(int infile, RGE_Player *list_owner);

    ~Visible_Resource_Manager();

    void save(int outfile);

    void Process_New_Tiles(RGE_Tile_List *tile_list);

    void AddResource(int Obj_Id, int ObjGroup);
    int Remove_Resource(int Obj_Id, int ObjGroup);
    VISIBLE_RESOURCE_REC *Get_Closest_Resource(int Xpos, int Ypos, int Zone, int ResType, int *excList, int elSize);
};

struct VISIBLE_RESOURCE_REC
{
    int object_id;

    char distance;

    char zone;

    char pos_x,
         pos_y;
};
