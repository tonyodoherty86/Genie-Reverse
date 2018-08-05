
//----- (0052C3F0) --------------------------------------------------------
RGE_Task *__thiscall TRIBE_Task_List::get_target_task(TRIBE_Task_List *this, RGE_Action_Object *obj, RGE_Static_Object *target_obj, float target_x, float target_y, float target_z)
{
  RGE_Action_Object *v6; // edx@1
  __int16 v7; // bp@1
  __int16 v8; // ax@5
  signed int v9; // ecx@7
  signed int v10; // edi@7
  int v11; // eax@15
  int v12; // edi@18
  int v13; // ebx@18
  RGE_Task **v14; // edx@19
  RGE_Task *result; // eax@20
  __int16 v16; // cx@21
  int v17; // edx@31
  int v18; // esi@31
  RGE_Task **v19; // ecx@32
  RGE_Player *v20; // eax@37
  RGE_Player *v21; // ecx@37
  int v22; // edx@42
  int v23; // esi@42
  RGE_Task **v24; // ecx@43
  RGE_Player *v25; // eax@49
  RGE_Player *v26; // ecx@49
  RGE_Master_Static_Object *v27; // ecx@51
  int v28; // esi@55
  int v29; // edi@55
  RGE_Task **v30; // edx@56
  __int16 v31; // cx@58
  RGE_Player *v32; // eax@64
  RGE_Player *v33; // ecx@64
  RGE_Master_Static_Object *v34; // eax@67
  __int16 v35; // di@67
  int v36; // edx@73
  int v37; // esi@73
  RGE_Task **v38; // ecx@74
  RGE_Player *v39; // eax@82
  RGE_Player *v40; // ecx@82
  __int16 v41; // ax@84
  int v42; // edx@87
  int v43; // esi@87
  RGE_Task **v44; // ecx@88
  RGE_Player *v45; // eax@93
  RGE_Player *v46; // ecx@93
  RGE_Master_Static_Object *v47; // ecx@95
  __int16 v48; // ax@97
  int v49; // edx@104
  int v50; // esi@104
  RGE_Task **v51; // ecx@105
  TRIBE_Task_List *v52; // [sp+10h] [bp-4h]@1

  v6 = obj;
  v7 = obj->attribute_type_held;
  v52 = this;
  if ( v7 == -1 )
    goto LABEL_26;
  if ( obj->attribute_amount_held <= 0.0 )
    goto LABEL_26;
  if ( !target_obj )
    goto LABEL_26;
  if ( target_obj->object_state != 2 )
    goto LABEL_26;
  v8 = obj->master_obj->object_group;
  if ( v8 != 4 && v8 != 21 )
    goto LABEL_26;
  v9 = -1;
  v10 = -1;
  if ( v8 == 4 )
  {
    switch ( v7 )
    {
      case 1:
      case 2:
      case 3:
      case 15:
      case 17:
        v9 = 109;
        v10 = 103;
        break;
      case 16:
        v9 = 109;
        v10 = 68;
        break;
      default:
        break;
    }
  }
  else if ( v8 == 21 && (v7 == 9 || v7 == 17) )
  {
    v9 = 45;
  }
  v11 = target_obj->master_obj->id;
  if ( v11 != v9 && v11 != v10 )
    goto LABEL_26;
  if ( target_obj->owner->id != obj->owner->id || (v12 = 0, v13 = v52->list_num, v13 <= 0) )
  {
    if ( !target_obj )
      goto LABEL_113;
    if ( v6 && target_obj->owner == v6->owner && target_obj->master_obj->master_type == 80 && !target_obj->object_state )
    {
      v17 = 0;
      v18 = v52->list_num;
      if ( v18 > 0 )
      {
        v19 = v52->list;
        while ( 1 )
        {
          result = *v19;
          if ( (*v19)->action_type == 101 )
            break;
          ++v17;
          ++v19;
          if ( v17 >= v18 )
            return 0;
        }
        return result;
      }
      return 0;
    }
    if ( !target_obj )
      goto LABEL_113;
    v20 = target_obj->owner;
    v21 = v6->owner;
    if ( (v20 == v21
       || (*(int (__stdcall **)(_DWORD))&v21->vfptr->gap4[24])(v20->id)
       && (*(int (__stdcall **)(_DWORD))&target_obj->owner->vfptr->gap4[24])(obj->owner->id))
      && target_obj->object_state < 3u
      && target_obj->master_obj->unit_level == 7 )
    {
      v22 = 0;
      v23 = v52->list_num;
      if ( v23 > 0 )
      {
        v24 = v52->list;
        while ( 1 )
        {
          result = *v24;
          if ( (*v24)->action_type == 3 )
            break;
          ++v22;
          ++v24;
          if ( v22 >= v23 )
            return 0;
        }
        return result;
      }
      return 0;
    }
    if ( !target_obj )
      goto LABEL_113;
LABEL_26:
    if ( obj )
    {
      v25 = target_obj->owner;
      v26 = obj->owner;
      if ( v25 == v26 || (*(int (__stdcall **)(_DWORD))&v26->vfptr->gap4[24])(v25->id) )
      {
        v27 = target_obj->master_obj;
        if ( v27->master_type == 80
          && (double)v27->hp > target_obj->hp
          && target_obj->object_state < 3u
          && v27->id != 50 )
        {
          v28 = 0;
          v29 = v52->list_num;
          if ( v29 > 0 )
          {
            v30 = v52->list;
            while ( 1 )
            {
              result = *v30;
              if ( (*v30)->action_type == 106 )
              {
                v31 = result->object_group;
                if ( v31 == -1 || !v31 )
                  break;
              }
              ++v28;
              ++v30;
              if ( v28 >= v29 )
                return 0;
            }
            return result;
          }
          return 0;
        }
      }
    }
    if ( target_obj
      && obj
      && ((v32 = target_obj->owner, v33 = obj->owner, v32 == v33)
       || (*(int (__stdcall **)(_DWORD))&v33->vfptr->gap4[24])(v32->id)
       && (*(int (__stdcall **)(_DWORD))&target_obj->owner->vfptr->gap4[24])(obj->owner->id))
      && ((v34 = target_obj->master_obj, v35 = v34->object_group, v35 == 2) || v35 == 20 || v35 == 21 || v35 == 22)
      && (double)v34->hp > target_obj->hp
      && target_obj->object_state < 3u )
    {
      v36 = 0;
      v37 = v52->list_num;
      if ( v37 > 0 )
      {
        v38 = v52->list;
        while ( 1 )
        {
          result = *v38;
          if ( (*v38)->action_type == 106 && result->object_group == v35 )
            break;
          ++v36;
          ++v38;
          if ( v36 >= v37 )
            return 0;
        }
        return result;
      }
    }
    else
    {
LABEL_113:
      if ( !obj || obj->master_obj->object_group != 18 )
        return RGE_Task_List::get_target_task(
                 (RGE_Task_List *)&v52->vfptr,
                 obj,
                 target_obj,
                 target_x,
                 target_y,
                 target_z);
      if ( target_obj )
      {
        v39 = target_obj->owner;
        v40 = obj->owner;
        if ( v39 == v40
          || target_obj->object_state >= 3u
          || (v41 = v39->id, v41 <= 0)
          || (*(int (__stdcall **)(_DWORD))&v40->vfptr->gap4[24])(v41)
          || target_obj->master_obj->object_group == 1 )
        {
          if ( target_obj )
          {
            v45 = target_obj->owner;
            v46 = obj->owner;
            if ( v45 == v46 || (*(int (__stdcall **)(_DWORD))&v46->vfptr->gap4[24])(v45->id) )
            {
              v47 = target_obj->master_obj;
              if ( (double)v47->hp > target_obj->hp && target_obj->object_state < 3u )
              {
                v48 = v47->object_group;
                if ( v48 != 21 && v48 != 2 && v48 != 20 && v48 != 22 && v48 != 1 && v48 != 27 && v48 != 3 )
                {
                  v49 = 0;
                  v50 = v52->list_num;
                  if ( v50 > 0 )
                  {
                    v51 = v52->list;
                    while ( 1 )
                    {
                      result = *v51;
                      if ( (*v51)->action_type == 105 )
                        break;
                      ++v49;
                      ++v51;
                      if ( v49 >= v50 )
                        return 0;
                    }
                    return result;
                  }
                }
              }
            }
          }
        }
        else
        {
          v42 = 0;
          v43 = v52->list_num;
          if ( v43 > 0 )
          {
            v44 = v52->list;
            while ( 1 )
            {
              result = *v44;
              if ( (*v44)->action_type == 104 )
                break;
              ++v42;
              ++v44;
              if ( v42 >= v43 )
                return 0;
            }
            return result;
          }
        }
      }
    }
    return 0;
  }
  v14 = v52->list;
  while ( 1 )
  {
    result = *v14;
    if ( (*v14)->attribute_type == v7 )
    {
      v16 = result->action_type;
      if ( v16 == 5 || v16 == 110 || v16 == 111 )
        return result;
    }
    ++v12;
    ++v14;
    if ( v12 >= v13 )
    {
      v6 = obj;
      goto LABEL_26;
    }
  }
}

//----- (0052C8D0) --------------------------------------------------------
int __stdcall TRIBE_Task_List::is_attack_task(RGE_Task *task)
{
  int result; // eax@2

  if ( task->action_type == 104 )
    result = 1;
  else
    result = RGE_Task_List::is_attack_task(task);
  return result;
}
