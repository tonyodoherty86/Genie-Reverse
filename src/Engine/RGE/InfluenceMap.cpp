
//----- (0044DF80) --------------------------------------------------------
void __thiscall InfluenceMap::InfluenceMap(InfluenceMap *this, int x, int y, char initialValue)
{
  InfluenceMap *v4; // esi@1
  int v5; // ebx@1
  char *v6; // edi@1
  int v7; // eax@1
  unsigned int v8; // ecx@1
  char **v9; // eax@1
  int v10; // eax@2
  int i; // ecx@2

  v4 = this;
  this->ySizeValue = y;
  v5 = x * y;
  this->xSizeValue = x;
  this->xReferencePointValue = 0;
  this->yReferencePointValue = 0;
  this->vfptr = (InfluenceMapVtbl *)InfluenceMap::`vftable';
  v6 = (char *)operator new(x * y);
  LOBYTE(v5) = initialValue;
  BYTE1(v5) = initialValue;
  v4->valueValue = v6;
  v7 = v5 << 16;
  LOWORD(v7) = v5;
  v8 = (unsigned int)(x * y) >> 2;
  memset32(v6, v7, v8);
  memset(&v6[4 * v8], initialValue, (_BYTE)x * (_BYTE)y & 3);
  v9 = (char **)operator new(4 * v4->ySizeValue);
  v4->rowValue = v9;
  if ( v9 )
  {
    v10 = 0;
    for ( i = 0; v10 < v4->ySizeValue; i += v4->xSizeValue )
      v4->rowValue[v10++] = &v4->valueValue[i];
  }
}
// 570444: using guessed type int (__thiscall *InfluenceMap::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (0044E030) --------------------------------------------------------
InfluenceMap *__thiscall InfluenceMap::`vector deleting destructor'(InfluenceMap *this, unsigned int __flags)
{
  InfluenceMap *v2; // esi@1

  v2 = this;
  InfluenceMap::~InfluenceMap(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0044E050) --------------------------------------------------------
void __thiscall InfluenceMap::InfluenceMap(InfluenceMap *this, int infile)
{
  this->xSizeValue = -1;
  this->ySizeValue = -1;
  this->vfptr = (InfluenceMapVtbl *)InfluenceMap::`vftable';
  this->xReferencePointValue = 0;
  this->yReferencePointValue = 0;
  InfluenceMap::load(this, infile);
}
// 570444: using guessed type int (__thiscall *InfluenceMap::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (0044E080) --------------------------------------------------------
void __thiscall InfluenceMap::~InfluenceMap(InfluenceMap *this)
{
  InfluenceMap *v1; // esi@1
  char *v2; // eax@1
  char **v3; // esi@3

  v1 = this;
  v2 = this->valueValue;
  this->vfptr = (InfluenceMapVtbl *)InfluenceMap::`vftable';
  if ( v2 )
    operator delete(v2);
  v3 = v1->rowValue;
  if ( v3 )
    operator delete(v3);
}
// 570444: using guessed type int (__thiscall *InfluenceMap::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (0044E0B0) --------------------------------------------------------
int __userpurge InfluenceMap::initialize@<eax>(InfluenceMap *this@<ecx>, int a2@<ebx>, char initialValue)
{
  char *v3; // edi@1
  unsigned int v4; // edx@1
  int v5; // eax@1

  LOBYTE(a2) = initialValue;
  BYTE1(a2) = initialValue;
  v3 = this->valueValue;
  v4 = this->xSizeValue * this->ySizeValue;
  v5 = a2 << 16;
  LOWORD(v5) = a2;
  memset32(v3, v5, v4 >> 2);
  memset(&v3[4 * (v4 >> 2)], initialValue, v4 & 3);
  return 1;
}

//----- (0044E0F0) --------------------------------------------------------
void __thiscall InfluenceMap::save(InfluenceMap *this, int outfile)
{
  int v2; // ebx@1
  InfluenceMap *v3; // edi@1
  char *v4; // ebp@1
  int i; // esi@2
  int outfilea; // [sp+14h] [bp+4h]@1

  v2 = outfile;
  v3 = this;
  v4 = (char *)&this->xSizeValue;
  rge_write(outfile, &this->xSizeValue, 4);
  rge_write(outfile, &v3->ySizeValue, 4);
  rge_write(outfile, &v3->xReferencePointValue, 4);
  rge_write(outfile, &v3->yReferencePointValue, 4);
  rge_write(outfile, &v3->unchangeableLimitValue, 1);
  for ( outfilea = 0; outfilea < v3->ySizeValue; ++outfilea )
  {
    for ( i = 0; i < *(_DWORD *)v4; ++i )
      rge_write(v2, &v3->rowValue[outfilea][i], 1);
  }
}

//----- (0044E1A0) --------------------------------------------------------
void __thiscall InfluenceMap::load(InfluenceMap *this, int infile)
{
  int v2; // ebx@1
  InfluenceMap *v3; // edi@1
  char *v4; // ebp@1
  int i; // esi@2
  int j; // [sp+10h] [bp-4h]@1

  v2 = infile;
  v3 = this;
  v4 = (char *)&this->xSizeValue;
  rge_read((int)&this->xSizeValue, (int)this, infile, &this->xSizeValue, 4);
  rge_read((int)v4, (int)v3, v2, &v3->ySizeValue, 4);
  rge_read((int)v4, (int)v3, v2, &v3->xReferencePointValue, 4);
  rge_read((int)v4, (int)v3, v2, &v3->yReferencePointValue, 4);
  rge_read((int)v4, (int)v3, v2, &v3->unchangeableLimitValue, 1);
  for ( j = 0; j < v3->ySizeValue; ++j )
  {
    for ( i = 0; i < *(_DWORD *)v4; v3->rowValue[j][i - 1] = infile )
    {
      rge_read((int)v4, (int)v3, v2, &infile, 1);
      ++i;
    }
  }
}

//----- (0044E250) --------------------------------------------------------
void __thiscall InfluenceMap::printToFile(InfluenceMap *this, char *filename)
{
  InfluenceMap *v2; // ebx@1
  FILE *v3; // eax@2
  FILE *v4; // esi@2
  signed int i; // edi@3
  signed int j; // edi@8
  char *v7; // ebp@13
  signed int k; // edi@14
  int v9; // ecx@15
  int v10; // edi@19
  signed int l; // edi@23
  signed int m; // edi@28
  char *filenamea; // [sp+10h] [bp+4h]@13

  v2 = this;
  if ( filename )
  {
    v3 = fopen(filename, aWa);
    v4 = v3;
    if ( v3 )
    {
      fprintf(v3, aFilenameS, filename);
      fprintf(v4, aDimensionsDXD, v2->xSizeValue, v2->ySizeValue);
      fprintf(v4, aReferencePoint, v2->xReferencePointValue, v2->yReferencePointValue);
      fprintf(v4, Str);
      fprintf(v4, asc_584818);
      for ( i = 0; i < v2->xSizeValue; ++i )
      {
        if ( i % 5 )
          fprintf(v4, a03d_1, i);
        else
          fprintf(v4, a03d, i);
      }
      fprintf(v4, Str);
      fprintf(v4, asc_584818);
      for ( j = 0; j < v2->xSizeValue; ++j )
      {
        if ( j % 5 )
          fprintf(v4, asc_5847F8, j);
        else
          fprintf(v4, asc_584800, j);
      }
      fprintf(v4, Str);
      v7 = 0;
      filenamea = 0;
      if ( v2->ySizeValue > 0 )
      {
        do
        {
          fprintf(v4, aR03d, v7);
          for ( k = 0; k < v2->xSizeValue; ++k )
          {
            v9 = v2->rowValue[(_DWORD)v7][k];
            if ( k % 5 )
              fprintf(v4, a03d_1, v9);
            else
              fprintf(v4, a03d, v9);
            v7 = filenamea;
          }
          v10 = (int)(v7 + 1);
          if ( (signed int)(v7 + 1) % 5 )
            fprintf(v4, aR03d_3, v7);
          else
            fprintf(v4, aR03d_0, v7);
          ++v7;
          filenamea = (char *)v10;
        }
        while ( v10 < v2->ySizeValue );
      }
      fprintf(v4, asc_584818);
      for ( l = 0; l < v2->xSizeValue; ++l )
      {
        if ( l % 5 )
          fprintf(v4, asc_5847F8, l);
        else
          fprintf(v4, asc_584800, l);
      }
      fprintf(v4, Str);
      fprintf(v4, asc_584818);
      for ( m = 0; m < v2->xSizeValue; ++m )
      {
        if ( m % 5 )
          fprintf(v4, a03d_1, m);
        else
          fprintf(v4, a03d, m);
      }
      fprintf(v4, Str);
      fclose(v4);
    }
  }
}

//----- (0044E4C0) --------------------------------------------------------
void __thiscall InfluenceMap::setReferencePoint(InfluenceMap *this, int x, int y)
{
  this->xReferencePointValue = x;
  this->yReferencePointValue = y;
}

//----- (0044E4E0) --------------------------------------------------------
int __thiscall InfluenceMap::lookupValue(InfluenceMap *this, int x, int y)
{
  return *(&this->rowValue[y - this->yReferencePointValue][x] - this->xReferencePointValue);
}

//----- (0044E510) --------------------------------------------------------
int __thiscall InfluenceMap::setValue(InfluenceMap *this, int x, int y, char v)
{
  int v4; // eax@1
  int v5; // edx@1
  int result; // eax@5

  v4 = x - this->xReferencePointValue;
  v5 = y - this->yReferencePointValue;
  if ( v4 < 0 || v5 < 0 || v4 >= this->xSizeValue || v5 >= this->ySizeValue )
  {
    result = 0;
  }
  else
  {
    this->rowValue[v5][v4] = v;
    result = 1;
  }
  return result;
}

//----- (0044E560) --------------------------------------------------------
int __thiscall InfluenceMap::setValue(InfluenceMap *this, int minX, int minY, int maxX, int maxY, char v)
{
  int v6; // eax@1
  int v7; // esi@1
  int v8; // edi@1
  int v9; // eax@1
  int v10; // edx@1
  int v11; // ebp@1
  int v12; // ebx@3
  int v13; // eax@4
  int v14; // ebx@9
  int v15; // eax@10
  int v16; // ebx@11
  int result; // eax@15
  int minXa; // [sp+14h] [bp+4h]@9
  int maxYa; // [sp+20h] [bp+10h]@1

  v6 = this->xReferencePointValue;
  v7 = maxX - v6;
  v8 = minX - v6;
  v9 = this->yReferencePointValue;
  v10 = minY - v9;
  v11 = maxY - v9;
  maxYa = maxY - v9;
  if ( v8 < 0
    || v10 < 0
    || (v12 = this->xSizeValue, v8 >= v12)
    || (v13 = this->ySizeValue, v10 >= v13)
    || v7 < 0
    || v11 < 0
    || v7 >= v12
    || v11 >= v13 )
  {
    result = 0;
  }
  else
  {
    v14 = v10;
    for ( minXa = v10; v14 <= v11; minXa = v14 )
    {
      v15 = v8;
      if ( v8 <= v7 )
      {
        v16 = v14;
        do
          this->rowValue[v16][++v15 - 1] = v;
        while ( v15 <= v7 );
        v11 = maxYa;
        v14 = minXa;
      }
      ++v14;
    }
    result = 1;
  }
  return result;
}

//----- (0044E600) --------------------------------------------------------
int __thiscall InfluenceMap::incrementValue(InfluenceMap *this, int x, int y, char v)
{
  int v4; // eax@1
  int v5; // edx@1
  char **v6; // esi@5
  char v7; // cl@5
  char *v8; // esi@5
  int result; // eax@6
  int v10; // edx@7

  v4 = x - this->xReferencePointValue;
  v5 = y - this->yReferencePointValue;
  if ( v4 < 0 || v5 < 0 || v4 >= this->xSizeValue || v5 >= this->ySizeValue )
  {
    result = 0;
  }
  else
  {
    v6 = this->rowValue;
    v7 = this->unchangeableLimitValue;
    v8 = &v6[v5][v4];
    if ( (unsigned __int8)*v8 < (unsigned __int8)v7 )
    {
      v10 = (unsigned __int8)*v8 + (unsigned __int8)v;
      if ( v10 < (unsigned __int8)v7 )
      {
        *v8 = v10;
        result = 1;
      }
      else
      {
        result = 1;
        *v8 = v7 - 1;
      }
    }
    else
    {
      result = 1;
    }
  }
  return result;
}

//----- (0044E680) --------------------------------------------------------
int __thiscall InfluenceMap::incrementValue(InfluenceMap *this, int minX, int minY, int maxX, int maxY, char v)
{
  InfluenceMap *v6; // ebp@1
  int v7; // eax@1
  int v8; // edi@1
  int v9; // esi@1
  int v10; // eax@1
  int v11; // edx@1
  int v12; // ecx@1
  int v13; // eax@3
  int v14; // eax@8
  int v15; // eax@12
  int v16; // eax@17
  char **v17; // eax@22
  char v18; // dl@22
  char *v19; // esi@22
  int v20; // ebx@23
  char *v21; // esi@23
  int v22; // eax@23
  bool v23; // zf@28
  int minXa; // [sp+14h] [bp+4h]@1
  int minYa; // [sp+18h] [bp+8h]@20
  int maxXa; // [sp+1Ch] [bp+Ch]@1
  int maxYa; // [sp+20h] [bp+10h]@20

  v6 = this;
  v7 = this->xReferencePointValue;
  v8 = minX - v7;
  v9 = maxX - v7;
  v10 = this->yReferencePointValue;
  minXa = v8;
  v11 = minY - v10;
  v12 = maxY - v10;
  maxXa = v9;
  if ( v8 >= 0 )
  {
    v13 = v6->xSizeValue;
    if ( v8 < v13 )
      goto LABEL_6;
    v8 = v13 - 1;
  }
  else
  {
    v8 = 0;
  }
  minXa = v8;
LABEL_6:
  if ( v11 >= 0 )
  {
    v14 = v6->xSizeValue;
    if ( v11 >= v14 )
      v11 = v14 - 1;
  }
  else
  {
    v11 = 0;
  }
  if ( v9 >= 0 )
  {
    v15 = v6->xSizeValue;
    if ( v9 < v15 )
      goto LABEL_15;
    v9 = v15 - 1;
  }
  else
  {
    v9 = 0;
  }
  maxXa = v9;
LABEL_15:
  if ( v12 >= 0 )
  {
    v16 = v6->xSizeValue;
    if ( v12 >= v16 )
      v12 = v16 - 1;
  }
  else
  {
    v12 = 0;
  }
  if ( v11 <= v12 )
  {
    minYa = v11;
    maxYa = v12 - v11 + 1;
    do
    {
      if ( v8 <= v9 )
      {
        do
        {
          v17 = &v6->rowValue[minYa];
          v18 = v6->unchangeableLimitValue;
          v19 = *v17;
          if ( (unsigned __int8)(*v17)[v8] < (unsigned __int8)v18 )
          {
            v20 = (unsigned __int8)v19[v8];
            v21 = &v19[v8];
            v22 = v20 + (unsigned __int8)v;
            if ( v22 < (unsigned __int8)v18 )
              *v21 = v22;
            else
              *v21 = v18 - 1;
          }
          v9 = maxXa;
          ++v8;
        }
        while ( v8 <= maxXa );
        v8 = minXa;
      }
      v23 = maxYa == 1;
      ++minYa;
      --maxYa;
    }
    while ( !v23 );
  }
  return 1;
}

//----- (0044E790) --------------------------------------------------------
int __thiscall InfluenceMap::decrementValue(InfluenceMap *this, int x, int y, char v)
{
  int v4; // eax@1
  int v5; // edx@1
  char *v6; // edx@5
  int result; // eax@6
  int v8; // ecx@7
  int v9; // eax@7
  int v10; // ecx@7

  v4 = x - this->xReferencePointValue;
  v5 = y - this->yReferencePointValue;
  if ( v4 < 0 || v5 < 0 || v4 >= this->xSizeValue || v5 >= this->ySizeValue )
  {
    result = 0;
  }
  else
  {
    v6 = &this->rowValue[v5][v4];
    if ( (unsigned __int8)*v6 < this->unchangeableLimitValue )
    {
      v8 = (unsigned __int8)v;
      v9 = (unsigned __int8)*v6 - (unsigned __int8)v;
      LOBYTE(v8) = v9 < 0;
      v10 = v9 & (v8 - 1);
      result = 1;
      *v6 = v10;
    }
    else
    {
      result = 1;
    }
  }
  return result;
}

//----- (0044E800) --------------------------------------------------------
int __thiscall InfluenceMap::decrementValue(InfluenceMap *this, int minX, int minY, int maxX, int maxY, char v)
{
  InfluenceMap *v6; // edi@1
  int v7; // eax@1
  int v8; // ebx@1
  int v9; // esi@1
  int v10; // eax@1
  int v11; // edx@1
  int v12; // ecx@1
  int v13; // eax@3
  int v14; // eax@7
  int v15; // eax@11
  int v16; // eax@15
  int v17; // ebx@18
  int i; // esi@19
  char **v19; // eax@20
  int minXa; // [sp+14h] [bp+4h]@1
  int minYa; // [sp+18h] [bp+8h]@18
  int maxXa; // [sp+1Ch] [bp+Ch]@1

  v6 = this;
  v7 = this->xReferencePointValue;
  v8 = minX - v7;
  v9 = maxX - v7;
  v10 = this->yReferencePointValue;
  minXa = v8;
  v11 = minY - v10;
  v12 = maxY - v10;
  maxXa = v9;
  if ( v8 >= 0 )
  {
    v13 = v6->xSizeValue;
    if ( v8 >= v13 )
      minXa = v13 - 1;
  }
  else
  {
    minXa = 0;
  }
  if ( v11 >= 0 )
  {
    v14 = v6->xSizeValue;
    if ( v11 >= v14 )
      v11 = v14 - 1;
  }
  else
  {
    v11 = 0;
  }
  if ( v9 >= 0 )
  {
    v15 = v6->xSizeValue;
    if ( v9 >= v15 )
      maxXa = v15 - 1;
  }
  else
  {
    maxXa = 0;
  }
  if ( v12 >= 0 )
  {
    v16 = v6->xSizeValue;
    if ( v12 >= v16 )
      v12 = v16 - 1;
  }
  else
  {
    v12 = 0;
  }
  if ( v11 <= v12 )
  {
    v17 = v11;
    minYa = v12 - v11 + 1;
    do
    {
      for ( i = minXa; i <= maxXa; ++i )
      {
        v19 = &v6->rowValue[v17];
        if ( (unsigned __int8)(*v19)[i] < v6->unchangeableLimitValue )
          (*v19)[i] = ((*v19)[i] - v) & (((unsigned __int8)(*v19)[i] - (unsigned __int8)v < 0) - 1);
      }
      ++v17;
      --minYa;
    }
    while ( minYa );
  }
  return 1;
}

//----- (0044E900) --------------------------------------------------------
int __thiscall InfluenceMap::setCoverageCount(InfluenceMap *this, XYPoint *min, XYPoint *max, int valueLevel)
{
  XYPoint *v4; // edi@1
  int v5; // esi@1
  int v6; // eax@2
  int v7; // ebx@3
  XYPoint *v8; // ebp@5
  int v9; // edx@5
  int v10; // eax@6
  int v11; // ebx@10
  char **v12; // ebp@11
  int v13; // esi@11
  int v14; // edx@11
  int v15; // edi@11
  int v16; // ecx@12
  bool v17; // sf@12
  unsigned __int8 v18; // of@12
  int result; // eax@17
  InfluenceMap *v20; // [sp+10h] [bp-8h]@1
  int i; // [sp+14h] [bp-4h]@9

  v4 = min;
  this->coverageCountValue = 0;
  v20 = this;
  v5 = min->x;
  if ( min->x < 0
    || (v6 = min->y, v6 < 0)
    || (v7 = this->xSizeValue, v5 >= v7)
    || v6 >= this->ySizeValue
    || (v8 = max, v9 = max->x, max->x < 0)
    || (v10 = max->y, v10 < 0)
    || v9 >= v7
    || v10 >= this->ySizeValue )
  {
    result = 0;
  }
  else
  {
    i = min->x;
    if ( v5 <= v9 )
    {
      do
      {
        v11 = v4->y;
        if ( v11 <= v10 )
        {
          v12 = this->rowValue;
          v13 = v5 - this->xReferencePointValue;
          v14 = 4 * v11;
          v15 = 4 * this->yReferencePointValue;
          do
          {
            v16 = (unsigned __int8)(*(char **)((char *)v12 + v14 - v15))[v13];
            v18 = __OFSUB__(v16, valueLevel);
            v17 = v16 - valueLevel < 0;
            this = v20;
            if ( !(v17 ^ v18) )
              ++v20->coverageCountValue;
            ++v11;
            v14 += 4;
            v10 = max->y;
          }
          while ( v11 <= v10 );
          v5 = i;
          v4 = min;
          v8 = max;
        }
        i = ++v5;
      }
      while ( v5 <= v8->x );
    }
    result = this->coverageCountValue;
  }
  return result;
}

//----- (0044E9E0) --------------------------------------------------------
int __thiscall InfluenceMap::setConnectionCount(InfluenceMap *this, XYPoint *min, XYPoint *max, int valueLevel, int countOrthogonalEdgesAsConnections, int countDiagonalEdgesAsConnections, int countDiagonalConnections)
{
  InfluenceMap *v7; // edi@1
  int v8; // esi@1
  int v9; // eax@2
  int v10; // ebx@3
  int v11; // ecx@4
  XYPoint *v12; // ebp@5
  int v13; // edx@5
  int v14; // eax@6
  int v15; // ecx@10
  int v16; // edx@11
  int v17; // ecx@11
  int v18; // ebx@13
  int v19; // edi@13
  int v20; // esi@13
  signed int v21; // ebp@13
  InfluenceMap *v23; // [sp+10h] [bp-24h]@1
  int v24; // [sp+14h] [bp-20h]@11
  int j; // [sp+18h] [bp-1Ch]@10
  char **v26; // [sp+1Ch] [bp-18h]@11
  int i; // [sp+20h] [bp-14h]@9
  int v28; // [sp+24h] [bp-10h]@3
  int v29; // [sp+28h] [bp-Ch]@4
  int v30; // [sp+2Ch] [bp-8h]@11
  int v31; // [sp+30h] [bp-4h]@11

  v7 = this;
  v23 = this;
  this->connectionCountValue = 0;
  v8 = min->x;
  if ( min->x >= 0 )
  {
    v9 = min->y;
    if ( v9 >= 0 )
    {
      v10 = this->xSizeValue;
      v28 = this->xSizeValue;
      if ( v8 < v10 )
      {
        v11 = this->ySizeValue;
        v29 = v7->ySizeValue;
        if ( v9 < v11 )
        {
          v12 = max;
          v13 = max->x;
          if ( max->x >= 0 )
          {
            v14 = max->y;
            if ( v14 >= 0 && v13 < v10 && v14 < v11 )
            {
              i = min->x;
              if ( v8 > v13 )
                return v7->connectionCountValue;
              while ( 1 )
              {
                v15 = min->y;
                j = min->y;
                if ( v15 > v14 )
                  goto LABEL_33;
                v26 = v7->rowValue;
                v30 = v7->xReferencePointValue;
                v16 = v8 - v30;
                v31 = v8 - v30;
                v24 = 4 * v15;
                v17 = 4 * v7->yReferencePointValue;
                do
                {
                  if ( (unsigned __int8)(*(char **)((char *)v26 + v24 - v17))[v16] < valueLevel )
                    goto LABEL_32;
                  v18 = j;
                  v19 = v8;
                  v20 = v24;
                  v21 = 0;
                  do
                  {
                    switch ( v21 )
                    {
                      case 0:
                        --v19;
                        goto LABEL_16;
                      case 7:
LABEL_16:
                        --v18;
                        v20 -= 4;
                        break;
                      case 1:
                      case 2:
                        ++v19;
                        break;
                      case 3:
                      case 4:
                        ++v18;
                        v20 += 4;
                        break;
                      case 5:
                      case 6:
                        --v19;
                        break;
                      default:
                        break;
                    }
                    if ( countDiagonalConnections || (char)v21 % -2 )
                    {
                      if ( v19 >= 0 && v19 < v28 && v18 >= 0 && v18 < v29 )
                      {
                        if ( (unsigned __int8)*(&(*(char **)((char *)v26 + v20 - v17))[v19] - v30) < valueLevel )
                          goto LABEL_30;
LABEL_29:
                        ++v23->connectionCountValue;
                        goto LABEL_30;
                      }
                      if ( countOrthogonalEdgesAsConnections == 1
                        && (((unsigned __int64)v21 >> 32) ^ abs(v21) & 1) - ((unsigned __int64)v21 >> 32) == 1
                        || countDiagonalEdgesAsConnections == 1 && !((char)v21 % -2) )
                      {
                        goto LABEL_29;
                      }
                    }
LABEL_30:
                    ++v21;
                  }
                  while ( v21 < 8 );
                  v12 = max;
                  v7 = v23;
                  v8 = i;
                  v16 = v31;
LABEL_32:
                  v24 += 4;
                  v14 = v12->y;
                  ++j;
                }
                while ( j <= v14 );
LABEL_33:
                i = ++v8;
                if ( v8 > v12->x )
                  return v7->connectionCountValue;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

//----- (0044EC00) --------------------------------------------------------
int __thiscall InfluenceMap::coverageIncluding(InfluenceMap *this, XYPoint *min, XYPoint *max, char valueLevel, char newValueLevel)
{
  int v5; // esi@1
  int v6; // edx@2
  int v7; // ebp@3
  int v8; // ebx@4
  XYPoint *v9; // eax@5
  int v10; // edi@5
  int v11; // eax@6
  char **v12; // ebp@11
  int v13; // esi@11
  int v14; // ebx@11
  int v15; // edi@11
  int v16; // eax@11
  int result; // eax@18
  int rVal; // [sp+10h] [bp-10h]@1
  InfluenceMap *v19; // [sp+14h] [bp-Ch]@1
  int v20; // [sp+18h] [bp-8h]@2
  int v21; // [sp+1Ch] [bp-4h]@6
  XYPoint *mina; // [sp+24h] [bp+4h]@9
  int i; // [sp+28h] [bp+8h]@5

  rVal = this->coverageCountValue;
  v5 = min->x;
  v19 = this;
  if ( min->x < 0
    || (v6 = min->y, v20 = min->y, v6 < 0)
    || (v7 = this->xSizeValue, v5 >= v7)
    || (v8 = this->ySizeValue, v6 >= v8)
    || (v9 = max, v10 = max->x, i = max->x, i < 0)
    || (v11 = v9->y, v21 = v11, v11 < 0)
    || v10 >= v7
    || v11 >= v8 )
  {
    result = 0;
  }
  else
  {
    for ( mina = (XYPoint *)min->x; v5 <= v10; mina = (XYPoint *)v5 )
    {
      if ( v6 <= v11 )
      {
        v12 = this->rowValue;
        v13 = v5 - this->xReferencePointValue;
        v14 = 4 * v6;
        v15 = 4 * this->yReferencePointValue;
        v16 = v11 - v6 + 1;
        do
        {
          if ( (unsigned __int8)(*(char **)((char *)v12 + v14 - v15))[v13] < (unsigned __int8)valueLevel
            && (unsigned __int8)newValueLevel + (unsigned __int8)(*(char **)((char *)v12 + v14 - v15))[v13] >= (unsigned __int8)valueLevel )
          {
            ++rVal;
          }
          v14 += 4;
          --v16;
        }
        while ( v16 );
        this = v19;
        v5 = (int)mina;
        v6 = v20;
        v10 = i;
        v11 = v21;
      }
      ++v5;
    }
    result = rVal;
  }
  return result;
}

//----- (0044ED20) --------------------------------------------------------
int __thiscall InfluenceMap::connectionsIncluding(InfluenceMap *this, XYPoint *min, XYPoint *max, char valueLevel, char newValueLevel, int countOrthogonalEdgesAsConnections, int countDiagonalEdgesAsConnections, int countDiagonalConnections)
{
  int v8; // edx@1
  InfluenceMap *v9; // esi@1
  int v10; // ebp@1
  int v11; // eax@2
  int v12; // ebx@3
  int v13; // ecx@4
  int v14; // edi@6
  int v15; // eax@7
  int v16; // eax@11
  int v17; // edx@11
  int v18; // eax@11
  int v19; // ecx@11
  int v20; // edi@14
  XYPoint *v21; // ebx@14
  signed int v22; // esi@14
  int v23; // edi@32
  XYPoint *v24; // ebx@32
  int v25; // esi@32
  signed int v26; // ebp@32
  int v27; // eax@46
  bool v28; // zf@55
  bool v29; // sf@55
  unsigned __int8 v30; // of@55
  int rVal; // [sp+10h] [bp-34h]@1
  int i; // [sp+14h] [bp-30h]@9
  char **v34; // [sp+18h] [bp-2Ch]@11
  int v35; // [sp+1Ch] [bp-28h]@3
  int v36; // [sp+20h] [bp-24h]@4
  int v37; // [sp+24h] [bp-20h]@5
  int v38; // [sp+28h] [bp-1Ch]@2
  int v39; // [sp+34h] [bp-10h]@11
  InfluenceMap *v40; // [sp+38h] [bp-Ch]@1
  int v41; // [sp+3Ch] [bp-8h]@6
  int v42; // [sp+40h] [bp-4h]@11
  XYPoint *mina; // [sp+48h] [bp+4h]@10
  int j; // [sp+4Ch] [bp+8h]@11

  v8 = min->x;
  v9 = this;
  v10 = this->connectionCountValue;
  v40 = this;
  rVal = this->connectionCountValue;
  if ( min->x >= 0 )
  {
    v11 = min->y;
    v38 = min->y;
    if ( v11 >= 0 )
    {
      v12 = this->xSizeValue;
      v35 = this->xSizeValue;
      if ( v8 < v12 )
      {
        v13 = this->ySizeValue;
        v36 = v9->ySizeValue;
        if ( v11 < v13 )
        {
          v37 = max->x;
          if ( max->x >= 0 )
          {
            v14 = max->y;
            v41 = max->y;
            if ( v14 >= 0 )
            {
              v15 = max->x;
              if ( v37 < v12 && v14 < v13 )
              {
                i = min->x;
                if ( v8 > v37 )
                  return v10;
                while ( 1 )
                {
                  mina = (XYPoint *)v38;
                  if ( v38 > v14 )
                    goto LABEL_57;
                  v34 = v9->rowValue;
                  v16 = v9->xReferencePointValue;
                  v39 = v16;
                  v17 = v8 - v16;
                  v42 = v17;
                  v18 = 4 * v38;
                  j = 4 * v38;
                  v19 = 4 * v9->yReferencePointValue;
                  do
                  {
                    if ( (unsigned __int8)newValueLevel + (unsigned __int8)(*(char **)((char *)v34 + v18 - v19))[v17] < (unsigned __int8)valueLevel )
                      goto LABEL_55;
                    if ( (unsigned __int8)(*(char **)((char *)v34 + j - v19))[v17] >= (unsigned __int8)valueLevel )
                    {
                      v20 = i;
                      v21 = mina;
                      v22 = 0;
                      do
                      {
                        switch ( v22 )
                        {
                          case 0:
                            --v20;
                            goto LABEL_17;
                          case 7:
LABEL_17:
                            v21 = (XYPoint *)((char *)v21 - 1);
                            break;
                          case 1:
                          case 2:
                            ++v20;
                            break;
                          case 3:
                          case 4:
                            v21 = (XYPoint *)((char *)v21 + 1);
                            break;
                          case 5:
                          case 6:
                            --v20;
                            break;
                          default:
                            break;
                        }
                        if ( countDiagonalConnections || (char)v22 % -2 )
                        {
                          if ( (v20 < 0 || v20 >= v35 || (signed int)v21 < 0 || (signed int)v21 >= v36)
                            && (countOrthogonalEdgesAsConnections == 1
                             && (((unsigned __int64)v22 >> 32) ^ abs(v22) & 1) - ((unsigned __int64)v22 >> 32) == 1
                             || countDiagonalEdgesAsConnections == 1 && !((char)v22 % -2)) )
                          {
                            --v10;
                          }
                          if ( v10 <= 0 )
                            break;
                        }
                        ++v22;
                      }
                      while ( v22 < 8 );
                      rVal = v10;
                    }
                    v23 = i;
                    v24 = mina;
                    v25 = j;
                    v26 = 0;
                    do
                    {
                      switch ( v26 )
                      {
                        case 0:
                          --v23;
                          goto LABEL_38;
                        case 1:
                        case 2:
                          ++v23;
                          break;
                        case 3:
                        case 4:
                          v24 = (XYPoint *)((char *)v24 + 1);
                          v25 += 4;
                          break;
                        case 5:
                        case 6:
                          --v23;
                          break;
                        case 7:
LABEL_38:
                          v24 = (XYPoint *)((char *)v24 - 1);
                          v25 -= 4;
                          break;
                        default:
                          break;
                      }
                      if ( countDiagonalConnections || (char)v26 % -2 )
                      {
                        if ( v23 >= 0 && v23 < v35 && (signed int)v24 >= 0 && (signed int)v24 < v36 )
                        {
                          if ( (unsigned __int8)*(&(*(char **)((char *)v34 + v25 - v19))[v23] - v39) < (unsigned __int8)valueLevel )
                            goto LABEL_53;
                          v27 = rVal + 2;
                          goto LABEL_52;
                        }
                        if ( countOrthogonalEdgesAsConnections == 1
                          && (((unsigned __int64)v26 >> 32) ^ abs(v26) & 1) - ((unsigned __int64)v26 >> 32) == 1
                          || countDiagonalEdgesAsConnections == 1 && !((char)v26 % -2) )
                        {
                          v27 = rVal - 1;
LABEL_52:
                          rVal = v27;
                          goto LABEL_53;
                        }
                      }
LABEL_53:
                      ++v26;
                    }
                    while ( v26 < 8 );
                    v9 = v40;
                    v10 = rVal;
                    v14 = v41;
                    v17 = v42;
LABEL_55:
                    v18 = j + 4;
                    v30 = __OFSUB__((char *)&mina->x + 1, v14);
                    v28 = (int *)((char *)&mina->x + 1) == (int *)v14;
                    v29 = (signed int)&mina->x + -v14 + 1 < 0;
                    mina = (XYPoint *)((char *)mina + 1);
                    j += 4;
                  }
                  while ( (unsigned __int8)(v29 ^ v30) | v28 );
                  v15 = v37;
                  v8 = i;
LABEL_57:
                  i = ++v8;
                  if ( v8 > v15 )
                    return v10;
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

//----- (0044F030) --------------------------------------------------------
void __thiscall InfluenceMap::setUnchangeableLimit(InfluenceMap *this, char uL)
{
  if ( uL )
    this->unchangeableLimitValue = uL;
}

//----- (0044F040) --------------------------------------------------------
int __thiscall InfluenceMap::maxValue(InfluenceMap *this)
{
  int v1; // esi@1
  char *v2; // edi@1
  __int64 v3; // rax@1

  v1 = this->ySizeValue * this->xSizeValue;
  v2 = this->valueValue;
  v3 = (unsigned __int8)*v2;
  if ( v1 > 0 )
  {
    do
    {
      if ( (unsigned __int8)v2[HIDWORD(v3)] > (signed int)v3 )
        LODWORD(v3) = (unsigned __int8)v2[HIDWORD(v3)];
      ++HIDWORD(v3);
    }
    while ( SHIDWORD(v3) < v1 );
  }
  return v3;
}
