
//----- (00466A20) --------------------------------------------------------
void __thiscall TEasy_Panel::TEasy_Panel(TEasy_Panel *this, char *name)
{
  TEasy_Panel *v2; // esi@1

  v2 = this;
  TPanel::TPanel((TPanel *)&this->vfptr, name);
  v2->vfptr = (TPanelVtbl *)&TEasy_Panel::`vftable';
  TEasy_Panel::init_vars(v2);
}
// 570D18: using guessed type int (__thiscall *TEasy_Panel::`vftable')(void *Memory, unsigned int __flags);

//----- (00466A70) --------------------------------------------------------
TEasy_Panel *__thiscall TEasy_Panel::`vector deleting destructor'(TEasy_Panel *this, unsigned int __flags)
{
  TEasy_Panel *v2; // esi@1

  v2 = this;
  TEasy_Panel::~TEasy_Panel(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00466A90) --------------------------------------------------------
int __thiscall TEasy_Panel::setup(TEasy_Panel *this, TDrawArea *render_area_in, TPanel *parent_in, char *info_file_name_in, int resource_file_id, int full_screen, int x_in, int y_in, int wid_in, int hgt_in, int allow_shadow_area_in)
{
  TEasy_Panel *v11; // esi@1
  int v12; // ebx@2
  int v13; // ecx@2
  int v14; // ebp@3
  int v15; // edi@3
  int result; // eax@13
  TPanelVtbl *v17; // ebx@14
  char *v18; // ebp@16
  char *v19; // eax@19
  int v20; // eax@22
  int v21; // edi@22
  __int32 v22; // ebx@23
  unsigned int v23; // eax@27
  unsigned __int16 v24; // dx@37
  unsigned __int16 v25; // cx@37
  unsigned __int16 v26; // ax@37
  unsigned __int16 v27; // dx@37
  unsigned __int16 v28; // cx@37
  unsigned __int16 v29; // ax@37
  int v30; // [sp+28h] [bp-CDCh]@19
  int own_mem; // [sp+3Ch] [bp-CC8h]@1
  int f2g; // [sp+40h] [bp-CC4h]@30
  int f2r; // [sp+44h] [bp-CC0h]@30
  int back_pic_id_b2; // [sp+48h] [bp-CBCh]@30
  int f1b; // [sp+4Ch] [bp-CB8h]@30
  int back_pic_id_c2; // [sp+50h] [bp-CB4h]@30
  int f1g; // [sp+54h] [bp-CB0h]@30
  int back_pic_id_a2; // [sp+58h] [bp-CACh]@30
  int f1r; // [sp+5Ch] [bp-CA8h]@30
  int pal_id; // [sp+60h] [bp-CA4h]@30
  int s2b; // [sp+64h] [bp-CA0h]@37
  int background_pos_in; // [sp+68h] [bp-C9Ch]@30
  int s2g; // [sp+6Ch] [bp-C98h]@37
  int bc6; // [sp+70h] [bp-C94h]@30
  int s2r; // [sp+74h] [bp-C90h]@37
  int bc4; // [sp+78h] [bp-C8Ch]@30
  int s1b; // [sp+7Ch] [bp-C88h]@30
  int bc2; // [sp+80h] [bp-C84h]@30
  int s1g; // [sp+84h] [bp-C80h]@30
  int t2b; // [sp+88h] [bp-C7Ch]@30
  int s1r; // [sp+8Ch] [bp-C78h]@30
  int t2r; // [sp+90h] [bp-C74h]@30
  int button_pic_id; // [sp+94h] [bp-C70h]@30
  int t1g; // [sp+98h] [bp-C6Ch]@30
  int popup_info_id; // [sp+9Ch] [bp-C68h]@30
  int f2b; // [sp+A0h] [bp-C64h]@30
  int bc5; // [sp+A4h] [bp-C60h]@30
  int bc3; // [sp+A8h] [bp-C5Ch]@30
  int back_pic_id_a1; // [sp+ACh] [bp-C58h]@30
  int bc1; // [sp+B0h] [bp-C54h]@30
  int cursor_id; // [sp+B4h] [bp-C50h]@30
  int t2g; // [sp+B8h] [bp-C4Ch]@30
  int back_pic_id_c1; // [sp+BCh] [bp-C48h]@30
  int t1b; // [sp+C0h] [bp-C44h]@30
  int background_color1_in; // [sp+C4h] [bp-C40h]@30
  int t1r; // [sp+C8h] [bp-C3Ch]@30
  int shad_amt; // [sp+CCh] [bp-C38h]@30
  int back_pic_id_b1; // [sp+D0h] [bp-C34h]@30
  int resDataSize; // [sp+D4h] [bp-C30h]@28
  char temp_label[256]; // [sp+D8h] [bp-C2Ch]@30
  char info_file_name2[260]; // [sp+1D8h] [bp-B2Ch]@20
  char background_pic_file_name_b1[260]; // [sp+2DCh] [bp-A28h]@30
  char background_pic_file_name_c2[260]; // [sp+3E0h] [bp-924h]@30
  char background_pic_file_name_a2[260]; // [sp+4E4h] [bp-820h]@30
  char palette_file_name[260]; // [sp+5E8h] [bp-71Ch]@30
  char background_pic_file_name_b2[260]; // [sp+6ECh] [bp-618h]@30
  char cursor_file_name[260]; // [sp+7F0h] [bp-514h]@30
  char background_pic_file_name_c1[260]; // [sp+8F4h] [bp-410h]@30
  char button_pics_file_name[260]; // [sp+9F8h] [bp-30Ch]@30
  char background_pic_file_name_a1[260]; // [sp+AFCh] [bp-208h]@30
  char popup_info_file_name_in[260]; // [sp+C00h] [bp-104h]@30

  v11 = this;
  own_mem = -1;
  this->allow_shadow_area = allow_shadow_area_in;
  TEasy_Panel::set_info_file(this, info_file_name_in, resource_file_id);
  if ( full_screen )
  {
    v12 = 0;
    v13 = 0;
    if ( render_area_in )
    {
      v14 = render_area_in->Width;
      v15 = render_area_in->Height;
    }
    else
    {
      v14 = 0;
      v15 = 0;
    }
  }
  else
  {
    v14 = wid_in;
    v15 = hgt_in;
    if ( wid_in > 0 && hgt_in > 0 && render_area_in )
    {
      v12 = x_in;
      if ( x_in == -1 )
        v12 = render_area_in->Width / 2 - wid_in / 2;
      v13 = y_in;
      if ( y_in == -1 )
        v13 = render_area_in->Height / 2 - hgt_in / 2;
    }
    else
    {
      v13 = y_in;
      v12 = x_in;
    }
  }
  result = TPanel::setup((TPanel *)&v11->vfptr, render_area_in, parent_in, v12, v13, v14, v15, 0);
  if ( result )
  {
    v17 = v11->vfptr;
    (*(void (__thiscall **)(TEasy_Panel *, int, int))&v11->vfptr[1].gap4[0])(v11, v14, v15);
    if ( full_screen )
      (*(void (__thiscall **)(TEasy_Panel *, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&v17->gap10[8])(
        v11,
        1,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0);
    v18 = 0;
    if ( shape_file_first && v11 != (TEasy_Panel *)-252 && v11->info_file_name[0] )
    {
      v19 = strchr(v11->info_file_name, 46);
      v30 = (int)v11->info_file_name;
      if ( v19 )
        sprintf(info_file_name2, aS_2, v30);
      else
        sprintf(info_file_name2, aS_sin, v30);
      v20 = _open(info_file_name2, 0x8000);
      v21 = v20;
      if ( v20 != -1 )
      {
        lseek(v20, 0, 2);
        v22 = _tell(v21);
        v18 = (char *)malloc(v22);
        if ( v18 )
        {
          lseek(v21, 0, 0);
          read(v21, v18, v22);
          own_mem = 1;
        }
        _close(v21);
      }
    }
    if ( v18 )
      goto LABEL_43;
    v23 = v11->info_id;
    if ( v23 != -1 )
      v18 = RESFILE_load(0x62696E61u, v23, &own_mem, &resDataSize);
    if ( v18 )
    {
LABEL_43:
      if ( sscanf(
             v18,
             aSSSDDSSSDDSSSD,
             temp_label,
             background_pic_file_name_a1,
             background_pic_file_name_a2,
             &back_pic_id_a1,
             &back_pic_id_a2,
             temp_label,
             background_pic_file_name_b1,
             background_pic_file_name_b2,
             &back_pic_id_b1,
             &back_pic_id_b2,
             temp_label,
             background_pic_file_name_c1,
             background_pic_file_name_c2,
             &back_pic_id_c1,
             &back_pic_id_c2,
             temp_label,
             palette_file_name,
             &pal_id,
             temp_label,
             cursor_file_name,
             &cursor_id,
             temp_label,
             temp_label,
             &shad_amt,
             temp_label,
             button_pics_file_name,
             &button_pic_id,
             temp_label,
             popup_info_file_name_in,
             &popup_info_id,
             temp_label,
             &background_pos_in,
             temp_label,
             &background_color1_in,
             temp_label,
             &bc1,
             &bc2,
             &bc3,
             &bc4,
             &bc5,
             &bc6,
             temp_label,
             &t1r,
             &t1g,
             &t1b,
             temp_label,
             &t2r,
             &t2g,
             &t2b,
             temp_label,
             &f1r,
             &f1g,
             &f1b,
             temp_label,
             &f2r,
             &f2g,
             &f2b,
             temp_label,
             &s1r,
             &s1g,
             &s1b) != -1 )
      {
        TEasy_Panel::set_use_bevels(v11, 1);
        if ( v11->render_area->Width >= 800 && _strcmpi(background_pic_file_name_b1, Str2) )
        {
          if ( v11->render_area->Width >= 1024 )
          {
            TEasy_Panel::set_background(v11, background_pic_file_name_c1, back_pic_id_c1);
            TEasy_Panel::set_background2(v11, background_pic_file_name_c2, back_pic_id_c2);
          }
          else
          {
            TEasy_Panel::set_background(v11, background_pic_file_name_b1, back_pic_id_b1);
            TEasy_Panel::set_background2(v11, background_pic_file_name_b2, back_pic_id_b2);
          }
        }
        else
        {
          TEasy_Panel::set_background(v11, background_pic_file_name_a1, back_pic_id_a1);
          TEasy_Panel::set_background2(v11, background_pic_file_name_a2, back_pic_id_a2);
        }
        TEasy_Panel::set_shadow_amount(v11, shad_amt);
        TEasy_Panel::set_palette(v11, palette_file_name, pal_id);
        TEasy_Panel::set_cursor(v11, cursor_file_name, cursor_id);
        TEasy_Panel::set_background_pos(v11, background_pos_in);
        TEasy_Panel::set_background_colors(v11, background_color1_in, background_color1_in);
        TEasy_Panel::set_bevel_colors(v11, bc1, bc2, bc3, bc4, bc5, bc6);
        HIBYTE(v24) = t2b;
        LOBYTE(v24) = t2g;
        HIBYTE(v25) = t1b;
        LOBYTE(v25) = t1g;
        TEasy_Panel::set_text_colors(v11, (unsigned __int8)t1r | (v25 << 8), (unsigned __int8)t2r | (v24 << 8));
        HIBYTE(v26) = f2b;
        LOBYTE(v26) = f2g;
        HIBYTE(v27) = f1b;
        LOBYTE(v27) = f1g;
        TEasy_Panel::set_focus_colors(v11, (unsigned __int8)f1r | (v27 << 8), (unsigned __int8)f2r | (v26 << 8));
        HIBYTE(v28) = s2b;
        LOBYTE(v28) = s2g;
        HIBYTE(v29) = s1b;
        LOBYTE(v29) = s1g;
        TEasy_Panel::set_state_colors(v11, (unsigned __int8)s1r | (v29 << 8), (unsigned __int8)s2r | (v28 << 8));
        TEasy_Panel::set_button_pics(v11, button_pics_file_name, button_pic_id);
        TEasy_Panel::set_popup_info_file(v11, popup_info_file_name_in, popup_info_id);
      }
      if ( own_mem == 1 )
        free(v18);
    }
    result = 1;
  }
  return result;
}
// 466EB1: too many varargs, some ignored
// 86BBFC: using guessed type unsigned __int8 shape_file_first;

//----- (00467100) --------------------------------------------------------
void __thiscall TEasy_Panel::TEasy_Panel(TEasy_Panel *this)
{
  TEasy_Panel *v1; // esi@1

  v1 = this;
  TPanel::TPanel((TPanel *)&this->vfptr);
  v1->vfptr = (TPanelVtbl *)&TEasy_Panel::`vftable';
  TEasy_Panel::init_vars(v1);
}
// 570D18: using guessed type int (__thiscall *TEasy_Panel::`vftable')(void *Memory, unsigned int __flags);

//----- (00467150) --------------------------------------------------------
void __thiscall TEasy_Panel::init_vars(TEasy_Panel *this)
{
  this->ideal_width = 640;
  this->ideal_height = 480;
  this->info_file_name[0] = 0;
  this->info_id = -1;
  this->background_pic = 0;
  this->background_pic2 = 0;
  this->palette = 0;
  this->cursor_file[0] = 0;
  this->cursor_id = -1;
  this->background_pos = 0;
  this->use_bevels = 0;
  this->bevel_color1 = 0;
  this->bevel_color2 = 0;
  this->bevel_color3 = 0;
  this->bevel_color4 = 0;
  this->bevel_color5 = 0;
  this->bevel_color6 = 0;
  this->text_color1 = 0xFFFFFF;
  this->text_color2 = 0;
  this->focus_color1 = 0xFFFF;
  this->focus_color2 = 0;
  this->state_color1 = 0xFFFFFF;
  this->state_color2 = 0;
  this->popup_info_file_name[0] = 0;
  this->popup_info_id = -1;
  this->button_pics = 0;
  this->shadow_color_table = 0;
  this->background_color1 = 0;
  this->background_color2 = 0;
  this->enable_ime = 0;
  this->help_mode = 0;
  this->stock_brush = 0;
  this->brush = 0;
  this->brush_color = 0;
  this->shadow_amount = 0;
  this->shadow_area = 0;
  this->saved_mouse_mode = 0;
}

//----- (004672A0) --------------------------------------------------------
void __thiscall TEasy_Panel::prepare_for_close(TEasy_Panel *this)
{
  TEasy_Panel *v1; // esi@1
  TDrawArea *v2; // edi@1
  TShape *v3; // edi@7
  TShape *v4; // edi@9
  RGE_Color_Table *v5; // ecx@13
  TShape *v6; // edi@15

  v1 = this;
  v2 = this->shadow_area;
  if ( v2 )
  {
    TDrawArea::~TDrawArea(this->shadow_area);
    operator delete(v2);
    v1->shadow_area = 0;
  }
  if ( v1->brush )
  {
    if ( !v1->stock_brush )
      DeleteObject(v1->brush);
    v1->brush = 0;
  }
  v3 = v1->background_pic;
  if ( v3 )
  {
    TShape::~TShape(v1->background_pic);
    operator delete(v3);
    v1->background_pic = 0;
  }
  v4 = v1->background_pic2;
  if ( v4 )
  {
    TShape::~TShape(v1->background_pic2);
    operator delete(v4);
    v1->background_pic2 = 0;
  }
  if ( v1->palette )
  {
    TPanelSystem::release_palette(&panel_system, v1->palette);
    v1->palette = 0;
  }
  v5 = v1->shadow_color_table;
  if ( v5 )
  {
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
    v1->shadow_color_table = 0;
  }
  v6 = v1->button_pics;
  if ( v6 )
  {
    TShape::~TShape(v1->button_pics);
    operator delete(v6);
    v1->button_pics = 0;
  }
}

//----- (00467380) --------------------------------------------------------
void __thiscall TEasy_Panel::setup_shadow_area(TEasy_Panel *this, int force_redraw)
{
  TEasy_Panel *v2; // esi@1
  TDrawArea *v3; // ecx@1
  TDrawArea *v4; // eax@5
  unsigned int v5; // ebp@5
  TDrawArea *v6; // eax@6
  TDrawArea *v7; // eax@7
  int v8; // edi@11
  int v9; // ebx@11
  int y_min; // [sp+10h] [bp-11Ch]@6
  int y_max; // [sp+14h] [bp-118h]@11
  int x_min; // [sp+18h] [bp-114h]@11
  int x_max; // [sp+1Ch] [bp-110h]@11
  char area_name[256]; // [sp+20h] [bp-10Ch]@6
  int v15; // [sp+128h] [bp-4h]@6

  v2 = this;
  v3 = this->shadow_area;
  if ( (!v3 || force_redraw) && v2->background_pic && v2->shadow_color_table )
  {
    v4 = v2->render_area;
    v5 = v4->DrawSystem->Flags;
    if ( !v3 )
    {
      v4->DrawSystem->Flags &= 1u;
      sprintf(area_name, aSShadowPanel, v2->panelNameValue);
      v6 = (TDrawArea *)operator new(0x100u);
      y_min = (int)v6;
      v15 = 0;
      if ( v6 )
        TDrawArea::TDrawArea(v6, area_name, 0);
      else
        v7 = 0;
      v15 = -1;
      v2->shadow_area = v7;
    }
    if ( v2->shadow_area )
    {
      TShape::shape_minmax(v2->background_pic, &x_min, &y_min, &x_max, &y_max, 0);
      v8 = x_max - x_min + 1;
      v9 = y_max - y_min + 1;
      if ( v8 > v2->pnl_wid )
        v8 = v2->pnl_wid;
      if ( v9 > v2->pnl_hgt )
        v9 = v2->pnl_hgt;
      if ( TDrawArea::Init(v2->shadow_area, v2->render_area->DrawSystem, v8, v9, 0, 0) )
      {
        TDrawArea::Clear(v2->shadow_area, 0, v2->background_color1);
        if ( TDrawArea::Lock(v2->shadow_area, aPanel_ezSetup_, 1) )
        {
          TShape::shape_draw(v2->background_pic, v2->shadow_area, 0, 0, 0, 0, 0);
          TDrawArea::SetShadowTable(v2->shadow_area, v2->shadow_color_table);
          TDrawArea::DrawShadowBox(v2->shadow_area, 0, 0, v8 - 1, v9 - 1);
          TDrawArea::Unlock(v2->shadow_area, aPanel_ezSetup_);
        }
      }
    }
    v2->render_area->DrawSystem->Flags = v5;
  }
}

//----- (00467560) --------------------------------------------------------
void __thiscall TEasy_Panel::draw_setup(TEasy_Panel *this, int clear)
{
  TPanel::draw_setup((TPanel *)&this->vfptr, clear);
}

//----- (00467570) --------------------------------------------------------
void __thiscall TEasy_Panel::draw(TEasy_Panel *this)
{
  TEasy_Panel *v1; // esi@1

  v1 = this;
  if ( this->need_restore )
  {
    if ( this->shadow_area )
      TEasy_Panel::setup_shadow_area(this, 1);
    v1->need_restore = 0;
  }
  if ( v1->draw_rect2_flag )
    v1->vfptr[1].__vecDelDtor((TPanel *)v1, 1u);
  else
    v1->vfptr[1].__vecDelDtor((TPanel *)v1, 0);
}

//----- (004675C0) --------------------------------------------------------
void __thiscall TEasy_Panel::draw_background(TEasy_Panel *this, int use_background2)
{
  TEasy_Panel *v2; // esi@1
  TDrawArea *v3; // ecx@5
  int v4; // eax@5
  signed int v5; // ebp@5
  int v6; // eax@6
  int i; // ebx@8
  int j; // edi@9
  TShape *v9; // edi@16
  signed int v10; // ebx@26
  signed int v11; // ebp@26
  int k; // ebp@31
  int l; // edi@32
  int v14; // edi@38
  TShape *pic; // [sp+10h] [bp-1Ch]@17
  int pic_hgt; // [sp+14h] [bp-18h]@5
  int pic_hgta; // [sp+14h] [bp-18h]@26
  int pic_hgtb; // [sp+14h] [bp-18h]@38
  int x_max; // [sp+18h] [bp-14h]@26
  int x_min; // [sp+1Ch] [bp-10h]@26
  int y_max; // [sp+20h] [bp-Ch]@26
  int y_min; // [sp+24h] [bp-8h]@26
  TPanelVtbl *v23; // [sp+28h] [bp-4h]@1

  v2 = this;
  v23 = this->vfptr;
  ((void (__stdcall *)(_DWORD))v23->draw_setup)(0);
  if ( !use_background2 )
    goto LABEL_48;
  if ( v2->shadow_area )
  {
    if ( v2->need_redraw == 2 )
      TDrawArea::Clear(v2->render_area, &v2->clip_rect, v2->background_color2);
    v3 = v2->shadow_area;
    v4 = v2->background_pos;
    v5 = v3->Width;
    pic_hgt = v3->Height;
    if ( v4 )
    {
      v6 = v4 - 1;
      if ( v6 )
      {
        if ( v6 == 1 )
        {
          for ( i = 0; i <= v2->pnl_hgt; i += pic_hgt )
          {
            for ( j = 0; j <= v2->pnl_wid; j += v5 )
              TDrawArea::Copy(v2->shadow_area, v2->render_area, v2->pnl_x + j, v2->pnl_y + i, 0, 0);
          }
        }
      }
      else
      {
        TDrawArea::Copy(
          v3,
          v2->render_area,
          (signed __int16)(v2->pnl_wid / 2 + LOWORD(v2->pnl_x) - v5 / 2),
          (signed __int16)(v2->pnl_hgt / 2 + LOWORD(v2->pnl_y) - v3->Height / 2),
          0,
          0);
      }
    }
    else
    {
      TDrawArea::Copy(v3, v2->render_area, v2->pnl_x, v2->pnl_y, 0, 0);
    }
    goto LABEL_42;
  }
  if ( use_background2 && (v9 = v2->background_pic2) != 0 )
  {
    pic = v2->background_pic2;
  }
  else
  {
LABEL_48:
    pic = v2->background_pic;
    v9 = v2->background_pic;
  }
  if ( v2->need_redraw != 2 && v9
    || (!use_background2 ? TDrawArea::Clear(v2->render_area, &v2->clip_rect, v2->background_color1) : TDrawArea::Clear(v2->render_area, &v2->clip_rect, v2->background_color2),
        v9) )
  {
    if ( TDrawArea::Lock(v2->render_area, aPanel_ezDraw_b, 1) )
    {
      TShape::shape_minmax(v9, &x_min, &y_min, &x_max, &y_max, 0);
      v10 = x_max - x_min + 1;
      v11 = y_max - y_min + 1;
      pic_hgta = y_max - y_min + 1;
      if ( v2->background_pos == 1 )
      {
        v14 = (signed __int16)(v2->pnl_wid / 2 + LOWORD(v2->pnl_x) - v10 / 2);
        pic_hgtb = (signed __int16)(v2->pnl_hgt / 2 + LOWORD(v2->pnl_y) - v11 / 2);
        TShape::shape_draw(pic, v2->render_area, v14, pic_hgtb, 0, 0, 0);
        if ( use_background2 && v2->shadow_color_table )
        {
          TDrawArea::SetShadowTable(v2->render_area, v2->shadow_color_table);
          TDrawArea::DrawShadowBox(v2->render_area, v14, pic_hgtb, v14 + v10 - 1, pic_hgtb + v11 - 1);
        }
      }
      else if ( v2->background_pos == 2 )
      {
        for ( k = 0; k <= v2->pnl_hgt; k += pic_hgta )
        {
          for ( l = 0; l <= v2->pnl_wid; l += v10 )
            TShape::shape_draw(pic, v2->render_area, v2->pnl_x + l, v2->pnl_y + k, 0, 0, 0);
        }
        if ( use_background2 && v2->shadow_color_table )
        {
          TDrawArea::SetShadowTable(v2->render_area, v2->shadow_color_table);
          TDrawArea::DrawShadowBox(
            v2->render_area,
            v2->pnl_x,
            v2->pnl_y,
            v2->pnl_wid + v2->pnl_x - 1,
            v2->pnl_y + v2->pnl_hgt - 1);
        }
      }
      else
      {
        TShape::shape_draw(v9, v2->render_area, v2->pnl_x, v2->pnl_y, 0, 0, 0);
        if ( use_background2 && v2->shadow_color_table )
        {
          TDrawArea::SetShadowTable(v2->render_area, v2->shadow_color_table);
          TDrawArea::DrawShadowBox(v2->render_area, v2->pnl_x, v2->pnl_y, v10 + v2->pnl_x - 1, v11 + v2->pnl_y - 1);
        }
      }
      TDrawArea::Unlock(v2->render_area, aPanel_ezDraw_b);
    }
  }
LABEL_42:
  if ( v2->use_bevels && TDrawArea::Lock(v2->render_area, aPanel_ezDraw_1, 1) )
  {
    TDrawArea::DrawBevel3(
      v2->render_area,
      v2->pnl_x,
      v2->pnl_y,
      v2->pnl_wid + v2->pnl_x - 1,
      v2->pnl_hgt + v2->pnl_y - 1,
      v2->bevel_color1,
      v2->bevel_color2,
      v2->bevel_color3,
      v2->bevel_color4,
      v2->bevel_color5,
      v2->bevel_color6);
    TDrawArea::Unlock(v2->render_area, aPanel_ezDraw_1);
  }
  v23->draw_finish((TPanel *)v2);
}

//----- (004679A0) --------------------------------------------------------
int __thiscall TEasy_Panel::handle_mouse_down(TEasy_Panel *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  TEasy_Panel *v6; // esi@1
  int result; // eax@2

  v6 = this;
  if ( TEasy_Panel::command_do_popup_help(this, mouse_button_in, x, y) )
    result = 1;
  else
    result = TPanel::handle_mouse_down((TPanel *)&v6->vfptr, mouse_button_in, x, y, ctrl_key, shift_key);
  return result;
}

//----- (004679F0) --------------------------------------------------------
void __thiscall TEasy_Panel::set_info_file(TEasy_Panel *this, char *file_name, int resource_file_id)
{
  if ( file_name )
  {
    strcpy(this->info_file_name, file_name);
    this->info_id = resource_file_id;
  }
  else
  {
    this->info_file_name[0] = 0;
    this->info_id = resource_file_id;
  }
}

//----- (00467A50) --------------------------------------------------------
void __thiscall TEasy_Panel::set_ideal_size(TEasy_Panel *this, int width, int height)
{
  this->ideal_width = width;
  this->ideal_height = height;
}

//----- (00467A70) --------------------------------------------------------
BOOL __thiscall TEasy_Panel::set_background(TEasy_Panel *this, char *file_name, int resource_id)
{
  TEasy_Panel *v3; // edi@1
  TShape *v4; // esi@1
  TShape *v5; // eax@9
  TShape *v6; // eax@10
  TShape *v7; // eax@12
  TShape *v8; // ecx@16
  TShape *v9; // esi@18
  char file_name2[260]; // [sp+Ch] [bp-110h]@7
  int v12; // [sp+118h] [bp-4h]@9

  v3 = this;
  v4 = this->background_pic;
  if ( v4 )
  {
    TShape::~TShape(this->background_pic);
    operator delete(v4);
    v3->background_pic = 0;
  }
  if ( file_name && *file_name && _strcmpi(file_name, Str2) )
  {
    if ( strchr(file_name, 46) )
      sprintf(file_name2, aS_2, file_name);
    else
      sprintf(file_name2, aS_shp, file_name);
    v5 = (TShape *)operator new(0x20u);
    v12 = 0;
    if ( v5 )
    {
      TShape::TShape(v5, file_name2, resource_id);
LABEL_15:
      v12 = -1;
      v3->background_pic = v6;
      goto LABEL_16;
    }
    goto LABEL_14;
  }
  if ( resource_id != -1 )
  {
    v7 = (TShape *)operator new(0x20u);
    v12 = 1;
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
  return v3->background_pic != 0;
}

//----- (00467BE0) --------------------------------------------------------
BOOL __thiscall TEasy_Panel::set_background2(TEasy_Panel *this, char *file_name, int resource_id)
{
  TEasy_Panel *v3; // edi@1
  TShape *v4; // esi@1
  TShape *v5; // eax@9
  TShape *v6; // eax@10
  TShape *v7; // eax@12
  TShape *v8; // ecx@16
  TShape *v9; // esi@18
  char file_name2[260]; // [sp+Ch] [bp-110h]@7
  int v12; // [sp+118h] [bp-4h]@9

  v3 = this;
  v4 = this->background_pic2;
  if ( v4 )
  {
    TShape::~TShape(this->background_pic2);
    operator delete(v4);
    v3->background_pic2 = 0;
  }
  if ( file_name && *file_name && _strcmpi(file_name, Str2) )
  {
    if ( strchr(file_name, 46) )
      sprintf(file_name2, aS_2, file_name);
    else
      sprintf(file_name2, aS_shp, file_name);
    v5 = (TShape *)operator new(0x20u);
    v12 = 0;
    if ( v5 )
    {
      TShape::TShape(v5, file_name2, resource_id);
LABEL_15:
      v12 = -1;
      v3->background_pic2 = v6;
      goto LABEL_16;
    }
    goto LABEL_14;
  }
  if ( resource_id != -1 )
  {
    v7 = (TShape *)operator new(0x20u);
    v12 = 1;
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
  v8 = v3->background_pic2;
  if ( v8 && !TShape::is_loaded(v8) )
  {
    v9 = v3->background_pic2;
    if ( v9 )
    {
      TShape::~TShape(v3->background_pic2);
      operator delete(v9);
    }
    v3->background_pic2 = 0;
  }
  return v3->background_pic2 != 0;
}

//----- (00467D50) --------------------------------------------------------
void __thiscall TEasy_Panel::set_background_colors(TEasy_Panel *this, int color1, char color2)
{
  TEasy_Panel *v3; // esi@1

  v3 = this;
  (*(void (__stdcall **)(_DWORD))&this->vfptr->gap10[0])(color1);
  v3->background_color1 = color1;
  v3->background_color2 = color2;
  v3->brush = GetStockObject(4);
  v3->stock_brush = 1;
  v3->brush_color = 0;
}

//----- (00467DA0) --------------------------------------------------------
int __thiscall TEasy_Panel::set_palette(TEasy_Panel *this, char *file_name, int resource_file_id)
{
  TEasy_Panel *v3; // esi@1
  RGE_Color_Table *v4; // ecx@3
  void *v6; // eax@10
  RGE_Color_Table *v7; // eax@13
  RGE_Color_Table *v8; // eax@14
  tagPALETTEENTRY palette_entries[256]; // [sp+10h] [bp-40Ch]@12
  int v10; // [sp+418h] [bp-4h]@13

  v3 = this;
  if ( this->palette )
  {
    TPanelSystem::release_palette(&panel_system, this->palette);
    v3->palette = 0;
  }
  v4 = v3->shadow_color_table;
  if ( v4 )
  {
    ((void (__stdcall *)(signed int))v4->vfptr->__vecDelDtor)(1);
    v3->shadow_color_table = 0;
  }
  if ( resource_file_id == -1 )
  {
    if ( !file_name || !*file_name )
      return 1;
    if ( !_strcmpi(file_name, Str2) )
      return 1;
  }
  v6 = TPanelSystem::get_palette(&panel_system, file_name, resource_file_id);
  v3->palette = v6;
  if ( v6 && v3->shadow_amount > 0 )
  {
    if ( GetPaletteEntries(v6, 0, 0x100u, palette_entries) )
    {
      v7 = (RGE_Color_Table *)operator new(0x128u);
      v10 = 0;
      if ( v7 )
      {
        RGE_Color_Table::RGE_Color_Table(v7, v3->render_area, v3->shadow_amount, 0, palette_entries);
        v3->shadow_color_table = v8;
        return 1;
      }
      v3->shadow_color_table = 0;
    }
    return 1;
  }
  return 0;
}

//----- (00467EF0) --------------------------------------------------------
int __thiscall TEasy_Panel::set_cursor(TEasy_Panel *this, char *file_name, int resource_id)
{
  TEasy_Panel *v3; // edx@1
  unsigned int v4; // ecx@1
  char v5; // al@1
  char *v6; // edi@1
  char *v7; // esi@1
  int result; // eax@1

  v3 = this;
  v4 = strlen(file_name) + 1;
  v5 = v4;
  v4 >>= 2;
  qmemcpy(v3->cursor_file, file_name, 4 * v4);
  v7 = &file_name[4 * v4];
  v6 = &v3->cursor_file[4 * v4];
  LOBYTE(v4) = v5;
  result = 1;
  qmemcpy(v6, v7, v4 & 3);
  v3->cursor_id = resource_id;
  return result;
}

//----- (00467F40) --------------------------------------------------------
void __thiscall TEasy_Panel::set_use_bevels(TEasy_Panel *this, int use_bevels_in)
{
  this->use_bevels = use_bevels_in;
}

//----- (00467F50) --------------------------------------------------------
void __thiscall TEasy_Panel::set_background_pos(TEasy_Panel *this, int background_pos_in)
{
  this->background_pos = background_pos_in;
}

//----- (00467F60) --------------------------------------------------------
void __thiscall TEasy_Panel::set_bevel_colors(TEasy_Panel *this, char c1, char c2, char c3, char c4, char c5, char c6)
{
  this->bevel_color1 = c1;
  this->bevel_color2 = c2;
  this->bevel_color3 = c3;
  this->bevel_color4 = c4;
  this->bevel_color5 = c5;
  this->bevel_color6 = c6;
}

//----- (00467FA0) --------------------------------------------------------
void __thiscall TEasy_Panel::set_text_colors(TEasy_Panel *this, unsigned int c1, unsigned int c2)
{
  this->text_color1 = c1;
  this->text_color2 = c2;
}

//----- (00467FC0) --------------------------------------------------------
void __thiscall TEasy_Panel::set_focus_colors(TEasy_Panel *this, unsigned int c1, unsigned int c2)
{
  this->focus_color1 = c1;
  this->focus_color2 = c2;
}

//----- (00467FE0) --------------------------------------------------------
void __thiscall TEasy_Panel::set_state_colors(TEasy_Panel *this, unsigned int c1, unsigned int c2)
{
  this->state_color1 = c1;
  this->state_color2 = c2;
}

//----- (00468000) --------------------------------------------------------
void __thiscall TEasy_Panel::set_popup_info_file(TEasy_Panel *this, char *file_name, int resource_file_id)
{
  if ( file_name )
  {
    strcpy(this->popup_info_file_name, file_name);
    this->popup_info_id = resource_file_id;
  }
  else
  {
    this->popup_info_file_name[0] = 0;
    this->popup_info_id = resource_file_id;
  }
}

//----- (00468060) --------------------------------------------------------
void __thiscall TEasy_Panel::set_button_pics(TEasy_Panel *this, char *file_name, int resource_file_id)
{
  TEasy_Panel *v3; // edi@1
  TShape *v4; // esi@1
  TShape *v5; // eax@9
  TShape *v6; // eax@10
  TShape *v7; // eax@12
  TShape *v8; // ecx@16
  TShape *v9; // esi@18
  char file_name2[260]; // [sp+Ch] [bp-110h]@7
  int v11; // [sp+118h] [bp-4h]@9

  v3 = this;
  v4 = this->button_pics;
  if ( v4 )
  {
    TShape::~TShape(this->button_pics);
    operator delete(v4);
    v3->button_pics = 0;
  }
  if ( file_name && *file_name && _strcmpi(file_name, Str2) )
  {
    if ( strchr(file_name, 46) )
      sprintf(file_name2, aS_2, file_name);
    else
      sprintf(file_name2, aS_shp, file_name);
    v5 = (TShape *)operator new(0x20u);
    v11 = 0;
    if ( v5 )
    {
      TShape::TShape(v5, file_name2, resource_file_id);
LABEL_15:
      v11 = -1;
      v3->button_pics = v6;
      goto LABEL_16;
    }
    goto LABEL_14;
  }
  if ( resource_file_id != -1 )
  {
    v7 = (TShape *)operator new(0x20u);
    v11 = 1;
    if ( v7 )
    {
      TShape::TShape(v7, message_in, resource_file_id);
      goto LABEL_15;
    }
LABEL_14:
    v6 = 0;
    goto LABEL_15;
  }
LABEL_16:
  v8 = v3->button_pics;
  if ( v8 && !TShape::is_loaded(v8) )
  {
    v9 = v3->button_pics;
    if ( v9 )
    {
      TShape::~TShape(v3->button_pics);
      operator delete(v9);
    }
    v3->button_pics = 0;
  }
}

//----- (004681D0) --------------------------------------------------------
void __thiscall TEasy_Panel::set_shadow_amount(TEasy_Panel *this, int val)
{
  TEasy_Panel *v2; // esi@1
  RGE_Color_Table *v3; // ecx@4
  void *v4; // eax@6
  RGE_Color_Table *v5; // eax@9
  RGE_Color_Table *v6; // eax@10
  tagPALETTEENTRY palette_entries[256]; // [sp+8h] [bp-40Ch]@8
  int v8; // [sp+410h] [bp-4h]@9

  v2 = this;
  if ( val == -1 )
    this->shadow_amount = 0;
  else
    this->shadow_amount = val;
  v3 = this->shadow_color_table;
  if ( v3 )
  {
    ((void (__stdcall *)(signed int))v3->vfptr->__vecDelDtor)(1);
    v2->shadow_color_table = 0;
  }
  v4 = v2->palette;
  if ( v4 && v2->shadow_amount > 0 && GetPaletteEntries(v4, 0, 0x100u, palette_entries) )
  {
    v5 = (RGE_Color_Table *)operator new(0x128u);
    v8 = 0;
    if ( v5 )
      RGE_Color_Table::RGE_Color_Table(v5, v2->render_area, v2->shadow_amount, 0, palette_entries);
    else
      v6 = 0;
    v8 = -1;
    v2->shadow_color_table = v6;
  }
  if ( v2->have_focus )
    v2->vfptr->set_redraw((TPanel *)v2, RedrawFull);
}

//----- (004682D0) --------------------------------------------------------
void __thiscall TEasy_Panel::set_enable_ime(TEasy_Panel *this, int enable_ime_in)
{
  int v2; // edx@1

  v2 = this->have_focus;
  this->enable_ime = enable_ime_in;
  if ( v2 )
  {
    if ( enable_ime_in )
      TPanelSystem::EnableIME(&panel_system);
    else
      TPanelSystem::DisableIME(&panel_system);
  }
}

//----- (00468300) --------------------------------------------------------
char *__thiscall TEasy_Panel::get_info_file(TEasy_Panel *this)
{
  return this->info_file_name;
}

//----- (00468310) --------------------------------------------------------
int __thiscall TEasy_Panel::get_info_id(TEasy_Panel *this)
{
  return this->info_id;
}

//----- (00468320) --------------------------------------------------------
TShape *__thiscall TEasy_Panel::get_background(TEasy_Panel *this)
{
  return this->background_pic;
}

//----- (00468330) --------------------------------------------------------
TShape *__thiscall TEasy_Panel::get_background2(TEasy_Panel *this)
{
  return this->background_pic2;
}

//----- (00468340) --------------------------------------------------------
void *__thiscall TEasy_Panel::get_palette(TEasy_Panel *this)
{
  return this->palette;
}

//----- (00468350) --------------------------------------------------------
char *__thiscall TEasy_Panel::get_cursor(TEasy_Panel *this)
{
  return this->cursor_file;
}

//----- (00468360) --------------------------------------------------------
int __thiscall TEasy_Panel::get_use_bevels(TEasy_Panel *this)
{
  return this->use_bevels;
}

//----- (00468370) --------------------------------------------------------
int __thiscall TEasy_Panel::get_background_pos(TEasy_Panel *this)
{
  return this->background_pos;
}

//----- (00468380) --------------------------------------------------------
void __thiscall TEasy_Panel::get_bevel_colors(TEasy_Panel *this, char *c1, char *c2, char *c3, char *c4, char *c5, char *c6)
{
  *c1 = this->bevel_color1;
  *c2 = this->bevel_color2;
  *c3 = this->bevel_color3;
  *c4 = this->bevel_color4;
  *c5 = this->bevel_color5;
  *c6 = this->bevel_color6;
}

//----- (004683D0) --------------------------------------------------------
void __thiscall TEasy_Panel::get_text_colors(TEasy_Panel *this, unsigned int *c1, unsigned int *c2)
{
  *c1 = this->text_color1;
  *c2 = this->text_color2;
}

//----- (004683F0) --------------------------------------------------------
void __thiscall TEasy_Panel::get_focus_colors(TEasy_Panel *this, unsigned int *c1, unsigned int *c2)
{
  *c1 = this->focus_color1;
  *c2 = this->focus_color2;
}

//----- (00468410) --------------------------------------------------------
int __thiscall TEasy_Panel::get_shadow_amount(TEasy_Panel *this)
{
  return this->shadow_amount;
}

//----- (00468420) --------------------------------------------------------
void __thiscall TEasy_Panel::get_state_colors(TEasy_Panel *this, unsigned int *c1, unsigned int *c2)
{
  *c1 = this->state_color1;
  *c2 = this->state_color2;
}

//----- (00468440) --------------------------------------------------------
char *__thiscall TEasy_Panel::get_popup_info_file(TEasy_Panel *this)
{
  return this->popup_info_file_name;
}

//----- (00468450) --------------------------------------------------------
int __thiscall TEasy_Panel::get_popup_info_id(TEasy_Panel *this)
{
  return this->popup_info_id;
}

//----- (00468460) --------------------------------------------------------
TShape *__thiscall TEasy_Panel::get_button_pics(TEasy_Panel *this)
{
  return this->button_pics;
}

//----- (00468470) --------------------------------------------------------
RGE_Color_Table *__thiscall TEasy_Panel::get_shadow_color_table(TEasy_Panel *this)
{
  return this->shadow_color_table;
}

//----- (00468480) --------------------------------------------------------
int __thiscall TEasy_Panel::get_enable_ime(TEasy_Panel *this)
{
  return this->enable_ime;
}

//----- (00468490) --------------------------------------------------------
int __thiscall TEasy_Panel::create_button(TEasy_Panel *this, TPanel *parent, TButtonPanel **button, int text_id1, int text_id2, int x, int y, int width, int height, int font_num, int sound_num, int action_id)
{
  TEasy_Panel *v12; // esi@1
  char text2[120]; // [sp+4h] [bp-F0h]@1
  char text1[120]; // [sp+7Ch] [bp-78h]@1

  v12 = this;
  TPanel::get_string(text_id1, text1, 120);
  TPanel::get_string(text_id2, text2, 120);
  return ((int (__thiscall *)(TEasy_Panel *, TPanel *, TButtonPanel **, char *, char *, int, int, int, int, int, int, int))v12->vfptr[1].set_rect)(
           v12,
           parent,
           button,
           text1,
           text2,
           x,
           y,
           width,
           height,
           font_num,
           sound_num,
           action_id);
}

//----- (00468530) --------------------------------------------------------
int __thiscall TEasy_Panel::create_button(TEasy_Panel *this, TPanel *parent, TButtonPanel **button, char *text1, char *text2, int x, int y, int width, int height, int font_num, int sound_num, int action_id)
{
  TEasy_Panel *v12; // esi@1
  int v13; // ecx@1
  signed int v14; // edi@1
  int v15; // ebx@1
  signed int v16; // ebp@1
  int v17; // edi@1
  int v18; // ebp@1
  TButtonPanel *v19; // eax@1
  int v20; // eax@2
  TDigital **v21; // eax@7
  RGE_Font *v22; // eax@11
  signed int v23; // edi@17
  int result; // eax@19
  int ideal_x; // [sp+14h] [bp-10h]@1
  int xa; // [sp+38h] [bp+14h]@1

  v12 = this;
  v13 = this->pnl_wid;
  v14 = v12->ideal_width;
  v15 = v12->pnl_hgt;
  v16 = v12->ideal_height;
  ideal_x = v13 * x / v14;
  xa = v15 * y / v16;
  v17 = v13 * width / v14;
  v18 = v15 * height / v16;
  v19 = (TButtonPanel *)operator new(0x2B8u);
  if ( v19 )
    TButtonPanel::TButtonPanel(v19);
  else
    v20 = 0;
  *button = (TButtonPanel *)v20;
  if ( v20
    && !*(_DWORD *)(v20 + 216)
    && (sound_num < 0 ? (v21 = 0) : (v21 = RGE_Base_Game::get_sound(rge_base_game, sound_num)),
        TButtonPanel::setup(
          (TPanel *)*button,
          v12->render_area,
          parent,
          ideal_x,
          xa,
          v17,
          v18,
          (TPanel *)3,
          (TDigital *)v21,
          (TPanel *)1,
          action_id)) )
  {
    TButtonPanel::set_sound_number(*button, sound_num);
    if ( font_num < 0 )
      v22 = RGE_Base_Game::get_font(rge_base_game, 10);
    else
      v22 = RGE_Base_Game::get_font(rge_base_game, font_num);
    TButtonPanel::set_text_info(*button, text1, v22->font, v22->font_wid, v22->font_hgt, -1, -1);
    if ( text2 )
      TButtonPanel::set_text(*button, 1, text2);
    if ( v12->use_bevels )
      TButtonPanel::set_bevel_info(
        *button,
        4,
        v12->bevel_color1,
        v12->bevel_color2,
        v12->bevel_color3,
        v12->bevel_color4,
        v12->bevel_color5,
        v12->bevel_color6);
    v23 = 0;
    do
    {
      TButtonPanel::set_text_color(*button, v23, v12->text_color1, v12->text_color2);
      TButtonPanel::set_highlight_text_color(*button, v23++, v12->focus_color1, v12->focus_color2);
    }
    while ( v23 < 9 );
    TButtonPanel::set_text_color(*button, 1, v12->state_color1, v12->state_color2);
    TButtonPanel::set_highlight_text_color(*button, 1, v12->focus_color1, v12->focus_color2);
    result = 1;
  }
  else
  {
    v12->error_code = 1;
    result = 0;
  }
  return result;
}

//----- (00468760) --------------------------------------------------------
int __thiscall TEasy_Panel::create_check_box(TEasy_Panel *this, TPanel *parent, TButtonPanel **button, int x, int y, int width, int height, int sound_num, int action_id)
{
  TEasy_Panel *v9; // esi@1
  int v10; // ecx@1
  signed int v11; // edi@1
  int v12; // ebx@1
  signed int v13; // ebp@1
  int v14; // ebx@1
  TButtonPanel *v15; // eax@1
  int v16; // eax@2
  TDigital **v17; // eax@7
  RGE_Font *v18; // eax@12
  int result; // eax@15
  int ideal_x; // [sp+14h] [bp-10h]@1
  int xa; // [sp+30h] [bp+Ch]@1
  int ideal_w; // [sp+34h] [bp+10h]@1

  v9 = this;
  v10 = this->pnl_wid;
  v11 = v9->ideal_width;
  v12 = v9->pnl_hgt;
  v13 = v9->ideal_height;
  ideal_x = v10 * x / v11;
  ideal_w = v12 * y / v13;
  xa = v10 * width / v11;
  v14 = v12 * height / v13;
  v15 = (TButtonPanel *)operator new(0x2B8u);
  if ( v15 )
    TButtonPanel::TButtonPanel(v15);
  else
    v16 = 0;
  *button = (TButtonPanel *)v16;
  if ( v16
    && !*(_DWORD *)(v16 + 216)
    && (sound_num < 0 ? (v17 = 0) : (v17 = RGE_Base_Game::get_sound(rge_base_game, sound_num)),
        TButtonPanel::setup(
          (TPanel *)*button,
          v9->render_area,
          parent,
          ideal_x,
          ideal_w,
          xa,
          v14,
          (TPanel *)6,
          (TDigital *)v17,
          (TPanel *)1,
          action_id)) )
  {
    TButtonPanel::set_sound_number(*button, sound_num);
    TButtonPanel::set_state_info(*button, 2);
    if ( v9->button_pics )
    {
      TButtonPanel::setDrawType((int)*button, 6);
      TButtonPanel::set_picture(*button, 0, v9->button_pics, 0);
      TButtonPanel::set_picture(*button, 1, v9->button_pics, 2);
    }
    else
    {
      v18 = RGE_Base_Game::get_font(rge_base_game, 0);
      TButtonPanel::set_text_info(*button, text_in, v18->font, v18->font_wid, v18->font_hgt, -1, -1);
      TButtonPanel::set_text(*button, 1, asc_583B74);
      TButtonPanel::setDrawType((int)*button, 3);
    }
    if ( v9->use_bevels )
      TButtonPanel::set_bevel_info(
        *button,
        4,
        v9->bevel_color1,
        v9->bevel_color2,
        v9->bevel_color3,
        v9->bevel_color4,
        v9->bevel_color5,
        v9->bevel_color6);
    TButtonPanel::set_text_color(*button, 0, v9->text_color1, v9->text_color2);
    TButtonPanel::set_highlight_text_color(*button, 0, v9->focus_color1, v9->focus_color2);
    TButtonPanel::set_text_color(*button, 1, v9->state_color1, v9->state_color2);
    TButtonPanel::set_highlight_text_color(*button, 1, v9->focus_color1, v9->focus_color2);
    result = 1;
  }
  else
  {
    v9->error_code = 1;
    result = 0;
  }
  return result;
}

//----- (004689C0) --------------------------------------------------------
int __thiscall TEasy_Panel::create_radio_button(TEasy_Panel *this, TPanel *parent, TButtonPanel **button, int x, int y, int width, int height, int sound_num, int action_id)
{
  TEasy_Panel *v9; // esi@1
  int v10; // ecx@1
  signed int v11; // edi@1
  int v12; // ebx@1
  signed int v13; // ebp@1
  int v14; // ebx@1
  TButtonPanel *v15; // eax@1
  int v16; // eax@2
  TDigital **v17; // eax@7
  RGE_Font *v18; // eax@12
  int result; // eax@15
  int ideal_x; // [sp+14h] [bp-10h]@1
  int xa; // [sp+30h] [bp+Ch]@1
  int ideal_w; // [sp+34h] [bp+10h]@1

  v9 = this;
  v10 = this->pnl_wid;
  v11 = v9->ideal_width;
  v12 = v9->pnl_hgt;
  v13 = v9->ideal_height;
  ideal_x = v10 * x / v11;
  ideal_w = v12 * y / v13;
  xa = v10 * width / v11;
  v14 = v12 * height / v13;
  v15 = (TButtonPanel *)operator new(0x2B8u);
  if ( v15 )
    TButtonPanel::TButtonPanel(v15);
  else
    v16 = 0;
  *button = (TButtonPanel *)v16;
  if ( v16
    && !*(_DWORD *)(v16 + 216)
    && (sound_num < 0 ? (v17 = 0) : (v17 = RGE_Base_Game::get_sound(rge_base_game, sound_num)),
        TButtonPanel::setup(
          (TPanel *)*button,
          v9->render_area,
          parent,
          ideal_x,
          ideal_w,
          xa,
          v14,
          (TPanel *)2,
          (TDigital *)v17,
          (TPanel *)1,
          action_id)) )
  {
    TButtonPanel::set_sound_number(*button, sound_num);
    if ( v9->button_pics )
    {
      TButtonPanel::setDrawType((int)*button, 6);
      TButtonPanel::set_picture(*button, 0, v9->button_pics, 4);
      TButtonPanel::set_picture(*button, 1, v9->button_pics, 6);
    }
    else
    {
      TButtonPanel::setDrawType((int)*button, 3);
      v18 = RGE_Base_Game::get_font(rge_base_game, 0);
      TButtonPanel::set_text_info(*button, text_in, v18->font, v18->font_wid, v18->font_hgt, -1, -1);
      TButtonPanel::set_text(*button, 1, asc_583B74);
    }
    if ( v9->use_bevels )
      TButtonPanel::set_bevel_info(
        *button,
        4,
        v9->bevel_color1,
        v9->bevel_color2,
        v9->bevel_color3,
        v9->bevel_color4,
        v9->bevel_color5,
        v9->bevel_color6);
    TButtonPanel::set_text_color(*button, 0, v9->text_color1, v9->text_color2);
    TButtonPanel::set_highlight_text_color(*button, 0, v9->focus_color1, v9->focus_color2);
    TButtonPanel::set_text_color(*button, 1, v9->state_color1, v9->state_color2);
    TButtonPanel::set_highlight_text_color(*button, 1, v9->focus_color1, v9->focus_color2);
    result = 1;
  }
  else
  {
    v9->error_code = 1;
    result = 0;
  }
  return result;
}

//----- (00468C20) --------------------------------------------------------
int __thiscall TEasy_Panel::create_text(TEasy_Panel *this, TPanel *parent, TTextPanel **text_panel, int text_id, int x, int y, int width, int height, int font_num, int horz_center, int vert_center, int word_wrap)
{
  TEasy_Panel *v12; // esi@1
  char text[256]; // [sp+4h] [bp-100h]@1

  v12 = this;
  TPanel::get_string(text_id, text, 256);
  return ((int (__thiscall *)(TEasy_Panel *, TPanel *, TTextPanel **, char *, int, int, int, int, int, int, int, int))v12->vfptr[1].set_redraw)(
           v12,
           parent,
           text_panel,
           text,
           x,
           y,
           width,
           height,
           font_num,
           horz_center,
           vert_center,
           word_wrap);
}

//----- (00468CB0) --------------------------------------------------------
int __thiscall TEasy_Panel::create_text(TEasy_Panel *this, TPanel *parent, TTextPanel **text_panel, char *text, int x, int y, int width, int height, int font_num, int horz_center, int vert_center, int word_wrap)
{
  TEasy_Panel *v12; // esi@1
  int v13; // ecx@1
  signed int v14; // edi@1
  int v15; // ebx@1
  signed int v16; // ebp@1
  int v17; // edi@1
  int v18; // ebp@1
  TTextPanel *v19; // eax@1
  TTextPanel *v20; // eax@2
  RGE_Font *v21; // eax@7
  TTextPanel::Alignment v23; // [sp-4h] [bp-24h]@14
  int ideal_x; // [sp+10h] [bp-10h]@1
  int xa; // [sp+30h] [bp+10h]@1

  v12 = this;
  v13 = this->pnl_wid;
  v14 = v12->ideal_width;
  v15 = v12->pnl_hgt;
  v16 = v12->ideal_height;
  ideal_x = v13 * x / v14;
  xa = v15 * y / v16;
  v17 = v13 * width / v14;
  v18 = v15 * height / v16;
  v19 = (TTextPanel *)operator new(0x188u);
  if ( v19 )
    TTextPanel::TTextPanel(v19);
  else
    v20 = 0;
  *text_panel = v20;
  if ( v20 && !v20->error_code )
  {
    v21 = font_num < 0 ? RGE_Base_Game::get_font(rge_base_game, 10) : RGE_Base_Game::get_font(rge_base_game, font_num);
    if ( TTextPanel::setup(
           *text_panel,
           v12->render_area,
           parent,
           ideal_x,
           xa,
           v17,
           v18,
           v21->font,
           v21->font_wid,
           v21->font_hgt,
           0,
           0,
           0,
           0,
           0,
           0,
           0) )
    {
      if ( horz_center && vert_center )
      {
        TTextPanel::set_alignment(*text_panel, 0, 0);
LABEL_18:
        TTextPanel::set_word_wrap(*text_panel, word_wrap);
        (*(void (__stdcall **)(char *))&(*text_panel)->vfptr[1].gap4[4])(text);
        TTextPanel::set_text_color(*text_panel, v12->text_color1, v12->text_color2);
        TTextPanel::set_highlight_text_color(*text_panel, v12->focus_color1, v12->focus_color2);
        return 1;
      }
      if ( horz_center )
      {
        v23 = 0;
      }
      else
      {
        v23 = 1;
        if ( vert_center )
        {
          TTextPanel::set_alignment(*text_panel, 0, AlignLeft);
          goto LABEL_18;
        }
      }
      TTextPanel::set_alignment(*text_panel, AlignTop, v23);
      goto LABEL_18;
    }
  }
  v12->error_code = 1;
  return 0;
}

//----- (00468E50) --------------------------------------------------------
int __thiscall TEasy_Panel::create_text(TEasy_Panel *this, TPanel *parent, TTextPanel **text_panel, char **text, int line_num, int x, int y, int width, int height, int font_num, int horz_center, int vert_center)
{
  TEasy_Panel *v12; // esi@1
  int v13; // ecx@1
  signed int v14; // edi@1
  int v15; // ebx@1
  signed int v16; // ebp@1
  int v17; // edi@1
  int v18; // ebp@1
  TTextPanel *v19; // eax@1
  TTextPanel *v20; // eax@2
  RGE_Font *v21; // eax@7
  TTextPanel::Alignment v23; // [sp-4h] [bp-24h]@14
  int ideal_x; // [sp+10h] [bp-10h]@1
  int xa; // [sp+34h] [bp+14h]@1

  v12 = this;
  v13 = this->pnl_wid;
  v14 = v12->ideal_width;
  v15 = v12->pnl_hgt;
  v16 = v12->ideal_height;
  ideal_x = v13 * x / v14;
  xa = v15 * y / v16;
  v17 = v13 * width / v14;
  v18 = v15 * height / v16;
  v19 = (TTextPanel *)operator new(0x188u);
  if ( v19 )
    TTextPanel::TTextPanel(v19);
  else
    v20 = 0;
  *text_panel = v20;
  if ( v20 && !v20->error_code )
  {
    v21 = font_num < 0 ? RGE_Base_Game::get_font(rge_base_game, 10) : RGE_Base_Game::get_font(rge_base_game, font_num);
    if ( TTextPanel::setup(
           *text_panel,
           v12->render_area,
           parent,
           ideal_x,
           xa,
           v17,
           v18,
           v21->font,
           v21->font_wid,
           v21->font_hgt,
           0,
           0,
           0,
           0,
           0,
           0,
           0) )
    {
      ((void (__stdcall *)(char **, int))(*text_panel)->vfptr[1].__vecDelDtor)(text, line_num);
      TTextPanel::scroll(*text_panel, 6, 0, 1);
      if ( horz_center && vert_center )
      {
        TTextPanel::set_alignment(*text_panel, 0, 0);
LABEL_18:
        TTextPanel::set_text_color(*text_panel, v12->text_color1, v12->text_color2);
        TTextPanel::set_highlight_text_color(*text_panel, v12->focus_color1, v12->focus_color2);
        return 1;
      }
      if ( horz_center )
      {
        v23 = 0;
      }
      else
      {
        v23 = 1;
        if ( vert_center )
        {
          TTextPanel::set_alignment(*text_panel, 0, AlignLeft);
          goto LABEL_18;
        }
      }
      TTextPanel::set_alignment(*text_panel, AlignTop, v23);
      goto LABEL_18;
    }
  }
  v12->error_code = 1;
  return 0;
}

//----- (00469000) --------------------------------------------------------
int __thiscall TEasy_Panel::create_input(TEasy_Panel *this, TPanel *parent, TInputPanel **input_panel, char *value, __int16 max_len, TInputPanel::FormatType format_type, int x, int y, int width, int height, int font_num)
{
  TEasy_Panel *v11; // esi@1
  int v12; // ecx@1
  signed int v13; // edi@1
  int v14; // ebx@1
  signed int v15; // ebp@1
  int v16; // edi@1
  int v17; // ebp@1
  TInputPanel *v18; // eax@1
  TInputPanel *v19; // eax@2
  RGE_Font *v20; // eax@7
  int result; // eax@12
  int ideal_x; // [sp+10h] [bp-10h]@1
  int xa; // [sp+38h] [bp+18h]@1

  v11 = this;
  v12 = this->pnl_wid;
  v13 = v11->ideal_width;
  v14 = v11->pnl_hgt;
  v15 = v11->ideal_height;
  ideal_x = v12 * x / v13;
  xa = v14 * y / v15;
  v16 = v12 * width / v13;
  v17 = v14 * height / v15;
  v18 = (TInputPanel *)operator new(0x1B8u);
  if ( v18 )
    TInputPanel::TInputPanel(v18);
  else
    v19 = 0;
  *input_panel = v19;
  if ( v19
    && !v19->error_code
    && (font_num < 0 ? (v20 = RGE_Base_Game::get_font(rge_base_game, 10)) : (v20 = RGE_Base_Game::get_font(
                                                                                     rge_base_game,
                                                                                     font_num)),
        TInputPanel::setup(
          *input_panel,
          v11->render_area,
          parent,
          ideal_x,
          xa,
          v16,
          v17,
          v20->font,
          v20->font_wid,
          v20->font_hgt,
          0,
          0,
          0,
          1,
          -1,
          -1,
          max_len,
          0,
          value,
          format_type)) )
  {
    if ( v11->use_bevels )
      ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*input_panel)->vfptr[1].set_rect)(
        3,
        v11->bevel_color1,
        v11->bevel_color2,
        v11->bevel_color3,
        v11->bevel_color4,
        v11->bevel_color5,
        v11->bevel_color6);
    TTextPanel::set_text_color((TTextPanel *)&(*input_panel)->vfptr, v11->text_color1, v11->text_color2);
    TTextPanel::set_highlight_text_color((TTextPanel *)&(*input_panel)->vfptr, v11->focus_color1, v11->focus_color2);
    result = 1;
  }
  else
  {
    v11->error_code = 1;
    result = 0;
  }
  return result;
}

//----- (004691C0) --------------------------------------------------------
int __thiscall TEasy_Panel::create_edit(TEasy_Panel *this, TPanel *parent, TEditPanel **edit_panel, char *value, __int16 max_len, TEditPanel::FormatType format_type, int x, int y, int width, int height, int font_num, int enable_ime, int turn_ime_on)
{
  TEasy_Panel *v13; // esi@1
  int v14; // ecx@1
  signed int v15; // edi@1
  int v16; // ebp@1
  int v17; // ebx@1
  TEditPanel *v18; // eax@1
  TEditPanel *v19; // eax@2
  RGE_Font *v20; // eax@7
  int result; // eax@12
  int xa; // [sp+34h] [bp+18h]@1

  v13 = this;
  v14 = this->pnl_wid;
  v15 = v13->ideal_width;
  v16 = v14 * x / v15;
  v17 = y * v13->pnl_hgt / v13->ideal_height;
  xa = v14 * width / v15;
  v18 = (TEditPanel *)operator new(0x16Cu);
  if ( v18 )
    TEditPanel::TEditPanel(v18);
  else
    v19 = 0;
  *edit_panel = v19;
  if ( v19
    && !v19->error_code
    && (font_num < 0 ? (v20 = RGE_Base_Game::get_font(rge_base_game, 10)) : (v20 = RGE_Base_Game::get_font(
                                                                                     rge_base_game,
                                                                                     font_num)),
        TEditPanel::setup(
          *edit_panel,
          v13->render_area,
          parent,
          v16,
          v17,
          xa,
          height,
          v20->font,
          max_len,
          value,
          format_type,
          format_type != 7)) )
  {
    if ( v13->use_bevels )
      TEditPanel::set_bevel_info(
        *edit_panel,
        3,
        v13->bevel_color1,
        v13->bevel_color2,
        v13->bevel_color3,
        v13->bevel_color4,
        v13->bevel_color5,
        v13->bevel_color6);
    TEditPanel::set_text_color(*edit_panel, v13->text_color1, v13->text_color2);
    TEditPanel::set_highlight_text_color(*edit_panel, v13->focus_color1, v13->focus_color2);
    TEditPanel::set_back_color(*edit_panel, v13->brush, v13->brush_color, v13->background_color1);
    TEditPanel::set_ime_info(*edit_panel, enable_ime, turn_ime_on);
    result = 1;
  }
  else
  {
    v13->error_code = 1;
    result = 0;
  }
  return result;
}

//----- (00469380) --------------------------------------------------------
char *__thiscall TEasy_Panel::create_drop_down(TEasy_Panel *this, TPanel *parent, TDropDownPanel **drop_panel, int list_width, int list_height, int x, int y, int width, int height, int font_num)
{
  TEasy_Panel *v10; // ebx@1
  int v11; // ecx@1
  signed int v12; // esi@1
  int v13; // edi@1
  signed int v14; // ebp@1
  char *result; // eax@4
  char *v16; // esi@4
  TDropDownPanel *v17; // eax@8
  TDropDownPanel *v18; // eax@9
  RGE_Font *v19; // eax@13
  int v20; // eax@13
  TShape *v21; // eax@14
  TListPanel *v22; // edi@18
  signed int v23; // edi@20
  void **v24; // esi@20
  int ideal_h; // [sp+10h] [bp-1Ch]@1
  int ideal_w; // [sp+14h] [bp-18h]@1
  int ideal_y; // [sp+18h] [bp-14h]@1
  int ideal_x; // [sp+1Ch] [bp-10h]@1
  char **xa; // [sp+40h] [bp+14h]@4
  char **list; // [sp+44h] [bp+18h]@1
  int list_h; // [sp+4Ch] [bp+20h]@1

  v10 = this;
  v11 = this->pnl_wid;
  v12 = v10->ideal_width;
  v13 = v10->pnl_hgt;
  v14 = v10->ideal_height;
  ideal_x = v11 * x / v12;
  ideal_y = v13 * y / v14;
  ideal_w = v11 * width / v12;
  ideal_h = v13 * height / v14;
  list = (char **)(18 * v11 / v12);
  list_h = v11 * list_width / v12;
  if ( font_num < 0 )
    RGE_Base_Game::get_font(rge_base_game, 10);
  else
    RGE_Base_Game::get_font(rge_base_game, font_num);
  result = (char *)calloc(1u, 4u);
  v16 = result;
  xa = (char **)result;
  if ( result )
  {
    result = (char *)calloc(0x14u, 1u);
    *(_DWORD *)v16 = result;
    if ( result )
    {
      strcpy(result, text_in);
      if ( !v10->error_code )
      {
        v17 = (TDropDownPanel *)operator new(0x144u);
        if ( v17 )
          TDropDownPanel::TDropDownPanel(v17);
        else
          v18 = 0;
        *drop_panel = v18;
        if ( v18
          && !v18->error_code
          && (v19 = RGE_Base_Game::get_font(rge_base_game, font_num),
              TDropDownPanel::setup(
                *drop_panel,
                v10->render_area,
                parent,
                v19->font,
                v19->font_wid,
                v19->font_hgt,
                0,
                0,
                1,
                255,
                ideal_x,
                ideal_y,
                ideal_w,
                ideal_h,
                0,
                0,
                (int)list,
                ideal_h,
                0,
                list_h,
                v13 * list_height / v14,
                xa,
                1,
                (int)list,
                0,
                0,
                0,
                0,
                (int)list,
                (int)list),
              v20) )
        {
          v21 = v10->button_pics;
          if ( v21 )
            TDropDownPanel::set_buttons(*drop_panel, v21, 14, -1, 8, 10, 12);
          if ( v10->use_bevels )
            TDropDownPanel::set_bevel_info(
              *drop_panel,
              3,
              v10->bevel_color1,
              v10->bevel_color2,
              v10->bevel_color3,
              v10->bevel_color4,
              v10->bevel_color5,
              v10->bevel_color6);
          TDropDownPanel::set_val_text_color(*drop_panel, v10->text_color1, v10->text_color2);
          v22 = (*drop_panel)->list_panel;
          TTextPanel::set_text_color(
            (TTextPanel *)&(*drop_panel)->list_panel->vfptr,
            v10->text_color1,
            v10->text_color2);
          TTextPanel::set_highlight_text_color((TTextPanel *)&v22->vfptr, v10->focus_color1, v10->focus_color2);
          ((void (__stdcall *)(signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*drop_panel)->val_panel->vfptr[1].set_rect)(
            3,
            v10->bevel_color1,
            v10->bevel_color2,
            v10->bevel_color3,
            v10->bevel_color4,
            v10->bevel_color5,
            v10->bevel_color6);
        }
        else
        {
          v10->error_code = 1;
        }
      }
      v23 = 1;
      v24 = (void **)xa;
      do
      {
        if ( *v24 )
        {
          free(*v24);
          *v24 = 0;
        }
        ++v24;
        --v23;
      }
      while ( v23 );
      free(xa);
      result = (char *)(v10->error_code == 0);
    }
  }
  else
  {
    v10->error_code = 1;
  }
  return result;
}

//----- (004696B0) --------------------------------------------------------
char *__thiscall TEasy_Panel::create_list(TEasy_Panel *this, TPanel *parent, TListPanel **list_panel, int x, int y, int width, int height, int font_num)
{
  TEasy_Panel *v8; // ebx@1
  int v9; // ecx@1
  signed int v10; // esi@1
  int v11; // edi@1
  signed int v12; // ebp@1
  char *result; // eax@4
  char *v14; // esi@4
  TListPanel *v15; // eax@8
  TListPanel *v16; // eax@9
  RGE_Font *v17; // eax@13
  void **v18; // esi@16
  signed int v19; // ebp@16
  int ideal_x; // [sp+18h] [bp-10h]@1
  char **xa; // [sp+34h] [bp+Ch]@4
  int ideal_h; // [sp+3Ch] [bp+14h]@1

  v8 = this;
  v9 = this->pnl_wid;
  v10 = v8->ideal_width;
  v11 = v8->pnl_hgt;
  v12 = v8->ideal_height;
  ideal_x = v9 * x / v10;
  ideal_h = v9 * width / v10;
  if ( font_num < 0 )
    RGE_Base_Game::get_font(rge_base_game, 10);
  else
    RGE_Base_Game::get_font(rge_base_game, font_num);
  result = (char *)calloc(1u, 4u);
  v14 = result;
  xa = (char **)result;
  if ( result )
  {
    result = (char *)calloc(0x14u, 1u);
    *(_DWORD *)v14 = result;
    if ( result )
    {
      strcpy(result, text_in);
      if ( !v8->error_code )
      {
        v15 = (TListPanel *)operator new(0x1A0u);
        if ( v15 )
          TListPanel::TListPanel(v15);
        else
          v16 = 0;
        *list_panel = v16;
        if ( v16
          && !v16->error_code
          && (v17 = RGE_Base_Game::get_font(rge_base_game, font_num),
              TTextPanel::setup(
                (TTextPanel *)&(*list_panel)->vfptr,
                v8->render_area,
                parent,
                ideal_x,
                v11 * y / v12,
                ideal_h,
                v11 * height / v12,
                v17->font,
                v17->font_wid,
                v17->font_hgt,
                0,
                0,
                0,
                1,
                -1,
                0,
                xa,
                1)) )
        {
          TListPanel::scroll_cur_line(*list_panel, 1, 0, 1);
        }
        else
        {
          v8->error_code = 1;
        }
      }
      v18 = (void **)xa;
      v19 = 1;
      do
      {
        if ( *v18 )
        {
          free(*v18);
          *v18 = 0;
        }
        ++v18;
        --v19;
      }
      while ( v19 );
      free(xa);
      if ( v8->use_bevels )
        ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))(*list_panel)->vfptr[1].set_rect)(
          3,
          v8->bevel_color1,
          v8->bevel_color2,
          v8->bevel_color3,
          v8->bevel_color4,
          v8->bevel_color5,
          v8->bevel_color6);
      TTextPanel::set_text_color((TTextPanel *)&(*list_panel)->vfptr, v8->text_color1, v8->text_color2);
      TTextPanel::set_highlight_text_color((TTextPanel *)&(*list_panel)->vfptr, v8->focus_color1, v8->focus_color2);
      result = (char *)1;
    }
  }
  else
  {
    v8->error_code = 1;
  }
  return result;
}

//----- (00469910) --------------------------------------------------------
int __thiscall TEasy_Panel::create_scrollbar(TEasy_Panel *this, TPanel *parent, TScrollBarPanel **scrollbar_panel, TTextPanel *list_panel, int list_size, int x, int y, int width, int height)
{
  TEasy_Panel *v9; // esi@1
  int v10; // eax@1
  int v11; // ecx@1
  signed int v12; // edi@1
  int v13; // ebx@1
  int v14; // ebp@1
  TScrollBarPanel *v15; // eax@1
  TScrollBarPanel *v16; // eax@2
  TScrollBarPanel **v17; // ebx@8
  TShape *v18; // eax@10
  int result; // eax@14
  int xa; // [sp+30h] [bp+14h]@1

  v9 = this;
  v10 = this->pnl_wid;
  v11 = this->pnl_hgt;
  v12 = v9->ideal_height;
  v13 = x * v10 / v9->ideal_width;
  v14 = v11 * y / v12;
  xa = v11 * height / v12;
  v15 = (TScrollBarPanel *)operator new(0x1C4u);
  if ( v15 )
    TScrollBarPanel::TScrollBarPanel(v15);
  else
    v16 = 0;
  *scrollbar_panel = v16;
  if ( v16
    && !v16->error_code
    && TScrollBarPanel::setup(
         v16,
         v9->render_area,
         parent,
         v13,
         v14,
         width,
         xa,
         0,
         0,
         0,
         0,
         width,
         width,
         (TPanel *)&list_panel->vfptr,
         list_size,
         0) )
  {
    if ( list_panel )
    {
      v17 = scrollbar_panel;
      TTextPanel::set_scrollbar(list_panel, *scrollbar_panel, 0);
    }
    else
    {
      v17 = scrollbar_panel;
    }
    v18 = v9->button_pics;
    if ( v18 )
      TScrollBarPanel::set_buttons(*v17, v18, -1, 8, 10, 12);
    if ( v9->use_bevels )
      TScrollBarPanel::set_bevel_info(
        *v17,
        3,
        v9->bevel_color1,
        v9->bevel_color2,
        v9->bevel_color3,
        v9->bevel_color4,
        v9->bevel_color5,
        v9->bevel_color6);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00469A80) --------------------------------------------------------
int __thiscall TEasy_Panel::create_auto_scrollbar(TEasy_Panel *this, TScrollBarPanel **scrollbar_panel, TTextPanel *list_panel, int width)
{
  int result; // eax@1

  result = ((int (__stdcall *)(TPanel *, TScrollBarPanel **, TTextPanel *, _DWORD, _DWORD, _DWORD, int, _DWORD))this->vfptr[1].draw_rect)(
             list_panel->parent_panel,
             scrollbar_panel,
             list_panel,
             0,
             0,
             0,
             width,
             0);
  if ( result )
  {
    TTextPanel::set_scrollbar(list_panel, *scrollbar_panel, 1);
    result = 1;
  }
  return result;
}

//----- (00469AD0) --------------------------------------------------------
int __thiscall TEasy_Panel::create_vert_slider(TEasy_Panel *this, TPanel *parent, TVerticalSliderPanel **slider_panel, int scale, int one_step, int page_step, int x, int y, int width, int height)
{
  TEasy_Panel *v10; // esi@1
  int v11; // ecx@1
  signed int v12; // edi@1
  int v13; // ebx@1
  signed int v14; // ebp@1
  int v15; // edi@1
  int v16; // ebx@1
  TVerticalSliderPanel *v17; // eax@1
  TVerticalSliderPanel *v18; // eax@2
  TShape *v19; // eax@7
  int result; // eax@11
  int ideal_x; // [sp+10h] [bp-10h]@1
  int xa; // [sp+38h] [bp+18h]@1

  v10 = this;
  v11 = this->pnl_wid;
  v12 = v10->ideal_width;
  v13 = v10->pnl_hgt;
  v14 = v10->ideal_height;
  ideal_x = v11 * x / v12;
  xa = v13 * y / v14;
  v15 = v11 * width / v12;
  v16 = v13 * height / v14;
  v17 = (TVerticalSliderPanel *)operator new(0x1CCu);
  if ( v17 )
    TVerticalSliderPanel::TVerticalSliderPanel(v17);
  else
    v18 = 0;
  *slider_panel = v18;
  if ( v18
    && !v18->error_code
    && TVerticalSliderPanel::setup(
         v18,
         v10->render_area,
         parent,
         ideal_x,
         xa,
         v15,
         v16,
         0,
         0,
         0,
         scale,
         one_step,
         page_step,
         1,
         0) )
  {
    v19 = v10->button_pics;
    if ( v19 )
      TScrollBarPanel::set_buttons((TScrollBarPanel *)&(*slider_panel)->vfptr, v19, -1, 8, 10, 12);
    if ( v10->use_bevels )
      TScrollBarPanel::set_bevel_info(
        (TScrollBarPanel *)&(*slider_panel)->vfptr,
        3,
        v10->bevel_color1,
        v10->bevel_color2,
        v10->bevel_color3,
        v10->bevel_color4,
        v10->bevel_color5,
        v10->bevel_color6);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00469C40) --------------------------------------------------------
int __thiscall TEasy_Panel::create_horz_slider(TEasy_Panel *this, TPanel *parent, THorizontalSliderPanel **slider_panel, int scale, int one_step, int page_step, int x, int y, int width, int height)
{
  TEasy_Panel *v10; // esi@1
  int v11; // ecx@1
  signed int v12; // edi@1
  int v13; // ebx@1
  signed int v14; // ebp@1
  int v15; // edi@1
  int v16; // ebx@1
  THorizontalSliderPanel *v17; // eax@1
  THorizontalSliderPanel *v18; // eax@2
  TShape *v19; // eax@7
  int result; // eax@11
  int ideal_x; // [sp+10h] [bp-10h]@1
  int xa; // [sp+38h] [bp+18h]@1

  v10 = this;
  v11 = this->pnl_wid;
  v12 = v10->ideal_width;
  v13 = v10->pnl_hgt;
  v14 = v10->ideal_height;
  ideal_x = v11 * x / v12;
  xa = v13 * y / v14;
  v15 = v11 * width / v12;
  v16 = v13 * height / v14;
  v17 = (THorizontalSliderPanel *)operator new(0x1CCu);
  if ( v17 )
    THorizontalSliderPanel::THorizontalSliderPanel(v17);
  else
    v18 = 0;
  *slider_panel = v18;
  if ( v18
    && !v18->error_code
    && THorizontalSliderPanel::setup(
         v18,
         v10->render_area,
         parent,
         ideal_x,
         xa,
         v15,
         v16,
         0,
         0,
         0,
         scale,
         one_step,
         page_step,
         1,
         0) )
  {
    v19 = v10->button_pics;
    if ( v19 )
      TScrollBarPanel::set_buttons((TScrollBarPanel *)&(*slider_panel)->vfptr, v19, -1, 8, 10, 12);
    if ( v10->use_bevels )
      TScrollBarPanel::set_bevel_info(
        (TScrollBarPanel *)&(*slider_panel)->vfptr,
        3,
        v10->bevel_color1,
        v10->bevel_color2,
        v10->bevel_color3,
        v10->bevel_color4,
        v10->bevel_color5,
        v10->bevel_color6);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00469DB0) --------------------------------------------------------
void __thiscall TEasy_Panel::position_panel(TEasy_Panel *this, TPanel *panel, int x, int y, int width, int height)
{
  ((void (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))panel->vfptr->set_fixed_position)(
    panel,
    this->pnl_wid * x % this->ideal_width,
    this->pnl_wid * x / this->ideal_width,
    this->pnl_hgt * y / this->ideal_height,
    this->pnl_wid * width / this->ideal_width,
    this->pnl_hgt * height / this->ideal_height);
}

//----- (00469E10) --------------------------------------------------------
void __thiscall TEasy_Panel::set_focus(TEasy_Panel *this, int have_focus_in)
{
  TEasy_Panel *v2; // esi@1
  TMousePointer *v3; // ecx@4
  TDrawArea *v4; // ecx@6
  void *v5; // edi@8

  v2 = this;
  TPanel::set_focus((TPanel *)&this->vfptr, have_focus_in);
  if ( v2->have_focus )
  {
    if ( v2->cursor_file[0] || v2->cursor_id >= 0 )
    {
      v3 = rge_base_game->mouse_pointer;
      if ( v3 )
        TMousePointer::LoadCursors(v3, v2->cursor_file, v2->cursor_id, 0);
    }
    v4 = v2->render_area;
    if ( v4 )
    {
      if ( v4->DrawSystem )
      {
        v5 = v2->palette;
        if ( v5 || (v5 = rge_base_game->prog_palette) != 0 )
        {
          if ( v4->DrawSystem->Pal != v5 )
          {
            TDrawArea::Clear(v4, 0, 0);
            TDrawSystem::Paint(v2->render_area->DrawSystem, 0);
            TDrawSystem::SetPalette(v2->render_area->DrawSystem, v5);
            v2->vfptr->set_redraw((TPanel *)v2, RedrawFull);
          }
        }
      }
    }
  }
  if ( v2->enable_ime )
  {
    if ( v2->have_focus )
      TPanelSystem::EnableIME(&panel_system);
    else
      TPanelSystem::DisableIME(&panel_system);
  }
}

//----- (00469EE0) --------------------------------------------------------
void __thiscall TEasy_Panel::popupOKDialog(TEasy_Panel *this, int text_id, char *panel_title, int wid, int hgt)
{
  TEasy_Panel *v5; // esi@1
  char text[256]; // [sp+4h] [bp-100h]@1

  v5 = this;
  TPanel::get_string(text_id, text, 256);
  TEasy_Panel::popupOKDialog(v5, text, panel_title, wid, hgt);
}

//----- (00469F30) --------------------------------------------------------
void __thiscall TEasy_Panel::popupOKDialog(TEasy_Panel *this, char *text, char *panel_title, int wid, int hgt)
{
  char *v5; // edi@1
  TEasy_Panel *v6; // ebx@1
  char *v7; // edx@3
  TMessageDialog *v8; // eax@7
  TMessageDialog *v9; // eax@8
  int v10; // ST08_4@10
  char temp_title[256]; // [sp+10h] [bp-10Ch]@3
  int v12; // [sp+118h] [bp-4h]@7

  v5 = panel_title;
  v6 = this;
  if ( panel_title && *panel_title )
  {
    v7 = temp_title;
  }
  else
  {
    v7 = temp_title;
    v5 = aOkdialog;
  }
  strcpy(v7, v5);
  if ( TPanelSystem::panel(&panel_system, temp_title) )
    TPanelSystem::destroyPanel(&panel_system, temp_title);
  v8 = (TMessageDialog *)operator new(0x4A4u);
  v12 = 0;
  if ( v8 )
    TMessageDialog::TMessageDialog(v8, temp_title);
  else
    v9 = 0;
  v10 = v6->popup_info_id;
  v12 = -1;
  TMessageDialog::setup(v9, (TPanel *)&v6->vfptr, v6->popup_info_file_name, v10, wid, hgt, 0, text, 90, 30);
}

//----- (0046A040) --------------------------------------------------------
void __thiscall TEasy_Panel::popupYesNoDialog(TEasy_Panel *this, int text_id, char *panel_title, int wid, int hgt)
{
  TEasy_Panel *v5; // esi@1
  char text[256]; // [sp+4h] [bp-100h]@1

  v5 = this;
  TPanel::get_string(text_id, text, 256);
  TEasy_Panel::popupYesNoDialog(v5, text, panel_title, wid, hgt);
}

//----- (0046A090) --------------------------------------------------------
void __thiscall TEasy_Panel::popupYesNoDialog(TEasy_Panel *this, char *text, char *panel_title, int wid, int hgt)
{
  TEasy_Panel *v5; // edi@1
  TMessageDialog *v6; // eax@3
  TMessageDialog *v7; // eax@4
  TMessageDialog *v8; // eax@5

  v5 = this;
  if ( !panel_title || !*panel_title )
  {
    v8 = (TMessageDialog *)operator new(0x4A4u);
    if ( v8 )
    {
      TMessageDialog::TMessageDialog(v8, aYesnodialog);
      goto LABEL_8;
    }
LABEL_7:
    v7 = 0;
    goto LABEL_8;
  }
  v6 = (TMessageDialog *)operator new(0x4A4u);
  if ( !v6 )
    goto LABEL_7;
  TMessageDialog::TMessageDialog(v6, panel_title);
LABEL_8:
  TMessageDialog::setup(
    v7,
    (TPanel *)&v5->vfptr,
    v5->popup_info_file_name,
    v5->popup_info_id,
    wid,
    hgt,
    2,
    text,
    90,
    30);
}

//----- (0046A150) --------------------------------------------------------
void __thiscall TEasy_Panel::popupYesNoCancelDialog(TEasy_Panel *this, int text_id, char *panel_title, int wid, int hgt)
{
  TEasy_Panel *v5; // esi@1
  char text[256]; // [sp+4h] [bp-100h]@1

  v5 = this;
  TPanel::get_string(text_id, text, 256);
  TEasy_Panel::popupYesNoCancelDialog(v5, text, panel_title, wid, hgt);
}

//----- (0046A1A0) --------------------------------------------------------
void __thiscall TEasy_Panel::popupYesNoCancelDialog(TEasy_Panel *this, char *text, char *panel_title, int wid, int hgt)
{
  TEasy_Panel *v5; // edi@1
  TMessageDialog *v6; // eax@3
  TMessageDialog *v7; // eax@4
  TMessageDialog *v8; // eax@5

  v5 = this;
  if ( !panel_title || !*panel_title )
  {
    v8 = (TMessageDialog *)operator new(0x4A4u);
    if ( v8 )
    {
      TMessageDialog::TMessageDialog(v8, aYesnocanceldia);
      goto LABEL_8;
    }
LABEL_7:
    v7 = 0;
    goto LABEL_8;
  }
  v6 = (TMessageDialog *)operator new(0x4A4u);
  if ( !v6 )
    goto LABEL_7;
  TMessageDialog::TMessageDialog(v6, panel_title);
LABEL_8:
  TMessageDialog::setup(
    v7,
    (TPanel *)&v5->vfptr,
    v5->popup_info_file_name,
    v5->popup_info_id,
    wid,
    hgt,
    4,
    text,
    120,
    25);
}

//----- (0046A260) --------------------------------------------------------
void __thiscall TEasy_Panel::command_help(TEasy_Panel *this, char *in_parent_panel, int help_string, int help_page, int x, int y)
{
  TEasy_Panel *v6; // esi@1
  THelpDialog *v7; // eax@4

  v6 = this;
  if ( help_string >= 0 && (TPanel::get_string(help_string) || (_BYTE)v0) )
  {
    v7 = (THelpDialog *)operator new(0x5A4u);
    if ( v7 )
      THelpDialog::THelpDialog(v7, v6, in_parent_panel, help_string, help_page, x, y);
  }
}

//----- (0046A2E0) --------------------------------------------------------
void __thiscall TEasy_Panel::command_help(TEasy_Panel *this, char *in_parent_panel, char *help_string, int help_page, int x, int y)
{
  TEasy_Panel *v6; // edi@1
  THelpDialog *v7; // eax@3

  v6 = this;
  if ( help_string && *help_string )
  {
    v7 = (THelpDialog *)operator new(0x5A4u);
    if ( v7 )
      THelpDialog::THelpDialog(v7, v6, in_parent_panel, help_string, help_page, x, y);
  }
}

//----- (0046A360) --------------------------------------------------------
void __thiscall TEasy_Panel::setup_popup_help(TEasy_Panel *this)
{
  TEasy_Panel *v1; // esi@1
  HCURSOR v2; // eax@1

  v1 = this;
  this->help_mode = 1;
  v2 = LoadCursorA(0, (LPCSTR)0x7F8B);
  RGE_Base_Game::set_mouse_cursor(rge_base_game, v2);
  RGE_Base_Game::set_mouse_facet(rge_base_game, 6);
  v1->saved_mouse_mode = TMousePointer::get_game_enable(rge_base_game->mouse_pointer);
  TMousePointer::set_game_enable(rge_base_game->mouse_pointer, 0);
}

//----- (0046A3C0) --------------------------------------------------------
void __thiscall TEasy_Panel::clear_popup_help(TEasy_Panel *this)
{
  TEasy_Panel *v1; // esi@1
  HCURSOR v2; // eax@1

  v1 = this;
  this->help_mode = 0;
  v2 = LoadCursorA(0, (LPCSTR)0x7F00);
  RGE_Base_Game::set_mouse_cursor(rge_base_game, v2);
  RGE_Base_Game::set_mouse_facet(rge_base_game, 0);
  TMousePointer::set_game_enable(rge_base_game->mouse_pointer, v1->saved_mouse_mode);
}

//----- (0046A410) --------------------------------------------------------
int __thiscall TEasy_Panel::command_do_popup_help(TEasy_Panel *this, char mouse_button_in, int mouse_x, int mouse_y)
{
  TEasy_Panel *v4; // esi@1
  HCURSOR v5; // eax@2
  int result; // eax@5
  int help_page; // [sp+10h] [bp-3F0h]@3
  char *temp; // [sp+14h] [bp-3ECh]@1
  char help_string2[1000]; // [sp+18h] [bp-3E8h]@1

  v4 = this;
  temp = help_string2;
  if ( this->help_mode == 1 )
  {
    this->help_mode = 0;
    v5 = LoadCursorA(0, (LPCSTR)0x7F00);
    RGE_Base_Game::set_mouse_cursor(rge_base_game, v5);
    RGE_Base_Game::set_mouse_facet(rge_base_game, 0);
    TMousePointer::set_game_enable(rge_base_game->mouse_pointer, v4->saved_mouse_mode);
    if ( mouse_button_in == 1 )
    {
      if ( v4->vfptr->get_help_info((TPanel *)v4, &temp, &help_page, mouse_x, mouse_y) )
        TEasy_Panel::command_help(v4, v4->panelNameValue, help_string2, help_page, mouse_x, mouse_y);
    }
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (0046A4E0) --------------------------------------------------------
int __thiscall TEasy_Panel::action(TEasy_Panel *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TEasy_Panel *v5; // ebp@1

  v5 = this;
  if ( fromPanel )
  {
    if ( TPanel::panelName(fromPanel) && !strcmp(TPanel::panelName(fromPanel), aOkdialog) )
    {
      if ( !actionIn || actionIn == 1 )
      {
        TPanelSystem::destroyPanel(&panel_system, aOkdialog);
        return 1;
      }
      return 1;
    }
    if ( TPanel::panelName(fromPanel) && !strcmp(TPanel::panelName(fromPanel), aYesnodialog) )
    {
      if ( !actionIn || actionIn == 1 )
      {
        TPanelSystem::destroyPanel(&panel_system, aYesnodialog);
        return 1;
      }
      return 1;
    }
    if ( TPanel::panelName(fromPanel) && !strcmp(TPanel::panelName(fromPanel), aYesnocanceldia) )
    {
      if ( !actionIn || actionIn == 1 || actionIn == 2 )
        TPanelSystem::destroyPanel(&panel_system, aYesnocanceldia);
      return 1;
    }
  }
  return TPanel::action((TPanel *)&v5->vfptr, fromPanel, actionIn, a1, a2);
}

//----- (0046A670) --------------------------------------------------------
void __thiscall TEasy_Panel::set_system_colors(TEasy_Panel *this)
{
  TEasy_Panel *v1; // esi@1
  unsigned int cols; // [sp+Ch] [bp-10h]@1
  int elems; // [sp+10h] [bp-Ch]@1
  tagPALETTEENTRY pe; // [sp+14h] [bp-8h]@1

  v1 = this;
  GetPaletteEntries(this->palette, this->color, 1u, &pe);
  cols = (unsigned __int8)pe.peRed | (*(unsigned __int16 *)&pe.peGreen << 8);
  elems = 5;
  SetSysColors(1, &elems, &cols);
  GetPaletteEntries(v1->palette, v1->text_color1, 1u, &pe);
  elems = 8;
  cols = (unsigned __int8)pe.peRed | (*(unsigned __int16 *)&pe.peGreen << 8);
  SetSysColors(1, &elems, &cols);
}
