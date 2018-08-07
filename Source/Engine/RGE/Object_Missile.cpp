
//----- (0045A740) --------------------------------------------------------
void __thiscall RGE_Missile_Object::RGE_Missile_Object(RGE_Missile_Object *this, RGE_Master_Combat_Object *tobj, RGE_Player *obj_owner, float x, float y, float z, int do_setup)
{
  RGE_Missile_Object *v7; // esi@1

  v7 = this;
  RGE_Combat_Object::RGE_Combat_Object((RGE_Combat_Object *)&this->vfptr, tobj, obj_owner, x, y, z, 0);
  v7->vfptr = (RGE_Static_ObjectVtbl *)&RGE_Missile_Object::`vftable';
  if( do_setup )
    RGE_Missile_Object::setup(v7, tobj, obj_owner, x, y, z);
  v7->type = 60;
}
// 5706F0: using guessed type int (__thiscall *RGE_Missile_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0045A7D0) --------------------------------------------------------
RGE_Missile_Object *__thiscall RGE_Missile_Object::`scalar deleting destructor'(RGE_Missile_Object *this, unsigned int __flags)
{
  RGE_Missile_Object *v2; // esi@1

  v2 = this;
  RGE_Missile_Object::~RGE_Missile_Object(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0045A800) --------------------------------------------------------
void __userpurge RGE_Missile_Object::RGE_Missile_Object(RGE_Missile_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld, int do_setup)
{
  RGE_Missile_Object *v5; // esi@1

  v5 = this;
  RGE_Combat_Object::RGE_Combat_Object((RGE_Combat_Object *)&this->vfptr, a2, infile, gworld, 0);
  v5->vfptr = (RGE_Static_ObjectVtbl *)&RGE_Missile_Object::`vftable';
  if( do_setup )
    RGE_Missile_Object::setup(v5, a2, infile, gworld);
  v5->type = 60;
}
// 5706F0: using guessed type int (__thiscall *RGE_Missile_Object::`vftable')(void *Memory, unsigned int __flags);

//----- (0045A870) --------------------------------------------------------
int __thiscall RGE_Missile_Object::setup(RGE_Missile_Object *this, RGE_Master_Combat_Object *tobj, RGE_Player *obj_owner, float x, float y, float z)
{
  RGE_Missile_Object *v6; // esi@1

  v6 = this;
  RGE_Combat_Object::setup((RGE_Combat_Object *)&this->vfptr, tobj, obj_owner, x, y, z);
  v6->type = 60;
  return 1;
}

//----- (0045A8A0) --------------------------------------------------------
int __userpurge RGE_Missile_Object::setup@<eax>(RGE_Missile_Object *this@<ecx>, int a2@<ebp>, int infile, RGE_Game_World *gworld)
{
  RGE_Missile_Object *v4; // esi@1
  int result; // eax@2

  v4 = this;
  RGE_Combat_Object::setup((RGE_Combat_Object *)&this->vfptr, a2, infile, gworld);
  v4->type = 60;
  if( save_game_version <= 7.0900002 )
  {
    result = 1;
    v4->max_range = v4->master_obj[1].construction_radius_x;
  }
  else
  {
    rge_read(a2, infile, infile, &v4->max_range, 4);
    result = 1;
  }
  return result;
}
// 58EBCC: using guessed type float save_game_version;

//----- (0045A910) --------------------------------------------------------
void __thiscall RGE_Missile_Object::save(RGE_Missile_Object *this, int outfile)
{
  RGE_Missile_Object *v2; // esi@1

  v2 = this;
  RGE_Combat_Object::save((RGE_Combat_Object *)&this->vfptr, outfile);
  rge_write(outfile, &v2->max_range, 4);
}

//----- (0045A950) --------------------------------------------------------
void __thiscall RGE_Missile_Object::init_missile(RGE_Missile_Object *this, RGE_Combat_Object *launcher, RGE_Static_Object *target, float in_range)
{
  RGE_Missile_Object *v4; // esi@1
  RGE_Action_Missile *v5; // eax@1
  RGE_Action *v6; // eax@2

  v4 = this;
  v5 = (RGE_Action_Missile *)operator new(0x54u);
  if( v5 )
    RGE_Action_Missile::RGE_Action_Missile(
      v5,
      (RGE_Action_Object *)&v4->vfptr,
      (RGE_Static_Object *)&launcher->vfptr,
      target,
      target->world_x,
      target->world_y,
      target->world_z);
  else
    v6 = 0;
  if( v6 )
    RGE_Action_List::add_action(v4->actions, v6);
  v4->max_range = in_range;
}

//----- (0045A9E0) --------------------------------------------------------
void __thiscall RGE_Missile_Object::init_missile(RGE_Missile_Object *this, RGE_Combat_Object *launcher, float x, float y, float z, float in_range)
{
  RGE_Missile_Object *v6; // esi@1
  RGE_Action_Missile *v7; // eax@1
  RGE_Action *v8; // eax@2

  v6 = this;
  v7 = (RGE_Action_Missile *)operator new(0x54u);
  if( v7 )
    RGE_Action_Missile::RGE_Action_Missile(
      v7,
      (RGE_Action_Object *)&v6->vfptr,
      (RGE_Static_Object *)&launcher->vfptr,
      0,
      x,
      y,
      z);
  else
    v8 = 0;
  if( v8 )
    RGE_Action_List::add_action(v6->actions, v8);
  v6->max_range = in_range;
}

//----- (0045AA70) --------------------------------------------------------
BOOL __thiscall RGE_Missile_Object::missile_move(RGE_Missile_Object *this)
{
  RGE_Missile_Object *v1; // esi@1
  double v2; // st7@1
  char v4; // c0@1
  RGE_Map *v5; // ecx@2
  float new_y; // [sp+4h] [bp-Ch]@1
  float new_x; // [sp+8h] [bp-8h]@1
  float new_z; // [sp+Ch] [bp-4h]@1

  v1 = this;
  new_x = this->world_x + this->velocity_x;
  v2 = this->velocity_z + this->world_z;
  new_y = this->world_y + this->velocity_y;
  new_z = v2;
  if( v4
    || (v5 = this->owner->world->map, v2 = (double)v5->map_width, v2 <= new_x)
    || (v2 = new_y, new_y < 0.0)
    || (v2 = (double)v5->map_height, v2 <= new_y) )
  {
    v1->vfptr->die_die_die((RGE_Static_Object *)v1);
  }
  (*(void (__thiscall **)(RGE_Missile_Object *, float, float, float))&v1->vfptr->gap4[48])(
    v1,
    COERCE_FLOAT(LODWORD(new_x)),
    COERCE_FLOAT(LODWORD(new_y)),
    COERCE_FLOAT(LODWORD(new_z)));
  return v2 == v1->world_z;
}

//----- (0045AB20) --------------------------------------------------------
RGE_Check_List *__thiscall RGE_Missile_Object::make_object_collision_list(RGE_Missile_Object *this, float delta)
{
  RGE_Missile_Object *v2; // edi@1
  RGE_Master_Static_Object *v3; // eax@1
  signed __int16 v4; // bp@3
  __int16 v5; // bx@3
  __int16 v6; // si@3
  RGE_Check_List *v7; // eax@3
  signed __int16 v8; // cx@3
  RGE_Check_List *v9; // eax@4
  RGE_Check_List *v10; // edx@6
  RGE_Map *v11; // ecx@8
  int v12; // edx@15
  RGE_Object_Node **v13; // ebp@17
  int v14; // ebx@17
  RGE_Object_Node *i; // esi@18
  RGE_Static_Object *v16; // ecx@19
  RGE_Master_Static_Object *v17; // edx@20
  double v18; // st7@22
  double v19; // st7@24
  double v20; // st6@24
  float v21; // ST54_4@30
  unsigned __int8 v23; // c0@28
  unsigned __int8 v24; // c3@28
  bool v25; // zf@34
  RGE_Check_List *result; // eax@40
  RGE_Check_List *v27; // [sp+10h] [bp-48h]@4
  int x2; // [sp+14h] [bp-44h]@3
  int x1; // [sp+18h] [bp-40h]@3
  int v30; // [sp+1Ch] [bp-3Ch]@15
  float rx2; // [sp+20h] [bp-38h]@20
  float ry2; // [sp+24h] [bp-34h]@20
  float ry; // [sp+28h] [bp-30h]@1
  float dy; // [sp+2Ch] [bp-2Ch]@28
  RGE_Map *map; // [sp+30h] [bp-28h]@3
  int v36; // [sp+34h] [bp-24h]@15
  RGE_Check_List *check_list; // [sp+38h] [bp-20h]@6
  int v38; // [sp+3Ch] [bp-1Ch]@15
  float rx; // [sp+40h] [bp-18h]@1
  int v40; // [sp+48h] [bp-10h]@15

  v2 = this;
  v3 = this->master_obj;
  rx = v3->radius_x;
  ry = v3->radius_y;
  if( rx <= 0.0 || ry <= 0.0 )
  {
    result = 0;
  }
  else
  {
    v4 = (signed __int64)(this->world_x - 3.0);
    x1 = (signed __int64)(this->world_x - 3.0);
    v5 = (signed __int64)(this->world_y - 3.0);
    x2 = (signed __int64)(this->world_x - -3.0);
    v6 = (signed __int64)(this->world_y - -3.0);
    map = this->owner->world->map;
    v7 = (RGE_Check_List *)operator new(4u);
    v8 = 0;
    if( v7 )
    {
      RGE_Check_List::RGE_Check_List(v7);
      v27 = v9;
      v8 = 0;
    }
    else
    {
      v27 = 0;
    }
    v10 = v27;
    check_list = v27;
    if( v4 < v8 )
    {
      LOWORD(x1) = 0;
      v4 = 0;
    }
    v11 = map;
    if( (signed __int16)x2 >= map->map_width )
      LOWORD(x2) = LOWORD(map->map_width) - 1;
    if( v5 < 0 )
      v5 = 0;
    if( v6 >= map->map_height )
      v6 = LOWORD(map->map_height) - 1;
    if( v5 <= v6 )
    {
      v38 = v4;
      v12 = 24 * v4;
      v40 = 24 * v4;
      v30 = v5;
      v36 = v6 - v5 + 1;
      do
      {
        if( v4 <= (signed __int16)x2 )
        {
          v13 = (RGE_Object_Node **)((char *)&v11->map_row_offset[v30]->objects.list + v12);
          v14 = (signed __int16)x2 - v38 + 1;
          do
          {
            for( i = *v13; i; i = i->next )
            {
              v16 = i->node;
              if( (RGE_Missile_Object *)i->node != v2 )
              {
                v17 = v16->master_obj;
                ry2 = v17->radius_y;
                rx2 = v17->radius_x;
                if( ry2 > 0.0 && rx2 > 0.0 )
                {
                  v18 = v16->world_z - v2->world_z;
                  if( v18 >= -(v17->radius_z - -0.1) && v18 <= v2->master_obj->radius_z - -0.1 )
                  {
                    v19 = v16->world_x - v2->world_x;
                    v20 = v16->world_y - v2->world_y;
                    if( v19 < 0.0 )
                      v19 = -v19;
                    if( v20 < 0.0 )
                      v20 = -v20;
                    dy = v20 - (ry2 + ry + delta);
                    if( v23 | v24 && dy <= 0.0 )
                    {
                      v21 = v19 - (rx2 + rx + delta);
                      RGE_Check_List::add_node(v27, v16, v21, dy, 0);
                    }
                  }
                }
              }
            }
            v13 += 6;
            --v14;
          }
          while( v14 );
          v4 = x1;
          v11 = map;
          v12 = v40;
        }
        v25 = v36 == 1;
        ++v30;
        --v36;
      }
      while( !v25 );
      v10 = v27;
    }
    if( !v10->list )
    {
      if( v10 )
      {
        RGE_Check_List::~RGE_Check_List(v10);
        operator delete(v27);
      }
      check_list = 0;
    }
    result = check_list;
  }
  return result;
}
