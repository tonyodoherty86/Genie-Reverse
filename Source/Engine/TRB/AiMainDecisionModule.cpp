
/**
 * @file    Engine\TRB\AiMainDecisionModule.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004E4800) --------------------------------------------------------
void __thiscall TribeMainDecisionAIModule::TribeMainDecisionAIModule(TribeMainDecisionAIModule *this, void *pW, int playerID, char *playerName, TRIBE_Player *aiP, char *buildListName, char *cityPlanName, char *ruleSetName)
{
  TribeMainDecisionAIModule *v8; // esi@1
  int v9; // edi@1
  int v10; // edi@3
  int v11; // edi@5
  int v12; // edi@7

  v8 = this;
  MainDecisionAIModule::MainDecisionAIModule(
    (MainDecisionAIModule *)&this->vfptr,
    pW,
    playerID,
    (RGE_Player *)&aiP->vfptr);
  TribeBuildAIModule::TribeBuildAIModule(&v8->buildAI, pW, playerID);
  TribeConstructionAIModule::TribeConstructionAIModule(&v8->constructionAI, pW, playerID);
  DiplomacyAIModule::DiplomacyAIModule(&v8->diplomacyAI, pW, playerID);
  EmotionalAIModule::EmotionalAIModule(&v8->emotionalAI, pW, playerID);
  TribeInformationAIModule::TribeInformationAIModule(&v8->informationAI, pW, playerID);
  TribeResourceAIModule::TribeResourceAIModule(&v8->resourceAI, pW, playerID, 4, 500, 0, 1000);
  TribeStrategyAIModule::TribeStrategyAIModule(&v8->strategyAI, pW, playerID);
  TribeTacticalAIModule::TribeTacticalAIModule(&v8->tacticalAI, pW, playerID);
  TradeAIModule::TradeAIModule(&v8->tradeAI, pW, playerID);
  v8->firstUpdate = 1;
  v8->veryFirstUpdate = 1;
  v8->aiPlayer = aiP;
  v8->updateDelay = playerID;
  v8->lastDiplomacyUpdateTime = 0;
  v8->lastTacticalUpdateTime = 0;
  v8->lastTributeChatTime = 0;
  v8->tributeChatTimeout = 0;
  v8->waitingOnTribute = 0;
  v8->tributeExpirationTimeout = 0;
  v8->tributeAddressed = 0;
  v8->tributeAmount = 0;
  v8->decidedInitialDiplomacy = 0;
  v8->requiredDiplomacyTributeAmount = 0;
  v8->vfptr = (AIModuleVtbl *)&TribeMainDecisionAIModule::`vftable';
  AIModule::setPlayer((AIModule *)&v8->vfptr, playerID, playerName);
  AIModule::setLogCommonHistory((AIModule *)&v8->vfptr, startLoggingAI != 0);
  TribeBuildAIModule::setMainDecisionAI(&v8->buildAI, v8);
  TribeConstructionAIModule::setMainDecisionAI(&v8->constructionAI, v8);
  DiplomacyAIModule::setMainDecisionAI(&v8->diplomacyAI, (MainDecisionAIModule *)&v8->vfptr);
  EmotionalAIModule::setMainDecisionAI(&v8->emotionalAI, (MainDecisionAIModule *)&v8->vfptr);
  TribeInformationAIModule::setMainDecisionAI(&v8->informationAI, v8);
  TribeResourceAIModule::setMainDecisionAI(&v8->resourceAI, v8);
  TribeStrategyAIModule::setMainDecisionAI(&v8->strategyAI, v8);
  TribeTacticalAIModule::setMainDecisionAI(&v8->tacticalAI, v8);
  TradeAIModule::setMainDecisionAI(&v8->tradeAI, (MainDecisionAIModule *)&v8->vfptr);
  AIModule::setPlayer((AIModule *)&v8->buildAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v8->constructionAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v8->diplomacyAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v8->emotionalAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v8->informationAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v8->resourceAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v8->strategyAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v8->tacticalAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v8->tradeAI.vfptr, playerID, playerName);
  TribeInformationAIModule::addResourceType(&v8->informationAI, 0, 48);
  TribeInformationAIModule::addResourceType(&v8->informationAI, 0, 126);
  TribeInformationAIModule::addResourceType(&v8->informationAI, 0, 59);
  TribeInformationAIModule::addResourceType(&v8->informationAI, 0, 65);
  TribeInformationAIModule::addResourceType(&v8->informationAI, 0, 52);
  TribeInformationAIModule::addResourceType(&v8->informationAI, 0, 53);
  TribeInformationAIModule::addResourceType(&v8->informationAI, 0, 260);
  TribeInformationAIModule::addResourceType(&v8->informationAI, 0, 263);
  TribeInformationAIModule::addResourceType(&v8->informationAI, 0, 50);
  v9 = 111;
  do
    TribeInformationAIModule::addResourceType(&v8->informationAI, 1, v9++);
  while ( v9 <= 114 );
  v10 = 134;
  do
    TribeInformationAIModule::addResourceType(&v8->informationAI, 1, v10++);
  while ( v10 <= 153 );
  v11 = 192;
  do
    TribeInformationAIModule::addResourceType(&v8->informationAI, 1, v11++);
  while ( v11 <= 197 );
  TribeInformationAIModule::addResourceType(&v8->informationAI, 2, 102);
  TribeInformationAIModule::addResourceType(&v8->informationAI, 3, 66);
  v12 = 336;
  do
    TribeInformationAIModule::addResourceType(&v8->informationAI, 3, v12++);
  while ( v12 <= 339 );
  EmotionalAIModule::setOverallState(&v8->emotionalAI, 0);
  memset(v8->tributeGiven, 0, sizeof(v8->tributeGiven));
}
// 5755C8: using guessed type int (__thiscall *TribeMainDecisionAIModule::`vftable')(void *Memory, unsigned int __flags);
// 62C50C: using guessed type int startLoggingAI;

//----- (004E4B60) --------------------------------------------------------
TribeMainDecisionAIModule *__thiscall TribeMainDecisionAIModule::`scalar deleting destructor'(TribeMainDecisionAIModule *this, unsigned int __flags)
{
  TribeMainDecisionAIModule *v2; // esi@1

  v2 = this;
  TribeMainDecisionAIModule::~TribeMainDecisionAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004E4B80) --------------------------------------------------------
void __thiscall TribeMainDecisionAIModule::TribeMainDecisionAIModule(TribeMainDecisionAIModule *this, int playerID, char *playerName, TRIBE_Player *aiP, int infile)
{
  TribeMainDecisionAIModule *v5; // esi@1

  v5 = this;
  MainDecisionAIModule::MainDecisionAIModule(
    (MainDecisionAIModule *)&this->vfptr,
    (RGE_Player *)&aiP->vfptr,
    playerID,
    (RGE_Player *)&aiP->vfptr,
    infile);
  TribeBuildAIModule::TribeBuildAIModule(&v5->buildAI, playerID, infile);
  TribeConstructionAIModule::TribeConstructionAIModule(&v5->constructionAI, playerID, infile);
  DiplomacyAIModule::DiplomacyAIModule(&v5->diplomacyAI, playerID, infile);
  EmotionalAIModule::EmotionalAIModule(&v5->emotionalAI, playerID, infile);
  TribeInformationAIModule::TribeInformationAIModule(&v5->informationAI, playerID, infile);
  TribeResourceAIModule::TribeResourceAIModule(&v5->resourceAI, (int)aiP, playerID, playerID, infile);
  TribeStrategyAIModule::TribeStrategyAIModule(&v5->strategyAI, (int)aiP, playerID, infile);
  TribeTacticalAIModule::TribeTacticalAIModule(&v5->tacticalAI, playerID, infile);
  TradeAIModule::TradeAIModule(&v5->tradeAI, playerID, infile);
  v5->aiPlayer = aiP;
  v5->firstUpdate = 0;
  v5->veryFirstUpdate = 0;
  v5->updateDelay = playerID;
  v5->lastDiplomacyUpdateTime = 0;
  v5->lastTacticalUpdateTime = 0;
  v5->decidedInitialDiplomacy = 0;
  v5->requiredDiplomacyTributeAmount = 0;
  v5->vfptr = (AIModuleVtbl *)&TribeMainDecisionAIModule::`vftable';
  AIModule::setPlayer((AIModule *)&v5->vfptr, playerID, playerName);
  AIModule::setLogCommonHistory((AIModule *)&v5->vfptr, startLoggingAI != 0);
  TribeBuildAIModule::setMainDecisionAI(&v5->buildAI, v5);
  TribeConstructionAIModule::setMainDecisionAI(&v5->constructionAI, v5);
  DiplomacyAIModule::setMainDecisionAI(&v5->diplomacyAI, (MainDecisionAIModule *)&v5->vfptr);
  EmotionalAIModule::setMainDecisionAI(&v5->emotionalAI, (MainDecisionAIModule *)&v5->vfptr);
  TribeInformationAIModule::setMainDecisionAI(&v5->informationAI, v5);
  TribeResourceAIModule::setMainDecisionAI(&v5->resourceAI, v5);
  TribeStrategyAIModule::setMainDecisionAI(&v5->strategyAI, v5);
  TribeTacticalAIModule::setMainDecisionAI(&v5->tacticalAI, v5);
  TradeAIModule::setMainDecisionAI(&v5->tradeAI, (MainDecisionAIModule *)&v5->vfptr);
  AIModule::setPlayer((AIModule *)&v5->buildAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v5->constructionAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v5->diplomacyAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v5->emotionalAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v5->informationAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v5->resourceAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v5->strategyAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v5->tacticalAI.vfptr, playerID, playerName);
  AIModule::setPlayer((AIModule *)&v5->tradeAI.vfptr, playerID, playerName);
  rge_read((int)playerName, playerID, infile, &v5->updateDelay, 4);
  rge_read((int)playerName, playerID, infile, &v5->lastDiplomacyUpdateTime, 4);
  rge_read((int)playerName, playerID, infile, &v5->lastTacticalUpdateTime, 4);
  if ( save_game_version >= 1.2 )
  {
    rge_read((int)playerName, playerID, infile, &v5->lastTributeChatTime, 4);
    rge_read((int)playerName, playerID, infile, &v5->tributeChatTimeout, 4);
    rge_read((int)playerName, playerID, infile, &v5->waitingOnTribute, 4);
    rge_read((int)playerName, playerID, infile, &v5->tributeExpirationTimeout, 4);
    rge_read((int)playerName, playerID, infile, &v5->tributeAddressed, 4);
    rge_read((int)playerName, playerID, infile, &v5->tributeAmount, 4);
  }
  if ( save_game_version < 7.0799999 )
  {
    memset(v5->tributeGiven, 0, sizeof(v5->tributeGiven));
  }
  else
  {
    rge_read((int)playerName, playerID, infile, &v5->decidedInitialDiplomacy, 4);
    rge_read((int)playerName, playerID, infile, &v5->requiredDiplomacyTributeAmount, 4);
    rge_read((int)playerName, playerID, infile, v5->tributeGiven, 36);
  }
}
// 5755C8: using guessed type int (__thiscall *TribeMainDecisionAIModule::`vftable')(void *Memory, unsigned int __flags);
// 58EBCC: using guessed type float save_game_version;
// 62C50C: using guessed type int startLoggingAI;

//----- (004E4EC0) --------------------------------------------------------
void __thiscall TribeMainDecisionAIModule::~TribeMainDecisionAIModule(TribeMainDecisionAIModule *this)
{
  TribeMainDecisionAIModule *v1; // esi@1

  v1 = this;
  this->vfptr = (AIModuleVtbl *)&TribeMainDecisionAIModule::`vftable';
  TradeAIModule::~TradeAIModule(&this->tradeAI);
  TribeTacticalAIModule::~TribeTacticalAIModule(&v1->tacticalAI);
  TribeStrategyAIModule::~TribeStrategyAIModule(&v1->strategyAI);
  TribeResourceAIModule::~TribeResourceAIModule(&v1->resourceAI);
  TribeInformationAIModule::~TribeInformationAIModule(&v1->informationAI);
  EmotionalAIModule::~EmotionalAIModule(&v1->emotionalAI);
  DiplomacyAIModule::~DiplomacyAIModule(&v1->diplomacyAI);
  TribeConstructionAIModule::~TribeConstructionAIModule(&v1->constructionAI);
  TribeBuildAIModule::~TribeBuildAIModule(&v1->buildAI);
  MainDecisionAIModule::~MainDecisionAIModule((MainDecisionAIModule *)&v1->vfptr);
}
// 5755C8: using guessed type int (__thiscall *TribeMainDecisionAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (004E4FA0) --------------------------------------------------------
void __thiscall TribeMainDecisionAIModule::setLogHistory(TribeMainDecisionAIModule *this, int v)
{
  TribeMainDecisionAIModule *v2; // esi@1

  v2 = this;
  this->buildAI.vfptr->setLogHistory((AIModule *)&this->buildAI, v);
  v2->constructionAI.vfptr->setLogHistory((AIModule *)&v2->constructionAI, v);
  v2->diplomacyAI.vfptr->setLogHistory((AIModule *)&v2->diplomacyAI, v);
  v2->emotionalAI.vfptr->setLogHistory((AIModule *)&v2->emotionalAI, v);
  v2->informationAI.vfptr->setLogHistory((AIModule *)&v2->informationAI, v);
  v2->resourceAI.vfptr->setLogHistory((AIModule *)&v2->resourceAI, v);
  v2->strategyAI.vfptr->setLogHistory((AIModule *)&v2->strategyAI, v);
  v2->tacticalAI.vfptr->setLogHistory((AIModule *)&v2->tacticalAI, v);
  v2->tradeAI.vfptr->setLogHistory((AIModule *)&v2->tradeAI, v);
  MainDecisionAIModule::setLogHistory((MainDecisionAIModule *)&v2->vfptr, v);
}

//----- (004E5050) --------------------------------------------------------
int __thiscall TribeMainDecisionAIModule::update(TribeMainDecisionAIModule *this, int timeLimit)
{
  TribeMainDecisionAIModule *v2; // esi@1
  int i; // edi@3
  int v4; // ST6C_4@4
  int v5; // ST68_4@4
  int v6; // eax@4
  float v7; // ST6C_4@9
  float v8; // ST6C_4@11
  float v9; // ST6C_4@13
  float v10; // ST6C_4@15
  int v11; // eax@16
  int v12; // ecx@18
  unsigned int v13; // ebp@20
  int v14; // eax@25
  int v15; // eax@28
  char *v16; // ecx@28
  char *v17; // eax@29
  char *v18; // ST68_4@33
  int v19; // eax@33
  char *v20; // ST68_4@35
  int v21; // eax@35
  int v22; // eax@38
  int v23; // eax@40
  int v24; // eax@40
  RGE_PlayerVtbl *v25; // ebx@40
  int v26; // eax@40
  int v27; // eax@40
  RGE_Player *v28; // edx@40
  unsigned int v29; // ecx@40
  char *v30; // ecx@42
  int v31; // eax@45
  int v32; // eax@45
  RGE_PlayerVtbl *v33; // ebp@45
  int v34; // eax@45
  char *v35; // ST6C_4@46
  int v36; // eax@46
  RGE_Player *v37; // eax@46
  int v38; // eax@48
  RGE_Player *v39; // edx@48
  RGE_Player *v40; // eax@51
  signed int v41; // ebp@52
  TRIBE_World *v42; // ebx@52
  RGE_Player *v43; // edi@53
  signed int v44; // ebp@62
  int j; // ebx@62
  RGE_Player *v46; // edi@63
  signed int v47; // kr0C_4@68
  int v48; // ebx@68
  int v49; // ebx@76
  signed int v50; // ebp@76
  RGE_Player *v51; // edi@77
  int v52; // eax@81
  char *v53; // ecx@82
  int v54; // edx@82
  int v55; // ebp@89
  char *v56; // edi@89
  int v57; // ecx@90
  char *v58; // eax@91
  int v59; // edx@99
  TRIBE_World *v60; // eax@105
  RGE_Player *v61; // ebp@106
  int v62; // eax@108
  char *v63; // ecx@109
  signed int v64; // edi@115
  int v65; // eax@117
  char *v66; // ecx@119
  RGE_PlayerVtbl *v67; // eax@123
  int v68; // eax@132
  signed int v69; // edi@135
  signed int v70; // ebx@135
  RGE_Game_World *v71; // eax@135
  RGE_Player *v72; // ecx@143
  signed int v73; // ebp@143
  RGE_Game_World *v74; // eax@143
  RGE_Player *v75; // edi@148
  RGE_PlayerVtbl *v76; // ebx@148
  RGE_Player *v77; // eax@154
  RGE_Game_World *v78; // ecx@154
  signed int v80; // [sp+68h] [bp-168h]@123
  int v81; // [sp+6Ch] [bp-164h]@28
  int v82; // [sp+6Ch] [bp-164h]@29
  int newEnemy; // [sp+80h] [bp-150h]@52
  int newEnemya; // [sp+80h] [bp-150h]@68
  int newEnemyb; // [sp+80h] [bp-150h]@98
  int newEnemyc; // [sp+80h] [bp-150h]@135
  TRIBE_World *world; // [sp+84h] [bp-14Ch]@52
  int numberNeutralCPs; // [sp+88h] [bp-148h]@52
  int numberNeutralCPsa; // [sp+88h] [bp-148h]@76
  int numberNeutralCPsb; // [sp+88h] [bp-148h]@105
  RGE_Player *temp2; // [sp+8Ch] [bp-144h]@8
  RGE_Player *temp2a; // [sp+8Ch] [bp-144h]@10
  RGE_Player *temp2b; // [sp+8Ch] [bp-144h]@12
  RGE_Player *temp2c; // [sp+8Ch] [bp-144h]@14
  RGE_Player *temp2d; // [sp+8Ch] [bp-144h]@52
  RGE_Player *temp2e; // [sp+8Ch] [bp-144h]@117
  char *swayableCPs; // [sp+90h] [bp-140h]@76
  int swayableCPs_4; // [sp+94h] [bp-13Ch]@76
  int swayableCPs_12; // [sp+9Ch] [bp-134h]@76
  int neutralList[9]; // [sp+A0h] [bp-130h]@56
  char tempString[256]; // [sp+C4h] [bp-10Ch]@28
  int v102; // [sp+1CCh] [bp-4h]@76

  v2 = this;
  if ( !this->player->world->game_state && this->firstUpdate == 1 )
  {
    this->firstUpdate = 0;
    AIModule::logCommonHistory((AIModule *)&this->vfptr, aInitialDiploma);
    for ( i = 1;
          i < v2->player->world->player_num;
          AIModule::logCommonHistory((AIModule *)&v2->vfptr, aPlayerDDislike, i++, v6, v5, v4) )
    {
      v4 = DiplomacyAIModule::stance(&v2->diplomacyAI, i, 1);
      v5 = DiplomacyAIModule::stance(&v2->diplomacyAI, i, 2);
      v6 = DiplomacyAIModule::stance(&v2->diplomacyAI, i, 0);
    }
    v2->strategyAI.vfptr->update((AIModule *)&v2->strategyAI, 0);
    TribeBuildAIModule::initialize(&v2->buildAI);
    TribeInformationAIModule::initialize(&v2->informationAI);
    TribeMainDecisionAIModule::setTributeChat(v2);
    if ( TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 129) == 1
      && !TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 125) )
    {
      v2->waitingOnTribute = 1;
      v2->tributeAmount = 0;
    }
    temp2 = (RGE_Player *)TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 138);
    if ( temp2 )
    {
      v7 = (double)(signed int)temp2;
      ((void (__stdcall *)(_DWORD, _DWORD))v2->player->vfptr->command_add_attribute)(0, LODWORD(v7));
    }
    temp2a = (RGE_Player *)TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 139);
    if ( temp2a )
    {
      v8 = (double)(signed int)temp2a;
      ((void (__stdcall *)(signed int, _DWORD))v2->player->vfptr->command_add_attribute)(3, LODWORD(v8));
    }
    temp2b = (RGE_Player *)TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 140);
    if ( temp2b )
    {
      v9 = (double)(signed int)temp2b;
      ((void (__stdcall *)(signed int, _DWORD))v2->player->vfptr->command_add_attribute)(2, LODWORD(v9));
    }
    temp2c = (RGE_Player *)TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 141);
    if ( temp2c )
    {
      v10 = (double)(signed int)temp2c;
      ((void (__stdcall *)(signed int, _DWORD))v2->player->vfptr->command_add_attribute)(1, LODWORD(v10));
    }
  }
  v11 = v2->updateDelay + 1;
  v2->updateDelay = v11;
  if ( v11 >= 20 )
  {
    v2->strategyAI.vfptr->update((AIModule *)&v2->strategyAI, 0);
    v2->updateDelay = 0;
  }
  v2->informationAI.vfptr->update((AIModule *)&v2->informationAI, 0);
  v12 = (int)&v2->player->world;
  if ( (*(_DWORD *)(*(_DWORD *)v12 + 4) - v2->lastDiplomacyUpdateTime) / 0x3E8 >= 0x3C )
  {
    v2->diplomacyAI.vfptr->update((AIModule *)&v2->diplomacyAI, 0);
    v12 = (int)&v2->player->world;
    v2->lastDiplomacyUpdateTime = *(_DWORD *)(*(_DWORD *)v12 + 4);
  }
  v13 = (*(_DWORD *)(*(_DWORD *)v12 + 4) - v2->lastTributeChatTime) / 0x3E8;
  if ( TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 124) > 0 && !v2->tributeAddressed )
  {
    if ( v13 >= v2->tributeChatTimeout && TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 125) > 0 )
    {
      if ( !v2->waitingOnTribute )
      {
        v2->waitingOnTribute = 1;
        v14 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 127);
        v2->tributeAmount = 0;
        v2->tributeExpirationTimeout = 1000 * v14;
      }
      v2->lastTributeChatTime = v2->player->world->world_time;
      if ( TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 130) == 1 )
      {
        if ( v2->tributeAmount > 0 )
        {
          (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(2306, tempString, 256);
          v15 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 124);
          v16 = tempString;
          v81 = v15 - v2->tributeAmount;
LABEL_33:
          v18 = v16;
          v19 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 128);
          RGE_Player::sendChatMessage(v2->player, v19, 0, v18, v81);
          TribeMainDecisionAIModule::setTributeChat(v2);
          goto LABEL_50;
        }
        (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(2307, tempString, 256);
        v82 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 124);
        v17 = tempString;
      }
      else
      {
        if ( TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 129) != 1 )
        {
LABEL_36:
          TribeMainDecisionAIModule::setTributeChat(v2);
          goto LABEL_50;
        }
        if ( v2->tributeAmount > 0 )
        {
          (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(2308, tempString, 256);
          v81 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 124);
          v16 = tempString;
          goto LABEL_33;
        }
        (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(2309, tempString, 256);
        v82 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 124) - v2->tributeAmount;
        v17 = tempString;
      }
      v20 = v17;
      v21 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 128);
      RGE_Player::sendChatMessage(v2->player, v21, 0, v20, v82);
      goto LABEL_36;
    }
    if ( v2->waitingOnTribute == 1 )
    {
      v22 = v2->tributeExpirationTimeout - v2->player->world->world_time_delta;
      v2->tributeExpirationTimeout = v22;
      if ( v22 > 0 )
      {
        if ( v2->tributeAmount < TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 124) )
          goto LABEL_50;
        if ( TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 129) != 1 )
        {
          if ( TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 130) != 1 )
            goto LABEL_50;
          (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(2302, tempString, 256);
          v38 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 128);
          RGE_Player::sendChatMessage(v2->player, v38, 0, tempString);
          v39 = v2->player;
          v2->waitingOnTribute = 0;
          v2->lastTributeChatTime = v39->world->world_time;
          goto LABEL_49;
        }
        v31 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 128);
        DiplomacyAIModule::setStance(&v2->diplomacyAI, v31, 0, 0);
        v32 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 128);
        DiplomacyAIModule::setStance(&v2->diplomacyAI, v32, 2, 100);
        v33 = v2->aiPlayer->vfptr;
        v34 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 128);
        v33->setDiplomaticStance((RGE_Player *)v2->aiPlayer, v34, 0);
        (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(2303, tempString, 256);
        v30 = tempString;
LABEL_46:
        v35 = v30;
        v36 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 128);
        RGE_Player::sendChatMessage(v2->player, v36, 0, v35);
        v37 = v2->player;
        v2->waitingOnTribute = 0;
        v2->lastTributeChatTime = v37->world->world_time;
LABEL_49:
        v2->tributeAddressed = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 132) == 0;
        goto LABEL_50;
      }
      if ( TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 130) == 1 )
      {
        v23 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 128);
        DiplomacyAIModule::setStance(&v2->diplomacyAI, v23, 0, 100);
        v24 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 128);
        DiplomacyAIModule::setStance(&v2->diplomacyAI, v24, 2, 0);
        v25 = v2->aiPlayer->vfptr;
        v26 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 128);
        v25->setDiplomaticStance((RGE_Player *)v2->aiPlayer, v26, 3);
        (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(2305, tempString, 256);
        v27 = TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 128);
        RGE_Player::sendChatMessage(v2->player, v27, 0, tempString);
        v28 = v2->player;
        v2->waitingOnTribute = 0;
        v29 = v28->world->world_time;
        v2->tributeAddressed = 1;
        v2->lastTributeChatTime = v29;
        goto LABEL_50;
      }
      if ( TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 129) == 1 )
      {
        (*(void (__stdcall **)(signed int, _DWORD, _DWORD))&rge_base_game->vfptr->gap8[24])(2304, tempString, 256);
        v30 = tempString;
        goto LABEL_46;
      }
    }
  }
LABEL_50:
  if ( !v2->decidedInitialDiplomacy )
  {
    v40 = v2->player;
    if ( v40->world->world_time > 0x2710 )
    {
      v41 = 1;
      v2->decidedInitialDiplomacy = 1;
      v42 = (TRIBE_World *)v40->world;
      world = v42;
      newEnemy = 0;
      temp2d = 0;
      numberNeutralCPs = 0;
      if ( v42->player_num > 1 )
      {
        do
        {
          v43 = v42->players[v41];
          if ( RGE_Player::computerPlayer(v43) )
          {
            ++newEnemy;
            if ( v43->vfptr->isAllNeutral(v43) == 1 )
            {
              neutralList[v41] = 1;
              ++numberNeutralCPs;
            }
            else
            {
              neutralList[v41] = 0;
            }
          }
          else
          {
            temp2d = (RGE_Player *)((char *)temp2d + 1);
          }
          ++v41;
        }
        while ( v41 < v42->player_num );
      }
      if ( v42->controllingComputerPlayer == -1 )
      {
        if ( newEnemy == 1 )
        {
          v42->controllingComputerPlayer = v2->player->id;
        }
        else
        {
          v44 = 1;
          for ( j = debug_rand(aCMsdevWorkA_16, 566) % newEnemy + 1; v44 < world->player_num; ++v44 )
          {
            v46 = world->players[v44];
            if ( RGE_Player::computerPlayer(v46) == 1 && !--j )
              world->controllingComputerPlayer = v46->id;
          }
        }
      }
      if ( world->controllingComputerPlayer == LOBYTE(v2->player->id) )
      {
        v47 = newEnemy - (_DWORD)temp2d;
        v48 = (newEnemy - (signed int)temp2d) / 2;
        newEnemya = (newEnemy - (signed int)temp2d) / 2;
        if ( v47 / 2 < 0 )
        {
          v48 = 0;
          newEnemya = 0;
        }
        if ( v48 > numberNeutralCPs )
        {
          v48 = numberNeutralCPs;
          newEnemya = numberNeutralCPs;
        }
        if ( TRIBE_Game::deathMatch((TRIBE_Game *)rge_base_game) == 1 )
        {
          v48 = 0;
          newEnemya = 0;
        }
        if ( numberNeutralCPs >= v48 && numberNeutralCPs > 0 )
        {
          v49 = 0;
          swayableCPs = 0;
          swayableCPs_4 = 0;
          swayableCPs_12 = 0;
          v50 = 1;
          v102 = 0;
          for ( numberNeutralCPsa = 1; v50 < world->player_num; numberNeutralCPsa = ++v50 )
          {
            v51 = world->players[v50];
            if ( RGE_Player::computerPlayer(world->players[v50])
              && neutralList[v50]
              && world->controllingComputerPlayer != v51->id
              && v49 < newEnemya )
            {
              v52 = 0;
              if ( v49 <= 0 )
              {
                v54 = swayableCPs_12;
              }
              else
              {
                v53 = swayableCPs;
                v54 = swayableCPs_12;
                do
                {
                  if ( v52 >= swayableCPs_12 )
                    break;
                  if ( *(_DWORD *)v53 == v50 )
                    goto LABEL_97;
                  ++v52;
                  v53 += 4;
                }
                while ( v52 < v49 );
              }
              if ( v49 > v54 - 1 )
              {
                v55 = v49 + 1;
                v56 = (char *)operator new(4 * (v49 + 1));
                if ( v56 )
                {
                  v57 = 0;
                  if ( swayableCPs_12 > 0 )
                  {
                    v58 = v56;
                    do
                    {
                      if ( v57 >= v55 )
                        break;
                      ++v57;
                      *(_DWORD *)v58 = *(_DWORD *)&v58[swayableCPs - v56];
                      v58 += 4;
                      v49 = swayableCPs_4;
                    }
                    while ( v57 < swayableCPs_12 );
                  }
                  operator delete(swayableCPs);
                  swayableCPs = v56;
                  swayableCPs_12 = v55;
                }
                v50 = numberNeutralCPsa;
              }
              swayableCPs_4 = ++v49;
              *(_DWORD *)&swayableCPs[4 * v49 - 4] = v50;
            }
LABEL_97:
            ;
          }
          newEnemyb = 2000;
          switch ( RGE_Base_Game::difficulty(rge_base_game) )
          {
            case 0:
              v59 = debug_rand(aCMsdevWorkA_16, 622) % 500 + 1400;
              goto LABEL_104;
            case 1:
              v59 = debug_rand(aCMsdevWorkA_16, 623) % 400 + 1000;
              goto LABEL_104;
            case 2:
              v59 = debug_rand(aCMsdevWorkA_16, 624) % 300 + 700;
              goto LABEL_104;
            case 3:
              v59 = debug_rand(aCMsdevWorkA_16, 625) % 200 + 450;
              goto LABEL_104;
            case 4:
              v59 = debug_rand(aCMsdevWorkA_16, 626) % 100 + 300;
LABEL_104:
              newEnemyb = v59;
              break;
            default:
              break;
          }
          v60 = world;
          numberNeutralCPsb = 1;
          if ( world->player_num > 1 )
          {
            while ( 1 )
            {
              v61 = v60->players[numberNeutralCPsb];
              if ( RGE_Player::computerPlayer(v61) && neutralList[numberNeutralCPsb] )
              {
                v62 = 0;
                if ( v49 > 0 )
                {
                  v63 = swayableCPs;
                  while ( v62 < swayableCPs_12 )
                  {
                    if ( *(_DWORD *)v63 == numberNeutralCPsb )
                    {
                      v61->vfptr->sendAICommand(v61, v2->player->id, 7, newEnemyb, 0, 0);
                      newEnemyb *= 2;
                      break;
                    }
                    ++v62;
                    v63 += 4;
                    if ( v62 >= v49 )
                      break;
                  }
                }
                v64 = 1;
                if ( world->player_num > 1 )
                  break;
              }
LABEL_128:
              v60 = world;
              if ( ++numberNeutralCPsb >= world->player_num )
                goto LABEL_129;
            }
            while ( 1 )
            {
              if ( numberNeutralCPsb != v64 )
              {
                temp2e = world->players[v64];
                v65 = RGE_Player::computerPlayer(temp2e);
                if ( !v65 )
                {
                  if ( v49 > 0 )
                  {
                    v66 = swayableCPs;
                    do
                    {
                      if ( v65 >= swayableCPs_12 )
                        break;
                      if ( *(_DWORD *)v66 == numberNeutralCPsb )
                        goto LABEL_124;
                      ++v65;
                      v66 += 4;
                    }
                    while ( v65 < v49 );
                  }
                  v67 = v61->vfptr;
                  v80 = 0;
                  goto LABEL_126;
                }
LABEL_124:
                if ( RGE_Player::computerPlayer(temp2e) == 1 )
                {
                  v67 = v61->vfptr;
                  v80 = 2;
LABEL_126:
                  v67->sendAICommand(v61, v2->player->id, 6, v64, v80, 0);
                  goto LABEL_127;
                }
              }
LABEL_127:
              if ( ++v64 >= world->player_num )
                goto LABEL_128;
            }
          }
LABEL_129:
          v102 = -1;
          if ( swayableCPs )
            operator delete(swayableCPs);
        }
      }
    }
  }
  if ( TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 217) == 1 )
  {
    v68 = 1000 * (TribeTacticalAIModule::strategicNumber(&v2->tacticalAI, 104) - 3);
    if ( v68 < 0 )
      v68 = 0;
    if ( v2->player->world->world_time > v68 )
    {
      TribeTacticalAIModule::setStrategicNumber(&v2->tacticalAI, 217, 0);
      v69 = 1;
      v70 = -1;
      v71 = v2->player->world;
      newEnemyc = -1;
      if ( v71->player_num > 1 )
      {
        while ( RGE_Player::computerPlayer(v71->players[v69]) == 1 )
        {
          ++v69;
          v71 = v2->player->world;
          if ( v69 >= v71->player_num )
            goto LABEL_140;
        }
        v70 = v69;
        newEnemyc = v69;
      }
LABEL_140:
      if ( v70 != -1 )
      {
        if ( !(*(int (__stdcall **)(signed int))&v2->player->vfptr->gap4[20])(v70) )
          ((void (__stdcall *)(_DWORD, signed int, signed int, _DWORD, _DWORD))v2->player->vfptr->sendAICommand)(
            v2->player->id,
            6,
            v70,
            0,
            0);
        v72 = v2->player;
        v73 = 1;
        v74 = v72->world;
        if ( v74->player_num > 1 )
        {
          while ( 1 )
          {
            if ( v73 != v72->id && v73 != v70 )
            {
              v75 = v74->players[v73];
              v76 = v75->vfptr;
              if ( (*(int (__thiscall **)(RGE_Player *, int))&v75->vfptr->gap4[20])(v75, newEnemyc) == 1 )
              {
                ((void (__stdcall *)(_DWORD, signed int, signed int, signed int, _DWORD))v2->player->vfptr->sendAICommand)(
                  v2->player->id,
                  6,
                  v73,
                  2,
                  0);
                if ( RGE_Player::computerPlayer(v75) == 1 )
                  v76->sendAICommand(v75, v2->player->id, 6, v2->player->id, 2, 0);
              }
              else if ( (*(int (__thiscall **)(RGE_Player *, int))&v76->gap4[24])(v75, newEnemyc) == 1 )
              {
                ((void (__stdcall *)(_DWORD, signed int, signed int, _DWORD, _DWORD))v2->player->vfptr->sendAICommand)(
                  v2->player->id,
                  6,
                  v73,
                  0,
                  0);
              }
            }
            v72 = v2->player;
            ++v73;
            v74 = v72->world;
            if ( v73 >= v74->player_num )
              break;
            v70 = newEnemyc;
          }
        }
      }
    }
  }
  v77 = v2->player;
  v78 = v77->world;
  if ( !v78->game_state && v78->currentUpdateComputerPlayer == v77->id )
  {
    v2->tacticalAI.vfptr->update((AIModule *)&v2->tacticalAI, 0);
    v2->lastTacticalUpdateTime = v2->player->world->world_time;
  }
  return 1;
}

//----- (004E5DB0) --------------------------------------------------------
int __thiscall TribeMainDecisionAIModule::save(TribeMainDecisionAIModule *this, int outfile)
{
  TribeMainDecisionAIModule *v2; // esi@1

  v2 = this;
  MainDecisionAIModule::save((MainDecisionAIModule *)&this->vfptr, outfile);
  v2->buildAI.vfptr[1].__vecDelDtor((AIModule *)&v2->buildAI, outfile);
  v2->constructionAI.vfptr[1].__vecDelDtor((AIModule *)&v2->constructionAI, outfile);
  v2->diplomacyAI.vfptr[1].__vecDelDtor((AIModule *)&v2->diplomacyAI, outfile);
  v2->emotionalAI.vfptr[1].__vecDelDtor((AIModule *)&v2->emotionalAI, outfile);
  TribeInformationAIModule::save(&v2->informationAI, outfile);
  v2->resourceAI.vfptr[1].__vecDelDtor((AIModule *)&v2->resourceAI, outfile);
  v2->strategyAI.vfptr[1].__vecDelDtor((AIModule *)&v2->strategyAI, outfile);
  v2->tacticalAI.vfptr[1].__vecDelDtor((AIModule *)&v2->tacticalAI, outfile);
  v2->tradeAI.vfptr[1].__vecDelDtor((AIModule *)&v2->tradeAI, outfile);
  rge_write(outfile, &v2->updateDelay, 4);
  rge_write(outfile, &v2->lastDiplomacyUpdateTime, 4);
  rge_write(outfile, &v2->lastTacticalUpdateTime, 4);
  rge_write(outfile, &v2->lastTributeChatTime, 4);
  rge_write(outfile, &v2->tributeChatTimeout, 4);
  rge_write(outfile, &v2->waitingOnTribute, 4);
  rge_write(outfile, &v2->tributeExpirationTimeout, 4);
  rge_write(outfile, &v2->tributeAddressed, 4);
  rge_write(outfile, &v2->tributeAmount, 4);
  rge_write(outfile, &v2->decidedInitialDiplomacy, 4);
  rge_write(outfile, &v2->requiredDiplomacyTributeAmount, 4);
  rge_write(outfile, v2->tributeGiven, 36);
  return 1;
}

//----- (004E5F30) --------------------------------------------------------
void __thiscall TribeMainDecisionAIModule::kick(TribeMainDecisionAIModule *this, int m)
{
  TribeMainDecisionAIModule *v2; // esi@1

  v2 = this;
  AIModule::logCommonHistory((AIModule *)&this->vfptr, aGotAKickD_, m);
  if ( m == 1 )
    TribeBuildAIModule::skipNextBuildListItem(&v2->buildAI);
  if ( m == 2 )
    TribeBuildAIModule::insert(&v2->buildAI, 83, 1, -1);
  if ( m == 3 )
  {
    AIModule::logCommonHistory((AIModule *)&v2->vfptr, aCurrentBuildLi);
    (*(void (__thiscall **)(int))&v2->buildAI.vfptr[1].gap4[0])((int)&v2->buildAI);
  }
}

//----- (004E5FA0) --------------------------------------------------------
RGE_Static_Object *__thiscall TribeMainDecisionAIModule::addObject(TribeMainDecisionAIModule *this, RGE_Static_Object *bo)
{
  TribeMainDecisionAIModule *v2; // esi@1
  RGE_Static_Object *result; // eax@2

  v2 = this;
  if ( bo )
  {
    TribeTacticalAIModule::addObject(&this->tacticalAI, bo);
    TribeInformationAIModule::addObject(&v2->informationAI, bo);
    result = MainDecisionAIModule::addObject((MainDecisionAIModule *)&v2->vfptr, bo);
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (004E5FE0) --------------------------------------------------------
int __thiscall TribeMainDecisionAIModule::removeObject(TribeMainDecisionAIModule *this, int id)
{
  TribeMainDecisionAIModule *v2; // esi@1

  v2 = this;
  TribeTacticalAIModule::removeObject(&this->tacticalAI, id);
  TribeBuildAIModule::removeBuiltItem(&v2->buildAI, id);
  TribeInformationAIModule::removeObject(&v2->informationAI, id);
  return MainDecisionAIModule::removeObject((MainDecisionAIModule *)&v2->vfptr, id);
}

//----- (004E6020) --------------------------------------------------------
int __thiscall TribeMainDecisionAIModule::objectGroupThatCanPerformAction(TribeMainDecisionAIModule *this, int a)
{
  int result; // eax@2

  switch ( a )
  {
    case 602:
    case 605:
    case 609:
    case 613:
      result = 4;
      break;
    case 619:
    case 620:
      result = 3;
      break;
    default:
      result = MainDecisionAIModule::objectGroupThatCanPerformAction((MainDecisionAIModule *)&this->vfptr, a);
      break;
  }
  return result;
}

//----- (004E6090) --------------------------------------------------------
BOOL __thiscall TribeMainDecisionAIModule::canPerformAction(TribeMainDecisionAIModule *this, int id, int a)
{
  TribeMainDecisionAIModule *v3; // esi@1
  RGE_Static_Object *v4; // edi@1

  v3 = this;
  v4 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->vfptr, id);
  return v4
      && v4->master_obj->object_group == ((int (__thiscall *)(TribeMainDecisionAIModule *, int))v3->vfptr[1].toggleLogHistory)(
                                           v3,
                                           a);
}

//----- (004E60D0) --------------------------------------------------------
void __thiscall TribeMainDecisionAIModule::detask(TribeMainDecisionAIModule *this, int uID)
{
  TribeTacticalAIModule::detask(&this->tacticalAI, uID);
}

//----- (004E60F0) --------------------------------------------------------
int __thiscall TribeMainDecisionAIModule::isMoveable(TribeMainDecisionAIModule *this, int o)
{
  RGE_Static_Object *v2; // eax@1
  __int16 v3; // ax@2
  int result; // eax@14

  v2 = MainDecisionAIModule::object((MainDecisionAIModule *)&this->vfptr, o);
  result = 0;
  if ( v2 )
  {
    v3 = v2->master_obj->object_group;
    if ( v3 != 3
      && v3 != 27
      && v3 != 30
      && v3 != 31
      && v3 != 5
      && v3 != 33
      && v3 != 7
      && v3 != 8
      && v3 != 32
      && v3 != 16
      && v3 != 14
      && v3 != 15 )
    {
      result = 1;
    }
  }
  return result;
}

//----- (004E6160) --------------------------------------------------------
void __thiscall TribeMainDecisionAIModule::updateBuildAIWithObjects(TribeMainDecisionAIModule *this)
{
  TribeMainDecisionAIModule *v1; // esi@1
  int i; // ebx@1
  int v3; // ebp@3
  int *v4; // edi@3
  int j; // eax@4
  RGE_Static_Object *v6; // eax@8
  RGE_Static_Object *v7; // edi@8
  RGE_Map *v8; // eax@10

  v1 = this;
  for ( i = 0; i < v1->objects.numberValue; ++i )
  {
    if ( i > v1->objects.maximumSizeValue - 1 )
    {
      v3 = i + 1;
      v4 = (int *)operator new(4 * i + 4);
      if ( v4 )
      {
        for ( j = 0; j < v1->objects.maximumSizeValue; v4[j - 1] = v1->objects.value[j - 1] )
        {
          if ( j >= v3 )
            break;
          ++j;
        }
        operator delete(v1->objects.value);
        v1->objects.value = v4;
        v1->objects.maximumSizeValue = v3;
      }
    }
    v6 = MainDecisionAIModule::object((MainDecisionAIModule *)&v1->vfptr, v1->objects.value[i]);
    v7 = v6;
    if ( v6 )
    {
      TribeBuildAIModule::addItem(&v1->buildAI, v6, 0);
      if ( v7->master_obj->id == 109 )
      {
        v8 = v1->player->world->map;
        ConstructionAIModule::setReferencePoint(
          (ConstructionAIModule *)&v1->constructionAI.vfptr,
          v8->map_width,
          v8->map_height,
          v7->world_x,
          v7->world_y,
          v7->world_z);
      }
    }
  }
}

//----- (004E6250) --------------------------------------------------------
void __thiscall TribeMainDecisionAIModule::tributeNotify(TribeMainDecisionAIModule *this, int playerID, int resourceID, int amount)
{
  TribeMainDecisionAIModule *v4; // esi@1
  signed int v5; // edi@6
  RGE_Player *v6; // eax@9
  RGE_Game_World *v7; // ecx@9
  RGE_Player *v8; // edx@9
  RGE_PlayerVtbl *v9; // ebp@14
  RGE_Player *v10; // ecx@15
  RGE_PlayerVtbl *v11; // edx@15
  signed int v12; // [sp+28h] [bp-120h]@15
  TribeTacticalAIModule *v13; // [sp+40h] [bp-108h]@5
  RGE_Player *newAlly; // [sp+44h] [bp-104h]@9
  char tempString[256]; // [sp+48h] [bp-100h]@9

  v4 = this;
  if ( this->waitingOnTribute == 1
    && playerID == TribeTacticalAIModule::strategicNumber(&this->tacticalAI, 128)
    && resourceID == 3 )
  {
    v4->tributeAmount += amount;
    return;
  }
  v13 = &v4->tacticalAI;
  if ( playerID != TribeTacticalAIModule::strategicNumber(&v4->tacticalAI, 128) )
  {
    DiplomacyAIModule::changeStance(&v4->diplomacyAI, playerID, 2, amount / 100);
    DiplomacyAIModule::changeStance(&v4->diplomacyAI, playerID, 0, amount / -100);
    v4->tributeGiven[playerID] += amount;
    v5 = 1;
    if ( ((int (__stdcall *)(int))v4->player->vfptr->isNeutral)(playerID) != 1
      || TribeTacticalAIModule::strategicNumber(v13, 217) != 1
      || v4->tributeGiven[playerID] < v4->requiredDiplomacyTributeAmount )
    {
      if ( (*(int (__stdcall **)(int))&v4->player->vfptr->gap4[20])(playerID) == 1 )
      {
        (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(2310, tempString, 256);
        RGE_Player::sendChatMessage(v4->player, playerID, 0, tempString);
      }
    }
    else
    {
      ((void (__stdcall *)(_DWORD, signed int, int, signed int, _DWORD))v4->player->vfptr->sendAICommand)(
        v4->player->id,
        6,
        playerID,
        2,
        0);
      (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(2311, tempString, 256);
      RGE_Player::sendChatMessage(v4->player, playerID, 0, tempString);
      v6 = v4->player;
      v7 = v6->world;
      v8 = v7->players[playerID];
      newAlly = v7->players[playerID];
      if ( v7->player_num > 1 )
      {
        while ( 1 )
        {
          if ( v5 != v6->id && v5 != playerID )
          {
            v9 = v8->vfptr;
            if ( (*(int (__thiscall **)(RGE_Player *, signed int))&v8->vfptr->gap4[24])(v8, v5) == 1 )
            {
              v10 = v4->player;
              v12 = 2;
              v11 = v10->vfptr;
            }
            else
            {
              if ( (*(int (__thiscall **)(RGE_Player *, signed int))&v9->gap4[20])(newAlly, v5) != 1 )
                goto LABEL_19;
              v10 = v4->player;
              v12 = 0;
              v11 = v10->vfptr;
            }
            ((void (__stdcall *)(_DWORD, signed int, signed int, signed int, _DWORD))v11->sendAICommand)(
              v10->id,
              6,
              v5,
              v12,
              0);
          }
LABEL_19:
          v6 = v4->player;
          if ( ++v5 >= v6->world->player_num )
            break;
          v8 = newAlly;
        }
      }
      TribeTacticalAIModule::setStrategicNumber(v13, 217, 0);
    }
  }
}

//----- (004E6490) --------------------------------------------------------
void __thiscall TribeMainDecisionAIModule::revokeTributeAlliance(TribeMainDecisionAIModule *this)
{
  TribeMainDecisionAIModule *v1; // esi@1
  TribeTacticalAIModule *v2; // edi@1
  RGE_PlayerVtbl *v3; // ebx@1
  int v4; // eax@1
  int v5; // eax@2
  int v6; // eax@2
  RGE_PlayerVtbl *v7; // ebx@2
  int v8; // eax@2
  int v9; // eax@2
  char tempString[256]; // [sp+18h] [bp-100h]@2

  v1 = this;
  v2 = &this->tacticalAI;
  v3 = this->player->vfptr;
  v4 = TribeTacticalAIModule::strategicNumber(&this->tacticalAI, 128);
  if ( !(*(int (__thiscall **)(RGE_Player *, int))&v3->gap4[20])(v1->player, v4) )
  {
    v5 = TribeTacticalAIModule::strategicNumber(v2, 128);
    DiplomacyAIModule::setStance(&v1->diplomacyAI, v5, 0, 0);
    v6 = TribeTacticalAIModule::strategicNumber(v2, 128);
    DiplomacyAIModule::setStance(&v1->diplomacyAI, v6, 2, 100);
    v7 = v1->aiPlayer->vfptr;
    v8 = TribeTacticalAIModule::strategicNumber(v2, 128);
    v7->setDiplomaticStance((RGE_Player *)v1->aiPlayer, v8, 3);
    (*(void (__stdcall **)(signed int, char *, signed int))&rge_base_game->vfptr->gap8[24])(2301, tempString, 256);
    v9 = TribeTacticalAIModule::strategicNumber(v2, 128);
    RGE_Player::sendChatMessage(v1->player, v9, 0, tempString);
    v1->waitingOnTribute = 0;
    v1->tributeAddressed = 1;
  }
}

//----- (004E6580) --------------------------------------------------------
void __thiscall TribeMainDecisionAIModule::setTributeChat(TribeMainDecisionAIModule *this)
{
  TribeMainDecisionAIModule *v1; // edi@1
  TribeTacticalAIModule *v2; // esi@1
  signed int v3; // ebx@2
  int v4; // ebx@2
  int v5; // ebx@2

  v1 = this;
  v2 = &this->tacticalAI;
  if ( TribeTacticalAIModule::strategicNumber(&this->tacticalAI, 126) <= 0 )
  {
    v1->tributeChatTimeout = TribeTacticalAIModule::strategicNumber(v2, 125);
  }
  else
  {
    v3 = debug_rand(aCMsdevWorkA_16, 1053);
    v4 = v3 % TribeTacticalAIModule::strategicNumber(v2, 126);
    v5 = v4 - TribeTacticalAIModule::strategicNumber(v2, 126) / 2;
    v1->tributeChatTimeout = TribeTacticalAIModule::strategicNumber(v2, 125) + v5;
  }
}

//----- (004E6600) --------------------------------------------------------
int __userpurge TribeMainDecisionAIModule::processAICommand@<eax>(TribeMainDecisionAIModule *this@<ecx>, double a2@<st0>, int caller, int mType, int p1, int p2, int p3)
{
  TribeMainDecisionAIModule *v7; // ebx@1
  int result; // eax@2
  float v9; // ST10_4@5
  DiplomacyAIModule *v10; // esi@9
  int v11; // eax@13
  RGE_Player *v12; // ebx@13

  v7 = this;
  switch ( mType )
  {
    case 0:
      TribeInformationAIModule::lookAtMap(&this->informationAI, a2);
      return 1;
    case 1:
      if ( caller == this->player->id
        || !RGE_Object_List::find_by_master_id(this->aiPlayer->objects, 84, -1.0, -1.0, 0, 2, 0) )
      {
        return 1;
      }
      v9 = (double)p2;
      ((void (__stdcall *)(int, int, _DWORD, _DWORD))v7->aiPlayer->vfptr[1].__vecDelDtor)(
        caller,
        p1,
        LODWORD(v9),
        v7->aiPlayer->attributes[46]);
      return 1;
    case 2:
    case 3:
      if ( caller == this->player->id )
        return 1;
      TribeTacticalAIModule::processCoopAttack(&this->tacticalAI, caller, p1, p2, p3);
      return 1;
    case 7:
      this->requiredDiplomacyTributeAmount = p1;
      TribeTacticalAIModule::setStrategicNumber(&this->tacticalAI, 217, 1);
      return 1;
    case 6:
      v10 = &this->diplomacyAI;
      DiplomacyAIModule::setChangeable(&this->diplomacyAI, p1, 1);
      if ( p2 )
      {
        if ( p2 == 1 )
        {
          DiplomacyAIModule::setStance(&v7->diplomacyAI, p1, 0, 49);
          DiplomacyAIModule::setStance(&v7->diplomacyAI, p1, 2, 49);
          DiplomacyAIModule::setRelation(&v7->diplomacyAI, p1, 1);
        }
        else if ( p2 == 2 )
        {
          DiplomacyAIModule::setStance(&v7->diplomacyAI, p1, 2, 100);
          DiplomacyAIModule::setRelation(&v7->diplomacyAI, p1, 0);
          if ( RGE_Base_Game::difficulty(rge_base_game) == 4 )
          {
            v11 = RGE_Player::computerPlayer(v7->player->world->players[p1]);
            v12 = v7->player;
            if ( v11 )
            {
              TRIBE_Command::command_allied_victory((TRIBE_Command *)v12->world->commands, v12->id, 0);
              DiplomacyAIModule::setChangeable(v10, p1, 0);
              result = 1;
            }
            else
            {
              TRIBE_Command::command_allied_victory((TRIBE_Command *)v12->world->commands, v12->id, 1);
              DiplomacyAIModule::setChangeable(v10, p1, 0);
              result = 1;
            }
          }
          else
          {
            TRIBE_Command::command_allied_victory((TRIBE_Command *)v7->player->world->commands, v7->player->id, 1);
            DiplomacyAIModule::setChangeable(v10, p1, 0);
            result = 1;
          }
          return result;
        }
      }
      else
      {
        DiplomacyAIModule::setStance(&v7->diplomacyAI, p1, 0, 100);
        DiplomacyAIModule::setRelation(&v7->diplomacyAI, p1, 3);
      }
      DiplomacyAIModule::setChangeable(&v7->diplomacyAI, p1, 0);
      return 1;
    default:
      return 0;
  }
}

//----- (004E6870) --------------------------------------------------------
int __thiscall TribeMainDecisionAIModule::currentScore(TribeMainDecisionAIModule *this, int playerID)
{
  RGE_Game_World *v2; // eax@2
  int result; // eax@3

  if ( playerID < 1 || (v2 = this->player->world, playerID > v2->player_num) )
    result = -1;
  else
    result = RGE_Victory_Conditions::get_victory_points(v2->players[playerID]->victory_conditions);
  return result;
}
