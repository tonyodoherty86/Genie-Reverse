
/**
 * @file    Engine\RGE\CommQueue.hpp
 * @author  Yvan Burrie
 * @date    2018/02/20
 * @version 1.0
 */

class RGE_Communications_Queue
{
public:

    unsigned int QueueDepth;
    unsigned int HighQueueDepth;
    unsigned int MaxQSize;
    char TBuff[255];
    unsigned int LastCurrentTurn;
    char Sequence;
    class MsgQueue *Queue;

    RGE_Communications_Queue(int MaxSize);

    ~RGE_Communications_Queue();

    int AllocateQueue(unsigned int NewQSize);
    int ExpectedNextSequence(unsigned int TurnID, unsigned int PlayerNo);
    unsigned int QueuedForTurn(unsigned int TurnID);
    void FlushAll();
    unsigned int FlushTurnRange(unsigned int LowRange, unsigned int HiRange);
    void FlushForPlayer(unsigned int p);
    unsigned int FlushForTurn(unsigned int TurnID);
    unsigned int FlushThruTurn(unsigned int TurnID);
    int AddItem(unsigned int ExecuteOnTurn, void *command, unsigned int nBytes, unsigned int PFrom, char InSequence, int ControlCommand);

    unsigned int GetQueueDepth();
    unsigned int GetHighQueueDepth();
    void *GetSpecificItem(unsigned int FromPlayer, unsigned int ExecuteOnTurn, char Seq, unsigned int *Size);
    void *GetNextItemSingle();
    void *GetNextItemOrdered(unsigned int ThisTurn);
    char GetNextSequence(unsigned int ThisTurn);

    void TestShowQueue();
};

class MsgQueue
{
public:

    unsigned int Code;
    unsigned int ExecTurn;
    char SeqNo;
    char *msgptr;
    unsigned int From;
    unsigned int Size;
    int ControlCommand;

    MsgQueue();

    ~MsgQueue();
};
