
//----- (00425750) --------------------------------------------------------
void __thiscall TCommunications_Handler::GameOver(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  RGE_Communications_Queue *v2; // ecx@1
  RGE_Communications_Queue *v3; // ecx@3

  v1 = this;
  v2 = this->InQ;
  v1->current_turn = 0;
  if ( v2 )
    RGE_Communications_Queue::FlushAll(v2);
  v3 = v1->OutQ;
  if ( v3 )
    RGE_Communications_Queue::FlushAll(v3);
}

//----- (00425780) --------------------------------------------------------
char *__thiscall TCommunications_Handler::WaitingOnNamedInfo(TCommunications_Handler *this, unsigned int PlayerNo)
{
  TCommunications_Handler *v2; // esi@1
  char *v3; // ebx@1
  char *v4; // ST18_4@1
  char *v5; // eax@1
  unsigned int v6; // eax@1
  unsigned int v7; // ST18_4@1
  int v8; // ST14_4@1
  char *v9; // ST10_4@1
  char *v10; // eax@1

  v2 = this;
  v3 = this->TBuff;
  v4 = TCommunications_Handler::WaitingOnInfo(this, PlayerNo);
  v5 = TCommunications_Handler::GetPlayerName(v2, PlayerNo);
  sprintf(v3, aDSS, PlayerNo, v5, v4);
  v6 = debug_timeGetTime();
  v7 = v2->LastTurnAck[PlayerNo];
  v8 = v6 - v2->LastPlayerCommunication[PlayerNo];
  v9 = TCommunications_Handler::WaitingOnInfo(v2, PlayerNo);
  v10 = TCommunications_Handler::GetPlayerName(v2, PlayerNo);
  sprintf(v3, aDSSQuietDMsecT, PlayerNo, v10, v9, v8, v7);
  return v3;
}

//----- (00425800) --------------------------------------------------------
char *__thiscall TCommunications_Handler::WaitingOnInfo(TCommunications_Handler *this, unsigned int PlayerNo)
{
  TCommunications_Handler *v2; // esi@1
  char *result; // eax@2
  unsigned int v4; // eax@5

  v2 = this;
  if ( TCommunications_Handler::IsPlayerComputer(this, PlayerNo) )
  {
    (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(1201, msg_str, 32);
    result = msg_str;
  }
  else if ( TCommunications_Handler::IsPlayerHuman(v2, PlayerNo) )
  {
    v4 = v2->LastTurnAck[PlayerNo];
    if ( v4 >= 4 )
    {
      if ( v4 >= v2->current_turn )
      {
        (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(1200, msg_str, 32);
        result = msg_str;
      }
      else
      {
        (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(1204, msg_str, 32);
        result = msg_str;
      }
    }
    else
    {
      (*(void (__stdcall **)(signed int, _DWORD, _DWORD))&rge_base_game->vfptr->gap8[24])(1203, msg_str, 32);
      result = msg_str;
    }
  }
  else
  {
    (*(void (__stdcall **)(signed int, _DWORD, _DWORD))&rge_base_game->vfptr->gap8[24])(1202, msg_str, 32);
    result = msg_str;
  }
  return result;
}

//----- (004258E0) --------------------------------------------------------
void __thiscall TCommunications_Handler::StopIfSyncFail(TCommunications_Handler *this, int b)
{
  TCommunications_Handler *v2; // esi@1

  v2 = this;
  RGE_Communications_Synchronize::SetDialogOnFail(this->Sync, b);
  RGE_Communications_Synchronize::SetStopOnFail(v2->Sync, b);
}

//----- (00425910) --------------------------------------------------------
void __thiscall TCommunications_Handler::ShowSyncChatMsgs(TCommunications_Handler *this, int b)
{
  RGE_Communications_Synchronize::SendChatMsgsAtChecksum(this->Sync, b);
}

//----- (00425930) --------------------------------------------------------
void __thiscall TCommunications_Handler::DropPacketsIntentionally(TCommunications_Handler *this, int b)
{
  this->IntentionallyDropPackets = b;
  if ( b )
    TDebuggingLog::Log(L, aDroppingPacket);
}

//----- (00425960) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetStepMode(TCommunications_Handler *this, int b)
{
  this->StepMode = b;
}

//----- (00425970) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetSpeedControl(TCommunications_Handler *this, int b)
{
  RGE_Communications_Speed::EnableSpeedControl(this->Speed, b);
}

//----- (00425990) --------------------------------------------------------
int __thiscall TCommunications_Handler::CalculatePlayerRange(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  signed int v2; // edi@1
  unsigned __int16 v3; // ax@1
  unsigned __int16 v4; // ax@4
  unsigned __int16 v5; // ax@6

  v1 = this;
  v2 = 1;
  v3 = this->MaxGamePlayers;
  this->PlayerOptions.HighPlayerNumber = 0;
  this->PlayerOptions.LowPlayerNumber = v3 + 1;
  if ( v3 >= 1u )
  {
    do
    {
      if ( TCommunications_Handler::IsPlayerHuman(v1, v2) || TCommunications_Handler::IsPlayerComputer(v1, v2) )
      {
        v4 = v1->PlayerOptions.HighPlayerNumber;
        if ( v4 <= v2 )
          v4 = v2;
        v1->PlayerOptions.HighPlayerNumber = v4;
        v5 = v1->PlayerOptions.LowPlayerNumber;
        if ( v5 >= v2 )
          v5 = v2;
        v1->PlayerOptions.LowPlayerNumber = v5;
      }
      ++v2;
    }
    while ( v2 <= v1->MaxGamePlayers );
  }
  return 1;
}

//----- (00425A20) --------------------------------------------------------
void __thiscall TCommunications_Handler::Step(TCommunications_Handler *this, int Numsteps)
{
  TCommunications_Handler *v2; // esi@1

  v2 = this;
  TCommunications_Handler::TEST();
  v2->Steps += Numsteps;
}

//----- (00425A40) --------------------------------------------------------
void __thiscall TCommunications_Handler::TCommunications_Handler(TCommunications_Handler *this, void *WinHandle, char MaxPlayers, TChat *ChatHandle, _GUID AppGuid)
{
  TCommunications_Handler *v5; // ebp@1
  unsigned int v6; // eax@1
  unsigned int v7; // eax@3
  int v8; // ecx@5
  int v9; // edx@5
  int v10; // edx@5
  char *v11; // eax@6
  char v12; // cl@9
  int v13; // esi@10
  NAME *v14; // eax@10
  char *v15; // edx@11
  char *v16; // edi@12
  NAME *v17; // eax@15
  char *v18; // edx@16
  char *v19; // edi@18
  RGE_Communications_Queue *v20; // eax@21
  RGE_Communications_Queue *v21; // eax@22
  void *v22; // eax@24
  int v23; // edi@25
  RESENDER *v24; // eax@25
  void *v25; // eax@27
  int v26; // edi@28
  HOLDER *v27; // eax@28
  RGE_Comm_Error *v28; // eax@30
  RGE_Comm_Error *v29; // eax@31
  RGE_Lobby *v30; // eax@33
  RGE_Lobby *v31; // eax@34
  RGE_Communications_Speed *v32; // eax@36
  RGE_Communications_Speed *v33; // eax@37
  RGE_Communications_Synchronize *v34; // eax@39
  RGE_Communications_Synchronize *v35; // eax@40
  unsigned int v36; // eax@42
  unsigned int v37; // edi@42
  unsigned __int16 v38; // cx@42
  signed int v39; // edi@42
  RGE_Communications_Queue *v40; // ecx@44
  RGE_Communications_Queue *v41; // ecx@46
  int v42; // eax@48
  signed int v43; // ecx@48
  char Codestr[32]; // [sp+10h] [bp-2Ch]@5
  int v45; // [sp+38h] [bp-4h]@21
  int MaxPlayersa; // [sp+44h] [bp+8h]@11
  int MaxPlayersb; // [sp+44h] [bp+8h]@17
  TChat *ChatHandlea; // [sp+48h] [bp+Ch]@10

  v5 = this;
  TDebuggingLog::FlushToDisk(L, 1);
  v5->ReturnRXPacketSize = v5->RXPacketLength;
  v6 = v5->RXPacketLength;
  if ( v6 <= v5->RXPacketLengthHigh )
    v6 = v5->RXPacketLengthHigh;
  v5->RXPacketLengthHigh = v6;
  v5->RXPacketLength = 0;
  v5->ReturnTXPacketSize = v5->TXPacketLength;
  v7 = v5->TXPacketLength;
  if ( v7 <= v5->TXPacketLengthHigh )
    v7 = v5->TXPacketLengthHigh;
  v5->TXPacketLengthHigh = v7;
  v5->TXPacketLength = 0;
  v5->OutQ = 0;
  v8 = (int)&v5->NullGUID;
  v5->InQ = 0;
  v5->GTDSerialNo = 0;
  *(_DWORD *)v8 = 0;
  *(_DWORD *)(v8 + 4) = 0;
  *(_DWORD *)(v8 + 8) = 0;
  *(_DWORD *)(v8 + 12) = 0;
  v5->CommunicationsStatus = 1;
  v5->ApplicationGUID = AppGuid;
  v9 = (int)&v5->SessionGUID;
  *(_DWORD *)v9 = v5->NullGUID.x;
  *(_DWORD *)(v9 + 4) = *(_DWORD *)&v5->NullGUID.s1;
  *(_DWORD *)(v9 + 8) = *(_DWORD *)&v5->NullGUID.c[0];
  *(_DWORD *)(v9 + 12) = *(_DWORD *)&v5->NullGUID.c[4];
  v10 = (int)&v5->ServiceGUID;
  v5->ServiceGUID.x = v5->NullGUID.x;
  *(_DWORD *)(v10 + 4) = *(_DWORD *)&v5->NullGUID.s1;
  *(_DWORD *)(v10 + 8) = *(_DWORD *)&v5->NullGUID.c[0];
  *(_DWORD *)(v10 + 12) = *(_DWORD *)&v5->NullGUID.c[4];
  v5->HostHWND = WinHandle;
  v5->Chat = ChatHandle;
  v5->MaxGamePlayers = (unsigned __int8)MaxPlayers;
  TDebuggingLog::Log(L, aCommRgeCommuni, aCMsdevWorkA_39);
  TDebuggingLog::Log(L, aCommSVersion__, aCMsdevWorkA_39, aFriJul17093938);
  strcpy(Codestr, a131708);
  if ( Codestr[0] )
  {
    v11 = Codestr;
    do
    {
      if ( *v11 == 58 )
        *v11 = 48;
      v12 = (v11++)[1];
    }
    while ( v12 );
  }
  v5->CommunicationsVersionCode = 3025031;
  v13 = (unsigned __int8)MaxPlayers + 1;
  ChatHandlea = (TChat *)((unsigned __int8)MaxPlayers + 1);
  v14 = (NAME *)operator new(v13 << 7);
  if ( v14 )
  {
    v15 = (char *)v14;
    MaxPlayersa = (unsigned __int8)MaxPlayers + 1;
    do
    {
      v16 = v15;
      v15 += 128;
      strcpy(v16, text_in);
      --MaxPlayersa;
    }
    while ( MaxPlayersa );
    v13 = (int)ChatHandlea;
  }
  else
  {
    v14 = 0;
  }
  v5->FriendlyName = v14;
  v17 = (NAME *)operator new(v13 << 7);
  if ( v17 )
  {
    v18 = (char *)v17;
    if ( v13 - 1 >= 0 )
    {
      MaxPlayersb = v13;
      do
      {
        v19 = v18;
        v18 += 128;
        strcpy(v19, text_in);
        --MaxPlayersb;
      }
      while ( MaxPlayersb );
    }
  }
  else
  {
    v17 = 0;
  }
  v5->FormalName = v17;
  v20 = (RGE_Communications_Queue *)operator new(0x118u);
  v45 = 0;
  if ( v20 )
    RGE_Communications_Queue::RGE_Communications_Queue(v20, 501);
  else
    v21 = 0;
  v45 = -1;
  v5->InQ = v21;
  v22 = operator new(0x6DD4u);
  v45 = 1;
  if ( v22 )
  {
    v23 = (int)v22 + 4;
    *(_DWORD *)v22 = 502;
    `eh vector constructor iterator'(
      (char *)v22 + 4,
      0x38u,
      502,
      (int)RESENDER::RESENDER,
      (void (__thiscall *)(void *))RESENDER::~RESENDER);
    v24 = (RESENDER *)v23;
  }
  else
  {
    v24 = 0;
  }
  v45 = -1;
  v5->Resend = v24;
  v25 = operator new(0x2F14u);
  v45 = 2;
  if ( v25 )
  {
    v26 = (int)v25 + 4;
    *(_DWORD *)v25 = 502;
    `eh vector constructor iterator'(
      (char *)v25 + 4,
      0x18u,
      502,
      (int)HOLDER::HOLDER,
      (void (__thiscall *)(void *))HOLDER::~HOLDER);
    v27 = (HOLDER *)v26;
  }
  else
  {
    v27 = 0;
  }
  v45 = -1;
  v5->OnHold = v27;
  v28 = (RGE_Comm_Error *)operator new(8u);
  v45 = 3;
  if ( v28 )
    RGE_Comm_Error::RGE_Comm_Error(v28, WinHandle);
  else
    v29 = 0;
  v45 = -1;
  v5->Err = v29;
  v30 = (RGE_Lobby *)operator new(0x1Cu);
  v45 = 4;
  if ( v30 )
    RGE_Lobby::RGE_Lobby(v30, WinHandle);
  else
    v31 = 0;
  v45 = -1;
  v5->Lobby = v31;
  v32 = (RGE_Communications_Speed *)operator new(0x240u);
  v45 = 5;
  if ( v32 )
    RGE_Communications_Speed::RGE_Communications_Speed(v32, v5);
  else
    v33 = 0;
  v45 = -1;
  v5->Speed = v33;
  v34 = (RGE_Communications_Synchronize *)operator new(0x7ECu);
  v45 = 6;
  if ( v34 )
    RGE_Communications_Synchronize::RGE_Communications_Synchronize(v34, v5);
  else
    v35 = 0;
  v45 = -1;
  v5->Sync = v35;
  v36 = debug_timeGetTime();
  v5->RXPacketLength = 0;
  v5->RXPacketLengthHigh = 0;
  v5->TXPacketLength = 0;
  v5->TXPacketLengthHigh = 0;
  LODWORD(v5->lastRXDataRate) = 0;
  LODWORD(v5->lastTXDataRate) = 0;
  v5->HoldCount = 0;
  v5->ServiceTimeout = 0;
  v5->TXPackets = 0;
  v5->RXPackets = 0;
  v5->RGE_Guaranteed_Delivery = 0;
  v5->ResendAcknowledgements = 0;
  v5->ResentToOther = 0;
  v5->DroppedPacketCount = 0;
  v5->LobbyLaunched = 0;
  v5->GTDSerialNo = 0;
  v5->dwStopTime = 0;
  v5->OutOfSyncFlag = 0;
  v37 = v36;
  TDebuggingLog::Time(L);
  v5->PlayerOptions.LastSentTime = v37;
  v5->AvgTurnTime = 0;
  v5->PauseChangePending = 0;
  v5->StepMode = 0;
  v5->IntentionallyDropPackets = 0;
  strcpy(v5->MyGameTitle, text_in);
  strcpy(v5->MyFriendlyName, text_in);
  strcpy(v5->MyFormalName, text_in);
  v5->TickStart = 0;
  v5->TickCount = 0;
  v5->LastTimeoutMessageTime = 0;
  v38 = v5->MaxGamePlayers;
  v5->PlayerOptions.LowPlayerNumber = 1;
  v5->PlayerOptions.HighPlayerNumber = v38;
  v5->PlayerOptions.GameHasStarted = 0;
  v5->PlayerOptions.ProgramState = 3;
  v5->MeHost = 0;
  v5->HaveHostInit = 0;
  v5->PlayerOptions.CommandTurnIncrement = 2;
  v5->current_turn = 4;
  v5->PlayerOptions.CurrentTurn = 4;
  v5->PlayerOptions.NeedsToBeSent = 0;
  v5->AcknowledgeAfterMsec = 50;
  v5->Me = 0;
  v5->Multiplayer = 0;
  v5->turnstart = 0;
  v5->mselapsed = 0;
  TDebuggingLog::Log(L, aInitializePlay);
  v39 = 1;
  if ( v5->MaxGamePlayers >= 1u )
  {
    do
      TCommunications_Handler::InitPlayerInformation(v5, v39++, 0, text_in, text_in);
    while ( v39 <= v5->MaxGamePlayers );
  }
  v5->PlayerOptions.NeedsToBeSent = 0;
  v5->PlayerOptions.LastSentTime = 0;
  TCommunications_Handler::ClearAllSerialNumbers(v5);
  TCommunications_Handler::ClearRXandTX(v5);
  memset(&v5->PlayerStopTurn[1], 0, 0x24u);
  v5->Steps = 1;
  TCommunications_Handler::ResetLastCommunicationTimes(v5);
  v40 = v5->InQ;
  v5->WaitingForAck = 0;
  if ( v40 )
    RGE_Communications_Queue::FlushAll(v40);
  v41 = v5->OutQ;
  if ( v41 )
    RGE_Communications_Queue::FlushAll(v41);
  v5->ShuttingDown = 0;
  v42 = (int)v5->Kicked;
  v43 = 10;
  do
  {
    *(_DWORD *)(v42 - 304) = 0;
    *(_DWORD *)v42 = 0;
    *(_DWORD *)(v42 + 688) = 0;
    v42 += 4;
    --v43;
  }
  while ( v43 );
  v5->PlayerOptions.DataSizeToFollow = 0;
  v5->OptionsData = 0;
}

//----- (004260F0) --------------------------------------------------------
RESENDER *__thiscall RESENDER::`vector deleting destructor'(RESENDER *this, unsigned int __flags)
{
  RESENDER *v2; // esi@1
  RESENDER *result; // eax@2
  char *v4; // eax@3

  v2 = this;
  if ( __flags & 2 )
  {
    `eh vector destructor iterator'(
      (int)this,
      0x38u,
      this[-1].DestMap[9],
      (void (__thiscall *)(void *))RESENDER::~RESENDER);
    operator delete(&v2[-1].DestMap[9]);
    result = v2;
  }
  else
  {
    v4 = this->ResendMsg;
    this->TimeSent = 0;
    if ( v4 )
      operator delete(v4);
    v2->ResendMsg = 0;
    v2->Serial = 0;
    v2->Length = 0;
    memset(v2->DestMap, 0, sizeof(v2->DestMap));
    if ( __flags & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (00426170) --------------------------------------------------------
HOLDER *__thiscall HOLDER::`vector deleting destructor'(HOLDER *this, unsigned int __flags)
{
  HOLDER *v2; // esi@1
  HOLDER *result; // eax@2

  v2 = this;
  if ( __flags & 2 )
  {
    `eh vector destructor iterator'((int)this, 0x18u, this[-1].fromPlayer, (void (__thiscall *)(void *))HOLDER::~HOLDER);
    operator delete(&v2[-1].fromPlayer);
    result = v2;
  }
  else
  {
    if ( this->HoldMsg )
      operator delete(this->HoldMsg);
    v2->HoldMsg = 0;
    v2->Serial = 0;
    v2->Length = 0;
    v2->dcoFromID = 0;
    v2->dcoReceiveID = 0;
    if ( __flags & 1 )
      operator delete(v2);
    result = v2;
  }
  return result;
}

//----- (004261E0) --------------------------------------------------------
void __thiscall TCommunications_Handler::~TCommunications_Handler(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // edi@1
  int v2; // ebx@1
  unsigned int v3; // esi@1
  RESENDER *v4; // edx@2
  unsigned int v5; // ecx@2
  int v6; // eax@3
  int v7; // eax@5
  void *v8; // esi@6
  int v9; // eax@7
  void *v10; // esi@8
  RGE_Communications_Queue *v11; // esi@9
  RGE_Lobby *v12; // esi@11
  RGE_Communications_Speed *v13; // esi@13
  RGE_Communications_Synchronize *v14; // esi@15
  RGE_Comm_Error *v15; // edi@17

  v1 = this;
  TCommunications_Handler::DestroyMultiplayerGame(this);
  TCommunications_Handler::CloseSession(v1);
  TCommunications_Handler::ReleaseComm(v1);
  TCommunications_Handler::FreeOptions(v1);
  operator delete(v1->FriendlyName);
  operator delete(v1->FormalName);
  v2 = 0;
  v3 = 0;
  do
  {
    v4 = v1->Resend;
    v5 = v4[v3].Serial;
    if ( v5 )
    {
      v6 = (int)&v4[v3];
      TDebuggingLog::Log(
        L,
        aNoMsgSlotDSerD,
        v2,
        v5,
        *(_DWORD *)(v6 + 12),
        *(_DWORD *)(v6 + 20),
        *(_DWORD *)(v6 + 24),
        *(_DWORD *)(v6 + 28),
        *(_DWORD *)(v6 + 32),
        *(_DWORD *)(v6 + 36),
        *(_DWORD *)(v6 + 40),
        *(_DWORD *)(v6 + 44),
        *(_DWORD *)(v6 + 48));
    }
    ++v3;
    ++v2;
  }
  while ( v3 <= 501 );
  v7 = (int)v1->Resend;
  if ( v7 )
  {
    v8 = (void *)(v7 - 4);
    `eh vector destructor iterator'(v7, 0x38u, *(_DWORD *)(v7 - 4), (void (__thiscall *)(void *))RESENDER::~RESENDER);
    operator delete(v8);
  }
  v9 = (int)v1->OnHold;
  if ( v9 )
  {
    v10 = (void *)(v9 - 4);
    `eh vector destructor iterator'(v9, 0x18u, *(_DWORD *)(v9 - 4), (void (__thiscall *)(void *))HOLDER::~HOLDER);
    operator delete(v10);
  }
  v11 = v1->InQ;
  if ( v11 )
  {
    RGE_Communications_Queue::~RGE_Communications_Queue(v1->InQ);
    operator delete(v11);
  }
  v12 = v1->Lobby;
  if ( v12 )
  {
    RGE_Lobby::~RGE_Lobby(v1->Lobby);
    operator delete(v12);
  }
  v13 = v1->Speed;
  if ( v13 )
  {
    RGE_Communications_Speed::~RGE_Communications_Speed(v1->Speed);
    operator delete(v13);
  }
  v14 = v1->Sync;
  if ( v14 )
  {
    RGE_Communications_Synchronize::~RGE_Communications_Synchronize(v1->Sync);
    operator delete(v14);
  }
  v15 = v1->Err;
  if ( v15 )
  {
    RGE_Comm_Error::~RGE_Comm_Error(v15);
    operator delete(v15);
  }
}

//----- (00426350) --------------------------------------------------------
void __thiscall TCommunications_Handler::KillAnyMissingPlayers(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // ebx@1
  unsigned int v2; // edi@1
  unsigned int *v3; // esi@2
  IUnknownVtbl *v4; // ecx@4
  unsigned int v5; // ST08_4@4
  void *v6; // ebp@4
  unsigned int v7; // eax@5
  unsigned int v8; // ecx@5
  unsigned int dwSize; // [sp+1Ch] [bp-14h]@4
  int hr; // [sp+20h] [bp-10h]@4
  MSGFORMAT_KILL_PLAYER kp; // [sp+24h] [bp-Ch]@5

  v1 = this;
  v2 = 1;
  if ( this->MaxGamePlayers >= 1u )
  {
    v3 = &this->PlayerOptions.dcoID[1];
    do
    {
      if ( TCommunications_Handler::IsPlayerHuman(v1, v2) )
      {
        v4 = glpIDC->vfptr;
        v5 = *v3;
        dwSize = 0;
        ((void (__stdcall *)(IDirectPlay3 *, unsigned int, _DWORD, unsigned int *))v4[7].QueryInterface)(
          glpIDC,
          v5,
          0,
          &dwSize);
        v6 = operator new(dwSize);
        hr = ((int (__stdcall *)(IDirectPlay3 *, unsigned int, void *, unsigned int *))glpIDC->vfptr[7].QueryInterface)(
               glpIDC,
               *v3,
               v6,
               &dwSize);
        operator delete(v6);
        if ( hr )
        {
          v7 = *v3;
          v8 = v1->current_turn;
          kp.PlayerNo = v2;
          kp.dcoID = v7;
          kp.CurrentTurn = v8;
          TDebuggingLog::Log(L, aTxKpDD, v2, 12);
          TCommunications_Handler::CommOut(v1, 0, 75, &kp, 12, 0);
          if ( !*(v3 - 106) )
            TCommunications_Handler::DropDeadPlayer(v1, v2, *v3);
        }
      }
      ++v2;
      ++v3;
    }
    while ( v2 <= v1->MaxGamePlayers );
  }
}

//----- (00426450) --------------------------------------------------------
void __thiscall RESENDER::RESENDER(RESENDER *this)
{
  this->TimeSent = 0;
  this->ResendMsg = 0;
  this->Serial = 0;
  this->Length = 0;
  memset(this->DestMap, 0, sizeof(this->DestMap));
}

//----- (00426470) --------------------------------------------------------
int __thiscall TCommunications_Handler::AddCommand(TCommunications_Handler *this, unsigned int ExecuteOnTurn, void *command, unsigned int nBytes, int PFrom, char Sequence, int ControlCommand)
{
  return RGE_Communications_Queue::AddItem(this->InQ, ExecuteOnTurn, command, nBytes, PFrom, Sequence, ControlCommand);
}

//----- (004264A0) --------------------------------------------------------
void __thiscall RESENDER::~RESENDER(RESENDER *this)
{
  RESENDER *v1; // esi@1
  char *v2; // eax@1

  v1 = this;
  v2 = this->ResendMsg;
  this->TimeSent = 0;
  if ( v2 )
    operator delete(v2);
  v1->ResendMsg = 0;
  v1->Serial = 0;
  v1->Length = 0;
  memset(v1->DestMap, 0, sizeof(v1->DestMap));
}

//----- (004264D0) --------------------------------------------------------
void *__thiscall TCommunications_Handler::get_command(TCommunications_Handler *this)
{
  void *result; // eax@2

  if ( this->Multiplayer )
  {
    if ( this->PlayerOptions.ProgramState == 3 )
      result = RGE_Communications_Queue::GetNextItemSingle(this->InQ);
    else
      result = RGE_Communications_Queue::GetNextItemOrdered(this->InQ, this->current_turn);
  }
  else
  {
    result = RGE_Communications_Queue::GetNextItemSingle(this->InQ);
  }
  return result;
}

//----- (00426510) --------------------------------------------------------
int __thiscall TCommunications_Handler::new_command(TCommunications_Handler *this, void *Command, int Size)
{
  return TCommunications_Handler::NewCommand(this, Command, Size, 0);
}

//----- (00426530) --------------------------------------------------------
int __thiscall TCommunications_Handler::NewCommand(TCommunications_Handler *this, void *Command, int Size, int ControlCommand)
{
  TCommunications_Handler *v4; // esi@1
  int v5; // eax@2
  int result; // eax@2
  unsigned int v7; // eax@3
  unsigned int v8; // edi@3
  char v9; // al@3

  v4 = this;
  if ( this->Multiplayer )
  {
    TDebuggingLog::Log(L, aTxCmdDCmdD, Size, *(_BYTE *)Command);
    v5 = TCommunications_Handler::CommOut(v4, 0, 62, Command, Size, 0);
    RGE_Comm_Error::ShowReturn(v4->Err, v5, Text);
    result = 1;
  }
  else
  {
    v7 = this->current_turn;
    v8 = v7 + this->PlayerOptions.CommandTurnIncrement;
    v9 = RGE_Communications_Queue::GetNextSequence(this->InQ, v7);
    TCommunications_Handler::AddCommand(v4, v8, Command, Size, v4->Me, v9, ControlCommand);
    result = 1;
  }
  return result;
}

//----- (004265E0) --------------------------------------------------------
void __thiscall HOLDER::HOLDER(HOLDER *this)
{
  this->HoldMsg = 0;
  this->Serial = 0;
  this->Length = 0;
  this->dcoFromID = 0;
  this->dcoReceiveID = 0;
}

//----- (00426600) --------------------------------------------------------
void __thiscall HOLDER::~HOLDER(HOLDER *this)
{
  HOLDER *v1; // esi@1

  v1 = this;
  if ( this->HoldMsg )
    operator delete(this->HoldMsg);
  v1->HoldMsg = 0;
  v1->Serial = 0;
  v1->Length = 0;
  v1->dcoFromID = 0;
  v1->dcoReceiveID = 0;
}

//----- (00426630) --------------------------------------------------------
void __thiscall TCommunications_Handler::LastWorldRandom(TCommunications_Handler *this, int lwr)
{
  RGE_Communications_Synchronize::SetLastWorldRandom(this->Sync, lwr);
}

//----- (00426650) --------------------------------------------------------
int __thiscall TCommunications_Handler::DoCycle(TCommunications_Handler *this, unsigned int WorldTime)
{
  TCommunications_Handler *v2; // esi@1
  int result; // eax@2
  unsigned int v4; // edi@5
  char *v5; // eax@6
  char *v6; // eax@6
  char *v7; // eax@6
  char *v8; // eax@6
  char *v9; // eax@6
  char *v10; // eax@6
  unsigned int v11; // eax@7
  int v12; // edi@7
  unsigned int *v13; // ecx@9
  char v14; // al@11
  RGE_Communications_Speed *v15; // ecx@11
  char v16; // al@11
  unsigned int v17; // edx@11
  unsigned int v18; // ebx@22
  bool v19; // zf@22
  signed int v20; // eax@22
  unsigned int v21; // edi@25
  unsigned int v22; // ebp@25
  int v23; // ecx@25
  int v24; // eax@25
  int v25; // ebx@26
  unsigned int v26; // edi@32
  unsigned int v27; // ecx@37
  signed int v28; // eax@37
  unsigned int v29; // ecx@40
  unsigned int v30; // ecx@44
  char *v31; // eax@49
  signed int v32; // eax@55
  signed int v33; // edi@59
  unsigned int v34; // eax@59
  int *v35; // ecx@60
  unsigned int v36; // eax@65
  int v37; // ecx@72
  int v38; // ebp@74
  unsigned int v39; // ST14_4@74
  unsigned int v40; // ST10_4@74
  unsigned int Now; // [sp+10h] [bp-8Ch]@25
  int numPlayers; // [sp+14h] [bp-88h]@25
  int selfTimedOutCount; // [sp+18h] [bp-84h]@25
  unsigned int LastAnyPlayerMessage; // [sp+1Ch] [bp-80h]@22
  unsigned int G; // [sp+20h] [bp-7Ch]@72
  unsigned int F; // [sp+24h] [bp-78h]@72
  char Msg; // [sp+28h] [bp-74h]@12
  int v48; // [sp+2Ch] [bp-70h]@12
  char AvgFramesMsec[4]; // [sp+30h] [bp-6Ch]@11
  char msg_str[100]; // [sp+38h] [bp-64h]@49

  v2 = this;
  if ( !this->Multiplayer )
    return -(this->PlayerOptions.ProgramState != 4);
  if ( this->Me > this->MaxGamePlayers )
    return 0;
  v4 = debug_timeGetTime();
  if ( v4 - LastLoggedInfo >= 0x1388 )
  {
    v5 = TCommunications_Handler::GetCommInfo(v2, 6);
    TDebuggingLog::Log(L, v5);
    v6 = TCommunications_Handler::GetCommInfo(v2, 5);
    TDebuggingLog::Log(L, v6);
    v7 = TCommunications_Handler::GetCommInfo(v2, 4);
    TDebuggingLog::Log(L, v7);
    v8 = TCommunications_Handler::GetCommInfo(v2, 3);
    TDebuggingLog::Log(L, v8);
    v9 = TCommunications_Handler::GetCommInfo(v2, 2);
    TDebuggingLog::Log(L, v9);
    v10 = TCommunications_Handler::GetCommInfo(v2, 1);
    TDebuggingLog::Log(L, v10);
    LastLoggedInfo = v4;
  }
  TCommunications_Handler::ReceiveGameMessages(v2);
  v2->LastPlayerCommunication[v2->Me] = v4;
  v11 = v2->current_turn;
  v12 = v11 + v2->PlayerOptions.CommandTurnIncrement;
  if ( v2->Multiplayer )
  {
    if ( v2->PlayerOptions.ProgramState != 3 )
    {
      v13 = &v2->LastTurnAck[v2->Me];
      if ( *v13 != v11 )
      {
        *v13 = v11;
        if ( v2->current_turn > 6 )
        {
          v14 = RGE_Communications_Speed::GetHighLatencyCenti(v2->Speed);
          v15 = v2->Speed;
          AvgFramesMsec[0] = v14;
          v16 = RGE_Communications_Speed::GetAvgFrameRate(v15);
          v17 = v2->Me;
          AvgFramesMsec[1] = v16;
          RGE_Communications_Speed::SetPlayerTurnSpeed(v2->Speed, v17, v16, AvgFramesMsec[0]);
        }
        `TCommunications_Handler::SendAllDoneMsg'::`4'::LastSentTime = debug_timeGetTime();
        Msg = 68;
        v48 = v12;
        TDebuggingLog::Log(L, aTxDoneD, 12);
        TCommunications_Handler::CommOut(v2, 0, 68, &Msg, 12, 0);
      }
    }
  }
  if ( v2->StepMode )
  {
    result = v2->Steps;
    if ( !result )
      return result;
    v2->Steps = result - 1;
  }
  RGE_Communications_Synchronize::DoChecksum(v2->Sync, v2->current_turn);
  if ( v2->OutOfSyncFlag == 1 && WorldTime >= v2->dwStopTime )
  {
    TCommunications_Handler::NotifyWindowParam(v2, COMM_SYNC_ERROR, v2->dwStopTime);
    return 0;
  }
  if ( RGE_Communications_Speed::BufferFramesRemaining(v2->Speed) && v2->current_turn > 6 )
    return RGE_Communications_Speed::BufferTimeToUse(v2->Speed, v2->current_turn);
  v18 = 0;
  LastAnyPlayerMessage = 0;
  v19 = TCommunications_Handler::AllPlayersAcknowledged(v2) == 0;
  v20 = v2->PlayerOptions.ProgramState;
  if ( v19 )
  {
    if ( v20 < 5 )
      return 0;
    RGE_Communications_Speed::WaitingOnAcknowledgement(v2->Speed);
    v21 = debug_timeGetTime();
    v22 = 1;
    v23 = 0;
    v24 = 0;
    Now = v21;
    selfTimedOutCount = 0;
    numPlayers = 0;
    if ( v2->MaxGamePlayers >= 1u )
    {
      v25 = (int)&v2->LastPlayerCommunication[1];
      while ( 1 )
      {
        if ( TCommunications_Handler::IsPlayerHuman(v2, v22) && v22 != v2->Me )
        {
          ++numPlayers;
          if ( LastAnyPlayerMessage <= *(_DWORD *)v25 )
            LastAnyPlayerMessage = *(_DWORD *)v25;
          v26 = v21 - *(_DWORD *)v25;
          if ( v26 > 0xEA60 )
            ++selfTimedOutCount;
          if ( v26 > 0x61A8 && Now - *(_DWORD *)(v25 + 40) > 0x61A8 )
          {
            *(_DWORD *)(v25 + 40) = Now;
            TCommunications_Handler::NotifyWindowParam(v2, COMM_PLAYER_NOT_RESPONDING, v22);
          }
          v27 = v2->current_turn;
          v28 = 0;
          if ( v27 <= 7 && v26 > 0x17ED0 )
          {
            TDebuggingLog::Log(L, aTimeoutPregram, v27, v26);
            v28 = 1;
          }
          v29 = v2->current_turn;
          if ( v29 > 7 && v26 > 0x1DA9C && v2->MeHost )
          {
            TDebuggingLog::Log(L, aTimeoutHostTur, v29, v26);
            v28 = 1;
          }
          v30 = v2->current_turn;
          if ( v30 > 7 && v26 > 0x1D6B4 )
          {
            TDebuggingLog::Log(L, aTimeoutPlayerT, v30, v26);
            v28 = 1;
          }
          if ( v28 )
          {
            TDebuggingLog::Log(L, aPlayerTimedOut, v26);
            TDebuggingLog::Log(L, aRecommendPlaye, v22);
            if ( v2->MeHost )
            {
              TDebuggingLog::Log(L, aPlayerDTurnDTi, v22, v2->current_turn, v26);
              (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(
                1210,
                msg_str,
                100);
              v31 = TCommunications_Handler::GetPlayerName(v2, v22);
              sprintf(v2->TBuff, msg_str, v31, v22);
              if ( v2->current_turn > 6 )
                TCommunications_Handler::SendChatMsgAll(v2, v2->TBuff);
              TDebuggingLog::Log(L, v2->TBuff);
              *(_DWORD *)(v25 + 344) = 1;
              TCommunications_Handler::Kick(v2, v22);
            }
            *(_DWORD *)v25 = Now;
            *(_DWORD *)(v25 + 80) = Now;
          }
        }
        ++v22;
        v25 += 4;
        if ( v22 > v2->MaxGamePlayers )
          break;
        v21 = Now;
      }
      v18 = LastAnyPlayerMessage;
      v21 = Now;
      v23 = selfTimedOutCount;
      v24 = numPlayers;
    }
    v32 = v24 + 1;
    if ( v32 == 3 )
    {
      if ( v23 < 2 )
        goto LABEL_65;
    }
    else if ( v23 < v32 / 2 )
    {
LABEL_65:
      v36 = v2->LastTimeoutMessageTime;
      if ( v18 > v36 )
        v36 = v18;
      if ( v21 - v36 > 0x61A8 )
      {
        TCommunications_Handler::CheckPingTime(v2, 1);
        v2->LastTimeoutMessageTime = debug_timeGetTime();
      }
      RGE_Communications_Speed::Skip(v2->Speed);
      return 0;
    }
    TDebuggingLog::Log(L, aIDroppedMyself);
    TCommunications_Handler::NotifyWindowParam(v2, COMM_PLAYER_DROPPED, v2->Me);
    v33 = 1;
    v34 = 1;
    if ( v2->MaxGamePlayers >= 1u )
    {
      v35 = &v2->WasKicked[1];
      do
      {
        *v35 = 1;
        ++v34;
        ++v35;
      }
      while ( v34 <= v2->MaxGamePlayers );
    }
    TRIBE_World::send_zone_score_info((TRIBE_World *)rge_base_game->world);
    TDebuggingLog::Log(L, aInitializePlay);
    if ( v2->MaxGamePlayers >= 1u )
    {
      do
        TCommunications_Handler::InitPlayerInformation(v2, v33++, 0, text_in, text_in);
      while ( v33 <= v2->MaxGamePlayers );
    }
    v2->PlayerOptions.NeedsToBeSent = 0;
    v2->PlayerOptions.LastSentTime = 0;
    TCommunications_Handler::UpdatePlayers(v2);
    result = 0;
  }
  else if ( v20 == 5 )
  {
    RGE_Communications_Speed::ReloadBufferFrames(v2->Speed);
    v37 = v2->MeHost;
    F = 0;
    G = 0;
    if ( v37 )
      RGE_Communications_Speed::AnalyzeGameSpeed(v2->Speed, &F, &G, 1);
    v38 = v2->current_turn + 1;
    v39 = G;
    v40 = F;
    v2->current_turn = v38;
    TDebuggingLog::Log(L, a____startingTu, v38, WorldTime, v40, v39);
    TCommunications_Handler::CheckPlayerStopTurn(v2, v2->current_turn);
    result = RGE_Communications_Speed::GetBufferGranularityAdjusted(v2->Speed);
  }
  else
  {
    result = 0;
  }
  return result;
}
// 8884D4: using guessed type int `TCommunications_Handler::SendAllDoneMsg'::`4'::LastSentTime;

//----- (00426D40) --------------------------------------------------------
int __thiscall TCommunications_Handler::HasKicked(TCommunications_Handler *this, unsigned int p)
{
  return this->Kicked[p];
}

//----- (00426D50) --------------------------------------------------------
int __thiscall TCommunications_Handler::SendPlayerName(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  IUnknownVtbl *v2; // ecx@1
  int v3; // edi@1
  DPNAME dpnSetName; // [sp+8h] [bp-10h]@1

  dpnSetName.dwSize = 0;
  v1 = this;
  dpnSetName.dwFlags = 0;
  dpnSetName.lpszLongName = (unsigned __int16 *)this->MyFormalName;
  dpnSetName.lpszShortName = (unsigned __int16 *)this->MyFriendlyName;
  v2 = glpIDC->vfptr;
  dpnSetName.dwSize = 16;
  v3 = ((int (__stdcall *)(IDirectPlay3 *, unsigned int, DPNAME *, signed int))v2[10].QueryInterface)(
         glpIDC,
         dcoID,
         &dpnSetName,
         2);
  RGE_Comm_Error::ShowReturn(v1->Err, v3, aSendPlayerName);
  return v3;
}

//----- (00426DC0) --------------------------------------------------------
void __thiscall TCommunications_Handler::LogRXMsg(TCommunications_Handler *this, unsigned int Serialno, unsigned int fromPlayer, unsigned int ExecuteOnTurn, char Command, char Sequence)
{
  if ( this->RGE_Guaranteed_Delivery )
    TDebuggingLog::Log(
      L,
      aGtdRxSerDFromP,
      Serialno,
      fromPlayer,
      this->current_turn,
      ExecuteOnTurn,
      (unsigned __int8)Command,
      (unsigned __int8)Command,
      (unsigned __int8)Sequence);
}

//----- (00426E10) --------------------------------------------------------
void __thiscall TCommunications_Handler::ReceiveGameMessages(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  unsigned int v2; // ebp@4
  unsigned int v3; // edi@4
  double v4; // st7@5
  unsigned int v5; // edx@5
  double v6; // st6@5
  IUnknownVtbl *v7; // edx@9
  int v8; // eax@9
  __int64 v9; // [sp+Ch] [bp-8h]@5

  v1 = this;
  if ( this->Multiplayer )
  {
    if ( !(__S3__3__ReceiveGameMessages_TCommunications_Handler__QAEXXZ_4EA[0] & 1) )
    {
      __S3__3__ReceiveGameMessages_TCommunications_Handler__QAEXXZ_4EA[0] |= 1u;
      lastTime = debug_timeGetTime();
    }
    v2 = debug_timeGetTime();
    v3 = v2 - lastTime;
    if ( v2 - lastTime > 0x3E8 )
    {
      TDebuggingLog::Log(
        L,
        aTxLdRxLdElapse,
        v1->TXPacketLength - oldTXCount,
        v1->RXPacketLength - oldRXCount,
        v3,
        v1->TXPacketLength,
        v1->RXPacketLength);
      v4 = (double)v3;
      v9 = v1->TXPacketLength - oldTXCount;
      v5 = v1->RXPacketLength;
      v6 = (double)v9;
      HIDWORD(v9) = 0;
      v1->lastTXDataRate = v6 * 1000.0 / v4;
      LODWORD(v9) = v5 - oldRXCount;
      v1->lastRXDataRate = (double)v9 * 1000.0 / v4;
      lastTime = v2;
      oldTXCount = v1->TXPacketLength;
      oldRXCount = v1->RXPacketLength;
    }
    if ( v1->RGE_Guaranteed_Delivery )
      TCommunications_Handler::ExecuteIncoming(v1);
    if ( !dcoID )
      goto LABEL_19;
    v7 = glpIDC->vfptr;
    LODWORD(v9) = 0;
    v8 = ((int (__stdcall *)(IDirectPlay3 *, unsigned int, __int64 *))v7[5].Release)(glpIDC, dcoID, &v9);
    if ( v8 )
    {
      RGE_Comm_Error::ShowReturn(v1->Err, v8, aMsgwait);
      goto LABEL_14;
    }
    if ( (_DWORD)v9 )
    {
LABEL_19:
      TCommunications_Handler::GetDPLAYMessages(v1);
      if ( !v1->RGE_Guaranteed_Delivery )
      {
LABEL_16:
        TCommunications_Handler::CheckPingTime(v1, 0);
        return;
      }
      TCommunications_Handler::ExecuteIncoming(v1);
    }
LABEL_14:
    if ( v1->RGE_Guaranteed_Delivery )
      TCommunications_Handler::SendStoredMessages(v1);
    goto LABEL_16;
  }
}

//----- (00426FB0) --------------------------------------------------------
void __thiscall TCommunications_Handler::ShutdownGameMessages(TCommunications_Handler *this)
{
  this->ShuttingDown = 1;
  TCommunications_Handler::ReceiveGameMessages(this);
}

//----- (00426FC0) --------------------------------------------------------
void __thiscall TCommunications_Handler::GetDPLAYMessages(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // edi@1
  char *v2; // ebx@2
  IUnknownVtbl *v3; // ecx@2
  unsigned int v4; // esi@5
  int v5; // ebp@5
  unsigned int v6; // eax@5
  unsigned int v7; // esi@11
  int v8; // ebp@11
  unsigned int v9; // eax@11
  unsigned int v10; // eax@13
  unsigned int v11; // esi@13
  unsigned int v12; // eax@14
  int v13; // eax@19
  int v14; // ecx@19
  unsigned int *v15; // edx@20
  int v16; // eax@25
  int v17; // ecx@25
  unsigned int *v18; // edx@26
  int v19; // ebp@29
  int v20; // esi@30
  unsigned int v21; // eax@30
  unsigned int v22; // eax@30
  int v23; // edx@30
  unsigned int dwSize; // [sp+3Ch] [bp-18h]@2
  unsigned int dcoFromID; // [sp+40h] [bp-14h]@1
  unsigned int dcoReceiveID; // [sp+44h] [bp-10h]@1
  unsigned int dwCount; // [sp+48h] [bp-Ch]@2
  unsigned int dwPreSize; // [sp+4Ch] [bp-8h]@2
  unsigned int loopStartTime; // [sp+50h] [bp-4h]@2

  v1 = this;
  dcoFromID = 0;
  dcoReceiveID = 0;
  if ( glpIDC )
  {
    dwPreSize = 4000;
    dwSize = 4000;
    v2 = this->InCommBuff;
    loopStartTime = debug_timeGetTime();
    v3 = glpIDC->vfptr;
    dwCount = 0;
    if ( !((int (__stdcall *)(IDirectPlay3 *, unsigned int, unsigned int *))v3[5].Release)(glpIDC, dcoID, &dwCount)
      && dwCount > 0xA )
    {
      TDebuggingLog::Log(L, aDpmsgcountU, dwCount);
    }
    while ( 1 )
    {
      v4 = debug_timeGetTime();
      v5 = ((int (__stdcall *)(IDirectPlay3 *, unsigned int *, unsigned int *, signed int, _DWORD, unsigned int *))glpIDC->vfptr[8].AddRef)(
             glpIDC,
             &dcoFromID,
             &dcoReceiveID,
             8,
             0,
             &dwPreSize);
      v6 = debug_timeGetTime() - v4;
      if ( v6 > 0x32 )
        TDebuggingLog::Log(L, aReceivePeekSlo, v6);
      if ( !v5 && dwPreSize >= 0xFA0 )
      {
        TDebuggingLog::Log(L, aTrueOverflowDR, dwSize, 4000);
        return;
      }
      dwSize = dwPreSize;
      if ( v5 )
        dwSize = 4000;
      v7 = debug_timeGetTime();
      v8 = ((int (__stdcall *)(IDirectPlay3 *, unsigned int *, unsigned int *, signed int, char *, unsigned int *))glpIDC->vfptr[8].AddRef)(
             glpIDC,
             &dcoFromID,
             &dcoReceiveID,
             1,
             v1->InCommBuff,
             &dwSize);
      v9 = debug_timeGetTime() - v7;
      if ( v9 > 0x32 )
        TDebuggingLog::Log(L, aReceiveSlowUMs, v9);
      v10 = debug_timeGetTime();
      v11 = loopStartTime;
      if ( v10 - loopStartTime > 0x1F4 )
      {
        v12 = debug_timeGetTime();
        TDebuggingLog::Log(L, aInReceiveLoopF, v12 - v11);
      }
      if ( v8 == -2005466946 || !dwSize )
        return;
      if ( v8 )
      {
        RGE_Comm_Error::ShowReturn(v1->Err, v8, aRcvMsg);
        return;
      }
      if ( dcoFromID
        && (v13 = v1->PlayerOptions.LowPlayerNumber,
            v14 = v1->PlayerOptions.HighPlayerNumber,
            (unsigned __int16)v13 <= (signed int)(unsigned __int16)v14) )
      {
        v15 = &v1->PlayerOptions.dcoID[v13];
        while ( *v15 != dcoFromID )
        {
          ++v13;
          ++v15;
          if ( v13 > v14 )
            goto LABEL_23;
        }
      }
      else
      {
LABEL_23:
        v13 = 0;
      }
      TDebuggingLog::Log(L, aRxDCDU, v13, *v2, *v2, dwSize);
      if ( dcoFromID
        && (v16 = v1->PlayerOptions.LowPlayerNumber,
            v17 = v1->PlayerOptions.HighPlayerNumber,
            (unsigned __int16)v16 <= (signed int)(unsigned __int16)v17) )
      {
        v18 = &v1->PlayerOptions.dcoID[v16];
        while ( *v18 != dcoFromID )
        {
          ++v16;
          ++v18;
          if ( v16 > v17 )
            goto LABEL_29;
        }
        v19 = v16;
      }
      else
      {
LABEL_29:
        v19 = 0;
      }
      v20 = *v2;
      v21 = debug_timeGetTime();
      TDebuggingLog::Log(L, aCommRxPDIdLdSi, v19, dcoFromID, dwSize, v20, v20, v21);
      v22 = dwSize;
      v23 = v1->RXPackets + 1;
      v1->RXPacketLength += dwSize;
      v1->RXPackets = v23;
      v2[v22] = 0;
      if ( !dcoFromID )
        break;
      TCommunications_Handler::PreprocessMessages(v1, dwSize, v1->InCommBuff, dcoFromID, dcoReceiveID, 0);
    }
    TCommunications_Handler::EvaluateSystemMessage(v1, dwSize, v1->InCommBuff, 0, dcoReceiveID);
  }
}

//----- (00427300) --------------------------------------------------------
void __thiscall TCommunications_Handler::CheckPingTime(TCommunications_Handler *this, int Forced)
{
  TCommunications_Handler *v2; // edi@1
  unsigned int v3; // esi@2
  unsigned int v4; // ebp@2
  unsigned int *v5; // ebx@3

  v2 = this;
  if ( this->Multiplayer )
  {
    v3 = 1;
    v4 = debug_timeGetTime();
    if ( v2->MaxGamePlayers >= 1u )
    {
      v5 = &v2->LastTXPing[1];
      do
      {
        if ( TCommunications_Handler::IsPlayerHuman(v2, v3) && v3 != v2->Me && (v4 - *v5 > 0x1F40 || Forced) )
          TCommunications_Handler::TXPing(v2, v3);
        ++v3;
        ++v5;
      }
      while ( v3 <= v2->MaxGamePlayers );
    }
  }
}

//----- (00427390) --------------------------------------------------------
BOOL __thiscall TCommunications_Handler::TXPing(TCommunications_Handler *this, unsigned int ToPlayer)
{
  TCommunications_Handler *v2; // esi@1
  unsigned int v3; // eax@1
  unsigned int v4; // ecx@2
  unsigned int *v5; // edx@3
  unsigned int v6; // edi@5

  v2 = this;
  v3 = debug_timeGetTime();
  pingpong_0.Command = 49;
  pingpong_0.Initiated = v3;
  pingpong_0.CurrentTurn = v2->current_turn;
  if ( ToPlayer )
  {
    v2->LastTXPing[ToPlayer] = v3;
    v6 = v2->PlayerOptions.dcoID[ToPlayer];
  }
  else
  {
    v4 = 1;
    if ( v2->MaxGamePlayers >= 1u )
    {
      v5 = &v2->LastTXPing[1];
      do
      {
        *v5 = v3;
        ++v4;
        ++v5;
      }
      while ( v4 <= v2->MaxGamePlayers );
    }
    v6 = 0;
  }
  TDebuggingLog::Log(L, aTxPingDD, ToPlayer, 12);
  return TCommunications_Handler::FastSend(v2, v6, &pingpong_0, 0xCu, 0, 0) == 0;
}

//----- (00427440) --------------------------------------------------------
BOOL __thiscall TCommunications_Handler::TXDebugPing(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1

  v1 = this;
  pingpong.Command = 51;
  pingpong.Initiated = debug_timeGetTime();
  pingpong.CurrentTurn = v1->current_turn;
  TDebuggingLog::Log(L, aTxDebugPingDD, 0, 12);
  return TCommunications_Handler::FastSend(v1, 0, &pingpong, 0xCu, 0, 0) == 0;
}

//----- (004274B0) --------------------------------------------------------
int __thiscall TCommunications_Handler::FastSend(TCommunications_Handler *this, unsigned int ToDPID, void *Buffer, unsigned int BuffLen, int Priority, int Guaranteed)
{
  unsigned int v6; // ebx@1
  TCommunications_Handler *v7; // edi@1
  int result; // eax@2
  unsigned int v9; // esi@5
  int v10; // ebp@5
  unsigned int v11; // eax@5
  unsigned int i; // esi@8

  v6 = ToDPID;
  v7 = this;
  if ( ToDPID == dcoID )
  {
    TDebuggingLog::Log(L, aNoSendToSelfFa);
    result = -2147467259;
  }
  else if ( dcoID )
  {
    v9 = debug_timeGetTime();
    v10 = ((int (__stdcall *)(IDirectPlay3 *, unsigned int, unsigned int, _DWORD, void *, unsigned int))glpIDC->vfptr[8].Release)(
            glpIDC,
            dcoID,
            ToDPID,
            0,
            Buffer,
            BuffLen);
    v11 = debug_timeGetTime() - v9;
    if ( v11 > 0x32 )
      TDebuggingLog::Log(L, aFastsendSlowLd, v11);
    if ( ToDPID )
    {
      v6 = 1;
    }
    else
    {
      for ( i = 1; i <= v7->MaxGamePlayers; ++i )
      {
        if ( TCommunications_Handler::IsPlayerHuman(v7, i) && i != v7->Me )
          ++v6;
      }
    }
    v7->TXPacketLength += BuffLen * v6;
    if ( v10 == -2147024809 )
    {
      TDebuggingLog::Log(L, aFasttxToInvali);
      result = -2147024809;
    }
    else
    {
      if ( v10 )
        RGE_Comm_Error::ShowReturn(v7->Err, v10, aFasttx);
      result = v10;
    }
  }
  else
  {
    TDebuggingLog::Log(L, aBadDcoid0NoTx);
    result = -2147467259;
  }
  return result;
}

//----- (00427600) --------------------------------------------------------
int __thiscall TCommunications_Handler::PreprocessMessages(TCommunications_Handler *this, unsigned int dwSize, char *CommBuff, unsigned int dcoFromID, unsigned int dcoReceiveID, int fromHold)
{
  TCommunications_Handler *v6; // esi@1
  signed int v7; // edi@2
  signed int v8; // ecx@2
  unsigned int *v9; // eax@3
  int result; // eax@8
  signed int v11; // eax@14
  signed int v12; // edx@14
  unsigned int *v13; // ecx@15
  unsigned int *v14; // ebx@19
  unsigned int v15; // eax@19
  char *v16; // ecx@26
  COMMSTATES v17; // edx@29
  char v18; // al@32
  unsigned int v19; // eax@43
  int v20; // ebp@43
  int v21; // ebx@43
  unsigned int *v22; // ecx@45
  char v23; // al@47
  RGE_Communications_Speed *v24; // ecx@47
  char v25; // al@47
  unsigned int v26; // edx@47
  int v27; // edx@49
  int v28; // eax@49
  int v29; // eax@51
  int v30; // ecx@51
  int v31; // eax@51
  char *v32; // eax@51
  int v33; // edx@54
  signed int v34; // ebx@55
  signed int v35; // ecx@55
  unsigned int *v36; // eax@56
  unsigned int v37; // ebp@64
  unsigned int v38; // eax@64
  int v39; // ebx@64
  unsigned int v40; // ecx@66
  unsigned int v41; // edx@66
  unsigned int *v42; // ecx@66
  char v43; // al@68
  RGE_Communications_Speed *v44; // ecx@68
  char v45; // al@68
  unsigned int v46; // ecx@68
  unsigned int v47; // ST24_4@72
  char *v48; // eax@72
  char *v49; // esi@80
  unsigned int v50; // ecx@85
  unsigned int v51; // eax@85
  bool v52; // cf@85
  bool v53; // zf@85
  unsigned int NextSerialNumber; // [sp+10h] [bp-180h]@10
  int v55; // [sp+14h] [bp-17Ch]@10
  int v56; // [sp+18h] [bp-178h]@49
  char Msg; // [sp+1Ch] [bp-174h]@48
  int v58; // [sp+20h] [bp-170h]@48
  char AvgFramesMsec[4]; // [sp+24h] [bp-16Ch]@47
  char msg[256]; // [sp+2Ch] [bp-164h]@51
  char msg_str[100]; // [sp+12Ch] [bp-64h]@80

  v6 = this;
  if ( dcoFromID
    && (v7 = this->PlayerOptions.LowPlayerNumber,
        v8 = this->PlayerOptions.HighPlayerNumber,
        (unsigned __int16)v7 <= (signed int)(unsigned __int16)v8) )
  {
    v9 = &v6->PlayerOptions.dcoID[v7];
    while ( *v9 != dcoFromID )
    {
      ++v7;
      ++v9;
      if ( v7 > v8 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v7 = 0;
  }
  if ( *CommBuff == 73 )
  {
    TCommunications_Handler::UnlinkToLevel(v6, SERVICE_AVAILABLE);
    TCommunications_Handler::NotifyWindow(v6, COMM_UPDATE_PLAYERS);
    TCommunications_Handler::NotifyWindow(v6, COMM_PLAYER_KICKED);
    return 1;
  }
  if ( !v7 )
  {
    TDebuggingLog::Log(L, aBadPlayerForId, dcoFromID);
    v55 = *((_DWORD *)CommBuff + 2);
    LOBYTE(NextSerialNumber) = 65;
    if ( dcoID )
    {
      ((void (__stdcall *)(IDirectPlay3 *, unsigned int, unsigned int, _DWORD, unsigned int *, signed int))glpIDC->vfptr[8].Release)(
        glpIDC,
        dcoID,
        dcoFromID,
        0,
        &NextSerialNumber,
        8);
      v6->TXPacketLength += 8;
      result = 0;
    }
    else
    {
      TDebuggingLog::Log(L, aBadDcoid0NoTx);
      result = 0;
    }
    return result;
  }
  v6->LastPlayerCommunication[v7] = debug_timeGetTime();
  if ( dcoFromID
    && (v11 = v6->PlayerOptions.LowPlayerNumber,
        v12 = v6->PlayerOptions.HighPlayerNumber,
        (unsigned __int16)v11 <= (signed int)(unsigned __int16)v12) )
  {
    v13 = &v6->PlayerOptions.dcoID[v11];
    while ( *v13 != dcoFromID )
    {
      ++v11;
      ++v13;
      if ( v11 > v12 )
        goto LABEL_18;
    }
    NextSerialNumber = v11;
  }
  else
  {
LABEL_18:
    NextSerialNumber = 0;
  }
  v14 = (unsigned int *)(CommBuff + 8);
  v15 = debug_timeGetTime();
  TDebuggingLog::Log(L, aPreproByte0CFr, *CommBuff, NextSerialNumber, dcoFromID, *((_DWORD *)CommBuff + 2), v15);
  if ( *CommBuff == 75 && v6->PlayerOptions.ProgramState == 3 )
  {
    TDebuggingLog::Log(L, aKillMessageRec, dcoFromID, *((_DWORD *)CommBuff + 4));
    if ( *v14 == v6->PlayerHighSerialNumber[v7] + 1 )
      v6->PlayerHighSerialNumber[v7] = *v14;
    TDebuggingLog::Log(L, aTxKpAckDDD, v7, *v14, 8);
    TCommunications_Handler::TXAcknowledgeMessage(v6, *v14, v7);
    v6->PlayerHighSerialNumber[*((_DWORD *)CommBuff + 3)] = 2000 * *((_DWORD *)CommBuff + 3);
    if ( *((_DWORD *)CommBuff + 4) == dcoID )
    {
      TCommunications_Handler::NotifyWindow(v6, COMM_PLAYER_KICKED);
      return 1;
    }
    return 1;
  }
  if ( *CommBuff == 67 )
  {
    v16 = CommBuff + 12;
    if ( !v6->RGE_Guaranteed_Delivery )
      v16 = CommBuff + 8;
    if ( v16[16] )
    {
      v17 = v6->PlayerOptions.ProgramState;
      if ( v17 != 3 )
      {
        TDebuggingLog::Log(L, aDiscardChtpreg, (unsigned __int8)v16[16], v17, v16 + 17);
        return 0;
      }
    }
    TDebuggingLog::Log(L, aChatChtpregame, (unsigned __int8)v16[16], v6->PlayerOptions.ProgramState, v16 + 17);
  }
  v18 = *CommBuff;
  if ( *CommBuff == 65 )
  {
    TCommunications_Handler::RXAcknowledgeStoredMessage(v6, *((_DWORD *)CommBuff + 1), v7);
    TCommunications_Handler::PurgeAcknowledgedStoredMessages(v6);
    return 1;
  }
  if ( v18 == 82 )
  {
    TDebuggingLog::Log(L, aPlayerReadyMsg);
    if ( v6->MeHost )
    {
      v6->PlayerOptions.PlayerReady[v7] = (unsigned __int8)CommBuff[1];
      TDebuggingLog::Log(L, aRcvdReadyDFrom, (unsigned __int8)CommBuff[1], v7);
      v6->PlayerOptions.User1[v7] = *((_DWORD *)CommBuff + 1);
      v6->PlayerOptions.User2[v7] = *v14;
      v6->PlayerOptions.User3[v7] = *((_DWORD *)CommBuff + 3);
      v6->PlayerOptions.User4[v7] = *((_DWORD *)CommBuff + 4);
      v6->PlayerOptions.User5[v7] = *((_DWORD *)CommBuff + 5);
      v6->PlayerOptions.User6[v7] = *((_DWORD *)CommBuff + 6);
      v6->PlayerOptions.User7[v7] = *((_DWORD *)CommBuff + 7);
      if ( !TCommunications_Handler::IsPlayerHuman(v6, v7) )
        TCommunications_Handler::SetPlayerHumanity(v6, v7, ME_HUMAN);
      if ( v6->CommunicationsVersionCode == *((_DWORD *)CommBuff + 8) )
      {
        TDebuggingLog::Log(L, aCommunications, v7, v6->CommunicationsVersionCode);
      }
      else
      {
        TCommunications_Handler::NotifyWindowParam(v6, COMM_PLAYER_SERVICE_ERROR, v7);
        sprintf(v6->TBuff, aPlayerDHasADif, v7);
        TDebuggingLog::Log(L, v6->TBuff);
      }
      v6->PlayerOptions.NeedsToBeSent = 1;
      TCommunications_Handler::SendSharedData(v6, 0);
      TCommunications_Handler::UpdatePlayer(v6, v7, 0);
      sprintf(
        v6->TBuff,
        aPlrRdyP1DP2DP3,
        v6->PlayerOptions.PlayerReady[1],
        v6->PlayerOptions.PlayerReady[2],
        v6->PlayerOptions.PlayerReady[3],
        v6->PlayerOptions.PlayerReady[4],
        v6->PlayerOptions.PlayerReady[5],
        v6->PlayerOptions.PlayerReady[6],
        v6->PlayerOptions.PlayerReady[7],
        v6->PlayerOptions.PlayerReady[8]);
      TDebuggingLog::Log(L, v6->TBuff);
      TCommunications_Handler::NotifyWindow(v6, COMM_UPDATE_PLAYERS);
      return 1;
    }
    return 1;
  }
  if ( v18 == 49 )
  {
    v19 = v6->current_turn;
    v20 = *((_DWORD *)CommBuff + 1);
    v21 = v19 + v6->PlayerOptions.CommandTurnIncrement;
    if ( v6->Multiplayer )
    {
      if ( v6->PlayerOptions.ProgramState != 3 )
      {
        v22 = &v6->LastTurnAck[v6->Me];
        if ( *v22 != v19 )
        {
          *v22 = v19;
          if ( v6->current_turn > 6 )
          {
            v23 = RGE_Communications_Speed::GetHighLatencyCenti(v6->Speed);
            v24 = v6->Speed;
            AvgFramesMsec[0] = v23;
            v25 = RGE_Communications_Speed::GetAvgFrameRate(v24);
            v26 = v6->Me;
            AvgFramesMsec[1] = v25;
            RGE_Communications_Speed::SetPlayerTurnSpeed(v6->Speed, v26, v25, AvgFramesMsec[0]);
          }
          `TCommunications_Handler::SendAllDoneMsg'::`4'::LastSentTime = debug_timeGetTime();
          Msg = 68;
          v58 = v21;
          TDebuggingLog::Log(L, aTxDoneD, 12);
          TCommunications_Handler::CommOut(v6, 0, 68, &Msg, 12, 0);
        }
      }
    }
    v27 = v6->current_turn;
    LOBYTE(NextSerialNumber) = 50;
    v55 = v20;
    v56 = v27;
    TDebuggingLog::Log(L, aTxPongDD, v7, 12);
    v28 = TCommunications_Handler::FastSend(v6, v6->PlayerOptions.dcoID[v7], &NextSerialNumber, 0xCu, 0, 0);
    RGE_Comm_Error::ShowReturn(v6->Err, v28, aTxPing);
    result = 1;
  }
  else
  {
    if ( v18 == 51 )
    {
      v29 = *((_DWORD *)CommBuff + 1);
      v30 = v6->current_turn;
      LOBYTE(NextSerialNumber) = 52;
      v55 = v29;
      v56 = v30;
      TDebuggingLog::Log(L, aTxDebugPongDD, v7, 12);
      v31 = TCommunications_Handler::FastSend(v6, v6->PlayerOptions.dcoID[v7], &NextSerialNumber, 0xCu, 0, 0);
      RGE_Comm_Error::ShowReturn(v6->Err, v31, aTxDebugPing);
      v32 = TCommunications_Handler::GetPlayerName(v6, v7);
      sprintf(msg, aReceivedDebugP, v32, v7);
      TDebuggingLog::Log(L, msg);
      TChat::AddChatMsg(v6->Chat, PlayerName, msg, 0);
      return 1;
    }
    if ( v18 == 63 )
    {
      if ( !v6->MeHost )
        return 1;
      v33 = *((_DWORD *)CommBuff + 1);
      if ( v33
        && (v34 = v6->PlayerOptions.LowPlayerNumber,
            v35 = v6->PlayerOptions.HighPlayerNumber,
            (unsigned __int16)v34 <= (signed int)(unsigned __int16)v35) )
      {
        v36 = &v6->PlayerOptions.dcoID[v34];
        while ( *v36 != v33 )
        {
          ++v34;
          ++v36;
          if ( v34 > v35 )
            goto LABEL_59;
        }
      }
      else
      {
LABEL_59:
        v34 = 0;
      }
      if ( v6->PlayerOptions.ProgramState == 3 )
      {
        sprintf(v6->TBuff, aPDReportedPDDc, v7, v34, *((_DWORD *)CommBuff + 1));
        TDebuggingLog::Log(L, v6->TBuff);
        TDebuggingLog::Log(L, aRcvdMissingPla, v34, *((_DWORD *)CommBuff + 1), v7);
        v6->PlayerOptions.PlayerReady[v34] = 0;
        v6->PlayerOptions.InvalidPlayer[v34] = 1;
        v6->PlayerOptions.NeedsToBeSent = 1;
        result = 1;
      }
      else
      {
        TDebuggingLog::Log(L, aRcvdMaxTxRepor, v34, v33, v7);
        TCommunications_Handler::Kick(v6, v34);
        result = 1;
      }
    }
    else
    {
      if ( v18 != 50 )
      {
        if ( v18 == 52 )
        {
          v47 = debug_timeGetTime() - *((_DWORD *)CommBuff + 1);
          v48 = TCommunications_Handler::GetPlayerName(v6, v7);
          sprintf(msg, aSDDebugPingEla, v48, v7, v47);
          TDebuggingLog::Log(L, msg);
          TChat::AddChatMsg(v6->Chat, PlayerName, msg, 0);
          return 1;
        }
        if ( v18 == 89 )
        {
          if ( v6->PlayerOptions.ProgramState == 3 )
          {
            v6->PlayerHighSerialNumber[v7] = *((_DWORD *)CommBuff + 1);
            TCommunications_Handler::ClearRXForPlayer(v6, v7);
            TDebuggingLog::Log(L, aNosuchserialSe, v7, v6->PlayerHighSerialNumber[v7], *((_DWORD *)CommBuff + 1));
            return 1;
          }
        }
        else
        {
          if ( v6->RGE_Guaranteed_Delivery )
          {
            if ( v6->IntentionallyDropPackets )
            {
              if ( v6->current_turn > 6 && ++dropcount >= 9 )
              {
                (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(
                  1212,
                  msg_str,
                  100);
                v49 = v6->TBuff;
                sprintf(v49, msg_str, *v14, *CommBuff, *CommBuff);
                TDebuggingLog::Log(L, v49);
                dropcount = 0;
                return 1;
              }
            }
            if ( *CommBuff == 88 )
            {
              TCommunications_Handler::TXResendReply(v6, *((_DWORD *)CommBuff + 1), v7);
              return 1;
            }
            if ( !v6->PlayerHighSerialNumber[v7] )
            {
              TDebuggingLog::Log(L, aFirstContactWi, v7, *v14);
              v6->PlayerHighSerialNumber[v7] = *v14 - 1;
            }
            v50 = *v14;
            v51 = v6->PlayerHighSerialNumber[v7] + 1;
            v52 = *v14 < v51;
            v53 = *v14 == v51;
            NextSerialNumber = v6->PlayerHighSerialNumber[v7] + 1;
            if ( v52 )
            {
              sprintf(v6->TBuff, aGtdRxPastSerDR, v50, v51, v7);
              TDebuggingLog::Log(L, v6->TBuff);
              TDebuggingLog::Log(L, aTxRAckDDD, v7, *v14, 8);
              TCommunications_Handler::TXAcknowledgeMessage(v6, *v14, v7);
              return 1;
            }
            if ( !v52 && !v53 )
            {
              ++v6->DroppedPacketCount;
              sprintf(v6->TBuff, aGtdRxFutureSer, *v14, v7);
              TDebuggingLog::Log(L, v6->TBuff);
              TCommunications_Handler::StoreIncoming(v6, *v14, CommBuff, dwSize, dcoFromID, dcoReceiveID);
              TDebuggingLog::Log(L, aTxFAckDDD, v7, *v14, 8);
              TCommunications_Handler::TXAcknowledgeMessage(v6, *v14, v7);
              TCommunications_Handler::TXResendRequest(v6, NextSerialNumber, v7);
              return 1;
            }
            if ( !fromHold )
            {
              TDebuggingLog::Log(L, aTxNAckDDD, v7, v50, 8);
              TCommunications_Handler::TXAcknowledgeMessage(v6, *v14, v7);
            }
            v6->PlayerHighSerialNumber[v7] = *v14;
            InContent = CommBuff + 12;
            InContentSize = dwSize - 12;
          }
          else
          {
            TCommunications_Handler::LogRXMsg(v6, *v14, v7, *((_DWORD *)CommBuff + 1), v18, CommBuff[1]);
            InContent = CommBuff + 8;
            InContentSize = dwSize - 8;
          }
          TDebuggingLog::Log(
            L,
            aProcessSerDCmd,
            *v14,
            (unsigned __int8)*CommBuff,
            (unsigned __int8)*CommBuff,
            (unsigned __int8)CommBuff[1],
            *((_DWORD *)CommBuff + 1),
            dwSize,
            dcoFromID,
            dcoReceiveID);
          if ( !v6->ShuttingDown )
            TCommunications_Handler::EvaluatePlayerMessage(
              v6,
              dwSize,
              v7,
              *((_DWORD *)CommBuff + 1),
              *CommBuff,
              CommBuff[1],
              InContent,
              InContentSize,
              dcoFromID,
              dcoReceiveID);
        }
        return 1;
      }
      v37 = debug_timeGetTime() - *((_DWORD *)CommBuff + 1);
      v38 = v6->current_turn;
      v39 = v38 + v6->PlayerOptions.CommandTurnIncrement;
      if ( v6->Multiplayer )
      {
        if ( v6->PlayerOptions.ProgramState != 3 )
        {
          v40 = v6->Me;
          v41 = v6->LastTurnAck[v40];
          v42 = &v6->LastTurnAck[v40];
          if ( v41 != v38 )
          {
            *v42 = v38;
            if ( v6->current_turn > 6 )
            {
              v43 = RGE_Communications_Speed::GetHighLatencyCenti(v6->Speed);
              v44 = v6->Speed;
              AvgFramesMsec[0] = v43;
              v45 = RGE_Communications_Speed::GetAvgFrameRate(v44);
              v46 = v6->Me;
              AvgFramesMsec[1] = v45;
              RGE_Communications_Speed::SetPlayerTurnSpeed(v6->Speed, v46, v45, AvgFramesMsec[0]);
            }
            `TCommunications_Handler::SendAllDoneMsg'::`4'::LastSentTime = debug_timeGetTime();
            Msg = 68;
            v58 = v39;
            TDebuggingLog::Log(L, aTxDoneD, 12);
            TCommunications_Handler::CommOut(v6, 0, 68, &Msg, 12, 0);
          }
        }
      }
      RGE_Communications_Speed::SetActualLatency(v6->Speed, v7, v37);
      result = 1;
    }
  }
  return result;
}
// 8884D4: using guessed type int `TCommunications_Handler::SendAllDoneMsg'::`4'::LastSentTime;

//----- (00428270) --------------------------------------------------------
void __thiscall TCommunications_Handler::NotifyWindow(TCommunications_Handler *this, COMMMESSAGES msg)
{
  TCommunications_Handler::NotifyWindowParam(this, msg, 0);
}

//----- (00428280) --------------------------------------------------------
void __thiscall TCommunications_Handler::NotifyWindowParam(TCommunications_Handler *this, COMMMESSAGES msg, int lparam)
{
  PostMessageA(this->HostHWND, 0x400u, msg, lparam);
  TDebuggingLog::Log(L, fmt, msg, lparam);
}

//----- (004282C0) --------------------------------------------------------
int __thiscall TCommunications_Handler::EvaluatePlayerMessage(TCommunications_Handler *this, unsigned int len, unsigned int fromPlayer, unsigned int ExecuteOnTurn, char Command, char Sequence, char *Content, unsigned int ContentSize, unsigned int dcoFromID, unsigned int dcoReceiveID)
{
  TCommunications_Handler *v10; // esi@1
  int result; // eax@2
  unsigned int v12; // ecx@6
  unsigned int v13; // eax@8
  unsigned int v14; // ebx@24
  signed int v15; // eax@25
  signed int v16; // edx@25
  unsigned int *v17; // ecx@26
  unsigned int v18; // edi@29

  v10 = this;
  if ( this->Multiplayer )
  {
    switch ( Command )
    {
      case 0x44:
        RGE_Communications_Speed::SetPlayerTurnSpeed(this->Speed, fromPlayer, Content[9], Content[8]);
        if ( v10->PlayerOptions.ProgramState >= 5 && v10->current_turn >= 6
          || (v12 = v10->current_turn, *((_DWORD *)Content + 1) >= v12) )
        {
          v13 = *((_DWORD *)Content + 1) - v10->PlayerOptions.CommandTurnIncrement;
          if ( v13 <= v10->LastTurnAck[fromPlayer] )
            v13 = v10->LastTurnAck[fromPlayer];
          v10->LastTurnAck[fromPlayer] = v13;
          result = 1;
        }
        else
        {
          TDebuggingLog::Log(L, aRegressionWarn, v12, *((_DWORD *)Content + 1));
          result = 0;
        }
        break;
      case 0x51:
        TCommunications_Handler::SetPlayerStopTurn(this, fromPlayer, *(_DWORD *)Content);
        result = 1;
        break;
      case 0x4D:
        RGE_Communications_Synchronize::Add(
          this->Sync,
          fromPlayer,
          *(_DWORD *)Content,
          *((_DWORD *)Content + 1),
          *((_DWORD *)Content + 2),
          *((_DWORD *)Content + 3),
          *((_DWORD *)Content + 4),
          *((_DWORD *)Content + 5),
          *((_DWORD *)Content + 6),
          *((_DWORD *)Content + 7));
        result = 1;
        break;
      case 0x3E:
        TCommunications_Handler::AddCommand(this, ExecuteOnTurn, Content, len, fromPlayer, Sequence, 0);
        result = 1;
        break;
      case 0x53:
        RGE_Communications_Speed::SetFutureSpeedChange(
          this->Speed,
          *(_WORD *)Content,
          *((_WORD *)Content + 1),
          ExecuteOnTurn);
        result = 1;
        break;
      case 0x43:
        TDebuggingLog::Log(
          L,
          aChatRxFromPDDR,
          fromPlayer,
          dcoFromID,
          dcoReceiveID,
          Content + 17,
          *((_DWORD *)Content + 3),
          ContentSize,
          (unsigned __int8)Content[16]);
        if ( Content[v10->Me + 1] != 89 && v10->PlayerOptions.ProgramState != 3 )
          goto LABEL_40;
        TChat::AddChatMsg(v10->Chat, v10->FriendlyName[(unsigned __int8)*Content].Text, Content + 17, 0);
        result = 1;
        break;
      case 0x50:
        TDebuggingLog::Log(L, aPDRequestedPau);
        TCommunications_Handler::LocalPauseGame(v10, fromPlayer);
        RGE_Communications_Synchronize::LogChecksums(v10->Sync, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        result = 1;
        break;
      case 0x55:
        TDebuggingLog::Log(L, aResumeMsgRcvd);
        TCommunications_Handler::LocalResumeGame(v10, fromPlayer);
        result = 1;
        break;
      case 0x2B:
        if ( !this->MeHost )
          goto LABEL_40;
        TCommunications_Handler::SendPauseGame(this, 0);
        TDebuggingLog::Log(L, aNonHostRequest);
        TCommunications_Handler::LocalResumeGame(v10, fromPlayer);
        result = 1;
        break;
      case 0x57:
        if ( !this->MeHost )
          goto LABEL_40;
        TCommunications_Handler::SendPauseGame(this, 1);
        TCommunications_Handler::LocalPauseGame(v10, fromPlayer);
        result = 1;
        break;
      case 0x4B:
        TDebuggingLog::Log(L, aKillMessageR_1, fromPlayer, *(_DWORD *)Content);
        v14 = *((_DWORD *)Content + 1);
        if ( v14
          && (v15 = v10->PlayerOptions.LowPlayerNumber,
              v16 = v10->PlayerOptions.HighPlayerNumber,
              (unsigned __int16)v15 <= (signed int)(unsigned __int16)v16) )
        {
          v17 = &v10->PlayerOptions.dcoID[v15];
          while ( *v17 != v14 )
          {
            ++v15;
            ++v17;
            if ( v15 > v16 )
              goto LABEL_29;
          }
          v18 = v15;
        }
        else
        {
LABEL_29:
          v18 = 0;
        }
        if ( !v18 )
          goto LABEL_40;
        if ( !v10->PlayerStopTurn[v18] )
          TCommunications_Handler::DropDeadPlayer(v10, v18, v14);
        if ( v18 == v10->Me )
        {
          TCommunications_Handler::NotifyWindow(v10, COMM_PLAYER_KICKED);
          result = 1;
        }
        else
        {
          if ( v10->PlayerStopTurn[v18] )
            goto LABEL_40;
          TCommunications_Handler::NotifyWindowParam(v10, COMM_OTHER_PLAYER_DROPPED, v18);
          result = 1;
        }
        break;
      case 0x4E:
        if ( this->MeHost )
          goto LABEL_40;
        TDebuggingLog::Log(L, aHostRequestedW);
        result = 1;
        break;
      default:
        TDebuggingLog::Log(L, aUnknownMessage, (unsigned __int8)Command, (unsigned __int8)Command);
LABEL_40:
        result = 1;
        break;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004286F0) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetPlayerStopTurn(TCommunications_Handler *this, unsigned int player, unsigned int Turn)
{
  this->PlayerStopTurn[player] = Turn;
}

//----- (00428710) --------------------------------------------------------
void __thiscall TCommunications_Handler::CheckPlayerStopTurn(TCommunications_Handler *this, unsigned int Turn)
{
  TCommunications_Handler *v2; // edi@1
  unsigned int v3; // esi@1
  char *v4; // ebx@2
  signed int v5; // ebx@10
  unsigned int i; // esi@10
  int StopPending; // [sp+10h] [bp-4h]@1

  v2 = this;
  StopPending = 0;
  v3 = 1;
  if ( this->MaxGamePlayers >= 1u )
  {
    v4 = (char *)&this->PlayerStopTurn[1];
    do
    {
      if ( *(_DWORD *)v4 )
        StopPending = 1;
      if ( *(_DWORD *)v4 == Turn )
      {
        TDebuggingLog::Log(L, aCheckplayersto, v3, Turn);
        TCommunications_Handler::InitPlayerInformation(v2, v3, 0, FrName, text_in);
        TCommunications_Handler::SetPlayerHumanity(v2, v3, ME_ELIMINATED);
        TCommunications_Handler::NotifyWindowParam(v2, COMM_PLAYER_RESIGNED, v3);
        *(_DWORD *)v4 = 0;
      }
      ++v3;
      v4 += 4;
    }
    while ( v3 <= v2->MaxGamePlayers );
  }
  if ( v2->current_turn > 6 && !StopPending )
  {
    v5 = 0;
    for ( i = 1; i <= v2->MaxGamePlayers; ++i )
    {
      if ( (TCommunications_Handler::IsPlayerHuman(v2, i) || TCommunications_Handler::IsPlayerComputer(v2, i))
        && i != v2->Me )
      {
        v5 = 1;
      }
    }
    if ( !v5 )
      TCommunications_Handler::NotifyWindow(v2, COMM_NO_OTHER_HUMANS);
  }
}

//----- (00428810) --------------------------------------------------------
void __thiscall TCommunications_Handler::ReleaseSettings(TCommunications_Handler *this)
{
  this->PlayerOptions.NeedsToBeSent = 0;
}

//----- (00428820) --------------------------------------------------------
int __thiscall TCommunications_Handler::SendSharedData(TCommunications_Handler *this, int SendImmediately)
{
  TCommunications_Handler *v2; // ebp@1
  int result; // eax@2
  unsigned int v4; // edi@5
  unsigned int v5; // ebx@11
  COMMPLAYEROPTIONS *v6; // eax@11
  int v7; // esi@11
  unsigned int i; // eax@11
  COMMPLAYEROPTIONS *SendImmediatelya; // [sp+14h] [bp+4h]@11

  v2 = this;
  if ( !glpIDC )
    return 0;
  if ( !this->MeHost )
    return 0;
  v4 = debug_timeGetTime();
  if ( SendImmediately )
  {
    v2->PlayerOptions.NeedsToBeSent = 1;
  }
  else if ( v4 - v2->PlayerOptions.LastSentTime < 0x7D0 )
  {
    return 0;
  }
  if ( v2->PlayerOptions.NeedsToBeSent )
  {
    if ( dcoID )
    {
      TDebuggingLog::Log(L, aSendingOptions);
      v5 = v2->PlayerOptions.DataSizeToFollow + 464;
      v2->PlayerOptions.LastSentTime = v4;
      v6 = (COMMPLAYEROPTIONS *)operator new(v5);
      qmemcpy(v6, &v2->PlayerOptions, sizeof(COMMPLAYEROPTIONS));
      qmemcpy(&v6[1], v2->OptionsData, v2->PlayerOptions.DataSizeToFollow);
      SendImmediatelya = v6;
      v7 = ((int (__stdcall *)(IDirectPlay3 *, unsigned int, COMMPLAYEROPTIONS *, unsigned int, signed int))glpIDC->vfptr[9].Release)(
             glpIDC,
             dcoID,
             v6,
             v5,
             2);
      RGE_Comm_Error::ShowReturn(v2->Err, v7, aSetPlayerData);
      operator delete(SendImmediatelya);
      v2->PlayerOptions.NeedsToBeSent = 0;
      TCommunications_Handler::NotifyWindow(v2, COMM_SHARED_DATA_SENT);
      for ( i = 1; i <= v2->MaxGamePlayers; v2->PlayerOptions.InvalidPlayer[i++] = 0 )
        ;
      result = v7;
    }
    else
    {
      TDebuggingLog::Log(L, aNoDcoidFailSen);
      result = -2147467259;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004289A0) --------------------------------------------------------
int TCommunications_Handler::TEST()
{
  TTaunt *v1; // eax@1
  TTaunt *v2; // eax@2
  TTaunt *v3; // esi@2
  int v4; // eax@4

  v1 = (TTaunt *)operator new(0x198u);
  if ( v1 )
  {
    TTaunt::TTaunt(v1, sound_driver);
    v3 = v2;
  }
  else
  {
    v3 = 0;
  }
  v4 = debug_rand(aCMsdevWorkA_39, 2290);
  TDebuggingLog::Log(L, aPlayingTauntD, 15 * v4 / 0x7FFF);
  TTaunt::PlayTauntNo(v3, 4);
  if ( v3 )
  {
    TTaunt::~TTaunt(v3);
    operator delete(v3);
  }
  return 1;
}

//----- (00428A70) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetSelfPlayer(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // ebx@1
  unsigned int v2; // edi@1
  unsigned int v3; // eax@2
  char *v4; // esi@2

  v1 = this;
  v2 = 1;
  if ( this->MaxGamePlayers < 1u )
  {
    v3 = dcoID;
LABEL_8:
    TDebuggingLog::Log(L, aSetSelfFailed_, v3);
  }
  else
  {
    v3 = dcoID;
    v4 = (char *)&this->PlayerOptions.dcoID[1];
    while ( 1 )
    {
      TDebuggingLog::Log(L, aCheckDcoidDToM, *(_DWORD *)v4, v3);
      v3 = dcoID;
      if ( *(_DWORD *)v4 == dcoID )
        break;
      ++v2;
      v4 += 4;
      if ( v2 > v1->MaxGamePlayers )
        goto LABEL_8;
    }
    TDebuggingLog::Log(L, aMatchIdSet_);
    v1->Me = v2;
    TCommunications_Handler::NotifyWindowParam(v1, COMM_PLAYER_ID_SET, v2);
  }
}

//----- (00428B10) --------------------------------------------------------
void __thiscall TCommunications_Handler::DropDeadPlayer(TCommunications_Handler *this, unsigned int PlayerNo, unsigned int PlayerDPID)
{
  TCommunications_Handler *v3; // esi@1
  unsigned int v4; // eax@4
  int *v5; // ecx@5
  signed int v6; // edi@7
  char msg_str[50]; // [sp+Ch] [bp-34h]@14

  v3 = this;
  this->WasKicked[PlayerNo] = 1;
  TDebuggingLog::Log(L, aDropDeadCalled, PlayerNo, PlayerDPID);
  v3->PlayerOptions.InvalidPlayer[PlayerNo] = 0;
  if ( !PlayerNo )
  {
    TDebuggingLog::Log(L, aPlayerNumberIn);
    TCommunications_Handler::UpdatePlayers(v3);
    return;
  }
  if ( PlayerNo == v3->Me )
  {
    TDebuggingLog::Log(L, aIDropped_);
    TCommunications_Handler::NotifyWindowParam(v3, COMM_PLAYER_DROPPED, v3->Me);
    v4 = 1;
    if ( v3->MaxGamePlayers >= 1u )
    {
      v5 = &v3->WasKicked[1];
      do
      {
        *v5 = 1;
        ++v4;
        ++v5;
      }
      while ( v4 <= v3->MaxGamePlayers );
    }
    TRIBE_World::send_zone_score_info((TRIBE_World *)rge_base_game->world);
    TDebuggingLog::Log(L, aInitializePlay);
    v6 = 1;
    if ( v3->MaxGamePlayers >= 1u )
    {
      do
        TCommunications_Handler::InitPlayerInformation(v3, v6++, 0, text_in, text_in);
      while ( v6 <= v3->MaxGamePlayers );
    }
    v3->PlayerOptions.NeedsToBeSent = 0;
    v3->PlayerOptions.LastSentTime = 0;
    TCommunications_Handler::UpdatePlayers(v3);
  }
  else
  {
    if ( !TCommunications_Handler::IsPlayerHuman(v3, PlayerNo) )
    {
      TCommunications_Handler::NotifyWindowParam(v3, COMM_PLAYER_DEFEATED, PlayerNo);
      TDebuggingLog::Log(L, aPlayerWasDefea);
      TCommunications_Handler::InitPlayerInformation(v3, PlayerNo, 0, aDefeated, aNoOtherInforma);
      TCommunications_Handler::UpdatePlayers(v3);
      TCommunications_Handler::CalculatePlayerRange(v3);
      return;
    }
    if ( v3->PlayerOptions.ProgramState < 5 || v3->current_turn < 6 )
    {
      TDebuggingLog::Log(L, aPlayerDroppedB);
      TCommunications_Handler::InitPlayerInformation(v3, PlayerNo, 0, aDropped, aNoOtherInforma);
      TCommunications_Handler::SetPlayerHumanity(v3, PlayerNo, 0);
      TCommunications_Handler::UpdatePlayers(v3);
      TCommunications_Handler::CalculatePlayerRange(v3);
    }
    else
    {
      TDebuggingLog::Log(L, aPlayerQuitTheG);
      (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(1213, msg_str, 50);
      sprintf(v3->TBuff, msg_str, PlayerNo, &v3->FriendlyName[PlayerNo]);
      TDebuggingLog::Log(L, v3->TBuff);
      TCommunications_Handler::InitPlayerInformation(v3, PlayerNo, 0, aDropped, text_in);
      TCommunications_Handler::SetPlayerHumanity(v3, PlayerNo, 0);
      TCommunications_Handler::UpdatePlayers(v3);
      TCommunications_Handler::CalculatePlayerRange(v3);
      if ( v3->PlayerStopTurn[PlayerNo] )
        return;
    }
    TCommunications_Handler::NotifyWindowParam(v3, COMM_OTHER_PLAYER_DROPPED, PlayerNo);
  }
}

//----- (00428DA0) --------------------------------------------------------
void __thiscall TCommunications_Handler::EvaluateSystemMessage(TCommunications_Handler *this, unsigned int type, char *CommBuff, unsigned int dcoFromID, unsigned int dcoReceiveID)
{
  TCommunications_Handler *v5; // ebp@1
  char *v6; // ebx@3
  int v7; // ecx@3
  unsigned int v8; // edi@9
  signed int v9; // eax@10
  signed int v10; // edx@10
  unsigned int *v11; // ecx@11
  unsigned int v12; // esi@14
  unsigned int v13; // ecx@21
  unsigned int v14; // ST24_4@21
  int v15; // esi@24
  char *v16; // edi@24
  COMMSTATES v17; // edx@24
  unsigned int v18; // esi@27
  unsigned int v19; // eax@27
  PLAYERHUMANITY *v20; // ecx@28
  unsigned int v21; // eax@43
  unsigned int v22; // esi@46
  signed int v23; // ebx@47
  int v24; // edi@47
  unsigned int v25; // eax@60
  unsigned int v26; // esi@61
  signed int v27; // edi@62
  int v28; // ebx@62
  int v29; // edx@66
  unsigned int v30; // eax@70
  int v31; // eax@71
  MSGFORMAT_KILL_PLAYER kp; // [sp+10h] [bp-Ch]@21
  unsigned int dcoFromIDa; // [sp+28h] [bp+Ch]@24

  v5 = this;
  if ( !this->Multiplayer )
  {
    TDebuggingLog::Log(L, aMpInDpanalysis);
    return;
  }
  v6 = CommBuff;
  TDebuggingLog::Log(L, aDpSysMsgD, *(_DWORD *)CommBuff);
  v7 = *(_DWORD *)CommBuff;
  if ( *(_DWORD *)CommBuff > 0x21u )
  {
    switch ( v7 )
    {
      case 261:
        goto LABEL_39;
      case 265:
        TDebuggingLog::Log(L, aDpChatMsg);
        return;
      case 257:
        if ( v5->PlayerOptions.ProgramState == 3 || v5->current_turn < 6 )
        {
          TDebuggingLog::Log(L, aHostOtherExitB);
          TCommunications_Handler::NotifyWindow(v5, COMM_HOST_EXITED);
          TCommunications_Handler::EnableNewPlayers((IDirectPlay2 *)&glpIDC->vfptr, 1);
        }
        else
        {
          TDebuggingLog::Log(L, aAssumedHost);
          v21 = v5->Me;
          v5->MeHost = 1;
          v5->PlayerOptions.HostPlayerNumber = v21;
          TCommunications_Handler::CheckPingTime(v5, 1);
          TCommunications_Handler::UpdatePlayers(v5);
          TCommunications_Handler::EnableNewPlayers((IDirectPlay2 *)&glpIDC->vfptr, 0);
          TCommunications_Handler::CalculatePlayerRange(v5);
          TCommunications_Handler::NotifyWindowParam(v5, COMM_HOST_CHANGED, v5->Me);
          TCommunications_Handler::KillAnyMissingPlayers(v5);
        }
        return;
      case 49:
        TDebuggingLog::Log(L, aCommHostSessio);
        v5->PlayerOptions.NeedsToBeSent = 1;
        TCommunications_Handler::UpdatePlayers(v5);
        TCommunications_Handler::NotifyWindow(v5, COMM_HOST_EXITED);
        return;
      case 258:
        sprintf(
          v5->TBuff,
          aPlayerDataP1DP,
          v5->PlayerOptions.dcoID[1],
          v5->PlayerOptions.dcoID[2],
          v5->PlayerOptions.dcoID[3],
          v5->PlayerOptions.dcoID[4],
          v5->PlayerOptions.dcoID[5],
          v5->PlayerOptions.dcoID[6],
          v5->PlayerOptions.dcoID[7],
          v5->PlayerOptions.dcoID[8]);
        TDebuggingLog::Log(L, v5->TBuff);
        v22 = 1;
        if ( v5->MaxGamePlayers >= 1u )
        {
          v23 = 2000;
          v24 = (int)&v5->PlayerHighSerialNumber[1];
          do
          {
            if ( !*(_DWORD *)v24 && *(_DWORD *)(v24 + 60) )
            {
              TCommunications_Handler::ClearRXTXForPlayer(v5, v22);
              *(_DWORD *)v24 = v23;
              TDebuggingLog::Log(L, aSetExpectedSer, v22, v23 + 1);
            }
            ++v22;
            v24 += 4;
            v23 += 2000;
          }
          while ( v22 <= v5->MaxGamePlayers );
          v6 = CommBuff;
        }
        if ( v5->MeHost )
        {
          TDebuggingLog::Log(L, aHostNoRcvOpts_);
        }
        else
        {
          TDebuggingLog::Log(L, aCheckingStateF);
          if ( v5->PlayerOptions.ProgramState == 3 )
          {
            TDebuggingLog::Log(L, aGroupOptionsRc);
            if ( *((_DWORD *)v6 + 4) >= 0x1D0u )
            {
              qmemcpy(&v5->PlayerOptions, *((const void **)v6 + 3), sizeof(v5->PlayerOptions));
              if ( *((_DWORD *)v6 + 4) >= v5->PlayerOptions.DataSizeToFollow + 464 )
                TCommunications_Handler::SetMyGameOptions(
                  v5,
                  (char *)(*((_DWORD *)v6 + 3) + 464),
                  v5->PlayerOptions.DataSizeToFollow);
              TCommunications_Handler::NotifyWindow(v5, COMM_UPDATE_PARAMS);
            }
            v25 = v5->PlayerOptions.CurrentTurn;
            v5->AcknowledgeAfterMsec = v5->PlayerOptions.AcknowledgeAfterMsec;
            v5->current_turn = v25;
            TCommunications_Handler::SetSelfPlayer(v5);
            if ( v5->PlayerOptions.GameHasStarted )
            {
              TDebuggingLog::Log(L, aHostLaunchedGa);
              TCommunications_Handler::CalculatePlayerRange(v5);
              TDebuggingLog::Log(L, aOptionsSetProg, v5->PlayerOptions.ProgramState);
              v5->PlayerOptions.ProgramState = 5;
              TCommunications_Handler::ResetLastCommunicationTimes(v5);
              TCommunications_Handler::ClearRXandTX(v5);
              v26 = 1;
              memset(&v5->PlayerStopTurn[1], 0, 0x24u);
              if ( v5->MaxGamePlayers >= 1u )
              {
                v27 = 2000;
                v28 = (int)&v5->PlayerHighSerialNumber[1];
                do
                {
                  if ( *(_DWORD *)(v28 + 60) )
                  {
                    *(_DWORD *)v28 = v27;
                    TDebuggingLog::Log(L, aSetExpectedSer, v26, v27 + 1);
                  }
                  ++v26;
                  v28 += 4;
                  v27 += 2000;
                }
                while ( v26 <= v5->MaxGamePlayers );
              }
              v29 = 2000 * v5->Me;
              v5->GTDSerialNo = v29 + 1;
              TDebuggingLog::Log(L, aSetMySerialNum, v29 + 1);
              TCommunications_Handler::NotifyWindow(v5, COMM_UPDATE_PARAMS);
              TCommunications_Handler::NotifyWindow(v5, COMM_LAUNCH_GAME);
            }
            else
            {
              TDebuggingLog::Log(L, aGameNotYetStar);
            }
            if ( !v5->PlayerOptions.GameHasStarted && !v5->GTDSerialNo )
            {
              v30 = v5->Me;
              if ( v30 )
              {
                v31 = 2000 * v30 + 1;
                v5->GTDSerialNo = v31;
                TDebuggingLog::Log(L, aSerialWas0Sett, v31);
              }
            }
            TCommunications_Handler::UpdatePlayers(v5);
            TCommunications_Handler::NotifyWindow(v5, COMM_UPDATE_PARAMS);
          }
        }
        return;
      case 259:
        TCommunications_Handler::UpdatePlayers(v5);
        TDebuggingLog::Log(L, aSetPlayerOrGro);
        TCommunications_Handler::NotifyWindow(v5, COMM_UPDATE_PARAMS);
        return;
      case 263:
        TDebuggingLog::Log(L, aSecureMessageD);
        return;
      case 260:
        TDebuggingLog::Log(L, aSetSessinoDesc);
        return;
      case 264:
        TDebuggingLog::Log(L, aStartSessionMe);
        TDebuggingLog::Log(L, aNotice);
        return;
      default:
        break;
    }
LABEL_77:
    TDebuggingLog::Log(L, aCommUnknownSys, *(_DWORD *)CommBuff);
    return;
  }
  if ( *(_DWORD *)CommBuff == 33 )
  {
    TDebuggingLog::Log(L, aDeletePlayerOf);
    return;
  }
  if ( v7 == 3 )
  {
    v15 = *((_DWORD *)CommBuff + 2);
    dcoFromIDa = *((_DWORD *)CommBuff + 2);
    TDebuggingLog::Log(L, aRxNewPlrIdD, *((_DWORD *)CommBuff + 2));
    TDebuggingLog::Log(L, aCommCreatePlay);
    v16 = v5->TBuff;
    sprintf(v5->TBuff, aCreatePlayerRe, v5->MeHost, v5->PlayerOptions.ProgramState, v15);
    TDebuggingLog::Log(L, v5->TBuff);
    v17 = v5->PlayerOptions.ProgramState;
    if ( v17 == 5 || v5->current_turn > 6 )
    {
      *v16 = 73;
      TDebuggingLog::Log(L, aTxGipU1, *((_DWORD *)CommBuff + 2));
      TCommunications_Handler::FastSend(v5, *((_DWORD *)CommBuff + 2), v5->TBuff, 1u, 0, 0);
    }
    else if ( v5->MeHost )
    {
      v18 = 1;
      v19 = v5->MaxGamePlayers;
      if ( (unsigned __int16)v19 < 1u )
      {
LABEL_31:
        v18 = 0;
      }
      else
      {
        v20 = &v5->PlayerOptions.Humanity[1];
        while ( *v20 )
        {
          ++v18;
          ++v20;
          if ( v18 > v19 )
            goto LABEL_31;
        }
      }
      if ( v18 && v17 == 3 )
      {
        TCommunications_Handler::InitPlayerInformation(
          v5,
          v18,
          *((_DWORD *)CommBuff + 2),
          *((char **)CommBuff + 8),
          *((char **)CommBuff + 9));
        v5->PlayerOptions.dcoID[v18] = dcoFromIDa;
        v5->PlayerOptions.Humanity[v18] = 2;
        v5->PlayerOptions.NeedsToBeSent = 1;
        v5->PlayerOptions.InvalidPlayer[v18] = 0;
        TCommunications_Handler::CalculatePlayerRange(v5);
        TCommunications_Handler::UpdatePlayer(v5, v18, 1);
        v5->PlayerOptions.NeedsToBeSent = 1;
        v5->PlayerHighSerialNumber[v18] = 2000 * v18;
        TCommunications_Handler::ClearRXTXForPlayer(v5, v18);
        TCommunications_Handler::SendSharedData(v5, 0);
      }
      else
      {
        *v16 = 73;
        TDebuggingLog::Log(L, aTxGip2U1, *((_DWORD *)CommBuff + 2));
        TCommunications_Handler::FastSend(v5, *((_DWORD *)CommBuff + 2), v5->TBuff, 1u, 0, 0);
        TCommunications_Handler::UpdatePlayers(v5);
      }
    }
  }
  else
  {
    if ( v7 != 5 )
    {
      if ( v7 == 7 )
      {
LABEL_39:
        TDebuggingLog::Log(L, aAddDeletePlaye);
        return;
      }
      goto LABEL_77;
    }
    v8 = *((_DWORD *)CommBuff + 2);
    if ( v8
      && (v9 = v5->PlayerOptions.LowPlayerNumber,
          v10 = v5->PlayerOptions.HighPlayerNumber,
          (unsigned __int16)v9 <= (signed int)(unsigned __int16)v10) )
    {
      v11 = &v5->PlayerOptions.dcoID[v9];
      while ( *v11 != v8 )
      {
        ++v9;
        ++v11;
        if ( v9 > v10 )
          goto LABEL_14;
      }
      v12 = v9;
    }
    else
    {
LABEL_14:
      v12 = 0;
    }
    TDebuggingLog::Log(L, aDpmsg_destrpyp);
    TDebuggingLog::Log(L, aFromPlayerIdD, *((_DWORD *)CommBuff + 2));
    TDebuggingLog::Log(L, aEquatesToOurPl, v12);
    TDebuggingLog::Log(L, aProgramStateIs, v5->PlayerOptions.ProgramState);
    TDebuggingLog::FlushLog(L);
    if ( TCommunications_Handler::IsPlayerHuman(v5, v12) && !v5->PlayerStopTurn[v12] )
    {
      if ( v12 == v5->Me )
        TCommunications_Handler::NotifyWindow(v5, COMM_PLAYER_DROPPED);
      else
        TCommunications_Handler::NotifyWindowParam(v5, COMM_OTHER_PLAYER_DROPPED, v12);
    }
    if ( v5->MeHost )
    {
      v13 = v5->current_turn;
      v14 = *((_DWORD *)CommBuff + 2);
      kp.PlayerNo = v12;
      kp.dcoID = v14;
      kp.CurrentTurn = v13;
      TDebuggingLog::Log(L, aHostSendToAllD, v12, v14);
      TDebuggingLog::Log(L, aTxKp2DD, v12, 12);
      TCommunications_Handler::CommOut(v5, 0, 75, &kp, 12, 0);
      if ( v12 )
      {
        if ( !v5->PlayerStopTurn[kp.PlayerNo] )
          TCommunications_Handler::DropDeadPlayer(v5, v12, v8);
      }
    }
  }
}

//----- (00429760) --------------------------------------------------------
void __thiscall TCommunications_Handler::SendGroupChatMsg(TCommunications_Handler *this, char *Text)
{
  TCommunications_Handler *v2; // edi@1
  unsigned int v3; // esi@1
  bool v4; // cf@1
  char DestMap[10]; // [sp+8h] [bp-Ch]@1

  v2 = this;
  *(_DWORD *)DestMap = 1313754702;
  v3 = 1;
  v4 = this->MaxGamePlayers < 1u;
  *(_DWORD *)&DestMap[4] = 1313754702;
  *(_WORD *)&DestMap[8] = 20046;
  if ( !v4 )
  {
    do
    {
      if ( TChat::inChatGroup(v2->Chat, v3) )
        DestMap[v3] = 89;
      ++v3;
    }
    while ( v3 <= v2->MaxGamePlayers );
  }
  TCommunications_Handler::TXChat(v2, v2->Me, DestMap, Text);
}

//----- (004297D0) --------------------------------------------------------
void __thiscall TCommunications_Handler::SendChatMsgAll(TCommunications_Handler *this, char *Text)
{
  unsigned int v2; // edx@1
  char DestMap[10]; // [sp+0h] [bp-Ch]@1

  *(_DWORD *)DestMap = 1499027801;
  v2 = this->Me;
  *(_DWORD *)&DestMap[4] = 1499027801;
  *(_WORD *)&DestMap[8] = 22873;
  TCommunications_Handler::TXChat(this, v2, DestMap, Text);
}

//----- (00429810) --------------------------------------------------------
void __thiscall TCommunications_Handler::SendChatMsg(TCommunications_Handler *this, unsigned int GamerID, unsigned int DestPlayerNo, char *Text)
{
  TCommunications_Handler *v4; // esi@1
  char DestMap[10]; // [sp+10h] [bp-Ch]@1

  v4 = this;
  TDebuggingLog::Log(L, aSendchatmsgFro, GamerID, DestPlayerNo, Text);
  *(_DWORD *)DestMap = 1313754702;
  *(_DWORD *)&DestMap[4] = 1313754702;
  *(_WORD *)&DestMap[8] = 20046;
  DestMap[DestPlayerNo] = 89;
  TCommunications_Handler::TXChat(v4, GamerID, DestMap, Text);
}

//----- (00429870) --------------------------------------------------------
int __thiscall TCommunications_Handler::TXChat(TCommunications_Handler *this, unsigned int GamerID, char *DestMap, char *Text)
{
  TCommunications_Handler *v4; // ebp@1
  int result; // eax@2
  unsigned int v6; // eax@3
  unsigned int v7; // esi@5
  unsigned int v8; // ecx@14
  bool v9; // zf@16
  int v10; // esi@16
  MSGFORMAT_CHAT cht; // [sp+10h] [bp-114h]@8

  v4 = this;
  if ( this->Multiplayer )
  {
    v6 = this->MaxGamePlayers;
    if ( GamerID <= (unsigned __int16)v6 )
    {
      v7 = 1;
      if ( v6 >= 1 )
      {
        do
        {
          if ( TCommunications_Handler::IsPlayerHuman(v4, v7) && DestMap[v7] == 89 )
            cht.DestPlayers[v7] = 89;
          else
            cht.DestPlayers[v7] = 78;
          ++v7;
        }
        while ( v7 <= v4->MaxGamePlayers );
      }
      if ( cht.DestPlayers[v4->Me] == 89 )
      {
        TChat::AddChatMsg(v4->Chat, v4->FriendlyName[GamerID].Text, Text, 1);
        TDebuggingLog::Log(L, aLocalChatAddS, Text);
      }
      if ( strlen(Text) <= 0xFF )
        v8 = strlen(Text);
      else
        v8 = 255;
      cht.TextSize = v8;
      cht.FromGamerID = GamerID;
      strncpy(cht.ChatMsg, Text, v8 + 1);
      v9 = v4->PlayerOptions.ProgramState == 3;
      cht.ChatMsg[255] = 0;
      cht.Pregame = v9;
      TDebuggingLog::Log(L, aTxChatSD, Text, cht.TextSize + 22);
      v10 = TCommunications_Handler::CommOut(v4, 0, 67, &cht, cht.TextSize + 22, 0);
      RGE_Comm_Error::ShowReturn(v4->Err, v10, aTxchat);
      result = v10;
    }
    else
    {
      result = -2147467259;
    }
  }
  else
  {
    TChat::AddChatMsg(this->Chat, this->FriendlyName[GamerID].Text, Text, 1);
    TDebuggingLog::Log(L, aLocalChatSingl, Text);
    result = 0;
  }
  return result;
}

//----- (00429A30) --------------------------------------------------------
void __thiscall TCommunications_Handler::SendSpeedChange(TCommunications_Handler *this, unsigned int Frames, unsigned int Granularity)
{
  TCommunications_Handler *v3; // esi@1

  v3 = this;
  if ( this->MeHost )
  {
    if ( this->Multiplayer )
    {
      HIWORD(Frames) = Granularity;
      TDebuggingLog::Log(L, aTxKpSpdD, 4);
      TCommunications_Handler::CommOut(v3, 0, 83, &Frames, 4, 0);
    }
  }
}

//----- (00429A90) --------------------------------------------------------
void __thiscall TCommunications_Handler::SendIResignMsg(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  char v2; // al@2
  RGE_Communications_Speed *v3; // ecx@2
  char v4; // al@2
  unsigned int v5; // edx@2
  int v6; // ecx@2
  MSGFORMAT_ONTURN resign; // [sp+4h] [bp-10h]@2
  MSGFORMAT_ALL_DONE alldone; // [sp+8h] [bp-Ch]@2

  v1 = this;
  if ( this->Multiplayer )
  {
    resign.ExecuteOnTurn = this->PlayerOptions.CommandTurnIncrement + this->current_turn;
    TDebuggingLog::Log(L, aTxRsgnD, 4);
    TCommunications_Handler::CommOut(v1, 0, 81, &resign, 4, 0);
    v2 = RGE_Communications_Speed::GetHighLatencyCenti(v1->Speed);
    v3 = v1->Speed;
    alldone.HighLatencyCenti = v2;
    v4 = RGE_Communications_Speed::GetAvgFrameRate(v3);
    v5 = v1->current_turn;
    v6 = v1->PlayerOptions.CommandTurnIncrement;
    alldone.FrameRateMsec = v4;
    alldone.Command = 68;
    alldone.ExecuteOnTurn = v5 + v6 + 1;
    TDebuggingLog::Log(L, aTxDoneD, 12);
    TCommunications_Handler::CommOut(v1, 0, 68, &alldone, 12, 0);
    alldone.ExecuteOnTurn = v1->current_turn + v1->PlayerOptions.CommandTurnIncrement + 2;
    TDebuggingLog::Log(L, aTxDoneD, 12);
    TCommunications_Handler::CommOut(v1, 0, 68, &alldone, 12, 0);
    alldone.ExecuteOnTurn = v1->current_turn + v1->PlayerOptions.CommandTurnIncrement + 3;
    TDebuggingLog::Log(L, aTxDoneD, 12);
    TCommunications_Handler::CommOut(v1, 0, 68, &alldone, 12, 0);
  }
}

//----- (00429BD0) --------------------------------------------------------
unsigned int __thiscall TCommunications_Handler::HiTurnAcknowledged(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // edi@1
  signed int v2; // esi@1
  char *v3; // ebx@2

  v1 = this;
  HIWORD(v2) = 0;
  *(_DWORD *)&__S4__4__SendStoredMessages_TCommunications_Handler__QAEHXZ_4EA[4] = 0;
  LOWORD(v2) = this->PlayerOptions.LowPlayerNumber;
  if ( (unsigned __int16)v2 <= (signed int)this->PlayerOptions.HighPlayerNumber )
  {
    v3 = (char *)&this->LastTurnAck[v2];
    do
    {
      if ( TCommunications_Handler::IsPlayerHuman(v1, v2)
        && *(_DWORD *)v3 > *(_DWORD *)&__S4__4__SendStoredMessages_TCommunications_Handler__QAEHXZ_4EA[4] )
      {
        *(_DWORD *)&__S4__4__SendStoredMessages_TCommunications_Handler__QAEHXZ_4EA[4] = *(_DWORD *)v3;
      }
      ++v2;
      v3 += 4;
    }
    while ( v2 <= v1->PlayerOptions.HighPlayerNumber );
  }
  return *(_DWORD *)&__S4__4__SendStoredMessages_TCommunications_Handler__QAEHXZ_4EA[4];
}

//----- (00429C40) --------------------------------------------------------
int __thiscall TCommunications_Handler::AllPlayersAcknowledged(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // edi@1
  int result; // eax@2
  unsigned int v3; // esi@7
  char *v4; // ebx@8

  v1 = this;
  if ( this->Multiplayer )
  {
    if ( this->ShuttingDown )
    {
      result = 0;
    }
    else if ( this->PlayerOptions.ProgramState == 4 )
    {
      result = 0;
    }
    else
    {
      v3 = this->PlayerOptions.LowPlayerNumber;
      if ( (unsigned __int16)v3 > (unsigned int)this->PlayerOptions.HighPlayerNumber )
      {
        result = 1;
      }
      else
      {
        v4 = (char *)&this->LastTurnAck[v3];
        while ( !TCommunications_Handler::IsPlayerHuman(v1, v3) || *(_DWORD *)v4 >= v1->current_turn )
        {
          ++v3;
          v4 += 4;
          if ( v3 > v1->PlayerOptions.HighPlayerNumber )
            return 1;
        }
        result = 0;
      }
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00429CE0) --------------------------------------------------------
int __thiscall TCommunications_Handler::SendChecksumMessage(TCommunications_Handler *this, unsigned int worldtime, unsigned int random, int csum1, int csum2, int csum3, int csum4, int csum5)
{
  TCommunications_Handler *v8; // esi@1
  int v9; // edi@1
  unsigned int Msg; // [sp+8h] [bp-24h]@1
  unsigned int v12; // [sp+Ch] [bp-20h]@1
  unsigned int v13; // [sp+10h] [bp-1Ch]@1
  int v14; // [sp+14h] [bp-18h]@1
  int v15; // [sp+18h] [bp-14h]@1
  int v16; // [sp+1Ch] [bp-10h]@1
  int v17; // [sp+20h] [bp-Ch]@1
  int v18; // [sp+24h] [bp-8h]@1
  unsigned int v19; // [sp+28h] [bp-4h]@1

  v8 = this;
  Msg = worldtime;
  v12 = this->current_turn;
  v14 = csum1;
  v15 = csum2;
  v16 = csum3;
  v17 = csum4;
  v18 = csum5;
  v13 = random;
  v19 = debug_timeGetTime();
  TDebuggingLog::Log(L, aTxCksumD, 36);
  v9 = TCommunications_Handler::CommOut(v8, 0, 77, &Msg, 36, 0);
  RGE_Comm_Error::ShowReturn(v8->Err, v9, aSendchecksum);
  return v9;
}

//----- (00429D90) --------------------------------------------------------
unsigned int __thiscall TCommunications_Handler::ExecuteIncoming(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  unsigned int v2; // ebx@1
  unsigned int result; // eax@2
  unsigned int v4; // ebp@5
  unsigned int *v5; // edi@6
  HOLDER *v6; // ecx@9
  unsigned int v7; // ebp@9
  int v8; // eax@9
  unsigned int v9; // ecx@9
  int v10; // edx@10
  int v11; // edi@11
  HOLDER *v12; // edx@14
  HOLDER *v13; // edx@16
  int v14; // edi@16
  unsigned int i; // [sp+8h] [bp-Ch]@3
  unsigned int pno; // [sp+Ch] [bp-8h]@5
  int v17; // [sp+10h] [bp-4h]@6

  v1 = this;
  v2 = 0;
  if ( this->Multiplayer )
  {
    i = 0;
    do
    {
      if ( v1->OnHold[v2].Length )
      {
        v4 = 1;
        pno = 1;
        if ( v1->MaxGamePlayers >= 1u )
        {
          v5 = &v1->PlayerOptions.dcoID[1];
          v17 = (int)&v1->PlayerOptions.dcoID[1];
          do
          {
            if ( TCommunications_Handler::IsPlayerHuman(v1, v4) && v4 != v1->Me )
            {
              v6 = v1->OnHold;
              v7 = *(v5 - 15) + 1;
              v8 = (int)&v6[v2];
              v9 = v6[v2].Serial;
              if ( v9 < v7 )
              {
                v10 = *(_DWORD *)(v8 + 12);
                if ( v10 == *v5 )
                {
                  TDebuggingLog::Log(L, aClearingPastOn, i, v9, *(_DWORD *)(v8 + 8), v10, *(_DWORD *)(v8 + 16), v7);
                  v11 = (int)&v1->OnHold[v2];
                  if ( *(_DWORD *)v11 )
                    operator delete(*(void **)v11);
                  *(_DWORD *)v11 = 0;
                  *(_DWORD *)(v11 + 4) = 0;
                  *(_DWORD *)(v11 + 8) = 0;
                  *(_DWORD *)(v11 + 12) = 0;
                  *(_DWORD *)(v11 + 16) = 0;
                  v5 = (unsigned int *)v17;
                }
              }
              v12 = v1->OnHold;
              if ( v12[v2].Serial == v7 && v12[v2].dcoFromID == *v5 )
              {
                sprintf(v1->TBuff, aCachedExecuteD, v7, i);
                TDebuggingLog::Log(L, v1->TBuff);
                TCommunications_Handler::PreprocessMessages(
                  v1,
                  v1->OnHold[v2].Length,
                  v1->OnHold[v2].HoldMsg,
                  v1->OnHold[v2].dcoFromID,
                  v1->OnHold[v2].dcoReceiveID,
                  1);
                TDebuggingLog::Log(
                  L,
                  aClearingOnhold,
                  i,
                  v1->OnHold[v2].Length,
                  v1->OnHold[v2].dcoFromID,
                  v1->OnHold[v2].dcoReceiveID);
                v13 = v1->OnHold;
                v14 = (int)&v13[v2];
                if ( v13[v2].HoldMsg )
                  operator delete(v13[v2].HoldMsg);
                *(_DWORD *)v14 = 0;
                *(_DWORD *)(v14 + 4) = 0;
                *(_DWORD *)(v14 + 8) = 0;
                *(_DWORD *)(v14 + 12) = 0;
                *(_DWORD *)(v14 + 16) = 0;
                v5 = (unsigned int *)v17;
              }
              v4 = pno;
            }
            ++v4;
            ++v5;
            pno = v4;
            v17 = (int)v5;
          }
          while ( v4 <= v1->MaxGamePlayers );
        }
      }
      ++v2;
      ++i;
    }
    while ( v2 <= 501 );
    result = 0;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00429F80) --------------------------------------------------------
void __thiscall TCommunications_Handler::ClearAllSerialNumbers(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  unsigned int v2; // ecx@1
  int v3; // eax@1

  v1 = this;
  TDebuggingLog::Log(L, aClearedAllSeri);
  v2 = 0;
  v3 = (int)v1->LastSerialRequestedTX;
  do
  {
    *(_DWORD *)(v3 + 324) = 0;
    *(_DWORD *)v3 = 0;
    *(_DWORD *)(v3 + 40) = 0;
    *(_DWORD *)(v3 + 80) = 0;
    *(_DWORD *)(v3 + 120) = 0;
    ++v2;
    v3 += 4;
  }
  while ( v2 <= v1->MaxGamePlayers );
}

//----- (00429FD0) --------------------------------------------------------
void __thiscall TCommunications_Handler::ClearRXandTX(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // edi@1
  unsigned int v2; // ebp@1
  int v3; // esi@2
  unsigned int v4; // ebp@5
  RESENDER *v5; // esi@7
  int v6; // esi@7
  TCommunications_Handler *v7; // [sp+10h] [bp-4h]@1

  v1 = this;
  v7 = this;
  v2 = 0;
  do
  {
    v3 = (int)&v1->OnHold[v2];
    if ( *(_DWORD *)v3 )
      operator delete(*(void **)v3);
    ++v2;
    *(_DWORD *)v3 = 0;
    *(_DWORD *)(v3 + 4) = 0;
    *(_DWORD *)(v3 + 8) = 0;
    *(_DWORD *)(v3 + 12) = 0;
    *(_DWORD *)(v3 + 16) = 0;
  }
  while ( v2 < 501 );
  v4 = 0;
  while ( 1 )
  {
    v5 = v1->Resend;
    v5[v4].TimeSent = 0;
    v6 = (int)&v5[v4];
    if ( *(_DWORD *)(v6 + 8) )
      operator delete(*(void **)(v6 + 8));
    ++v4;
    *(_DWORD *)(v6 + 8) = 0;
    *(_DWORD *)(v6 + 4) = 0;
    *(_DWORD *)(v6 + 12) = 0;
    memset((void *)(v6 + 16), 0, 0x28u);
    if ( v4 >= 501 )
      break;
    v1 = v7;
  }
}

//----- (0042A060) --------------------------------------------------------
void __thiscall TCommunications_Handler::ClearRXForPlayer(TCommunications_Handler *this, unsigned int PlayerNo)
{
  TCommunications_Handler *v2; // ebx@1
  unsigned int v3; // edi@1
  int v4; // esi@2

  v2 = this;
  v3 = 0;
  do
  {
    v4 = (int)&v2->OnHold[v3];
    if ( *(_DWORD *)(v4 + 12) == v2->PlayerOptions.dcoID[PlayerNo] )
    {
      if ( *(_DWORD *)v4 )
        operator delete(*(void **)v4);
      *(_DWORD *)v4 = 0;
      *(_DWORD *)(v4 + 4) = 0;
      *(_DWORD *)(v4 + 8) = 0;
      *(_DWORD *)(v4 + 12) = 0;
      *(_DWORD *)(v4 + 16) = 0;
    }
    ++v3;
  }
  while ( v3 <= 501 );
}

//----- (0042A0C0) --------------------------------------------------------
int __thiscall TCommunications_Handler::CountWaitingMessages(TCommunications_Handler *this)
{
  int v1; // ebx@1
  int v2; // edi@1
  TCommunications_Handler *v3; // ebp@1
  unsigned int v4; // esi@1
  int v5; // eax@2
  int v6; // ecx@2

  v1 = 0;
  v2 = 0;
  v3 = this;
  v4 = 0;
  do
  {
    v5 = (int)&v3->Resend[v4];
    v6 = *(_DWORD *)(v5 + 4);
    if ( v6 )
    {
      TDebuggingLog::Log(
        L,
        aGtdSerDSlotDCm,
        v6,
        v2,
        **(_BYTE **)(v5 + 8),
        *(_DWORD *)(v5 + 12),
        *(_DWORD *)(v5 + 20),
        *(_DWORD *)(v5 + 24),
        *(_DWORD *)(v5 + 28),
        *(_DWORD *)(v5 + 32),
        *(_DWORD *)(v5 + 36),
        *(_DWORD *)(v5 + 40),
        *(_DWORD *)(v5 + 44),
        *(_DWORD *)(v5 + 48));
      ++v1;
    }
    ++v4;
    ++v2;
  }
  while ( v4 <= 501 );
  return v1;
}

//----- (0042A130) --------------------------------------------------------
void __thiscall TCommunications_Handler::ClearTXForPlayer(TCommunications_Handler *this, unsigned int PlayerNo)
{
  signed int v2; // edx@1
  unsigned int v3; // eax@1

  v2 = 502;
  v3 = 4 * PlayerNo + 16;
  do
  {
    v3 += 56;
    --v2;
    *(unsigned int *)((char *)&this->Resend[-1].TimeSent + v3) = 0;
  }
  while ( v2 );
}

//----- (0042A160) --------------------------------------------------------
void __thiscall TCommunications_Handler::ClearRXTXForPlayer(TCommunications_Handler *this, unsigned int PlayerNo)
{
  TCommunications_Handler *v2; // esi@1

  v2 = this;
  TCommunications_Handler::ClearTXForPlayer(this, PlayerNo);
  TCommunications_Handler::ClearRXForPlayer(v2, PlayerNo);
}

//----- (0042A180) --------------------------------------------------------
int __thiscall TCommunications_Handler::StoreIncoming(TCommunications_Handler *this, unsigned int SerialNumber, char *InBuff, unsigned int Length, unsigned int dcoFromID, unsigned int dcoReceiveID)
{
  TCommunications_Handler *v6; // edi@1
  HOLDER *v7; // ebp@3
  unsigned int v8; // ecx@3
  unsigned int *v9; // eax@3
  unsigned int v10; // esi@7
  unsigned int *v11; // eax@7
  int v12; // ebx@12
  int v13; // ebp@12
  char *v14; // eax@12
  int v16; // ebp@16
  unsigned int v17; // ebx@16
  char **v18; // eax@17
  char *v19; // esi@17
  TCommunications_Handler *v20; // [sp+10h] [bp-4h]@1

  v6 = this;
  v20 = this;
  if ( !Length )
    TDebuggingLog::Log(L, aStoreincomingC);
  v7 = v6->OnHold;
  v8 = 0;
  v9 = &v7->dcoFromID;
  do
  {
    if ( *(v9 - 2) == SerialNumber && *v9 == dcoFromID )
    {
      TDebuggingLog::Log(L, aFutureSerDPrev, SerialNumber, v8);
      return 1;
    }
    ++v8;
    v9 += 6;
  }
  while ( v8 <= 0x1F5 );
  v10 = 0;
  v11 = &v7->Length;
  while ( *v11 || !Length )
  {
    ++v10;
    v11 += 6;
    if ( v10 >= 0x1F5 )
    {
      TDebuggingLog::Log(L, aDidNotStore);
      if ( v10 > 0x1EB )
      {
        TDebuggingLog::Log(L, aHoldFullWarnin, v10);
        v16 = 0;
        v17 = 0;
        do
        {
          v18 = &v6->OnHold[v17].HoldMsg;
          v19 = v18[2];
          if ( v19 )
            TDebuggingLog::Log(L, aSDSerDFromidDL, v16, v18[1], v18[3], v19, **v18, **v18, (*v18)[1]);
          ++v17;
          ++v16;
        }
        while ( v17 < 501 );
      }
      return 1;
    }
  }
  v12 = v10;
  v7[v10].Length = Length;
  v13 = (int)&v6->OnHold[v10];
  v14 = (char *)operator new(*(_DWORD *)(v13 + 8));
  *(_DWORD *)v13 = v14;
  if ( v14 )
  {
    qmemcpy(v14, InBuff, *(_DWORD *)(v13 + 8));
    v6 = v20;
    *(_DWORD *)(v13 + 8) = Length;
  }
  v6->OnHold[v12].Serial = SerialNumber;
  v6->OnHold[v12].dcoFromID = dcoFromID;
  v6->OnHold[v12].dcoReceiveID = dcoReceiveID;
  return 1;
}

//----- (0042A330) --------------------------------------------------------
int __thiscall TCommunications_Handler::StoreForResend(TCommunications_Handler *this, unsigned int SerialNumber, char *OutCommBuff, unsigned int Length, unsigned int *ResendDestMap)
{
  TCommunications_Handler *v5; // ebx@1
  int result; // eax@3
  int v7; // ebp@4
  unsigned int v8; // esi@4
  RESENDER *v9; // ecx@5
  unsigned int v10; // edx@5
  int v11; // eax@6
  int v12; // edi@9
  RESENDER *v13; // edx@10
  int v14; // esi@10
  char *v15; // eax@10
  unsigned int v16; // esi@12
  unsigned int *v17; // ebp@13
  int v18; // edi@13
  int v19; // [sp+10h] [bp-8h]@9
  int v20; // [sp+14h] [bp-4h]@10

  v5 = this;
  if ( this->Multiplayer )
  {
    if ( this->RGE_Guaranteed_Delivery )
    {
      v7 = 0;
      v8 = 0;
      while ( 1 )
      {
        v9 = v5->Resend;
        v10 = v9[v8].Serial;
        if ( !v10 )
          break;
        v11 = (int)&v9[v8];
        TDebuggingLog::Log(
          L,
          aQueueHasSerDSl,
          v10,
          v7,
          **(_BYTE **)(v11 + 8),
          **(_BYTE **)(v11 + 8),
          *(_DWORD *)(v11 + 12),
          *(_DWORD *)(v11 + 20),
          *(_DWORD *)(v11 + 24),
          *(_DWORD *)(v11 + 28),
          *(_DWORD *)(v11 + 32),
          *(_DWORD *)(v11 + 36),
          *(_DWORD *)(v11 + 40),
          *(_DWORD *)(v11 + 44),
          *(_DWORD *)(v11 + 48));
        ++v8;
        ++v7;
        if ( v8 >= 501 )
        {
          TDebuggingLog::Log(L, aResendBufferFi, v7);
          goto LABEL_8;
        }
      }
      v12 = v7;
      v19 = v12 * 56;
      v5->Resend[v12].Length = Length;
      if ( Length )
      {
        v13 = v5->Resend;
        v14 = (int)&v13[v12];
        v20 = (int)&v13[v12];
        v15 = (char *)operator new(v13[v12].Length);
        *(_DWORD *)(v14 + 8) = v15;
        if ( v15 )
        {
          qmemcpy(v15, OutCommBuff, *(_DWORD *)(v14 + 12));
          *(_DWORD *)(v20 + 12) = Length;
        }
      }
      v5->Resend[v12].Serial = SerialNumber;
      qmemcpy(v5->Resend[v12].DestMap, ResendDestMap, 4 * v5->MaxGamePlayers + 4);
      TDebuggingLog::Log(L, aStoredDbForRes, Length, v7, SerialNumber, v5->MaxGamePlayers);
      v16 = 1;
      if ( v5->MaxGamePlayers >= 1u )
      {
        v17 = ResendDestMap + 1;
        v18 = v12 * 56 + 20;
        do
        {
          if ( *(unsigned int *)((char *)&v5->Resend->TimeSent + v18) )
            TDebuggingLog::Log(L, aToPDRetriesD, v16, *v17);
          ++v16;
          v18 += 4;
          ++v17;
        }
        while ( v16 <= v5->MaxGamePlayers );
      }
      *(unsigned int *)((char *)&v5->Resend->TimeSent + v19) = debug_timeGetTime();
      result = 1;
    }
    else
    {
      TDebuggingLog::Log(L, aRgegtdStore);
      result = 0;
    }
  }
  else
  {
LABEL_8:
    result = 0;
  }
  return result;
}

//----- (0042A540) --------------------------------------------------------
int __thiscall TCommunications_Handler::TXAcknowledgeMessage(TCommunications_Handler *this, unsigned int serialno, unsigned int fromPlayer)
{
  TCommunications_Handler *v3; // esi@1
  int result; // eax@2
  _DWORD *v5; // edi@3
  unsigned int v6; // ebx@5
  int v7; // ebp@5
  unsigned int v8; // eax@5

  v3 = this;
  if ( this->RGE_Guaranteed_Delivery )
  {
    v5 = operator new(8u);
    *(_BYTE *)v5 = 65;
    v5[1] = serialno;
    if ( dcoID )
    {
      v6 = debug_timeGetTime();
      v7 = ((int (__stdcall *)(IDirectPlay3 *, unsigned int, unsigned int, _DWORD, _DWORD *, signed int))glpIDC->vfptr[8].Release)(
             glpIDC,
             dcoID,
             v3->PlayerOptions.dcoID[fromPlayer],
             0,
             v5,
             8);
      v8 = debug_timeGetTime() - v6;
      if ( v8 > 0x32 )
        TDebuggingLog::Log(L, aTxacknowledgem, v8);
      v3->TXPacketLength += 8;
      operator delete(v5);
      if ( v7 )
      {
        RGE_Comm_Error::ShowReturn(v3->Err, v7, aGtdAck);
        result = 0;
      }
      else
      {
        result = 1;
      }
    }
    else
    {
      TDebuggingLog::Log(L, aBadDcoid0NoTx);
      result = 0;
    }
  }
  else
  {
    TDebuggingLog::Log(L, aRgegtdAck);
    result = 0;
  }
  return result;
}

//----- (0042A650) --------------------------------------------------------
int __thiscall TCommunications_Handler::RXAcknowledgeStoredMessage(TCommunications_Handler *this, unsigned int serialno, unsigned int fromPlayer)
{
  TCommunications_Handler *v3; // edi@1
  int result; // eax@2
  unsigned int v5; // edx@3
  unsigned int v6; // esi@3
  RESENDER *v7; // eax@4
  unsigned int v8; // ecx@4

  v3 = this;
  if ( this->RGE_Guaranteed_Delivery )
  {
    TDebuggingLog::Log(L, aCommRxAckFromP, fromPlayer, serialno);
    v3->WaitingForAck = 0;
    v5 = 0;
    v6 = 4 * fromPlayer + 16;
    do
    {
      v7 = v3->Resend;
      v8 = v7[v5].Serial;
      if ( v8 == serialno )
      {
        if ( v8 )
          *(unsigned int *)((char *)&v7->TimeSent + v6) = 0;
      }
      ++v5;
      v6 += 56;
    }
    while ( v5 <= 501 );
    result = 1;
  }
  else
  {
    TDebuggingLog::Log(L, aRgegtdRxack);
    result = 0;
  }
  return result;
}

//----- (0042A6E0) --------------------------------------------------------
int __thiscall TCommunications_Handler::PurgeAcknowledgedStoredMessages(TCommunications_Handler *this)
{
  int v1; // ebp@1
  unsigned int v2; // edi@1
  TCommunications_Handler *v3; // ebx@1
  unsigned int j; // esi@3
  int v5; // esi@9
  void *v6; // eax@9
  signed int v7; // ecx@13
  unsigned int *v8; // eax@13
  unsigned int NonAckCount; // [sp+10h] [bp-Ch]@2
  unsigned int i; // [sp+14h] [bp-8h]@1
  signed int v12; // [sp+18h] [bp-4h]@1

  v1 = 0;
  v2 = 4;
  v3 = this;
  i = 0;
  v12 = 4;
  do
  {
    NonAckCount = 0;
    if ( v3->Resend[v1].Serial )
    {
      for ( j = 1; j <= v3->MaxGamePlayers; ++j )
      {
        if ( TCommunications_Handler::IsPlayerHuman(v3, j) && *(&v3->Resend->TimeSent + j + v2) )
          ++NonAckCount;
      }
      if ( !NonAckCount )
      {
        TDebuggingLog::Log(L, aGtdSerDSlotDAc, v3->Resend[v1].Serial, i);
        v5 = (int)&v3->Resend[v1];
        v6 = *(void **)(v5 + 8);
        *(_DWORD *)v5 = 0;
        if ( v6 )
          operator delete(v6);
        *(_DWORD *)(v5 + 8) = 0;
        *(_DWORD *)(v5 + 4) = 0;
        *(_DWORD *)(v5 + 12) = 0;
        memset((void *)(v5 + 16), 0, 0x28u);
        v2 = v12;
      }
    }
    v2 += 14;
    ++v1;
    ++i;
    v12 = v2;
  }
  while ( v2 <= 0x1B6A );
  v7 = 502;
  v8 = &v3->Resend->Serial;
  do
  {
    if ( *v8 )
      ++v3->WaitingForAck;
    v8 += 14;
    --v7;
  }
  while ( v7 );
  return 1;
}

//----- (0042A800) --------------------------------------------------------
unsigned int __thiscall TCommunications_Handler::SendStoredMessages(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  unsigned int v2; // eax@5
  unsigned int v3; // edi@5
  unsigned int *v5; // ebp@7
  unsigned int v6; // ebx@7
  _DWORD *v7; // ecx@7
  int v8; // eax@11
  int v9; // edx@12
  unsigned int v10; // eax@26
  int v11; // ebp@30
  unsigned int v12; // edi@30
  int v13; // ebx@31
  unsigned int *v14; // eax@36
  int v15; // ST20_4@38
  unsigned int v16; // eax@38
  unsigned int v17; // ebx@39
  unsigned int v18; // eax@39
  unsigned int *v19; // eax@42
  unsigned int v20; // edx@42
  char *v21; // eax@48
  unsigned int items; // [sp+18h] [bp-20h]@7
  unsigned int *itemsa; // [sp+18h] [bp-20h]@31
  unsigned int OldestMessageElapsed; // [sp+1Ch] [bp-1Ch]@7
  unsigned int OldestMessageSlot; // [sp+20h] [bp-18h]@7
  int v26; // [sp+24h] [bp-14h]@7
  int v27; // [sp+24h] [bp-14h]@31
  int hr; // [sp+2Ch] [bp-Ch]@5
  int hra; // [sp+2Ch] [bp-Ch]@39
  MSGFORMAT_MISSING_PLAYER m; // [sp+30h] [bp-8h]@50

  v1 = this;
  if ( !this->RGE_Guaranteed_Delivery )
  {
    TDebuggingLog::Log(L, aRgegtdSendstor);
    return 0;
  }
  if ( !(__S4__4__SendStoredMessages_TCommunications_Handler__QAEHXZ_4EA[0] & 1) )
  {
    __S4__4__SendStoredMessages_TCommunications_Handler__QAEHXZ_4EA[0] |= 1u;
    lastResendTime = debug_timeGetTime();
  }
  v2 = debug_timeGetTime();
  v3 = 0;
  hr = v2;
  if ( (double)lastResendBytes / (double)(signed int)(v2 - lastResendTime) > 2.0 )
    return 0;
  lastResendTime = v2;
  lastResendBytes = 0;
  OldestMessageElapsed = 0;
  OldestMessageSlot = 0;
  items = 0;
  TCommunications_Handler::PurgeAcknowledgedStoredMessages(v1);
  v5 = &v1->Resend->TimeSent;
  v6 = 0;
  v7 = v5 + 5;
  v26 = (int)(v5 + 5);
  do
  {
    if ( *(v7 - 4) )
    {
      ++items;
      if ( hr - *v5 > OldestMessageElapsed )
      {
        OldestMessageElapsed = hr - *v5;
        OldestMessageSlot = v3;
      }
      v8 = v1->MaxGamePlayers;
      if ( (unsigned __int16)v8 >= 1u )
      {
        v9 = v1->MaxGamePlayers;
        do
        {
          if ( 240 - *v7 > v6 )
            v6 = 240 - *v7;
          ++v7;
          --v9;
        }
        while ( v9 );
        v7 = (_DWORD *)v26;
      }
    }
    ++v3;
    v5 += 14;
    v7 += 14;
    v26 = (int)v7;
  }
  while ( v3 <= 0x1F5 );
  if ( !items )
    return 0;
  if ( v1->current_turn > 6 )
  {
    if ( v1->ShuttingDown )
    {
      if ( OldestMessageElapsed < 0xFA )
        return 0;
    }
    else
    {
      v10 = resend_adj2 + 2 * v1->Speed->HighestLatencyMsec;
      if ( resend_adj1 + 500 > v10 )
        v10 = resend_adj1 + 500;
      if ( OldestMessageElapsed < v10 )
        return 0;
    }
  }
  else if ( OldestMessageElapsed < 0x7D0 )
  {
    return 0;
  }
  v11 = OldestMessageSlot;
  v12 = 1;
  v1->Resend[OldestMessageSlot].TimeSent = debug_timeGetTime();
  if ( v1->MaxGamePlayers < 1u )
    return v1->ResentToOther;
  v13 = v11 * 56 + 20;
  v27 = v11 * 56 + 20;
  itemsa = &v1->PlayerOptions.dcoID[1];
  while ( !*(unsigned int *)((char *)&v1->Resend->TimeSent + v13)
       || !TCommunications_Handler::IsPlayerHuman(v1, v12)
       || !*itemsa
       || v12 == v1->Me )
  {
LABEL_51:
    ++v12;
    ++itemsa;
    v13 = v27 + 4;
    v27 += 4;
    if ( v12 > v1->MaxGamePlayers )
      return v1->ResentToOther;
  }
  v14 = (unsigned int *)((char *)&v1->Resend->TimeSent + v13);
  if ( *v14 )
    --*v14;
  v15 = *(unsigned int *)((char *)&v1->Resend->TimeSent + v13);
  v16 = debug_timeGetTime();
  TDebuggingLog::Log(
    L,
    aResendingDToPD,
    OldestMessageSlot,
    v12,
    *itemsa,
    v1->Resend[v11].Length,
    OldestMessageElapsed,
    v16,
    v15);
  if ( dcoID )
  {
    v17 = debug_timeGetTime();
    TDebuggingLog::Log(L, aTxStorDDD, v12, OldestMessageSlot, v1->Resend[v11].Length);
    hra = ((int (__stdcall *)(IDirectPlay3 *, unsigned int, unsigned int, _DWORD, char *, unsigned int))glpIDC->vfptr[8].Release)(
            glpIDC,
            dcoID,
            *itemsa,
            0,
            v1->Resend[v11].ResendMsg,
            v1->Resend[v11].Length);
    v18 = debug_timeGetTime() - v17;
    if ( v18 > 0x32 )
      TDebuggingLog::Log(L, aSendstoredmess, v18);
    if ( hra )
    {
      RGE_Comm_Error::ShowReturn(v1->Err, hra, aResendTransmit);
    }
    else
    {
      v19 = &v1->Resend[v11].Length;
      v20 = v1->TXPacketLength;
      ++v1->ResentToOther;
      v1->TXPacketLength = *v19 + v20;
      lastResendBytes += *v19;
      TDebuggingLog::Log(L, aCommResentTxSe, v1->Resend[v11].Serial, v12, v1->Resend[v11].Length);
    }
    if ( !*(unsigned int *)((char *)&v1->Resend->TimeSent + v27)
      && TCommunications_Handler::IsPlayerHuman(v1, v12)
      && *itemsa
      && v12 != v1->Me )
    {
      v21 = TCommunications_Handler::GetPlayerName(v1, v12);
      sprintf(v1->TBuff, aMaxResendsToPl, v12, v21);
      TDebuggingLog::Log(L, v1->TBuff);
      if ( v1->MeHost )
      {
        TDebuggingLog::Log(L, aHostRcvdMaxTxF, v12);
        *(itemsa - 50) = 1;
        TCommunications_Handler::Kick(v1, v12);
      }
      else
      {
        m.PlayerID = *itemsa;
        TDebuggingLog::Log(L, aTxMissingPlaye, m.PlayerID);
        m.Command = 63;
        TDebuggingLog::Log(L, aTxMpD, 8);
        TCommunications_Handler::FastSend(v1, 0, &m, 8u, 0, 0);
      }
    }
    goto LABEL_51;
  }
  TDebuggingLog::Log(L, aBadDcoid0NoTx);
  return 0;
}
// 62CF08: using guessed type int resend_adj1;
// 62CF0C: using guessed type int resend_adj2;

//----- (0042AD10) --------------------------------------------------------
int __thiscall TCommunications_Handler::TXResendReply(TCommunications_Handler *this, unsigned int serial, unsigned int toPlayer)
{
  TCommunications_Handler *v3; // esi@1
  int result; // eax@2
  unsigned int v5; // ebx@3
  unsigned int v6; // edi@3
  unsigned int v7; // eax@7
  unsigned int v8; // ebp@7
  unsigned int v9; // edx@8
  unsigned int v10; // eax@11
  void *v11; // eax@12
  RESENDER *v12; // ecx@12
  unsigned int v13; // ebp@13
  unsigned int v14; // eax@13
  RESENDER *v15; // ebp@18
  int v16; // ST44_4@18
  unsigned int v17; // eax@18
  unsigned int v18; // edx@23
  unsigned int BadTransmitCount; // [sp+18h] [bp-18h]@10
  unsigned int i; // [sp+1Ch] [bp-14h]@10
  unsigned int GoodTransmitCount; // [sp+20h] [bp-10h]@10
  int hr; // [sp+24h] [bp-Ch]@13
  MSGFORMAT_RESEND nosuch; // [sp+28h] [bp-8h]@12
  unsigned int toPlayera; // [sp+38h] [bp+8h]@10

  v3 = this;
  if ( this->RGE_Guaranteed_Delivery )
  {
    v5 = toPlayer;
    v6 = 0;
    if ( this->PlayerOptions.dcoID[toPlayer] )
    {
      if ( dcoID )
      {
        v7 = debug_timeGetTime();
        v8 = serial;
        if ( serial != v3->LastSerialRepliedTX[toPlayer] || (v9 = v3->LastRequestRepliedTX[toPlayer], v7 - v9 >= 0x1F4) )
        {
          v3->LastSerialRepliedTX[toPlayer] = serial;
          v3->LastRequestRepliedTX[toPlayer] = v7;
          GoodTransmitCount = 0;
          BadTransmitCount = 0;
          i = 0;
          toPlayera = 4 * toPlayer + 16;
          do
          {
            v10 = v3->Resend[v6].Serial;
            if ( v10 == v8 )
            {
              sprintf(v3->TBuff, aFoundResendSer, v10, v5);
              TDebuggingLog::Log(L, v3->TBuff);
              v11 = operator new(v3->Resend[v6].Length);
              v12 = v3->Resend;
              *(_DWORD *)&nosuch.Command = v11;
              --*(unsigned int *)((char *)&v12->TimeSent + toPlayera);
              if ( !dcoID )
              {
                TDebuggingLog::Log(L, aBadDcoid0NoTx);
                goto LABEL_27;
              }
              v13 = debug_timeGetTime();
              TDebuggingLog::Log(L, aTxResRepDDD, v5, serial, v3->Resend[v6].Length);
              hr = ((int (__stdcall *)(IDirectPlay3 *, unsigned int, unsigned int, _DWORD, char *, unsigned int))glpIDC->vfptr[8].Release)(
                     glpIDC,
                     dcoID,
                     v3->PlayerOptions.dcoID[v5],
                     0,
                     v3->Resend[v6].ResendMsg,
                     v3->Resend[v6].Length);
              v14 = debug_timeGetTime() - v13;
              if ( v14 > 0x32 )
                TDebuggingLog::Log(L, aTxresendreplyS, v14);
              if ( hr )
              {
                RGE_Comm_Error::ShowReturn(v3->Err, hr, aResendTx);
                ++BadTransmitCount;
              }
              else
              {
                ++GoodTransmitCount;
                v3->TXPacketLength += v3->Resend[v6].Length;
              }
              v15 = v3->Resend;
              v16 = *v15[v6].ResendMsg;
              v17 = debug_timeGetTime();
              TDebuggingLog::Log(
                L,
                aCommRetransmit,
                v5,
                v15[v6].Serial,
                i,
                v16,
                v16,
                v15[v6].Length,
                *(unsigned int *)((char *)&v15->TimeSent + toPlayera),
                v17);
              operator delete(*(void **)&nosuch.Command);
              v8 = serial;
            }
            ++v6;
            ++i;
            toPlayera += 56;
          }
          while ( v6 <= 501 );
          if ( GoodTransmitCount || BadTransmitCount )
          {
            TDebuggingLog::Log(
              L,
              aResendToPDFulf,
              v5,
              GoodTransmitCount,
              BadTransmitCount,
              BadTransmitCount + GoodTransmitCount);
          }
          else if ( v3->PlayerOptions.ProgramState == 3 )
          {
            TDebuggingLog::Log(L, aDidNotHaveRequ, v8, v5);
            v18 = v3->GTDSerialNo - 1;
            nosuch.Command = 89;
            nosuch.Serialno = v18;
            TDebuggingLog::Log(L, aTxRnsmDDD, v5, v8, 8);
            TCommunications_Handler::FastSend(v3, v3->PlayerOptions.dcoID[v5], &nosuch, 8u, 0, 0);
            TDebuggingLog::Log(L, aTxNoSuchMessag, v8);
            TCommunications_Handler::ClearTXForPlayer(v3, v5);
          }
          TCommunications_Handler::PurgeAcknowledgedStoredMessages(v3);
          result = 1;
        }
        else
        {
          TDebuggingLog::Log(L, aResReplyTooSoo, serial, v7 - v9);
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
      TDebuggingLog::Log(L, aInvalidPlayerR);
LABEL_27:
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0042B0A0) --------------------------------------------------------
int __thiscall TCommunications_Handler::TXResendRequest(TCommunications_Handler *this, unsigned int serial, unsigned int toPlayer)
{
  TCommunications_Handler *v3; // edi@1
  unsigned int v4; // eax@2
  unsigned int v5; // esi@2
  _DWORD *v6; // ebp@4
  int result; // eax@5
  int v8; // esi@6
  unsigned int v9; // eax@6
  unsigned int toPlayera; // [sp+18h] [bp+8h]@6

  v3 = this;
  if ( !this->RGE_Guaranteed_Delivery )
    goto LABEL_13;
  v4 = debug_timeGetTime();
  v5 = toPlayer;
  if ( serial == v3->LastSerialRequestedTX[toPlayer] && v4 - v3->LastRequestHonoredTX[toPlayer] < 0x1F4 )
    goto LABEL_13;
  v3->LastSerialRequestedTX[toPlayer] = serial;
  v3->LastRequestHonoredTX[toPlayer] = v4;
  v6 = operator new(8u);
  *(_BYTE *)v6 = 88;
  v6[1] = serial;
  TDebuggingLog::Log(L, aGtdTxResendReq, toPlayer, serial);
  if ( !dcoID )
  {
    TDebuggingLog::Log(L, aBadDcoid0NoTx);
    return 0;
  }
  toPlayera = debug_timeGetTime();
  TDebuggingLog::Log(L, aTxResReqDDD, v5, serial, 8);
  v8 = ((int (__stdcall *)(IDirectPlay3 *, unsigned int, unsigned int, _DWORD, _DWORD *, signed int))glpIDC->vfptr[8].Release)(
         glpIDC,
         dcoID,
         v3->PlayerOptions.dcoID[v5],
         0,
         v6,
         8);
  v9 = debug_timeGetTime() - toPlayera;
  if ( v9 > 0x32 )
    TDebuggingLog::Log(L, aGetnextsequenc, v9);
  operator delete(v6);
  if ( v8 )
  {
LABEL_13:
    result = 0;
  }
  else
  {
    v3->TXPacketLength += 8;
    result = 1;
  }
  return result;
}

//----- (0042B200) --------------------------------------------------------
unsigned __int8 __thiscall TCommunications_Handler::GetNextSequence(TCommunications_Handler *this, unsigned int ThisTurn)
{
  unsigned __int8 result; // al@2

  if ( ThisTurn == LastCurrentTurn )
  {
    result = Sequence[0]++ + 1;
    if ( Sequence[0] < 0xFFu )
    {
      if ( this->PlayerOptions.ProgramState == 4 && result > 0x64u )
      {
        Sequence[0] = 100;
        result = 100;
      }
    }
    else
    {
      TDebuggingLog::Log(L, aTooManyCommand, (unsigned __int8)Sequence[0]);
      result = 0;
    }
  }
  else
  {
    LastCurrentTurn = ThisTurn;
    Sequence[0] = 1;
    result = 1;
  }
  return result;
}

//----- (0042B270) --------------------------------------------------------
int __thiscall TCommunications_Handler::CommOut(TCommunications_Handler *this, unsigned int To, char MsgType, void *Msg, int Length, char ResendSeq)
{
  TCommunications_Handler *v6; // ebp@1
  unsigned int v7; // esi@1
  MSGFORMAT_HEADER_GUARANTEED *v9; // ebx@7
  signed int v10; // eax@13
  unsigned int *v11; // edi@17
  unsigned __int8 v12; // al@27
  MSGFORMAT_HEADER_GUARANTEED *v13; // eax@31
  unsigned int v14; // ebx@33
  unsigned int v15; // esi@33
  unsigned int *v16; // edi@33
  unsigned int v17; // esi@45
  unsigned int v18; // edi@45
  int v19; // ebx@45
  unsigned int v20; // eax@45
  unsigned int i; // esi@48
  RGE_Comm_Error *v22; // ecx@57
  unsigned int v23; // edi@61
  unsigned int v24; // esi@61
  unsigned int v25; // eax@61
  unsigned int j; // esi@64
  const char *v27; // edi@75
  int v28; // esi@77
  int v29; // edi@77
  unsigned int v30; // eax@77
  int FullLength; // [sp+18h] [bp-24h]@15
  signed int HeaderLength; // [sp+1Ch] [bp-20h]@13
  MSGFORMAT_HEADER_GUARANTEED *txMsg; // [sp+20h] [bp-1Ch]@7
  char *OutCommBuff; // [sp+24h] [bp-18h]@31
  unsigned int OutgoingCount; // [sp+28h] [bp-14h]@39
  int SyncTurn; // [sp+2Ch] [bp-10h]@17
  char GTDString[10]; // [sp+30h] [bp-Ch]@77

  v6 = this;
  v7 = 0;
  if ( !this->Multiplayer )
    return 0;
  if ( !glpIDC )
    return 0;
  if ( !this->GTDSerialNo )
  {
    TDebuggingLog::Log(L, aSerNotSetNoTra);
    return 0;
  }
  v9 = (MSGFORMAT_HEADER_GUARANTEED *)operator new(0xCu);
  txMsg = v9;
  if ( MsgType == 49 || MsgType == 50 || MsgType == 63 || MsgType == 65 )
    TDebuggingLog::Log(L, aBadMsgTypeAsse);
  if ( v6->RGE_Guaranteed_Delivery )
  {
    v9->Serialno = v6->GTDSerialNo;
    v6->PlayerHighSerialNumber[v6->Me] = v6->GTDSerialNo++;
    v10 = 12;
    HeaderLength = 12;
  }
  else
  {
    HeaderLength = 8;
    v9->Serialno = 0;
    v10 = 8;
  }
  FullLength = v10 + Length;
  if ( (unsigned int)(v10 + Length) > 0xFA0 )
    TDebuggingLog::Log(L, aErrorFullLengt, 4000, v10, Length);
  v9->Sequence = 0;
  v9->Command = 0;
  v11 = v6->DestMap;
  SyncTurn = v6->PlayerOptions.CommandTurnIncrement + v6->current_turn;
  v9->ExecuteOnTurn = SyncTurn;
  do
  {
    if ( TCommunications_Handler::IsPlayerHuman(v6, v7) && v7 != v6->Me )
      *v11 = 240;
    else
      *v11 = 0;
    ++v7;
    ++v11;
  }
  while ( v7 <= v6->MaxGamePlayers );
  if ( MsgType == 49 || MsgType == 50 || MsgType == 63 || MsgType == 65 )
  {
    TDebuggingLog::Log(L, aAssertBadMsgTy);
  }
  else
  {
    v12 = TCommunications_Handler::GetNextSequence(v6, SyncTurn);
    v9->Sequence = v12;
    if ( v6->PlayerOptions.ProgramState != 5 && !v12 )
    {
      operator delete(v9);
      return -2005466866;
    }
  }
  v9->Command = MsgType;
  v13 = (MSGFORMAT_HEADER_GUARANTEED *)operator new(FullLength + 1);
  qmemcpy(v13, v9, HeaderLength);
  OutCommBuff = (char *)v13;
  if ( Length )
    qmemcpy((char *)v13 + HeaderLength, Msg, Length);
  v14 = 0;
  v15 = 0;
  v16 = v6->DestMap;
  do
  {
    if ( TCommunications_Handler::IsPlayerHuman(v6, v15) && v15 != v6->Me )
    {
      *v16 = 240;
      ++v14;
    }
    else
    {
      *v16 = 0;
    }
    ++v15;
    ++v16;
  }
  while ( v15 <= v6->MaxGamePlayers );
  OutgoingCount = v14;
  if ( v6->RGE_Guaranteed_Delivery )
  {
    if ( !FullLength )
    {
      TDebuggingLog::Log(L, aDamagedMsg0b);
      return -2147467259;
    }
    if ( v14 )
    {
      if ( !dcoID )
      {
        TDebuggingLog::Log(L, aBadDcoid0NoTx);
        --v6->GTDSerialNo;
        return -2147467259;
      }
      v17 = debug_timeGetTime();
      v18 = To;
      v19 = ((int (__stdcall *)(IDirectPlay3 *, unsigned int, unsigned int, _DWORD, char *, int))glpIDC->vfptr[8].Release)(
              glpIDC,
              dcoID,
              To,
              0,
              OutCommBuff,
              FullLength);
      v20 = debug_timeGetTime() - v17;
      if ( v20 > 0x32 )
        TDebuggingLog::Log(L, aCommoutSlowLdM, v20);
      if ( To )
      {
        v18 = 1;
      }
      else
      {
        for ( i = 1; i <= v6->MaxGamePlayers; ++i )
        {
          if ( TCommunications_Handler::IsPlayerHuman(v6, i) && i != v6->Me )
            ++v18;
        }
      }
      if ( v19 )
      {
        v22 = v6->Err;
        --v6->GTDSerialNo;
        RGE_Comm_Error::ShowReturn(v22, v19, aTxRgtgtd);
      }
      else
      {
        v6->TXPacketLength += FullLength * v18;
        TCommunications_Handler::StoreForResend(v6, txMsg->Serialno, OutCommBuff, FullLength, v6->DestMap);
      }
      goto LABEL_74;
    }
    goto LABEL_73;
  }
  if ( !v14 )
  {
LABEL_73:
    v19 = 0;
    goto LABEL_74;
  }
  if ( !dcoID )
  {
    TDebuggingLog::Log(L, aBadDcoid0NoTx);
    return -2147467259;
  }
  v23 = To;
  v24 = debug_timeGetTime();
  v19 = ((int (__stdcall *)(IDirectPlay3 *, unsigned int, unsigned int, _DWORD, char *, int))glpIDC->vfptr[8].Release)(
          glpIDC,
          dcoID,
          To,
          0,
          OutCommBuff,
          FullLength);
  v25 = debug_timeGetTime() - v24;
  if ( v25 > 0x32 )
    TDebuggingLog::Log(L, aCommout2SlowLd, v25);
  if ( To )
  {
    v23 = 1;
  }
  else
  {
    for ( j = 1; j <= v6->MaxGamePlayers; ++j )
    {
      if ( TCommunications_Handler::IsPlayerHuman(v6, j) && j != v6->Me )
        ++v23;
    }
  }
  if ( !v19 )
    v6->TXPacketLength += FullLength * v23;
LABEL_74:
  if ( OutgoingCount )
  {
    v27 = aGtd_0;
    if ( !v6->RGE_Guaranteed_Delivery )
      v27 = aGtd;
    strcpy(GTDString, v27);
    v28 = OutCommBuff[HeaderLength];
    v29 = txMsg->Command;
    v30 = debug_timeGetTime();
    TDebuggingLog::Log(
      L,
      aCommSerDSTxToD,
      txMsg->Serialno,
      GTDString,
      To,
      Length,
      HeaderLength,
      txMsg->Sequence,
      txMsg->ExecuteOnTurn,
      v29,
      v29,
      v28,
      v28,
      OutgoingCount,
      v19,
      v30);
  }
  if ( v19 )
  {
    RGE_Comm_Error::ShowReturn(v6->Err, v19, aTx);
  }
  else
  {
    ++v6->TXPackets;
    if ( MsgType == 62 )
      TCommunications_Handler::AddCommand(v6, SyncTurn, Msg, Length, v6->Me, txMsg->Sequence, 0);
  }
  operator delete(txMsg);
  operator delete(OutCommBuff);
  return v19;
}

//----- (0042B860) --------------------------------------------------------
void __thiscall TCommunications_Handler::DestroyMultiplayerGame(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // ebp@1
  unsigned int v2; // eax@1
  unsigned int v3; // esi@1
  unsigned __int16 v4; // cx@1
  signed int v5; // edi@1
  RGE_Communications_Queue *v6; // ecx@3
  RGE_Communications_Queue *v7; // ecx@5
  int v8; // eax@7
  signed int v9; // ecx@7

  v1 = this;
  TCommunications_Handler::DestroyMyPlayer(this);
  v2 = debug_timeGetTime();
  v1->RXPacketLength = 0;
  v1->RXPacketLengthHigh = 0;
  v1->TXPacketLength = 0;
  v1->TXPacketLengthHigh = 0;
  LODWORD(v1->lastRXDataRate) = 0;
  LODWORD(v1->lastTXDataRate) = 0;
  v1->HoldCount = 0;
  v1->ServiceTimeout = 0;
  v1->TXPackets = 0;
  v1->RXPackets = 0;
  v1->RGE_Guaranteed_Delivery = 0;
  v1->ResendAcknowledgements = 0;
  v1->ResentToOther = 0;
  v1->DroppedPacketCount = 0;
  v1->LobbyLaunched = 0;
  v1->GTDSerialNo = 0;
  v1->dwStopTime = 0;
  v1->OutOfSyncFlag = 0;
  v3 = v2;
  TDebuggingLog::Time(L);
  v1->AvgTurnTime = 0;
  v1->PauseChangePending = 0;
  v1->StepMode = 0;
  v1->IntentionallyDropPackets = 0;
  v1->PlayerOptions.LastSentTime = v3;
  strcpy(v1->MyGameTitle, text_in);
  strcpy(v1->MyFriendlyName, text_in);
  strcpy(v1->MyFormalName, text_in);
  v4 = v1->MaxGamePlayers;
  v1->TickStart = 0;
  v1->TickCount = 0;
  v1->LastTimeoutMessageTime = 0;
  v1->PlayerOptions.LowPlayerNumber = 1;
  v1->PlayerOptions.HighPlayerNumber = v4;
  v1->PlayerOptions.GameHasStarted = 0;
  v1->PlayerOptions.ProgramState = 3;
  v1->MeHost = 0;
  v1->HaveHostInit = 0;
  v1->PlayerOptions.CommandTurnIncrement = 2;
  v1->current_turn = 4;
  v1->PlayerOptions.CurrentTurn = 4;
  v1->PlayerOptions.NeedsToBeSent = 0;
  v1->AcknowledgeAfterMsec = 50;
  v1->Me = 0;
  v1->Multiplayer = 0;
  v1->turnstart = 0;
  v1->mselapsed = 0;
  TDebuggingLog::Log(L, aInitializePlay);
  v5 = 1;
  if ( v1->MaxGamePlayers >= 1u )
  {
    do
      TCommunications_Handler::InitPlayerInformation(v1, v5++, 0, text_in, text_in);
    while ( v5 <= v1->MaxGamePlayers );
  }
  v1->PlayerOptions.NeedsToBeSent = 0;
  v1->PlayerOptions.LastSentTime = 0;
  TCommunications_Handler::ClearAllSerialNumbers(v1);
  TCommunications_Handler::ClearRXandTX(v1);
  memset(&v1->PlayerStopTurn[1], 0, 0x24u);
  v1->Steps = 1;
  TCommunications_Handler::ResetLastCommunicationTimes(v1);
  v6 = v1->InQ;
  v1->WaitingForAck = 0;
  if ( v6 )
    RGE_Communications_Queue::FlushAll(v6);
  v7 = v1->OutQ;
  if ( v7 )
    RGE_Communications_Queue::FlushAll(v7);
  v1->ShuttingDown = 0;
  v8 = (int)v1->Kicked;
  v9 = 10;
  do
  {
    *(_DWORD *)(v8 - 304) = 0;
    *(_DWORD *)v8 = 0;
    *(_DWORD *)(v8 + 688) = 0;
    v8 += 4;
    --v9;
  }
  while ( v9 );
}

//----- (0042BAD0) --------------------------------------------------------
int __thiscall TCommunications_Handler::GetCommunicationsStatus(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  int result; // eax@1

  v1 = this;
  result = TCommunications_Handler::AnalyzeCommunicationsStatus(this);
  v1->CommunicationsStatus = result;
  return result;
}

//----- (0042BAE0) --------------------------------------------------------
int __thiscall TCommunications_Handler::UnlinkCurrentLevel(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // ebp@1
  unsigned int v2; // eax@2
  unsigned int v3; // esi@2
  signed int v4; // edi@2
  unsigned __int16 v5; // cx@2
  RGE_Communications_Queue *v6; // ecx@4
  RGE_Communications_Queue *v7; // ecx@6
  int v8; // eax@8
  signed int v9; // ecx@8
  unsigned int v10; // eax@11
  unsigned int v11; // esi@11
  signed int v12; // edi@11
  unsigned __int16 v13; // cx@11
  RGE_Communications_Queue *v14; // ecx@13
  RGE_Communications_Queue *v15; // ecx@15
  int v16; // eax@17
  signed int v17; // ecx@17
  signed int v18; // esi@21
  TChat *v19; // ecx@23
  signed int v20; // edi@24
  unsigned __int16 v21; // dx@26
  RGE_Communications_Speed *v22; // edi@26
  RGE_Communications_Synchronize *v23; // edi@28
  RGE_Communications_Speed *v24; // eax@30
  RGE_Communications_Speed *v25; // eax@31
  RGE_Communications_Synchronize *v26; // eax@33
  RGE_Communications_Synchronize *v27; // eax@34
  int v28; // ecx@36
  unsigned __int16 v29; // dx@37
  signed int v30; // esi@37
  TChat *v31; // ecx@39
  RGE_Communications_Speed *v32; // esi@39
  int v33; // edx@39
  RGE_Communications_Synchronize *v34; // esi@41
  RGE_Communications_Speed *v35; // eax@43
  RGE_Communications_Speed *v36; // eax@44
  RGE_Communications_Synchronize *v37; // eax@46
  RGE_Communications_Synchronize *v38; // eax@47
  RGE_Communications_Queue *v39; // ecx@55

  v1 = this;
  TDebuggingLog::Log(L, aUnlinkingCurre, this->CommunicationsStatus);
  switch ( v1->CommunicationsStatus )
  {
    case 2:
      v1->Multiplayer = 0;
      v2 = debug_timeGetTime();
      v1->RXPacketLength = 0;
      v1->RXPacketLengthHigh = 0;
      v1->TXPacketLength = 0;
      v1->TXPacketLengthHigh = 0;
      LODWORD(v1->lastRXDataRate) = 0;
      LODWORD(v1->lastTXDataRate) = 0;
      v1->HoldCount = 0;
      v1->ServiceTimeout = 0;
      v1->TXPackets = 0;
      v1->RXPackets = 0;
      v1->RGE_Guaranteed_Delivery = 0;
      v1->ResendAcknowledgements = 0;
      v1->ResentToOther = 0;
      v1->DroppedPacketCount = 0;
      v1->LobbyLaunched = 0;
      v1->GTDSerialNo = 0;
      v1->dwStopTime = 0;
      v1->OutOfSyncFlag = 0;
      v3 = v2;
      TDebuggingLog::Time(L);
      v1->AvgTurnTime = 0;
      v1->PauseChangePending = 0;
      v1->StepMode = 0;
      v1->IntentionallyDropPackets = 0;
      v1->PlayerOptions.LastSentTime = v3;
      strcpy(v1->MyGameTitle, text_in);
      strcpy(v1->MyFriendlyName, text_in);
      strcpy(v1->MyFormalName, text_in);
      v1->TickStart = 0;
      v1->TickCount = 0;
      v1->LastTimeoutMessageTime = 0;
      v4 = 1;
      v5 = v1->MaxGamePlayers;
      v1->PlayerOptions.LowPlayerNumber = 1;
      v1->PlayerOptions.HighPlayerNumber = v5;
      v1->PlayerOptions.GameHasStarted = 0;
      v1->PlayerOptions.ProgramState = 3;
      v1->MeHost = 0;
      v1->HaveHostInit = 0;
      v1->PlayerOptions.CommandTurnIncrement = 2;
      v1->current_turn = 4;
      v1->PlayerOptions.CurrentTurn = 4;
      v1->PlayerOptions.NeedsToBeSent = 0;
      v1->AcknowledgeAfterMsec = 50;
      v1->Me = 0;
      v1->Multiplayer = 0;
      v1->turnstart = 0;
      v1->mselapsed = 0;
      TDebuggingLog::Log(L, aInitializePlay);
      if ( v1->MaxGamePlayers >= 1u )
      {
        do
          TCommunications_Handler::InitPlayerInformation(v1, v4++, 0, text_in, text_in);
        while ( v4 <= v1->MaxGamePlayers );
      }
      v1->PlayerOptions.NeedsToBeSent = 0;
      v1->PlayerOptions.LastSentTime = 0;
      TCommunications_Handler::ClearAllSerialNumbers(v1);
      TCommunications_Handler::ClearRXandTX(v1);
      memset(&v1->PlayerStopTurn[1], 0, 0x24u);
      v1->Steps = 1;
      TCommunications_Handler::ResetLastCommunicationTimes(v1);
      v6 = v1->InQ;
      v1->WaitingForAck = 0;
      if ( v6 )
        RGE_Communications_Queue::FlushAll(v6);
      v7 = v1->OutQ;
      if ( v7 )
        RGE_Communications_Queue::FlushAll(v7);
      v1->ShuttingDown = 0;
      v8 = (int)v1->Kicked;
      v9 = 10;
      do
      {
        *(_DWORD *)(v8 - 304) = 0;
        *(_DWORD *)v8 = 0;
        *(_DWORD *)(v8 + 688) = 0;
        v8 += 4;
        --v9;
      }
      while ( v9 );
      v1->Me = 1;
      v1->MyFriendlyName[0] = 0;
      v1->MyFormalName[0] = 0;
      break;
    case 3:
      v1->Multiplayer = 0;
      v10 = debug_timeGetTime();
      v1->RXPacketLength = 0;
      v1->RXPacketLengthHigh = 0;
      v1->TXPacketLength = 0;
      v1->TXPacketLengthHigh = 0;
      LODWORD(v1->lastRXDataRate) = 0;
      LODWORD(v1->lastTXDataRate) = 0;
      v1->HoldCount = 0;
      v1->ServiceTimeout = 0;
      v1->TXPackets = 0;
      v1->RXPackets = 0;
      v1->RGE_Guaranteed_Delivery = 0;
      v1->ResendAcknowledgements = 0;
      v1->ResentToOther = 0;
      v1->DroppedPacketCount = 0;
      v1->LobbyLaunched = 0;
      v1->GTDSerialNo = 0;
      v1->dwStopTime = 0;
      v1->OutOfSyncFlag = 0;
      v11 = v10;
      TDebuggingLog::Time(L);
      v1->AvgTurnTime = 0;
      v1->PauseChangePending = 0;
      v1->StepMode = 0;
      v1->IntentionallyDropPackets = 0;
      v1->PlayerOptions.LastSentTime = v11;
      strcpy(v1->MyGameTitle, text_in);
      strcpy(v1->MyFriendlyName, text_in);
      strcpy(v1->MyFormalName, text_in);
      v1->TickStart = 0;
      v1->TickCount = 0;
      v1->LastTimeoutMessageTime = 0;
      v12 = 1;
      v13 = v1->MaxGamePlayers;
      v1->PlayerOptions.LowPlayerNumber = 1;
      v1->PlayerOptions.HighPlayerNumber = v13;
      v1->PlayerOptions.GameHasStarted = 0;
      v1->PlayerOptions.ProgramState = 3;
      v1->MeHost = 0;
      v1->HaveHostInit = 0;
      v1->PlayerOptions.CommandTurnIncrement = 2;
      v1->current_turn = 4;
      v1->PlayerOptions.CurrentTurn = 4;
      v1->PlayerOptions.NeedsToBeSent = 0;
      v1->AcknowledgeAfterMsec = 50;
      v1->Me = 0;
      v1->Multiplayer = 0;
      v1->turnstart = 0;
      v1->mselapsed = 0;
      TDebuggingLog::Log(L, aInitializePlay);
      if ( v1->MaxGamePlayers >= 1u )
      {
        do
          TCommunications_Handler::InitPlayerInformation(v1, v12++, 0, text_in, text_in);
        while ( v12 <= v1->MaxGamePlayers );
      }
      v1->PlayerOptions.NeedsToBeSent = 0;
      v1->PlayerOptions.LastSentTime = 0;
      TCommunications_Handler::ClearAllSerialNumbers(v1);
      TCommunications_Handler::ClearRXandTX(v1);
      memset(&v1->PlayerStopTurn[1], 0, 0x24u);
      v1->Steps = 1;
      TCommunications_Handler::ResetLastCommunicationTimes(v1);
      v14 = v1->InQ;
      v1->WaitingForAck = 0;
      if ( v14 )
        RGE_Communications_Queue::FlushAll(v14);
      v15 = v1->OutQ;
      if ( v15 )
        RGE_Communications_Queue::FlushAll(v15);
      v1->ShuttingDown = 0;
      v16 = (int)v1->Kicked;
      v17 = 10;
      do
      {
        *(_DWORD *)(v16 - 304) = 0;
        *(_DWORD *)v16 = 0;
        *(_DWORD *)(v16 + 688) = 0;
        v16 += 4;
        --v17;
      }
      while ( v17 );
      v1->Me = 1;
      v1->PlayerOptions.Humanity[1] = 2;
      break;
    case 4:
      v1->TXPackets = 0;
      v1->RXPackets = 0;
      v1->RGE_Guaranteed_Delivery = 1;
      v1->ResendAcknowledgements = 0;
      v1->ResentToOther = 0;
      v1->DroppedPacketCount = 0;
      v1->LobbyLaunched = 0;
      v1->ShuttingDown = 0;
      TDebuggingLog::Log(L, aUnlinkReleasec);
      TCommunications_Handler::ReleaseComm(v1);
      break;
    case 5:
      TDebuggingLog::Log(L, aUnlinkServicea);
      TCommunications_Handler::ReleaseComm(v1);
      TDebuggingLog::Log(L, aInitializePlay);
      v18 = 1;
      if ( v1->MaxGamePlayers >= 1u )
      {
        do
          TCommunications_Handler::InitPlayerInformation(v1, v18++, 0, text_in, text_in);
        while ( v18 <= v1->MaxGamePlayers );
      }
      v19 = v1->Chat;
      v1->PlayerOptions.NeedsToBeSent = 0;
      v1->PlayerOptions.LastSentTime = 0;
      TChat::ClearChat(v19);
      v1->MyGameTitle[0] = 0;
      goto LABEL_51;
    case 6:
      TCommunications_Handler::ClearRXandTX(v1);
      TCommunications_Handler::DropAllHostedPlayers(v1);
      TDebuggingLog::Log(L, aUnlinkSessiona);
      TChat::ClearChat(v1->Chat);
      TCommunications_Handler::CloseSession(v1);
      v1->GTDSerialNo = 0;
      TDebuggingLog::Log(L, aInitializePlay);
      v20 = 1;
      if ( v1->MaxGamePlayers >= 1u )
      {
        do
          TCommunications_Handler::InitPlayerInformation(v1, v20++, 0, text_in, text_in);
        while ( v20 <= v1->MaxGamePlayers );
      }
      v21 = v1->MaxGamePlayers;
      v1->PlayerOptions.NeedsToBeSent = 0;
      v1->PlayerOptions.LastSentTime = 0;
      v1->PlayerOptions.HighPlayerNumber = v21;
      v1->PlayerOptions.ProgramState = 3;
      v1->PlayerOptions.CommandTurnIncrement = 2;
      v1->current_turn = 4;
      v1->PlayerOptions.CurrentTurn = 4;
      v1->Me = 0;
      dcoID = 0;
      TCommunications_Handler::ClearAllSerialNumbers(v1);
      v22 = v1->Speed;
      v1->PlayerOptions.GameHasStarted = 0;
      v1->ShuttingDown = 0;
      if ( v22 )
      {
        RGE_Communications_Speed::~RGE_Communications_Speed(v22);
        operator delete(v22);
      }
      v23 = v1->Sync;
      if ( v23 )
      {
        RGE_Communications_Synchronize::~RGE_Communications_Synchronize(v1->Sync);
        operator delete(v23);
      }
      v24 = (RGE_Communications_Speed *)operator new(0x240u);
      if ( v24 )
        RGE_Communications_Speed::RGE_Communications_Speed(v24, v1);
      else
        v25 = 0;
      v1->Speed = v25;
      v26 = (RGE_Communications_Synchronize *)operator new(0x7ECu);
      if ( v26 )
        RGE_Communications_Synchronize::RGE_Communications_Synchronize(v26, v1);
      else
        v27 = 0;
      v1->Sync = v27;
      v28 = (int)&v1->SessionGUID;
      *(_DWORD *)v28 = v1->NullGUID.x;
      *(_DWORD *)(v28 + 4) = *(_DWORD *)&v1->NullGUID.s1;
      *(_DWORD *)(v28 + 8) = *(_DWORD *)&v1->NullGUID.c[0];
      *(_DWORD *)(v28 + 12) = *(_DWORD *)&v1->NullGUID.c[4];
      break;
    case 7:
      TDebuggingLog::Log(L, aUnlinkSerssion);
      v29 = v1->MaxGamePlayers;
      v1->MeHost = 0;
      v1->PlayerOptions.HostPlayerNumber = 0;
      v1->PlayerOptions.HighPlayerNumber = v29;
      v1->PlayerOptions.ProgramState = 3;
      v1->PlayerOptions.CommandTurnIncrement = 2;
      v1->current_turn = 4;
      v1->PlayerOptions.CurrentTurn = 4;
      v1->HaveHostInit = 0;
      TCommunications_Handler::CloseSession(v1);
      TDebuggingLog::Log(L, aInitializePlay);
      v30 = 1;
      if ( v1->MaxGamePlayers >= 1u )
      {
        do
          TCommunications_Handler::InitPlayerInformation(v1, v30++, 0, text_in, text_in);
        while ( v30 <= v1->MaxGamePlayers );
      }
      v31 = v1->Chat;
      v1->PlayerOptions.NeedsToBeSent = 0;
      v1->PlayerOptions.LastSentTime = 0;
      TChat::ClearChat(v31);
      dcoID = 0;
      v32 = v1->Speed;
      v33 = v1->PlayerOptions.CommandTurnIncrement + 2;
      v1->Me = 0;
      v1->current_turn = v33;
      v1->PlayerOptions.GameHasStarted = 0;
      v1->ShuttingDown = 0;
      if ( v32 )
      {
        RGE_Communications_Speed::~RGE_Communications_Speed(v32);
        operator delete(v32);
      }
      v34 = v1->Sync;
      if ( v34 )
      {
        RGE_Communications_Synchronize::~RGE_Communications_Synchronize(v1->Sync);
        operator delete(v34);
      }
      v35 = (RGE_Communications_Speed *)operator new(0x240u);
      if ( v35 )
        RGE_Communications_Speed::RGE_Communications_Speed(v35, v1);
      else
        v36 = 0;
      v1->Speed = v36;
      v37 = (RGE_Communications_Synchronize *)operator new(0x7ECu);
      if ( v37 )
      {
        RGE_Communications_Synchronize::RGE_Communications_Synchronize(v37, v1);
        v1->Sync = v38;
      }
      else
      {
        v1->Sync = 0;
      }
      break;
    case 9:
      TDebuggingLog::Log(L, aUnlinkPlayercr);
      TCommunications_Handler::DestroyMyPlayer(v1);
      v1->Me = 0;
      dcoID = 0;
      RGE_Communications_Queue::FlushAll(v1->InQ);
      v1->ShuttingDown = 0;
      break;
    case 0xB:
      TDebuggingLog::Log(L, aUnlinkPlayerse);
LABEL_51:
      v1->Me = 0;
      dcoID = 0;
      v1->ShuttingDown = 0;
      break;
    case 0xC:
      TDebuggingLog::Log(L, aUnlinkGameopti);
      TCommunications_Handler::FreeOptions(v1);
      v1->PlayerOptions.NeedsToBeSent = 0;
      v1->ShuttingDown = 0;
      break;
    case 0xA:
      TDebuggingLog::Log(L, aUnlinkCommsett);
      TCommunications_Handler::ReleaseSettings(v1);
      TCommunications_Handler::ResetLastCommunicationTimes(v1);
      v1->ShuttingDown = 0;
      break;
    case 0xD:
      v1->PlayerOptions.ProgramState = 3;
      TDebuggingLog::Log(L, aUnlinkGameislo);
      v1->ShuttingDown = 0;
      break;
    case 0xE:
      TChat::ClearChat(v1->Chat);
      TDebuggingLog::Log(L, aUnlinkGameisru);
      v39 = v1->InQ;
      v1->LastTimeoutMessageTime = 0;
      RGE_Communications_Queue::FlushAll(v39);
      v1->PlayerOptions.GameHasStarted = 0;
      v1->ShuttingDown = 0;
      break;
    case 0xF:
      TDebuggingLog::Log(L, aUnlinkGameispa);
      break;
    default:
      TDebuggingLog::Log(L, aUnlinkUnknown);
      break;
    case 0:
    case 1:
      break;
  }
  TDebuggingLog::Log(L, aLevelIsNow___D, v1->CommunicationsStatus - 1);
  return TCommunications_Handler::AnalyzeCommunicationsStatus(v1);
}

//----- (0042C5D0) --------------------------------------------------------
int __thiscall TCommunications_Handler::UnlinkToLevel(TCommunications_Handler *this, COMMSTATUS lvl)
{
  TCommunications_Handler *v2; // esi@1
  int v3; // eax@1
  COMMSTATUS v4; // ebx@1
  COMMSTATUS v5; // edi@3
  int v6; // eax@4
  COMMSTATUS v7; // ST0C_4@6
  int v8; // eax@6
  int result; // eax@6

  v2 = this;
  v3 = TCommunications_Handler::AnalyzeCommunicationsStatus(this);
  v4 = lvl;
  v2->CommunicationsStatus = v3;
  TDebuggingLog::Log(L, aUnlinkToLevelD, lvl, v3);
  if ( (signed int)lvl < 1 )
    v4 = 1;
  v5 = v2->CommunicationsStatus;
  if ( v5 <= v4 )
  {
LABEL_6:
    v7 = v2->CommunicationsStatus;
    v8 = TCommunications_Handler::GetCommunicationsStatus(v2);
    TDebuggingLog::Log(L, aAfterUnlinking, v8, v7);
    result = TCommunications_Handler::AnalyzeCommunicationsStatus(v2);
  }
  else
  {
    while ( 1 )
    {
      v6 = TCommunications_Handler::UnlinkCurrentLevel(v2);
      v2->CommunicationsStatus = v6;
      if ( v6 == v5 )
        break;
      if ( v6 <= v4 )
        goto LABEL_6;
    }
    sprintf(v2->TBuff, aUnlinkFromLeve, v5);
    TDebuggingLog::Log(L, v2->TBuff);
    result = TCommunications_Handler::AnalyzeCommunicationsStatus(v2);
  }
  return result;
}

//----- (0042C690) --------------------------------------------------------
int __thiscall TCommunications_Handler::AnalyzeCommunicationsStatus(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // ebx@1
  int result; // eax@3

  v1 = this;
  if ( TCommunications_Handler::IsPaused(this) && v1->current_turn >= 6 )
    return 15;
  if ( v1->PlayerOptions.ProgramState != 5 )
    goto LABEL_26;
  if ( v1->current_turn >= 6 )
    return 14;
  if ( v1->current_turn >= 6 )
  {
LABEL_26:
    if ( v1->PlayerOptions.NeedsToBeSent )
    {
      result = 12;
    }
    else if ( dcoID )
    {
      result = 9;
    }
    else if ( v1->MeHost )
    {
      result = 7;
    }
    else if ( !memcmp(&v1->SessionGUID, &v1->NullGUID, 0x10u) )
    {
      if ( !memcmp(&v1->ServiceGUID, &v1->NullGUID, 0x10u) )
      {
        if ( glpIDC )
        {
          result = 4;
        }
        else if ( v1->Multiplayer )
        {
          result = 3;
        }
        else
        {
          result = 2 - (v1->Me != 1);
        }
      }
      else
      {
        result = 5;
      }
    }
    else
    {
      result = 6;
    }
  }
  else
  {
    result = 13;
  }
  return result;
}

//----- (0042C7A0) --------------------------------------------------------
void __thiscall TCommunications_Handler::ResetLastCommunicationTimes(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  unsigned int v2; // eax@1
  signed int v3; // edx@1
  unsigned int *v4; // ecx@2

  v1 = this;
  v2 = debug_timeGetTime();
  v3 = 1;
  if ( v1->MaxGamePlayers >= 1u )
  {
    v4 = &v1->LastTXPing[1];
    do
    {
      *(v4 - 20) = v2;
      *v4 = v2;
      ++v3;
      ++v4;
    }
    while ( v3 <= v1->MaxGamePlayers );
  }
}

//----- (0042C7F0) --------------------------------------------------------
BOOL __thiscall TCommunications_Handler::IsPaused(TCommunications_Handler *this)
{
  return this->PlayerOptions.ProgramState == 4;
}

//----- (0042C800) --------------------------------------------------------
void __thiscall TCommunications_Handler::DropAllHostedPlayers(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // edi@1
  signed int v2; // esi@3

  v1 = this;
  if ( this->MeHost )
  {
    if ( this->current_turn <= 6 )
    {
      v2 = 1;
      if ( this->MaxGamePlayers >= 1u )
      {
        do
          TCommunications_Handler::Kick(v1, v2++);
        while ( v2 <= v1->MaxGamePlayers );
      }
    }
  }
}

//----- (0042C840) --------------------------------------------------------
void __thiscall TCommunications_Handler::LocalResumeGame(TCommunications_Handler *this, unsigned int p)
{
  this->PlayerOptions.ProgramState = 5;
  TCommunications_Handler::NotifyWindowParam(this, COMM_RESUME, p);
}

//----- (0042C860) --------------------------------------------------------
void __thiscall TCommunications_Handler::LocalPauseGame(TCommunications_Handler *this, unsigned int p)
{
  this->PlayerOptions.ProgramState = 4;
  TCommunications_Handler::NotifyWindowParam(this, COMM_PAUSE, p);
}

//----- (0042C880) --------------------------------------------------------
void __thiscall TCommunications_Handler::SendPauseGame(TCommunications_Handler *this, int Pause)
{
  TCommunications_Handler *v2; // esi@1

  v2 = this;
  if ( this->Multiplayer && this->MeHost )
  {
    if ( Pause )
    {
      TDebuggingLog::Log(L, aTxPause);
      TCommunications_Handler::CommOut(v2, 0, 80, 0, 0, 0);
    }
    else
    {
      TDebuggingLog::Log(L, aTxResume);
      TCommunications_Handler::CommOut(v2, 0, 85, 0, 0, 0);
    }
  }
}

//----- (0042C8F0) --------------------------------------------------------
int __thiscall TCommunications_Handler::TogglePauseGame(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  int result; // eax@2

  v1 = this;
  if ( this->PauseChangePending )
  {
    result = 0;
  }
  else if ( TCommunications_Handler::IsPaused(this) )
  {
    TCommunications_Handler::RequestResumeGame(v1, 0);
    result = 1;
  }
  else
  {
    TCommunications_Handler::RequestPauseGame(v1, 0);
    result = 1;
  }
  return result;
}

//----- (0042C930) --------------------------------------------------------
void __thiscall TCommunications_Handler::RequestPauseGame(TCommunications_Handler *this, int SendChatInfo)
{
  TCommunications_Handler *v2; // esi@1

  v2 = this;
  if ( this->Multiplayer )
  {
    if ( this->MeHost )
    {
      TCommunications_Handler::SendPauseGame(this, 1);
      TCommunications_Handler::LocalPauseGame(v2, v2->Me);
    }
    else
    {
      TDebuggingLog::Log(L, aTxReqPause);
      TCommunications_Handler::CommOut(v2, 0, 87, 0, 0, 0);
    }
  }
  else
  {
    TCommunications_Handler::LocalPauseGame(this, this->Me);
  }
}

//----- (0042C9A0) --------------------------------------------------------
void __thiscall TCommunications_Handler::RequestResumeGame(TCommunications_Handler *this, int SendChatInfo)
{
  TCommunications_Handler *v2; // esi@1

  v2 = this;
  if ( this->Multiplayer )
  {
    if ( this->MeHost )
    {
      TCommunications_Handler::SendPauseGame(this, 0);
      TCommunications_Handler::LocalResumeGame(v2, v2->Me);
    }
    else
    {
      TDebuggingLog::Log(L, aTxReqRes);
      TCommunications_Handler::CommOut(v2, 0, 43, 0, 0, 0);
    }
  }
  else
  {
    TDebuggingLog::Log(L, aResumeRequeste);
    TCommunications_Handler::LocalResumeGame(v2, v2->Me);
  }
}

//----- (0042CA20) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetRandomSeed(TCommunications_Handler *this, int val)
{
  TCommunications_Handler *v2; // esi@1
  int v3; // eax@2
  unsigned int v4; // eax@3

  v2 = this;
  if ( this->MeHost )
  {
    v3 = val;
    if ( val == -1 )
    {
      v4 = debug_timeGetTime();
      debug_srand(aCMsdevWorkA_39, 4896, v4);
      v3 = debug_rand(aCMsdevWorkA_39, 4897);
    }
    v2->PlayerOptions.RandomSeed = v3;
    v2->PlayerOptions.NeedsToBeSent = 1;
    TCommunications_Handler::SendSharedData(v2, 0);
  }
}

//----- (0042CA90) --------------------------------------------------------
unsigned int __thiscall TCommunications_Handler::GetRandomSeed(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  unsigned int v2; // eax@2

  v1 = this;
  if ( !this->Multiplayer )
  {
    v2 = debug_timeGetTime();
    debug_srand(aCMsdevWorkA_39, 4918, v2);
    v1->PlayerOptions.RandomSeed = debug_rand(aCMsdevWorkA_39, 4919);
  }
  return v1->PlayerOptions.RandomSeed;
}

//----- (0042CAF0) --------------------------------------------------------
unsigned int __thiscall TCommunications_Handler::WhoAmI(TCommunications_Handler *this)
{
  return this->Me;
}

//----- (0042CB00) --------------------------------------------------------
int __thiscall TCommunications_Handler::IsHost(TCommunications_Handler *this)
{
  int result; // eax@2

  if ( this->Multiplayer )
    result = this->MeHost;
  else
    result = 1;
  return result;
}

//----- (0042CB20) --------------------------------------------------------
char *TCommunications_Handler::GetCommStateStr()
{
  return 0;
}

//----- (0042CB30) --------------------------------------------------------
char *__thiscall TCommunications_Handler::GetReadyPlayerStr(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // ebp@1
  unsigned int v2; // ecx@1
  char v3; // al@1
  char *v4; // edi@1
  char *v5; // esi@1
  unsigned int v6; // eax@1
  int v7; // edx@2

  v1 = this;
  v2 = strlen(aReady) + 1;
  v3 = v2;
  v2 >>= 2;
  qmemcpy(Buff, aReady, 4 * v2);
  v5 = &aReady[4 * v2];
  v4 = &Buff[4 * v2];
  LOBYTE(v2) = v3;
  v6 = 1;
  qmemcpy(v4, v5, v2 & 3);
  if ( v1->MaxGamePlayers >= 1u )
  {
    v7 = (int)&v1->PlayerOptions.Humanity[1];
    do
    {
      if ( *(_DWORD *)(v7 + 76) < v1->current_turn )
      {
        switch ( *(_DWORD *)v7 )
        {
          case 2:
            Buff[v6 + 6] = 87;
            break;
          case 4:
            Buff[v6 + 6] = 67;
            break;
          case 0:
            Buff[v6 + 6] = 45;
            break;
          case 6:
            Buff[v6 + 6] = 86;
            break;
          case 5:
            Buff[v6 + 6] = 88;
            break;
          default:
            Buff[v6 + 6] = 63;
            break;
        }
      }
      else
      {
        Buff[v6 + 6] = 65;
      }
      ++v6;
      v7 += 4;
    }
    while ( v6 <= v1->MaxGamePlayers );
  }
  return Buff;
}

//----- (0042CC00) --------------------------------------------------------
PLAYERHUMANITY __thiscall TCommunications_Handler::GetPlayerHumanity(TCommunications_Handler *this, unsigned int PlayerNo)
{
  PLAYERHUMANITY result; // eax@3

  if ( PlayerNo < 1 || PlayerNo > this->MaxGamePlayers )
    result = 0;
  else
    result = this->PlayerOptions.Humanity[PlayerNo];
  return result;
}

//----- (0042CC30) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetPlayerHumanity(TCommunications_Handler *this, unsigned int PlayerNo, PLAYERHUMANITY Type)
{
  TCommunications_Handler *v3; // esi@1

  v3 = this;
  if ( PlayerNo >= 1 && PlayerNo <= this->MaxGamePlayers )
  {
    this->PlayerOptions.Humanity[PlayerNo] = Type;
    TCommunications_Handler::UpdatePlayer(this, PlayerNo, 1);
    TCommunications_Handler::NotifyWindow(v3, COMM_UPDATE_PARAMS);
    if ( v3->MeHost )
    {
      if ( v3->PlayerOptions.ProgramState == 3 )
      {
        v3->PlayerOptions.NeedsToBeSent = 1;
        TCommunications_Handler::SendSharedData(v3, 0);
      }
    }
  }
}

//----- (0042CC90) --------------------------------------------------------
int __thiscall TCommunications_Handler::GetActivePlayerCount(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // edi@1
  signed int v2; // esi@1
  int v3; // ebx@1
  bool v4; // zf@1

  v1 = this;
  v2 = 0;
  v3 = 0;
  v4 = this->MaxGamePlayers == 0;
  do
  {
    if ( TCommunications_Handler::IsPlayerHuman(v1, v2) || TCommunications_Handler::IsPlayerComputer(v1, v2) )
      ++v3;
    ++v2;
  }
  while ( v2 <= v1->MaxGamePlayers );
  return v3;
}

//----- (0042CCD0) --------------------------------------------------------
int __thiscall TCommunications_Handler::IsPlayerHuman(TCommunications_Handler *this, unsigned int PlayerNo)
{
  PLAYERHUMANITY v2; // eax@3
  int result; // eax@5

  result = 0;
  if ( PlayerNo >= 1 && PlayerNo <= this->MaxGamePlayers )
  {
    v2 = this->PlayerOptions.Humanity[PlayerNo];
    if ( v2 == 2 || v2 == 5 )
      result = 1;
  }
  return result;
}

//----- (0042CD10) --------------------------------------------------------
int __thiscall TCommunications_Handler::IsPlayerComputer(TCommunications_Handler *this, unsigned int PlayerNo)
{
  int result; // eax@3

  if ( PlayerNo < 1 || PlayerNo > this->MaxGamePlayers )
    result = 0;
  else
    result = this->PlayerOptions.Humanity[PlayerNo] == 4;
  return result;
}

//----- (0042CD50) --------------------------------------------------------
char *__thiscall TCommunications_Handler::GetCommInfo(TCommunications_Handler *this, char LineNum)
{
  char *v2; // edx@1
  TCommunications_Handler *v3; // ebx@1
  int v4; // ebp@1
  char *v5; // edi@2
  char *v6; // edi@4
  unsigned int v7; // ecx@5
  char v8; // al@5
  char *v9; // edi@5
  char *v10; // esi@5
  int v11; // eax@5
  const char *v12; // edi@5
  unsigned __int64 v13; // st7@7
  double v14; // ST18_8@7
  char *v15; // eax@7
  RGE_Communications_Speed *v16; // eax@7
  unsigned int v17; // ST24_4@7
  char *v18; // eax@7
  unsigned int v19; // ST24_4@7
  char *v20; // eax@7
  char *v21; // eax@7
  unsigned int v22; // edi@7
  int v23; // esi@32
  int v24; // edi@36
  int v26; // [sp+20h] [bp-118h]@17
  unsigned int dwCount; // [sp+24h] [bp-114h]@7
  unsigned int v28; // [sp+28h] [bp-110h]@21
  unsigned int v29; // [sp+2Ch] [bp-10Ch]@13
  unsigned int v30; // [sp+30h] [bp-108h]@25
  unsigned int v31; // [sp+34h] [bp-104h]@9
  char tmp[255]; // [sp+38h] [bp-100h]@5
  unsigned __int8 LineNuma; // [sp+13Ch] [bp+4h]@1

  v2 = Lin;
  v3 = this;
  v4 = 0;
  LineNuma = LineNum - 1;
  if ( this->Multiplayer )
  {
    do
    {
      v6 = v2;
      v2 += 256;
      strcpy(v6, text_in);
    }
    while ( (signed int)v2 < (signed int)&Lin[1792] );
    v7 = strlen(message_in) + 1;
    v8 = v7;
    v7 >>= 2;
    qmemcpy(tmp, message_in, 4 * v7);
    v10 = &message_in[4 * v7];
    v9 = &tmp[4 * v7];
    LOBYTE(v7) = v8;
    v11 = v3->MeHost;
    qmemcpy(v9, v10, v7 & 3);
    v12 = aHost;
    if ( !v11 )
      v12 = aClient;
    *(double *)&v13 = v3->lastRXDataRate;
    strcpy(tmp, v12);
    v14 = v3->lastTXDataRate;
    v15 = TCommunications_Handler::GetReadyPlayerStr(v3);
    sprintf(Lin, aPDT6ld_7sSTx0_, v3->Me, v3->current_turn, tmp, v15, v14, (_DWORD)v13, (_DWORD)(v13 >> 32));
    v16 = RGE_Communications_Speed::GetLatencyInfo(v3->Speed);
    sprintf(&Lin[256], aS, v16);
    v17 = RGE_Communications_Speed::GetAdjustmentCount(v3->Speed);
    v18 = RGE_Communications_Speed::GetMachineSpeedInfo(v3->Speed);
    sprintf(&Lin[512], aSSpeedAdjustsD, v18, v17);
    dwCount = 0;
    ((void (__stdcall *)(IDirectPlay3 *, unsigned int, unsigned int *))glpIDC->vfptr[5].Release)(
      glpIDC,
      dcoID,
      &dwCount);
    v19 = dwCount;
    v20 = RGE_Communications_Speed::GetSelfPlayerOptimalSpeedStr(v3->Speed);
    sprintf(&Lin[768], aSDpmsgsD, v20, v19);
    v21 = RGE_Communications_Speed::GetPlayerSpeedStatusStr(v3->Speed, 0);
    sprintf(&Lin[1024], aS, v21);
    v22 = debug_timeGetTime();
    if ( TCommunications_Handler::IsPlayerHuman(v3, 8u) && v3->Me != 8 )
      v31 = v22 - v3->LastPlayerCommunication[8];
    else
      v31 = 0;
    if ( TCommunications_Handler::IsPlayerHuman(v3, 7u) && v3->Me != 7 )
      v29 = v22 - v3->LastPlayerCommunication[7];
    else
      v29 = 0;
    if ( TCommunications_Handler::IsPlayerHuman(v3, 6u) && v3->Me != 6 )
      v26 = v22 - v3->LastPlayerCommunication[6];
    else
      v26 = 0;
    if ( TCommunications_Handler::IsPlayerHuman(v3, 5u) && v3->Me != 5 )
      v28 = v22 - v3->LastPlayerCommunication[5];
    else
      v28 = 0;
    if ( TCommunications_Handler::IsPlayerHuman(v3, 4u) && v3->Me != 4 )
      v30 = v22 - v3->LastPlayerCommunication[4];
    else
      v30 = 0;
    if ( TCommunications_Handler::IsPlayerHuman(v3, 3u) && v3->Me != 3 )
      v4 = v22 - v3->LastPlayerCommunication[3];
    if ( TCommunications_Handler::IsPlayerHuman(v3, 2u) && v3->Me != 2 )
      v23 = v22 - v3->LastPlayerCommunication[2];
    else
      v23 = 0;
    if ( TCommunications_Handler::IsPlayerHuman(v3, 1u) && v3->Me != 1 )
      v24 = v22 - v3->LastPlayerCommunication[1];
    else
      v24 = 0;
    sprintf(&Lin[1280], aLastcommP15dP2, v24, v23, v4, v30, v28, v26, v29, v31);
  }
  else
  {
    do
    {
      v5 = v2;
      v2 += 256;
      strcpy(v5, asc_580464);
    }
    while ( (signed int)v2 < (signed int)&Lin[1792] );
    sprintf(Lin, aSingleplayerTD, this->current_turn);
  }
  return &Lin[256 * LineNuma];
}

//----- (0042D0E0) --------------------------------------------------------
char *__thiscall TCommunications_Handler::GetPlayerName(TCommunications_Handler *this, unsigned int PlayerNo)
{
  char *result; // eax@2

  if ( PlayerNo <= this->MaxGamePlayers )
  {
    if ( PlayerNo == this->Me )
      result = this->MyFriendlyName;
    else
      result = this->FriendlyName[PlayerNo].Text;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0042D120) --------------------------------------------------------
void __thiscall TCommunications_Handler::UpdatePlayerInformation(TCommunications_Handler *this, unsigned int dpID, char *AFriendlyName, char *AFormalName)
{
  int v4; // eax@2
  int v5; // esi@2
  char *v6; // edx@3

  if ( dpID
    && (v4 = this->PlayerOptions.LowPlayerNumber,
        v5 = this->PlayerOptions.HighPlayerNumber,
        (unsigned __int16)v4 <= (signed int)(unsigned __int16)v5) )
  {
    v6 = (char *)&this->PlayerOptions.dcoID[v4];
    while ( *(_DWORD *)v6 != dpID )
    {
      ++v4;
      v6 += 4;
      if ( v4 > v5 )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v4 = 0;
  }
  if ( !v4 )
    TCommunications_Handler::InitPlayerInformation(this, 0, dpID, AFriendlyName, AFormalName);
}

//----- (0042D170) --------------------------------------------------------
int __thiscall TCommunications_Handler::IsLobbyLaunched(TCommunications_Handler *this)
{
  return RGE_Lobby::IsLobbyLaunched(this->Lobby);
}

//----- (0042D180) --------------------------------------------------------
IDirectPlay3 *__thiscall TCommunications_Handler::LaunchLobbyGame(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  RGE_Lobby *v2; // ecx@1
  int v3; // edi@1
  unsigned int v4; // eax@3
  IDirectPlay3 *result; // eax@4
  int v6; // eax@7
  IDirectPlay3 *NewDPConv; // [sp+8h] [bp-58h]@1
  char *name; // [sp+Ch] [bp-54h]@7
  DPSESSIONDESC2 test; // [sp+10h] [bp-50h]@5

  v1 = this;
  v2 = this->Lobby;
  NewDPConv = 0;
  v3 = (unsigned __int8)RGE_Lobby::CheckForLobbyLaunch(v2, &NewDPConv);
  if ( !v3 )
  {
LABEL_10:
    v1->LobbyLaunched = v3;
    return (IDirectPlay3 *)v3;
  }
  if ( glpIDC )
  {
    v4 = glpIDC->vfptr->Release((IUnknown *)glpIDC);
    TDebuggingLog::Log(L, aReleaseCountD, v4);
  }
  result = NewDPConv;
  glpIDC = NewDPConv;
  if ( NewDPConv )
  {
    v3 = (unsigned __int8)RGE_Lobby::GetSessionInfo(v1->Lobby, &test);
    if ( v3 )
      TCommunications_Handler::DebugSessionInformation(&test);
    TCommunications_Handler::CommGetCaps(v1);
    v1->Multiplayer = 1;
    TCommunications_Handler::DPlayGetSessionDesc(v1);
    RGE_Lobby::GetPlayerInfo(v1->Lobby, &name);
    TCommunications_Handler::SetMyPlayerName(v1, name);
    v1->PlayerOptions.ProgramState = 3;
    TCommunications_Handler::AddSelfPlayer(v1);
    v6 = (unsigned __int8)RGE_Lobby::IsThisHost(v1->Lobby);
    v1->MeHost = v6;
    if ( v6 )
    {
      v1->Me = 1;
      v1->PlayerOptions.dcoID[1] = dcoID;
      v1->PlayerOptions.Humanity[v1->Me] = 2;
      v1->HaveHostInit = 1;
      v1->PlayerOptions.ProgramState = 3;
      TCommunications_Handler::SetRandomSeed(v1, rge_base_game->random_game_seed);
      v1->GTDSerialNo = 2001;
    }
    TCommunications_Handler::UpdatePlayers(v1);
    goto LABEL_10;
  }
  return result;
}

//----- (0042D2D0) --------------------------------------------------------
void __thiscall TCommunications_Handler::InitPlayerInformation(TCommunications_Handler *this, unsigned int PlayerNo, unsigned int dpID, char *FrName, char *FoName)
{
  RGE_Communications_Queue *v5; // ecx@3

  if ( PlayerNo >= 1 && PlayerNo <= this->MaxGamePlayers )
  {
    this->PlayerOptions.PlayerReady[PlayerNo] = 0;
    this->PlayerOptions.User1[PlayerNo] = 0;
    this->PlayerOptions.User2[PlayerNo] = 0;
    this->PlayerOptions.User3[PlayerNo] = 0;
    this->PlayerOptions.User4[PlayerNo] = 0;
    this->PlayerOptions.User5[PlayerNo] = 0;
    this->PlayerOptions.User6[PlayerNo] = 0;
    this->PlayerOptions.User7[PlayerNo] = 0;
    this->PlayerOptions.InvalidPlayer[PlayerNo] = 0;
    this->LastTurnAck[PlayerNo] = 0;
    this->PlayerOptions.Humanity[PlayerNo] = 0;
    this->PlayerOptions.dcoID[PlayerNo] = dpID;
    this->PlayerHighSerialNumber[PlayerNo] = 0;
    this->dwFlags = 0;
    this->dwMaxBufferSize = 0;
    this->dwMaxQueueSize = 0;
    this->dwMaxPlayers = 0;
    this->dwHundredBaud = 0;
    this->dwLatency = 0;
    v5 = this->InQ;
    if ( v5 )
      RGE_Communications_Queue::FlushForPlayer(v5, PlayerNo);
    TDebuggingLog::Log(L, aPlayerDLdIsIni, PlayerNo, dpID, FrName, FoName);
  }
}

//----- (0042D3B0) --------------------------------------------------------
int __thiscall TCommunications_Handler::SetGameTitle(TCommunications_Handler *this, char *Game)
{
  sprintf(this->MyGameTitle, aSS_2, Game, this->MyFriendlyName);
  return 1;
}

//----- (0042D3E0) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetMyPlayerName(TCommunications_Handler *this, char *Name)
{
  strcpy(this->MyFriendlyName, Name);
  strcpy(this->MyFormalName, aOptionalInform);
}

//----- (0042D440) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetPlayerName(TCommunications_Handler *this, unsigned int PlayerNo, char *Name)
{
  if ( PlayerNo == this->Me )
    TCommunications_Handler::SetMyPlayerName(this, Name);
  else
    strcpy(this->FriendlyName[PlayerNo].Text, Name);
}

//----- (0042D490) --------------------------------------------------------
void *__thiscall TCommunications_Handler::SetWindowHandle(TCommunications_Handler *this, void *hwnd)
{
  void *result; // eax@1

  result = hwnd;
  this->HostHWND = hwnd;
  return result;
}

//----- (0042D4A0) --------------------------------------------------------
int __thiscall TCommunications_Handler::CreateDirectPlayConversation(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // edi@1
  char *v2; // esi@1
  int v3; // ebx@1
  int result; // eax@2
  int v5; // edi@4
  int v6; // eax@6
  int v7; // esi@6
  unsigned int v8; // eax@8
  IDirectPlay *lpIDC; // [sp+Ch] [bp-4h]@1

  v1 = this;
  v2 = (char *)&this->ServiceGUID;
  v3 = DirectPlayCreate(&this->ServiceGUID, &lpIDC, 0);
  RGE_Comm_Error::ShowReturn(v1->Err, v3, aDpcreate);
  if ( glpIDC )
  {
    TDebuggingLog::Log(L, aAlreadyHaveCon);
    return -2005467131;
  }
  if ( v3 )
  {
    v5 = (int)&v1->NullGUID;
    *(_DWORD *)v2 = *(_DWORD *)v5;
    *((_DWORD *)v2 + 1) = *(_DWORD *)(v5 + 4);
    result = v3;
    *((_DWORD *)v2 + 2) = *(_DWORD *)(v5 + 8);
    *((_DWORD *)v2 + 3) = *(_DWORD *)(v5 + 12);
    return result;
  }
  if ( lpIDC )
  {
    v6 = lpIDC->vfptr->QueryInterface((IUnknown *)lpIDC, &IID_IDirectPlay3A, (void **)&glpIDC);
    v7 = v6;
    if ( v6 )
    {
      TDebuggingLog::Log(L, aGetGlpidcRetur, v6);
      return v7;
    }
    v8 = lpIDC->vfptr->Release((IUnknown *)lpIDC);
    TDebuggingLog::Log(L, aReleaseLinksD, v8);
  }
  return 0;
}

//----- (0042D580) --------------------------------------------------------
int TCommunications_Handler::OpenMultiplayerConnection()
{
  return -1;
}

//----- (0042D590) --------------------------------------------------------
int __thiscall TCommunications_Handler::CreateMultiplayerGame(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  TChat *v2; // ecx@1
  int v3; // eax@1
  unsigned int v4; // edx@1
  int v5; // eax@1
  int v6; // edi@1
  int result; // eax@3
  DPSESSIONDESC2 dSess2; // [sp+Ch] [bp-50h]@1

  v1 = this;
  v2 = this->Chat;
  v1->Multiplayer = 1;
  v1->HaveHostInit = 0;
  v1->PlayerOptions.CommandTurnIncrement = 2;
  v1->current_turn = 4;
  v1->PlayerOptions.CurrentTurn = 4;
  TChat::ClearChat(v2);
  v3 = TCommunications_Handler::CreateDirectPlayConversation(v1);
  RGE_Comm_Error::ShowReturn(v1->Err, v3, aDpcreateconv);
  v1->MeHost = 1;
  memset(&dSess2, 0, sizeof(dSess2));
  dSess2.dwMaxPlayers = v1->MaxGamePlayers;
  dSess2.dwSize = 80;
  v4 = v1->ApplicationGUID.x;
  dSess2.dwCurrentPlayers = 1;
  dSess2.guidApplication.x = v4;
  dSess2.dwFlags = 68;
  *(_DWORD *)&dSess2.guidApplication.s1 = *(_DWORD *)&v1->ApplicationGUID.s1;
  *(_DWORD *)&dSess2.guidApplication.c[0] = *(_DWORD *)&v1->ApplicationGUID.c[0];
  v5 = *(_DWORD *)&v1->ApplicationGUID.c[4];
  dSess2.lpszSessionName = (unsigned __int16 *)v1->MyGameTitle;
  *(_DWORD *)&dSess2.guidApplication.c[4] = v5;
  TCommunications_Handler::DebugSessionInformation(&dSess2);
  v6 = glpIDC->vfptr[8].QueryInterface((IUnknown *)glpIDC, (_GUID *)&dSess2, (void **)2);
  RGE_Comm_Error::ShowReturn(v1->Err, v6, aDpOpenCreate);
  if ( v6 )
  {
    if ( v6 == -2005466966 )
    {
      TCommunications_Handler::NotifyWindow(v1, COMM_NO_LINK);
      result = 0;
    }
    else
    {
      v1->PlayerOptions.ProgramState = 1;
      result = 0;
    }
  }
  else
  {
    TCommunications_Handler::SetRandomSeed(v1, rge_base_game->random_game_seed);
    TCommunications_Handler::AddSelfPlayer(v1);
    TCommunications_Handler::CommGetCaps(v1);
    TCommunications_Handler::DPlayGetSessionDesc(v1);
    v1->Me = 1;
    v1->PlayerOptions.HostPlayerNumber = 1;
    v1->PlayerOptions.dcoID[1] = dcoID;
    v1->PlayerOptions.Humanity[v1->Me] = 2;
    v1->HaveHostInit = 1;
    v1->PlayerOptions.ProgramState = 3;
    v1->GTDSerialNo = 2001;
    TCommunications_Handler::UpdatePlayers(v1);
    result = 1;
  }
  return result;
}

//----- (0042D720) --------------------------------------------------------
void __thiscall TCommunications_Handler::PackPlayersDown(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // ebx@1
  signed int v2; // esi@1
  unsigned int v3; // ebp@5
  char *v4; // eax@10
  char *v5; // eax@11
  signed int v6; // [sp+8h] [bp-10h]@2
  int i; // [sp+Ch] [bp-Ch]@1
  char *v8; // [sp+10h] [bp-8h]@2

  v1 = this;
  v2 = 1;
  i = 1;
  if ( this->MaxGamePlayers >= 1u )
  {
    v6 = 1;
    v8 = (char *)&this->PlayerOptions.dcoID[1];
    do
    {
      if ( TCommunications_Handler::IsPlayerHuman(v1, v2) || TCommunications_Handler::IsPlayerComputer(v1, v2) )
      {
        v5 = TCommunications_Handler::GetPlayerName(v1, v2);
        TDebuggingLog::Log(L, aPositionDLocke, v2, v5);
      }
      else
      {
        v3 = v2;
        if ( v2 <= v1->MaxGamePlayers )
        {
          while ( !TCommunications_Handler::IsPlayerHuman(v1, v3) && !TCommunications_Handler::IsPlayerComputer(v1, v3) )
          {
            if ( (signed int)++v3 > v1->MaxGamePlayers )
              goto LABEL_12;
          }
          strcpy(v1->FriendlyName[v6].Text, v1->FriendlyName[v3].Text);
          strcpy(v1->FormalName[v6].Text, v1->FormalName[v3].Text);
          v2 = i;
          *((_DWORD *)v8 + 12) = v1->PlayerOptions.PlayerReady[v3];
          *(_DWORD *)v8 = v1->PlayerOptions.dcoID[v3];
          *((_DWORD *)v8 + 22) = v1->PlayerOptions.User1[v3];
          *((_DWORD *)v8 + 32) = v1->PlayerOptions.User2[v3];
          *((_DWORD *)v8 + 42) = v1->PlayerOptions.User3[v3];
          *((_DWORD *)v8 + 52) = v1->PlayerOptions.User4[v3];
          *((_DWORD *)v8 + 62) = v1->PlayerOptions.User5[v3];
          *((_DWORD *)v8 + 72) = v1->PlayerOptions.User6[v3];
          *((_DWORD *)v8 + 82) = v1->PlayerOptions.User7[v3];
          *((_DWORD *)v8 + 92) = v1->PlayerOptions.Humanity[v3];
          *((_DWORD *)v8 + 111) = v1->LastTurnAck[v3];
          *((_DWORD *)v8 - 136) = v1->LastPlayerCommunication[v3];
          TDebuggingLog::Log(L, aMovedDD, v3, i);
          v4 = TCommunications_Handler::GetPlayerName(v1, i);
          TDebuggingLog::Log(L, aPositionDLocke, i, v4);
          TCommunications_Handler::InitPlayerInformation(v1, v3, 0, text_in, text_in);
        }
      }
LABEL_12:
      i = ++v2;
      v8 += 4;
      ++v6;
    }
    while ( v2 <= v1->MaxGamePlayers );
  }
  TCommunications_Handler::SetSelfPlayer(v1);
}

//----- (0042D960) --------------------------------------------------------
IDirectPlay3 *__thiscall TCommunications_Handler::AddSelfPlayer(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  IDirectPlay3 *result; // eax@1
  int v3; // edi@2
  DPNAME names; // [sp+8h] [bp-10h]@1

  v1 = this;
  TDebuggingLog::Log(L, aCreateThePlaye);
  names.dwFlags = 0;
  names.lpszShortName = (unsigned __int16 *)v1->MyFriendlyName;
  names.dwSize = 16;
  names.lpszLongName = (unsigned __int16 *)v1->MyFormalName;
  TDebuggingLog::Log(L, aAddingPlayerS, v1->MyFriendlyName);
  result = glpIDC;
  if ( glpIDC )
  {
    v3 = ((int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))glpIDC->vfptr[2].QueryInterface)(
           glpIDC,
           &dcoID,
           &names,
           0,
           0,
           0,
           0);
    RGE_Comm_Error::ShowReturn(v1->Err, v3, aAddSelfPlayer);
    if ( v3 )
    {
      TCommunications_Handler::CloseSession(v1);
      TCommunications_Handler::ReleaseComm(v1);
      v1->PlayerOptions.ProgramState = 1;
      result = 0;
    }
    else
    {
      TDebuggingLog::Log(L, aRcvdDpidOfD, dcoID);
      TCommunications_Handler::GetMyMultiPlayerCaps(v1);
      result = (IDirectPlay3 *)1;
    }
  }
  return result;
}

//----- (0042DA50) --------------------------------------------------------
int __thiscall TCommunications_Handler::InitJoinGame(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1

  v1 = this;
  TChat::ClearChat(this->Chat);
  v1->Multiplayer = 1;
  v1->HaveHostInit = 0;
  v1->MeHost = 0;
  v1->GTDSerialNo = 0;
  return TCommunications_Handler::CreateDirectPlayConversation(v1);
}

//----- (0042DA80) --------------------------------------------------------
IDirectPlay3 *__thiscall TCommunications_Handler::JoinMultiplayerGame(TCommunications_Handler *this, _GUID *GameGuid)
{
  TCommunications_Handler *v2; // esi@1
  IDirectPlay3 *result; // eax@2
  char *v4; // edi@3
  int v5; // edx@3
  int v6; // eax@3
  unsigned int v7; // ST08_4@3
  int v8; // eax@3
  DPSESSIONDESC2 dSess2; // [sp+Ch] [bp-50h]@3

  v2 = this;
  if ( glpIDC )
  {
    memset(&dSess2, 0, sizeof(dSess2));
    v4 = (char *)&this->SessionGUID;
    dSess2.dwSize = 80;
    *(_DWORD *)v4 = GameGuid->x;
    *((_DWORD *)v4 + 1) = *(_DWORD *)&GameGuid->s1;
    *((_DWORD *)v4 + 2) = *(_DWORD *)&GameGuid->c[0];
    v5 = *(_DWORD *)&GameGuid->c[4];
    this->MeHost = 0;
    *((_DWORD *)v4 + 3) = v5;
    dSess2.guidInstance.x = GameGuid->x;
    *(_DWORD *)&dSess2.guidInstance.s1 = *(_DWORD *)&GameGuid->s1;
    v6 = *(_DWORD *)&GameGuid->c[4];
    *(_DWORD *)&dSess2.guidInstance.c[0] = *(_DWORD *)&GameGuid->c[0];
    *(_DWORD *)&dSess2.guidInstance.c[4] = v6;
    dSess2.guidApplication.x = this->ApplicationGUID.x;
    *(_DWORD *)&dSess2.guidApplication.s1 = *(_DWORD *)&this->ApplicationGUID.s1;
    *(_DWORD *)&dSess2.guidApplication.c[0] = *(_DWORD *)&this->ApplicationGUID.c[0];
    v7 = this->SessionGUID.x;
    *(_DWORD *)&dSess2.guidApplication.c[4] = *(_DWORD *)&this->ApplicationGUID.c[4];
    TDebuggingLog::Log(L, aOpenSessionFor, v7);
    v8 = glpIDC->vfptr[8].QueryInterface((IUnknown *)glpIDC, (_GUID *)&dSess2, (void **)1);
    switch ( v8 )
    {
      case -2005466786:
        RGE_Comm_Error::ShowReturn(v2->Err, -2005466786, aJoinMpGame);
        result = 0;
        break;
      case -2005467131:
        RGE_Comm_Error::ShowReturn(v2->Err, -2005467131, aJoinMpGame);
        result = 0;
        break;
      case -2005466806:
        RGE_Comm_Error::ShowReturn(v2->Err, -2005466806, aJoinMpGame);
        TCommunications_Handler::NotifyWindow(v2, COMM_NO_NEW_PLAYERS);
        result = 0;
        break;
      default:
        if ( v8 )
        {
          RGE_Comm_Error::ShowReturn(v2->Err, v8, aJoinMpGame);
          v2->PlayerOptions.ProgramState = 1;
          result = 0;
        }
        else
        {
          result = TCommunications_Handler::AddSelfPlayer(v2);
          if ( result )
          {
            v2->PlayerOptions.ProgramState = 3;
            result = (IDirectPlay3 *)1;
          }
        }
        break;
    }
  }
  else
  {
    TDebuggingLog::Log(L, aJmpgCreateWNoV);
    result = 0;
  }
  return result;
}

//----- (0042DC20) --------------------------------------------------------
void __thiscall TCommunications_Handler::LaunchMultiplayerGame(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  unsigned int v2; // edi@1
  signed int v3; // ebx@2
  int v4; // ebp@2
  int v5; // ecx@6
  unsigned int v6; // eax@7
  unsigned int *v7; // ecx@8

  v1 = this;
  TCommunications_Handler::EnableNewPlayers((IDirectPlay2 *)&glpIDC->vfptr, 0);
  v1->PlayerOptions.ProgramState = 5;
  TCommunications_Handler::CalculatePlayerRange(v1);
  v2 = 1;
  v1->PlayerOptions.GameHasStarted = 1;
  TCommunications_Handler::ClearRXandTX(v1);
  TCommunications_Handler::PackPlayersDown(v1);
  if ( v1->MaxGamePlayers >= 1u )
  {
    v3 = 2000;
    v4 = (int)&v1->PlayerHighSerialNumber[1];
    do
    {
      if ( *(_DWORD *)(v4 + 60) )
      {
        *(_DWORD *)v4 = v3;
        TDebuggingLog::Log(L, aSetExpectedSer, v2, v3 + 1);
      }
      ++v2;
      v4 += 4;
      v3 += 2000;
    }
    while ( v2 <= v1->MaxGamePlayers );
  }
  v5 = 2000 * v1->Me;
  v1->GTDSerialNo = v5 + 1;
  TDebuggingLog::Log(L, aHostSetOwnSeri, v5 + 1);
  TCommunications_Handler::SendSharedData(v1, 1);
  v1->current_turn = v1->PlayerOptions.CommandTurnIncrement + 1;
  if ( v1->Multiplayer )
  {
    TDebuggingLog::Log(L, aClearPlayerAck);
    v6 = v1->PlayerOptions.LowPlayerNumber;
    if ( (unsigned __int16)v6 <= (unsigned int)v1->PlayerOptions.HighPlayerNumber )
    {
      v7 = &v1->LastTurnAck[v6];
      do
      {
        if ( v6 != v1->Me )
          *v7 = 0;
        ++v6;
        ++v7;
      }
      while ( v6 <= v1->PlayerOptions.HighPlayerNumber );
    }
  }
  TCommunications_Handler::ResetLastCommunicationTimes(v1);
  TCommunications_Handler::NotifyWindow(v1, COMM_UPDATE_PARAMS);
}

//----- (0042DD70) --------------------------------------------------------
int __thiscall TCommunications_Handler::GetMyMultiPlayerCaps(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  int result; // eax@2
  int v3; // edi@5
  unsigned int v4; // edx@7
  unsigned int v5; // ecx@7
  unsigned int v6; // eax@7
  unsigned int v7; // edx@7
  unsigned int v8; // eax@7
  DPCAPS dpCaps; // [sp+Ch] [bp-28h]@3

  v1 = this;
  if ( glpIDC )
  {
    memset(&dpCaps, 0, sizeof(dpCaps));
    dpCaps.dwSize = 40;
    if ( dcoID )
    {
      v3 = ((int (__stdcall *)(IDirectPlay3 *, unsigned int, DPCAPS *, signed int))glpIDC->vfptr[6].AddRef)(
             glpIDC,
             dcoID,
             &dpCaps,
             1);
      RGE_Comm_Error::ShowReturn(v1->Err, v3, aGetPlayerCaps);
      if ( v3 )
      {
        result = v3;
      }
      else
      {
        v4 = dpCaps.dwMaxBufferSize;
        v5 = dpCaps.dwMaxPlayers;
        v1->dwFlags = dpCaps.dwFlags;
        v6 = dpCaps.dwMaxQueueSize;
        v1->dwMaxBufferSize = v4;
        v7 = dpCaps.dwHundredBaud;
        v1->dwMaxQueueSize = v6;
        v8 = dpCaps.dwLatency;
        v1->RGE_Guaranteed_Delivery = 1;
        v1->dwMaxPlayers = v5;
        v1->dwHundredBaud = v7;
        v1->dwLatency = v8;
        TDebuggingLog::Log(L, aEnumeratedPlay);
        TDebuggingLog::Log(L, aLatencyD, v1->dwLatency);
        TDebuggingLog::Log(L, aMaxqueuesizeD, v1->dwMaxQueueSize);
        TDebuggingLog::Log(L, aRge_gtdDeliver, v1->RGE_Guaranteed_Delivery);
        result = 0;
      }
    }
    else
    {
      result = -2147467259;
    }
  }
  else
  {
    result = -2147467259;
  }
  return result;
}

//----- (0042DEA0) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetApplicationGUID(TCommunications_Handler *this, _GUID guid)
{
  this->ApplicationGUID = guid;
}

//----- (0042DED0) --------------------------------------------------------
IDirectPlay3 *TCommunications_Handler::GetDPInterface()
{
  return glpIDC;
}

//----- (0042DEE0) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetServiceGUID(TCommunications_Handler *this, _GUID inGuid)
{
  this->ServiceGUID = inGuid;
}

//----- (0042DF10) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetSessionGUID(TCommunications_Handler *this, _GUID inGuid)
{
  this->SessionGUID = inGuid;
}

//----- (0042DF40) --------------------------------------------------------
void __thiscall TCommunications_Handler::UpdatePlayers(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // edi@1
  signed int v2; // esi@1

  v1 = this;
  v2 = this->PlayerOptions.LowPlayerNumber;
  if ( (unsigned __int16)v2 <= (signed int)this->PlayerOptions.HighPlayerNumber )
  {
    do
      TCommunications_Handler::UpdatePlayer(v1, v2++, 0);
    while ( v2 <= v1->PlayerOptions.HighPlayerNumber );
  }
  TCommunications_Handler::NotifyWindow(v1, COMM_UPDATE_PLAYERS);
}

//----- (0042DF90) --------------------------------------------------------
void __thiscall TCommunications_Handler::UpdatePlayer(TCommunications_Handler *this, unsigned int PlayerNo, int Notify)
{
  unsigned int v3; // ebp@1
  TCommunications_Handler *v4; // ebx@1
  unsigned int v5; // edi@1
  int v6; // ecx@4
  bool v7; // zf@4
  IUnknownVtbl *v8; // ecx@11
  int v9; // esi@11
  const char *v10; // edi@19
  char *v11; // [sp+8h] [bp-24h]@5
  unsigned int v12; // [sp+Ch] [bp-20h]@5
  void *lpData; // [sp+20h] [bp-Ch]@11
  MSGFORMAT_MISSING_PLAYER m; // [sp+24h] [bp-8h]@19

  v3 = PlayerNo;
  v4 = this;
  v5 = this->PlayerOptions.dcoID[PlayerNo];
  switch ( this->PlayerOptions.Humanity[PlayerNo] )
  {
    case 0:
      TDebuggingLog::Log(L, aPDAbsent, PlayerNo);
      goto LABEL_4;
    case 3:
      TDebuggingLog::Log(L, aPDEliminated, PlayerNo);
LABEL_4:
      v6 = Notify;
      v4->PlayerOptions.dcoID[v3] = 0;
      v4->PlayerOptions.PlayerReady[v3] = 0;
      v7 = v6 == 0;
      goto LABEL_29;
    case 2:
      v12 = PlayerNo;
      v11 = aPDHuman;
      goto LABEL_9;
    case 4:
      TDebuggingLog::Log(L, aPDComputer, PlayerNo);
      goto LABEL_27;
    case 5:
      TDebuggingLog::Log(L, aPDCyborg, PlayerNo);
      goto LABEL_10;
    case 6:
      v12 = PlayerNo;
      this->PlayerOptions.PlayerReady[PlayerNo] = 1;
      v11 = aPDViewonly;
LABEL_9:
      TDebuggingLog::Log(L, v11, v12);
LABEL_10:
      if ( !v5 )
      {
        TDebuggingLog::Log(L, aPDNotDefinedUp, v3);
        return;
      }
      v8 = glpIDC->vfptr;
      PlayerNo = 0;
      ((void (__stdcall *)(IDirectPlay3 *, unsigned int, _DWORD, unsigned int *))v8[7].QueryInterface)(
        glpIDC,
        v5,
        0,
        &PlayerNo);
      lpData = calloc(PlayerNo, 1u);
      v9 = ((int (__stdcall *)(IDirectPlay3 *, unsigned int, void *, unsigned int *))glpIDC->vfptr[7].QueryInterface)(
             glpIDC,
             v5,
             lpData,
             &PlayerNo);
      RGE_Comm_Error::ShowReturn(v4->Err, v9, aGetPnameInfo);
      if ( v9 <= -2005467106 )
      {
        if ( v9 != -2005467106 && v9 != -2147024809 )
          goto LABEL_18;
        goto LABEL_23;
      }
      if ( v9 == -2005467006 )
      {
LABEL_23:
        TDebuggingLog::Log(L, aFatalErrorPlay, v9);
        strcpy(v4->FriendlyName[v3].Text, aError_2);
        v4->PlayerOptions.Humanity[v3] = 0;
LABEL_24:
        free(lpData);
        goto LABEL_28;
      }
      if ( v9 == -2005466986 )
      {
        TDebuggingLog::Log(L, aInvalidPlayerD, v5);
        if ( v4->PlayerOptions.ProgramState == 3 )
        {
          v4->PlayerOptions.Humanity[v3] = 2;
          if ( TCommunications_Handler::IsPlayerHuman(v4, v3) )
          {
            TDebuggingLog::Log(L, aInvalidPlayer);
            m.PlayerID = v5;
            TDebuggingLog::Log(L, aTxMissingPlaye, v5);
            m.Command = 63;
            TDebuggingLog::Log(L, aTxMpDD, v5, 8);
            TCommunications_Handler::FastSend(v4, 0, &m, 8u, 0, 0);
            free(lpData);
            goto LABEL_28;
          }
        }
        goto LABEL_24;
      }
      if ( v9 )
      {
LABEL_18:
        TDebuggingLog::Log(L, aUnknownFailOnU);
        v4->PlayerOptions.Humanity[v3] = 0;
        v4->PlayerOptions.dcoID[v3] = 0;
        free(lpData);
        goto LABEL_28;
      }
      v10 = (const char *)*((_DWORD *)lpData + 2);
      *(_DWORD *)&m.Command = &v4->FriendlyName[v3];
      strcpy(*(char **)&m.Command, v10);
      strcpy(v4->FormalName[v3].Text, *((const char **)lpData + 3));
      *(_DWORD *)&m.Command = &v4->FormalName[v3];
      v4->PlayerOptions.Humanity[v3] = 2;
      free(lpData);
LABEL_28:
      v7 = Notify == 0;
LABEL_29:
      if ( !v7 )
        TCommunications_Handler::NotifyWindow(v4, COMM_UPDATE_PLAYERS);
      return;
    case 1:
      TDebuggingLog::Log(L, aPDClosed, PlayerNo);
LABEL_27:
      v4->PlayerOptions.dcoID[v3] = 0;
      v4->PlayerOptions.PlayerReady[v3] = 1;
      goto LABEL_28;
    default:
      strcpy(this->FriendlyName[PlayerNo].Text, aError_3);
      TDebuggingLog::Log(L, aCommInvalidPDH, v3, this->PlayerOptions.Humanity[v3]);
      return;
  }
}

//----- (0042E380) --------------------------------------------------------
int __thiscall TCommunications_Handler::SetMyReadiness(TCommunications_Handler *this, int Ready, unsigned int User1, unsigned int User2, unsigned int User3, unsigned int User4, unsigned int User5, unsigned int User6, unsigned int User7)
{
  TCommunications_Handler *v9; // esi@1
  unsigned int v10; // eax@1
  unsigned int v11; // eax@1
  int v12; // eax@1
  char v13; // cl@1
  MSGFORMAT_SETREADYOPTIONS rdy; // [sp+10h] [bp-28h]@1

  v9 = this;
  v10 = this->Me;
  TDebuggingLog::Log(
    L,
    aSetMyReadiness,
    this->Me,
    this->PlayerOptions.PlayerReady[v10],
    this->PlayerOptions.User1[v10],
    this->PlayerOptions.User2[v10],
    this->PlayerOptions.User3[v10],
    this->PlayerOptions.User4[v10],
    this->PlayerOptions.User5[v10],
    this->PlayerOptions.User6[v10],
    this->PlayerOptions.User7[v10]);
  v9->PlayerOptions.PlayerReady[v9->Me] = Ready;
  v9->PlayerOptions.User1[v9->Me] = User1;
  v9->PlayerOptions.User2[v9->Me] = User2;
  v9->PlayerOptions.User3[v9->Me] = User3;
  v9->PlayerOptions.User4[v9->Me] = User4;
  v9->PlayerOptions.User5[v9->Me] = User5;
  v9->PlayerOptions.User6[v9->Me] = User6;
  v9->PlayerOptions.User7[v9->Me] = User7;
  rdy.Ready = Ready;
  rdy.User1 = User1;
  rdy.User4 = User4;
  v11 = v9->CommunicationsVersionCode;
  rdy.User2 = User2;
  rdy.CommunicationsVersionCode = v11;
  v12 = v9->MeHost;
  rdy.User5 = User5;
  v13 = v9->RGE_Guaranteed_Delivery;
  rdy.User3 = User3;
  rdy.User6 = User6;
  rdy.User7 = User7;
  rdy.RGEGuaranteed = v13;
  rdy.Command = 82;
  if ( !v12 )
  {
    TDebuggingLog::Log(L, aTxRdyD, 40);
    TCommunications_Handler::FastSend(v9, 0, &rdy, 0x28u, 0, 0);
  }
  TCommunications_Handler::NotifyWindow(v9, COMM_UPDATE_PARAMS);
  return 1;
}

//----- (0042E500) --------------------------------------------------------
int __thiscall TCommunications_Handler::GetClientReadiness(TCommunications_Handler *this, unsigned int PlayerNo, int *Ready, unsigned int *User1, unsigned int *User2, unsigned int *User3, unsigned int *User4, unsigned int *User5, unsigned int *User6, unsigned int *User7)
{
  *Ready = this->PlayerOptions.PlayerReady[PlayerNo];
  *User1 = this->PlayerOptions.User1[PlayerNo];
  *User2 = this->PlayerOptions.User2[PlayerNo];
  *User3 = this->PlayerOptions.User3[PlayerNo];
  *User4 = this->PlayerOptions.User4[PlayerNo];
  *User5 = this->PlayerOptions.User5[PlayerNo];
  *User6 = this->PlayerOptions.User6[PlayerNo];
  *User7 = this->PlayerOptions.User7[PlayerNo];
  return 1;
}

//----- (0042E580) --------------------------------------------------------
int __thiscall TCommunications_Handler::IsPlayerReady(TCommunications_Handler *this, unsigned int PlayerNo)
{
  int result; // eax@3

  if ( PlayerNo < 1 || PlayerNo > this->MaxGamePlayers )
    result = 0;
  else
    result = this->PlayerOptions.PlayerReady[PlayerNo];
  return result;
}

//----- (0042E5B0) --------------------------------------------------------
int __thiscall TCommunications_Handler::ComputerPlayerGameStart(TCommunications_Handler *this)
{
  int result; // eax@2

  if ( this->Multiplayer )
    result = this->current_turn > 6;
  else
    result = 1;
  return result;
}

//----- (0042E5E0) --------------------------------------------------------
int __thiscall TCommunications_Handler::MultiplayerGameStart(TCommunications_Handler *this)
{
  int result; // eax@2

  if ( this->Multiplayer )
  {
    if ( this->current_turn <= 6 )
    {
      TCommunications_Handler::DoCycle(this, 0);
      result = 0;
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

//----- (0042E610) --------------------------------------------------------
int __thiscall TCommunications_Handler::AllPlayersReady(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // edi@1
  signed int v2; // esi@1
  char *v3; // ebx@2
  int result; // eax@6

  v1 = this;
  v2 = this->PlayerOptions.LowPlayerNumber;
  if ( (unsigned __int16)v2 > (signed int)this->PlayerOptions.HighPlayerNumber )
  {
    result = 1;
  }
  else
  {
    v3 = (char *)&this->PlayerOptions.PlayerReady[v2];
    while ( !TCommunications_Handler::IsPlayerHuman(v1, v2) || *(_DWORD *)v3 )
    {
      ++v2;
      v3 += 4;
      if ( v2 > v1->PlayerOptions.HighPlayerNumber )
        return 1;
    }
    result = 0;
  }
  return result;
}

//----- (0042E670) --------------------------------------------------------
int __thiscall TCommunications_Handler::DPlayGetSessionDesc(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // ebx@1
  int result; // eax@2
  _DWORD *v3; // esi@3
  int v4; // edi@5
  int v5; // ecx@6
  unsigned int v6; // eax@6
  unsigned int dwSize; // [sp+Ch] [bp-4h]@3

  v1 = this;
  if ( glpIDC )
  {
    ((void (__stdcall *)(IDirectPlay3 *, _DWORD, unsigned int *))glpIDC->vfptr[7].AddRef)(glpIDC, 0, &dwSize);
    v3 = calloc(dwSize, 1u);
    if ( v3 )
    {
      v4 = ((int (__stdcall *)(IDirectPlay3 *, _DWORD *, unsigned int *))glpIDC->vfptr[7].AddRef)(glpIDC, v3, &dwSize);
      RGE_Comm_Error::ShowReturn(v1->Err, v4, aGetSessionDesc);
      if ( !v4 )
      {
        v5 = (int)&v1->SessionGUID;
        *(_DWORD *)v5 = v3[2];
        *(_DWORD *)(v5 + 4) = v3[3];
        *(_DWORD *)(v5 + 8) = v3[4];
        *(_DWORD *)(v5 + 12) = v3[5];
        v6 = v3[11];
        v1->CurrentPlayers = v6;
        TDebuggingLog::Log(L, aRxCurrentPlaye, v6);
      }
      free(v3);
      result = v4;
    }
    else
    {
      result = -2147024882;
    }
  }
  else
  {
    result = -2147467259;
  }
  return result;
}

//----- (0042E730) --------------------------------------------------------
int __thiscall TCommunications_Handler::CommGetCaps(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  int result; // eax@2
  IUnknownVtbl *v3; // ecx@3
  int v4; // eax@3
  int v5; // edi@3
  DPCAPS DPCaps; // [sp+14h] [bp-28h]@3

  v1 = this;
  if ( glpIDC )
  {
    v3 = glpIDC->vfptr;
    DPCaps.dwSize = 40;
    v4 = ((int (__stdcall *)(IDirectPlay3 *, DPCAPS *, _DWORD))v3[4].Release)(glpIDC, &DPCaps, 0);
    RGE_Comm_Error::ShowReturn(v1->Err, v4, aGetCaps);
    v5 = ((int (__stdcall *)(IDirectPlay3 *, DPCAPS *, signed int))glpIDC->vfptr[4].Release)(glpIDC, &DPCaps, 1);
    RGE_Comm_Error::ShowReturn(v1->Err, v5, aGetGuaranteedC);
    TDebuggingLog::Log(L, aDirectPlayIiiC);
    TDebuggingLog::Log(L, aMaxBufferSizeD, DPCaps.dwMaxBufferSize);
    TDebuggingLog::Log(L, aMaxQueueSizeD, DPCaps.dwMaxQueueSize);
    TDebuggingLog::Log(L, aMaxPlayersD, DPCaps.dwMaxPlayers);
    TDebuggingLog::Log(L, aBaudRateD00, DPCaps.dwHundredBaud);
    TDebuggingLog::Log(L, aLatencyD_1, DPCaps.dwLatency);
    TDebuggingLog::Log(L, aHeaderLengthD, DPCaps.dwHeaderLength);
    TDebuggingLog::Log(L, aTimeoutD, DPCaps.dwTimeout);
    v1->ServiceTimeout = DPCaps.dwTimeout;
    if ( DPCaps.dwFlags & 0x20 )
      TDebuggingLog::Log(L, aGuaranteedOpti);
    else
      TDebuggingLog::Log(L, aNotGuaranteedO);
    if ( DPCaps.dwFlags & 2 )
      TDebuggingLog::Log(L, aThisPlayerIsTh);
    else
      TDebuggingLog::Log(L, aNotTheHost_);
    if ( DPCaps.dwFlags & 0x10 )
      TDebuggingLog::Log(L, aOptimizedKeepa);
    else
      TDebuggingLog::Log(L, aNotOptimizedFo);
    if ( DPCaps.dwFlags & 0x40 )
      TDebuggingLog::Log(L, aGuaranteedDeli);
    else
      TDebuggingLog::Log(L, aNotGuaranteedS);
    result = v5;
    v1->RGE_Guaranteed_Delivery = 1;
  }
  else
  {
    result = -2147467259;
  }
  return result;
}

//----- (0042E920) --------------------------------------------------------
int __thiscall TCommunications_Handler::CloseSession(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  int v2; // edi@1
  int v3; // eax@3
  RGE_Comm_Error *v4; // ecx@3
  signed int v5; // eax@3
  unsigned int *v6; // ecx@4

  v1 = this;
  v2 = 0;
  TDebuggingLog::Log(L, aCloseSessionCa);
  if ( glpIDC )
    v2 = glpIDC->vfptr[1].AddRef((IUnknown *)glpIDC);
  v3 = (int)&v1->SessionGUID;
  *(_DWORD *)v3 = v1->NullGUID.x;
  *(_DWORD *)(v3 + 4) = *(_DWORD *)&v1->NullGUID.s1;
  *(_DWORD *)(v3 + 8) = *(_DWORD *)&v1->NullGUID.c[0];
  v4 = v1->Err;
  *(_DWORD *)(v3 + 12) = *(_DWORD *)&v1->NullGUID.c[4];
  RGE_Comm_Error::ShowReturn(v4, v2, aCloseSession);
  v5 = 1;
  if ( v1->MaxGamePlayers >= 1u )
  {
    v6 = &v1->LastTurnAck[1];
    do
    {
      *v6 = 0;
      ++v5;
      ++v6;
    }
    while ( v5 <= v1->MaxGamePlayers );
  }
  return v2;
}

//----- (0042E9B0) --------------------------------------------------------
int __thiscall TCommunications_Handler::ReleaseComm(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  unsigned int v2; // eax@2
  int v3; // eax@2
  int v4; // esi@2

  v1 = this;
  if ( glpIDC )
  {
    v2 = glpIDC->vfptr->Release((IUnknown *)glpIDC);
    TDebuggingLog::Log(L, a1_releaseCommL, v2);
    v3 = (int)&v1->NullGUID;
    v4 = (int)&v1->ServiceGUID;
    *(_DWORD *)v4 = *(_DWORD *)v3;
    *(_DWORD *)(v4 + 4) = *(_DWORD *)(v3 + 4);
    *(_DWORD *)(v4 + 8) = *(_DWORD *)(v3 + 8);
    *(_DWORD *)(v4 + 12) = *(_DWORD *)(v3 + 12);
    glpIDC = 0;
  }
  return 0;
}

//----- (0042EA10) --------------------------------------------------------
int __thiscall TCommunications_Handler::Kick(TCommunications_Handler *this, unsigned int PlayerNo)
{
  TCommunications_Handler *v2; // esi@1
  unsigned int v3; // eax@5
  unsigned int v4; // ecx@6
  unsigned int v5; // ST10_4@6
  int result; // eax@11
  MSGFORMAT_KILL_PLAYER kp; // [sp+8h] [bp-Ch]@6

  v2 = this;
  if ( PlayerNo >= 1
    && PlayerNo <= this->MaxGamePlayers
    && glpIDC
    && TCommunications_Handler::IsPlayerHuman(this, PlayerNo) )
  {
    v3 = v2->PlayerOptions.dcoID[PlayerNo];
    if ( v3 )
    {
      v4 = v2->current_turn;
      v5 = v2->PlayerOptions.dcoID[PlayerNo];
      kp.PlayerNo = PlayerNo;
      kp.dcoID = v3;
      kp.CurrentTurn = v4;
      TDebuggingLog::Log(L, aSentToAllDropP, PlayerNo, v5);
      TDebuggingLog::Log(L, aTxKp3DD, PlayerNo, 12);
      TCommunications_Handler::CommOut(v2, 0, 75, &kp, 12, 0);
      if ( !v2->PlayerStopTurn[PlayerNo] )
        TCommunications_Handler::DropDeadPlayer(v2, PlayerNo, v2->PlayerOptions.dcoID[PlayerNo]);
    }
    TCommunications_Handler::NotifyWindow(v2, COMM_UPDATE_PLAYERS);
    if ( v2->MeHost )
    {
      if ( v2->current_turn <= 6 )
        TCommunications_Handler::SendSharedData(v2, 1);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0042EB10) --------------------------------------------------------
IDirectPlay3 *__thiscall TCommunications_Handler::DestroyMyPlayer(TCommunications_Handler *this)
{
  IDirectPlay3 *result; // eax@1
  TCommunications_Handler *v2; // edi@1
  int v3; // esi@4

  result = glpIDC;
  v2 = this;
  if ( glpIDC )
  {
    if ( dcoID )
    {
      v3 = ((int (__stdcall *)(_DWORD, _DWORD))glpIDC->vfptr[3].QueryInterface)(glpIDC, dcoID);
      RGE_Comm_Error::ShowReturn(v2->Err, v3, aReleasePlayer);
      if ( !v3 )
      {
        dcoID = 0;
        v2->Me = 0;
      }
      result = (IDirectPlay3 *)v3;
    }
    else
    {
      result = 0;
    }
  }
  return result;
}

//----- (0042EB60) --------------------------------------------------------
char *__thiscall TCommunications_Handler::SetMyGameOptions(TCommunications_Handler *this, char *vpData, unsigned int dwSize)
{
  TCommunications_Handler *v3; // ebx@1
  char *result; // eax@2

  v3 = this;
  if ( dwSize > 0x7D0 )
    return 0;
  TCommunications_Handler::FreeOptions(this);
  if ( vpData && dwSize )
  {
    result = (char *)operator new(dwSize + 1);
    v3->OptionsData = result;
    if ( !result )
      return result;
    qmemcpy(result, vpData, dwSize);
    v3->PlayerOptions.DataSizeToFollow = dwSize;
  }
  if ( v3->MeHost )
    v3->PlayerOptions.NeedsToBeSent = 1;
  TDebuggingLog::Log(L, aHostSetOptions, dwSize);
  return (char *)1;
}

//----- (0042EBF0) --------------------------------------------------------
char *__thiscall TCommunications_Handler::GetMyGameOptions(TCommunications_Handler *this, unsigned int *dwSize)
{
  *dwSize = this->PlayerOptions.DataSizeToFollow;
  return this->OptionsData;
}

//----- (0042EC10) --------------------------------------------------------
void __thiscall TCommunications_Handler::FreeOptions(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1
  char *v2; // ST00_4@2

  v1 = this;
  if ( this->OptionsData )
  {
    v2 = this->OptionsData;
    this->PlayerOptions.DataSizeToFollow = 0;
    operator delete(v2);
    v1->OptionsData = 0;
  }
}

//----- (0042EC40) --------------------------------------------------------
int __cdecl StringFromGUID(_GUID *lpguid, unsigned __int16 *lpwsz)
{
  unsigned __int16 *v2; // eax@1
  unsigned int v3; // esi@1

  *lpwsz = 123;
  v2 = lpwsz + 1;
  v3 = 0;
  do
  {
    if ( GuidMap[v3] == 45 )
    {
      *v2 = 45;
    }
    else
    {
      ++v2;
      *(v2 - 1) = wszDigits[(unsigned int)*((_BYTE *)&lpguid->x + (unsigned __int8)GuidMap[v3]) >> 4];
      *v2 = wszDigits[*((_BYTE *)&lpguid->x + (unsigned __int8)GuidMap[v3]) & 0xF];
    }
    ++v2;
    ++v3;
  }
  while ( v3 < 0x14 );
  *v2 = 125;
  v2[1] = 0;
  return 38;
}

//----- (0042ECC0) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetHostPlayerNumber(TCommunications_Handler *this, unsigned int PlayerNo)
{
  this->PlayerOptions.HostPlayerNumber = PlayerNo;
}

//----- (0042ECD0) --------------------------------------------------------
unsigned int __thiscall TCommunications_Handler::GetHostPlayerNumber(TCommunications_Handler *this)
{
  return this->PlayerOptions.HostPlayerNumber;
}

//----- (0042ECE0) --------------------------------------------------------
void __stdcall TCommunications_Handler::DebugSessionInformation(DPSESSIONDESC2 *dpsd)
{
  unsigned __int16 wszSPGuid[39]; // [sp+8h] [bp-50h]@1

  TDebuggingLog::Log(L, aInformationInD);
  TDebuggingLog::Log(L, aSizeDpsessiond, dpsd->dwSize);
  TDebuggingLog::Log(L, aFlagsD, dpsd->dwFlags);
  TDebuggingLog::Log(L, aInstanceGuidDa, dpsd->guidInstance.x);
  TDebuggingLog::Log(L, aData2D, dpsd->guidInstance.s1);
  TDebuggingLog::Log(L, aData3D, dpsd->guidInstance.s2);
  TDebuggingLog::Log(L, aData4U, dpsd->guidInstance.c);
  StringFromGUID(&dpsd->guidInstance, wszSPGuid);
  TDebuggingLog::Log(L, aInstanceGuidSt, wszSPGuid);
  TDebuggingLog::Log(L, aApplicatnGuidD, dpsd->guidApplication.x);
  TDebuggingLog::Log(L, aData2D, dpsd->guidApplication.s1);
  TDebuggingLog::Log(L, aData3D, dpsd->guidApplication.s2);
  TDebuggingLog::Log(L, aData4U, dpsd->guidApplication.c);
  TDebuggingLog::Log(L, aMaxPlayersD_1, dpsd->dwMaxPlayers);
  TDebuggingLog::Log(L, aCurrentPlayers, dpsd->dwCurrentPlayers);
  TDebuggingLog::Log(L, aReserved1D, dpsd->dwReserved1);
  TDebuggingLog::Log(L, aReserved2D, dpsd->dwReserved2);
  TDebuggingLog::Log(L, aUser1D, dpsd->dwUser1);
  TDebuggingLog::Log(L, aUser2D, dpsd->dwUser2);
  TDebuggingLog::Log(L, aUser3D, dpsd->dwUser3);
  TDebuggingLog::Log(L, aUser4D, dpsd->dwUser4);
  TDebuggingLog::Log(L, aEnd);
}

//----- (0042EF00) --------------------------------------------------------
int __stdcall TCommunications_Handler::EnableNewPlayers(IDirectPlay2 *lpDP2, int bEnable)
{
  int result; // eax@2
  int v4; // esi@4
  unsigned int v5; // eax@4

  if ( lpDP2 )
  {
    result = lpDP2->vfptr->QueryInterface((IUnknown *)lpDP2, &IID_IDirectPlay, (void **)&lpDP2);
    if ( result >= 0 )
    {
      v4 = ((int (__stdcall *)(IDirectPlay2 *, int))lpDP2->vfptr[3].AddRef)(lpDP2, bEnable);
      v5 = lpDP2->vfptr->Release((IUnknown *)lpDP2);
      TDebuggingLog::Log(L, aReleasedToLink, v5);
      result = v4;
    }
  }
  else
  {
    result = -2147024809;
  }
  return result;
}

//----- (0042EF60) --------------------------------------------------------
void __thiscall TCommunications_Handler::OutOfSync(TCommunications_Handler *this, int Status, unsigned int StopTime)
{
  this->OutOfSyncFlag = Status;
  this->dwStopTime = StopTime;
}

//----- (0042EF80) --------------------------------------------------------
int __thiscall TCommunications_Handler::SendZoneMessage(TCommunications_Handler *this, char *Data, unsigned int dwSize)
{
  TCommunications_Handler *v3; // esi@1
  int result; // eax@2
  _GUID v5; // ST08_16@3
  int v6; // eax@3

  v3 = this;
  if ( TCommunications_Handler::IsLobbyLaunched(this) )
  {
    TDebuggingLog::Log(L, aSendingZoneMes);
    TDebuggingLog::Log(L, aTxZoneMsgU, dwSize);
    *(_QWORD *)&v5.x = *(_QWORD *)&rge_base_game->prog_info->zone_guid.x;
    *(_QWORD *)&v5.c[0] = *(_QWORD *)&rge_base_game->prog_info->zone_guid.c[0];
    v6 = RGE_Lobby::SendZoneMessage(v3->Lobby, Data, dwSize, v5);
    if ( v6 )
    {
      RGE_Comm_Error::ShowReturn(v3->Err, v6, aSendgameoption);
      result = 0;
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    TDebuggingLog::Log(L, aNotLobbyLaunch);
    result = 0;
  }
  return result;
}

//----- (0042F040) --------------------------------------------------------
int __stdcall EnumPlayersCallback2(unsigned int pidID, unsigned int dwPlayerType, DPNAME *lpName, unsigned int dwFlags, void *lpContext)
{
  int v5; // eax@2
  int v6; // edx@2
  char *v7; // ecx@3
  int v8; // edi@6

  if ( pidID
    && (v5 = *((_WORD *)lpContext + 2953),
        v6 = *((_WORD *)lpContext + 2952),
        (unsigned __int16)v5 <= (signed int)(unsigned __int16)v6) )
  {
    v7 = (char *)lpContext + 4 * v5 + 5476;
    while ( *(_DWORD *)v7 != pidID )
    {
      ++v5;
      v7 += 4;
      if ( v5 > v6 )
        goto LABEL_6;
    }
    v8 = v5;
  }
  else
  {
LABEL_6:
    v8 = 0;
  }
  sprintf(x, aEnumDNameSIdD, pidID, lpName->lpszShortName, v8);
  TDebuggingLog::Log(L, aEnumDebugS, x);
  TDebuggingLog::Log(L, aForceenumDName, pidID, lpName->lpszShortName, v8);
  TDebuggingLog::Log(L, aFillPlayerInfo);
  TCommunications_Handler::UpdatePlayerInformation(
    (TCommunications_Handler *)lpContext,
    pidID,
    lpName->lpszShortNameA,
    lpName->lpszLongNameA);
  return 1;
}

//----- (0042F110) --------------------------------------------------------
void __thiscall TCommunications_Handler::ForcePlayerEnumeration(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1

  v1 = this;
  TDebuggingLog::Log(L, aForceCallingEn);
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD))glpIDC->vfptr[4].QueryInterface)(
    glpIDC,
    0,
    EnumPlayersCallback2,
    v1,
    0);
}

//----- (0042F140) --------------------------------------------------------
void __thiscall TCommunications_Handler::ForcePlayerDestroyAndCreate(TCommunications_Handler *this)
{
  TCommunications_Handler *v1; // esi@1

  v1 = this;
  TDebuggingLog::Log(L, aForceSelfPlaye);
  ((void (__stdcall *)(_DWORD, _DWORD))glpIDC->vfptr[3].QueryInterface)(glpIDC, dcoID);
  dcoID = 0;
  TCommunications_Handler::AddSelfPlayer(v1);
  TDebuggingLog::Log(L, aCreateCalled_);
}

//----- (0042F190) --------------------------------------------------------
void TCommunications_Handler::ForceNameChange()
{
  IUnknownVtbl *v1; // ecx@1
  DPNAME dpn; // [sp+0h] [bp-30h]@1
  char test[32]; // [sp+10h] [bp-20h]@1

  TDebuggingLog::Log(L, aForceNameChang);
  *(_DWORD *)&test[8] = dword_5832C4;
  *(_DWORD *)&test[4] = dword_5832C0;
  *(_DWORD *)&test[15] = 0;
  *(_DWORD *)&test[19] = 0;
  test[14] = byte_5832CA;
  *(_DWORD *)&test[23] = 0;
  *(_DWORD *)test = *(_DWORD *)aTemp_0;
  *(_DWORD *)&test[27] = 0;
  dpn.lpszLongName = (unsigned __int16 *)test;
  *(_WORD *)&test[12] = word_5832C8;
  test[31] = 0;
  dpn.lpszShortName = (unsigned __int16 *)test;
  v1 = glpIDC->vfptr;
  dpn.dwSize = 16;
  ((void (__stdcall *)(IDirectPlay3 *, unsigned int, DPNAME *, signed int))v1[10].QueryInterface)(
    glpIDC,
    dcoID,
    &dpn,
    2);
}
// 5832C0: using guessed type int dword_5832C0;
// 5832C4: using guessed type int dword_5832C4;
// 5832C8: using guessed type __int16 word_5832C8;
// 5832CA: using guessed type char byte_5832CA;

//----- (0042F230) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetSpeedV1(TCommunications_Handler *this, unsigned int v1)
{
  RGE_Communications_Speed *v2; // ecx@1

  v2 = this->Speed;
  RGE_Communications_Speed::SetV1(v1);
}

//----- (0042F250) --------------------------------------------------------
void __thiscall TCommunications_Handler::SetSpeedV2(TCommunications_Handler *this, unsigned int v2)
{
  RGE_Communications_Speed *ecx1; // ecx@1

  ecx1 = this->Speed;
  RGE_Communications_Speed::SetV2(v2);
}

//----- (0042F270) --------------------------------------------------------
int __thiscall TCommunications_Handler::IsPlayerOutOfSync(TCommunications_Handler *this, unsigned int pnum, unsigned int worldturn)
{
  return RGE_Communications_Synchronize::IsPlayerOutOfSync(this->Sync, pnum, worldturn);
}
