
/**
 * @file    Engine\TRB\ActionWonder.cpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

//----- (004D3470) --------------------------------------------------------
void __userpurge TRIBE_Action_Wonder::TRIBE_Action_Wonder(TRIBE_Action_Wonder *this@<ecx>, int a2@<ebp>, int infile, RGE_Action_Object *obj_in)
{
  TRIBE_Action_Wonder *v4; // esi@1

  v4 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, a2, infile, obj_in, 1);
  v4->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Wonder::`vftable';
  v4->action_type = 120;
}
// 575378: using guessed type int (__thiscall *TRIBE_Action_Wonder::`vftable')(void *Memory, unsigned int __flags);

//----- (004D34A0) --------------------------------------------------------
TRIBE_Action_Wonder *__thiscall TRIBE_Action_Wonder::`scalar deleting destructor'(TRIBE_Action_Wonder *this, unsigned int __flags)
{
  TRIBE_Action_Wonder *v2; // esi@1

  v2 = this;
  TRIBE_Action_Wonder::~TRIBE_Action_Wonder(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004D34C0) --------------------------------------------------------
void __thiscall TRIBE_Action_Wonder::TRIBE_Action_Wonder(TRIBE_Action_Wonder *this, RGE_Action_Object *obj_in)
{
  TRIBE_Action_Wonder *v2; // esi@1

  v2 = this;
  RGE_Action::RGE_Action((RGE_Action *)&this->vfptr, obj_in, 1);
  v2->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Wonder::`vftable';
  v2->action_type = 120;
  LODWORD(v2->timer) = 0;
}
// 575378: using guessed type int (__thiscall *TRIBE_Action_Wonder::`vftable')(void *Memory, unsigned int __flags);

//----- (004D34F0) --------------------------------------------------------
void __thiscall TRIBE_Action_Wonder::~TRIBE_Action_Wonder(TRIBE_Action_Wonder *this)
{
  TRIBE_Action_Wonder *v1; // ebx@1
  RGE_Game_World *v2; // eax@1
  RGE_Player **v3; // edi@2
  signed int v4; // ebp@2
  signed int v5; // esi@3
  _DWORD *v6; // edi@4
  RGE_Action_Object *v7; // ecx@5
  signed int v8; // esi@10
  _DWORD *v9; // edi@11
  RGE_Action_Object *v10; // ecx@12
  RGE_Action_Object *v11; // edx@16
  signed int v12; // edi@16
  RGE_Player *v13; // esi@16
  RGE_Object_Node *v14; // ecx@16
  RGE_Action_Object *v15; // eax@17
  RGE_Player **players; // [sp+24h] [bp-14h]@2

  v1 = this;
  this->vfptr = (RGE_ActionVtbl *)&TRIBE_Action_Wonder::`vftable';
  v2 = rge_base_game->world;
  if ( !v2->game_state )
  {
    v3 = v2->players;
    v4 = v2->player_num;
    players = v2->players;
    if ( this->state == 2 )
    {
      v5 = 1;
      if ( v4 > 1 )
      {
        v6 = v3 + 1;
        do
        {
          v7 = v1->obj;
          if ( v5 != v7->owner->id )
            ((void (__stdcall *)(_DWORD, signed int, signed int))v7->vfptr->unexplore_terrain)(*v6, 1, -1);
          ++v5;
          ++v6;
        }
        while ( v5 < v4 );
        v3 = players;
      }
    }
    if ( v1->state == 6 )
    {
      v8 = 1;
      if ( v4 > 1 )
      {
        v9 = v3 + 1;
        do
        {
          v10 = v1->obj;
          if ( v8 != v10->owner->id )
            ((void (__stdcall *)(_DWORD, _DWORD, signed int))v10->vfptr->unexplore_terrain)(*v9, 0, -1);
          ++v8;
          ++v9;
        }
        while ( v8 < v4 );
      }
      if ( !rge_base_game->world[1].world_time )
      {
        v11 = v1->obj;
        v12 = 0;
        v13 = v11->owner;
        v14 = v13->objects->list;
        if ( v14 )
        {
          while ( 1 )
          {
            v15 = (RGE_Action_Object *)v14->node;
            if ( (RGE_Action_Object *)v14->node != v11 && v15->master_obj->id == 276 && v15->object_state >= 2u )
              break;
            v14 = v14->next;
            if ( !v14 )
              goto LABEL_23;
          }
          v12 = 1;
        }
LABEL_23:
        RGE_Base_Game::reset_countdown_timer(rge_base_game, v13->id);
        if ( v12 )
          RGE_Base_Game::set_countdown_timer(rge_base_game, v1->obj->owner->id, 2000);
      }
    }
    rge_base_game->vfptr->notification(
      rge_base_game,
      110,
      v1->obj->owner->id,
      (signed __int64)v1->obj->world_x,
      (signed __int64)v1->obj->world_y,
      0);
  }
  RGE_Action::~RGE_Action((RGE_Action *)&v1->vfptr);
}
// 575378: using guessed type int (__thiscall *TRIBE_Action_Wonder::`vftable')(void *Memory, unsigned int __flags);

//----- (004D3690) --------------------------------------------------------
void __thiscall TRIBE_Action_Wonder::first_in_stack(TRIBE_Action_Wonder *this, char first_time)
{
  if ( first_time )
    ((void (__stdcall *)(_DWORD))this->vfptr->set_state)(2);
}

//----- (004D36B0) --------------------------------------------------------
void __thiscall TRIBE_Action_Wonder::set_state(TRIBE_Action_Wonder *this, char new_state)
{
  TRIBE_Action_Wonder *v2; // ebx@1
  RGE_Base_Game *v3; // ecx@3
  signed int v4; // edi@3
  RGE_Game_World *v5; // eax@3
  signed int v6; // ebp@3
  _DWORD *v7; // esi@4
  RGE_Action_Object *v8; // ecx@5
  signed int v9; // esi@12
  RGE_Game_World *v10; // eax@12
  signed int v11; // ebp@12
  _DWORD *v12; // edi@13
  RGE_Action_Object *v13; // ecx@14

  v2 = this;
  this->state = new_state;
  if ( new_state == 2 )
  {
    v9 = 1;
    v10 = rge_base_game->world;
    v11 = v10->player_num;
    if ( v11 > 1 )
    {
      v12 = v10->players + 1;
      do
      {
        v13 = v2->obj;
        if ( v9 != v13->owner->id )
          ((void (__stdcall *)(_DWORD, signed int, signed int))v13->vfptr->explore_terrain)(*v12, 1, -1);
        ++v9;
        ++v12;
      }
      while ( v9 < v11 );
    }
    rge_base_game->vfptr->notification(
      rge_base_game,
      108,
      v2->obj->owner->id,
      (signed __int64)v2->obj->world_x,
      (signed __int64)v2->obj->world_y,
      0);
  }
  else if ( new_state == 6 )
  {
    v3 = rge_base_game;
    v4 = 1;
    v5 = rge_base_game->world;
    v6 = v5->player_num;
    if ( v6 > 1 )
    {
      v7 = v5->players + 1;
      do
      {
        v8 = v2->obj;
        if ( v4 != v8->owner->id )
        {
          ((void (__stdcall *)(_DWORD, signed int, signed int))v8->vfptr->unexplore_terrain)(*v7, 1, -1);
          ((void (__stdcall *)(_DWORD, _DWORD, signed int))v2->obj->vfptr->explore_terrain)(*v7, 0, -1);
        }
        ++v4;
        ++v7;
      }
      while ( v4 < v6 );
      v3 = rge_base_game;
    }
    if ( !v3->world[1].world_time )
      RGE_Base_Game::set_countdown_timer(v3, v2->obj->owner->id, 2000);
    rge_base_game->vfptr->notification(
      rge_base_game,
      109,
      v2->obj->owner->id,
      (signed __int64)v2->obj->world_x,
      (signed __int64)v2->obj->world_y,
      0);
  }
}

//----- (004D3810) --------------------------------------------------------
char __thiscall TRIBE_Action_Wonder::update(TRIBE_Action_Wonder *this)
{
  TRIBE_Action_Wonder *v1; // esi@1
  RGE_Action_Object *v2; // edi@4
  double v3; // st7@4
  char result; // al@6

  v1 = this;
  if ( this->state == 2 )
  {
    if ( this->obj->object_state == 2 )
    {
      ((void (__stdcall *)(signed int))this->vfptr->set_state)(6);
      return 0;
    }
  }
  else if ( this->state == 6 && this->timer < 2000.0 )
  {
    v2 = this->obj;
    v3 = v2->owner->world->world_time_delta_seconds + v2->owner->world->world_time_delta_seconds + this->timer;
    this->timer = v3;
    if ( !rge_base_game->world[1].world_time )
    {
      RGE_Base_Game::set_countdown_timer(rge_base_game, v2->owner->id, (signed __int64)(2000.0 - v3));
      if ( v1->timer >= 2000.0 )
      {
        RGE_Player::win_game_now(v1->obj->owner);
        result = 0;
        rge_base_game->world->game_end_condition = 100;
        return result;
      }
    }
  }
  return 0;
}
