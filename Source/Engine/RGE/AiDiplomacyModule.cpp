
//----- (0040BEC0) --------------------------------------------------------
void __thiscall DiplomacyAIModule::DiplomacyAIModule(DiplomacyAIModule *this, void *pW, int playerID)
{
  DiplomacyAIModule *v3; // esi@1
  signed int v4; // eax@1
  int *v5; // ecx@1

  v3 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aDiplomacyAi, 1003, playerID, pW);
  v4 = 0;
  v3->vfptr = (AIModuleVtbl *)&DiplomacyAIModule::`vftable';
  v3->md = 0;
  v5 = v3->likeTable;
  do
  {
    *(v5 - 10) = 49;
    *v5 = 49;
    v3->changeableTable[v4++] = 1;
    ++v5;
  }
  while( v4 <= 9 );
}
// 56E818: using guessed type int (__thiscall *DiplomacyAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040BF20) --------------------------------------------------------
DiplomacyAIModule *__thiscall DiplomacyAIModule::`vector deleting destructor'(DiplomacyAIModule *this, unsigned int __flags)
{
  DiplomacyAIModule *v2; // esi@1

  v2 = this;
  DiplomacyAIModule::~DiplomacyAIModule(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0040BF40) --------------------------------------------------------
void __thiscall DiplomacyAIModule::DiplomacyAIModule(DiplomacyAIModule *this, int playerID, int infile)
{
  DiplomacyAIModule *v3; // esi@1
  char *v4; // ebx@1
  int *v5; // esi@1
  int v6; // ebp@1

  v3 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aDiplomacyAi, 1003, playerID, 0);
  v3->md = 0;
  v3->vfptr = (AIModuleVtbl *)&DiplomacyAIModule::`vftable';
  v4 = v3->changeableTable;
  v5 = v3->likeTable;
  v6 = 10;
  do
  {
    rge_read(v6, infile, infile, v5 - 10, 4);
    rge_read(v6, infile, infile, v5, 4);
    rge_read(v6, infile, infile, v4, 1);
    ++v5;
    ++v4;
    --v6;
  }
  while( v6 );
}
// 56E818: using guessed type int (__thiscall *DiplomacyAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040BFF0) --------------------------------------------------------
void __thiscall DiplomacyAIModule::~DiplomacyAIModule(DiplomacyAIModule *this)
{
  this->vfptr = (AIModuleVtbl *)&DiplomacyAIModule::`vftable';
  AIModule::~AIModule((AIModule *)&this->vfptr);
}
// 56E818: using guessed type int (__thiscall *DiplomacyAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040C000) --------------------------------------------------------
void __thiscall DiplomacyAIModule::setMainDecisionAI(DiplomacyAIModule *this, MainDecisionAIModule *m)
{
  this->md = m;
}

//----- (0040C010) --------------------------------------------------------
int __thiscall DiplomacyAIModule::update(DiplomacyAIModule *this, int timeLimit)
{
  DiplomacyAIModule *v2; // edi@1
  int v3; // esi@1
  RGE_Player *v4; // eax@1

  v2 = this;
  v3 = 1;
  v4 = this->md->player;
  if( v4->world->player_num > 1 )
  {
    do
    {
      if( v3 != v4->id )
      {
        if( DiplomacyAIModule::isAlly(v2, v3) && !DiplomacyAIModule::isAlliedWithMe(v2, v3) )
          DiplomacyAIModule::changeStance(v2, v3, 0, 1);
        if( !DiplomacyAIModule::isAlly(v2, v3) && DiplomacyAIModule::isAlliedWithMe(v2, v3) )
          DiplomacyAIModule::changeStance(v2, v3, 2, 1);
      }
      ++v3;
      v4 = v2->md->player;
    }
    while( v3 < v4->world->player_num );
  }
  return 1;
}

//----- (0040C0A0) --------------------------------------------------------
int __thiscall DiplomacyAIModule::save(DiplomacyAIModule *this, int outfile)
{
  char *v2; // ebx@1
  char *v3; // esi@1
  signed int v4; // ebp@1

  v2 = this->changeableTable;
  v3 = (char *)this->likeTable;
  v4 = 10;
  do
  {
    rge_write(outfile, v3 - 40, 4);
    rge_write(outfile, v3, 4);
    rge_write(outfile, v2, 1);
    v3 += 4;
    ++v2;
    --v4;
  }
  while( v4 );
  return 1;
}

//----- (0040C100) --------------------------------------------------------
int __thiscall DiplomacyAIModule::stance(DiplomacyAIModule *this, int playerID, int likeType)
{
  int result; // eax@6
  int v4; // esi@7
  int v5; // edx@9

  if( playerID <= 0 || playerID >= this->md->player->world->player_num )
    return -1;
  if( !likeType )
    return this->dislikeTable[playerID];
  if( likeType != 1 )
  {
    if( likeType == 2 )
      return this->likeTable[playerID];
    return -1;
  }
  v4 = 49 - this->dislikeTable[playerID];
  if( v4 < 0 )
    v4 = -v4;
  v5 = 49 - this->likeTable[playerID];
  if( v5 < 0 )
    v5 = -v5;
  result = 100 - v4 - v5;
  if( result < 0 )
    result = 0;
  return result;
}

//----- (0040C190) --------------------------------------------------------
void __thiscall DiplomacyAIModule::changeStance(DiplomacyAIModule *this, int playerID, int likeType, int delta)
{
  int v4; // esi@5
  int v5; // esi@14

  if( playerID > 0 && playerID < this->md->player->world->player_num )
  {
    if( likeType )
    {
      if( likeType == 2 )
      {
        v4 = delta + this->likeTable[playerID];
        this->likeTable[playerID] = v4;
        if( this->changeableTable[playerID] )
        {
          if( v4 >= 0 )
          {
            if( v4 > 100 )
              this->likeTable[playerID] = 100;
          }
          else
          {
            this->likeTable[playerID] = 0;
          }
        }
        else if( v4 >= 0 )
        {
          if( v4 > 48 )
            this->likeTable[playerID] = 48;
        }
        else
        {
          this->likeTable[playerID] = 0;
        }
      }
    }
    else
    {
      v5 = delta + this->dislikeTable[playerID];
      this->dislikeTable[playerID] = v5;
      if( this->changeableTable[playerID] )
      {
        if( v5 >= 0 )
        {
          if( v5 > 100 )
            this->dislikeTable[playerID] = 100;
        }
        else
        {
          this->dislikeTable[playerID] = 0;
        }
      }
      else if( v5 >= 50 )
      {
        if( v5 > 100 )
          this->dislikeTable[playerID] = 100;
      }
      else
      {
        this->dislikeTable[playerID] = 50;
      }
    }
  }
}

//----- (0040C2B0) --------------------------------------------------------
void __thiscall DiplomacyAIModule::setStance(DiplomacyAIModule *this, int playerID, int likeType, int value)
{
  if( playerID > 0 && playerID < this->md->player->world->player_num )
  {
    if( likeType )
    {
      if( likeType == 2 )
      {
        this->likeTable[playerID] = value;
        if( this->changeableTable[playerID] )
        {
          if( value >= 0 )
          {
            if( value > 100 )
              this->likeTable[playerID] = 100;
          }
          else
          {
            this->likeTable[playerID] = 0;
          }
        }
        else if( value >= 0 )
        {
          if( value > 48 )
            this->likeTable[playerID] = 48;
        }
        else
        {
          this->likeTable[playerID] = 0;
        }
      }
    }
    else
    {
      this->dislikeTable[playerID] = value;
      if( this->changeableTable[playerID] )
      {
        if( value >= 0 )
        {
          if( value > 100 )
            this->dislikeTable[playerID] = 100;
        }
        else
        {
          this->dislikeTable[playerID] = 0;
        }
      }
      else if( value >= 50 )
      {
        if( value > 100 )
          this->dislikeTable[playerID] = 100;
      }
      else
      {
        this->dislikeTable[playerID] = 50;
      }
    }
  }
}

//----- (0040C3B0) --------------------------------------------------------
BOOL __thiscall DiplomacyAIModule::isDisliked(DiplomacyAIModule *this, int playerID)
{
  return playerID > 0 && playerID < this->md->player->world->player_num && this->dislikeTable[playerID] > 49;
}

//----- (0040C3F0) --------------------------------------------------------
BOOL __thiscall DiplomacyAIModule::isAmbivalent(DiplomacyAIModule *this, int playerID)
{
  DiplomacyAIModule *v2; // esi@1

  v2 = this;
  return !DiplomacyAIModule::isDisliked(this, playerID) && !DiplomacyAIModule::isLiked(v2, playerID);
}

//----- (0040C420) --------------------------------------------------------
BOOL __thiscall DiplomacyAIModule::isLiked(DiplomacyAIModule *this, int playerID)
{
  return playerID > 0 && playerID < this->md->player->world->player_num && this->likeTable[playerID] > 49;
}

//----- (0040C460) --------------------------------------------------------
BOOL __thiscall DiplomacyAIModule::isChangeable(DiplomacyAIModule *this, int playerID)
{
  return playerID > 0 && playerID < this->md->player->world->player_num && this->changeableTable[playerID] == 1;
}

//----- (0040C4A0) --------------------------------------------------------
void __thiscall DiplomacyAIModule::setChangeable(DiplomacyAIModule *this, int playerID, char v)
{
  if( playerID > 0 && playerID < this->md->player->world->player_num )
    this->changeableTable[playerID] = v;
}

//----- (0040C4D0) --------------------------------------------------------
int __thiscall DiplomacyAIModule::mostHated(DiplomacyAIModule *this, int tributeOn, int tributePlayer, int attackWinningPlayer, int attackWinningPlayerFactor)
{
  DiplomacyAIModule *v5; // edi@1
  int v6; // esi@1
  RGE_Player *v7; // ecx@1
  RGE_Game_World *v8; // eax@1
  int *v9; // ebx@2
  signed __int64 v10; // rax@8
  int v11; // ecx@8
  int highestValue; // [sp+8h] [bp-8h]@1
  int highest; // [sp+Ch] [bp-4h]@1

  v5 = this;
  highest = -1;
  highestValue = -1;
  v6 = 1;
  v7 = this->md->player;
  v8 = v7->world;
  if( v8->player_num > 1 )
  {
    v9 = &v5->dislikeTable[1];
    do
    {
      if( v6 != v7->id
        && v8->players[v6]->game_status != 2
        && (tributeOn <= 0 || tributePlayer != v6 || !DiplomacyAIModule::isAlly(v5, v6)) )
      {
        LODWORD(v10) = RGE_Victory_Conditions::get_victory_points(v5->md->player->world->players[v6]->victory_conditions);
        v11 = *v9;
        if( attackWinningPlayerFactor > 1 )
        {
          v10 = (signed int)v10;
          if( attackWinningPlayer == 1 )
            v11 += v10 / attackWinningPlayerFactor;
          else
            v11 -= v10 / attackWinningPlayerFactor;
        }
        if( v11 > highestValue )
        {
          highest = v6;
          highestValue = v11;
        }
      }
      ++v6;
      ++v9;
      v7 = v5->md->player;
      v8 = v7->world;
    }
    while( v6 < v8->player_num );
  }
  return highest;
}

//----- (0040C5B0) --------------------------------------------------------
int __thiscall DiplomacyAIModule::mostLiked(DiplomacyAIModule *this, int tributeOn, int tributePlayer)
{
  DiplomacyAIModule *v3; // ebp@1
  int v4; // esi@1
  signed int v5; // ebx@1
  RGE_Player *v6; // ecx@1
  RGE_Game_World *v7; // eax@1
  int v8; // edx@2
  int *v9; // edi@2
  int highest; // [sp+Ch] [bp-8h]@1

  v3 = this;
  v4 = 1;
  v5 = -1;
  highest = -1;
  v6 = this->md->player;
  v7 = v6->world;
  if( v7->player_num > 1 )
  {
    v8 = -284 - (_DWORD)v3;
    v9 = &v3->likeTable[1];
    while( 1 )
    {
      if( v4 != v6->id
        && (*(RGE_Player **)((char *)v7->players + v8 + (unsigned int)v9))->game_status != 2
        && (tributeOn <= 0 || tributePlayer != v4 || !DiplomacyAIModule::isEnemy(v3, v4))
        && *v9 > v5 )
      {
        highest = v4;
        v5 = *v9;
      }
      ++v4;
      ++v9;
      v6 = v3->md->player;
      v7 = v6->world;
      if( v4 >= v7->player_num )
        break;
      v8 = -284 - (_DWORD)v3;
    }
  }
  return highest;
}

//----- (0040C660) --------------------------------------------------------
int __thiscall DiplomacyAIModule::isEnemy(DiplomacyAIModule *this, int playerID)
{
  RGE_Player *v2; // eax@2
  int result; // eax@5

  result = 0;
  if( playerID > 0 )
  {
    v2 = this->md->player;
    if( playerID <= v2->world->player_num && playerID != v2->id && v2->relations[playerID] == 3 )
      result = 1;
  }
  return result;
}

//----- (0040C6A0) --------------------------------------------------------
int __thiscall DiplomacyAIModule::isNeutral(DiplomacyAIModule *this, int playerID)
{
  RGE_Player *v2; // eax@2
  int result; // eax@5

  result = 0;
  if( playerID > 0 )
  {
    v2 = this->md->player;
    if( playerID <= v2->world->player_num && playerID != v2->id && v2->relations[playerID] == 1 )
      result = 1;
  }
  return result;
}

//----- (0040C6E0) --------------------------------------------------------
int __thiscall DiplomacyAIModule::isAlly(DiplomacyAIModule *this, int playerID)
{
  RGE_Player *v2; // eax@1
  int result; // eax@2

  v2 = this->md->player;
  if( playerID == v2->id )
    result = 1;
  else
    result = playerID > 0 && playerID <= v2->world->player_num && !v2->relations[playerID];
  return result;
}

//----- (0040C730) --------------------------------------------------------
int __thiscall DiplomacyAIModule::isAlliedWithMe(DiplomacyAIModule *this, int playerID)
{
  RGE_Player *v2; // esi@2
  RGE_Game_World *v3; // eax@2
  RGE_Player *v4; // ecx@3
  int result; // eax@5

  result = 0;
  if( playerID > 0 )
  {
    v2 = this->md->player;
    v3 = v2->world;
    if( playerID < v3->player_num )
    {
      v4 = v3->players[playerID];
      if( v4 )
      {
        if( (*(int (__stdcall **)(_DWORD))&v4->vfptr->gap4[24])(v2->id) )
          result = 1;
      }
    }
  }
  return result;
}

//----- (0040C780) --------------------------------------------------------
void __thiscall DiplomacyAIModule::setRelation(DiplomacyAIModule *this, int playerID, int newRelation)
{
  RGE_Player *v3; // edx@2

  if( playerID > 0 )
  {
    v3 = this->md->player;
    if( playerID < v3->world->player_num )
    {
      if( this->changeableTable[playerID] )
        v3->vfptr->setDiplomaticStance(v3, playerID, newRelation);
    }
  }
}
