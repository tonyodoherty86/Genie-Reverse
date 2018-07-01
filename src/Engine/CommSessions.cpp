
/**
 * @file    Engine\RGE\CommSessions.cpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

GUID ApplicationGUID,
     ServGUID;

TCommunications_Handler *comm;

IDirectPlay3 *glpSERV;

TCommunications_Sessions::TCommunications_Sessions(TCommunications_Handler *Comm)
{
    comm = Comm;

    glpSERV = TCommunications_Handler::GetDPInterface();

    ServGUID.x = comm->ServiceGUID.x;
    *(_DWORD *)&ServGUID.s1 = *(_DWORD *)&comm->ServiceGUID.s1;
    *(_DWORD *)&ServGUID.c[0] = *(_DWORD *)&comm->ServiceGUID.c[0];
    *(_DWORD *)&ServGUID.c[4] = *(_DWORD *)&comm->ServiceGUID.c[4];

    ApplicationGUID.x = comm->ApplicationGUID.x;
    *(_DWORD *)&ApplicationGUID.s1 = *(_DWORD *)&comm->ApplicationGUID.s1;
    *(_DWORD *)&ApplicationGUID.c[0] = *(_DWORD *)&comm->ApplicationGUID.c[0];
    *(_DWORD *)&ApplicationGUID.c[4] = *(_DWORD *)&comm->ApplicationGUID.c[4];

    this->SessionCount = 0;
    this->EraseInformation();
    this->Refresh();
}

void TCommunications_Sessions::EraseInformation()
{
    this->SessionCount = 0;

    memset(this->Session, 0, sizeof(this->Session));
}

int TCommunications_Sessions::GetSessionCount()
{
    return this->SessionCount;
}

char *TCommunications_Sessions::GetSessionName(int id)
{
    if( id < 0 || id > this->SessionCount )
        return 0;
    else
        return this->Session[id].Name;
}

unsigned int TCommunications_Sessions::GetSessionMaxPlayers(int id)
{
    if( id < 0 || id > this->SessionCount )
        return 0;
    else
        return this->Session[id].MaxPlayers;
}

unsigned int TCommunications_Sessions::GetSessionCurrentPlayers(int id)
{
    if( id < 0 || id > this->SessionCount )
        return 0;
    else
        return this->Session[id].CurrentPlayers;
}

GUID *TCommunications_Sessions::GetSessionGUID(int id)
{
    if( id < 0 || id > this->SessionCount )
        return 0;
    else
        return &this->Session[id].SessGUID;
}

int TCommunications_Sessions::IncSessionCount()
{
    return this->SessionCount++;
}

int TCommunications_Sessions::AddSession(
    GUID Instance,
    GUID Application,
    unsigned int MaxPlayers,
    unsigned int CurrentPlayers,
    char *Name,
    char *Password,
    unsigned int User1,
    unsigned int User2,
    unsigned int User3,
    unsigned int User4)
{
    this->Session[this->SessionCount].AppGUID        = Application;
    this->Session[this->SessionCount].SessGUID       = Instance;
    this->Session[this->SessionCount].MaxPlayers     = MaxPlayers;
    this->Session[this->SessionCount].CurrentPlayers = CurrentPlayers;
    this->Session[this->SessionCount].User1          = User1;
    this->Session[this->SessionCount].User1          = User2;
    this->Session[this->SessionCount].User1          = User3;
    this->Session[this->SessionCount].User1          = User4;

    if( Name ){
        strcpy(this->Session[this->SessionCount].Name, Name);
    }

    if( Password ){
        strcpy(this->Session[this->SessionCount].Password, Password);
    }

    this->IncSessionCount();

    return 1;
}

int TCommunications_Sessions::Refresh()
{
    this->EraseInformation();

    DPSESSIONDESC2 dpDesc;
    memset(&dpDesc, 0, sizeof(dpDesc));
    dpDesc.guidApplication = ApplicationGUID;
    IUnknownVtbl *v2 = glpSERV->vfptr;
    dpDesc.dwSize = 80;
    return ((int (__stdcall *)(struct IDirectPlay3 *, DPSESSIONDESC2 *, _DWORD, int (__stdcall *)(DPSESSIONDESC2 *, unsigned int *, unsigned int, void *), TCommunications_Sessions *, signed int))v2[4].AddRef)(
                     glpSERV,
                     &dpDesc,
                     0,
                     EnumSessionCallback,
                     this,
                     1);
}

int EnumSessionCallback(DPSESSIONDESC2 *lpDPSessionDesc, unsigned int *lpdwTimeOut, unsigned int dwFlags, void *lpContext)
{
    if( dwFlags & 1 ){
        return 0;
    }else{
        GUID v5;
        *(_QWORD *)&v5.x = *(_QWORD *)&lpDPSessionDesc->guidApplication.x;
        *(_QWORD *)&v5.c[0] = *(_QWORD *)&lpDPSessionDesc->guidApplication.c[0];
        GUID v6;
        *(_QWORD *)&v6.x = *(_QWORD *)&lpDPSessionDesc->guidInstance.x;
        *(_QWORD *)&v6.c[0] = *(_QWORD *)&lpDPSessionDesc->guidInstance.c[0];

        lpContext->AddSession(
            v6,
            v5,
            lpDPSessionDesc->dwMaxPlayers,
            lpDPSessionDesc->dwCurrentPlayers,
            lpDPSessionDesc->lpszSessionNameA,
            lpDPSessionDesc->lpszPasswordA,
            lpDPSessionDesc->dwUser1,
            lpDPSessionDesc->dwUser2,
            lpDPSessionDesc->dwUser3,
            lpDPSessionDesc->dwUser4);

        return 1;
    }
}

bool TCommunications_Sessions::IsEqualGuid(GUID *lpguid1, GUID *lpguid2)
{
    return lpguid1->x == lpguid2->x
            && *(_DWORD *)&lpguid1->s1 == *(_DWORD *)&lpguid2->s1
            && *(_DWORD *)&lpguid1->c[0] == *(_DWORD *)&lpguid2->c[0]
            && *(_DWORD *)&lpguid1->c[4] == *(_DWORD *)&lpguid2->c[4];
}
