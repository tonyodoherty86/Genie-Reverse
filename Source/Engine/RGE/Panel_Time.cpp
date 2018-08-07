
//----- (0048A680) --------------------------------------------------------
void __thiscall RGE_Panel_Time::RGE_Panel_Time(RGE_Panel_Time *this, TDrawArea *draw_area_in, TPanel *parent_in, void *font_in)
{
  RGE_Panel_Time *v4; // esi@1

  v4 = this;
  TPanel::TPanel((TPanel *)&this->vfptr);
  v4->font = font_in;
  v4->handle_mouse_input = 0;
  v4->game_time = 0;
  v4->last_game_time = 0;
  v4->vfptr = (TPanelVtbl *)&RGE_Panel_Time::`vftable';
  v4->old_time = -1;
  if( !TPanel::setup((TPanel *)&v4->vfptr, draw_area_in, parent_in, 0, 0, 0, 0, 0) )
    v4->error_code = 1;
}
// 572040: using guessed type int (__thiscall *RGE_Panel_Time::`vftable')(void *Memory, unsigned int __flags);

//----- (0048A710) --------------------------------------------------------
RGE_Panel_Time *__thiscall RGE_Panel_Time::`scalar deleting destructor'(RGE_Panel_Time *this, unsigned int __flags)
{
  RGE_Panel_Time *v2; // esi@1

  v2 = this;
  RGE_Panel_Time::~RGE_Panel_Time(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0048A740) --------------------------------------------------------
void __thiscall RGE_Panel_Time::draw(RGE_Panel_Time *this)
{
  RGE_Panel_Time *v1; // esi@1
  TPanelVtbl *v2; // ebx@4
  TDrawArea *v3; // ecx@4
  signed int v4; // edi@7
  int v5; // ecx@7
  int v6; // ebp@7
  int v7; // ebp@10
  RGE_Game_World *v8; // ecx@10
  int v9; // edi@10
  signed int v10; // ebx@11
  int v11; // ST18_4@13
  char *v12; // eax@13
  __int64 v13; // ST14_8@16
  int countdown_timer; // [sp+1Ch] [bp-7Ch]@12
  int player_num; // [sp+20h] [bp-78h]@10
  TPanelVtbl *v16; // [sp+24h] [bp-74h]@4
  void *old_font; // [sp+28h] [bp-70h]@5
  tagPALETTEENTRY paletteColor; // [sp+2Ch] [bp-6Ch]@13
  char str[100]; // [sp+34h] [bp-64h]@6

  v1 = this;
  if( this->render_area && this->visible && this->active )
  {
    v2 = this->vfptr;
    v16 = v2;
    ((void (__stdcall *)(_DWORD))v2->draw_setup)(0);
    v3 = v1->render_area;
    ++v1->display_changed_count;
    if( TDrawArea::GetDc(v3, aRpnl_timDraw) )
    {
      SelectClipRgn(v1->render_area->DrawDc, v1->clip_rgn);
      old_font = SelectObject(v1->render_area->DrawDc, v1->font);
      if( RGE_Base_Game::get_paused(rge_base_game) )
      {
        SetBkColor(v1->render_area->DrawDc, 0xFFFFFFu);
        SetBkMode(v1->render_area->DrawDc, 2);
        SetTextColor(v1->render_area->DrawDc, 0xFFu);
        sprintf(str, aPaused_1);
        TextOutA(v1->render_area->DrawDc, v1->render_rect.left, v1->render_rect.top - 2, str, strlen(str));
      }
      else
      {
        SetBkMode(v1->render_area->DrawDc, 1);
        SetTextColor(v1->render_area->DrawDc, 0xFFFFFFu);
        v4 = v1->game_time;
        v5 = 0;
        v6 = 0;
        if( v4 > 59 )
        {
          v5 = v4 / 60;
          v4 %= 60;
          if( v5 > 59 )
          {
            v6 = v5 / 60;
            v5 %= 60;
          }
        }
        sprintf(str, a02ld02ld02ld3_, v6, v5, v4, rge_base_game->world->game_speed);
        TextOutA(v1->render_area->DrawDc, v1->render_rect.left, v1->render_rect.top - 2, str, strlen(str));
        v7 = 1;
        v8 = rge_base_game->world;
        v9 = v8->player_num;
        player_num = v8->player_num;
        if( v9 > 1 )
        {
          v10 = 13;
          do
          {
            RGE_Base_Game::get_countdown_timer(rge_base_game, v7, &countdown_timer);
            if( countdown_timer >= 0 )
            {
              GetPaletteEntries(
                rge_base_game->draw_system->Pal,
                rge_base_game->world->players[v7]->color_table->map_color,
                1u,
                &paletteColor);
              SetTextColor(
                v1->render_area->DrawDc,
                (unsigned __int8)paletteColor.peRed | (*(unsigned __int16 *)&paletteColor.peGreen << 8));
              v11 = countdown_timer;
              v12 = TPanel::get_string(11300);
              sprintf(str, v12, v11);
              TextOutA(v1->render_area->DrawDc, v1->render_rect.left, v1->render_rect.top + v10, str, strlen(str));
              v9 = player_num;
              v10 += 13;
            }
            ++v7;
          }
          while( v7 < v9 );
          v2 = v16;
        }
      }
      SelectObject(v1->render_area->DrawDc, old_font);
      v13 = (__int64)v1->render_area->DrawDc;
      SelectClipRgn((HDC)v13, (HRGN)HIDWORD(v13));
      TDrawArea::ReleaseDc(v1->render_area, aRpnl_timDraw);
    }
    v2->draw_finish((TPanel *)v1);
  }
}

//----- (0048AA70) --------------------------------------------------------
int __thiscall RGE_Panel_Time::handle_idle(RGE_Panel_Time *this)
{
  RGE_Panel_Time *v1; // esi@1
  signed int v2; // edx@1
  int v3; // eax@2
  TPanel *v4; // ecx@6

  v1 = this;
  TPanel::handle_idle((TPanel *)&this->vfptr);
  v1->game_time = rge_base_game->world->world_time / 0x3E8;
  v2 = rge_base_game->world->old_time / 0x3E8;
  if( v2 > 0 )
  {
    v3 = v1->old_time;
    if( v3 == -1 )
    {
      v1->old_time = v2;
      v1->real_time = 0;
    }
    else
    {
      v1->real_time = v2 - v3;
    }
  }
  if( v1->game_time != v1->last_game_time )
  {
    v1->vfptr->set_redraw((TPanel *)v1, RedrawNormal);
    v4 = v1->parent_panel;
    if( v4 )
      ((void (__stdcall *)(signed int))v4->vfptr->set_redraw)(1);
    v1->last_game_time = v1->game_time;
  }
  return 0;
}
