
//----- (0047BA70) --------------------------------------------------------
void __thiscall TScreenPanel::TScreenPanel(TScreenPanel *this)
{
  TScreenPanel *v1; // esi@1

  v1 = this;
  TEasy_Panel::TEasy_Panel((TEasy_Panel *)&this->vfptr);
  v1->vfptr = (TPanelVtbl *)&TScreenPanel::`vftable';
}
// 571910: using guessed type int (__thiscall *TScreenPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (0047BA90) --------------------------------------------------------
TScreenPanel *__thiscall TScreenPanel::`scalar deleting destructor'(TScreenPanel *this, unsigned int __flags)
{
  TScreenPanel *v2; // esi@1

  v2 = this;
  TScreenPanel::~TScreenPanel(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0047BAB0) --------------------------------------------------------
void __thiscall TScreenPanel::TScreenPanel(TScreenPanel *this, char *name)
{
  TScreenPanel *v2; // esi@1

  v2 = this;
  TEasy_Panel::TEasy_Panel((TEasy_Panel *)&this->vfptr, name);
  v2->vfptr = (TPanelVtbl *)&TScreenPanel::`vftable';
}
// 571910: using guessed type int (__thiscall *TScreenPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (0047BAD0) --------------------------------------------------------
void __thiscall TScreenPanel::~TScreenPanel(TScreenPanel *this)
{
  this->vfptr = (TPanelVtbl *)&TScreenPanel::`vftable';
  TEasy_Panel::~TEasy_Panel((TEasy_Panel *)&this->vfptr);
}
// 571910: using guessed type int (__thiscall *TScreenPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (0047BAE0) --------------------------------------------------------
BOOL __thiscall TScreenPanel::setup(TScreenPanel *this, TDrawArea *render_area_in, char *info_file_name, int resource_file_id, int allow_shadow_area_in)
{
  return TEasy_Panel::setup(
           (TEasy_Panel *)&this->vfptr,
           render_area_in,
           0,
           info_file_name,
           resource_file_id,
           1,
           0,
           0,
           0,
           0,
           allow_shadow_area_in) != 0;
}

//----- (0047BB10) --------------------------------------------------------
BOOL __thiscall TScreenPanel::setup(TScreenPanel *this, TDrawArea *render_area_in, char *palette_file, int pal_res_id, char color_in, int allow_shadow_area_in)
{
  return TEasy_Panel::setup((TEasy_Panel *)&this->vfptr, render_area_in, 0, 0, -1, 1, 0, 0, 0, 0, allow_shadow_area_in) != 0;
}

//----- (0047BB50) --------------------------------------------------------
int __thiscall TScreenPanel::handle_paint(TScreenPanel *this)
{
  TPanel::handle_paint((TPanel *)&this->vfptr);
  return 0;
}

//----- (0047BB60) --------------------------------------------------------
void __thiscall TScreenPanel::set_focus(TScreenPanel *this, int have_focus_in)
{
  TScreenPanel *v2; // esi@1
  bool v3; // zf@1
  TDrawArea *v4; // ecx@1
  bool v5; // bl@1
  TDrawSystem *v6; // eax@2
  void *v7; // eax@7
  tagPALETTEENTRY v8; // edi@10
  TDrawArea *v9; // eax@12
  TDrawSystem *v10; // ecx@13
  tagPALETTEENTRY color; // [sp+10h] [bp-408h]@0
  int save_focus; // [sp+14h] [bp-404h]@1
  tagPALETTEENTRY color_table[256]; // [sp+18h] [bp-400h]@8

  v2 = this;
  v3 = this == last_screen;
  v4 = this->render_area;
  v5 = !v3;
  save_focus = v2->have_focus;
  if( v4 && (v6 = v4->DrawSystem) != 0 && have_focus_in && !v3 && (v6->ScreenMode == 2 || v6->DrawType == 1) )
  {
    v7 = v2->palette;
    *(_WORD *)&color.peRed = 0;
    color.peBlue = 0;
    if( v7 )
      GetPaletteEntries(v7, 0, 0x100u, color_table);
    else
      TDrawArea::GetPalette(v4, color_table);
    v8 = color;
    RGE_fade_palette(v2->render_area, color, 0.13, 1, 0, -1, -1);
    TDrawArea::Clear(v2->render_area, 0, 0);
    TDrawSystem::Paint(v2->render_area->DrawSystem, 0);
  }
  else
  {
    v8 = color;
  }
  TEasy_Panel::set_focus((TEasy_Panel *)&v2->vfptr, have_focus_in);
  v9 = v2->render_area;
  if( v9 )
  {
    v10 = v9->DrawSystem;
    if( v9->DrawSystem )
    {
      if( have_focus_in && v5 && (v10->ScreenMode == 2 || v10->DrawType == 1) )
      {
        RGE_fade_palette(v9, v8, 0.0, 2, color_table, -1, -1);
        v2->vfptr->handle_paint((TPanel *)v2);
        RGE_fade_palette(v2->render_area, v8, 0.0, 1, 0, -1, -1);
        TDrawSystem::Paint(v2->render_area->DrawSystem, 0);
        RGE_fade_palette(v2->render_area, v8, 0.13, 2, color_table, -1, -1);
      }
    }
  }
  if( have_focus_in != save_focus )
  {
    if( v2->have_focus )
      last_screen = v2;
  }
}
// 86B248: using guessed type struct TScreenPanel *last_screen;
