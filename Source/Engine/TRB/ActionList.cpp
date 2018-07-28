
//----- (004D0150) --------------------------------------------------------
void __thiscall TRIBE_Action_List::TRIBE_Action_List(TRIBE_Action_List *this, RGE_Action_Object *obj_in)
{
  TRIBE_Action_List *v2; // esi@1

  v2 = this;
  RGE_Action_List::RGE_Action_List((RGE_Action_List *)&this->vfptr, obj_in);
  v2->vfptr = (RGE_Action_ListVtbl *)&TRIBE_Action_List::`vftable';
}
// 575170: using guessed type struct RGE_Action *(__thiscall *TRIBE_Action_List::`vftable')(TRIBE_Action_List *this, int infile, __int16 action_type);

//----- (004D0170) --------------------------------------------------------
void __userpurge TRIBE_Action_List::create_action(TRIBE_Action_List *this@<ecx>, int a2@<ebp>, int infile, __int16 action_type)
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
      v5 = (TRIBE_Action_Build *)operator new(0x40u);
      if ( v5 )
        TRIBE_Action_Build::TRIBE_Action_Build(v5, a2, infile, v4->obj);
      break;
    case 102:
      v6 = (TRIBE_Action_Make_Obj *)operator new(0x50u);
      if ( v6 )
        TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(v6, a2, infile, v4->obj);
      break;
    case 103:
      v7 = (TRIBE_Action_Make_Tech *)operator new(0x48u);
      if ( v7 )
        TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(v7, a2, infile, v4->obj);
      break;
    case 104:
      v8 = (TRIBE_Action_Convert *)operator new(0x48u);
      if ( v8 )
        TRIBE_Action_Convert::TRIBE_Action_Convert(v8, a2, infile, v4->obj);
      break;
    case 105:
      v9 = (TRIBE_Action_Heal *)operator new(0x40u);
      if ( v9 )
        TRIBE_Action_Heal::TRIBE_Action_Heal(v9, a2, infile, v4->obj);
      break;
    case 107:
      v10 = (TRIBE_Action_Artifact *)operator new(0x40u);
      if ( v10 )
        TRIBE_Action_Artifact::TRIBE_Action_Artifact(v10, a2, infile, v4->obj);
      break;
    case 120:
      v11 = (TRIBE_Action_Wonder *)operator new(0x40u);
      if ( v11 )
        TRIBE_Action_Wonder::TRIBE_Action_Wonder(v11, a2, infile, v4->obj);
      break;
    case 108:
      v12 = (TRIBE_Action_Discovery_Artifact *)operator new(0x44u);
      if ( v12 )
        TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(v12, a2, infile, v4->obj);
      break;
    case 110:
      v13 = (TRIBE_Action_Hunt *)operator new(0x44u);
      if ( v13 )
        TRIBE_Action_Hunt::TRIBE_Action_Hunt(v13, a2, infile, v4->obj);
      break;
    case 106:
      v14 = (TRIBE_Action_Repair *)operator new(0x44u);
      if ( v14 )
        TRIBE_Action_Repair::TRIBE_Action_Repair(v14, a2, infile, v4->obj, 1);
      break;
    case 111:
      v15 = (TRIBE_Action_Trade *)operator new(0x48u);
      if ( v15 )
        TRIBE_Action_Trade::TRIBE_Action_Trade(v15, a2, infile, v4->obj);
      break;
    case 12:
      v16 = (RGE_Action_Transport *)operator new(0x40u);
      if ( v16 )
        RGE_Action_Transport::RGE_Action_Transport(v16, a2, infile, v4->obj);
      break;
    case 3:
      v17 = (RGE_Action_Enter *)operator new(0x40u);
      if ( v17 )
        RGE_Action_Enter::RGE_Action_Enter(v17, a2, infile, v4->obj);
      break;
    default:
      RGE_Action_List::create_action((RGE_Action_List *)&this->vfptr, a2, infile, action_type);
      break;
  }
}

//----- (004D05D0) --------------------------------------------------------
void __thiscall TRIBE_Action_List::create_task_action(TRIBE_Action_List *this, RGE_Task *task, RGE_Static_Object *target_obj, float target_x, float target_y, float target_z)
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
        v7 = (TRIBE_Action_Build *)operator new(0x40u);
        if ( v7 )
          TRIBE_Action_Build::TRIBE_Action_Build(v7, v6->obj, task, target_obj);
      }
      else
      {
        v8 = (TRIBE_Action_Build *)operator new(0x40u);
        if ( v8 )
          TRIBE_Action_Build::TRIBE_Action_Build(v8, v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 104:
      if ( target_obj )
      {
        v9 = (TRIBE_Action_Convert *)operator new(0x48u);
        if ( v9 )
          TRIBE_Action_Convert::TRIBE_Action_Convert(v9, v6->obj, task, target_obj);
      }
      else
      {
        v10 = (TRIBE_Action_Convert *)operator new(0x48u);
        if ( v10 )
          TRIBE_Action_Convert::TRIBE_Action_Convert(v10, v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 105:
      if ( target_obj )
      {
        v11 = (TRIBE_Action_Heal *)operator new(0x40u);
        if ( v11 )
          TRIBE_Action_Heal::TRIBE_Action_Heal(v11, v6->obj, task, target_obj);
      }
      else
      {
        v12 = (TRIBE_Action_Heal *)operator new(0x40u);
        if ( v12 )
          TRIBE_Action_Heal::TRIBE_Action_Heal(v12, v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 107:
      if ( target_obj )
      {
        v13 = (TRIBE_Action_Artifact *)operator new(0x40u);
        if ( v13 )
          TRIBE_Action_Artifact::TRIBE_Action_Artifact(v13, v6->obj, task, target_obj);
      }
      else
      {
        v14 = (TRIBE_Action_Artifact *)operator new(0x40u);
        if ( v14 )
          TRIBE_Action_Artifact::TRIBE_Action_Artifact(v14, v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 120:
      v15 = (TRIBE_Action_Wonder *)operator new(0x40u);
      if ( v15 )
        TRIBE_Action_Wonder::TRIBE_Action_Wonder(v15, v6->obj);
      break;
    case 108:
      if ( target_obj )
      {
        v16 = (TRIBE_Action_Discovery_Artifact *)operator new(0x44u);
        if ( v16 )
          TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(v16, v6->obj, task, target_obj);
      }
      else
      {
        v17 = (TRIBE_Action_Discovery_Artifact *)operator new(0x44u);
        if ( v17 )
          TRIBE_Action_Discovery_Artifact::TRIBE_Action_Discovery_Artifact(
            v17,
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
        v18 = (TRIBE_Action_Hunt *)operator new(0x44u);
        if ( v18 )
          TRIBE_Action_Hunt::TRIBE_Action_Hunt(v18, v6->obj, task, target_obj);
      }
      else
      {
        v19 = (TRIBE_Action_Hunt *)operator new(0x44u);
        if ( v19 )
          TRIBE_Action_Hunt::TRIBE_Action_Hunt(v19, v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 106:
      if ( target_obj )
      {
        v20 = (TRIBE_Action_Repair *)operator new(0x44u);
        if ( v20 )
          TRIBE_Action_Repair::TRIBE_Action_Repair(v20, v6->obj, task, target_obj);
      }
      else
      {
        v21 = (TRIBE_Action_Repair *)operator new(0x44u);
        if ( v21 )
          TRIBE_Action_Repair::TRIBE_Action_Repair(v21, v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 111:
      if ( target_obj )
      {
        v22 = (TRIBE_Action_Trade *)operator new(0x48u);
        if ( v22 )
          TRIBE_Action_Trade::TRIBE_Action_Trade(v22, v6->obj, task, target_obj);
      }
      else
      {
        v23 = (TRIBE_Action_Trade *)operator new(0x48u);
        if ( v23 )
          TRIBE_Action_Trade::TRIBE_Action_Trade(v23, v6->obj, task, target_x, target_y, target_z);
      }
      break;
    case 3:
      v24 = (RGE_Action_Enter *)operator new(0x40u);
      if ( v24 )
        RGE_Action_Enter::RGE_Action_Enter(v24, v6->obj, task, target_obj);
      break;
    case 12:
      v25 = (RGE_Action_Transport *)operator new(0x40u);
      if ( v25 )
        RGE_Action_Transport::RGE_Action_Transport(v25, v6->obj, task, target_x, target_y, target_z);
      break;
    default:
      RGE_Action_List::create_task_action(
        (RGE_Action_List *)&this->vfptr,
        task,
        target_obj,
        target_x,
        target_y,
        target_z);
      break;
  }
}

//----- (004D0C50) --------------------------------------------------------
void __thiscall TRIBE_Action_List::get_action_name(TRIBE_Action_List *this, char *action_name)
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
        v3 = aBuild;
        goto LABEL_15;
      case 102:
        v4 = aMakeobject;
        goto LABEL_17;
      case 103:
        v3 = aMaketech;
        goto LABEL_15;
      case 104:
        v4 = aConvert;
        goto LABEL_17;
      case 105:
        v3 = aHeal;
        goto LABEL_15;
      case 107:
        v4 = aArtifact;
        goto LABEL_17;
      case 108:
        v3 = aDiscoveryartif;
        goto LABEL_15;
      case 110:
        v4 = aHunt;
        goto LABEL_17;
      case 106:
        v3 = aRepair;
        goto LABEL_15;
      case 111:
        v4 = aTrade;
        goto LABEL_17;
      case 3:
        v3 = aEnter;
        goto LABEL_15;
      case 12:
        v4 = aTransport;
LABEL_17:
        strcpy(action_name, v4);
        break;
      default:
        RGE_Action_List::get_action_name((RGE_Action_List *)&this->vfptr, action_name);
        break;
    }
  }
  else
  {
    v3 = aNone_3;
LABEL_15:
    strcpy(action_name, v3);
  }
}
