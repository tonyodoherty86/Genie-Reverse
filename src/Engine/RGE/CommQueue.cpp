
class RGE_Communications_Queue
{
    unsigned int QueueDepth;
    unsigned int HighQueueDepth;
    unsigned int MaxQSize;
    char TBuff[255];
    unsigned int LastCurrentTurn;
    char Sequence;
    struct MsgQueue *Queue;
};

struct MsgQueue
{
    unsigned int Code;
    unsigned int ExecTurn;
    char SeqNo;
    char *msgptr;
    unsigned int From;
    unsigned int Size;
    int ControlCommand;
};
