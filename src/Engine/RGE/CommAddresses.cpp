
//----- (004249D0) --------------------------------------------------------
void __thiscall RGE_Communications_Addresses::RGE_Communications_Addresses(RGE_Communications_Addresses *this, TCommunications_Handler *CommIn)
{
  RGE_Communications_Addresses *v2; // esi@1
  int v3; // ebx@1
  void *v4; // eax@1
  int v5; // edi@2
  char *v6; // edi@6

  v2 = this;
  this->comm = CommIn;
  RGE_Communications_Addresses::EraseInformation(this);
  v3 = WSAStartup(0x101u, &v2->wsaData);
  v4 = operator new(0x504u);
  if ( v4 )
  {
    v5 = (int)v4 + 4;
    *(_DWORD *)v4 = 8;
    `eh vector constructor iterator'(
      (char *)v4 + 4,
      0xA0u,
      8,
      (int)IPAD::IPAD,
      (void (__thiscall *)(void *))IPAD::~IPAD);
  }
  else
  {
    v5 = 0;
  }
  v2->pIPAD = (IPAD *)v5;
  if ( v3 )
  {
    v2->Status = 0;
  }
  else
  {
    v2->Status = 1;
    RGE_Communications_Addresses::GetHostName(v2);
    v6 = (char *)operator new(0xFFu);
    RGE_Communications_Addresses::SetIPAddresses(v2, v6);
    RGE_Communications_Addresses::SetIPAliases(v2, v6);
    operator delete(v6);
  }
}

//----- (00424AC0) --------------------------------------------------------
IPAD *__thiscall IPAD::`vector deleting destructor'(IPAD *this, unsigned int __flags)
{
  IPAD *v2; // esi@1
  IPAD *result; // eax@2

  v2 = this;
  if ( __flags & 2 )
  {
    `eh vector destructor iterator'(
      (int)this,
      0xA0u,
      *(_DWORD *)&this[-1].Alias[124],
      (void (__thiscall *)(void *))IPAD::~IPAD);
    operator delete(&v2[-1].Alias[124]);
    result = v2;
  }
  else
  {
    if ( __flags & 1 )
      operator delete(this);
    result = v2;
  }
  return result;
}

//----- (00424B10) --------------------------------------------------------
void __thiscall RGE_Communications_Addresses::~RGE_Communications_Addresses(RGE_Communications_Addresses *this)
{
  RGE_Communications_Addresses *v1; // esi@1
  int v2; // eax@3
  void *v3; // esi@4

  v1 = this;
  RGE_Communications_Addresses::EraseInformation(this);
  if ( v1->Status )
    WSACleanup();
  v2 = (int)v1->pIPAD;
  if ( v2 )
  {
    v3 = (void *)(v2 - 4);
    `eh vector destructor iterator'(v2, 0xA0u, *(_DWORD *)(v2 - 4), (void (__thiscall *)(void *))IPAD::~IPAD);
    operator delete(v3);
  }
}

//----- (00424B60) --------------------------------------------------------
char *__thiscall RGE_Communications_Addresses::GetHostName(RGE_Communications_Addresses *this)
{
  char *v1; // esi@1

  v1 = this->hostname;
  gethostname(this->hostname, 128);
  return v1;
}

//----- (00424B80) --------------------------------------------------------
void *__thiscall RGE_Communications_Addresses::SetIPAliases(RGE_Communications_Addresses *this, char *sz)
{
  RGE_Communications_Addresses *v2; // ebx@1
  void *result; // eax@1
  const char **v4; // edx@3
  const char *i; // edi@3

  v2 = this;
  result = this->hostname;
  if ( this != (RGE_Communications_Addresses *)-404 )
  {
    result = gethostbyname(this->hostname);
    if ( result )
    {
      *sz = 0;
      v4 = (const char **)*((_DWORD *)result + 1);
      v2->AliasesAvailable = 0;
      for ( i = *v4; *v4; i = *v4 )
      {
        ++v4;
        strcpy(v2->pIPAD[v2->AliasesAvailable++].Alias, i);
      }
      result = (void *)v2->AliasesAvailable;
    }
  }
  return result;
}

//----- (00424C20) --------------------------------------------------------
char *__thiscall RGE_Communications_Addresses::GetAddress(RGE_Communications_Addresses *this, unsigned int Num)
{
  char *result; // eax@1

  result = this->pIPAD[Num].DottedIPAddress;
  if ( !result || Num > this->AddressesAvailable )
    result = text_in;
  return result;
}

//----- (00424C50) --------------------------------------------------------
char *__thiscall RGE_Communications_Addresses::GetAlias(RGE_Communications_Addresses *this, unsigned int Num)
{
  char *result; // eax@2

  if ( Num > this->AliasesAvailable || (result = this->pIPAD[Num].Alias, &this->pIPAD[Num] == (IPAD *)-32) )
    result = text_in;
  return result;
}

//----- (00424C80) --------------------------------------------------------
_DWORD *__thiscall RGE_Communications_Addresses::SetIPAddresses(RGE_Communications_Addresses *this, char *sz)
{
  RGE_Communications_Addresses *v2; // ebx@1
  _DWORD *result; // eax@1
  int *v4; // ebp@3
  int i; // eax@3
  char temp[25]; // [sp+10h] [bp-1Ch]@4

  v2 = this;
  result = (_DWORD *)this->hostname;
  if ( this != (RGE_Communications_Addresses *)-404 )
  {
    result = gethostbyname(this->hostname);
    if ( result )
    {
      *sz = 0;
      v4 = (int *)result[3];
      v2->AddressesAvailable = 0;
      for ( i = *v4; *v4; i = *v4 )
      {
        sprintf(temp, aD_D_D_D, *(_BYTE *)i, *(_BYTE *)(i + 1), *(_BYTE *)(i + 2), *(_BYTE *)(i + 3));
        ++v4;
        strcat(sz, temp);
        strcpy(v2->pIPAD[v2->AddressesAvailable++].DottedIPAddress, temp);
      }
      result = (_DWORD *)v2->AddressesAvailable;
    }
  }
  return result;
}

//----- (00424D90) --------------------------------------------------------
void __thiscall RGE_Communications_Addresses::EraseInformation(RGE_Communications_Addresses *this)
{
  strcpy(this->hostname, message_in);
  this->AliasesAvailable = 0;
  this->AddressesAvailable = 0;
}

//----- (00424DD0) --------------------------------------------------------
void __thiscall IPAD::IPAD(IPAD *this)
{
  strcpy(this->DottedIPAddress, message_in);
  strcpy(this->Alias, message_in);
}
