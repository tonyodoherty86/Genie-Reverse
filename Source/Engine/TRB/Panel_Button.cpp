
//----- (00519DA0) --------------------------------------------------------
void __thiscall TRIBE_Panel_Button::TRIBE_Panel_Button(TRIBE_Panel_Button *this, TDrawArea *render_area_in, TPanel *parent_panel_in, TDigital *sound_in, void *font_in, int font_wid_in, int font_hgt_in, TShape *border_pic_in)
{
  TRIBE_Panel_Button *v8; // esi@1

  v8 = this;
  TButtonPanel::TButtonPanel((TButtonPanel *)this);
  *((_BYTE *)v8 + 704) = 0;
  *((_DWORD *)v8 + 178) = 0;
  *((_DWORD *)v8 + 179) = 0;
  *((_BYTE *)v8 + 720) = 0;
  *((_DWORD *)v8 + 244) = 0;
  *((_DWORD *)v8 + 174) = 0;
  *((_DWORD *)v8 + 175) = 0;
  *((_DWORD *)v8 + 177) = border_pic_in;
  *(_DWORD *)v8 = &TRIBE_Panel_Button::`vftable';
  if ( TButtonPanel::setup(
         (TPanel *)v8,
         render_area_in,
         parent_panel_in,
         0,
         0,
         0,
         0,
         (TPanel *)1,
         sound_in,
         (TPanel *)1,
         -1) )
  {
    TButtonPanel::set_font((TButtonPanel *)v8, font_in, font_wid_in, font_hgt_in);
  }
  else
  {
    *((_DWORD *)v8 + 54) = 1;
  }
}
// 576AD0: using guessed type int (__thiscall *TRIBE_Panel_Button::`vftable')(void *Memory, unsigned int __flags);

//----- (00519E70) --------------------------------------------------------
TRIBE_Panel_Button *__thiscall TRIBE_Panel_Button::`vector deleting destructor'(TRIBE_Panel_Button *this, unsigned int __flags)
{
  TRIBE_Panel_Button *v2; // esi@1

  v2 = this;
  TRIBE_Panel_Button::~TRIBE_Panel_Button(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00519EA0) --------------------------------------------------------
void __thiscall TRIBE_Panel_Button::set_text_msg(TRIBE_Panel_Button *this, char *text_msg_in)
{
  TRIBE_Panel_Button *v2; // esi@1

  v2 = this;
  if ( text_msg_in )
  {
    strncpy((char *)this + 720, text_msg_in, 0x100u);
    *((_BYTE *)v2 + 975) = 0;
  }
  else
  {
    *((_BYTE *)this + 720) = 0;
  }
}

//----- (00519EE0) --------------------------------------------------------
int __thiscall TRIBE_Panel_Button::is_inside(TRIBE_Panel_Button *this, int x, int y)
{
  TRIBE_Panel_Button *v3; // esi@1
  int result; // eax@1
  char v5; // al@2
  int v6; // ecx@4

  v3 = this;
  result = TPanel::is_inside((TPanel *)this, x, y);
  if ( result )
  {
    v5 = *((_BYTE *)v3 + 704);
    result = 1;
    if ( v5 == 2 || v5 == 3 )
    {
      v6 = *(_DWORD *)(*((_DWORD *)v3 + 16) + 1212);
      if ( v6 )
      {
        if ( (*(int (__stdcall **)(int, int))(*(_DWORD *)v6 + 188))(x, y) )
          result = 0;
      }
    }
  }
  return result;
}

//----- (00519F40) --------------------------------------------------------
void __thiscall TRIBE_Panel_Button::draw(TRIBE_Panel_Button *this)
{
  TRIBE_Panel_Button *v1; // esi@1
  TRIBE_Panel_Button *v2; // ebp@6
  char v3; // al@6
  signed int v4; // edi@6
  char v5; // al@13
  void *v6; // ebp@16
  int v7; // edx@17
  char *v8; // eax@17
  int v9; // ebx@17
  const char *v10; // edx@18
  int v11; // edi@21
  int v12; // ecx@21
  int v13; // eax@22
  int v14; // ecx@29
  const char *v15; // edx@29
  int v16; // edi@33
  char v17; // al@43
  int v18; // edi@44
  int v19; // edi@45
  int v20; // ebx@45
  RGE_Game_World *v21; // eax@55
  int y; // [sp+10h] [bp-2Ch]@22
  int ya; // [sp+10h] [bp-2Ch]@33
  char *text; // [sp+14h] [bp-28h]@18
  char *texta; // [sp+14h] [bp-28h]@30
  int x; // [sp+18h] [bp-24h]@21
  int xa; // [sp+18h] [bp-24h]@33
  int frame; // [sp+1Ch] [bp-20h]@17
  __int16 framea; // [sp+1Ch] [bp-20h]@43
  HGDIOBJ old_font; // [sp+20h] [bp-1Ch]@17
  int v31; // [sp+24h] [bp-18h]@6
  tagSIZE text_size; // [sp+28h] [bp-14h]@21
  char msg[10]; // [sp+30h] [bp-Ch]@63

  v1 = this;
  if ( *((_BYTE *)this + 704) == 3 )
  {
    TButtonPanel::draw((TButtonPanel *)this);
    return;
  }
  if ( !*((_DWORD *)this + 8) || !*((_DWORD *)this + 28) || !*((_DWORD *)this + 27) )
  {
    *((_DWORD *)this + 14) = 0;
    return;
  }
  v31 = *(_DWORD *)this;
  (*(void (__stdcall **)(_DWORD))(*(_DWORD *)this + 40))(0);
  v2 = (TRIBE_Panel_Button *)((char *)v1 + 36);
  (*(void (__stdcall **)(int))(**((_DWORD **)v1 + 16) + 52))((int)v1 + 36);
  v3 = *((_BYTE *)v1 + 704);
  v4 = 1;
  if ( (!v3 || v3 == 1) && *((_DWORD *)v1 + 177) && TDrawArea::Lock(*((TDrawArea **)v1 + 8), aTpnl_btnDraw, 1) )
  {
    v4 = 0;
    TShape::shape_draw(
      *((TShape **)v1 + 177),
      *((TDrawArea **)v1 + 8),
      *((_DWORD *)v1 + 3),
      *((_DWORD *)v1 + 4),
      *((_DWORD *)v1 + 179) + (*((_DWORD *)v1 + 126) != 0),
      0,
      0);
    TDrawArea::Unlock(*((TDrawArea **)v1 + 8), aTpnl_btnDraw);
  }
  if ( v4 )
    (*(void (__stdcall **)(char *))(**((_DWORD **)v1 + 16) + 52))((char *)v1 + 36);
  v5 = *((_BYTE *)v1 + 704);
  if ( v5 != 1 && v5 != 3 || !*((_DWORD *)v1 + 102) )
  {
    if ( *((_DWORD *)v1 + 83)
      && *((_WORD *)v1 + 184) >= 0
      && TDrawArea::Lock(*((TDrawArea **)v1 + 8), aTpnl_btnDraw3, 1) )
    {
      v17 = *((_BYTE *)v1 + 704);
      framea = *((_WORD *)v1 + 184);
      if ( v17 )
      {
        v19 = *((_DWORD *)v1 + 3);
        if ( v17 == 1 )
        {
          ++v19;
          v20 = *((_DWORD *)v1 + 4) + 1;
          TDrawArea::SetClipRect(
            *((TDrawArea **)v1 + 8),
            *(_DWORD *)v2 + 1,
            *((_DWORD *)v1 + 10) + 1,
            *((_DWORD *)v1 + 11) - 1,
            *((_DWORD *)v1 + 12) - 1);
          if ( *((_DWORD *)v1 + 126) )
          {
            ++v19;
            ++v20;
          }
        }
        else
        {
          v20 = *((_DWORD *)v1 + 4);
          if ( *((_DWORD *)v1 + 126) )
            framea = *((_WORD *)v1 + 184) + 1;
        }
      }
      else
      {
        v18 = *((_DWORD *)v1 + 3);
        if ( *((_DWORD *)v1 + 126) )
        {
          v19 = v18 + 3;
          v20 = *((_DWORD *)v1 + 4) + 3;
          TDrawArea::SetClipRect(
            *((TDrawArea **)v1 + 8),
            *(_DWORD *)v2 + 3,
            *((_DWORD *)v1 + 10) + 3,
            *((_DWORD *)v1 + 11) - 2,
            *((_DWORD *)v1 + 12) - 3);
        }
        else
        {
          v19 = v18 + 2;
          v20 = *((_DWORD *)v1 + 4) + 2;
          TDrawArea::SetClipRect(
            *((TDrawArea **)v1 + 8),
            *(_DWORD *)v2 + 2,
            *((_DWORD *)v1 + 10) + 2,
            *((_DWORD *)v1 + 11) - 2,
            *((_DWORD *)v1 + 12) - 2);
        }
      }
      if ( *((_DWORD *)v1 + 172) )
      {
        fog_next_shape = 1;
        ASMSet_Shadowing(16711935, 0, -16711936, 0);
      }
      if ( *((_DWORD *)v1 + 178) )
      {
        v21 = RGE_Base_Game::get_player(rge_base_game);
        ASMSet_Color_Xform(16 * (*(_WORD *)(v21[1].world_time + 38) + 1));
        TShape::shape_draw(*((TShape **)v1 + 83), *((TDrawArea **)v1 + 8), v19, v20, framea, 1, *((char **)v1 + 178));
      }
      else
      {
        TShape::shape_draw(*((TShape **)v1 + 83), *((TDrawArea **)v1 + 8), v19, v20, framea, 0, 0);
      }
      if ( *((_DWORD *)v1 + 172) )
        fog_next_shape = 0;
      TDrawArea::Unlock(*((TDrawArea **)v1 + 8), aTpnl_btnDraw3);
    }
    goto LABEL_60;
  }
  v6 = TDrawArea::GetDc(*((TDrawArea **)v1 + 8), aTpnl_btnDraw);
  if ( v6 )
  {
    SelectClipRgn(v6, *((HRGN *)v1 + 34));
    old_font = SelectObject(v6, *((HGDIOBJ *)v1 + 122));
    SetBkMode(v6, 1);
    v7 = *((_WORD *)v1 + 251);
    frame = *((_DWORD *)v1 + 6) / 2;
    v8 = (char *)*((_DWORD *)v1 + v7 + 102);
    v9 = *((_DWORD *)v1 + 5) / 2;
    if ( v8 )
    {
      v10 = (const char *)*((_DWORD *)v1 + v7 + 102);
      text = v8;
    }
    else
    {
      text = (char *)*((_DWORD *)v1 + 102);
      v10 = (const char *)*((_DWORD *)v1 + 102);
    }
    if ( !v10 )
      goto LABEL_39;
    x = (signed __int16)strlen(v10);
    GetTextExtentPoint32A(v6, (LPCSTR)v10, x, &text_size);
    v11 = *((_DWORD *)v1 + 3) + v9 - text_size.cx / 2;
    v12 = *((_WORD *)v1 + 251);
    if ( *((_DWORD *)v1 + v12 + 111) )
    {
      v13 = *((_DWORD *)v1 + 4) + frame - *((_DWORD *)v1 + 124);
      y = *((_DWORD *)v1 + 4) + frame - *((_DWORD *)v1 + 124);
    }
    else
    {
      v13 = *((_DWORD *)v1 + 4) + frame - *((_DWORD *)v1 + 124) / 2;
      y = *((_DWORD *)v1 + 4) + frame - *((_DWORD *)v1 + 124) / 2;
    }
    if ( *((_DWORD *)v1 + 101) )
    {
      if ( *((_DWORD *)v1 + 126) )
        goto LABEL_29;
    }
    else if ( !*((_DWORD *)v1 + 126) )
    {
LABEL_29:
      SetTextColor(v6, *((_DWORD *)v1 + v12 + 139));
      TextOutA(v6, v11 - 1, y + 1, text, x);
      SetTextColor(v6, *((_DWORD *)v1 + *((_WORD *)v1 + 251) + 130));
      TextOutA(v6, v11, y, text, x);
      v14 = *((_WORD *)v1 + 251);
      v15 = (const char *)*((_DWORD *)v1 + v14 + 111);
      if ( v15 )
      {
        texta = (char *)*((_DWORD *)v1 + v14 + 111);
      }
      else
      {
        v15 = (const char *)*((_DWORD *)v1 + 111);
        texta = (char *)*((_DWORD *)v1 + 111);
      }
      if ( !v15 )
        goto LABEL_39;
      v16 = (signed __int16)strlen(v15);
      GetTextExtentPoint32A(v6, (LPCSTR)v15, v16, &text_size);
      xa = *((_DWORD *)v1 + 3) + v9 - text_size.cx / 2;
      ya = *((_DWORD *)v1 + 4) + frame;
      if ( *((_DWORD *)v1 + 101) )
      {
        if ( *((_DWORD *)v1 + 126) )
        {
LABEL_38:
          SetTextColor(v6, *((_DWORD *)v1 + *((_WORD *)v1 + 251) + 139));
          TextOutA(v6, xa - 1, ya + 1, texta, v16);
          SetTextColor(v6, *((_DWORD *)v1 + *((_WORD *)v1 + 251) + 130));
          TextOutA(v6, xa, ya, texta, v16);
LABEL_39:
          SelectObject(v6, old_font);
          SelectClipRgn(v6, 0);
          TDrawArea::ReleaseDc(*((TDrawArea **)v1 + 8), aTpnl_btnDraw);
          goto LABEL_60;
        }
      }
      else if ( !*((_DWORD *)v1 + 126) )
      {
        goto LABEL_38;
      }
      ++xa;
      ++ya;
      goto LABEL_38;
    }
    ++v11;
    y = v13 + 1;
    goto LABEL_29;
  }
LABEL_60:
  if ( *((_DWORD *)v1 + 174) && *((_DWORD *)v1 + 175) > 0 )
  {
    if ( TDrawArea::GetDc(*((TDrawArea **)v1 + 8), aTpnl_btnDraw2) )
    {
      sprintf(msg, aD_3, *((_DWORD *)v1 + 175));
      SelectClipRgn(*(HDC *)(*((_DWORD *)v1 + 8) + 56), *((HRGN *)v1 + 34));
      SetBkMode(*(HDC *)(*((_DWORD *)v1 + 8) + 56), 1);
      SetTextColor(*(HDC *)(*((_DWORD *)v1 + 8) + 56), 0xCCCCCCu);
      TextOutA(
        *(HDC *)(*((_DWORD *)v1 + 8) + 56),
        *((_DWORD *)v1 + 3) + (*((_DWORD *)v1 + 126) != 0) + 3,
        *((_DWORD *)v1 + 4) + (*((_DWORD *)v1 + 126) != 0) + 2,
        msg,
        strlen(msg));
      SelectClipRgn(*(HDC *)(*((_DWORD *)v1 + 8) + 56), 0);
      TDrawArea::ReleaseDc(*((TDrawArea **)v1 + 8), aTpnl_invDraw2);
    }
  }
  (*(void (__thiscall **)(TRIBE_Panel_Button *))(v31 + 44))(v1);
}

//----- (0051A570) --------------------------------------------------------
void __thiscall TRIBE_Panel_Button::set_display_garrison(TRIBE_Panel_Button *this, int value)
{
  int v2; // edx@1

  v2 = *(_DWORD *)this;
  *((_DWORD *)this + 174) = value;
  (*(void (__stdcall **)(signed int))(v2 + 32))(1);
}

//----- (0051A590) --------------------------------------------------------
void __thiscall TRIBE_Panel_Button::set_garrison_number(TRIBE_Panel_Button *this, int value)
{
  int v2; // edx@1

  v2 = *(_DWORD *)this;
  *((_DWORD *)this + 175) = value;
  (*(void (__stdcall **)(signed int))(v2 + 32))(1);
}

//----- (0051A5B0) --------------------------------------------------------
int __thiscall TRIBE_Panel_Button::get_garrison_number(TRIBE_Panel_Button *this)
{
  return *((_DWORD *)this + 175);
}
