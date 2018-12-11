#include "ActionArtifact.hpp"
#include "IDA.h"

#include <cstdlib>
#include <cstring>

#include <RGE/ActionList.hpp>
#include <RGE/ActionMove.hpp>
#include <RGE/Task.hpp>
#include <RGE/Object_Static.hpp>
#include <RGE/Object_Action.hpp>
#include <RGE/MasterObject_Static.hpp>
#include <RGE/MasterObject_Action.hpp>
#include <RGE/Player.hpp>
#include <RGE/World.hpp>
#include <RGE/Map.hpp>
#include <RGE/ObjectList.hpp>

/**
 * @file    Engine\TRB\ActionArtifact.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004CCBA0) --------------------------------------------------------
TRIBE_Action_Artifact::TRIBE_Action_Artifact(int infile, RGE_Action_Object *obj_in) :
    RGE_Action(infile, obj_in, 1)
{
  TRIBE_Action_Artifact *v4; // esi@1

  v4 = this;
  v4->action_type = 107;
}
// 574EA8: using guessed type int (__thiscall *TRIBE_Action_Artifact::`vftable')(void *Memory, unsigned int __flags);

//----- (004CCBD0) --------------------------------------------------------
//----- (004CCC00) --------------------------------------------------------
TRIBE_Action_Artifact::TRIBE_Action_Artifact(RGE_Action_Object *obj_in, RGE_Task *task_in, RGE_Static_Object *target_obj_in) :
    RGE_Action(obj_in, 1)
{
  TRIBE_Action_Artifact *v4; // esi@1

  v4 = this;
  v4->action_type = 107;
  v4->task = task_in;
  v4->target_obj = target_obj_in;
}
// 574EA8: using guessed type int (__thiscall *TRIBE_Action_Artifact::`vftable')(void *Memory, unsigned int __flags);

//----- (004CCC30) --------------------------------------------------------
TRIBE_Action_Artifact::TRIBE_Action_Artifact(RGE_Action_Object *obj_in, RGE_Task *task_in, float x, float y, float z) :
    RGE_Action(obj_in, 1)
{
  TRIBE_Action_Artifact *v6; // esi@1

  v6 = this;
  v6->task = task_in;
  v6->target_y = y;
  v6->action_type = 107;
  v6->target_x = x;
  v6->target_z = z;
}
// 574EA8: using guessed type int (__thiscall *TRIBE_Action_Artifact::`vftable')(void *Memory, unsigned int __flags);

//----- (004CCC70) --------------------------------------------------------
void TRIBE_Action_Artifact::first_in_stack(char first_time)
{
  if ( first_time )
  {
    if ( this->target_obj )
    {
      this->set_state(5);
    }
    else if ( this->target_x == -1|| this->target_y == -1 )
    {
      this->set_state(6);
    }
    else
    {
      this->set_state(4);
    }
  }
}

//----- (004CCCB0) --------------------------------------------------------
void TRIBE_Action_Artifact::set_state( char new_state)
{
  TRIBE_Action_Artifact *v2; // esi@1
  RGE_Static_Object *v3; // eax@5
  RGE_Action_Move_To *v4; // eax@5
  RGE_Action *v5; // eax@6
  RGE_Action_Move_To *v6; // eax@10

  v2 = this;
  this->state = new_state;
  if ( new_state == 4 )
  {
    this->sub_actions->delete_list();
    v6 = new RGE_Action_Move_To(
        v2->obj,
        v2->target_x,
        v2->target_y,
        v2->target_z,
        0.0,
        v2->task->move_sprite);
    v5 = v6;
    if ( v5 )
      goto LABEL_14;
  }
  else
  {
    if ( new_state != 5 )
    {
      if ( new_state == 10 )
        LODWORD(this->timer) = 1077936128;
      return;
    }
    this->sub_actions->delete_list();
    v3 = v2->target_obj;
    v2->target_x = v3->world_x;
    v2->target_y = v3->world_y;
    v2->target_z = v3->world_z;
    v2->target_obj = 0;
    v4 = new RGE_Action_Move_To(
        v2->obj,
        v2->target_x,
        v2->target_y,
        v2->target_z,
        0.0,
        v2->task->move_sprite);
    v5 = v4;
    if ( v5 )
    {
LABEL_14:
      v2->sub_actions->add_action(v5);
      v5->set_state(6);
      return;
    }
  }
}

//----- (004CCDF0) --------------------------------------------------------
bool TRIBE_Action_Artifact::update()
{
  TRIBE_Action_Artifact *v1; // esi@1
  int8_t v2; // al@1
  int8_t v4; // c0@5
  int8_t v5; // c3@5
  char result; // al@6
  RGE_Player *v7; // edi@7

  v1 = this;
  v2 = this->sub_actions->update();
  if ( v2 && v2 <= 3u )
      v1->sub_actions->delete_list();
  switch ( v1->state )
  {
    case 0xA:
      v1->timer = v1->timer - v1->obj->owner->world->world_time_delta_seconds;
      if ( !(v4 | v5) )
        goto LABEL_12;
      v1->set_state(6);
      result = 0;
      break;
    case 6:
      v7 = v1->check_ownership();
      if ( v7 )
      {
        v1->sub_actions->delete_list();
        v1->obj->change_ownership(v7);
        result = 0;
      }
      else
      {
        v1->set_state(10);
        result = 0;
      }
      break;
    case 0x64:
      v1->obj->change_ownership(*v1->obj->owner->world->players);
      v1->set_state(6);
      result = 0;
      break;
    case 1:
      result = 1;
      break;
    default:
LABEL_12:
      result = 0;
      break;
  }
  return result;
}

//----- (004CCF30) --------------------------------------------------------
RGE_Player *TRIBE_Action_Artifact::check_ownership()
{
  RGE_Action_Object *v1; // esi@1
  RGE_Master_Static_Object *v2; // edi@1
  int16_t v3; // bp@1
  int v4; // ebx@1
  RGE_Game_World *v5; // eax@1
  RGE_Map *v6; // edi@1
  unsigned int v7; // esi@1
  void *v8; // edx@1
  int16_t v9; // ax@12
  int16_t v10; // cx@12
  int v11; // ebx@12
  int v12; // esi@14
  int v13; // ebp@14
  int i; // edx@15
  int v15; // ecx@16
  int16_t v16; // ax@16
  int v17; // eax@20
  int16_t v18; // ax@26
  int16_t v19; // si@26
  int16_t v20; // bx@26
  _BYTE *v21; // ecx@27
  RGE_Player *v22; // eax@33
  RGE_Player *result; // eax@34
  int x1; // [sp+10h] [bp-18h]@1
  int x0; // [sp+14h] [bp-14h]@1
  RGE_Map *map; // [sp+18h] [bp-10h]@12
  char *player_list; // [sp+1Ch] [bp-Ch]@1
  int16_t player_num; // [sp+20h] [bp-8h]@1
  TRIBE_Action_Artifact *v29; // [sp+24h] [bp-4h]@1

  v1 = this->obj;
  v29 = this;
  v2 = v1->master_obj;
  x0 = (int64_t)(v1->world_x - 1.0 - v2->radius_x);
  v3 = (int64_t)(v1->world_y - 1.0 - v2->radius_y);
  x1 = (int64_t)(v2->radius_x + v1->world_x - -1.0);
  v4 = (int64_t)(v2->radius_y + v1->world_y - -1.0);
  v6 = v1->owner->world->map;
  v7 = (int16_t)v5->player_num;
  player_num = player_num;
  v8 = calloc(size_t(v5), 1u);
  player_list = (char *)v8;
  if ( player_num > 0 )
    memset(v8, 0, v7);
  if ( (int16_t)x0 < 0 )
    x0 = 0;
  if ( v3 < 0 )
    v3 = 0;
  if (x1 >= v6->map_width )
    x1 = v6->map_width - 1;
  if (v4 >= v6->map_height )
    v4 = v6->map_height - 1;
  if ( v3 <= (int16_t)v4 )
  {
    v9 = x0;
    map = (RGE_Map *)(4 * v3);
    v10 = x1;
    v11 = (int16_t)v4 - v3 + 1;
    do
    {
      if ( v9 <= v10 )
      {
        v12 = 24 * v9;
        v13 = v10 - v9 + 1;
        do
        {
//          for ( i = *(int *)((char *)&(*(RGE_MapVtbl **)((char *)&map->vfptr + (unsigned int)v6->map_row_offset))->do_terrain_brush_stroke
//                           + v12); i; i = *(_DWORD *)(i + 4) )
          for (RGE_Object_Node *object = map->map_row_offset[v12]->objects->list; object != nullptr; object++)
          {
            v15 = *(_DWORD *)i;
            v16 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)i + 8) + 20);
            if ( v16 != 1 && v16 != 11 && v16 != 30 && *(_BYTE *)(v15 + 72) == 2 )
            {
              v17 = *(_WORD *)(*(_DWORD *)(v15 + 12) + 74);
              ++player_list[v17];
            }
          }
          v12 += 24;
          --v13;
        }
        while ( v13 );
        v10 = x1;
        v9 = x0;
      }
      --v11;
      map = (RGE_Map *)((char *)map + 4);
    }
    while ( v11 );
    v8 = player_list;
  }
  v18 = 1;
  v19 = -1;
  v20 = 0;
  if ( player_num > 1 )
  {
    v21 = (uint8_t *)v8 + 1;
    do
    {
      if ( *v21 )
      {
        ++v20;
        v19 = v18;
      }
      ++v18;
      ++v21;
    }
    while ( v18 < player_num );
  }
  free(v8);
  if ( v20 != 1 || v19 <= 0 || (v22 = v29->obj->owner, v19 == v22->id) )
    result = 0;
  else
    result = v22->world->players[v19];
  return result;
}

//----- (004CD120) --------------------------------------------------------
int TRIBE_Action_Artifact::stop()
{
  this->set_state(6);
  return 1;
}

//----- (004CD130) --------------------------------------------------------
int TRIBE_Action_Artifact::move_to(RGE_Static_Object *obj_in, float x, float y, float z)
{
  this->target_x = x;
  this->target_y = y;
  this->target_z = z;
  this->set_state(4);
  return 1;
}

//----- (004CD160) --------------------------------------------------------
int TRIBE_Action_Artifact::work(RGE_Static_Object *obj_in, float x, float y, float z)
{
  int result; // eax@2

  if ( obj_in )
  {
    this->target_obj = obj_in;
    this->set_state(5);
    result = 1;
  }
  else
  {
    this->target_x = x;
    this->target_y = y;
    this->target_z = z;
    this->set_state(4);
    result = 1;
  }
  return result;
}

//----- (004CD1A0) --------------------------------------------------------
void TRIBE_Action_Artifact::reset_owner()
{
  this->set_state(100);
}
