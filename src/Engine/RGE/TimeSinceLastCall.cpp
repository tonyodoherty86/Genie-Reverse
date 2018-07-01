
//----- (00480390) --------------------------------------------------------
void __thiscall RGE_TimeSinceLastCall::RGE_TimeSinceLastCall(RGE_TimeSinceLastCall *this)
{
  RGE_TimeSinceLastCall *v1; // esi@1
  unsigned int v2; // eax@1

  v1 = this;
  this->lowTSLC = 99999;
  this->highTSLC = 0;
  this->Offset = 0;
  this->cps = 0;
  v2 = debug_timeGetTime();
  v1->FirstCall = v2;
  v1->Now = v2;
  v1->LastCall = v2;
  memset(v1->aTSLC, 0, sizeof(v1->aTSLC));
}

//----- (00480400) --------------------------------------------------------
unsigned int __thiscall RGE_TimeSinceLastCall::GetAvg(RGE_TimeSinceLastCall *this, int duration)
{
  unsigned int v2; // eax@1
  int v3; // edx@3
  int i; // esi@3
  unsigned int result; // eax@9

  v2 = 0;
  if ( duration < 1 || duration > 100 )
  {
    result = 0;
  }
  else
  {
    v3 = this->Offset;
    for ( i = 0; i < duration; ++i )
    {
      if ( --v3 <= 0 )
        v3 = 100;
      v2 += this->aTSLC[v3];
      if ( v2 >= 0x3E8 )
        this->cps = i;
    }
    result = v2 / duration;
  }
  return result;
}

//----- (00480460) --------------------------------------------------------
unsigned int __thiscall RGE_TimeSinceLastCall::Get(RGE_TimeSinceLastCall *this)
{
  return debug_timeGetTime() - this->LastCall;
}

//----- (00480480) --------------------------------------------------------
unsigned int __thiscall RGE_TimeSinceLastCall::Set(RGE_TimeSinceLastCall *this)
{
  RGE_TimeSinceLastCall *v1; // esi@1
  unsigned int v2; // eax@1
  unsigned int v3; // ecx@1
  unsigned int result; // eax@2
  int v5; // edx@3
  int v6; // ecx@3
  unsigned int v7; // ecx@5
  unsigned int v8; // ecx@7

  v1 = this;
  v2 = debug_timeGetTime();
  v3 = v1->LastCall;
  if ( v3 == v2 )
  {
    result = 0;
  }
  else
  {
    v1->LastCall = v2;
    v5 = v2 - v3;
    v6 = v1->Offset + 1;
    v1->TSLC = v5;
    v1->Offset = v6;
    if ( v6 > 100 )
      v1->Offset = 0;
    v1->aTSLC[v1->Offset] = v1->TSLC;
    result = v1->TSLC;
    v7 = v1->lowTSLC;
    if ( result < v7 )
      v7 = v1->TSLC;
    v1->lowTSLC = v7;
    v8 = v1->highTSLC;
    if ( result > v8 )
      v8 = result;
    v1->highTSLC = v8;
  }
  return result;
}

//----- (00480510) --------------------------------------------------------
void __thiscall RGE_TimeSinceLastCall::Skip(RGE_TimeSinceLastCall *this)
{
  RGE_TimeSinceLastCall *v1; // esi@1

  v1 = this;
  debug_timeGetTime();
  v1->LastCall = debug_timeGetTime();
}

//----- (00480540) --------------------------------------------------------
RGE_TimeSinceLastCall *__thiscall RGE_TimeSinceLastCall::GetAvgInfo(RGE_TimeSinceLastCall *this, int duration)
{
  RGE_TimeSinceLastCall *v2; // esi@1
  unsigned int v3; // eax@1

  v2 = this;
  v3 = RGE_TimeSinceLastCall::GetAvg(this, duration);
  sprintf(v2->TBuff, aAvgDD, v3, duration);
  return v2;
}

//----- (00480570) --------------------------------------------------------
RGE_TimeSinceLastCall *__thiscall RGE_TimeSinceLastCall::GetHiLoMaxInfo(RGE_TimeSinceLastCall *this, int duration)
{
  unsigned int v2; // ebp@1
  unsigned int v3; // eax@1
  unsigned int v4; // ebx@1
  RGE_TimeSinceLastCall *v5; // esi@1
  unsigned int v6; // edi@1
  int v7; // edx@3
  unsigned int v8; // ecx@6
  int v9; // ecx@11
  int v10; // eax@11

  v2 = duration;
  v3 = 0;
  v4 = 0;
  v5 = this;
  v6 = 999999;
  if ( duration < 1 || duration > 100 )
  {
    v10 = duration;
    v6 = duration;
    v9 = duration;
  }
  else
  {
    v7 = this->Offset;
    if ( duration > 0 )
    {
      do
      {
        if ( --v7 <= 0 )
          v7 = 100;
        v8 = v5->aTSLC[v7];
        v3 += v8;
        if ( v8 < v6 )
          v6 = v5->aTSLC[v7];
        if ( v8 > v4 )
          v4 = v5->aTSLC[v7];
        --duration;
      }
      while ( duration );
    }
    v9 = v4;
    v10 = v3 / v2;
  }
  sprintf(v5->TBuff, aLoloDLoDAvgDDH, v5->lowTSLC, v6, v10, v2, v9, v5->highTSLC);
  return v5;
}

//----- (00480610) --------------------------------------------------------
RGE_TimeSinceLastCall *__thiscall RGE_TimeSinceLastCall::GetHiLoInfo(RGE_TimeSinceLastCall *this, int duration)
{
  unsigned int v2; // ebp@1
  unsigned int v3; // eax@1
  unsigned int v4; // ebx@1
  RGE_TimeSinceLastCall *v5; // edi@1
  unsigned int v6; // esi@1
  int v7; // edx@3
  unsigned int v8; // ecx@6
  int v9; // ecx@11
  int v10; // eax@11

  v2 = duration;
  v3 = 0;
  v4 = 0;
  v5 = this;
  v6 = 999999;
  if ( duration < 1 || duration > 100 )
  {
    v10 = duration;
    v6 = duration;
    v9 = duration;
  }
  else
  {
    v7 = this->Offset;
    if ( duration > 0 )
    {
      do
      {
        if ( --v7 <= 0 )
          v7 = 100;
        v8 = v5->aTSLC[v7];
        v3 += v8;
        if ( v8 < v6 )
          v6 = v5->aTSLC[v7];
        if ( v8 > v4 )
          v4 = v5->aTSLC[v7];
        --duration;
      }
      while ( duration );
    }
    v9 = v4;
    v10 = v3 / v2;
  }
  sprintf(v5->TBuff, aLoDAvgDHiDOfD, v6, v10, v9, v2);
  return v5;
}

//----- (004806A0) --------------------------------------------------------
unsigned int __thiscall RGE_TimeSinceLastCall::CPS(RGE_TimeSinceLastCall *this)
{
  RGE_TimeSinceLastCall *v1; // esi@1

  v1 = this;
  this->cps = 0;
  RGE_TimeSinceLastCall::GetAvg(this, 100);
  return v1->cps;
}

//----- (004806C0) --------------------------------------------------------
unsigned int __thiscall RGE_TimeSinceLastCall::GetFirstCall(RGE_TimeSinceLastCall *this)
{
  return this->FirstCall;
}

//----- (004806D0) --------------------------------------------------------
RGE_TimeSinceLastCall *__thiscall RGE_TimeSinceLastCall::GetElapsedFirstCall(RGE_TimeSinceLastCall *this)
{
  RGE_TimeSinceLastCall *v1; // edi@1
  int v2; // ebx@1
  int v3; // esi@1
  unsigned int v4; // ecx@1
  unsigned int v5; // eax@1
  signed int v6; // ecx@1

  v1 = this;
  v2 = 0;
  v3 = 0;
  v4 = debug_timeGetTime();
  v5 = v1->FirstCall;
  v1->Now = v4;
  v6 = (v4 - v5) / 0x3E8;
  if ( v6 > 59 )
  {
    v3 = v6 / 60;
    v6 %= 60;
    if ( v3 > 59 )
    {
      v2 = v3 / 60;
      v3 %= 60;
    }
  }
  sprintf(v1->TBuff, a02ld02ld02ld, v2, v3, v6);
  return v1;
}

//----- (00480770) --------------------------------------------------------
void __thiscall RGE_TimeSinceLastCall::Test(RGE_TimeSinceLastCall *this)
{
  memset32(this->aTSLC, 10, 0x64u);
}
