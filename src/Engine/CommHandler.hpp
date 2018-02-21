
/**
 * @file    Engine\CommHandler.hpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

enum COMMSTATUS
{
    UNINITIALIZED           = 0x00,
    INITIALIZED             = 0x01,
    SINGLE_PLAYER           = 0x02,
    MULTIPLAYER_RESET       = 0x03,
    CONVERSATION_OPEN       = 0x04,
    SERVICE_AVAILABLE       = 0x05,
    SESSION_AVAILABLE       = 0x06,
    SESSION_HOSTED          = 0x07,
    SESSION_JOINED          = 0x08,
    PLAYER_CREATED          = 0x09,
    COMM_SETTINGS_EXCHANGED = 0x0A,
    GAME_PLAYER_SET         = 0x0B,
    GAME_OPTIONS_EXCHANGED  = 0x0C,
    GAME_IS_LOADING         = 0x0D,
    GAME_IS_RUNNING         = 0x0E,
    GAME_IS_PAUSED          = 0x0F,
};

enum COMMSTATES
{
    COMM_STATE_ERROR      = 0x01,
    COMM_STATE_INITIALIZE = 0x02,
    COMM_STATE_JOINNOW    = 0x03,
    COMM_STATE_PAUSE      = 0x04,
    COMM_STATE_RUNNING    = 0x05,
    COMM_STATE_FINISHED   = 0x06,
};

enum PLAYERHUMANITY
{
    ME_ABSENT     = 0x00,
    ME_CLOSED     = 0x01,
    ME_HUMAN      = 0x02,
    ME_ELIMINATED = 0x03,
    ME_COMPUTER   = 0x04,
    ME_CYBORG     = 0x05,
    ME_VIEWONLY   = 0x06,
};

struct COMMPLAYEROPTIONS
{
    char NeedsToBeSent;
    unsigned int LastSentTime;

    COMMSTATES ProgramState;

    unsigned int CurrentTurn;
    char TurnSpeedMsec;
    unsigned int dcoID[10];
    unsigned int AcknowledgeAfterMsec;
    char CommandTurnIncrement;
    int PlayerReady[10];
    unsigned int User1[10];
    unsigned int User2[10];
    unsigned int User3[10];
    unsigned int User4[10];
    unsigned int User5[10];
    unsigned int User6[10];
    unsigned int User7[10];

    PLAYERHUMANITY Humanity[10];

    char InvalidPlayer[10];
    unsigned int Initialized;
    unsigned int RandomSeed;
    unsigned short HighPlayerNumber;
    unsigned short LowPlayerNumber;
    unsigned int HostPlayerNumber;
    int GameHasStarted;
    unsigned int DataSizeToFollow;
};

enum COMMMESSAGES
{
    COMM_PAUSE = 0x17A2,
    COMM_RESUME = 0x17A3,
    COMM_UPDATE_PLAYERS = 0x17A4,
    COMM_UPDATE_CHAT = 0x17A5,
    COMM_UPDATE_PARAMS = 0x17A6,
    COMM_LAUNCH_GAME = 0x17A7,
    COMM_CANCEL_GAME = 0x17A8,
    COMM_HOST_EXITED = 0x17A9,
    COMM_PLAYER_KICKED = 0x17AA,
    COMM_NO_NEW_PLAYERS = 0x17AB,
    COMM_FATAL_ERROR = 0x17AC,
    COMM_CONNECTED = 0x17AD,
    COMM_NO_LINK = 0x17AE,
    COMM_CLIENT_IS_SLOW = 0x17AF,
    COMM_SYNC_ERROR = 0x17B0,
    COMM_HOST_CHANGED = 0x17B1,
    COMM_PLAYER_DROPPED = 0x17B2,
    COMM_OTHER_PLAYER_DROPPED = 0x17B3,
    COMM_PLAYER_RESIGNED = 0x17B4,
    COMM_PLAYER_DEFEATED = 0x17B5,
    COMM_PLAYER_BAD_VERSION = 0x17B6,
    COMM_PLAYER_SERVICE_ERROR = 0x17B7,
    COMM_PLAYER_ID_SET = 0x17B8,
    COMM_HOST_BUSY = 0x17B9,
    COMM_LOBBY_TIMEOUT = 0x17BA,
    COMM_SHARED_DATA_SENT = 0x17BB,
    COMM_NO_OTHER_HUMANS = 0x17BC,
    COMM_PLAYER_NOT_RESPONDING = 0x17BD,
    COMM_UNKNOWN = 0x17BE,
};

class TCommunications_Handler
{
public:

    int OptionsChanged;
    char *OptionsData;

    int Steps;

    unsigned int TickStart;
    unsigned int TickCount;

    unsigned int TimeSinceLastCall;

    class TChat *Chat;

    int MeHost;
    int HaveHostInit;
    char InCommBuff[4001];
    char TBuff[257];
    unsigned int current_turn;
    unsigned int next_command_turn;
    unsigned int sequence;
    int WaitOnPlayer;
    unsigned int TurnSpeedMsec;
    unsigned int AcknowledgeAfterMsec;
    unsigned int Me;
    int Multiplayer;
    int OutOfSyncFlag;
    unsigned int dwStopTime;

    float lastRXDataRate,
          lastTXDataRate;

    char MyFriendlyName[129],
         MyFormalName[129],
         MyGameTitle[129];

    unsigned int CurrentPlayers;

    int previous_last_world_random;
    int last_world_random;

    int StepMode;

    unsigned int turnstart;
    unsigned int lastcalltick;
    unsigned int mselapsed;

    int AvgTurnTime;
    int SkipFrames;
    int PauseChangePending;
    unsigned int CommunicationsVersionCode;
    int ShuttingDown;
    unsigned int ReturnElapsed;
    unsigned int ReturnRXPacketSize;
    unsigned int ReturnTXPacketSize;
    unsigned int RXPacketLength;
    unsigned int RXPacketLengthHigh;
    unsigned int TXPacketLength;
    unsigned int TXPacketLengthHigh;

    struct NAME *FriendlyName,
                *FormalName;

    unsigned int LastTimeoutMessageTime;

    COMMSTATUS CommunicationsStatus;

    unsigned short MaxGamePlayers;

    GUID ServiceGUID,
         ApplicationGUID,
         SessionGUID;

    HWND *HostHWND;

    int LobbyLaunched;
    unsigned int MaxReceiveLatency;
    GUID NullGUID;
    unsigned int ResendAcknowledgements;
    unsigned int ResentToOther;
    unsigned int DroppedPacketCount;
    unsigned int RXPackets;
    unsigned int TXPackets;
    int IAmLagging;
    unsigned int ServiceTimeout;
    unsigned int LastPlayerCommunication[10];
    unsigned int LastPlayerWarning[10];
    unsigned int LastTXPing[10];
    unsigned int PlayerStopTurn[10];
    unsigned int LastSerialRequestedTX[10];
    unsigned int LastRequestHonoredTX[10];
    unsigned int LastSerialRepliedTX[10];
    unsigned int LastRequestRepliedTX[10];
    unsigned int dwFlags;
    unsigned int dwMaxBufferSize;
    unsigned int dwMaxQueueSize;
    unsigned int dwMaxPlayers;
    unsigned int dwHundredBaud;
    unsigned int dwLatency;
    int Kicked[10];

    class RGE_Communications_Queue *InQ,
                                   *OutQ;
    class RGE_Lobby *Lobby;
    class RGE_TimeSinceLastCall *tslc;
    class RGE_Communications_Speed *Speed;
    class RGE_Communications_Synchronize *Sync;
    class RGE_Communications_Addresses *Addresses;
    class RGE_Comm_Error *Err;

    unsigned int GTDSerialNo;
    unsigned int HighResendStore;
    unsigned int DestMap[10];
    char RGE_Guaranteed_Delivery;
    int IntentionallyDropPackets;
    unsigned int WaitingForAck;
    struct RESENDER *Resend;
    struct HOLDER *OnHold;
    unsigned int PlayerHighSerialNumber[10];

    COMMPLAYEROPTIONS PlayerOptions;

    unsigned int LastTurnAck[10];
    unsigned int HoldCount;
    int WasKicked[10];

    void GameOver();

    char *WaitingOnNamedInfo(unsigned int PlayerNo);
    char *WaitingOnInfo(unsigned int PlayerNo);

    void StopIfSyncFail(int b);
    void ShowSyncChatMsgs(int b);
    void DropPacketsIntentionally(int b);
    void SetStepMode(int b);
    void SetSpeedControl(int b);
    int CalculatePlayerRange();
    void Step(int Numsteps);

    TCommunications_Handler(HWND *WinHandle, char MaxPlayers, TChat *ChatHandle, GUID AppGuid);
    ~TCommunications_Handler();

    void KillAnyMissingPlayers();
    int AddCommand(unsigned int ExecuteOnTurn, void *command, unsigned int nBytes, int PFrom, char Sequence, int ControlCommand);
    void *get_command();
    int new_command(void *Command, int Size);
    int NewCommand(void *Command, int Size, int ControlCommand);
    void LastWorldRandom(int lwr);
    int DoCycle(unsigned int WorldTime);
    int HasKicked(unsigned int p);
    int SendPlayerName();
    void LogRXMsg(unsigned int Serialno, unsigned int fromPlayer, unsigned int ExecuteOnTurn, char Command, char Sequence);
    void ReceiveGameMessages();
    void ShutdownGameMessages();
    void GetDPLAYMessages();
    void CheckPingTime(int Forced);
    int TXPing(unsigned int ToPlayer);
    int TXDebugPing();
    int FastSend(unsigned int ToDPID, void *Buffer, unsigned int BuffLen, int Priority, int Guaranteed);
    int PreprocessMessages(unsigned int dwSize, char *CommBuff, unsigned int dcoFromID, unsigned int dcoReceiveID, int fromHold);

    void NotifyWindow(COMMMESSAGES msg);
    void NotifyWindowParam(COMMMESSAGES msg, int lparam);
    int EvaluatePlayerMessage(unsigned int len, unsigned int fromPlayer, unsigned int ExecuteOnTurn, char Command, char Sequence, char *Content, unsigned int ContentSize, unsigned int dcoFromID, unsigned int dcoReceiveID);
    void SetPlayerStopTurn(unsigned int player, unsigned int Turn);
    void CheckPlayerStopTurn(unsigned int Turn);
    void ReleaseSettings();
    int SendSharedData(int SendImmediately);
    static int TEST();
    void SetSelfPlayer();
    void DropDeadPlayer(unsigned int PlayerNo, unsigned int PlayerDPID);
    void EvaluateSystemMessage(unsigned int type, char *CommBuff, unsigned int dcoFromID, unsigned int dcoReceiveID);
    void SendGroupChatMsg(char *Text);
    void SendChatMsgAll(char *Text);
    void SendChatMsg(unsigned int GamerID, unsigned int DestPlayerNo, char *Text);
    int TXChat(unsigned int GamerID, char *DestMap, char *Text);
    void SendSpeedChange(unsigned int Frames, unsigned int Granularity);
    void SendIResignMsg();
    unsigned int HiTurnAcknowledged();
    int AllPlayersAcknowledged();
    int SendChecksumMessage(unsigned int worldtime, unsigned int random, int csum1, int csum2, int csum3, int csum4, int csum5);
    unsigned int ExecuteIncoming();
    void ClearAllSerialNumbers();
    void ClearRXandTX();
    void ClearRXForPlayer(unsigned int PlayerNo);
    int CountWaitingMessages();
    void ClearTXForPlayer(unsigned int PlayerNo);
    void ClearRXTXForPlayer(unsigned int PlayerNo);
    int StoreIncoming(unsigned int SerialNumber, char *InBuff, unsigned int Length, unsigned int dcoFromID, unsigned int dcoReceiveID);
    int StoreForResend(unsigned int SerialNumber, char *OutCommBuff, unsigned int Length, unsigned int *ResendDestMap);
    int TXAcknowledgeMessage(unsigned int serialno, unsigned int fromPlayer);
    int RXAcknowledgeStoredMessage(unsigned int serialno, unsigned int fromPlayer);
    int PurgeAcknowledgedStoredMessages();
    unsigned int SendStoredMessages();
    int TXResendReply(unsigned int serial, unsigned int toPlayer);
    int TXResendRequest(unsigned int serial, unsigned int toPlayer);
    unsigned char GetNextSequence(unsigned int ThisTurn);
    int CommOut(unsigned int To, char MsgType, void *Msg, int Length, char ResendSeq);
    void DestroyMultiplayerGame();
    int GetCommunicationsStatus();
    int UnlinkCurrentLevel();
    int UnlinkToLevel(COMMSTATUS lvl);
    int AnalyzeCommunicationsStatus();
    void ResetLastCommunicationTimes();
    int IsPaused();
    void DropAllHostedPlayers();
    void LocalResumeGame(unsigned int p);
    void LocalPauseGame(unsigned int p);
    void SendPauseGame(int Pause);
    int TogglePauseGame();
    void RequestPauseGame(int SendChatInfo);
    void RequestResumeGame(int SendChatInfo);
    void SetRandomSeed(int val);
    unsigned int GetRandomSeed();
    unsigned int WhoAmI();
    int IsHost();
    static char *GetCommStateStr();
    char *GetReadyPlayerStr();
    PLAYERHUMANITY GetPlayerHumanity(unsigned int PlayerNo);
    void SetPlayerHumanity(unsigned int PlayerNo, PLAYERHUMANITY Type);
    int GetActivePlayerCount();
    int IsPlayerHuman(unsigned int PlayerNo);
    int IsPlayerComputer(unsigned int PlayerNo);
    char *GetCommInfo(char LineNum);
    char *GetPlayerName(unsigned int PlayerNo);
    void UpdatePlayerInformation(unsigned int dpID, char *AFriendlyName, char *AFormalName);
    int IsLobbyLaunched();
    IDirectPlay3 *LaunchLobbyGame();
    void InitPlayerInformation(unsigned int PlayerNo, unsigned int dpID, char *FrName, char *FoName);
    int SetGameTitle(char *Game);
    void SetMyPlayerName(char *Name);
    void SetPlayerName(unsigned int PlayerNo, char *Name);
    void *SetWindowHandle(void *hwnd);
    int CreateDirectPlayConversation();
    static int OpenMultiplayerConnection();
    int CreateMultiplayerGame();
    void PackPlayersDown();
    IDirectPlay3 *AddSelfPlayer();
    int InitJoinGame();
    IDirectPlay3 *JoinMultiplayerGame(GUID *GameGuid);
    void LaunchMultiplayerGame();
    int GetMyMultiPlayerCaps();
    void SetApplicationGUID(GUID guid);
    static IDirectPlay3 *GetDPInterface();
    void SetServiceGUID(GUID inGuid);
    void SetSessionGUID(GUID inGuid);
    void UpdatePlayers();
    void UpdatePlayer(unsigned int PlayerNo, int Notify);
    int SetMyReadiness(int Ready, unsigned int User1, unsigned int User2, unsigned int User3, unsigned int User4, unsigned int User5, unsigned int User6, unsigned int User7);
    int GetClientReadiness(unsigned int PlayerNo, int *Ready, unsigned int *User1, unsigned int *User2, unsigned int *User3, unsigned int *User4, unsigned int *User5, unsigned int *User6, unsigned int *User7);
    int IsPlayerReady(unsigned int PlayerNo);
    int ComputerPlayerGameStart();
    int MultiplayerGameStart();
    int AllPlayersReady();
    int DPlayGetSessionDesc();
    int CommGetCaps();
    int CloseSession();
    int ReleaseComm();
    int Kick(unsigned int PlayerNo);
    IDirectPlay3 *DestroyMyPlayer();
    char *SetMyGameOptions(char *vpData, unsigned int dwSize);
    char *GetMyGameOptions(unsigned int *dwSize);
    void FreeOptions();
    void SetHostPlayerNumber(unsigned int PlayerNo);
    unsigned int GetHostPlayerNumber();
    static void DebugSessionInformation(DPSESSIONDESC2 *dpsd);
    static int EnableNewPlayers(IDirectPlay2 *lpDP2, int bEnable);
    void OutOfSync(int Status, unsigned int StopTime);
    int SendZoneMessage(char *Data, unsigned int dwSize);
    static int EnumPlayersCallback2(unsigned int pidID, unsigned int dwPlayerType, DPNAME *lpName, unsigned int dwFlags, void *lpContext);
    void ForcePlayerEnumeration();
    void ForcePlayerDestroyAndCreate();
    static void ForceNameChange();
    void SetSpeedV1(unsigned int v1);
    void SetSpeedV2(unsigned int v2);
    int IsPlayerOutOfSync(unsigned int pnum, unsigned int worldturn);
};

int StringFromGUID(GUID *lpguid, unsigned short *lpwsz);

struct NAME
{
    char Text[128];
};

struct RESENDER
{
    unsigned int TimeSent;
    unsigned int Serial;
    char *ResendMsg;
    unsigned int Length;
    unsigned int DestMap[10];

    RESENDER();
    ~RESENDER();
};

struct HOLDER
{
    char *HoldMsg;
    unsigned int Serial;
    unsigned int Length;
    unsigned int dcoFromID;
    unsigned int dcoReceiveID;
    unsigned int fromPlayer;

    HOLDER();
    ~HOLDER();
};
