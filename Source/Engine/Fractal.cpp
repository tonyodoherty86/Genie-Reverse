
//----- (0044AB90) --------------------------------------------------------
void __thiscall PointMaker::SetDefaultValues(PointMaker *this)
{
  this->NumberOfSatellites = 2;
  this->SatelliteRadius = 2;
  this->NumSplitsPerBranch = 3;
  this->Height = 280;
  this->Width = 280;
  this->BranchRadius = 3;
  this->BranchDistance = 3;
  this->ChanceOfNextNode = 50;
  this->MaxNumberOfBranches = 6;
  this->PrimaryRadius = 4;
  this->BorderDepthPercentage = 15;
  this->MaxBranchFlag = 0;
  this->SatelliteDistance = 1;
  this->MaxNumberOfBranchLevels = 16;
  this->MinimumNumTiles = 2000;
  memset(this->Point, 0, sizeof(this->Point));
  this->DoNotDrawOnFlag = 0;
  this->DrawOnOnlyFlag = 0;
  this->DrawToOneArrayFlag = 0;
  this->DrawOnlyInExternalArrayFlag = 0;
}

//----- (0044AC50) --------------------------------------------------------
void __thiscall PointMaker::PointMaker(PointMaker *this)
{
  PointMaker *v1; // esi@1

  v1 = this;
  this->ProbArray = 0;
  this->PlacementArray = 0;
  PointMaker::SetDefaultValues(this);
  PointMaker::MakeArrays(v1);
  PointMaker::CreateMasks(v1);
}

//----- (0044AC80) --------------------------------------------------------
void __thiscall PointMaker::~PointMaker(PointMaker *this)
{
  PointMaker *v1; // esi@1

  v1 = this;
  PointMaker::DeleteArrays(this);
  PointMaker::SetDefaultValues(v1);
  v1->ProbArray = 0;
  v1->PlacementArray = 0;
  PointMaker::DeleteMasks(v1);
}

//----- (0044ACB0) --------------------------------------------------------
void __thiscall PointMaker::CreateMasks(PointMaker *this)
{
  PointMaker *v1; // ebx@1
  char *v2; // eax@1
  char *v3; // edi@1
  char *v4; // edi@1
  char ptr3[25]; // [sp+1Ch] [bp-74h]@1
  char ptr4[36]; // [sp+38h] [bp-58h]@1
  char ptr5[49]; // [sp+5Ch] [bp-34h]@1

  v1 = this;
  this->Mask_2x2 = (char *)operator new(0x10u);
  v1->Mask_3x3 = (char *)operator new(0x19u);
  v1->Mask_4x4 = (char *)operator new(0x24u);
  v1->Mask_5x5 = (char *)operator new(0x31u);
  ptr3[0] = 0;
  ptr3[1] = 0;
  ptr3[2] = 0;
  ptr3[3] = 0;
  ptr3[4] = 0;
  ptr3[5] = 0;
  ptr3[6] = 1;
  ptr3[7] = 1;
  ptr3[8] = 1;
  ptr3[9] = 0;
  ptr3[10] = 0;
  ptr3[11] = 1;
  ptr3[12] = 2;
  ptr3[13] = 1;
  ptr3[14] = 0;
  ptr3[15] = 0;
  ptr3[16] = 1;
  ptr3[17] = 1;
  ptr3[18] = 1;
  ptr3[19] = 0;
  ptr3[20] = 0;
  ptr3[21] = 0;
  ptr3[22] = 0;
  ptr3[23] = 0;
  ptr3[24] = 0;
  ptr4[0] = 0;
  ptr4[1] = 0;
  ptr4[2] = 0;
  ptr4[3] = 0;
  ptr4[4] = 0;
  ptr4[5] = 0;
  ptr4[6] = 0;
  ptr4[7] = 1;
  ptr4[8] = 1;
  ptr4[9] = 1;
  ptr4[10] = 1;
  ptr4[11] = 0;
  ptr4[12] = 0;
  ptr4[13] = 1;
  ptr4[14] = 2;
  ptr4[15] = 2;
  ptr4[16] = 1;
  ptr4[17] = 0;
  ptr4[18] = 0;
  ptr4[23] = 0;
  ptr4[24] = 0;
  ptr4[29] = 0;
  ptr4[30] = 0;
  ptr4[31] = 0;
  ptr4[32] = 0;
  ptr4[33] = 0;
  ptr4[34] = 0;
  ptr4[35] = 0;
  ptr5[0] = 0;
  ptr5[1] = 0;
  ptr5[2] = 0;
  ptr5[3] = 0;
  ptr5[4] = 0;
  ptr5[5] = 0;
  ptr5[6] = 0;
  ptr5[7] = 0;
  ptr5[13] = 0;
  ptr5[14] = 0;
  ptr5[20] = 0;
  ptr5[21] = 0;
  ptr5[27] = 0;
  ptr5[28] = 0;
  ptr5[34] = 0;
  ptr5[35] = 0;
  ptr5[41] = 0;
  ptr5[42] = 0;
  ptr5[43] = 0;
  ptr5[44] = 0;
  ptr5[45] = 0;
  ptr5[46] = 0;
  ptr5[47] = 0;
  ptr5[48] = 0;
  v2 = v1->Mask_2x2;
  ptr4[19] = 1;
  ptr4[22] = 1;
  ptr4[25] = 1;
  ptr4[26] = 1;
  ptr4[27] = 1;
  ptr4[28] = 1;
  ptr5[8] = 1;
  ptr5[9] = 1;
  ptr5[10] = 1;
  ptr5[11] = 1;
  ptr5[12] = 1;
  ptr5[15] = 1;
  ptr5[19] = 1;
  ptr5[22] = 1;
  ptr5[26] = 1;
  ptr5[29] = 1;
  ptr5[33] = 1;
  ptr5[36] = 1;
  ptr5[37] = 1;
  ptr5[38] = 1;
  ptr5[39] = 1;
  ptr5[40] = 1;
  ptr4[20] = 2;
  ptr4[21] = 2;
  ptr5[16] = 2;
  ptr5[17] = 2;
  ptr5[18] = 2;
  ptr5[23] = 2;
  ptr5[25] = 2;
  ptr5[30] = 2;
  ptr5[31] = 2;
  ptr5[32] = 2;
  *(_DWORD *)v2 = 0;
  ptr5[24] = 3;
  *((_DWORD *)v2 + 1) = 65792;
  *((_DWORD *)v2 + 2) = 65792;
  *((_DWORD *)v2 + 3) = 0;
  v3 = v1->Mask_3x3;
  qmemcpy(v3, ptr3, 0x18u);
  v3[24] = ptr3[24];
  qmemcpy(v1->Mask_4x4, ptr4, 0x24u);
  v4 = v1->Mask_5x5;
  qmemcpy(v4, ptr5, 0x30u);
  v4[48] = ptr5[48];
}

//----- (0044AF90) --------------------------------------------------------
void __thiscall PointMaker::DeleteMasks(PointMaker *this)
{
  PointMaker *v1; // esi@1

  v1 = this;
  operator delete(this->Mask_2x2);
  operator delete(v1->Mask_3x3);
  operator delete(v1->Mask_4x4);
  operator delete(v1->Mask_5x5);
}

//----- (0044AFE0) --------------------------------------------------------
void __thiscall PointMaker::DrawMask(PointMaker *this, int x, int y, int size)
{
  int v4; // edx@1
  PointMaker *v5; // edi@1
  int v6; // ebp@1
  int v7; // esi@2
  int v8; // eax@2
  int v9; // ebx@19
  int v10; // ebx@21
  int v11; // ecx@24
  int v12; // esi@25
  int v13; // esi@27
  int v14; // ebx@32
  int v15; // ecx@34
  int v16; // esi@37
  int v17; // eax@40
  int v18; // edx@40
  int v19; // esi@40
  int v20; // esi@43
  int v21; // ecx@43
  int v22; // ebx@45
  char *v23; // ecx@47
  char v24; // dl@47
  char *v25; // eax@47
  bool v26; // zf@54
  int mapptr; // [sp+10h] [bp-10h]@40
  int v28; // [sp+14h] [bp-Ch]@41
  int i; // [sp+18h] [bp-8h]@43
  int len; // [sp+1Ch] [bp-4h]@5
  char *xa; // [sp+24h] [bp+4h]@18
  char *maskptr; // [sp+28h] [bp+8h]@19
  int w; // [sp+2Ch] [bp+Ch]@43

  v4 = x;
  v5 = this;
  v6 = this->Width;
  if ( x <= v6 )
  {
    v7 = this->Height;
    v8 = y;
    if ( y <= v7 && size + x + 2 >= 0 && size + y + 2 >= 0 )
    {
      len = size + 2;
      if ( size == 2 )
      {
        if ( x + 4 <= v6 && x < 0 )
          v4 = 0;
        if ( y + 4 <= v7 && y < 0 )
          v8 = 0;
      }
      else if ( size == 3 )
      {
        if ( x + 5 <= v6 && x < 0 )
          v4 = 0;
        v8 = (v7 < 5) + y;
      }
      if ( size == 4 )
      {
        xa = this->Mask_4x4;
        if ( v4 + 6 <= v6 )
        {
          if ( v4 >= 0 )
          {
            maskptr = (char *)6;
          }
          else
          {
            maskptr = (char *)(v4 + 6);
            v10 = (int)&xa[-v4];
            v4 = 0;
            xa = (char *)v10;
          }
          v9 = (int)maskptr;
        }
        else
        {
          v9 = v6 - v4;
          maskptr = (char *)(v6 - v4);
        }
        v11 = v8 + 6;
        if ( v8 + 6 <= v7 )
        {
          if ( v8 >= 0 )
          {
            v12 = 6;
          }
          else
          {
            v13 = (int)&xa[-(v6 * v8)];
            v8 = 0;
            xa = (char *)v13;
            v12 = v11;
          }
        }
        else
        {
          v12 = v7 - v8;
        }
      }
      else
      {
        xa = this->Mask_5x5;
        if ( v4 + 7 <= v6 )
        {
          if ( v4 >= 0 )
          {
            maskptr = (char *)7;
          }
          else
          {
            maskptr = (char *)(v4 + 7);
            v14 = (int)&xa[-v4];
            v4 = 0;
            xa = (char *)v14;
          }
        }
        else
        {
          maskptr = (char *)(v6 - v4);
        }
        v15 = v8 + 7;
        if ( v8 + 7 <= v7 )
        {
          if ( v8 >= 0 )
          {
            v12 = 7;
          }
          else
          {
            v16 = (int)&xa[-(v6 * v8)];
            v8 = 0;
            xa = (char *)v16;
            v12 = v15;
          }
        }
        else
        {
          v12 = v7 - v8;
        }
        v9 = (int)maskptr;
      }
      v17 = v4 + v6 * v8;
      v18 = v12;
      v19 = v12 - 1;
      mapptr = v17;
      if ( v18 )
      {
        v28 = v19 + 1;
        do
        {
          if ( v9 > 0 )
          {
            v20 = v17;
            v21 = (int)&xa[-v17];
            w = v9;
            for ( i = (int)&xa[-v17]; ; v21 = i )
            {
              v22 = *(_BYTE *)(v21 + v20);
              if ( v20 >= 1 && v20 < v5->SizeArrays - 1 )
              {
                v23 = v5->ProbArray;
                v24 = v23[v20];
                v25 = &v23[v20];
                if ( v24 )
                {
                  if ( v24 + v22 >= 255 )
                    *v25 = -1;
                  else
                    *v25 = v24 + v22;
                }
                else
                {
                  *v25 = v22;
                  ++v5->ProbabilityTiles;
                }
              }
              ++v20;
              if ( !--w )
                break;
            }
            v9 = (int)maskptr;
            v17 = mapptr;
          }
          xa += len;
          v17 += v5->Width;
          v26 = v28 == 1;
          mapptr = v17;
          --v28;
        }
        while ( !v26 );
      }
    }
  }
}

//----- (0044B210) --------------------------------------------------------
void __thiscall PointMaker::ClearArrays(PointMaker *this)
{
  char *v1; // edi@2
  char *v2; // edi@4

  if ( !this->DrawToOneArrayFlag )
  {
    v1 = this->PlacementArray;
    if ( v1 )
      memset(v1, 0, this->SizeArrays);
  }
  v2 = this->ProbArray;
  if ( v2 )
    memset(v2, 0, this->SizeArrays);
}

//----- (0044B270) --------------------------------------------------------
void __thiscall PointMaker::DeleteArrays(PointMaker *this)
{
  PointMaker *v1; // esi@1

  v1 = this;
  if ( this->ProbArray )
    operator delete(this->ProbArray);
  if ( v1->PlacementArray )
    operator delete(v1->PlacementArray);
  v1->ProbArray = 0;
  v1->PlacementArray = 0;
}

//----- (0044B2B0) --------------------------------------------------------
void __thiscall PointMaker::MakeArrays(PointMaker *this)
{
  PointMaker *v1; // esi@1
  signed int v2; // edi@1
  char *v3; // eax@3
  signed int v4; // edx@3
  signed int v5; // edi@4
  char *v6; // eax@6
  signed int v7; // ecx@6

  v1 = this;
  v2 = 9;
  this->SizeArrays = this->Width * this->Height;
  do
  {
    if ( v1->ProbArray )
      break;
    v3 = (char *)operator new(v1->SizeArrays);
    v4 = v2--;
    v1->ProbArray = v3;
  }
  while ( v4 );
  v5 = 9;
  do
  {
    if ( v1->PlacementArray )
      break;
    v6 = (char *)operator new(v1->SizeArrays);
    v7 = v5--;
    v1->PlacementArray = v6;
  }
  while ( v7 );
}

//----- (0044B320) --------------------------------------------------------
int __thiscall PointMaker::CreateShape(PointMaker *this)
{
  PointMaker *v1; // esi@1
  int v2; // edi@1
  int v3; // edx@1
  int v4; // edi@1
  signed int v5; // eax@1
  int v6; // ecx@1
  unsigned int v7; // ecx@1
  int v8; // edx@1
  int v9; // edi@1
  int v10; // eax@1
  signed int v11; // ebp@1
  signed int v12; // edx@2
  int v13; // eax@3
  int v14; // edx@3
  int v15; // eax@3

  v1 = this;
  this->NumNodes = 0;
  PointMaker::ClearArrays(this);
  PointMaker::PrepareLimits(v1);
  v2 = v1->LeftLimit;
  v3 = v2 + debug_rand(aCMsdevWorkA_34, 215) % (2 * (50 - v2) * v1->Width / 100);
  v4 = v1->TopLimit;
  v1->x = v3;
  v5 = debug_rand(aCMsdevWorkA_34, 216);
  v6 = v1->Height;
  v1->ProbabilityTiles = 0;
  v1->NumNodes = 0;
  v7 = (signed int)((unsigned __int64)(2748779070i64 * (50 - v4) * v6) >> 32) >> 5;
  v8 = v5 % (signed int)((v7 >> 31) + v7);
  v1->Prime.x = v1->x;
  v1->y = v8 + v4;
  v1->Prime.y = v8 + v4;
  PointMaker::DrawPrimaryIntoProbabilityArray(v1);
  PointMaker::ErrorCheckingAndCorrection(v1);
  v9 = v1->MinimumNumTiles;
  v10 = v1->ProbabilityTiles;
  v11 = 0;
  v1->NumTilesActuallyChosen = 0;
  if ( v10 < v9 )
  {
    do
    {
      v12 = v11++;
      if ( v12 >= 1500 )
        break;
      v13 = v1->Prime.x;
      v14 = v1->MaxNumberOfBranchLevels;
      v1->y = v1->Prime.y;
      v1->x = v13;
      v1->CurrentNumberOfBranchLevels = v14;
      v1->NumNodes = 0;
      v15 = PointMaker::MakeFirstLink(v1);
      PointMaker::Branch(v1, v15);
    }
    while ( v1->ProbabilityTiles < v9 );
  }
  PointMaker::CreateMapBasedOnProbabilityArray(v1);
  PointMaker::MapCleanUpEliminatingSinglesOnly(v1);
  return v1->ProbabilityTiles;
}

//----- (0044B470) --------------------------------------------------------
int __thiscall PointMaker::CreateShape(PointMaker *this, int xt, int yt)
{
  PointMaker *v3; // esi@1
  int v4; // edi@1
  int v5; // eax@1
  signed int v6; // ebp@1
  signed int v7; // eax@2
  int v8; // edx@3
  int v9; // eax@3
  int v10; // eax@3

  v3 = this;
  this->NumNodes = 0;
  PointMaker::ClearArrays(this);
  PointMaker::PrepareLimits(v3);
  v3->y = yt;
  v3->Prime.y = yt;
  v3->ProbabilityTiles = 0;
  v3->NumNodes = 0;
  v3->x = xt;
  v3->Prime.x = xt;
  PointMaker::DrawPrimaryIntoProbabilityArray(v3);
  PointMaker::ErrorCheckingAndCorrection(v3);
  v4 = v3->MinimumNumTiles;
  v5 = v3->ProbabilityTiles;
  v6 = 0;
  v3->NumTilesActuallyChosen = 0;
  if ( v5 < v4 )
  {
    do
    {
      v7 = v6++;
      if ( v7 >= 1500 )
        break;
      v8 = v3->Prime.y;
      v9 = v3->MaxNumberOfBranchLevels;
      v3->x = v3->Prime.x;
      v3->y = v8;
      v3->CurrentNumberOfBranchLevels = v9;
      v3->NumNodes = 0;
      v10 = PointMaker::MakeFirstLink(v3);
      PointMaker::Branch(v3, v10);
    }
    while ( v3->ProbabilityTiles < v4 );
  }
  PointMaker::CreateMapBasedOnProbabilityArray(v3);
  PointMaker::MapCleanUpEliminatingSinglesOnly(v3);
  return v3->ProbabilityTiles;
}

//----- (0044B540) --------------------------------------------------------
void __thiscall PointMaker::Branch(PointMaker *this, const int which)
{
  PointMaker *v2; // esi@1
  int v3; // eax@4
  int v4; // ebx@4
  int v5; // edi@5
  int i; // edi@6
  int v7; // eax@7

  v2 = this;
  if ( this->CurrentNumberOfBranchLevels > 1
    && debug_rand(aCMsdevWorkA_34, 278) % 100 < 10 * this->ChanceOfNextNode
    && v2->ProbabilityTiles < 2 * v2->MinimumNumTiles )
  {
    v3 = v2->NumSplitsPerBranch;
    v4 = 0;
    --v2->CurrentNumberOfBranchLevels;
    if ( v3 > 0 )
    {
      do
      {
        v2->x = v2->Point[which].x;
        v2->y = v2->Point[which].y;
        v5 = PointMaker::MakeNewLink(v2);
        PointMaker::DrawCurrentBranchIntoProbArray(v2, v5);
        PointMaker::Branch(v2, v5);
        ++v4;
      }
      while ( v4 < v2->NumSplitsPerBranch );
    }
  }
  for ( i = 0; i < v2->NumberOfSatellites; ++i )
  {
    v7 = PointMaker::MakeSatelliteLink(v2);
    PointMaker::DrawCurrentSatelliteIntoProbArray(v2, v7);
  }
}

//----- (0044B610) --------------------------------------------------------
int __thiscall PointMaker::MakeFirstLink(PointMaker *this)
{
  PointMaker *v1; // esi@1
  int v2; // edi@1
  int v3; // ebx@3
  int v4; // ecx@5
  int v5; // edx@5
  int v6; // eax@5
  int v7; // ecx@5
  int v8; // edx@5
  int v9; // edx@11
  int v10; // edx@12
  int v11; // edx@14
  int v12; // edx@15
  int v13; // ecx@17
  int result; // eax@17

  v1 = this;
  v2 = debug_rand(aCMsdevWorkA_34, 308) % this->BranchDistance + 2;
  if ( (char)debug_rand(aCMsdevWorkA_34, 308) % -2 )
    v2 = -v2;
  v3 = debug_rand(aCMsdevWorkA_34, 309) % v1->BranchDistance + 2;
  if ( (char)debug_rand(aCMsdevWorkA_34, 309) % -2 )
    v3 = -v3;
  v4 = v1->x;
  v5 = v1->y;
  v1->DirX = v2;
  v6 = v4 + v2;
  v7 = v5 + v3;
  v8 = v1->LeftLimit;
  v1->DirY = v3;
  if ( v6 < v8 )
  {
    v6 = v8;
    if ( v2 < 0 )
      v1->DirX = -v2;
  }
  if ( v7 < v1->TopLimit )
  {
    v7 = v1->TopLimit;
    if ( v3 < 0 )
      v1->DirY = -v3;
  }
  v9 = v1->RightLimit;
  if ( v6 >= v9 )
  {
    v6 = v9 - 1;
    v10 = v1->DirX;
    if ( v10 > 0 )
      v1->DirX = -v10;
  }
  v11 = v1->BottomLimit;
  if ( v7 >= v11 )
  {
    v7 = v11 - 1;
    v12 = v1->DirY;
    if ( v12 > 0 )
      v1->DirY = -v12;
  }
  v1->y = v7;
  v13 = v1->NumNodes;
  v1->x = v6;
  v1->Point[v13].x = v6;
  v1->Point[v1->NumNodes].y = v1->y;
  result = v1->NumNodes;
  v1->NumNodes = result + 1;
  return result;
}

//----- (0044B760) --------------------------------------------------------
int __thiscall PointMaker::MakeNewLink(PointMaker *this)
{
  PointMaker *v1; // esi@1
  int v2; // ebx@1
  int v3; // edi@3
  int v4; // eax@5
  int v5; // edx@5
  int v6; // ecx@5
  int v7; // ebx@5
  int v8; // edi@5
  int v9; // eax@9
  int v10; // ecx@11
  int v11; // ebx@13
  int v12; // edi@13
  int v13; // edx@25
  int result; // eax@25
  int v15; // [sp+10h] [bp-4h]@7

  v1 = this;
  v2 = debug_rand(aCMsdevWorkA_34, 330) % this->BranchDistance + 1;
  if ( (char)debug_rand(aCMsdevWorkA_34, 330) % -2 )
    v2 = -v2;
  v3 = debug_rand(aCMsdevWorkA_34, 331) % v1->BranchDistance + 1;
  if ( (char)debug_rand(aCMsdevWorkA_34, 331) % -2 )
    v3 = -v3;
  v4 = v1->DirX;
  v5 = v1->x;
  v6 = v1->DirY;
  v7 = v4 + v2;
  v8 = v6 + v3;
  if ( v7 + v5 < 5 )
  {
    v7 = -v7;
    v1->DirX = -v4;
  }
  v15 = v1->Width - 5;
  if ( v7 + v5 >= v15 )
  {
    v7 = -v7;
    v1->DirX = -v1->DirX;
  }
  v9 = v1->y;
  if ( v8 + v9 < 5 )
  {
    v8 = -v7;
    v1->DirY = -v6;
  }
  v10 = v1->Height - 5;
  if ( v8 + v9 >= v10 )
    v8 = -v8;
  v11 = v5 + v7;
  v12 = v9 + v8;
  if ( v11 < 5 )
    v11 = 5;
  if ( v11 >= v15 )
    v11 = v15;
  if ( v12 < 5 )
    v12 = 5;
  if ( v12 >= v10 )
    v12 = v1->Height - 5;
  if ( (char)debug_rand(aCMsdevWorkA_34, 346) % -2 )
    v1->DirX += debug_rand(aCMsdevWorkA_34, 346) % 3 - 1;
  if ( (char)debug_rand(aCMsdevWorkA_34, 347) % -2 )
    v1->DirY += debug_rand(aCMsdevWorkA_34, 347) % 3 - 1;
  v13 = v1->NumNodes;
  v1->x = v11;
  v1->y = v12;
  v1->Point[v13].x = v11;
  v1->Point[v1->NumNodes].y = v1->y;
  result = v1->NumNodes;
  v1->NumNodes = result + 1;
  return result;
}

//----- (0044B950) --------------------------------------------------------
int __thiscall PointMaker::MakeSatelliteLink(PointMaker *this)
{
  PointMaker *v1; // esi@1
  int v2; // ebx@1
  int v3; // edi@3
  int v4; // eax@5
  int v5; // ecx@5
  int v6; // ebx@5
  int v7; // edi@5
  int v8; // eax@9
  int v9; // edx@13
  int v10; // ecx@13
  int result; // eax@13

  v1 = this;
  v2 = debug_rand(aCMsdevWorkA_34, 357) % this->SatelliteDistance + 1;
  if ( (char)debug_rand(aCMsdevWorkA_34, 357) % -2 )
    v2 = -v2;
  v3 = debug_rand(aCMsdevWorkA_34, 358) % v1->SatelliteDistance + 1;
  if ( (char)debug_rand(aCMsdevWorkA_34, 358) % -2 )
    v3 = -v3;
  v4 = v1->DirX;
  v5 = v1->DirY;
  v6 = v4 + v2;
  v7 = v5 + v3;
  if ( v1->x + v6 < 3 )
  {
    v6 = -v6;
    v1->DirX = -v4;
  }
  if ( v1->x + v6 >= v1->Width - 3 )
  {
    v6 = -v6;
    v1->DirX = -v1->DirX;
  }
  v8 = v1->y;
  if ( v7 + v8 < 3 )
  {
    v7 = -v6;
    v1->DirY = -v5;
  }
  if ( v7 + v8 >= v1->Height - 3 )
  {
    v7 = -v7;
    v1->DirY = -v1->DirY;
  }
  v9 = v1->NumNodes;
  v10 = v6 + v1->x;
  v1->x = v10;
  v1->y = v8 + v7;
  v1->Point[v9].x = v10;
  v1->Point[v1->NumNodes].y = v1->y;
  result = v1->NumNodes;
  v1->NumNodes = result + 1;
  return result;
}

//----- (0044BAA0) --------------------------------------------------------
void __thiscall PointMaker::DrawPrimaryIntoProbabilityArray(PointMaker *this)
{
  PointMaker *v1; // esi@1
  int v2; // edx@1
  int v3; // eax@1
  int v4; // ecx@1
  int v5; // edi@1
  int v6; // ebx@1
  int v7; // eax@1
  int v8; // ebp@1
  int v9; // edx@12
  int y1; // ST2C_4@12
  int x2; // ST28_4@12
  int v12; // ecx@12
  int desty; // [sp+10h] [bp-10h]@12
  int i; // [sp+14h] [bp-Ch]@9

  v1 = this;
  v2 = this->Prime.x;
  v3 = this->Prime.y;
  v4 = this->PrimaryRadius;
  v5 = v2 - v4;
  v6 = v3 - v4;
  v7 = v4 + v3;
  v8 = v4 + v2;
  if ( v2 - v4 < 0 )
    v5 = 0;
  if ( v6 < 0 )
    v6 = 0;
  if ( v8 > v1->Width - 1 )
    v8 = v1->Width - 1;
  if ( v7 > v1->Height - 1 )
    v7 = v1->Height - 1;
  v1->ProbabilityAdd = 1;
  i = 0;
  if ( v4 > 0 )
  {
    while ( 1 )
    {
      v9 = v5;
      y1 = v6;
      ++v5;
      x2 = v8;
      ++v6;
      --v8;
      desty = v7 - 1;
      PointMaker::AddingRect(v1, v9, y1, x2, v7);
      v12 = v1->PrimaryRadius;
      ++v1->ProbabilityAdd;
      if ( ++i >= v12 )
        break;
      v7 = desty;
    }
  }
}

//----- (0044BB60) --------------------------------------------------------
void __thiscall PointMaker::DrawCurrentBranchIntoProbArray(PointMaker *this, int which)
{
  PointMaker *v2; // esi@1
  int v3; // ecx@1
  int v4; // eax@1
  int v5; // ebp@1
  int v6; // edi@1
  int v7; // ebx@1
  int v8; // edx@1
  int v9; // ecx@9
  int v10; // ecx@11
  int v11; // ecx@20
  int v12; // ecx@21
  int v13; // eax@21
  char *v14; // eax@23
  char v15; // dl@23
  int desty; // [sp+10h] [bp-8h]@1
  int i; // [sp+14h] [bp-4h]@13

  v2 = this;
  v3 = this->Point[which].x;
  v4 = v2->BranchRadius;
  v5 = v4 + v3;
  v6 = v3 - v4;
  v7 = v2->Point[which].y - v4;
  v8 = v4 + v2->Point[which].y;
  desty = v4 + v2->Point[which].y;
  if ( v4 + v3 >= 0 && v8 >= 0 && v6 < v2->Width && v7 < v2->Height )
  {
    if ( v6 < 0 )
      v6 = 0;
    if ( v7 < 0 )
      v7 = 0;
    v9 = v2->Width;
    if ( v5 >= v9 )
      v5 = v9 - 1;
    v10 = v2->Height;
    if ( v8 >= v10 )
    {
      desty = v10 - 1;
      v8 = v10 - 1;
    }
    v2->ProbabilityAdd = 1;
    i = 0;
    if ( v4 > 0 )
    {
      while ( 1 )
      {
        PointMaker::AddingRect(v2, v6, v7, v5, v8);
        if ( ++v6 >= v2->Width )
          break;
        if ( ++v7 >= v2->Height )
          break;
        if ( --v5 < 0 )
          break;
        if ( --desty < 0 )
          break;
        v11 = v2->BranchRadius;
        ++v2->ProbabilityAdd;
        if ( ++i >= v11 )
          break;
        v8 = desty;
      }
    }
    v12 = v2->ProbabilityAdd;
    v13 = v2->Point[which].x + v2->Point[which].y * v2->Width;
    if ( v13 >= 1 && v13 < v2->SizeArrays - 1 )
    {
      v14 = &v2->ProbArray[v13];
      v15 = *v14;
      if ( *v14 )
      {
        if ( v15 + v12 >= 255 )
          *v14 = -1;
        else
          *v14 = v15 + v12;
      }
      else
      {
        *v14 = v12;
        ++v2->ProbabilityTiles;
      }
    }
  }
}

//----- (0044BCD0) --------------------------------------------------------
void __thiscall PointMaker::DrawCurrentSatelliteIntoProbArray(PointMaker *this, int which)
{
  PointMaker *v2; // esi@1
  int v3; // edi@1
  int v4; // eax@3
  int v5; // edx@3
  char *v6; // eax@5
  char v7; // cl@5

  v2 = this;
  v3 = this->SatelliteRadius;
  for ( this->ProbabilityAdd = 2; v3 >= 0; ++v2->ProbabilityAdd )
    PointMaker::AddingCircle(v2, v2->Point[which].x, v2->Point[which].y, v3--);
  v4 = v2->Point[which].x + v2->Width * v2->Point[which].y;
  v5 = v2->ProbabilityAdd;
  if ( v4 >= 1 && v4 < v2->SizeArrays - 1 )
  {
    v6 = &v2->ProbArray[v4];
    v7 = *v6;
    if ( *v6 )
    {
      if ( v7 + v5 >= 255 )
        *v6 = -1;
      else
        *v6 = v7 + v5;
    }
    else
    {
      *v6 = v5;
      ++v2->ProbabilityTiles;
    }
  }
}

//----- (0044BD80) --------------------------------------------------------
void __thiscall PointMaker::AddingRect(PointMaker *this, int x1, int y1, int x2, int y2)
{
  int v5; // edx@1
  int v6; // ebx@1
  int v7; // ebp@1
  int v8; // eax@1
  int v9; // esi@1
  int v10; // edi@1
  int v11; // eax@3
  int v12; // edx@5
  char *v13; // esi@7
  char v14; // al@7
  int v15; // edx@13
  char *v16; // eax@15
  char *v17; // esi@15
  char v18; // al@15
  bool v19; // zf@21
  int v20; // ebx@23
  int v21; // edx@26
  char *v22; // eax@28
  char *v23; // esi@28
  char v24; // al@28
  int v25; // eax@33
  int v26; // edx@33
  char *v27; // esi@35
  char v28; // al@35
  int w; // [sp+10h] [bp-4h]@1
  int x1a; // [sp+18h] [bp+4h]@3
  int top; // [sp+1Ch] [bp+8h]@1
  int topa; // [sp+1Ch] [bp+8h]@25
  int start; // [sp+20h] [bp+Ch]@4
  int y2a; // [sp+24h] [bp+10h]@1

  v5 = this->Width;
  v6 = x1 + v5 * y1;
  v7 = x2 - x1;
  v8 = y2 - y1;
  top = v6;
  w = x2 - x1;
  v9 = v8 - 1;
  y2a = v8 - 1;
  v10 = v6 + v5 * (v8 - 1);
  if ( x2 - x1 >= 0 && v8 >= 0 )
  {
    v11 = v6;
    x1a = v6;
    if ( v7 >= 0 )
    {
      start = v7 + 1;
      do
      {
        v12 = this->ProbabilityAdd;
        if ( v11 >= 1 && v11 < this->SizeArrays - 1 )
        {
          v13 = &this->ProbArray[v11];
          v14 = *v13;
          if ( *v13 )
          {
            if ( v14 + v12 >= 255 )
              *v13 = -1;
            else
              *v13 = v14 + v12;
            v6 = top;
          }
          else
          {
            *v13 = v12;
            ++this->ProbabilityTiles;
          }
        }
        v15 = this->ProbabilityAdd;
        if ( v10 >= 1 && v10 < this->SizeArrays - 1 )
        {
          v16 = this->ProbArray;
          v17 = &v16[v10];
          v18 = v16[v10];
          if ( v18 )
          {
            if ( v18 + v15 >= 255 )
              *v17 = -1;
            else
              *v17 = v18 + v15;
            v6 = top;
          }
          else
          {
            *v17 = v15;
            ++this->ProbabilityTiles;
          }
        }
        ++v10;
        v11 = x1a + 1;
        v19 = start == 1;
        ++x1a;
        --start;
      }
      while ( !v19 );
      v9 = y2a;
    }
    v20 = this->Width + v6;
    if ( v9 >= 0 && v9 )
    {
      topa = v9;
      do
      {
        v21 = this->ProbabilityAdd;
        if ( v20 >= 1 && v20 < this->SizeArrays - 1 )
        {
          v22 = this->ProbArray;
          v23 = &v22[v20];
          v24 = v22[v20];
          if ( v24 )
          {
            if ( v24 + v21 >= 255 )
              *v23 = -1;
            else
              *v23 = v24 + v21;
          }
          else
          {
            *v23 = v21;
            ++this->ProbabilityTiles;
          }
        }
        v25 = w + v20;
        v26 = this->ProbabilityAdd;
        if ( w + v20 >= 1 && v25 < this->SizeArrays - 1 )
        {
          v27 = &this->ProbArray[v25];
          v28 = *v27;
          if ( *v27 )
          {
            if ( v28 + v26 >= 255 )
              *v27 = -1;
            else
              *v27 = v28 + v26;
          }
          else
          {
            *v27 = v26;
            ++this->ProbabilityTiles;
          }
        }
        v20 += this->Width;
        --topa;
      }
      while ( topa );
    }
  }
}

//----- (0044BF90) --------------------------------------------------------
void __thiscall PointMaker::AddingCircle(PointMaker *this, int x1, int y1, int radius)
{
  int v4; // eax@1
  PointMaker *v5; // esi@1
  int v6; // edi@3
  double v8; // st7@4
  char v9; // c3@4
  signed __int64 v10; // rax@6
  char v11; // cl@8
  float v12; // ST28_4@14
  float x; // ST2C_4@14
  float v14; // ST18_4@14
  signed __int64 v15; // rax@14
  int v16; // ecx@14
  char *v17; // eax@16
  char v18; // dl@16
  float curx; // [sp+10h] [bp-1Ch]@4
  float lasty; // [sp+18h] [bp-14h]@3
  float W; // [sp+1Ch] [bp-10h]@3
  int step; // [sp+28h] [bp-4h]@3
  int radiusa; // [sp+38h] [bp+Ch]@3

  v4 = radius;
  v5 = this;
  if ( !radius )
  {
    v4 = 1;
    radius = 1;
  }
  W = (double)this->Width;
  *(float *)&radiusa = (double)radius;
  lasty = 0.0;
  v6 = 0;
  step = 360 / (3 * v4);
  do
  {
    curx = TRIGONOMETRY::sin360(&trig, v6) * *(float *)&radiusa;
    v8 = TRIGONOMETRY::cos360(&trig, v6) * *(float *)&radiusa;
    if ( !v9 || v8 != lasty )
    {
      v10 = (signed __int64)(W * v8 + curx);
      HIDWORD(v10) = v5->ProbabilityAdd;
      if ( (signed int)v10 >= 1 && (signed int)v10 < v5->SizeArrays - 1 )
      {
        LODWORD(v10) = &v5->ProbArray[v10];
        v11 = *(_BYTE *)v10;
        if ( *(_BYTE *)v10 )
        {
          if ( (signed int)v11 + HIDWORD(v10) >= 255 )
            *(_BYTE *)v10 = -1;
          else
            *(_BYTE *)v10 = v11 + BYTE4(v10);
        }
        else
        {
          *(_BYTE *)v10 = BYTE4(v10);
          ++v5->ProbabilityTiles;
        }
      }
      lasty = v8;
      if ( (char)debug_rand(aCMsdevWorkA_34, 497) % -2 )
      {
        v12 = TRIGONOMETRY::sin360(&trig, v6) * *(float *)&radiusa;
        x = (double)(unsigned __int8)((char)debug_rand(aCMsdevWorkA_34, 499) % -2) + v12 - -1.0;
        v14 = TRIGONOMETRY::cos360(&trig, v6) * *(float *)&radiusa;
        v15 = (signed __int64)(((double)(unsigned __int8)((char)debug_rand(aCMsdevWorkA_34, 500) % -2) + v14 - -1.0) * W
                             + x);
        v16 = v5->ProbabilityAdd + 1;
        if ( (signed int)v15 >= 1 && (signed int)v15 < v5->SizeArrays - 1 )
        {
          v17 = &v5->ProbArray[v15];
          v18 = *v17;
          if ( *v17 )
          {
            if ( v18 + v16 >= 255 )
              *v17 = -1;
            else
              *v17 = v18 + v16;
          }
          else
          {
            *v17 = v16;
            ++v5->ProbabilityTiles;
          }
        }
      }
    }
    v6 += step;
  }
  while ( v6 < 360 );
}

//----- (0044C1B0) --------------------------------------------------------
void __thiscall PointMaker::CreateMapBasedOnProbabilityArray(PointMaker *this)
{
  int v1; // edx@1
  int i; // eax@1

  v1 = 0;
  for ( i = 0; i < this->SizeArrays; ++i )
  {
    if ( this->ProbArray[i] )
    {
      ++v1;
      this->PlacementArray[i] = 1;
    }
  }
  this->NumTilesActuallyChosen += v1;
}

//----- (0044C200) --------------------------------------------------------
void __thiscall PointMaker::SetPoint(PointMaker *this, int x1, int y1)
{
  this->x = x1;
  this->y = y1;
}

//----- (0044C220) --------------------------------------------------------
void __thiscall PointMaker::SetMaxNumberOfBranches(PointMaker *this, int num)
{
  this->MaxNumberOfBranches = num;
}

//----- (0044C230) --------------------------------------------------------
void __thiscall PointMaker::SetChanceOfNextNode(PointMaker *this, int num)
{
  this->ChanceOfNextNode = num;
}

//----- (0044C240) --------------------------------------------------------
void __thiscall PointMaker::SetNumberOfSatellites(PointMaker *this, int num)
{
  this->NumberOfSatellites = num;
}

//----- (0044C250) --------------------------------------------------------
void __thiscall PointMaker::SetSplitsPerBranch(PointMaker *this, int num)
{
  this->NumSplitsPerBranch = num;
}

//----- (0044C260) --------------------------------------------------------
void __thiscall PointMaker::SetWidthAndHeight(PointMaker *this, int w, int h)
{
  this->Width = w;
  this->Height = h;
}

//----- (0044C280) --------------------------------------------------------
void __thiscall PointMaker::SetStartPositionRadius(PointMaker *this, int num)
{
  this->PrimaryRadius = num;
}

//----- (0044C290) --------------------------------------------------------
void __thiscall PointMaker::SetBranchsRadius(PointMaker *this, int num)
{
  this->BranchRadius = num;
}

//----- (0044C2A0) --------------------------------------------------------
void __thiscall PointMaker::SetSatelliteRadius(PointMaker *this, int num)
{
  this->SatelliteRadius = num;
}

//----- (0044C2B0) --------------------------------------------------------
void __thiscall PointMaker::SetMaxNumberOfBranchLevels(PointMaker *this, int num)
{
  this->MaxBranchFlag = 1;
  this->MaxNumberOfBranchLevels = num;
}

//----- (0044C2D0) --------------------------------------------------------
void __thiscall PointMaker::SetSatelliteDistance(PointMaker *this, int num)
{
  this->SatelliteDistance = num;
}

//----- (0044C2E0) --------------------------------------------------------
void __thiscall PointMaker::SetBranchDistance(PointMaker *this, int num)
{
  this->BranchDistance = num;
}

//----- (0044C2F0) --------------------------------------------------------
void __thiscall PointMaker::SetMinimumNumberOfTiles(PointMaker *this, int num)
{
  this->MinimumNumTiles = num;
}

//----- (0044C300) --------------------------------------------------------
void __thiscall PointMaker::SetDrawToOneArray(PointMaker *this)
{
  this->DrawToOneArrayFlag = 1;
}

//----- (0044C310) --------------------------------------------------------
void __thiscall PointMaker::SetBorderDepthPercentage(PointMaker *this, int num)
{
  this->BorderDepthPercentage = num;
  if ( num > 30 )
    this->BorderDepthPercentage = 30;
  if ( this->BorderDepthPercentage < 5 )
    this->BorderDepthPercentage = 5;
  PointMaker::PrepareLimits(this);
}

//----- (0044C350) --------------------------------------------------------
char *__thiscall PointMaker::RetrieveMap(PointMaker *this)
{
  return this->PlacementArray;
}

//----- (0044C360) --------------------------------------------------------
char *__thiscall PointMaker::RetrieveProbMap(PointMaker *this)
{
  return this->ProbArray;
}

//----- (0044C370) --------------------------------------------------------
void __thiscall PointMaker::ErrorCheckingAndCorrection(PointMaker *this)
{
  int v1; // esi@1
  int v2; // edi@1
  int v3; // eax@1
  int v4; // eax@11
  int v5; // esi@11
  int v6; // eax@11

  v1 = this->Width;
  v2 = v1 * this->Height;
  v3 = this->BranchRadius;
  this->SizeArrays = v2;
  if ( v3 > v1 )
    this->BranchRadius = 2 * v1 / 3;
  if ( this->SatelliteRadius > v1 )
    this->SatelliteRadius = 2 * v1 / 3;
  if ( this->PrimaryRadius > v1 )
    this->PrimaryRadius = 2 * v1 / 3;
  if ( this->NumSplitsPerBranch > 4 )
    this->NumSplitsPerBranch = 4;
  if ( this->NumberOfSatellites > 4 )
    this->NumberOfSatellites = 4;
  v4 = v2 / this->MinimumNumTiles;
  this->DrawToOneArrayFlag = 0;
  v5 = v4;
  v6 = 10 * (10 - v4);
  this->ChanceOfNextNode = v6;
  if ( v6 < 35 )
    this->ChanceOfNextNode = 35;
  if ( this->ChanceOfNextNode > 80 )
    this->ChanceOfNextNode = 80;
  if ( !this->MaxBranchFlag )
    this->MaxNumberOfBranchLevels = v5 - this->ChanceOfNextNode / 5;
  if ( this->MaxNumberOfBranchLevels < 10 )
    this->MaxNumberOfBranchLevels = 10;
  if ( this->MaxNumberOfBranchLevels > 30 )
    this->MaxNumberOfBranchLevels = 30;
  this->MaxBranchFlag = 0;
}

//----- (0044C4B0) --------------------------------------------------------
void __thiscall PointMaker::PrepareLimits(PointMaker *this)
{
  int v1; // esi@1
  int v2; // edi@1
  int v3; // edx@1
  int v4; // edx@1
  int v5; // esi@1

  v1 = this->Width;
  v2 = this->BorderDepthPercentage;
  v3 = v1 * this->BorderDepthPercentage / 100;
  this->LeftLimit = v3;
  this->RightLimit = v1 - v3;
  v4 = v2 * this->Height / 100;
  v5 = this->Height - v4;
  this->TopLimit = v4;
  this->BottomLimit = v5;
}

//----- (0044C510) --------------------------------------------------------
void __thiscall PointMaker::MapCleanUpEliminatingSinglesOnly(PointMaker *this)
{
  int v1; // edx@1
  signed int v2; // ebx@1
  int v3; // eax@1
  signed int v4; // edi@2
  int v5; // edx@3
  char *v6; // eax@3
  signed int v7; // esi@3
  int w; // [sp+4h] [bp-8h]@1
  int h; // [sp+8h] [bp-4h]@1

  v1 = this->Height - 1;
  v2 = 1;
  v3 = this->Width - 1;
  h = this->Height - 1;
  for ( w = this->Width - 1; v2 < v1; ++v2 )
  {
    v4 = 1;
    if ( v3 > 1 )
    {
      do
      {
        v5 = this->Width;
        v6 = &this->PlacementArray[v4] + v5 * v2;
        v7 = 0;
        if ( v6[-v5] > 0 )
          v7 = 1;
        if ( *(v6 - 1) > 0 )
          ++v7;
        if ( v6[1] > 0 )
          ++v7;
        if ( v6[v5] > 0 )
          ++v7;
        if ( *v6 )
        {
          if ( !v7 )
            *v6 = 0;
        }
        v3 = w;
        ++v4;
      }
      while ( v4 < w );
      v1 = h;
    }
  }
}
