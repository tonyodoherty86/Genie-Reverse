
//----- (00508670) --------------------------------------------------------
void __thiscall RGE_Task::RGE_Task(RGE_Task *this, __int16 id_in)
{
  this->id = id_in;
  this->task_type = 1;
  this->is_default = 0;
  this->action_type = 0;
  this->object_group = 0;
  this->object_id = 0;
  this->terrain_id = -1;
  this->attribute_type = -1;
  this->attribute_type2 = -1;
  this->attribute_type3 = -1;
  this->attribute_type4 = -1;
  LODWORD(this->work_val1) = 0;
  LODWORD(this->work_val2) = 0;
  LODWORD(this->work_range) = 0;
  this->search_flag = 0;
  LODWORD(this->search_wait_time) = 0;
  this->combat_level = 0;
  this->combat_level_flag = 0;
  this->work_flag = 0;
  this->work_flag2 = 0;
  this->owner_type = 0;
  this->holding_attr = 0;
  this->state_building = 0;
  this->move_sprite = 0;
  this->work_sprite = 0;
  this->work_sprite2 = 0;
  this->carry_sprite = 0;
  this->work_sound = 0;
  this->work_sound2 = 0;
}

//----- (00508700) --------------------------------------------------------
void __thiscall RGE_Task::copy(RGE_Task *this, RGE_Task *other_task)
{
  this->is_default = other_task->is_default;
  this->action_type = other_task->action_type;
  this->object_group = other_task->object_group;
  this->object_id = other_task->object_id;
  this->terrain_id = other_task->terrain_id;
  this->attribute_type = other_task->attribute_type;
  this->attribute_type2 = other_task->attribute_type2;
  this->attribute_type3 = other_task->attribute_type3;
  this->attribute_type4 = other_task->attribute_type4;
  this->work_val1 = other_task->work_val1;
  this->work_val2 = other_task->work_val2;
  this->work_range = other_task->work_range;
  this->search_flag = other_task->search_flag;
  this->search_wait_time = other_task->search_wait_time;
  this->combat_level = other_task->combat_level;
  this->combat_level_flag = other_task->combat_level_flag;
  this->work_flag = other_task->work_flag;
  this->work_flag2 = other_task->work_flag2;
  this->owner_type = other_task->owner_type;
  this->holding_attr = other_task->holding_attr;
  this->state_building = other_task->state_building;
  this->move_sprite = other_task->move_sprite;
  this->work_sprite = other_task->work_sprite;
  this->work_sprite2 = other_task->work_sprite2;
  this->carry_sprite = other_task->carry_sprite;
  this->work_sound = other_task->work_sound;
  this->work_sound2 = other_task->work_sound2;
}

//----- (005087C0) --------------------------------------------------------
void __userpurge RGE_Task::load(RGE_Task *this@<ecx>, int a2@<ebp>, int infile, RGE_Sprite **sprites, RGE_Sound **sounds)
{
  int v5; // esi@1
  RGE_Task *v6; // edi@1
  RGE_Sprite **v7; // ebx@1
  RGE_Sprite *v8; // eax@2
  RGE_Sprite *v9; // eax@5
  RGE_Sprite *v10; // eax@8
  RGE_Sprite *v11; // eax@11
  RGE_Sound **v12; // ebx@13
  RGE_Sound *v13; // eax@14

  v5 = infile;
  v6 = this;
  rge_read(a2, (int)this, infile, &this->id, 2);
  rge_read(a2, (int)v6, v5, &v6->is_default, 1);
  rge_read(a2, (int)v6, v5, &v6->action_type, 2);
  rge_read(a2, (int)v6, v5, &v6->object_group, 2);
  rge_read(a2, (int)v6, v5, &v6->object_id, 2);
  rge_read(a2, (int)v6, v5, &v6->terrain_id, 2);
  rge_read(a2, (int)v6, v5, &v6->attribute_type, 2);
  rge_read(a2, (int)v6, v5, &v6->attribute_type2, 2);
  rge_read(a2, (int)v6, v5, &v6->attribute_type3, 2);
  rge_read(a2, (int)v6, v5, &v6->attribute_type4, 2);
  rge_read(a2, (int)v6, v5, &v6->work_val1, 4);
  rge_read(a2, (int)v6, v5, &v6->work_val2, 4);
  rge_read(a2, (int)v6, v5, &v6->work_range, 4);
  rge_read(a2, (int)v6, v5, &v6->search_flag, 1);
  rge_read(a2, (int)v6, v5, &v6->search_wait_time, 4);
  rge_read(a2, (int)v6, v5, &v6->combat_level, 1);
  rge_read(a2, (int)v6, v5, &v6->combat_level_flag, 1);
  rge_read(a2, (int)v6, v5, &v6->work_flag, 2);
  rge_read(a2, (int)v6, v5, &v6->work_flag2, 2);
  rge_read(a2, (int)v6, v5, &v6->owner_type, 1);
  rge_read(a2, (int)v6, v5, &v6->holding_attr, 1);
  rge_read(a2, (int)v6, v5, &v6->state_building, 1);
  rge_read(a2, (int)v6, v5, &infile, 2);
  v7 = sprites;
  if ( (_WORD)infile == -1 )
    v8 = 0;
  else
    v8 = sprites[(signed __int16)infile];
  v6->move_sprite = v8;
  rge_read(a2, (int)v6, v5, &infile, 2);
  if ( (_WORD)infile == -1 )
    v9 = 0;
  else
    v9 = v7[(signed __int16)infile];
  v6->work_sprite = v9;
  rge_read(a2, (int)v6, v5, &infile, 2);
  if ( (_WORD)infile == -1 )
    v10 = 0;
  else
    v10 = v7[(signed __int16)infile];
  v6->work_sprite2 = v10;
  rge_read(a2, (int)v6, v5, &infile, 2);
  if ( (_WORD)infile == -1 )
    v11 = 0;
  else
    v11 = v7[(signed __int16)infile];
  v6->carry_sprite = v11;
  rge_read(a2, (int)v6, v5, &infile, 2);
  v12 = sounds;
  if ( (_WORD)infile == -1 )
    v13 = 0;
  else
    v13 = sounds[(signed __int16)infile];
  v6->work_sound = v13;
  rge_read(a2, (int)v6, v5, &infile, 2);
  if ( (_WORD)infile == -1 )
    v6->work_sound2 = 0;
  else
    v6->work_sound2 = v12[(signed __int16)infile];
}

//----- (00508A20) --------------------------------------------------------
void __thiscall RGE_Task::load(RGE_Task *this, _iobuf *infile, RGE_Sprite **sprites, RGE_Sound **sounds)
{
  RGE_Task *v4; // esi@1
  char v5; // al@1
  char v6; // cl@1
  char v7; // dl@1
  char v8; // al@1
  char v9; // cl@1
  char v10; // dl@1
  __int16 v11; // ax@1
  RGE_Sprite **v12; // ecx@1
  RGE_Sprite *v13; // eax@2
  RGE_Sprite *v14; // eax@5
  RGE_Sprite *v15; // eax@8
  RGE_Sprite *v16; // eax@11
  RGE_Sound **v17; // ecx@13
  RGE_Sound *v18; // eax@14
  __int16 temp_combat_level; // [sp+4h] [bp-18h]@1
  __int16 temp_combat_level_flag; // [sp+6h] [bp-16h]@1
  __int16 temp_search_flag; // [sp+8h] [bp-14h]@1
  __int16 temp_owner_type; // [sp+Ah] [bp-12h]@1
  __int16 temp_holding_attr; // [sp+Ch] [bp-10h]@1
  __int16 temp_state_building; // [sp+Eh] [bp-Eh]@1
  __int16 move_sprite_id; // [sp+10h] [bp-Ch]@1
  __int16 work_sprite_id; // [sp+12h] [bp-Ah]@1
  __int16 work_sprite2_id; // [sp+14h] [bp-8h]@1
  __int16 carry_sprite_id; // [sp+16h] [bp-6h]@1
  __int16 work_sound_id; // [sp+18h] [bp-4h]@1
  __int16 work_sound2_id; // [sp+1Ah] [bp-2h]@1

  v4 = this;
  fscanf(
    infile,
    aHdHdHdHdHdHd_1,
    &this->id,
    &infile,
    &this->action_type,
    &this->object_group,
    &this->object_id,
    &this->terrain_id,
    &this->attribute_type,
    &this->attribute_type2,
    &this->attribute_type3,
    &this->attribute_type4,
    &this->work_val1,
    &this->work_val2,
    &this->work_range,
    &temp_search_flag,
    &this->search_wait_time,
    &temp_combat_level,
    &temp_combat_level_flag,
    &this->work_flag,
    &this->work_flag2,
    &temp_owner_type,
    &temp_holding_attr,
    &temp_state_building,
    &move_sprite_id,
    &work_sprite_id,
    &work_sprite2_id,
    &carry_sprite_id,
    &work_sound_id,
    &work_sound2_id);
  v5 = temp_combat_level;
  v6 = temp_combat_level_flag;
  v4->is_default = (char)infile;
  v7 = temp_search_flag;
  v4->combat_level = v5;
  v8 = temp_owner_type;
  v4->combat_level_flag = v6;
  v9 = temp_holding_attr;
  v4->search_flag = v7;
  v10 = temp_state_building;
  v4->owner_type = v8;
  v11 = move_sprite_id;
  v4->holding_attr = v9;
  v12 = sprites;
  v4->state_building = v10;
  if ( v11 == -1 )
    v13 = 0;
  else
    v13 = v12[v11];
  v4->move_sprite = v13;
  if ( work_sprite_id == -1 )
    v14 = 0;
  else
    v14 = v12[work_sprite_id];
  v4->work_sprite = v14;
  if ( work_sprite2_id == -1 )
    v15 = 0;
  else
    v15 = v12[work_sprite2_id];
  v4->work_sprite2 = v15;
  if ( carry_sprite_id == -1 )
    v16 = 0;
  else
    v16 = v12[carry_sprite_id];
  v17 = sounds;
  v4->carry_sprite = v16;
  if ( work_sound_id == -1 )
    v18 = 0;
  else
    v18 = v17[work_sound_id];
  v4->work_sound = v18;
  if ( work_sound2_id == -1 )
    v4->work_sound2 = 0;
  else
    v4->work_sound2 = v17[work_sound2_id];
}

//----- (00508BB0) --------------------------------------------------------
void __thiscall RGE_Task::save(RGE_Task *this, int outfile)
{
  int v2; // edi@1
  RGE_Task *v3; // esi@1
  int v4; // ecx@1
  RGE_Sprite *v5; // eax@1
  int v6; // eax@4
  int v7; // edx@7
  RGE_Sprite *v8; // eax@7
  int v9; // ecx@10
  RGE_Sprite *v10; // eax@10
  int v11; // eax@13
  int v12; // edx@16
  RGE_Sound *v13; // esi@16

  v2 = outfile;
  v3 = this;
  rge_write(outfile, this, 2);
  rge_write(v2, &v3->id, 2);
  rge_write(v2, &v3->is_default, 1);
  rge_write(v2, &v3->action_type, 2);
  rge_write(v2, &v3->object_group, 2);
  rge_write(v2, &v3->object_id, 2);
  rge_write(v2, &v3->terrain_id, 2);
  rge_write(v2, &v3->attribute_type, 2);
  rge_write(v2, &v3->attribute_type2, 2);
  rge_write(v2, &v3->attribute_type3, 2);
  rge_write(v2, &v3->attribute_type4, 2);
  rge_write(v2, &v3->work_val1, 4);
  rge_write(v2, &v3->work_val2, 4);
  rge_write(v2, &v3->work_range, 4);
  rge_write(v2, &v3->search_flag, 1);
  rge_write(v2, &v3->search_wait_time, 4);
  rge_write(v2, &v3->combat_level, 1);
  rge_write(v2, &v3->combat_level_flag, 1);
  rge_write(v2, &v3->work_flag, 2);
  rge_write(v2, &v3->work_flag2, 2);
  rge_write(v2, &v3->owner_type, 1);
  rge_write(v2, &v3->holding_attr, 1);
  rge_write(v2, &v3->state_building, 1);
  v5 = v3->move_sprite;
  if ( v5 )
  {
    LOWORD(v4) = v5->id;
    outfile = v4;
  }
  else
  {
    outfile = -1;
  }
  rge_write(v2, &outfile, 2);
  v6 = (int)v3->work_sprite;
  if ( v6 )
  {
    LOWORD(v6) = *(_WORD *)(v6 + 114);
    outfile = v6;
  }
  else
  {
    outfile = -1;
  }
  rge_write(v2, &outfile, 2);
  v8 = v3->work_sprite2;
  if ( v8 )
  {
    LOWORD(v7) = v8->id;
    outfile = v7;
  }
  else
  {
    outfile = -1;
  }
  rge_write(v2, &outfile, 2);
  v10 = v3->carry_sprite;
  if ( v10 )
  {
    LOWORD(v9) = v10->id;
    outfile = v9;
  }
  else
  {
    outfile = -1;
  }
  rge_write(v2, &outfile, 2);
  v11 = (int)&v3->work_sound->play_at_update_count;
  if ( v11 )
  {
    LOWORD(v11) = *(_WORD *)(v11 + 12);
    outfile = v11;
  }
  else
  {
    outfile = -1;
  }
  rge_write(v2, &outfile, 2);
  v13 = v3->work_sound2;
  if ( v13 )
  {
    LOWORD(v12) = v13->id;
    outfile = v12;
  }
  else
  {
    outfile = -1;
  }
  rge_write(v2, &outfile, 2);
}
