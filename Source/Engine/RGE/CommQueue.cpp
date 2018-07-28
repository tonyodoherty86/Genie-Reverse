
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

//----- (00431720) --------------------------------------------------------
void __thiscall RGE_Communications_Queue::RGE_Communications_Queue(RGE_Communications_Queue *this, int MaxSize)
{
  int v2; // eax@1

  v2 = MaxSize;
  if( MaxSize < 20 )
    v2 = 20;
  this->QueueDepth = 0;
  this->HighQueueDepth = 0;
  this->LastCurrentTurn = 0;
  this->Queue = 0;
  this->MaxQSize = v2;
  this->Sequence = 1;
  RGE_Communications_Queue::AllocateQueue(this, v2);
}

//----- (00431760) --------------------------------------------------------
void __thiscall RGE_Communications_Queue::~RGE_Communications_Queue(RGE_Communications_Queue *this)
{
  MsgQueue *v1; // eax@1
  int *v2; // esi@2

  v1 = this->Queue;
  if( v1 )
  {
    v2 = &v1[-1].ControlCommand;
    `eh vector destructor iterator'(
      (int)v1,
      0x1Cu,
      v1[-1].ControlCommand,
      (void (__thiscall *)(void *))MsgQueue::~MsgQueue);
    operator delete(v2);
  }
}

//----- (00431790) --------------------------------------------------------
MsgQueue *__thiscall MsgQueue::`vector deleting destructor'(MsgQueue *this, unsigned int __flags)
{
  MsgQueue *v2; // esi@1
  MsgQueue *result; // eax@2
  char *v4; // eax@3

  v2 = this;
  if( __flags & 2 )
  {
    `eh vector destructor iterator'(
      (int)this,
      0x1Cu,
      this[-1].ControlCommand,
      (void (__thiscall *)(void *))MsgQueue::~MsgQueue);
    operator delete(&v2[-1].ControlCommand);
    result = v2;
  }
  else
  {
    v4 = this->msgptr;
    this->Code = 0;
    this->ExecTurn = 0;
    this->SeqNo = 0;
    this->From = 0;
    this->Size = 0;
    this->ControlCommand = 0;
    if( v4 )
      operator delete(v4);
    v2->msgptr = 0;
    if( __flags & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (00431810) --------------------------------------------------------
int __thiscall RGE_Communications_Queue::AllocateQueue(RGE_Communications_Queue *this, unsigned int NewQSize)
{
  RGE_Communications_Queue *v2; // esi@1
  int result; // eax@2
  int v4; // ebx@3
  void *v5; // eax@3
  int v6; // ebp@4
  int v7; // eax@9
  int v8; // ebp@9
  int v9; // ebx@10
  int v10; // eax@11
  unsigned int v11; // edi@11
  void *v12; // eax@11
  int v13; // eax@15
  void *v14; // edi@16
  MsgQueue *v15; // [sp+10h] [bp-20h]@4
  unsigned int i; // [sp+14h] [bp-1Ch]@9
  const void *v17; // [sp+18h] [bp-18h]@11
  RGE_Communications_Queue *v18; // [sp+1Ch] [bp-14h]@1

  v2 = this;
  v18 = this;
  if( NewQSize >= this->MaxQSize )
  {
    v4 = NewQSize + 1;
    v5 = operator new(28 * (NewQSize + 1) + 4);
    if( v5 )
    {
      v6 = (int)v5 + 4;
      *(_DWORD *)v5 = v4;
      `eh vector constructor iterator'(
        (char *)v5 + 4,
        0x1Cu,
        v4,
        (int)MsgQueue::MsgQueue,
        (void (__thiscall *)(void *))MsgQueue::~MsgQueue);
      v15 = (MsgQueue *)v6;
    }
    else
    {
      v15 = 0;
    }
    if( v15 )
    {
      if( v2->Queue )
      {
        i = 0;
        v7 = -8 - (_DWORD)v15;
        v8 = (int)&v15->SeqNo;
        do
        {
          v9 = v7 + v8;
          if( *(unsigned int *)((char *)&v2->Queue->Size + v7 + v8) )
          {
            *(_DWORD *)(v8 - 8) = 0;
            *(_DWORD *)(v8 - 4) = 0;
            *(_BYTE *)v8 = 0;
            *(_DWORD *)(v8 + 8) = 0;
            *(_DWORD *)(v8 + 12) = 0;
            *(_DWORD *)(v8 + 16) = 0;
            *(_DWORD *)(v8 - 8) = *(unsigned int *)((char *)&v2->Queue->Code + v9);
            *(_DWORD *)(v8 - 4) = *(unsigned int *)((char *)&v2->Queue->ExecTurn + v9);
            *(_BYTE *)v8 = *(&v2->Queue->SeqNo + v9);
            v10 = (int)v2->Queue + v9;
            v11 = *(_DWORD *)(v10 + 20);
            v17 = *(const void **)(v10 + 12);
            v12 = operator new(v11 + 1);
            *(_DWORD *)(v8 + 4) = v12;
            if( v12 )
            {
              qmemcpy(v12, v17, v11);
              v2 = v18;
            }
            *(_DWORD *)(v8 + 8) = *(unsigned int *)((char *)&v2->Queue->From + v9);
            *(_DWORD *)(v8 + 12) = *(unsigned int *)((char *)&v2->Queue->Size + v9);
            *(_DWORD *)(v8 + 16) = *(int *)((char *)&v2->Queue->ControlCommand + v9);
            v7 = -8 - (_DWORD)v15;
          }
          v8 += 28;
          ++i;
        }
        while( i <= v2->MaxQSize );
        v13 = (int)v2->Queue;
        if( v13 )
        {
          v14 = (void *)(v13 - 4);
          `eh vector destructor iterator'(
            v13,
            0x1Cu,
            *(_DWORD *)(v13 - 4),
            (void (__thiscall *)(void *))MsgQueue::~MsgQueue);
          operator delete(v14);
        }
      }
      v2->MaxQSize = NewQSize;
      v2->Queue = v15;
      result = 1;
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004319E0) --------------------------------------------------------
int __thiscall RGE_Communications_Queue::ExpectedNextSequence(RGE_Communications_Queue *this, unsigned int TurnID, unsigned int PlayerNo)
{
  char v3; // bl@1
  unsigned int v4; // esi@1
  int v5; // edx@1
  MsgQueue *v6; // eax@2
  unsigned int v7; // eax@6

  v3 = 1;
  v4 = 0;
  Count[0] = 1;
  v5 = 0;
  do
  {
    v6 = &this->Queue[v5];
    if( v6->ExecTurn == TurnID && v6->From == PlayerNo && v6->Size )
      Count[0] = ++v3;
    v7 = this->HighQueueDepth;
    ++v4;
    ++v5;
  }
  while( v4 <= v7 );
  LOBYTE(v7) = -((unsigned __int8)v3 <= 0xFFu);
  return *(_DWORD *)Count & v7;
}

//----- (00431A40) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Queue::QueuedForTurn(RGE_Communications_Queue *this, unsigned int TurnID)
{
  unsigned int result; // eax@1
  char *v3; // edx@1
  unsigned int v4; // ecx@1

  result = 0;
  v3 = (char *)&this->Queue->ExecTurn;
  v4 = this->HighQueueDepth + 1;
  do
  {
    if( *(_DWORD *)v3 == TurnID )
      ++result;
    v3 += 28;
    --v4;
  }
  while( v4 );
  return result;
}

//----- (00431A70) --------------------------------------------------------
void __thiscall RGE_Communications_Queue::FlushAll(RGE_Communications_Queue *this)
{
  RGE_Communications_Queue::FlushTurnRange(this, 0, 0);
}

//----- (00431A80) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Queue::FlushTurnRange(RGE_Communications_Queue *this, unsigned int LowRange, unsigned int HiRange)
{
  RGE_Communications_Queue *v3; // ebp@1
  int v4; // edi@1
  MsgQueue *v5; // eax@2
  int v6; // esi@2
  unsigned int v7; // eax@2
  void *v8; // eax@7
  unsigned int Count; // [sp+10h] [bp-8h]@1
  unsigned int i; // [sp+14h] [bp-4h]@1

  v3 = this;
  Count = 0;
  i = 0;
  v4 = 0;
  do
  {
    v5 = v3->Queue;
    v6 = (int)&v5[v4];
    v7 = v5[v4].ExecTurn;
    if( v7 >= LowRange && v7 <= HiRange || !LowRange && !HiRange )
    {
      ++Count;
      if( *(_DWORD *)(v6 + 20) > 0u )
      {
        v8 = *(void **)(v6 + 12);
        *(_DWORD *)v6 = 0;
        *(_DWORD *)(v6 + 4) = 0;
        *(_BYTE *)(v6 + 8) = 0;
        *(_DWORD *)(v6 + 16) = 0;
        *(_DWORD *)(v6 + 20) = 0;
        *(_DWORD *)(v6 + 24) = 0;
        if( v8 )
          operator delete(v8);
        *(_DWORD *)(v6 + 12) = 0;
      }
    }
    ++v4;
    ++i;
  }
  while( i <= v3->HighQueueDepth );
  return Count;
}

//----- (00431B10) --------------------------------------------------------
void __thiscall RGE_Communications_Queue::FlushForPlayer(RGE_Communications_Queue *this, unsigned int p)
{
  RGE_Communications_Queue *v2; // ebp@1
  int v3; // edi@1
  MsgQueue *v4; // edx@2
  unsigned int v5; // ecx@2
  int v6; // eax@2
  unsigned int v7; // edx@3
  int v8; // esi@4
  void *v9; // eax@4
  unsigned int i; // [sp+10h] [bp-4h]@1

  v2 = this;
  TDebuggingLog::Log(L, aFlushingQueueF, p);
  i = 0;
  v3 = 0;
  do
  {
    v4 = v2->Queue;
    v5 = v4[v3].From;
    v6 = (int)&v4[v3];
    if( v5 == p )
    {
      v7 = *(_DWORD *)(v6 + 20);
      if( v7 > 0 )
      {
        TDebuggingLog::Log(
          L,
          aRemoveQDSeqDTo,
          i,
          *(_BYTE *)(v6 + 8),
          *(_DWORD *)(v6 + 4),
          v5,
          v7,
          *(_DWORD *)(v6 + 24),
          *(_DWORD *)v6);
        v8 = (int)&v2->Queue[v3];
        v9 = *(void **)(v8 + 12);
        *(_DWORD *)v8 = 0;
        *(_DWORD *)(v8 + 4) = 0;
        *(_BYTE *)(v8 + 8) = 0;
        *(_DWORD *)(v8 + 16) = 0;
        *(_DWORD *)(v8 + 20) = 0;
        *(_DWORD *)(v8 + 24) = 0;
        if( v9 )
          operator delete(v9);
        *(_DWORD *)(v8 + 12) = 0;
      }
    }
    ++v3;
    ++i;
  }
  while( i <= v2->HighQueueDepth );
}

//----- (00431BD0) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Queue::FlushForTurn(RGE_Communications_Queue *this, unsigned int TurnID)
{
  return RGE_Communications_Queue::FlushTurnRange(this, TurnID, TurnID);
}

//----- (00431BE0) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Queue::FlushThruTurn(RGE_Communications_Queue *this, unsigned int TurnID)
{
  return RGE_Communications_Queue::FlushTurnRange(this, 0, TurnID);
}

//----- (00431BF0) --------------------------------------------------------
int __thiscall RGE_Communications_Queue::AddItem(RGE_Communications_Queue *this, unsigned int ExecuteOnTurn, void *command, unsigned int nBytes, unsigned int PFrom, char InSequence, int ControlCommand)
{
  RGE_Communications_Queue *v7; // ebp@1
  unsigned int v8; // esi@1
  char *v9; // eax@1
  unsigned int v10; // ecx@2
  int v11; // edx@4
  unsigned int v12; // eax@6
  int result; // eax@7
  unsigned int v14; // eax@9
  MsgQueue *v15; // edi@11
  int v16; // ebx@11
  char *v17; // eax@11
  unsigned int i; // [sp+10h] [bp-4h]@1

  v7 = this;
  v8 = 0;
  i = 0;
  v9 = (char *)&this->Queue->Size;
  if( *(_DWORD *)v9 )
  {
    v10 = this->MaxQSize;
    do
    {
      if( v8 >= v10 )
        break;
      v11 = *((_DWORD *)v9 + 7);
      v9 += 28;
      ++v8;
    }
    while( v11 );
    i = v8;
  }
  v12 = v7->MaxQSize;
  if( v8 >= v12 )
  {
    result = RGE_Communications_Queue::AllocateQueue(v7, v12 + 20);
    if( !result )
      return result;
    i = ++v8;
  }
  v14 = v7->HighQueueDepth;
  if( v8 > v14 )
    v14 = v8;
  v15 = v7->Queue;
  v7->HighQueueDepth = v14;
  v16 = v8;
  v17 = (char *)operator new(nBytes + 1);
  v15[v8].msgptr = v17;
  if( v17 )
  {
    qmemcpy(v17, command, nBytes);
    v8 = i;
  }
  v7->Queue[v16].Size = nBytes;
  v7->Queue[v16].SeqNo = InSequence;
  v7->Queue[v16].ExecTurn = ExecuteOnTurn;
  v7->Queue[v16].From = PFrom;
  v7->Queue[v16].Code = (unsigned __int8)InSequence + 1000 * PFrom;
  result = 1;
  v7->Queue[v16].ControlCommand = ControlCommand;
  v7->QueueDepth = v8;
  return result;
}

//----- (00431D10) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Queue::GetQueueDepth(RGE_Communications_Queue *this)
{
  return this->QueueDepth;
}

//----- (00431D20) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Queue::GetHighQueueDepth(RGE_Communications_Queue *this)
{
  return this->HighQueueDepth;
}

//----- (00431D30) --------------------------------------------------------
void *__thiscall RGE_Communications_Queue::GetSpecificItem(RGE_Communications_Queue *this, unsigned int FromPlayer, unsigned int ExecuteOnTurn, char Seq, unsigned int *Size)
{
  unsigned int v5; // edx@1
  MsgQueue *v6; // eax@1
  MsgQueue *v8; // ecx@6

  v5 = 0;
  v6 = this->Queue;
  while( v6->Code != (unsigned __int8)Seq + 1000 * FromPlayer || v6->ExecTurn != ExecuteOnTurn )
  {
    ++v5;
    ++v6;
    if( v5 > this->HighQueueDepth )
      return 0;
  }
  *Size = this->Queue[v5].Size;
  retptr_1 = this->Queue[v5].msgptr;
  this->Queue[v5].msgptr = 0;
  v8 = &this->Queue[v5];
  v8->Code = 0;
  v8->ExecTurn = 0;
  v8->SeqNo = 0;
  v8->From = 0;
  v8->Size = 0;
  v8->ControlCommand = 0;
  return retptr_1;
}

//----- (00431DD0) --------------------------------------------------------
void *__thiscall RGE_Communications_Queue::GetNextItemSingle(RGE_Communications_Queue *this)
{
  MsgQueue *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int *v3; // edx@1
  unsigned int v5; // edx@5
  MsgQueue *v6; // eax@5

  v1 = this->Queue;
  v2 = 0;
  v3 = &v1->Size;
  while( *v3 <= 0 )
  {
    ++v2;
    v3 += 7;
    if( v2 > this->HighQueueDepth )
      return 0;
  }
  v5 = v2;
  retptr = v1[v2].msgptr;
  v6 = &this->Queue[v2];
  v6->Code = 0;
  v6->ExecTurn = 0;
  v6->SeqNo = 0;
  v6->From = 0;
  v6->Size = 0;
  v6->ControlCommand = 0;
  this->Queue[v5].msgptr = 0;
  return retptr;
}

//----- (00431E40) --------------------------------------------------------
void *__thiscall RGE_Communications_Queue::GetNextItemOrdered(RGE_Communications_Queue *this, unsigned int ThisTurn)
{
  unsigned int v2; // ebx@1
  unsigned int v3; // ebp@1
  RGE_Communications_Queue *v4; // esi@1
  unsigned int v5; // edi@1
  int v6; // eax@2
  MsgQueue *v7; // edx@6
  void *result; // eax@11
  int v9; // esi@12
  int SendMsg; // [sp+10h] [bp-4h]@1

  v2 = -1;
  v3 = 0;
  v4 = this;
  SendMsg = -1;
  v5 = 0;
  do
  {
    v6 = (int)&v4->Queue[v5];
    if( *(_DWORD *)v6 && *(_DWORD *)(v6 + 20) )
    {
      if( *(_DWORD *)(v6 + 4) < ThisTurn )
        RGE_Communications_Queue::TestShowQueue(v4);
      v7 = v4->Queue;
      if( v7[v5].Code < v2 && v7[v5].ExecTurn == ThisTurn )
      {
        v2 = v7[v5].Code;
        SendMsg = v3;
      }
    }
    ++v3;
    ++v5;
  }
  while( v3 <= v4->HighQueueDepth );
  if( SendMsg == -1 )
  {
    result = 0;
  }
  else
  {
    retptr_0 = v4->Queue[SendMsg].msgptr;
    v4->Queue[SendMsg].msgptr = 0;
    v9 = (int)&v4->Queue[SendMsg];
    *(_DWORD *)v9 = 0;
    *(_DWORD *)(v9 + 4) = 0;
    *(_BYTE *)(v9 + 8) = 0;
    *(_DWORD *)(v9 + 16) = 0;
    *(_DWORD *)(v9 + 20) = 0;
    *(_DWORD *)(v9 + 24) = 0;
    result = retptr_0;
  }
  return result;
}

//----- (00431F10) --------------------------------------------------------
char __thiscall RGE_Communications_Queue::GetNextSequence(RGE_Communications_Queue *this, unsigned int ThisTurn)
{
  char result; // al@2
  char v3; // dl@3

  if( ThisTurn == this->LastCurrentTurn )
  {
    v3 = this->Sequence + 1;
    this->Sequence = v3;
    result = (unsigned __int8)v3 < 0xFFu ? v3 : 0;
  }
  else
  {
    this->LastCurrentTurn = ThisTurn;
    this->Sequence = 1;
    result = 1;
  }
  return result;
}

//----- (00431F60) --------------------------------------------------------
void __thiscall MsgQueue::MsgQueue(MsgQueue *this)
{
  this->Code = 0;
  this->ExecTurn = 0;
  this->SeqNo = 0;
  this->From = 0;
  this->Size = 0;
  this->ControlCommand = 0;
  this->msgptr = 0;
}

//----- (00431F80) --------------------------------------------------------
void __thiscall MsgQueue::~MsgQueue(MsgQueue *this)
{
  MsgQueue *v1; // esi@1
  char *v2; // eax@1

  v1 = this;
  v2 = this->msgptr;
  this->Code = 0;
  this->ExecTurn = 0;
  this->SeqNo = 0;
  this->From = 0;
  this->Size = 0;
  this->ControlCommand = 0;
  if( v2 )
    operator delete(v2);
  v1->msgptr = 0;
}
