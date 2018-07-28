
//----- (00436220) --------------------------------------------------------
void __thiscall TDebuggingLog::TDebuggingLog(TDebuggingLog *this)
{
  TDebuggingLog *v1; // ebx@1

  v1 = this;
  this->LogToFile = 0;
  this->LogToOutput = 0;
  this->LogError = 0;
  this->LogIsOpen = 0;
  TDebuggingLog::LogSequence(this, 0);
  TDebuggingLog::LogTimestamp(v1, 0);
  TDebuggingLog::LogDateTimestamp(v1, 0);
  TDebuggingLog::FlushToDisk(v1, 0);
  TDebuggingLog::OpenLog(v1);
  TDebuggingLog::Log(v1, aLogging);
  TDebuggingLog::Time(v1);
  strcpy(v1->Filename, aCApplogerr_txt);
}

//----- (004362B0) --------------------------------------------------------
void __thiscall TDebuggingLog::LogFile(TDebuggingLog *this, int DoLog)
{
  TDebuggingLog *v2; // esi@1
  char *v3; // eax@4

  v2 = this;
  if( DoLog )
    this->LogToFile = 1;
  else
    this->LogToFile = 0;
  v3 = TDebuggingLog::YesOrNo(DoLog);
  TDebuggingLog::Log(v2, aLoggingToFileS, v3);
}

//----- (004362F0) --------------------------------------------------------
void __thiscall TDebuggingLog::LogOutput(TDebuggingLog *this, int DoLog)
{
  TDebuggingLog *v2; // esi@1
  char *v3; // eax@4

  v2 = this;
  if( DoLog )
    this->LogToOutput = 1;
  else
    this->LogToOutput = 0;
  v3 = TDebuggingLog::YesOrNo(DoLog);
  TDebuggingLog::Log(v2, aLoggingToOutpu, v3);
}

//----- (00436330) --------------------------------------------------------
void __thiscall TDebuggingLog::LogTimestamp(TDebuggingLog *this, int DoTimestamp)
{
  TDebuggingLog *v2; // esi@1
  char *v3; // eax@1

  v2 = this;
  this->Timestamp = DoTimestamp != 0;
  v3 = TDebuggingLog::YesOrNo(DoTimestamp != 0);
  TDebuggingLog::Log(v2, aTimestampMilli, v3);
}

//----- (00436360) --------------------------------------------------------
void __thiscall TDebuggingLog::LogDateTimestamp(TDebuggingLog *this, int DoTimestamp)
{
  TDebuggingLog *v2; // esi@1
  char *v3; // eax@4

  v2 = this;
  if( DoTimestamp )
    this->DateTimestamp = 1;
  else
    this->DateTimestamp = 0;
  v3 = TDebuggingLog::YesOrNo(this->Timestamp);
  TDebuggingLog::Log(v2, aDateTimeStampS, v3);
}

//----- (004363A0) --------------------------------------------------------
void __thiscall TDebuggingLog::Time(TDebuggingLog *this)
{
  TDebuggingLog *v1; // edi@1
  unsigned int v2; // esi@1
  struct tm *v3; // eax@1
  char *v4; // eax@2
  int ltime; // [sp+10h] [bp-Ch]@1
  __int64 fTicksElapsed; // [sp+14h] [bp-8h]@1

  v1 = this;
  v2 = debug_timeGetTime();
  time(&ltime);
  v3 = localtime(&ltime);
  fTicksElapsed = v2 - v1->LogStartTickCount;
  *(float *)&fTicksElapsed = (double)fTicksElapsed * 0.001;
  if( v3 )
    v4 = asctime(v3);
  else
    v4 = a_;
  TDebuggingLog::Log(v1, aTimeS7_1fSec_E, v4, *(float *)&fTicksElapsed);
}

//----- (00436430) --------------------------------------------------------
void __thiscall TDebuggingLog::FlushToDisk(TDebuggingLog *this, int DoFlush)
{
  TDebuggingLog *v2; // esi@1
  char *v3; // eax@4

  v2 = this;
  if( DoFlush )
    this->Flush = 1;
  else
    this->Flush = 0;
  v3 = TDebuggingLog::YesOrNo(this->Flush);
  TDebuggingLog::Log(v2, aFlushQueueEach, v3);
}

//----- (00436470) --------------------------------------------------------
void __thiscall TDebuggingLog::LogSequence(TDebuggingLog *this, int DoSequence)
{
  TDebuggingLog *v2; // esi@1
  char *v3; // eax@4

  v2 = this;
  if( DoSequence )
  {
    this->Sequence = 1;
    this->SeqNo = 0;
  }
  else
  {
    this->Sequence = 0;
  }
  v3 = TDebuggingLog::YesOrNo(this->Sequence);
  TDebuggingLog::Log(v2, aSequenceNumber, v3);
}

//----- (004364B0) --------------------------------------------------------
void __thiscall TDebuggingLog::OpenLog(TDebuggingLog *this)
{
  TDebuggingLog *v1; // ebp@1
  signed int v2; // eax@4
  bool v3; // zf@10
  bool v4; // sf@10
  unsigned __int8 v5; // of@10
  int nLoop; // [sp+10h] [bp-4h]@4

  v1 = this;
  if( this->LogToFile && (!this->LogIsOpen || this->LogError) )
  {
    this->LogStartTickCount = debug_timeGetTime();
    v2 = 1;
    for( nLoop = 1; ; v2 = nLoop )
    {
      if( v2 == 1 )
        strcpy(v1->Filename, aCAoelog_txt);
      else
        sprintf(v1->Filename, aCAoelog_2d_txt, v2 - 1);
      logstream = fopen(v1->Filename, aWt);
      if( logstream )
        break;
      v5 = __OFSUB__(nLoop + 1, 25);
      v3 = nLoop == 24;
      v4 = nLoop++ - 24 < 0;
      if( !((unsigned __int8)(v4 ^ v5) | v3) )
      {
        v1->LogError = 1;
        v1->LogIsOpen = 0;
        return;
      }
    }
    v1->LogIsOpen = 1;
    TDebuggingLog::Log(v1, aLogFileSIsOpen, v1->Filename);
    TDebuggingLog::Time(v1);
  }
}

//----- (004365A0) --------------------------------------------------------
void __thiscall TDebuggingLog::FlushLog(TDebuggingLog *this)
{
  if( this->LogToFile )
    fflush(logstream);
}

//----- (004365C0) --------------------------------------------------------
void __thiscall TDebuggingLog::CloseLog(TDebuggingLog *this)
{
  TDebuggingLog *v1; // esi@1

  v1 = this;
  if( this->LogToFile )
  {
    if( this != (TDebuggingLog *)-1840 )
      TDebuggingLog::Log(this, aClosingDebugLo, this->Filename);
    TDebuggingLog::Time(v1);
    TDebuggingLog::Log(v1, aLogFileIsClose);
    fclose(logstream);
    v1->LogIsOpen = 0;
  }
}

//----- (00436610) --------------------------------------------------------
void TDebuggingLog::Log(TDebuggingLog *this, char *fmt, ...)
{
  int v2; // eax@1
  DWORD v3; // eax@10
  unsigned int v4; // edx@10
  signed __int64 v5; // ST2C_8@10
  int v6; // eax@10
  unsigned __int64 v7; // st7@10
  char *v8; // eax@13
  int ltime; // [sp+20h] [bp-84h]@13
  char s2[32]; // [sp+24h] [bp-80h]@10
  char s3[32]; // [sp+44h] [bp-60h]@10
  char s4[32]; // [sp+64h] [bp-40h]@10
  char s1[32]; // [sp+84h] [bp-20h]@10
  va_list va; // [sp+B0h] [bp+Ch]@1

  va_start(va, fmt);
  v2 = this->LogToFile;
  if( (v2 || this->LogToOutput) && !this->LogError )
  {
    if( !this->LogIsOpen && v2 )
      TDebuggingLog::OpenLog(this);
    if( this->LogIsOpen || !this->LogToFile )
    {
      ++this->SeqNo;
      vsprintf(this->TBuff, fmt, va);
      v3 = GetTickCount();
      v4 = this->LogStartTickCount;
      v5 = v3;
      v6 = this->Timestamp;
      s4[0] = 0;
      s3[0] = 0;
      s2[0] = 0;
      s1[0] = 0;
      *(double *)&v7 = ((double)v5 - (double)(signed int)v4) * 0.001;
      if( v6 )
        sprintf(s1, a_2f, (_DWORD)v7, (_DWORD)(v7 >> 32));
      if( this->DateTimestamp )
      {
        time(&ltime);
        v8 = ctime(&ltime);
        strncat(s2, v8, 0x14u);
        strcat(s2, asc_5840F4);
      }
      if( this->Sequence )
        sprintf(s3, aLd, this->SeqNo);
      strcpy(s4, asc_580464);
      sprintf(this->osbuf, aSSSSS, s1, s2, s3, s4, this->TBuff);
      if( this->LogToOutput )
        OutputDebugStringA(this->osbuf);
      if( this->LogToFile && this->LogIsOpen )
      {
        fputs(this->osbuf, logstream);
        if( this->Flush )
          fflush(logstream);
      }
    }
    else
    {
      this->LogError = 1;
    }
  }
}

//----- (00436810) --------------------------------------------------------
char *__stdcall TDebuggingLog::YesOrNo(int TorF)
{
  char *result; // eax@1

  result = aIsNowActive_;
  if( !TorF )
    result = aHasBeenDeactiv;
  return result;
}
