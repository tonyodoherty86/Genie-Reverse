
//----- (0043E840) --------------------------------------------------------
void __thiscall THelpDialog::THelpDialog(THelpDialog *this, TEasy_Panel *parentPanel, char *in_parent_panel, int help_string_id, int in_help_page_id, int x, int y)
{
  THelpDialog *v7; // esi@1
  char *v8; // eax@1

  v7 = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)&this->vfptr, aHelpDialog);
  v7->vfptr = (TPanelVtbl *)&THelpDialog::`vftable';
  v8 = TPanel::get_string(help_string_id);
  THelpDialog::setup_help(v7, parentPanel, in_parent_panel, v8, in_help_page_id, x, y);
}
// 56F9C8: using guessed type int (__thiscall *THelpDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043E8C0) --------------------------------------------------------
THelpDialog *__thiscall THelpDialog::`vector deleting destructor'(THelpDialog *this, unsigned int __flags)
{
  THelpDialog *v2; // esi@1

  v2 = this;
  THelpDialog::~THelpDialog(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0043E8E0) --------------------------------------------------------
void __thiscall THelpDialog::THelpDialog(THelpDialog *this, TEasy_Panel *parentPanel, char *in_parent_panel, char *in_help_string, int in_help_page_id, int x, int y)
{
  THelpDialog *v7; // esi@1

  v7 = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)&this->vfptr, aHelpDialog);
  v7->vfptr = (TPanelVtbl *)&THelpDialog::`vftable';
  THelpDialog::setup_help(v7, parentPanel, in_parent_panel, in_help_string, in_help_page_id, x, y);
}
// 56F9C8: using guessed type int (__thiscall *THelpDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043E950) --------------------------------------------------------
void __thiscall THelpDialog::~THelpDialog(THelpDialog *this)
{
  THelpDialog *v1; // esi@1
  TButtonPanel *v2; // ecx@1
  TButtonPanel *v3; // ecx@3
  TTextPanel *v4; // ecx@5
  TTextPanel *v5; // ecx@7

  v1 = this;
  this->vfptr = (TPanelVtbl *)&THelpDialog::`vftable';
  v2 = this->ok_button;
  if ( v2 )
    (**(void (__stdcall ***)(_DWORD))v2)(1);
  v3 = v1->encyclopedia_button;
  if ( v3 )
    (**(void (__stdcall ***)(_DWORD))v3)(1);
  v4 = v1->list;
  if ( v4 )
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
  v5 = v1->title;
  if ( v5 )
    ((void (__stdcall *)(_DWORD))v5->vfptr->__vecDelDtor)(1);
  TDialogPanel::~TDialogPanel((TDialogPanel *)&v1->vfptr);
}
// 56F9C8: using guessed type int (__thiscall *THelpDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043E9E0) --------------------------------------------------------
void __thiscall THelpDialog::setup_help(THelpDialog *this, TEasy_Panel *parentPanel, char *in_parent_panel, char *help_string, int in_help_page_id, int mouse_x, int mouse_y)
{
  THelpDialog *v7; // ebp@1
  char *v8; // ebx@1
  RGE_Font *v9; // eax@1
  TEasy_Panel *v10; // edi@1
  TPanelVtbl *v11; // esi@1
  int v12; // STAC_4@1
  char *v13; // STA8_4@1
  TDrawArea *v14; // eax@1
  int v15; // esi@2
  int v16; // ebx@2
  int v17; // ebx@3
  int v18; // ecx@10
  int v19; // ebx@11
  TPanelVtbl *v20; // edi@17
  char *v21; // eax@19
  TButtonPanel *v22; // eax@25
  TPanel *v23; // eax@25
  signed int v24; // ecx@25
  signed int v25; // [sp+98h] [bp-38h]@23
  int v26; // [sp+9Ch] [bp-34h]@23
  RGE_Font *rge_text_font; // [sp+C4h] [bp-Ch]@1
  TPanel *tabList[2]; // [sp+C8h] [bp-8h]@25
  signed int parentPanela; // [sp+D4h] [bp+4h]@2
  int panel_height; // [sp+D8h] [bp+8h]@7

  v7 = this;
  v8 = (char *)&this->list;
  this->ok_button = 0;
  this->encyclopedia_button = 0;
  this->title = 0;
  this->list = 0;
  strcpy(this->parent_panel, in_parent_panel);
  v7->help_page_id = in_help_page_id;
  v9 = RGE_Base_Game::get_font(rge_base_game, 11);
  v10 = parentPanel;
  v11 = v7->vfptr;
  rge_text_font = v9;
  v12 = TEasy_Panel::get_popup_info_id(parentPanel);
  v13 = TEasy_Panel::get_popup_info_file(parentPanel);
  v14 = TPanel::renderArea((TPanel *)&parentPanel->vfptr);
  if ( ((int (__thiscall *)(THelpDialog *, TDrawArea *, TEasy_Panel *, signed int, signed int, char *, int, signed int))v11[1].handle_idle)(
         v7,
         v14,
         parentPanel,
         340,
         400,
         v13,
         v12,
         1) )
  {
    ((void (__thiscall *)(THelpDialog *, THelpDialog *, char *, char *, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, signed int))v11[1].set_redraw)(
      v7,
      v7,
      v8,
      help_string,
      10,
      10,
      330,
      390,
      11,
      0,
      0,
      1);
    v15 = *(_WORD *)(*(_DWORD *)v8 + 254) + 2;
    parentPanela = rge_text_font->font_hgt * v15 + 55;
    v16 = TPanel::width((TPanel *)&v10->vfptr);
    if ( TPanel::xPosition((TPanel *)&v10->vfptr) + v16 < mouse_x + 355 )
    {
      if ( TPanel::xPosition((TPanel *)&v10->vfptr) + 10 > mouse_x - 345 )
        v17 = TPanel::width((TPanel *)&v10->vfptr) / 2 - 170;
      else
        v17 = abs(mouse_x - 345 - TPanel::xPosition((TPanel *)&v10->vfptr));
    }
    else
    {
      v17 = abs(-5 - mouse_x + TPanel::xPosition((TPanel *)&v10->vfptr));
    }
    panel_height = v17;
    if ( v17 < 0 )
    {
      v17 = 0;
      panel_height = 0;
    }
    if ( TPanel::yPosition((TPanel *)&v10->vfptr) > mouse_y - parentPanela - 10 )
    {
      v19 = TPanel::height((TPanel *)&v10->vfptr);
      if ( parentPanela + mouse_y + 10 > TPanel::yPosition((TPanel *)&v10->vfptr) + v19 )
        v18 = TPanel::height((TPanel *)&v10->vfptr) / 2 - parentPanela / 2;
      else
        v18 = abs(mouse_y - TPanel::yPosition((TPanel *)&v10->vfptr) + 10);
      v17 = panel_height;
    }
    else
    {
      v18 = abs(mouse_y - parentPanela - TPanel::yPosition((TPanel *)&v10->vfptr) - 10);
    }
    if ( v18 < 0 )
      v18 = 0;
    v20 = v7->vfptr;
    v7->vfptr->set_fixed_position((TPanel *)v7, v17, v18, 340, parentPanela);
    (*(void (__thiscall **)(THelpDialog *, int, int))&v20[1].gap4[0])(v7, v7->max_wid, v7->max_hgt);
    ((void (__stdcall *)(signed int, signed int, signed int, int))v7->list->vfptr->set_fixed_position)(
      10,
      10,
      330,
      rge_text_font->font_hgt * v15);
    if ( RGE_Base_Game::singlePlayerGame(rge_base_game) )
    {
      if ( in_help_page_id >= 0 )
      {
        v21 = TPanel::get_string(in_help_page_id);
        if ( v21 )
        {
          if ( *v21 )
            (*(void (__thiscall **)(THelpDialog *, THelpDialog *, int, signed int, _DWORD, signed int, int, signed int, signed int, signed int, _DWORD, _DWORD))&v20[1].gap4[4])(
              v7,
              v7,
              (int)&v7->encyclopedia_button,
              9277,
              0,
              25,
              rge_text_font->font_hgt * v15 + 20,
              120,
              25,
              11,
              0,
              0);
        }
      }
    }
    if ( v7->encyclopedia_button )
    {
      v26 = rge_text_font->font_hgt * v15 + 20;
      v25 = 195;
    }
    else
    {
      v26 = rge_text_font->font_hgt * v15 + 20;
      v25 = 110;
    }
    (*(void (__thiscall **)(THelpDialog *, THelpDialog *, int, signed int, _DWORD, signed int, int, signed int, signed int, signed int, _DWORD, _DWORD))&v20[1].gap4[4])(
      v7,
      v7,
      (int)&v7->ok_button,
      4001,
      0,
      v25,
      v26,
      120,
      25,
      11,
      0,
      0);
    v22 = v7->ok_button;
    *((_DWORD *)v22 + 166) = 27;
    *((_DWORD *)v22 + 167) = 0;
    TPanel::set_curr_child((TPanel *)&v7->vfptr, (TPanel *)v7->ok_button);
    v23 = (TPanel *)v7->encyclopedia_button;
    tabList[0] = (TPanel *)v7->ok_button;
    v24 = 1;
    if ( v23 )
    {
      tabList[1] = v23;
      v24 = 2;
    }
    v20->set_tab_order((TPanel *)v7, (TPanel *)tabList, (TPanel *)v24);
  }
}

//----- (0043ED40) --------------------------------------------------------
int __thiscall THelpDialog::action(THelpDialog *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  int v5; // ebx@1
  int result; // eax@3
  void *v7; // edi@5
  char *v8; // eax@5

  v5 = this->help_page_id;
  if ( actionIn != 1 )
    goto LABEL_9;
  if ( fromPanel == (TPanel *)this->ok_button )
  {
    TPanelSystem::setCurrentPanel(&panel_system, this->parent_panel, 0);
    TPanelSystem::destroyPanel(&panel_system, aHelpDialog);
    return 1;
  }
  if ( fromPanel != (TPanel *)this->encyclopedia_button )
  {
LABEL_9:
    result = TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, actionIn, a1, a2);
  }
  else
  {
    TPanelSystem::setCurrentPanel(&panel_system, this->parent_panel, 0);
    TPanelSystem::destroyPanel(&panel_system, aHelpDialog);
    v7 = rge_base_game->prog_window;
    v8 = TPanel::get_string(v5);
    WinHelpA(v7, szHelp, 0x101u, (ULONG_PTR)v8);
    result = 1;
  }
  return result;
}

//----- (0043EE10) --------------------------------------------------------
int __thiscall THelpDialog::handle_mouse_down(THelpDialog *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  THelpDialog *v6; // esi@1
  TPanelVtbl *v7; // edi@1
  int result; // eax@2

  v6 = this;
  v7 = this->vfptr;
  if ( ((int (__stdcall *)(int, int))this->vfptr->is_inside)(x, y) )
  {
    result = TEasy_Panel::handle_mouse_down((TEasy_Panel *)&v6->vfptr, mouse_button_in, x, y, ctrl_key, shift_key);
  }
  else
  {
    v7->action((TPanel *)v6, (TPanel *)v6->ok_button, 1, 0, 0);
    result = 1;
  }
  return result;
}
