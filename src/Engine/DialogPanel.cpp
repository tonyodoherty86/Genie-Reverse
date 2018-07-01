
//----- (00473C10) --------------------------------------------------------
void __thiscall TDialogPanel::TDialogPanel(TDialogPanel *this, char *panel_name_in)
{
  TDialogPanel *v2; // esi@1

  v2 = this;
  TEasy_Panel::TEasy_Panel((TEasy_Panel *)&this->vfptr, panel_name_in);
  v2->text_font_id = 11;
  v2->input_font_id = 11;
  v2->button_font_id = 11;
  v2->dlg_wnd = 0;
  v2->save_parent_child = 0;
  v2->button_sound_id = 0;
  v2->vfptr = (TPanelVtbl *)&TDialogPanel::`vftable';
}
// 5710B0: using guessed type int (__thiscall *TDialogPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00473C60) --------------------------------------------------------
TDialogPanel *__thiscall TDialogPanel::`vector deleting destructor'(TDialogPanel *this, unsigned int __flags)
{
  TDialogPanel *v2; // esi@1

  v2 = this;
  TDialogPanel::~TDialogPanel(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00473C80) --------------------------------------------------------
int __thiscall TDialogPanel::setup(TDialogPanel *this, TDrawArea *render_area_in, TPanel *parent_in, int wid_in, int hgt_in, char *info_file_name, int resource_file_id, int allow_shadow_area_in)
{
  TDialogPanel *v8; // esi@1
  int v9; // ebx@2
  int v10; // ebp@2
  int result; // eax@4
  TPanel *v12; // ecx@6

  v8 = this;
  if ( parent_in )
  {
    v9 = TPanel::width(parent_in);
    v10 = TPanel::height(parent_in);
    TPanel::xPosition(parent_in);
    TPanel::yPosition(parent_in);
  }
  else
  {
    v9 = render_area_in->Width;
    v10 = render_area_in->Height;
  }
  result = TEasy_Panel::setup(
             (TEasy_Panel *)&v8->vfptr,
             render_area_in,
             parent_in,
             info_file_name,
             resource_file_id,
             0,
             v9 / 2 - wid_in / 2,
             v10 / 2 - hgt_in / 2,
             wid_in,
             hgt_in,
             allow_shadow_area_in);
  if ( result )
  {
    v12 = v8->parent_panel;
    if ( v12 )
    {
      v8->save_parent_child = v12->curr_child;
      TPanel::set_curr_child(v12, (TPanel *)&v8->vfptr);
    }
    TPanel::set_z_order((TPanel *)&v8->vfptr, 1, 0);
    TPanelSystem::setModalPanel(&panel_system, (TPanel *)&v8->vfptr);
    result = 1;
  }
  else
  {
    v8->error_code = 1;
  }
  return result;
}

//----- (00473D60) --------------------------------------------------------
int __thiscall TDialogPanel::setup(TDialogPanel *this, TDrawArea *render_area_in, TPanel *parent_in, int wid_in, int hgt_in, int color_in, int allow_shadow_area_in)
{
  TDialogPanel *v7; // esi@1
  int v8; // ebx@2
  int v9; // ebp@2
  int result; // eax@4
  TPanel *v11; // ecx@6

  v7 = this;
  if ( parent_in )
  {
    v8 = TPanel::width(parent_in);
    v9 = TPanel::height(parent_in);
  }
  else
  {
    v8 = render_area_in->Width;
    v9 = render_area_in->Height;
  }
  result = TEasy_Panel::setup(
             (TEasy_Panel *)&v7->vfptr,
             render_area_in,
             parent_in,
             0,
             -1,
             0,
             v8 / 2 - wid_in / 2,
             v9 / 2 - hgt_in / 2,
             wid_in,
             hgt_in,
             allow_shadow_area_in);
  if ( result )
  {
    (*(void (__thiscall **)(TDialogPanel *, int))&v7->vfptr->gap10[0])(v7, color_in);
    TPanel::set_z_order((TPanel *)&v7->vfptr, 1, 0);
    TPanelSystem::setModalPanel(&panel_system, (TPanel *)&v7->vfptr);
    v11 = v7->parent_panel;
    if ( v11 )
    {
      v7->save_parent_child = v11->curr_child;
      TPanel::set_curr_child(v11, (TPanel *)&v7->vfptr);
    }
    result = 1;
  }
  else
  {
    v7->error_code = 1;
  }
  return result;
}

//----- (00473E40) --------------------------------------------------------
void __thiscall TDialogPanel::~TDialogPanel(TDialogPanel *this)
{
  TDialogPanel *v1; // esi@1
  TPanel *v2; // ecx@3

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TDialogPanel::`vftable';
  if ( !TPanelSystem::restorePreviousModalPanel(&panel_system) )
    TPanelSystem::setModalPanel(&panel_system, 0);
  v2 = v1->parent_panel;
  if ( v2 )
  {
    ((void (__stdcall *)(signed int))v2->vfptr->set_redraw)(2);
    TPanel::set_curr_child(v1->parent_panel, v1->save_parent_child);
  }
  TEasy_Panel::~TEasy_Panel((TEasy_Panel *)&v1->vfptr);
}
// 5710B0: using guessed type int (__thiscall *TDialogPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00473EC0) --------------------------------------------------------
void __thiscall TDialogPanel::set_focus(TDialogPanel *this, int have_focus_in)
{
  TEasy_Panel::set_focus((TEasy_Panel *)&this->vfptr, have_focus_in);
}
