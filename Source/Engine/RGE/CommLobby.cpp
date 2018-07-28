
//----- (0042F290) --------------------------------------------------------
void __thiscall RGE_Lobby::RGE_Lobby(RGE_Lobby *this, void *Host)
{
  RGE_Lobby *v2; // esi@1
  RGE_Comm_Error *v3; // eax@1
  RGE_Comm_Error *v4; // eax@2

  v2 = this;
  this->HostHWND = Host;
  v3 = (RGE_Comm_Error *)operator new(8u);
  if( v3 )
    RGE_Comm_Error::RGE_Comm_Error(v3, Host);
  else
    v4 = 0;
  v2->Err = v4;
  v2->glpDP = 0;
  v2->glpdplConnection = 0;
  v2->glpDPL = 0;
  v2->glpDPL2 = 0;
  v2->lobby_game = 0;
}

//----- (0042F300) --------------------------------------------------------
void __thiscall RGE_Lobby::~RGE_Lobby(RGE_Lobby *this)
{
  RGE_Lobby *v1; // edi@1
  RGE_Comm_Error *v2; // esi@1

  v1 = this;
  v2 = this->Err;
  if( v2 )
  {
    RGE_Comm_Error::~RGE_Comm_Error(this->Err);
    operator delete(v2);
  }
  RGE_Lobby::ClearLobbyInfo(v1);
}

//----- (0042F330) --------------------------------------------------------
void __thiscall RGE_Lobby::ClearLobbyInfo(RGE_Lobby *this)
{
  RGE_Lobby *v1; // esi@1
  IDirectPlayLobby2 *v2; // eax@3
  int v3; // eax@4

  v1 = this;
  if( this->glpdplConnection )
  {
    operator delete(this->glpdplConnection);
    v1->glpdplConnection = 0;
  }
  v2 = v1->glpDPL2;
  if( v2 )
  {
    v3 = v2->vfptr->Release((IUnknown *)v1->glpDPL2);
    RGE_Comm_Error::ShowReturn(v1->Err, v3, aRelease);
    v1->glpDPL2 = 0;
  }
  v1->lobby_game = 0;
  v1->glpDP = 0;
}

//----- (0042F370) --------------------------------------------------------
int __thiscall RGE_Lobby::IsLobbyLaunched(RGE_Lobby *this)
{
  RGE_Lobby *v1; // esi@1

  v1 = this;
  TDebuggingLog::Log(L, aLobbyGameLaunc, this->lobby_game);
  return v1->lobby_game;
}

//----- (0042F3A0) --------------------------------------------------------
int __stdcall EnumPlayersCallbackLobby(unsigned int pidID, unsigned int dwPlayerType, DPNAME *lpName, unsigned int dwFlags, void *lpContext)
{
  TDebuggingLog::Log(L, aEnumplayerDpid, pidID);
  TDebuggingLog::Log(L, aEnumplayerName, lpName->lpszShortName);
  TDebuggingLog::Log(L, aEnumerationNot);
  if( dwFlags & 0x10 )
    TDebuggingLog::Log(L, aRemotePlayer);
  if( dwFlags & 8 )
    TDebuggingLog::Log(L, aLocalPlayer);
  return 1;
}

//----- (0042F430) --------------------------------------------------------
char __thiscall RGE_Lobby::CheckForLobbyLaunch(RGE_Lobby *this, IDirectPlay3 **direct_play)
{
  RGE_Lobby *v2; // esi@1
  int v3; // ebx@1
  char result; // al@2
  IDirectPlayLobby2 **v5; // edi@3
  DPLCONNECTION *v6; // eax@5
  IDirectPlayLobby2 *v7; // ecx@5
  int v8; // edi@7
  int v9; // edi@11
  unsigned int dwSize; // [sp+1Ch] [bp-4h]@1

  v2 = this;
  dwSize = 41;
  *direct_play = 0;
  RGE_Lobby::ClearLobbyInfo(this);
  v3 = DirectPlayLobbyCreateA(0, &v2->glpDPL, 0, 0, 0);
  RGE_Comm_Error::ShowReturn(v2->Err, v3, aLobbyCreate);
  if( v3 >= 0 )
  {
    v5 = &v2->glpDPL2;
    v2->glpDPL->vfptr->QueryInterface((IUnknown *)v2->glpDPL, &IID_IDirectPlayLobby2A, (void **)&v2->glpDPL2);
    if( v2->glpDPL2 )
    {
      ((void (__stdcall *)(IDirectPlayLobby2 *, _DWORD, _DWORD, unsigned int *))v2->glpDPL2->vfptr[2].Release)(
        v2->glpDPL2,
        0,
        0,
        &dwSize);
      v6 = (DPLCONNECTION *)operator new(dwSize + 1);
      v7 = *v5;
      v2->glpdplConnection = v6;
      if( ((int (__stdcall *)(IDirectPlayLobby2 *, _DWORD, void *, unsigned int *))v7->vfptr[2].Release)(
             v7,
             0,
             v6,
             &dwSize) >= 0 )
      {
        TDebuggingLog::Log(L, aLobbyLaunchedG);
        v2->glpdplConnection->lpSessionDesc->dwFlags = 68;
        v2->glpdplConnection->lpSessionDesc->dwMaxPlayers = 9;
        ((void (__stdcall *)(IDirectPlayLobby2 *, _DWORD, _DWORD, DPLCONNECTION *))(*v5)->vfptr[4].QueryInterface)(
          *v5,
          0,
          0,
          v2->glpdplConnection);
        TDebuggingLog::Log(L, aPreConnect);
        v8 = ((int (__stdcall *)(IDirectPlayLobby2 *, _DWORD, int, _DWORD))(*v5)->vfptr[1].QueryInterface)(
               *v5,
               0,
               (int)&v2->glpDP,
               0);
        TDebuggingLog::Log(L, aPostConnect);
        if( v8 >= 0 )
        {
          TDebuggingLog::Log(L, aPreQi);
          v9 = v2->glpDP->vfptr->QueryInterface((IUnknown *)v2->glpDP, &IID_IDirectPlay3A, (void **)direct_play);
          RGE_Comm_Error::ShowReturn(v2->Err, v9, aLobbyQi);
          if( v9 >= 0 )
          {
            TDebuggingLog::Log(L, aCallingEnumera);
            ((void (__stdcall *)(IDirectPlay3 *, _DWORD, int (__stdcall *)(unsigned int, unsigned int, DPNAME *, unsigned int, void *), RGE_Lobby *, _DWORD))(*direct_play)->vfptr[4].QueryInterface)(
              *direct_play,
              0,
              EnumPlayersCallbackLobby,
              v2,
              0);
            TDebuggingLog::Log(L, aPostEnump);
            result = 1;
            v2->lobby_game = 1;
          }
          else
          {
            TDebuggingLog::Log(L, aQueryinterface);
            result = -1;
          }
        }
        else if( v8 == -2005466896 )
        {
          result = -1;
        }
        else
        {
          TDebuggingLog::Log(L, aFailedToConnec);
          RGE_Comm_Error::ShowReturn(v2->Err, v8, aConnect);
          result = -1;
        }
      }
      else
      {
        v2->lobby_game = 0;
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
  return result;
}

//----- (0042F640) --------------------------------------------------------
char __thiscall RGE_Lobby::IsThisHost(RGE_Lobby *this)
{
  char result; // al@2

  if( this->lobby_game )
    result = ((unsigned __int8)this->glpdplConnection->dwFlags >> 1) & 1;
  else
    result = 0;
  return result;
}

//----- (0042F660) --------------------------------------------------------
char __thiscall RGE_Lobby::GetPlayerInfo(RGE_Lobby *this, char **player_name)
{
  char result; // al@2

  if( this->lobby_game )
  {
    *player_name = this->glpdplConnection->lpPlayerName->lpszShortNameA;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0042F680) --------------------------------------------------------
char __thiscall RGE_Lobby::GetSessionInfo(RGE_Lobby *this, DPSESSIONDESC2 *info)
{
  char result; // al@2

  if( this->lobby_game )
  {
    qmemcpy(info, this->glpdplConnection->lpSessionDesc, sizeof(DPSESSIONDESC2));
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0042F6B0) --------------------------------------------------------
BOOL __thiscall RGE_Lobby::SendZoneHandshakeResponse(RGE_Lobby *this)
{
  return this->lobby_game != 0;
}

//----- (0042F6C0) --------------------------------------------------------
BOOL __thiscall RGE_Lobby::GameIsOver(RGE_Lobby *this)
{
  return this->lobby_game != 0;
}

//----- (0042F6D0) --------------------------------------------------------
int __thiscall RGE_Lobby::ReceiveZoneMessages(RGE_Lobby *this)
{
  RGE_Lobby *v1; // edi@1
  IDirectPlayLobby *v2; // eax@2
  IUnknownVtbl *v3; // ecx@2
  int v4; // esi@2
  int result; // eax@5
  unsigned int dwDataSize; // [sp+18h] [bp-808h]@2
  unsigned int dwRXFlags; // [sp+1Ch] [bp-804h]@2
  char Data[2048]; // [sp+20h] [bp-800h]@2

  v1 = this;
  if( !this->lobby_game )
    goto LABEL_13;
  v2 = this->glpDPL;
  v3 = v2->vfptr;
  dwDataSize = 2048;
  v4 = ((int (__stdcall *)(IDirectPlayLobby *, _DWORD, _DWORD, unsigned int *, char *, unsigned int *))v3[3].QueryInterface)(
         v2,
         0,
         0,
         &dwRXFlags,
         Data,
         &dwDataSize);
  RGE_Comm_Error::ShowReturn(v1->Err, v4, aRxLobbyMessage);
  if( v4 == -2005466946 || !dwDataSize )
    goto LABEL_13;
  if( v4 )
  {
    RGE_Comm_Error::ShowReturn(v1->Err, v4, aRxlobbyMsg);
    return 0;
  }
  if( dwRXFlags == 1 )
  {
    TDebuggingLog::Log(L, aLobbySystemMes);
    switch ( *(_DWORD *)Data )
    {
      case 4:
        TDebuggingLog::Log(L, aLobbyApplicati);
        result = 0;
        break;
      case 1:
        TDebuggingLog::Log(L, aLobbyConnectio);
        result = 0;
        break;
      case 2:
        TDebuggingLog::Log(L, aLobbyConnect_2);
        result = 0;
        break;
      case 3:
        TDebuggingLog::Log(L, aLobbyConnect_0);
        result = 0;
        break;
      default:
        TDebuggingLog::Log(L, aLobbyUnknownMe, *(_DWORD *)Data);
        goto LABEL_13;
    }
  }
  else
  {
LABEL_13:
    result = 0;
  }
  return result;
}

//----- (0042F830) --------------------------------------------------------
int __thiscall RGE_Lobby::SendZoneMessage(RGE_Lobby *this, char *Data, unsigned int dwSize, _GUID guid)
{
  int result; // eax@2
  void *v5; // ebx@3
  int v6; // esi@3
  RGE_Lobby *v7; // [sp+0h] [bp-4h]@1

  v7 = this;
  if( this->lobby_game )
  {
    TDebuggingLog::Log(L, aSendingDBytesT, dwSize, dwSize + 48);
    v5 = operator new(dwSize + 48);
    *(_DWORD *)v5 = 5;
    *((_DWORD *)v5 + 1) = 0;
    *(GUID *)((char *)v5 + 8) = GUID_NULL;
    *((_DWORD *)v5 + 10) = dwSize + 48;
    *(_GUID *)((char *)v5 + 24) = guid;
    qmemcpy((char *)v5 + 44, Data, dwSize);
    v6 = ((int (__stdcall *)(IDirectPlayLobby2 *, _DWORD, _DWORD, void *, unsigned int))v7->glpDPL2->vfptr[3].Release)(
           v7->glpDPL2,
           0,
           0,
           v5,
           dwSize + 48);
    operator delete(v5);
    if( !v6 )
      TDebuggingLog::Log(L, aSendlobbymessa);
    RGE_Comm_Error::ShowReturn(v7->Err, v6, aSendLobbyMsg);
    result = v6;
  }
  else
  {
    result = 0;
  }
  return result;
}
