
//----- (0047EB80) --------------------------------------------------------
void __thiscall TRegistry::TRegistry(TRegistry *this, char *Key)
{
  TRegistry *v2; // esi@1
  unsigned int *v3; // edi@1
  HKEY *v4; // ebx@1

  v2 = this;
  v3 = &this->gdwDisp;
  v4 = &this->ghMachineKeyRead;
  this->ghMachineKey = 0;
  this->ghUserKey = 0;
  this->ghMachineKeyRead = 0;
  RegCreateKeyExA(HKEY_CURRENT_USER, Key, 0, 0, 0, 0xF003Fu, 0, &this->ghUserKey, &this->gdwDisp);
  RegCreateKeyExA(HKEY_LOCAL_MACHINE, Key, 0, 0, 0, 0xF003Fu, 0, &v2->ghMachineKey, v3);
  RegCreateKeyExA(HKEY_LOCAL_MACHINE, Key, 0, 0, 0, 1u, 0, v4, v3);
}

//----- (0047EC00) --------------------------------------------------------
void __thiscall TRegistry::~TRegistry(TRegistry *this)
{
  TRegistry *v1; // esi@1

  v1 = this;
  if ( this->ghUserKey )
  {
    RegCloseKey(this->ghUserKey);
    v1->ghUserKey = 0;
  }
  if ( v1->ghMachineKey )
  {
    RegCloseKey(v1->ghMachineKey);
    v1->ghMachineKey = 0;
  }
  if ( v1->ghMachineKeyRead )
  {
    RegCloseKey(v1->ghMachineKeyRead);
    v1->ghMachineKeyRead = 0;
  }
}

//----- (0047EC40) --------------------------------------------------------
int __thiscall TRegistry::RegSet(TRegistry *this, int UseUserKey, char *lptszName, char *lpData, unsigned int dwSize)
{
  int result; // eax@2

  if ( UseUserKey )
    result = RegSetValueExA(this->ghUserKey, lptszName, 0, 4u, lpData, dwSize) == 0;
  else
    result = RegSetValueExA(this->ghMachineKey, lptszName, 0, 4u, lpData, dwSize) == 0;
  return result;
}

//----- (0047ECA0) --------------------------------------------------------
int __thiscall TRegistry::RegSetInt(TRegistry *this, int UseUserKey, char *lptszName, int Value)
{
  int result; // eax@2

  if ( UseUserKey )
    result = RegSetValueExA(this->ghUserKey, lptszName, 0, 4u, (const BYTE *)&Value, 4u) == 0;
  else
    result = RegSetValueExA(this->ghMachineKey, lptszName, 0, 4u, (const BYTE *)&Value, 4u) == 0;
  return result;
}

//----- (0047ED00) --------------------------------------------------------
int __thiscall TRegistry::RegSetAscii(TRegistry *this, int UseUserKey, char *lptszName, char *lpData, unsigned int dwSize)
{
  int result; // eax@2

  if ( UseUserKey )
    result = RegSetValueExA(this->ghUserKey, lptszName, 0, 1u, lpData, dwSize) == 0;
  else
    result = RegSetValueExA(this->ghMachineKey, lptszName, 0, 1u, lpData, dwSize) == 0;
  return result;
}

//----- (0047ED60) --------------------------------------------------------
char *__thiscall TRegistry::RegGetAscii(TRegistry *this, int UseUserKey, char *lptszName)
{
  void *v4; // [sp-18h] [bp-24h]@2
  char *v5; // [sp-14h] [bp-20h]@2
  unsigned int *v6; // [sp-Ch] [bp-18h]@2
  char *v7; // [sp-8h] [bp-14h]@2
  unsigned int *v8; // [sp-4h] [bp-10h]@2
  unsigned int dwSize; // [sp+4h] [bp-8h]@1
  unsigned int dwType; // [sp+8h] [bp-4h]@1

  dwType = 1;
  dwSize = 255;
  if ( UseUserKey )
  {
    v8 = &dwSize;
    v7 = this->Data;
    v6 = &dwType;
    v5 = lptszName;
    v4 = this->ghUserKey;
  }
  else
  {
    v8 = &dwSize;
    v7 = this->Data;
    v6 = &dwType;
    v5 = lptszName;
    v4 = this->ghMachineKeyRead;
  }
  return (char *)(RegQueryValueExA(v4, v5, 0, v6, v7, v8) == 0 ? (unsigned int)this->Data : 0);
}

//----- (0047EDD0) --------------------------------------------------------
int __thiscall TRegistry::RegGet(TRegistry *this, int UseUserKey, char *lptszName, char *lpData, unsigned int *lpdwDataSize)
{
  int result; // eax@2

  if ( UseUserKey )
    result = RegQueryValueExA(this->ghUserKey, lptszName, 0, (LPDWORD)&lpdwDataSize, lpData, lpdwDataSize);
  else
    result = RegQueryValueExA(this->ghMachineKeyRead, lptszName, 0, (LPDWORD)&lpdwDataSize, lpData, lpdwDataSize);
  return result;
}

//----- (0047EE20) --------------------------------------------------------
char *__thiscall TRegistry::RegGetInt(TRegistry *this, int UseUserKey, char *lptszName)
{
  char *result; // eax@5
  void *v4; // [sp-18h] [bp-20h]@2
  char *v5; // [sp-14h] [bp-1Ch]@2
  unsigned int *v6; // [sp-Ch] [bp-14h]@2
  char *v7; // [sp-8h] [bp-10h]@2
  unsigned int *v8; // [sp-4h] [bp-Ch]@2
  unsigned int Size; // [sp+0h] [bp-8h]@1
  unsigned int dwType; // [sp+4h] [bp-4h]@1

  Size = 4;
  dwType = 4;
  if ( UseUserKey )
  {
    v8 = &Size;
    v7 = (char *)&lptszName;
    v6 = &dwType;
    v5 = lptszName;
    v4 = this->ghUserKey;
  }
  else
  {
    v8 = &Size;
    v7 = (char *)&lptszName;
    v6 = &dwType;
    v5 = lptszName;
    v4 = this->ghMachineKeyRead;
  }
  if ( RegQueryValueExA(v4, v5, 0, v6, v7, v8) )
    result = (char *)-1;
  else
    result = lptszName;
  return result;
}
