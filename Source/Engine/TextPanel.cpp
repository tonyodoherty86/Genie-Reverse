
//----- (0047BF40) --------------------------------------------------------
void __thiscall TTextPanel::TTextPanel(TTextPanel *this)
{
  TTextPanel *v1; // esi@1

  v1 = this;
  TPanel::TPanel((TPanel *)&this->vfptr);
  v1->back_color = -1;
  v1->list = 0;
  v1->num_lines = 0;
  v1->draw_lines = 0;
  v1->top_line = 0;
  v1->bot_line = 0;
  v1->cur_line = 0;
  v1->cur_col = 0;
  v1->font = 0;
  v1->font_wid = 0;
  v1->font_hgt = 0;
  v1->vert_align = 0;
  v1->horz_align = 0;
  v1->word_wrap = 0;
  v1->text_style = 2;
  v1->text_color1 = 0xFFFFFF;
  v1->text_color2 = 0;
  v1->highlightTextColor2 = 0;
  v1->scbar_panel = 0;
  v1->auto_scbar = 0;
  v1->fixed_len = 0;
  v1->text_wid = 0;
  v1->text_hgt = 0;
  v1->back_pic = 0;
  v1->back_pic_wid = 0;
  v1->back_pic_hgt = 0;
  v1->fill_back = 0;
  v1->outline = 0;
  v1->outline_color = 0;
  v1->sorted = 0;
  v1->second_column_pos = 0;
  v1->full_width = 0;
  v1->scbar_width = 0;
  v1->scbar_active = 0;
  v1->bevel_type = 0;
  v1->bevel_color1 = 0;
  v1->bevel_color2 = 0;
  v1->bevel_color3 = 0;
  v1->bevel_color4 = 0;
  v1->bevel_color5 = 0;
  v1->bevel_color6 = 0;
  v1->clip_rgn2 = 0;
  v1->border_size = 0;
  v1->spacer_size = 0;
  v1->handle_mouse_input = 0;
  v1->highlightTextColor1 = 0xFFFF;
  v1->vfptr = (TPanelVtbl *)&TTextPanel::`vftable';
  v1->panel_type = 1;
}
// 571BF8: using guessed type int (__thiscall *TTextPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (0047C090) --------------------------------------------------------
TTextPanel *__thiscall TTextPanel::`vector deleting destructor'(TTextPanel *this, unsigned int __flags)
{
  TTextPanel *v2; // esi@1

  v2 = this;
  TTextPanel::~TTextPanel(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0047C120) --------------------------------------------------------
int __thiscall TTextPanel::setup(TTextPanel *this, TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, void *font_in, int font_wid_in, int font_hgt_in, char *back_pic_in, int fill_back_in, char back_color_in, int outline_in, char outline_color_in, __int16 fixed_len_in, char *text_in)
{
  TTextPanel *v17; // esi@1

  v17 = this;
  TPanel::setup((TPanel *)&this->vfptr, render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);
  v17->fill_back = fill_back_in;
  v17->back_color = back_color_in;
  v17->outline = outline_in;
  v17->outline_color = outline_color_in;
  v17->fixed_len = fixed_len_in;
  if( outline_in )
    v17->bevel_type = 1;
  (*(void (__thiscall **)(TTextPanel *, char *))&v17->vfptr[1].gap4[4])(v17, text_in);
  TTextPanel::set_font(v17, font_in, font_wid_in, font_hgt_in);
  TTextPanel::set_alignment(v17, 0, 0);
  TTextPanel::set_back_pic(v17, back_pic_in);
  return 1;
}

//----- (0047C1E0) --------------------------------------------------------
int __thiscall TTextPanel::setup(TTextPanel *this, TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, void *font_in, int font_wid_in, int font_hgt_in, char *back_pic_in, int fill_back_in, char back_color_in, int outline_in, char outline_color_in, __int16 fixed_len_in, int string_id_in)
{
  TTextPanel *v17; // esi@1
  char str; // [sp+4h] [bp-1000h]@3

  v17 = this;
  TPanel::setup((TPanel *)&this->vfptr, render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);
  v17->fill_back = fill_back_in;
  v17->back_color = back_color_in;
  v17->outline = outline_in;
  v17->outline_color = outline_color_in;
  v17->fixed_len = fixed_len_in;
  if( outline_in )
    v17->bevel_type = 1;
  TTextPanel::set_font(v17, font_in, font_wid_in, font_hgt_in);
  TTextPanel::set_alignment(v17, 0, 0);
  TTextPanel::set_back_pic(v17, back_pic_in);
  TPanel::get_string(string_id_in, &str, 4096);
  (*(void (__thiscall **)(TTextPanel *, char *))&v17->vfptr[1].gap4[4])(v17, &str);
  return 1;
}

//----- (0047C2F0) --------------------------------------------------------
int __thiscall TTextPanel::setup(TTextPanel *this, TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, void *font_in, int font_wid_in, int font_hgt_in, char *back_pic_in, int fill_back_in, char back_color_in, int outline_in, char outline_color_in, __int16 fixed_len_in, char **text_in, int num_lines_in)
{
  TTextPanel *v18; // esi@1

  v18 = this;
  TPanel::setup((TPanel *)&this->vfptr, render_area_in, parent_panel_in, x_in, y_in, wid_in, hgt_in, 0);
  v18->fill_back = fill_back_in;
  v18->back_color = back_color_in;
  v18->outline = outline_in;
  v18->outline_color = outline_color_in;
  v18->fixed_len = fixed_len_in;
  if( outline_in )
    v18->bevel_type = 1;
  ((void (__thiscall *)(TTextPanel *, char **, int))v18->vfptr[1].__vecDelDtor)(v18, text_in, num_lines_in);
  TTextPanel::set_font(v18, font_in, font_wid_in, font_hgt_in);
  TTextPanel::set_alignment(v18, AlignTop, AlignLeft);
  TTextPanel::set_back_pic(v18, back_pic_in);
  return 1;
}

//----- (0047C3B0) --------------------------------------------------------
void __thiscall TTextPanel::set_rect(TTextPanel *this, int x_in, int y_in, int wid_in, int hgt_in)
{
  TTextPanel *v5; // esi@1
  int v6; // eax@1
  TScrollBarPanel *v7; // ecx@2
  TPanel *v8; // ecx@3
  int v9; // edi@4
  int v10; // edx@4
  int clip_rect2_8; // ST28_4@11
  int v12; // eax@11

  v5 = this;
  TPanel::set_rect((TPanel *)&this->vfptr, x_in, y_in, wid_in, hgt_in);
  v6 = v5->auto_scbar;
  v5->full_width = v5->pnl_wid;
  if( v6 )
  {
    v7 = v5->scbar_panel;
    if( v7 )
    {
      (*(void (__stdcall **)(_DWORD))&v7->vfptr->gap10[4])(0);
      v8 = v5->parent_panel;
      v5->scbar_active = 0;
      if( v8 )
      {
        v9 = v5->pnl_x - TPanel::xPosition(v8);
        v10 = v5->pnl_y - TPanel::yPosition(v5->parent_panel);
      }
      else
      {
        v9 = v5->pnl_x;
        v10 = v5->pnl_y;
      }
      ((void (__stdcall *)(int, int, _DWORD, _DWORD))v5->scbar_panel->vfptr->set_fixed_position)(
        v5->full_width + v9 - v5->scbar_width,
        v10,
        v5->scbar_width,
        v5->pnl_hgt);
    }
  }
  TTextPanel::calc_draw_info(v5, 1);
  if( v5->second_column_pos )
  {
    if( v5->clip_rgn2 )
    {
      DeleteObject(v5->clip_rgn2);
      v5->clip_rgn2 = 0;
    }
    if( v5->visible )
    {
      clip_rect2_8 = v5->clip_rect.right;
      v12 = v5->render_rect.left + v5->second_column_pos - 10;
      if( v12 > v5->clip_rect.right )
        v12 = v5->clip_rect.right;
      v5->clip_rgn2 = CreateRectRgn(v5->clip_rect.left, v5->clip_rect.top, v12, v5->clip_rect.bottom);
    }
  }
}

//----- (0047C4D0) --------------------------------------------------------
void __thiscall TTextPanel::set_scrollbar(TTextPanel *this, TScrollBarPanel *scbar_panel_in, int auto_scbar_in)
{
  TTextPanel *v3; // esi@1
  int v4; // eax@2
  int v5; // ecx@2
  TPanelVtbl *v6; // edx@2

  v3 = this;
  this->scbar_panel = scbar_panel_in;
  this->auto_scbar = auto_scbar_in;
  if( scbar_panel_in )
  {
    v4 = TPanel::width((TPanel *)&scbar_panel_in->vfptr);
    v5 = v3->pnl_wid;
    v6 = v3->vfptr;
    v3->scbar_width = v4;
    v6->set_rect((TPanel *)v3, v3->pnl_x, v3->pnl_y, v5, v3->pnl_hgt);
  }
}

//----- (0047C520) --------------------------------------------------------
signed int __stdcall TTextPanel::char_type(char *c)
{
  signed int result; // eax@4

  if( !c || !*c )
    goto LABEL_11;
  if( IsDBCSLeadByte(*c) )
    return 2;
  if( (unsigned __int8)*c >= 0xA1u && (unsigned __int8)*c <= 0xDFu )
    result = 1;
  else
LABEL_11:
    result = 0;
  return result;
}

//----- (0047C560) --------------------------------------------------------
void __thiscall TTextPanel::set_text(TTextPanel *this, char *text_in)
{
  TTextPanel *v2; // ebx@1
  char *v3; // esi@1
  unsigned __int8 *v4; // eax@8
  unsigned __int8 *v5; // edi@8
  size_t v6; // ebp@9
  char temp_text[256]; // [sp+10h] [bp-100h]@9

  v2 = this;
  TTextPanel::free_text(this);
  v3 = text_in;
  if( text_in )
  {
    if( *text_in )
    {
      if( v2->word_wrap || v2->horz_align == 6 )
      {
        TTextPanel::word_wrap_append(v2, text_in);
      }
      else
      {
        while( 1 )
        {
          v4 = _mbschr((const unsigned __int8 *)v3, 0xAu);
          v5 = v4;
          if( !v4 )
            break;
          v6 = (signed __int16)((_WORD)v4 - (_WORD)v3);
          strncpy(temp_text, v3, v6);
          temp_text[v6] = 0;
          TTextPanel::append_line(v2, temp_text, 0);
          v3 = (char *)(v5 + 1);
        }
        TTextPanel::append_line(v2, v3, 0);
      }
    }
    else
    {
      TTextPanel::append_line(v2, message_in, 0);
    }
  }
  else if( v2->fixed_len != (_WORD)text_in )
  {
    TTextPanel::append_line(v2, message_in, 0);
  }
}

//----- (0047C640) --------------------------------------------------------
int __thiscall TTextPanel::word_wrap_append(TTextPanel *this, char *text_in)
{
  const unsigned __int8 *v2; // esi@1
  signed __int16 v3; // bx@1
  TTextPanel *v4; // edi@1
  int v5; // eax@4
  void *v6; // ebp@6
  signed __int16 v8; // bp@10
  bool v9; // zf@10
  const unsigned __int8 *v10; // edi@10
  __int16 v11; // ax@12
  char *v12; // ecx@12
  unsigned __int8 *v13; // eax@19
  __int16 v14; // ax@19
  unsigned __int8 *v15; // edi@26
  __int16 v16; // ax@27
  signed int v17; // ebp@31
  signed int v18; // eax@31
  size_t v19; // edi@58
  int v20; // ebx@58
  const unsigned __int8 *v21; // eax@63
  unsigned __int8 *v22; // eax@67
  int found_break; // [sp+10h] [bp-170h]@10
  int found_return; // [sp+14h] [bp-16Ch]@10
  void *dc; // [sp+18h] [bp-168h]@6
  int found_space; // [sp+1Ch] [bp-164h]@10
  char *last_char; // [sp+20h] [bp-160h]@19
  signed __int16 last_chara; // [sp+20h] [bp-160h]@26
  TTextPanel *v29; // [sp+24h] [bp-15Ch]@1
  int max_wid; // [sp+28h] [bp-158h]@6
  char *next_char; // [sp+2Ch] [bp-154h]@30
  char *next_chara; // [sp+2Ch] [bp-154h]@31
  tagSIZE text_size; // [sp+30h] [bp-150h]@12
  int found_linefeed; // [sp+38h] [bp-148h]@10
  int found_bad_return; // [sp+3Ch] [bp-144h]@10
  int japanese; // [sp+40h] [bp-140h]@8
  void *old_font; // [sp+44h] [bp-13Ch]@8
  tagTEXTMETRICA tm; // [sp+48h] [bp-138h]@8
  char temp_text[256]; // [sp+80h] [bp-100h]@58

  v2 = (const unsigned __int8 *)text_in;
  v3 = 0;
  v4 = this;
  v29 = this;
  if( text_in && *text_in )
  {
    if( this->auto_scbar )
      v5 = this->full_width - this->scbar_width;
    else
      v5 = this->pnl_wid;
    max_wid = v5 - 10;
    v6 = TDrawArea::GetDc(this->render_area, aPnl_txtWord_wr);
    dc = v6;
    if( !v6 )
      return 0;
    old_font = SelectObject(v6, v4->font);
    GetTextMetricsA(v6, &tm);
    japanese = tm.tmCharSet == -128;
    while( 1 )
    {
      v8 = _mbslen(v2);
      v9 = *v2 == 10;
      found_return = 0;
      found_linefeed = 0;
      found_space = 0;
      found_break = 0;
      found_bad_return = 0;
      v10 = v2;
      if( v9 )
      {
        found_return = 1;
      }
      else
      {
        v3 = 1;
        v11 = (unsigned int)_mbsinc(v2);
        GetTextExtentPoint32A(dc, (LPCSTR)v2, (signed __int16)(v11 - (_WORD)v2), &text_size);
        v12 = 0;
        if( v8 >= 1 )
        {
          while( text_size.cx < max_wid )
          {
            if( *v10 == 10 )
            {
              --v3;
              found_return = 1;
              if( v12 && *v12 == 13 )
              {
                found_linefeed = 1;
                --v3;
              }
              break;
            }
            if( *v10 == 13 )
              found_bad_return = 1;
            last_char = (char *)v10;
            v13 = _mbsinc(v10);
            v10 = v13;
            ++v3;
            v14 = (unsigned int)_mbsinc(v13);
            GetTextExtentPoint32A(dc, (LPCSTR)v2, (signed __int16)(v14 - (_WORD)v2), &text_size);
            if( v3 > v8 )
              break;
            v12 = last_char;
          }
        }
      }
      if( !found_return )
      {
        GetTextExtentPoint32A(dc, (LPCSTR)v2, (signed __int16)strlen((const char *)v2), &text_size);
        if( text_size.cx <= max_wid )
          break;
        v3 = 1;
        v15 = (unsigned __int8 *)v2;
        last_chara = 1;
        if( v8 > 1 )
        {
          do
          {
            v16 = (unsigned int)_mbsinc(v15);
            GetTextExtentPoint32A(dc, (LPCSTR)v2, (signed __int16)(v16 - (_WORD)v2), &text_size);
            if( text_size.cx > max_wid )
              break;
            last_chara = v3++ - 1;
            v15 = _mbsinc(v15);
          }
          while( v3 < v8 );
        }
        while( v3 > 1 )
        {
          next_char = (char *)v15;
          v15 = _mbsdec(v2, v15);
          --v3;
          if( japanese )
          {
            v17 = TTextPanel::char_type((char *)v15);
            v18 = TTextPanel::char_type(next_char);
            next_chara = (char *)v18;
            if( !v17 && !v18 )
            {
              if( _ismbcspace(*v15) )
                goto LABEL_52;
              v18 = (signed int)next_chara;
            }
            if( v17 == 2 && v18 == 2
              || v17 == 1 && v18 == 1
              || !v17 && v18 == 2
              || v17 == 2 && !v18
              || !v17 && v18 == 1
              || v17 == 1 && !v18 )
            {
              found_break = 1;
              break;
            }
          }
          else if( _ismbcspace(*v15) )
          {
LABEL_52:
            found_space = 1;
            break;
          }
        }
        if( !found_space && !found_break )
        {
          v3 = last_chara;
          found_break = 1;
        }
        if( !found_space && !found_break )
          break;
      }
      memset(temp_text, 0, sizeof(temp_text));
      v19 = v3;
      _mbsncpy((unsigned __int8 *)temp_text, v2, v3);
      v20 = found_linefeed;
      if( found_linefeed )
        _mbscat((unsigned __int8 *)temp_text, (const unsigned __int8 *)::text_in);
      if( found_return )
        _mbscat((unsigned __int8 *)temp_text, (const unsigned __int8 *)::text_in);
      if( found_bad_return )
      {
        v21 = (const unsigned __int8 *)temp_text;
        if( temp_text[0] )
        {
          do
          {
            if( *v21 == 13 )
              *v21 = 32;
            v21 = _mbsinc(v21);
          }
          while( *v21 );
        }
      }
      TTextPanel::append_line(v29, temp_text, 0);
      v22 = _mbsninc(v2, v19);
      v2 = v22;
      if( v20 )
        v2 = _mbsinc(v22);
      if( found_return )
        v2 = _mbsinc(v2);
      v3 = 0;
    }
    TTextPanel::append_line(v29, (char *)v2, 0);
    SelectObject(dc, old_font);
    TDrawArea::ReleaseDc(v29->render_area, aPnl_txtWord_wr);
  }
  return 1;
}

//----- (0047CA70) --------------------------------------------------------
void __thiscall TTextPanel::set_text(TTextPanel *this, int string_id_in)
{
  TTextPanel *v2; // esi@1
  char str; // [sp+4h] [bp-1000h]@1

  v2 = this;
  TPanel::get_string(string_id_in, &str, 4096);
  (*(void (__thiscall **)(TTextPanel *, char *))&v2->vfptr[1].gap4[4])(v2, &str);
}

//----- (0047CAB0) --------------------------------------------------------
void __thiscall TTextPanel::set_text(TTextPanel *this, char **text_in, __int16 num_lines_in)
{
  TTextPanel *v3; // edi@1
  char **v4; // esi@5
  int v5; // ebx@5

  v3 = this;
  TTextPanel::free_text(this);
  if( num_lines_in )
  {
    if( num_lines_in > 0 )
    {
      v4 = text_in;
      v5 = num_lines_in;
      do
      {
        TTextPanel::append_line(v3, *v4, 0);
        ++v4;
        --v5;
      }
      while( v5 );
    }
  }
  else if( v3->fixed_len )
  {
    TTextPanel::append_line(v3, message_in, 0);
  }
}

//----- (0047CB10) --------------------------------------------------------
void __thiscall TTextPanel::set_font(TTextPanel *this, void *font_in, int font_wid_in, int font_hgt_in)
{
  TTextPanel *v4; // esi@1

  v4 = this;
  this->font_wid = font_wid_in;
  this->font = font_in;
  this->font_hgt = font_hgt_in;
  TTextPanel::calc_draw_info(this, 1);
  v4->vfptr->set_redraw((TPanel *)v4, RedrawNormal);
}

//----- (0047CB50) --------------------------------------------------------
void __thiscall TTextPanel::set_alignment(TTextPanel *this, TTextPanel::Alignment vert_align_in, TTextPanel::Alignment horz_align_in)
{
  TPanelVtbl *v3; // eax@1

  this->vert_align = vert_align_in;
  v3 = this->vfptr;
  this->horz_align = horz_align_in;
  ((void (__stdcall *)(signed int))v3->set_redraw)(1);
}

//----- (0047CB70) --------------------------------------------------------
void __thiscall TTextPanel::set_word_wrap(TTextPanel *this, int word_wrap_in)
{
  TPanelVtbl *v2; // edx@1

  v2 = this->vfptr;
  this->word_wrap = word_wrap_in;
  ((void (__stdcall *)(signed int))v2->set_redraw)(1);
}

//----- (0047CB90) --------------------------------------------------------
void __thiscall TTextPanel::set_style(TTextPanel *this, TTextPanel::Style text_style_in)
{
  TPanelVtbl *v2; // edx@1

  v2 = this->vfptr;
  this->text_style = text_style_in;
  ((void (__stdcall *)(signed int))v2->set_redraw)(1);
}

//----- (0047CBB0) --------------------------------------------------------
void __thiscall TTextPanel::set_text_color(TTextPanel *this, unsigned int text_color1_in, unsigned int text_color2_in)
{
  TPanelVtbl *v3; // eax@1

  this->text_color1 = text_color1_in;
  v3 = this->vfptr;
  this->text_color2 = text_color2_in;
  ((void (__stdcall *)(signed int))v3->set_redraw)(1);
}

//----- (0047CBD0) --------------------------------------------------------
void __thiscall TTextPanel::set_highlight_text_color(TTextPanel *this, unsigned int text_color1_in, unsigned int text_color2_in)
{
  TPanelVtbl *v3; // eax@1

  this->highlightTextColor1 = text_color1_in;
  v3 = this->vfptr;
  this->highlightTextColor2 = text_color2_in;
  ((void (__stdcall *)(signed int))v3->set_redraw)(1);
}

//----- (0047CBF0) --------------------------------------------------------
void __thiscall TTextPanel::set_fill_back(TTextPanel *this, int fill_back_in, char back_color_in)
{
  this->fill_back = fill_back_in;
  this->back_color = back_color_in;
}

//----- (0047CC10) --------------------------------------------------------
void __thiscall TTextPanel::set_back_pic(TTextPanel *this, char *back_pic_in)
{
  TTextPanel *v2; // esi@1
  TShape *v3; // edi@1
  TShape *v4; // eax@5
  TShape *v5; // eax@6
  int v6; // ecx@8
  int x_max; // [sp+Ch] [bp-1Ch]@8
  int x_min; // [sp+10h] [bp-18h]@8
  int y_max; // [sp+14h] [bp-14h]@8
  int y_min; // [sp+18h] [bp-10h]@8
  int v11; // [sp+24h] [bp-4h]@5

  v2 = this;
  v3 = this->back_pic;
  if( v3 )
  {
    TShape::~TShape(this->back_pic);
    operator delete(v3);
    v2->back_pic = 0;
    v2->back_pic_wid = 0;
    v2->back_pic_hgt = 0;
  }
  if( back_pic_in && *back_pic_in )
  {
    v4 = (TShape *)operator new(0x20u);
    v11 = 0;
    if( v4 )
      TShape::TShape(v4, back_pic_in, -1);
    else
      v5 = 0;
    v11 = -1;
    v2->back_pic = v5;
    TShape::shape_minmax(v5, &x_min, &y_min, &x_max, &y_max, 0);
    v6 = y_max - y_min + 1;
    v2->back_pic_wid = x_max - x_min + 1;
    v2->back_pic_hgt = v6;
  }
}

//----- (0047CCF0) --------------------------------------------------------
void __thiscall TTextPanel::set_outline(TTextPanel *this, int outline_in, char outline_color_in)
{
  TPanelVtbl *v3; // edx@2
  TPanelVtbl *v4; // edx@3

  this->outline = outline_in;
  if( outline_in )
  {
    v3 = this->vfptr;
    this->bevel_type = 1;
    this->outline_color = outline_color_in;
    ((void (__stdcall *)(signed int))v3->set_redraw)(1);
  }
  else
  {
    v4 = this->vfptr;
    this->bevel_type = 0;
    this->outline_color = outline_color_in;
    ((void (__stdcall *)(signed int))v4->set_redraw)(1);
  }
}

//----- (0047CD40) --------------------------------------------------------
void __thiscall TTextPanel::set_bevel_info(TTextPanel *this, int bevel_type_in, int c1, int c2, int c3, int c4, int c5, int c6)
{
  this->bevel_color1 = c1;
  this->bevel_color2 = c2;
  this->bevel_color3 = c3;
  this->bevel_color4 = c4;
  this->bevel_type = bevel_type_in;
  this->bevel_color5 = c5;
  this->bevel_color6 = c6;
  switch ( bevel_type_in )
  {
    case 1:
    case 2:
    case 5:
      this->border_size = 1;
      TTextPanel::calc_draw_info(this, 1);
      break;
    case 3:
    case 6:
      this->border_size = 2;
      TTextPanel::calc_draw_info(this, 1);
      break;
    case 4:
    case 7:
      this->border_size = 3;
      TTextPanel::calc_draw_info(this, 1);
      break;
    default:
      this->border_size = 0;
      TTextPanel::calc_draw_info(this, 1);
      break;
  }
}

//----- (0047CE00) --------------------------------------------------------
void __thiscall TTextPanel::set_spacer_size(TTextPanel *this, int size_in)
{
  this->spacer_size = size_in;
  TTextPanel::calc_draw_info(this, 1);
}

//----- (0047CE20) --------------------------------------------------------
void __thiscall TTextPanel::set_active(TTextPanel *this, int activ_in)
{
  TTextPanel *v2; // esi@1
  TPanelVtbl **v3; // ecx@2
  TPanelVtbl *v4; // edx@3

  v2 = this;
  TPanel::set_active((TPanel *)&this->vfptr, activ_in);
  if( v2->auto_scbar )
  {
    v3 = &v2->scbar_panel->vfptr;
    if( v3 )
    {
      v4 = *v3;
      if( v2->active )
        (*(void (__stdcall **)(int))&v4->gap10[4])(v2->scbar_active);
      else
        (*(void (__stdcall **)(_DWORD))&v4->gap10[4])(0);
    }
  }
}

//----- (0047CE70) --------------------------------------------------------
void __thiscall TTextPanel::calc_draw_info(TTextPanel *this, int update_scbar)
{
  TTextPanel *v2; // esi@1
  int v3; // eax@1
  signed int v4; // ecx@1
  int v5; // edx@3
  int v6; // eax@3
  signed int v7; // eax@4
  int v8; // edi@11
  int v9; // edx@11
  int v10; // ebx@11
  int v11; // eax@15
  TScrollBarPanel *v12; // ecx@23
  int v13; // eax@27
  int v14; // eax@29
  int v15; // eax@32

  v2 = this;
  v3 = this->font_hgt;
  v4 = v3 + 2;
  v2->text_hgt = v3 + 2;
  if( v3 )
  {
    v5 = v2->spacer_size;
    v6 = v2->border_size;
    if( v5 )
    {
      v7 = v2->pnl_hgt - 2 * v6;
      v4 = v4 + 2 * v5 - 1;
    }
    else
    {
      v7 = v2->pnl_hgt - 2 * v6;
    }
    v3 = v7 / v4;
    v2->draw_lines = v3;
  }
  else
  {
    v2->draw_lines = 1;
  }
  if( v2->draw_lines < 1 )
    v2->draw_lines = 1;
  LOWORD(v4) = v2->num_lines;
  if( v2->top_line >= (signed __int16)v4 )
    v2->top_line = v4 - 1;
  LOWORD(v3) = v2->draw_lines;
  v8 = v2->top_line;
  v9 = (signed __int16)v4;
  v10 = v2->draw_lines;
  if( (signed __int16)v4 - v8 < v10 )
  {
    v8 = v4 - v3;
    v2->top_line = v4 - v3;
  }
  if( v2->top_line < 0 )
    v2->top_line = 0;
  LOWORD(v8) = v2->top_line;
  v11 = v8 + v3 - 1;
  v2->bot_line = v11;
  if( (signed __int16)v11 < 0 )
    v2->bot_line = 0;
  if( v2->bot_line >= (signed __int16)v4 )
    v2->bot_line = v4 - 1;
  if( v2->cur_line < 0 )
    v2->cur_line = 0;
  if( v2->cur_line >= (signed __int16)v4 )
    v2->cur_line = v4 - 1;
  v12 = v2->scbar_panel;
  if( v12 )
  {
    if( update_scbar )
      TScrollBarPanel::set_list_len(v12, v9 - v10 + 1, (signed __int16)v8);
    if( v2->auto_scbar )
    {
      v13 = v2->scbar_active;
      if( v2->num_lines <= v2->draw_lines )
      {
        if( v13 )
        {
          TPanel::set_rect((TPanel *)&v2->vfptr, v2->pnl_x, v2->pnl_y, v2->full_width, v2->pnl_hgt);
          v15 = v2->active;
          v2->scbar_active = 0;
          if( v15 )
            (*(void (__stdcall **)(_DWORD))&v2->scbar_panel->vfptr->gap10[4])(0);
        }
      }
      else if( !v13 )
      {
        TPanel::set_rect((TPanel *)&v2->vfptr, v2->pnl_x, v2->pnl_y, v2->full_width - v2->scbar_width, v2->pnl_hgt);
        v14 = v2->active;
        v2->scbar_active = 1;
        if( v14 )
        {
          (*(void (__stdcall **)(signed int))&v2->scbar_panel->vfptr->gap10[4])(1);
          v2->text_wid = v2->pnl_wid;
          return;
        }
      }
    }
  }
  v2->text_wid = v2->pnl_wid;
}

//----- (0047D060) --------------------------------------------------------
void __thiscall TTextPanel::scroll(TTextPanel *this, char scroll_type, __int16 scroll_val, int update_scbar)
{
  TTextPanel *v4; // esi@1
  __int16 v5; // cx@3

  v4 = this;
  switch ( scroll_type )
  {
    case 0:
      this->top_line += scroll_val;
      break;
    case 1:
      v5 = scroll_val;
      goto LABEL_10;
    case 2:
      ++this->top_line;
      break;
    case 3:
      --this->top_line;
      break;
    case 4:
      this->top_line += this->draw_lines - 1;
      break;
    case 5:
      this->top_line += 1 - this->draw_lines;
      break;
    case 6:
      this->top_line = 0;
      break;
    case 7:
      v5 = this->num_lines - 1;
LABEL_10:
      v4->top_line = v5;
      break;
    default:
      break;
  }
  TTextPanel::calc_draw_info(v4, update_scbar);
  v4->vfptr->set_redraw((TPanel *)v4, RedrawNormal);
}

//----- (0047D120) --------------------------------------------------------
int __thiscall TTextPanel::key_down_action(TTextPanel *this, int key, int count, int alt_key, int ctrl_key, int shift_key)
{
  TTextPanel *v6; // esi@1
  TPanel *v7; // ecx@4
  int result; // eax@11
  char v9; // [sp-Ch] [bp-14h]@2
  char v10; // [sp-Ch] [bp-14h]@7
  __int16 v11; // [sp-8h] [bp-10h]@2
  __int16 v12; // [sp-8h] [bp-10h]@7

  v6 = this;
  switch ( key )
  {
    case 40:
      v11 = 0;
      v9 = 2;
      goto LABEL_4;
    case 38:
      v11 = 0;
      v9 = 3;
LABEL_4:
      TTextPanel::scroll(this, v9, v11, 1);
      v7 = v6->parent_panel;
      if( v7 && v6->tab_stop )
        goto LABEL_11;
      goto LABEL_14;
    case 34:
      v12 = 0;
      v10 = 4;
      goto LABEL_9;
    case 33:
      v12 = 0;
      v10 = 5;
LABEL_9:
      TTextPanel::scroll(this, v10, v12, 1);
      v7 = v6->parent_panel;
      if( !v7 || !v6->tab_stop )
        goto LABEL_14;
LABEL_11:
      ((void (__stdcall *)(int, int, int, int, int))v7->vfptr->key_down_action)(
        key,
        count,
        alt_key,
        ctrl_key,
        shift_key);
      result = 1;
      break;
    case 36:
      TTextPanel::scroll(this, 6, 0, 1);
      result = 1;
      break;
    case 35:
      TTextPanel::scroll(this, 7, 0, 1);
LABEL_14:
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

//----- (0047D200) --------------------------------------------------------
int __thiscall TTextPanel::action(TTextPanel *this, TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2)
{
  TScrollBarPanel *v5; // eax@1
  int result; // eax@4

  v5 = this->scbar_panel;
  if( v5 && (TScrollBarPanel *)from_panel == v5 )
  {
    switch ( action_in )
    {
      case 0:
        TTextPanel::scroll(this, 3, 0, 1);
        result = 1;
        break;
      case 1:
        TTextPanel::scroll(this, 2, 0, 1);
        result = 1;
        break;
      case 2:
        TTextPanel::scroll(this, 5, 0, 1);
        result = 1;
        break;
      case 3:
        TTextPanel::scroll(this, 4, 0, 1);
        result = 1;
        break;
      case 4:
        TTextPanel::scroll(this, 1, action_val1, 0);
        result = 1;
        break;
      default:
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    result = TPanel::action((TPanel *)&this->vfptr, from_panel, action_in, action_val1, action_val2);
  }
  return result;
}

//----- (0047D2C0) --------------------------------------------------------
void __thiscall TTextPanel::draw(TTextPanel *this)
{
  TTextPanel *v1; // esi@1
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
  if( v3 && this->visible && this->active )
  {
    TTextPanel::draw_background(this);
    v4 = v1->vfptr;
    v8 = v1->vfptr;
    v1->vfptr->draw_setup((TPanel *)v1, 0);
    v5 = TDrawArea::GetDc(v1->render_area, aPnl_txtDraw);
    if( v5 )
    {
      SelectClipRgn(v5, v1->clip_rgn);
      old_font = SelectObject(v5, v1->font);
      SetBkMode(v5, 1);
      for( i = v1->top_line; i <= v1->bot_line; ++v2 )
      {
        if( v1->tab_stop && v1->have_focus || v1->mouse_captured )
          TTextPanel::draw_line(v1, v5, v2, i, v1->highlightTextColor1, v1->highlightTextColor2);
        else
          TTextPanel::draw_line(v1, v5, v2, i, v1->text_color1, v1->text_color2);
        ++i;
      }
      SelectObject(v5, old_font);
      SelectClipRgn(v5, 0);
      TDrawArea::ReleaseDc(v1->render_area, aPnl_txtDraw);
      v4 = v8;
    }
    TTextPanel::draw_border(v1);
    v4->draw_finish((TPanel *)v1);
  }
}

//----- (0047D3D0) --------------------------------------------------------
void __thiscall TTextPanel::draw_background(TTextPanel *this)
{
  TTextPanel *v1; // esi@1
  int v2; // ebx@1
  signed int v3; // ecx@3
  signed int v4; // edi@3
  signed __int16 v5; // cx@4
  signed int v6; // edi@8
  signed int v7; // ebp@8
  int v8; // ebp@12
  int v9; // edi@14
  int v10; // ebx@14
  TPanel *v11; // ecx@22
  signed int v12; // eax@23
  int pic_cols; // [sp+10h] [bp-8h]@4
  int v14; // [sp+14h] [bp-4h]@12

  v1 = this;
  LOWORD(v2) = 0;
  if( this->back_pic )
  {
    if( TDrawArea::Lock(this->render_area, aPnl_txtDraw_ba, 1) )
    {
      v3 = v1->back_pic_wid;
      v4 = v1->pnl_wid;
      if( v3 < v4 )
      {
        pic_cols = v4 / v3;
        if( v3 * (signed __int16)(v4 / v3) < v4 )
          LOWORD(pic_cols) = pic_cols + 1;
        v5 = pic_cols;
      }
      else
      {
        v5 = 1;
        LOWORD(pic_cols) = 1;
      }
      v6 = v1->back_pic_hgt;
      v7 = v1->pnl_hgt;
      if( v6 >= v7 )
      {
        v2 = v7 / v6;
        if( v6 * (signed __int16)(v7 / v6) < v7 )
          LOWORD(v2) = v2 + 1;
      }
      if( (signed __int16)v2 > 0 )
      {
        v8 = 0;
        v14 = (signed __int16)v2;
        do
        {
          if( v5 > 0 )
          {
            v9 = 0;
            v10 = v5;
            do
            {
              TShape::shape_draw(
                v1->back_pic,
                v1->render_area,
                v1->pnl_x + v1->back_pic_wid * v9++,
                v1->pnl_y + v1->back_pic_hgt * v8,
                0,
                0,
                0);
              --v10;
            }
            while( v10 );
            v5 = pic_cols;
          }
          ++v8;
          --v14;
        }
        while( v14 );
      }
      TDrawArea::Unlock(v1->render_area, aPnl_txtDraw_ba);
    }
  }
  else if( this->fill_back )
  {
    if( TDrawArea::Lock(this->render_area, aPnl_txtDraw__1, 1) )
    {
      TDrawArea::FillRect(
        v1->render_area,
        v1->pnl_x,
        v1->pnl_y,
        v1->pnl_wid + v1->pnl_x - 1,
        v1->pnl_hgt + v1->pnl_y - 1,
        v1->back_color);
      TDrawArea::Unlock(v1->render_area, aPnl_txtDraw__1);
    }
  }
  else
  {
    v11 = this->parent_panel;
    if( v11 )
    {
      v12 = v1->bevel_type;
      if( v12 < 2 || v12 > 7 )
      {
        if( !v11->just_drawn )
          ((void (__stdcall *)(int))v11->vfptr->draw_rect)((int)&v1->clip_rect);
      }
      else
      {
        ((void (__stdcall *)(int))v11->vfptr->draw_rect2)((int)&v1->clip_rect);
      }
    }
  }
}

//----- (0047D570) --------------------------------------------------------
void __thiscall TTextPanel::draw_border(TTextPanel *this)
{
  TTextPanel *v1; // esi@1

  v1 = this;
  if( this->bevel_type )
  {
    if( TDrawArea::Lock(this->render_area, aPnl_txtDraw_bo, 1) )
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
          TDrawArea::Unlock(v1->render_area, aPnl_txtDraw_bo);
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
          TDrawArea::Unlock(v1->render_area, aPnl_txtDraw_bo);
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
          TDrawArea::Unlock(v1->render_area, aPnl_txtDraw_bo);
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
    TDrawArea::Unlock(v1->render_area, aPnl_txtDraw_bo);
  }
}

//----- (0047D760) --------------------------------------------------------
void __thiscall TTextPanel::draw_line(TTextPanel *this, void *dc, __int16 draw_row, __int16 text_line, unsigned int color1, unsigned int color2)
{
  TTextPanel *v6; // ebp@1
  const char *v7; // ebx@1
  const char *v8; // eax@1
  TTextPanel::Alignment v9; // eax@7
  int v10; // edi@10
  TTextPanel::Style v11; // eax@12
  int v12; // eax@13
  TTextPanel::Style v13; // eax@28
  int v14; // eax@29
  __int16 text_len; // [sp+10h] [bp-20h]@1
  char *temp_text2; // [sp+14h] [bp-1Ch]@1
  __int16 text2_len; // [sp+18h] [bp-18h]@1
  TTextPanel *v18; // [sp+1Ch] [bp-14h]@1
  tagRECT line_rect; // [sp+20h] [bp-10h]@7
  int draw_rowa; // [sp+38h] [bp+8h]@10
  int x2; // [sp+3Ch] [bp+Ch]@7

  v6 = this;
  v18 = this;
  text_len = 0;
  text2_len = 0;
  v7 = TTextPanel::get_text(this, text_line);
  v8 = TTextPanel::get_text2(v6, text_line);
  temp_text2 = (char *)v8;
  if( v7 )
  {
    text_len = strlen(v7);
  }
  else if( !v8 )
  {
    return;
  }
  if( v8 )
    text2_len = strlen(v8);
  TTextPanel::calc_line_pos(v6, dc, draw_row, text_line, &line_rect, 0);
  v9 = v6->horz_align;
  x2 = line_rect.left;
  if( v9 && v9 != 6 )
    x2 = line_rect.left + 5;
  v10 = line_rect.top;
  draw_rowa = x2 + v6->second_column_pos;
  if( v6->clip_rgn2 )
    SelectClipRgn(dc, v6->clip_rgn2);
  v11 = v6->text_style;
  if( v11 )
  {
    v12 = v11 - 1;
    if( v12 )
    {
      if( v12 == 1 )
      {
        SetTextColor(dc, color2);
        if( v7 )
          TextOutA(dc, x2 - 1, v10 + 1, (LPCSTR)v7, text_len);
        SetTextColor(dc, color1);
        if( v7 )
          TextOutA(dc, x2, v10, (LPCSTR)v7, text_len);
      }
      goto LABEL_25;
    }
    SetTextColor(dc, color1);
    if( v7 )
      TextOutA(dc, x2 - 1, v10 + 1, (LPCSTR)v7, text_len);
    SetTextColor(dc, color2);
    if( !v7 )
      goto LABEL_25;
  }
  else
  {
    SetTextColor(dc, color1);
    if( !v7 )
      goto LABEL_25;
  }
  TextOutA(dc, x2, v10, (LPCSTR)v7, text_len);
LABEL_25:
  if( temp_text2 )
  {
    if( v18->clip_rgn2 )
      SelectClipRgn(dc, v18->clip_rgn);
    v13 = v18->text_style;
    if( v13 )
    {
      v14 = v13 - 1;
      if( v14 )
      {
        if( v14 == 1 )
        {
          SetTextColor(dc, color2);
          TextOutA(dc, draw_rowa - 1, v10 + 1, temp_text2, text2_len);
          SetTextColor(dc, color1);
          TextOutA(dc, draw_rowa, v10, temp_text2, text2_len);
        }
      }
      else
      {
        SetTextColor(dc, color1);
        TextOutA(dc, draw_rowa - 1, v10 + 1, temp_text2, text2_len);
        SetTextColor(dc, color2);
        TextOutA(dc, draw_rowa, v10, temp_text2, text2_len);
      }
    }
    else
    {
      SetTextColor(dc, color1);
      TextOutA(dc, draw_rowa, v10, temp_text2, text2_len);
    }
  }
}

//----- (0047D9E0) --------------------------------------------------------
void __thiscall TTextPanel::calc_line_pos(TTextPanel *this, void *dc, __int16 draw_row, __int16 text_line, tagRECT *line_rect, int *cursor_x_offset)
{
  TTextPanel *v6; // esi@1
  const unsigned __int8 *v7; // eax@1
  const unsigned __int8 *v8; // ebx@1
  int v9; // ecx@1
  __int16 v10; // ax@4
  __int16 v11; // dx@4
  int v12; // ebp@8
  TTextPanel::Alignment v13; // eax@10
  int v14; // eax@13
  int v15; // eax@14
  int v16; // edi@16
  int v17; // eax@16
  int v18; // edi@17
  int v19; // eax@17
  int v20; // eax@22
  int v21; // ebx@23
  __int64 v22; // rax@27
  int v23; // ecx@27
  int v24; // ecx@28
  int col_offset; // [sp+10h] [bp-10Ch]@3
  tagSIZE text_size; // [sp+14h] [bp-108h]@5
  char temp_text2[256]; // [sp+1Ch] [bp-100h]@6

  v6 = this;
  v7 = (const unsigned __int8 *)TTextPanel::get_text(this, text_line);
  v8 = v7;
  v9 = 0;
  if( v7 )
  {
    if( v6->cur_col )
    {
      v10 = _mbslen(v7);
      v11 = v6->cur_col;
      if( v11 <= v10 )
      {
        memset(temp_text2, 0, sizeof(temp_text2));
        _mbsncpy((unsigned __int8 *)temp_text2, v8, v11);
        GetTextExtentPoint32A(dc, (LPCSTR)v8, (signed __int16)strlen(temp_text2), &text_size);
      }
      else
      {
        GetTextExtentPoint32A(dc, (LPCSTR)v8, (signed __int16)strlen((const char *)v8), &text_size);
      }
      col_offset = text_size.cx;
    }
    else
    {
      col_offset = 0;
    }
    _mbslen(v8);
    GetTextExtentPoint32A(dc, (LPCSTR)v8, (signed __int16)strlen((const char *)v8), &text_size);
    v12 = text_size.cx;
    v9 = col_offset;
  }
  else
  {
    col_offset = 0;
    v12 = 0;
  }
  v13 = v6->horz_align;
  if( v13 && v13 != 6 )
  {
    v9 += 5;
    col_offset = v9;
  }
  v14 = v13 - 1;
  if( !v14 )
  {
    v16 = v6->pnl_x;
    v17 = v6->border_size;
    goto LABEL_21;
  }
  v15 = v14 - 1;
  if( !v15 )
  {
    v18 = v6->pnl_wid + v6->pnl_x - v6->border_size - v12 - 7;
    goto LABEL_22;
  }
  if( v15 != 3 )
  {
    v16 = v6->pnl_x - v12 / 2;
    v17 = v6->pnl_wid / 2;
LABEL_21:
    v18 = v17 + v16;
    goto LABEL_22;
  }
  v18 = v6->border_size + v6->pnl_x;
  v19 = v6->pnl_wid;
  if( v9 + 1 >= v19 )
    v18 = v18 + v19 - v9 - 2;
LABEL_22:
  v20 = v6->spacer_size;
  if( v20 )
    v21 = v6->text_hgt + 2 * v20 - 1;
  else
    v21 = v6->text_hgt;
  if( v6->vert_align == 3 )
  {
    v23 = v6->border_size + v6->pnl_y + v21 * draw_row;
  }
  else
  {
    if( v6->vert_align == 4 )
    {
      v24 = v6->pnl_hgt + v6->pnl_y - v21 * (v6->num_lines - draw_row) - v6->border_size - v20 - 1;
      goto LABEL_31;
    }
    v22 = v21 * v6->num_lines;
    v23 = v6->pnl_y + v21 * draw_row - (((signed int)v22 - HIDWORD(v22)) >> 1);
    v20 = v6->pnl_hgt / 2;
  }
  v24 = v20 + v23;
LABEL_31:
  line_rect->left = v18;
  line_rect->top = v24;
  line_rect->right = v12 + v18 - 1;
  line_rect->bottom = v6->text_hgt + v24;
  if( cursor_x_offset )
    *cursor_x_offset = col_offset;
}

//----- (0047DC10) --------------------------------------------------------
int __thiscall TTextPanel::mouse_left_down_action(TTextPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TPanel *v5; // eax@1

  v5 = this->parent_panel;
  if( v5 )
    v5->vfptr->action(v5, (TPanel *)this, 1, 0, 0);
  return 0;
}

//----- (0047DC30) --------------------------------------------------------
int __thiscall TTextPanel::numberLines(TTextPanel *this)
{
  return this->num_lines;
}

//----- (0047DC40) --------------------------------------------------------
int __thiscall TTextPanel::numberDrawLines(TTextPanel *this)
{
  return this->draw_lines;
}

//----- (0047DC50) --------------------------------------------------------
int __thiscall TTextPanel::currentLineNumber(TTextPanel *this)
{
  return this->cur_line;
}

//----- (0047DC60) --------------------------------------------------------
void __thiscall TTextPanel::setCurrentLineNumber(TTextPanel *this, int v)
{
  TTextPanel::set_line(this, v);
}

//----- (0047DC80) --------------------------------------------------------
void __thiscall TTextPanel::set_line(TTextPanel *this, int line_in)
{
  this->cur_line = line_in;
  TTextPanel::calc_draw_info(this, 1);
}

//----- (0047DCA0) --------------------------------------------------------
void __thiscall TTextPanel::set_line_by_id(TTextPanel *this, int id_in)
{
  TTextPanel::TextNode *v2; // eax@1
  int v3; // edx@1

  v2 = this->list;
  v3 = 0;
  if( v2 )
  {
    while( v2->id != id_in )
    {
      v2 = v2->next_node;
      ++v3;
      if( !v2 )
        return;
    }
    TTextPanel::set_line(this, v3);
  }
}

//----- (0047DCD0) --------------------------------------------------------
void *__thiscall TTextPanel::append_line(TTextPanel *this, char *text_in, int id_in)
{
  return TTextPanel::insert_line(this, this->num_lines, text_in, id_in);
}

//----- (0047DCF0) --------------------------------------------------------
void *__thiscall TTextPanel::append_line(TTextPanel *this, char *text_in, char *text2_in, int id_in)
{
  return TTextPanel::insert_line(this, this->num_lines, text_in, text2_in, id_in);
}

//----- (0047DD10) --------------------------------------------------------
void *__thiscall TTextPanel::append_line(TTextPanel *this, int string_id_in, int id_in)
{
  return TTextPanel::insert_line(this, this->num_lines, string_id_in, id_in);
}

//----- (0047DD30) --------------------------------------------------------
void *__thiscall TTextPanel::append_line(TTextPanel *this, int string_id_in, int string_id2_in, int id_in)
{
  return TTextPanel::insert_line(this, this->num_lines, string_id_in, string_id2_in, id_in);
}

//----- (0047DD50) --------------------------------------------------------
void *__thiscall TTextPanel::insert_line(TTextPanel *this, int line_in, char *text_in, int id_in)
{
  return TTextPanel::insert_line(this, line_in, text_in, 0, id_in);
}

//----- (0047DD70) --------------------------------------------------------
void *__thiscall TTextPanel::insert_line(TTextPanel *this, int line_in, char *text_in, char *text2_in, int id_in)
{
  TTextPanel *v5; // esi@1
  void *result; // eax@1
  int v7; // ebx@1
  __int16 v8; // ax@2
  void *v9; // eax@7
  void *v10; // eax@10
  TTextPanel *v11; // edi@14
  __int16 v12; // ax@14
  int v13; // ecx@20
  TTextPanel::TextNode *v14; // eax@20
  TTextPanel::TextNode *v15; // esi@23
  TTextPanel::TextNode *v16; // ebp@23
  TTextPanel::TextNode *v17; // ecx@37
  size_t v18; // [sp-8h] [bp-1Ch]@3
  TTextPanel *v19; // [sp+10h] [bp-4h]@1

  v5 = this;
  v19 = this;
  result = calloc(1u, 0x10u);
  v7 = (int)result;
  if( !result )
    return result;
  v8 = v5->fixed_len;
  if( v8 )
  {
    v18 = v8 + 1;
  }
  else if( text_in )
  {
    v18 = strlen(text_in) + 1;
  }
  else
  {
    v18 = 1;
  }
  v9 = calloc(v18, 1u);
  *(_DWORD *)v7 = v9;
  if( !v9 )
  {
    free((void *)v7);
    return 0;
  }
  if( text2_in )
  {
    v10 = calloc(strlen(text2_in) + 1, 1u);
    *(_DWORD *)(v7 + 4) = v10;
    if( !v10 )
    {
      free(*(void **)v7);
      free((void *)v7);
      return 0;
    }
  }
  if( !text_in )
  {
    **(_BYTE **)v7 = 0;
LABEL_17:
    v11 = v19;
    goto LABEL_18;
  }
  v11 = v19;
  v12 = v19->fixed_len;
  if( !v12 )
  {
    strcpy(*(char **)v7, text_in);
    goto LABEL_17;
  }
  strncpy(*(char **)v7, text_in, v12);
  *(_BYTE *)(*(_DWORD *)v7 + v19->fixed_len) = 0;
LABEL_18:
  if( text2_in )
  {
    strcpy(*(char **)(v7 + 4), text2_in);
    v11 = v19;
  }
  *(_DWORD *)(v7 + 8) = id_in;
  v13 = 0;
  *(_DWORD *)(v7 + 12) = 0;
  v14 = v11->list;
  if( v14 )
  {
    if( v11->sorted )
    {
      v15 = v11->list;
      v16 = 0;
      if( !v14 )
        goto LABEL_44;
      while( CompareStringA(0x400u, 1u, *(PCNZCH *)v7, -1, v15->text, -1) != 1 )
      {
        v16 = v15;
        v15 = v15->next_node;
        if( !v15 )
          goto LABEL_30;
      }
      *(_DWORD *)(v7 + 12) = v15;
      if( v16 )
        v16->next_node = (TTextPanel::TextNode *)v7;
      else
        v19->list = (TTextPanel::TextNode *)v7;
LABEL_30:
      if( !v15 )
LABEL_44:
        v16->next_node = (TTextPanel::TextNode *)v7;
      v11 = v19;
    }
    else if( line_in )
    {
      if( line_in < v11->num_lines )
      {
        while( v13 != line_in - 1 )
        {
          v14 = v14->next_node;
          ++v13;
        }
        *(_DWORD *)(v7 + 12) = v14->next_node;
        v14->next_node = (TTextPanel::TextNode *)v7;
      }
      else
      {
        do
        {
          v17 = v14;
          v14 = v14->next_node;
        }
        while( v14 );
        v17->next_node = (TTextPanel::TextNode *)v7;
      }
    }
    else
    {
      *(_DWORD *)(v7 + 12) = v14;
      v11->list = (TTextPanel::TextNode *)v7;
    }
  }
  else
  {
    v11->list = (TTextPanel::TextNode *)v7;
  }
  ++v11->num_lines;
  TTextPanel::calc_draw_info(v11, 1);
  v11->vfptr->set_redraw((TPanel *)v11, RedrawNormal);
  return (void *)1;
}

//----- (0047DF90) --------------------------------------------------------
void *__thiscall TTextPanel::insert_line(TTextPanel *this, int line_in, int string_id_in, int id_in)
{
  TTextPanel *v4; // esi@1
  char str[256]; // [sp+4h] [bp-100h]@1

  v4 = this;
  TPanel::get_string(string_id_in, str, 256);
  return TTextPanel::insert_line(v4, line_in, str, id_in);
}

//----- (0047DFE0) --------------------------------------------------------
void *__thiscall TTextPanel::insert_line(TTextPanel *this, int line_in, int string_id_in, int string_id2_in, int id_in)
{
  TTextPanel *v5; // esi@1
  char str2[256]; // [sp+4h] [bp-200h]@1
  char str1[256]; // [sp+104h] [bp-100h]@1

  v5 = this;
  TPanel::get_string(string_id_in, str1, 256);
  TPanel::get_string(string_id2_in, str2, 256);
  return TTextPanel::insert_line(v5, line_in, str1, str2, id_in);
}

//----- (0047E050) --------------------------------------------------------
void *__thiscall TTextPanel::change_line(TTextPanel *this, int line_in, char *text_in, char *text2_in, int id_in)
{
  TTextPanel *v5; // esi@1
  int v6; // edi@1
  void *result; // eax@1

  v5 = this;
  v6 = this->sorted;
  this->sorted = 0;
  result = TTextPanel::insert_line(this, line_in, text_in, text2_in, id_in);
  if( result )
  {
    TTextPanel::delete_line(v5, line_in + 1);
    v5->sorted = v6;
    result = (void *)1;
  }
  else
  {
    v5->sorted = v6;
  }
  return result;
}

//----- (0047E0B0) --------------------------------------------------------
void *__thiscall TTextPanel::change_line(TTextPanel *this, int line_in, int string_id_in, int string_id2_in, int id_in)
{
  TTextPanel *v5; // esi@1
  int v6; // edi@1
  void *result; // eax@1

  v5 = this;
  v6 = this->sorted;
  this->sorted = 0;
  result = TTextPanel::insert_line(this, line_in, string_id_in, string_id2_in, id_in);
  if( result )
  {
    TTextPanel::delete_line(v5, line_in + 1);
    v5->sorted = v6;
    result = (void *)1;
  }
  else
  {
    v5->sorted = v6;
  }
  return result;
}

//----- (0047E110) --------------------------------------------------------
int __thiscall TTextPanel::delete_line(TTextPanel *this, int line_in)
{
  TTextPanel *v2; // esi@1
  TTextPanel::TextNode *v3; // edi@4
  TTextPanel::TextNode *v4; // eax@5
  int i; // ecx@5
  __int16 v6; // ax@14
  int result; // eax@18

  v2 = this;
  if( line_in < 0 || line_in > this->num_lines - 1 )
    goto LABEL_22;
  if( line_in )
  {
    v4 = this->list;
    for( i = 0; i != line_in - 1; ++i )
      v4 = v4->next_node;
    v3 = v4->next_node;
    v4->next_node = v3->next_node;
  }
  else
  {
    v3 = this->list;
    this->list = v3->next_node;
  }
  if( v3 )
  {
    if( v3->text )
      free(v3->text);
    if( v3->text2 )
      free(v3->text2);
    free(v3);
    v6 = --v2->num_lines;
    if( v6 )
    {
      if( v2->cur_line >= v6 )
        v2->cur_line = v6 - 1;
    }
    else
    {
      v2->cur_line = 0;
    }
    TTextPanel::calc_draw_info(v2, 1);
    v2->vfptr->set_redraw((TPanel *)v2, RedrawNormal);
    result = 1;
  }
  else
  {
LABEL_22:
    result = 0;
  }
  return result;
}

//----- (0047E1E0) --------------------------------------------------------
int __thiscall TTextPanel::get_line(TTextPanel *this)
{
  int result; // eax@2

  if( this->num_lines )
    result = this->cur_line;
  else
    result = -1;
  return result;
}

//----- (0047E200) --------------------------------------------------------
int __thiscall TTextPanel::get_line(TTextPanel *this, int id_in)
{
  TTextPanel::TextNode *v2; // ecx@1
  int result; // eax@1

  v2 = this->list;
  result = 0;
  if( v2 )
  {
    while( v2->id != id_in )
    {
      v2 = v2->next_node;
      ++result;
      if( !v2 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    result = -1;
  }
  return result;
}

//----- (0047E230) --------------------------------------------------------
int __thiscall TTextPanel::get_line(TTextPanel *this, char *text_in)
{
  TTextPanel::TextNode *v2; // edi@1
  int result; // eax@1

  v2 = this->list;
  result = 0;
  if( v2 )
  {
    while( strcmp(v2->text, text_in) )
    {
      v2 = v2->next_node;
      ++result;
      if( !v2 )
        goto LABEL_4;
    }
  }
  else
  {
LABEL_4:
    result = -1;
  }
  return result;
}

//----- (0047E290) --------------------------------------------------------
char *__thiscall TTextPanel::get_text(TTextPanel *this)
{
  return TTextPanel::get_text(this, this->cur_line);
}

//----- (0047E2A0) --------------------------------------------------------
char *__thiscall TTextPanel::get_text(TTextPanel *this, int line_in)
{
  TTextPanel::TextNode *v2; // eax@1
  int v3; // edx@1
  char *result; // eax@4

  v2 = this->list;
  v3 = 0;
  if( v2 )
  {
    while( v3 != line_in )
    {
      v2 = v2->next_node;
      ++v3;
      if( !v2 )
      {
        empty_text_0 = 0;
        return &empty_text_0;
      }
    }
    result = v2->text;
  }
  else
  {
    empty_text_0 = 0;
    result = &empty_text_0;
  }
  return result;
}

//----- (0047E2E0) --------------------------------------------------------
char *__thiscall TTextPanel::get_text2(TTextPanel *this)
{
  return TTextPanel::get_text2(this, this->cur_line);
}

//----- (0047E2F0) --------------------------------------------------------
char *__thiscall TTextPanel::get_text2(TTextPanel *this, int line_in)
{
  TTextPanel::TextNode *v2; // eax@1
  int v3; // edx@1
  char *result; // eax@4

  v2 = this->list;
  v3 = 0;
  if( v2 )
  {
    while( v3 != line_in )
    {
      v2 = v2->next_node;
      ++v3;
      if( !v2 )
      {
        empty_text = 0;
        return &empty_text;
      }
    }
    result = v2->text2;
  }
  else
  {
    empty_text = 0;
    result = &empty_text;
  }
  return result;
}

//----- (0047E330) --------------------------------------------------------
int __thiscall TTextPanel::get_id(TTextPanel *this)
{
  return TTextPanel::get_id(this, this->cur_line);
}

//----- (0047E340) --------------------------------------------------------
int __thiscall TTextPanel::get_id(TTextPanel *this, int line_in)
{
  TTextPanel::TextNode *v2; // eax@1
  int v3; // edx@1
  int result; // eax@4

  v2 = this->list;
  v3 = 0;
  if( v2 )
  {
    while( v3 != line_in )
    {
      v2 = v2->next_node;
      ++v3;
      if( !v2 )
        return -1;
    }
    result = v2->id;
  }
  else
  {
    result = -1;
  }
  return result;
}

//----- (0047E380) --------------------------------------------------------
void __thiscall TTextPanel::free_text(TTextPanel *this)
{
  TTextPanel *v1; // ebx@1
  TTextPanel::TextNode *v2; // esi@1
  TTextPanel::TextNode *v3; // eax@6

  v1 = this;
  v2 = this->list;
  if( v2 )
  {
    do
    {
      if( v2->text )
        free(v2->text);
      if( v2->text2 )
        free(v2->text2);
      v3 = v2;
      v2 = v2->next_node;
      free(v3);
    }
    while( v2 );
    v1->list = 0;
  }
  v1->num_lines = 0;
  TTextPanel::calc_draw_info(v1, 1);
  v1->vfptr->set_redraw((TPanel *)v1, RedrawNormal);
}

//----- (0047E3F0) --------------------------------------------------------
void __thiscall TTextPanel::set_second_column_pos(TTextPanel *this, int val)
{
  TPanelVtbl *v2; // edx@1

  v2 = this->vfptr;
  this->second_column_pos = val;
  ((void (__stdcall *)(signed int))v2->set_redraw)(1);
}

//----- (0047E410) --------------------------------------------------------
int __thiscall TTextPanel::get_text_rect(TTextPanel *this, tagRECT *rect)
{
  TTextPanel *v2; // esi@1
  void *v3; // edi@1
  HGDIOBJ v4; // ebp@2
  int result; // eax@2

  v2 = this;
  v3 = TDrawArea::GetDc(this->render_area, aPnl_txtGet_tex);
  if( v3 )
  {
    v4 = SelectObject(v3, v2->font);
    TTextPanel::calc_line_pos(v2, v3, 0, 0, rect, 0);
    SelectObject(v3, v4);
    TDrawArea::ReleaseDc(v2->render_area, aPnl_txtGet_tex);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
