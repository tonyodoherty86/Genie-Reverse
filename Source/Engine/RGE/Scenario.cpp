
//----- (0048AB10) --------------------------------------------------------
void __thiscall RGE_Scenario_Header::RGE_Scenario_Header(RGE_Scenario_Header *this, RGE_Scenario *scenario_info)
{
  RGE_Scenario_Header *v2; // ebp@1
  RGE_Scenario *v3; // ebx@2

  v2 = this;
  this->vfptr = (RGE_Scenario_HeaderVtbl *)&RGE_Scenario_Header::`vftable';
  this->error_code = 0;
  this->version = 2;
  this->checksum = time(0);
  if( RGE_Scenario::Get_description(scenario_info) )
  {
    v3 = (RGE_Scenario *)(strlen(RGE_Scenario::Get_description(scenario_info)) + 1);
    v2->description = (char *)malloc((size_t)v3);
  }
  else
  {
    v3 = scenario_info;
    v2->description = 0;
  }
  if( v2->description )
  {
    strcpy(v2->description, RGE_Scenario::Get_description(scenario_info));
    *((_BYTE *)v3 + (unsigned int)v2->description - 1) = 0;
  }
}
// 572120: using guessed type __int32 (__thiscall *RGE_Scenario_Header::`vftable')(RGE_Scenario_Header *__hidden this);

//----- (0048ABB0) --------------------------------------------------------
void __thiscall RGE_Scenario_Header::RGE_Scenario_Header(RGE_Scenario_Header *this, int infile)
{
  RGE_Scenario_Header *v2; // esi@1
  int v3; // ebx@1
  char *v4; // edi@1
  char *v5; // ebp@1
  char *v6; // eax@4
  int header_size; // [sp+10h] [bp-4h]@1

  v2 = this;
  v3 = infile;
  v4 = (char *)&this->version;
  v5 = (char *)&this->checksum;
  this->error_code = 0;
  this->version = 0;
  this->checksum = 0;
  this->description = 0;
  this->vfptr = (RGE_Scenario_HeaderVtbl *)&RGE_Scenario_Header::`vftable';
  rge_read_uncompressed(v3, &header_size, 4);
  rge_read_uncompressed(v3, v4, 4);
  if( *(_DWORD *)v4 >= 2 )
    rge_read_uncompressed(v3, v5, 4);
  rge_read_uncompressed(v3, &infile, 4);
  if( infile <= 0 )
  {
    v2->description = 0;
  }
  else
  {
    v6 = (char *)malloc(infile);
    v2->description = v6;
    if( v6 )
      rge_read_uncompressed(v3, v6, infile);
    else
      v2->error_code = 1;
  }
}
// 572120: using guessed type __int32 (__thiscall *RGE_Scenario_Header::`vftable')(RGE_Scenario_Header *__hidden this);

//----- (0048AC70) --------------------------------------------------------
void __thiscall RGE_Scenario_Header::~RGE_Scenario_Header(RGE_Scenario_Header *this)
{
  RGE_Scenario_Header *v1; // esi@1
  char *v2; // eax@1

  v1 = this;
  v2 = this->description;
  this->vfptr = (RGE_Scenario_HeaderVtbl *)&RGE_Scenario_Header::`vftable';
  if( v2 )
  {
    free(v2);
    v1->description = 0;
  }
}
// 572120: using guessed type __int32 (__thiscall *RGE_Scenario_Header::`vftable')(RGE_Scenario_Header *__hidden this);

//----- (0048ACA0) --------------------------------------------------------
unsigned int __thiscall RGE_Scenario_Header::get_size(RGE_Scenario_Header *this)
{
  char *v1; // edi@1
  unsigned int result; // eax@2

  v1 = this->description;
  if( v1 )
    result = strlen(v1) + 13;
  else
    result = 12;
  return result;
}

//----- (0048ACC0) --------------------------------------------------------
void __thiscall RGE_Scenario_Header::save(RGE_Scenario_Header *this, int outfile)
{
  RGE_Scenario_Header *v2; // esi@1
  const char *v3; // edi@3
  char *v4; // esi@6
  int desc_size; // [sp+Ch] [bp-8h]@4
  int header_size; // [sp+10h] [bp-4h]@1

  v2 = this;
  header_size = ((int (*)(void))this->vfptr->get_size)();
  rge_write_uncompressed(outfile, &header_size, 4);
  rge_write_uncompressed(outfile, &v2->version, 4);
  if( v2->version >= 2 )
    rge_write_uncompressed(outfile, &v2->checksum, 4);
  v3 = v2->description;
  if( v3 )
    desc_size = strlen(v3) + 1;
  else
    desc_size = 0;
  rge_write_uncompressed(outfile, &desc_size, 4);
  v4 = v2->description;
  if( v4 )
    rge_write_uncompressed(outfile, v4, desc_size);
}

//----- (0048AD60) --------------------------------------------------------
void __thiscall RGE_Scenario::RGE_Scenario(RGE_Scenario *this, RGE_Game_World *w)
{
  RGE_Scenario *v2; // esi@1
  RGE_Timeline *v3; // eax@1
  RGE_Timeline *v4; // eax@2

  v2 = this;
  this->vfptr = (RGE_ScenarioVtbl *)&RGE_Scenario::`vftable';
  this->world = w;
  v3 = (RGE_Timeline *)operator new(0x14u);
  if( v3 )
    RGE_Timeline::RGE_Timeline(v3, v2->world);
  else
    v4 = 0;
  v2->time_line = v4;
  RGE_Scenario::InitializeTextValues(v2);
  v2->mission_picture = 0;
  v2->victory_conquest = 1;
  memset(v2->player_name, 0, sizeof(v2->player_name));
}
// 572128: using guessed type struct RGE_Static_Object *(__thiscall *RGE_Scenario::`vftable')(RGE_Scenario *this, int);

//----- (0048ADF0) --------------------------------------------------------
RGE_Scenario *__thiscall RGE_Scenario::`vector deleting destructor'(RGE_Scenario *this, unsigned int __flags)
{
  RGE_Scenario *v2; // esi@1

  v2 = this;
  RGE_Scenario::~RGE_Scenario(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0048AE10) --------------------------------------------------------
void __userpurge RGE_Scenario::RGE_Scenario(RGE_Scenario *this@<ecx>, char *a2@<ebp>, int infile, RGE_Game_World *w)
{
  RGE_Scenario *v4; // ebx@1
  int v5; // edi@1
  RGE_Timeline *v6; // eax@10
  RGE_Timeline *v7; // eax@11
  __int16 v8; // ax@13
  char *v9; // eax@16
  int v10; // ecx@16
  char *v11; // eax@20
  int v12; // ecx@20
  char *v13; // eax@23
  int v14; // ecx@23
  char *v15; // eax@26
  int v16; // ecx@26
  char *v17; // eax@29
  int v18; // ecx@29
  __int16 v19; // ax@39
  __int16 v20; // ax@41
  __int16 v21; // ax@43
  __int16 v22; // ax@46
  TPicture *v23; // eax@50
  TPicture *v24; // eax@51
  void **v25; // edi@54
  int v26; // ebp@54
  __int16 v27; // ax@55
  _BYTE *v28; // ecx@57
  void **v29; // edi@58
  size_t *v30; // ebp@58
  __int16 v31; // ax@59
  int v32; // edx@61
  _BYTE *v33; // eax@61
  void **v34; // edi@63
  __int16 v35; // ax@64
  _BYTE *v36; // edx@66
  int v37; // edi@67
  void *v38; // eax@72
  void *v39; // eax@74
  signed int v40; // eax@75
  void *v41; // eax@76
  double v42; // st7@78
  __int16 length; // [sp+12h] [bp-F6h]@13
  char *v44; // [sp+14h] [bp-F4h]@10
  int val; // [sp+18h] [bp-F0h]@78
  char text[224]; // [sp+1Ch] [bp-ECh]@34
  int v47; // [sp+104h] [bp-4h]@10

  v4 = this;
  this->vfptr = (RGE_ScenarioVtbl *)&RGE_Scenario::`vftable';
  this->world = w;
  RGE_Scenario::InitializeTextValues(this);
  v5 = (int)&v4->Version;
  rge_read((int)a2, (int)&v4->Version, infile, &v4->Version, 4);
  if( v4->Version > 1.13 )
  {
    v5 = (int)v4->player_name;
    a2 = (char *)16;
    do
    {
      rge_read((int)a2, v5, infile, (void *)v5, 256);
      v5 += 256;
      --a2;
    }
    while( a2 );
  }
  if( v4->Version > 1.13 )
  {
    v5 = (int)v4->PlType;
    a2 = (char *)16;
    do
    {
      rge_read((int)a2, v5, infile, (void *)(v5 + 128), 4);
      rge_read((int)a2, v5, infile, (void *)v5, 4);
      rge_read((int)a2, v5, infile, (void *)(v5 + 64), 4);
      rge_read((int)a2, v5, infile, (void *)(v5 - 64), 4);
      v5 += 4;
      --a2;
    }
    while( a2 );
  }
  if( v4->Version < 1.07 )
    v4->victory_conquest = 1;
  else
    rge_read((int)a2, v5, infile, &v4->victory_conquest, 1);
  v6 = (RGE_Timeline *)operator new(0x14u);
  v44 = (char *)v6;
  v47 = 0;
  if( v6 )
    RGE_Timeline::RGE_Timeline(v6, a2, infile, v4->world);
  else
    v7 = 0;
  v4->time_line = v7;
  v47 = -1;
  rge_read(-1, 0, infile, &length, 2);
  v8 = length;
  if( length > 0 )
  {
    rge_read(-1, 0, infile, v4->scenario_name, length);
    v8 = length;
  }
  v4->scenario_name[v8] = 0;
  rge_read(-1, 0, infile, &length, 2);
  if( length <= 0 )
  {
    v4->description = 0;
  }
  else
  {
    v9 = (char *)calloc(length, 1u);
    v10 = length;
    v4->description = v9;
    rge_read(-1, 0, infile, v9, v10);
    v4->description[length - 1] = 0;
  }
  if( v4->Version < 1.11 )
  {
    v4->hints = 0;
    v4->win_message = 0;
    v4->loss_message = 0;
  }
  else
  {
    rge_read(-1, 0, infile, &length, 2);
    if( length <= 0 )
    {
      v4->hints = 0;
    }
    else
    {
      v11 = (char *)calloc(length, 1u);
      v12 = length;
      v4->hints = v11;
      rge_read(-1, 0, infile, v11, v12);
      v4->hints[length - 1] = 0;
    }
    rge_read(-1, 0, infile, &length, 2);
    if( length <= 0 )
    {
      v4->win_message = 0;
    }
    else
    {
      v13 = (char *)calloc(length, 1u);
      v14 = length;
      v4->win_message = v13;
      rge_read(-1, 0, infile, v13, v14);
      v4->win_message[length - 1] = 0;
    }
    rge_read(-1, 0, infile, &length, 2);
    if( length <= 0 )
    {
      v4->loss_message = 0;
    }
    else
    {
      v15 = (char *)calloc(length, 1u);
      v16 = length;
      v4->loss_message = v15;
      rge_read(-1, 0, infile, v15, v16);
      v4->loss_message[length - 1] = 0;
    }
    rge_read(-1, 0, infile, &length, 2);
    if( length > 0 )
    {
      v17 = (char *)calloc(length, 1u);
      v18 = length;
      v4->historicle_notes = v17;
      rge_read(-1, 0, infile, v17, v18);
      goto LABEL_32;
    }
  }
  v4->historicle_notes = 0;
LABEL_32:
  if( v4->Version < 1.03 )
  {
    rge_read(-1, 0, infile, &length, 2);
    if( length > 0 )
      rge_read(-1, 0, infile, text, length);
    rge_read(-1, 0, infile, &length, 2);
    if( length > 0 )
      rge_read(-1, 0, infile, text, length);
    rge_read(-1, 0, infile, &length, 2);
    if( length > 0 )
      rge_read(-1, 0, infile, text, length);
  }
  rge_read(-1, 0, infile, &length, 2);
  v19 = length;
  if( length > 0 )
  {
    rge_read(-1, 0, infile, v4->Cine_PreGame, length);
    v19 = length;
  }
  v4->Cine_PreGame[v19] = 0;
  rge_read(-1, 0, infile, &length, 2);
  v20 = length;
  if( length > 0 )
  {
    rge_read(-1, 0, infile, v4->Cine_Victory, length);
    v20 = length;
  }
  v4->Cine_Victory[v20] = 0;
  rge_read(-1, 0, infile, &length, 2);
  v21 = length;
  if( length > 0 )
  {
    rge_read(-1, 0, infile, v4->Cine_Loss, length);
    v21 = length;
  }
  v4->Cine_Loss[v21] = 0;
  if( v4->Version >= 1.09 )
  {
    rge_read(-1, 0, infile, &length, 2);
    v22 = length;
    if( length > 0 )
    {
      rge_read(-1, 0, infile, v4->Mission_Bmp, length);
      v22 = length;
    }
    v4->Mission_Bmp[v22] = 0;
  }
  if( v4->Version < 1.1 )
  {
    v4->mission_picture = 0;
  }
  else
  {
    v23 = (TPicture *)operator new(0x20u);
    v44 = (char *)v23;
    v47 = 1;
    if( v23 )
    {
      TPicture::TPicture(v23, infile, 1);
      v47 = -1;
      v4->mission_picture = v24;
    }
    else
    {
      v47 = -1;
      v4->mission_picture = 0;
    }
  }
  v25 = (void **)v4->BuildList;
  v26 = 16;
  do
  {
    rge_read(v26, (int)v25, infile, &length, 2);
    v27 = length;
    if( length > 0 )
    {
      rge_read(v26, (int)v25, infile, *v25, length);
      v27 = length;
    }
    v28 = *v25;
    ++v25;
    --v26;
    v28[v27] = 0;
  }
  while( v26 );
  v29 = (void **)v4->CityPlan;
  v30 = (size_t *)16;
  do
  {
    rge_read((int)v30, (int)v29, infile, &length, 2);
    v31 = length;
    if( length > 0 )
    {
      rge_read((int)v30, (int)v29, infile, *v29, length);
      v31 = length;
    }
    v32 = v31;
    v33 = *v29;
    ++v29;
    v30 = (size_t *)((char *)v30 - 1);
    v33[v32] = 0;
  }
  while( v30 );
  if( v4->Version >= 1.08 )
  {
    v34 = (void **)v4->AiRules;
    v30 = (size_t *)16;
    do
    {
      rge_read((int)v30, (int)v34, infile, &length, 2);
      v35 = length;
      if( length > 0 )
      {
        rge_read((int)v30, (int)v34, infile, *v34, length);
        v35 = length;
      }
      v36 = *v34;
      ++v34;
      v30 = (size_t *)((char *)v30 - 1);
      v36[v35] = 0;
    }
    while( v30 );
  }
  v37 = (int)v4->BuildListFileSize;
  v44 = (char *)16;
  do
  {
    rge_read((int)v30, v37, infile, (void *)v37, 4);
    v30 = (size_t *)(v37 + 64);
    rge_read(v37 + 64, v37, infile, (void *)(v37 + 64), 4);
    if( v4->Version >= 1.08 )
      rge_read((int)v30, v37, infile, (void *)(v37 + 128), 4);
    *(_DWORD *)(v37 - 192) = 0;
    *(_DWORD *)(v37 - 128) = 0;
    *(_DWORD *)(v37 - 64) = 0;
    if( v4->Version >= 1.15 )
    {
      if( *(_DWORD *)v37 > 0 )
      {
        v38 = calloc(*(_DWORD *)v37, 1u);
        *(_DWORD *)(v37 - 192) = v38;
        rge_read((int)v30, v37, infile, v38, *(_DWORD *)v37);
      }
      if( (signed int)*v30 > 0 )
      {
        v39 = calloc(*v30, 1u);
        *(_DWORD *)(v37 - 128) = v39;
        rge_read((int)v30, v37, infile, v39, *v30);
      }
      v40 = *(_DWORD *)(v37 + 128);
      if( v40 > 0 )
      {
        v41 = calloc(v40, 1u);
        *(_DWORD *)(v37 - 64) = v41;
        rge_read((int)v30, v37, infile, v41, *(_DWORD *)(v37 + 128));
      }
    }
    v37 += 4;
    --v44;
  }
  while( v44 );
  v42 = v4->Version;
  val = 0;
  if( v42 > 1.02 )
    rge_read((int)v30, v37, infile, &val, 4);
}
// 572128: using guessed type struct RGE_Static_Object *(__thiscall *RGE_Scenario::`vftable')(RGE_Scenario *this, int);

//----- (0048B580) --------------------------------------------------------
RGE_Static_Object *__stdcall RGE_Scenario::get_object_pointer(int obj_ID)
{
  return 0;
}

//----- (0048B5A0) --------------------------------------------------------
void __thiscall RGE_Scenario::~RGE_Scenario(RGE_Scenario *this)
{
  RGE_Scenario *v1; // esi@1
  RGE_Timeline *v2; // ecx@1
  TPicture *v3; // edi@13
  int v4; // esi@15
  signed int v5; // edi@15

  v1 = this;
  v2 = this->time_line;
  v1->vfptr = (RGE_ScenarioVtbl *)&RGE_Scenario::`vftable';
  if( v2 )
  {
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
    v1->time_line = 0;
  }
  if( v1->description )
    free(v1->description);
  if( v1->hints )
    free(v1->hints);
  if( v1->win_message )
    free(v1->win_message);
  if( v1->loss_message )
    free(v1->loss_message);
  if( v1->historicle_notes )
    free(v1->historicle_notes);
  operator delete(v1->scenario_name);
  v3 = v1->mission_picture;
  if( v3 )
  {
    TPicture::~TPicture(v1->mission_picture);
    operator delete(v3);
    v1->mission_picture = 0;
  }
  v4 = (int)v1->CityPlan;
  v5 = 16;
  do
  {
    operator delete(*(void **)(v4 - 64));
    operator delete(*(void **)v4);
    operator delete(*(void **)(v4 + 64));
    if( *(_DWORD *)(v4 + 128) )
      free(*(void **)(v4 + 128));
    if( *(_DWORD *)(v4 + 192) )
      free(*(void **)(v4 + 192));
    if( *(_DWORD *)(v4 + 256) )
      free(*(void **)(v4 + 256));
    v4 += 4;
    --v5;
  }
  while( v5 );
}
// 572128: using guessed type struct RGE_Static_Object *(__thiscall *RGE_Scenario::`vftable')(RGE_Scenario *this, int);

//----- (0048B6C0) --------------------------------------------------------
void __thiscall RGE_Scenario::InitializeTextValues(RGE_Scenario *this)
{
  RGE_Scenario *v1; // ebp@1
  char *v2; // edi@1
  int v3; // ecx@1
  int v4; // ebp@1
  void *v5; // edi@2
  void *v6; // edi@2
  void *v7; // edi@2
  unsigned int v8; // ecx@2
  char v9; // al@2
  void *v10; // edi@2
  char *v11; // edi@2
  char *v12; // esi@2
  signed int v13; // eax@2
  _BYTE *v14; // [sp+18h] [bp-48h]@1
  signed int v15; // [sp+1Ch] [bp-44h]@1
  char none_string[30]; // [sp+20h] [bp-40h]@1
  char default_string[30]; // [sp+40h] [bp-20h]@1

  v1 = this;
  (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(10101, none_string, 30);
  (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(10107, default_string, 30);
  v1->description = 0;
  v1->hints = 0;
  v1->win_message = 0;
  v1->loss_message = 0;
  v1->historicle_notes = 0;
  v2 = (char *)operator new(0xE0u);
  v1->scenario_name = v2;
  memset(v2, 0, 0xE0u);
  strcpy(v1->Cine_PreGame, none_string);
  strcpy(v1->Cine_Victory, none_string);
  strcpy(v1->Cine_Loss, none_string);
  v15 = 16;
  strcpy(v1->Mission_Bmp, none_string);
  v3 = (int)v1->player_name;
  v4 = (int)v1->PlType;
  v14 = (_BYTE *)v3;
  do
  {
    *(_DWORD *)(v4 - 64) = 0;
    *(_DWORD *)v4 = 0;
    *(_DWORD *)(v4 + 64) = 0;
    *(_DWORD *)(v4 + 128) = 0;
    *v14 = 0;
    v5 = operator new(0xE0u);
    *(_DWORD *)(v4 - 1540) = v5;
    memset(v5, 0, 0xE0u);
    strcpy(*(char **)(v4 - 1540), default_string);
    v6 = operator new(0xE0u);
    *(_DWORD *)(v4 - 1476) = v6;
    memset(v6, 0, 0xE0u);
    strcpy(*(char **)(v4 - 1476), none_string);
    v7 = operator new(0xE0u);
    *(_DWORD *)(v4 - 1412) = v7;
    memset(v7, 0, 0xE0u);
    v4 += 4;
    v8 = strlen(default_string) + 1;
    v9 = v8;
    v10 = *(void **)(v4 - 1416);
    v8 >>= 2;
    qmemcpy(v10, default_string, 4 * v8);
    v12 = &default_string[4 * v8];
    v11 = (char *)v10 + 4 * v8;
    LOBYTE(v8) = v9;
    v13 = v15;
    qmemcpy(v11, v12, v8 & 3);
    *(_DWORD *)(v4 - 1352) = 0;
    *(_DWORD *)(v4 - 1288) = 0;
    *(_DWORD *)(v4 - 1224) = 0;
    *(_DWORD *)(v4 - 1160) = 0;
    *(_DWORD *)(v4 - 1096) = 0;
    *(_DWORD *)(v4 - 1032) = 0;
    v14 += 256;
    --v15;
  }
  while( v13 != 1 );
}

//----- (0048B910) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_scenario_name(RGE_Scenario *this, char *str)
{
  if( str )
    strcpy(this->scenario_name, str);
  else
    *this->scenario_name = 0;
}

//----- (0048B950) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_description(RGE_Scenario *this, char *str)
{
  RGE_Scenario::Set_message(this, str, 0);
}

//----- (0048B960) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_Cine_PreGame(RGE_Scenario *this, char *str)
{
  if( str )
    strcpy(this->Cine_PreGame, str);
  else
    this->Cine_PreGame[0] = 0;
}

//----- (0048B9A0) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_Cine_Victory(RGE_Scenario *this, char *str)
{
  if( str )
    strcpy(this->Cine_Victory, str);
  else
    this->Cine_Victory[0] = 0;
}

//----- (0048B9E0) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_Cine_Loss(RGE_Scenario *this, char *str)
{
  if( str )
    strcpy(this->Cine_Loss, str);
  else
    this->Cine_Loss[0] = 0;
}

//----- (0048BA20) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_Mission_Bmp(RGE_Scenario *this, char *str)
{
  if( str )
    strcpy(this->Mission_Bmp, str);
  else
    this->Mission_Bmp[0] = 0;
}

//----- (0048BA60) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_BuildList(RGE_Scenario *this, int which_player, char *str, int WithExtension)
{
  char **v4; // edx@2

  if( str )
  {
    v4 = &this->BuildList[which_player];
    strcpy(*v4, str);
  }
  else
  {
    v4 = &this->BuildList[which_player];
    **v4 = 0;
  }
  if( WithExtension == 1 )
    (*v4)[strlen(str) - 4] = 0;
}

//----- (0048BAD0) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_CityPlan(RGE_Scenario *this, int which_player, char *str, int WithExtension)
{
  char **v4; // edx@2

  if( str )
  {
    v4 = &this->CityPlan[which_player];
    strcpy(*v4, str);
  }
  else
  {
    v4 = &this->CityPlan[which_player];
    **v4 = 0;
  }
  if( WithExtension == 1 )
    (*v4)[strlen(str) - 4] = 0;
}

//----- (0048BB40) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_player_AI(RGE_Scenario *this, int which_player, char *str, int WithExtension)
{
  char **v4; // edx@2

  if( str )
  {
    v4 = &this->AiRules[which_player];
    strcpy(*v4, str);
  }
  else
  {
    v4 = &this->AiRules[which_player];
    **v4 = 0;
  }
  if( WithExtension == 1 )
    (*v4)[strlen(str) - 4] = 0;
}

//----- (0048BBB0) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_Version(RGE_Scenario *this, float ver)
{
  this->Version = ver;
}

//----- (0048BBC0) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_player_Type(RGE_Scenario *this, int which, int t)
{
  if( which >= 0 && which < 16 )
    this->PlType[which] = t;
}

//----- (0048BBE0) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_player_Civ(RGE_Scenario *this, int which, int c)
{
  if( which >= 0 && which < 16 )
    this->PlCivilization[which] = c;
}

//----- (0048BC00) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_player_Active(RGE_Scenario *this, int which, int val)
{
  if( which >= 0 && which < 16 )
    this->PlActive[which] = val;
}

//----- (0048BC20) --------------------------------------------------------
void __thiscall RGE_Scenario::SetPlayerName(RGE_Scenario *this, int which, char *Name)
{
  strcpy(this->player_name[which].Name, Name);
}

//----- (0048BC60) --------------------------------------------------------
char *__thiscall RGE_Scenario::Get_scenario_name(RGE_Scenario *this)
{
  return this->scenario_name;
}

//----- (0048BC70) --------------------------------------------------------
char *__thiscall RGE_Scenario::Get_description(RGE_Scenario *this)
{
  return this->description;
}

//----- (0048BC80) --------------------------------------------------------
char *__thiscall RGE_Scenario::Get_Cine_PreGame(RGE_Scenario *this)
{
  return this->Cine_PreGame;
}

//----- (0048BC90) --------------------------------------------------------
char *__thiscall RGE_Scenario::Get_Cine_Victory(RGE_Scenario *this)
{
  return this->Cine_Victory;
}

//----- (0048BCA0) --------------------------------------------------------
char *__thiscall RGE_Scenario::Get_Cine_Loss(RGE_Scenario *this)
{
  return this->Cine_Loss;
}

//----- (0048BCB0) --------------------------------------------------------
char *__thiscall RGE_Scenario::Get_Mission_Bmp(RGE_Scenario *this)
{
  return this->Mission_Bmp;
}

//----- (0048BCC0) --------------------------------------------------------
char *__thiscall RGE_Scenario::Get_BuildList(RGE_Scenario *this, int which_player, int WithExtension)
{
  RGE_Scenario *v3; // ebp@1
  signed int v4; // ebx@1
  int v5; // eax@3
  const char *v7; // edi@10
  char random_str[50]; // [sp+18h] [bp-16Ch]@1
  char none_str[50]; // [sp+4Ch] [bp-138h]@1
  char temp_path[260]; // [sp+80h] [bp-104h]@1

  v3 = this;
  v4 = -1;
  (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(10107, random_str, 50);
  (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(10101, none_str, 50);
  if( !GetTempPathA(0x104u, temp_path) )
    strcpy(temp_path, a__1);
  v5 = which_player;
  if( WithExtension == 1 && v3->BuildListFileSize[which_player] > 0 && v3->BuildListFile[which_player] )
  {
    sprintf(v3->TempText1, aStemp_buildlis, temp_path, which_player);
    v4 = _open(v3->TempText1, 33537, 384);
    v5 = which_player;
  }
  if( v4 != -1 )
  {
    _write(v4, v3->BuildListFile[v5], v3->BuildListFileSize[v5]);
    _close(v4);
    return v3->TempText1;
  }
  if( WithExtension == 1 )
  {
    v7 = v3->BuildList[v5];
    if( strcmp(v3->BuildList[v5], none_str) && strcmp(v7, random_str) )
    {
      sprintf(v3->TempText1, aSS_ai, rge_base_game->prog_info->ai_dir, v7);
      return v3->TempText1;
    }
    v5 = which_player;
  }
  sprintf(v3->TempText1, aS_2, v3->BuildList[v5]);
  return v3->TempText1;
}

//----- (0048BEC0) --------------------------------------------------------
char *__thiscall RGE_Scenario::Get_CityPlan(RGE_Scenario *this, int which_player, int WithExtension)
{
  RGE_Scenario *v3; // ebp@1
  signed int v4; // ebx@1
  int v5; // eax@3
  const char *v7; // edi@10
  char random_str[50]; // [sp+18h] [bp-16Ch]@1
  char none_str[50]; // [sp+4Ch] [bp-138h]@1
  char temp_path[260]; // [sp+80h] [bp-104h]@1

  v3 = this;
  v4 = -1;
  (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(10107, random_str, 50);
  (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(10101, none_str, 50);
  if( !GetTempPathA(0x104u, temp_path) )
    strcpy(temp_path, a__1);
  v5 = which_player;
  if( WithExtension == 1 && v3->CityPlanFileSize[which_player] > 0 && v3->CityPlanFile[which_player] )
  {
    sprintf(v3->TempText2, aStemp_cityplan, temp_path, which_player);
    v4 = _open(v3->TempText2, 33537, 384);
    v5 = which_player;
  }
  if( v4 != -1 )
  {
    _write(v4, v3->CityPlanFile[v5], v3->CityPlanFileSize[v5]);
    _close(v4);
    return v3->TempText2;
  }
  if( WithExtension == 1 )
  {
    v7 = v3->BuildList[v5];
    if( strcmp(v3->BuildList[v5], none_str) && strcmp(v7, random_str) )
    {
      sprintf(v3->TempText2, aSS_cty, rge_base_game->prog_info->ai_dir, v3->CityPlan[which_player]);
      return v3->TempText2;
    }
    v5 = which_player;
  }
  sprintf(v3->TempText2, aS_2, v3->CityPlan[v5]);
  return v3->TempText2;
}

//----- (0048C0D0) --------------------------------------------------------
double RGE_Scenario::Get_Version()
{
  return 1.15;
}

//----- (0048C0E0) --------------------------------------------------------
char *__thiscall RGE_Scenario::Get_player_AI(RGE_Scenario *this, int which_player, int WithExtension)
{
  RGE_Scenario *v3; // ebp@1
  signed int v4; // ebx@1
  int v5; // eax@3
  const char *v7; // edi@10
  char random_str[50]; // [sp+18h] [bp-16Ch]@1
  char none_str[50]; // [sp+4Ch] [bp-138h]@1
  char temp_path[260]; // [sp+80h] [bp-104h]@1

  v3 = this;
  v4 = -1;
  (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(10107, random_str, 50);
  (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(10101, none_str, 50);
  if( !GetTempPathA(0x104u, temp_path) )
    strcpy(temp_path, a__1);
  v5 = which_player;
  if( WithExtension == 1 && v3->AiRulesFileSize[which_player] > 0 && v3->AiRulesFile[which_player] )
  {
    sprintf(v3->TempText3, aStemp_airulesD, temp_path, which_player);
    v4 = _open(v3->TempText3, 33537, 384);
    v5 = which_player;
  }
  if( v4 != -1 )
  {
    _write(v4, v3->AiRulesFile[v5], v3->AiRulesFileSize[v5]);
    _close(v4);
    return v3->TempText3;
  }
  if( WithExtension == 1 )
  {
    v7 = v3->BuildList[v5];
    if( strcmp(v3->BuildList[v5], none_str) && strcmp(v7, random_str) )
    {
      sprintf(v3->TempText3, aSS_per, rge_base_game->prog_info->ai_dir, v3->AiRules[which_player]);
      return v3->TempText3;
    }
    v5 = which_player;
  }
  sprintf(v3->TempText3, aS_2, v3->AiRules[v5]);
  return v3->TempText3;
}

//----- (0048C2F0) --------------------------------------------------------
int __thiscall RGE_Scenario::GetPlayerPosture(RGE_Scenario *this, int which)
{
  int result; // eax@4

  if( which < 0 || which >= 9 )
  {
LABEL_9:
    result = 0;
  }
  else
  {
    switch ( this->PlayerPosture[which] )
    {
      case 1:
        result = 1;
        break;
      case 2:
        result = 2;
        break;
      case 3:
        result = 3;
        break;
      case 4:
        result = 4;
        break;
      case 5:
        result = 5;
        break;
      default:
        goto LABEL_9;
    }
  }
  return result;
}

//----- (0048C360) --------------------------------------------------------
PlayerName *__thiscall RGE_Scenario::GetPlayerName(RGE_Scenario *this, int which)
{
  return &this->player_name[which];
}

//----- (0048C370) --------------------------------------------------------
int __thiscall RGE_Scenario::Get_player_Type(RGE_Scenario *this, int which)
{
  int result; // eax@3

  if( which < 0 || which >= 16 )
    result = 0;
  else
    result = this->PlType[which];
  return result;
}

//----- (0048C390) --------------------------------------------------------
int __thiscall RGE_Scenario::Get_player_Civ(RGE_Scenario *this, int which)
{
  int result; // eax@3

  if( which < 0 || which >= 16 )
    result = 0;
  else
    result = this->PlCivilization[which];
  return result;
}

//----- (0048C3B0) --------------------------------------------------------
int __thiscall RGE_Scenario::Get_player_Active(RGE_Scenario *this, int which)
{
  int result; // eax@3

  if( which < 0 || which >= 16 )
    result = 0;
  else
    result = this->PlActive[which];
  return result;
}

//----- (0048C3D0) --------------------------------------------------------
void __fastcall RGE_Scenario::update(RGE_Scenario *this, RGE_Master_Static_Object **a2)
{
  RGE_Timeline *v2; // ecx@1

  v2 = this->time_line;
  if( v2 )
    RGE_Timeline::update(v2, a2);
}

//----- (0048C3E0) --------------------------------------------------------
void __thiscall RGE_Scenario::save(RGE_Scenario *this, int outfile)
{
  RGE_Scenario *v2; // ebp@1
  char *v3; // esi@1
  PlayerName *v4; // esi@1
  signed int v5; // edi@1
  int v6; // esi@3
  signed int v7; // edi@3
  RGE_Timeline *v8; // ecx@5
  const char *v9; // edi@7
  const char *v10; // edi@12
  const char *v11; // edi@17
  const char *v12; // edi@22
  const char *v13; // edi@27
  const char *v14; // edi@32
  TPicture *v15; // eax@45
  TPicture *v16; // edi@45
  TPicture *v17; // eax@46
  TPicture *v18; // esi@47
  const char **v19; // esi@54
  const char **v20; // esi@58
  const char **v21; // esi@63
  signed int v22; // ebp@63
  int v23; // esi@67
  signed int v24; // eax@69
  int v25; // edi@69
  signed int v26; // eax@74
  int v27; // edi@74
  signed int v28; // eax@79
  int v29; // edi@79
  void *v30; // eax@85
  void *v31; // eax@87
  void *v32; // eax@89
  unsigned int length; // [sp+10h] [bp-1E0h]@8
  int v34; // [sp+14h] [bp-1DCh]@54
  void *v35; // [sp+18h] [bp-1D8h]@45
  float *v36; // [sp+1Ch] [bp-1D4h]@1
  int val; // [sp+20h] [bp-1D0h]@92
  char temp_file_name[224]; // [sp+24h] [bp-1CCh]@69
  char file_name[224]; // [sp+104h] [bp-ECh]@45
  int v40; // [sp+1ECh] [bp-4h]@45

  v2 = this;
  v3 = (char *)&this->Version;
  v36 = &this->Version;
  *(float *)v3 = RGE_Scenario::Get_Version();
  rge_write(outfile, v3, 4);
  v4 = v2->player_name;
  v5 = 16;
  do
  {
    rge_write(outfile, v4, 256);
    ++v4;
    --v5;
  }
  while( v5 );
  v6 = (int)v2->PlType;
  v7 = 16;
  do
  {
    rge_write(outfile, (void *)(v6 + 128), 4);
    rge_write(outfile, (void *)v6, 4);
    rge_write(outfile, (void *)(v6 + 64), 4);
    rge_write(outfile, (void *)(v6 - 64), 4);
    v6 += 4;
    --v7;
  }
  while( v7 );
  rge_write(outfile, &v2->victory_conquest, 1);
  v8 = v2->time_line;
  if( v8 )
    RGE_Timeline::save(v8, outfile);
  v9 = v2->scenario_name;
  if( v9 )
    length = strlen(v9);
  else
    length = 0;
  rge_write(outfile, &length, 2);
  if( (signed __int16)length > 0 )
    rge_write(outfile, v2->scenario_name, (signed __int16)length);
  v10 = v2->description;
  if( v10 )
  {
    length = strlen(v10);
    ++length;
  }
  else
  {
    length = 0;
  }
  rge_write(outfile, &length, 2);
  if( (signed __int16)length > 0 )
    rge_write(outfile, v2->description, (signed __int16)length);
  v11 = v2->hints;
  if( v11 )
  {
    length = strlen(v11);
    ++length;
  }
  else
  {
    length = 0;
  }
  rge_write(outfile, &length, 2);
  if( (signed __int16)length > 0 )
    rge_write(outfile, v2->hints, (signed __int16)length);
  v12 = v2->win_message;
  if( v12 )
  {
    length = strlen(v12);
    ++length;
  }
  else
  {
    length = 0;
  }
  rge_write(outfile, &length, 2);
  if( (signed __int16)length > 0 )
    rge_write(outfile, v2->win_message, (signed __int16)length);
  v13 = v2->loss_message;
  if( v13 )
  {
    length = strlen(v13);
    ++length;
  }
  else
  {
    length = 0;
  }
  rge_write(outfile, &length, 2);
  if( (signed __int16)length > 0 )
    rge_write(outfile, v2->loss_message, (signed __int16)length);
  v14 = v2->historicle_notes;
  if( v14 )
  {
    length = strlen(v14);
    ++length;
  }
  else
  {
    length = 0;
  }
  rge_write(outfile, &length, 2);
  if( (signed __int16)length > 0 )
    rge_write(outfile, v2->historicle_notes, (signed __int16)length);
  length = strlen(v2->Cine_PreGame);
  rge_write(outfile, &length, 2);
  if( (signed __int16)length > 0 )
    rge_write(outfile, v2->Cine_PreGame, (signed __int16)length);
  length = strlen(v2->Cine_Victory);
  rge_write(outfile, &length, 2);
  if( (signed __int16)length > 0 )
    rge_write(outfile, v2->Cine_Victory, (signed __int16)length);
  length = strlen(v2->Cine_Loss);
  rge_write(outfile, &length, 2);
  if( (signed __int16)length > 0 )
    rge_write(outfile, v2->Cine_Loss, (signed __int16)length);
  length = strlen(v2->Mission_Bmp);
  rge_write(outfile, &length, 2);
  if( (signed __int16)length > 0 )
    rge_write(outfile, v2->Mission_Bmp, (signed __int16)length);
  sprintf(file_name, aS_bmp, v2->Mission_Bmp);
  v15 = (TPicture *)operator new(0x20u);
  v35 = v15;
  v16 = 0;
  v40 = 0;
  if( v15 )
  {
    TPicture::TPicture(v15, file_name, -1, 0, 0, 0);
    v16 = v17;
  }
  v18 = v2->mission_picture;
  v40 = -1;
  if( !v18 )
    goto LABEL_53;
  if( v16->Dib )
  {
    if( v18 )
    {
      TPicture::~TPicture(v18);
      operator delete(v18);
    }
LABEL_53:
    v2->mission_picture = v16;
    goto LABEL_54;
  }
  if( v16 )
  {
    TPicture::~TPicture(v16);
    operator delete(v16);
  }
LABEL_54:
  TPicture::Save(v2->mission_picture, outfile);
  v19 = (const char **)v2->BuildList;
  v34 = 16;
  do
  {
    length = strlen(*v19);
    rge_write(outfile, &length, 2);
    if( (signed __int16)length > 0 )
      rge_write(outfile, (void *)*v19, (signed __int16)length);
    ++v19;
    --v34;
  }
  while( v34 );
  v20 = (const char **)v2->CityPlan;
  v34 = 16;
  v35 = v2->CityPlan;
  do
  {
    length = strlen(*v20);
    rge_write(outfile, &length, 2);
    if( (signed __int16)length > 0 )
      rge_write(outfile, (void *)*v20, (signed __int16)length);
    ++v20;
    --v34;
  }
  while( v34 );
  if( *v36 >= 1.08 )
  {
    v21 = (const char **)v2->AiRules;
    v22 = 16;
    do
    {
      length = strlen(*v21);
      rge_write(outfile, &length, 2);
      if( (signed __int16)length > 0 )
        rge_write(outfile, (void *)*v21, (signed __int16)length);
      ++v21;
      --v22;
    }
    while( v22 );
  }
  v23 = (int)v35;
  v34 = 16;
  do
  {
    if( *(_DWORD *)(v23 - 64) )
    {
      sprintf(temp_file_name, aSS_ai, rge_base_game->prog_info->ai_dir, *(_DWORD *)(v23 - 64));
      v24 = _open(temp_file_name, 0x8000);
      v25 = v24;
      if( v24 > -1 )
      {
        lseek(v24, 0, 2);
        *(_DWORD *)(v23 + 320) = _tell(v25);
        if( *(_DWORD *)(v23 + 128) )
          free(*(void **)(v23 + 128));
        *(_DWORD *)(v23 + 128) = calloc(*(_DWORD *)(v23 + 320), 1u);
        lseek(v25, 0, 0);
        read(v25, *(void **)(v23 + 128), *(_DWORD *)(v23 + 320));
        _close(v25);
      }
    }
    if( *(_DWORD *)v23 )
    {
      sprintf(temp_file_name, aSS_cty, rge_base_game->prog_info->ai_dir, *(_DWORD *)v23);
      v26 = _open(temp_file_name, 0x8000);
      v27 = v26;
      if( v26 > -1 )
      {
        lseek(v26, 0, 2);
        *(_DWORD *)(v23 + 384) = _tell(v27);
        if( *(_DWORD *)(v23 + 192) )
          free(*(void **)(v23 + 192));
        *(_DWORD *)(v23 + 192) = calloc(*(_DWORD *)(v23 + 384), 1u);
        lseek(v27, 0, 0);
        read(v27, *(void **)(v23 + 192), *(_DWORD *)(v23 + 384));
        _close(v27);
      }
    }
    if( *(_DWORD *)(v23 + 64) )
    {
      sprintf(temp_file_name, aSS_per, rge_base_game->prog_info->ai_dir, *(_DWORD *)(v23 + 64));
      v28 = _open(temp_file_name, 0x8000);
      v29 = v28;
      if( v28 > -1 )
      {
        lseek(v28, 0, 2);
        *(_DWORD *)(v23 + 448) = _tell(v29);
        if( *(_DWORD *)(v23 + 256) )
          free(*(void **)(v23 + 256));
        *(_DWORD *)(v23 + 256) = calloc(*(_DWORD *)(v23 + 448), 1u);
        lseek(v29, 0, 0);
        read(v29, *(void **)(v23 + 256), *(_DWORD *)(v23 + 448));
        _close(v29);
      }
    }
    rge_write(outfile, (void *)(v23 + 320), 4);
    rge_write(outfile, (void *)(v23 + 384), 4);
    if( *v36 >= 1.08 )
      rge_write(outfile, (void *)(v23 + 448), 4);
    v30 = *(void **)(v23 + 128);
    if( v30 )
      rge_write(outfile, v30, *(_DWORD *)(v23 + 320));
    v31 = *(void **)(v23 + 192);
    if( v31 )
      rge_write(outfile, v31, *(_DWORD *)(v23 + 384));
    v32 = *(void **)(v23 + 256);
    if( v32 )
      rge_write(outfile, v32, *(_DWORD *)(v23 + 448));
    v23 += 4;
    --v34;
  }
  while( v34 );
  val = -99;
  rge_write(outfile, &val, 4);
}

//----- (0048CC20) --------------------------------------------------------
int __thiscall RGE_Scenario::active_player_count(RGE_Scenario *this)
{
  int v1; // ebx@1
  RGE_Scenario *v2; // edi@1
  int v3; // esi@1

  v1 = 0;
  v2 = this;
  v3 = 0;
  do
  {
    if( RGE_Scenario::Get_player_Active(v2, v3) )
      ++v1;
    ++v3;
  }
  while( v3 < 16 );
  return v1;
}

//----- (0048CC50) --------------------------------------------------------
int __thiscall RGE_Scenario::any_player_count(RGE_Scenario *this)
{
  int v1; // ebx@1
  RGE_Scenario *v2; // edi@1
  int v3; // esi@1

  v1 = 0;
  v2 = this;
  v3 = 0;
  do
  {
    if( RGE_Scenario::Get_player_Active(v2, v3) && RGE_Scenario::Get_player_Type(v2, v3) == 1 )
      ++v1;
    ++v3;
  }
  while( v3 < 16 );
  return v1;
}

//----- (0048CC80) --------------------------------------------------------
int __thiscall RGE_Scenario::computer_player_count(RGE_Scenario *this)
{
  int v1; // ebx@1
  RGE_Scenario *v2; // edi@1
  int v3; // esi@1

  v1 = 0;
  v2 = this;
  v3 = 0;
  do
  {
    if( RGE_Scenario::Get_player_Active(v2, v3) && !RGE_Scenario::Get_player_Type(v2, v3) )
      ++v1;
    ++v3;
  }
  while( v3 < 16 );
  return v1;
}

//----- (0048CCB0) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_conquest_victory(RGE_Scenario *this, char flag)
{
  this->victory_conquest = flag;
}

//----- (0048CCC0) --------------------------------------------------------
char __thiscall RGE_Scenario::Get_conquest_victory(RGE_Scenario *this)
{
  return this->victory_conquest;
}

//----- (0048CCD0) --------------------------------------------------------
void __thiscall RGE_Scenario::add_description(RGE_Scenario *this, char *new_text)
{
  char **v2; // eax@1
  char *v3; // ecx@1

  v2 = &this->description;
  v3 = this->description;
  if( v3 )
    addstring(v2, v3, new_text);
  else
    getstring(v2, new_text);
}

//----- (0048CD10) --------------------------------------------------------
void __thiscall RGE_Scenario::Set_message(RGE_Scenario *this, char *str, int message)
{
  RGE_Scenario *v3; // ebx@1
  signed int v4; // edi@2
  char *v5; // ebp@5

  v3 = this;
  if( str )
    v4 = strlen(str) + 1;
  else
    v4 = 0;
  if( v4 <= 0 )
    v5 = 0;
  else
    v5 = (char *)calloc(v4, 1u);
  qmemcpy(v5, str, v4);
  switch ( message )
  {
    case 0:
      if( v3->description )
        free(v3->description);
      v3->description = v5;
      break;
    case 1:
      if( v3->hints )
        free(v3->hints);
      v3->hints = v5;
      break;
    case 2:
      if( !v3->win_message )
        free(0);
      v3->win_message = v5;
      break;
    case 3:
      if( v3->loss_message )
        free(v3->loss_message);
      v3->loss_message = v5;
      break;
    case 4:
      if( v3->historicle_notes )
        free(v3->historicle_notes);
      v3->historicle_notes = v5;
      break;
    default:
      if( v5 )
        free(v5);
      break;
  }
}

//----- (0048CE40) --------------------------------------------------------
char *__thiscall RGE_Scenario::Get_message(RGE_Scenario *this, int message)
{
  char *result; // eax@2

  switch ( message )
  {
    case 0:
      result = this->description;
      break;
    case 1:
      result = this->hints;
      break;
    case 2:
      result = this->win_message;
      break;
    case 3:
      result = this->loss_message;
      break;
    case 4:
      result = this->historicle_notes;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (0048CEA0) --------------------------------------------------------
void __thiscall RGE_Scenario_File_Info::RGE_Scenario_File_Info(RGE_Scenario_File_Info *this, char *in_filename)
{
  RGE_Scenario_File_Info *v2; // ebx@1
  int v3; // eax@1
  int v4; // edi@1
  int v5; // ebp@2
  int v6; // esi@4

  v2 = this;
  strcpy(this->filename, in_filename);
  v3 = rge_open(v2->filename, 0x8000);
  v4 = v3;
  if( v3 == -1 )
  {
    v2->scenario_num = 0;
    v2->scenarios = 0;
    RGE_Scenario_File_Info::reload_scenarios(v2);
    return;
  }
  rge_read_uncompressed(v3, &v2->scenario_num, 4);
  v5 = 0;
  if( v2->scenario_num <= 0 )
  {
    v2->scenarios = 0;
    goto LABEL_8;
  }
  v2->scenarios = (RGE_Scenario_File_Entry *)calloc(v2->scenario_num, 0x10Cu);
  if( v2->scenario_num <= 0 )
  {
LABEL_8:
    rge_close(v4);
    RGE_Scenario_File_Info::reload_scenarios(v2);
    return;
  }
  v6 = 0;
  do
  {
    rge_read_uncompressed(v4, &v2->scenarios[v6], 4);
    rge_read_uncompressed(v4, v2->scenarios[v6].name, 260);
    ++v5;
    v2->scenarios[v6].scenario_header = (RGE_Scenario_Header *)((int (__stdcall *)(int))rge_base_game->vfptr->new_scenario_header)(v4);
    ++v6;
  }
  while( v5 < v2->scenario_num );
  rge_close(v4);
  RGE_Scenario_File_Info::reload_scenarios(v2);
}

//----- (0048CFD0) --------------------------------------------------------
void __thiscall RGE_Scenario_File_Info::~RGE_Scenario_File_Info(RGE_Scenario_File_Info *this)
{
  RGE_Scenario_File_Info *v1; // esi@1
  int v2; // eax@1
  int v3; // ebp@2
  int v4; // ebx@3
  RGE_Scenario_File_Entry *v5; // eax@4
  RGE_Scenario_Header *v6; // edi@4

  v1 = this;
  RGE_Scenario_File_Info::save(this);
  v2 = v1->scenario_num;
  if( v2 > 0 )
  {
    v3 = 0;
    if( v2 > 0 )
    {
      v4 = 0;
      do
      {
        v5 = v1->scenarios;
        v6 = v5[v4].scenario_header;
        if( v6 )
        {
          RGE_Scenario_Header::~RGE_Scenario_Header(v5[v4].scenario_header);
          operator delete(v6);
        }
        ++v3;
        ++v4;
      }
      while( v3 < v1->scenario_num );
    }
    free(v1->scenarios);
    v1->scenarios = 0;
    v1->scenario_num = 0;
  }
}

//----- (0048D040) --------------------------------------------------------
void __thiscall RGE_Scenario_File_Info::save(RGE_Scenario_File_Info *this)
{
  RGE_Scenario_File_Info *v1; // ebx@1
  int v2; // eax@1
  int v3; // edi@1
  int v4; // ebp@2
  int v5; // esi@3

  v1 = this;
  v2 = rge_open(this->filename, 33537, 384);
  v3 = v2;
  if( v2 != -1 )
  {
    rge_write_uncompressed(v2, &v1->scenario_num, 4);
    v4 = 0;
    if( v1->scenario_num > 0 )
    {
      v5 = 0;
      do
      {
        rge_write_uncompressed(v3, &v1->scenarios[v5], 4);
        rge_write_uncompressed(v3, v1->scenarios[v5].name, 260);
        ((void (__stdcall *)(int))v1->scenarios[v5].scenario_header->vfptr->save)(v3);
        ++v4;
        ++v5;
      }
      while( v4 < v1->scenario_num );
    }
    rge_close(v3);
  }
}

//----- (0048D0E0) --------------------------------------------------------
void __thiscall RGE_Scenario_File_Info::reload_scenarios(RGE_Scenario_File_Info *this)
{
  RGE_Scenario_File_Info *v1; // ebx@1
  signed int v2; // edi@1
  __int32 v3; // esi@1
  __int32 v4; // esi@4
  int v5; // ebp@11
  int v6; // edi@12
  const char *v7; // eax@13
  RGE_Scenario_File_Entry *v8; // eax@17
  int v9; // edx@17
  int v10; // eax@20
  int v11; // esi@20
  int v12; // ebp@27
  int v13; // edi@28
  RGE_Scenario_File_Entry *v14; // ecx@29
  RGE_Scenario_Header *v15; // esi@29
  char looped; // [sp+12h] [bp-22Eh]@1
  char found_in_list; // [sp+13h] [bp-22Dh]@12
  int v18; // [sp+14h] [bp-22Ch]@13
  int handle; // [sp+18h] [bp-228h]@8
  int count; // [sp+1Ch] [bp-224h]@1
  RGE_Scenario_File_Entry *new_scenarios; // [sp+20h] [bp-220h]@11
  int version; // [sp+24h] [bp-21Ch]@21
  char file_name[256]; // [sp+28h] [bp-218h]@1
  _finddata_t file_info; // [sp+128h] [bp-118h]@1

  v1 = this;
  v2 = 0;
  count = 0;
  looped = 0;
  sprintf(file_name, aS_scn_1, rge_base_game->prog_info->scenario_dir);
  v3 = _findfirst(file_name, &file_info);
  if( v3 != -1 )
  {
    do
      ++v2;
    while( _findnext(v3, &file_info) != -1 );
    count = v2;
  }
  sprintf(file_name, aS_scx_1, rge_base_game->prog_info->scenario_dir);
  v4 = _findfirst(file_name, &file_info);
  if( v4 != -1 )
  {
    do
      ++v2;
    while( _findnext(v4, &file_info) != -1 );
    count = v2;
  }
  sprintf(file_name, aS_scn_1, rge_base_game->prog_info->scenario_dir);
  if( v2 > 0 )
  {
    handle = _findfirst(file_name, &file_info);
    if( handle == -1 )
    {
      sprintf(file_name, aS_scx_1, rge_base_game->prog_info->scenario_dir);
      handle = _findfirst(file_name, &file_info);
      looped = 1;
    }
    if( handle != -1 )
    {
      new_scenarios = (RGE_Scenario_File_Entry *)calloc(v2, 0x10Cu);
      v5 = (int)&new_scenarios->scenario_header;
      while( 1 )
      {
        do
        {
          v6 = 0;
          found_in_list = 0;
          if( v1->scenario_num > 0 )
          {
            v7 = v1->scenarios->name;
            v18 = (int)v1->scenarios->name;
            while( strcmp(v7, file_info.name) )
            {
              ++v6;
              v7 = (const char *)(v18 + 268);
              v18 += 268;
              if( v6 >= v1->scenario_num )
                goto LABEL_19;
            }
            v8 = v1->scenarios;
            v9 = v6;
            if( file_info.time_write <= v8[v6].time )
            {
              found_in_list = 1;
              strcpy((char *)(v5 + 4), v8[v9].name);
              *(_DWORD *)(v5 - 4) = v1->scenarios[v9].time;
              *(_DWORD *)v5 = v1->scenarios[v9].scenario_header;
              v1->scenarios[v9].scenario_header = 0;
            }
          }
LABEL_19:
          if( !found_in_list )
          {
            strcpy((char *)(v5 + 4), file_info.name);
            *(_DWORD *)(v5 - 4) = file_info.time_write;
            sprintf(file_name, aSS, rge_base_game->prog_info->scenario_dir, file_info.name);
            v10 = rge_open(file_name, 0x8000);
            v11 = v10;
            if( v10 > -1 )
            {
              rge_read_uncompressed(v10, &version, 4);
              *(_DWORD *)v5 = ((int (__stdcall *)(int))rge_base_game->vfptr->new_scenario_header)(v11);
              rge_close(v11);
            }
          }
          v5 += 268;
        }
        while( _findnext(handle, &file_info) != -1 );
        if( looped )
          break;
        sprintf(file_name, aS_scx_1, rge_base_game->prog_info->scenario_dir);
        handle = _findfirst(file_name, &file_info);
        if( handle == -1 )
          break;
        looped = 1;
      }
      if( v1->scenarios )
      {
        v12 = 0;
        if( v1->scenario_num > 0 )
        {
          v13 = 0;
          do
          {
            v14 = v1->scenarios;
            v15 = v14[v13].scenario_header;
            if( v15 )
            {
              RGE_Scenario_Header::~RGE_Scenario_Header(v14[v13].scenario_header);
              operator delete(v15);
            }
            ++v12;
            ++v13;
          }
          while( v12 < v1->scenario_num );
        }
        free(v1->scenarios);
      }
      v1->scenarios = new_scenarios;
      v1->scenario_num = count;
    }
  }
}

//----- (0048D4D0) --------------------------------------------------------
char *__thiscall RGE_Scenario_File_Info::get_scenario_name(RGE_Scenario_File_Info *this, int id)
{
  char *result; // eax@3

  if( id >= this->scenario_num || id < 0 )
    result = 0;
  else
    result = this->scenarios[id].name;
  return result;
}

//----- (0048D500) --------------------------------------------------------
RGE_Scenario_Header *__thiscall RGE_Scenario_File_Info::get_scenario_info(RGE_Scenario_File_Info *this, int id)
{
  RGE_Scenario_Header *result; // eax@3

  if( id >= this->scenario_num || id < 0 )
    result = 0;
  else
    result = this->scenarios[id].scenario_header;
  return result;
}
