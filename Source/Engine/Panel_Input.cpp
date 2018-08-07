
//----- (00476C10) --------------------------------------------------------
void __thiscall TInputPanel::TInputPanel(TInputPanel *this)
{
  TInputPanel *v1; // esi@1

  v1 = this;
  TTextPanel::TTextPanel((TTextPanel *)&this->vfptr);
  v1->caret_color = 0;
  v1->caret_interval = GetCaretBlinkTime();
  v1->caret_last_time = 0;
  v1->draw_caret = 1;
  v1->insert_mode = 1;
  v1->handle_mouse_input = 1;
  v1->bevel_type = 1;
  v1->overLengthSound = 0;
  v1->input_buffer = 0;
  v1->input_buffer1 = 0;
  v1->input_buffer2 = 0;
  v1->input_len = 0;
  v1->max_len = 0;
  v1->input_pos = 0;
  v1->vfptr = (TPanelVtbl *)&TInputPanel::`vftable';
  v1->panel_type = 7;
  v1->horz_align = 5;
}
// 571488: using guessed type int (__thiscall *TInputPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00476CD0) --------------------------------------------------------
TInputPanel *__thiscall TInputPanel::`vector deleting destructor'(TInputPanel *this, unsigned int __flags)
{
  TInputPanel *v2; // esi@1

  v2 = this;
  TInputPanel::~TInputPanel(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00476EE0) --------------------------------------------------------
void __thiscall TInputPanel::set_focus(TInputPanel *this, int have_focus_in)
{
  TInputPanel *v2; // esi@1

  v2 = this;
  TPanel::set_focus((TPanel *)&this->vfptr, have_focus_in);
  if( v2->have_focus )
  {
    v2->draw_caret = 1;
    v2->caret_last_time = debug_timeGetTime();
  }
}

//----- (00476F20) --------------------------------------------------------
void __thiscall TInputPanel::set_format(TInputPanel *this, TInputPanel::FormatType format_type_in)
{
  this->format_type = format_type_in;
}

//----- (00476F30) --------------------------------------------------------
int __thiscall TInputPanel::handle_idle(TInputPanel *this)
{
  TInputPanel *v1; // esi@1
  TPanelVtbl *v2; // edx@3

  v1 = this;
  if( this->have_focus && debug_timeGetTime() - this->caret_last_time >= this->caret_interval )
  {
    v2 = v1->vfptr;
    v1->draw_caret = v1->draw_caret == 0;
    v2->set_redraw((TPanel *)v1, RedrawNormal);
    v1->caret_last_time = debug_timeGetTime();
  }
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}

//----- (00476FA0) --------------------------------------------------------
int __thiscall TInputPanel::char_action(TInputPanel *this, int key, __int16 count)
{
  TInputPanel *v3; // edi@1
  __int16 v4; // bp@7
  int v5; // ebx@9
  TInputPanel::FormatType v6; // eax@10
  const unsigned __int8 *v7; // eax@11
  const unsigned __int8 *v8; // eax@14
  const unsigned __int8 *v9; // eax@16
  TDigital *v11; // ecx@53
  TDigital *v12; // ecx@55
  TDigital *v13; // ecx@57

  v3 = this;
  if( key == 8 || key == 9 || key == 10 || key == 13 || key == 27 || key < 27 )
    return 1;
  v4 = count;
  if( !count )
    v4 = 1;
  v5 = 0;
  if( v4 <= 0 )
    return 1;
  while( 2 )
  {
    v6 = v3->format_type;
    switch ( v6 )
    {
      case 8:
        v7 = (const unsigned __int8 *)TTextPanel::get_text((TTextPanel *)&v3->vfptr);
        if( _mbslen(v7) < 2 && key >= 48 && key <= 57 )
          goto LABEL_50;
        v8 = (const unsigned __int8 *)TTextPanel::get_text((TTextPanel *)&v3->vfptr);
        if( _mbslen(v8) == 2 && key == 48 )
        {
          v9 = (const unsigned __int8 *)TTextPanel::get_text((TTextPanel *)&v3->vfptr);
          if( !_mbscmp(a10, v9) )
            goto LABEL_50;
        }
        v11 = v3->overLengthSound;
        if( !v11 )
          goto LABEL_59;
        TDigital::play(v11);
        return 1;
      case 1:
      case 2:
      case 3:
        if( (key < 48 || key > 57)
          && (key != 45 || *v3->input_buffer || v6 == 3)
          && (key != 46 || !_mbschr((const unsigned __int8 *)v3->input_buffer, 0x2Eu) || v3->format_type != 1) )
        {
          goto LABEL_55;
        }
        goto LABEL_50;
      case 4:
      case 5:
        if( key == 46 )
        {
          if( v6 != 4 || _mbschr((const unsigned __int8 *)v3->input_buffer, 0x2Eu) )
            goto LABEL_55;
          goto LABEL_50;
        }
        if( key != 92
          && key != 58
          && key != 47
          && key != 34
          && key != 42
          && key != 63
          && key != 62
          && key != 60
          && key != 124 )
        {
LABEL_50:
          if( !TInputPanel::insert_character(v3, key) )
            return 1;
          if( (signed __int16)++v5 >= v4 )
            return 1;
          continue;
        }
LABEL_55:
        v12 = v3->overLengthSound;
        if( v12 )
        {
          TDigital::play(v12);
          return 1;
        }
LABEL_59:
        MessageBeep(0xFFFFFFFF);
        return 1;
      case 6:
        if( (key != 58 || v3->input_len == 1)
          && key != 47
          && key != 34
          && key != 42
          && key != 63
          && key != 62
          && key != 60
          && key != 124 )
        {
          goto LABEL_50;
        }
        v13 = v3->overLengthSound;
        if( !v13 )
          goto LABEL_59;
        TDigital::play(v13);
        return 1;
      default:
        goto LABEL_50;
    }
  }
}

//----- (00477220) --------------------------------------------------------
int __thiscall TInputPanel::key_down_action(TInputPanel *this, int key, __int16 count, int alt_key, int ctrl_key, int shift_key)
{
  TInputPanel *v6; // esi@1
  int result; // eax@3
  __int16 v8; // ax@4
  __int16 v9; // ax@5
  __int16 v10; // ax@6
  __int16 v11; // ax@7
  __int16 v12; // di@10
  const unsigned __int8 *v13; // eax@10
  __int16 v14; // ax@12
  __int16 v15; // ax@16
  __int16 v16; // ax@17
  const unsigned __int8 *v17; // eax@17
  const unsigned __int8 *v18; // eax@18
  __int16 v19; // cx@20
  __int16 v20; // ax@23
  const unsigned __int8 *v21; // eax@23
  __int16 v22; // ax@33
  const unsigned __int8 *v23; // eax@37
  __int16 v24; // ax@38
  int v25; // ecx@38
  const unsigned __int8 *v26; // eax@39
  const unsigned __int8 *v27; // eax@41
  __int16 v28; // cx@45
  __int16 v29; // ax@46
  __int16 v30; // ax@51
  __int16 v31; // cx@53
  const unsigned __int8 *v32; // eax@59
  char *v33; // eax@7
  TPanel *v34; // ecx@71
  TPanel *v35; // ecx@73

  v6 = this;
  switch ( key )
  {
    case 37:
      if( this->num_lines >= 1 )
      {
        v8 = this->cur_col;
        if( v8 > 0 )
        {
          v9 = v8 - 1;
          goto LABEL_62;
        }
        v10 = this->cur_line;
        if( v10 > 0 )
        {
          v11 = v10 - 1;
          this->cur_line = v11;
          v33 = TTextPanel::get_text((TTextPanel *)&this->vfptr, v11);
          goto LABEL_61;
        }
        goto LABEL_77;
      }
      result = 1;
      break;
    case 39:
      if( this->num_lines >= 1 )
      {
        v12 = this->cur_col;
        v13 = (const unsigned __int8 *)TTextPanel::get_text((TTextPanel *)&this->vfptr, this->cur_line);
        if( v12 >= (signed __int16)_mbslen(v13) )
        {
          v14 = v6->cur_line;
          if( v6->cur_line >= v6->num_lines - 1 )
            goto LABEL_77;
          v6->cur_col = 0;
          v6->cur_line = v14 + 1;
          goto LABEL_19;
        }
        v6->cur_col = v12 + 1;
        TInputPanel::calc_input_pos(v6);
        v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
        result = 1;
      }
      else
      {
        result = 1;
      }
      break;
    case 38:
      if( this->num_lines >= 1 )
      {
        v15 = this->cur_line;
        if( v15 <= 0 )
          goto LABEL_77;
        v16 = v15 - 1;
        this->cur_line = v16;
        v17 = (const unsigned __int8 *)TTextPanel::get_text((TTextPanel *)&this->vfptr, v16);
        if( v6->cur_col > (signed __int16)_mbslen(v17) )
        {
          v18 = (const unsigned __int8 *)TTextPanel::get_text((TTextPanel *)&v6->vfptr, v6->cur_line);
          v6->cur_col = _mbslen(v18);
        }
LABEL_19:
        TInputPanel::calc_input_pos(v6);
        v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
        result = 1;
      }
      else
      {
        result = 1;
      }
      break;
    case 40:
      v19 = this->num_lines;
      if( v19 >= 1 )
      {
        if( v6->cur_line >= v19 - 1 )
          goto LABEL_77;
        v20 = v6->cur_line + 1;
        v6->cur_line = v20;
        v21 = (const unsigned __int8 *)TTextPanel::get_text((TTextPanel *)&v6->vfptr, v20);
        if( v6->cur_col <= (signed __int16)_mbslen(v21) )
          goto LABEL_63;
        goto LABEL_60;
      }
      result = 1;
      break;
    case 36:
      if( this->num_lines >= 1 )
      {
        if( !ctrl_key )
        {
          if( !this->cur_col )
            goto LABEL_77;
          this->cur_col = 0;
          goto LABEL_42;
        }
        if( !this->cur_col && !this->cur_line )
          goto LABEL_77;
        this->cur_col = 0;
        this->cur_line = 0;
        TInputPanel::calc_input_pos(this);
        v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
        result = 1;
      }
      else
      {
        result = 1;
      }
      break;
    case 35:
      v22 = this->num_lines;
      if( v22 >= 1 )
      {
        if( ctrl_key )
        {
          if( this->cur_line == v22 - 1 )
          {
            v23 = (const unsigned __int8 *)TTextPanel::get_text((TTextPanel *)&this->vfptr, this->cur_line);
            if( v6->cur_col == (unsigned __int16)_mbslen(v23) )
              goto LABEL_77;
          }
          v24 = v6->num_lines - 1;
          v6->cur_line = v24;
          v25 = v24;
        }
        else
        {
          v26 = (const unsigned __int8 *)TTextPanel::get_text((TTextPanel *)&this->vfptr, this->cur_line);
          if( v6->cur_col == (unsigned __int16)_mbslen(v26) )
            goto LABEL_77;
          v25 = v6->cur_line;
        }
        v27 = (const unsigned __int8 *)TTextPanel::get_text((TTextPanel *)&v6->vfptr, v25);
        v6->cur_col = _mbslen(v27);
LABEL_42:
        v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
        TInputPanel::calc_input_pos(v6);
        result = 1;
      }
      else
      {
        result = 1;
      }
      break;
    case 33:
      if( this->num_lines >= 1 )
      {
        v28 = this->cur_line;
        if( v28 <= 0 )
          goto LABEL_77;
        v29 = v6->top_line;
        if( v28 < v29 || v28 > v6->bot_line )
          v6->cur_line = v29;
        if( v6->cur_line == v29 )
        {
          TTextPanel::scroll((TTextPanel *)&v6->vfptr, 5, 0, 1);
          v29 = v6->top_line;
        }
        goto LABEL_59;
      }
      result = 1;
      break;
    case 34:
      v30 = this->num_lines;
      if( v30 >= 1 )
      {
        v31 = this->cur_line;
        if( v6->cur_line >= v30 - 1 )
          goto LABEL_77;
        if( v31 < v6->top_line || (v29 = v6->bot_line, v31 > v29) )
        {
          v29 = v6->bot_line;
          v6->cur_line = v29;
        }
        if( v6->cur_line == v29 )
        {
          TTextPanel::scroll((TTextPanel *)&v6->vfptr, 4, 0, 1);
          v29 = v6->bot_line;
        }
LABEL_59:
        v6->cur_line = v29;
        v32 = (const unsigned __int8 *)TTextPanel::get_text((TTextPanel *)&v6->vfptr, v29);
        if( v6->cur_col > (signed __int16)_mbslen(v32) )
        {
LABEL_60:
          v33 = TTextPanel::get_text((TTextPanel *)&v6->vfptr, v6->cur_line);
LABEL_61:
          v9 = _mbslen((const unsigned __int8 *)v33);
LABEL_62:
          v6->cur_col = v9;
        }
LABEL_63:
        TInputPanel::calc_input_pos(v6);
        v6->vfptr->set_redraw((TPanel *)v6, RedrawNormal);
        result = 1;
      }
      else
      {
        result = 1;
      }
      break;
    case 46:
      TInputPanel::delete_character(this);
      result = 1;
      break;
    case 45:
      if( shift_key )
        goto LABEL_76;
      if( ctrl_key )
        goto LABEL_77;
      this->insert_mode = this->insert_mode == 0;
      result = 1;
      break;
    case 8:
      TInputPanel::backspace_character(this);
      result = 1;
      break;
    case 13:
      if( this->format_type == 7 )
      {
        TInputPanel::insert_character(this, 10);
        result = 1;
      }
      else
      {
        v34 = this->parent_panel;
        if( !v34 )
          goto LABEL_77;
        ((void (__stdcall *)(TInputPanel *, _DWORD, _DWORD, _DWORD))v34->vfptr->action)(v6, 0, 0, 0);
        result = 1;
      }
      break;
    case 27:
      v35 = this->parent_panel;
      if( !v35 )
        goto LABEL_77;
      ((void (__stdcall *)(TInputPanel *, signed int, _DWORD, _DWORD))v35->vfptr->action)(v6, 1, 0, 0);
      result = 1;
      break;
    case 86:
      if( !ctrl_key )
        goto LABEL_78;
LABEL_76:
      TInputPanel::paste(this);
LABEL_77:
      result = 1;
      break;
    default:
LABEL_78:
      result = 0;
      break;
  }
  return result;
}

//----- (004777C0) --------------------------------------------------------
void __thiscall TInputPanel::draw(TInputPanel *this)
{
  TInputPanel *v1; // esi@1
  __int16 v2; // ax@6
  void *v3; // edi@8
  HGDIOBJ v4; // ebp@9
  int v5; // ebx@10
  int v6; // edi@10
  int v7; // ebp@10
  int cursor_x_offset; // [sp+4h] [bp-18h]@9
  TPanelVtbl *v9; // [sp+8h] [bp-14h]@8
  tagRECT line_rect; // [sp+Ch] [bp-10h]@9

  v1 = this;
  TTextPanel::draw((TTextPanel *)&this->vfptr);
  if( v1->render_area )
  {
    if( v1->visible )
    {
      if( v1->active )
      {
        if( v1->have_focus )
        {
          if( v1->draw_caret )
          {
            v2 = v1->cur_line;
            if( v2 >= v1->top_line && v2 <= v1->bot_line )
            {
              v9 = v1->vfptr;
              v9->draw_setup((TPanel *)v1, 0);
              v3 = TDrawArea::GetDc(v1->render_area, aPnl_inpDraw);
              if( v3 )
              {
                v4 = SelectObject(v3, v1->font);
                TTextPanel::calc_line_pos(
                  (TTextPanel *)&v1->vfptr,
                  v3,
                  v1->cur_line - v1->top_line,
                  v1->cur_line,
                  &line_rect,
                  &cursor_x_offset);
                SelectObject(v3, v4);
                TDrawArea::ReleaseDc(v1->render_area, aPnl_inpDraw);
                if( TDrawArea::Lock(v1->render_area, aPnl_inpDraw, 1) )
                {
                  v5 = cursor_x_offset + line_rect.left;
                  v6 = line_rect.bottom - line_rect.top + 1;
                  v7 = line_rect.top;
                  if( cursor_x_offset + line_rect.left < v1->render_rect.right )
                  {
                    TDrawArea::DrawVertLine(
                      v1->render_area,
                      cursor_x_offset + line_rect.left,
                      line_rect.top,
                      line_rect.bottom - line_rect.top + 1,
                      v1->caret_color);
                    TDrawArea::DrawVertLine(v1->render_area, v5 + 1, v7, v6, v1->caret_color);
                  }
                  TDrawArea::Unlock(v1->render_area, aPnl_inpDraw);
                }
              }
              v9->draw_finish((TPanel *)v1);
            }
          }
        }
      }
    }
  }
}

//----- (00477910) --------------------------------------------------------
void __thiscall TInputPanel::set_text(TInputPanel *this, char *text_in)
{
  TInputPanel *v2; // esi@1
  unsigned __int8 *v3; // eax@1
  __int16 v4; // ax@5
  TInputPanel::FormatType v5; // ecx@5

  v2 = this;
  v3 = (unsigned __int8 *)this->input_buffer;
  if( v3 )
  {
    if( text_in )
      _mbscpy(v3, (const unsigned __int8 *)text_in);
    else
      *v3 = 0;
    v4 = _mbslen((const unsigned __int8 *)v2->input_buffer);
    v5 = v2->format_type;
    v2->input_len = v4;
    v2->input_pos = 0;
    v2->cur_line = 0;
    v2->cur_col = 0;
    if( v5 != 7 && v4 > 0 )
    {
      v2->input_pos = v4;
      v2->cur_col = v4;
    }
    TInputPanel::reformat(v2);
  }
}

//----- (004779A0) --------------------------------------------------------
char *__thiscall TInputPanel::get_input_buffer(TInputPanel *this)
{
  return this->input_buffer;
}

//----- (004779B0) --------------------------------------------------------
int __thiscall TInputPanel::append_character(TInputPanel *this, int c)
{
  this->input_pos = this->input_len;
  return TInputPanel::insert_character(this, c);
}

//----- (004779D0) --------------------------------------------------------
int __thiscall TInputPanel::insert_character(TInputPanel *this, int c)
{
  TInputPanel *v2; // esi@1
  TDigital *v3; // ecx@2
  int result; // eax@3
  char *v5; // edi@5
  const unsigned __int8 *v6; // ebx@6
  __int16 v7; // ax@8
  unsigned __int8 *v8; // eax@10

  v2 = this;
  if( this->input_len < this->max_len )
  {
    v5 = this->input_buffer1;
    if( this->input_buffer == v5 )
    {
      v6 = (const unsigned __int8 *)this->input_buffer1;
      v5 = this->input_buffer2;
    }
    else
    {
      v6 = (const unsigned __int8 *)this->input_buffer2;
    }
    this->input_buffer = v5;
    *v5 = 0;
    v7 = this->input_pos;
    if( v7 > 0 )
    {
      _mbsncpy((unsigned __int8 *)v5, v6, v7);
      v6 = _mbsninc(v6, v2->input_pos);
      v5 = (char *)_mbsninc((const unsigned __int8 *)v5, v2->input_pos);
    }
    _mbsncpy((unsigned __int8 *)v5, (const unsigned __int8 *)&c, 1u);
    v8 = _mbsinc((const unsigned __int8 *)v5);
    _mbsncpy(v8, v6, v2->input_len - v2->input_pos + 1);
    ++v2->input_len;
    ++v2->input_pos;
    TInputPanel::reformat(v2);
    TInputPanel::calc_cur_line_col(v2);
    v2->draw_caret = 1;
    v2->caret_last_time = debug_timeGetTime();
    result = 1;
  }
  else
  {
    v3 = this->overLengthSound;
    if( v3 )
    {
      TDigital::play(v3);
      result = 0;
    }
    else
    {
      MessageBeep(0xFFFFFFFF);
      result = 0;
    }
  }
  return result;
}

//----- (00477AF0) --------------------------------------------------------
int __thiscall TInputPanel::delete_character(TInputPanel *this)
{
  TInputPanel *v1; // esi@1
  char *v3; // edi@3
  char *v4; // ebx@4
  __int16 v5; // ax@6
  unsigned __int8 *v6; // ebp@6
  unsigned __int8 *v7; // eax@9
  signed __int16 v8; // di@9
  unsigned __int8 *v9; // eax@13
  const unsigned __int8 *v10; // ebx@13
  unsigned __int8 *cur_dest; // [sp+4h] [bp-8h]@6
  int move_back_one; // [sp+8h] [bp-4h]@3

  v1 = this;
  if( this->input_pos >= this->input_len )
    return 0;
  v3 = this->input_buffer1;
  move_back_one = 0;
  if( this->input_buffer == v3 )
  {
    v4 = this->input_buffer1;
    v3 = this->input_buffer2;
  }
  else
  {
    v4 = this->input_buffer2;
  }
  this->input_buffer = v3;
  *v3 = 0;
  v5 = this->input_pos;
  v6 = (unsigned __int8 *)v4;
  cur_dest = (unsigned __int8 *)v3;
  if( v5 > 0 )
  {
    _mbsncpy((unsigned __int8 *)v3, (const unsigned __int8 *)v4, v5);
    v6 = _mbsninc((const unsigned __int8 *)v4, v1->input_pos);
    cur_dest = _mbsninc((const unsigned __int8 *)v3, v1->input_pos);
  }
  if( *v6 == 13 )
  {
    v7 = _mbsinc(v6);
    v8 = 1;
    if( *v7 == 10 )
    {
      v7 = _mbsinc(v7);
      v8 = 2;
    }
    goto LABEL_18;
  }
  if( *v6 != 10 || v6 <= (unsigned __int8 *)v4 )
  {
    v7 = _mbsinc(v6);
    goto LABEL_17;
  }
  v9 = _mbsdec((const unsigned __int8 *)v4, v6);
  v10 = v9;
  if( *v9 != 13 )
  {
    v7 = _mbsninc(v9, 2u);
LABEL_17:
    v8 = 1;
    goto LABEL_18;
  }
  cur_dest = _mbsdec((const unsigned __int8 *)v3, cur_dest);
  v7 = _mbsninc(v10, 2u);
  v8 = 2;
  move_back_one = 1;
LABEL_18:
  _mbsncpy(cur_dest, v7, v1->input_len - v1->input_pos + 1);
  if( move_back_one )
    --v1->input_pos;
  v1->input_len -= v8;
  TInputPanel::reformat(v1);
  TInputPanel::calc_cur_line_col(v1);
  v1->draw_caret = 1;
  v1->caret_last_time = debug_timeGetTime();
  return 1;
}

//----- (00477C90) --------------------------------------------------------
int __thiscall TInputPanel::backspace_character(TInputPanel *this)
{
  __int16 v1; // ax@1
  int result; // eax@2

  v1 = this->input_pos;
  if( v1 <= 0 )
  {
    result = 0;
  }
  else
  {
    this->input_pos = v1 - 1;
    result = TInputPanel::delete_character(this);
  }
  return result;
}

//----- (00477CB0) --------------------------------------------------------
int __thiscall TInputPanel::paste(TInputPanel *this)
{
  signed int v1; // ebx@1
  TInputPanel *v2; // esi@1
  int result; // eax@1
  HANDLE v4; // eax@3
  const unsigned __int8 *v5; // eax@4
  const unsigned __int8 *v6; // ebp@4
  TDigital *v7; // esi@9
  unsigned __int8 *v8; // edi@12
  const unsigned __int8 *v9; // ebp@13
  unsigned __int8 *v10; // ebp@15
  unsigned __int8 *v11; // edi@15
  unsigned __int8 *v12; // eax@15
  HGLOBAL hMem; // [sp+10h] [bp-1004h]@3
  unsigned __int8 v14; // [sp+14h] [bp-1000h]@1

  v1 = 0;
  v2 = this;
  v14 = 0;
  result = IsClipboardFormatAvailable(1u);
  if( result )
  {
    result = OpenClipboard(v2->render_area->Wnd);
    if( result )
    {
      v4 = GetClipboardData(1u);
      hMem = v4;
      if( v4 )
      {
        v5 = (const unsigned __int8 *)GlobalLock(v4);
        v6 = v5;
        if( v5 )
        {
          v1 = _mbslen(v5);
          if( v1 > 4095 )
            v1 = 4095;
          memset(&v14, 0, 0x1000u);
          _mbsncpy(&v14, v6, v1);
          GlobalUnlock(hMem);
        }
      }
      CloseClipboard();
      if( v2->input_len + v1 < v2->max_len )
      {
        v8 = (unsigned __int8 *)v2->input_buffer1;
        if( (unsigned __int8 *)v2->input_buffer == v8 )
        {
          v9 = (const unsigned __int8 *)v2->input_buffer1;
          v8 = (unsigned __int8 *)v2->input_buffer2;
        }
        else
        {
          v9 = (const unsigned __int8 *)v2->input_buffer2;
        }
        v2->input_buffer = (char *)v8;
        *v8 = 0;
        _mbsncpy(v8, v9, v2->input_pos);
        v10 = _mbsninc(v9, v2->input_pos);
        v11 = _mbsninc(v8, v2->input_pos);
        _mbsncpy(v11, &v14, v1);
        v12 = _mbsninc(v11, v1);
        _mbsncpy(v12, v10, v2->input_len - v2->input_pos + 1);
        v2->input_len += v1;
        v2->input_pos += v1;
        TInputPanel::reformat(v2);
        TInputPanel::calc_cur_line_col(v2);
        v2->draw_caret = 1;
        v2->caret_last_time = debug_timeGetTime();
        result = 1;
      }
      else
      {
        v7 = v2->overLengthSound;
        if( v7 )
        {
          TDigital::play(v7);
          result = 0;
        }
        else
        {
          MessageBeep(0xFFFFFFFF);
          result = 0;
        }
      }
    }
  }
  return result;
}

//----- (00477E90) --------------------------------------------------------
void __thiscall TInputPanel::reformat(TInputPanel *this)
{
  TInputPanel *v1; // esi@1
  __int16 v2; // bx@1
  __int16 v3; // di@1
  __int16 v4; // ax@1

  v1 = this;
  v2 = this->top_line;
  v3 = this->cur_line;
  TTextPanel::set_text((TTextPanel *)&this->vfptr, this->input_buffer);
  v4 = v1->num_lines;
  if( v3 >= v4 )
    v3 = v4 - 1;
  v1->cur_line = v3;
  if( v2 >= v4 )
    v1->top_line = v4 - 1;
  TTextPanel::scroll((TTextPanel *)&v1->vfptr, 1, v2, 1);
  v1->vfptr->set_redraw((TPanel *)v1, RedrawNormal);
}

//----- (00477EF0) --------------------------------------------------------
void __thiscall TInputPanel::calc_input_pos(TInputPanel *this)
{
  TInputPanel *v1; // esi@1
  __int16 v2; // bx@1
  TTextPanel::TextNode *v3; // edi@1
  __int16 v4; // ax@4
  __int16 v5; // cx@4
  __int16 v6; // cx@8
  __int16 v7; // ax@9

  v1 = this;
  v2 = 0;
  v3 = this->list;
  for( this->input_pos = 0; v3; ++v2 )
  {
    if( v2 >= v1->cur_line )
      break;
    v1->input_pos += _mbslen((const unsigned __int8 *)v3->text);
    v3 = v3->next_node;
  }
  v4 = v1->cur_col;
  v1->input_pos += v4;
  v5 = v1->input_pos;
  if( v4 > 0 && v5 > 0 && v1->input_buffer[v5 - 1] == 10 )
  {
    v1->input_pos = v5 - 1;
    v1->cur_col = v4 - 1;
  }
  v6 = v1->cur_col;
  if( v6 > 0 )
  {
    v7 = v1->input_pos;
    if( v7 > 0 && v1->input_buffer[v7 - 1] == 13 )
    {
      v1->input_pos = v7 - 1;
      v1->cur_col = v6 - 1;
    }
  }
  while( v1->cur_line < v1->top_line )
    TTextPanel::scroll((TTextPanel *)&v1->vfptr, 3, 1, 1);
  while( v1->cur_line > v1->bot_line )
    TTextPanel::scroll((TTextPanel *)&v1->vfptr, 2, 1, 1);
}

//----- (00478010) --------------------------------------------------------
void __thiscall TInputPanel::calc_cur_line_col(TInputPanel *this)
{
  TInputPanel *v1; // esi@1
  __int16 v2; // bx@1
  TTextPanel::TextNode *v3; // edi@1
  __int16 v4; // ax@3
  __int16 v5; // cx@5
  __int16 v6; // ax@10

  v1 = this;
  v2 = 0;
  v3 = this->list;
  this->cur_line = 0;
  for( this->cur_col = 0; v3; v3 = v3->next_node )
  {
    if( v1->cur_line == v1->num_lines - 1 )
      break;
    v4 = _mbslen((const unsigned __int8 *)v3->text);
    if( v4 + v2 > v1->input_pos )
      break;
    v2 += v4;
    ++v1->cur_line;
  }
  v5 = v1->input_pos;
  v1->cur_col = v5 - v2;
  if( (signed __int16)(v5 - v2) > 0 && v5 > 0 && v1->input_buffer[v5 - 1] == 10 )
  {
    --v1->cur_col;
    v1->input_pos = v5 - 1;
  }
  if( v1->cur_col > 0 )
  {
    v6 = v1->input_pos;
    if( v6 > 0 && v1->input_buffer[v6 - 1] == 13 )
    {
      --v1->cur_col;
      v1->input_pos = v6 - 1;
    }
  }
  while( v1->cur_line < v1->top_line )
    TTextPanel::scroll((TTextPanel *)&v1->vfptr, 3, 1, 1);
  while( v1->cur_line > v1->bot_line )
    TTextPanel::scroll((TTextPanel *)&v1->vfptr, 2, 1, 1);
}

//----- (00478150) --------------------------------------------------------
int __thiscall TInputPanel::is_blank(TInputPanel *this)
{
  char *v1; // eax@1
  unsigned __int8 *v2; // esi@1

  v1 = TTextPanel::currentLine((TTextPanel *)&this->vfptr);
  v2 = (unsigned __int8 *)v1;
  if( v1 && *v1 )
  {
    while( *v2 )
    {
      if( !_ismbcspace(*v2) )
        return 0;
      v2 = _mbsinc(v2);
    }
  }
  return 1;
}

//----- (004781A0) --------------------------------------------------------
char *__thiscall TInputPanel::get_trimmed_str(TInputPanel *this, char *str, int str_len)
{
  unsigned __int8 *v3; // esi@1
  const unsigned __int8 *v4; // edi@1
  char temp_str[256]; // [sp+Ch] [bp-100h]@1

  memset(temp_str, 0, sizeof(temp_str));
  strcpy(temp_str, TTextPanel::currentLine((TTextPanel *)&this->vfptr));
  v3 = (unsigned __int8 *)str;
  memset(str, 0, str_len);
  v4 = (const unsigned __int8 *)temp_str;
  if( _ismbcspace((unsigned __int8)temp_str[0]) )
  {
    do
      v4 = _mbsinc(v4);
    while( _ismbcspace(*v4) );
  }
  for( ; *v4; v4 = _mbsinc(v4) )
  {
    _mbsncpy(v3, v4, 1u);
    v3 = _mbsinc(v3);
  }
  do
  {
    *v3 = 0;
    if( (char *)v3 == str )
      break;
    v3 = _mbsdec((const unsigned __int8 *)str, v3);
  }
  while( _ismbcspace(*v3) );
  return str;
}
