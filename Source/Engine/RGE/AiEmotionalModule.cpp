
//----- (0040C7C0) --------------------------------------------------------
void __thiscall EmotionalAIModule::EmotionalAIModule(EmotionalAIModule *this, void *pW, int playerID)
{
  EmotionalAIModule *v3; // ebx@1

  v3 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aEmotionalAi, 1004, playerID, pW);
  v3->md = 0;
  v3->vfptr = (AIModuleVtbl *)&EmotionalAIModule::`vftable';
  memset32(v3->stateValue, 49, 6u);
  strcpy((char *)v3->stateNameValue, aAggressive);
  strcpy(v3->stateNameValue[1], aCompassionate);
  strcpy(v3->stateNameValue[2], aDefensive);
  strcpy(v3->stateNameValue[3], aFriendly);
  strcpy(v3->stateNameValue[4], aPassive);
  strcpy(v3->stateNameValue[5], aVengeful);
}
// 56E858: using guessed type int (__thiscall *EmotionalAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040C900) --------------------------------------------------------
EmotionalAIModule *__thiscall EmotionalAIModule::`scalar deleting destructor'(EmotionalAIModule *this, unsigned int __flags)
{
  EmotionalAIModule *v2; // esi@1

  v2 = this;
  EmotionalAIModule::~EmotionalAIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0040C920) --------------------------------------------------------
void __thiscall EmotionalAIModule::EmotionalAIModule(EmotionalAIModule *this, int playerID, int infile)
{
  EmotionalAIModule *v3; // ebx@1
  int *v4; // esi@1
  int v5; // edi@1

  v3 = this;
  AIModule::AIModule((AIModule *)&this->vfptr, aEmotionalAi, 1004, playerID, 0);
  v3->md = 0;
  v3->vfptr = (AIModuleVtbl *)&EmotionalAIModule::`vftable';
  v4 = v3->stateValue;
  v5 = 6;
  do
  {
    rge_read(infile, v5, infile, v4, 4);
    ++v4;
    --v5;
  }
  while ( v5 );
  strcpy((char *)v3->stateNameValue, aAggressive);
  strcpy(v3->stateNameValue[1], aCompassionate);
  strcpy(v3->stateNameValue[2], aDefensive);
  strcpy(v3->stateNameValue[3], aFriendly);
  strcpy(v3->stateNameValue[4], aPassive);
  strcpy(v3->stateNameValue[5], aVengeful);
}
// 56E858: using guessed type int (__thiscall *EmotionalAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040CA90) --------------------------------------------------------
void __thiscall EmotionalAIModule::~EmotionalAIModule(EmotionalAIModule *this)
{
  this->vfptr = (AIModuleVtbl *)&EmotionalAIModule::`vftable';
  AIModule::~AIModule((AIModule *)&this->vfptr);
}
// 56E858: using guessed type int (__thiscall *EmotionalAIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040CAA0) --------------------------------------------------------
void __thiscall EmotionalAIModule::setMainDecisionAI(EmotionalAIModule *this, MainDecisionAIModule *m)
{
  this->md = m;
}

//----- (0040CAB0) --------------------------------------------------------
int __thiscall EmotionalAIModule::save(EmotionalAIModule *this, int outfile)
{
  char *v2; // esi@1
  signed int v3; // edi@1

  v2 = (char *)this->stateValue;
  v3 = 6;
  do
  {
    rge_write(outfile, v2, 4);
    v2 += 4;
    --v3;
  }
  while ( v3 );
  return 1;
}

//----- (0040CAE0) --------------------------------------------------------
char *__thiscall EmotionalAIModule::stateName(EmotionalAIModule *this, int s)
{
  char *result; // eax@3

  if ( s < 0 || s >= 6 )
    result = 0;
  else
    result = this->stateNameValue[s];
  return result;
}

//----- (0040CB10) --------------------------------------------------------
int __thiscall EmotionalAIModule::state(EmotionalAIModule *this, int s)
{
  int result; // eax@3

  if ( s < 0 || s >= 6 )
    result = -1;
  else
    result = this->stateValue[s];
  return result;
}

//----- (0040CB30) --------------------------------------------------------
void __thiscall EmotionalAIModule::setState(EmotionalAIModule *this, int s, int value)
{
  if ( s >= 0 && s < 6 )
    this->stateValue[s] = value;
}

//----- (0040CB50) --------------------------------------------------------
void __thiscall EmotionalAIModule::incrementState(EmotionalAIModule *this, int s, int delta)
{
  if ( s >= 0 && s < 6 )
    this->stateValue[s] += delta;
}

//----- (0040CB80) --------------------------------------------------------
void __thiscall EmotionalAIModule::decrementState(EmotionalAIModule *this, int s, int delta)
{
  if ( s >= 0 && s < 6 )
    this->stateValue[s] -= delta;
}

//----- (0040CBB0) --------------------------------------------------------
int __thiscall EmotionalAIModule::overallState(EmotionalAIModule *this)
{
  int v1; // edi@1
  int result; // eax@1
  signed int v3; // edx@1
  char *v4; // esi@1

  v1 = this->stateValue[0];
  result = 0;
  v3 = 1;
  v4 = (char *)&this->stateValue[1];
  do
  {
    if ( v1 < *(_DWORD *)v4 )
    {
      result = v3;
      v1 = *(_DWORD *)v4;
    }
    ++v3;
    v4 += 4;
  }
  while ( v3 < 6 );
  return result;
}

//----- (0040CBE0) --------------------------------------------------------
void __thiscall EmotionalAIModule::setOverallState(EmotionalAIModule *this, int s)
{
  switch ( s )
  {
    case 0:
      this->stateValue[0] = 100;
      this->stateValue[4] = 10;
      this->stateValue[1] = 10;
      this->stateValue[3] = 10;
      this->stateValue[2] = 0;
      this->stateValue[5] = 70;
      break;
    case 4:
      this->stateValue[0] = 20;
      this->stateValue[4] = 100;
      this->stateValue[1] = 70;
      this->stateValue[3] = 50;
      this->stateValue[2] = 60;
      this->stateValue[5] = 0;
      break;
    case 1:
      this->stateValue[0] = 10;
      this->stateValue[4] = 50;
      this->stateValue[1] = 100;
      this->stateValue[3] = 80;
      this->stateValue[2] = 50;
      this->stateValue[5] = 0;
      break;
    case 3:
      this->stateValue[0] = 10;
      this->stateValue[4] = 50;
      this->stateValue[1] = 70;
      this->stateValue[3] = 100;
      this->stateValue[2] = 50;
      this->stateValue[5] = 20;
      break;
    case 2:
      this->stateValue[0] = 20;
      this->stateValue[4] = 60;
      this->stateValue[1] = 50;
      this->stateValue[3] = 50;
      this->stateValue[2] = 100;
      this->stateValue[5] = 10;
      break;
    case 5:
      this->stateValue[0] = 90;
      this->stateValue[4] = 10;
      this->stateValue[1] = 0;
      this->stateValue[3] = 30;
      this->stateValue[2] = 50;
      this->stateValue[5] = 100;
      break;
    default:
      return;
  }
}

//----- (0040CD80) --------------------------------------------------------
int EmotionalAIModule::defaultState()
{
  return 4;
}
