
/**
 * @file    Engine\TRB\Player.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

class TRIBE_Player;

struct TRIBE_FealtyOffer
{
	// 0
	char Sequence;
	// 1
	char StartedBy;
	// 8
	int GameTime;
	// 12
	char Declare;
	// 13
	char OldDiplomacy;
	// 14
	char NewDiplomacy;
	// 15
	char OldIntelligence;
	// 16
	char NewIntelligence;
	// 17
	char OldTrade;
	// 18
	char NewTrade;
	// 19
	char Demand;
	// 20
	char Gold;
	// 24
	char Message[100];
	// 124
	char Status;
};

struct Item_Avail
{
    char *name;
    short id;
    short pict;
    short inventory_item_1;
    float inventory_cost_1;
    short inventory_item_2;
    float inventory_cost_2;
    short inventory_item_3;
    float inventory_cost_3;
    int help_string_id;
    int help_page_id;
};

struct Trade_Avail
{
    RGE_Player *player;
    RGE_Static_Object *dock;
    float inventory;
};

class TRIBE_Player : public RGE_Player
{
public:

    // 4768
    class TRIBE_Player_Tech *tech_tree;
    // 4772
    int fog_update;
    // 4776
    int update_count;
#ifdef ENGINE_AOK
    // 4780
    int alertedEnemyCount;
    // 4784
    int regularAttackCount;
    // 4788
    int regularAttackMode;
    // 4792
    float regularAttackX;
    // 4796
    float regularAttackY;
    // 4800
    int townAttackCount;
    // 4804
    char townAttackMode;
    // 4808
    float townAttackX;
    // 4812
    float townAttackY;
#endif
    // 4816
    int update_history_count;
    // 4820
    int updateCountNeedHelp;
    // 4824
    float update_time;
    // 4828
    class TribeMainDecisionAIModule *playerAI;
    // 4832
    char aiStatusInformationValue[256];
    char aiStatusInformationValue2[256];
    char aiStatusInformationValue3[256];
    char aiStatusInformationValue4[256];
    char aiStatusInformationValue5[256];
    char aiStatusInformationValue6[256];
    // 6368
    float ruin_held_time;
    // 6372
    float artifact_held_time;
    // 6376
    class TRIBE_History_Info *history;/* TODO: was moved in AOK */
#if ENGINE_AOK
    // 6380
    int HistoryValue1;
    // 6384
    int oldKills;
    // 6388
    int oldHitPoints;
    // 6392
    int oldRazings;
    // 6396
    int battleMode;
    // 6400
    int razingsMode;
    // 6404
    int totalKills;
    // 6408
    int totalHitPoints;
    // 6412
    int totalRazings;
    // 6416
    int oldPlayerKills[9];
    // 6452
    class TRIBE_TechTree *TechTree;
    // 6456
    char chanceToDodgeMissiles;
    // 6457
    char chanceToMaintainDistance;
    // 6458
    char fealtyDiplomatics[9];
    // 6467
    char fealtyIntelligences[9];
    // 6476
    char fealtyTrades[9];
    // 6489
    TRIBE_FealtyOffer fealtyOffers[9];

    // 7712
    short fealtyValue;
    // 7714
    char offMapTradeRouteExplored[20];
    // 7734
    char offMapTradeRouteBeingExplored[20];

    // 7792
    char productionQueueEnabled;

    // 7800
    int nomadBuildLock;
    // 7804
    int openGatesForPathingCount;
    // 7808
    int maxTradeAmount;
    // 7812
    int oldMaxTradeAmount;
    // 7816
    int maxTradeLimit;
    // 7820
    int currentWoodLimit;
    // 7824
    int currentFoodLimit;
    // 7828
    int currentStoneLimit;
    // 7832
    int currentOreLimit;
    // 7836
    int commodityVolumeDelta;
    // 7840
    float tradeVigorRate;
    // 7844
    int tradeRefreshTimer;
    // 7848
    int tradeRefreshRate;
    // 7852
    int farmQueueCount;
#endif

    TRIBE_Player(int infile, TRIBE_World *gworld, char this_id);
    TRIBE_Player(TRIBE_World *gworld, RGE_Master_Player *prototype, char this_id, char *new_name, char m_player_id, char computerPlayer, char flag, char *buildListName, char *cityPlanName, char *ruleSetName);

    ~TRIBE_Player();

    TRIBE_Building_Object *make_scenario_obj(float world_x, float world_y, float world_z, short master_id, char state, float new_angle);

    void save(int outfile);

    void update();

    void scenario_save(int outfile);
    void scenario_load(int infile, int *player_id_hash, float version);

    void load(int infile);
    void load_master_object(int infile, short index, char type, RGE_Sprite **sprites, RGE_Sound **sounds);

    void tech_cost(short tech_id, short *inv_1, short *inv_amt_1, short *inv_2, short *inv_amt_2, short *inv_3, short *inv_amt_3);
    void obj_cost(short obj_id, char **name, short *inv_1, short *inv_amt_1, short *inv_2, short *inv_amt_2, short *inv_3, short *inv_amt_3, float modifier);

    RGE_Static_Object *find_obj(short obj_id, RGE_Static_Object *after_obj);
    RGE_Static_Object *make_new_object(int obj_id, float x, float y, float z, int build_all_the_way);

    void interface_tech_avail(Item_Avail **list, short *list_num, short obj_cat);
    void interface_item_avail(Item_Avail **list, short *list_num, short obj_cat);
    void interface_trade_avail(Trade_Avail **list, short *list_num);

    char command_make_building(short obj_id, float x, float y);
    char command_make_wall(short obj_id, int x1, int y1, int x2, int y2);
    char command_building_make_tech(short tech_id);
    char command_building_cancel();
    char command_delete_object(RGE_Static_Object *obj);
    char command_trade_attribute(int attribute);
    char command_trade_attribute(int unitID, int attribute);
    char command_attack_ground(float x, float y);
    char command_give_attribute(int to_player_id, int attr_id, float attr_amount, float attr_cost);
    char command_building_make_obj(short obj_id);
    char command_make_repair(RGE_Static_Object *obj);
    char command_make_unload(float x, float y);

    char check_obj_cost(short obj_id, short *attribute_needed, float modifier, int ignore_pop);
    char pay_obj_cost(short obj_id, float modifier, int ignore_pop);
    void reimburse_obj_cost(short obj_id);
    char check_tech_cost(short tech_id, short *attribute_needed);
    char pay_tech_cost(short tech_id);
    void tech_abling(int tech_id, char able_flag);
    void rev_tech(int age);
    void add_population_entry();
    void random_start();
    void objectCost(int id, int unused1, ResourceItem *ri, int unused2);
    int objectCostByType(int id);
    void researchCost(int id, int unused1, ResourceItem *ri, int unused2);
    int objectAvailable(int id);
    int researchAvailable(int id);
    int researchEverAvailable(int id);
    short researchState(int id);
    char *aiStatus(int sNum);
    void kickAI(int m);
    int strategicNumber(int sN);
    void logMessage(char *textIn, ...);
    int sendAICommand(int caller, int mType, int p1, int p2, int p3);
    RGE_Object_Node *addObject(RGE_Static_Object *obj, int sleepFlag, int dopple_flag);
    void removeObject(RGE_Static_Object *obj, int sleepFlag, int dopple_flag, RGE_Object_Node *node);
    void buildObject(int bi, int oi, float x, float y, int ui);
    void cancelBuild(int reason, int blockerID, int blockerType, float x, float y, int uniqueID, int builderID);
    void registerBuild(RGE_Static_Object *obj, int uniqueID);
    void trainUnit(int uType, int bID, int uniqueID);
    void cancelTrain(int reason, int uType, int location, int uniqueID);
    void registerTrain(int uType, int location, int uniqueID, int gameID);
    void research(int rType, int bID, int uniqueID);
    void cancelResearch(int reason, int rType, int location, int uniqueID);
    void registerResearch(int rType, int location, int uniqueID);
    void taskTrader(int tID, int oID, int ownerID, float x, float y);
    void taskResourceGatherer(int gID, int oID, int ownerID, float x, float y);
    void setDiplomaticStance(int playerNum, int rType);
    void loadAIInformation(char *bL, char *cP, char *rS, int mood, int mapType);
    void notify(int caller, int recipient, int mType, int p1, int p2, int p3);
    void notifyAI(int callerID, int recipientID, int mType, int p1, int p2, int p3);
    static int intelligentCivSelection(int mapType, int gameType, int mapSize);
    void intelligentBuildListAndRulesSelection(char *b, char *r, int mapType, int gameType, int mapSize);

    void setupEgyptian(int *b, int mapType, int gameType, int mapSize);
    void setupGreek(int *b, int mapType, int gameType, int mapSize);
    void setupBabylonian(int *b, int mapType, int gameType, int mapSize);
    void setupAssyrian(int *b, int mapType, int gameType, int mapSize);
    void setupMinoan(int *b, int mapType, int gameType, int mapSize);
    void setupHittite(int *b, int mapType, int gameType, int mapSize);
    void setupPhoenician(int *b, int mapType, int gameType, int mapSize);
    void setupSumerian(int *b, int mapType, int gameType, int mapSize);
    void setupPersian(int *b, int mapType, int gameType, int mapSize);
    void setupShang(int *b, int mapType, int gameType, int mapSize);
    void setupYamato(int *b, int mapType, int gameType, int mapSize);
    void setupChoson(int *b, int mapType, int gameType, int mapSize);
    void setupRoman(int *b, int mapType, int gameType, int mapSize);
    void setupCarthaginian(int *b, int mapType, int gameType, int mapSize);
    void setupPalmyran(int *b, int mapType, int gameType, int mapSize);
    void setupMacedonian(int *b, int mapType, int gameType, int mapSize);

    void logStatus(_iobuf *out, int firstTime);
    void trackUnitGather(int unitID, int attributeID, int amount);
    void get_achievement(char achievement, char *info);
    void load_victory(int infile, int *player_id_hash, char version_control);
    void new_victory();
    void add_attribute_num(short attribute, float amount, char earned);
    void analyize_selected_objects();
    int get_mouse_pointer_action_vars(int Obj_id, int *newFacet, int *text_id);

    void scenario_postload(int infile, int *player_id_hash, float version);
};

class TRIBE_Gaia : public TRIBE_Player
{
public:

    float update_time;
    int update_nature;
    int last_count;
    int animal_max;

    TRIBE_Gaia(int infile, TRIBE_World *gworld, char this_id);

    ~TRIBE_Gaia();

    TRIBE_Gaia(TRIBE_World *gworld, RGE_Master_Player *prototype, char this_id, char *new_name, char m_player_id);

    void save(int outfile);

    void update();

    void load_master_object(int infile, short index, char type, RGE_Sprite **sprites, RGE_Sound **sounds);
};
