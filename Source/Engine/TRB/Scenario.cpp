
//----- (0052A990) --------------------------------------------------------
void __thiscall TRIBE_Scenario_Header::TRIBE_Scenario_Header(TRIBE_Scenario_Header *this, T_Scenario *scenario_info)
{
  TRIBE_Scenario_Header *v2; // esi@1

  v2 = this;
  RGE_Scenario_Header::RGE_Scenario_Header((RGE_Scenario_Header *)&this->vfptr, (RGE_Scenario *)&scenario_info->vfptr);
  v2->vfptr = (RGE_Scenario_HeaderVtbl *)&TRIBE_Scenario_Header::`vftable';
  v2->any_sp_victory = T_Scenario::any_sp_victory(scenario_info);
  v2->active_player_count = RGE_Scenario::active_player_count((RGE_Scenario *)&scenario_info->vfptr);
}
// 577300: using guessed type __int32 (__thiscall *TRIBE_Scenario_Header::`vftable')(TRIBE_Scenario_Header *__hidden this);

//----- (0052A9F0) --------------------------------------------------------
void __thiscall TRIBE_Scenario_Header::TRIBE_Scenario_Header(TRIBE_Scenario_Header *this, int infile)
{
  TRIBE_Scenario_Header *v2; // esi@1
  int v3; // ecx@1

  v2 = this;
  RGE_Scenario_Header::RGE_Scenario_Header((RGE_Scenario_Header *)&this->vfptr, infile);
  v3 = v2->error_code;
  v2->vfptr = (RGE_Scenario_HeaderVtbl *)&TRIBE_Scenario_Header::`vftable';
  v2->any_sp_victory = 0;
  v2->active_player_count = 0;
  if ( !v3 )
  {
    rge_read_uncompressed(infile, &v2->any_sp_victory, 4);
    rge_read_uncompressed(infile, &v2->active_player_count, 4);
  }
}
// 577300: using guessed type __int32 (__thiscall *TRIBE_Scenario_Header::`vftable')(TRIBE_Scenario_Header *__hidden this);

//----- (0052AA70) --------------------------------------------------------
unsigned int __thiscall TRIBE_Scenario_Header::get_size(TRIBE_Scenario_Header *this)
{
  return RGE_Scenario_Header::get_size((RGE_Scenario_Header *)&this->vfptr) + 8;
}

//----- (0052AA80) --------------------------------------------------------
void __thiscall TRIBE_Scenario_Header::save(TRIBE_Scenario_Header *this, int outfile)
{
  TRIBE_Scenario_Header *v2; // esi@1

  v2 = this;
  RGE_Scenario_Header::save((RGE_Scenario_Header *)&this->vfptr, outfile);
  rge_write_uncompressed(outfile, &v2->any_sp_victory, 4);
  rge_write_uncompressed(outfile, &v2->active_player_count, 4);
}

//----- (0052AAC0) --------------------------------------------------------
void __thiscall T_Scenario::T_Scenario(T_Scenario *this, RGE_Game_World *w)
{
  T_Scenario *v2; // esi@1

  v2 = this;
  RGE_Scenario::RGE_Scenario((RGE_Scenario *)&this->vfptr, w);
  v2->vfptr = (RGE_ScenarioVtbl *)&T_Scenario::`vftable';
  T_Scenario::InitializePlayerValues(v2);
  T_Scenario::InitializeVictoryValues(v2);
  T_Scenario::InitializeFriendlinessValues(v2);
  v2->mp_victory_type = 0;
  v2->victory_score = 900;
  v2->victory_time = 9000;
  v2->victory_all_flag = 0;
  v2->which_player = 0;
  v2->ScenarioOptions[0] = 0;
  v2->ScenarioOptions[1] = 0;
  v2->ScenarioOptions[2] = 0;
  T_Scenario::ClearDisabledTechnologies(v2);
}
// 577308: using guessed type struct RGE_Static_Object *(__thiscall *T_Scenario::`vftable')(T_Scenario *this, int);

//----- (0052AB60) --------------------------------------------------------
T_Scenario *__thiscall T_Scenario::`scalar deleting destructor'(T_Scenario *this, unsigned int __flags)
{
  T_Scenario *v2; // esi@1

  v2 = this;
  T_Scenario::~T_Scenario(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0052AB90) --------------------------------------------------------
void __userpurge T_Scenario::T_Scenario(T_Scenario *this@<ecx>, char *a2@<ebp>, int infile, RGE_Game_World *w)
{
  int v4; // esi@1
  T_Scenario *v5; // edi@1
  double v6; // st7@1
  PlayerName *v7; // ebx@2
  int v8; // ebp@2
  Player_Start_Info *v9; // ebx@5
  Player_Start_Info *v10; // ebp@5
  int v11; // ebx@8
  SP_Victory_Info (*v12)[12]; // ebx@15
  int v13; // ebp@15
  signed int v14; // ebx@20
  int infilea; // [sp+24h] [bp+4h]@8

  v4 = infile;
  v5 = this;
  RGE_Scenario::RGE_Scenario((RGE_Scenario *)&this->vfptr, a2, infile, w);
  v5->vfptr = (RGE_ScenarioVtbl *)&T_Scenario::`vftable';
  w = 0;
  T_Scenario::InitializeVictoryValues(v5);
  T_Scenario::InitializeFriendlinessValues(v5);
  T_Scenario::ClearDisabledTechnologies(v5);
  v6 = v5->Version;
  v5->mp_victory_type = 0;
  v5->victory_score = 900;
  v5->victory_time = 9000;
  v5->victory_all_flag = 0;
  v5->which_player = 0;
  if ( v6 <= 1.13 )
  {
    v7 = v5->player_name;
    v8 = 16;
    do
    {
      rge_read(v8, (int)v5, infile, v7, 256);
      ++v7;
      --v8;
    }
    while ( v8 );
  }
  if ( v5->Version <= 1.13 )
  {
    v11 = (int)v5->PlType;
    v10 = v5->player_info;
    infilea = 16;
    do
    {
      rge_read((int)v10, (int)v5, v4, (void *)(v11 + 128), 4);
      rge_read((int)v10, (int)v5, v4, v10, 16);
      rge_read((int)v10, (int)v5, v4, (void *)v11, 4);
      rge_read((int)v10, (int)v5, v4, (void *)(v11 + 64), 4);
      rge_read((int)v10, (int)v5, v4, (void *)(v11 - 64), 4);
      ++v10;
      v11 += 4;
      --infilea;
    }
    while ( infilea );
  }
  else
  {
    v9 = v5->player_info;
    v10 = (Player_Start_Info *)16;
    do
    {
      rge_read((int)v10, (int)v5, infile, v9, 16);
      ++v9;
      v10 = (Player_Start_Info *)((char *)v10 - 1);
    }
    while ( v10 );
  }
  if ( v5->Version > 1.02 )
    rge_read((int)v10, (int)v5, v4, &w, 4);
  rge_read((int)v10, (int)v5, v4, &v5->victory, 24);
  rge_read((int)v10, (int)v5, v4, &v5->victory_all_flag, 4);
  if ( v5->Version < 1.13 )
  {
    v5->mp_victory_type = 4;
    v5->victory_score = 900;
    v5->victory_time = 9000;
  }
  else
  {
    rge_read((int)v10, (int)v5, v4, &v5->mp_victory_type, 4);
    rge_read((int)v10, (int)v5, v4, &v5->victory_score, 4);
    rge_read((int)v10, (int)v5, v4, &v5->victory_time, 4);
  }
  rge_read((int)v10, (int)v5, v4, v5->Opponent, 1024);
  v12 = v5->sp_victory;
  v13 = 16;
  do
  {
    rge_read(v13, (int)v5, v4, v12, 720);
    ++v12;
    --v13;
  }
  while ( v13 );
  if ( v5->Version > 1.02 )
    rge_read(0, (int)v5, v4, &w, 4);
  if ( LODWORD(v5->Version) == 1065437102 )
  {
    v13 = (int)v5->AlliedVictory;
    v14 = 16;
    do
    {
      rge_read(v13, (int)v5, v4, v5->AlliedVictory, 64);
      --v14;
    }
    while ( v14 );
  }
  if ( v5->Version >= 1.02 )
    rge_read(v13, (int)v5, v4, v5->AlliedVictory, 64);
  if ( v5->Version > 1.03 )
    rge_read(v13, (int)v5, v4, v5->DisabledTechnology, 1280);
  if ( v5->Version > 1.04 )
  {
    if ( v5->Version >= 1.12 )
    {
      rge_read(v13, (int)v5, v4, v5->ScenarioOptions, 12);
    }
    else
    {
      rge_read(v13, (int)v5, v4, v5->ScenarioOptions, 4);
      v5->ScenarioOptions[1] = 0;
      v5->ScenarioOptions[2] = 0;
    }
  }
  if ( v5->Version > 1.05 )
    rge_read(v13, (int)v5, v4, v5->PlayerAge, 64);
  if ( v5->Version > 1.02 )
    rge_read(v13, (int)v5, v4, &w, 4);
  v5->victory.MP_Conquest = v5->victory_conquest;
}
// 577308: using guessed type struct RGE_Static_Object *(__thiscall *T_Scenario::`vftable')(T_Scenario *this, int);

//----- (0052AF20) --------------------------------------------------------
void __thiscall T_Scenario::save(T_Scenario *this, int outfile)
{
  T_Scenario *v2; // edi@1
  Player_Start_Info *v3; // ebx@1
  signed int v4; // ebp@1
  SP_Victory_Info (*v5)[12]; // ebx@3
  signed int v6; // ebp@3
  int checksum; // [sp+10h] [bp-4h]@1

  v2 = this;
  checksum = -99;
  T_Scenario::WriteDisabledTechnologiesToMainSystem(this);
  RGE_Scenario::save((RGE_Scenario *)&v2->vfptr, outfile);
  v3 = v2->player_info;
  v4 = 16;
  do
  {
    rge_write(outfile, v3, 16);
    ++v3;
    --v4;
  }
  while ( v4 );
  rge_write(outfile, &checksum, 4);
  rge_write(outfile, &v2->victory, 24);
  rge_write(outfile, &v2->victory_all_flag, 4);
  rge_write(outfile, &v2->mp_victory_type, 4);
  rge_write(outfile, &v2->victory_score, 4);
  rge_write(outfile, &v2->victory_time, 4);
  rge_write(outfile, v2->Opponent, 1024);
  v5 = v2->sp_victory;
  v6 = 16;
  do
  {
    rge_write(outfile, v5, 720);
    ++v5;
    --v6;
  }
  while ( v6 );
  rge_write(outfile, &checksum, 4);
  rge_write(outfile, v2->AlliedVictory, 64);
  rge_write(outfile, v2->DisabledTechnology, 1280);
  rge_write(outfile, v2->ScenarioOptions, 12);
  rge_write(outfile, v2->PlayerAge, 64);
  rge_write(outfile, &checksum, 4);
}

//----- (0052B080) --------------------------------------------------------
void __thiscall T_Scenario::InitializePlayerValues(T_Scenario *this)
{
  char *v1; // eax@1
  signed int v2; // edx@1
  char *v3; // ecx@1
  int v4; // ebp@2
  char *v5; // [sp+10h] [bp-4h]@1

  v1 = (char *)this->PlType;
  v2 = 0;
  v5 = (char *)this->PlType;
  v3 = (char *)&this->player_info[0].Food;
  do
  {
    v4 = (int)(v3 - 8);
    ++v2;
    v3 += 16;
    v1 += 4;
    *(_DWORD *)v4 = 0;
    *(_DWORD *)(v4 + 4) = 0;
    *(_DWORD *)(v4 + 8) = 0;
    *(_DWORD *)(v4 + 12) = 0;
    *((_DWORD *)v1 + 31) = 0;
    *(_DWORD *)v4 = 0;
    *((_DWORD *)v3 - 5) = 200;
    *((_DWORD *)v3 - 4) = 200;
    *((_DWORD *)v3 - 3) = 150;
    *((_DWORD *)v1 - 1) = 0;
    *((_DWORD *)v1 + 15) = v2;
    *((_DWORD *)v1 - 17) = 4;
    *((_DWORD *)v1 + 3254) = 0;
    *((_DWORD *)v1 + 3596) = 0;
  }
  while ( v2 < 16 );
  *(_DWORD *)v5 = 1;
}

//----- (0052B100) --------------------------------------------------------
void __thiscall T_Scenario::ClearDisabledTechnologies(T_Scenario *this)
{
  memset32(this->DisabledTechnology, 1, 0x140u);
}

//----- (0052B120) --------------------------------------------------------
void __thiscall T_Scenario::InitializeAIInformation(T_Scenario *this)
{
  T_Scenario *v1; // edi@1
  int v2; // esi@1
  RGE_PlayerVtbl *v3; // ebx@2
  char *v4; // ST0C_4@2
  char *v5; // ST08_4@2
  char *v6; // eax@2

  v1 = this;
  v2 = 0;
  do
  {
    v3 = v1->world->players[v2]->vfptr;
    v4 = RGE_Scenario::Get_player_AI((RGE_Scenario *)&v1->vfptr, v2, 1);
    v5 = RGE_Scenario::Get_CityPlan((RGE_Scenario *)&v1->vfptr, v2, 1);
    v6 = RGE_Scenario::Get_BuildList((RGE_Scenario *)&v1->vfptr, v2, 1);
    v3->loadAIInformation(v1->world->players[v2++], v6, v5, v4, 4, -1);
  }
  while ( v2 < 16 );
}

//----- (0052B170) --------------------------------------------------------
void __thiscall T_Scenario::Set_victory_all_flag(T_Scenario *this, int i)
{
  signed int v2; // eax@1

  v2 = i;
  if ( i < 0 )
    v2 = 0;
  if ( v2 > 1 )
    v2 = 1;
  this->victory_all_flag = v2;
}

//----- (0052B190) --------------------------------------------------------
int __thiscall T_Scenario::Get_victory_all_flag(T_Scenario *this)
{
  return this->victory_all_flag;
}

//----- (0052B1A0) --------------------------------------------------------
void __thiscall T_Scenario::SetMPVictory(T_Scenario *this, int i)
{
  this->mp_victory_type = i;
  if ( i != 4 )
    this->victory_conquest = 1;
}

//----- (0052B1C0) --------------------------------------------------------
int __thiscall T_Scenario::GetMPVictory(T_Scenario *this)
{
  return this->mp_victory_type;
}

//----- (0052B1D0) --------------------------------------------------------
void __thiscall T_Scenario::SetVictoryScore(T_Scenario *this, int i)
{
  this->victory_score = i;
}

//----- (0052B1E0) --------------------------------------------------------
int __thiscall T_Scenario::GetVictoryScore(T_Scenario *this)
{
  return this->victory_score;
}

//----- (0052B1F0) --------------------------------------------------------
void __thiscall T_Scenario::SetVictoryTime(T_Scenario *this, int i)
{
  this->victory_time = i;
}

//----- (0052B200) --------------------------------------------------------
int __thiscall T_Scenario::GetVictoryTime(T_Scenario *this)
{
  return this->victory_time;
}

//----- (0052B210) --------------------------------------------------------
void __thiscall T_Scenario::SetSPWhich(T_Scenario *this, int i)
{
  signed int v2; // eax@1

  v2 = i;
  if ( i < 0 )
    v2 = 0;
  if ( v2 > 16 )
    v2 = 15;
  this->which_player = v2;
}

//----- (0052B230) --------------------------------------------------------
int __thiscall T_Scenario::GetSPWhich(T_Scenario *this)
{
  return this->which_player;
}

//----- (0052B240) --------------------------------------------------------
void __thiscall T_Scenario::InitializeVictoryValues(T_Scenario *this)
{
  this->victory.MP_Conquest = 1;
  this->victory.MP_Ruins = 0;
  this->victory.MP_Artifacts = 0;
  this->victory.MP_Discoveries = 0;
  this->victory.MP_Exploration = 0;
  this->victory.MP_Gold = 0;
  memset(this->sp_victory, 0, sizeof(this->sp_victory));
}

//----- (0052B280) --------------------------------------------------------
void __thiscall T_Scenario::ClearSPVictoryCondition(T_Scenario *this, int which)
{
  memset((char *)this->sp_victory + 60 * (which + 12 * this->which_player), 0, 0x3Cu);
}

//----- (0052B2B0) --------------------------------------------------------
void __thiscall T_Scenario::InitializeFriendlinessValues(T_Scenario *this)
{
  memset32(this->Opponent, 3, 0x100u);
}

//----- (0052B2D0) --------------------------------------------------------
void __thiscall T_Scenario::Set_player_attitude(T_Scenario *this, int which, int opponent, int attitude)
{
  if ( (attitude == 1 || attitude == 3 || !attitude) && which >= 0 && which < 16 && opponent >= 0 && opponent < 16 )
    this->Opponent[0].Attitude[opponent + 16 * which] = attitude;
}

//----- (0052B310) --------------------------------------------------------
int __thiscall T_Scenario::Get_player_attitude(T_Scenario *this, int which, int opponent)
{
  int result; // eax@5

  if ( which < 0 || which >= 16 || opponent < 0 || opponent >= 16 )
    result = -1;
  else
    result = this->Opponent[which].Attitude[opponent];
  return result;
}

//----- (0052B340) --------------------------------------------------------
void __thiscall T_Scenario::Set_player_Gold(T_Scenario *this, int which, int g)
{
  if ( which >= 0 && which < 16 )
    (&this->vfptr)[which + 409] = (RGE_ScenarioVtbl *)g;
}

//----- (0052B360) --------------------------------------------------------
void __thiscall T_Scenario::Set_player_Wood(T_Scenario *this, int which, int w)
{
  if ( which >= 0 && which < 16 )
    this->player_info[which].Wood = w;
}

//----- (0052B380) --------------------------------------------------------
void __thiscall T_Scenario::Set_player_Food(T_Scenario *this, int which, int f)
{
  if ( which >= 0 && which < 16 )
    this->player_info[which].Food = f;
}

//----- (0052B3A0) --------------------------------------------------------
void __thiscall T_Scenario::Set_player_Stone(T_Scenario *this, int which, int s)
{
  if ( which >= 0 && which < 16 )
    this->player_info[which].Stone = s;
}

//----- (0052B3C0) --------------------------------------------------------
void __thiscall T_Scenario::Set_player_Info(T_Scenario *this, int which, Player_Start_Info *i)
{
  if ( which >= 0 && which < 16 )
    *(Player_Start_Info *)&(&this->vfptr)[which + 409] = *i;
}

//----- (0052B400) --------------------------------------------------------
void __thiscall T_Scenario::Set_Multi_Conquest(T_Scenario *this, int c)
{
  if ( c )
  {
    this->victory.MP_Conquest = 1;
    RGE_Scenario::Set_conquest_victory((RGE_Scenario *)&this->vfptr, 1);
  }
  else
  {
    this->victory.MP_Conquest = 0;
    RGE_Scenario::Set_conquest_victory((RGE_Scenario *)&this->vfptr, 0);
  }
}

//----- (0052B430) --------------------------------------------------------
void __thiscall T_Scenario::Set_Multi_Ruins(T_Scenario *this, int r)
{
  this->victory.MP_Ruins = r;
}

//----- (0052B440) --------------------------------------------------------
void __thiscall T_Scenario::Set_Multi_Artifacts(T_Scenario *this, int a)
{
  this->victory.MP_Artifacts = a;
}

//----- (0052B450) --------------------------------------------------------
void __thiscall T_Scenario::Set_Multi_Discoveries(T_Scenario *this, int d)
{
  this->victory.MP_Discoveries = d;
}

//----- (0052B460) --------------------------------------------------------
void __thiscall T_Scenario::Set_Multi_Exploration(T_Scenario *this, int e)
{
  this->victory.MP_Exploration = e;
}

//----- (0052B470) --------------------------------------------------------
void __thiscall T_Scenario::Set_Multi_Gold(T_Scenario *this, int g)
{
  this->victory.MP_Gold = g;
}

//----- (0052B480) --------------------------------------------------------
void __thiscall T_Scenario::SetSPRectangle(T_Scenario *this, int VicID, float x1, float y1, float x2, float y2)
{
  *((float *)&this->vfptr + 15 * (VicID + 12 * this->which_player + 114)) = x1;
  this->sp_victory[0][VicID + 12 * this->which_player].y1 = y1;
  this->sp_victory[0][VicID + 12 * this->which_player].x2 = x2;
  this->sp_victory[0][VicID + 12 * this->which_player].y2 = y2;
}

//----- (0052B500) --------------------------------------------------------
void __thiscall T_Scenario::SetSPObjectType(T_Scenario *this, int VicID, int ObjType)
{
  this->sp_victory[0][VicID + 12 * this->which_player].ObjType = ObjType;
}

//----- (0052B530) --------------------------------------------------------
void __thiscall T_Scenario::SetSPPlayerID(T_Scenario *this, int VicID, int PlayerID)
{
  this->sp_victory[0][VicID + 12 * this->which_player].PlayerID = PlayerID;
}

//----- (0052B560) --------------------------------------------------------
void __thiscall T_Scenario::SetSPAllFlag(T_Scenario *this, int VicID, int AllFlag)
{
  this->sp_victory[0][VicID + 12 * this->which_player].AllFlag = AllFlag;
}

//----- (0052B590) --------------------------------------------------------
void __thiscall T_Scenario::SetSPAttribType(T_Scenario *this, int VicID, int AttribType)
{
  this->sp_victory[0][VicID + 12 * this->which_player].AttribType = AttribType;
}

//----- (0052B5C0) --------------------------------------------------------
void __thiscall T_Scenario::SetSPVictoryType(T_Scenario *this, int VicID, int VictoryType)
{
  this->sp_victory[0][VicID + 12 * this->which_player].VictoryType = VictoryType;
}

//----- (0052B5F0) --------------------------------------------------------
void __thiscall T_Scenario::SetSPObject(T_Scenario *this, int VicID, RGE_Static_Object *obj)
{
  if ( obj )
    this->sp_victory[0][VicID + 12 * this->which_player].obj_ID = T_Scenario::get_object_ID(obj) + 1;
}

//----- (0052B630) --------------------------------------------------------
void __thiscall T_Scenario::SetSPDestObjectID(T_Scenario *this, int VicID, RGE_Static_Object *dest_obj)
{
  if ( dest_obj )
    this->sp_victory[0][VicID + 12 * this->which_player].dest_obj_ID = T_Scenario::get_object_ID(dest_obj) + 1;
}

//----- (0052B670) --------------------------------------------------------
void __thiscall T_Scenario::SetSPAmount(T_Scenario *this, int VicID, int Amount)
{
  this->sp_victory[0][VicID + 12 * this->which_player].Amount = Amount;
}

//----- (0052B6A0) --------------------------------------------------------
void __thiscall T_Scenario::SetPlayerAlliedVictory(T_Scenario *this, int which, int OnOff)
{
  this->AlliedVictory[which] = OnOff;
}

//----- (0052B6C0) --------------------------------------------------------
void __thiscall T_Scenario::SetDisabledTechnology(T_Scenario *this, int PlayerId, int which, int tf)
{
  this->DisabledTechnology[0][which + 20 * PlayerId] = tf;
}

//----- (0052B6E0) --------------------------------------------------------
void __thiscall T_Scenario::SetScenarioOption(T_Scenario *this, int option, int value)
{
  this->ScenarioOptions[option] = value;
}

//----- (0052B700) --------------------------------------------------------
void __thiscall T_Scenario::SetPlayerAge(T_Scenario *this, int which, int val)
{
  this->PlayerAge[which] = val;
}

//----- (0052B720) --------------------------------------------------------
int __thiscall T_Scenario::Get_player_Gold(T_Scenario *this, int which)
{
  int result; // eax@3

  if ( which < 0 || which >= 16 )
    result = 0;
  else
    result = this->player_info[which].Gold;
  return result;
}

//----- (0052B740) --------------------------------------------------------
int __thiscall T_Scenario::Get_player_Wood(T_Scenario *this, int which)
{
  int result; // eax@3

  if ( which < 0 || which >= 16 )
    result = 0;
  else
    result = this->player_info[which].Wood;
  return result;
}

//----- (0052B760) --------------------------------------------------------
int __thiscall T_Scenario::Get_player_Food(T_Scenario *this, int which)
{
  int result; // eax@3

  if ( which < 0 || which >= 16 )
    result = 0;
  else
    result = this->player_info[which].Food;
  return result;
}

//----- (0052B780) --------------------------------------------------------
int __thiscall T_Scenario::Get_player_Stone(T_Scenario *this, int which)
{
  int result; // eax@3

  if ( which < 0 || which >= 16 )
    result = 0;
  else
    result = this->player_info[which].Stone;
  return result;
}

//----- (0052B7A0) --------------------------------------------------------
T_Scenario *__thiscall T_Scenario::Get_player_Info(T_Scenario *this, int which)
{
  T_Scenario *result; // eax@3

  if ( which < 0 || which >= 16 )
    result = 0;
  else
    result = (T_Scenario *)((char *)this + 16 * (which + 409));
  return result;
}

//----- (0052B7C0) --------------------------------------------------------
int __thiscall T_Scenario::Get_Multi_Conquest(T_Scenario *this)
{
  return this->victory.MP_Conquest;
}

//----- (0052B7D0) --------------------------------------------------------
int __thiscall T_Scenario::Get_Multi_Ruins(T_Scenario *this)
{
  return this->victory.MP_Ruins;
}

//----- (0052B7E0) --------------------------------------------------------
int __thiscall T_Scenario::Get_Multi_Artifacts(T_Scenario *this)
{
  return this->victory.MP_Artifacts;
}

//----- (0052B7F0) --------------------------------------------------------
int __thiscall T_Scenario::Get_Multi_Discoveries(T_Scenario *this)
{
  return this->victory.MP_Discoveries;
}

//----- (0052B800) --------------------------------------------------------
int __thiscall T_Scenario::Get_Multi_Exploration(T_Scenario *this)
{
  return this->victory.MP_Exploration;
}

//----- (0052B810) --------------------------------------------------------
int __thiscall T_Scenario::Get_Multi_Gold(T_Scenario *this)
{
  return this->victory.MP_Gold;
}

//----- (0052B820) --------------------------------------------------------
void __thiscall T_Scenario::GetSPRectangle(T_Scenario *this, int VicID, float *x1, float *y1, float *x2, float *y2)
{
  *x1 = *((float *)&this->vfptr + 15 * (VicID + 12 * this->which_player + 114));
  *y1 = this->sp_victory[0][VicID + 12 * this->which_player].y1;
  *x2 = this->sp_victory[0][VicID + 12 * this->which_player].x2;
  *y2 = this->sp_victory[0][VicID + 12 * this->which_player].y2;
}

//----- (0052B8B0) --------------------------------------------------------
int __thiscall T_Scenario::GetSPObjectType(T_Scenario *this, int VicID)
{
  return this->sp_victory[this->which_player][VicID].ObjType;
}

//----- (0052B8E0) --------------------------------------------------------
int __thiscall T_Scenario::GetSPPlayerID(T_Scenario *this, int VicID)
{
  return this->sp_victory[this->which_player][VicID].PlayerID;
}

//----- (0052B910) --------------------------------------------------------
int __thiscall T_Scenario::GetSPAllFlag(T_Scenario *this, int VicID)
{
  return this->sp_victory[this->which_player][VicID].AllFlag;
}

//----- (0052B940) --------------------------------------------------------
int __thiscall T_Scenario::GetSPAttribType(T_Scenario *this, int VicID)
{
  return this->sp_victory[this->which_player][VicID].AttribType;
}

//----- (0052B970) --------------------------------------------------------
int __thiscall T_Scenario::GetSPAmount(T_Scenario *this, int VicID)
{
  return this->sp_victory[this->which_player][VicID].Amount;
}

//----- (0052B9A0) --------------------------------------------------------
int __thiscall T_Scenario::GetSPVictoryType(T_Scenario *this, int VicID)
{
  return this->sp_victory[this->which_player][VicID].VictoryType;
}

//----- (0052B9D0) --------------------------------------------------------
RGE_Static_Object *__thiscall T_Scenario::GetSPDestObjectID(T_Scenario *this, int VicID)
{
  return (RGE_Static_Object *)((int (__stdcall *)(int))this->vfptr->get_object_pointer)(this->sp_victory[0][VicID + 12 * this->which_player].dest_obj_ID);
}

//----- (0052BA00) --------------------------------------------------------
RGE_Static_Object *__thiscall T_Scenario::GetSPObject(T_Scenario *this, int VicID)
{
  return (RGE_Static_Object *)((int (__stdcall *)(int))this->vfptr->get_object_pointer)(this->sp_victory[0][VicID + 12 * this->which_player].obj_ID);
}

//----- (0052BA30) --------------------------------------------------------
int __thiscall T_Scenario::GetPlayerAlliedVictory(T_Scenario *this, int which)
{
  return this->AlliedVictory[which];
}

//----- (0052BA40) --------------------------------------------------------
int __thiscall T_Scenario::GetDisabledTechnology(T_Scenario *this, int PlayerId, int which)
{
  return this->DisabledTechnology[PlayerId][which];
}

//----- (0052BA60) --------------------------------------------------------
int __thiscall T_Scenario::GetScenarioOption(T_Scenario *this, int option)
{
  return this->ScenarioOptions[option];
}

//----- (0052BA70) --------------------------------------------------------
int __thiscall T_Scenario::GetPlayerAge(T_Scenario *this, int which)
{
  return this->PlayerAge[which];
}

//----- (0052BA80) --------------------------------------------------------
void __fastcall T_Scenario::update(T_Scenario *this, RGE_Master_Static_Object **a2)
{
  RGE_Timeline::update(this->time_line, a2);
}

//----- (0052BA90) --------------------------------------------------------
void __thiscall T_Scenario::SaveAttributesIntoPlayers(T_Scenario *this)
{
  T_Scenario *v1; // esi@1
  signed int v2; // ebx@1
  signed int v3; // ebp@2
  float amount; // ST04_4@3
  float v5; // ST04_4@3
  float v6; // ST04_4@3
  float v7; // ST04_4@3
  int v8; // edx@3
  RGE_Game_World *v9; // eax@3
  int i; // edi@3
  char *v11; // [sp+14h] [bp-8h]@2

  v1 = this;
  v2 = 1;
  if ( this->world->player_num > 1 )
  {
    v3 = 4585;
    v11 = (char *)this->AlliedVictory;
    do
    {
      amount = (double)T_Scenario::Get_player_Food(v1, v2 - 1);
      RGE_Player::new_attribute_num(v1->world->players[v2], 0, amount);
      v5 = (double)T_Scenario::Get_player_Stone(v1, v2 - 1);
      RGE_Player::new_attribute_num(v1->world->players[v2], 2, v5);
      v6 = (double)T_Scenario::Get_player_Gold(v1, v2 - 1);
      RGE_Player::new_attribute_num(v1->world->players[v2], 3, v6);
      v7 = (double)T_Scenario::Get_player_Wood(v1, v2 - 1);
      RGE_Player::new_attribute_num(v1->world->players[v2], 1, v7);
      v9 = v1->world;
      for ( i = 1; i < v9->player_num; ++i )
      {
        if ( i != v2 )
        {
          LOBYTE(v8) = *((_BYTE *)&v1->vfptr + 4 * (i + v3));
          RGE_Player::set_relation(v9->players[v2], i, v8);
        }
        v9 = v1->world;
      }
      RGE_Player::set_allied_victory(v1->world->players[v2++], *v11);
      v3 += 16;
      v11 += 4;
    }
    while ( v2 < v1->world->player_num );
  }
}

//----- (0052BBC0) --------------------------------------------------------
void __thiscall T_Scenario::Save_victory_conditions_into_players(T_Scenario *this, int SaveAttributes)
{
  T_Scenario *v2; // ebx@1
  RGE_Game_World *v3; // eax@3
  signed int k; // esi@3
  RGE_Game_World *v5; // eax@7
  signed int l; // edi@7
  RGE_Player *v7; // ecx@8
  int v8; // eax@8
  RGE_Victory_Conditions *v9; // esi@8
  int v10; // eax@10
  int v11; // eax@12
  int v12; // eax@14
  int v13; // eax@16
  RGE_Game_World *v14; // eax@20
  signed int m; // edi@20
  RGE_Player *v16; // ecx@21
  int v17; // eax@21
  RGE_Victory_Conditions *v18; // esi@21
  int v19; // eax@23
  int v20; // eax@25
  int v21; // eax@27
  int v22; // eax@29
  RGE_Game_World *v23; // eax@32
  int v24; // esi@33
  RGE_Victory_Conditions *v25; // edi@34
  int v26; // ecx@34
  int v27; // eax@35
  int v28; // eax@37
  RGE_Static_Object *v29; // eax@54
  RGE_Static_Object *(__thiscall *v30)(RGE_Scenario *, int); // ebp@56
  RGE_Static_Object *v31; // ST1C_4@57
  int v32; // eax@57
  RGE_Static_Object *v33; // eax@57
  float v34; // ST1C_4@58
  float v35; // ST18_4@58
  float v36; // ST14_4@58
  float v37; // ST10_4@58
  RGE_Static_Object *v38; // eax@58
  int v39; // ecx@66
  int v40; // eax@69
  RGE_Static_Object *(__thiscall *v41)(RGE_Scenario *, int); // ebp@74
  RGE_Static_Object *v42; // eax@75
  bool v43; // sf@76
  unsigned __int8 v44; // of@76
  int i; // [sp+10h] [bp-10h]@34
  signed int v46; // [sp+14h] [bp-Ch]@33
  int j; // [sp+18h] [bp-8h]@32
  int SaveAttributesa; // [sp+24h] [bp+4h]@33

  v2 = this;
  if ( SaveAttributes )
    T_Scenario::SaveAttributesIntoPlayers(this);
  v3 = v2->world;
  for ( k = 1; k < v3->player_num; ++k )
  {
    RGE_Victory_Conditions::destroy_all(v3->players[k]->victory_conditions);
    v3 = v2->world;
  }
  if ( v2->mp_victory_type == 4 )
  {
    if ( !v2->victory_all_flag )
      goto LABEL_80;
    v5 = v2->world;
    for ( l = 1; l < v5->player_num; ++l )
    {
      v7 = v5->players[l];
      v8 = v2->victory.MP_Exploration;
      v9 = v7->victory_conditions;
      if ( v8 )
        RGE_Victory_Conditions::add_explore(v9, 8, v8, 1);
      v10 = v2->victory.MP_Ruins;
      if ( v10 )
        RGE_Victory_Conditions::add_attributes(v9, 8, 14, v10, 1);
      v11 = v2->victory.MP_Artifacts;
      if ( v11 )
        RGE_Victory_Conditions::add_attributes(v9, 8, 7, v11, 1);
      v12 = v2->victory.MP_Discoveries;
      if ( v12 )
        RGE_Victory_Conditions::add_attributes(v9, 8, 13, v12, 0);
      v13 = v2->victory.MP_Gold;
      if ( v13 )
        RGE_Victory_Conditions::add_attributes(v9, 8, 3, v13, 1);
      v5 = v2->world;
    }
    if ( !v2->victory_all_flag )
    {
LABEL_80:
      v14 = v2->world;
      for ( m = 1; m < v14->player_num; ++m )
      {
        v16 = v14->players[m];
        v17 = v2->victory.MP_Exploration;
        v18 = v16->victory_conditions;
        if ( v17 )
          RGE_Victory_Conditions::add_explore(v18, 8, v17, 1);
        v19 = v2->victory.MP_Ruins;
        if ( v19 )
          RGE_Victory_Conditions::add_attributes(v18, 9, 14, v19, 1);
        v20 = v2->victory.MP_Artifacts;
        if ( v20 )
          RGE_Victory_Conditions::add_attributes(v18, 10, 7, v20, 1);
        v21 = v2->victory.MP_Discoveries;
        if ( v21 )
          RGE_Victory_Conditions::add_attributes(v18, 11, 13, v21, 0);
        v22 = v2->victory.MP_Gold;
        if ( v22 )
          RGE_Victory_Conditions::add_attributes(v18, 12, 3, v22, 1);
        v14 = v2->world;
      }
    }
  }
  v23 = v2->world;
  j = 0;
  if ( v23->player_num - 1 > 0 )
  {
    SaveAttributesa = 114;
    v46 = 1;
    v24 = (int)&v2->sp_victory[0][0].AttribType;
    do
    {
      v25 = v23->players[v46]->victory_conditions;
      v26 = 0;
      i = 0;
      do
      {
        v27 = *(_DWORD *)(v24 - 8);
        if ( !v27 )
          goto LABEL_76;
        if ( v27 == 4 )
        {
          v28 = *(_DWORD *)v24;
          if ( *(_DWORD *)v24 == 6 )
          {
            RGE_Victory_Conditions::add_explore(v25, 1, *(_DWORD *)(v24 - 4), 1);
          }
          else
          {
            switch ( v28 )
            {
              case 4:
                RGE_Victory_Conditions::add_attributes(v25, 1, 11, *(_DWORD *)(v24 - 4), 0);
                break;
              case 3:
                RGE_Victory_Conditions::add_attributes(v25, 1, 0, *(_DWORD *)(v24 - 4), 0);
                break;
              case 2:
                RGE_Victory_Conditions::add_attributes(v25, 1, 2, *(_DWORD *)(v24 - 4), 0);
                break;
              case 1:
                RGE_Victory_Conditions::add_attributes(v25, 1, 1, *(_DWORD *)(v24 - 4), 0);
                break;
              default:
                if ( v28 )
                {
                  if ( v28 == 5 )
                    RGE_Victory_Conditions::add_attributes(v25, 1, 6, *(_DWORD *)(v24 - 4), 0);
                }
                else
                {
                  RGE_Victory_Conditions::add_attributes(v25, 1, 3, *(_DWORD *)(v24 - 4), 0);
                }
                break;
            }
          }
        }
        else
        {
          if ( v27 == 6 )
          {
            RGE_Victory_Conditions::add_attributes(v25, 1, *(_DWORD *)v24, *(_DWORD *)(v24 - 4), 0);
            goto LABEL_76;
          }
          if ( v27 == 5 )
          {
            v29 = v2->vfptr->get_object_pointer((RGE_Scenario *)v2, *(_DWORD *)(v24 + 4));
            RGE_Victory_Conditions::add_capture(v25, 1, v29, 1);
            goto LABEL_76;
          }
          if ( v27 == 3 )
          {
            v30 = v2->vfptr->get_object_pointer;
            if ( v30((RGE_Scenario *)&v2->vfptr, *(_DWORD *)(v24 + 8)) )
            {
              v31 = *(RGE_Static_Object **)(v24 + 8);
              v32 = ((int (__thiscall *)(T_Scenario *))v30)(v2);
              v33 = (RGE_Static_Object *)((int (__thiscall *)(T_Scenario *, _DWORD, int))v30)(
                                           v2,
                                           *(_DWORD *)(v24 + 4),
                                           v32);
              RGE_Victory_Conditions::add_bring(v25, 1, v33, v31);
            }
            else
            {
              v34 = *(float *)(v24 - 12);
              v35 = *(float *)(v24 - 16);
              v36 = *(float *)(v24 - 20);
              v37 = *((float *)&v2->vfptr + 15 * (i + SaveAttributesa));
              v38 = v30((RGE_Scenario *)&v2->vfptr, *(_DWORD *)(v24 + 4));
              RGE_Victory_Conditions::add_bring(v25, 1, v38, v37, v36, v35, v34);
            }
          }
          else if ( v27 == 2 )
          {
            if ( *(float *)(v24 - 16) <= 0.0 )
              RGE_Victory_Conditions::add_create(v25, 1, *(_DWORD *)(v24 - 40), *(_DWORD *)(v24 - 4), 0);
            else
              RGE_Victory_Conditions::add_create(
                v25,
                1,
                *(_DWORD *)(v24 - 40),
                *(_DWORD *)(v24 - 4),
                *((float *)&v2->vfptr + 15 * (v26 + SaveAttributesa)),
                *(float *)(v24 - 20),
                *(float *)(v24 - 16),
                *(float *)(v24 - 12),
                0);
          }
          else
          {
            if ( v27 == 7 )
            {
              TRIBE_Victory_Conditions::add_tech((TRIBE_Victory_Conditions *)v25, 1, *(_DWORD *)v24);
              goto LABEL_76;
            }
            if ( v27 == 1 )
            {
              v39 = *(_DWORD *)(v24 - 40);
              if ( v39 && *(_DWORD *)(v24 - 36) )
              {
                RGE_Victory_Conditions::add_destroy(v25, 1, v39, 0);
                goto LABEL_76;
              }
              v40 = *(_DWORD *)(v24 - 32);
              if ( !v40 )
                goto LABEL_81;
              if ( v39 )
              {
                RGE_Victory_Conditions::add_destroy(v25, 1, v39, *(_DWORD *)(v24 - 4), v2->world->players[v40]);
                goto LABEL_76;
              }
              if ( v40 )
              {
                RGE_Victory_Conditions::add_destroy(v25, 1, v2->world->players[v40]);
              }
              else
              {
LABEL_81:
                v41 = v2->vfptr->get_object_pointer;
                if ( v41((RGE_Scenario *)&v2->vfptr, *(_DWORD *)(v24 + 4)) )
                {
                  v42 = v41((RGE_Scenario *)&v2->vfptr, *(_DWORD *)(v24 + 4));
                  RGE_Victory_Conditions::add_destroy(v25, 1, v42);
                }
              }
            }
          }
        }
LABEL_76:
        v24 += 60;
        v26 = i + 1;
        v44 = __OFSUB__(i + 1, 12);
        v43 = i++ - 11 < 0;
      }
      while ( v43 ^ v44 );
      SaveAttributesa += 12;
      v23 = v2->world;
      ++v46;
      ++j;
    }
    while ( j < v23->player_num - 1 );
  }
}

//----- (0052C080) --------------------------------------------------------
RGE_Static_Object *__thiscall T_Scenario::get_object_pointer(T_Scenario *this, int obj_ID)
{
  RGE_Static_Object *result; // eax@1

  result = 0;
  if ( obj_ID > 0 )
    result = RGE_Game_World::object(this->world, obj_ID - 1);
  return result;
}

//----- (0052C0A0) --------------------------------------------------------
int __stdcall T_Scenario::get_object_ID(RGE_Static_Object *obj)
{
  return obj->id;
}

//----- (0052C0B0) --------------------------------------------------------
void __thiscall T_Scenario::WriteDisabledTechnologiesToMainSystem(T_Scenario *this)
{
  T_Scenario *v1; // ebp@1
  RGE_Game_World *v2; // eax@1
  signed int v3; // ebx@2
  char *v4; // esi@3
  TRIBE_Player *v5; // edi@4

  v1 = this;
  v2 = this->world;
  if ( v2 )
  {
    v3 = 1;
    if ( v2->player_num > 1 )
    {
      v4 = (char *)&this->DisabledTechnology[0][1];
      do
      {
        v5 = (TRIBE_Player *)v2->players[v3];
        if ( v1->ScenarioOptions[0] )
          v2->effects->vfptr->do_effect(v2->effects, 100, (RGE_Player *)v5);
        TRIBE_Player::tech_abling(v5, 88, *(v4 - 4));
        TRIBE_Player::tech_abling(v5, 89, *v4);
        TRIBE_Player::tech_abling(v5, 90, v4[4]);
        TRIBE_Player::tech_abling(v5, 91, v4[8]);
        TRIBE_Player::tech_abling(v5, 94, v4[12]);
        TRIBE_Player::tech_abling(v5, 95, v4[16]);
        TRIBE_Player::tech_abling(v5, 97, v4[20]);
        TRIBE_Player::tech_abling(v5, 98, v4[24]);
        TRIBE_Player::tech_abling(v5, 93, v4[28]);
        TRIBE_Player::tech_abling(v5, 96, v4[32]);
        TRIBE_Player::tech_abling(v5, 92, v4[36]);
        TRIBE_Player::tech_abling(v5, 101, v4[40]);
        TRIBE_Player::tech_abling(v5, 102, v4[44]);
        TRIBE_Player::tech_abling(v5, 103, v4[48]);
        TRIBE_Player::tech_abling(v5, 115, v4[52]);
        TRIBE_Player::tech_abling(v5, 116, v4[56]);
        ++v3;
        v2 = v1->world;
        v4 += 80;
      }
      while ( v3 < v2->player_num );
    }
  }
}

//----- (0052C1E0) --------------------------------------------------------
int __thiscall T_Scenario::any_sp_victory(T_Scenario *this)
{
  T_Scenario *v1; // edi@1
  int v2; // ebx@1
  int v3; // esi@3

  v1 = this;
  v2 = 0;
  while ( !RGE_Scenario::Get_player_Active((RGE_Scenario *)&v1->vfptr, v2) )
  {
LABEL_6:
    if ( ++v2 >= 16 )
      return 0;
  }
  T_Scenario::SetSPWhich(v1, v2);
  v3 = 0;
  while ( !T_Scenario::GetSPVictoryType(v1, v3) )
  {
    if ( ++v3 >= 12 )
      goto LABEL_6;
  }
  return 1;
}

//----- (0052C230) --------------------------------------------------------
void __thiscall T_Scenario::set_player_tech(T_Scenario *this, TRIBE_Player *player)
{
  T_Scenario *v2; // ebp@1
  int v3; // ebx@1
  char *v4; // edi@2

  v2 = this;
  v3 = player->id - 1;
  if ( v3 >= 0 )
  {
    v4 = (char *)this + 80 * v3;
    TRIBE_Player::tech_abling(player, 88, v4[19444]);
    TRIBE_Player::tech_abling(player, 89, v4[19448]);
    TRIBE_Player::tech_abling(player, 90, v4[19452]);
    TRIBE_Player::tech_abling(player, 91, v4[19456]);
    TRIBE_Player::tech_abling(player, 94, v4[19460]);
    TRIBE_Player::tech_abling(player, 95, v4[19464]);
    TRIBE_Player::tech_abling(player, 97, v4[19468]);
    TRIBE_Player::tech_abling(player, 98, v4[19472]);
    TRIBE_Player::tech_abling(player, 93, v4[19476]);
    TRIBE_Player::tech_abling(player, 96, v4[19480]);
    TRIBE_Player::tech_abling(player, 92, v4[19484]);
    TRIBE_Player::tech_abling(player, 101, v4[19488]);
    TRIBE_Player::tech_abling(player, 102, v4[19492]);
    TRIBE_Player::tech_abling(player, 103, v4[19496]);
    TRIBE_Player::tech_abling(player, 115, v4[19500]);
    TRIBE_Player::tech_abling(player, 116, v4[19504]);
    TRIBE_Player_Tech::check_for_new_tech(player->tech_tree);
    if ( v2->ScenarioOptions[0] )
      ((void (__stdcall *)(signed int, TRIBE_Player *))v2->world->effects->vfptr->do_effect)(100, player);
    if ( rge_base_game->prog_mode != 7 )
    {
      switch ( v2->PlayerAge[v3] )
      {
        case 1:
          TRIBE_Player::rev_tech(player, 25);
          break;
        case 2:
          TRIBE_Player::rev_tech(player, 23);
          break;
        case 3:
          TRIBE_Player::rev_tech(player, 24);
          break;
        case 4:
          TRIBE_Player::rev_tech(player, 1);
          break;
        default:
          break;
      }
    }
    if ( (double)*((signed int *)v4 + 4875) == 0.0 )
      *((_DWORD *)player->attributes + 48) = 1065353216;
  }
}
