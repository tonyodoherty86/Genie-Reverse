
//----- (0051D790) --------------------------------------------------------
void __thiscall TRIBE_Panel_Time::TRIBE_Panel_Time(TRIBE_Panel_Time *this, TDrawArea *render_area_in, TPanel *parent_in)
{
  TRIBE_Panel_Time *v3; // esi@1

  v3 = this;
  TPanel::TPanel((TPanel *)&this->vfptr);
  v3->vfptr = (TPanelVtbl *)&TRIBE_Panel_Time::`vftable';
  v3->handle_mouse_input = 0;
  v3->font = RGE_Base_Game::get_font(rge_base_game, 11)->font;
  v3->color1 = 0xFFFFFF;
  v3->color2 = 0;
  v3->clock_type = 0;
  v3->clock_format = 0;
  v3->old_clock_type = 0;
  v3->old_clock_format = 0;
  v3->player_id = 0;
  v3->world = 0;
  v3->player = 0;
  v3->start_real_time = 0;
  v3->game_time = 0;
  v3->last_game_time = 0;
  v3->last_display_time = -1;
  v3->ImageBuffer = 0;
  v3->LastIBWidth = -1;
  v3->LastIBHeight = -1;
  v3->ImageTextActive = 0;
  v3->image_clip_region = 0;
  if ( !TPanel::setup((TPanel *)&v3->vfptr, render_area_in, parent_in, 0, 0, 0, 0, 0) )
    v3->error_code = 1;
}
// 576EA8: using guessed type int (__thiscall *TRIBE_Panel_Time::`vftable')(void *Memory, unsigned int __flags);

//----- (0051D890) --------------------------------------------------------
TRIBE_Panel_Time *__thiscall TRIBE_Panel_Time::`scalar deleting destructor'(TRIBE_Panel_Time *this, unsigned int __flags)
{
  TRIBE_Panel_Time *v2; // esi@1

  v2 = this;
  TRIBE_Panel_Time::~TRIBE_Panel_Time(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0051DAD0) --------------------------------------------------------
void __thiscall TRIBE_Panel_Time::startup(TRIBE_Panel_Time *this)
{
  this->world = (TRIBE_World *)rge_base_game->world;
  this->start_real_time = debug_timeGetTime();
}

//----- (0051DB00) --------------------------------------------------------
void __thiscall TRIBE_Panel_Time::set_clock_type(TRIBE_Panel_Time *this, int clock_type_in, int player_id_in)
{
  TRIBE_Panel_Time *v3; // esi@1
  TRIBE_Player *v4; // eax@2
  TRIBE_Player *v5; // eax@7
  TPanelVtbl *v6; // edi@23

  v3 = this;
  if ( this->clock_type != clock_type_in || (v4 = this->player) != 0 && v4->id != player_id_in )
  {
    this->clock_type = clock_type_in;
    if ( player_id_in <= 0 )
      this->player = 0;
    else
      this->player = (TRIBE_Player *)this->world->players[player_id_in];
    v5 = this->player;
    if ( v5 )
    {
      switch ( v5->color_table->id )
      {
        case 0:
          this->color1 = 16711680;
          this->color2 = 11776947;
          goto LABEL_19;
        case 1:
          this->color1 = 2177478;
          goto LABEL_18;
        case 2:
          this->color1 = 0xFFFF;
          goto LABEL_18;
        case 3:
          this->color1 = (unsigned int)&loc_4F73A3;
          goto LABEL_18;
        case 4:
          this->color1 = 1013747;
          goto LABEL_18;
        case 5:
          this->color1 = 50944;
          goto LABEL_18;
        case 6:
          this->color1 = (unsigned int)&pathSystem.MGP_openPaths[14537].total + 2;
          goto LABEL_18;
        case 7:
          this->color1 = 11382016;
          goto LABEL_18;
        default:
          break;
      }
    }
    this->color1 = 0xFFFFFF;
LABEL_18:
    this->color2 = 0;
LABEL_19:
    if ( clock_type_in == 1 || clock_type_in == 2 )
      this->clock_format = 1;
    else
      this->clock_format = 2;
    v6 = this->vfptr;
    if ( clock_type_in )
      (*(void (__fastcall **)(TRIBE_Panel_Time *, _DWORD, signed int))&v6->gap10[4])(this, 0, 1);
    else
      (*(void (__fastcall **)(TRIBE_Panel_Time *, _DWORD, signed int))&v6->gap10[4])(this, 0, 0);
    v6->set_redraw((TPanel *)v3, RedrawNormal);
    ((void (__stdcall *)(signed int))v3->parent_panel->vfptr->set_redraw)(1);
    v6->handle_idle((TPanel *)v3);
  }
}

//----- (0051DC60) --------------------------------------------------------
int __thiscall TRIBE_Panel_Time::get_clock_type(TRIBE_Panel_Time *this)
{
  return this->clock_type;
}

//----- (0051DC70) --------------------------------------------------------
int __thiscall TRIBE_Panel_Time::get_player_id(TRIBE_Panel_Time *this)
{
  TRIBE_Player *v1; // eax@1
  int result; // eax@2

  v1 = this->player;
  if ( v1 )
    result = v1->id;
  else
    result = 0;
  return result;
}

//----- (0051DC90) --------------------------------------------------------
void __thiscall TRIBE_Panel_Time::draw(TRIBE_Panel_Time *this)
{
  TRIBE_Panel_Time *v1; // esi@1
  TPanelVtbl *v2; // edi@4
  int v3; // ecx@4
  unsigned int v4; // eax@5
  TDrawArea *v5; // ecx@15
  HGDIOBJ v6; // eax@18
  TDrawArea *v7; // edx@18
  signed int v8; // edi@19
  int v9; // ecx@19
  int v10; // ebx@19
  UINT v11; // ebp@22
  unsigned int v12; // edx@23
  char *v13; // ST14_4@27
  int v14; // ST18_4@28
  char *v15; // ST14_4@28
  char *v16; // eax@26
  int v17; // edi@32
  int v18; // ebx@32
  int v19; // ST30_4@32
  int v20; // ST2C_4@32
  int yTop; // ST38_4@32
  __int64 v22; // ST14_8@32
  int v23; // [sp+8h] [bp-148h]@25
  tagRECT rect; // [sp+2Ch] [bp-124h]@32
  int v25; // [sp+3Ch] [bp-114h]@32
  TPanelVtbl *v26; // [sp+40h] [bp-110h]@4
  int v27; // [sp+44h] [bp-10Ch]@32
  int xRight; // [sp+48h] [bp-108h]@32
  void *old_font; // [sp+4Ch] [bp-104h]@18
  char str[256]; // [sp+50h] [bp-100h]@22

  v1 = this;
  if ( this->render_area && this->visible && this->active )
  {
    v2 = this->vfptr;
    ++this->display_changed_count;
    v26 = v2;
    ((void (__stdcall *)(_DWORD))v2->draw_setup)(0);
    v3 = v1->clock_format;
    if ( v3 == 1 )
      v4 = v1->game_time;
    else
      v4 = 5 * ((v1->game_time + 4) / 5);
    v1->display_time = v4;
    if ( v1->ImageBuffer
      && (v1->display_time != v1->last_display_time
       || v1->clock_type != v1->old_clock_type
       || v3 != v1->old_clock_format
       || v1->need_restore) )
    {
      TRIBE_Panel_Time::render_to_image_buffer(v1);
      if ( v1->need_restore )
      {
        v1->need_restore = 0;
        v2->draw_finish((TPanel *)v1);
        return;
      }
    }
    if ( v1->ImageTextActive )
    {
      v5 = v1->ImageBuffer;
      if ( v5 )
      {
        TDrawArea::SetTrans(v5, 1, 1);
        TDrawArea::Copy(
          v1->ImageBuffer,
          v1->render_area,
          v1->UsedScreenRect.left,
          v1->UsedScreenRect.top,
          &v1->UsedImageRect,
          1);
        TDrawArea::SetTrans(v1->ImageBuffer, 0, 1);
        v2->draw_finish((TPanel *)v1);
        return;
      }
    }
    if ( !TDrawArea::GetDc(v1->render_area, aTpnl_timDraw) )
      goto finish_up_1;
    SelectClipRgn(v1->render_area->DrawDc, v1->clip_rgn);
    v6 = SelectObject(v1->render_area->DrawDc, v1->font);
    v7 = v1->render_area;
    old_font = v6;
    SetBkMode(v7->DrawDc, 1);
    if ( v1->clock_format == 1 )
    {
      v8 = v1->game_time;
      v9 = 0;
      v10 = 0;
      if ( v8 > 59 )
      {
        v9 = v8 / 60;
        v8 %= 60;
        if ( v9 > 59 )
        {
          v10 = v9 / 60;
          v9 %= 60;
        }
      }
      sprintf(str, a02ld02ld02ld3_, v10, v9, v8, rge_base_game->world->game_speed);
      v11 = 32;
      goto LABEL_32;
    }
    v12 = (v1->game_time + 4) / 5;
    if ( v1->clock_type != 4 )
    {
      if ( v1->clock_type == 5 )
      {
        v14 = 5 * v12;
        v15 = TPanel::get_string(11302);
        sprintf(str, v15, v14);
      }
      else
      {
        v23 = 5 * v12;
        if ( v1->clock_type != 6 )
        {
          v16 = TPanel::get_string(11300);
LABEL_30:
          sprintf(str, v16, v23);
          goto LABEL_31;
        }
        v13 = TPanel::get_string(11303);
        sprintf(str, v13, v23);
      }
LABEL_31:
      v11 = 34;
LABEL_32:
      SetTextColor(v1->render_area->DrawDc, v1->color2);
      v17 = v1->render_rect.left + 1;
      v18 = v1->render_rect.top + 1;
      v19 = v18 + v1->pnl_hgt - 2;
      v20 = v17 + v1->pnl_wid - 2;
      yTop = v1->render_rect.top;
      xRight = v20 - 2;
      v25 = v19 - 2;
      SetRect(&rect, v17 - 1, v18 - 1, v20 - 2, v19 - 2);
      DrawTextA(v1->render_area->DrawDc, str, -1, &rect, v11);
      v27 = v18 + 1;
      SetRect(&rect, v17 - 1, v18 + 1, xRight, v19);
      DrawTextA(v1->render_area->DrawDc, str, -1, &rect, v11);
      SetRect(&rect, v17 + 1, yTop, v20, v25);
      DrawTextA(v1->render_area->DrawDc, str, -1, &rect, v11);
      SetRect(&rect, v17 + 1, v27, v20, v19);
      DrawTextA(v1->render_area->DrawDc, str, -1, &rect, v11);
      SetTextColor(v1->render_area->DrawDc, v1->color1);
      SetRect(&rect, v17, v18, v20 - 1, v19 - 1);
      DrawTextA(v1->render_area->DrawDc, str, -1, &rect, v11);
      SelectObject(v1->render_area->DrawDc, old_font);
      v22 = (__int64)v1->render_area->DrawDc;
      SelectClipRgn((HDC)v22, (HRGN)HIDWORD(v22));
      TDrawArea::ReleaseDc(v1->render_area, aTpnl_timDraw);
      v2 = v26;
finish_up_1:
      v2->draw_finish((TPanel *)v1);
      return;
    }
    v23 = 5 * v12;
    v16 = TPanel::get_string(11301);
    goto LABEL_30;
  }
}

//----- (0051E0E0) --------------------------------------------------------
void __thiscall TRIBE_Panel_Time::get_true_render_rect(TRIBE_Panel_Time *this, tagRECT *drawRect)
{
  char *v2; // ecx@5
  char *v3; // ecx@6

  if ( this->ImageBuffer && this->render_area && this->visible && this->active )
  {
    v2 = (char *)&this->UsedScreenRect;
    drawRect->left = *(_DWORD *)v2;
    drawRect->top = *((_DWORD *)v2 + 1);
    drawRect->right = *((_DWORD *)v2 + 2);
    drawRect->bottom = *((_DWORD *)v2 + 3);
  }
  else
  {
    v3 = (char *)&this->render_rect;
    drawRect->left = *(_DWORD *)v3;
    drawRect->top = *((_DWORD *)v3 + 1);
    drawRect->right = *((_DWORD *)v3 + 2);
    drawRect->bottom = *((_DWORD *)v3 + 3);
  }
}

//----- (0051E150) --------------------------------------------------------
int __thiscall TRIBE_Panel_Time::handle_idle(TRIBE_Panel_Time *this)
{
  TRIBE_Panel_Time *v1; // esi@1
  TRIBE_Player *v2; // eax@5
  TRIBE_Player *v3; // eax@7
  TRIBE_Player *v4; // eax@10
  int countdown_timer; // [sp+4h] [bp-4h]@6

  v1 = this;
  TPanel::handle_idle((TPanel *)&this->vfptr);
  switch ( v1->clock_type )
  {
    case 1:
      v1->game_time = (debug_timeGetTime() - v1->start_real_time) / 0x3E8;
      goto LABEL_14;
    case 2:
      v1->game_time = v1->world->world_time / 0x3E8;
      goto LABEL_14;
    case 3:
      v1->game_time = (signed __int64)v1->world->countdown_clock;
      goto LABEL_14;
    case 4:
      v2 = v1->player;
      if ( !v2 )
        goto LABEL_13;
      RGE_Base_Game::get_countdown_timer(rge_base_game, v2->id, &countdown_timer);
      v1->game_time = countdown_timer;
      goto LABEL_14;
    case 5:
      v3 = v1->player;
      if ( !v3 || LODWORD(v3->artifact_held_time) == -1082130432 )
        goto LABEL_13;
      v1->game_time = (signed __int64)v3->artifact_held_time;
      goto LABEL_14;
    case 6:
      v4 = v1->player;
      if ( v4 && LODWORD(v4->ruin_held_time) != -1082130432 )
        v1->game_time = (signed __int64)v4->ruin_held_time;
      else
LABEL_13:
        v1->game_time = 0;
      goto LABEL_14;
    case 0:
      return 0;
    default:
LABEL_14:
      if ( v1->game_time != v1->last_game_time )
      {
        v1->vfptr->set_redraw((TPanel *)v1, RedrawNormal);
        ((void (__stdcall *)(signed int))v1->parent_panel->vfptr->set_redraw)(1);
        v1->last_game_time = v1->game_time;
      }
      break;
  }
  return 0;
}

//----- (0051E2B0) --------------------------------------------------------
void *__thiscall TRIBE_Panel_Time::render_to_image_buffer(TRIBE_Panel_Time *this)
{
  TRIBE_Panel_Time *v1; // esi@1
  TDrawArea *v2; // ecx@1
  void *result; // eax@2
  signed int v4; // edi@5
  int v5; // ecx@5
  int v6; // ebx@5
  bool v7; // zf@6
  bool v8; // sf@6
  unsigned __int8 v9; // of@6
  UINT v10; // edi@8
  unsigned int v11; // edx@9
  char *v12; // ST14_4@13
  int v13; // ST18_4@14
  char *v14; // ST14_4@14
  char *v15; // eax@12
  int v16; // ebx@18
  int v17; // ebp@18
  __int64 v18; // ST14_8@18
  int v19; // eax@18
  int v20; // edx@18
  int v21; // ecx@18
  int v22; // edi@18
  int v23; // edx@18
  unsigned int v24; // eax@18
  int v25; // edx@18
  int v26; // edi@18
  int v27; // ecx@18
  int v28; // [sp+4h] [bp-128h]@11
  tagRECT rect; // [sp+18h] [bp-114h]@18
  void *old_font; // [sp+28h] [bp-104h]@4
  char str[256]; // [sp+2Ch] [bp-100h]@8

  v1 = this;
  v2 = this->ImageBuffer;
  if ( !v2 )
    return 0;
  TDrawArea::PtrClear(v2, &v1->ImageRect, 1);
  result = TDrawArea::GetDc(v1->ImageBuffer, aTpnl_timRender);
  if ( result )
  {
    TDrawArea::SetClipRect(v1->ImageBuffer, &v1->ImageRect);
    SelectClipRgn(v1->ImageBuffer->DrawDc, v1->image_clip_region);
    old_font = SelectObject(v1->ImageBuffer->DrawDc, v1->font);
    SetBkMode(v1->ImageBuffer->DrawDc, 1);
    if ( v1->clock_format == 1 )
    {
      v4 = v1->game_time;
      v5 = 0;
      v6 = 0;
      if ( v4 > 59 )
      {
        v5 = v4 / 60;
        v9 = __OFSUB__(v4 / 60, 59);
        v7 = v4 / 60 == 59;
        v8 = v4 / 60 - 59 < 0;
        v4 %= 60;
        if ( !((unsigned __int8)(v8 ^ v9) | v7) )
        {
          v6 = v5 / 60;
          v5 %= 60;
        }
      }
      sprintf(str, a02ld02ld02ld3_, v6, v5, v4, rge_base_game->world->game_speed);
      v10 = 32;
      goto LABEL_18;
    }
    v11 = (v1->game_time + 4) / 5;
    if ( v1->clock_type != 4 )
    {
      if ( v1->clock_type == 5 )
      {
        v13 = 5 * v11;
        v14 = TPanel::get_string(11302);
        sprintf(str, v14, v13);
      }
      else
      {
        v28 = 5 * v11;
        if ( v1->clock_type != 6 )
        {
          v15 = TPanel::get_string(11300);
LABEL_16:
          sprintf(str, v15, v28);
          goto LABEL_17;
        }
        v12 = TPanel::get_string(11303);
        sprintf(str, v12, v28);
      }
LABEL_17:
      v10 = 34;
LABEL_18:
      SetTextColor(v1->ImageBuffer->DrawDc, v1->color2);
      v16 = v1->pnl_hgt - 1;
      v17 = v1->pnl_wid - 2 + 1;
      SetRect(&rect, 0, 0, v1->pnl_wid - 3, v1->pnl_hgt - 3);
      DrawTextA(v1->ImageBuffer->DrawDc, str, -1, &rect, v10);
      SetRect(&rect, 0, 2, v17 - 2, v16);
      DrawTextA(v1->ImageBuffer->DrawDc, str, -1, &rect, v10);
      SetRect(&rect, 2, 0, v17, v16 - 2);
      DrawTextA(v1->ImageBuffer->DrawDc, str, -1, &rect, v10);
      SetRect(&rect, 2, 2, v17, v16);
      DrawTextA(v1->ImageBuffer->DrawDc, str, -1, &rect, v10);
      SetTextColor(v1->ImageBuffer->DrawDc, v1->color1);
      SetRect(&rect, 1, 1, v17 - 1, v16 - 1);
      DrawTextA(v1->ImageBuffer->DrawDc, str, -1, &rect, v10);
      SelectObject(v1->ImageBuffer->DrawDc, old_font);
      v18 = (__int64)v1->ImageBuffer->DrawDc;
      SelectClipRgn((HDC)v18, (HRGN)HIDWORD(v18));
      TDrawArea::ReleaseDc(v1->ImageBuffer, aTpnl_timRender);
      v19 = v1->pnl_wid;
      v20 = v1->render_rect.left;
      v21 = v1->pnl_hgt;
      v1->UsedImageRect.left = 0;
      v1->UsedImageRect.top = 0;
      v22 = v1->render_rect.top;
      --v19;
      v1->UsedScreenRect.left = v20;
      --v21;
      v23 = v19 + v20;
      v1->UsedScreenRect.top = v22;
      v1->UsedImageRect.right = v19;
      v24 = v1->display_time;
      v1->UsedImageRect.bottom = v21;
      v1->UsedScreenRect.right = v23;
      v25 = v1->clock_format;
      v26 = v21 + v22;
      v27 = v1->clock_type;
      v1->UsedScreenRect.bottom = v26;
      v1->last_display_time = v24;
      v1->old_clock_type = v27;
      v1->old_clock_format = v25;
      v1->ImageTextActive = 1;
      return (void *)1;
    }
    v28 = 5 * v11;
    v15 = TPanel::get_string(11301);
    goto LABEL_16;
  }
  return result;
}

//----- (0051E650) --------------------------------------------------------
void __thiscall Time_Line_Panel::Time_Line_Panel(Time_Line_Panel *this)
{
  Time_Line_Panel *v1; // esi@1

  v1 = this;
  TEasy_Panel::TEasy_Panel((TEasy_Panel *)&this->vfptr);
  v1->text_style = 2;
  v1->axis_font = 0;
  v1->axis_font_wid = 0;
  v1->axis_font_hgt = 0;
  v1->body_font = 0;
  v1->body_font_wid = 0;
  v1->body_font_hgt = 0;
  v1->text_color1 = 0xFFFFFF;
  v1->text_color2 = 0;
  v1->highlightTextColor1 = 0xFFFF;
  v1->highlightTextColor2 = 0;
  v1->text_wid = 0;
  v1->text_hgt = 0;
  v1->background_pic = 0;
  v1->background_pic_wid = 0;
  v1->background_pic_hgt = 0;
  v1->fill_back = 0;
  v1->back_color = -1;
  v1->outline = 0;
  v1->outline_color = 0;
  v1->bevel_type = 0;
  v1->bevel_color1 = 0;
  v1->bevel_color2 = 0;
  v1->bevel_color3 = 0;
  v1->bevel_color4 = 0;
  v1->bevel_color5 = 0;
  v1->bevel_color6 = 0;
  v1->special_events_pic = 0;
  v1->special_events_pic_wid = 0;
  v1->special_events_pic_hgt = 0;
  v1->total_slices_to_drop = 0;
  v1->time_slice_events = 0;
  v1->vfptr = (TPanelVtbl *)&Time_Line_Panel::`vftable';
  v1->handle_mouse_input = 0;
  v1->timeline_flag = 1;
  v1->drop_flag = 0;
  v1->pop_reading_rate = 12;
  v1->legend_entry_text[0] = 0;
  v1->legend_entry_text[1] = 0;
  v1->legend_entry_text[2] = 0;
}
// 576F88: using guessed type int (__thiscall *Time_Line_Panel::`vftable')(void *Memory, unsigned int __flags);

//----- (0051E770) --------------------------------------------------------
Time_Line_Panel *__thiscall Time_Line_Panel::`vector deleting destructor'(Time_Line_Panel *this, unsigned int __flags)
{
  Time_Line_Panel *v2; // esi@1

  v2 = this;
  Time_Line_Panel::~Time_Line_Panel(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0051E790) --------------------------------------------------------
void __thiscall Time_Line_Panel::~Time_Line_Panel(Time_Line_Panel *this)
{
  Time_Line_Panel *v1; // esi@1
  Special_Events *i; // eax@1
  TShape *v3; // edi@3
  TShape *v4; // edi@5
  TPanel **v5; // edi@7
  signed int v6; // ebx@7

  v1 = this;
  this->vfptr = (TPanelVtbl *)&Time_Line_Panel::`vftable';
  for ( i = this->time_slice_events; i; i = v1->time_slice_events )
  {
    v1->time_slice_events = i->next;
    free(i);
  }
  v3 = v1->background_pic;
  if ( v3 )
  {
    TShape::~TShape(v1->background_pic);
    operator delete(v3);
    v1->background_pic = 0;
  }
  v4 = v1->special_events_pic;
  if ( v4 )
  {
    TShape::~TShape(v1->special_events_pic);
    operator delete(v4);
    v1->special_events_pic = 0;
  }
  v5 = (TPanel **)v1->legend_entry_text;
  v6 = 3;
  do
  {
    TPanel::delete_panel(v5);
    ++v5;
    --v6;
  }
  while ( v6 );
  TEasy_Panel::~TEasy_Panel((TEasy_Panel *)&v1->vfptr);
}
// 576F88: using guessed type int (__thiscall *Time_Line_Panel::`vftable')(void *Memory, unsigned int __flags);

//----- (0051E860) --------------------------------------------------------
signed int __thiscall Time_Line_Panel::create_timeline(Time_Line_Panel *this, TPanel *parent_panel_in, struct Time_Line_Panel **a3, __int32 y_in, __int32 a5, __int32 a6, __int32 a7, __int32 a8, __int32 a9, __int32 a10, __int32 a11)
{
  TPanel *v11; // esi@1
  __int32 v12; // ebp@1
  __int32 v13; // ebx@1
  Time_Line_Panel *v14; // eax@1
  struct Time_Line_Panel *v15; // eax@2
  RGE_Font *v16; // eax@7
  RGE_Font *v17; // edi@9
  RGE_Font *v18; // eax@10
  int v19; // ST2C_4@12
  int v20; // ST28_4@12
  void *v21; // ST24_4@12
  int v22; // ST20_4@12
  int v23; // ST1C_4@12
  void *v24; // ST18_4@12
  TDrawArea *v25; // eax@12
  Time_Line_Panel *v27; // [sp+10h] [bp-10h]@1
  TPanel *parent_panel_ina; // [sp+24h] [bp+4h]@1
  int y_ina; // [sp+2Ch] [bp+Ch]@1

  v11 = parent_panel_in;
  v27 = this;
  v12 = y_in * TPanel::width(parent_panel_in) / a10;
  y_ina = a5 * TPanel::height(parent_panel_in) / a11;
  parent_panel_ina = (TPanel *)(a6 * TPanel::width(parent_panel_in) / a10);
  v13 = a7 * TPanel::height(v11) / a11;
  v14 = (Time_Line_Panel *)operator new(0x52Cu);
  if ( v14 )
    Time_Line_Panel::Time_Line_Panel(v14);
  else
    v15 = 0;
  *a3 = v15;
  if ( !v15 || v15->error_code )
  {
    v27->error_code = 1;
  }
  else
  {
    if ( a8 < 0 )
      v16 = RGE_Base_Game::get_font(rge_base_game, 11);
    else
      v16 = RGE_Base_Game::get_font(rge_base_game, a8);
    v17 = v16;
    if ( a9 < 0 )
      v18 = RGE_Base_Game::get_font(rge_base_game, 11);
    else
      v18 = RGE_Base_Game::get_font(rge_base_game, a9);
    v19 = v18->font_hgt;
    v20 = v18->font_wid;
    v21 = v18->font;
    v22 = v17->font_hgt;
    v23 = v17->font_wid;
    v24 = v17->font;
    v25 = TPanel::renderArea(v11);
    if ( Time_Line_Panel::setup(
           *a3,
           v25,
           v11,
           v12,
           y_ina,
           (int)parent_panel_ina,
           v13,
           v24,
           v23,
           v22,
           v21,
           v20,
           v19,
           0,
           0,
           0,
           0,
           0,
           0) )
    {
      Time_Line_Panel::init_timeline(*a3);
      return 1;
    }
    v27->error_code = 1;
  }
  return 0;
}

//----- (0051E9E0) --------------------------------------------------------
int __thiscall Time_Line_Panel::setup(Time_Line_Panel *this, TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, void *axis_font_in, int axis_font_wid_in, int axis_font_hgt_in, void *body_font_in, int body_font_wid_in, int body_font_hgt_in, char *back_pic_in, char *special_event_pic_in, int fill_back_in, char back_color_in, int outline_in, char outline_color_in)
{
  Time_Line_Panel *v19; // esi@1
  char back_color_ina; // [sp+44h] [bp+40h]@3

  v19 = this;
  TPanel::setup((TPanel *)&this->vfptr, render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);
  v19->fill_back = fill_back_in;
  v19->back_color = back_color_in;
  v19->outline = outline_in;
  v19->outline_color = outline_color_in;
  if ( outline_in )
    v19->bevel_type = 1;
  Time_Line_Panel::set_axis_font(v19, axis_font_in, axis_font_wid_in, axis_font_hgt_in);
  Time_Line_Panel::set_body_font(v19, body_font_in, body_font_wid_in, body_font_hgt_in);
  Time_Line_Panel::set_background(v19, back_pic_in);
  Time_Line_Panel::set_special_events(v19, special_event_pic_in);
  back_color_ina = GetNearestPaletteIndex(v19->render_area->DrawSystem->Pal, 0);
  Time_Line_Panel::set_back_color(v19, 1, back_color_ina);
  return 1;
}

//----- (0051EAB0) --------------------------------------------------------
void __thiscall Time_Line_Panel::set_bevel_info(Time_Line_Panel *this, int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6)
{
  this->bevel_type = bevel_type_in;
  this->bevel_color1 = c1;
  this->bevel_color2 = c2;
  this->bevel_color3 = c3;
  this->bevel_color4 = c4;
  this->bevel_color5 = c5;
  this->bevel_color6 = c6;
}

//----- (0051EB00) --------------------------------------------------------
int __thiscall Time_Line_Panel::set_background(Time_Line_Panel *this, char *file_name)
{
  Time_Line_Panel *v2; // esi@1
  TShape *v3; // edi@1
  TShape *v4; // eax@5
  TShape *v5; // eax@6
  __int16 v6; // cx@8
  int result; // eax@8
  int x_max; // [sp+Ch] [bp-1Ch]@8
  int x_min; // [sp+10h] [bp-18h]@8
  int y_max; // [sp+14h] [bp-14h]@8
  int y_min; // [sp+18h] [bp-10h]@8
  int v12; // [sp+24h] [bp-4h]@5

  v2 = this;
  v3 = this->background_pic;
  if ( v3 )
  {
    TShape::~TShape(this->background_pic);
    operator delete(v3);
    v2->background_pic = 0;
    v2->background_pic_wid = 0;
    v2->background_pic_hgt = 0;
  }
  if ( file_name && *file_name )
  {
    v4 = (TShape *)operator new(0x20u);
    v12 = 0;
    if ( v4 )
      TShape::TShape(v4, file_name, -1);
    else
      v5 = 0;
    v12 = -1;
    v2->background_pic = v5;
    TShape::shape_minmax(v5, &x_min, &y_min, &x_max, &y_max, 0);
    v6 = y_max - y_min + 1;
    v2->background_pic_wid = x_max - x_min + 1;
    v2->background_pic_hgt = v6;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0051EC10) --------------------------------------------------------
int __thiscall Time_Line_Panel::set_background(Time_Line_Panel *this, char *file_name, int resource_id)
{
  Time_Line_Panel *v3; // esi@1
  TShape *v4; // edi@1
  TShape *v5; // eax@9
  TShape *v6; // eax@10
  TShape *v7; // eax@12
  TShape *v8; // ecx@16
  TShape *v9; // edi@18
  TShape *v10; // ecx@21
  __int16 v11; // dx@22
  int result; // eax@22
  int y_max; // [sp+Ch] [bp-124h]@22
  int y_min; // [sp+10h] [bp-120h]@22
  int x_min; // [sp+14h] [bp-11Ch]@22
  TShape *v16; // [sp+18h] [bp-118h]@9
  int x_max; // [sp+1Ch] [bp-114h]@22
  char file_name2[260]; // [sp+20h] [bp-110h]@7
  int v19; // [sp+12Ch] [bp-4h]@9

  v3 = this;
  v4 = this->background_pic;
  if ( v4 )
  {
    TShape::~TShape(this->background_pic);
    operator delete(v4);
    v3->background_pic = 0;
    v3->background_pic_wid = 0;
    v3->background_pic_hgt = 0;
  }
  if ( file_name && *file_name && _strcmpi(file_name, Str2) )
  {
    if ( strchr(file_name, 46) )
      sprintf(file_name2, aS_2, file_name);
    else
      sprintf(file_name2, aS_shp, file_name);
    v5 = (TShape *)operator new(0x20u);
    v16 = v5;
    v19 = 0;
    if ( v5 )
    {
      TShape::TShape(v5, file_name2, resource_id);
LABEL_15:
      v19 = -1;
      v3->background_pic = v6;
      goto LABEL_16;
    }
    goto LABEL_14;
  }
  if ( resource_id != -1 )
  {
    v7 = (TShape *)operator new(0x20u);
    v16 = v7;
    v19 = 1;
    if ( v7 )
    {
      TShape::TShape(v7, message_in, resource_id);
      goto LABEL_15;
    }
LABEL_14:
    v6 = 0;
    goto LABEL_15;
  }
LABEL_16:
  v8 = v3->background_pic;
  if ( v8 && !TShape::is_loaded(v8) )
  {
    v9 = v3->background_pic;
    if ( v9 )
    {
      TShape::~TShape(v3->background_pic);
      operator delete(v9);
    }
    v3->background_pic = 0;
  }
  v10 = v3->background_pic;
  if ( v10 )
  {
    TShape::shape_minmax(v10, &x_min, &y_min, &x_max, &y_max, 0);
    v11 = y_max;
    result = 1;
    v3->background_pic_wid = x_max - x_min + 1;
    v3->background_pic_hgt = v11 - y_min + 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0051EDD0) --------------------------------------------------------
int __thiscall Time_Line_Panel::set_special_events(Time_Line_Panel *this, char *file_name)
{
  Time_Line_Panel *v2; // esi@1
  TShape *v3; // edi@1
  TShape *v4; // eax@5
  TShape *v5; // eax@6
  __int16 v6; // cx@8
  int result; // eax@8
  int x_max; // [sp+Ch] [bp-1Ch]@8
  int x_min; // [sp+10h] [bp-18h]@8
  int y_max; // [sp+14h] [bp-14h]@8
  int y_min; // [sp+18h] [bp-10h]@8
  int v12; // [sp+24h] [bp-4h]@5

  v2 = this;
  v3 = this->special_events_pic;
  if ( v3 )
  {
    TShape::~TShape(this->special_events_pic);
    operator delete(v3);
    v2->special_events_pic = 0;
    v2->special_events_pic_wid = 0;
    v2->special_events_pic_hgt = 0;
  }
  if ( file_name && *file_name )
  {
    v4 = (TShape *)operator new(0x20u);
    v12 = 0;
    if ( v4 )
      TShape::TShape(v4, file_name, -1);
    else
      v5 = 0;
    v12 = -1;
    v2->special_events_pic = v5;
    TShape::shape_minmax(v5, &x_min, &y_min, &x_max, &y_max, 0);
    v6 = y_max - y_min + 1;
    v2->special_events_pic_wid = x_max - x_min + 1;
    v2->special_events_pic_hgt = v6;
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0051EEE0) --------------------------------------------------------
int __thiscall Time_Line_Panel::set_special_events(Time_Line_Panel *this, char *file_name, int resource_id)
{
  Time_Line_Panel *v3; // esi@1
  TShape *v4; // edi@1
  TShape *v5; // eax@9
  TShape *v6; // eax@10
  TShape *v7; // eax@12
  TShape *v8; // ecx@16
  TShape *v9; // edi@18
  TShape *v10; // ecx@21
  __int16 v11; // dx@22
  int result; // eax@22
  int y_max; // [sp+Ch] [bp-124h]@22
  int y_min; // [sp+10h] [bp-120h]@22
  int x_min; // [sp+14h] [bp-11Ch]@22
  TShape *v16; // [sp+18h] [bp-118h]@9
  int x_max; // [sp+1Ch] [bp-114h]@22
  char file_name2[260]; // [sp+20h] [bp-110h]@7
  int v19; // [sp+12Ch] [bp-4h]@9

  v3 = this;
  v4 = this->special_events_pic;
  if ( v4 )
  {
    TShape::~TShape(this->special_events_pic);
    operator delete(v4);
    v3->special_events_pic = 0;
    v3->special_events_pic_wid = 0;
    v3->special_events_pic_hgt = 0;
  }
  if ( file_name && *file_name && _strcmpi(file_name, Str2) )
  {
    if ( strchr(file_name, 46) )
      sprintf(file_name2, aS_2, file_name);
    else
      sprintf(file_name2, aS_shp, file_name);
    v5 = (TShape *)operator new(0x20u);
    v16 = v5;
    v19 = 0;
    if ( v5 )
    {
      TShape::TShape(v5, file_name2, resource_id);
LABEL_15:
      v19 = -1;
      v3->special_events_pic = v6;
      goto LABEL_16;
    }
    goto LABEL_14;
  }
  if ( resource_id != -1 )
  {
    v7 = (TShape *)operator new(0x20u);
    v16 = v7;
    v19 = 1;
    if ( v7 )
    {
      TShape::TShape(v7, message_in, resource_id);
      goto LABEL_15;
    }
LABEL_14:
    v6 = 0;
    goto LABEL_15;
  }
LABEL_16:
  v8 = v3->special_events_pic;
  if ( v8 && !TShape::is_loaded(v8) )
  {
    v9 = v3->special_events_pic;
    if ( v9 )
    {
      TShape::~TShape(v3->special_events_pic);
      operator delete(v9);
    }
    v3->special_events_pic = 0;
  }
  v10 = v3->special_events_pic;
  if ( v10 )
  {
    TShape::shape_minmax(v10, &x_min, &y_min, &x_max, &y_max, 0);
    v11 = y_max;
    result = 1;
    v3->special_events_pic_wid = x_max - x_min + 1;
    v3->special_events_pic_hgt = v11 - y_min + 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0051F0A0) --------------------------------------------------------
void __thiscall Time_Line_Panel::set_axis_font(Time_Line_Panel *this, void *font_in, int font_wid_in, int font_hgt_in)
{
  TPanelVtbl *v4; // edx@1

  this->axis_font = font_in;
  this->axis_font_wid = font_wid_in;
  v4 = this->vfptr;
  this->axis_font_hgt = font_hgt_in;
  ((void (__stdcall *)(signed int))v4->set_redraw)(1);
}

//----- (0051F0D0) --------------------------------------------------------
void __thiscall Time_Line_Panel::set_body_font(Time_Line_Panel *this, void *font_in, int font_wid_in, int font_hgt_in)
{
  TPanelVtbl *v4; // edx@1

  this->body_font = font_in;
  this->body_font_wid = font_wid_in;
  v4 = this->vfptr;
  this->body_font_hgt = font_hgt_in;
  ((void (__stdcall *)(signed int))v4->set_redraw)(1);
}

//----- (0051F100) --------------------------------------------------------
void __thiscall Time_Line_Panel::set_back_color(Time_Line_Panel *this, int use_back_color_flag_in, char back_color_in)
{
  this->fill_back = use_back_color_flag_in;
  this->back_color = back_color_in;
}

//----- (0051F120) --------------------------------------------------------
void __thiscall Time_Line_Panel::draw_border(Time_Line_Panel *this)
{
  Time_Line_Panel *v1; // esi@1

  v1 = this;
  if ( this->bevel_type )
  {
    if ( TDrawArea::Lock(this->render_area, aTpnl_tmlDraw_b, 1) )
    {
      switch ( v1->bevel_type )
      {
        case 1:
          TDrawArea::DrawRect(
            v1->render_area,
            v1->pnl_x,
            v1->pnl_y,
            v1->pnl_wid + v1->pnl_x - 1,
            v1->pnl_hgt + v1->pnl_y - 1,
            v1->outline_color);
          TDrawArea::Unlock(v1->render_area, aTpnl_tmlDraw_b);
          return;
        case 2:
          TDrawArea::DrawBevel(
            v1->render_area,
            v1->pnl_x,
            v1->pnl_y,
            v1->pnl_wid + v1->pnl_x - 1,
            v1->pnl_hgt + v1->pnl_y - 1,
            v1->bevel_color6,
            v1->bevel_color1);
          goto LABEL_9;
        case 3:
          TDrawArea::DrawBevel2(
            v1->render_area,
            v1->pnl_x,
            v1->pnl_y,
            v1->pnl_wid + v1->pnl_x - 1,
            v1->pnl_hgt + v1->pnl_y - 1,
            v1->bevel_color6,
            v1->bevel_color5,
            v1->bevel_color2,
            v1->bevel_color1);
          goto LABEL_11;
        case 4:
          TDrawArea::DrawBevel3(
            v1->render_area,
            v1->pnl_x,
            v1->pnl_y,
            v1->pnl_wid + v1->pnl_x - 1,
            v1->pnl_hgt + v1->pnl_y - 1,
            v1->bevel_color6,
            v1->bevel_color5,
            v1->bevel_color4,
            v1->bevel_color3,
            v1->bevel_color2,
            v1->bevel_color1);
          break;
        case 5:
          TDrawArea::DrawBevel(
            v1->render_area,
            v1->pnl_x,
            v1->pnl_y,
            v1->pnl_wid + v1->pnl_x - 1,
            v1->pnl_hgt + v1->pnl_y - 1,
            v1->bevel_color1,
            v1->bevel_color6);
LABEL_9:
          TDrawArea::Unlock(v1->render_area, aTpnl_tmlDraw_b);
          return;
        case 6:
          TDrawArea::DrawBevel2(
            v1->render_area,
            v1->pnl_x,
            v1->pnl_y,
            v1->pnl_wid + v1->pnl_x - 1,
            v1->pnl_hgt + v1->pnl_y - 1,
            v1->bevel_color1,
            v1->bevel_color2,
            v1->bevel_color5,
            v1->bevel_color6);
LABEL_11:
          TDrawArea::Unlock(v1->render_area, aTpnl_tmlDraw_b);
          return;
        case 7:
          TDrawArea::DrawBevel3(
            v1->render_area,
            v1->pnl_x,
            v1->pnl_y,
            v1->pnl_wid + v1->pnl_x - 1,
            v1->pnl_hgt + v1->pnl_y - 1,
            v1->bevel_color1,
            v1->bevel_color2,
            v1->bevel_color3,
            v1->bevel_color4,
            v1->bevel_color5,
            v1->bevel_color6);
          break;
        default:
          break;
      }
    }
    TDrawArea::Unlock(v1->render_area, aTpnl_tmlDraw_b);
  }
}

//----- (0051F310) --------------------------------------------------------
void __thiscall Time_Line_Panel::init_timeline(Time_Line_Panel *this)
{
  Time_Line_Panel *v1; // esi@1
  int v2; // ebp@1
  RGE_Game_World *v3; // eax@1
  signed int v4; // edi@2
  int v5; // eax@3
  int v6; // eax@6
  int v7; // ecx@6
  signed int v8; // edx@8
  double v9; // st7@8
  char v11; // c0@8
  int v12; // eax@11
  int v13; // ecx@11
  int v14; // eax@11
  int v15; // ecx@11
  int v16; // eax@11
  signed int v17; // eax@11

  v1 = this;
  v2 = 0;
  this->num_history_entries = 0;
  v3 = rge_base_game->world;
  if ( v3->player_num - 1 > 0 )
  {
    v4 = 1;
    do
    {
      v5 = TRIBE_History_Info::get_history_entry_num(*(TRIBE_History_Info **)&v3->players[v4][3].groups_used[62]);
      if ( v1->num_history_entries < v5 )
        v1->num_history_entries = v5;
      ++v2;
      ++v4;
      v3 = rge_base_game->world;
    }
    while ( v2 < v3->player_num - 1 );
  }
  v6 = TPanel::width((TPanel *)&v1->vfptr);
  v7 = v6 - 49;
  if ( !v1->num_history_entries )
  {
    v1->num_history_entries = 1;
    v1->timeline_flag = 0;
  }
  v8 = v1->num_history_entries;
  LODWORD(v1->time_slice_drop_rate) = 0;
  v9 = (double)(v6 - 49);
  v1->bar_thickness = v9 / (double)v8;
  if ( v11 )
  {
    LODWORD(v1->bar_thickness) = 1065353216;
    v1->num_entries_page = v7;
    v1->drop_flag = 1;
    v1->total_slices_to_drop = v8 - v7;
    v1->time_slice_drop_rate = v9 / (double)(v8 - v7);
  }
  else
  {
    v1->num_entries_page = v8;
  }
  v1->X_axis_length = (unsigned __int64)(signed __int64)((double)v1->num_entries_page * v1->bar_thickness) + 4;
  v1->Y_axis_length = -26 - 4 * v1->axis_font_hgt + TPanel::height((TPanel *)&v1->vfptr);
  v1->X_start_line_pos = TPanel::xPosition((TPanel *)&v1->vfptr) + 27;
  v12 = TPanel::yPosition((TPanel *)&v1->vfptr);
  v13 = v1->axis_font_hgt;
  v1->X_line_pos = v1->X_start_line_pos;
  v14 = v12 + 2 * v13 + 15;
  v15 = v1->X_axis_length;
  v1->Y_start_line_pos = v14;
  v1->Y_line_pos = v14;
  v16 = v1->Y_axis_length - 3;
  v1->X_line_max_width = v15 - 2;
  v1->Y_line_max_length = v16;
  v17 = v1->num_entries_page;
  if ( v17 >= 12 )
    v1->pop_reading_rate = (signed __int64)((double)(v17 - 1) * 0.083333336);
  else
    v1->pop_reading_rate = 1;
}

//----- (0051F4E0) --------------------------------------------------------
void __thiscall Time_Line_Panel::add_pop_total_special_event(Time_Line_Panel *this, int sample_time_slice, int sample_pop_total, int sample_x_line_pos, int time_flag)
{
  Time_Line_Panel *v5; // esi@1
  _DWORD *v6; // eax@1

  v5 = this;
  v6 = calloc(1u, 0xB0u);
  *v6 = sample_time_slice;
  v6[1] = sample_x_line_pos;
  v6[2] = 0;
  v6[3] = 0;
  *((_BYTE *)v6 + 16) = 0;
  *((_BYTE *)v6 + 17) = 0;
  v6[6] = 0;
  v6[7] = 0;
  v6[8] = 0;
  v6[9] = 0;
  v6[10] = 0;
  v6[11] = 0;
  v6[12] = 0;
  v6[13] = 0;
  v6[14] = 0;
  *((_BYTE *)v6 + 60) = 0;
  v6[28] = 0;
  *((_BYTE *)v6 + 116) = 0;
  *((_BYTE *)v6 + 18) = 3;
  v6[5] = sample_pop_total;
  v6[42] = time_flag;
  v6[43] = v5->time_slice_events;
  v5->time_slice_events = (Special_Events *)v6;
}

//----- (0051F560) --------------------------------------------------------
void __thiscall Time_Line_Panel::record_special_event(Time_Line_Panel *this, char player_id, TRIBE_History_Info *history, char player_color, int time_slice, int x_line_pos, int y_line_pos, int intermediate_y_line_segment)
{
  int v8; // edi@1
  Time_Line_Panel *v9; // esi@1
  _DWORD *v10; // eax@2
  int v11; // edx@2
  int v12; // ecx@2

  v8 = time_slice;
  v9 = this;
  if ( TRIBE_History_Info::get_history_event(history, time_slice, (char *)&time_slice) )
  {
    v10 = calloc(1u, 0xB0u);
    v11 = y_line_pos;
    v10[1] = x_line_pos;
    v12 = intermediate_y_line_segment;
    v10[2] = v11;
    v10[3] = v12;
    *v10 = v8;
    *((_BYTE *)v10 + 16) = player_id;
    *((_BYTE *)v10 + 17) = player_color;
    *((_BYTE *)v10 + 18) = time_slice;
    v10[5] = 0;
    v10[6] = 0;
    v10[7] = 0;
    v10[8] = 0;
    v10[9] = 0;
    v10[10] = 0;
    v10[11] = 0;
    v10[12] = 0;
    v10[13] = 0;
    v10[14] = 0;
    *((_BYTE *)v10 + 60) = 0;
    v10[28] = 0;
    *((_BYTE *)v10 + 116) = 0;
    v10[42] = 0;
    v10[43] = v9->time_slice_events;
    v9->time_slice_events = (Special_Events *)v10;
  }
}

//----- (0051F600) --------------------------------------------------------
int __thiscall Time_Line_Panel::calculate_icon_location(Time_Line_Panel *this, Special_Events *event_ptr, __int16 icon_number, char history_type)
{
  Special_Events *v4; // ebx@1
  Time_Line_Panel *v5; // esi@1
  int v6; // edi@1
  TShape *v7; // ecx@1
  int v8; // ebp@5
  int v9; // ecx@15
  int v10; // eax@15
  int v11; // ecx@17
  signed int v12; // eax@20
  unsigned int v13; // kr04_4@22
  int v14; // edi@22
  int v15; // eax@22
  int v16; // edx@22
  int v17; // ecx@22
  int v18; // edx@25
  int v19; // ecx@25
  unsigned int v20; // kr0C_4@26
  int v21; // edi@26
  int v22; // eax@26
  int v23; // edx@26
  int v24; // ecx@26
  int v25; // ecx@29
  int v26; // edi@29
  int v27; // eax@29
  unsigned int v28; // kr14_4@31
  int v29; // edi@31
  int v30; // eax@31
  int v31; // edx@31
  int v32; // ecx@31
  int v33; // eax@32
  int v34; // ecx@34
  int v35; // eax@37
  signed int v36; // ebp@40
  int v37; // edx@40
  int v38; // ecx@45
  int v39; // edx@45
  int v40; // eax@45
  int v41; // esi@45
  signed int v42; // ebp@47
  int v43; // edx@47
  int v44; // ecx@55
  int v45; // edx@55
  int result; // eax@55
  __int16 height; // [sp+12h] [bp-12h]@8
  int ret_val; // [sp+14h] [bp-10h]@1
  int temp_start_txt_x1; // [sp+18h] [bp-Ch]@1
  int temp_start_y; // [sp+1Ch] [bp-8h]@1
  int temp_start_x; // [sp+20h] [bp-4h]@1

  v4 = event_ptr;
  v5 = this;
  v6 = 0;
  ret_val = 1;
  event_ptr->icon_flag = 0;
  v7 = this->special_events_pic;
  temp_start_x = 0;
  temp_start_y = 0;
  temp_start_txt_x1 = 0;
  if ( !v7 )
    ret_val = 0;
  if ( !TShape::shape_count(v7) )
    ret_val = 0;
  v8 = icon_number;
  if ( TShape::shape_count(v5->special_events_pic) < v8 )
    ret_val = 0;
  if ( ret_val )
  {
    TShape::shape_bounds(v5->special_events_pic, v8, (__int16 *)&event_ptr, &height);
    if ( (signed __int16)event_ptr > 0 )
      v5->special_events_pic_wid = (signed __int16)event_ptr;
    if ( height > 0 )
      v5->special_events_pic_hgt = height;
    if ( ret_val )
    {
      if ( v5->special_events_pic_hgt > v4->intermediate_y_line_segment )
        ret_val = 0;
      v9 = v4->X_line_pos;
      v10 = v5->special_events_pic_wid / 2;
      if ( v9 + v10 > v5->X_start_line_pos + v5->X_line_max_width )
        ret_val = 0;
      v11 = v9 - v10;
      if ( v11 < v5->X_start_line_pos )
        ret_val = 0;
      if ( ret_val )
      {
        v12 = v4->intermediate_y_line_segment;
        temp_start_x = v11;
        temp_start_y = v12 / 2 + 2 * v4->Y_line_pos - v5->special_events_pic_hgt / 2;
      }
    }
  }
  switch ( v4->event )
  {
    case 0:
      v13 = strlen(v4->text1) + 1;
      v14 = v4->X_line_pos;
      v4->text_length1 = v13 - 1;
      v15 = (v13 - 1) * v5->body_font_wid;
      v16 = v5->X_start_line_pos;
      v17 = v5->X_line_max_width;
      if ( v15 + v14 + 2 < v17 + v16 )
        temp_start_txt_x1 = v4->X_line_pos + 2;
      else
        temp_start_txt_x1 = v17 - v15 + v16 - 3;
      v18 = v5->body_font_hgt;
      v19 = v4->intermediate_y_line_segment + v4->Y_line_pos - v18 - 2;
      goto LABEL_35;
    case 1:
      v20 = strlen(v4->text1) + 1;
      v21 = v4->X_line_pos;
      v4->text_length1 = v20 - 1;
      v22 = (v20 - 1) * v5->body_font_wid;
      v23 = v5->X_start_line_pos;
      v24 = v5->X_line_max_width;
      if ( v22 + v21 + 2 < v24 + v23 )
        temp_start_txt_x1 = v4->X_line_pos + 2;
      else
        temp_start_txt_x1 = v24 - v22 + v23 - 8;
      v25 = v5->body_font_hgt;
      v26 = v4->Y_line_pos;
      v27 = v5->Y_line_max_length + v5->Y_start_line_pos;
      if ( v25 + v26 + 2 < v27 )
        goto LABEL_36;
      v6 = v27 - v25 - 2;
      break;
    case 2:
      v28 = strlen(v4->text1) + 1;
      v29 = v4->X_line_pos;
      v4->text_length1 = v28 - 1;
      v30 = (v28 - 1) * v5->body_font_wid;
      v31 = v5->X_start_line_pos;
      v32 = v5->X_line_max_width;
      if ( v30 + v29 + 2 < v32 + v31 )
        v33 = v4->X_line_pos + 2;
      else
        v33 = v32 - v30 + v31 - 3;
      v18 = v5->body_font_hgt;
      v34 = v4->intermediate_y_line_segment + v4->Y_line_pos - v18;
      temp_start_txt_x1 = v33;
      v19 = v34 - 2;
LABEL_35:
      v26 = v5->Y_start_line_pos;
      if ( v19 > v26 )
      {
        v35 = v26 + v5->Y_line_max_length;
        if ( v19 < v35 )
          v6 = v19;
        else
          v6 = v35 - v18 - 3;
      }
      else
      {
LABEL_36:
        v6 = v26 + 2;
      }
      break;
    case 6:
      *(_DWORD *)&icon_number = v5->X_line_max_width + v5->X_start_line_pos;
      v36 = v5->body_font_wid;
      v37 = v4->X_line_pos;
      if ( (signed int)(v37 + v36 * strlen(v4->text1)) <= icon_number )
        v4->text_length1 = strlen(v4->text1);
      else
        v4->text_length1 = (icon_number - v37) / v36;
      if ( v4->text_length1 > 2 )
        v4->text_length1 = 2;
      v38 = v5->special_events_pic_hgt;
      v39 = v5->body_font_hgt;
      v40 = v5->Y_line_max_length;
      v41 = v5->Y_start_line_pos;
      if ( v39 + temp_start_y + v38 + 1 > v40 + v41 )
        goto LABEL_53;
      goto LABEL_54;
    case 8:
      *(_DWORD *)&icon_number = v5->X_line_max_width + v5->X_start_line_pos;
      v42 = v5->body_font_wid;
      v43 = v4->X_line_pos;
      if ( (signed int)(v43 + v42 * strlen(v4->text1)) <= icon_number )
        v4->text_length1 = strlen(v4->text1);
      else
        v4->text_length1 = (icon_number - v43) / v42;
      if ( v4->text_length1 > 5 )
        v4->text_length1 = 5;
      v38 = v5->special_events_pic_hgt;
      v39 = v5->body_font_hgt;
      v40 = v5->Y_line_max_length;
      v41 = v5->Y_start_line_pos;
      if ( v39 + temp_start_y + v38 + 1 > v40 + v41 )
LABEL_53:
        temp_start_y = v40 - v39 - v38 + v41 - 1;
LABEL_54:
      temp_start_txt_x1 = temp_start_x;
      v6 = temp_start_y + v38 + 1;
      break;
    default:
      break;
  }
  v44 = temp_start_txt_x1;
  v45 = temp_start_y;
  v4->start_x = temp_start_x;
  result = ret_val;
  v4->start_txt_x1 = v44;
  v4->start_y = v45;
  v4->start_txt_y1 = v6;
  if ( result )
    v4->icon_flag = 1;
  return result;
}

//----- (0051FA30) --------------------------------------------------------
void __thiscall Time_Line_Panel::draw(Time_Line_Panel *this)
{
  Time_Line_Panel *v1; // esi@1
  TDrawArea *v2; // eax@1
  TPanelVtbl *v3; // edi@4

  v1 = this;
  TPanel::draw((TPanel *)&this->vfptr);
  v2 = v1->render_area;
  v1->need_redraw = 0;
  if ( v2 && v1->visible )
  {
    if ( v1->active )
    {
      v3 = v1->vfptr;
      v1->vfptr->draw_setup((TPanel *)v1, 0);
      Time_Line_Panel::draw_background(v1);
      Time_Line_Panel::draw_border(v1);
      Time_Line_Panel::draw_axis(v1);
      Time_Line_Panel::draw_timeline(v1);
      Time_Line_Panel::draw_special_events(v1);
      Time_Line_Panel::draw_civilization_names(v1);
      v3->draw_finish((TPanel *)v1);
    }
  }
}

//----- (0051FA90) --------------------------------------------------------
void __thiscall Time_Line_Panel::draw_axis(Time_Line_Panel *this)
{
  Time_Line_Panel *v1; // esi@1
  int v2; // ST0C_4@2
  int v3; // ST08_4@2
  int v4; // ST04_4@2
  int v5; // eax@2
  int v6; // ST0C_4@2
  int v7; // ST08_4@2
  int v8; // ST04_4@2
  int v9; // eax@2
  int v10; // ST0C_4@2
  int v11; // ST08_4@2
  int v12; // ST04_4@2
  int v13; // eax@2
  int v14; // ST0C_4@2
  int v15; // ST08_4@2
  int v16; // ST04_4@2
  int v17; // eax@2
  int v18; // ebx@5
  int v19; // ebp@5
  int v20; // ebx@7
  int v21; // ebp@7
  int v22; // ebp@7
  char white_color; // [sp+10h] [bp-68h]@1
  HGDIOBJ white_colora; // [sp+10h] [bp-68h]@4
  char temp_str[100]; // [sp+14h] [bp-64h]@4

  v1 = this;
  white_color = GetNearestPaletteIndex(this->render_area->DrawSystem->Pal, 0xFFFFFFu);
  if ( TDrawArea::Lock(v1->render_area, aTpnl_tmlDraw_a, 1) )
  {
    v2 = TPanel::yPosition((TPanel *)&v1->vfptr) + 2 * v1->axis_font_hgt + v1->Y_axis_length + 13;
    v3 = TPanel::xPosition((TPanel *)&v1->vfptr) + v1->X_axis_length + 24;
    v4 = v1->Y_axis_length + TPanel::yPosition((TPanel *)&v1->vfptr) + 2 * v1->axis_font_hgt + 12;
    v5 = TPanel::xPosition((TPanel *)&v1->vfptr);
    TDrawArea::FillRect(v1->render_area, v5 + 25, v4, v3, v2, white_color);
    v6 = TPanel::yPosition((TPanel *)&v1->vfptr) + 2 * v1->axis_font_hgt + 14;
    v7 = TPanel::xPosition((TPanel *)&v1->vfptr) + v1->X_axis_length + 24;
    v8 = TPanel::yPosition((TPanel *)&v1->vfptr) + 2 * v1->axis_font_hgt + 13;
    v9 = TPanel::xPosition((TPanel *)&v1->vfptr);
    TDrawArea::FillRect(v1->render_area, v9 + 25, v8, v7, v6, white_color);
    v10 = TPanel::yPosition((TPanel *)&v1->vfptr) + 2 * v1->axis_font_hgt + v1->Y_axis_length + 13;
    v11 = TPanel::xPosition((TPanel *)&v1->vfptr) + 26;
    v12 = TPanel::yPosition((TPanel *)&v1->vfptr) + 2 * v1->axis_font_hgt + 13;
    v13 = TPanel::xPosition((TPanel *)&v1->vfptr);
    TDrawArea::FillRect(v1->render_area, v13 + 25, v12, v11, v10, white_color);
    v14 = TPanel::yPosition((TPanel *)&v1->vfptr) + 2 * v1->axis_font_hgt + v1->Y_axis_length + 13;
    v15 = TPanel::xPosition((TPanel *)&v1->vfptr) + v1->X_axis_length + 24;
    v16 = TPanel::yPosition((TPanel *)&v1->vfptr) + 2 * v1->axis_font_hgt + 13;
    v17 = TPanel::xPosition((TPanel *)&v1->vfptr);
    TDrawArea::FillRect(v1->render_area, v17 + v1->X_axis_length + 23, v16, v15, v14, white_color);
  }
  TDrawArea::Unlock(v1->render_area, aTpnl_tmlDraw_a);
  if ( TDrawArea::GetDc(v1->render_area, aTpnl_tmlDraw_a) )
  {
    SetBkMode(v1->render_area->DrawDc, 1);
    white_colora = SelectObject(v1->render_area->DrawDc, v1->axis_font);
    if ( TPanel::get_string(11351, temp_str, 100) )
    {
      v18 = TPanel::xPosition((TPanel *)&v1->vfptr) + 8;
      v19 = TPanel::yPosition((TPanel *)&v1->vfptr) + 5;
      SetTextColor(v1->render_area->DrawDc, 0xFFFFFFu);
      TextOutA(v1->render_area->DrawDc, v18, v19, temp_str, strlen(temp_str));
    }
    if ( TPanel::get_string(11350, temp_str, 100) )
    {
      v20 = v1->X_axis_length / 2 + v1->X_start_line_pos - (v1->axis_font_wid * strlen(temp_str) >> 1);
      v21 = TPanel::height((TPanel *)&v1->vfptr);
      v22 = -5 - v1->axis_font_hgt + TPanel::yPosition((TPanel *)&v1->vfptr) + v21;
      SetTextColor(v1->render_area->DrawDc, 0xFFFFFFu);
      TextOutA(v1->render_area->DrawDc, v20, v22, temp_str, strlen(temp_str));
    }
    SelectObject(v1->render_area->DrawDc, white_colora);
    TDrawArea::ReleaseDc(v1->render_area, aTpnl_tmlDraw_a);
  }
}

//----- (0051FD90) --------------------------------------------------------
void __thiscall Time_Line_Panel::draw_special_events(Time_Line_Panel *this)
{
  Time_Line_Panel *v1; // esi@1
  Special_Events *i; // edi@3
  HGDIOBJ v3; // eax@17
  Special_Events *v4; // ebx@17
  signed int v5; // ebp@20
  unsigned int v6; // kr04_4@20
  int v7; // ST08_4@20
  unsigned int v8; // kr14_4@20
  int v9; // edi@20
  int v10; // ST08_4@20
  char v11; // [sp-4h] [bp-18h]@5
  void *old_font; // [sp+10h] [bp-4h]@17

  v1 = this;
  if ( this->timeline_flag )
  {
    GetNearestPaletteIndex(this->render_area->DrawSystem->Pal, 0xFFFFFFu);
    GetNearestPaletteIndex(v1->render_area->DrawSystem->Pal, 0);
    if ( TDrawArea::Lock(v1->render_area, aTpnl_tmlDraw_s, 1) )
    {
      for ( i = v1->time_slice_events; i; i = i->next )
      {
        switch ( i->event )
        {
          case 0:
            v11 = 0;
            goto LABEL_14;
          case 1:
            v11 = 1;
            goto LABEL_14;
          case 2:
            v11 = 2;
            goto LABEL_14;
          case 4:
            Time_Line_Panel::draw_icon(v1, i, 0, 4);
            break;
          case 5:
            Time_Line_Panel::draw_icon(v1, i, 1, 5);
            break;
          case 6:
            Time_Line_Panel::draw_icon(v1, i, 2, 6);
            break;
          case 7:
            Time_Line_Panel::draw_icon(v1, i, 3, 7);
            break;
          case 8:
            Time_Line_Panel::draw_icon(v1, i, 4, 8);
            break;
          case 3:
            v11 = 3;
LABEL_14:
            Time_Line_Panel::draw_icon(v1, i, -1, v11);
            break;
          default:
            continue;
        }
      }
    }
    TDrawArea::Unlock(v1->render_area, aTpnl_tmlDraw_s);
    if ( TDrawArea::GetDc(v1->render_area, aTpnl_tmlDraw_s) )
    {
      SetBkMode(v1->render_area->DrawDc, 1);
      v3 = SelectObject(v1->render_area->DrawDc, v1->body_font);
      v4 = v1->time_slice_events;
      for ( old_font = v3; v4; v4 = v4->next )
      {
        switch ( v4->event )
        {
          case 0:
            SetTextColor(v1->render_area->DrawDc, 0);
            TextOutA(v1->render_area->DrawDc, v4->start_txt_x1, v4->start_txt_y1, v4->text1, v4->text_length1);
            break;
          case 3:
            v5 = v4->time_slice != 0 ? -2 : 2;
            SetTextColor(v1->render_area->DrawDc, 0xFFFFFFu);
            v6 = strlen(v4->text1) + 1;
            v7 = TPanel::yPosition((TPanel *)&v1->vfptr) + v1->axis_font_hgt + 8;
            TextOutA(
              v1->render_area->DrawDc,
              v4->X_line_pos + v5 - v1->axis_font_wid * (strlen(v4->text1) >> 1),
              v7,
              v4->text1,
              v6 - 1);
            v8 = strlen(v4->text2) + 1;
            v9 = TPanel::yPosition((TPanel *)&v1->vfptr);
            v10 = -7 - 2 * v1->axis_font_hgt + TPanel::height((TPanel *)&v1->vfptr) + v9;
            TextOutA(
              v1->render_area->DrawDc,
              v4->X_line_pos + v5 - v1->axis_font_wid * (strlen(v4->text2) >> 1),
              v10,
              v4->text2,
              v8 - 1);
            break;
          case 6:
            if ( v4->icon_flag )
              goto LABEL_22;
            break;
          case 1:
LABEL_22:
            SetTextColor(v1->render_area->DrawDc, 0);
            TextOutA(v1->render_area->DrawDc, v4->start_txt_x1, v4->start_txt_y1, v4->text1, v4->text_length1);
            break;
          case 8:
            if ( v4->icon_flag )
              goto LABEL_24;
            break;
          case 2:
LABEL_24:
            SetTextColor(v1->render_area->DrawDc, 0);
            TextOutA(v1->render_area->DrawDc, v4->start_txt_x1, v4->start_txt_y1, v4->text1, v4->text_length1);
            break;
          default:
            continue;
        }
      }
      SelectObject(v1->render_area->DrawDc, old_font);
      TDrawArea::ReleaseDc(v1->render_area, aTpnl_tmlDraw_s);
    }
  }
}

//----- (00520080) --------------------------------------------------------
void __thiscall Time_Line_Panel::draw_background(Time_Line_Panel *this)
{
  Time_Line_Panel *v1; // esi@1
  signed int v2; // ecx@3
  signed int v3; // edi@3
  signed __int16 v4; // cx@4
  signed int v5; // edi@8
  signed int v6; // ebx@8
  int v7; // eax@9
  int v8; // ebp@13
  int v9; // edi@15
  int v10; // ebx@15
  TPanel *v11; // ecx@23
  signed int v12; // eax@24
  int pic_cols; // [sp+10h] [bp-8h]@4
  __int16 pic_rows; // [sp+14h] [bp-4h]@0
  int pic_rowsa; // [sp+14h] [bp-4h]@13

  v1 = this;
  if ( this->background_pic )
  {
    if ( TDrawArea::Lock(this->render_area, aTpnl_tmlDraw_2, 1) )
    {
      v2 = v1->background_pic_wid;
      v3 = v1->pnl_wid;
      if ( v2 < v3 )
      {
        pic_cols = v3 / v2;
        if ( v2 * (signed __int16)(v3 / v2) < v3 )
          LOWORD(pic_cols) = pic_cols + 1;
        v4 = pic_cols;
      }
      else
      {
        v4 = 1;
        LOWORD(pic_cols) = 1;
      }
      v5 = v1->background_pic_hgt;
      v6 = v1->pnl_hgt;
      if ( v5 < v6 )
      {
        LOWORD(v7) = pic_rows;
      }
      else
      {
        v7 = v6 / v5;
        if ( v5 * (signed __int16)(v6 / v5) < v6 )
          LOWORD(v7) = v7 + 1;
      }
      if ( (signed __int16)v7 > 0 )
      {
        v8 = 0;
        pic_rowsa = (signed __int16)v7;
        do
        {
          if ( v4 > 0 )
          {
            v9 = 0;
            v10 = v4;
            do
            {
              TShape::shape_draw(
                v1->background_pic,
                v1->render_area,
                v1->pnl_x + v1->background_pic_wid * v9++,
                v1->pnl_y + v1->background_pic_hgt * v8,
                0,
                0,
                0);
              --v10;
            }
            while ( v10 );
            v4 = pic_cols;
          }
          ++v8;
          --pic_rowsa;
        }
        while ( pic_rowsa );
      }
      TDrawArea::Unlock(v1->render_area, aTpnl_tmlDraw_2);
    }
  }
  else if ( this->fill_back )
  {
    if ( TDrawArea::Lock(this->render_area, aTpnl_tmlDraw_0, 1) )
    {
      TDrawArea::FillRect(
        v1->render_area,
        v1->pnl_x,
        v1->pnl_y,
        v1->pnl_wid + v1->pnl_x - 1,
        v1->pnl_hgt + v1->pnl_y - 1,
        v1->back_color);
      TDrawArea::Unlock(v1->render_area, aTpnl_tmlDraw_0);
    }
  }
  else
  {
    v11 = this->parent_panel;
    if ( v11 )
    {
      v12 = v1->bevel_type;
      if ( v12 < 2 || v12 > 7 )
      {
        if ( !v11->just_drawn )
          ((void (__stdcall *)(int))v11->vfptr->draw_rect)((int)&v1->clip_rect);
      }
      else
      {
        ((void (__stdcall *)(int))v11->vfptr->draw_rect2)((int)&v1->clip_rect);
      }
    }
  }
}

//----- (00520220) --------------------------------------------------------
void __thiscall Time_Line_Panel::draw_civilization_names(Time_Line_Panel *this)
{
  Time_Line_Panel *v1; // ebp@1
  HGDIOBJ v2; // eax@3
  RGE_Base_Game *v3; // ecx@3
  int v4; // esi@3
  RGE_Game_World *v5; // eax@3
  signed int v6; // edi@4
  char v7; // al@5
  signed int v8; // ST28_4@5
  RGE_Game_World *v9; // eax@7
  signed int v10; // ebx@8
  int y_line_segment_length; // ST2C_4@9
  float pop_total; // [sp+10h] [bp-144h]@3
  int v13; // [sp+14h] [bp-140h]@8
  int Y_line_pos; // [sp+1Ch] [bp-138h]@7
  int X_line_pos; // [sp+20h] [bp-134h]@7
  void *old_font; // [sp+24h] [bp-130h]@3
  char temp_str[100]; // [sp+28h] [bp-12Ch]@9
  char civ_str[100]; // [sp+8Ch] [bp-C8h]@9
  char name_str[100]; // [sp+F0h] [bp-64h]@9

  v1 = this;
  if ( this->timeline_flag )
  {
    SetTextColor(this->render_area->DrawDc, 0);
    if ( TDrawArea::GetDc(v1->render_area, aTpnl_tmlDraw_c) )
    {
      SetBkMode(v1->render_area->DrawDc, 1);
      v2 = SelectObject(v1->render_area->DrawDc, v1->body_font);
      v3 = rge_base_game;
      old_font = v2;
      v4 = 0;
      pop_total = 0.0;
      v5 = rge_base_game->world;
      if ( v5->player_num - 1 > 0 )
      {
        v6 = 1;
        do
        {
          v7 = TRIBE_History_Info::get_history_entry(*(TRIBE_History_Info **)&v5->players[v6][3].groups_used[62], 0, 0);
          v3 = rge_base_game;
          v8 = (unsigned __int8)v7;
          ++v4;
          v5 = rge_base_game->world;
          ++v6;
          pop_total = (double)v8 + pop_total;
        }
        while ( v4 < v5->player_num - 1 );
      }
      if ( pop_total != 0.0 )
      {
        X_line_pos = v1->X_start_line_pos + 3;
        Y_line_pos = v1->Y_start_line_pos;
        v9 = v3->world;
        if ( v9->player_num - 1 > 0 )
        {
          v13 = 0;
          v10 = 1;
          do
          {
            y_line_segment_length = (signed __int64)((double)(unsigned __int8)TRIBE_History_Info::get_history_entry(
                                                                                *(TRIBE_History_Info **)&v9->players[v10][3].groups_used[62],
                                                                                0,
                                                                                0)
                                                   / pop_total
                                                   * (double)v1->Y_line_max_length);
            (*(void (__stdcall **)(signed int, _DWORD, _DWORD, char *, signed int))&rge_base_game->vfptr->gap28[0])(
              105,
              rge_base_game->world->players[v10]->master_player_id,
              0,
              civ_str,
              100);
            strcpy(name_str, rge_base_game->world->players[v10]->name);
            sprintf(temp_str, aSS_1, name_str, civ_str);
            TextOutA(
              v1->render_area->DrawDc,
              X_line_pos,
              Y_line_pos + y_line_segment_length / 2 - v1->body_font_hgt / 2,
              temp_str,
              strlen(temp_str));
            ++v10;
            v9 = rge_base_game->world;
            Y_line_pos += y_line_segment_length;
            ++v13;
          }
          while ( v13 < v9->player_num - 1 );
        }
        SelectObject(v1->render_area->DrawDc, old_font);
        TDrawArea::ReleaseDc(v1->render_area, aTpnl_tmlDraw_c);
      }
    }
  }
}

//----- (005204A0) --------------------------------------------------------
void __thiscall Time_Line_Panel::draw_timeline(Time_Line_Panel *this)
{
  Time_Line_Panel *v1; // esi@1
  int v2; // ebx@3
  int v3; // eax@3
  int v4; // ebp@6
  RGE_Game_World *v5; // eax@6
  signed int v6; // edi@7
  RGE_Player *v7; // edx@8
  int v8; // ecx@10
  int v9; // edi@12
  int v10; // eax@12
  int v11; // eax@18
  int v12; // ebp@20
  RGE_Game_World *v13; // eax@20
  int v14; // ebx@21
  signed int v15; // edi@21
  int v16; // edx@22
  int v17; // edi@29
  signed __int64 v18; // rax@29
  int v19; // ecx@29
  RGE_Game_World *v20; // eax@33
  signed int v21; // ebx@34
  char *v22; // eax@36
  signed int v23; // eax@45
  int v24; // ebp@45
  int v25; // edi@45
  double v26; // st7@50
  double v27; // st7@52
  char v28; // bp@62
  int v29; // ebp@64
  int v30; // ecx@64
  int v31; // eax@66
  int v32; // edx@66
  bool v33; // sf@66
  unsigned __int8 v34; // of@66
  int v35; // eax@67
  char event; // [sp+13h] [bp-51h]@8
  float pop_total; // [sp+14h] [bp-50h]@6
  float temp_pop_num; // [sp+18h] [bp-4Ch]@8
  int time_slice; // [sp+1Ch] [bp-48h]@3
  float next_pop_total; // [sp+20h] [bp-44h]@19
  float float_remainder; // [sp+24h] [bp-40h]@33
  int cntr_droped_slice_rate; // [sp+28h] [bp-3Ch]@3
  int pop_sample_cntr; // [sp+2Ch] [bp-38h]@3
  int v44; // [sp+30h] [bp-34h]@34
  int v45; // [sp+34h] [bp-30h]@4
  int error_correction_drop_time_slice_rate; // [sp+38h] [bp-2Ch]@3
  int time_slice_cntr; // [sp+3Ch] [bp-28h]@3
  int v48; // [sp+40h] [bp-24h]@45
  int Y_line_total; // [sp+44h] [bp-20h]@33
  int cntr2; // [sp+48h] [bp-1Ch]@32
  int intermediate_x_pos; // [sp+4Ch] [bp-18h]@32
  int special_event_flag; // [sp+50h] [bp-14h]@6
  int error_correction_time_slice_thickness; // [sp+54h] [bp-10h]@3
  int time; // [sp+58h] [bp-Ch]@29
  int y_line_segment_length; // [sp+5Ch] [bp-8h]@8
  int temp_color; // [sp+60h] [bp-4h]@45

  v1 = this;
  if ( this->timeline_flag )
  {
    if ( TDrawArea::Lock(this->render_area, aTpnl_tmlDraw_t, 1) )
    {
      v2 = 0;
      v1->X_line_pos = v1->X_start_line_pos;
      v3 = v1->num_history_entries;
      pop_sample_cntr = 0;
      error_correction_time_slice_thickness = 0;
      error_correction_drop_time_slice_rate = 0;
      cntr_droped_slice_rate = 0;
      time_slice_cntr = 0;
      time_slice = 0;
      if ( v3 > 0 )
      {
        v45 = 1;
        while ( time_slice_cntr < v1->num_entries_page )
        {
          v4 = 0;
          pop_total = 0.0;
          special_event_flag = 0;
          v5 = rge_base_game->world;
          if ( v5->player_num - 1 > 0 )
          {
            v6 = 1;
            do
            {
              LOBYTE(y_line_segment_length) = TRIBE_History_Info::get_history_entry(
                                                *(TRIBE_History_Info **)&v5->players[v6][3].groups_used[62],
                                                0,
                                                v2);
              y_line_segment_length = (unsigned __int8)y_line_segment_length;
              v7 = rge_base_game->world->players[v6];
              temp_pop_num = (double)(unsigned __int8)y_line_segment_length;
              if ( TRIBE_History_Info::get_history_event(*(TRIBE_History_Info **)&v7[3].groups_used[62], v2, &event) )
                special_event_flag = 1;
              ++v6;
              v5 = rge_base_game->world;
              ++v4;
              v8 = v5->player_num;
              pop_total = temp_pop_num + pop_total;
            }
            while ( v4 < v8 - 1 );
          }
          if ( pop_total == 0.0 )
            return;
          v9 = (signed __int64)v1->time_slice_drop_rate;
          v10 = v9 * (1 - v45)
              + (unsigned __int64)(signed __int64)((double)v45 * v1->time_slice_drop_rate)
              - error_correction_drop_time_slice_rate;
          if ( !v1->drop_flag
            || special_event_flag
            || cntr_droped_slice_rate < v10
            || v45 - 1 >= v1->total_slices_to_drop )
          {
            v11 = v1->num_entries_page - 1;
            ++cntr_droped_slice_rate;
            ++time_slice_cntr;
            if ( v2 == v11 )
            {
              next_pop_total = pop_total;
            }
            else
            {
              v12 = 0;
              next_pop_total = 0.0;
              v13 = rge_base_game->world;
              if ( v13->player_num - 1 > 0 )
              {
                v14 = v2 + 1;
                v15 = 1;
                do
                {
                  LOBYTE(y_line_segment_length) = TRIBE_History_Info::get_history_entry(
                                                    *(TRIBE_History_Info **)&v13->players[v15][3].groups_used[62],
                                                    0,
                                                    v14);
                  y_line_segment_length = (unsigned __int8)y_line_segment_length;
                  ++v12;
                  v13 = rge_base_game->world;
                  ++v15;
                  v16 = v13->player_num - 1;
                  next_pop_total = (double)(unsigned __int8)y_line_segment_length + next_pop_total;
                }
                while ( v12 < v16 );
                v2 = time_slice;
              }
              if ( next_pop_total == 0.0 )
                return;
            }
            if ( pop_sample_cntr != v1->pop_reading_rate - 1 && v2 )
            {
              ++pop_sample_cntr;
            }
            else
            {
              Time_Line_Panel::add_pop_total_special_event(v1, v2, (signed __int64)pop_total, v1->X_line_pos, 1);
              pop_sample_cntr = 0;
            }
            time = v2 + 1;
            v17 = (signed __int64)((double)(v2 + 1) * v1->bar_thickness);
            v18 = (signed __int64)v1->bar_thickness;
            v19 = (v2 + 1) * v18;
            if ( v19 >= v17 - error_correction_time_slice_thickness )
              special_event_flag = (signed __int64)v1->bar_thickness;
            else
              special_event_flag = v18 + v17 - error_correction_time_slice_thickness++ - v19;
            cntr2 = 0;
            intermediate_x_pos = 0;
            if ( special_event_flag > 0 )
            {
              do
              {
                v1->Y_line_pos = v1->Y_start_line_pos;
                Y_line_total = 0;
                float_remainder = 0.0;
                v20 = rge_base_game->world;
                if ( v20->player_num - 1 > 0 )
                {
                  v44 = 0;
                  v21 = 1;
                  do
                  {
                    switch ( v20->players[v21]->color_table->id )
                    {
                      case 0:
                        v22 = (char *)12845056;
                        break;
                      case 1:
                        v22 = (char *)200;
                        break;
                      case 2:
                        v22 = (char *)60138;
                        break;
                      case 3:
                        v22 = (char *)2185868;
                        break;
                      case 4:
                        v22 = (char *)33023;
                        break;
                      case 5:
                        v22 = (char *)0x8000;
                        break;
                      case 6:
                        v22 = (char *)&pathSystem.MGP_openPaths[54981].total;
                        break;
                      case 7:
                        v22 = (char *)&pathSystem.MGP_openPaths[54973].total;
                        break;
                      default:
                        v22 = (char *)0xFFFFFF;
                        break;
                    }
                    LOBYTE(temp_color) = GetNearestPaletteIndex(v1->render_area->DrawSystem->Pal, (COLORREF)v22);
                    v23 = (unsigned __int8)TRIBE_History_Info::get_history_entry(
                                             *(TRIBE_History_Info **)&rge_base_game->world->players[v21][3].groups_used[62],
                                             0,
                                             time_slice);
                    v24 = v1->Y_line_max_length;
                    v48 = v24;
                    temp_pop_num = (double)v23;
                    v25 = (signed __int64)(temp_pop_num / pop_total * (double)v24);
                    y_line_segment_length = (signed __int64)(temp_pop_num / pop_total * (double)v24);
                    if ( temp_pop_num >= 1.0 && v25 < 1 )
                    {
                      v25 = 1;
                      y_line_segment_length = 1;
                    }
                    if ( LODWORD(v1->bar_thickness) != 1065353216 )
                    {
                      if ( time_slice == v1->num_entries_page - 1 )
                      {
                        v26 = temp_pop_num;
                      }
                      else
                      {
                        LOBYTE(v48) = TRIBE_History_Info::get_history_entry(
                                        *(TRIBE_History_Info **)&rge_base_game->world->players[v21][3].groups_used[62],
                                        0,
                                        time);
                        v48 = (unsigned __int8)v48;
                        v26 = (double)(unsigned __int8)v48;
                      }
                      v24 = v1->Y_line_max_length;
                      v48 = v1->Y_line_max_length;
                      v48 = (unsigned __int64)(signed __int64)(v26 / next_pop_total * (double)v48) - v25;
                      v27 = (double)intermediate_x_pos / v1->bar_thickness * (double)v48 + (double)y_line_segment_length;
                      v25 = (signed __int64)v27;
                      y_line_segment_length = (signed __int64)v27;
                      if ( temp_pop_num >= 1.0 && v25 < 1 )
                      {
                        v25 = 1;
                        y_line_segment_length = 1;
                      }
                      float_remainder = float_remainder + v27 - (double)y_line_segment_length;
                      if ( float_remainder > 1.0 )
                      {
                        ++v25;
                        float_remainder = float_remainder - 1.0;
                      }
                    }
                    if ( v44 == rge_base_game->world->player_num - 2 )
                    {
                      if ( v25 + Y_line_total > v24 )
                        v25 = v24 - Y_line_total;
                      if ( v25 + Y_line_total < v24 )
                        v25 = v24 - Y_line_total;
                    }
                    v28 = temp_color;
                    TDrawArea::DrawVertLine(v1->render_area, v1->X_line_pos, v1->Y_line_pos, v25, temp_color);
                    if ( !cntr2 )
                      Time_Line_Panel::record_special_event(
                        v1,
                        v44 + 1,
                        *(TRIBE_History_Info **)&rge_base_game->world->players[v21][3].groups_used[62],
                        v28,
                        time_slice,
                        v1->X_line_pos,
                        v1->Y_line_pos,
                        v25);
                    v29 = Y_line_total;
                    v30 = v44;
                    v1->Y_line_pos += v25;
                    ++v21;
                    v20 = rge_base_game->world;
                    Y_line_total = v25 + v29;
                    v44 = v30 + 1;
                  }
                  while ( v30 + 1 < v20->player_num - 1 );
                  v2 = time_slice;
                }
                v31 = cntr2 + 1;
                v32 = intermediate_x_pos + 1;
                v34 = __OFSUB__(cntr2 + 1, special_event_flag);
                v33 = cntr2 + 1 - special_event_flag < 0;
                ++v1->X_line_pos;
                cntr2 = v31;
                intermediate_x_pos = v32;
              }
              while ( v33 ^ v34 );
            }
          }
          else
          {
            cntr_droped_slice_rate = 0;
            ++v45;
            if ( v10 > v9 )
              ++error_correction_drop_time_slice_rate;
          }
          v35 = v1->num_history_entries;
          time_slice = ++v2;
          if ( v2 >= v35 )
            break;
        }
      }
    }
    TDrawArea::Unlock(v1->render_area, aTpnl_tmlDraw_t);
  }
}

//----- (00520AE0) --------------------------------------------------------
void __thiscall Time_Line_Panel::draw_icon(Time_Line_Panel *this, Special_Events *event_ptr, __int16 icon_number, char history_type)
{
  Time_Line_Panel *v4; // ebx@1
  int v5; // ebp@10
  int v6; // eax@10
  int v7; // ecx@10
  signed int v8; // edi@10
  int v9; // eax@14
  char black_color; // [sp+10h] [bp-38h]@1
  char temp_str[50]; // [sp+14h] [bp-34h]@2

  v4 = this;
  GetNearestPaletteIndex(this->render_area->DrawSystem->Pal, 0xFFFFFFu);
  black_color = GetNearestPaletteIndex(v4->render_area->DrawSystem->Pal, 0);
  switch ( event_ptr->event )
  {
    case 0:
      if ( !TPanel::get_string(4202, temp_str, 50) )
        goto LABEL_8;
      goto LABEL_7;
    case 1:
      if ( TPanel::get_string(4203, temp_str, 50) )
        goto LABEL_7;
      goto LABEL_8;
    case 2:
      if ( !TPanel::get_string(4204, temp_str, 50) )
        goto LABEL_8;
LABEL_7:
      sprintf(event_ptr->text1, aS_2, temp_str);
      break;
    case 4:
    case 5:
    case 7:
LABEL_8:
      event_ptr->text1[0] = 0;
      break;
    case 8:
      sprintf(temp_str, aLd1d, event_ptr->interger_value_1, event_ptr->interger_value_2);
      sprintf(event_ptr->text1, aS_2, temp_str);
      goto LABEL_10;
    case 3:
LABEL_10:
      sprintf(event_ptr->text1, aLd_0, event_ptr->pop_total);
      v5 = 0;
      v6 = 3 * event_ptr->time_slice;
      event_ptr->text_length1 = strlen(event_ptr->text1);
      v7 = 0;
      v8 = 5 * v6;
      if ( 5 * v6 > 59 )
      {
        v7 = v8 / 60;
        if ( v8 / 60 > 59 )
        {
          v5 = v7 / 60;
          v7 %= 60;
        }
      }
      sprintf(temp_str, a1ld02ld, v5, v7);
      sprintf(event_ptr->text2, aS_2, temp_str);
      event_ptr->text_length2 = strlen(event_ptr->text2);
      break;
    default:
      break;
  }
  v9 = Time_Line_Panel::calculate_icon_location(v4, event_ptr, icon_number, history_type);
  if ( event_ptr->event )
  {
    if ( event_ptr->event == 1 )
    {
      TDrawArea::DrawVertLine(
        v4->render_area,
        event_ptr->X_line_pos,
        event_ptr->Y_line_pos,
        event_ptr->intermediate_y_line_segment,
        black_color);
    }
    else if ( event_ptr->event == 2 )
    {
      TDrawArea::DrawVertLine(
        v4->render_area,
        event_ptr->X_line_pos,
        event_ptr->Y_line_pos,
        event_ptr->intermediate_y_line_segment,
        black_color);
    }
    else if ( v9 )
    {
      TShape::shape_draw(
        v4->special_events_pic,
        v4->render_area,
        event_ptr->start_x,
        event_ptr->start_y,
        icon_number,
        0,
        0);
    }
  }
  else
  {
    TDrawArea::DrawVertLine(
      v4->render_area,
      event_ptr->X_line_pos,
      event_ptr->Y_line_pos,
      event_ptr->intermediate_y_line_segment,
      black_color);
  }
}

//----- (00520D50) --------------------------------------------------------
void __thiscall Time_Line_Panel::draw_legend(Time_Line_Panel *this)
{
  Time_Line_Panel *v1; // esi@1
  TShape *v2; // ecx@1

  v1 = this;
  v2 = this->special_events_pic;
  if ( v2 )
  {
    if ( TShape::shape_count(v2) )
      TPanel::width((TPanel *)&v1->vfptr);
  }
}
