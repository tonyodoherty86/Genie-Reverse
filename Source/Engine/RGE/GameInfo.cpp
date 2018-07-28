
//----- (0044C5A0) --------------------------------------------------------
void __userpurge RGE_Campaign_Info::RGE_Campaign_Info(RGE_Campaign_Info *this@<ecx>, int a2@<edi>, int infile, RGE_Campaign **campaigns, int campaign_num)
{
  RGE_Campaign_Info *v5; // ebp@1
  int *v6; // edi@1
  RGE_Scenario_Info *v7; // eax@2
  int v8; // ecx@2
  RGE_Campaign **v9; // edi@5
  RGE_Campaign *v10; // ecx@7
  size_t v11; // eax@9
  RGE_Scenario_Info *v12; // eax@9
  int v13; // esi@9
  RGE_Scenario_Info *v14; // ebx@9
  unsigned int v15; // ecx@10
  RGE_Scenario_Info *v16; // esi@10
  char v17; // al@10
  char *v18; // edi@10
  char *v19; // esi@10
  char v20; // cl@10
  unsigned int v21; // eax@11
  RGE_Scenario_Info *v22; // esi@11
  int v23; // eax@13
  int v24; // ecx@13
  int v25; // eax@15
  bool v26; // zf@17
  RGE_Campaign **infilea; // [sp+14h] [bp+4h]@5

  v5 = this;
  rge_read((int)this, a2, infile, this, 255);
  rge_read((int)v5, a2, infile, &v5->current_scenario, 4);
  v6 = &v5->scenario_num;
  rge_read((int)v5, (int)&v5->scenario_num, infile, &v5->scenario_num, 4);
  rge_read((int)v5, (int)&v5->scenario_num, infile, &v5->last_scenario, 4);
  if( v5->scenario_num <= 0 )
  {
    v5->scenario_info = 0;
  }
  else
  {
    v7 = (RGE_Scenario_Info *)calloc(v5->scenario_num, 1u);
    v8 = *v6;
    v5->scenario_info = v7;
    rge_read((int)v5, (int)v6, infile, v7, v8);
  }
  v5->campaign = 0;
  if( campaign_num > 0 )
  {
    v9 = campaigns;
    infilea = campaigns;
    do
    {
      if( !strcmp(RGE_Campaign::get_name(*v9), v5->campaign_name) )
      {
        v10 = *v9;
        v5->campaign = *v9;
        if( v5->scenario_num != RGE_Campaign::scenario_number(v10) )
        {
          if( v5->scenario_num > RGE_Campaign::scenario_number(v5->campaign) )
          {
            v11 = RGE_Campaign::scenario_number(v5->campaign);
            v12 = (RGE_Scenario_Info *)calloc(v11, 1u);
            v13 = v5->scenario_num;
            v14 = v12;
            if( v13 >= RGE_Campaign::scenario_number(v5->campaign) )
            {
              v21 = RGE_Campaign::scenario_number(v5->campaign);
              v22 = v5->scenario_info;
              qmemcpy(v14, v22, 4 * (v21 >> 2));
              v19 = &v22[4 * (v21 >> 2)].scenario_status;
              v18 = &v14[4 * (v21 >> 2)].scenario_status;
              v20 = v21;
            }
            else
            {
              v15 = v13;
              v16 = v5->scenario_info;
              v17 = v15;
              v15 >>= 2;
              qmemcpy(v14, v16, 4 * v15);
              v19 = &v16[4 * v15].scenario_status;
              v18 = &v14[4 * v15].scenario_status;
              v20 = v17;
            }
            qmemcpy(v18, v19, v20 & 3);
            free(v5->scenario_info);
            v9 = infilea;
            v5->scenario_info = v14;
          }
          v23 = RGE_Campaign::scenario_number(v5->campaign);
          v24 = v5->last_scenario;
          v5->scenario_num = v23;
          if( v24 >= v23 )
            v5->last_scenario = v23 - 1;
          v25 = v5->last_scenario;
          if( v5->current_scenario > v25 )
            v5->current_scenario = v25;
        }
      }
      ++v9;
      v26 = campaign_num == 1;
      infilea = v9;
      --campaign_num;
    }
    while( !v26 );
  }
}

//----- (0044C780) --------------------------------------------------------
void __thiscall RGE_Campaign_Info::RGE_Campaign_Info(RGE_Campaign_Info *this, RGE_Campaign *new_campaign)
{
  RGE_Campaign_Info *v2; // ebx@1
  signed int v3; // eax@2
  RGE_Scenario_Info *v4; // eax@3

  v2 = this;
  if( new_campaign )
  {
    this->campaign = new_campaign;
    strcpy(this->campaign_name, RGE_Campaign::get_name(new_campaign));
    v3 = RGE_Campaign::scenario_number(v2->campaign);
    v2->scenario_num = v3;
    if( v3 <= 0 )
    {
      v2->scenario_info = 0;
      v2->current_scenario = -1;
      v2->last_scenario = -1;
    }
    else
    {
      v2->current_scenario = 0;
      v2->last_scenario = 0;
      v4 = (RGE_Scenario_Info *)calloc(v3, 1u);
      v2->scenario_info = v4;
      v4->scenario_status = 2;
    }
  }
  else
  {
    this->campaign = 0;
    strcpy(this->campaign_name, message_in);
    this->current_scenario = 0;
    this->last_scenario = 0;
    this->scenario_num = 0;
    this->scenario_info = 0;
  }
}

//----- (0044C870) --------------------------------------------------------
void __thiscall RGE_Campaign_Info::~RGE_Campaign_Info(RGE_Campaign_Info *this)
{
  RGE_Campaign_Info *v1; // esi@1

  v1 = this;
  if( this->scenario_info )
  {
    free(this->scenario_info);
    v1->scenario_info = 0;
  }
}

//----- (0044C8A0) --------------------------------------------------------
void __thiscall RGE_Campaign_Info::save(RGE_Campaign_Info *this, int outfile)
{
  RGE_Campaign_Info *v2; // esi@1
  int v3; // ebp@1

  v2 = this;
  TDebuggingLog::Log(L, aPifSavingCampa, this->last_scenario, this);
  rge_write(outfile, v2, 255);
  rge_write(outfile, &v2->current_scenario, 4);
  rge_write(outfile, &v2->scenario_num, 4);
  rge_write(outfile, &v2->last_scenario, 4);
  v3 = v2->scenario_num;
  if( v3 > 0 )
    rge_write(outfile, v2->scenario_info, v3);
}

//----- (0044C930) --------------------------------------------------------
void __thiscall RGE_Campaign_Info::rehook_campaigns(RGE_Campaign_Info *this, RGE_Campaign **campaigns, int campaign_num)
{
  int v3; // eax@1
  RGE_Campaign_Info *v4; // ebx@1
  RGE_Campaign **v5; // ebp@2
  RGE_Campaign *v6; // ecx@4
  size_t v7; // eax@5
  RGE_Scenario_Info *v8; // eax@5
  int v9; // esi@5
  RGE_Scenario_Info *v10; // ebp@5
  unsigned int v11; // ecx@6
  RGE_Scenario_Info *v12; // esi@6
  char v13; // al@6
  char *v14; // edi@6
  char *v15; // esi@6
  char v16; // cl@6
  unsigned int v17; // eax@7
  RGE_Scenario_Info *v18; // esi@7
  int v19; // eax@9
  int v20; // ecx@9
  int v21; // eax@11
  bool v22; // zf@13
  RGE_Campaign **campaignsa; // [sp+8h] [bp+4h]@2
  RGE_Campaign **campaign_numa; // [sp+Ch] [bp+8h]@2

  v3 = campaign_num;
  v4 = this;
  this->campaign = 0;
  if( campaign_num > 0 )
  {
    v5 = campaigns;
    campaign_numa = campaigns;
    campaignsa = (RGE_Campaign **)v3;
    do
    {
      if( !strcmp(RGE_Campaign::get_name(*v5), v4->campaign_name) )
      {
        v6 = *v5;
        v4->campaign = *v5;
        if( v4->scenario_num != RGE_Campaign::scenario_number(v6) )
        {
          v7 = RGE_Campaign::scenario_number(v4->campaign);
          v8 = (RGE_Scenario_Info *)calloc(v7, 1u);
          v9 = v4->scenario_num;
          v10 = v8;
          if( v9 >= RGE_Campaign::scenario_number(v4->campaign) )
          {
            v17 = RGE_Campaign::scenario_number(v4->campaign);
            v18 = v4->scenario_info;
            qmemcpy(v10, v18, 4 * (v17 >> 2));
            v15 = &v18[4 * (v17 >> 2)].scenario_status;
            v14 = &v10[4 * (v17 >> 2)].scenario_status;
            v16 = v17;
          }
          else
          {
            v11 = v9;
            v12 = v4->scenario_info;
            v13 = v11;
            v11 >>= 2;
            qmemcpy(v10, v12, 4 * v11);
            v15 = &v12[4 * v11].scenario_status;
            v14 = &v10[4 * v11].scenario_status;
            v16 = v13;
          }
          qmemcpy(v14, v15, v16 & 3);
          free(v4->scenario_info);
          v4->scenario_info = v10;
          v5 = campaign_numa;
        }
        v19 = RGE_Campaign::scenario_number(v4->campaign);
        v20 = v4->last_scenario;
        v4->scenario_num = v19;
        if( v20 >= v19 )
          v4->last_scenario = v19 - 1;
        v21 = v4->last_scenario;
        if( v4->current_scenario > v21 )
          v4->current_scenario = v21;
      }
      ++v5;
      v22 = campaignsa == (RGE_Campaign **)1;
      campaign_numa = v5;
      campaignsa = (RGE_Campaign **)((char *)campaignsa - 1);
    }
    while( !v22 );
  }
}

//----- (0044CA90) --------------------------------------------------------
char __thiscall RGE_Campaign_Info::set_current_scenario(RGE_Campaign_Info *this, int num)
{
  int v2; // edx@3
  char result; // al@4

  if( num < this->scenario_num && this->scenario_info[num].scenario_status )
  {
    v2 = this->last_scenario;
    if( num <= v2 )
    {
      this->current_scenario = num;
      result = 1;
    }
    else
    {
      this->current_scenario = v2;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0044CAD0) --------------------------------------------------------
bool __thiscall RGE_Campaign_Info::verify_campaign_name(RGE_Campaign_Info *this, char *in_campaign_name)
{
  return strcmp(this->campaign_name, in_campaign_name) == 0;
}

//----- (0044CB20) --------------------------------------------------------
int __thiscall RGE_Campaign_Info::get_scenario_list(RGE_Campaign_Info *this, char ***list, int *curr_scenario)
{
  RGE_Campaign_Info *v3; // edi@1
  int v4; // esi@2
  char *v5; // eax@3
  int result; // eax@4

  v3 = this;
  if( this->campaign )
  {
    v4 = 0;
    for( *list = (char **)calloc(this->last_scenario + 1, 4u); v4 <= v3->last_scenario; ++v4 )
    {
      v5 = RGE_Campaign::get_scenario_name(v3->campaign, v4);
      getstring(&(*list)[v4], v5);
    }
    *curr_scenario = v3->current_scenario;
    result = v3->last_scenario + 1;
  }
  else
  {
    result = -1;
    *curr_scenario = -1;
  }
  return result;
}

//----- (0044CBB0) --------------------------------------------------------
int __thiscall RGE_Campaign_Info::get_current_scenario(RGE_Campaign_Info *this)
{
  return this->current_scenario;
}

//----- (0044CBC0) --------------------------------------------------------
void __thiscall RGE_Campaign_Info::notify_of_scenario_complete(RGE_Campaign_Info *this)
{
  RGE_Campaign_Info *v1; // esi@1
  int v2; // eax@1
  int v3; // eax@2
  int v4; // eax@4

  v1 = this;
  v2 = this->current_scenario;
  if( v2 > -1 )
  {
    this->scenario_info[v2].scenario_status = 1;
    v3 = this->current_scenario;
    if( this->last_scenario <= v3 )
    {
      this->last_scenario = v3 + 1;
      RGE_Campaign_Info::set_current_scenario(this, v3 + 1);
    }
    v4 = v1->scenario_num;
    if( v1->last_scenario >= v4 )
      v1->last_scenario = v4 - 1;
    v1->scenario_info[v1->last_scenario].scenario_status = 2;
  }
}

//----- (0044CC20) --------------------------------------------------------
int __thiscall RGE_Campaign_Info::open_scenario(RGE_Campaign_Info *this)
{
  signed int v1; // eax@1
  int result; // eax@2

  v1 = this->current_scenario;
  if( v1 <= -1 )
    result = -1;
  else
    result = RGE_Campaign::open_scenario(this->campaign, v1);
  return result;
}

//----- (0044CC40) --------------------------------------------------------
void __userpurge RGE_Person_Info::RGE_Person_Info(RGE_Person_Info *this@<ecx>, int a2@<edi>, int infile, RGE_Campaign **in_campaigns, int in_campaign_num)
{
  int v5; // ebp@1
  RGE_Person_Info *v6; // esi@1
  int *v7; // ebx@1
  int v8; // edi@1
  RGE_Campaign_Info *v9; // eax@3
  RGE_Campaign_Info *v10; // eax@4

  v5 = infile;
  v6 = this;
  this->campaign_num = in_campaign_num;
  this->campaigns = in_campaigns;
  rge_read(infile, a2, infile, this, 255);
  rge_read(v5, a2, v5, &v6->current_campaign, 4);
  v7 = &v6->campaign_info_num;
  rge_read(v5, a2, v5, &v6->campaign_info_num, 4);
  v8 = 0;
  if( v6->campaign_info_num <= 0 )
  {
    v6->campaign_info = 0;
  }
  else
  {
    v6->campaign_info = (RGE_Campaign_Info **)calloc(v6->campaign_info_num, 4u);
    if( *v7 > 0 )
    {
      do
      {
        v9 = (RGE_Campaign_Info *)operator new(0x114u);
        if( v9 )
          RGE_Campaign_Info::RGE_Campaign_Info(v9, v8, infile, v6->campaigns, v6->campaign_num);
        else
          v10 = 0;
        v6->campaign_info[++v8 - 1] = v10;
      }
      while( v8 < *v7 );
    }
  }
}

//----- (0044CD40) --------------------------------------------------------
void __thiscall RGE_Person_Info::RGE_Person_Info(RGE_Person_Info *this, char *in_name, RGE_Campaign **in_campaigns, int in_campaign_num)
{
  strcpy(this->name, in_name);
  this->campaign_info_num = 0;
  this->campaign_info = 0;
  this->campaigns = in_campaigns;
  this->current_campaign = -1;
  this->campaign_num = in_campaign_num;
}

//----- (0044CDA0) --------------------------------------------------------
void __thiscall RGE_Person_Info::~RGE_Person_Info(RGE_Person_Info *this)
{
  RGE_Person_Info *v1; // edi@1
  int v2; // ebx@2
  RGE_Campaign_Info **v3; // eax@3
  RGE_Campaign_Info *v4; // esi@3

  v1 = this;
  if( this->campaign_info )
  {
    v2 = 0;
    if( this->campaign_info_num > 0 )
    {
      do
      {
        v3 = v1->campaign_info;
        v4 = v3[v2];
        if( v4 )
        {
          RGE_Campaign_Info::~RGE_Campaign_Info(v3[v2]);
          operator delete(v4);
        }
        ++v2;
      }
      while( v2 < v1->campaign_info_num );
    }
    free(v1->campaign_info);
    v1->campaign_info = 0;
    v1->campaign_info_num = 0;
  }
}

//----- (0044CE10) --------------------------------------------------------
void __thiscall RGE_Person_Info::save(RGE_Person_Info *this, int outfile)
{
  RGE_Person_Info *v2; // edi@1
  int i; // esi@1

  v2 = this;
  TDebuggingLog::Log(L, aPifSavingPlaye, this);
  rge_write(outfile, v2, 255);
  rge_write(outfile, &v2->current_campaign, 4);
  rge_write(outfile, &v2->campaign_info_num, 4);
  for( i = 0; i < v2->campaign_info_num; ++i )
    RGE_Campaign_Info::save(v2->campaign_info[i], outfile);
}

//----- (0044CE90) --------------------------------------------------------
void __thiscall RGE_Person_Info::rehook_campaigns(RGE_Person_Info *this, RGE_Campaign **in_campaigns, int in_campaign_num)
{
  RGE_Person_Info *v3; // esi@1
  int v4; // edi@1
  int v5; // eax@1

  v3 = this;
  v4 = 0;
  this->campaign_num = in_campaign_num;
  v5 = this->campaign_info_num;
  this->campaigns = in_campaigns;
  if( v5 > 0 )
  {
    do
      RGE_Campaign_Info::rehook_campaigns(v3->campaign_info[v4++], v3->campaigns, v3->campaign_num);
    while( v4 < v3->campaign_info_num );
  }
}

//----- (0044CEE0) --------------------------------------------------------
RGE_Person_Info *__thiscall RGE_Person_Info::get_name(RGE_Person_Info *this)
{
  return this;
}

//----- (0044CEF0) --------------------------------------------------------
char __thiscall RGE_Person_Info::set_current_campaign(RGE_Person_Info *this, int num)
{
  RGE_Person_Info *v2; // ebx@1
  int v3; // ebp@3
  int v4; // esi@4
  char *v5; // eax@5
  RGE_Campaign_Info **v6; // eax@7
  RGE_Campaign_Info **v7; // esi@7
  RGE_Campaign_Info *v8; // eax@9
  RGE_Campaign_Info *v9; // eax@10
  int v10; // eax@12
  char result; // al@12
  int numa; // [sp+20h] [bp+4h]@7

  v2 = this;
  if( num >= 0 && num < this->campaign_num && (v3 = num, this->campaigns[num]) )
  {
    v4 = 0;
    if( this->campaign_info_num <= 0 )
    {
LABEL_7:
      v6 = (RGE_Campaign_Info **)calloc(v2->campaign_info_num + 1, 4u);
      v7 = v2->campaign_info;
      numa = (int)v6;
      if( v7 )
        qmemcpy(v6, v7, 4 * v2->campaign_info_num);
      free(v2->campaign_info);
      v2->campaign_info = (RGE_Campaign_Info **)numa;
      v8 = (RGE_Campaign_Info *)operator new(0x114u);
      if( v8 )
        RGE_Campaign_Info::RGE_Campaign_Info(v8, v2->campaigns[v3]);
      else
        v9 = 0;
      v2->campaign_info[v2->campaign_info_num] = v9;
      v10 = v2->campaign_info_num;
      v2->current_campaign = v10;
      v2->campaign_info_num = v10 + 1;
      result = 1;
    }
    else
    {
      while( 1 )
      {
        v5 = RGE_Campaign::get_name(v2->campaigns[v3]);
        if( RGE_Campaign_Info::verify_campaign_name(v2->campaign_info[v4], v5) )
          break;
        if( ++v4 >= v2->campaign_info_num )
          goto LABEL_7;
      }
      v2->current_campaign = v4;
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0044D050) --------------------------------------------------------
int __thiscall RGE_Person_Info::get_current_campaign(RGE_Person_Info *this)
{
  RGE_Person_Info *v1; // esi@1
  int v2; // eax@1
  int v3; // edi@3
  char *v4; // eax@4
  int result; // eax@6

  v1 = this;
  v2 = this->current_campaign;
  if( v2 < 0 || v2 >= this->campaign_info_num || (v3 = 0, this->campaign_num <= 0) )
  {
    result = -1;
  }
  else
  {
    while( 1 )
    {
      v4 = RGE_Campaign::get_name(v1->campaigns[v3]);
      if( RGE_Campaign_Info::verify_campaign_name(v1->campaign_info[v1->current_campaign], v4) )
        break;
      if( ++v3 >= v1->campaign_num )
        return -1;
    }
    result = v3;
  }
  return result;
}

//----- (0044D0C0) --------------------------------------------------------
int __thiscall RGE_Person_Info::get_current_scenario(RGE_Person_Info *this)
{
  int v1; // eax@1
  int v2; // eax@2
  int result; // eax@3

  v1 = this->current_campaign;
  if( v1 > -1 && (v2 = v1, this->campaigns[v2]) )
    result = RGE_Campaign_Info::get_current_scenario(this->campaign_info[v2]);
  else
    result = -1;
  return result;
}

//----- (0044D0F0) --------------------------------------------------------
char __thiscall RGE_Person_Info::set_current_scenario(RGE_Person_Info *this, int num)
{
  int v2; // eax@1
  int v3; // eax@2
  char result; // al@3

  v2 = this->current_campaign;
  if( v2 > -1 && (v3 = v2, this->campaigns[v3]) )
    result = RGE_Campaign_Info::set_current_scenario(this->campaign_info[v3], num);
  else
    result = 0;
  return result;
}

//----- (0044D130) --------------------------------------------------------
int __thiscall RGE_Person_Info::get_scenario_list(RGE_Person_Info *this, char ***list, int *current_scenario)
{
  int v3; // eax@1
  int result; // eax@2

  v3 = this->current_campaign;
  if( v3 <= -1 )
    result = 0;
  else
    result = RGE_Campaign_Info::get_scenario_list(this->campaign_info[v3], list, current_scenario);
  return result;
}

//----- (0044D160) --------------------------------------------------------
void __thiscall RGE_Person_Info::notify_of_scenario_complete(RGE_Person_Info *this)
{
  int v1; // eax@1

  v1 = this->current_campaign;
  if( v1 > -1 )
    RGE_Campaign_Info::notify_of_scenario_complete(this->campaign_info[v1]);
}

//----- (0044D180) --------------------------------------------------------
int __thiscall RGE_Person_Info::open_scenario(RGE_Person_Info *this)
{
  int v1; // eax@1
  int result; // eax@2

  v1 = this->current_campaign;
  if( v1 <= -1 )
    result = -1;
  else
    result = RGE_Campaign_Info::open_scenario(this->campaign_info[v1]);
  return result;
}

//----- (0044D1A0) --------------------------------------------------------
void __thiscall RGE_Game_Info::RGE_Game_Info(RGE_Game_Info *this, char *filename)
{
  RGE_Game_Info *v2; // ebx@1
  char *v3; // ebp@1
  int v4; // eax@1
  int v5; // edi@1
  int v6; // esi@3
  RGE_Person_Info *v7; // eax@5
  RGE_Person_Info *v8; // eax@6
  RGE_Person_Info **v9; // ecx@8
  int version; // [sp+10h] [bp-10h]@2
  int v11; // [sp+1Ch] [bp-4h]@5

  v2 = this;
  v3 = (char *)&this->people_num;
  this->people_info = 0;
  this->people_num = 0;
  this->campaign_num = 0;
  this->campaigns = 0;
  RGE_Game_Info::find_campaigns(this);
  strcpy(v2->save_filename, filename);
  v4 = rge_open(filename, 0x8000);
  v5 = v4;
  if( v4 <= -1 || (rge_read((int)v3, v4, v4, &version, 4), version != *(_DWORD *)a1_00) )
  {
    v2->current_person = -1;
    *(_DWORD *)v3 = 0;
    v2->people_info = 0;
    return;
  }
  rge_read((int)v3, v5, v5, v2, 4);
  rge_read((int)v3, v5, v5, v3, 4);
  v6 = 0;
  if( *(_DWORD *)v3 <= 0 )
  {
    v2->people_info = 0;
    goto LABEL_11;
  }
  v2->people_info = (RGE_Person_Info **)calloc(*(_DWORD *)v3, 4u);
  if( *(_DWORD *)v3 <= 0 )
  {
LABEL_11:
    rge_close(v5);
    return;
  }
  do
  {
    v7 = (RGE_Person_Info *)operator new(0x114u);
    v11 = 0;
    if( v7 )
      RGE_Person_Info::RGE_Person_Info(v7, v5, v5, v2->campaigns, v2->campaign_num);
    else
      v8 = 0;
    v9 = v2->people_info;
    ++v6;
    v11 = -1;
    v9[v6 - 1] = v8;
  }
  while( v6 < *(_DWORD *)v3 );
  rge_close(v5);
}

//----- (0044D300) --------------------------------------------------------
void __thiscall RGE_Game_Info::~RGE_Game_Info(RGE_Game_Info *this)
{
  RGE_Game_Info *v1; // esi@1
  int i; // ebp@4
  RGE_Campaign **v3; // eax@5
  RGE_Campaign *v4; // edi@5
  int j; // ebp@10
  RGE_Person_Info **v6; // edx@11
  RGE_Person_Info *v7; // edi@11

  v1 = this;
  if( this->save_filename[0] )
    RGE_Game_Info::save(this, this->save_filename);
  if( v1->campaigns )
  {
    for( i = 0; i < v1->campaign_num; ++i )
    {
      v3 = v1->campaigns;
      v4 = v3[i];
      if( v4 )
      {
        RGE_Campaign::~RGE_Campaign(v3[i]);
        operator delete(v4);
      }
    }
    free(v1->campaigns);
    v1->campaigns = 0;
  }
  if( v1->people_info )
  {
    for( j = 0; j < v1->people_num; ++j )
    {
      v6 = v1->people_info;
      v7 = v6[j];
      if( v7 )
      {
        RGE_Person_Info::~RGE_Person_Info(v6[j]);
        operator delete(v7);
      }
    }
    free(v1->people_info);
    v1->people_info = 0;
  }
}

//----- (0044D3B0) --------------------------------------------------------
void __thiscall RGE_Game_Info::save(RGE_Game_Info *this, char *filename)
{
  RGE_Game_Info *v2; // ebx@1
  int v3; // eax@1
  int v4; // edi@1
  int i; // esi@3

  v2 = this;
  TDebuggingLog::Log(L, aPifCreatingPla);
  strcpy(v2->save_filename, filename);
  v3 = rge_open(filename, 33545, 384);
  v4 = v3;
  if( v3 != -1 )
  {
    rge_write(v3, a1_00, 4);
    rge_write(v4, v2, 4);
    rge_write(v4, &v2->people_num, 4);
    if( v2->people_num > 0 )
    {
      for( i = 0; i < v2->people_num; ++i )
        RGE_Person_Info::save(v2->people_info[i], v4);
    }
    rge_close(v4);
  }
}

//----- (0044D470) --------------------------------------------------------
void __thiscall RGE_Game_Info::find_campaigns(RGE_Game_Info *this)
{
  RGE_Game_Info *v1; // esi@1
  int v2; // ebx@2
  RGE_Campaign **v3; // eax@3
  RGE_Campaign *v4; // edi@3
  __int32 v5; // eax@7
  __int32 v6; // edi@7
  __int32 v7; // edi@9
  signed int v8; // eax@11
  int v9; // edi@11
  __int32 v10; // ebx@12
  RGE_Campaign *v11; // eax@13
  RGE_Campaign *v12; // eax@14
  RGE_Campaign **v13; // edx@16
  __int32 v14; // ebx@17
  int i; // edi@18
  RGE_Campaign *v16; // eax@19
  RGE_Campaign *v17; // eax@20
  RGE_Campaign **v18; // edx@22
  int j; // edi@25
  _finddata_t file_info; // [sp+14h] [bp-228h]@7
  char file_name[260]; // [sp+12Ch] [bp-110h]@7
  int v22; // [sp+238h] [bp-4h]@13

  v1 = this;
  if( this->campaigns )
  {
    v2 = 0;
    if( this->campaign_num > 0 )
    {
      do
      {
        v3 = v1->campaigns;
        v4 = v3[v2];
        if( v4 )
        {
          RGE_Campaign::~RGE_Campaign(v3[v2]);
          operator delete(v4);
        }
        ++v2;
      }
      while( v2 < v1->campaign_num );
    }
    free(v1->campaigns);
    v1->campaigns = 0;
  }
  sprintf(file_name, aS_cpn, rge_base_game->prog_info->campaign_dir);
  v5 = _findfirst(file_name, &file_info);
  v1->campaign_num = 0;
  v6 = v5;
  if( v5 != -1 )
  {
    do
      ++v1->campaign_num;
    while( _findnext(v6, &file_info) != -1 );
  }
  sprintf(file_name, aS_cpx, rge_base_game->prog_info->campaign_dir);
  v7 = _findfirst(file_name, &file_info);
  if( v7 != -1 )
  {
    do
      ++v1->campaign_num;
    while( _findnext(v7, &file_info) != -1 );
  }
  v8 = v1->campaign_num;
  v9 = 0;
  if( v8 <= 0 )
  {
    v1->campaigns = 0;
  }
  else
  {
    v1->campaigns = (RGE_Campaign **)calloc(v8, 4u);
    sprintf(file_name, aS_cpn, rge_base_game->prog_info->campaign_dir);
    v10 = _findfirst(file_name, &file_info);
    if( v10 != -1 )
    {
      do
      {
        v11 = (RGE_Campaign *)operator new(0x20Cu);
        v22 = 0;
        if( v11 )
          RGE_Campaign::RGE_Campaign(v11, file_info.name);
        else
          v12 = 0;
        v13 = v1->campaigns;
        v22 = -1;
        v13[v9++] = v12;
      }
      while( _findnext(v10, &file_info) != -1 );
    }
    sprintf(file_name, aS_cpx, rge_base_game->prog_info->campaign_dir);
    v14 = _findfirst(file_name, &file_info);
    if( v14 != -1 )
    {
      for( i = v9; ; ++i )
      {
        v16 = (RGE_Campaign *)operator new(0x20Cu);
        v22 = 1;
        if( v16 )
          RGE_Campaign::RGE_Campaign(v16, file_info.name);
        else
          v17 = 0;
        v18 = v1->campaigns;
        v22 = -1;
        v18[i] = v17;
        if( _findnext(v14, &file_info) == -1 )
          break;
      }
    }
  }
  for( j = 0; j < v1->people_num; ++j )
    RGE_Person_Info::rehook_campaigns(v1->people_info[j], v1->campaigns, v1->campaign_num);
}

//----- (0044D710) --------------------------------------------------------
char __thiscall RGE_Game_Info::add_new_person(RGE_Game_Info *this, char *name)
{
  RGE_Game_Info *v2; // ebx@1
  RGE_Person_Info **v3; // eax@1
  RGE_Person_Info **v4; // ebp@1
  RGE_Person_Info *v5; // eax@1
  RGE_Person_Info *v6; // eax@2
  int v7; // eax@4

  v2 = this;
  v3 = (RGE_Person_Info **)calloc(this->people_num + 1, 4u);
  v4 = v3;
  qmemcpy(v3, v2->people_info, 4 * v2->people_num);
  free(v2->people_info);
  v2->people_info = v4;
  v5 = (RGE_Person_Info *)operator new(0x114u);
  if( v5 )
    RGE_Person_Info::RGE_Person_Info(v5, name, v2->campaigns, v2->campaign_num);
  else
    v6 = 0;
  v2->people_info[v2->people_num] = v6;
  v7 = v2->people_num;
  v2->current_person = v7;
  v2->people_num = v7 + 1;
  return 1;
}

//----- (0044D7D0) --------------------------------------------------------
char __thiscall RGE_Game_Info::set_current_person(RGE_Game_Info *this, int num)
{
  char result; // al@2

  if( num >= this->people_num )
  {
    this->current_person = -1;
    result = 0;
  }
  else
  {
    this->current_person = num;
    result = 1;
  }
  return result;
}

//----- (0044D7F0) --------------------------------------------------------
char __thiscall RGE_Game_Info::set_current_campaign(RGE_Game_Info *this, int num)
{
  int v2; // eax@1
  char result; // al@3

  v2 = this->current_person;
  if( this->current_person >= this->people_num || v2 < 0 )
    result = 0;
  else
    result = RGE_Person_Info::set_current_campaign(this->people_info[v2], num);
  return result;
}

//----- (0044D820) --------------------------------------------------------
char __thiscall RGE_Game_Info::set_current_scenario(RGE_Game_Info *this, int num)
{
  int v2; // eax@1
  char result; // al@3

  v2 = this->current_person;
  if( this->current_person < 0 || v2 >= this->people_num )
    result = 0;
  else
    result = RGE_Person_Info::set_current_scenario(this->people_info[v2], num);
  return result;
}

//----- (0044D850) --------------------------------------------------------
int __thiscall RGE_Game_Info::get_people_list(RGE_Game_Info *this, char ***list, int *current_player)
{
  RGE_Game_Info *v3; // ebx@1
  int v4; // eax@1
  int v5; // esi@2
  RGE_Person_Info *v6; // eax@3

  v3 = this;
  v4 = this->people_num;
  if( v4 > 0 )
  {
    v5 = 0;
    for( *list = (char **)calloc(v4, 4u); v5 < v3->people_num; ++v5 )
    {
      v6 = RGE_Person_Info::get_name(v3->people_info[v5]);
      getstring(&(*list)[v5], v6->name);
    }
    *current_player = v3->current_person;
  }
  return v3->people_num;
}

//----- (0044D8C0) --------------------------------------------------------
int __thiscall RGE_Game_Info::get_campaign_list(RGE_Game_Info *this, char ***list, int *current_campaign)
{
  RGE_Game_Info *v3; // edi@1
  int v4; // eax@1
  int v5; // esi@2
  char *v6; // eax@3
  int v7; // eax@4

  v3 = this;
  v4 = this->campaign_num;
  if( v4 > 0 )
  {
    v5 = 0;
    for( *list = (char **)calloc(v4, 4u); v5 < v3->campaign_num; ++v5 )
    {
      v6 = RGE_Campaign::get_name(v3->campaigns[v5]);
      getstring(&(*list)[v5], v6);
    }
    v7 = v3->current_person;
    if( v3->current_person < v3->people_num && v7 >= 0 )
      *current_campaign = RGE_Person_Info::get_current_campaign(v3->people_info[v7]);
  }
  return v3->campaign_num;
}

//----- (0044D940) --------------------------------------------------------
int __thiscall RGE_Game_Info::get_scenario_list(RGE_Game_Info *this, char ***list, int *current_scenario)
{
  RGE_Game_Info *v3; // esi@1
  int v4; // eax@1
  int result; // eax@3

  v3 = this;
  v4 = this->current_person;
  if( this->current_person >= this->people_num || v4 < 0 )
  {
    result = -1;
    *current_scenario = -1;
  }
  else
  {
    *current_scenario = RGE_Person_Info::get_current_scenario(this->people_info[v4]);
    result = RGE_Person_Info::get_scenario_list(v3->people_info[v3->current_person], list, current_scenario);
  }
  return result;
}

//----- (0044D990) --------------------------------------------------------
int __thiscall RGE_Game_Info::get_current_scenario(RGE_Game_Info *this)
{
  int v1; // eax@1
  int result; // eax@3

  v1 = this->current_person;
  if( this->current_person >= this->people_num || v1 < 0 )
    result = -1;
  else
    result = RGE_Person_Info::get_current_scenario(this->people_info[v1]);
  return result;
}

//----- (0044D9B0) --------------------------------------------------------
int __thiscall RGE_Game_Info::get_current_campaign(RGE_Game_Info *this)
{
  int v1; // eax@1
  int result; // eax@3

  v1 = this->current_person;
  if( this->current_person >= this->people_num || v1 < 0 )
    result = -1;
  else
    result = RGE_Person_Info::get_current_campaign(this->people_info[v1]);
  return result;
}

//----- (0044D9D0) --------------------------------------------------------
int __thiscall RGE_Game_Info::get_current_player(RGE_Game_Info *this)
{
  return this->current_person;
}

//----- (0044D9E0) --------------------------------------------------------
RGE_Person_Info *__thiscall RGE_Game_Info::get_current_player_name(RGE_Game_Info *this)
{
  RGE_Person_Info *result; // eax@2

  if( this->current_person >= 0 )
    result = RGE_Person_Info::get_name(this->people_info[this->current_person]);
  else
    result = 0;
  return result;
}

//----- (0044DA00) --------------------------------------------------------
void __thiscall RGE_Game_Info::notify_of_scenario_complete(RGE_Game_Info *this)
{
  RGE_Game_Info *v1; // esi@1
  int v2; // eax@1

  v1 = this;
  v2 = this->current_person;
  if( this->current_person < this->people_num && v2 >= 0 )
    RGE_Person_Info::notify_of_scenario_complete(this->people_info[v2]);
  RGE_Game_Info::save(v1, v1->save_filename);
}

//----- (0044DA30) --------------------------------------------------------
int __thiscall RGE_Game_Info::open_scenario(RGE_Game_Info *this)
{
  int v1; // eax@1
  int result; // eax@3

  v1 = this->current_person;
  if( this->current_person >= this->people_num || v1 < 0 )
    result = -1;
  else
    result = RGE_Person_Info::open_scenario(this->people_info[v1]);
  return result;
}

//----- (0044DA50) --------------------------------------------------------
void __thiscall RGE_Game_Info::remove_player(RGE_Game_Info *this, int id)
{
  RGE_Game_Info *v2; // esi@1
  RGE_Person_Info **v3; // eax@3
  RGE_Person_Info *v4; // ebx@3
  int i; // eax@5
  int v6; // ecx@7
  int v7; // edx@7

  v2 = this;
  if( id >= 0 && id < this->people_num )
  {
    v3 = this->people_info;
    v4 = v3[id];
    if( v4 )
    {
      RGE_Person_Info::~RGE_Person_Info(v3[id]);
      operator delete(v4);
    }
    for( i = id; i < v2->people_num - 1; v2->people_info[i - 1] = v2->people_info[i] )
      ++i;
    v6 = v2->current_person;
    v7 = v2->people_num - 1;
    v2->people_num = v7;
    if( v6 == v7 )
      v2->current_person = v7 - 1;
  }
}
