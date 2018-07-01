
//----- (004490E0) --------------------------------------------------------
void __thiscall RGE_Effects::RGE_Effects(RGE_Effects *this, int infile)
{
  RGE_Effects *v2; // ebx@1
  int v3; // edi@1
  size_t *v4; // ebp@1
  int v5; // esi@1
  int v6; // ebp@4
  void *v7; // ebx@4
  _DWORD *v8; // esi@5
  void *v9; // eax@5
  signed int v10; // ebp@5
  bool v11; // zf@5
  bool v12; // sf@5
  int v13; // esi@8
  unsigned __int8 v14; // of@10
  int v15; // [sp+10h] [bp-14h]@3
  int index; // [sp+14h] [bp-10h]@2
  RGE_Effects *v17; // [sp+18h] [bp-Ch]@1
  _DWORD *v18; // [sp+1Ch] [bp-8h]@5
  char *v19; // [sp+20h] [bp-4h]@1
  int infilea; // [sp+28h] [bp+4h]@6

  v2 = this;
  v3 = infile;
  v4 = (size_t *)&this->effect_num;
  v17 = this;
  this->vfptr = (RGE_EffectsVtbl *)&RGE_Effects::`vftable';
  v19 = (char *)&this->effect_num;
  rge_read((int)&this->effect_num, infile, infile, &this->effect_num, 4);
  v5 = 0;
  if ( (signed int)*v4 <= 0 )
  {
    v2->effects = 0;
    *v4 = 0;
  }
  else
  {
    v2->effects = (RGE_Effect *)calloc(*v4, 0x2Cu);
    index = 0;
    if ( (signed int)*v4 > 0 )
    {
      v15 = 0;
      do
      {
        v6 = (int)&v2->effects->id;
        rge_read(v6, v3, v3, (void *)(v6 + 2), 31);
        v7 = (void *)(v5 + v6 + 36);
        rge_read(v6, v3, v3, v7, 2);
        if ( *(_WORD *)v7 <= 0 )
        {
          *(_DWORD *)(v5 + v6 + 40) = 0;
        }
        else
        {
          v8 = (_DWORD *)(v5 + v6 + 40);
          v18 = v8;
          v9 = calloc(*(_WORD *)v7, 0xCu);
          v10 = 0;
          v11 = *(_WORD *)v7 == 0;
          v12 = *(_WORD *)v7 < 0;
          *v8 = v9;
          if ( !v12 && !v11 )
          {
            infilea = 0;
            while ( 1 )
            {
              v13 = infilea + *v8;
              rge_read(v10, v3, v3, (void *)v13, 1);
              rge_read(v10, v3, v3, (void *)(v13 + 2), 2);
              rge_read(v10, v3, v3, (void *)(v13 + 4), 2);
              rge_read(v10, v3, v3, (void *)(v13 + 6), 2);
              rge_read(v10++, v3, v3, (void *)(v13 + 8), 4);
              infilea += 12;
              if ( v10 >= *(_WORD *)v7 )
                break;
              v8 = v18;
            }
          }
          v5 = v15;
        }
        v2 = v17;
        v5 += 44;
        v14 = __OFSUB__(index + 1, *(_DWORD *)v19);
        v12 = index++ + 1 - *(_DWORD *)v19 < 0;
        v15 = v5;
      }
      while ( v12 ^ v14 );
    }
  }
}
// 570430: using guessed type int (__thiscall *RGE_Effects::`vftable')(void *Memory, unsigned int __flags);

//----- (00449240) --------------------------------------------------------
RGE_Effects *__thiscall RGE_Effects::`scalar deleting destructor'(RGE_Effects *this, unsigned int __flags)
{
  RGE_Effects *v2; // esi@1

  v2 = this;
  RGE_Effects::~RGE_Effects(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00449260) --------------------------------------------------------
void __thiscall RGE_Effects::RGE_Effects(RGE_Effects *this, char *effect_file)
{
  RGE_Effects *v2; // edi@1
  char *v3; // ST18_4@1
  FILE *v4; // eax@1
  FILE *v5; // ebp@1
  __int16 v6; // bx@1
  size_t *v7; // esi@2
  RGE_Effect *v8; // eax@7
  int v9; // ecx@7
  __int16 v10; // ax@7
  int v11; // eax@8
  RGE_Effect *v12; // ecx@8
  bool v13; // zf@8
  bool v14; // sf@8
  unsigned __int8 v15; // of@8
  int v16; // ecx@8
  _BYTE *v17; // esi@9
  RGE_Effect *v18; // ecx@10
  int this_effect_num; // [sp+Ch] [bp-Ch]@6
  int index; // [sp+10h] [bp-8h]@3
  int count; // [sp+14h] [bp-4h]@2

  v2 = this;
  v3 = effect_file;
  this->vfptr = (RGE_EffectsVtbl *)&RGE_Effects::`vftable';
  v4 = fopen(v3, Mode);
  v5 = v4;
  v6 = 0;
  if ( v4 )
  {
    v7 = (size_t *)&v2->effect_num;
    if ( fscanf(v4, aDD_1, &v2->effect_num, &count) == -1 )
    {
      *v7 = 0;
      v2->effects = 0;
    }
    else
    {
      v2->effects = (RGE_Effect *)calloc(*v7, 0x2Cu);
      index = 0;
      if ( count > 0 )
      {
        while ( 1 )
        {
          fscanf(v5, aD_3, &this_effect_num);
          if ( fscanf(v5, aSHd, v2->effects[this_effect_num].name, &v2->effects[this_effect_num].effect_list_num) == -1 )
            break;
          v2->effects[this_effect_num].id = this_effect_num;
          v8 = v2->effects;
          v9 = (int)&v8[this_effect_num].id;
          v10 = v8[this_effect_num].effect_list_num;
          if ( v10 <= v6 )
          {
            *(_DWORD *)(v9 + 40) = 0;
          }
          else
          {
            v2->effects[this_effect_num].effect_list = (RGE_Effect_Command *)calloc(v10, 0xCu);
            v11 = this_effect_num;
            v12 = v2->effects;
            v15 = __OFSUB__(v12[this_effect_num].effect_list_num, v6);
            v13 = v12[this_effect_num].effect_list_num == v6;
            v14 = (signed __int16)(v12[this_effect_num].effect_list_num - v6) < 0;
            v16 = (int)&v12[this_effect_num].id;
            if ( (unsigned __int8)(v14 ^ v15) | v13 )
              goto LABEL_14;
            while ( 1 )
            {
              v17 = (_BYTE *)(*(_DWORD *)(v16 + 40) + 12 * v6);
              if ( fscanf(v5, aHdHdHdHdF, &effect_file, v17 + 2, v17 + 4, v17 + 6, v17 + 8) == -1 )
                break;
              ++v6;
              *v17 = (_BYTE)effect_file;
              v11 = this_effect_num;
              v18 = v2->effects;
              v15 = __OFSUB__(v6, v18[this_effect_num].effect_list_num);
              v14 = (signed __int16)(v6 - v18[this_effect_num].effect_list_num) < 0;
              v16 = (int)&v18[this_effect_num].id;
              if ( !(v14 ^ v15) )
                goto LABEL_14;
            }
          }
          v11 = this_effect_num;
LABEL_14:
          convert_us(v2->effects[v11].name);
          if ( ++index >= count )
          {
            fclose(v5);
            return;
          }
          v6 = 0;
        }
      }
    }
    fclose(v5);
  }
  else
  {
    v2->effect_num = 0;
    v2->effects = 0;
  }
}
// 570430: using guessed type int (__thiscall *RGE_Effects::`vftable')(void *Memory, unsigned int __flags);

//----- (00449440) --------------------------------------------------------
void __thiscall RGE_Effects::~RGE_Effects(RGE_Effects *this)
{
  RGE_Effects *v1; // edi@1
  int v2; // ebx@1
  int v3; // eax@1
  int v4; // eax@2
  int v5; // esi@3
  RGE_Effect_Command *v6; // eax@3

  v1 = this;
  v2 = 0;
  v3 = this->effect_num;
  this->vfptr = (RGE_EffectsVtbl *)&RGE_Effects::`vftable';
  if ( v3 > 0 )
  {
    v4 = 0;
    do
    {
      v5 = v4;
      v6 = v1->effects[v4].effect_list;
      if ( v6 )
        free(v6);
      ++v2;
      v1->effects[v5].effect_list = 0;
      v4 = (signed __int16)v2;
    }
    while ( (signed __int16)v2 < v1->effect_num );
  }
  if ( v1->effects )
  {
    free(v1->effects);
    v1->effects = 0;
  }
  v1->effect_num = 0;
}
// 570430: using guessed type int (__thiscall *RGE_Effects::`vftable')(void *Memory, unsigned int __flags);

//----- (004494B0) --------------------------------------------------------
void __thiscall RGE_Effects::save(RGE_Effects *this, int outfile)
{
  RGE_Effects *v2; // esi@1
  int v3; // edi@1
  char *v4; // ebx@1
  RGE_Effect *v5; // esi@4
  signed int v6; // ebx@4
  int v7; // ebp@5
  int v8; // esi@6
  bool v9; // sf@7
  unsigned __int8 v10; // of@7
  int index; // [sp+Ch] [bp-14h]@1
  RGE_Effects *v12; // [sp+10h] [bp-10h]@1
  RGE_Effect_Command **v13; // [sp+14h] [bp-Ch]@5
  __int16 *v14; // [sp+18h] [bp-8h]@4
  char *v15; // [sp+1Ch] [bp-4h]@1
  int outfilea; // [sp+24h] [bp+4h]@2

  v2 = this;
  v3 = outfile;
  v4 = (char *)&this->effect_num;
  v12 = this;
  v15 = (char *)&this->effect_num;
  rge_write(outfile, &this->effect_num, 4);
  index = 0;
  if ( *(_DWORD *)v4 > 0 )
  {
    outfilea = 0;
    while ( 1 )
    {
      v5 = v2->effects;
      rge_write(v3, v5->name, 31);
      v14 = &v5[outfilea].effect_list_num;
      rge_write(v3, v14, 2);
      v6 = 0;
      if ( *v14 > 0 )
      {
        v7 = 0;
        v13 = &v5[outfilea].effect_list;
        do
        {
          v8 = (int)&(*v13)[v7].command;
          rge_write(v3, &(*v13)[v7], 1);
          rge_write(v3, (void *)(v8 + 2), 2);
          rge_write(v3, (void *)(v8 + 4), 2);
          rge_write(v3, (void *)(v8 + 6), 2);
          rge_write(v3, (void *)(v8 + 8), 4);
          ++v6;
          ++v7;
        }
        while ( v6 < *v14 );
      }
      v10 = __OFSUB__(index + 1, *(_DWORD *)v15);
      v9 = index++ + 1 - *(_DWORD *)v15 < 0;
      ++outfilea;
      if ( !(v9 ^ v10) )
        break;
      v2 = v12;
    }
  }
}

//----- (004495C0) --------------------------------------------------------
void __thiscall RGE_Effects::do_effect(RGE_Effects *this, __int16 current_effect, RGE_Player *player)
{
  RGE_Effect *v3; // ebx@2
  __int16 v4; // di@3
  RGE_Effect_Command *v5; // eax@4
  int v6; // ecx@4
  int v7; // eax@4
  __int16 v8; // dx@8
  float v9; // eax@8
  __int16 v10; // cx@12

  if ( current_effect < this->effect_num )
  {
    v3 = &this->effects[current_effect];
    if ( v3 )
    {
      v4 = 0;
      if ( v3->effect_list_num > 0 )
      {
        do
        {
          v5 = v3->effect_list;
          v6 = v5[v4].command;
          v7 = (int)&v5[v4].command;
          switch ( v6 )
          {
            case 4:
              LOWORD(v6) = *(_WORD *)(v7 + 6);
              RGE_Player::modify_tobj_delta(player, *(_WORD *)(v7 + 2), *(_WORD *)(v7 + 4), *(float *)(v7 + 8), v6);
              break;
            case 5:
              LOWORD(v6) = *(_WORD *)(v7 + 6);
              RGE_Player::modify_tobj_percent(player, *(_WORD *)(v7 + 2), *(_WORD *)(v7 + 4), *(float *)(v7 + 8), v6);
              break;
            case 0:
              LOWORD(v6) = *(_WORD *)(v7 + 6);
              RGE_Player::modify_tobj(player, *(_WORD *)(v7 + 2), *(_WORD *)(v7 + 4), *(float *)(v7 + 8), v6);
              break;
            case 1:
              LOWORD(v6) = *(_WORD *)(v7 + 2);
              v8 = *(_WORD *)(v7 + 4);
              v9 = *(float *)(v7 + 8);
              if ( (signed __int16)v6 > -1 )
              {
                if ( v8 )
                  ((void (__thiscall *)(RGE_Player *, int, _DWORD, _DWORD))player->vfptr->add_attribute_num)(
                    player,
                    v6,
                    LODWORD(v9),
                    0);
                else
                  RGE_Player::new_attribute_num(player, v6, v9);
              }
              break;
            case 2:
              v10 = *(_WORD *)(v7 + 2);
              if ( v10 > -1 )
                RGE_Player::make_available(player, v10, *(_BYTE *)(v7 + 4));
              break;
            case 3:
              RGE_Player::copy_obj(player, *(_WORD *)(v7 + 2), *(_WORD *)(v7 + 4));
              break;
            default:
              break;
          }
          ++v4;
        }
        while ( v4 < v3->effect_list_num );
      }
    }
  }
}
