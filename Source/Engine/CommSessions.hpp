#pragma once

/**
 * @file    Engine\CommSessions.hpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

#include "CommHandler.hpp"
class TCommunications_Handler;

struct SEs
{
    char Name[255];

    char Password[255];

    GUID AppGUID,
         SessGUID;

    unsigned int CurrentPlayers,
                 MaxPlayers;

    unsigned int User1,
                 User2,
                 User3,
                 User4;
};

class TCommunications_Sessions
{
public:

    int SessionCount;

    SEs Session[501];

    GUID glpGuid;

    IDirectPlay2 *glpIDC;

    TCommunications_Sessions(TCommunications_Handler *Comm);

    void EraseInformation();
    int GetSessionCount();
    char *GetSessionName(int id);
    unsigned int GetSessionMaxPlayers(int id);
    unsigned int GetSessionCurrentPlayers(int id);
    GUID *GetSessionGUID(int id);
    int IncSessionCount();

    int AddSession(
        GUID Instance,
        GUID Application,
        unsigned int MaxPlayers,
        unsigned int CurrentPlayers,
        char *Name,
        char *Password,
        unsigned int User1,
        unsigned int User2,
        unsigned int User3,
        unsigned int User4);

    int Refresh();
};

int EnumSessionCallback(
    DPSESSIONDESC2 *lpDPSessionDesc,
    unsigned int *lpdwTimeOut,
    unsigned int dwFlags,
    void *lpContext);
