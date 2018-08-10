
//----- (0051A5C0) --------------------------------------------------------
void __thiscall TRIBE_Panel_Inven::TRIBE_Panel_Inven(TRIBE_Panel_Inven *this, TDrawArea *render_area_in, TPanel *parent_panel_in, void *font_in, TRIBE_Player *player_in)
{
  TRIBE_Panel_Inven *v5; // esi@1

  v5 = this;
  TPanel::TPanel((TPanel *)&this->vfptr);
  v5->font = font_in;
  v5->save_attr_num = 0;
  v5->save_attr = 0;
  v5->pics = 0;
  v5->idle_time = 0;
  v5->player = 0;
  v5->back_color = 0;
  v5->vfptr = (TPanelVtbl *)&TRIBE_Panel_Inven::`vftable';
  v5->idle_interval = 500;
  v5->font_color = 0xFFFFFF;
  if ( TPanel::setup((TPanel *)&v5->vfptr, render_area_in, parent_panel_in, 0, 0, 0, 0, 0) )
    TRIBE_Panel_Inven::set_player(v5, player_in);
  else
    v5->error_code = 1;
}
// 576BB8: using guessed type int (__thiscall *TRIBE_Panel_Inven::`vftable')(void *Memory, unsigned int __flags);

//----- (0051A690) --------------------------------------------------------
TRIBE_Panel_Inven *__thiscall TRIBE_Panel_Inven::`vector deleting destructor'(TRIBE_Panel_Inven *this, unsigned int __flags)
{
  TRIBE_Panel_Inven *v2; // esi@1

  v2 = this;
  TRIBE_Panel_Inven::~TRIBE_Panel_Inven(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0051A6B0) --------------------------------------------------------
void __thiscall TRIBE_Panel_Inven::set_text_color(TRIBE_Panel_Inven *this, unsigned int font_color_in, unsigned int back_color_in)
{
  TPanelVtbl *v3; // eax@1

  this->font_color = font_color_in;
  v3 = this->vfptr;
  this->back_color = back_color_in;
  ((void (__stdcall *)(signed int))v3->set_redraw)(1);
}

//----- (0051AAD0) --------------------------------------------------------
int __thiscall TRIBE_Panel_Inven::handle_idle(TRIBE_Panel_Inven *this)
{
  TRIBE_Panel_Inven *v1; // ebx@1
  int v2; // eax@1
  __int16 v3; // di@6
  int changed; // [sp+10h] [bp-8h]@6

  v1 = this;
  TPanel::handle_idle((TPanel *)&this->vfptr);
  v2 = rge_base_game->prog_mode;
  if ( (v2 == 4 || v2 == 6 || v2 == 7 || v2 == 5) && debug_timeGetTime() - v1->idle_time >= v1->idle_interval )
  {
    color_log(-70, -70, 5);
    v3 = 0;
    changed = 0;
    if ( v1->save_attr_num > 0 )
    {
      while ( (unsigned __int16)(signed __int64)v1->player->attributes[v3] == v1->save_attr[v3] )
      {
        if ( ++v3 >= v1->save_attr_num )
          goto LABEL_11;
      }
      changed = 1;
    }
LABEL_11:
    if ( changed )
    {
      color_log(-70, 22, 5);
      TRIBE_Panel_Inven::save_info(v1);
      v1->vfptr->set_redraw((TPanel *)v1, RedrawNormal);
    }
    v1->idle_time = debug_timeGetTime();
    color_log(-70, 95, 5);
  }
  return 0;
}

//----- (0051ABF0) --------------------------------------------------------
void __thiscall TRIBE_Panel_Inven::set_player(TRIBE_Panel_Inven *this, TRIBE_Player *player_in)
{
  TRIBE_Panel_Inven *v2; // esi@1

  v2 = this;
  this->player = player_in;
  TRIBE_Panel_Inven::save_info(this);
  v2->vfptr->set_redraw((TPanel *)v2, RedrawNormal);
}

//----- (0051AC10) --------------------------------------------------------
void __thiscall TRIBE_Panel_Inven::save_info(TRIBE_Panel_Inven *this)
{
  TRIBE_Panel_Inven *v1; // esi@1
  signed int v2; // edi@1
  __int16 *v3; // eax@1
  __int16 v4; // ax@5
  signed __int64 v5; // rax@7

  v1 = this;
  v2 = 0;
  v3 = this->save_attr;
  if ( v3 )
  {
    if ( this->save_attr_num == this->player->attribute_num )
      goto LABEL_6;
    if ( v3 )
    {
      free(v3);
      v1->save_attr = 0;
    }
  }
  v4 = v1->player->attribute_num;
  v1->save_attr_num = v4;
  v1->save_attr = (__int16 *)calloc(v4, 2u);
LABEL_6:
  if ( v1->save_attr_num > 0 )
  {
    do
    {
      v5 = (signed __int64)v1->player->attributes[v2++];
      v1->save_attr[v2 - 1] = v5;
    }
    while ( v2 < v1->save_attr_num );
  }
}

//----- (0051ACA0) --------------------------------------------------------
char __thiscall TRIBE_Panel_Inven::get_help_info(TRIBE_Panel_Inven *this, char **string, int *page, int x, int y)
{
  TRIBE_Panel_Inven *v5; // esi@1
  char result; // al@2
  int v7; // eax@5
  int v8; // ST08_4@6
  char *v9; // eax@6
  int v10; // ST08_4@8
  char *v11; // eax@8
  int v12; // ST08_4@10
  char *v13; // eax@10
  int v14; // ST08_4@11
  char *v15; // eax@11

  v5 = this;
  if ( this->active )
  {
    if ( ((int (__stdcall *)(int, int))this->vfptr->is_inside)(x, y) )
    {
      v7 = v5->pnl_x;
      if ( x >= v7 + 55 )
      {
        if ( x >= v7 + 110 )
        {
          if ( x >= v7 + 165 )
          {
            v14 = (signed __int64)v5->player->attributes[2];
            v15 = TPanel::get_string(120048);
            sprintf(*string, v15, v14);
            result = 1;
            *page = -1;
          }
          else
          {
            v12 = (signed __int64)v5->player->attributes[3];
            v13 = TPanel::get_string(120047);
            sprintf(*string, v13, v12);
            *page = -1;
            result = 1;
          }
        }
        else
        {
          v10 = (signed __int64)*v5->player->attributes;
          v11 = TPanel::get_string(120045);
          sprintf(*string, v11, v10);
          result = 1;
          *page = -1;
        }
      }
      else
      {
        v8 = (signed __int64)v5->player->attributes[1];
        v9 = TPanel::get_string(120046);
        sprintf(*string, v9, v8);
        result = 1;
        *page = -1;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}
