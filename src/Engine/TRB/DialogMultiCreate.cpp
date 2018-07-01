
//----- (004920C0) --------------------------------------------------------
void __thiscall TribeMPCreateDialog::TribeMPCreateDialog(TribeMPCreateDialog *this, TPanel *parentPanel)
{
  TribeMPCreateDialog *v2; // ebp@1
  TPanel **v3; // ebx@1
  int v4; // ST28_4@1
  char *v5; // ST24_4@1
  TDrawArea *v6; // eax@1
  TPanel **v7; // esi@9
  TPanel *v8; // eax@10
  TPanel *v9; // ecx@10
  TPanel *v10; // eax@10
  TPanel *tab_list[3]; // [sp+10h] [bp-11Ch]@10
  TribeMPCreateDialog *v12; // [sp+1Ch] [bp-110h]@1
  char str[256]; // [sp+20h] [bp-10Ch]@5
  int v14; // [sp+128h] [bp-4h]@1

  v2 = this;
  v12 = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)&this->vfptr, aCreateDialog);
  v3 = (TPanel **)&v2->inputGamename;
  v14 = 0;
  v2->vfptr = (TPanelVtbl *)&TribeMPCreateDialog::`vftable';
  v2->title = 0;
  v2->input_title = 0;
  v2->inputGamename = 0;
  v2->okButton = 0;
  v2->cancelButton = 0;
  v4 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)parentPanel);
  v5 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)parentPanel);
  v6 = TPanel::renderArea(parentPanel);
  if ( TDialogPanel::setup((TDialogPanel *)&v2->vfptr, v6, parentPanel, 500, 230, v5, v4, 1)
    && TEasy_Panel::create_text(
         (TEasy_Panel *)&v2->vfptr,
         (TPanel *)&v2->vfptr,
         &v2->title,
         9638,
         20,
         20,
         460,
         30,
         1,
         1,
         1,
         0)
    && TEasy_Panel::create_text(
         (TEasy_Panel *)&v2->vfptr,
         (TPanel *)&v2->vfptr,
         &v2->input_title,
         9642,
         40,
         85,
         420,
         20,
         4,
         0,
         1,
         0) )
  {
    if ( TRegistry::RegGetAscii(Regs, 1, aDefaultAgeOf_0) )
      strcpy(str, TRegistry::RegGetAscii(Regs, 1, aDefaultAgeOf_0));
    else
      str[0] = 0;
    if ( TEasy_Panel::create_edit(
           (TEasy_Panel *)&v2->vfptr,
           (TPanel *)&v2->vfptr,
           &v2->inputGamename,
           str,
           40,
           0,
           40,
           110,
           420,
           23,
           11,
           1,
           0)
      && TEasy_Panel::create_button(
           (TEasy_Panel *)&v2->vfptr,
           (TPanel *)&v2->vfptr,
           &v2->okButton,
           4001,
           0,
           60,
           180,
           180,
           30,
           0,
           0,
           0) )
    {
      v7 = (TPanel **)&v2->cancelButton;
      if ( TEasy_Panel::create_button(
             (TEasy_Panel *)&v2->vfptr,
             (TPanel *)&v2->vfptr,
             &v2->cancelButton,
             4002,
             0,
             260,
             180,
             180,
             30,
             0,
             0,
             0) )
      {
        v8 = *v7;
        v8[2].max_wid = 27;
        v8[2].min_hgt = 0;
        v9 = *v7;
        v10 = (TPanel *)v2->okButton;
        tab_list[0] = *v3;
        tab_list[2] = v9;
        tab_list[1] = v10;
        TPanel::set_tab_order(tab_list, 3);
        TPanel::set_curr_child((TPanel *)&v2->vfptr, *v3);
      }
    }
  }
}
// 572620: using guessed type int (__thiscall *TribeMPCreateDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (00492310) --------------------------------------------------------
TribeMPCreateDialog *__thiscall TribeMPCreateDialog::`vector deleting destructor'(TribeMPCreateDialog *this, unsigned int __flags)
{
  TribeMPCreateDialog *v2; // esi@1

  v2 = this;
  TribeMPCreateDialog::~TribeMPCreateDialog(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (00492330) --------------------------------------------------------
void __thiscall TribeMPCreateDialog::~TribeMPCreateDialog(TribeMPCreateDialog *this)
{
  TribeMPCreateDialog *v1; // esi@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeMPCreateDialog::`vftable';
  TPanel::delete_panel((TPanel **)&this->title);
  TPanel::delete_panel((TPanel **)&v1->input_title);
  TPanel::delete_panel((TPanel **)&v1->inputGamename);
  TPanel::delete_panel((TPanel **)&v1->okButton);
  TPanel::delete_panel((TPanel **)&v1->cancelButton);
  TDialogPanel::~TDialogPanel((TDialogPanel *)&v1->vfptr);
}
// 572620: using guessed type int (__thiscall *TribeMPCreateDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (004923C0) --------------------------------------------------------
int __thiscall TribeMPCreateDialog::action(TribeMPCreateDialog *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeMPCreateDialog *v5; // ebx@1
  TEditPanel *v6; // edx@4
  int result; // eax@7
  unsigned int v8; // ST0C_4@8
  char *v9; // eax@8
  char *v10; // eax@8
  TDrawSystem **v11; // ebp@8
  TDrawSystem *v12; // ebp@11
  int v13; // esi@14
  HWND v14; // eax@14
  TribeMPSetupScreen *v15; // eax@17
  TEasy_Panel *v16; // ebx@20
  unsigned int v17; // [sp+10h] [bp-1Ch]@8
  int v18; // [sp+14h] [bp-18h]@8
  int v19; // [sp+18h] [bp-14h]@8
  int v20; // [sp+1Ch] [bp-10h]@8
  int v21; // [sp+28h] [bp-4h]@17

  v5 = this;
  if ( !fromPanel )
    return TPanel::action((TPanel *)&this->vfptr, fromPanel, actionIn, a1, a2);
  if ( fromPanel != (TPanel *)this->okButton || actionIn != 1 )
  {
    v6 = this->inputGamename;
    if ( (TEditPanel *)fromPanel != v6 || actionIn )
    {
      if ( fromPanel == (TPanel *)this->cancelButton && actionIn == 1 || (TEditPanel *)fromPanel == v6 && actionIn == 1 )
      {
        TPanelSystem::setCurrentPanel(&panel_system, aJoinScreen, 0);
        TPanelSystem::destroyPanel(&panel_system, aCreateDialog);
        return 1;
      }
      return TPanel::action((TPanel *)&this->vfptr, fromPanel, actionIn, a1, a2);
    }
  }
  if ( TEditPanel::is_blank(this->inputGamename) )
  {
    TPanel::set_curr_child((TPanel *)&v5->vfptr, (TPanel *)&v5->inputGamename->vfptr);
    result = 1;
  }
  else
  {
    RGE_Base_Game::disable_input(rge_base_game);
    v8 = strlen(TEditPanel::currentLine(v5->inputGamename)) + 1;
    v9 = TEditPanel::currentLine(v5->inputGamename);
    TRegistry::RegSetAscii(Regs, 1, aDefaultAgeOf_0, v9, v8);
    v10 = TEditPanel::currentLine(v5->inputGamename);
    TCommunications_Handler::SetGameTitle(comm, v10);
    v11 = &v5->render_area->DrawSystem;
    TDebuggingLog::Log(L, aCallingCreatem);
    TPanelSystem::setCurrentPanel(&panel_system, aJoinScreen, 0);
    RGE_Base_Game::draw_window(rge_base_game);
    v17 = comm->ServiceGUID.x;
    v18 = *(_DWORD *)&comm->ServiceGUID.s1;
    v19 = *(_DWORD *)&comm->ServiceGUID.c[0];
    v20 = *(_DWORD *)&comm->ServiceGUID.c[4];
    if ( !memcmp(&v17, &DPSPGUID_TCPIP, 0x10u) )
      TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game, 1219, info_file_name_in, 50053);
    else
      TRIBE_Game::show_status_message((TRIBE_Game *)rge_base_game, 1218, info_file_name_in, 50053);
    RGE_Base_Game::draw_window(rge_base_game);
    WinExec(CmdLine, 0);
    v12 = *v11;
    if ( v12->DrawType == 2 && v12->ScreenMode == 2 )
      v12->DirDraw->vfptr[3].AddRef((IUnknown *)v12->DirDraw);
    memset(&comm->PlayerStopTurn[1], 0, 0x24u);
    v13 = TCommunications_Handler::CreateMultiplayerGame(comm);
    TDebuggingLog::Log(L, aReturnedFromCr);
    v14 = FindWindowA(WindowName, WindowName);
    if ( v14 )
      SendMessageA(v14, 0x10u, 0, 0);
    if ( v13 )
    {
      v15 = (TribeMPSetupScreen *)operator new(0x890u);
      v21 = 0;
      if ( v15 )
        TribeMPSetupScreen::TribeMPSetupScreen(v15);
      v21 = -1;
      TPanelSystem::setCurrentPanel(&panel_system, aMpSetupScreen, 0);
      TPanelSystem::destroyPanel(&panel_system, aStatusScreen);
      TPanelSystem::destroyPanel(&panel_system, aCreateDialog);
      TPanelSystem::destroyPanel(&panel_system, aJoinScreen);
      result = 1;
    }
    else
    {
      v16 = (TEasy_Panel *)v5->parent_panel;
      TPanelSystem::destroyPanel(&panel_system, aCreateDialog);
      TPanelSystem::setCurrentPanel(&panel_system, aJoinScreen, 0);
      TPanelSystem::destroyPanel(&panel_system, aStatusScreen);
      TEasy_Panel::popupOKDialog(v16, 9645, 0, 450, 100);
      result = 1;
    }
  }
  return result;
}
