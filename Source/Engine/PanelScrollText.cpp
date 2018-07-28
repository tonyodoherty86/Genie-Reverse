
//----- (00492E70) --------------------------------------------------------
void __thiscall TScrollTextPanel::TScrollTextPanel(TScrollTextPanel *this, TPanel *parent_in, TDrawArea *render_area_in, int x, int y, int wid, int hgt, int speed_in, void *font_in, int font_wid_in, int font_hgt_in, char *text_in)
{
  TScrollTextPanel *v12; // esi@1

  v12 = this;
  TTextPanel::TTextPanel((TTextPanel *)&this->vfptr);
  v12->speed = speed_in;
  v12->vfptr = (TPanelVtbl *)&TScrollTextPanel::`vftable';
  v12->scroll = 0;
  v12->last_time = 0;
  v12->done = 0;
  if( TTextPanel::setup(
         (TTextPanel *)&v12->vfptr,
         render_area_in,
         parent_in,
         x,
         y,
         wid,
         hgt,
         font_in,
         font_wid_in,
         font_hgt_in,
         0,
         0,
         0,
         0,
         0,
         0,
         0) )
  {
    TTextPanel::set_alignment((TTextPanel *)&v12->vfptr, AlignTop, 0);
    TTextPanel::set_word_wrap((TTextPanel *)&v12->vfptr, 1);
    TScrollTextPanel::set_text(v12, text_in);
    TTextPanel::set_text_color((TTextPanel *)&v12->vfptr, v12->text_color1, v12->text_color2);
  }
}
// 572878: using guessed type int (__thiscall *TScrollTextPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00492F50) --------------------------------------------------------
TScrollTextPanel *__thiscall TScrollTextPanel::`vector deleting destructor'(TScrollTextPanel *this, unsigned int __flags)
{
  TScrollTextPanel *v2; // esi@1

  v2 = this;
  TScrollTextPanel::~TScrollTextPanel(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00492F70) --------------------------------------------------------
void __thiscall TScrollTextPanel::~TScrollTextPanel(TScrollTextPanel *this)
{
  this->vfptr = (TPanelVtbl *)&TScrollTextPanel::`vftable';
  TTextPanel::~TTextPanel((TTextPanel *)&this->vfptr);
}
// 572878: using guessed type int (__thiscall *TScrollTextPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00492F80) --------------------------------------------------------
void __thiscall TScrollTextPanel::set_text(TScrollTextPanel *this, char *text_in)
{
  TScrollTextPanel *v2; // esi@1

  v2 = this;
  TTextPanel::set_text((TTextPanel *)&this->vfptr, text_in);
  v2->last_time = 0;
  v2->scroll = 0;
  v2->done = 0;
}

//----- (00492FB0) --------------------------------------------------------
int __thiscall TScrollTextPanel::handle_idle(TScrollTextPanel *this)
{
  TScrollTextPanel *v1; // esi@1
  unsigned int v2; // eax@3
  unsigned int v3; // edi@3
  signed __int64 v4; // rax@3
  TPanel *v5; // ecx@6

  v1 = this;
  if( this->last_time )
  {
    v2 = debug_timeGetTime();
    v3 = v2;
    v4 = (signed __int64)((double)(v2 - v1->last_time) * 0.001 * (double)v1->speed);
    if( (signed int)v4 > 0 )
    {
      HIDWORD(v4) = v1->vfptr;
      v1->scroll += v4;
      (*(void (__thiscall **)(TScrollTextPanel *, signed int))(HIDWORD(v4) + 32))(v1, 1);
      v1->last_time = v3;
    }
  }
  else
  {
    this->last_time = debug_timeGetTime();
  }
  if( v1->done )
  {
    v5 = v1->parent_panel;
    if( v5 )
      ((void (__stdcall *)(TScrollTextPanel *, signed int, _DWORD, _DWORD))v5->vfptr->action)(v1, 1, 0, 0);
  }
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}

//----- (00493070) --------------------------------------------------------
void __thiscall TScrollTextPanel::draw(TScrollTextPanel *this)
{
  TScrollTextPanel *v1; // esi@1
  TDrawArea *v2; // eax@1
  TPanelVtbl *v3; // ebx@4
  void *v4; // edi@4
  __int16 v5; // bx@5
  HGDIOBJ old_font; // [sp+4h] [bp-8h]@5
  TPanelVtbl *v7; // [sp+8h] [bp-4h]@4

  v1 = this;
  v2 = this->render_area;
  this->need_redraw = 0;
  if( v2 && this->visible && this->active )
  {
    TTextPanel::draw_background((TTextPanel *)&this->vfptr);
    v3 = v1->vfptr;
    v7 = v1->vfptr;
    v1->vfptr->draw_setup((TPanel *)v1, 0);
    v4 = TDrawArea::GetDc(v1->render_area, aScr_credDraw);
    if( v4 )
    {
      SelectClipRgn(v4, v1->clip_rgn);
      old_font = SelectObject(v4, v1->font);
      SetBkMode(v4, 1);
      v5 = 0;
      if( v1->num_lines > 0 )
      {
        do
        {
          TScrollTextPanel::draw_scrolled_line(v1, v4, v5, v5, v1->text_color1, v1->text_color2);
          ++v5;
        }
        while( v5 < v1->num_lines );
      }
      SelectObject(v4, old_font);
      SelectClipRgn(v4, 0);
      TDrawArea::ReleaseDc(v1->render_area, aScr_credDraw);
      v3 = v7;
    }
    TTextPanel::draw_border((TTextPanel *)&v1->vfptr);
    v3->draw_finish((TPanel *)v1);
  }
}

//----- (00493160) --------------------------------------------------------
void __thiscall TScrollTextPanel::draw_scrolled_line(TScrollTextPanel *this, void *dc, __int16 draw_row, __int16 text_line, unsigned int color1, unsigned int color2)
{
  TScrollTextPanel *v6; // ebx@1
  const char *v7; // ebp@1
  const char *v8; // eax@1
  TTextPanel::Alignment v9; // eax@7
  int v10; // edi@10
  TTextPanel::Style v11; // eax@15
  int v12; // eax@16
  TTextPanel::Style v13; // eax@31
  int v14; // eax@32
  __int16 text_len; // [sp+10h] [bp-24h]@1
  char *temp_text2; // [sp+14h] [bp-20h]@1
  __int16 text2_len; // [sp+18h] [bp-1Ch]@1
  int v18; // [sp+1Ch] [bp-18h]@1
  TScrollTextPanel *v19; // [sp+20h] [bp-14h]@1
  tagRECT line_rect; // [sp+24h] [bp-10h]@7
  int draw_rowa; // [sp+3Ch] [bp+8h]@10
  int x2; // [sp+40h] [bp+Ch]@7

  v6 = this;
  v19 = this;
  text_len = 0;
  text2_len = 0;
  v18 = text_line;
  v7 = TTextPanel::get_text((TTextPanel *)&this->vfptr, text_line);
  v8 = TTextPanel::get_text2((TTextPanel *)&v6->vfptr, text_line);
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
  TTextPanel::calc_line_pos((TTextPanel *)&v6->vfptr, dc, draw_row, text_line, &line_rect, 0);
  v9 = v6->horz_align;
  x2 = line_rect.left;
  if( v9 && v9 != 6 )
    x2 = line_rect.left + 5;
  draw_rowa = x2 + v6->second_column_pos;
  v10 = line_rect.top + v6->pnl_hgt - v6->scroll;
  if( v18 == v6->num_lines - 1 && v10 + v6->font_hgt < v6->pnl_y )
    v6->done = 1;
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
      goto LABEL_28;
    }
    SetTextColor(dc, color1);
    if( v7 )
      TextOutA(dc, x2 - 1, v10 + 1, (LPCSTR)v7, text_len);
    SetTextColor(dc, color2);
    if( !v7 )
      goto LABEL_28;
  }
  else
  {
    SetTextColor(dc, color1);
    if( !v7 )
      goto LABEL_28;
  }
  TextOutA(dc, x2, v10, (LPCSTR)v7, text_len);
LABEL_28:
  if( temp_text2 )
  {
    if( v19->clip_rgn2 )
      SelectClipRgn(dc, v19->clip_rgn);
    v13 = v19->text_style;
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
