
/**
 * @file    Engine\RGE\PathingSystem.cpp
 * @author  Yvan Burrie
 * @date    2018/06/23
 * @version 1.0
 */

PathingSystem aiPathSystem;
int *DiagionalDistance;
PathingSystem pathSystem;
int MapPathsDisplay;

//----- (0046B050) --------------------------------------------------------
int _E12()
{
  _E9();
  return _E11();
}

//----- (0046B060) --------------------------------------------------------
void _E9()
{
  PathingSystem::PathingSystem(&pathSystem, 255, 255, 0, 0, 0);
}

//----- (0046B080) --------------------------------------------------------
int _E11()
{
  return atexit(_E10);
}

//----- (0046B090) --------------------------------------------------------
void __cdecl _E10()
{
  PathingSystem::~PathingSystem(&pathSystem);
}

//----- (0046B0A0) --------------------------------------------------------
int _E17()
{
  _E14();
  return _E16();
}

//----- (0046B0B0) --------------------------------------------------------
void _E14()
{
  PathingSystem::PathingSystem(&aiPathSystem, 255, 255, 1, 0, 0);
}

//----- (0046B0D0) --------------------------------------------------------
int _E16()
{
  return atexit(_E15);
}

//----- (0046B0E0) --------------------------------------------------------
void __cdecl _E15()
{
  PathingSystem::~PathingSystem(&aiPathSystem);
}

//----- (0046B0F0) --------------------------------------------------------
void __thiscall PathingSystem::PathingSystem(PathingSystem *this, int x, int y, int aiPSInit, RGE_Map *map, RGE_Game_World *world)
{
  PathingSystem *v6; // esi@1
  int **v7; // edi@1
  int aiPSInita; // [sp+24h] [bp+Ch]@1

  v6 = this;
  this->initialCollidingObjects.value = 0;
  this->initialCollidingObjects.numberValue = 0;
  this->initialCollidingObjects.desiredNumberValue = 0;
  this->initialCollidingObjects.maximumSizeValue = 0;
  this->currentUnobstructibles.value = 0;
  this->currentUnobstructibles.numberValue = 0;
  this->currentUnobstructibles.desiredNumberValue = 0;
  this->currentUnobstructibles.maximumSizeValue = 0;
  this->aiPS = aiPSInit;
  this->xSizeValue = -1;
  this->ySizeValue = -1;
  this->currentTerrainException1 = -1;
  this->currentTerrainException2 = -1;
  this->vfptr = (PathingSystemVtbl *)&PathingSystem::`vftable';
  this->numberOpenPathsValue = 0;
  this->numberTraversedPathsValue = 0;
  this->mapValue = 0;
  this->worldValue = 0;
  this->currentObject = 0;
  LODWORD(this->averageNumWaypoints) = 0;
  LODWORD(this->averagePathLength) = 0;
  LODWORD(this->averagePathIterations) = 0;
  LODWORD(this->averageClosestTargetDistance) = 0;
  this->numAttempts = 0;
  this->numFails = 0;
  this->numSuccesses = 0;
  this->numInitialPathsValue = 0;
  this->numContinuePathsValue = 0;
  this->numCanPathsValue = 0;
  LODWORD(this->averageSuccessTime) = 0;
  LODWORD(this->averageFailTime) = 0;
  PathingSystem::initialize(this, x, y, map, world);
  PathingSystem::initMisc(v6, 0);
  PathingSystem::zeroObstructionMap(v6);
  aiPSInita = 0;
  v7 = &DiagionalDistance;
  do
  {
    *v7 = (int *)(signed __int64)(0.5 - (double)aiPSInita * 1.4141999 * -16.0);
    ++v7;
    ++aiPSInita;
  }
  while ( (signed int)v7 < (signed int)&pathSystem );
}
// 570E8C: using guessed type int (__thiscall *PathingSystem::`vftable')(void *Memory, unsigned int __flags);
// 74D040: using guessed type int *DiagionalDistance;

//----- (0046B250) --------------------------------------------------------
PathingSystem *__thiscall PathingSystem::`vector deleting destructor'(PathingSystem *this, unsigned int __flags)
{
  PathingSystem *v2; // esi@1

  v2 = this;
  PathingSystem::~PathingSystem(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0046B270) --------------------------------------------------------
void __thiscall PathingSystem::~PathingSystem(PathingSystem *this)
{
  PathingSystem *v1; // esi@1
  int *v2; // eax@1
  int *v3; // eax@3

  v1 = this;
  this->vfptr = (PathingSystemVtbl *)&PathingSystem::`vftable';
  v2 = this->currentUnobstructibles.value;
  if ( v2 )
  {
    operator delete(v2);
    v1->currentUnobstructibles.value = 0;
  }
  v1->currentUnobstructibles.numberValue = 0;
  v1->currentUnobstructibles.desiredNumberValue = 0;
  v1->currentUnobstructibles.maximumSizeValue = 0;
  v3 = v1->initialCollidingObjects.value;
  if ( v3 )
  {
    operator delete(v3);
    v1->initialCollidingObjects.value = 0;
  }
  v1->initialCollidingObjects.numberValue = 0;
  v1->initialCollidingObjects.desiredNumberValue = 0;
  v1->initialCollidingObjects.maximumSizeValue = 0;
}
// 570E8C: using guessed type int (__thiscall *PathingSystem::`vftable')(void *Memory, unsigned int __flags);

//----- (0046B310) --------------------------------------------------------
int __thiscall PathingSystem::initialize(PathingSystem *this, int x, int y, RGE_Map *map, RGE_Game_World *world)
{
  int result; // eax@2

  this->mapValue = map;
  this->worldValue = world;
  if ( map )
  {
    this->xSizeValue = map->map_width;
    this->ySizeValue = map->map_height;
    this->CurrentFacetMask = -16;
    result = 1;
  }
  else
  {
    this->ySizeValue = y;
    this->xSizeValue = x;
    this->CurrentFacetMask = -16;
    result = 1;
  }
  return result;
}

//----- (0046B360) --------------------------------------------------------
void __thiscall PathingSystem::printToFile(PathingSystem *this, char *filename)
{
  PathingSystem *v2; // ebp@1
  FILE *v3; // eax@2
  FILE *v4; // esi@2
  int i; // edi@3
  int j; // edi@5
  int v7; // edi@7
  int k; // ebx@11
  int v9; // ST0C_4@13
  int v10; // ST0C_4@14
  int v11; // ebx@16

  v2 = this;
  if ( filename )
  {
    v3 = fopen(filename, aWa);
    v4 = v3;
    if ( v3 )
    {
      fprintf(v3, aFilenameS, filename);
      fprintf(v4, aDimensionsDXD, 4 * v2->xSizeValue, 4 * v2->ySizeValue);
      fprintf(v4, Str);
      fprintf(v4, asc_585248);
      for ( i = 0; i < v2->xSizeValue; ++i )
        fprintf(v4, a04d, i);
      fprintf(v4, Str);
      fprintf(v4, asc_585248);
      for ( j = 0; j < v2->xSizeValue; ++j )
        fprintf(v4, asc_585238, j);
      fprintf(v4, Str);
      v7 = 0;
      if ( 4 * v2->ySizeValue > 0 )
      {
        do
        {
          if ( (char)v7 % -4 )
            fprintf(v4, asc_584818);
          else
            fprintf(v4, aR03d, v7 / 4);
          for ( k = 0; k < 4 * v2->xSizeValue; ++k )
          {
            if ( (char)k % -4 )
            {
              v10 = (unsigned __int8)PathingSystem::obstruction(v2, k, v7);
              fprintf(v4, a1d_0, v10);
            }
            else
            {
              v9 = (unsigned __int8)PathingSystem::obstruction(v2, k, v7);
              fprintf(v4, a1d, v9);
            }
          }
          v11 = v7 + 1;
          if ( (((unsigned __int64)(v7 + 1) >> 32) ^ abs(v7 + 1) & 3) == (unsigned __int64)(v7 + 1) >> 32 )
            fprintf(v4, aR03d_2, v7 / 4);
          else
            fprintf(v4, Str, v7 / 4);
          ++v7;
        }
        while ( v11 < 4 * v2->ySizeValue );
      }
      fprintf(v4, Str);
      fclose(v4);
    }
  }
}

//----- (0046B550) --------------------------------------------------------
char __thiscall PathingSystem::lookupMisc(PathingSystem *this, int x, int y)
{
  return this->miscValue[x][y];
}

//----- (0046B570) --------------------------------------------------------
void __thiscall PathingSystem::setMisc(PathingSystem *this, int x, int y, char v)
{
  this->miscValue[x][y] = v;
}

//----- (0046B590) --------------------------------------------------------
void __thiscall PathingSystem::initMisc(PathingSystem *this, char v)
{
  int v2; // edx@1
  int v3; // eax@1

  HIWORD(v2) = HIWORD(this);
  LOBYTE(v2) = v;
  BYTE1(v2) = v;
  v3 = v2 << 16;
  LOWORD(v3) = v2;
  memset32(this->miscValue, v3, 0x3F80u);
  this->miscValue[254][254] = v;
}

//----- (0046B5C0) --------------------------------------------------------
void __thiscall PathingSystem::zeroObstructionMap(PathingSystem *this)
{
  memset(this->obstructionValue, 0, sizeof(this->obstructionValue));
}

//----- (0046B5E0) --------------------------------------------------------
unsigned int __thiscall PathingSystem::obstruction(PathingSystem *this, int x, int y)
{
  return ((unsigned int)this->obstructionValue[x][y >> 2] >> LOBYTE((&ObstructionValueShift)[y & 3])) & 3;
}
// 584EF4: using guessed type unsigned __int8 *ObstructionValueShift;

//----- (0046B620) --------------------------------------------------------
void __thiscall PathingSystem::incrementObstruction(PathingSystem *this, int x, int y)
{
  char *v3; // ecx@1
  unsigned __int8 v4; // bl@1
  unsigned __int8 v5; // al@1

  v3 = (char *)this + (y >> 2);
  v4 = v3[255 * x + 845348];
  v5 = (v4 >> LOBYTE((&ObstructionValueShift)[y & 3])) & 3;
  if ( v5 < 3u )
    v3[255 * x + 845348] = ((v5 + 1) << LOBYTE((&ObstructionValueShift)[y & 3])) | v4 & (unsigned int)(&ObstructionValueMask)[y & 3];
}
// 584EF0: using guessed type unsigned __int8 *ObstructionValueMask;
// 584EF4: using guessed type unsigned __int8 *ObstructionValueShift;

//----- (0046B680) --------------------------------------------------------
void __thiscall PathingSystem::decrementObstruction(PathingSystem *this, int x, int y)
{
  char *v3; // ecx@1
  unsigned __int8 v4; // bl@1
  char v5; // al@1

  v3 = (char *)this + 255 * x;
  v4 = v3[(y >> 2) + 845348];
  v5 = (v4 >> LOBYTE((&ObstructionValueShift)[y & 3])) & 3;
  if ( v5 )
    v3[(y >> 2) + 845348] = ((v5 - 1) << LOBYTE((&ObstructionValueShift)[y & 3])) | v4 & (unsigned int)(&ObstructionValueMask)[y & 3];
}
// 584EF0: using guessed type unsigned __int8 *ObstructionValueMask;
// 584EF4: using guessed type unsigned __int8 *ObstructionValueShift;

//----- (0046B6E0) --------------------------------------------------------
int __thiscall PathingSystem::findTilePath(PathingSystem *this, int startX, int startY, int goalX, int goalY, RGE_Moving_Object *unit, float actionRange, int cTargetID, int copyPathWhenDone, float *pathLength, int checkPathingIterations, int checkTerrainFirstTime, int checkCollisions, int stepSize, int unobstructiblePlayerID, int unobstructibleGroupID)
{
  PathingSystem *v16; // esi@1
  int v17; // eax@3
  RGE_Moving_Object *v18; // edi@9
  int v19; // eax@10
  int v20; // ebx@10
  int v21; // ecx@10
  int v22; // edx@10
  int v23; // eax@14
  int v24; // ebx@14
  int v25; // ebx@15
  int v26; // et2@15
  double v27; // st7@17
  char *v28; // ecx@21
  char *v30; // ecx@28
  int v31; // edx@30
  int v32; // eax@30
  RGE_Map *v33; // edx@31
  int j; // ebx@31
  int v35; // ecx@32
  char *v36; // eax@33
  char v37; // dl@34
  int v38; // eax@36
  int v39; // edx@37
  int v40; // eax@37
  int v41; // ecx@37
  RGE_Static_Object *v42; // eax@38
  int v43; // eax@41
  int v44; // ST10_4@41
  RGE_Static_Object *v45; // ecx@41
  int v46; // eax@41
  RGE_Moving_Object *v47; // edx@41
  float v48; // ST0C_4@41
  double v49; // st7@41
  float v50; // ST08_4@41
  RGE_Moving_Object *v51; // ebx@44
  int v52; // eax@45
  int v53; // edi@45
  int v54; // eax@48
  int v55; // edx@49
  RGE_Static_Object *v56; // ebx@53
  RGE_Moving_Object *v57; // edi@60
  signed __int64 v58; // rax@60
  signed __int64 v59; // rax@62
  signed __int64 v60; // rax@64
  int v61; // ecx@64
  signed __int64 v62; // rax@66
  int v63; // ecx@66
  int v64; // ecx@66
  int v65; // edx@68
  char v66; // al@68
  int v67; // eax@71
  int v68; // ebx@71
  int v69; // ecx@71
  int v70; // edx@71
  int v71; // eax@75
  int v72; // ebx@75
  int v73; // ebx@76
  int v74; // et1@76
  int v75; // ebx@78
  char v76; // cl@78
  double v77; // st7@78
  int v78; // eax@78
  bool v79; // c0@78
  bool v80; // c3@78
  signed __int64 v81; // rax@79
  RGE_Master_Static_Object *v82; // eax@81
  double v83; // st7@81
  double v84; // st6@81
  double v85; // st6@81
  double v86; // st7@81
  double v87; // st6@81
  signed __int64 v88; // rax@81
  double v89; // st6@81
  int v90; // edi@81
  signed int v91; // ecx@81
  int v92; // edx@82
  RGE_Player *v93; // eax@84
  int v94; // edi@94
  int v95; // eax@96
  int v96; // ebx@96
  int v97; // ecx@96
  int v98; // edx@96
  int v99; // eax@100
  int v100; // ebx@100
  int v101; // ebx@101
  int v102; // et0@101
  int v103; // ebx@103
  double v104; // st7@103
  signed __int64 v105; // rax@103
  signed int v106; // ecx@103
  char v107; // cl@108
  int v108; // eax@109
  int v109; // eax@109
  int v110; // ecx@109
  int v111; // edx@109
  float v112; // ecx@111
  float v113; // eax@115
  int v114; // edx@115
  float v115; // eax@116
  char v116; // dl@117
  int v117; // ecx@117
  signed int v118; // ecx@118
  int v119; // eax@122
  int v120; // eax@128
  double v121; // st7@137
  int v122; // eax@137
  int v123; // ebx@137
  int v124; // ecx@137
  int v125; // edx@137
  int v126; // eax@141
  int v127; // ebx@141
  int v128; // ebx@142
  int v129; // ett@142
  int v130; // eax@144
  int v131; // ebx@144
  int v132; // ecx@144
  int v133; // edx@144
  int v134; // eax@148
  int v135; // ebx@148
  int v136; // ebx@149
  int v137; // et2@149
  int *v138; // ST4C_4@151
  int v139; // eax@151
  int v140; // edx@151
  unsigned __int8 v141; // cl@151
  unsigned __int8 v142; // bl@152
  int v143; // edx@157
  int v144; // ebx@157
  int v145; // edi@157
  int v146; // ebx@159
  int v147; // edi@159
  int v148; // ebx@161
  int v149; // edi@161
  int v150; // ebx@162
  int v151; // edi@162
  int v152; // ebx@163
  int v153; // edi@163
  int v154; // ebx@165
  int v155; // edi@165
  float v156; // edi@169
  int v157; // edi@170
  RGE_Map *v158; // edi@175
  int v159; // eax@179
  int v160; // edi@179
  _BYTE *v161; // ebx@180
  float *v162; // edi@184
  signed int v163; // edx@194
  int v164; // edx@196
  float v165; // ebx@196
  int v166; // eax@196
  int v167; // ecx@198
  int v168; // eax@203
  int v169; // edx@203
  int v170; // eax@203
  char *v171; // eax@205
  int v172; // edx@209
  int v173; // ecx@210
  int v174; // edi@216
  signed int v175; // eax@218
  int v176; // ebx@235
  int v177; // ecx@237
  int v178; // edi@240
  int v179; // edx@245
  int v180; // eax@245
  RGE_Static_Object *v181; // eax@249
  float v182; // eax@250
  int v183; // ecx@255
  int v184; // edx@266
  signed int v185; // ebx@266
  signed int v186; // edi@266
  char v187; // al@267
  int v188; // ecx@267
  int v189; // edx@267
  char v190; // cl@270
  float v191; // edx@270
  int v192; // eax@275
  char *v193; // ecx@279
  RGE_Moving_Object *v194; // edi@281
  int v195; // ebx@281
  int v196; // eax@284
  int v197; // edx@285
  RGE_Static_Object *v198; // eax@289
  RGE_Moving_Object *v199; // edi@298
  int v200; // ebx@298
  int v201; // eax@301
  int v202; // edx@302
  RGE_Static_Object *v203; // eax@306
  char *v204; // ecx@315
  RGE_Moving_Object *v205; // edi@317
  int v206; // ebx@317
  _DWORD *v207; // edx@319
  int k; // eax@320
  RGE_Static_Object *v209; // eax@324
  RGE_Moving_Object *v210; // edi@333
  int v211; // ebx@333
  _DWORD *v212; // edx@335
  int l; // eax@336
  RGE_Static_Object *v214; // eax@340
  RGE_Static_Object *v215; // ecx@347
  int v216; // ecx@350
  signed int v217; // ebx@350
  signed int v218; // edi@350
  char v219; // al@351
  int v220; // ecx@351
  int v221; // edx@351
  char v222; // cl@354
  int v223; // edx@354
  char *v224; // ecx@357
  RGE_Moving_Object *v225; // edi@359
  int v226; // ebx@359
  int v227; // eax@362
  int v228; // edx@363
  RGE_Static_Object *v229; // eax@367
  RGE_Moving_Object *v230; // edi@376
  int v231; // ebx@376
  int v232; // eax@379
  int v233; // edx@380
  RGE_Static_Object *v234; // eax@384
  RGE_Static_Object *v235; // ecx@391
  int bestPathPoint; // [sp+20h] [bp-7Ch]@94
  int bestPathPoint_4; // [sp+24h] [bp-78h]@94
  int temp; // [sp+28h] [bp-74h]@103
  int temp_4; // [sp+2Ch] [bp-70h]@103
  char *v240; // [sp+30h] [bp-6Ch]@151
  int newTotal; // [sp+34h] [bp-68h]@151
  unsigned __int8 v242; // [sp+38h] [bp-64h]@184
  RGE_Tile **v243; // [sp+44h] [bp-58h]@178
  int *v244; // [sp+48h] [bp-54h]@144
  char v245; // [sp+50h] [bp-4Ch]@260
  float unobstructibleObjectHitpoints; // [sp+54h] [bp-48h]@233
  int v247; // [sp+58h] [bp-44h]@151
  int v248; // [sp+5Ch] [bp-40h]@180
  int MGP_goalTolerance; // [sp+60h] [bp-3Ch]@81
  int SkipBit; // [sp+64h] [bp-38h]@118
  int v251; // [sp+68h] [bp-34h]@118
  unsigned __int8 v252; // [sp+6Ch] [bp-30h]@177
  unsigned __int8 v253; // [sp+70h] [bp-2Ch]@179
  int iterations; // [sp+74h] [bp-28h]@81
  int i; // [sp+78h] [bp-24h]@118
  char v256; // [sp+7Ch] [bp-20h]@192
  signed int numberIterationCap; // [sp+80h] [bp-1Ch]@84
  int yDeltaDown; // [sp+84h] [bp-18h]@81
  int xDeltaRight; // [sp+88h] [bp-14h]@81
  int yDeltaUp; // [sp+8Ch] [bp-10h]@81
  int xDeltaLeft; // [sp+90h] [bp-Ch]@81
  int yDeltaDown4; // [sp+94h] [bp-8h]@81
  int xDeltaRight4; // [sp+98h] [bp-4h]@81

  v16 = this;
  if ( startX < 0
    || startY < 0
    || (v17 = this->xSizeValue, startX > v17)
    || startY > v17
    || goalX < 0
    || goalY < 0
    || goalX > v17
    || goalY > v17 )
  {
    if ( copyPathWhenDone != 1 )
      return 0;
    v30 = (char *)&unit->pathValue;
    if ( unit->storePathInExceptionPath )
      v30 = (char *)&unit->exceptionPathValue;
LABEL_396:
    Path::killPath((Path *)v30);
    return 0;
  }
  v18 = unit;
  if ( actionRange > 1.0 )
  {
    v19 = goalX;
    v20 = goalY;
    v21 = startX;
    v22 = startY;
    if ( goalX < startX )
    {
      v19 = startX;
      v21 = goalX;
    }
    if ( goalY < startY )
    {
      v20 = startY;
      v22 = goalY;
    }
    v23 = v19 - v21;
    v24 = v20 - v22;
    if ( v23 < v24 )
    {
      v25 = v24 - v23;
    }
    else
    {
      v26 = v23 - v24;
      LOBYTE(v23) = v24;
      v25 = v26;
    }
    v27 = (double)(signed int)&(&DiagionalDistance)[(unsigned __int8)v23][4 * v25];
    if ( actionRange * 16.0 > v27 )
    {
      if ( pathLength )
        *(_DWORD *)pathLength = 0;
      if ( copyPathWhenDone != 1 )
        return 1;
      v28 = (char *)&unit->pathValue;
      if ( unit->storePathInExceptionPath )
        v28 = (char *)&unit->exceptionPathValue;
      Path::killPath((Path *)v28);
      return 1;
    }
    unit->vfptr->maximumSpeed((RGE_Static_Object *)unit);
    if ( v27 == 0.0 )
    {
      if ( pathLength )
        *(_DWORD *)pathLength = 0;
      if ( copyPathWhenDone != 1 )
        return 0;
      v30 = (char *)&v18->pathValue;
      if ( v18->storePathInExceptionPath )
      {
        Path::killPath(&v18->exceptionPathValue);
        return 0;
      }
      goto LABEL_396;
    }
  }
  v16->currentObject = v18;
  v16->currentTerrainTable = v16->worldValue->terrains[v18->master_obj->terrain];
  v31 = unobstructiblePlayerID;
  v16->currentTerrainException1 = v18->currentTerrainException1;
  v32 = unobstructibleGroupID;
  v16->currentTerrainException2 = v18->currentTerrainException2;
  v16->currentUnobstructiblePlayerID = v31;
  v16->currentUnobstructibleGroupID = v32;
  v16->currentUnobstructibles.numberValue = 0;
  if ( MapPathsDisplay )
  {
    v33 = v16->mapValue;
    for ( j = 0; j < v33->map_height; ++j )
    {
      v35 = 0;
      if ( v33->map_width > 0 )
      {
        v36 = &v33->map_row_offset[j]->draw_attribute;
        do
        {
          v37 = *v36;
          v36 += 24;
          ++v35;
          *(v36 - 24) = v37 & 0x70;
        }
        while ( v35 < v16->mapValue->map_width );
      }
      v33 = v16->mapValue;
    }
    v38 = ((int (*)(void))rge_base_game->vfptr->get_view_panel)();
    (*(void (__thiscall **)(int, signed int))(*(_DWORD *)v38 + 32))(v38, 2);
  }
  v39 = cTargetID;
  v40 = 4 * goalX;
  v41 = 4 * goalY;
  v16->minTarget.x = 4 * goalX;
  v16->minTarget.y = v41;
  v16->currentTargetID = v39;
  v16->maxTarget.x = v40 + 3;
  v16->maxTarget.y = v41 + 3;
  if ( v39 != -1 )
  {
    v42 = RGE_Game_World::object(v16->worldValue, v39);
    if ( v42 )
    {
      v16->minTarget.x = (signed __int64)((v42->world_x - v42->master_obj->radius_x) * 4.0);
      v16->minTarget.y = (signed __int64)((v42->world_y - v42->master_obj->radius_y) * 4.0);
      v16->maxTarget.x = (signed __int64)((v42->master_obj->radius_x + v42->world_x) * 4.0);
      v16->maxTarget.y = (signed __int64)((v42->master_obj->radius_y + v42->world_y) * 4.0);
    }
    else
    {
      v16->currentTargetID = -1;
    }
  }
  v43 = checkTerrainFirstTime;
  v44 = v16->aiPS;
  v45 = (RGE_Static_Object *)&v16->currentObject->vfptr;
  v16->startOfPath = 1;
  v16->checkTerrainOnFirstPass = v43;
  v46 = RGE_Static_Object::removeFromObstructionMap(v45, v44);
  v47 = v16->currentObject;
  v16->currentObjectInObMap = v46;
  v48 = floor(v47->world_y) - -0.5;
  v49 = floor(v16->currentObject->world_x) - -0.5;
  v50 = v49;
  if ( PathingSystem::passable(v16, v16->currentObject, v50, v48, 1) )
  {
    LODWORD(v16->currentXOffset) = 1056964608;
    LODWORD(v16->currentYOffset) = 1056964608;
  }
  else
  {
    v16->currentXOffset = v18->world_x - floor(v18->world_x);
    v49 = v18->world_y - floor(v18->world_y);
    v16->currentYOffset = v49;
  }
  v51 = v16->currentObject;
  if ( v51->continueCounter >= 10 )
  {
    v52 = v51->pathingGroupMembers.numberValue;
    *(float *)&v53 = 0.0;
    *(float *)&unobstructiblePlayerID = 0.0;
    if ( v52 > 0 )
    {
      do
      {
        if ( v53 > v51->pathingGroupMembers.maximumSizeValue - 1 )
        {
          unobstructibleGroupID = (int)operator new(4 * v53 + 4);
          if ( unobstructibleGroupID )
          {
            v54 = 0;
            if ( v51->pathingGroupMembers.maximumSizeValue > 0 )
            {
              v55 = unobstructibleGroupID;
              do
              {
                if ( v54 >= v53 + 1 )
                  break;
                v53 = unobstructiblePlayerID;
                *(_DWORD *)(v55 + 4 * v54) = v51->pathingGroupMembers.value[v54];
                ++v54;
              }
              while ( v54 < v51->pathingGroupMembers.maximumSizeValue );
            }
            operator delete(v51->pathingGroupMembers.value);
            v51->pathingGroupMembers.value = (int *)unobstructibleGroupID;
            v51->pathingGroupMembers.maximumSizeValue = v53 + 1;
          }
        }
        v56 = RGE_Game_World::object(v16->worldValue, v51->pathingGroupMembers.value[v53]);
        if ( v56 )
        {
          if ( v56->id != v16->currentObject->id )
          {
            unobstructiblePlayerID = (unsigned __int8)v56->vfptr->waitingToMove(v56);
            v56->vfptr->getSpeed(v56);
            cTargetID = (int)v56[2].inside_obj;
            if ( *(float *)&unobstructiblePlayerID != 0.0
              || v49 != 0.0
              || (v49 = *(float *)&cTargetID, *(float *)&cTargetID > 0.0) )
            {
              RGE_Static_Object::removeFromObstructionMap(v56, v16->aiPS);
            }
          }
        }
        v51 = v16->currentObject;
        ++v53;
        unobstructiblePlayerID = v53;
      }
      while ( v53 < v51->pathingGroupMembers.numberValue );
    }
  }
  v57 = v16->currentObject;
  v58 = (signed __int64)((v57->world_x - v57->master_obj->radius_x) * 4.0);
  v16->minInitialPosition.x = v58;
  if ( (signed int)v58 < 0 )
    v16->minInitialPosition.x = 0;
  v59 = (signed __int64)((v57->world_y - v57->master_obj->radius_y) * 4.0);
  v16->minInitialPosition.y = v59;
  if ( (signed int)v59 < 0 )
    v16->minInitialPosition.y = 0;
  v60 = (signed __int64)((v57->master_obj->radius_x + v57->world_x) * 4.0);
  v61 = 4 * v16->xSizeValue;
  v16->maxInitialPosition.x = v60;
  if ( (signed int)v60 > v61 )
    v16->maxInitialPosition.x = v61;
  v62 = (signed __int64)((v57->master_obj->radius_y + v57->world_y) * 4.0);
  v63 = v16->ySizeValue;
  v16->maxInitialPosition.y = v62;
  v64 = 4 * v63;
  if ( (signed int)v62 > v64 )
    v16->maxInitialPosition.y = v64;
  RGE_Moving_Object::setInitialPoints(v57, &v16->minInitialPosition, &v16->maxInitialPosition);
  v65 = startX;
  v16->initialTile.y = startY;
  v66 = v16->CurrentFacetMask;
  v16->initialTile.x = v65;
  v16->MGP_closestTargetDistance = -1;
  if ( (unsigned __int8)v66 < 0xF0u )
  {
    v16->CurrentFacetMask = v66 + 8;
  }
  else
  {
    v16->CurrentFacetMask = 0;
    memset(v16->facetValue, 0xFFu, 0xFE00u);
    v16->facetValue[254][254] = -1;
  }
  v16->numberOpenPathsValue = 1;
  v16->numberTraversedPathsValue = 0;
  v67 = goalX;
  v68 = goalY;
  v69 = startX;
  v70 = startY;
  if ( goalX < startX )
  {
    v67 = startX;
    v69 = goalX;
  }
  if ( goalY < startY )
  {
    v68 = startY;
    v70 = goalY;
  }
  v71 = v67 - v69;
  v72 = v68 - v70;
  if ( v71 < v72 )
  {
    v73 = v72 - v71;
  }
  else
  {
    v74 = v71 - v72;
    LOBYTE(v71) = v72;
    v73 = v74;
  }
  unobstructiblePlayerID = (int)&(&DiagionalDistance)[(unsigned __int8)v71][4 * v73];
  v75 = startX;
  v76 = startY;
  v77 = (double)stepSize;
  v78 = unobstructiblePlayerID;
  v79 = v77 < actionRange;
  v80 = v77 == actionRange;
  v16->MGP_costValue[0][startY + 255 * startX] = unobstructiblePlayerID;
  v16->MGP_openPaths[1].total = v78;
  v16->MGP_bestTraversedPath.total = v78;
  v16->MGP_openPaths[1].x = v75;
  v16->MGP_openPaths[1].y = v76;
  v16->MGP_openPaths[0].total = -2000000000;
  v16->MGP_bestTraversedPath.x = v75;
  v16->MGP_bestTraversedPath.y = v76;
  if ( v79 || v80 )
    v81 = (signed __int64)(actionRange * 16.0);
  else
    LODWORD(v81) = 16 * stepSize;
  MGP_goalTolerance = v81;
  v82 = v16->currentObject->master_obj;
  v83 = v82->radius_x;
  v84 = v16->currentXOffset - -100.0;
  startX = SLODWORD(v82->radius_y);
  v85 = v84 - v83;
  actionRange = v85;
  v86 = v83 + v16->currentXOffset;
  xDeltaLeft = (unsigned __int64)(signed __int64)(v85 - -0.000049999999) - 100;
  xDeltaRight = (unsigned __int64)(signed __int64)(v86 - -100.00005) - 100;
  v87 = v16->currentYOffset - -100.0 - *(float *)&startX;
  *(float *)&unobstructiblePlayerID = v87;
  v88 = (signed __int64)(v87 - -0.000049999999);
  v89 = *(float *)&startX + v16->currentYOffset;
  yDeltaUp = v88 - 100;
  *(float *)&startX = v89;
  yDeltaDown = (unsigned __int64)(signed __int64)(v89 - -100.00005) - 100;
  cTargetID = -400 - (unsigned __int64)(signed __int64)(actionRange * -4.0);
  xDeltaRight4 = -400 - (unsigned __int64)(signed __int64)((v86 - -100.0) * -4.0);
  checkTerrainFirstTime = -400 - (unsigned __int64)(signed __int64)(*(float *)&unobstructiblePlayerID * -4.0);
  yDeltaDown4 = -400 - (unsigned __int64)(signed __int64)((*(float *)&startX - -100.0) * -4.0);
  iterations = 0;
  startY = (goalY - startY) * (goalY - startY);
  v90 = (signed int)(signed __int64)(sqrt((double)((goalX - v75) * (goalX - v75)) + (double)startY) * 16.0) / 16;
  v91 = numberPathingIterations * v90;
  if ( v90 > 10 )
    v92 = v91 / 100;
  else
    v92 = v91 / 10;
  numberIterationCap = v92;
  v93 = v16->currentObject->owner;
  if ( !v93->id && v92 > 100 )
    numberIterationCap = 100;
  if ( RGE_Player::computerPlayer(v93) == 1 )
    numberIterationCap = 2500 * v90 / 100;
  if ( v16->numberOpenPathsValue <= 0 )
    goto LABEL_350;
LABEL_90:
  if ( numberPathingIterations != -1 && checkPathingIterations == 1 && iterations > numberIterationCap
    || iterations > 20000 )
  {
LABEL_350:
    v216 = v16->numberOpenPathsValue + 1;
    v16->numberOpenPathsValue = v216;
    v16->MGP_openPaths[v216].x = v16->MGP_bestTraversedPath.x;
    v16->MGP_openPaths[v16->numberOpenPathsValue].y = v16->MGP_bestTraversedPath.y;
    v16->MGP_openPaths[v16->numberOpenPathsValue].total = 0;
    v217 = v16->numberOpenPathsValue;
    v218 = v16->numberOpenPathsValue;
    if ( v217 >= 1 )
    {
      v219 = v16->MGP_openPaths[v217].y;
      v220 = v217 / 2;
      LOBYTE(goalY) = v16->MGP_openPaths[v217].x;
      LOBYTE(goalX) = v219;
      v221 = v16->MGP_openPaths[v217 / 2].total;
      startY = v16->MGP_openPaths[v217].total;
      if ( startY < v221 )
      {
        do
        {
          *(_DWORD *)&v16->MGP_openPaths[v218].x = *(_DWORD *)&v16->MGP_openPaths[v220].x;
          v16->MGP_openPaths[v218].total = v16->MGP_openPaths[v220].total;
          v218 /= 2;
          v220 /= 2;
        }
        while ( startY < v16->MGP_openPaths[v220].total );
      }
      if ( v218 != v217 )
      {
        v222 = goalX;
        v223 = startY;
        v16->MGP_openPaths[v218].x = goalY;
        v16->MGP_openPaths[v218].y = v222;
        v16->MGP_openPaths[v218].total = v223;
      }
    }
    if ( copyPathWhenDone != 1 || PathingSystem::copyPath(v16, stepSize) )
    {
      if ( pathLength )
        *pathLength = (double)v16->MGP_bestTraversedPath.total;
      v230 = v16->currentObject;
      v231 = 0;
      for ( stepSize = 0; v231 < v230->pathingGroupMembers.numberValue; stepSize = v231 )
      {
        if ( v231 > v230->pathingGroupMembers.maximumSizeValue - 1 )
        {
          goalY = (int)operator new(4 * v231 + 4);
          if ( goalY )
          {
            v232 = 0;
            if ( v230->pathingGroupMembers.maximumSizeValue > 0 )
            {
              v233 = goalY;
              do
              {
                if ( v232 >= v231 + 1 )
                  break;
                v231 = stepSize;
                *(_DWORD *)(v233 + 4 * v232) = v230->pathingGroupMembers.value[v232];
                ++v232;
              }
              while ( v232 < v230->pathingGroupMembers.maximumSizeValue );
            }
            operator delete(v230->pathingGroupMembers.value);
            v230->pathingGroupMembers.value = (int *)goalY;
            v230->pathingGroupMembers.maximumSizeValue = v231 + 1;
          }
        }
        v234 = RGE_Game_World::object(v16->worldValue, v230->pathingGroupMembers.value[v231]);
        if ( v234 && v234->id != v16->currentObject->id && v234->lastInObstructionMapValue == 1 && !v234->inside_obj )
          RGE_Static_Object::addToObstructionMap(v234, v16->aiPS);
        v230 = v16->currentObject;
        ++v231;
      }
    }
    else
    {
      v224 = (char *)&unit->pathValue;
      if ( unit->storePathInExceptionPath )
        v224 = (char *)&unit->exceptionPathValue;
      Path::killPath((Path *)v224);
      v225 = v16->currentObject;
      v226 = 0;
      for ( stepSize = 0; v226 < v225->pathingGroupMembers.numberValue; stepSize = v226 )
      {
        if ( v226 > v225->pathingGroupMembers.maximumSizeValue - 1 )
        {
          goalY = (int)operator new(4 * v226 + 4);
          if ( goalY )
          {
            v227 = 0;
            if ( v225->pathingGroupMembers.maximumSizeValue > 0 )
            {
              v228 = goalY;
              do
              {
                if ( v227 >= v226 + 1 )
                  break;
                v226 = stepSize;
                *(_DWORD *)(v228 + 4 * v227) = v225->pathingGroupMembers.value[v227];
                ++v227;
              }
              while ( v227 < v225->pathingGroupMembers.maximumSizeValue );
            }
            operator delete(v225->pathingGroupMembers.value);
            v225->pathingGroupMembers.value = (int *)goalY;
            v225->pathingGroupMembers.maximumSizeValue = v226 + 1;
          }
        }
        v229 = RGE_Game_World::object(v16->worldValue, v225->pathingGroupMembers.value[v226]);
        if ( v229 && v229->id != v16->currentObject->id && v229->lastInObstructionMapValue == 1 && !v229->inside_obj )
          RGE_Static_Object::addToObstructionMap(v229, v16->aiPS);
        v225 = v16->currentObject;
        ++v226;
      }
    }
    goto LABEL_390;
  }
  v94 = v16->MGP_openPaths[1].x;
  bestPathPoint = v16->MGP_openPaths[1].x;
  bestPathPoint_4 = v16->MGP_openPaths[1].y;
  if ( MapPathsDisplay )
    v16->mapValue->map_row_offset[v16->MGP_openPaths[1].y][v94].draw_attribute = -127;
  v95 = goalX;
  v96 = goalY;
  v97 = bestPathPoint;
  v98 = bestPathPoint_4;
  if ( goalX < bestPathPoint )
  {
    v95 = bestPathPoint;
    v97 = goalX;
  }
  if ( goalY < bestPathPoint_4 )
  {
    v96 = bestPathPoint_4;
    v98 = goalY;
  }
  v99 = v95 - v97;
  v100 = v96 - v98;
  if ( v99 < v100 )
  {
    v101 = v100 - v99;
  }
  else
  {
    v102 = v99 - v100;
    LOBYTE(v99) = v100;
    v101 = v102;
  }
  startY = (int)&(&DiagionalDistance)[(unsigned __int8)v99][4 * v101];
  v103 = *(_DWORD *)&v16->MGP_openPaths[1].x & 0xFF;
  temp_4 = *(_DWORD *)&v16->MGP_openPaths[1].y & 0xFF;
  startY = (goalX - v103) * (goalX - v103);
  v104 = (double)startY;
  startY = (goalY - temp_4) * (goalY - temp_4);
  temp = v103;
  v105 = (signed __int64)(sqrt(v104 + (double)startY) * 16.0);
  v106 = v16->MGP_closestTargetDistance;
  if ( v106 == -1 || (signed int)v105 < v106 )
    v16->MGP_closestTargetDistance = v105;
  if ( (signed int)v105 < MGP_goalTolerance )
  {
    if ( copyPathWhenDone != 1 || PathingSystem::copyPath(v16, stepSize) )
    {
      if ( pathLength )
        *pathLength = (double)v16->MGP_costValue[0][bestPathPoint_4 + 255 * v94];
      v199 = v16->currentObject;
      v200 = 0;
      for ( stepSize = 0; v200 < v199->pathingGroupMembers.numberValue; stepSize = v200 )
      {
        if ( v200 > v199->pathingGroupMembers.maximumSizeValue - 1 )
        {
          goalY = (int)operator new(4 * v200 + 4);
          if ( goalY )
          {
            v201 = 0;
            if ( v199->pathingGroupMembers.maximumSizeValue > 0 )
            {
              v202 = goalY;
              do
              {
                if ( v201 >= v200 + 1 )
                  break;
                v200 = stepSize;
                *(_DWORD *)(v202 + 4 * v201) = v199->pathingGroupMembers.value[v201];
                ++v201;
              }
              while ( v201 < v199->pathingGroupMembers.maximumSizeValue );
            }
            operator delete(v199->pathingGroupMembers.value);
            v199->pathingGroupMembers.value = (int *)goalY;
            v199->pathingGroupMembers.maximumSizeValue = v200 + 1;
          }
        }
        v203 = RGE_Game_World::object(v16->worldValue, v199->pathingGroupMembers.value[v200]);
        if ( v203 && v203->id != v16->currentObject->id && v203->lastInObstructionMapValue == 1 && !v203->inside_obj )
          RGE_Static_Object::addToObstructionMap(v203, v16->aiPS);
        v199 = v16->currentObject;
        ++v200;
      }
      goto LABEL_346;
    }
    v193 = (char *)&unit->pathValue;
    if ( unit->storePathInExceptionPath )
      v193 = (char *)&unit->exceptionPathValue;
    Path::killPath((Path *)v193);
    v194 = v16->currentObject;
    v195 = 0;
    for ( stepSize = 0; v195 < v194->pathingGroupMembers.numberValue; stepSize = v195 )
    {
      if ( v195 > v194->pathingGroupMembers.maximumSizeValue - 1 )
      {
        goalY = (int)operator new(4 * v195 + 4);
        if ( goalY )
        {
          v196 = 0;
          if ( v194->pathingGroupMembers.maximumSizeValue > 0 )
          {
            v197 = goalY;
            do
            {
              if ( v196 >= v195 + 1 )
                break;
              v195 = stepSize;
              *(_DWORD *)(v197 + 4 * v196) = v194->pathingGroupMembers.value[v196];
              ++v196;
            }
            while ( v196 < v194->pathingGroupMembers.maximumSizeValue );
          }
          operator delete(v194->pathingGroupMembers.value);
          v194->pathingGroupMembers.value = (int *)goalY;
          v194->pathingGroupMembers.maximumSizeValue = v195 + 1;
        }
      }
      v198 = RGE_Game_World::object(v16->worldValue, v194->pathingGroupMembers.value[v195]);
      if ( v198 && v198->id != v16->currentObject->id && v198->lastInObstructionMapValue == 1 && !v198->inside_obj )
        RGE_Static_Object::addToObstructionMap(v198, v16->aiPS);
      v194 = v16->currentObject;
      ++v195;
    }
LABEL_390:
    if ( v16->currentObjectInObMap == 1 )
    {
      v235 = (RGE_Static_Object *)&v16->currentObject->vfptr;
      if ( !v235->inside_obj )
      {
        RGE_Static_Object::addToObstructionMap(v235, v16->aiPS);
        return 0;
      }
    }
    return 0;
  }
  if ( (signed int)v105 < v16->MGP_bestTraversedPath.total )
  {
    v107 = v16->MGP_openPaths[1].x;
    v16->MGP_bestTraversedPath.total = v105;
    v16->MGP_bestTraversedPath.x = v107;
    v16->MGP_bestTraversedPath.y = v16->MGP_openPaths[1].y;
  }
  v108 = v16->numberTraversedPathsValue;
  LODWORD(actionRange) = 1;
  v16->numberTraversedPathsValue = v108 + 1;
  v109 = v16->numberOpenPathsValue;
  v16->MGP_openPaths[1].x = v16->MGP_openPaths[v109].x;
  v16->MGP_openPaths[1].y = v16->MGP_openPaths[v109].y;
  v16->MGP_openPaths[1].total = v16->MGP_openPaths[v109].total;
  v110 = v109 - 1;
  v16->numberOpenPathsValue = v109 - 1;
  LOBYTE(v109) = v16->MGP_openPaths[1].y;
  LOBYTE(startY) = v16->MGP_openPaths[1].x;
  v111 = v16->MGP_openPaths[1].total;
  LOBYTE(startX) = v109;
  unobstructibleGroupID = v111;
  if ( v110 / 2 > 1 )
  {
    unobstructiblePlayerID = v110;
    do
    {
      LODWORD(v112) = 2 * LODWORD(actionRange);
      if ( 2 * LODWORD(actionRange) < unobstructiblePlayerID
        && v16->MGP_openPaths[2 * LODWORD(actionRange)].total > v16->MGP_openPaths[2 * LODWORD(actionRange) + 1].total )
      {
        ++LODWORD(v112);
      }
      if ( unobstructibleGroupID < v16->MGP_openPaths[LODWORD(v112)].total )
        break;
      v113 = actionRange;
      v114 = *(_DWORD *)&v16->MGP_openPaths[LODWORD(v112)].x;
      actionRange = v112;
      *(_DWORD *)&v16->MGP_openPaths[LODWORD(v113)].x = v114;
      v16->MGP_openPaths[LODWORD(v113)].total = v16->MGP_openPaths[LODWORD(v112)].total;
      unobstructiblePlayerID = v16->numberOpenPathsValue;
    }
    while ( SLODWORD(v112) < unobstructiblePlayerID / 2 );
  }
  v115 = actionRange;
  if ( LODWORD(actionRange) != 1 )
  {
    v116 = startX;
    v16->MGP_openPaths[LODWORD(actionRange)].x = startY;
    v117 = unobstructibleGroupID;
    v16->MGP_openPaths[LODWORD(v115)].y = v116;
    v16->MGP_openPaths[LODWORD(v115)].total = v117;
  }
  v118 = 0;
  i = 0;
  SkipBit = 1;
  v251 = bestPathPoint_4 + 255 * v94;
  while ( 1 )
  {
    switch ( v118 )
    {
      case 0:
        v103 -= stepSize;
        temp = v103;
        temp_4 -= stepSize;
        break;
      case 1:
      case 2:
        v103 += stepSize;
        temp = v103;
        break;
      case 3:
        v119 = stepSize + temp_4;
        goto LABEL_126;
      case 4:
        temp_4 += stepSize;
        break;
      case 5:
      case 6:
        v103 -= stepSize;
        temp = v103;
        break;
      case 7:
        v119 = temp_4 - stepSize;
LABEL_126:
        temp_4 = v119;
        break;
      default:
        break;
    }
    if ( (v16->facetValue[0][v251] & 0xF8) == v16->CurrentFacetMask )
      v120 = v16->facetValue[0][v251] & 7;
    else
      v120 = 8;
    if ( SkipBit & (unsigned int)(&FacetSkipMask)[v120]
      || v103 < 0
      || temp_4 < 0
      || v103 >= v16->xSizeValue
      || temp_4 >= v16->ySizeValue
      || v103 == v16->initialTile.x && temp_4 == v16->initialTile.y )
    {
      goto LABEL_274;
    }
    startY = (v103 - v94) * (v103 - v94);
    v121 = (double)startY;
    startY = (temp_4 - bestPathPoint_4) * (temp_4 - bestPathPoint_4);
    startX = (signed __int64)(sqrt(v121 + (double)startY) * 16.0);
    startY = v16->MGP_costValue[0][v251];
    v122 = goalX;
    v123 = goalY;
    v124 = bestPathPoint;
    v125 = bestPathPoint_4;
    if ( goalX < bestPathPoint )
    {
      v122 = bestPathPoint;
      v124 = goalX;
    }
    if ( goalY < bestPathPoint_4 )
    {
      v123 = bestPathPoint_4;
      v125 = goalY;
    }
    v126 = v122 - v124;
    v127 = v123 - v125;
    if ( v126 < v127 )
    {
      v128 = v127 - v126;
    }
    else
    {
      v129 = v126 - v127;
      LOBYTE(v126) = v127;
      v128 = v129;
    }
    v244 = &(&DiagionalDistance)[(unsigned __int8)v126][4 * v128];
    v130 = goalX;
    v131 = goalY;
    v132 = temp;
    v133 = temp_4;
    if ( goalX < temp )
    {
      v130 = temp;
      v132 = goalX;
    }
    if ( goalY < temp_4 )
    {
      v131 = temp_4;
      v133 = goalY;
    }
    v134 = v130 - v132;
    v135 = v131 - v133;
    if ( v134 < v135 )
    {
      v136 = v135 - v134;
    }
    else
    {
      v137 = v134 - v135;
      LOBYTE(v134) = v135;
      v136 = v137;
    }
    v138 = &(&DiagionalDistance)[(unsigned __int8)v134][4 * v136];
    v139 = temp_4;
    v140 = startX + startY + (char *)v138 - (char *)v244;
    v141 = temp;
    newTotal = startX + startY + (char *)v138 - (char *)v244;
    v247 = temp_4 + 255 * temp;
    v240 = (char *)v16->facetValue + v247;
    LOBYTE(startY) = *v240;
    v142 = (startY & 0xF8) == v16->CurrentFacetMask ? startY & 7 : -1;
    if ( v142 >= 8u || v16->MGP_costValue[0][v247] > v140 )
      break;
LABEL_273:
    v118 = i;
    v103 = temp;
LABEL_274:
    i = ++v118;
    SkipBit *= 2;
    if ( v118 >= 8 )
    {
      v192 = v16->numberOpenPathsValue;
      v16->startOfPath = 0;
      ++iterations;
      if ( v192 > 0 )
        goto LABEL_90;
      goto LABEL_350;
    }
  }
  switch ( i )
  {
    case 0:
      v143 = temp + xDeltaLeft;
      v139 = yDeltaUp + temp_4;
      v141 = v94 + xDeltaRight;
      unobstructiblePlayerID = bestPathPoint_4 + yDeltaDown;
      v144 = temp_4;
      startX = cTargetID + 4 * temp;
      v145 = checkTerrainFirstTime;
      goto LABEL_167;
    case 1:
      v139 = yDeltaUp + temp_4;
      v143 = v94 + xDeltaLeft;
      v141 = v94 + xDeltaRight;
      unobstructiblePlayerID = bestPathPoint_4 + yDeltaDown;
      v144 = temp_4;
      startX = cTargetID + 4 * bestPathPoint;
      v145 = checkTerrainFirstTime;
      goto LABEL_167;
    case 2:
      v143 = v94 + xDeltaLeft;
      v139 = yDeltaUp + temp_4;
      v141 = xDeltaRight + temp;
      unobstructiblePlayerID = bestPathPoint_4 + yDeltaDown;
      v146 = temp_4;
      startX = cTargetID + 4 * bestPathPoint;
      v147 = checkTerrainFirstTime;
      goto LABEL_161;
    case 3:
      v143 = xDeltaLeft + v94;
      v139 = bestPathPoint_4 + yDeltaUp;
      v141 = xDeltaRight + temp;
      unobstructiblePlayerID = bestPathPoint_4 + yDeltaDown;
      v146 = bestPathPoint_4;
      startX = cTargetID + 4 * bestPathPoint;
      v147 = checkTerrainFirstTime;
LABEL_161:
      LODWORD(actionRange) = v147 + 4 * v146;
      v148 = bestPathPoint_4;
      startY = xDeltaRight4 + 4 * temp;
      v149 = yDeltaDown4;
      break;
    case 4:
      v143 = v94 + xDeltaLeft;
      v139 = bestPathPoint_4 + yDeltaUp;
      v141 = xDeltaRight + temp;
      unobstructiblePlayerID = temp_4 + yDeltaDown;
      v150 = bestPathPoint_4;
      startX = cTargetID + 4 * bestPathPoint;
      v151 = checkTerrainFirstTime;
      goto LABEL_169;
    case 5:
      v143 = xDeltaLeft + v94;
      v139 = bestPathPoint_4 + yDeltaUp;
      v141 = v94 + xDeltaRight;
      v152 = bestPathPoint;
      unobstructiblePlayerID = temp_4 + yDeltaDown;
      v153 = cTargetID;
      goto LABEL_165;
    case 6:
      v143 = temp + xDeltaLeft;
      v139 = bestPathPoint_4 + yDeltaUp;
      v141 = v94 + xDeltaRight;
      v152 = temp;
      unobstructiblePlayerID = temp_4 + yDeltaDown;
      v153 = cTargetID;
LABEL_165:
      startX = v153 + 4 * v152;
      v154 = bestPathPoint;
      LODWORD(actionRange) = checkTerrainFirstTime + 4 * bestPathPoint_4;
      v155 = xDeltaRight4;
      goto LABEL_170;
    case 7:
      v143 = temp + xDeltaLeft;
      v139 = bestPathPoint_4 + yDeltaUp;
      v141 = v94 + xDeltaRight;
      unobstructiblePlayerID = bestPathPoint_4 + yDeltaDown;
      v144 = bestPathPoint_4;
      startX = cTargetID + 4 * temp;
      v145 = checkTerrainFirstTime;
LABEL_167:
      LODWORD(actionRange) = v145 + 4 * v144;
      v148 = bestPathPoint_4;
      startY = xDeltaRight4 + 4 * bestPathPoint;
      v149 = yDeltaDown4;
      break;
    default:
      v143 = temp;
      unobstructiblePlayerID = temp_4;
      v150 = temp_4;
      startX = cTargetID + 4 * temp;
      v151 = checkTerrainFirstTime;
LABEL_169:
      LODWORD(v156) = v151 + 4 * v150;
      v154 = temp;
      actionRange = v156;
      v155 = xDeltaRight4;
LABEL_170:
      v157 = v155 + 4 * v154;
      v148 = temp_4;
      startY = v157;
      v149 = yDeltaDown4;
      break;
  }
  unobstructibleGroupID = v149 + 4 * v148;
  if ( v143 < 0 )
    LOBYTE(v143) = v143 + 1;
  if ( v139 < 0 )
    LOBYTE(v139) = v139 + 1;
  startX += startX < 0 ? 1 : 0;
  LODWORD(actionRange) += SLODWORD(actionRange) < 0 ? 1 : 0;
  v158 = v16->mapValue;
  if ( v141 >= v158->map_width || (unsigned __int8)unobstructiblePlayerID >= v158->map_height )
  {
LABEL_193:
    v256 = -2;
  }
  else
  {
    v252 = v139;
    if ( (unsigned __int8)v139 <= (unsigned __int8)unobstructiblePlayerID )
    {
      v243 = v158->map_row_offset;
      do
      {
        v159 = v252;
        v253 = v143;
        v160 = (int)&v243[v252][(unsigned __int8)v143].screen_xpos;
        if ( (unsigned __int8)v143 <= v141 )
        {
          v161 = (_BYTE *)(v160 + 6);
          v248 = v160 + 6;
          while ( 1 )
          {
            if ( v16->initialTile.x != v253 || v16->initialTile.y != v159 )
            {
              v162 = v16->currentTerrainTable;
              v242 = *(v161 - 1) & 0x1F;
              if ( v242 != v16->currentTerrainException1 && v242 != v16->currentTerrainException2 && v162[v242] <= 0.0 )
              {
                if ( !(*v161 & 0xF) || v162[v16->mapValue->border_types[*v161 & 0xF].underlay_terrain] <= 0.0 )
                  goto LABEL_193;
                v161 = (_BYTE *)v248;
              }
            }
            v161 += 24;
            v248 = (int)v161;
            if ( ++v253 > v141 )
              break;
            v159 = v252;
          }
        }
        ++v252;
      }
      while ( v252 <= (unsigned __int8)unobstructiblePlayerID );
    }
    v256 = 1;
  }
  v163 = (unsigned __int8)v256;
  unobstructiblePlayerID = (unsigned __int8)v256;
  if ( v256 == 1 && checkCollisions == (unsigned __int8)v256 )
  {
    v164 = unobstructibleGroupID;
    v165 = actionRange;
    *(float *)&unobstructiblePlayerID = 0.0;
    v166 = unobstructibleGroupID - LODWORD(actionRange) - 1;
    if ( v166 < 0 )
    {
      v163 = 1;
LABEL_232:
      unobstructiblePlayerID = v163;
      goto LABEL_233;
    }
    v167 = startX;
    if ( v166 >= 24
      || startX <= v16->maxTarget.x
      && SLODWORD(actionRange) <= v16->maxTarget.y
      && startY >= v16->minTarget.x
      && unobstructibleGroupID >= v16->minTarget.y )
    {
      v174 = startX;
      if ( startX < startY )
      {
        startX *= 255;
        do
        {
          v175 = LODWORD(v165);
          if ( SLODWORD(v165) < v164 )
          {
            do
            {
              if ( ((unsigned __int8)*(&v16->obstructionValue[0][v175 >> 2] + startX) >> LOBYTE((&ObstructionValueShift)[v175 & 3])) & 3 )
              {
                if ( v16->currentTargetID == -1
                  || v16->minTarget.x > v174
                  || v174 > v16->maxTarget.x
                  || v16->minTarget.y > v175
                  || v175 > v16->maxTarget.y )
                {
                  goto LABEL_230;
                }
                unobstructiblePlayerID = 1;
              }
              v164 = unobstructibleGroupID;
              ++v175;
            }
            while ( v175 < unobstructibleGroupID );
            v165 = actionRange;
          }
          ++v174;
          startX += 255;
        }
        while ( v174 < startY );
      }
      v163 = unobstructiblePlayerID != 1;
      goto LABEL_232;
    }
    v168 = 2 * ((LOBYTE(actionRange) & 3) + 4 * v166);
    v169 = (int)(&ObstructionMasks)[v168];
    v170 = dword_584F24[v168];
    startX = v169;
    if ( !v170 )
    {
      if ( v167 < startY )
      {
        v171 = &v16->obstructionValue[v167][SLODWORD(actionRange) >> 2];
        while ( !(v169 & *(_DWORD *)v171) )
        {
          ++v167;
          v171 += 255;
          if ( v167 >= startY )
            goto LABEL_208;
        }
LABEL_230:
        v163 = 254;
        goto LABEL_232;
      }
LABEL_208:
      unobstructiblePlayerID = 1;
      v163 = 1;
      goto LABEL_233;
    }
    v172 = v167;
    if ( v167 >= startY )
      goto LABEL_208;
    v173 = (int)&v16->obstructionValue[v167][SLODWORD(actionRange) >> 2];
    while ( !(startX & *(_DWORD *)v173) && !(v170 & *(_DWORD *)(v173 + 4)) )
    {
      ++v172;
      v173 += 255;
      if ( v172 >= startY )
      {
        unobstructiblePlayerID = 1;
        v163 = 1;
        goto LABEL_233;
      }
    }
    unobstructiblePlayerID = 254;
    v163 = 254;
  }
LABEL_233:
  actionRange = 0.0;
  unobstructibleObjectHitpoints = 0.0;
  if ( v163 == 254 )
  {
    if ( v16->currentUnobstructibleGroupID == -1 )
      goto LABEL_272;
    v176 = temp - 1;
    if ( temp - 1 < 0 )
      v176 = 0;
    v177 = 0;
    for ( startY = 0; v176 <= temp + 1; ++v176 )
    {
      if ( v176 >= v16->xSizeValue || v177 )
        break;
      v178 = temp_4 - 1;
      if ( temp_4 - 1 < 0 )
        v178 = 0;
      for ( unobstructibleGroupID = temp_4 + 1; v178 <= unobstructibleGroupID; ++v178 )
      {
        if ( v178 >= v16->ySizeValue || v177 )
          break;
        v179 = v16->currentUnobstructiblePlayerID;
        *(float *)&startX = 0.0;
        v180 = RGE_Game_World::objectGroupOnTile(
                 v16->worldValue,
                 v179,
                 v16->currentUnobstructibleGroupID,
                 v176,
                 v178,
                 &startX);
        if ( v180 == -1 )
        {
          if ( startX > 0 )
            startY = 1;
        }
        else
        {
          v181 = RGE_Game_World::object(v16->worldValue, v180);
          if ( v181 )
          {
            v182 = v181->hp;
            LODWORD(actionRange) = 1;
            unobstructibleObjectHitpoints = v182;
          }
        }
        v177 = startY;
      }
    }
    if ( v177 == 1 )
      goto LABEL_272;
    v163 = unobstructiblePlayerID;
  }
  v183 = 16 * v16->miscValue[0][v247] + newTotal;
  if ( LODWORD(actionRange) == 1 )
  {
    if ( unobstructibleObjectHitpoints < 10.0 )
      v183 += 16;
    else
      v183 += 60;
  }
  if ( (v16->facetValue[0][v251] & 0xF8) == v16->CurrentFacetMask )
    v245 = v16->facetValue[0][v251] & 7;
  else
    v245 = -1;
  if ( i != (unsigned __int8)v245 )
    ++v183;
  if ( *(float *)&v163 == 0.0 )
    v183 = 0;
  v16->MGP_costValue[0][v247] = v183;
  *v240 = v16->CurrentFacetMask | i & 7;
  v184 = v16->numberOpenPathsValue + 1;
  v16->numberOpenPathsValue = v184;
  v16->MGP_openPaths[v184].x = temp;
  v16->MGP_openPaths[v16->numberOpenPathsValue].y = temp_4;
  v16->MGP_openPaths[v16->numberOpenPathsValue].total = v183;
  v185 = v16->numberOpenPathsValue;
  v186 = v16->numberOpenPathsValue;
  if ( v185 >= 1 )
  {
    v187 = v16->MGP_openPaths[v185].y;
    v188 = v185 / 2;
    LOBYTE(startY) = v16->MGP_openPaths[v185].x;
    LOBYTE(startX) = v187;
    v189 = v16->MGP_openPaths[v185 / 2].total;
    actionRange = *(float *)&v16->MGP_openPaths[v185].total;
    if ( SLODWORD(actionRange) < v189 )
    {
      do
      {
        *(_DWORD *)&v16->MGP_openPaths[v186].x = *(_DWORD *)&v16->MGP_openPaths[v188].x;
        v16->MGP_openPaths[v186].total = v16->MGP_openPaths[v188].total;
        v186 /= 2;
        v188 /= 2;
      }
      while ( SLODWORD(actionRange) < v16->MGP_openPaths[v188].total );
    }
    if ( v186 != v185 )
    {
      v190 = startX;
      v191 = actionRange;
      v16->MGP_openPaths[v186].x = startY;
      v16->MGP_openPaths[v186].y = v190;
      *(float *)&v16->MGP_openPaths[v186].total = v191;
    }
  }
  if ( *(float *)&unobstructiblePlayerID != 0.0 )
  {
LABEL_272:
    v94 = bestPathPoint;
    goto LABEL_273;
  }
  if ( copyPathWhenDone == 1 && !PathingSystem::copyPath(v16, stepSize) )
  {
    v204 = (char *)&unit->pathValue;
    if ( unit->storePathInExceptionPath )
      v204 = (char *)&unit->exceptionPathValue;
    Path::killPath((Path *)v204);
    v205 = v16->currentObject;
    v206 = 0;
    for ( stepSize = 0; v206 < v205->pathingGroupMembers.numberValue; stepSize = v206 )
    {
      if ( v206 > v205->pathingGroupMembers.maximumSizeValue - 1 )
      {
        v207 = operator new(4 * v206 + 4);
        goalY = (int)v207;
        if ( v207 )
        {
          for ( k = 0; k < v205->pathingGroupMembers.maximumSizeValue; ++k )
          {
            if ( k >= v206 + 1 )
              break;
            v206 = stepSize;
            v207[k] = v205->pathingGroupMembers.value[k];
          }
          operator delete(v205->pathingGroupMembers.value);
          v205->pathingGroupMembers.value = (int *)goalY;
          v205->pathingGroupMembers.maximumSizeValue = v206 + 1;
        }
      }
      v209 = RGE_Game_World::object(v16->worldValue, v205->pathingGroupMembers.value[v206]);
      if ( v209 && v209->id != v16->currentObject->id && v209->lastInObstructionMapValue == 1 && !v209->inside_obj )
        RGE_Static_Object::addToObstructionMap(v209, v16->aiPS);
      v205 = v16->currentObject;
      ++v206;
    }
    goto LABEL_390;
  }
  if ( pathLength )
    *pathLength = (double)v16->MGP_costValue[0][bestPathPoint_4 + 255 * bestPathPoint];
  v210 = v16->currentObject;
  v211 = 0;
  for ( stepSize = 0; v211 < v210->pathingGroupMembers.numberValue; stepSize = v211 )
  {
    if ( v211 > v210->pathingGroupMembers.maximumSizeValue - 1 )
    {
      v212 = operator new(4 * v211 + 4);
      goalY = (int)v212;
      if ( v212 )
      {
        for ( l = 0; l < v210->pathingGroupMembers.maximumSizeValue; ++l )
        {
          if ( l >= v211 + 1 )
            break;
          v211 = stepSize;
          v212[l] = v210->pathingGroupMembers.value[l];
        }
        operator delete(v210->pathingGroupMembers.value);
        v210->pathingGroupMembers.value = (int *)goalY;
        v210->pathingGroupMembers.maximumSizeValue = v211 + 1;
      }
    }
    v214 = RGE_Game_World::object(v16->worldValue, v210->pathingGroupMembers.value[v211]);
    if ( v214 && v214->id != v16->currentObject->id && v214->lastInObstructionMapValue == 1 && !v214->inside_obj )
      RGE_Static_Object::addToObstructionMap(v214, v16->aiPS);
    v210 = v16->currentObject;
    ++v211;
  }
LABEL_346:
  if ( v16->currentObjectInObMap == 1 )
  {
    v215 = (RGE_Static_Object *)&v16->currentObject->vfptr;
    if ( !v215->inside_obj )
      RGE_Static_Object::addToObstructionMap(v215, v16->aiPS);
  }
  return 1;
}
// 57F9F4: using guessed type int numberPathingIterations;
// 584EF4: using guessed type unsigned __int8 *ObstructionValueShift;
// 584EF8: using guessed type int *FacetSkipMask;
// 584F20: using guessed type unsigned __int32 *ObstructionMasks;
// 584F24: using guessed type int dword_584F24[];
// 74D040: using guessed type int *DiagionalDistance;
// 86B138: using guessed type int MapPathsDisplay;

//----- (0046D250) --------------------------------------------------------
void __thiscall PathingSystem::incrementInitialPaths(PathingSystem *this)
{
  ++this->numInitialPathsValue;
}

//----- (0046D260) --------------------------------------------------------
void __thiscall PathingSystem::incrementContinuePaths(PathingSystem *this)
{
  ++this->numContinuePathsValue;
}

//----- (0046D270) --------------------------------------------------------
void __thiscall PathingSystem::incrementCanPaths(PathingSystem *this)
{
  ++this->numCanPathsValue;
}

//----- (0046D280) --------------------------------------------------------
int __thiscall PathingSystem::passable(PathingSystem *this, RGE_Moving_Object *obj, float newX, float newY, int checkTerrain)
{
  PathingSystem *v5; // esi@1
  RGE_Game_World *v6; // eax@1
  int v7; // ST20_4@1
  double v8; // st7@1
  RGE_Master_Static_Object *v9; // eax@1
  double v10; // st7@1
  double v11; // st6@1
  float v12; // ST1C_4@1
  int v13; // edi@1
  signed __int64 v14; // rax@1
  signed int v15; // ebp@1
  int v16; // ebx@1
  signed int v17; // ebx@1
  signed int v18; // edi@3
  int v19; // edx@6
  signed int v20; // eax@6
  RGE_Map *v21; // edi@6
  signed int v22; // ecx@6
  signed int v23; // eax@6
  signed int v24; // ebx@6
  int i; // ecx@9
  _BYTE *v26; // edx@12
  float *v27; // ecx@15
  int v28; // ecx@27
  int v29; // eax@33
  signed int v30; // edi@33
  int v31; // ecx@33
  int v32; // eax@33
  unsigned __int32 *v33; // ebx@33
  int v34; // ecx@34
  char *v35; // edx@35
  int v36; // edx@39
  int v37; // ecx@40
  int v38; // eax@46
  signed int v39; // edx@47
  int minY; // [sp+18h] [bp-20h]@1
  unsigned __int8 yRadius; // [sp+1Ch] [bp-1Ch]@8
  int maxY; // [sp+20h] [bp-18h]@1
  unsigned __int8 v44; // [sp+24h] [bp-14h]@11
  unsigned __int8 v45; // [sp+28h] [bp-10h]@6
  unsigned __int8 inObMap; // [sp+2Ch] [bp-Ch]@6
  int inObMapa; // [sp+2Ch] [bp-Ch]@27
  unsigned __int8 v48; // [sp+34h] [bp-4h]@15
  float newXa; // [sp+40h] [bp+8h]@1
  float newXb; // [sp+40h] [bp+8h]@33
  int minX; // [sp+44h] [bp+Ch]@1
  int maxX; // [sp+48h] [bp+10h]@27

  v5 = this;
  v6 = this->worldValue;
  this->currentObject = obj;
  this->currentTerrainTable = v6->terrains[obj->master_obj->terrain];
  this->initialTile.x = -1;
  this->initialTile.y = -1;
  this->minInitialPosition.x = -1;
  this->minInitialPosition.y = -1;
  this->maxInitialPosition.x = -1;
  this->maxInitialPosition.y = -1;
  *(float *)&v7 = newX - floor(newX);
  v8 = floor(newY);
  v9 = obj->master_obj;
  v10 = newY - v8;
  v11 = v9->radius_x;
  v12 = v9->radius_y;
  v13 = 4 * (unsigned __int64)(signed __int64)newX;
  v14 = (signed __int64)((*(float *)&v7 - -100.0 - v11) * -4.0);
  v15 = v13 - v14 - 400;
  LODWORD(newXa) = v13 - v14 - 400;
  v16 = 4 * (unsigned __int64)(signed __int64)newY;
  minY = v16 - (unsigned __int64)(signed __int64)((v10 - -100.0 - v12) * -4.0) - 400;
  minX = v13 - (unsigned __int64)(signed __int64)((v11 + *(float *)&v7 - -100.0) * -4.0) - 400;
  v17 = v16 - (unsigned __int64)(signed __int64)((v12 + v10 - -100.0) * -4.0) - 400;
  maxY = v17;
  if ( v15 < 0 )
  {
    ++v15;
    newXa = *(float *)&v15;
  }
  v18 = minY;
  if ( minY < 0 )
    v18 = minY++ + 1;
  if ( checkTerrain )
  {
    v19 = minX >> 2;
    v20 = v18;
    v21 = v5->mapValue;
    v22 = v17 >> 2;
    v23 = v20 >> 2;
    v24 = v15 >> 2;
    inObMap = v22;
    v45 = v15 >> 2;
    if ( (unsigned __int8)(minX >> 2) >= v21->map_width || (unsigned __int8)v22 >= v21->map_height )
      return 0;
    yRadius = v23;
    if ( (unsigned __int8)v23 > (unsigned __int8)v22 )
    {
      v15 = LODWORD(newXa);
    }
    else
    {
      v15 = LODWORD(newXa);
      for ( i = v45; ; i = v45 )
      {
        v44 = v24;
        if ( (unsigned __int8)v24 <= (unsigned __int8)v19 )
        {
          v26 = (char *)&v5->mapValue->map_row_offset[yRadius][i] + 6;
          do
          {
            if ( v5->initialTile.x != v44 || v5->initialTile.y != yRadius )
            {
              v48 = *(v26 - 1) & 0x1F;
              v27 = v5->currentTerrainTable;
              if ( v48 != v5->currentTerrainException1 && v48 != v5->currentTerrainException2 && v27[v48] <= 0.0 )
              {
                if ( !(*v26 & 0xF) || v27[v5->mapValue->border_types[*v26 & 0xF].underlay_terrain] <= 0.0 )
                  return 0;
                v15 = LODWORD(newXa);
              }
            }
            v26 += 24;
            LOBYTE(v24) = v24 + 1;
            v44 = v24;
          }
          while ( (unsigned __int8)v24 <= (unsigned __int8)(minX >> 2) );
          LOBYTE(v24) = v45;
          LOBYTE(v19) = minX >> 2;
        }
        if ( ++yRadius > inObMap )
          break;
      }
    }
    v17 = maxY;
    v18 = minY;
  }
  inObMapa = RGE_Static_Object::removeFromObstructionMap((RGE_Static_Object *)&obj->vfptr, v5->aiPS);
  maxX = 0;
  v28 = v17 - v18 - 1;
  if ( v28 >= 0 )
  {
    if ( v28 >= 24
      || v15 <= v5->maxTarget.x && v18 <= v5->maxTarget.y && minX >= v5->minTarget.x && v17 >= v5->minTarget.y )
    {
      if ( v15 < minX )
      {
        v38 = 255 * v15;
        do
        {
          v39 = v18;
          if ( v18 < v17 )
          {
            do
            {
              if ( ((unsigned __int8)*(&v5->obstructionValue[0][v39 >> 2] + v38) >> LOBYTE((&ObstructionValueShift)[v39 & 3])) & 3 )
              {
                if ( v5->currentTargetID == -1
                  || v5->minTarget.x > v15
                  || v15 > v5->maxTarget.x
                  || v5->minTarget.y > v39
                  || v39 > v5->maxTarget.y )
                {
                  goto LABEL_58;
                }
                maxX = 1;
              }
              v17 = maxY;
              ++v39;
            }
            while ( v39 < maxY );
          }
          ++v15;
          v38 += 255;
        }
        while ( v15 < minX );
      }
      if ( maxX == 1 )
        goto LABEL_58;
    }
    else
    {
      v29 = v18 & 3;
      v30 = v18 >> 2;
      v31 = 2 * (v29 + 4 * v28);
      v32 = dword_584F24[v31];
      v33 = (&ObstructionMasks)[v31];
      newXb = *(float *)&(&ObstructionMasks)[v31];
      if ( v32 )
      {
        v36 = v15;
        if ( v15 < minX )
        {
          v37 = (int)&v5->obstructionValue[v15][v30];
          while ( !(LODWORD(newXb) & *(_DWORD *)v37) && !(v32 & *(_DWORD *)(v37 + 4)) )
          {
            ++v36;
            v37 += 255;
            if ( v36 >= minX )
              goto LABEL_62;
          }
          goto LABEL_58;
        }
      }
      else
      {
        v34 = v15;
        if ( v15 < minX )
        {
          v35 = &v5->obstructionValue[v15][v30];
          while ( !((unsigned int)v33 & *(_DWORD *)v35) )
          {
            ++v34;
            v35 += 255;
            if ( v34 >= minX )
              goto LABEL_62;
          }
LABEL_58:
          if ( inObMapa && !obj->inside_obj )
            RGE_Static_Object::addToObstructionMap((RGE_Static_Object *)&obj->vfptr, v5->aiPS);
          return 0;
        }
      }
    }
  }
LABEL_62:
  if ( inObMapa )
  {
    if ( !obj->inside_obj )
      RGE_Static_Object::addToObstructionMap((RGE_Static_Object *)&obj->vfptr, v5->aiPS);
  }
  return 1;
}
// 584EF4: using guessed type unsigned __int8 *ObstructionValueShift;
// 584F20: using guessed type unsigned __int32 *ObstructionMasks;
// 584F24: using guessed type int dword_584F24[];

//----- (0046D740) --------------------------------------------------------
int __thiscall PathingSystem::checksum(PathingSystem *this)
{
  int v1; // esi@1
  char *v2; // edx@1
  signed int v3; // edi@1
  signed int v4; // ecx@2

  v1 = 0;
  v2 = (char *)this->obstructionValue;
  v3 = 1020;
  do
  {
    v4 = 0;
    do
      v1 ^= (unsigned __int8)v2[v4++];
    while ( v4 < 255 );
    v2 += 255;
    --v3;
  }
  while ( v3 );
  return v1;
}

//----- (0046D770) --------------------------------------------------------
void __thiscall PathingSystem::printState(PathingSystem *this, RGE_Moving_Object *unit)
{
  PathingSystem *v2; // ebp@1
  void (*v3)(RGE_Static_Object *, char *, ...); // edi@1
  signed int v4; // edi@1
  int v5; // esi@2
  int v6; // ecx@3
  char v7; // dl@3
  char v8; // [sp+Ch] [bp-8h]@4
  void (*v9)(RGE_Static_Object *, char *, ...); // [sp+10h] [bp-4h]@1

  v2 = this;
  v3 = unit->vfptr->logDebug;
  v9 = v3;
  v3((RGE_Static_Object *)&unit->vfptr, aThereAreDOpenP, this->numberOpenPathsValue, this->numberTraversedPathsValue);
  ((void (__cdecl *)(RGE_Moving_Object *, char *))v3)(unit, aTheOpenPaths);
  v4 = 1;
  if ( v2->numberOpenPathsValue >= 1 )
  {
    v5 = (int)&v2->MGP_openPaths[1].y;
    do
    {
      v6 = *(_BYTE *)v5;
      v7 = v2->facetValue[*(_BYTE *)(v5 - 1)][v6];
      if ( (v7 & 0xF8) == v2->CurrentFacetMask )
        v8 = v7 & 7;
      else
        v8 = -1;
      v9(
        (RGE_Static_Object *)&unit->vfptr,
        a5dDDTotalDFace,
        v4++,
        *(_BYTE *)(v5 - 1),
        v6,
        *(_DWORD *)(v5 + 3),
        (unsigned __int8)v8);
      v5 += 8;
    }
    while ( v4 <= v2->numberOpenPathsValue );
  }
}

//----- (0046D830) --------------------------------------------------------
int __thiscall PathingSystem::copyPath(PathingSystem *this, int stepSize)
{
  PathingSystem *v2; // esi@1
  RGE_Moving_Object *v3; // eax@1
  Path *v4; // ecx@1
  char v5; // cl@3
  int v6; // edi@3
  int v7; // ebp@3
  char v8; // bl@3
  char v9; // al@3
  RGE_Moving_Object *v10; // eax@6
  double v11; // st7@6
  float v12; // edx@6
  Path *v13; // ecx@6
  RGE_Moving_Object *v14; // eax@12
  int v15; // eax@17
  int v16; // edi@17
  int v17; // ecx@19
  int v18; // edx@21
  int v19; // ebp@21
  int v20; // ecx@23
  int v21; // edi@26
  int v22; // ecx@27
  int v23; // ebx@27
  int v24; // ecx@28
  int i; // eax@28
  int v26; // ebp@33
  int *v27; // edi@33
  int j; // eax@34
  char v29; // al@50
  double v30; // st7@53
  RGE_Moving_Object *v31; // esi@54
  int result; // eax@55
  char currentFacet; // [sp+10h] [bp-34h]@4
  int tWY2; // [sp+14h] [bp-30h]@21
  int tWX2; // [sp+18h] [bp-2Ch]@17
  int tWY1; // [sp+1Ch] [bp-28h]@21
  int fooX; // [sp+20h] [bp-24h]@25
  int fooY; // [sp+24h] [bp-20h]@26
  int objectCountOnTile; // [sp+28h] [bp-1Ch]@27
  PathingSystem::BYTEPoint temp; // [sp+2Ch] [bp-18h]@3
  Waypoint wp; // [sp+34h] [bp-10h]@6

  v2 = this;
  v3 = this->currentObject;
  v4 = &v3->pathValue;
  if ( v3->storePathInExceptionPath )
    v4 = &v3->exceptionPathValue;
  Path::killPath(v4);
  v5 = v2->MGP_openPaths[1].y;
  temp.x = v2->MGP_openPaths[1].x;
  temp.y = v5;
  v6 = (unsigned __int8)temp.x;
  v7 = (unsigned __int8)v5;
  v8 = -1;
  v9 = v2->facetValue[(unsigned __int8)temp.x][(unsigned __int8)v5];
  if ( (v9 & 0xF8) == v2->CurrentFacetMask )
    currentFacet = v9 & 7;
  else
    currentFacet = -1;
  v10 = v2->currentObject;
  v11 = (double)(unsigned __int8)v5 + v2->currentYOffset;
  wp.x = (double)(unsigned __int8)temp.x + v2->currentXOffset;
  wp.y = v11;
  v12 = v10->world_z;
  wp.facetToNextWaypoint = currentFacet;
  wp.z = v12;
  v13 = &v10->pathValue;
  if ( v10->storePathInExceptionPath )
    v13 = &v10->exceptionPathValue;
  Path::initToStart(v13);
  while ( v2->initialTile.x != v6 || v2->initialTile.y != v7 )
  {
    if ( currentFacet != v8 )
    {
      v14 = v2->currentObject;
      if ( v14->storePathInExceptionPath )
      {
        if ( !Path::insertAtCurrent(&v14->exceptionPathValue, &wp) )
          return 0;
      }
      else if ( !Path::insertAtCurrent(&v14->pathValue, &wp) )
      {
        return 0;
      }
    }
    if ( v2->currentUnobstructibleGroupID != -1 )
    {
      v15 = v6 - 1;
      v16 = v6 + 1;
      tWX2 = v16;
      if ( v15 >= 0 )
      {
        v17 = v2->xSizeValue;
        if ( v16 >= v17 )
        {
          --v15;
          tWX2 = v17 - 1;
        }
      }
      else
      {
        v15 = 0;
        tWX2 = v16 + 1;
      }
      v18 = v7 - 1;
      v19 = v7 + 1;
      tWY1 = v18;
      tWY2 = v19;
      if ( v18 >= 0 )
      {
        v20 = v2->ySizeValue;
        if ( v19 >= v20 )
        {
          tWY1 = v18 - 1;
          tWY2 = v20 - 1;
        }
      }
      else
      {
        tWY1 = 0;
        tWY2 = v19 + 1;
      }
      for ( fooX = v15; fooX <= tWX2; ++fooX )
      {
        v21 = tWY1;
        for ( fooY = tWY1; v21 <= tWY2; fooY = v21 )
        {
          v22 = v2->currentUnobstructibleGroupID;
          objectCountOnTile = 0;
          v23 = RGE_Game_World::objectGroupOnTile(
                  v2->worldValue,
                  v2->currentUnobstructiblePlayerID,
                  v22,
                  fooX,
                  v21,
                  &objectCountOnTile);
          if ( v23 != -1 )
          {
            v24 = v2->currentUnobstructibles.numberValue;
            for ( i = 0; i < v24; ++i )
            {
              if ( i >= v2->currentUnobstructibles.maximumSizeValue )
                break;
              if ( v2->currentUnobstructibles.value[i] == v23 )
                goto LABEL_39;
            }
            if ( v24 > v2->currentUnobstructibles.maximumSizeValue - 1 )
            {
              v26 = v24 + 1;
              v27 = (int *)operator new(4 * (v24 + 1));
              if ( v27 )
              {
                for ( j = 0;
                      j < v2->currentUnobstructibles.maximumSizeValue;
                      v27[j - 1] = v2->currentUnobstructibles.value[j - 1] )
                {
                  if ( j >= v26 )
                    break;
                  ++j;
                }
                operator delete(v2->currentUnobstructibles.value);
                v2->currentUnobstructibles.value = v27;
                v2->currentUnobstructibles.maximumSizeValue = v26;
              }
            }
            v21 = fooY;
            v2->currentUnobstructibles.value[v2->currentUnobstructibles.numberValue++] = v23;
          }
LABEL_39:
          ++v21;
        }
      }
    }
    switch ( currentFacet )
    {
      case 0:
        temp.x += stepSize;
        temp.y += stepSize;
        break;
      case 1:
        temp.y += stepSize;
        break;
      case 2:
        temp.x -= stepSize;
        temp.y += stepSize;
        break;
      case 3:
        temp.x -= stepSize;
        break;
      case 4:
        temp.x -= stepSize;
        temp.y -= stepSize;
        break;
      case 5:
        temp.y -= stepSize;
        break;
      case 6:
        temp.x += stepSize;
        temp.y -= stepSize;
        break;
      case 7:
        temp.x += stepSize;
        break;
      default:
        break;
    }
    v6 = (unsigned __int8)temp.x;
    v7 = (unsigned __int8)temp.y;
    v8 = currentFacet;
    v29 = v2->facetValue[(unsigned __int8)temp.x][(unsigned __int8)temp.y];
    if ( (v29 & 0xF8) == v2->CurrentFacetMask )
      currentFacet = v29 & 7;
    else
      currentFacet = -1;
    wp.facetToNextWaypoint = currentFacet;
    v30 = (double)(unsigned __int8)temp.y + v2->currentYOffset;
    wp.x = (double)(unsigned __int8)temp.x + v2->currentXOffset;
    wp.y = v30;
  }
  v31 = v2->currentObject;
  if ( !v31->storePathInExceptionPath )
  {
    result = Path::insertAtCurrent(&v31->pathValue, &wp);
    if ( !result )
      return result;
    return 1;
  }
  if ( Path::insertAtCurrent(&v31->exceptionPathValue, &wp) )
    return 1;
  return 0;
}

//----- (0046DCB0) --------------------------------------------------------
void __thiscall PathingSystem::copyUnobstructibles(PathingSystem *this, ManagedArray<int> *d)
{
  PathingSystem *v2; // ebx@1
  int v3; // edi@1
  ManagedArray<int> *v4; // esi@2
  int v5; // ebp@4
  int *v6; // edi@4
  int j; // eax@5
  int v8; // ecx@10
  ManagedArray<int> *v9; // edx@10
  int v10; // eax@10
  int v11; // ebp@15
  int *v12; // edi@15
  int k; // eax@16
  int i; // [sp+8h] [bp-4h]@1
  ManagedArray<int> *da; // [sp+10h] [bp+4h]@10

  v2 = this;
  v3 = this->currentUnobstructibles.numberValue;
  i = this->currentUnobstructibles.numberValue;
  if ( v3 >= 0 )
  {
    v4 = d;
    do
    {
      if ( v3 > v2->currentUnobstructibles.maximumSizeValue - 1 )
      {
        v5 = v3 + 1;
        v6 = (int *)operator new(4 * v3 + 4);
        if ( v6 )
        {
          for ( j = 0; j < v2->currentUnobstructibles.maximumSizeValue; v6[j - 1] = v2->currentUnobstructibles.value[j - 1] )
          {
            if ( j >= v5 )
              break;
            ++j;
          }
          operator delete(v2->currentUnobstructibles.value);
          v2->currentUnobstructibles.value = v6;
          v2->currentUnobstructibles.maximumSizeValue = v5;
        }
        v3 = i;
      }
      v8 = v4->numberValue;
      v9 = (ManagedArray<int> *)v2->currentUnobstructibles.value[v3];
      v10 = 0;
      for ( da = (ManagedArray<int> *)v2->currentUnobstructibles.value[v3]; v10 < v8; ++v10 )
      {
        if ( v10 >= v4->maximumSizeValue )
          break;
        if ( (ManagedArray<int> *)v4->value[v10] == v9 )
          goto LABEL_22;
      }
      if ( v8 > v4->maximumSizeValue - 1 )
      {
        v11 = v8 + 1;
        v12 = (int *)operator new(4 * (v8 + 1));
        if ( v12 )
        {
          for ( k = 0; k < v4->maximumSizeValue; v12[k - 1] = v4->value[k - 1] )
          {
            if ( k >= v11 )
              break;
            ++k;
          }
          operator delete(v4->value);
          v4->value = v12;
          v4->maximumSizeValue = v11;
        }
        v9 = da;
        v3 = i;
      }
      v4->value[v4->numberValue++] = (int)v9;
LABEL_22:
      i = --v3;
    }
    while ( v3 >= 0 );
  }
}
