
//----- (00478F40) --------------------------------------------------------
void __thiscall TMessagePanel::TMessagePanel(TMessagePanel *this, void *font_in, int font_wid_in, int font_hgt_in)
{
  TMessagePanel *v4; // esi@1

  v4 = this;
  TPanel::TPanel((TPanel *)&this->vfptr);
  v4->font = font_in;
  v4->font_hgt = font_hgt_in;
  v4->LastIBWidth = -1;
  v4->LastIBHeight = -1;
  v4->message_type = 0;
  v4->showing_message = 0;
  v4->start_time = 0;
  v4->show_message_interval = 8000;
  v4->font_wid = font_wid_in;
  v4->font_color = 0;
  v4->back_color = 0;
  v4->horz_just = 2;
  v4->vert_just = 0;
  v4->word_wrap = 0;
  v4->image_clip_region = 0;
  v4->ImageBuffer = 0;
  v4->ImageTextActive = 0;
  v4->Icon1 = 0;
  v4->Icon2 = 0;
  v4->IconFrame1 = 0;
  v4->IconFrame2 = 0;
  v4->vfptr = (TPanelVtbl *)&TMessagePanel::`vftable';
  v4->text[0] = 0;
  v4->handle_mouse_input = 0;
  TPanel::set_active((TPanel *)&v4->vfptr, 0);
}
// 571668: using guessed type int (__thiscall *TMessagePanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00479030) --------------------------------------------------------
TMessagePanel *__thiscall TMessagePanel::`vector deleting destructor'(TMessagePanel *this, unsigned int __flags)
{
  TMessagePanel *v2; // esi@1

  v2 = this;
  TMessagePanel::~TMessagePanel(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00479270) --------------------------------------------------------
void __thiscall TMessagePanel::set_justification(TMessagePanel *this, TMessagePanel::JustType horz_just_in, TMessagePanel::JustType vert_just_in, int word_wrap_in)
{
  this->horz_just = horz_just_in;
  this->vert_just = vert_just_in;
  this->word_wrap = word_wrap_in;
}

//----- (004792A0) --------------------------------------------------------
void __thiscall TMessagePanel::show_message(TMessagePanel *this, TMessagePanel::MessageType message_type_in, char *text_in, char colorIn, char backColorIn, void *font_in, int font_wid_in, int font_hgt_in)
{
  TMessagePanel *v8; // esi@1
  TDrawArea *v9; // eax@8
  TPanelVtbl *v10; // edi@10
  TPanel *v11; // ecx@10

  v8 = this;
  if( !this->showing_message
    || this->message_type != message_type_in
    || strncmp(text_in, this->text, 0x1FFu)
    || font_in && font_in != v8->font )
  {
    if( font_in )
    {
      v8->font = font_in;
      v8->font_wid = font_wid_in;
      v8->font_hgt = font_hgt_in;
    }
    v8->message_type = message_type_in;
    memset(v8->text, 0, sizeof(v8->text));
    strncpy(v8->text, text_in, 0x1FFu);
    ++v8->display_changed_count;
    v8->showing_message = 1;
    v8->start_time = debug_timeGetTime();
    v8->font_color = colorIn;
    v9 = v8->ImageBuffer;
    v8->index_color = 1;
    v8->back_color = backColorIn;
    if( v9 )
      TMessagePanel::render_to_image_buffer(v8);
    v10 = v8->vfptr;
    (*(void (__thiscall **)(TMessagePanel *, signed int))&v8->vfptr->gap10[4])(v8, 1);
    v10->set_redraw((TPanel *)v8, RedrawNormal);
    v11 = v8->parent_panel;
    if( v11 )
      ((void (__stdcall *)(signed int))v11->vfptr->set_redraw)(1);
  }
}

//----- (004793C0) --------------------------------------------------------
void __thiscall TMessagePanel::show_message2(TMessagePanel *this, TMessagePanel::MessageType message_type_in, char *text_in, unsigned int color1, unsigned int color2, void *font_in, int font_wid_in, int font_hgt_in, TShape *Icon1_in, int Frame1_in, TShape *Icon2_in, int Frame2_in)
{
  TMessagePanel *v12; // esi@1
  int v13; // ebx@12
  TDrawArea *v14; // eax@12
  TPanelVtbl *v15; // edi@14
  TPanel *v16; // ecx@14

  v12 = this;
  if( !this->showing_message
    || this->message_type != message_type_in
    || strncmp(text_in, this->text, 0x1FFu)
    || font_in && font_in != v12->font
    || v12->Icon1 != Icon1_in
    || v12->Icon2 != Icon2_in
    || v12->IconFrame1 != Frame1_in
    || v12->IconFrame2 != Frame2_in )
  {
    if( font_in )
    {
      v12->font = font_in;
      v12->font_wid = font_wid_in;
      v12->font_hgt = font_hgt_in;
    }
    v12->IconFrame1 = Frame1_in;
    v12->message_type = message_type_in;
    v12->Icon1 = Icon1_in;
    v12->IconFrame2 = Frame2_in;
    v12->Icon2 = Icon2_in;
    memset(v12->text, 0, sizeof(v12->text));
    strncpy(v12->text, text_in, 0x1FFu);
    v13 = v12->display_changed_count + 1;
    v12->showing_message = 1;
    v12->display_changed_count = v13;
    v12->start_time = debug_timeGetTime();
    v12->font_color1 = color1;
    v14 = v12->ImageBuffer;
    v12->index_color = 0;
    v12->font_color2 = color2;
    if( v14 )
      TMessagePanel::render_to_image_buffer(v12);
    v15 = v12->vfptr;
    (*(void (__thiscall **)(TMessagePanel *, signed int))&v12->vfptr->gap10[4])(v12, 1);
    v15->set_redraw((TPanel *)v12, RedrawNormal);
    v16 = v12->parent_panel;
    if( v16 )
      ((void (__stdcall *)(signed int))v16->vfptr->set_redraw)(1);
  }
}

//----- (00479540) --------------------------------------------------------
void __thiscall TMessagePanel::remove_message(TMessagePanel *this)
{
  TMessagePanel *v1; // esi@1
  TPanelVtbl *v2; // edi@2
  TPanel *v3; // ecx@2

  v1 = this;
  if( this->showing_message )
  {
    v2 = this->vfptr;
    this->showing_message = 0;
    (*(void (__stdcall **)(_DWORD))&v2->gap10[4])(0);
    v2->set_redraw((TPanel *)v1, RedrawNormal);
    v3 = v1->parent_panel;
    if( v3 )
      ((void (__stdcall *)(signed int))v3->vfptr->set_redraw)(1);
  }
  v1->ImageTextActive = 0;
}

//----- (00479590) --------------------------------------------------------
void __thiscall TMessagePanel::draw(TMessagePanel *this)
{
  TMessagePanel *v1; // esi@1
  TPanelVtbl *v2; // edi@5
  TDrawArea *v3; // ecx@6
  int v4; // ebx@13
  TMessagePanel::MessageType v5; // eax@18
  UINT v6; // edi@19
  TMessagePanel::JustType v7; // eax@25
  TMessagePanel::JustType v8; // eax@29
  int v9; // ST2C_4@33
  int y; // [sp+10h] [bp-48h]@18
  int x; // [sp+14h] [bp-44h]@18
  int wid; // [sp+18h] [bp-40h]@18
  int hgt; // [sp+1Ch] [bp-3Ch]@18
  int font_rgb; // [sp+20h] [bp-38h]@13
  HGDIOBJ old_font; // [sp+30h] [bp-28h]@12
  TPanelVtbl *v16; // [sp+34h] [bp-24h]@5
  tagPALETTEENTRY paletteColor; // [sp+38h] [bp-20h]@13
  tagSIZE ts; // [sp+40h] [bp-18h]@18
  tagRECT rect; // [sp+48h] [bp-10h]@33

  v1 = this;
  if( this->render_area && this->visible && this->active && this->showing_message )
  {
    v2 = this->vfptr;
    v16 = this->vfptr;
    ((void (__stdcall *)(_DWORD))this->vfptr->draw_setup)(0);
    if( v1->ImageTextActive && (v3 = v1->ImageBuffer) != 0 )
    {
      if( v1->need_restore )
      {
        TMessagePanel::render_to_image_buffer(v1);
        v1->need_restore = 0;
        v2->draw_finish((TPanel *)v1);
      }
      else
      {
        TDrawArea::SetTrans(v3, 1, 1);
        TDrawArea::Copy(
          v1->ImageBuffer,
          v1->render_area,
          v1->UsedScreenRect.left,
          v1->UsedScreenRect.top,
          &v1->UsedImageRect,
          1);
        TDrawArea::SetTrans(v1->ImageBuffer, 0, 1);
        v2->draw_finish((TPanel *)v1);
      }
    }
    else
    {
      if( v1->text[0] && TDrawArea::GetDc(v1->render_area, aPnl_msgDraw) )
      {
        SelectClipRgn(v1->render_area->DrawDc, v1->clip_rgn);
        old_font = SelectObject(v1->render_area->DrawDc, v1->font);
        if( v1->index_color )
        {
          GetPaletteEntries(rge_base_game->draw_system->Pal, v1->font_color, 1u, &paletteColor);
          font_rgb = (unsigned __int8)paletteColor.peRed | (*(unsigned __int16 *)&paletteColor.peGreen << 8);
          GetPaletteEntries(rge_base_game->draw_system->Pal, v1->back_color, 1u, &paletteColor);
          v4 = (unsigned __int8)paletteColor.peRed | (*(unsigned __int16 *)&paletteColor.peGreen << 8);
        }
        else
        {
          v4 = v1->font_color2;
          font_rgb = v1->font_color1;
        }
        if( v1->message_type == 2 )
        {
          SetBkColor(v1->render_area->DrawDc, 0);
          SetBkMode(v1->render_area->DrawDc, 2);
        }
        else
        {
          SetBkMode(v1->render_area->DrawDc, 1);
        }
        x = v1->render_rect.left + 1;
        y = v1->render_rect.top + 1;
        wid = v1->pnl_wid - 2;
        hgt = v1->pnl_hgt - 2;
        GetTextExtentPoint32A(v1->render_area->DrawDc, v1->text, strlen(v1->text), &ts);
        v5 = v1->message_type;
        if( v5 == 1 )
        {
          v6 = 33;
        }
        else if( v5 == 5 )
        {
          v6 = 34;
        }
        else
        {
          GetTextExtentPoint32A(v1->render_area->DrawDc, v1->text, strlen(v1->text), &ts);
          if( !v1->word_wrap || (v6 = 16, ts.cx <= wid) )
            v6 = 32;
          v7 = v1->horz_just;
          if( v7 == 4 )
          {
            v6 |= 1u;
          }
          else if( v7 == 3 )
          {
            v6 |= 2u;
          }
          v8 = v1->vert_just;
          if( v8 == 4 )
          {
            v6 |= 4u;
          }
          else if( v8 == 1 )
          {
            v6 |= 8u;
          }
        }
        SetTextColor(v1->render_area->DrawDc, v4);
        v9 = x + wid;
        SetRect(&rect, x - 1, y - 1, v9 - 2, hgt + y - 2);
        DrawTextA(v1->render_area->DrawDc, v1->text, -1, &rect, v6);
        SetRect(&rect, x - 1, y + 1, v9 - 2, hgt + y);
        DrawTextA(v1->render_area->DrawDc, v1->text, -1, &rect, v6);
        SetRect(&rect, x + 1, y - 1, v9, hgt + y - 2);
        DrawTextA(v1->render_area->DrawDc, v1->text, -1, &rect, v6);
        SetRect(&rect, x + 1, y + 1, v9, hgt + y);
        DrawTextA(v1->render_area->DrawDc, v1->text, -1, &rect, v6);
        SetTextColor(v1->render_area->DrawDc, font_rgb);
        SetRect(&rect, x, y, v9 - 1, hgt + y - 1);
        DrawTextA(v1->render_area->DrawDc, v1->text, -1, &rect, v6);
        SelectObject(v1->render_area->DrawDc, old_font);
        SelectClipRgn(v1->render_area->DrawDc, 0);
        TDrawArea::ReleaseDc(v1->render_area, aPnl_msgDraw);
        v2 = v16;
      }
      v2->draw_finish((TPanel *)v1);
    }
  }
  else
  {
    this->need_redraw = 0;
  }
}

//----- (00479A10) --------------------------------------------------------
void __thiscall TMessagePanel::get_true_render_rect(TMessagePanel *this, tagRECT *drawRect)
{
  char *v2; // ecx@6
  char *v3; // ecx@7

  if( this->ImageBuffer && this->render_area && this->visible && this->active && this->showing_message )
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

//----- (00479A80) --------------------------------------------------------
int __thiscall TMessagePanel::handle_idle(TMessagePanel *this)
{
  TMessagePanel *v1; // esi@1
  TMessagePanel::MessageType v2; // eax@3

  v1 = this;
  if( this->active )
  {
    if( this->showing_message )
    {
      v2 = this->message_type;
      if( (v2 == 1 || v2 == 3 || v2 == 4)
        && (signed int)(debug_timeGetTime() - this->start_time) >= this->show_message_interval )
      {
        TMessagePanel::remove_message(v1);
      }
    }
  }
  return 0;
}

//----- (00479AE0) --------------------------------------------------------
void *__thiscall TMessagePanel::render_to_image_buffer(TMessagePanel *this)
{
  TMessagePanel *v1; // esi@1
  TDrawArea *v2; // ecx@1
  void *result; // eax@2
  int v4; // eax@7
  int v5; // ebp@12
  int v6; // ebx@12
  TMessagePanel::MessageType v7; // edi@14
  int v8; // ecx@14
  int v9; // eax@14
  int v10; // edx@14
  UINT v11; // edi@15
  signed int v12; // ebx@20
  TMessagePanel::JustType v13; // ebp@22
  TMessagePanel::JustType v14; // ebp@30
  int v15; // eax@43
  int v16; // ecx@43
  int v17; // edx@43
  int v18; // eax@45
  int v19; // ebp@47
  TShape *v20; // ecx@47
  int v21; // eax@48
  int v22; // edi@48
  TShape *v23; // ecx@49
  int v24; // eax@50
  int v25; // edi@50
  int v26; // eax@52
  int v27; // edx@52
  int v28; // ecx@52
  int v29; // edx@52
  int v30; // eax@52
  int x; // [sp+10h] [bp-40h]@12
  int Display_hgt; // [sp+14h] [bp-3Ch]@14
  int y; // [sp+18h] [bp-38h]@12
  int wid; // [sp+1Ch] [bp-34h]@12
  unsigned int back_rgb; // [sp+20h] [bp-30h]@9
  int hgt; // [sp+24h] [bp-2Ch]@12
  int font_rgb; // [sp+28h] [bp-28h]@7
  HGDIOBJ old_font; // [sp+2Ch] [bp-24h]@6
  tagPALETTEENTRY paletteColor; // [sp+30h] [bp-20h]@7
  tagSIZE ts; // [sp+38h] [bp-18h]@12
  tagRECT rect; // [sp+40h] [bp-10h]@13

  v1 = this;
  v2 = this->ImageBuffer;
  if( v2 )
  {
    TDrawArea::PtrClear(v2, &v1->ImageRect, 1);
    if( v1->text[0] )
    {
      result = TDrawArea::GetDc(v1->ImageBuffer, aPnl_msgRender_);
      if( result )
      {
        TDrawArea::SetClipRect(v1->ImageBuffer, &v1->ImageRect);
        SelectClipRgn(v1->ImageBuffer->DrawDc, v1->image_clip_region);
        old_font = SelectObject(v1->ImageBuffer->DrawDc, v1->font);
        if( v1->index_color )
        {
          GetPaletteEntries(rge_base_game->draw_system->Pal, v1->font_color, 1u, &paletteColor);
          font_rgb = (unsigned __int8)paletteColor.peRed | (*(unsigned __int16 *)&paletteColor.peGreen << 8);
          GetPaletteEntries(rge_base_game->draw_system->Pal, v1->back_color, 1u, &paletteColor);
          v4 = (unsigned __int8)paletteColor.peRed | (*(unsigned __int16 *)&paletteColor.peGreen << 8);
        }
        else
        {
          v4 = v1->font_color2;
          font_rgb = v1->font_color1;
        }
        back_rgb = v4;
        if( v1->message_type == 2 )
        {
          SetBkColor(v1->ImageBuffer->DrawDc, 0);
          SetBkMode(v1->ImageBuffer->DrawDc, 2);
        }
        else
        {
          SetBkMode(v1->ImageBuffer->DrawDc, 1);
        }
        wid = v1->pnl_wid - 2;
        hgt = v1->pnl_hgt - 2;
        v5 = v1->ImageRect.left + 1;
        v6 = v1->ImageRect.top + 1;
        x = v1->ImageRect.left + 1;
        y = v1->ImageRect.top + 1;
        if( GetTextExtentPoint32A(v1->ImageBuffer->DrawDc, v1->text, strlen(v1->text), &ts) )
        {
          v7 = v1->message_type;
          Display_hgt = ts.cy + 2;
          v8 = 0;
          v9 = 0;
          v10 = ts.cx + 2;
          if( v7 == 1 )
          {
            v11 = 33;
            v9 = ((v1->pnl_wid - v10) >> 1) - 1;
          }
          else if( v7 == 5 )
          {
            v11 = 34;
            v9 = v1->pnl_wid - v10 - 1;
            v8 = 0;
          }
          else
          {
            if( v1->word_wrap && ts.cx > wid )
            {
              v10 = v1->pnl_wid;
              Display_hgt = v1->pnl_hgt;
              v9 = 0;
              v8 = 0;
              v11 = 16;
              v12 = 0;
            }
            else
            {
              v10 = ts.cx + 1;
              v11 = 32;
              Display_hgt = ts.cy + 1;
              v12 = 1;
            }
            v13 = v1->horz_just;
            if( v13 == 4 )
            {
              v11 |= 1u;
              if( v12 )
                v9 = ((v1->pnl_wid - v10) >> 1) - 1;
            }
            else if( v13 == 3 )
            {
              v11 |= 2u;
              if( v12 )
                v9 = v1->pnl_wid - v10 - 1;
            }
            else if( v12 )
            {
              v9 = 0;
            }
            v14 = v1->vert_just;
            if( v14 == 4 )
            {
              v11 |= 4u;
              if( v12 )
                v8 = ((v1->pnl_hgt - Display_hgt) >> 1) - 1;
            }
            else if( v14 == 1 )
            {
              v11 |= 8u;
              if( v12 )
                v8 = v1->pnl_hgt - Display_hgt - 1;
            }
            else if( v12 )
            {
              v8 = 0;
            }
            v5 = x;
          }
          if( v8 < 0 )
            v8 = 0;
          if( v9 < 0 )
            v9 = 0;
          v1->UsedImageRect.left = v9;
          v15 = v10 + v9;
          v1->UsedImageRect.top = v8;
          v16 = Display_hgt + v8;
          v17 = v1->ImageRect.right;
          v1->UsedImageRect.right = v15;
          v1->UsedImageRect.bottom = v16;
          if( v15 > v17 )
            v1->UsedImageRect.right = v17;
          v18 = v1->ImageRect.bottom;
          if( v16 > v18 )
            v1->UsedImageRect.bottom = v18;
          SetTextColor(v1->ImageBuffer->DrawDc, back_rgb);
          v19 = wid + v5;
          SetRect(&rect, x - 1, y - 1, v19 - 2, hgt + y - 2);
          DrawTextA(v1->ImageBuffer->DrawDc, v1->text, -1, &rect, v11);
          SetRect(&rect, x - 1, y + 1, v19 - 2, hgt + y);
          DrawTextA(v1->ImageBuffer->DrawDc, v1->text, -1, &rect, v11);
          SetRect(&rect, x + 1, y - 1, v19, hgt + y - 2);
          DrawTextA(v1->ImageBuffer->DrawDc, v1->text, -1, &rect, v11);
          SetRect(&rect, x + 1, y + 1, v19, hgt + y);
          DrawTextA(v1->ImageBuffer->DrawDc, v1->text, -1, &rect, v11);
          SetTextColor(v1->ImageBuffer->DrawDc, font_rgb);
          SetRect(&rect, x, y, v19 - 1, hgt + y - 1);
          DrawTextA(v1->ImageBuffer->DrawDc, v1->text, -1, &rect, v11);
          v20 = v1->Icon1;
          if( v20 )
          {
            v21 = (int)&v20->shape_info[v1->IconFrame1];
            v22 = *(_DWORD *)(v21 + 16);
            TShape::shape_draw(
              v20,
              v1->ImageBuffer,
              *(_DWORD *)(v21 + 24) - v22 + v1->UsedImageRect.left - 4,
              *(_DWORD *)(v21 + 28) + v1->UsedImageRect.top + 6,
              v1->IconFrame1,
              0,
              0);
            v1->UsedImageRect.left += -4 - v22;
          }
          v23 = v1->Icon2;
          if( v23 )
          {
            v24 = (int)&v23->shape_info[v1->IconFrame2];
            v25 = *(_DWORD *)(v24 + 16);
            TShape::shape_draw(
              v23,
              v1->ImageBuffer,
              *(_DWORD *)(v24 + 24) - v25 + v1->UsedImageRect.left - 4,
              *(_DWORD *)(v24 + 28) + v1->UsedImageRect.top + 6,
              v1->IconFrame2,
              0,
              0);
            v1->UsedImageRect.left += -4 - v25;
          }
          v1->ImageTextActive = 1;
        }
        else
        {
          SetRect(&rect, v5 - 1, v6 - 1, wid + v5 - 2, hgt + v6 - 2);
          SetRect(&v1->UsedImageRect, 0, 0, 1, 1);
          v1->ImageTextActive = 0;
        }
        SelectObject(v1->ImageBuffer->DrawDc, old_font);
        SelectClipRgn(v1->ImageBuffer->DrawDc, 0);
        TDrawArea::ReleaseDc(v1->ImageBuffer, aPnl_msgRender_);
        v26 = v1->render_rect.left;
        v27 = v1->UsedImageRect.top;
        v1->UsedScreenRect.left = v26 + v1->UsedImageRect.left;
        v28 = v1->render_rect.top;
        v1->UsedScreenRect.top = v28 + v27;
        v29 = v26 + v1->UsedImageRect.right;
        v30 = v1->UsedImageRect.bottom;
        v1->UsedScreenRect.right = v29;
        v1->UsedScreenRect.bottom = v28 + v30;
        result = (void *)v1->ImageTextActive;
      }
    }
    else
    {
      SetRect(&v1->UsedImageRect, 0, 0, 1, 1);
      SetRect(
        &v1->UsedScreenRect,
        v1->render_rect.left,
        v1->render_rect.top,
        v1->render_rect.left + 1,
        v1->render_rect.top + 1);
      v1->ImageTextActive = 1;
      result = (void *)1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0047A160) --------------------------------------------------------
int __stdcall TMessagePanel::handle_mouse_down(char mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (0047A170) --------------------------------------------------------
int __stdcall TMessagePanel::handle_mouse_move(int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (0047A180) --------------------------------------------------------
int __stdcall TMessagePanel::handle_mouse_up(char mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (0047A190) --------------------------------------------------------
void __thiscall TMessagePanel::set_font(TMessagePanel *this, void *font_in, int font_wid_in, int font_hgt_in)
{
  TPanelVtbl *v4; // eax@2

  if( this->font != font_in )
  {
    this->font = font_in;
    this->font_wid = font_wid_in;
    v4 = this->vfptr;
    this->font_hgt = font_hgt_in;
    this->need_restore = 1;
    ((void (__stdcall *)(signed int))v4->set_redraw)(1);
  }
}
