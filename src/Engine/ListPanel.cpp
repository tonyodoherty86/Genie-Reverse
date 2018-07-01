
//----- (004782A0) --------------------------------------------------------
void __thiscall TListPanel::TListPanel(TListPanel *this)
{
  TListPanel *v1; // esi@1

  v1 = this;
  TTextPanel::TTextPanel((TTextPanel *)&this->vfptr);
  v1->mouse_move_tolerance = 0;
  v1->mouse_scroll_last_time = 0;
  v1->mouse_scroll_up = 0;
  v1->mouse_scroll_down = 0;
  v1->auto_track = 0;
  v1->drawHighlightBar = 1;
  v1->vfptr = (TPanelVtbl *)&TListPanel::`vftable';
  v1->panel_type = 4;
  v1->bevel_type = 1;
  v1->mouse_scroll_interval = 50;
  v1->handle_mouse_input = 1;
  v1->spacer_size = 1;
  v1->border_size = 1;
}
// 571578: using guessed type int (__thiscall *TListPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00478310) --------------------------------------------------------
TListPanel *__thiscall TListPanel::`scalar deleting destructor'(TListPanel *this, unsigned int __flags)
{
  TListPanel *v2; // esi@1

  v2 = this;
  TListPanel::~TListPanel(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00478330) --------------------------------------------------------
void __thiscall TListPanel::~TListPanel(TListPanel *this)
{
  this->vfptr = (TPanelVtbl *)&TListPanel::`vftable';
  TTextPanel::~TTextPanel((TTextPanel *)&this->vfptr);
}
// 571578: using guessed type int (__thiscall *TListPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00478340) --------------------------------------------------------
void __thiscall TListPanel::set_auto_track(TListPanel *this, int auto_track_in)
{
  this->auto_track = auto_track_in;
}

//----- (00478350) --------------------------------------------------------
void __thiscall TListPanel::set_bevel_info(TListPanel *this, int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6)
{
  TListPanel *v8; // esi@1

  v8 = this;
  switch ( bevel_type_in )
  {
    case 3:
    case 6:
      this->spacer_size = 2;
      break;
    case 4:
    case 7:
      this->spacer_size = 3;
      break;
    default:
      this->spacer_size = 1;
      break;
  }
  TTextPanel::set_bevel_info((TTextPanel *)&this->vfptr, bevel_type_in, c1, c2, c3, c4, c5, c6);
  if ( !v8->border_size )
  {
    v8->border_size = 1;
    TTextPanel::calc_draw_info((TTextPanel *)&v8->vfptr, 1);
  }
}

//----- (004783F0) --------------------------------------------------------
int __thiscall TListPanel::handle_idle(TListPanel *this)
{
  TListPanel *v1; // esi@1
  unsigned int v2; // eax@3
  __int16 v3; // ax@5
  __int16 v5; // ax@8

  v1 = this;
  TPanel::handle_idle((TPanel *)&this->vfptr);
  if ( !v1->mouse_scroll_up && !v1->mouse_scroll_down )
    return 0;
  v2 = debug_timeGetTime();
  if ( v2 - v1->mouse_scroll_last_time < v1->mouse_scroll_interval )
    return 0;
  v1->mouse_scroll_last_time = v2;
  if ( !v1->mouse_scroll_up )
  {
    v5 = v1->bot_line;
    if ( v1->cur_line != v5 )
      TListPanel::scroll_cur_line(v1, 1, v5, 1);
    TListPanel::scroll_cur_line(v1, 2, 0, 1);
    return 0;
  }
  v3 = v1->top_line;
  if ( v1->cur_line != v3 )
    TListPanel::scroll_cur_line(v1, 1, v3, 1);
  TListPanel::scroll_cur_line(v1, 3, 0, 1);
  return 0;
}

//----- (004784A0) --------------------------------------------------------
int __thiscall TListPanel::mouse_move_action(TListPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TListPanel *v5; // esi@1
  int result; // eax@2
  __int16 v7; // ax@4

  v5 = this;
  if ( this->auto_track )
  {
    result = ((int (__stdcall *)(int, int))this->vfptr->is_inside)(x, y);
    if ( result )
    {
      v7 = (unsigned int)TListPanel::item_at(v5, x, y);
      if ( v7 >= v5->top_line && v7 <= v5->bot_line )
        TListPanel::goto_item(v5, x, y);
      result = 1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00478510) --------------------------------------------------------
int __thiscall TListPanel::mouse_left_down_action(TListPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TListPanel *v5; // esi@1

  v5 = this;
  TPanel::capture_mouse((TPanel *)&this->vfptr);
  TListPanel::goto_item(v5, x, y);
  return 1;
}

//----- (00478540) --------------------------------------------------------
int __thiscall TListPanel::mouse_left_move_action(TListPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TListPanel *v5; // esi@1
  int v6; // eax@1
  int v8; // ecx@5
  int v9; // ecx@8

  v5 = this;
  v6 = this->pnl_y;
  if ( y < v6 )
    goto LABEL_15;
  if ( y < v6 + this->pnl_hgt )
  {
    this->mouse_scroll_up = 0;
    this->mouse_scroll_down = 0;
    TListPanel::goto_item(this, x, y);
    return 1;
  }
  if ( y >= v6 )
  {
    if ( y <= this->pnl_hgt + v6 - 1 )
    {
      this->mouse_scroll_up = 0;
      this->mouse_scroll_down = 0;
    }
    else
    {
      v9 = this->mouse_scroll_down;
      v5->mouse_scroll_up = 0;
      if ( !v9 )
      {
        v5->mouse_scroll_down = 1;
        goto LABEL_10;
      }
    }
  }
  else
  {
LABEL_15:
    v8 = this->mouse_scroll_up;
    v5->mouse_scroll_down = 0;
    if ( !v8 )
    {
      v5->mouse_scroll_up = 1;
LABEL_10:
      v5->mouse_scroll_last_time = debug_timeGetTime() - v5->mouse_scroll_interval;
      return 1;
    }
  }
  return 1;
}

//----- (00478610) --------------------------------------------------------
int __thiscall TListPanel::mouse_left_up_action(TListPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TListPanel *v5; // esi@1
  TPanel *v6; // ecx@1
  __int16 v7; // ax@2

  v5 = this;
  TPanel::release_mouse((TPanel *)&this->vfptr);
  v6 = v5->parent_panel;
  v5->mouse_scroll_up = 0;
  v5->mouse_scroll_down = 0;
  if ( v6 )
  {
    v7 = v5->cur_line;
    if ( v7 > -1 && v7 < v5->num_lines )
      ((void (__stdcall *)(TListPanel *, signed int, _DWORD, _DWORD))v6->vfptr->action)(v5, 2, v7, 0);
  }
  return 1;
}

//----- (00478660) --------------------------------------------------------
int __thiscall TListPanel::mouse_left_dbl_click_action(TListPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TListPanel *v5; // esi@1
  TPanel *v6; // ecx@1
  __int16 v7; // ax@2

  v5 = this;
  TListPanel::goto_item(this, x, y);
  v6 = v5->parent_panel;
  if ( v6 )
  {
    v7 = v5->cur_line;
    if ( v7 > -1 && v7 < v5->num_lines )
      ((void (__stdcall *)(TListPanel *, signed int, _DWORD, _DWORD))v6->vfptr->action)(v5, 3, v7, 0);
  }
  return 1;
}

//----- (004786B0) --------------------------------------------------------
char *__thiscall TListPanel::item_at(TListPanel *this, int x, int y)
{
  int v3; // edx@1
  int v4; // esi@2
  int v5; // eax@4

  v3 = this->spacer_size;
  if ( v3 )
    v4 = this->text_hgt + 2 * v3 - 1;
  else
    v4 = this->text_hgt;
  v5 = y - this->border_size - this->pnl_y;
  LOWORD(this) = this->top_line;
  return (char *)this + (v5 - v3) / v4;
}

//----- (00478700) --------------------------------------------------------
void __thiscall TListPanel::goto_item(TListPanel *this, int x, int y)
{
  TListPanel *v3; // esi@1
  __int16 v4; // ax@1

  v3 = this;
  v4 = (unsigned int)TListPanel::item_at(this, x, y);
  TListPanel::scroll_cur_line(v3, 1, v4, 1);
}

//----- (00478730) --------------------------------------------------------
int __thiscall TListPanel::key_down_action(TListPanel *this, int key, __int16 count, int alt_key, int ctrl_key, int shift_key)
{
  int result; // eax@2
  TPanel *v7; // eax@8
  __int16 v8; // dx@9

  switch ( key )
  {
    case 40:
      TListPanel::scroll_cur_line(this, 2, 0, 1);
      result = 1;
      break;
    case 38:
      TListPanel::scroll_cur_line(this, 3, 0, 1);
      result = 1;
      break;
    case 34:
      TListPanel::scroll_cur_line(this, 4, 0, 1);
      result = 1;
      break;
    case 33:
      TListPanel::scroll_cur_line(this, 5, 0, 1);
      result = 1;
      break;
    case 36:
      TListPanel::scroll_cur_line(this, 6, 0, 1);
      result = 1;
      break;
    case 35:
      TListPanel::scroll_cur_line(this, 7, 0, 1);
      result = 1;
      break;
    case 13:
      v7 = this->parent_panel;
      if ( v7 )
      {
        v8 = this->cur_line;
        if ( v8 > -1 && v8 < this->num_lines )
          v7->vfptr->action(v7, (TPanel *)this, 3, v8, 0);
      }
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (00478850) --------------------------------------------------------
int __thiscall TListPanel::char_action(TListPanel *this, int key, __int16 count)
{
  TListPanel *v3; // ebx@1
  int v4; // eax@1
  TTextPanel::TextNode *v5; // esi@1
  signed int v6; // edi@1
  int v7; // ebp@1
  TTextPanel::TextNode *v8; // esi@6

  v3 = this;
  v4 = toupper(key);
  v5 = v3->list;
  v6 = 0;
  v7 = v4;
  if ( v5 )
  {
    while ( v6 <= v3->cur_line || toupper(*v5->text) != v7 )
    {
      v5 = v5->next_node;
      ++v6;
      if ( !v5 )
        goto LABEL_5;
    }
    goto LABEL_11;
  }
LABEL_5:
  if ( v3->cur_line > 0 )
  {
    v8 = v3->list;
    v6 = 0;
    if ( v8 )
    {
      while ( toupper(*v8->text) != v7 )
      {
        if ( ++v6 >= v3->cur_line )
          return 0;
        v8 = v8->next_node;
        if ( !v8 )
          return 0;
      }
LABEL_11:
      TListPanel::scroll_cur_line(v3, 1, v6, 1);
      return 1;
    }
  }
  return 0;
}

//----- (00478900) --------------------------------------------------------
int __thiscall TListPanel::action(TListPanel *this, TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2)
{
  return TTextPanel::action((TTextPanel *)&this->vfptr, from_panel, action_in, action_val1, action_val2);
}

//----- (00478920) --------------------------------------------------------
void __thiscall TListPanel::scroll_cur_line(TListPanel *this, char scroll_type, __int16 scroll_val, int update_scrollbar)
{
  TListPanel *v4; // esi@1
  __int16 v5; // ax@1
  __int16 v6; // di@1
  __int16 v7; // ax@6
  __int16 v8; // cx@8
  __int16 v9; // cx@11
  __int16 v10; // ax@13
  __int16 v11; // ax@14
  __int16 v12; // cx@17
  __int16 v13; // ax@20
  __int16 v14; // cx@25
  __int16 v15; // ax@39
  TPanel *v16; // ecx@40

  v4 = this;
  v5 = this->cur_line;
  v6 = this->cur_line;
  switch ( scroll_type )
  {
    case 1:
      this->cur_line = scroll_val;
      if ( scroll_val >= 0 )
      {
        if ( scroll_val > this->num_lines - 1 )
          this->cur_line = this->num_lines - 1;
      }
      else
      {
        this->cur_line = 0;
      }
      v7 = this->cur_line;
      if ( v7 >= this->top_line )
      {
        v8 = this->bot_line;
        if ( v7 > v8 )
          TTextPanel::scroll((TTextPanel *)&v4->vfptr, 0, v7 - v8, update_scrollbar);
      }
      else
      {
        TTextPanel::scroll((TTextPanel *)&this->vfptr, 1, v7, update_scrollbar);
      }
      break;
    case 2:
      if ( v5 < this->top_line || (v9 = this->bot_line, v5 > v9) )
      {
        v9 = v4->bot_line;
        v4->cur_line = v9;
      }
      v10 = v4->cur_line;
      if ( v10 < v9 )
      {
        v11 = v10 + 1;
        goto LABEL_38;
      }
      if ( v10 < v4->num_lines - 1 )
      {
        v4->cur_line = v10 + 1;
        TTextPanel::scroll((TTextPanel *)&v4->vfptr, 2, 0, update_scrollbar);
      }
      break;
    case 3:
      v12 = this->top_line;
      if ( v5 < v12 || v5 > v4->bot_line )
        v4->cur_line = v12;
      v13 = v4->cur_line;
      if ( v13 > v12 )
      {
        v11 = v13 - 1;
        goto LABEL_38;
      }
      if ( v13 > 0 )
      {
        v4->cur_line = v13 - 1;
        TTextPanel::scroll((TTextPanel *)&v4->vfptr, 3, 0, update_scrollbar);
      }
      break;
    case 4:
      if ( v5 < this->top_line || (v14 = this->bot_line, v5 > v14) )
      {
        v14 = v4->bot_line;
        v4->cur_line = v14;
      }
      if ( v4->cur_line != v14 )
        goto LABEL_35;
      TTextPanel::scroll((TTextPanel *)&v4->vfptr, 4, 0, update_scrollbar);
      goto LABEL_37;
    case 5:
      v14 = this->top_line;
      if ( v5 < v14 || v5 > v4->bot_line )
        v4->cur_line = v14;
      if ( v4->cur_line != v14 )
        goto LABEL_35;
      TTextPanel::scroll((TTextPanel *)&v4->vfptr, 5, 0, update_scrollbar);
      v4->cur_line = v4->top_line;
      break;
    case 6:
      TTextPanel::scroll((TTextPanel *)&this->vfptr, 6, 0, update_scrollbar);
      v14 = v4->top_line;
LABEL_35:
      v4->cur_line = v14;
      break;
    case 7:
      TTextPanel::scroll((TTextPanel *)&this->vfptr, 7, 0, update_scrollbar);
LABEL_37:
      v11 = v4->bot_line;
LABEL_38:
      v4->cur_line = v11;
      break;
    default:
      break;
  }
  v4->vfptr->set_redraw((TPanel *)v4, RedrawNormal);
  v15 = v4->cur_line;
  if ( v15 != v6 )
  {
    v16 = v4->parent_panel;
    if ( v16 )
    {
      if ( v15 > -1 && v15 < v4->num_lines )
        ((void (__stdcall *)(TListPanel *, signed int, _DWORD, _DWORD))v16->vfptr->action)(v4, 1, v15, 0);
    }
  }
}

//----- (00478BA0) --------------------------------------------------------
void __thiscall TListPanel::draw(TListPanel *this)
{
  TListPanel *v1; // esi@1
  __int16 v2; // bp@1
  TDrawArea *v3; // eax@1
  TPanelVtbl *v4; // ebx@4
  void *v5; // edi@4
  __int16 i; // bx@5
  HGDIOBJ old_font; // [sp+8h] [bp-8h]@5
  TPanelVtbl *v8; // [sp+Ch] [bp-4h]@4

  v1 = this;
  v2 = 0;
  v3 = this->render_area;
  this->need_redraw = 0;
  if ( v3 && this->visible && this->active )
  {
    TTextPanel::draw_background((TTextPanel *)&this->vfptr);
    v4 = v1->vfptr;
    v8 = v1->vfptr;
    v1->vfptr->draw_setup((TPanel *)v1, 0);
    v5 = TDrawArea::GetDc(v1->render_area, aPnl_lstDraw);
    if ( v5 )
    {
      SelectClipRgn(v5, v1->clip_rgn);
      old_font = SelectObject(v5, v1->font);
      SetBkMode(v5, 1);
      for ( i = v1->top_line; i <= v1->bot_line; ++v2 )
      {
        if ( v1->drawHighlightBar && (v1->have_focus || v1->mouse_captured) && v1->top_line + v2 == v1->cur_line )
          TTextPanel::draw_line((TTextPanel *)&v1->vfptr, v5, v2, i, v1->highlightTextColor1, v1->highlightTextColor2);
        else
          TTextPanel::draw_line((TTextPanel *)&v1->vfptr, v5, v2, i, v1->text_color1, v1->text_color2);
        ++i;
      }
      SelectObject(v5, old_font);
      SelectClipRgn(v5, 0);
      TDrawArea::ReleaseDc(v1->render_area, aPnl_lstDraw);
      v4 = v8;
    }
    TTextPanel::draw_border((TTextPanel *)&v1->vfptr);
    TListPanel::draw_highlight_bar(v1);
    v4->draw_finish((TPanel *)v1);
  }
}

//----- (00478CD0) --------------------------------------------------------
void __thiscall TListPanel::draw_highlight_bar(TListPanel *this)
{
  TListPanel *v1; // esi@1
  __int16 v2; // ax@2
  void *v3; // eax@4
  int v4; // ecx@6
  int v5; // edx@6
  int v6; // edi@6
  int v7; // eax@6
  int v8; // edx@6
  int v9; // ecx@6
  int v10; // eax@6
  int v11; // ebp@6
  tagRECT r; // [sp+4h] [bp-10h]@5

  v1 = this;
  if ( this->drawHighlightBar )
  {
    v2 = this->cur_line;
    if ( v2 >= this->top_line && v2 <= this->bot_line )
    {
      v3 = TDrawArea::GetDc(this->render_area, aPnl_lstDraw_hi);
      if ( v3 )
      {
        TTextPanel::calc_line_pos((TTextPanel *)&v1->vfptr, v3, v1->cur_line - v1->top_line, v1->cur_line, &r, 0);
        TDrawArea::ReleaseDc(v1->render_area, aPnl_lstDraw_hi);
        if ( TDrawArea::Lock(v1->render_area, aPnl_lstDraw_hi, 1) )
        {
          v4 = v1->pnl_x;
          v5 = v1->border_size;
          v6 = v5 + v4;
          v7 = v4 + v1->pnl_wid - v5;
          v8 = v1->spacer_size;
          v9 = r.top - v8;
          v10 = v7 - 1;
          v11 = r.bottom + v8;
          switch ( v1->bevel_type )
          {
            case 0:
            case 1:
              TDrawArea::DrawRect(v1->render_area, v6, v9, v10, v11, -1);
              break;
            case 5:
              TDrawArea::DrawBevel(v1->render_area, v6, v9, v10, v11, v1->bevel_color6, v1->bevel_color1);
              break;
            case 6:
              TDrawArea::DrawBevel2(
                v1->render_area,
                v6,
                v9,
                v10,
                v11,
                v1->bevel_color6,
                v1->bevel_color5,
                v1->bevel_color2,
                v1->bevel_color1);
              break;
            case 7:
              TDrawArea::DrawBevel3(
                v1->render_area,
                v6,
                v9,
                v10,
                v11,
                v1->bevel_color6,
                v1->bevel_color5,
                v1->bevel_color4,
                v1->bevel_color3,
                v1->bevel_color2,
                v1->bevel_color1);
              break;
            case 2:
              TDrawArea::DrawBevel(v1->render_area, v6, v9, v10, v11, v1->bevel_color1, v1->bevel_color6);
              break;
            case 3:
              TDrawArea::DrawBevel2(
                v1->render_area,
                v6,
                v9,
                v10,
                v11,
                v1->bevel_color1,
                v1->bevel_color2,
                v1->bevel_color5,
                v1->bevel_color6);
              break;
            case 4:
              TDrawArea::DrawBevel3(
                v1->render_area,
                v6,
                v9,
                v10,
                v11,
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
      }
      TDrawArea::Unlock(v1->render_area, aPnl_lstDraw_hi);
    }
  }
}

//----- (00478EE0) --------------------------------------------------------
void __thiscall TListPanel::setDrawHighlightBar(TListPanel *this, int v)
{
  this->drawHighlightBar = v;
}

//----- (00478EF0) --------------------------------------------------------
void __thiscall TListPanel::set_focus(TListPanel *this, int have_focus_in)
{
  TListPanel *v2; // esi@1
  TPanel *v3; // ecx@2
  __int16 v4; // ax@3

  v2 = this;
  TPanel::set_focus((TPanel *)&this->vfptr, have_focus_in);
  if ( v2->have_focus )
  {
    v3 = v2->parent_panel;
    if ( v3 )
    {
      v4 = v2->cur_line;
      if ( v4 > -1 && v4 < v2->num_lines )
        ((void (__stdcall *)(TListPanel *, signed int, _DWORD, _DWORD))v3->vfptr->action)(v2, 1, v4, 0);
    }
  }
}
