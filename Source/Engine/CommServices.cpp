
void TCommunications_Services::TCommunications_Services()
{
    char *v1; // edx@1
    signed int v2; // ebp@1
    char *v3; // ST18_4@2

    this->ServiceCount = 0;
    v1 = (char *)&this->Service[0].Active;
    v2 = 100;
    do
    {
        v3 = v1 - 92;
        v1 += 96;
        strcpy(v3, message_in);
        --v2;
        *((_DWORD *)v1 - 27) = 0;
        *((_DWORD *)v1 - 24) = 0;
        *((_DWORD *)v1 - 25) = 0;
        *((_DWORD *)v1 - 26) = 0;
    }
    while ( v2 );
    DirectPlayEnumerateA(DPEnumCallback, this);
}

int TCommunications_Services::GetServiceCount()
{
    return this->ServiceCount;
}

int TCommunications_Services::IncServiceCount()
{
    int result; // eax@1

    result = this->ServiceCount + 1;
    this->ServiceCount = result;
    return result;
}

char *TCommunications_Services::GetServiceName(int id)
{
    char *result; // eax@3

    if ( id < 0 || id > this->ServiceCount )
        result = 0;
    else
        result = (char *)this + 96 * id;
    return result;
}

int TCommunications_Services::SetServiceName(int id, char *Text)
{
    char *v3; // edx@1
    unsigned int v4; // ecx@1
    char v5; // al@1
    char *v6; // edi@1
    char *v7; // esi@1
    int result; // eax@1

    v3 = (char *)this + 96 * id;
    v4 = strlen(Text) + 1;
    v5 = v4;
    v4 >>= 2;
    qmemcpy(v3, Text, 4 * v4);
    v7 = &Text[4 * v4];
    v6 = &v3[4 * v4];
    LOBYTE(v4) = v5;
    result = 1;
    qmemcpy(v6, v7, v4 & 3);
    return result;
}

GUID *TCommunications_Services::GetServiceGUID(GUID *result, int __$ReturnUdt)
{
    GUID *v3; // ecx@1
    GUID *v4; // eax@1

    v3 = this->Service[__$ReturnUdt].GUID;
    v4 = result;
    result->x = v3->x;
    *(_DWORD *)&result->s1 = *(_DWORD *)&v3->s1;
    *(_DWORD *)&result->c[0] = *(_DWORD *)&v3->c[0];
    *(_DWORD *)&result->c[4] = *(_DWORD *)&v3->c[4];
    return v4;
}

void TCommunications_Services::EnumServiceGUID(int id, GUID *gid)
{
    if ( id >= 0 && id <= this->ServiceCount )
        this->Service[id].GUID = gid;
}

int TCommunications_Services::GetServiceActive(int id)
{
    int result; // eax@3

    if ( id < 0 || id > this->ServiceCount )
        result = 0;
    else
        result = this->Service[id].Active;
    return result;
}

void TCommunications_Services::SetServiceActive(int id, int state)
{
    if ( id >= 0 && id <= this->ServiceCount )
        this->Service[id].Active = state;
}

static int DPEnumCallback(GUID *pid, char *szName, unsigned int major_ver, unsigned int minor_ver, void *lpx)
{
    TCommunications_Services *v5; // esi@1
    int v6; // edi@1
    int result; // eax@2

    v5 = (TCommunications_Services *)lpx;
    v6 = TCommunications_Services::GetServiceCount((TCommunications_Services *)lpx);
    TCommunications_Services::SetServiceName(v5, v6, szName);
    TCommunications_Services::EnumServiceGUID(v5, v6, pid);
    if ( DirectPlayCreate(pid, (LPDIRECTPLAY *)&lpx, 0) )
    {
        TCommunications_Services::SetServiceActive(v5, v6, 0);
        TCommunications_Services::IncServiceCount(v5);
        result = 1;
    }
    else
    {
        TCommunications_Services::SetServiceActive(v5, v6, 1);
        (*(void (__stdcall **)(void *))(*(_DWORD *)lpx + 8))(lpx);
        TCommunications_Services::IncServiceCount(v5);
        result = 1;
    }
    return result;
}
