void __thiscall TCommunications_Sessions::TCommunications_Sessions(TCommunications_Sessions *this, TCommunications_Handler *Comm); // idb
void __thiscall TCommunications_Sessions::EraseInformation(TCommunications_Sessions *this); // idb
int __thiscall TCommunications_Sessions::GetSessionCount(TCommunications_Sessions *this); // idb
char *__thiscall TCommunications_Sessions::GetSessionName(TCommunications_Sessions *this, int id); // idb
unsigned int __thiscall TCommunications_Sessions::GetSessionMaxPlayers(TCommunications_Sessions *this, int id); // idb
unsigned int __thiscall TCommunications_Sessions::GetSessionCurrentPlayers(TCommunications_Sessions *this, int id); // idb
_GUID *__thiscall TCommunications_Sessions::GetSessionGUID(TCommunications_Sessions *this, int id); // idb
int __thiscall TCommunications_Sessions::IncSessionCount(TCommunications_Sessions *this); // idb
int __thiscall TCommunications_Sessions::AddSession(TCommunications_Sessions *this, _GUID Instance, _GUID Application, unsigned int MaxPlayers, unsigned int CurrentPlayers, char *Name, char *Password, unsigned int User1, unsigned int User2, unsigned int User3, unsigned int User4); // idb
int __thiscall TCommunications_Sessions::Refresh(TCommunications_Sessions *this); // idb
int __stdcall EnumSessionCallback(DPSESSIONDESC2 *lpDPSessionDesc, unsigned int *lpdwTimeOut, unsigned int dwFlags, void *lpContext); // idb