
//----- (004755C0) --------------------------------------------------------
void __thiscall TEditPanel::TEditPanel(TEditPanel *this)
{
  TEditPanel *v1; // esi@1

  v1 = this;
  TPanel::TPanel((TPanel *)&this->vfptr);
  v1->edit_wnd = 0;
  v1->text = 0;
  v1->fixed_len = 0;
  v1->brush = 0;
  v1->old_sub_wnd_proc = 0;
  v1->text_color1 = 0;
  v1->text_color2 = 0;
  v1->highlight_text_color1 = 0;
  v1->highlight_text_color2 = 0;
  v1->back_color = 0;
  v1->sel_len = 0;
  v1->bevel_color1 = 0;
  v1->bevel_color2 = 0;
  v1->bevel_color3 = 0;
  v1->bevel_color4 = 0;
  v1->bevel_color5 = 0;
  v1->bevel_color6 = 0;
  v1->bevel_size = 0;
  v1->imc = 0;
  v1->enable_ime = 0;
  v1->turn_ime_on = 0;
  v1->vfptr = (TPanelVtbl *)&TEditPanel::`vftable';
  v1->handle_mouse_input = 1;
  v1->hidden = 1;
  v1->bevel_type = 1;
}
// 5713A8: using guessed type int (__thiscall *TEditPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00475670) --------------------------------------------------------
TEditPanel *__thiscall TEditPanel::`vector deleting destructor'(TEditPanel *this, unsigned int __flags)
{
  TEditPanel *v2; // esi@1

  v2 = this;
  TEditPanel::~TEditPanel(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00475770) --------------------------------------------------------
int __thiscall TEditPanel::setup(TEditPanel *this, TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, void *font_in, __int16 fixed_len_in, char *text_in, TEditPanel::FormatType format_in, int auto_sel_in)
{
  TEditPanel *v12; // esi@1
  __int16 v13; // ax@1
  int result; // eax@3
  HWND v15; // eax@4
  LONG v16; // eax@6
  void *v17; // ST24_4@6
  char *v18; // eax@6
  WPARAM v19; // eax@11
  TEditPanel::FormatType v20; // ecx@13

  v12 = this;
  this->format = format_in;
  v13 = fixed_len_in;
  if ( fixed_len_in > 0 )
    v13 = fixed_len_in + 1;
  this->fixed_len = v13;
  this->font = font_in;
  this->auto_sel = auto_sel_in;
  result = TPanel::setup((TPanel *)&this->vfptr, render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 255);
  if ( result )
  {
    v15 = CreateWindowExA(
            0,
            aEdit,
            0,
            v12->format != 7 ? 1073741952 : 1075839044,
            x_in + 1,
            y_in + 1,
            wid_in - 2,
            hgt_in - 2,
            render_area_in->Wnd,
            (HMENU)1,
            v12->render_area->DrawSystem->Inst,
            0);
    v12->edit_wnd = v15;
    if ( v15 )
    {
      SetWindowLongA(v15, -21, (LONG)v12);
      v16 = GetWindowLongA(v12->edit_wnd, -4);
      v17 = v12->edit_wnd;
      v12->old_sub_wnd_proc = (int (__stdcall *)())v16;
      SetWindowLongA(v17, -4, (LONG)pnl_sub_wnd_proc);
      v18 = (char *)calloc(v12->fixed_len + 2, 1u);
      v12->text = v18;
      if ( v18 )
      {
        *v18 = 0;
        v12->text_len = 0;
        if ( text_in && *text_in )
          TEditPanel::set_text(v12, text_in);
        v12->brush = GetStockObject(4);
        v12->text_color1 = 0xFFFFFF;
        v12->highlight_text_color1 = 0xFFFFFF;
        v19 = (WPARAM)v12->font;
        v12->back_color = 0;
        v12->text_color2 = 0;
        v12->highlight_text_color2 = 0;
        if ( v19 )
          SendMessageA(v12->edit_wnd, 0x30u, v19, 0);
        v20 = v12->format;
        v12->draw_format = 0x2000;
        result = 1;
        v12->draw_format = v20 != 7 ? 8224 : 8208;
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
  }
  return result;
}

//----- (00475930) --------------------------------------------------------
int __stdcall pnl_sub_wnd_proc(void *wnd, unsigned int msg, unsigned int wparam, int lparam)
{
  TEditPanel *v4; // eax@1
  int result; // eax@2

  v4 = (TEditPanel *)GetWindowLongA(wnd, -21);
  if ( v4 )
    result = TEditPanel::sub_wnd_proc(v4, wnd, msg, wparam, lparam);
  else
    result = 0;
  return result;
}

//----- (00475970) --------------------------------------------------------
void __thiscall TEditPanel::set_text(TEditPanel *this, char *text_in)
{
  TEditPanel *v2; // esi@1

  v2 = this;
  if ( this->edit_wnd )
  {
    if ( text_in )
    {
      memset(this->text, 0, this->fixed_len);
      strncpy(this->text, text_in, this->fixed_len - 1);
      v2->text[v2->fixed_len - 1] = 0;
      v2->text_len = strlen(v2->text);
    }
    else
    {
      *this->text = 0;
      this->text_len = 0;
    }
    SetWindowTextA(v2->edit_wnd, v2->text);
    v2->sel_len = 0;
  }
  v2->vfptr->set_redraw((TPanel *)v2, RedrawNormal);
}

//----- (00475A30) --------------------------------------------------------
void __thiscall TEditPanel::update_text(TEditPanel *this)
{
  TEditPanel *v1; // esi@1
  void *v2; // eax@1
  char *v3; // edx@2
  int v4; // eax@2
  void *v5; // ST00_4@4
  unsigned int end; // [sp+4h] [bp-8h]@4
  unsigned int start; // [sp+8h] [bp-4h]@4

  v1 = this;
  v2 = this->edit_wnd;
  if ( v2 )
  {
    GetWindowTextA(v2, this->text, this->fixed_len + 1);
    v3 = v1->text;
    v4 = v1->fixed_len;
    v1->text_len = strlen(v1->text);
    v3[v4 - 1] = 0;
    if ( v1->text_len > v1->fixed_len - 1 )
    {
      SetWindowTextA(v1->edit_wnd, v1->text);
      MessageBeep(0xFFFFFFFF);
    }
    v5 = v1->edit_wnd;
    start = 0;
    end = 0;
    SendMessageA(v5, 0xB0u, (WPARAM)&start, (LPARAM)&end);
    v1->sel_len = end - start;
  }
}

//----- (00475AF0) --------------------------------------------------------
char *__thiscall TEditPanel::get_text(TEditPanel *this)
{
  TEditPanel *v1; // esi@1

  v1 = this;
  TEditPanel::update_text(this);
  return v1->text;
}

//----- (00475B00) --------------------------------------------------------
char *__thiscall TEditPanel::get_input_buffer(TEditPanel *this)
{
  TEditPanel *v1; // esi@1

  v1 = this;
  TEditPanel::update_text(this);
  return v1->text;
}

//----- (00475B10) --------------------------------------------------------
char *__thiscall TEditPanel::currentLine(TEditPanel *this)
{
  TEditPanel *v1; // esi@1

  v1 = this;
  TEditPanel::update_text(this);
  return v1->text;
}

//----- (00475B20) --------------------------------------------------------
void __thiscall TEditPanel::set_active(TEditPanel *this, int activ_in)
{
  TEditPanel *v2; // esi@1
  void *v3; // eax@1

  v2 = this;
  TPanel::set_active((TPanel *)&this->vfptr, activ_in);
  v3 = v2->edit_wnd;
  if ( v3 )
  {
    if ( !v2->active )
    {
      ShowWindow(v3, 0);
      v2->hidden = 1;
    }
  }
}

//----- (00475B60) --------------------------------------------------------
void __thiscall TEditPanel::set_focus(TEditPanel *this, int have_focus_in)
{
  TEditPanel *v2; // esi@1
  int v3; // edi@1
  HWND v4; // eax@2
  void *v5; // ecx@2
  HIMC v6; // eax@7
  HIMC v7; // eax@10
  void *v8; // eax@21
  void *v9; // eax@27

  v2 = this;
  v3 = this->have_focus;
  TPanel::set_focus((TPanel *)&this->vfptr, have_focus_in);
  if ( v2->edit_wnd )
  {
    v4 = GetFocus();
    v5 = v2->edit_wnd;
    if ( v2->have_focus )
    {
      if ( v4 != v5 )
        SetFocus(v2->edit_wnd);
      if ( !v2->imc )
      {
        if ( v2->enable_ime )
          v6 = ImmGetContext(v2->edit_wnd);
        else
          v6 = ImmAssociateContext(v2->edit_wnd, 0);
        v2->imc = v6;
      }
      v7 = v2->imc;
      if ( v7 && v2->enable_ime )
      {
        if ( v2->turn_ime_on )
          imc_retval = ImmSetOpenStatus(v7, 1);
        else
          imc_retval = ImmSetOpenStatus(v7, 0);
      }
    }
    else if ( v4 == v5 && v4 != v2->render_area->Wnd )
    {
      SetFocus(v2->render_area->Wnd);
    }
  }
  if ( v3 && !v2->have_focus )
  {
    TEditPanel::update_text(v2);
    v2->vfptr->set_redraw((TPanel *)v2, RedrawNormal);
  }
  v8 = v2->edit_wnd;
  if ( v8 && v2->have_focus && !v3 && v2->auto_sel )
    SendMessageA(v8, 0xB1u, 0, -1);
  if ( !tab_key )
  {
    v9 = v2->edit_wnd;
    if ( v9 )
    {
      if ( !v2->have_focus && !v2->hidden )
      {
        ShowWindow(v9, 0);
        v2->hidden = 1;
      }
    }
  }
  if ( v2->have_focus )
    ignore_next_char = 0;
}
// 86B23C: using guessed type int imc_retval;

//----- (00475CC0) --------------------------------------------------------
void __thiscall TEditPanel::set_rect(TEditPanel *this, int x_in, int y_in, int wid_in, int hgt_in)
{
  TEditPanel *v5; // esi@1
  void *v6; // edi@1
  BOOL v7; // edx@5
  int v8; // ecx@8
  int v9; // eax@8
  int v10; // edx@9
  int v11; // ecx@9
  int v12; // edi@9
  int v13; // edx@9
  int v14; // eax@9
  int v15; // edx@10
  int v16; // ecx@10
  int v17; // edx@10
  int v18; // ecx@10

  v5 = this;
  TPanel::set_rect((TPanel *)&this->vfptr, x_in, y_in, wid_in, hgt_in);
  v6 = v5->edit_wnd;
  if ( v6 )
  {
    v7 = !v5->hidden && v5->visible && v5->active;
    MoveWindow(
      v6,
      v5->bevel_size + v5->pnl_x,
      v5->bevel_size + v5->pnl_y,
      v5->pnl_wid - 2 * v5->bevel_size - 1,
      v5->pnl_hgt - 2 * v5->bevel_size - 1,
      v7);
  }
  v8 = v5->render_rect.left;
  v9 = v5->bevel_size;
  if ( v5->format == 7 )
  {
    v10 = v8 + v9 + 1;
    v11 = v9 + v5->render_rect.top;
    v5->draw_rect.left = v10;
    v5->draw_rect.top = v11;
    v12 = v9;
    v13 = v5->render_rect.right - v9 - GetSystemMetrics(21) - 1;
    v14 = v5->render_rect.bottom - v12;
    v5->draw_rect.right = v13;
    v5->draw_rect.bottom = v14;
  }
  else
  {
    v15 = v8 + v9 + 8;
    v16 = v9 + v5->render_rect.top;
    v5->draw_rect.left = v15;
    v17 = v5->render_rect.right;
    v5->draw_rect.top = v16;
    v18 = v5->render_rect.bottom - v9;
    v5->draw_rect.right = v17 - v9;
    v5->draw_rect.bottom = v18;
  }
}

//----- (00475DD0) --------------------------------------------------------
void __thiscall TEditPanel::set_redraw(TEditPanel *this, TPanel::RedrawMode redraw_mode)
{
  TEditPanel *v2; // esi@1
  void *v3; // eax@3

  v2 = this;
  TPanel::set_redraw((TPanel *)&this->vfptr, RedrawNormal);
  if ( v2->active )
  {
    if ( redraw_mode )
    {
      v3 = v2->edit_wnd;
      if ( v3 )
      {
        if ( !v2->hidden )
          InvalidateRect(v3, 0, 1);
      }
    }
  }
}

//----- (00475E10) --------------------------------------------------------
void __thiscall TEditPanel::set_text_color(TEditPanel *this, unsigned int val1, unsigned int val2)
{
  TPanelVtbl *v3; // eax@1

  this->text_color1 = val1;
  v3 = this->vfptr;
  this->text_color2 = val2;
  ((void (__stdcall *)(signed int))v3->set_redraw)(1);
}

//----- (00475E50) --------------------------------------------------------
void __thiscall TEditPanel::set_bevel_info(TEditPanel *this, int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6)
{
  TEditPanel *v8; // esi@1
  TPanelVtbl *v9; // edi@6

  v8 = this;
  this->bevel_color1 = c1;
  this->bevel_color2 = c2;
  this->bevel_type = bevel_type_in;
  this->bevel_color3 = c3;
  this->bevel_color4 = c4;
  this->bevel_color5 = c5;
  this->bevel_color6 = c6;
  switch ( bevel_type_in )
  {
    case 1:
    case 2:
    case 5:
      this->bevel_size = 1;
      break;
    case 3:
    case 6:
      this->bevel_size = 2;
      break;
    case 4:
    case 7:
      this->bevel_size = 3;
      break;
    default:
      this->bevel_size = 0;
      break;
  }
  v9 = this->vfptr;
  this->vfptr->set_rect((TPanel *)this, this->pnl_x, this->pnl_y, this->pnl_wid, this->pnl_hgt);
  v9->set_redraw((TPanel *)v8, RedrawNormal);
}

//----- (00475F20) --------------------------------------------------------
void __thiscall TEditPanel::set_ime_info(TEditPanel *this, int enable_ime_in, int turn_ime_on_in)
{
  this->enable_ime = enable_ime_in;
  this->turn_ime_on = turn_ime_on_in;
}

//----- (00475F40) --------------------------------------------------------
void *__thiscall TEditPanel::wnd_proc(TEditPanel *this, void *hwnd, unsigned int msg, unsigned int wParam, int lParam)
{
  TEditPanel *v5; // esi@1
  void *v6; // eax@1

  v5 = this;
  v6 = this->edit_wnd;
  if ( !v6 || !this->active || !this->visible || this->hidden )
    return (void *)TPanel::wnd_proc((TPanel *)&v5->vfptr, hwnd, msg, wParam, lParam);
  if ( msg != 7 )
  {
    if ( msg == 273 )
    {
      if ( (void *)lParam == v6 && HIWORD(wParam) == 1024 )
        InvalidateRect(v6, 0, 1);
    }
    else if ( msg == 307 && this->brush && (void *)(unsigned __int16)lParam == v6 )
    {
      SetBkColor((HDC)wParam, this->back_color);
      SetBkMode((HDC)wParam, 2);
      SetTextColor((HDC)wParam, v5->highlight_text_color1);
      return v5->brush;
    }
    return (void *)TPanel::wnd_proc((TPanel *)&v5->vfptr, hwnd, msg, wParam, lParam);
  }
  return (void *)TPanel::wnd_proc((TPanel *)&this->vfptr, hwnd, 7u, wParam, lParam);
}

//----- (00476040) --------------------------------------------------------
int __thiscall TEditPanel::sub_wnd_proc(TEditPanel *this, void *hwnd, unsigned int msg, unsigned int wParam, int lParam)
{
  unsigned int v5; // ebx@1
  unsigned int v6; // ebp@1
  TEditPanel *v7; // esi@1
  void *v8; // edi@10
  int result; // eax@10
  TPanel *v10; // ecx@14
  unsigned int v11; // edi@15
  int v12; // ebp@18
  SHORT v13; // ax@18
  TPanelVtbl *v14; // edx@18
  void *v15; // eax@37
  LRESULT v16; // edi@40
  int v17; // edi@50
  int v18; // ebx@50
  TPanel *v19; // eax@50
  unsigned int old_start; // [sp+10h] [bp-1Ch]@37
  unsigned int new_end; // [sp+14h] [bp-18h]@37
  unsigned int old_end; // [sp+18h] [bp-14h]@37
  tagRECT rect; // [sp+1Ch] [bp-10h]@10

  v5 = lParam;
  v6 = msg;
  v7 = this;
  if ( this->edit_wnd && this->active && this->visible && !this->hidden )
  {
    if ( msg > 0x14 )
    {
      if ( msg <= 0x200 )
      {
        if ( msg != 512 )
        {
          switch ( msg )
          {
            case 0x100u:
              v10 = this->parent_panel;
              if ( !v10 )
              {
                v11 = wParam;
                if ( wParam != 27 )
                  goto LABEL_37;
                SendMessageA(v7->edit_wnd, 0xC7u, 0, 0);
                return 0;
              }
              v11 = wParam;
              if ( ((int (__stdcall *)(void *, unsigned int, unsigned int, int))v10->vfptr->wnd_proc)(
                     hwnd,
                     msg,
                     wParam,
                     lParam) )
              {
                return 0;
              }
              if ( v11 == 9 )
              {
                v12 = GetKeyState(18) < 0;
                wParam = GetKeyState(17) < 0;
                v13 = GetKeyState(16);
                v14 = v7->vfptr;
                tab_key = 1;
                v14->handle_key_down((TPanel *)v7, 9, v5, v12, wParam, v13 < 0);
                tab_key = 0;
                return 0;
              }
              if ( v11 == 13 )
              {
                ((void (__stdcall *)(TEditPanel *, _DWORD, _DWORD, _DWORD))v7->parent_panel->vfptr->action)(v7, 0, 0, 0);
                return 0;
              }
              if ( v11 == 27 )
              {
                if ( ((int (__stdcall *)(TEditPanel *, signed int, _DWORD, _DWORD))v7->parent_panel->vfptr->action)(
                       v7,
                       1,
                       0,
                       0) )
                {
LABEL_33:
                  result = 0;
                }
                else
                {
                  SendMessageA(v7->edit_wnd, 0xC7u, 0, 0);
                  result = 0;
                }
                return result;
              }
              break;
            case 0x101u:
              if ( wParam != 9 )
                goto LABEL_36;
              return 0;
            case 0x102u:
              result = TEditPanel::verify_char(this, wParam);
              if ( result )
                goto LABEL_36;
              return result;
            case 0x104u:
              if ( !this->imc || !this->enable_ime )
              {
                SetFocus(this->render_area->Wnd);
                PostMessageA(v7->render_area->Wnd, v6, wParam, lParam);
              }
              goto LABEL_33;
            default:
              goto LABEL_36;
          }
          goto LABEL_37;
        }
        if ( !rge_base_game->windows_mouse )
        {
          MouseCursorInChildContol = 1;
          RGE_Base_Game::mouse_off(rge_base_game);
        }
      }
    }
    else if ( msg == 20 )
    {
      if ( this->brush )
      {
        v8 = (void *)wParam;
        SelectObject((HDC)wParam, this->brush);
        GetClientRect(hwnd, &rect);
        FillRect(v8, &rect, v7->brush);
        return 1;
      }
    }
    else if ( msg == 15 )
    {
      InvalidateRect(hwnd, 0, 1);
    }
  }
LABEL_36:
  v11 = wParam;
LABEL_37:
  v15 = v7->edit_wnd;
  old_start = 0;
  old_end = 0;
  msg = 0;
  new_end = 0;
  if ( v15 && v6 != 176 )
  {
    lParam = 1;
    SendMessageA(v15, 0xB0u, (WPARAM)&old_start, (LPARAM)&old_end);
  }
  else
  {
    lParam = 0;
  }
  v16 = CallWindowProcA((WNDPROC)v7->old_sub_wnd_proc, hwnd, v6, v11, v5);
  if ( lParam )
  {
    SendMessageA(v7->edit_wnd, 0xB0u, (WPARAM)&msg, (LPARAM)&new_end);
    if ( msg != old_start || new_end != old_end )
    {
      InvalidateRect(v7->edit_wnd, 0, 1);
      UpdateWindow(v7->edit_wnd);
    }
  }
  if ( v6 == 770 )
    TEditPanel::update_text(v7);
  if ( v6 == 513 || v6 == 514 || v6 == 516 || v6 == 517 )
  {
    v17 = (unsigned __int16)v5 + v7->pnl_x;
    v18 = v7->pnl_y + (v5 >> 16);
    v19 = TPanelSystem::currentPanel(&panel_system);
    v16 = v19->vfptr->wnd_proc(v19, v7->render_area->Wnd, v6, wParam, (unsigned __int16)v17 | (v18 << 16));
  }
  return v16;
}
// 62C4C4: using guessed type int MouseCursorInChildContol;

//----- (00476440) --------------------------------------------------------
int __thiscall TEditPanel::verify_char(TEditPanel *this, int key)
{
  TEditPanel *v2; // esi@1
  signed int v4; // eax@16
  bool v5; // zf@16
  bool v6; // zf@22

  v2 = this;
  if ( ignore_next_char )
  {
    ignore_next_char = 0;
    return 0;
  }
  if ( key == 9 )
    return 0;
  if ( key == 13 && this->format != 7 )
    return 0;
  if ( key != 8 )
  {
    TEditPanel::update_text(this);
    if ( !v2->sel_len )
    {
      if ( v2->text_len >= v2->fixed_len - 1 )
      {
        MessageBeep(0xFFFFFFFF);
        return 0;
      }
      if ( v2->text_len >= v2->fixed_len - 2 && IsDBCSLeadByte(key) )
      {
        ignore_next_char = 1;
        MessageBeep(0xFFFFFFFF);
        return 0;
      }
    }
    switch ( v2->format )
    {
      case 8:
        v4 = v2->text_len;
        v5 = v4 == 2;
        if ( v4 >= 2 )
          goto LABEL_20;
        if ( key >= 48 && key <= 57 )
          return 1;
        v5 = v4 == 2;
LABEL_20:
        if ( !v5 || key != 48 )
          goto LABEL_49;
        v6 = _mbscmp(a10, (const unsigned __int8 *)v2->text) == 0;
        goto LABEL_31;
      case 1:
      case 2:
      case 3:
        TEditPanel::update_text(v2);
        if ( key >= 48 && key <= 57 || key == 45 && !*v2->text && v2->format != 3 )
          return 1;
        if ( key != 46 || !_mbschr((const unsigned __int8 *)v2->text, 0x2Eu) )
          goto LABEL_49;
        v6 = v2->format == 1;
LABEL_31:
        if ( v6 )
          return 1;
        MessageBeep(0xFFFFFFFF);
        return 0;
      case 4:
      case 5:
        TEditPanel::update_text(v2);
        if ( key == 46 )
        {
          if ( v2->format != 4 || _mbschr((const unsigned __int8 *)v2->text, 0x2Eu) )
            goto LABEL_49;
        }
        else
        {
          if ( key == 92 || key == 58 )
            goto LABEL_49;
LABEL_42:
          if ( key == 47 || key == 34 || key == 42 || key == 63 || key == 62 || key == 60 || key == 124 )
          {
LABEL_49:
            MessageBeep(0xFFFFFFFF);
            return 0;
          }
        }
        break;
      case 6:
        TEditPanel::update_text(v2);
        if ( key != 58 || v2->text_len == 1 )
          goto LABEL_42;
        goto LABEL_49;
      default:
        return 1;
    }
  }
  return 1;
}

//----- (00476680) --------------------------------------------------------
void __thiscall TEditPanel::draw(TEditPanel *this)
{
  TEditPanel *v1; // esi@1
  int v2; // eax@1
  TPanelVtbl *v3; // ebx@2
  int v4; // ST24_4@5
  TPanel *v5; // ecx@6
  signed int v6; // eax@7
  void *v7; // eax@26
  int v8; // ecx@28
  void *v9; // eax@33
  void *v10; // edi@33
  HGDIOBJ old_font; // ST38_4@34
  int v12; // eax@34
  int v13; // edx@34
  int v14; // ecx@34
  UINT v15; // edx@34
  TPanelVtbl *v16; // [sp+Ch] [bp-14h]@2
  tagRECT r; // [sp+10h] [bp-10h]@34

  v1 = this;
  v2 = this->visible;
  this->need_redraw = 0;
  if ( v2 )
  {
    v3 = this->vfptr;
    v16 = this->vfptr;
    ((void (__stdcall *)(_DWORD))this->vfptr->draw_setup)(0);
    if ( v1->brush && v1->active && v1->have_focus )
    {
      v4 = (unsigned __int8)GetNearestPaletteIndex(v1->render_area->DrawSystem->Pal, v1->back_color);
      TDrawArea::Clear(v1->render_area, &v1->clip_rect, v4);
    }
    else
    {
      v5 = v1->parent_panel;
      if ( v5 )
      {
        v6 = v1->bevel_type;
        if ( v6 < 2 || v6 > 7 )
        {
          if ( !v5->just_drawn )
            ((void (__stdcall *)(int))v5->vfptr->draw_rect)((int)&v1->clip_rect);
        }
        else
        {
          ((void (__stdcall *)(int))v5->vfptr->draw_rect2)((int)&v1->clip_rect);
        }
      }
      else
      {
        TDrawArea::Clear(v1->render_area, &v1->clip_rect, v1->color);
      }
    }
    if ( v1->bevel_type )
    {
      if ( TDrawArea::Lock(v1->render_area, aPnl_editDraw, 1) )
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
              v1->bevel_color1);
            break;
          case 2:
            TDrawArea::DrawBevel(
              v1->render_area,
              v1->pnl_x,
              v1->pnl_y,
              v1->pnl_wid + v1->pnl_x - 1,
              v1->pnl_hgt + v1->pnl_y - 1,
              v1->bevel_color6,
              v1->bevel_color1);
            break;
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
            break;
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
            break;
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
            break;
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
      TDrawArea::Unlock(v1->render_area, aPnl_editDraw);
    }
    v7 = v1->edit_wnd;
    if ( v7 && v1->active )
    {
      v8 = v1->hidden;
      if ( v1->have_focus )
      {
        if ( v8 )
        {
          ShowWindow(v7, 5);
          InvalidateRect(v1->edit_wnd, 0, 1);
          v1->hidden = 0;
          v3->draw_finish((TPanel *)v1);
          return;
        }
      }
      else
      {
        if ( !v8 )
        {
          ShowWindow(v7, 0);
          v1->hidden = 1;
        }
        v9 = TDrawArea::GetDc(v1->render_area, aPnl_editDraw);
        v10 = v9;
        if ( v9 )
        {
          SelectClipRgn(v9, v1->clip_rgn);
          old_font = SelectObject(v10, v1->font);
          SetBkMode(v10, 1);
          SetTextColor(v10, v1->text_color2);
          v12 = v1->draw_rect.right;
          v13 = v1->draw_rect.top + 1;
          r.left = v1->draw_rect.left - 1;
          v14 = v1->draw_rect.bottom;
          r.top = v13;
          v15 = v1->draw_format;
          r.right = v12 - 1;
          r.bottom = v14 + 1;
          DrawTextExA(v10, v1->text, -1, &r, v15, 0);
          SetTextColor(v10, v1->text_color1);
          DrawTextExA(v10, v1->text, -1, &v1->draw_rect, v1->draw_format, 0);
          SelectObject(v10, old_font);
          SelectClipRgn(v10, 0);
          TDrawArea::ReleaseDc(v1->render_area, aPnl_editDraw);
          v3 = v16;
        }
      }
    }
    v3->draw_finish((TPanel *)v1);
  }
}

//----- (00476A60) --------------------------------------------------------
int __thiscall TEditPanel::is_blank(TEditPanel *this)
{
  TEditPanel *v1; // esi@1
  unsigned __int8 *v2; // esi@1

  v1 = this;
  TEditPanel::update_text(this);
  v2 = (unsigned __int8 *)v1->text;
  if ( v2 && *v2 )
  {
    while ( *v2 )
    {
      if ( !_ismbcspace(*v2) )
        return 0;
      v2 = _mbsinc(v2);
    }
  }
  return 1;
}

//----- (00476AB0) --------------------------------------------------------
char *__thiscall TEditPanel::get_trimmed_str(TEditPanel *this, char *str, int str_len)
{
  TEditPanel *v3; // esi@1
  unsigned __int8 *v4; // esi@1
  const unsigned __int8 *v5; // edi@1
  char temp_str[256]; // [sp+Ch] [bp-100h]@1

  v3 = this;
  TEditPanel::update_text(this);
  memset(temp_str, 0, sizeof(temp_str));
  strcpy(temp_str, v3->text);
  v4 = (unsigned __int8 *)str;
  memset(str, 0, str_len);
  v5 = (const unsigned __int8 *)temp_str;
  if ( _ismbcspace((unsigned __int8)temp_str[0]) )
  {
    do
      v5 = _mbsinc(v5);
    while ( _ismbcspace(*v5) );
  }
  for ( ; *v5; v5 = _mbsinc(v5) )
  {
    _mbsncpy(v4, v5, 1u);
    v4 = _mbsinc(v4);
  }
  do
  {
    *v4 = 0;
    if ( (char *)v4 == str )
      break;
    v4 = _mbsdec((const unsigned __int8 *)str, v4);
  }
  while ( _ismbcspace(*v4) );
  return str;
}

//----- (00476BB0) --------------------------------------------------------
void __thiscall TEditPanel::handle_reactivate(TEditPanel *this)
{
  TEditPanel *v1; // esi@1
  HWND v2; // eax@3
  void *v3; // esi@3

  v1 = this;
  if ( this->edit_wnd && this->have_focus )
  {
    v2 = GetFocus();
    v3 = v1->edit_wnd;
    if ( v2 != v3 )
      SetFocus(v3);
  }
}

//----- (00476BE0) --------------------------------------------------------
int __thiscall TEditPanel::handle_mouse_down(TEditPanel *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  return TPanel::handle_mouse_down((TPanel *)&this->vfptr, mouse_button_in, x, y, ctrl_key, shift_key);
}
