
/**
 * @file    Engine\RGE\AiModule.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (0040DD90) --------------------------------------------------------
void __thiscall AIModuleID::AIModuleID(AIModuleID *this, char *n, int i)
{
  this->id = i;
  this->vfptr = (AIModuleIDVtbl *)AIModuleID::`vftable';
  if ( n )
    strncpy(this->name, n, 0x3Fu);
  else
    strcpy(this->name, message_in);
}
// 56E928: using guessed type int (__thiscall *AIModuleID::`vftable'[3])(void *Memory, unsigned int __flags);

//----- (0040DDF0) --------------------------------------------------------
AIModuleID *__thiscall AIModuleID::`vector deleting destructor'(AIModuleID *this, unsigned int __flags)
{
  AIModuleID *v2; // esi@1

  v2 = this;
  AIModuleID::~AIModuleID(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0040DE10) --------------------------------------------------------
void __thiscall AIModuleID::~AIModuleID(AIModuleID *this)
{
  this->vfptr = (AIModuleIDVtbl *)AIModuleID::`vftable';
}
// 56E928: using guessed type int (__thiscall *AIModuleID::`vftable'[3])(void *Memory, unsigned int __flags);

//----- (0040DE20) --------------------------------------------------------
void __thiscall AIModuleID::setID(AIModuleID *this, int i, char *n)
{
  this->id = i;
  if ( n )
    strncpy(this->name, n, 0x3Fu);
  else
    strcpy(this->name, message_in);
}

//----- (0040DE70) --------------------------------------------------------
void __thiscall AIModuleMessage::AIModuleMessage(AIModuleMessage *this)
{
  AIModuleMessage *v1; // ebx@1

  v1 = this;
  this->id = 0;
  this->priority = 0;
  AIModuleID::AIModuleID(&this->sender, aSender, 0);
  AIModuleID::AIModuleID(&v1->recipient, aRecipient, 0);
  v1->data1 = 0;
  v1->data2 = 0;
  v1->data3 = 0;
  v1->callbackMessage = 0;
  v1->timeStamp = 0;
  v1->next = 0;
  v1->prev = 0;
  v1->vfptr = (AIModuleMessageVtbl *)AIModuleMessage::`vftable';
  strcpy(v1->text, message_in);
}
// 56E92C: using guessed type int (__thiscall *AIModuleMessage::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (0040DF30) --------------------------------------------------------
AIModuleMessage *__thiscall AIModuleMessage::`scalar deleting destructor'(AIModuleMessage *this, unsigned int __flags)
{
  AIModuleMessage *v2; // esi@1

  v2 = this;
  AIModuleMessage::~AIModuleMessage(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0040DF50) --------------------------------------------------------
void __thiscall AIModuleMessage::AIModuleMessage(AIModuleMessage *this, int s, int r, int i, int p, int d1, int d2, int d3, AIModuleMessage *c, int t)
{
  AIModuleMessage *v10; // ebx@1

  v10 = this;
  this->priority = p;
  this->id = i;
  AIModuleID::AIModuleID(&this->sender, message_in, s);
  AIModuleID::AIModuleID(&v10->recipient, message_in, r);
  v10->data1 = d1;
  v10->data2 = d2;
  v10->data3 = d3;
  v10->callbackMessage = c;
  v10->timeStamp = t;
  v10->vfptr = (AIModuleMessageVtbl *)AIModuleMessage::`vftable';
  strcpy(v10->text, message_in);
}
// 56E92C: using guessed type int (__thiscall *AIModuleMessage::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (0040E030) --------------------------------------------------------
void __thiscall AIModuleMessage::AIModuleMessage(AIModuleMessage *this, AIModuleMessage *m)
{
  AIModuleMessage *v2; // esi@1

  v2 = this;
  this->id = m->id;
  this->priority = m->priority;
  AIModuleID::AIModuleID(&this->sender, m->sender.name, m->sender.id);
  AIModuleID::AIModuleID(&v2->recipient, m->recipient.name, m->recipient.id);
  v2->data1 = m->data1;
  v2->data2 = m->data2;
  v2->data3 = m->data3;
  v2->callbackMessage = m->callbackMessage;
  v2->timeStamp = m->timeStamp;
  v2->next = 0;
  v2->prev = 0;
  v2->vfptr = (AIModuleMessageVtbl *)AIModuleMessage::`vftable';
  AIModuleMessage::setText(v2, m->text);
}
// 56E92C: using guessed type int (__thiscall *AIModuleMessage::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (0040E120) --------------------------------------------------------
void __thiscall AIModuleMessage::~AIModuleMessage(AIModuleMessage *this)
{
  AIModuleMessage *v1; // esi@1
  AIModuleMessage *v2; // ecx@1

  v1 = this;
  this->vfptr = (AIModuleMessageVtbl *)AIModuleMessage::`vftable';
  v2 = this->callbackMessage;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  AIModuleID::~AIModuleID(&v1->recipient);
  AIModuleID::~AIModuleID(&v1->sender);
}
// 56E92C: using guessed type int (__thiscall *AIModuleMessage::`vftable'[2])(void *Memory, unsigned int __flags);

//----- (0040E190) --------------------------------------------------------
void __thiscall AIModuleMessage::setText(AIModuleMessage *this, char *t)
{
  if ( t )
    strncpy(this->text, t, 0x7Fu);
  else
    strcpy(this->text, message_in);
}

//----- (0040E1E0) --------------------------------------------------------
void __thiscall AIModuleMessage::setSender(AIModuleMessage *this, int i, char *n)
{
  AIModuleID::setID(&this->sender, i, n);
}

//----- (0040E200) --------------------------------------------------------
void __thiscall AIModuleMessage::setRecipient(AIModuleMessage *this, int i, char *n)
{
  AIModuleID::setID(&this->recipient, i, n);
}

//----- (0040E220) --------------------------------------------------------
void __thiscall AIModule::AIModule(AIModule *this)
{
  AIModule *v1; // ebx@1

  v1 = this;
  AIModuleID::AIModuleID(&this->idValue, message_in, -1);
  v1->playerNumberValue = -1;
  v1->runningValue = 0;
  v1->pausedValue = 0;
  v1->logHistoryValue = 0;
  v1->logCommonHistoryValue = 0;
  v1->historyLogFile = 0;
  v1->intelligenceLevelValue = 5;
  v1->priorityValue = 50;
  v1->processFrameValue = 0;
  v1->vfptr = (AIModuleVtbl *)&AIModule::`vftable';
  strcpy(v1->playerNameValue, aUnknown);
}
// 56E930: using guessed type int (__thiscall *AIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040E2B0) --------------------------------------------------------
AIModule *__thiscall AIModule::`scalar deleting destructor'(AIModule *this, unsigned int __flags)
{
  AIModule *v2; // esi@1

  v2 = this;
  AIModule::~AIModule(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0040E2D0) --------------------------------------------------------
void __thiscall AIModule::AIModule(AIModule *this, char *n, int i, int pN, void *pW)
{
  AIModule *v5; // ebx@1

  v5 = this;
  AIModuleID::AIModuleID(&this->idValue, n, i);
  v5->playerNumberValue = pN;
  v5->runningValue = 0;
  v5->pausedValue = 0;
  v5->logHistoryValue = 0;
  v5->logCommonHistoryValue = 0;
  v5->historyLogFile = 0;
  v5->intelligenceLevelValue = 5;
  v5->priorityValue = 50;
  v5->processFrameValue = 0;
  v5->vfptr = (AIModuleVtbl *)&AIModule::`vftable';
  strcpy(v5->playerNameValue, aUnknown);
}
// 56E930: using guessed type int (__thiscall *AIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040E360) --------------------------------------------------------
void __thiscall AIModule::~AIModule(AIModule *this)
{
  AIModule *v1; // esi@1
  int v2; // eax@1

  v1 = this;
  v2 = this->logCommonHistoryValue;
  this->vfptr = (AIModuleVtbl *)&AIModule::`vftable';
  if ( v2 && commonHistoryLogFile )
  {
    fclose(commonHistoryLogFile);
    commonHistoryLogFile = 0;
  }
  AIModuleID::~AIModuleID(&v1->idValue);
}
// 56E930: using guessed type int (__thiscall *AIModule::`vftable')(void *Memory, unsigned int __flags);

//----- (0040E3A0) --------------------------------------------------------
AIModuleID *__thiscall AIModule::id(AIModule *this, AIModuleID *result)
{
  AIModuleID *v2; // eax@1

  v2 = result;
  result->id = this->idValue.id;
  qmemcpy(result->name, this->idValue.name, sizeof(result->name));
  result->vfptr = (AIModuleIDVtbl *)AIModuleID::`vftable';
  return v2;
}
// 56E928: using guessed type int (__thiscall *AIModuleID::`vftable'[3])(void *Memory, unsigned int __flags);

//----- (0040E3D0) --------------------------------------------------------
int __thiscall AIModule::idNumber(AIModule *this)
{
  return this->idValue.id;
}

//----- (0040E3E0) --------------------------------------------------------
int __thiscall AIModule::playerNumber(AIModule *this)
{
  return this->playerNumberValue;
}

//----- (0040E3F0) --------------------------------------------------------
char *__thiscall AIModule::playerName(AIModule *this)
{
  return this->playerNameValue;
}

//----- (0040E400) --------------------------------------------------------
void __thiscall AIModule::setPlayer(AIModule *this, int i, char *n)
{
  this->playerNumberValue = i;
  if ( n )
    strncpy(this->playerNameValue, n, 0x3Fu);
  else
    strcpy(this->playerNameValue, aUnknown);
}

//----- (0040E450) --------------------------------------------------------
void __thiscall AIModule::start(AIModule *this)
{
  this->runningValue = 1;
}

//----- (0040E460) --------------------------------------------------------
void __thiscall AIModule::stop(AIModule *this)
{
  this->runningValue = 0;
}

//----- (0040E470) --------------------------------------------------------
void __thiscall AIModule::toggleRun(AIModule *this)
{
  this->runningValue = this->runningValue == 0;
}

//----- (0040E490) --------------------------------------------------------
void __thiscall AIModule::togglePause(AIModule *this)
{
  this->pausedValue = this->pausedValue == 0;
}

//----- (0040E4C0) --------------------------------------------------------
int __thiscall AIModule::running(AIModule *this)
{
  return this->runningValue;
}

//----- (0040E4D0) --------------------------------------------------------
int __thiscall AIModule::paused(AIModule *this)
{
  return this->pausedValue;
}

//----- (0040E4E0) --------------------------------------------------------
int __thiscall AIModule::loggingHistory(AIModule *this)
{
  return this->logHistoryValue;
}

//----- (0040E510) --------------------------------------------------------
int __thiscall AIModule::loggingCommonHistory(AIModule *this)
{
  return this->logCommonHistoryValue;
}

//----- (0040E520) --------------------------------------------------------
void __thiscall AIModule::setLogCommonHistory(AIModule *this, int v)
{
  int v2; // eax@1
  AIModule *v3; // esi@1
  bool v4; // zf@1
  struct tm *v5; // eax@3
  char *v6; // eax@3

  v2 = v;
  v3 = this;
  v4 = v == 0;
  this->logCommonHistoryValue = v;
  if ( v4 || commonHistoryLogFile )
  {
    if ( !v2 )
    {
      if ( commonHistoryLogFile )
      {
        fclose(commonHistoryLogFile);
        commonHistoryLogFile = 0;
      }
    }
  }
  else
  {
    commonHistoryLogFile = fopen(Filename, aWa);
    time(&v);
    v5 = localtime(&v);
    v6 = asctime(v5);
    AIModule::logCommonHistory(v3, aCommonAiHistor, v6);
    AIModule::logCommonHistory(v3, message_in);
  }
}

//----- (0040E5E0) --------------------------------------------------------
int __thiscall AIModule::intelligenceLevel(AIModule *this)
{
  return this->intelligenceLevelValue;
}

//----- (0040E5F0) --------------------------------------------------------
int __thiscall AIModule::setIntelligenceLevel(AIModule *this, int v)
{
  int result; // eax@2

  this->intelligenceLevelValue = v;
  if ( v >= 1 )
  {
    if ( v <= 10 )
    {
      result = 1;
    }
    else
    {
      this->intelligenceLevelValue = 10;
      result = 0;
    }
  }
  else
  {
    this->intelligenceLevelValue = 1;
    result = 0;
  }
  return result;
}

//----- (0040E630) --------------------------------------------------------
int __thiscall AIModule::priority(AIModule *this)
{
  return this->priorityValue;
}

//----- (0040E640) --------------------------------------------------------
int __thiscall AIModule::setPriority(AIModule *this, int v)
{
  int result; // eax@2

  this->priorityValue = v;
  if ( v >= 1 )
  {
    if ( v <= 100 )
    {
      result = 1;
    }
    else
    {
      this->priorityValue = 100;
      result = 0;
    }
  }
  else
  {
    this->priorityValue = 1;
    result = 0;
  }
  return result;
}

//----- (0040E680) --------------------------------------------------------
int __thiscall AIModule::incrementPriority(AIModule *this, int v)
{
  return AIModule::setPriority(this, v + this->priorityValue);
}

//----- (0040E6A0) --------------------------------------------------------
int __thiscall AIModule::decrementPriority(AIModule *this, int v)
{
  return AIModule::setPriority(this, this->priorityValue - v);
}

//----- (0040E6C0) --------------------------------------------------------
int __stdcall AIModule::sendMessage(AIModuleMessage *m, int processNow)
{
  return 0;
}

//----- (0040E6E0) --------------------------------------------------------
int __stdcall AIModule::processMessage(AIModuleMessage *m)
{
  return 0;
}

//----- (0040E6F0) --------------------------------------------------------
int __stdcall AIModule::update(int timeLimit)
{
  return 0;
}

//----- (0040E710) --------------------------------------------------------
int AIModule::messageLimit()
{
  return 0;
}

//----- (0040E730) --------------------------------------------------------
int AIModule::callbackLimit()
{
  return 0;
}

//----- (0040E750) --------------------------------------------------------
int AIModule::messageTimeout()
{
  return 0;
}

//----- (0040E770) --------------------------------------------------------
int __stdcall AIModule::purgeMessages(AIModuleID s)
{
  AIModuleID::~AIModuleID(&s);
  return 0;
}

//----- (0040E780) --------------------------------------------------------
int __stdcall AIModule::purgeMessagesWithID(AIModuleID s, int i)
{
  AIModuleID::~AIModuleID(&s);
  return 0;
}

//----- (0040E790) --------------------------------------------------------
int __stdcall AIModule::purgeMessagesWithPriorityBelow(AIModuleID s, int p)
{
  AIModuleID::~AIModuleID(&s);
  return 0;
}

//----- (0040E7A0) --------------------------------------------------------
int __stdcall AIModule::purgeMessagesWithData(AIModuleID s, int i, int n, int d)
{
  AIModuleID::~AIModuleID(&s);
  return 0;
}

//----- (0040E7B0) --------------------------------------------------------
int __stdcall AIModule::purgeCallbacks(AIModuleID s)
{
  AIModuleID::~AIModuleID(&s);
  return 0;
}

//----- (0040E7C0) --------------------------------------------------------
int __stdcall AIModule::purgeCallbacksWithID(AIModuleID s, int i)
{
  AIModuleID::~AIModuleID(&s);
  return 0;
}

//----- (0040E7D0) --------------------------------------------------------
int __stdcall AIModule::purgeCallbacksWithPriorityBelow(AIModuleID s, int p)
{
  AIModuleID::~AIModuleID(&s);
  return 0;
}

//----- (0040E7E0) --------------------------------------------------------
int __stdcall AIModule::purgeCallbacksWithData(AIModuleID s, int i, int n, int d)
{
  AIModuleID::~AIModuleID(&s);
  return 0;
}

//----- (0040E810) --------------------------------------------------------
int __stdcall AIModule::filterOutMessage(AIModuleMessage *m)
{
  return 0;
}

//----- (0040E830) --------------------------------------------------------
void AIModule::logCommonHistory(AIModule *this, char *textIn, ...)
{
  char textOut[1024]; // [sp+8h] [bp-400h]@4
  va_list va; // [sp+414h] [bp+Ch]@1

  va_start(va, textIn);
  if ( (specificAIPlayerToLog == -1 || specificAIPlayerToLog == this->playerNumberValue) && commonHistoryLogFile )
  {
    vsprintf(textOut, textIn, va);
    if ( strlen(textOut) == 0 )
      fprintf(commonHistoryLogFile, aPD, this->playerNumberValue);
    else
      fprintf(commonHistoryLogFile, aPDSS, this->playerNumberValue, this->idValue.name, textOut);
    fflush(commonHistoryLogFile);
  }
}
// 57F9FC: using guessed type int specificAIPlayerToLog;

//----- (0040E8F0) --------------------------------------------------------
int __thiscall AIModule::processFrame(AIModule *this)
{
  return this->processFrameValue;
}

//----- (0040E900) --------------------------------------------------------
void __thiscall AIModule::incrementProcessFrame(AIModule *this)
{
  int v1; // eax@1

  v1 = this->processFrameValue + 1;
  this->processFrameValue = v1;
  if ( v1 == 0x7FFFFFFF )
    this->processFrameValue = 0;
}

//----- (0040E920) --------------------------------------------------------
int __stdcall AIModule::timeDifference(AIModuleMessage *m)
{
  return 0;
}
