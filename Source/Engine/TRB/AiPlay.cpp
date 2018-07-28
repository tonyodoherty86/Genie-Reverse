
/**
 * @file    Engine\TRB\AiPlay.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004E68B0) --------------------------------------------------------
void __thiscall TribeAIPlayBook::TribeAIPlayBook(TribeAIPlayBook *this)
{
  TribeAIPlayBook *v1; // esi@1

  v1 = this;
  AIPlayBook::AIPlayBook((AIPlayBook *)&this->vfptr);
  v1->vfptr = (AIPlayBookVtbl *)&TribeAIPlayBook::`vftable';
}
// 575620: using guessed type int (__thiscall *TribeAIPlayBook::`vftable')(void *Memory, unsigned int __flags);

//----- (004E68D0) --------------------------------------------------------
TribeAIPlayBook *__thiscall TribeAIPlayBook::`vector deleting destructor'(TribeAIPlayBook *this, unsigned int __flags)
{
  TribeAIPlayBook *v2; // esi@1

  v2 = this;
  TribeAIPlayBook::~TribeAIPlayBook(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004E6900) --------------------------------------------------------
int __stdcall TribeAIPlayBook::convertTargetNameToIntType(char *t)
{
  return AIPlayBook::convertTargetNameToIntType(t);
}

//----- (004E6910) --------------------------------------------------------
int __stdcall TribeAIPlayBook::convertTargetCharacteristicNameToIntType(char *t)
{
  return AIPlayBook::convertTargetCharacteristicNameToIntType(t);
}

//----- (004E6920) --------------------------------------------------------
int __stdcall TribeAIPlayBook::convertUnitNameToIntType(char *t)
{
  int result; // eax@1

  result = strcmp(t, aHand);
  if ( result )
  {
    if ( !strcmp(t, aRanged) )
    {
      result = 1;
    }
    else if ( !strcmp(t, aPriest) )
    {
      result = 4;
    }
    else if ( !strcmp(t, aSiege) )
    {
      result = 5;
    }
    else if ( !strcmp(t, aCavalry) )
    {
      result = 2;
    }
    else if ( !strcmp(t, aLegion) )
    {
      result = 3;
    }
    else
    {
      result = AIPlayBook::convertUnitNameToIntType(t);
    }
  }
  return result;
}

//----- (004E6AD0) --------------------------------------------------------
int __userpurge TribeAIPlayBook::convertUnitToIntType@<eax>(TribeAIPlayBook *this@<ecx>, double a2@<st0>, RGE_Static_Object *obj)
{
  __int16 v3; // ax@1
  int result; // eax@2

  v3 = obj->master_obj->object_group;
  switch ( v3 )
  {
    case 18:
      result = 4;
      break;
    case 28:
      result = 3;
      break;
    case 13:
      result = 5;
      break;
    case 12:
    case 35:
      result = 2;
      break;
    default:
      ((void (*)(void))obj->vfptr->weaponRange)();
      result = a2 > 1.0;
      break;
  }
  return result;
}
