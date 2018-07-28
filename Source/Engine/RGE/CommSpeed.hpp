
/**
 * @file    Engine\RGE\CommSpeed.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

class RGE_Communications_Speed
{
public:

    char TBuff[255];

    RGE_TimeSinceLastCall *TurnTSLC;
    RGE_TimeSinceLastCall *FrameTSLC;

    TCommunications_Handler *Comm;

    long double AccumDiff;
    int SpeedControlEnabled;
    unsigned int CurrentBufferFrames;
    unsigned int FutureBufferFrames;
    unsigned int TotalBufferFramesRemaining;
    unsigned int TargetTurnLengthMsec;
    unsigned int CurrentBufferGranularity;
    unsigned int FutureBufferGranularity;
    unsigned int OverheadFactor;
    unsigned int TimeSinceLastBuffer;
    unsigned int FutureSpeedChangeTurn;
    unsigned int NextLatencyChangeTurn;
    unsigned int ActualLatency[10];
    unsigned int AverageTSLC[10];
    char PlayerOptimalFrames[10];
    char PlayerOptimalGranularity[10];
    unsigned __int16 RequestFasterOrSlower[10];
    unsigned int PlayerAvgFramesMsec[10];
    unsigned int PlayerHighLatencyMsec[10];
    unsigned int HighestLatencyMsec;
    unsigned int SkipFrames;
    unsigned int OptimalBufferFrames;
    unsigned int OptimalBufferGranularity;
    unsigned int DiffOffset;
    unsigned int AllAcknowledgedBuffersRemaining;
    unsigned int LastAdjusted;
    unsigned int RealTimePassed;
    unsigned int BufferTimePassed;
    unsigned int DroppedFrames;
    unsigned int DroppedFramesTurn;
    unsigned int AdjustmentCount;
    int LastFrameHadTime;

    RGE_Communications_Speed(TCommunications_Handler *c);

    ~RGE_Communications_Speed();

    void SetPlayerTurnSpeed(unsigned int PlayerNo, char AvgFramesMsec, char HiLatencyCenti);
    void SetActualLatency(unsigned int PlayerNo, unsigned int Msec);
    void SetFutureSpeedChange(unsigned int BuffCount, unsigned int BuffGran, unsigned int ExecTurn);
    void EnableSpeedControl(int TorF);
    unsigned int GetBufferGranularity();
    unsigned int GetAdjustmentCount();
    unsigned int GetBufferGranularityAdjusted();
    unsigned int BufferFramesRemaining();
    unsigned int WaitingOnAcknowledgement();
    void AdjustLocalSpeed();
    void ReloadBufferFrames();
    unsigned int BufferTimeToUse(unsigned int current_turn);
    void Skip();
    unsigned int GetHighLatencyCenti();
    unsigned int GetPlayerLatency(unsigned int PlayerNo);
    RGE_Communications_Speed *GetLatencyInfo();
    char *GetSelfPlayerOptimalSpeedStr();
    char *GetPlayerSpeedStatusStr(int PlayerNo);
    char *GetMachineSpeedInfo();
    int GetRecommendedBufferFrames();
    unsigned int GetAvgFrameRate();
    unsigned int GetRecommendedBufferGranularity();
    int AnalyzeGameSpeed(unsigned int *NewGranularity, unsigned int *NewBufferFrames, int ChangeAlso);
    static void SetV1(unsigned int v1);
    static void SetV2(unsigned int v2);
};
