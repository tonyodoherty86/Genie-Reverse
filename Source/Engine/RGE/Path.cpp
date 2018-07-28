
//----- (0046A740) --------------------------------------------------------
void __thiscall Path::Path(Path *this, int v)
{
  Path *v2; // esi@1
  char *v3; // ebx@3
  int v4; // edi@3
  int v5; // eax@4
  int v6; // ecx@4
  float v7; // edx@5

  v2 = this;
  this->timeStampValue = 0;
  this->pathValue = 0;
  this->maxSizeValue = 0;
  this->currentSizeValue = 0;
  this->currentWaypointValue = 0;
  LODWORD(this->startValue.x) = 0;
  LODWORD(this->startValue.y) = 0;
  LODWORD(this->startValue.z) = 0;
  LODWORD(this->goalValue.x) = 0;
  LODWORD(this->goalValue.y) = 0;
  LODWORD(this->goalValue.z) = 0;
  if( !v || v >= 0 )
  {
    this->maxSizeValue = v;
    v3 = (char *)operator new(16 * v);
    v4 = 0;
    if( v2->currentSizeValue > 0 )
    {
      v5 = 0;
      v6 = (int)(v3 + 8);
      do
      {
        ++v4;
        v6 += 16;
        v7 = v2->pathValue[v5].x;
        ++v5;
        *(float *)(v6 - 24) = v7;
        *(_DWORD *)(v6 - 20) = *((_DWORD *)&v2->pathValue[v5] - 3);
        *(_DWORD *)(v6 - 16) = *((_DWORD *)&v2->pathValue[v5] - 2);
        *(_BYTE *)(v6 - 12) = *((_BYTE *)&v2->pathValue[v5] - 4);
      }
      while( v4 < v2->currentSizeValue );
    }
    if( v2->pathValue )
      operator delete(v2->pathValue);
    v2->pathValue = (Waypoint *)v3;
  }
}

//----- (0046A7F0) --------------------------------------------------------
void __thiscall Path::~Path(Path *this)
{
  if( this->pathValue )
    operator delete(this->pathValue);
}

//----- (0046A810) --------------------------------------------------------
ostream *__cdecl operator<<(ostream *out, Path *p)
{
  int v2; // ebx@1
  int v3; // edi@2
  int v4; // eax@3
  unsigned __int64 v5; // st7@3
  ostream *v6; // eax@3
  int v7; // eax@3
  unsigned __int64 v8; // st7@3
  int v9; // ST04_4@3
  ostream *v10; // eax@3
  int v11; // eax@3
  unsigned __int64 v12; // st7@3
  ostream *v13; // eax@3
  ostream *v14; // eax@3
  int v16; // [sp+4h] [bp-14h]@0

  v2 = 0;
  if( p->currentSizeValue > 0 )
  {
    v3 = 0;
    do
    {
      v4 = ostream::operator<<(out, asc_584EE8);
      *(double *)&v5 = p->pathValue[v3].x;
      *(_DWORD *)(v4 + 4) = 1;
      v6 = (ostream *)ostream::operator<<(v16, v5 >> 32);
      v7 = ostream::operator<<(v6, asc_584EE4);
      *(double *)&v8 = p->pathValue[v3].y;
      *(_DWORD *)(v7 + 4) = 1;
      v10 = (ostream *)ostream::operator<<(v9, v8 >> 32);
      v11 = ostream::operator<<(v10, asc_584EE4);
      *(double *)&v12 = p->pathValue[v3].z;
      *(_DWORD *)(v11 + 4) = 1;
      v13 = (ostream *)ostream::operator<<(v12, v12 >> 32);
      ostream::operator<<(v13, asc_584EE4);
      v14 = (ostream *)ostream::operator<<(out, p->pathValue[v3].facetToNextWaypoint);
      ostream::operator<<(v14, asc_584EE0);
      ++v2;
      ++v3;
    }
    while( v2 < p->currentSizeValue );
  }
  return out;
}
// 55AFD0: using guessed type _DWORD __stdcall ostream::operator<<(_DWORD, _DWORD);

//----- (0046A8E0) --------------------------------------------------------
Path *__thiscall Path::operator+(Path *this, Path *result, Path *__$ReturnUdt)
{
  Path *v3; // esi@1
  int v4; // ebp@1
  int v5; // eax@1
  int v6; // edi@1
  int v7; // ecx@2
  Waypoint v8; // ST00_16@2
  int v9; // esi@3
  int v10; // edi@4
  Waypoint *v11; // edx@5
  Waypoint v12; // ST00_16@5
  Path newPath; // [sp+14h] [bp-40h]@1
  int v15; // [sp+50h] [bp-4h]@1

  v3 = this;
  v4 = 0;
  Path::Path(&newPath, __$ReturnUdt->maxSizeValue + this->maxSizeValue);
  v5 = v3->currentSizeValue;
  v6 = 0;
  v15 = 1;
  if( v5 > 0 )
  {
    do
    {
      v7 = (int)&v3->pathValue[v4];
      *(_QWORD *)&v8.x = *(_QWORD *)v7;
      *(_QWORD *)&v8.z = *(_QWORD *)(v7 + 8);
      Path::insertAtEnd(&newPath, v8);
      ++v6;
      ++v4;
    }
    while( v6 < v3->currentSizeValue );
  }
  v9 = 0;
  if( __$ReturnUdt->currentSizeValue > 0 )
  {
    v10 = v6;
    do
    {
      v11 = &__$ReturnUdt->pathValue[v10];
      *(_QWORD *)&v12.x = *(_QWORD *)&v11->x;
      *(_QWORD *)&v12.z = *(_QWORD *)&v11->z;
      Path::insertAtEnd(&newPath, v12);
      ++v10;
      ++v9;
    }
    while( v9 < __$ReturnUdt->currentSizeValue );
  }
  qmemcpy(result, &newPath, sizeof(Path));
  LOBYTE(v15) = 0;
  Path::~Path(&newPath);
  return result;
}

//----- (0046A9E0) --------------------------------------------------------
Path *__thiscall Path::operator=(Path *this, Path *p)
{
  Path *v2; // esi@1
  int v3; // ecx@1
  int v4; // eax@1
  int v5; // eax@5
  char *v6; // ebx@7
  int v7; // ebp@7
  int v8; // eax@8
  int v9; // ecx@8
  float v10; // edx@9
  int v11; // ecx@13
  int v12; // eax@14

  v2 = this;
  v3 = this->maxSizeValue;
  v4 = p->maxSizeValue;
  if( v3 < v4 )
  {
    if( !v4 )
      goto LABEL_19;
    if( v3 > v4 )
      goto LABEL_13;
    if( v4 )
      v5 = v3 + v4;
    else
LABEL_19:
      v5 = 2 * v3;
    v2->maxSizeValue = v5;
    v6 = (char *)operator new(16 * v5);
    v7 = 0;
    if( v2->currentSizeValue > 0 )
    {
      v8 = 0;
      v9 = (int)(v6 + 8);
      do
      {
        ++v7;
        v9 += 16;
        v10 = v2->pathValue[v8].x;
        ++v8;
        *(float *)(v9 - 24) = v10;
        *(_DWORD *)(v9 - 20) = *((_DWORD *)&v2->pathValue[v8] - 3);
        *(_DWORD *)(v9 - 16) = *((_DWORD *)&v2->pathValue[v8] - 2);
        *(_BYTE *)(v9 - 12) = *((_BYTE *)&v2->pathValue[v8] - 4);
      }
      while( v7 < v2->currentSizeValue );
    }
    if( v2->pathValue )
      operator delete(v2->pathValue);
    v2->pathValue = (Waypoint *)v6;
  }
LABEL_13:
  v11 = 0;
  if( p->currentSizeValue > 0 )
  {
    v12 = 0;
    do
    {
      ++v11;
      v2->pathValue[v12].x = p->pathValue[v12].x;
      v2->pathValue[v12].y = p->pathValue[v12].y;
      v2->pathValue[v12].z = p->pathValue[v12].z;
      v2->pathValue[v12].facetToNextWaypoint = p->pathValue[v12].facetToNextWaypoint;
      ++v12;
    }
    while( v11 < p->currentSizeValue );
  }
  v2->currentWaypointValue = p->currentWaypointValue;
  v2->currentSizeValue = p->currentSizeValue;
  return v2;
}

//----- (0046AAE0) --------------------------------------------------------
int __thiscall Path::operator==(Path *this, Path *p)
{
  int v2; // edi@1
  int v3; // esi@1
  Waypoint *v4; // eax@2
  Waypoint *v5; // ecx@2
  int v6; // edx@2
  int v7; // ebp@2
  int result; // eax@8

  v2 = this->currentSizeValue;
  v3 = 0;
  if( v2 <= 0 )
  {
    result = 1;
  }
  else
  {
    v4 = this->pathValue;
    v5 = p->pathValue;
    v6 = (int)&v4->z;
    v7 = (char *)v4 - (char *)v5;
    while( *(float *)((char *)&v5->x + v7) == v5->x
         && *(float *)(v6 - 4) == v5->y
         && *(float *)v6 == v5->z
         && *(_BYTE *)(v6 + 4) == v5->facetToNextWaypoint )
    {
      ++v3;
      v6 += 16;
      ++v5;
      if( v3 >= v2 )
        return 1;
    }
    result = 0;
  }
  return result;
}

//----- (0046AB60) --------------------------------------------------------
int __thiscall Path::insertAtCurrent(Path *this, Waypoint *w)
{
  Path *v2; // esi@1
  int v3; // eax@1
  int result; // eax@2
  Waypoint *v5; // ebp@3
  int v6; // edi@3
  int v7; // eax@4
  int v8; // ecx@4
  float v9; // edx@5
  int v10; // eax@8

  v2 = this;
  v3 = this->currentSizeValue;
  if( v3 <= 1000 )
  {
    v5 = (Waypoint *)operator new(16 * (v3 + 1));
    v6 = 0;
    *v5 = *w;
    if( v2->currentSizeValue > 0 )
    {
      v7 = 0;
      v8 = (int)&v5[1].y;
      do
      {
        ++v6;
        v8 += 16;
        v9 = v2->pathValue[v7].x;
        ++v7;
        *(float *)(v8 - 20) = v9;
        *(_DWORD *)(v8 - 16) = *((_DWORD *)&v2->pathValue[v7] - 3);
        *(_DWORD *)(v8 - 12) = *((_DWORD *)&v2->pathValue[v7] - 2);
        *(_BYTE *)(v8 - 8) = *((_BYTE *)&v2->pathValue[v7] - 4);
      }
      while( v6 < v2->currentSizeValue );
    }
    if( v2->pathValue )
      operator delete(v2->pathValue);
    v10 = v2->currentSizeValue;
    v2->pathValue = v5;
    v2->currentSizeValue = v10 + 1;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046AC10) --------------------------------------------------------
int __thiscall Path::insertAtEnd(Path *this, Waypoint w)
{
  Path *v2; // esi@1
  int v3; // eax@1
  int v4; // eax@2
  char *v5; // ebp@2
  int v6; // edi@2
  int v7; // eax@3
  int v8; // ecx@3
  float v9; // edx@4

  v2 = this;
  v3 = this->maxSizeValue;
  if( this->currentSizeValue == v3 )
  {
    v4 = 2 * v3;
    this->maxSizeValue = v4;
    v5 = (char *)operator new(16 * v4);
    v6 = 0;
    if( v2->currentSizeValue > 0 )
    {
      v7 = 0;
      v8 = (int)(v5 + 8);
      do
      {
        ++v6;
        v8 += 16;
        v9 = v2->pathValue[v7].x;
        ++v7;
        *(float *)(v8 - 24) = v9;
        *(_DWORD *)(v8 - 20) = *((_DWORD *)&v2->pathValue[v7] - 3);
        *(_DWORD *)(v8 - 16) = *((_DWORD *)&v2->pathValue[v7] - 2);
        *(_BYTE *)(v8 - 12) = *((_BYTE *)&v2->pathValue[v7] - 4);
      }
      while( v6 < v2->currentSizeValue );
    }
    if( v2->pathValue )
      operator delete(v2->pathValue);
    v2->pathValue = (Waypoint *)v5;
  }
  v2->pathValue[v2->currentSizeValue].x = w.x;
  v2->pathValue[v2->currentSizeValue].y = w.y;
  v2->pathValue[v2->currentSizeValue].z = w.z;
  v2->pathValue[v2->currentSizeValue++].facetToNextWaypoint = w.facetToNextWaypoint;
  return 1;
}

//----- (0046ACE0) --------------------------------------------------------
int __thiscall Path::contains(Path *this, Waypoint *w)
{
  Path *v2; // esi@1
  int v3; // ebx@1
  int v4; // edi@2
  double v5; // ST18_8@3
  double v6; // ST18_8@4
  int result; // eax@6

  v2 = this;
  v3 = 0;
  if( this->currentSizeValue <= 0 )
  {
    result = 0;
  }
  else
  {
    v4 = 0;
    while( 1 )
    {
      v5 = floor(v2->pathValue[v4].x);
      if( v5 == floor(w->x) )
      {
        v6 = floor(v2->pathValue[v4].y);
        if( v6 == floor(w->y) )
          break;
      }
      ++v3;
      ++v4;
      if( v3 >= v2->currentSizeValue )
        return 0;
    }
    result = 1;
  }
  return result;
}

//----- (0046ADA0) --------------------------------------------------------
void __thiscall Path::killPath(Path *this)
{
  this->currentSizeValue = 0;
  this->currentWaypointValue = 0;
}

//----- (0046ADB0) --------------------------------------------------------
int __thiscall Path::maxNumberOfWaypoints(Path *this)
{
  return this->maxSizeValue;
}

//----- (0046ADC0) --------------------------------------------------------
int __thiscall Path::numberOfWaypoints(Path *this)
{
  return this->currentSizeValue;
}

//----- (0046ADD0) --------------------------------------------------------
unsigned int __thiscall Path::timeStamp(Path *this)
{
  return this->timeStampValue;
}

//----- (0046ADE0) --------------------------------------------------------
void __thiscall Path::setTimeStamp(Path *this, unsigned int v)
{
  this->timeStampValue = v;
}

//----- (0046ADF0) --------------------------------------------------------
long double __thiscall Path::length(Path *this)
{
  int v1; // edx@1
  long double result; // st7@1
  Waypoint *v3; // eax@2
  int v4; // ecx@2
  int v5; // eax@2
  double v6; // st6@3
  double v7; // st5@3
  double v8; // st2@3
  float v9; // ST00_4@3
  double v10; // rt0@3
  double v11; // st2@3

  v1 = this->currentSizeValue;
  result = 0.0;
  if( v1 > 1 )
  {
    v3 = this->pathValue;
    v4 = v1 - 1;
    v5 = (int)&v3[1];
    do
    {
      v6 = *(float *)v5 - *(float *)(v5 - 16);
      v7 = *(float *)(v5 + 8) - *(float *)(v5 - 8);
      v8 = *(float *)(v5 + 4) - *(float *)(v5 - 12);
      v9 = v8;
      v10 = v8;
      v11 = *(float *)(v5 + 8) - *(float *)(v5 - 16);
      v5 += 16;
      --v4;
      result = result + sqrt(v7 * v11 + v6 * v6 + v10 * v9);
    }
    while( v4 );
  }
  return result;
}

//----- (0046AE50) --------------------------------------------------------
Waypoint *__thiscall Path::start(Path *this)
{
  return &this->startValue;
}

//----- (0046AE60) --------------------------------------------------------
Waypoint *__thiscall Path::goal(Path *this)
{
  return &this->goalValue;
}

//----- (0046AE70) --------------------------------------------------------
Waypoint *__thiscall Path::waypoint(Path *this, int w)
{
  Waypoint *v2; // edx@1
  Waypoint *result; // eax@4

  v2 = this->pathValue;
  if( v2 && w > -1 && w < this->currentSizeValue )
    result = &v2[w];
  else
    result = 0;
  return result;
}

//----- (0046AEA0) --------------------------------------------------------
Waypoint *__thiscall Path::currentWaypoint(Path *this)
{
  Waypoint *v1; // edx@1
  int v2; // eax@2
  Waypoint *result; // eax@4

  v1 = this->pathValue;
  if( v1 && (v2 = this->currentWaypointValue, v2 > -1) && v2 < this->currentSizeValue )
    result = &v1[v2];
  else
    result = 0;
  return result;
}

//----- (0046AEC0) --------------------------------------------------------
int __thiscall Path::currentWaypointNumber(Path *this)
{
  return this->currentWaypointValue;
}

//----- (0046AED0) --------------------------------------------------------
void __thiscall Path::setCurrentWaypointNumber(Path *this, int v)
{
  this->currentWaypointValue = v;
}

//----- (0046AEE0) --------------------------------------------------------
Waypoint *__thiscall Path::nextWaypoint(Path *this)
{
  Waypoint *v1; // edx@1
  int v2; // eax@2
  int v3; // eax@3
  Waypoint *result; // eax@4

  v1 = this->pathValue;
  if( v1 && (v2 = this->currentWaypointValue, v2 > -1) && (v3 = v2 + 1, v3 < this->currentSizeValue) )
    result = &v1[v3];
  else
    result = 0;
  return result;
}

//----- (0046AF10) --------------------------------------------------------
Waypoint *__thiscall Path::previousWaypoint(Path *this)
{
  Waypoint *v1; // edx@1
  int v2; // eax@2
  Waypoint *result; // eax@4

  v1 = this->pathValue;
  if( v1 && (v2 = this->currentWaypointValue, v2 + 1 > 0) && v2 < this->currentSizeValue )
    result = &v1[v2 - 1];
  else
    result = 0;
  return result;
}

//----- (0046AF40) --------------------------------------------------------
Waypoint *__thiscall Path::firstWaypoint(Path *this)
{
  Waypoint *result; // eax@1

  result = this->pathValue;
  if( !result || this->currentSizeValue <= 0 )
    result = 0;
  return result;
}

//----- (0046AF60) --------------------------------------------------------
Waypoint *__thiscall Path::lastWaypoint(Path *this)
{
  Waypoint *v1; // edx@1
  int v2; // eax@2
  Waypoint *result; // eax@3

  v1 = this->pathValue;
  if( v1 && (v2 = this->currentSizeValue, v2 > 0) )
    result = &v1[v2 - 1];
  else
    result = 0;
  return result;
}

//----- (0046AF80) --------------------------------------------------------
void __thiscall Path::initToStart(Path *this)
{
  this->currentWaypointValue = 0;
}

//----- (0046AF90) --------------------------------------------------------
void __thiscall Path::initToEnd(Path *this)
{
  this->currentWaypointValue = this->currentSizeValue - 1;
}

//----- (0046AFA0) --------------------------------------------------------
int __thiscall Path::moveToNextWaypoint(Path *this)
{
  int v1; // edx@1
  int v2; // eax@1
  int result; // eax@2

  v1 = this->currentWaypointValue;
  v2 = this->currentSizeValue - 1;
  if( v1 >= v2 )
  {
    this->currentWaypointValue = v2;
    result = 0;
  }
  else
  {
    result = 1;
    this->currentWaypointValue = v1 + 1;
  }
  return result;
}

//----- (0046AFC0) --------------------------------------------------------
int __thiscall Path::moveToLastWaypoint(Path *this)
{
  int v1; // eax@1
  int result; // eax@2

  v1 = this->currentWaypointValue;
  if( v1 <= 0 )
  {
    result = 0;
  }
  else
  {
    this->currentWaypointValue = v1 - 1;
    result = 1;
  }
  return result;
}

//----- (0046AFE0) --------------------------------------------------------
long double __thiscall Path::distanceToNextWaypoint(Path *this)
{
  Waypoint *v1; // edx@1
  long double result; // st7@1
  int v3; // eax@2
  int v4; // esi@4
  int v5; // eax@4
  double v6; // st6@4
  double v7; // st5@4
  double v8; // st7@4
  float v9; // ST04_4@4
  double v10; // rtt@4
  float v11; // ST04_4@4

  v1 = this->pathValue;
  result = 0.0;
  if( v1 )
  {
    v3 = this->currentWaypointValue;
    if( v3 >= 0 && v3 < this->currentSizeValue - 1 )
    {
      v4 = v3 + 1;
      v5 = (int)&v1[v3];
      v6 = *(float *)(v5 + 20) - *(float *)(v5 + 4);
      v7 = v1[v4].x - *(float *)v5;
      v8 = *(float *)(v5 + 24) - *(float *)(v5 + 8);
      v9 = v7;
      v10 = v7 * v9;
      v11 = v8;
      result = sqrt(v10 + v6 * v6 + v8 * v11);
    }
  }
  return result;
}
