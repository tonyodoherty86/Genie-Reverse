
/**
 * @file    Engine\RGE\Action.cpp
 * @author  Yvan Burrie
 * @date    2018/06/26
 * @version 1.0
 */

//----- (00404BB0) --------------------------------------------------------
void __userpurge RGE_Action_Missile::RGE_Action_Missile(RGE_Action_Missile *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  int v4; // edi@1
  RGE_Action_Missile *v5; // esi@1

  v4 = infile;
  v5 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v5->vfptr = (RGE_ActionVtbl *)&RGE_Action_Missile::`vftable';
  v5->action_type = 8;
  rge_read(a2, v4, v4, &v5->velocity_x, 4);
  rge_read(a2, v4, v4, &v5->velocity_y, 4);
  rge_read(a2, v4, v4, &v5->velocity_z, 4);
  rge_read(a2, v4, v4, &v5->ballistic_velocity, 4);
  rge_read(a2, v4, v4, &v5->ballistic_acceleration, 4);
}
// 56E320: using guessed type int (__thiscall *RGE_Action_Missile::`vftable')(void *Memory, unsigned int __flags);

//----- (00404C60) --------------------------------------------------------
RGE_Action_Missile *__thiscall RGE_Action_Missile::`scalar deleting destructor'(RGE_Action_Missile *this, unsigned int __flags)
{
  RGE_Action_Missile *v2; // esi@1

  v2 = this;
  RGE_Action_Missile::~RGE_Action_Missile(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00404C90) --------------------------------------------------------
void __thiscall RGE_Action_Missile::RGE_Action_Missile(RGE_Action_Missile *this, RGE_Action_Object *obj_in, RGE_Static_Object *launcher, RGE_Static_Object *target, float x, float y, float z)
{
  RGE_Action_Missile *v7; // esi@1

  v7 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v7->target_x = x;
  v7->vfptr = (RGE_ActionVtbl *)&RGE_Action_Missile::`vftable';
  v7->action_type = 8;
  v7->target_y = y;
  v7->target_z = z;
  RGE_Action::set_target_obj((RGE_Action *)&v7->vfptr, target);
  RGE_Action::set_target_obj2((RGE_Action *)&v7->vfptr, launcher);
}
// 56E320: using guessed type int (__thiscall *RGE_Action_Missile::`vftable')(void *Memory, unsigned int __flags);

//----- (00404D10) --------------------------------------------------------
void __thiscall RGE_Action_Missile::first_in_stack(RGE_Action_Missile *this, char first_time)
{
  if ( first_time )
  {
    if ( this->target_obj || LODWORD(this->target_x) != -1082130432 && LODWORD(this->target_y) != -1082130432 )
      ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(3);
    else
      ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(1);
  }
  else
  {
    ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(4);
  }
}

//----- (00404D50) --------------------------------------------------------
void __thiscall RGE_Action_Missile::intercept(RGE_Action_Missile *this, float *tx, float *ty, float *tz)
{
  RGE_Static_Object *v4; // eax@1

  v4 = this->target_obj;
  if ( v4 )
  {
    *tx = v4->world_x;
    *ty = this->target_obj->world_y;
    *tz = this->target_obj->master_obj->radius_z * 0.5 + this->target_obj->world_z;
  }
  else
  {
    *tx = this->target_x;
    *ty = this->target_y;
    *tz = this->target_z;
  }
}

//----- (00404DB0) --------------------------------------------------------
void __thiscall RGE_Action_Missile::set_state(RGE_Action_Missile *this, char new_state)
{
  RGE_Action_Missile *v2; // esi@1
  RGE_Action_Object *v3; // eax@3
  double v4; // st7@3
  double v5; // st5@3
  double v6; // st6@3
  long double v7; // st7@3
  RGE_Static_Object *v8; // ecx@4
  RGE_Static_Object *v9; // eax@6
  __int16 v10; // ax@7
  long double v11; // st7@12
  RGE_Master_Static_Object *v12; // eax@12
  long double v13; // st6@12
  long double v14; // rt0@12
  double v15; // st6@12
  float v16; // ST18_4@12
  double v17; // rt1@12
  float v18; // ST18_4@12
  long double v19; // st6@12
  float v20; // ST18_4@13
  double v21; // st7@13
  double v22; // st6@13
  double v23; // rt0@13
  double v24; // st6@13
  RGE_Action_Object *v25; // ecx@14
  long double v26; // st7@15
  RGE_Static_ObjectVtbl *v27; // eax@15
  long double v28; // st6@15
  float v29; // ST08_4@15
  RGE_Static_ObjectVtbl *v30; // eax@18
  float v31; // ST08_4@18
  RGE_Master_Static_Object *v32; // ecx@19
  double v33; // st7@21
  double v34; // rt1@23
  double v35; // st5@23
  RGE_ActionVtbl *v36; // edx@23
  RGE_ActionVtbl *v37; // edx@24
  float v38; // [sp+8h] [bp-28h]@3
  float d; // [sp+Ch] [bp-24h]@3
  float speed; // [sp+10h] [bp-20h]@6
  float dz; // [sp+14h] [bp-1Ch]@3
  float v42; // [sp+18h] [bp-18h]@3
  float target_vx; // [sp+1Ch] [bp-14h]@12
  float target_vy; // [sp+20h] [bp-10h]@12
  float tx; // [sp+24h] [bp-Ch]@3
  float ty; // [sp+28h] [bp-8h]@3
  float tz; // [sp+2Ch] [bp-4h]@3
  float new_statea; // [sp+34h] [bp+4h]@3
  float new_stateb; // [sp+34h] [bp+4h]@23

  v2 = this;
  this->state = new_state;
  if ( new_state == 1 )
  {
    ((void (*)(void))this->obj->vfptr->die_die_die)();
  }
  else if ( new_state == 3 )
  {
    RGE_Action_Missile::intercept(this, &tx, &ty, &tz);
    v3 = v2->obj;
    v4 = ty - v3->world_y;
    v5 = tx - v3->world_x;
    v6 = tz - v3->world_z;
    v38 = v5;
    new_statea = v4;
    dz = v6;
    v42 = v6 * dz;
    v7 = sqrt(v5 * v38 + v4 * new_statea + v42);
    d = v7;
    if ( v3->master_obj[1].attack_reaction == 1 )
    {
      v8 = v2->target_obj;
      if ( v8 )
      {
        ((void (*)(void))v8->vfptr->getSpeed)();
        if ( v7 > 0.0 )
        {
          ((void (*)(void))v2->target_obj->vfptr->getSpeed)();
          v9 = v2->target_obj2;
          speed = v7;
          if ( v9 )
          {
            v10 = v9->master_obj->id;
            if ( v10 == 35 || v10 == 36 || v10 == 280 )
            {
              v7 = speed;
              if ( speed > 1.0 )
                speed = 1.0;
            }
          }
          ((void (*)(void))v2->target_obj->vfptr->getAngle)();
          v11 = cos(v7) * speed;
          target_vx = v11;
          ((void (*)(void))v2->target_obj->vfptr->getAngle)();
          v12 = v2->obj->master_obj;
          v13 = sin(v11) * speed;
          target_vy = v13;
          v14 = v13 + new_statea;
          v15 = target_vx + v38;
          v16 = v15;
          v17 = v15 * v16;
          v18 = v14;
          v19 = d - sqrt(v17 + v14 * v18 + v42) + *(float *)&v12[1].vfptr;
          if ( v19 > *(float *)&v12[1].vfptr * 0.5 )
          {
            v20 = v19;
            v21 = d / v20;
            v22 = v21 * target_vx + v38;
            v38 = v22;
            v23 = v22;
            v24 = v21 * target_vy + new_statea;
            new_statea = v24;
            d = sqrt(v23 * v38 + v24 * new_statea + v42);
          }
        }
      }
    }
    v25 = v2->obj;
    switch ( v25->master_obj[1].map_color )
    {
      case 0:
        v26 = v38 / d;
        v27 = v25->vfptr;
        v2->velocity_x = v26;
        v28 = new_statea / d;
        v2->velocity_y = v28;
        v2->velocity_z = dz / d;
        v29 = atan2(v26, v28);
        ((void (__stdcall *)(_DWORD))v27->new_angle)(LODWORD(v29));
        LODWORD(v2->timer) = 0;
        break;
      case 1:
        v2->vfptr->set_state((RGE_Action *)v2, 4);
        break;
      case 2:
        v2->vfptr->set_state((RGE_Action *)v2, 4);
        break;
      case 3:
        v2->velocity_x = v38;
        v2->velocity_y = new_statea;
        v30 = v25->vfptr;
        v2->velocity_z = dz;
        v31 = atan2(v38, new_statea);
        ((void (__stdcall *)(_DWORD))v30->new_angle)(LODWORD(v31));
        break;
      default:
        break;
    }
    v32 = v2->obj->master_obj;
    if ( *(float *)&v32[1].help_string_id <= 0.0 )
    {
      v37 = v2->vfptr;
      LODWORD(v2->ballistic_velocity) = 0;
      LODWORD(v2->ballistic_acceleration) = 0;
      v37->set_state((RGE_Action *)v2, 4);
    }
    else
    {
      if ( *(float *)&v32[1].vfptr <= 0.0 )
        v33 = 0.0;
      else
        v33 = d / *(float *)&v32[1].vfptr;
      v34 = v33 * 0.5;
      v35 = -(d * *(float *)&v32[1].help_string_id);
      v36 = v2->vfptr;
      new_stateb = (v35 + v35) / (v34 * v34);
      v2->ballistic_acceleration = new_stateb;
      v2->ballistic_velocity = -(v34 * new_stateb);
      v36->set_state((RGE_Action *)v2, 4);
    }
  }
}

//----- (004050F0) --------------------------------------------------------
char __thiscall RGE_Action_Missile::update(RGE_Action_Missile *this)
{
  RGE_Action_Missile *v1; // esi@1
  RGE_Action_Object *v2; // eax@1
  int v3; // edx@1
  RGE_Game_World *v4; // ecx@1
  RGE_Static_Object *v5; // ecx@7
  RGE_Static_Object *v6; // ecx@10
  RGE_Action_Object *v7; // eax@15
  char v8; // cl@15
  double v9; // st6@18
  double v10; // st5@18
  double v11; // st4@18
  double v12; // st3@18
  float v13; // et1@18
  char v15; // c0@18
  RGE_Moving_Object *v16; // ecx@20
  double v17; // st7@21
  double v18; // rt0@21
  double v19; // st6@21
  char v20; // al@22
  RGE_Missile_Object *v21; // ecx@22
  char v22; // al@22
  RGE_Static_Object *v23; // eax@24
  RGE_Check_List *v24; // eax@27
  RGE_Check_List *v25; // edi@27
  RGE_Check_Node *v26; // ebp@28
  RGE_Action_Object *v27; // eax@29
  RGE_Static_Object *v28; // ecx@32
  RGE_Static_Object *v29; // edx@32
  RGE_Player *v30; // edi@34
  RGE_Player *v31; // ecx@37
  RGE_Player *v32; // ecx@40
  RGE_Static_Object *v33; // ecx@42
  RGE_Static_ObjectVtbl **v34; // ecx@54
  RGE_Action_Object *v35; // eax@55
  RGE_Static_ObjectVtbl *v36; // edx@55
  float v37; // edi@55
  float v38; // eax@55
  float v40; // [sp+Ah] [bp-38h]@55
  float v41; // [sp+Eh] [bp-34h]@55
  RGE_Static_ObjectVtbl **v42; // [sp+12h] [bp-30h]@55
  char hit_ground; // [sp+2Dh] [bp-15h]@22
  float vz; // [sp+2Eh] [bp-14h]@1
  float s; // [sp+32h] [bp-10h]@1
  float t; // [sp+36h] [bp-Ch]@1
  float vy; // [sp+3Ah] [bp-8h]@1
  RGE_Check_List *bounds; // [sp+3Eh] [bp-4h]@1
  RGE_Check_List *boundsa; // [sp+3Eh] [bp-4h]@27

  v1 = this;
  *(float *)&bounds = 0.0;
  v2 = this->obj;
  v3 = this->targetID;
  vy = 0.0;
  vz = 0.0;
  v4 = v2->owner->world;
  t = v4->world_time_delta_seconds;
  s = *(float *)&v2->master_obj[1].vfptr * t;
  if ( v3 != -1 && !RGE_Game_World::object(v4, v3) )
    v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
  if ( v1->target2ID != -1 && !RGE_Game_World::object(v1->obj->owner->world, v1->target2ID) )
    v1->vfptr->set_target_obj2((RGE_Action *)v1, 0);
  v5 = v1->target_obj;
  if ( v5 && RGE_Static_Object::is_dying(v5) )
    v1->vfptr->set_target_obj((RGE_Action *)v1, 0);
  v6 = v1->target_obj2;
  if ( v6 && RGE_Static_Object::is_dying(v6) )
    v1->vfptr->set_target_obj2((RGE_Action *)v1, 0);
  if ( v1->state == 1 )
    return 1;
  if ( v1->state != 4 )
    return 0;
  v7 = v1->obj;
  v8 = v7->master_obj[1].map_color;
  if ( v8 )
  {
    if ( v8 == 3 )
    {
      bounds = (RGE_Check_List *)LODWORD(v1->velocity_x);
      vy = v1->velocity_y;
      vz = v1->velocity_z;
    }
  }
  else
  {
    v9 = v1->velocity_x;
    v10 = v1->velocity_y;
    v11 = v1->velocity_z;
    v12 = s + v1->timer;
    v1->timer = *(float *)&v12;
    v13 = v7[1].hp;
    *(float *)&bounds = v9 * s;
    vy = v10 * s;
    vz = v11 * s;
    if ( !v15 )
      v1->vfptr->set_state((RGE_Action *)v1, 1);
  }
  v16 = (RGE_Moving_Object *)&v1->obj->vfptr;
  if ( *(float *)&v16->master_obj[1].help_string_id > 0.0 )
  {
    v17 = v1->ballistic_acceleration * t;
    v18 = v17 * 0.5 + v1->ballistic_velocity;
    v19 = v17 + v1->ballistic_velocity;
    v1->ballistic_velocity = *(float *)&v19;
    vz = v18 * t + vz;
  }
  RGE_Moving_Object::set_velocity(v16, *(float *)&bounds, vy, vz);
  v20 = RGE_Missile_Object::missile_move((RGE_Missile_Object *)v1->obj);
  v21 = (RGE_Missile_Object *)v1->obj;
  hit_ground = v20;
  v22 = v21->master_obj[1].map_color;
  if ( (unsigned __int8)v22 > 2u )
  {
    if ( v22 == 3 )
    {
      v23 = v1->target_obj2;
      if ( v23 )
      {
        ((void (__thiscall *)(RGE_Static_Object *, RGE_Static_Object *, RGE_Static_Object *, _DWORD, _DWORD, _DWORD))v23->vfptr[1].remove_overlay_sprite)(
          v23,
          v1->target_obj,
          v23,
          LODWORD(v21->world_x),
          LODWORD(v21->world_y),
          LODWORD(v21->world_z));
        v1->vfptr->set_state((RGE_Action *)v1, 1);
      }
      else
      {
        ((void (__stdcall *)(RGE_Static_Object *, RGE_Missile_Object *, _DWORD, _DWORD, _DWORD))v21->vfptr[1].remove_overlay_sprite)(
          v1->target_obj,
          v21,
          LODWORD(v21->world_x),
          LODWORD(v21->world_y),
          LODWORD(v21->world_z));
        v1->vfptr->set_state((RGE_Action *)v1, 1);
      }
    }
    goto LABEL_52;
  }
  v24 = RGE_Missile_Object::make_object_collision_list(v21, s);
  v25 = v24;
  boundsa = v24;
  if ( !v24 )
    goto LABEL_52;
  v26 = v24->list;
  if ( !v24->list )
    goto LABEL_51;
  do
  {
    v27 = v1->obj;
    if ( !v27->master_obj[1].convert_terrain_flag )
    {
      v29 = v1->target_obj;
      if ( v26->node != v29 )
        goto LABEL_49;
      v28 = v1->target_obj2;
      if ( !v28 )
        goto LABEL_47;
      goto LABEL_46;
    }
    if ( v27->master_obj[1].convert_terrain_flag != 1 )
    {
      if ( v27->master_obj[1].convert_terrain_flag != 2 )
        goto LABEL_49;
      v28 = v1->target_obj2;
      v29 = v26->node;
      if ( !v28 )
      {
        v31 = v29->owner;
        if ( v31 != v27->owner && v31->id )
          goto LABEL_47;
        (*(void (__thiscall **)(RGE_Action_Object *, _DWORD, _DWORD, _DWORD, RGE_Action_Object *, _DWORD))&v27->vfptr[1].gap4[48])(
          v27,
          LODWORD(v27->world_x),
          LODWORD(v27->world_y),
          LODWORD(v27->world_z),
          v27,
          0);
LABEL_48:
        v1->vfptr->set_state((RGE_Action *)v1, 1);
        goto LABEL_49;
      }
      if ( v29 == v28 )
        goto LABEL_49;
      v30 = v29->owner;
      if ( v30 == v27->owner || !v30->id )
      {
        (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, RGE_Static_Object *, _DWORD))&v28->vfptr[1].gap4[48])(
          LODWORD(v27->world_x),
          LODWORD(v27->world_y),
          LODWORD(v27->world_z),
          v28,
          0);
        goto LABEL_48;
      }
LABEL_46:
      ((void (__thiscall *)(RGE_Action_Object *, RGE_Static_Object *, RGE_Action_Object *, _DWORD, _DWORD, _DWORD))v28->vfptr[1].remove_overlay_sprite)(
        (RGE_Action_Object *)v28,
        v29,
        (RGE_Action_Object *)v28,
        LODWORD(v27->world_x),
        LODWORD(v27->world_y),
        LODWORD(v27->world_z));
      goto LABEL_48;
    }
    v29 = v26->node;
    v32 = v26->node->owner;
    if ( v32 != v27->owner && v32->id )
    {
      v33 = v1->target_obj2;
      if ( v33 )
      {
        ((void (__thiscall *)(RGE_Action_Object *, RGE_Static_Object *, RGE_Action_Object *, _DWORD, _DWORD, _DWORD))v33->vfptr[1].remove_overlay_sprite)(
          (RGE_Action_Object *)v33,
          v29,
          (RGE_Action_Object *)v33,
          LODWORD(v27->world_x),
          LODWORD(v27->world_y),
          LODWORD(v27->world_z));
        goto LABEL_48;
      }
LABEL_47:
      ((void (__thiscall *)(RGE_Action_Object *, RGE_Static_Object *, RGE_Action_Object *, _DWORD, _DWORD, _DWORD))v27->vfptr[1].remove_overlay_sprite)(
        v27,
        v29,
        v27,
        LODWORD(v27->world_x),
        LODWORD(v27->world_y),
        LODWORD(v27->world_z));
      goto LABEL_48;
    }
LABEL_49:
    v26 = v26->next;
  }
  while ( v26 );
  v25 = boundsa;
LABEL_51:
  RGE_Check_List::~RGE_Check_List(v25);
  operator delete(v25);
LABEL_52:
  if ( hit_ground && v1->state != 1 )
  {
    v34 = &v1->target_obj2->vfptr;
    if ( v34 )
    {
      v35 = v1->obj;
      v36 = *v34;
      v42 = &v1->target_obj2->vfptr;
      v41 = v35->world_z;
      v37 = v35->world_y;
      v38 = v35->world_x;
      v40 = v37;
    }
    else
    {
      v42 = &v1->obj->vfptr;
      v36 = *v42;
      v41 = *((float *)v42 + 16);
      v40 = *((float *)v42 + 15);
      v38 = *((float *)v42 + 14);
    }
    (*(void (__stdcall **)(float, float, float, void *, _DWORD))&v36[1].gap4[48])(
      COERCE_FLOAT(LODWORD(v38)),
      COERCE_FLOAT(LODWORD(v40)),
      COERCE_FLOAT(LODWORD(v41)),
      v42,
      0);
    v1->vfptr->set_state((RGE_Action *)v1, 1);
  }
  return 0;
}

//----- (004054B0) --------------------------------------------------------
void __thiscall RGE_Action_Missile::save(RGE_Action_Missile *this, int outfile)
{
  RGE_Action_Missile *v2; // esi@1

  v2 = this;
  RGE_Action::save((RGE_Action *)&this->vfptr, outfile);
  rge_write(outfile, &v2->velocity_x, 4);
  rge_write(outfile, &v2->velocity_y, 4);
  rge_write(outfile, &v2->velocity_z, 4);
  rge_write(outfile, &v2->ballistic_velocity, 4);
  rge_write(outfile, &v2->ballistic_acceleration, 4);
}
