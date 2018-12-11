#pragma once

/**
 * @file    Engine\RGE\CommLobby.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

#include "IDA.h"

class RGE_Comm_Error;

class RGE_Lobby
{
public:

    HWND *HostHWND;

    IDirectPlayLobby *glpDPL;
    IDirectPlayLobby2 *glpDPL2;
    IDirectPlay2 *glpDP;
    DPLCONNECTION *glpdplConnection;
    char lobby_game;

    RGE_Comm_Error *Err;

    RGE_Lobby(void *Host);

    ~RGE_Lobby();

    void ClearLobbyInfo();
    int IsLobbyLaunched();
    char CheckForLobbyLaunch(IDirectPlay3 **direct_play);
    char IsThisHost();
    char GetPlayerInfo(char **player_name);
    char GetSessionInfo(DPSESSIONDESC2 *info);
    int SendZoneHandshakeResponse();
    int GameIsOver();
    int ReceiveZoneMessages();
    int SendZoneMessage(char *Data, unsigned int dwSize, _GUID guid);
};

int EnumPlayersCallbackLobby(unsigned int pidID, unsigned int dwPlayerType, DPNAME *lpName, unsigned int dwFlags, void *lpContext);
