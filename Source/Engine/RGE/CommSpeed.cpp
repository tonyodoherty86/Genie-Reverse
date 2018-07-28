
//----- (00432620) --------------------------------------------------------
void __thiscall RGE_Communications_Speed::RGE_Communications_Speed(RGE_Communications_Speed *this, TCommunications_Handler *c)
{
  RGE_Communications_Speed *v2; // esi@1
  signed int v3; // edx@1
  char *v4; // ecx@1
  int v5; // eax@1
  RGE_TimeSinceLastCall *v6; // eax@3
  RGE_TimeSinceLastCall *v7; // eax@4
  RGE_TimeSinceLastCall *v8; // eax@6
  RGE_TimeSinceLastCall *v9; // eax@7

  v2 = this;
  v3 = 10;
  this->Comm = c;
  this->CurrentBufferGranularity = 90;
  this->OptimalBufferGranularity = 90;
  this->CurrentBufferFrames = 10;
  this->OptimalBufferFrames = 10;
  this->SpeedControlEnabled = 1;
  this->OverheadFactor = 0;
  this->LastAdjusted = 0;
  this->AdjustmentCount = 0;
  this->LastFrameHadTime = 0;
  this->TotalBufferFramesRemaining = 0;
  this->TimeSinceLastBuffer = 0;
  this->TargetTurnLengthMsec = 500;
  this->RealTimePassed = 0;
  this->BufferTimePassed = 0;
  this->DroppedFrames = 0;
  this->DroppedFramesTurn = 0;
  this->NextLatencyChangeTurn = 0;
  this->FutureBufferFrames = 0;
  this->FutureBufferGranularity = 0;
  v4 = (char *)this->RequestFasterOrSlower;
  v5 = (int)v2->AverageTSLC;
  do
  {
    *(_DWORD *)(v5 - 40) = 30;
    *(_DWORD *)v5 = 0;
    *(_WORD *)v4 = 0;
    *(_DWORD *)(v5 + 80) = 0;
    *(_DWORD *)(v5 + 120) = 0;
    v4 += 2;
    v5 += 4;
    --v3;
  }
  while ( v3 );
  v2->HighestLatencyMsec = 500;
  v6 = (RGE_TimeSinceLastCall *)operator new(0x2B4u);
  if ( v6 )
    RGE_TimeSinceLastCall::RGE_TimeSinceLastCall(v6);
  else
    v7 = 0;
  v2->FrameTSLC = v7;
  v8 = (RGE_TimeSinceLastCall *)operator new(0x2B4u);
  if ( v8 )
    RGE_TimeSinceLastCall::RGE_TimeSinceLastCall(v8);
  else
    v9 = 0;
  v2->TurnTSLC = v9;
}

//----- (00432780) --------------------------------------------------------
void __thiscall RGE_Communications_Speed::~RGE_Communications_Speed(RGE_Communications_Speed *this)
{
  RGE_Communications_Speed *v1; // esi@1
  RGE_TimeSinceLastCall *v2; // edi@1
  RGE_TimeSinceLastCall *v3; // esi@3

  v1 = this;
  v2 = this->FrameTSLC;
  if ( v2 )
  {
    RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall(this->FrameTSLC);
    operator delete(v2);
  }
  v3 = v1->TurnTSLC;
  if ( v3 )
  {
    RGE_TimeSinceLastCall::~RGE_TimeSinceLastCall(v3);
    operator delete(v3);
  }
}

//----- (004327C0) --------------------------------------------------------
void __thiscall RGE_Communications_Speed::SetPlayerTurnSpeed(RGE_Communications_Speed *this, unsigned int PlayerNo, char AvgFramesMsec, char HiLatencyCenti)
{
  if ( PlayerNo >= 1 && PlayerNo <= 9 )
  {
    this->PlayerAvgFramesMsec[PlayerNo] = (unsigned __int8)AvgFramesMsec;
    this->PlayerHighLatencyMsec[PlayerNo] = 10 * (unsigned __int8)HiLatencyCenti;
  }
}

//----- (00432800) --------------------------------------------------------
void __thiscall RGE_Communications_Speed::SetActualLatency(RGE_Communications_Speed *this, unsigned int PlayerNo, unsigned int Msec)
{
  unsigned int v3; // eax@3

  if ( PlayerNo >= 1 && PlayerNo <= 9 )
  {
    v3 = Msec;
    if ( Msec < 0x1E )
      v3 = 30;
    if ( v3 > 0x1770 )
      v3 = 6000;
    this->ActualLatency[PlayerNo] = v3;
  }
}

//----- (00432840) --------------------------------------------------------
void __thiscall RGE_Communications_Speed::SetFutureSpeedChange(RGE_Communications_Speed *this, unsigned int BuffCount, unsigned int BuffGran, unsigned int ExecTurn)
{
  if ( !this->NextLatencyChangeTurn )
  {
    this->FutureBufferFrames = BuffCount;
    this->FutureBufferGranularity = BuffGran;
    this->NextLatencyChangeTurn = ExecTurn;
  }
}

//----- (00432870) --------------------------------------------------------
void __thiscall RGE_Communications_Speed::EnableSpeedControl(RGE_Communications_Speed *this, int TorF)
{
  this->SpeedControlEnabled = TorF;
}

//----- (00432880) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Speed::GetBufferGranularity(RGE_Communications_Speed *this)
{
  return this->CurrentBufferGranularity;
}

//----- (00432890) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Speed::GetAdjustmentCount(RGE_Communications_Speed *this)
{
  return this->AdjustmentCount;
}

//----- (004328A0) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Speed::GetBufferGranularityAdjusted(RGE_Communications_Speed *this)
{
  unsigned int result; // eax@1

  result = this->CurrentBufferGranularity;
  this->LastFrameHadTime = 1;
  return result;
}

//----- (004328C0) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Speed::BufferFramesRemaining(RGE_Communications_Speed *this)
{
  return this->TotalBufferFramesRemaining;
}

//----- (004328D0) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Speed::WaitingOnAcknowledgement(RGE_Communications_Speed *this)
{
  unsigned int result; // eax@1

  result = this->SkipFrames + 1;
  this->SkipFrames = result;
  return result;
}

//----- (004328E0) --------------------------------------------------------
void __thiscall RGE_Communications_Speed::AdjustLocalSpeed(RGE_Communications_Speed *this)
{
  unsigned int v1; // eax@1
  TCommunications_Handler *v2; // esi@2
  unsigned int v3; // eax@3

  v1 = this->NextLatencyChangeTurn;
  if ( v1 )
  {
    v2 = this->Comm;
    this->LastAdjusted = 0;
    if ( v2->current_turn >= v1 )
    {
      v3 = this->AdjustmentCount;
      this->NextLatencyChangeTurn = 0;
      this->AdjustmentCount = v3 + 1;
      this->CurrentBufferFrames = this->FutureBufferFrames;
      this->CurrentBufferGranularity = this->FutureBufferGranularity;
      this->FutureBufferFrames = 0;
      this->FutureBufferGranularity = 0;
    }
  }
}

//----- (00432940) --------------------------------------------------------
void __thiscall RGE_Communications_Speed::ReloadBufferFrames(RGE_Communications_Speed *this)
{
  RGE_Communications_Speed *v1; // esi@1

  v1 = this;
  RGE_TimeSinceLastCall::Set(this->TurnTSLC);
  v1->DroppedFramesTurn = 0;
  RGE_Communications_Speed::AdjustLocalSpeed(v1);
  v1->TotalBufferFramesRemaining = v1->CurrentBufferFrames;
}

//----- (00432970) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Speed::BufferTimeToUse(RGE_Communications_Speed *this, unsigned int current_turn)
{
  RGE_Communications_Speed *v2; // esi@1
  int v3; // eax@1
  RGE_TimeSinceLastCall *v4; // ecx@1
  unsigned int v5; // eax@4
  unsigned int result; // eax@5
  unsigned int v7; // eax@6
  TCommunications_Handler *v8; // ecx@6
  unsigned int v9; // edx@8
  unsigned int v10; // ecx@8
  unsigned int v11; // ebx@8
  int v12; // eax@10

  v2 = this;
  v3 = this->LastFrameHadTime;
  v4 = this->FrameTSLC;
  if ( v3 )
    RGE_TimeSinceLastCall::Set(v4);
  else
    RGE_TimeSinceLastCall::Skip(v4);
  v5 = v2->TotalBufferFramesRemaining;
  v2->LastFrameHadTime = 0;
  if ( v5 )
  {
    v7 = RGE_TimeSinceLastCall::Get(v2->TurnTSLC);
    v8 = v2->Comm;
    v2->RealTimePassed = v7;
    if ( TCommunications_Handler::AllPlayersAcknowledged(v8) )
      v2->AllAcknowledgedBuffersRemaining += v2->TotalBufferFramesRemaining;
    v9 = v2->TotalBufferFramesRemaining;
    result = v2->CurrentBufferGranularity;
    v10 = result * (v2->CurrentBufferFrames - v9);
    v11 = v2->RealTimePassed + v2->OverheadFactor;
    v2->BufferTimePassed = v10;
    if ( v11 >= v10 )
    {
      v2->LastFrameHadTime = 1;
      v2->TotalBufferFramesRemaining = v9 - 1;
    }
    else
    {
      if ( current_turn > 6 )
      {
        v12 = v2->DroppedFramesTurn + 1;
        ++v2->DroppedFrames;
        v2->DroppedFramesTurn = v12;
      }
      v2->LastFrameHadTime = 0;
      result = 0;
    }
  }
  else
  {
    v2->LastFrameHadTime = 0;
    result = 0;
  }
  return result;
}

//----- (00432A70) --------------------------------------------------------
void __thiscall RGE_Communications_Speed::Skip(RGE_Communications_Speed *this)
{
  RGE_Communications_Speed *v1; // esi@1

  v1 = this;
  RGE_TimeSinceLastCall::Skip(this->FrameTSLC);
  v1->LastFrameHadTime = 0;
}

//----- (00432A90) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Speed::GetHighLatencyCenti(RGE_Communications_Speed *this)
{
  RGE_Communications_Speed *v1; // ebp@1
  unsigned int v2; // ebx@1
  unsigned int v3; // esi@1
  char *v4; // edi@1
  unsigned int result; // eax@6

  v1 = this;
  v2 = 0;
  v3 = 1;
  v4 = (char *)&this->ActualLatency[1];
  do
  {
    if ( TCommunications_Handler::IsPlayerHuman(v1->Comm, v3) && v2 <= *(_DWORD *)v4 )
      v2 = *(_DWORD *)v4;
    ++v3;
    v4 += 4;
  }
  while ( v3 <= 9 );
  v1->HighestLatencyMsec = v2;
  result = (v2 + 5) / 0xA;
  if ( result <= 1 )
    result = 1;
  if ( result >= 0xFF )
    result = 255;
  return result;
}

//----- (00432B00) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Speed::GetPlayerLatency(RGE_Communications_Speed *this, unsigned int PlayerNo)
{
  unsigned int result; // eax@3

  if ( PlayerNo < 1 || PlayerNo > 9 )
    result = 0;
  else
    result = this->ActualLatency[PlayerNo];
  return result;
}

//----- (00432B20) --------------------------------------------------------
RGE_Communications_Speed *__thiscall RGE_Communications_Speed::GetLatencyInfo(RGE_Communications_Speed *this)
{
  RGE_Communications_Speed *v1; // edx@1
  unsigned int v2; // ebx@1
  char *v3; // ebp@1
  RGE_Communications_Speed *v5; // [sp+10h] [bp-1Ch]@1
  char buf[24]; // [sp+14h] [bp-18h]@4

  v1 = this;
  v5 = this;
  v2 = 1;
  strcpy(this->TBuff, aLatency);
  v3 = (char *)&this->ActualLatency[1];
  while ( 1 )
  {
    if ( TCommunications_Handler::IsPlayerHuman(v1->Comm, v2) )
    {
      sprintf(buf, aPDD, v2, *(_DWORD *)v3);
      strcat(v5->TBuff, buf);
    }
    ++v2;
    v3 += 4;
    if ( v2 > 9 )
      break;
    v1 = v5;
  }
  return v5;
}

//----- (00432BD0) --------------------------------------------------------
char *__thiscall RGE_Communications_Speed::GetSelfPlayerOptimalSpeedStr(RGE_Communications_Speed *this)
{
  RGE_Communications_Speed *v1; // esi@1
  int v2; // edi@1
  signed int v3; // eax@1

  v1 = this;
  v2 = RGE_Communications_Speed::GetRecommendedBufferFrames(this);
  v3 = RGE_Communications_Speed::GetRecommendedBufferGranularity(v1);
  sprintf(buf, aMeoptimalBuf3d, v2, v3, 1000 / v3, v2 * v3);
  return buf;
}

//----- (00432C10) --------------------------------------------------------
char *__thiscall RGE_Communications_Speed::GetPlayerSpeedStatusStr(RGE_Communications_Speed *this, int PlayerNo)
{
  RGE_Communications_Speed *v2; // esi@1
  unsigned int v3; // edi@3
  unsigned int v4; // ebx@3
  RGE_TimeSinceLastCall *v5; // eax@3
  char *result; // eax@3

  v2 = this;
  if ( PlayerNo < 0 || PlayerNo > 9 )
  {
    result = 0;
  }
  else
  {
    v3 = this->CurrentBufferGranularity;
    v4 = this->CurrentBufferFrames;
    v5 = RGE_TimeSinceLastCall::GetHiLoInfo(this->FrameTSLC, 50);
    sprintf(speedstr, aBuf3d3dGran3dm, v2->TotalBufferFramesRemaining, v4, v3, v3 * v4, v5);
    result = speedstr;
  }
  return result;
}

//----- (00432C70) --------------------------------------------------------
char *__thiscall RGE_Communications_Speed::GetMachineSpeedInfo(RGE_Communications_Speed *this)
{
  RGE_Communications_Speed *v1; // edx@1
  signed int v2; // ebx@1
  char *v3; // ebp@1
  RGE_Communications_Speed *v5; // [sp+10h] [bp-1Ch]@1
  char buf[24]; // [sp+14h] [bp-18h]@4

  v1 = this;
  v5 = this;
  v2 = 1;
  strcpy(Info, aPlrspeed);
  v3 = (char *)&this->PlayerAvgFramesMsec[1];
  while ( 1 )
  {
    if ( TCommunications_Handler::IsPlayerHuman(v1->Comm, v2) )
    {
      sprintf(buf, aP1dFrDLatD, v2, *(_DWORD *)v3, *((_DWORD *)v3 + 10));
      strcat(Info, buf);
    }
    ++v2;
    v3 += 4;
    if ( v2 > 9 )
      break;
    v1 = v5;
  }
  return Info;
}

//----- (00432D20) --------------------------------------------------------
int __thiscall RGE_Communications_Speed::GetRecommendedBufferFrames(RGE_Communications_Speed *this)
{
  RGE_Communications_Speed *v1; // ebp@1
  unsigned int v2; // ebx@1
  signed int v3; // esi@1
  char *v4; // edi@1
  unsigned int v5; // eax@6
  int result; // eax@10

  v1 = this;
  v2 = 0;
  v3 = 1;
  v4 = (char *)&this->ActualLatency[1];
  do
  {
    if ( TCommunications_Handler::IsPlayerHuman(v1->Comm, v3) && v2 <= *(_DWORD *)v4 )
      v2 = *(_DWORD *)v4;
    ++v3;
    v4 += 4;
  }
  while ( v3 <= 9 );
  v5 = v2 / v1->CurrentBufferGranularity;
  v1->OptimalBufferFrames = v5;
  if ( v5 >= 0x14 )
    v5 = 20;
  v1->OptimalBufferFrames = v5;
  if ( v5 <= 4 )
    v5 = 4;
  result = v5 + 1;
  v1->OptimalBufferFrames = result;
  return result;
}

//----- (00432D90) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Speed::GetAvgFrameRate(RGE_Communications_Speed *this)
{
  return RGE_TimeSinceLastCall::GetAvg(this->FrameTSLC, 50);
}

//----- (00432DA0) --------------------------------------------------------
unsigned int __thiscall RGE_Communications_Speed::GetRecommendedBufferGranularity(RGE_Communications_Speed *this)
{
  RGE_Communications_Speed *v1; // esi@1
  unsigned int result; // eax@1

  v1 = this;
  result = RGE_TimeSinceLastCall::GetAvg(this->FrameTSLC, 50);
  v1->OptimalBufferGranularity = result;
  if ( result > 0x96 )
    result = 150;
  v1->OptimalBufferGranularity = result;
  if ( result < 0xA )
    result = 10;
  v1->OptimalBufferGranularity = result;
  return result;
}

//----- (00432DE0) --------------------------------------------------------
int __thiscall RGE_Communications_Speed::AnalyzeGameSpeed(RGE_Communications_Speed *this, unsigned int *NewGranularity, unsigned int *NewBufferFrames, int ChangeAlso)
{
  RGE_Communications_Speed *v4; // esi@1
  int result; // eax@1
  unsigned int v6; // eax@6
  unsigned int v7; // ebx@8
  unsigned int v8; // ebp@8
  signed int v9; // edi@8
  unsigned int *v10; // esi@8
  unsigned int v11; // edi@15
  unsigned int v12; // esi@19
  unsigned int v13; // ebp@25
  unsigned int v14; // ebx@25
  unsigned int v15; // eax@25
  RGE_Communications_Speed *v16; // [sp+10h] [bp-Ch]@1
  unsigned int v17; // [sp+14h] [bp-8h]@17
  unsigned int SyncTurn; // [sp+18h] [bp-4h]@4

  v4 = this;
  v16 = this;
  result = TCommunications_Handler::IsHost(this->Comm);
  if ( result )
  {
    if ( v4->NextLatencyChangeTurn )
    {
      result = 0;
    }
    else
    {
      SyncTurn = v4->Comm->PlayerOptions.CommandTurnIncrement + v4->Comm->current_turn;
      if ( SyncTurn >= 0x14 )
      {
        v6 = v4->LastAdjusted + 1;
        v4->LastAdjusted = v6;
        if ( v6 >= 5 )
        {
          v7 = 10;
          v8 = 30;
          v9 = 1;
          v10 = &v4->PlayerHighLatencyMsec[1];
          do
          {
            if ( TCommunications_Handler::IsPlayerHuman(v16->Comm, v9) )
            {
              if ( v7 <= *(v10 - 10) )
                v7 = *(v10 - 10);
              if ( v8 <= *v10 )
                v8 = *v10;
            }
            ++v9;
            ++v10;
          }
          while ( v9 <= 9 );
          v11 = 10 * ((v7 + 5) / 0xA);
          if ( v11 > 0x96 )
            v11 = 150;
          v17 = v16->CurrentBufferGranularity;
          if ( abs(v11 - v17) < 0xAu )
            v11 = v16->CurrentBufferGranularity;
          v12 = v8 / v11 + 2;
          if ( v12 >= 0x14 )
            v12 = 20;
          if ( v12 <= 4 )
            v12 = 4;
          if ( v12 * v11 < 0xFA )
            v12 = 0xFA / v11 + 1;
          v13 = v16->CurrentBufferFrames;
          v14 = v17 * v16->CurrentBufferFrames;
          v15 = abs(v12 * v11 - v14);
          if ( v15 > 0xA )
          {
            if ( v12 * v11 < v14 && v15 > 0x64 && v13 > 4 )
              v12 = v13 - 1;
            *NewGranularity = v11;
            *NewBufferFrames = v12;
            if ( ChangeAlso )
            {
              if ( v16->SpeedControlEnabled )
              {
                RGE_Communications_Speed::SetFutureSpeedChange(v16, v12, v11, SyncTurn);
                TCommunications_Handler::SendSpeedChange(v16->Comm, v12, v11);
              }
            }
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
      }
      else
      {
        result = 0;
      }
    }
  }
  return result;
}

//----- (00432FB0) --------------------------------------------------------
void __stdcall RGE_Communications_Speed::SetV1(unsigned int v1)
{
  TDebuggingLog::Log(L, aSpeedSetV1D, v1);
}

//----- (00432FD0) --------------------------------------------------------
void __stdcall RGE_Communications_Speed::SetV2(unsigned int v2)
{
  TDebuggingLog::Log(L, aSpeedSetV2D, v2);
}
