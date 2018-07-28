
//----- (00432FF0) --------------------------------------------------------
void __thiscall RGE_Communications_Synchronize::RGE_Communications_Synchronize(RGE_Communications_Synchronize *this, TCommunications_Handler *c)
{
  RGE_Communications_Synchronize *v2; // esi@1
  int v3; // eax@1
  signed int v4; // edx@1

  v2 = this;
  this->Comm = c;
  this->CheckTime = 1000;
  this->CheckTurn = 10;
  TDebuggingLog::Log(L, aCheckTurnD, 10);
  v2->StopOnSyncFail = 1;
  v2->DoChecksums = 1;
  v2->LastResult = 1;
  v2->NewData = 0;
  v2->Offset = 0;
  v2->LastWorldRandom = 0;
  v2->GameWorldChecksum = 0;
  v2->SendChatMsgs = 0;
  v2->DialogOnSyncFail = 0;
  v3 = (int)&v2->Check[0].WTurn;
  v4 = 55;
  do
  {
    *(_DWORD *)(v3 - 4) = 0;
    *(_DWORD *)v3 = 0;
    *(_DWORD *)(v3 + 4) = 0;
    *(_DWORD *)(v3 + 8) = 0;
    *(_DWORD *)(v3 + 12) = 0;
    *(_DWORD *)(v3 + 16) = 0;
    *(_DWORD *)(v3 + 20) = 0;
    *(_DWORD *)(v3 + 24) = 0;
    *(_DWORD *)(v3 - 8) = 0;
    v3 += 36;
    --v4;
  }
  while ( v4 );
}

//----- (00433070) --------------------------------------------------------
void __thiscall RGE_Communications_Synchronize::~RGE_Communications_Synchronize(RGE_Communications_Synchronize *this)
{
  char *v1; // eax@1
  signed int v2; // edx@1

  v1 = (char *)&this->Check[0].WTurn;
  v2 = 55;
  do
  {
    *((_DWORD *)v1 - 1) = 0;
    *(_DWORD *)v1 = 0;
    *((_DWORD *)v1 + 1) = 0;
    *((_DWORD *)v1 + 2) = 0;
    *((_DWORD *)v1 + 3) = 0;
    *((_DWORD *)v1 + 4) = 0;
    *((_DWORD *)v1 + 5) = 0;
    *((_DWORD *)v1 + 6) = 0;
    *((_DWORD *)v1 - 2) = 0;
    v1 += 36;
    --v2;
  }
  while ( v2 );
}

//----- (004330A0) --------------------------------------------------------
int __thiscall RGE_Communications_Synchronize::Add(RGE_Communications_Synchronize *this, unsigned int player, unsigned int worldtime, unsigned int worldturn, unsigned int worldrandom, int cs1, int cs2, int cs3, int cs4, int cs5)
{
  int result; // eax@2
  unsigned int v11; // eax@3

  if ( this->DoChecksums )
  {
    v11 = this->Offset + 1;
    this->Offset = v11;
    if ( v11 >= 0x36 )
      this->Offset = 0;
    this->Check[this->Offset].WTime = worldtime;
    this->Check[this->Offset].WTurn = worldturn;
    this->Check[this->Offset].cs1 = cs1;
    this->Check[this->Offset].cs2 = cs2;
    this->Check[this->Offset].cs3 = cs3;
    *((_DWORD *)&this->Comm + 9 * (this->Offset + 2)) = cs4;
    this->Check[this->Offset].cs5 = cs5;
    this->Check[this->Offset].Random = worldrandom;
    this->Check[this->Offset].PlayerNo = player;
    this->NewData = 1;
    result = RGE_Communications_Synchronize::ValidateChecksums(
               this,
               player,
               worldtime,
               worldturn,
               worldrandom,
               cs1,
               cs2,
               cs3,
               cs4,
               cs5);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00433180) --------------------------------------------------------
int __thiscall RGE_Communications_Synchronize::ValidateChecksums(RGE_Communications_Synchronize *this, unsigned int player, unsigned int worldtime, unsigned int worldturn, unsigned int worldrandom, int cs1, int cs2, int cs3, int cs4, int cs5)
{
  RGE_Communications_Synchronize *v10; // esi@1
  signed int v11; // ebx@1
  int result; // eax@2
  unsigned int v13; // ecx@3
  int v14; // eax@3

  v10 = this;
  v11 = 0;
  if ( !this->NewData )
    return this->LastResult;
  this->NewData = 0;
  this->LastResult = 0;
  v13 = 1;
  v14 = (int)&v10->Check[1].WTime;
  while ( 1 )
  {
    if ( *(_DWORD *)(v14 + 4) != worldturn )
      goto LABEL_7;
    if ( *(_DWORD *)v14 != worldtime )
    {
      v11 = 1;
LABEL_7:
      if ( *(_DWORD *)v14 != worldtime )
        goto LABEL_15;
    }
    if ( *(_DWORD *)(v14 + 8) != cs1
      || *(_DWORD *)(v14 + 12) != cs2
      || *(_DWORD *)(v14 + 16) != cs3
      || *(_DWORD *)(v14 + 20) != cs4
      || *(_DWORD *)(v14 + 24) != cs5
      || *(_DWORD *)(v14 + 28) != worldrandom )
    {
      v11 = 1;
    }
LABEL_15:
    if ( v11 )
      break;
    ++v13;
    v14 += 36;
    if ( v13 > 0x36 )
    {
      TDebuggingLog::Log(L, aPDInSync_Wtime, player, worldtime, worldturn, worldrandom, cs1);
      result = 1;
      v10->LastResult = 1;
      return result;
    }
  }
  RGE_Communications_Synchronize::LogChecksums(v10, player, worldtime, worldturn, cs1, cs2, cs3, cs4, cs5, worldrandom);
  TCommunications_Handler::NotifyWindowParam(v10->Comm, COMM_SYNC_ERROR, worldturn);
  v10->LastResult = 0;
  return 0;
}

//----- (00433290) --------------------------------------------------------
signed int __thiscall RGE_Communications_Synchronize::DoChecksum(RGE_Communications_Synchronize *this, unsigned int turn)
{
  RGE_Communications_Synchronize *v2; // esi@1
  unsigned int v3; // ebp@1
  signed int result; // eax@2
  RGE_Game_World *v5; // eax@3
  signed int v6; // edi@9
  RGE_Game_World *v7; // eax@9
  int v8; // eax@10
  RGE_Base_Game *v9; // ecx@10
  int v10; // edi@11
  int v11; // eax@11
  int v12; // ebx@11
  int v13; // ST20_4@11
  int v14; // ST1C_4@11
  int v15; // ST18_4@11
  int v16; // ST14_4@11
  unsigned int v17; // ST0C_4@11
  unsigned int v18; // eax@11
  int cs3; // [sp+10h] [bp-10Ch]@7
  int cs2; // [sp+14h] [bp-108h]@7
  int cs4; // [sp+18h] [bp-104h]@7
  char tmp[255]; // [sp+1Ch] [bp-100h]@8

  v2 = this;
  v3 = 0;
  if ( this->DoChecksums )
  {
    v5 = rge_base_game->world;
    if ( v5 )
      v3 = v5->world_time;
    if ( turn >= this->CheckTurn )
    {
      TDebuggingLog::Log(L, aSyncCheckAtTur, this->CheckTurn);
      v2->CheckTurn += 4;
      cs2 = 0;
      cs3 = 0;
      cs4 = 0;
      RGE_Base_Game::GetWorldChecksums(rge_base_game, &cs2, &cs3, &cs4);
      if ( v2->SendChatMsgs )
      {
        sprintf(tmp, aWorldtimeLdRan, v3, v2->LastWorldRandom, v2->GameWorldChecksum);
        TCommunications_Handler::SendChatMsgAll(v2->Comm, tmp);
      }
      UnifiedVisibleChecksum = RGE_Visible_Map::checksumUnifiedVisible((*rge_base_game->world->players)->visible);
      v6 = 1;
      v7 = rge_base_game->world;
      if ( v7->player_num > 1 )
      {
        do
        {
          v8 = RGE_Visible_Map::checksumVisible(v7->players[v6]->visible);
          v9 = rge_base_game;
          VisibleChecksum[v6++] = v8;
          v7 = v9->world;
        }
        while ( v6 < v7->player_num );
      }
      v10 = UnifiedVisibleChecksum;
      v11 = PathingSystem::checksum(&pathSystem);
      v12 = v11;
      v13 = v11;
      v14 = cs4;
      v15 = cs3;
      v16 = cs2;
      v17 = v2->LastWorldRandom;
      v18 = TCommunications_Handler::WhoAmI(v2->Comm);
      RGE_Communications_Synchronize::Add(v2, v18, v3, turn, v17, v10, v16, v15, v14, v13);
      TCommunications_Handler::SendChecksumMessage(v2->Comm, v3, v2->LastWorldRandom, v10, cs2, cs3, cs4, v12);
      TDebuggingLog::Log(L, aChecksumTDWtDR, turn, v3, v2->LastWorldRandom, v2->GameWorldChecksum);
      TDebuggingLog::FlushLog(L);
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

//----- (00433450) --------------------------------------------------------
void __thiscall RGE_Communications_Synchronize::SetLastWorldRandom(RGE_Communications_Synchronize *this, unsigned int lwr)
{
  this->LastWorldRandom = lwr;
}

//----- (00433460) --------------------------------------------------------
void __thiscall RGE_Communications_Synchronize::LogChecksums(RGE_Communications_Synchronize *this, unsigned int player, unsigned int worldtime, unsigned int worldturn, int cs1, int cs2, int cs3, int cs4, int cs5, unsigned int random)
{
  RGE_Communications_Synchronize *v10; // esi@1
  FILE *v11; // ebx@1
  int v12; // esi@5
  TDebuggingLog *v13; // edx@32
  unsigned int v14; // ebp@34
  TDebuggingLog *v15; // edx@37
  char *v16; // eax@39
  int v17; // eax@41
  TDebuggingLog *v18; // edx@46
  signed int v19; // [sp+10h] [bp-20Ch]@5
  int *v20; // [sp+10h] [bp-20Ch]@34
  RGE_Communications_Synchronize *v21; // [sp+14h] [bp-208h]@1
  char TBuff[513]; // [sp+18h] [bp-204h]@1

  v10 = this;
  v21 = this;
  v11 = fopen(aCAoesync_txt, aWt);
  sprintf(TBuff, aAddingPDWtimeD, player, worldtime, worldturn, cs1, cs2, cs3, cs4, cs5, random);
  TDebuggingLog::Log(L, TBuff);
  if ( v11 )
  {
    fputs(TBuff, v11);
    fputs(Str, v11);
  }
  sprintf(TBuff, aPlrWrldtimeCom);
  TDebuggingLog::Log(L, TBuff);
  if ( v11 )
  {
    fputs(TBuff, v11);
    fputs(Str, v11);
  }
  v12 = (int)&v10->Check[1].WTime;
  v19 = 53;
  do
  {
    sprintf(
      TBuff,
      a_2d_8d_8d_6d_8,
      *(_DWORD *)(v12 - 4),
      *(_DWORD *)v12,
      *(_DWORD *)(v12 + 4),
      *(_DWORD *)(v12 + 28),
      *(_DWORD *)(v12 + 8),
      *(_DWORD *)(v12 + 12),
      *(_DWORD *)(v12 + 16),
      *(_DWORD *)(v12 + 20),
      *(_DWORD *)(v12 + 24));
    TDebuggingLog::Log(L, TBuff);
    if ( v11 )
    {
      fputs(TBuff, v11);
      fputs(Str, v11);
    }
    if ( *(_DWORD *)(v12 + 4) == worldturn && *(_DWORD *)v12 != worldtime )
    {
      sprintf(TBuff, aWorldTimeIsOut, worldtime, *(_DWORD *)v12, worldturn);
      TDebuggingLog::Log(L, TBuff);
      if ( v11 )
      {
        fputs(TBuff, v11);
        fputs(Str, v11);
      }
    }
    if ( *(_DWORD *)v12 == worldtime )
    {
      if ( *(_DWORD *)(v12 + 28) != random )
      {
        sprintf(TBuff, aMismatchedRand, random, *(_DWORD *)(v12 + 28));
        TDebuggingLog::Log(L, TBuff);
        if ( v11 )
        {
          fputs(TBuff, v11);
          fputs(Str, v11);
        }
      }
      if ( *(_DWORD *)(v12 + 8) != cs1 )
      {
        sprintf(TBuff, aMismatchedUnif);
        TDebuggingLog::Log(L, TBuff);
        if ( v11 )
        {
          fputs(TBuff, v11);
          fputs(Str, v11);
        }
      }
      if ( *(_DWORD *)(v12 + 12) != cs2 )
      {
        sprintf(TBuff, aMismatchedChec);
        TDebuggingLog::Log(L, TBuff);
        if ( v11 )
        {
          fputs(TBuff, v11);
          fputs(Str, v11);
        }
      }
      if ( *(_DWORD *)(v12 + 16) != cs3 )
      {
        sprintf(TBuff, aMismatched__po);
        TDebuggingLog::Log(L, TBuff);
        if ( v11 )
        {
          fputs(TBuff, v11);
          fputs(Str, v11);
        }
      }
      if ( *(_DWORD *)(v12 + 20) != cs4 )
      {
        sprintf(TBuff, aMismatched___a);
        TDebuggingLog::Log(L, TBuff);
        if ( v11 )
        {
          fputs(TBuff, v11);
          fputs(Str, v11);
        }
      }
      if ( *(_DWORD *)(v12 + 24) != cs5 )
      {
        sprintf(TBuff, aMismatched___o);
        TDebuggingLog::Log(L, TBuff);
        if ( v11 )
        {
          fputs(TBuff, v11);
          fputs(Str, v11);
        }
      }
    }
    v12 += 36;
    --v19;
  }
  while ( v19 );
  v13 = L;
  strcpy(TBuff, aPlayerChecksum);
  TDebuggingLog::Log(v13, TBuff);
  if ( v11 )
  {
    fputs(TBuff, v11);
    fputs(Str, v11);
  }
  v14 = 0;
  v20 = VisibleChecksum;
  do
  {
    if ( TCommunications_Handler::IsPlayerHuman(v21->Comm, v14)
      || TCommunications_Handler::IsPlayerComputer(v21->Comm, v14) )
    {
      v15 = L;
      strcpy(TBuff, asc_5837C4);
      TDebuggingLog::Log(v15, TBuff);
      if ( v11 )
      {
        fputs(TBuff, v11);
        fputs(Str, v11);
      }
      v16 = TCommunications_Handler::GetPlayerName(v21->Comm, v14);
      sprintf(TBuff, aPlayerS, v16);
      TDebuggingLog::Log(L, TBuff);
      if ( v11 )
      {
        fputs(TBuff, v11);
        fputs(Str, v11);
      }
      v17 = RGE_Base_Game::GetChecksum(rge_base_game, v14);
      sprintf(TBuff, aPDCsumD, v14, v17);
      TDebuggingLog::Log(L, TBuff);
      if ( v11 )
      {
        fputs(TBuff, v11);
        fputs(Str, v11);
      }
      sprintf(TBuff, aVisibleChecksu, *v20);
      TDebuggingLog::Log(L, TBuff);
      if ( v11 )
      {
        fputs(TBuff, v11);
        fputs(Str, v11);
      }
    }
    ++v14;
    ++v20;
  }
  while ( (unsigned int)v20 < 0x62D22C );
  v18 = L;
  strcpy(TBuff, a___endOfLog);
  TDebuggingLog::Log(v18, TBuff);
  if ( v11 )
  {
    fputs(TBuff, v11);
    fputs(Str, v11);
  }
  fclose(v11);
}

//----- (00433A90) --------------------------------------------------------
void __thiscall RGE_Communications_Synchronize::EnableSyncChecking(RGE_Communications_Synchronize *this, int Status)
{
  this->DoChecksums = Status;
}

//----- (00433AA0) --------------------------------------------------------
void __thiscall RGE_Communications_Synchronize::SetStopOnFail(RGE_Communications_Synchronize *this, int Status)
{
  this->StopOnSyncFail = Status;
}

//----- (00433AB0) --------------------------------------------------------
void __thiscall RGE_Communications_Synchronize::SetDialogOnFail(RGE_Communications_Synchronize *this, int Status)
{
  this->DialogOnSyncFail = Status;
}

//----- (00433AC0) --------------------------------------------------------
void __thiscall RGE_Communications_Synchronize::SendChatMsgsAtChecksum(RGE_Communications_Synchronize *this, int Status)
{
  this->SendChatMsgs = Status;
}

//----- (00433AD0) --------------------------------------------------------
int __thiscall RGE_Communications_Synchronize::IsPlayerOutOfSync(RGE_Communications_Synchronize *this, unsigned int pnum, unsigned int worldturn)
{
  RGE_Communications_Synchronize *v3; // edx@1
  int v4; // ebx@1
  char *v5; // edi@1
  int v6; // ebp@1
  unsigned int v7; // ecx@1
  char *v8; // eax@1
  int v9; // eax@6
  int result; // eax@8
  unsigned int v11; // esi@9
  int v12; // eax@14
  signed int v13; // esi@23
  int mycs4; // [sp+10h] [bp-28h]@1
  int mycs3; // [sp+14h] [bp-24h]@1
  int mycs2; // [sp+18h] [bp-20h]@1
  int mycs5; // [sp+1Ch] [bp-1Ch]@1
  int NumSame; // [sp+20h] [bp-18h]@1
  int NumDiff; // [sp+24h] [bp-14h]@1
  int NumPlayers; // [sp+28h] [bp-10h]@1
  int foundMine; // [sp+2Ch] [bp-Ch]@1
  unsigned int myRandom; // [sp+30h] [bp-8h]@1
  RGE_Communications_Synchronize *v23; // [sp+34h] [bp-4h]@1

  v3 = this;
  v4 = 0;
  v5 = (char *)&this->Check[1].WTurn;
  v23 = this;
  NumDiff = 0;
  NumSame = 0;
  foundMine = 0;
  v6 = 0;
  mycs2 = 0;
  mycs3 = 0;
  mycs4 = 0;
  mycs5 = 0;
  myRandom = 0;
  NumPlayers = 0;
  v7 = 1;
  v8 = v5;
  while ( *((_DWORD *)v8 - 2) != pnum || *(_DWORD *)v8 != worldturn )
  {
    ++v7;
    v8 += 36;
    if ( v7 > 0x36 )
      goto LABEL_7;
  }
  foundMine = 1;
  v9 = (int)v3 + 36 * v7;
  mycs2 = v3->Check[v7].cs2;
  v4 = *(_DWORD *)(v9 + 52);
  v6 = *(_DWORD *)(v9 + 60);
  mycs4 = *((_DWORD *)&v3->Comm + 9 * (v7 + 2));
  mycs3 = *(_DWORD *)(v9 + 68);
  mycs5 = *(_DWORD *)(v9 + 76);
  myRandom = *(_DWORD *)(v9 + 80);
LABEL_7:
  if ( !foundMine )
  {
    TDebuggingLog::Log(L, aOutofsyncDidnT);
    return 0;
  }
  TDebuggingLog::Log(L, aOutofsyncMyVal, v4, v6, mycs2, mycs3, mycs4, mycs5);
  v11 = 1;
  do
  {
    if ( *((_DWORD *)v5 - 2) != pnum && *(_DWORD *)v5 == worldturn )
    {
      if ( v4 != *((_DWORD *)v5 - 1) || v6 != *((_DWORD *)v5 + 1) )
      {
        v12 = mycs2;
      }
      else
      {
        v12 = mycs2;
        if ( mycs2 == *((_DWORD *)v5 + 2)
          && mycs3 == *((_DWORD *)v5 + 3)
          && mycs4 == *((_DWORD *)v5 + 4)
          && mycs5 == *((_DWORD *)v5 + 5)
          && myRandom == *((_DWORD *)v5 + 6) )
        {
          ++NumSame;
          TDebuggingLog::Log(L, aOutofsyncDSame, v11, v4, v6, mycs2, mycs3, mycs4, mycs5);
          goto LABEL_22;
        }
      }
      ++NumDiff;
      TDebuggingLog::Log(L, aOutofsyncDDiff, v11, v4, v6, v12, mycs3, mycs4, mycs5);
    }
LABEL_22:
    ++v11;
    v5 += 36;
  }
  while ( v11 <= 0x36 );
  v13 = 1;
  do
  {
    if ( TCommunications_Handler::GetPlayerHumanity(v23->Comm, v13) == 2 )
      ++NumPlayers;
    ++v13;
  }
  while ( v13 <= 9 );
  TDebuggingLog::Log(L, aOutofsyncNumpl, NumPlayers, NumDiff, NumSame);
  if ( NumSame + NumDiff >= NumPlayers - 1 )
  {
    if ( NumDiff <= NumSame )
    {
      TDebuggingLog::Log(L, aOutofsyncRet_2);
      result = 0;
    }
    else
    {
      TDebuggingLog::Log(L, aOutofsyncRet_1);
      result = 1;
    }
  }
  else
  {
    TDebuggingLog::Log(L, aOutofsyncRetur);
    result = 0;
  }
  return result;
}
