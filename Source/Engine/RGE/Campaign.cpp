
//----- (00423230) --------------------------------------------------------
void __thiscall RGE_Campaign::RGE_Campaign(RGE_Campaign *this, char *in_filename)
{
  RGE_Campaign *v2; // ebx@1
  int v3; // eax@1
  int v4; // esi@1
  signed int v5; // eax@2
  RGE_Scenario_Offset *v6; // eax@3
  int v7; // ecx@3
  int v8; // edx@3

  v2 = this;
  sprintf(this->filename, aSS, rge_base_game->prog_info->campaign_dir, in_filename);
  v3 = _open(v2->filename, 0x8000);
  v4 = v3;
  if( v3 < 0 )
  {
    strcpy(v2->campaign_header.name, aFileNotFound);
    v2->campaign_header.scenario_num = 0;
    v2->campaign_header.version = 0;
    v2->scenario_offsets = 0;
  }
  else
  {
    read(v3, v2, 0x108u);
    v5 = v2->campaign_header.scenario_num;
    if( v5 <= 0 )
    {
      v2->scenario_offsets = 0;
      _close(v4);
    }
    else
    {
      v6 = (RGE_Scenario_Offset *)calloc(v5, 0x208u);
      v7 = v2->campaign_header.scenario_num;
      v8 = v2->campaign_header.scenario_num;
      v2->scenario_offsets = v6;
      read(v4, v6, 8 * (v7 + (v8 << 6)));
      _close(v4);
    }
  }
}

//----- (00423330) --------------------------------------------------------
void __thiscall RGE_Campaign::RGE_Campaign(RGE_Campaign *this, char *campaign_filename, char *campaign_name, int scenario_num, char **scenarios, char **scenarios_name)
{
  RGE_Campaign *v6; // ebp@1
  int v7; // ebx@1
  char **v8; // edx@3
  signed int v9; // eax@3
  const char *v10; // edi@5
  char *campaign_filenamea; // [sp+14h] [bp+4h]@3
  char *scenario_numa; // [sp+1Ch] [bp+Ch]@5

  v6 = this;
  sprintf(this->filename, aSS, rge_base_game->prog_info->campaign_dir, campaign_filename);
  v6->campaign_header.version = *(_DWORD *)a1_00;
  v7 = 0;
  strcpy(v6->campaign_header.name, campaign_name);
  v6->campaign_header.scenario_num = scenario_num;
  if( scenario_num <= 0 )
  {
    v6->scenario_offsets = 0;
    goto LABEL_8;
  }
  v6->scenario_offsets = (RGE_Scenario_Offset *)calloc(scenario_num, 0x208u);
  if( scenario_num <= 0 )
  {
LABEL_8:
    RGE_Campaign::create_file(v6);
    return;
  }
  v8 = scenarios;
  v9 = (char *)scenarios_name - (char *)scenarios;
  campaign_filenamea = (char *)scenario_num;
  while( 1 )
  {
    v10 = *(char **)((char *)v8 + v9);
    ++v8;
    strcpy(v6->scenario_offsets[v7].name, v10);
    scenario_numa = v6->scenario_offsets[v7].file_name;
    ++v7;
    strcpy(scenario_numa, *(v8 - 1));
    if( !--campaign_filenamea )
      break;
    v9 = (char *)scenarios_name - (char *)scenarios;
  }
  RGE_Campaign::create_file(v6);
}

//----- (00423480) --------------------------------------------------------
void __thiscall RGE_Campaign::~RGE_Campaign(RGE_Campaign *this)
{
  RGE_Campaign *v1; // esi@1

  v1 = this;
  if( this->scenario_offsets )
  {
    free(this->scenario_offsets);
    v1->scenario_offsets = 0;
  }
}

//----- (004234B0) --------------------------------------------------------
void __thiscall RGE_Campaign::create_file(RGE_Campaign *this)
{
  RGE_Campaign *v1; // ebp@1
  int v2; // edi@1
  int v3; // eax@2
  signed int v4; // eax@5
  int v5; // esi@5
  __int32 v6; // edi@6
  void *v7; // ebx@6
  int v8; // ecx@7
  bool v9; // sf@7
  unsigned __int8 v10; // of@7
  int v11; // [sp+Ch] [bp-13Ch]@4
  int handle; // [sp+10h] [bp-138h]@1
  int index; // [sp+14h] [bp-134h]@3
  int current_offset; // [sp+18h] [bp-130h]@3
  char tempname[300]; // [sp+1Ch] [bp-12Ch]@5

  v1 = this;
  v2 = _open(this->filename, 33537, 384);
  handle = v2;
  if( v2 >= 0 )
  {
    _write(v2, v1, 0x108u);
    v3 = v1->campaign_header.scenario_num;
    if( v3 > 0 )
    {
      _write(v2, v1->scenario_offsets, 520 * v3);
      index = 0;
      current_offset = 520 * v1->campaign_header.scenario_num + 264;
      if( v1->campaign_header.scenario_num > 0 )
      {
        v11 = 0;
        do
        {
          sprintf(tempname, aSS, rge_base_game->prog_info->scenario_dir, v1->scenario_offsets[v11].file_name);
          v4 = _open(tempname, 0x8000);
          v5 = v4;
          if( v4 > -1 )
          {
            lseek(v4, 0, 2);
            v6 = _tell(v5);
            v7 = calloc(v6, 1u);
            lseek(v5, 0, 0);
            read(v5, v7, v6);
            _write(handle, v7, v6);
            v1->scenario_offsets[v11].offset = current_offset;
            v1->scenario_offsets[v11].size = v6;
            current_offset += v6;
            free(v7);
            _close(v5);
            v2 = handle;
          }
          v8 = v1->campaign_header.scenario_num;
          v10 = __OFSUB__(index + 1, v8);
          v9 = index++ + 1 - v8 < 0;
          ++v11;
        }
        while( v9 ^ v10 );
      }
      lseek(v2, 264, 0);
      _write(v2, v1->scenario_offsets, 520 * v1->campaign_header.scenario_num);
    }
    _close(v2);
  }
}

//----- (00423690) --------------------------------------------------------
int __thiscall RGE_Campaign::open_scenario(RGE_Campaign *this, int scenario)
{
  RGE_Campaign *v2; // ebx@1
  int v3; // eax@3
  int v4; // edi@3
  int result; // eax@4

  v2 = this;
  if( scenario < 0
    || scenario >= this->campaign_header.scenario_num
    || (v3 = _open(this->filename, 0x8000), v4 = v3, v3 < 0) )
  {
    result = -1;
  }
  else
  {
    lseek(v3, v2->scenario_offsets[scenario].offset, 0);
    rge_fake_open(v4, v2->scenario_offsets[scenario].size);
    result = v4;
  }
  return result;
}

//----- (00423710) --------------------------------------------------------
char *__thiscall RGE_Campaign::get_name(RGE_Campaign *this)
{
  return this->campaign_header.name;
}

//----- (00423720) --------------------------------------------------------
int __thiscall RGE_Campaign::scenario_number(RGE_Campaign *this)
{
  return this->campaign_header.scenario_num;
}

//----- (00423730) --------------------------------------------------------
int __thiscall RGE_Campaign::scenario_info(RGE_Campaign *this, char ***scenario_names)
{
  RGE_Campaign *v2; // edi@1
  int v3; // esi@1
  int v4; // ebx@2

  v2 = this;
  v3 = 0;
  *scenario_names = (char **)calloc(this->campaign_header.scenario_num, 4u);
  if( v2->campaign_header.scenario_num > 0 )
  {
    v4 = 0;
    do
    {
      getstring(&(*scenario_names)[v3++], v2->scenario_offsets[v4].name);
      ++v4;
    }
    while( v3 < v2->campaign_header.scenario_num );
  }
  return v2->campaign_header.scenario_num;
}

//----- (004237A0) --------------------------------------------------------
char *__thiscall RGE_Campaign::get_scenario_name(RGE_Campaign *this, int num)
{
  return this->scenario_offsets[num].name;
}
