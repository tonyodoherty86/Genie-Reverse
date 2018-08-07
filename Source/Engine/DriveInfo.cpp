
//----- (00449770) --------------------------------------------------------
void __thiscall DriveInformation::DriveInformation(DriveInformation *this)
{
  DriveInformation *v1; // ebx@1
  int v2; // eax@1

  v1 = this;
  v2 = _getdrive();
  v1->initialDriveValue = v2;
  v1->currentDriveValue = v2;
  DriveInformation::updateDirectory(v1);
  strcpy(v1->initialDirectoryValue, v1->currentDirectoryValue);
}

//----- (004497C0) --------------------------------------------------------
int __thiscall DriveInformation::initialDrive(DriveInformation *this)
{
  return this->initialDriveValue;
}

//----- (004497D0) --------------------------------------------------------
int __thiscall DriveInformation::initialDriveAsLetter(DriveInformation *this)
{
  return this->initialDriveValue + 64;
}

//----- (004497E0) --------------------------------------------------------
char *__thiscall DriveInformation::initialDirectory(DriveInformation *this)
{
  return this->initialDirectoryValue;
}

//----- (004497F0) --------------------------------------------------------
int __thiscall DriveInformation::currentDrive(DriveInformation *this)
{
  return this->currentDriveValue;
}

//----- (00449800) --------------------------------------------------------
int __thiscall DriveInformation::currentDriveAsLetter(DriveInformation *this)
{
  return this->currentDriveValue + 64;
}

//----- (00449810) --------------------------------------------------------
char *__thiscall DriveInformation::currentDirectory(DriveInformation *this)
{
  return this->currentDirectoryValue;
}

//----- (00449820) --------------------------------------------------------
int __thiscall DriveInformation::numberDrives(DriveInformation *this)
{
  return this->driveValues[0];
}

//----- (00449830) --------------------------------------------------------
int __thiscall DriveInformation::validDrive(DriveInformation *this, int v)
{
  return this->driveValues[v];
}

//----- (00449840) --------------------------------------------------------
void __thiscall DriveInformation::checkDrives(DriveInformation *this)
{
  DriveInformation *v1; // ebx@1
  int v2; // edi@1
  char *v3; // esi@1

  v1 = this;
  this->driveValues[0] = 0;
  v2 = 1;
  v3 = (char *)&this->driveValues[1];
  do
  {
    if ( _chdrive(v2) )
    {
      *(_DWORD *)v3 = 0;
    }
    else
    {
      ++v1->driveValues[0];
      *(_DWORD *)v3 = 1;
    }
    ++v2;
    v3 += 4;
  }
  while ( v2 <= 26 );
  _chdrive(v1->currentDriveValue);
}

//----- (004498A0) --------------------------------------------------------
int __stdcall DriveInformation::numberOfFilesWithFilename(char *n)
{
  __int32 v2; // eax@1
  __int32 v3; // esi@1
  int result; // eax@2
  signed int v5; // edi@3
  _finddata_t fileInfo; // [sp+4h] [bp-118h]@1

  v2 = _findfirst(n, &fileInfo);
  v3 = v2;
  if ( v2 == -1 )
  {
    result = 0;
  }
  else
  {
    v5 = 1;
    if ( _findnext(v2, &fileInfo) != -1 )
    {
      do
        ++v5;
      while ( _findnext(v3, &fileInfo) != -1 );
    }
    result = v5;
  }
  return result;
}

//----- (00449910) --------------------------------------------------------
int __stdcall DriveInformation::numberOfFilesWithAttribute(int a)
{
  __int32 v2; // eax@1
  __int32 v3; // esi@1
  int result; // eax@2
  signed int v5; // edi@3
  _finddata_t fileInfo; // [sp+4h] [bp-118h]@1

  v2 = _findfirst(a__0, &fileInfo);
  v3 = v2;
  if ( v2 == -1 )
  {
    result = 0;
  }
  else
  {
    v5 = 1;
    if ( _findnext(v2, &fileInfo) != -1 )
    {
      do
      {
        if ( a & fileInfo.attrib )
          ++v5;
      }
      while ( _findnext(v3, &fileInfo) != -1 );
    }
    result = v5;
  }
  return result;
}

//----- (00449990) --------------------------------------------------------
int __stdcall DriveInformation::numberOfFilesWithFilenameOrAttribute(char *n, int a)
{
  __int32 v3; // eax@1
  __int32 v4; // esi@1
  int result; // eax@2
  signed int v6; // edi@3
  _finddata_t fileInfo; // [sp+4h] [bp-118h]@1

  v3 = _findfirst(a__0, &fileInfo);
  v4 = v3;
  if ( v3 == -1 )
  {
    result = 0;
  }
  else
  {
    v6 = 1;
    if ( _findnext(v3, &fileInfo) != -1 )
    {
      do
      {
        if ( a & fileInfo.attrib || strstr(fileInfo.name, n) )
          ++v6;
      }
      while ( _findnext(v4, &fileInfo) != -1 );
    }
    result = v6;
  }
  return result;
}

//----- (00449A20) --------------------------------------------------------
int __thiscall DriveInformation::resetCurrentDriveAndDirectory(DriveInformation *this)
{
  DriveInformation *v1; // esi@1
  int result; // eax@2

  v1 = this;
  if ( DriveInformation::resetCurrentDrive(this) )
    result = DriveInformation::resetCurrentDirectory(v1);
  else
    result = 0;
  return result;
}

//----- (00449A40) --------------------------------------------------------
int __thiscall DriveInformation::resetCurrentDrive(DriveInformation *this)
{
  return DriveInformation::changeDrive(this, this->initialDriveValue);
}

//----- (00449A50) --------------------------------------------------------
int __thiscall DriveInformation::resetCurrentDirectory(DriveInformation *this)
{
  return DriveInformation::changeDirectory(this, this->initialDirectoryValue);
}

//----- (00449A60) --------------------------------------------------------
int __thiscall DriveInformation::changeDrive(DriveInformation *this, int d)
{
  DriveInformation *v2; // esi@1
  int result; // eax@2

  v2 = this;
  if ( _chdrive(d) )
  {
    result = 0;
  }
  else
  {
    v2->currentDriveValue = d;
    result = 1;
  }
  return result;
}

//----- (00449A90) --------------------------------------------------------
int __thiscall DriveInformation::changeDirectory(DriveInformation *this, char *d)
{
  DriveInformation *v2; // esi@1
  int result; // eax@2

  v2 = this;
  if ( _chdir(d) )
  {
    result = 0;
  }
  else
  {
    DriveInformation::updateDirectory(v2);
    result = 1;
  }
  return result;
}

//----- (00449AC0) --------------------------------------------------------
void __thiscall DriveInformation::updateDirectory(DriveInformation *this)
{
  char *v1; // esi@1
  char cDrive[3]; // [sp+4h] [bp-308h]@1
  char extension[256]; // [sp+8h] [bp-304h]@1
  char filename[256]; // [sp+108h] [bp-204h]@1
  char fullPath[260]; // [sp+208h] [bp-104h]@1

  v1 = (char *)this;
  _getcwd(fullPath, 260);
  v1 += 264;
  _splitpath(fullPath, cDrive, v1, filename, extension);
  sprintf(v1, aSSS_1, v1, filename, extension);
}
