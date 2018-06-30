void __thiscall TCommunications_Services::TCommunications_Services(TCommunications_Services *this); // idb
void __thiscall TCommunications_Services::~TCommunications_Services(TCommunications_Services *this); // idb
int __thiscall TCommunications_Services::GetServiceCount(TCommunications_Services *this); // idb
int __thiscall TCommunications_Services::IncServiceCount(TCommunications_Services *this); // idb
char *__thiscall TCommunications_Services::GetServiceName(TCommunications_Services *this, int id); // idb
int __thiscall TCommunications_Services::SetServiceName(TCommunications_Services *this, int id, char *Text); // idb
_GUID *__thiscall TCommunications_Services::GetServiceGUID(TCommunications_Services *this, _GUID *result, int __$ReturnUdt); // idb
void __thiscall TCommunications_Services::EnumServiceGUID(TCommunications_Services *this, int id, _GUID *gid); // idb
int __thiscall TCommunications_Services::GetServiceActive(TCommunications_Services *this, int id); // idb
void __thiscall TCommunications_Services::SetServiceActive(TCommunications_Services *this, int id, int state); // idb
int __stdcall DPEnumCallback(_GUID *pid, char *szName, unsigned int major_ver, unsigned int minor_ver, void *lpx); // idb