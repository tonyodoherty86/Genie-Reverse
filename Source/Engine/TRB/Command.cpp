
//----- (00509720) --------------------------------------------------------
void __thiscall TRIBE_Command::TRIBE_Command(TRIBE_Command *this, TRIBE_World *world, TCommunications_Handler *com_hand)
{
  TRIBE_Command *v3; // esi@1

  v3 = this;
  RGE_Command::RGE_Command((RGE_Command *)&this->vfptr, (RGE_Game_World *)&world->vfptr, com_hand);
  v3->vfptr = (RGE_CommandVtbl *)&TRIBE_Command::`vftable';
}
// 576558: using guessed type void (__thiscall *TRIBE_Command::`vftable')(RGE_Command *this, struct RGE_Command_Give_Attribute *);

//----- (00509740) --------------------------------------------------------
TRIBE_Command *__thiscall TRIBE_Command::`vector deleting destructor'(TRIBE_Command *this, unsigned int __flags)
{
  TRIBE_Command *v2; // esi@1

  v2 = this;
  TRIBE_Command::~TRIBE_Command(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00509770) --------------------------------------------------------
void __userpurge TRIBE_Command::do_command(TRIBE_Command *this@<ecx>, int a2@<ebx>, void *order)
{
  TRIBE_Command *v3; // esi@1

  v3 = this;
  debug_rand(aCMsdevWorkA_32, 63);
  switch ( *(_BYTE *)order )
  {
    case 0x64:
      TRIBE_Command::do_command_make(v3, (TRIBE_Command_Make *)order);
      break;
    case 0x65:
      TRIBE_Command::do_command_research(v3, (TRIBE_Command_Research *)order);
      break;
    case 0x66:
      TRIBE_Command::do_command_build(v3, (TRIBE_Command_Build *)order);
      break;
    case 0x69:
      TRIBE_Command::do_command_build_wall(v3, (TRIBE_Command_Build_Wall *)order);
      break;
    case 0x68:
      TRIBE_Command::do_command_explore(v3, (TRIBE_Command_Explore *)order);
      break;
    case 0x67:
      TRIBE_Command::do_command_game(v3, (TRIBE_Command_Game *)order);
      break;
    case 4:
      TRIBE_Command::do_command_tribe_create(v3, (RGE_Command_Create *)order);
      break;
    case 0x6A:
      TRIBE_Command::do_command_cancel_build(v3, (TRIBE_Command_Cancel_Build *)order);
      break;
    case 0x6B:
      TRIBE_Command::do_command_attack_ground(v3, (TRIBE_Command_Attack_Ground *)order);
      break;
    case 0x6C:
      v3->vfptr[1].do_command_give_attribute((RGE_Command *)v3, (RGE_Command_Give_Attribute *)order);
      break;
    case 0x6D:
      TRIBE_Command::do_command_trade_attribute(v3, (TRIBE_Command_Trade_Attribute *)order);
      break;
    case 0x6E:
      TRIBE_Command::do_command_repair(v3, (TRIBE_Command_Repair *)order);
      break;
    case 0x6F:
      TRIBE_Command::do_command_unload(v3, (TRIBE_Command_Unload *)order);
      break;
    case 0x77:
      TRIBE_Command::do_command_queue(v3, a2, (TRIBE_Command_Queue *)order);
      break;
    default:
      RGE_Command::do_command((RGE_Command *)&v3->vfptr, order);
      break;
  }
}

//----- (00509910) --------------------------------------------------------
void __thiscall TRIBE_Command::do_command_tribe_create(TRIBE_Command *this, RGE_Command_Create *order)
{
  int v2; // edx@1
  int v3; // esi@1
  RGE_Player *v4; // edx@3
  TRIBE_Building_Object *v5; // eax@3

  v2 = order->player_id;
  v3 = order->obj_catagory;
  if ( this->world->players[v2]->master_objects[v3]->movement_type == 1 )
    LODWORD(order->location_z) = 1082130432;
  v4 = this->world->players[v2];
  v5 = (TRIBE_Building_Object *)((int (__stdcall *)(RGE_Player *, _DWORD, _DWORD, _DWORD))v4->master_objects[v3]->vfptr->make_new_obj)(
                                  v4,
                                  LODWORD(order->location_x),
                                  LODWORD(order->location_y),
                                  LODWORD(order->location_z));
  if ( v5->master_obj->master_type == 80 )
    TRIBE_Building_Object::build(v5, 10000.0);
}

//----- (00509980) --------------------------------------------------------
void __thiscall TRIBE_Command::do_command_make(TRIBE_Command *this, TRIBE_Command_Make *order)
{
  TRIBE_Command_Make *v2; // esi@1
  TRIBE_Command *v3; // ebx@1
  TRIBE_Building_Object *v4; // edi@1
  TRIBE_Action_Make_Obj *v5; // eax@4
  int v6; // eax@5
  UnitAIModule *v7; // eax@10
  int v8; // ST00_4@10
  UnitAIModule *v9; // eax@10
  RGE_Player *v10; // ecx@11
  __int16 progress; // [sp+Ch] [bp-78h]@2
  __int16 work_target; // [sp+Eh] [bp-76h]@2
  TRIBE_Action_Make_Obj *v13; // [sp+10h] [bp-74h]@4
  char work_name[100]; // [sp+14h] [bp-70h]@2
  int v15; // [sp+80h] [bp-4h]@4

  v2 = order;
  v3 = this;
  v4 = (TRIBE_Building_Object *)RGE_Game_World::object(this->world, order->unit_id);
  if ( !v4 )
  {
    v10 = v3->world->players[v2->unit_player_id];
    if ( !v10 )
      return;
    goto LABEL_14;
  }
  TRIBE_Building_Object::work_status(v4, (__int16 *)&order, &work_target, &progress, work_name, 100);
  if ( (_WORD)order == 103 || (_WORD)order == 102 )
  {
    v10 = v3->world->players[v2->unit_player_id];
    if ( !v10 )
      return;
LABEL_14:
    (*(void (__stdcall **)(_DWORD, _DWORD, int, int))&v10->vfptr[1].gap4[16])(0, v2->obj_id, v2->unit_id, v2->unique_id);
    return;
  }
  v5 = (TRIBE_Action_Make_Obj *)operator new(0x50u);
  v13 = v5;
  v15 = 0;
  if ( v5 )
    TRIBE_Action_Make_Obj::TRIBE_Action_Make_Obj(v5, (RGE_Action_Object *)&v4->vfptr, v2->obj_id, v2->unique_id, 0);
  else
    v6 = 0;
  v15 = -1;
  if ( v6 )
    (*(void (__thiscall **)(TRIBE_Building_Object *, int))&v4->vfptr[1].gap4[28])(v4, v6);
  if ( RGE_Static_Object::unitAI((RGE_Static_Object *)&v4->vfptr) )
  {
    v7 = RGE_Static_Object::unitAI((RGE_Static_Object *)&v4->vfptr);
    UnitAIModule::setCurrentAction(v7, 620);
    v8 = v2->unique_id;
    v9 = RGE_Static_Object::unitAI((RGE_Static_Object *)&v4->vfptr);
    UnitAIModule::setCurrentTarget(v9, v8, -1, -1.0, -1.0, -1.0);
  }
}

//----- (00509AF0) --------------------------------------------------------
void __thiscall TRIBE_Command::do_command_research(TRIBE_Command *this, TRIBE_Command_Research *order)
{
  TRIBE_Command_Research *v2; // esi@1
  TRIBE_Command *v3; // ebx@1
  TRIBE_Building_Object *v4; // edi@1
  TRIBE_Action_Make_Tech *v5; // eax@4
  int v6; // eax@5
  UnitAIModule *v7; // eax@10
  int v8; // ST00_4@10
  UnitAIModule *v9; // eax@10
  RGE_Player *v10; // ecx@11
  __int16 progress; // [sp+Ch] [bp-78h]@2
  __int16 work_target; // [sp+Eh] [bp-76h]@2
  TRIBE_Action_Make_Tech *v13; // [sp+10h] [bp-74h]@4
  char work_name[100]; // [sp+14h] [bp-70h]@2
  int v15; // [sp+80h] [bp-4h]@4

  v2 = order;
  v3 = this;
  v4 = (TRIBE_Building_Object *)RGE_Game_World::object(this->world, order->unit_id);
  if ( !v4 )
  {
    v10 = v3->world->players[v2->unit_player_id];
    if ( !v10 )
      return;
    goto LABEL_14;
  }
  TRIBE_Building_Object::work_status(v4, (__int16 *)&order, &work_target, &progress, work_name, 100);
  if ( (_WORD)order == 103 || (_WORD)order == 102 )
  {
    v10 = v3->world->players[v2->unit_player_id];
    if ( !v10 )
      return;
LABEL_14:
    ((void (__stdcall *)(_DWORD, int, signed int, int))v10->vfptr[1].isNeutral)(
      v2->tech_id,
      v2->unit_id,
      -1,
      v2->unique_id);
    return;
  }
  v5 = (TRIBE_Action_Make_Tech *)operator new(0x48u);
  v13 = v5;
  v15 = 0;
  if ( v5 )
    TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(v5, (RGE_Action_Object *)&v4->vfptr, v2->tech_id, v2->unique_id);
  else
    v6 = 0;
  v15 = -1;
  if ( v6 )
    (*(void (__thiscall **)(TRIBE_Building_Object *, int))&v4->vfptr[1].gap4[28])(v4, v6);
  if ( RGE_Static_Object::unitAI((RGE_Static_Object *)&v4->vfptr) )
  {
    v7 = RGE_Static_Object::unitAI((RGE_Static_Object *)&v4->vfptr);
    UnitAIModule::setCurrentAction(v7, 620);
    v8 = v2->unique_id;
    v9 = RGE_Static_Object::unitAI((RGE_Static_Object *)&v4->vfptr);
    UnitAIModule::setCurrentTarget(v9, v8, -1, -1.0, -1.0, -1.0);
  }
}

//----- (00509C60) --------------------------------------------------------
void __thiscall TRIBE_Command::do_command_build(TRIBE_Command *this, TRIBE_Command_Build *order)
{
  TRIBE_Command_Build *v2; // esi@1
  TRIBE_Player *v3; // edi@1
  __int16 v4; // ax@2
  RGE_Master_Static_Object *v5; // ebx@3
  RGE_Master_Static_ObjectVtbl *v6; // ebp@4
  RGE_Static_Object *v7; // eax@6
  RGE_Static_Object *v8; // eax@10
  int v9; // ebp@12
  RGE_Obj_Info *v10; // ebx@13
  RGE_Static_Object *v11; // eax@14
  RGE_Static_Object *v12; // edi@14
  TRIBE_Command *v13; // [sp+3Ch] [bp-Ch]@1
  int blockingObject; // [sp+40h] [bp-8h]@4
  int placementResult; // [sp+44h] [bp-4h]@4
  TRIBE_Command_Build *ordera; // [sp+4Ch] [bp+4h]@1

  v2 = order;
  v13 = this;
  ordera = (TRIBE_Command_Build *)order->unit_num;
  v3 = (TRIBE_Player *)this->world->players[v2->unit_player_id];
  if ( v3 )
  {
    v4 = v2->obj_id;
    if ( v4 != -1 )
    {
      v5 = v3->master_objects[v4];
      if ( v5 )
      {
        v6 = v5->vfptr;
        LOBYTE(placementResult) = ((int (__thiscall *)(RGE_Master_Static_Object *, TRIBE_Player *, _DWORD, _DWORD, int *, signed int, signed int, signed int, signed int, signed int, signed int))v5->vfptr->check_placement)(
                                    v5,
                                    v3,
                                    LODWORD(v2->location_x),
                                    LODWORD(v2->location_y),
                                    &blockingObject,
                                    1,
                                    1,
                                    1,
                                    1,
                                    1,
                                    1);
        if ( (_BYTE)placementResult )
        {
          if ( (signed int)ordera > 0 )
          {
            v7 = RGE_Command::get_obj((RGE_Command *)&v13->vfptr, *(RGE_Obj_Info *)&v2[1].command);
            if ( v7 )
              (*(void (__thiscall **)(TRIBE_Player *, _DWORD, int, _DWORD, _DWORD, _DWORD, int, int))&v3->vfptr[1].gap4[4])(
                v3,
                (unsigned __int8)placementResult,
                blockingObject,
                v2->obj_id,
                LODWORD(v2->location_x),
                LODWORD(v2->location_y),
                v2->unique_id,
                v7->id);
          }
        }
        else if ( TRIBE_Player::pay_obj_cost(v3, v2->obj_id, 1.0, 0) )
        {
          v9 = (*((int (__thiscall **)(RGE_Master_Static_Object *, TRIBE_Player *, _DWORD, _DWORD, _DWORD, int))&v6[1].__vecDelDtor
                + 1))(
                 v5,
                 v3,
                 LODWORD(v2->location_x),
                 LODWORD(v2->location_y),
                 0,
                 v2->unique_id);
          if ( (signed int)ordera > 0 )
          {
            v10 = (RGE_Obj_Info *)&v2[1];
            do
            {
              v11 = RGE_Command::get_obj((RGE_Command *)&v13->vfptr, (RGE_Obj_Info)v10->id);
              v12 = v11;
              if ( v11 )
              {
                RGE_Static_Object::removeAllFromPathingGroup(v11);
                ((void (__thiscall *)(RGE_Static_Object *, int, _DWORD, _DWORD, _DWORD))v12->vfptr->do_command)(
                  v12,
                  v9,
                  LODWORD(v2->location_x),
                  LODWORD(v2->location_y),
                  0);
              }
              ++v10;
              ordera = (TRIBE_Command_Build *)((char *)ordera - 1);
            }
            while ( ordera );
          }
        }
        else if ( (signed int)ordera > 0 )
        {
          v8 = RGE_Command::get_obj((RGE_Command *)&v13->vfptr, *(RGE_Obj_Info *)&v2[1].command);
          if ( v8 )
            (*(void (__thiscall **)(TRIBE_Player *, _DWORD, int, _DWORD, _DWORD, _DWORD, int, int))&v3->vfptr[1].gap4[4])(
              v3,
              0,
              blockingObject,
              v2->obj_id,
              LODWORD(v2->location_x),
              LODWORD(v2->location_y),
              v2->unique_id,
              v8->id);
        }
      }
    }
  }
}

//----- (00509E10) --------------------------------------------------------
void __thiscall TRIBE_Command::do_command_build_wall(TRIBE_Command *this, TRIBE_Command_Build_Wall *order)
{
  TRIBE_Command_Build_Wall *v2; // esi@1
  TRIBE_Command *v3; // ebp@1
  TRIBE_Player *v4; // edi@1
  __int16 v5; // ax@2
  TRIBE_Master_Building_Object *v6; // ebx@3
  int v7; // eax@4
  int v8; // ecx@4
  int v9; // eax@4
  int v10; // eax@4
  char v11; // cl@7
  char v12; // al@7
  char v13; // cl@11
  char v14; // al@11
  int v15; // ecx@12
  int v16; // eax@12
  RGE_Obj_Info *v17; // edi@19
  int v18; // ebx@19
  RGE_Static_Object *v19; // eax@20
  RGE_Static_Object *v20; // esi@20
  int v21; // [sp-14h] [bp-3Ch]@8
  int v22; // [sp-10h] [bp-38h]@8
  int v23; // [sp-Ch] [bp-34h]@8
  int v24; // [sp-8h] [bp-30h]@8
  RGE_Static_Object **v25; // [sp-4h] [bp-2Ch]@8
  int y2; // [sp+10h] [bp-18h]@4
  int x2; // [sp+14h] [bp-14h]@4
  int x1; // [sp+18h] [bp-10h]@4
  int v29; // [sp+1Ch] [bp-Ch]@4
  int unitNum; // [sp+20h] [bp-8h]@1
  RGE_Obj_Info *units; // [sp+24h] [bp-4h]@1

  v2 = order;
  v3 = this;
  unitNum = order->unit_num;
  units = (RGE_Obj_Info *)&order[1];
  v4 = (TRIBE_Player *)this->world->players[order->unit_player_id];
  if ( !v4 )
    return;
  v5 = order->obj_id;
  if ( v5 == -1 )
    return;
  v6 = (TRIBE_Master_Building_Object *)v4->master_objects[v5];
  if ( !v6 )
    return;
  v7 = order->y2;
  v8 = order->y1;
  y2 = v7;
  order = 0;
  v29 = abs(v7 - v8);
  x1 = v2->x1;
  v9 = v2->x2;
  x2 = v9;
  v10 = abs(v9 - x1);
  if ( v29 != v10 )
  {
    if ( v29 < v10 )
    {
      TRIBE_Command::place_line_of_walls(v4, v6, v2->unique_id, x1, v8, x2, v8, (RGE_Static_Object **)&order);
      v13 = v2->y2;
      v14 = v2->y1;
      if ( (unsigned __int8)v14 >= (unsigned __int8)v13 )
      {
        if ( (unsigned __int8)v14 <= (unsigned __int8)v13 )
          goto LABEL_17;
        v25 = (RGE_Static_Object **)&order;
        v24 = v2->y2;
        v15 = v2->x2;
        v16 = v2->y1 - 1;
        v23 = v2->x2;
      }
      else
      {
        v25 = (RGE_Static_Object **)&order;
        v24 = v2->y2;
        v15 = v2->x2;
        v16 = v2->y1 + 1;
        v23 = v2->x2;
      }
      v22 = v16;
      v21 = v15;
    }
    else
    {
      TRIBE_Command::place_line_of_walls(v4, v6, v2->unique_id, x1, v8, x1, y2, (RGE_Static_Object **)&order);
      v11 = v2->x2;
      v12 = v2->x1;
      if ( (unsigned __int8)v12 >= (unsigned __int8)v11 )
      {
        if ( (unsigned __int8)v12 <= (unsigned __int8)v11 )
          goto LABEL_17;
        v25 = (RGE_Static_Object **)&order;
        v24 = v2->y2;
        v23 = v2->x2;
        v22 = v2->y2;
        v21 = v2->x1 - 1;
      }
      else
      {
        v25 = (RGE_Static_Object **)&order;
        v24 = v2->y2;
        v23 = v2->x2;
        v22 = v2->y2;
        v21 = v2->x1 + 1;
      }
    }
    TRIBE_Command::place_line_of_walls(v4, v6, v2->unique_id, v21, v22, v23, v24, v25);
    goto LABEL_17;
  }
  TRIBE_Command::place_line_of_walls(v4, v6, v2->unique_id, x1, v8, x2, y2, (RGE_Static_Object **)&order);
LABEL_17:
  if ( order && unitNum > 0 )
  {
    v17 = units;
    v18 = unitNum;
    do
    {
      v19 = RGE_Command::get_obj((RGE_Command *)&v3->vfptr, (RGE_Obj_Info)v17->id);
      v20 = v19;
      if ( v19 )
      {
        RGE_Static_Object::removeAllFromPathingGroup(v19);
        ((void (__thiscall *)(RGE_Static_Object *, TRIBE_Command_Build_Wall *, _DWORD, int, _DWORD))v20->vfptr->do_command)(
          v20,
          order,
          *(_DWORD *)&order[3].obj_id,
          order[3].unique_id,
          0);
      }
      ++v17;
      --v18;
    }
    while ( v18 );
  }
}

//----- (0050A010) --------------------------------------------------------
void __stdcall TRIBE_Command::place_line_of_walls(TRIBE_Player *player, TRIBE_Master_Building_Object *master_obj, int unique_id, int x1, int y1, int x2, int y2, RGE_Static_Object **first_wall)
{
  int v9; // ecx@1
  TRIBE_Master_Building_Object *v10; // esi@7
  TRIBE_Player *v11; // ebp@7
  RGE_Static_Object *v12; // eax@10
  int x_skip; // [sp+3Ch] [bp-Ch]@2
  int y_skip; // [sp+40h] [bp-8h]@5
  char (__thiscall *v15)(RGE_Master_Static_Object *, RGE_Player *, float, float, int *, char, char, char, char, char, char); // [sp+44h] [bp-4h]@7
  TRIBE_Player *playera; // [sp+4Ch] [bp+4h]@8
  float world_x; // [sp+50h] [bp+8h]@8
  signed int x1a; // [sp+58h] [bp+10h]@7
  int y; // [sp+5Ch] [bp+14h]@7

  v9 = x1;
  if ( x1 == x2 )
    x_skip = 0;
  else
    x_skip = x2 <= x1 ? -1 : 1;
  if ( y1 == y2 )
    y_skip = 0;
  else
    y_skip = y2 <= y1 ? -1 : 1;
  v10 = master_obj;
  v11 = player;
  x1a = y1;
  y = v9;
  v15 = master_obj->vfptr->check_placement;
  while ( 1 )
  {
    LOBYTE(v9) = v10->elevation_flag;
    *(float *)&playera = (double)y - -0.5;
    world_x = (double)x1a - -0.5;
    if ( !(unsigned __int8)((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v15)(
                             v10,
                             v11,
                             playera,
                             LODWORD(world_x),
                             0,
                             1,
                             v9,
                             0,
                             1,
                             1,
                             1) )
    {
      if ( !TRIBE_Player::pay_obj_cost(v11, v10->id, 1.0, 0) )
        return;
      v12 = (RGE_Static_Object *)(*((int (__thiscall **)(TRIBE_Master_Building_Object *, TRIBE_Player *, TRIBE_Player *, float, _DWORD, int))&v10->vfptr[1].__vecDelDtor
                                  + 1))(
                                   v10,
                                   v11,
                                   playera,
                                   COERCE_FLOAT(LODWORD(world_x)),
                                   0,
                                   unique_id);
      if ( v12 && !*first_wall )
        *first_wall = v12;
    }
    if ( y == x2 && x1a == y2 )
      break;
    v9 = x_skip;
    y += x_skip;
    x1a += y_skip;
  }
}

//----- (0050A140) --------------------------------------------------------
void __thiscall TRIBE_Command::do_command_explore(TRIBE_Command *this, TRIBE_Command_Explore *order)
{
  TRIBE_Command *v2; // ebp@1
  TRIBE_Command_Explore *v3; // edi@1
  RGE_Obj_Info *v4; // ebx@1
  char v5; // al@2
  RGE_Static_Object *v6; // eax@3
  RGE_Static_Object *v7; // esi@3
  TRIBE_Command *v8; // [sp+Ch] [bp-4h]@1
  TRIBE_Command_Explore *ordera; // [sp+14h] [bp+4h]@2

  v2 = this;
  v3 = order;
  v8 = this;
  v4 = (RGE_Obj_Info *)&order[1];
  if ( this->world->players[order->unit_player_id] )
  {
    v5 = order->numUnits;
    ordera = 0;
    if ( v5 )
    {
      do
      {
        v6 = RGE_Command::get_obj((RGE_Command *)&v2->vfptr, (RGE_Obj_Info)v4->id);
        v7 = v6;
        if ( v6 )
        {
          RGE_Static_Object::removeAllFromPathingGroup(v6);
          ((void (__fastcall *)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD, signed int))v7->vfptr->explore)(
            v7,
            (unsigned __int64)(signed __int64)v3->targetXPosition >> 32,
            (signed __int64)v3->targetXPosition,
            (signed __int64)v3->targetYPosition,
            1);
          v2 = v8;
        }
        ++v4;
        ordera = (TRIBE_Command_Explore *)((char *)ordera + 1);
      }
      while ( (signed int)ordera < v3->numUnits );
    }
  }
}

//----- (0050A1D0) --------------------------------------------------------
void __thiscall TRIBE_Command::do_command_game(TRIBE_Command *this, TRIBE_Command_Game *order)
{
  TRIBE_Command *v2; // edi@1
  TRIBE_Screen_Status_Message *v3; // eax@5
  unsigned int v4; // eax@14
  TEasy_Panel *v5; // esi@14
  TDrawSystem *v6; // edi@15
  void *v7; // eax@15
  float v8; // eax@17
  char fileName[260]; // [sp+10h] [bp-110h]@14
  int v10; // [sp+11Ch] [bp-4h]@5

  v2 = this;
  switch ( order->game_command )
  {
    case 5:
      RGE_Player::set_allied_victory(this->world->players[order->var1], order->var2);
      break;
    case 0:
      RGE_Player::set_relation(this->world->players[order->var1], order->var2, (signed __int64)order->var3);
      ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD))rge_base_game->vfptr->notification)(
        8,
        order->var1,
        order->var2,
        order->var4,
        0);
      RGE_Game_World::update_mutual_allies(v2->world);
      break;
    case 1:
      RGE_Game_World::set_game_speed(this->world, order->var3);
      break;
    case 8:
      out_of_sync2 = 1;
      v3 = (TRIBE_Screen_Status_Message *)operator new(0x47Cu);
      v10 = 0;
      if ( v3 )
        TRIBE_Screen_Status_Message::TRIBE_Screen_Status_Message(v3, aTempScreen, message_in, 0, -1);
      v10 = -1;
      TPanelSystem::setCurrentPanel(&panel_system, aTempScreen, 0);
      TRIBE_Game::close_game_screens((TRIBE_Game *)rge_base_game, 1);
      if ( do_debug_random )
      {
        debug_random_write();
        dump_vismap_log();
        if ( actionFile )
        {
          fclose(actionFile);
          actionFile = 0;
        }
        if ( DVlogf )
        {
          fclose(DVlogf);
          DVlogf = 0;
        }
        if ( DDlogf )
        {
          fclose(DDlogf);
          DDlogf = 0;
        }
      }
      v4 = TCommunications_Handler::WhoAmI(comm);
      sprintf(fileName, aSyncerrD_gam, v4);
      TRIBE_Game::save_game((TRIBE_Game *)rge_base_game, fileName);
      RGE_Player::loss_if_game_on(v2->world->players[v2->world->curr_player]);
      TRIBE_Game::do_game_over((TRIBE_Game *)rge_base_game);
      v5 = (TEasy_Panel *)TPanelSystem::currentPanel(&panel_system);
      if ( v5 )
      {
        v6 = rge_base_game->draw_system;
        v7 = TEasy_Panel::get_palette(v5);
        TDrawSystem::SetPalette(v6, v7);
        RGE_Base_Game::set_render_all(rge_base_game);
        RGE_Base_Game::draw_window(rge_base_game);
        TEasy_Panel::popupOKDialog(v5, 2406, 0, 450, 100);
      }
      TPanelSystem::destroyPanel(&panel_system, aTempScreen);
      break;
    case 2:
      v8 = order->var3;
      LOWORD(v8) = order->var2;
      ((void (__stdcall *)(_DWORD, _DWORD, _DWORD))this->world->players[order->var1]->vfptr->add_attribute_num)(
        LODWORD(v8),
        LODWORD(order->var3),
        0);
      break;
    case 4:
      rge_base_game->quick_build = order->var1;
      break;
    case 6:
      TRIBE_World::cheat((TRIBE_World *)this->world, order->var1, LOBYTE(order->var2));
      break;
    case 7:
      ((void (__stdcall *)(signed int, RGE_Player *))this->world->effects->vfptr->do_effect)(
        113,
        this->world->players[order->var1]);
      break;
    default:
      return;
  }
}
// 62C4D0: using guessed type int do_debug_random;
// 62C564: using guessed type int out_of_sync2;

//----- (0050A490) --------------------------------------------------------
void __thiscall TRIBE_Command::do_command_cancel_build(TRIBE_Command *this, TRIBE_Command_Cancel_Build *order)
{
  RGE_Static_Object *v2; // eax@1

  v2 = RGE_Game_World::object(this->world, order->unit_id);
  if ( v2 )
    ((void (__thiscall *)(RGE_Static_Object *))v2->vfptr[1].copy_obj)(v2);
}

//----- (0050A4C0) --------------------------------------------------------
void __thiscall TRIBE_Command::do_command_attack_ground(TRIBE_Command *this, TRIBE_Command_Attack_Ground *order)
{
  TRIBE_Command *v2; // ebx@1
  RGE_Obj_Info *v3; // edi@1
  int v4; // ebp@2
  RGE_Static_Object *v5; // eax@3

  v2 = this;
  v3 = (RGE_Obj_Info *)&order[1];
  if ( order->unit_num > 0 )
  {
    v4 = order->unit_num;
    do
    {
      v5 = RGE_Command::get_obj((RGE_Command *)&v2->vfptr, (RGE_Obj_Info)v3->id);
      if ( v5 )
        (*((void (__thiscall **)(RGE_Static_Object *, _DWORD, _DWORD, _DWORD, signed int))&v5->vfptr->notify + 1))(
          v5,
          LODWORD(order->location_x),
          LODWORD(order->location_y),
          0,
          1);
      ++v3;
      --v4;
    }
    while ( v4 );
  }
}

//----- (0050A510) --------------------------------------------------------
void __thiscall TRIBE_Command::do_command_give_attribute(TRIBE_Command *this, TRIBE_Command_Give_Attribute *order)
{
  TRIBE_Command_Give_Attribute *v2; // esi@1
  TRIBE_Command *v3; // edi@1
  RGE_Player **v4; // ecx@6
  int v5; // ebx@6
  double v6; // st7@6
  float *v7; // eax@6
  bool v8; // c0@6
  bool v9; // c3@6
  float *v10; // ebx@6
  RGE_Player **v11; // edx@8
  RGE_Player *v12; // ecx@8
  float v13; // ST3C_4@8
  float v14; // ST24_4@8
  float v15; // ST24_4@8
  int v16; // ebx@8
  RGE_Player *v17; // edi@8
  float cost; // [sp+3Ch] [bp-4h]@1
  TRIBE_Command_Give_Attribute *ordera; // [sp+44h] [bp+4h]@2

  v2 = order;
  v3 = this;
  cost = 0.0;
  if ( order->attr_amount < 0.0 )
    *(float *)&ordera = 0.0;
  else
    ordera = (TRIBE_Command_Give_Attribute *)LODWORD(order->attr_amount);
  if ( *(float *)&ordera > 0.0 )
    cost = v2->attr_cost * *(float *)&ordera;
  v4 = this->world->players;
  v5 = v2->attr_id;
  v6 = *(float *)&ordera + cost;
  v7 = v4[v2->player_id]->attributes;
  v8 = v6 < v7[v5];
  v9 = v6 == v7[v5];
  v10 = &v7[v5];
  if ( !v8 && !v9 )
  {
    cost = *v10 * v2->attr_cost;
    *(float *)&ordera = *v10 - cost;
  }
  ((void (__stdcall *)(_WORD, TRIBE_Command_Give_Attribute *, _DWORD))v4[v2->to_player_id]->vfptr->add_attribute_num)(
    v2->attr_id,
    ordera,
    0);
  v11 = v3->world->players;
  v12 = v11[v2->player_id];
  v13 = *(float *)&ordera + cost;
  LOWORD(v11) = v2->attr_id;
  v14 = -v13;
  ((void (__stdcall *)(RGE_Player **, _DWORD, _DWORD))v12->vfptr->add_attribute_num)(v11, LODWORD(v14), 0);
  ((void (__stdcall *)(signed int, _DWORD, _DWORD))v3->world->players[v2->player_id]->vfptr->add_attribute_num)(
    53,
    LODWORD(v13),
    0);
  v15 = -*(float *)&ordera;
  ((void (__stdcall *)(signed int, _DWORD, _DWORD))v3->world->players[v2->to_player_id]->vfptr->add_attribute_num)(
    53,
    LODWORD(v15),
    0);
  rge_base_game->vfptr->notification(
    rge_base_game,
    7,
    v2->player_id,
    v2->to_player_id,
    v2->attr_id,
    (signed __int64)*(float *)&ordera);
  v16 = v2->to_player_id;
  v17 = v3->world->players[v16];
  ((void (__fastcall *)(RGE_Player *, _DWORD, _DWORD, int, signed int, _DWORD, _DWORD, _DWORD))v17->vfptr->notify)(
    v17,
    (unsigned __int64)(signed __int64)v2->attr_amount >> 32,
    v2->player_id,
    v16,
    522,
    v2->attr_id,
    (signed __int64)v2->attr_amount,
    0);
}

//----- (0050A6A0) --------------------------------------------------------
void __thiscall TRIBE_Command::do_command_trade_attribute(TRIBE_Command *this, TRIBE_Command_Trade_Attribute *order)
{
  TRIBE_Command *v2; // edi@1
  RGE_Obj_Info *v3; // esi@1
  int v4; // ebx@2
  RGE_Static_Object *v5; // eax@3

  v2 = this;
  v3 = (RGE_Obj_Info *)&order[1];
  if ( order->unit_num > 0 )
  {
    v4 = order->unit_num;
    do
    {
      v5 = RGE_Command::get_obj((RGE_Command *)&v2->vfptr, (RGE_Obj_Info)v3->id);
      if ( v5 )
        v5->attribute_type_held = order->attribute;
      ++v3;
      --v4;
    }
    while ( v4 );
  }
}

//----- (0050A6E0) --------------------------------------------------------
void __thiscall TRIBE_Command::do_command_repair(TRIBE_Command *this, TRIBE_Command_Repair *order)
{
  TRIBE_Command *v2; // ebx@1
  int v3; // edi@1
  RGE_Obj_Info *v4; // esi@1
  RGE_Static_Object *v5; // ebp@1
  TRIBE_Combat_Object *v6; // eax@2

  v2 = this;
  v3 = order->unit_num;
  v4 = (RGE_Obj_Info *)&order[1];
  v5 = RGE_Command::get_obj((RGE_Command *)&this->vfptr, order->target);
  if ( v3 > 0 )
  {
    do
    {
      v6 = (TRIBE_Combat_Object *)RGE_Command::get_obj((RGE_Command *)&v2->vfptr, (RGE_Obj_Info)v4->id);
      if ( v6 )
        TRIBE_Combat_Object::do_repair(v6, v5);
      ++v4;
      --v3;
    }
    while ( v3 );
  }
}

//----- (0050A730) --------------------------------------------------------
void __thiscall TRIBE_Command::do_command_unload(TRIBE_Command *this, TRIBE_Command_Unload *order)
{
  TRIBE_Command_Unload *v2; // edi@1
  RGE_Obj_Info *v3; // ebx@1
  RGE_Static_Object *v4; // eax@3
  RGE_Static_Object *v5; // esi@3
  TRIBE_Command *v6; // [sp+28h] [bp-4h]@1
  TRIBE_Command_Unload *ordera; // [sp+30h] [bp+4h]@2

  v2 = order;
  v6 = this;
  v3 = (RGE_Obj_Info *)&order[1];
  if ( order->unit_num > 0 )
  {
    ordera = (TRIBE_Command_Unload *)order->unit_num;
    do
    {
      v4 = RGE_Command::get_obj((RGE_Command *)&v6->vfptr, (RGE_Obj_Info)v3->id);
      v5 = v4;
      if ( v4 )
      {
        RGE_Static_Object::removeAllFromPathingGroup(v4);
        ((void (__stdcall *)(_DWORD, _DWORD, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, signed int, signed int, _DWORD, signed int))v5->owner->vfptr->processAIOrder)(
          v5->owner->id,
          v5->id,
          721,
          v5->id,
          v5->owner->id,
          LODWORD(v2->location_x),
          LODWORD(v2->location_y),
          0,
          1065353216,
          1,
          0,
          100);
      }
      ++v3;
      ordera = (TRIBE_Command_Unload *)((char *)ordera - 1);
    }
    while ( ordera );
  }
}

//----- (0050A7B0) --------------------------------------------------------
void __userpurge TRIBE_Command::do_command_queue(TRIBE_Command *this@<ecx>, int a2@<ebx>, TRIBE_Command_Queue *order)
{
  TRIBE_Building_Object *v3; // ecx@1
  __int16 v4; // dx@2

  v3 = (TRIBE_Building_Object *)RGE_Game_World::object(this->world, order->bldg_id);
  if ( v3 )
  {
    v4 = order->train_count;
    if ( v4 <= 0 )
      TRIBE_Building_Object::remove_from_production_queue(v3, a2, order->train_id, -v4);
    else
      TRIBE_Building_Object::add_to_production_queue(v3, a2, order->train_id, v4);
  }
}

//----- (0050A7F0) --------------------------------------------------------
void __thiscall TRIBE_Command::command_make(TRIBE_Command *this, RGE_Static_Object *unit, __int16 obj_id)
{
  TRIBE_Command *v3; // ebx@1
  void *v4; // eax@2
  void *v5; // esi@2
  char v6; // dl@3

  v3 = this;
  if ( unit )
  {
    v4 = calloc(1u, 0x10u);
    v5 = v4;
    if ( v4 )
    {
      *((_DWORD *)v4 + 1) = unit->id;
      v6 = unit->owner->id;
      *(_BYTE *)v4 = 100;
      *((_BYTE *)v4 + 8) = v6;
      *((_WORD *)v4 + 5) = obj_id;
      *((_DWORD *)v4 + 3) = -1;
      TDebuggingLog::Log(L, aSendCmdMakeUni, unit->master_obj->name, obj_id);
      RGE_Command::submit((RGE_Command *)&v3->vfptr, v5, 16);
    }
  }
}

//----- (0050A860) --------------------------------------------------------
void __thiscall TRIBE_Command::command_make(TRIBE_Command *this, int playerID, int buildingID, int objID, int uniqueID)
{
  TRIBE_Command *v5; // ebx@1
  _DWORD *v6; // esi@2

  v5 = this;
  if ( buildingID >= 0 )
  {
    v6 = calloc(1u, 0x10u);
    if ( v6 )
    {
      v6[1] = buildingID;
      *((_BYTE *)v6 + 8) = playerID;
      *(_BYTE *)v6 = 100;
      *((_WORD *)v6 + 5) = objID;
      v6[3] = uniqueID;
      TDebuggingLog::Log(L, aSendCmdMake2Pl, playerID, buildingID, objID);
      RGE_Command::submit((RGE_Command *)&v5->vfptr, v6, 16);
    }
  }
}

//----- (0050A8D0) --------------------------------------------------------
void __thiscall TRIBE_Command::command_research(TRIBE_Command *this, RGE_Static_Object *unit, __int16 tech_id)
{
  TRIBE_Command *v3; // ebx@1
  void *v4; // eax@2
  void *v5; // esi@2
  char v6; // dl@3

  v3 = this;
  if ( unit )
  {
    v4 = calloc(1u, 0x10u);
    v5 = v4;
    if ( v4 )
    {
      *((_DWORD *)v4 + 1) = unit->id;
      v6 = unit->owner->id;
      *(_BYTE *)v4 = 101;
      *((_BYTE *)v4 + 8) = v6;
      *((_WORD *)v4 + 5) = tech_id;
      *((_DWORD *)v4 + 3) = -1;
      TDebuggingLog::Log(L, aSendCmdResearc, unit->master_obj->name, tech_id);
      RGE_Command::submit((RGE_Command *)&v3->vfptr, v5, 16);
    }
  }
}

//----- (0050A940) --------------------------------------------------------
void __thiscall TRIBE_Command::command_research(TRIBE_Command *this, int playerID, int buildingID, int techID, int uniqueID)
{
  TRIBE_Command *v5; // ebx@1
  _DWORD *v6; // esi@2

  v5 = this;
  if ( buildingID >= 0 )
  {
    v6 = calloc(1u, 0x10u);
    if ( v6 )
    {
      v6[1] = buildingID;
      *((_BYTE *)v6 + 8) = playerID;
      *(_BYTE *)v6 = 101;
      *((_WORD *)v6 + 5) = techID;
      v6[3] = uniqueID;
      TDebuggingLog::Log(L, aSendCmdResea_1, playerID, buildingID, techID);
      RGE_Command::submit((RGE_Command *)&v5->vfptr, v6, 16);
    }
  }
}

//----- (0050A9B0) --------------------------------------------------------
void __thiscall TRIBE_Command::command_build(TRIBE_Command *this, RGE_Static_Object **unit, __int16 list_num, __int16 obj_id, float location_x, float location_y)
{
  RGE_Static_Object **v6; // ebp@1
  void *v7; // eax@3
  _BYTE *v8; // esi@3
  bool v9; // zf@3
  char *v10; // eax@3
  int v11; // ebp@5
  char *v12; // edx@5
  int v13; // ecx@6
  __int16 v14; // ax@12
  TRIBE_Command *v15; // [sp+10h] [bp-4h]@1

  v6 = unit;
  v15 = this;
  if ( unit )
  {
    if ( list_num >= 1 )
    {
      v7 = calloc(1u, 4 * list_num + 20);
      v8 = v7;
      v9 = v7 == 0;
      v10 = (char *)v7 + 20;
      if ( !v9 )
      {
        if ( list_num > 0 )
        {
          v11 = list_num;
          v12 = (char *)((char *)unit - v10);
          do
          {
            v13 = *(_DWORD *)&v10[(_DWORD)v12];
            if ( v13 )
              *(_DWORD *)v10 = *(_DWORD *)(v13 + 4);
            else
              *(_DWORD *)v10 = -1;
            v10 += 4;
            --v11;
          }
          while ( v11 );
          v6 = unit;
        }
        *v8 = 102;
        v8[1] = list_num;
        if ( *v6 )
          v14 = (*v6)->owner->id;
        else
          LOBYTE(v14) = -1;
        v8[2] = v14;
        *((_WORD *)v8 + 6) = obj_id;
        *((float *)v8 + 1) = location_x;
        *((float *)v8 + 2) = location_y;
        *((_DWORD *)v8 + 4) = -1;
        TDebuggingLog::Log(L, aSendCmdBuildCn, list_num, obj_id);
        RGE_Command::submit((RGE_Command *)&v15->vfptr, v8, 4 * list_num + 20);
      }
    }
  }
}

//----- (0050AA90) --------------------------------------------------------
void __thiscall TRIBE_Command::command_build(TRIBE_Command *this, int playerID, int *unitID, int numUnits, int objectID, float xLoc, float yLoc, int uniqueID)
{
  void *v8; // eax@3
  float *v9; // esi@3
  bool v10; // zf@3
  char *v11; // eax@3
  int v12; // edx@5
  char *v13; // ecx@5
  TRIBE_Command *v14; // [sp+10h] [bp-4h]@1

  v14 = this;
  if ( unitID )
  {
    if ( numUnits >= 1 )
    {
      v8 = calloc(1u, 4 * numUnits + 20);
      v9 = (float *)v8;
      v10 = v8 == 0;
      v11 = (char *)v8 + 20;
      if ( !v10 )
      {
        if ( numUnits > 0 )
        {
          v12 = numUnits;
          v13 = (char *)((char *)unitID - v11);
          do
          {
            *(_DWORD *)v11 = *(_DWORD *)&v11[(_DWORD)v13];
            v11 += 4;
            --v12;
          }
          while ( v12 );
        }
        v9[1] = xLoc;
        v9[2] = yLoc;
        *(_BYTE *)v9 = 102;
        *((_BYTE *)v9 + 1) = numUnits;
        *((_WORD *)v9 + 6) = objectID;
        *((_DWORD *)v9 + 4) = uniqueID;
        *((_BYTE *)v9 + 2) = playerID;
        TDebuggingLog::Log(L, aSendCmdBuild2C, numUnits, objectID);
        RGE_Command::submit((RGE_Command *)&v14->vfptr, v9, 4 * numUnits + 20);
      }
    }
  }
}

//----- (0050AB30) --------------------------------------------------------
void __thiscall TRIBE_Command::command_build_wall(TRIBE_Command *this, RGE_Static_Object **unit, __int16 list_num, __int16 obj_id, int x1, int y1, int x2, int y2)
{
  RGE_Static_Object **v8; // edi@1
  __int16 v9; // bx@2
  int v10; // ebp@3
  void *v11; // eax@3
  _BYTE *v12; // esi@3
  bool v13; // zf@3
  char *v14; // eax@3
  int v15; // edi@5
  char *v16; // edx@5
  int v17; // ecx@6
  __int16 v18; // ax@12
  int v19; // ebx@14
  int v20; // edx@18
  int v21; // ecx@22
  int v22; // eax@26
  TRIBE_Command *v23; // [sp+10h] [bp-4h]@1
  int list_numa; // [sp+1Ch] [bp+8h]@3

  v8 = unit;
  v23 = this;
  if ( unit )
  {
    v9 = list_num;
    if ( list_num >= 1 )
    {
      v10 = list_num;
      list_numa = 4 * list_num + 16;
      v11 = calloc(1u, list_numa);
      v12 = v11;
      v13 = v11 == 0;
      v14 = (char *)v11 + 16;
      if ( !v13 )
      {
        if ( v9 > 0 )
        {
          v15 = v9;
          v16 = (char *)((char *)unit - v14);
          do
          {
            v17 = *(_DWORD *)&v14[(_DWORD)v16];
            if ( v17 )
              *(_DWORD *)v14 = *(_DWORD *)(v17 + 4);
            else
              *(_DWORD *)v14 = -1;
            v14 += 4;
            --v15;
          }
          while ( v15 );
          v8 = unit;
        }
        *v12 = 105;
        v12[1] = v9;
        if ( *v8 )
          v18 = (*v8)->owner->id;
        else
          LOBYTE(v18) = -1;
        v19 = x1;
        v12[2] = v18;
        *((_WORD *)v12 + 4) = obj_id;
        if ( x1 < 0 )
          v19 = 0;
        if ( v19 > 255 )
          LOBYTE(v19) = -1;
        v20 = y1;
        if ( y1 < 0 )
          v20 = 0;
        if ( v20 > 255 )
          LOBYTE(v20) = -1;
        v21 = x2;
        if ( x2 < 0 )
          v21 = 0;
        if ( v21 > 255 )
          LOBYTE(v21) = -1;
        v22 = y2;
        if ( y2 < 0 )
          v22 = 0;
        if ( v22 > 255 )
          LOBYTE(v22) = -1;
        v12[6] = v22;
        v12[3] = v19;
        v12[4] = v20;
        v12[5] = v21;
        *((_DWORD *)v12 + 3) = -1;
        TDebuggingLog::Log(L, aSendCmdBldWall, v10, obj_id);
        RGE_Command::submit((RGE_Command *)&v23->vfptr, v12, list_numa);
      }
    }
  }
}

//----- (0050AC70) --------------------------------------------------------
void __thiscall TRIBE_Command::command_explore(TRIBE_Command *this, int playerID, int *unitID, int numUnits, float x, float y)
{
  void *v6; // eax@3
  float *v7; // esi@3
  bool v8; // zf@3
  char *v9; // eax@3
  int v10; // edx@5
  char *v11; // ecx@5
  TRIBE_Command *v12; // [sp+10h] [bp-4h]@1

  v12 = this;
  if ( unitID )
  {
    if ( numUnits >= 1 )
    {
      v6 = calloc(1u, 4 * numUnits + 12);
      v7 = (float *)v6;
      v8 = v6 == 0;
      v9 = (char *)v6 + 12;
      if ( !v8 )
      {
        if ( numUnits > 0 )
        {
          v10 = numUnits;
          v11 = (char *)((char *)unitID - v9);
          do
          {
            *(_DWORD *)v9 = *(_DWORD *)&v9[(_DWORD)v11];
            v9 += 4;
            --v10;
          }
          while ( v10 );
        }
        *(_BYTE *)v7 = 104;
        *((_BYTE *)v7 + 1) = numUnits;
        *((_BYTE *)v7 + 2) = playerID;
        v7[1] = x;
        v7[2] = y;
        TDebuggingLog::Log(L, aSendCmdExplore, numUnits);
        RGE_Command::submit((RGE_Command *)&v12->vfptr, v7, 4 * numUnits + 12);
      }
    }
  }
}

//----- (0050AD00) --------------------------------------------------------
void __thiscall TRIBE_Command::command_allied_victory(TRIBE_Command *this, __int16 player, char flag)
{
  TRIBE_Command *v3; // edi@1
  _WORD *v4; // esi@1

  v3 = this;
  v4 = calloc(1u, 0x10u);
  if ( v4 )
  {
    v4[1] = player;
    v4[2] = (unsigned __int8)flag;
    *((_DWORD *)v4 + 2) = 0;
    *(_BYTE *)v4 = 103;
    *((_BYTE *)v4 + 1) = 5;
    TDebuggingLog::Log(L, aSendCmdAlliedV, player, (unsigned __int8)flag);
    RGE_Command::submit((RGE_Command *)&v3->vfptr, v4, 16);
  }
}

//----- (0050AD70) --------------------------------------------------------
void __thiscall TRIBE_Command::command_relation(TRIBE_Command *this, __int16 player, __int16 target_player, __int16 relation)
{
  TRIBE_Command *v4; // ebx@1
  float *v5; // esi@1

  v4 = this;
  v5 = (float *)calloc(1u, 0x10u);
  if ( v5 )
  {
    *((_WORD *)v5 + 2) = target_player;
    *((_WORD *)v5 + 6) = relation;
    v5[2] = (double)relation;
    *((_WORD *)v5 + 1) = player;
    *(_BYTE *)v5 = 103;
    *((_BYTE *)v5 + 1) = 0;
    TDebuggingLog::Log(L, aSendCmdRelatio, player, target_player, relation);
    RGE_Command::submit((RGE_Command *)&v4->vfptr, v5, 16);
  }
}

//----- (0050ADF0) --------------------------------------------------------
void __thiscall TRIBE_Command::command_game_speed(TRIBE_Command *this, float gamespeed)
{
  TRIBE_Command *v2; // edi@1
  float *v3; // esi@1

  v2 = this;
  v3 = (float *)calloc(1u, 0x10u);
  if ( v3 )
  {
    *(_BYTE *)v3 = 103;
    v3[2] = gamespeed;
    *((_BYTE *)v3 + 1) = 1;
    TDebuggingLog::Log(L, aSendCmdGameSpd);
    RGE_Command::submit((RGE_Command *)&v2->vfptr, v3, 16);
  }
}

//----- (0050AE40) --------------------------------------------------------
void __thiscall TRIBE_Command::command_save_game(TRIBE_Command *this)
{
  TRIBE_Command *v1; // edi@1
  void *v2; // eax@1
  void *v3; // esi@1

  v1 = this;
  v2 = calloc(1u, 0x10u);
  v3 = v2;
  if ( v2 )
  {
    *(_BYTE *)v2 = 103;
    *((_BYTE *)v2 + 1) = 8;
    TDebuggingLog::Log(L, aSendCmdSavegam);
    RGE_Command::submit((RGE_Command *)&v1->vfptr, v3, 16);
  }
}

//----- (0050AE80) --------------------------------------------------------
void __thiscall TRIBE_Command::command_inventory(TRIBE_Command *this, __int16 player, __int16 inventory, float amount)
{
  TRIBE_Command *v4; // edi@1
  float *v5; // esi@1

  v4 = this;
  v5 = (float *)calloc(1u, 0x10u);
  if ( v5 )
  {
    *((_WORD *)v5 + 2) = inventory;
    v5[2] = amount;
    *((_WORD *)v5 + 1) = player;
    *(_BYTE *)v5 = 103;
    *((_BYTE *)v5 + 1) = 2;
    TDebuggingLog::Log(L, aSendCmdInvPlrD, player, inventory);
    RGE_Command::submit((RGE_Command *)&v4->vfptr, v5, 16);
  }
}

//----- (0050AEE0) --------------------------------------------------------
void __thiscall TRIBE_Command::command_upgrade_town(TRIBE_Command *this, __int16 player)
{
  TRIBE_Command *v2; // edi@1
  _WORD *v3; // esi@1

  v2 = this;
  v3 = calloc(1u, 0x10u);
  if ( v3 )
  {
    *(_BYTE *)v3 = 103;
    v3[1] = player;
    *((_BYTE *)v3 + 1) = 3;
    TDebuggingLog::Log(L, aSendCmdUpgTown);
    RGE_Command::submit((RGE_Command *)&v2->vfptr, v3, 16);
  }
}

//----- (0050AF30) --------------------------------------------------------
void __thiscall TRIBE_Command::command_quick_build(TRIBE_Command *this, __int16 quick_build)
{
  TRIBE_Command *v2; // edi@1
  _WORD *v3; // esi@1

  v2 = this;
  v3 = calloc(1u, 0x10u);
  if ( v3 )
  {
    *(_BYTE *)v3 = 103;
    v3[1] = quick_build;
    *((_BYTE *)v3 + 1) = 4;
    TDebuggingLog::Log(L, aSendCmdQuickbl);
    RGE_Command::submit((RGE_Command *)&v2->vfptr, v3, 16);
  }
}

//----- (0050AF80) --------------------------------------------------------
void __thiscall TRIBE_Command::command_shared_los(TRIBE_Command *this, __int16 player)
{
  TRIBE_Command *v2; // edi@1
  _WORD *v3; // esi@1

  v2 = this;
  v3 = calloc(1u, 0x10u);
  if ( v3 )
  {
    *(_BYTE *)v3 = 103;
    v3[1] = player;
    *((_BYTE *)v3 + 1) = 7;
    TDebuggingLog::Log(L, aSendCmdSharedl);
    RGE_Command::submit((RGE_Command *)&v2->vfptr, v3, 16);
  }
}

//----- (0050AFD0) --------------------------------------------------------
void __thiscall TRIBE_Command::command_cancel_build(TRIBE_Command *this, RGE_Static_Object *unit)
{
  TRIBE_Command *v2; // edi@1
  _DWORD *v3; // esi@1

  v2 = this;
  v3 = calloc(1u, 8u);
  if ( v3 )
  {
    *(_BYTE *)v3 = 106;
    v3[1] = unit->id;
    TDebuggingLog::Log(L, aSendCmdCancelb);
    RGE_Command::submit((RGE_Command *)&v2->vfptr, v3, 8);
  }
}

//----- (0050B020) --------------------------------------------------------
void __thiscall TRIBE_Command::command_attack_ground(TRIBE_Command *this, RGE_Static_Object **unit, __int16 list_num, float x, float y)
{
  void *v5; // eax@3
  float *v6; // esi@3
  bool v7; // zf@3
  char *v8; // eax@3
  int v9; // ebp@5
  char *v10; // edx@5
  int v11; // ecx@6
  TRIBE_Command *v12; // [sp+10h] [bp-4h]@1

  v12 = this;
  if ( unit )
  {
    if ( list_num >= 1 )
    {
      v5 = calloc(1u, 4 * list_num + 12);
      v6 = (float *)v5;
      v7 = v5 == 0;
      v8 = (char *)v5 + 12;
      if ( !v7 )
      {
        if ( list_num > 0 )
        {
          v9 = list_num;
          v10 = (char *)((char *)unit - v8);
          do
          {
            v11 = *(_DWORD *)&v8[(_DWORD)v10];
            if ( v11 )
              *(_DWORD *)v8 = *(_DWORD *)(v11 + 4);
            else
              *(_DWORD *)v8 = -1;
            v8 += 4;
            --v9;
          }
          while ( v9 );
        }
        *(_BYTE *)v6 = 107;
        *((_BYTE *)v6 + 1) = list_num;
        v6[1] = x;
        v6[2] = y;
        TDebuggingLog::Log(L, aSendCmdAttackG, list_num);
        RGE_Command::submit((RGE_Command *)&v12->vfptr, v6, 4 * list_num + 12);
      }
    }
  }
}

//----- (0050B0D0) --------------------------------------------------------
void __thiscall TRIBE_Command::command_cheat(TRIBE_Command *this, __int16 player, __int16 cheat_code)
{
  TRIBE_Command *v3; // edi@1
  _WORD *v4; // esi@1

  v3 = this;
  v4 = calloc(1u, 0x10u);
  if ( v4 )
  {
    *(_BYTE *)v4 = 103;
    v4[1] = player;
    v4[2] = cheat_code;
    *((_BYTE *)v4 + 1) = 6;
    TDebuggingLog::Log(L, aSendCmdCheatD, cheat_code);
    RGE_Command::submit((RGE_Command *)&v3->vfptr, v4, 16);
  }
}

//----- (0050B130) --------------------------------------------------------
void __thiscall TRIBE_Command::command_give_attribute(TRIBE_Command *this, int player_id, int to_player_id, int attr_id, float attr_amount, float attr_cost)
{
  TRIBE_Command *v6; // edi@1
  float *v7; // esi@1

  v6 = this;
  v7 = (float *)calloc(1u, 0xCu);
  *((_BYTE *)v7 + 3) = attr_id;
  v7[1] = attr_amount;
  *(_BYTE *)v7 = 108;
  *((_BYTE *)v7 + 1) = player_id;
  *((_BYTE *)v7 + 2) = to_player_id;
  v7[2] = attr_cost;
  TDebuggingLog::Log(L, aSendCmdGiveAtt, player_id, to_player_id);
  RGE_Command::submit((RGE_Command *)&v6->vfptr, v7, 12);
}

//----- (0050B190) --------------------------------------------------------
void __thiscall TRIBE_Command::command_trade_attribute(TRIBE_Command *this, RGE_Static_Object **unit, __int16 list_num, int attribute)
{
  void *v4; // eax@3
  _BYTE *v5; // esi@3
  bool v6; // zf@3
  char *v7; // eax@3
  int v8; // ebp@5
  char *v9; // edx@5
  int v10; // ecx@6
  TRIBE_Command *v11; // [sp+10h] [bp-4h]@1

  v11 = this;
  if ( unit )
  {
    if ( list_num >= 1 )
    {
      v4 = calloc(1u, 4 * list_num + 8);
      v5 = v4;
      v6 = v4 == 0;
      v7 = (char *)v4 + 8;
      if ( !v6 )
      {
        if ( list_num > 0 )
        {
          v8 = list_num;
          v9 = (char *)((char *)unit - v7);
          do
          {
            v10 = *(_DWORD *)&v7[(_DWORD)v9];
            if ( v10 )
              *(_DWORD *)v7 = *(_DWORD *)(v10 + 4);
            else
              *(_DWORD *)v7 = -1;
            v7 += 4;
            --v8;
          }
          while ( v8 );
        }
        *v5 = 109;
        v5[1] = list_num;
        *((_DWORD *)v5 + 1) = attribute;
        TDebuggingLog::Log(L, aSendCmdTradeAt, list_num);
        RGE_Command::submit((RGE_Command *)&v11->vfptr, v5, 4 * list_num + 8);
      }
    }
  }
}

//----- (0050B230) --------------------------------------------------------
void __thiscall TRIBE_Command::command_trade_attribute(TRIBE_Command *this, int unitID, int playerID, int attribute)
{
  TRIBE_Command *v4; // edi@1
  void *v5; // eax@1
  _BYTE *v6; // esi@1
  bool v7; // zf@1
  int *v8; // eax@1

  v4 = this;
  v5 = calloc(1u, 0xCu);
  v6 = v5;
  v7 = v5 == 0;
  v8 = (int *)((char *)v5 + 8);
  if ( !v7 )
  {
    if ( v8 )
    {
      *v8 = unitID;
      *v6 = 109;
      v6[1] = 1;
      *((_DWORD *)v6 + 1) = attribute;
      TDebuggingLog::Log(L, aSendCmdTrade_1);
      RGE_Command::submit((RGE_Command *)&v4->vfptr, v6, 12);
    }
  }
}

//----- (0050B290) --------------------------------------------------------
void __thiscall TRIBE_Command::command_repair(TRIBE_Command *this, RGE_Static_Object **unit, __int16 unit_count, RGE_Static_Object *target)
{
  void *v4; // eax@3
  _DWORD *v5; // esi@3
  bool v6; // zf@3
  char *v7; // eax@3
  int v8; // edi@5
  char *v9; // edx@5
  int v10; // ecx@6
  int v11; // eax@10
  TRIBE_Command *v12; // [sp+10h] [bp-4h]@1

  v12 = this;
  if ( unit )
  {
    if ( unit_count >= 1 )
    {
      v4 = calloc(1u, 4 * unit_count + 8);
      v5 = v4;
      v6 = v4 == 0;
      v7 = (char *)v4 + 8;
      if ( !v6 )
      {
        if ( unit_count > 0 )
        {
          v8 = unit_count;
          v9 = (char *)((char *)unit - v7);
          do
          {
            v10 = *(_DWORD *)&v7[(_DWORD)v9];
            if ( v10 )
              *(_DWORD *)v7 = *(_DWORD *)(v10 + 4);
            else
              *(_DWORD *)v7 = -1;
            v7 += 4;
            --v8;
          }
          while ( v8 );
        }
        v11 = target->id;
        *(_BYTE *)v5 = 110;
        v5[1] = v11;
        *((_BYTE *)v5 + 1) = unit_count;
        TDebuggingLog::Log(L, aSendCmdRepairC, unit_count);
        RGE_Command::submit((RGE_Command *)&v12->vfptr, v5, 4 * unit_count + 8);
      }
    }
  }
}

//----- (0050B330) --------------------------------------------------------
void __thiscall TRIBE_Command::command_unload(TRIBE_Command *this, RGE_Static_Object **unit, __int16 list_num, float x, float y)
{
  void *v5; // eax@3
  float *v6; // esi@3
  bool v7; // zf@3
  char *v8; // eax@3
  int v9; // ebp@5
  char *v10; // edx@5
  int v11; // ecx@6
  TRIBE_Command *v12; // [sp+10h] [bp-4h]@1

  v12 = this;
  if ( unit )
  {
    if ( list_num >= 1 )
    {
      v5 = calloc(1u, 4 * list_num + 12);
      v6 = (float *)v5;
      v7 = v5 == 0;
      v8 = (char *)v5 + 12;
      if ( !v7 )
      {
        if ( list_num > 0 )
        {
          v9 = list_num;
          v10 = (char *)((char *)unit - v8);
          do
          {
            v11 = *(_DWORD *)&v8[(_DWORD)v10];
            if ( v11 )
              *(_DWORD *)v8 = *(_DWORD *)(v11 + 4);
            else
              *(_DWORD *)v8 = -1;
            v8 += 4;
            --v9;
          }
          while ( v9 );
        }
        *(_BYTE *)v6 = 111;
        *((_BYTE *)v6 + 1) = list_num;
        v6[1] = x;
        v6[2] = y;
        TDebuggingLog::Log(L, aSendCmdUnloadC, list_num);
        RGE_Command::submit((RGE_Command *)&v12->vfptr, v6, 4 * list_num + 12);
      }
    }
  }
}

//----- (0050B3E0) --------------------------------------------------------
void __thiscall TRIBE_Command::command_queue(TRIBE_Command *this, RGE_Static_Object *bldg_obj, __int16 train_id, __int16 train_count)
{
  TRIBE_Command *v4; // edi@1
  _WORD *v5; // esi@1
  int v6; // ecx@2

  v4 = this;
  v5 = calloc(1u, 0xCu);
  if ( v5 )
  {
    *(_BYTE *)v5 = 119;
    v6 = bldg_obj->id;
    v5[5] = train_count;
    *((_DWORD *)v5 + 1) = v6;
    v5[4] = train_id;
    TDebuggingLog::Log(L, aSendCmdQueueBD, bldg_obj->id, train_id, train_count);
    RGE_Command::submit((RGE_Command *)&v4->vfptr, v5, 12);
  }
}
