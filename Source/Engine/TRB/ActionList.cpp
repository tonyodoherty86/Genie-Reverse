#include "ActionList.hpp"
#include "ActionBuild.hpp"
#include "ActionMakeObj.hpp"
#include "ActionMakeTech.hpp"
#include "ActionConvert.hpp"
#include "ActionHeal.hpp"
#include "ActionArtifact.hpp"
#include "ActionWonder.hpp"
#include "ActionDiscovery.hpp"
#include "ActionHunt.hpp"
#include "ActionRepair.hpp"
#include "ActionTrade.hpp"

#include <RGE/ActionEnter.hpp>
#include <RGE/ActionTransport.hpp>
#include <RGE/Task.hpp>

#include <cstring>

//----- (004D0150) --------------------------------------------------------
TRIBE_Action_List::TRIBE_Action_List(RGE_Action_Object *obj_in) :
    RGE_Action_List (obj_in)
{
}
// 575170: using guessed type struct RGE_Action *(__thiscall *TRIBE_Action_List::`vftable')(TRIBE_Action_List *this, int infile, __int16 action_type);

//----- (004D0170) --------------------------------------------------------
void TRIBE_Action_List::create_action(int infile, int16_t action_type)
{
  TRIBE_Action_List *v4; // esi@1
  TRIBE_Action_Build *v5; // eax@2
  TRIBE_Action_Make_Obj *v6; // eax@4
  TRIBE_Action_Make_Tech *v7; // eax@6
  TRIBE_Action_Convert *v8; // eax@8
  TRIBE_Action_Heal *v9; // eax@10
  TRIBE_Action_Artifact *v10; // eax@12
  TRIBE_Action_Wonder *v11; // eax@14
  TRIBE_Action_Discovery_Artifact *v12; // eax@16
  TRIBE_Action_Hunt *v13; // eax@18
  TRIBE_Action_Repair *v14; // eax@20
  TRIBE_Action_Trade *v15; // eax@22
  RGE_Action_Transport *v16; // eax@24
  RGE_Action_Enter *v17; // eax@26

  v4 = this;
  switch ( action_type )
  {
    case 101:
      v5 = new TRIBE_Action_Build(infile, v4->obj);
      break;
    case 102:
      v6 = new TRIBE_Action_Make_Obj(infile, v4->obj);
      break;
    case 103:
      v7 = new TRIBE_Action_Make_Tech(infile, v4->obj);
      break;
    case 104:
      v8 = new TRIBE_Action_Convert(infile, v4->obj);
      break;
    case 105:
      v9 = new TRIBE_Action_Heal(infile, v4->obj);
      break;
    case 107:
      v10 = new TRIBE_Action_Artifact(infile, v4->obj);
      break;
    case 120:
      v11 = new TRIBE_Action_Wonder(infile, v4->obj);
      break;
    case 108:
      v12 = new TRIBE_Action_Discovery_Artifact(infile, v4->obj);
      break;
    case 110:
      v13 = new TRIBE_Action_Hunt(infile, v4->obj);
      break;
    case 106:
      v14 = new TRIBE_Action_Repair(infile, v4->obj, 1);
      break;
    case 111:
      v15 = new TRIBE_Action_Trade(infile, v4->obj);
      break;
    case 12:
      v16 = new RGE_Action_Transport(infile, v4->obj);
      break;
    case 3:
      v17 = new RGE_Action_Enter(infile, v4->obj);
      break;
    default:
      RGE_Action_List::create_action(infile, action_type);
      break;
  }
}

//----- (004D05D0) --------------------------------------------------------
void TRIBE_Action_List::create_task_action(RGE_Task *task, RGE_Static_Object *target_obj, float target_x, float target_y, float target_z)
{
  TRIBE_Action_List *v6; // esi@1
  TRIBE_Action_Build *v7; // eax@3
  TRIBE_Action_Build *v8; // eax@5
  TRIBE_Action_Convert *v9; // eax@8
  TRIBE_Action_Convert *v10; // eax@10
  TRIBE_Action_Heal *v11; // eax@13
  TRIBE_Action_Heal *v12; // eax@15
  TRIBE_Action_Artifact *v13; // eax@18
  TRIBE_Action_Artifact *v14; // eax@20
  TRIBE_Action_Wonder *v15; // eax@22
  TRIBE_Action_Discovery_Artifact *v16; // eax@25
  TRIBE_Action_Discovery_Artifact *v17; // eax@27
  TRIBE_Action_Hunt *v18; // eax@30
  TRIBE_Action_Hunt *v19; // eax@32
  TRIBE_Action_Repair *v20; // eax@35
  TRIBE_Action_Repair *v21; // eax@37
  TRIBE_Action_Trade *v22; // eax@40
  TRIBE_Action_Trade *v23; // eax@42
  RGE_Action_Enter *v24; // eax@44
  RGE_Action_Transport *v25; // eax@46

  v6 = this;
  switch ( task->action_type )
  {
    case 101:
      if ( target_obj )
      {
          v7 = new TRIBE_Action_Build(v6->obj, task, target_obj);
      }
      else
      {
          v8 = new TRIBE_Action_Build(v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 104:
      if ( target_obj )
      {
          v9 = new TRIBE_Action_Convert(v6->obj, task, target_obj);
      }
      else
      {
          v10 = new TRIBE_Action_Convert(v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 105:
      if ( target_obj )
      {
          v11 = new TRIBE_Action_Heal(v6->obj, task, target_obj);
      }
      else
      {
        v12 = new TRIBE_Action_Heal(v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 107:
      if ( target_obj )
      {
          v13 = new TRIBE_Action_Artifact(v6->obj, task, target_obj);
      }
      else
      {
          v14 = new TRIBE_Action_Artifact(v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 120:
      v15 = new TRIBE_Action_Wonder(v6->obj);
      break;
    case 108:
      if ( target_obj )
      {
        v16 = new TRIBE_Action_Discovery_Artifact(v6->obj, task, target_obj);
      }
      else
      {

        v17 = new TRIBE_Action_Discovery_Artifact(
            v6->obj,
            task,
            target_x,
            target_y,
            target_z);
      }
      break;
    case 110:
      if ( target_obj )
      {
        v18 = new TRIBE_Action_Hunt(v6->obj, task, target_obj);
      }
      else
      {
        v19 = new TRIBE_Action_Hunt(v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 106:
      if ( target_obj )
      {
        v20 = new TRIBE_Action_Repair(v6->obj, task, target_obj);
      }
      else
      {
        v21 = new TRIBE_Action_Repair(v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 111:
      if ( target_obj )
      {
        v22 = new TRIBE_Action_Trade(v6->obj, task, target_obj);
      }
      else
      {
        v23 = new TRIBE_Action_Trade(v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 3:
      v24 = new RGE_Action_Enter(v6->obj, task, target_obj);
      break;
    case 12:
      v25 = new RGE_Action_Transport(v6->obj, task, target_x, target_y, target_z);
      break;
    default:
      RGE_Action_List::create_task_action(
        task,
        target_obj,
        target_x,
        target_y,
        target_z);
      break;
  }
}

//----- (004D0C50) --------------------------------------------------------
void TRIBE_Action_List::get_action_name(char *action_name)
{
  RGE_Action_Node *v2; // eax@1
  const char *v3; // edi@2
  const char *v4; // edi@5

  v2 = this->list;
  if ( v2 )
  {
    switch ( v2->action->action_type )
    {
      case 101:
        v3 = "Build";
        goto LABEL_15;
      case 102:
        v4 = "MakeObject";
        goto LABEL_17;
      case 103:
        v3 = "MakeTech";
        goto LABEL_15;
      case 104:
        v4 = "Convert";
        goto LABEL_17;
      case 105:
        v3 = "Heal";
        goto LABEL_15;
      case 107:
        v4 = "Artifact";
        goto LABEL_17;
      case 108:
        v3 = "DiscoveryArtifact";
        goto LABEL_15;
      case 110:
        v4 = "Hunt";
        goto LABEL_17;
      case 106:
        v3 = "Repair";
        goto LABEL_15;
      case 111:
        v4 = "Trade";
        goto LABEL_17;
      case 3:
        v3 = "Enter";
        goto LABEL_15;
      case 12:
        v4 = "Transport";
LABEL_17:
        strcpy(action_name, v4);
        break;
      default:
        RGE_Action_List::get_action_name(action_name);
        break;
    }
  }
  else
  {
    v3 = "None";
LABEL_15:
    strcpy(action_name, v3);
  }
}
