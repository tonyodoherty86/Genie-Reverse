
//----- (0043AD70) --------------------------------------------------------
void __userpurge TribeAboutDialog::TribeAboutDialog(TribeAboutDialog *this@<ecx>, int a2@<eax>, TScreenPanel *parentPanel)
{
  void *v3; // esp@1
  TribeAboutDialog *v4; // ebp@1
  int v5; // ST24_4@1
  char *v6; // ST20_4@1
  TDrawArea *v7; // eax@1
  TTextPanel *v8; // ebx@3
  TPicturePanel *v9; // eax@5
  TPicturePanel *v10; // eax@6
  int v11; // esi@9
  int v12; // eax@9
  TTextPanel *v13; // esi@11
  char *v14; // eax@13
  TButtonPanel *v15; // eax@16
  int v16; // edx@16
  TPanel *panel_list; // [sp+1Ch] [bp-122Ch]@16
  int v18; // [sp+20h] [bp-1228h]@16
  tagRECT rect; // [sp+24h] [bp-1224h]@4
  TPicturePanel *v20; // [sp+34h] [bp-1214h]@5
  TribeAboutDialog *v21; // [sp+38h] [bp-1210h]@1
  char str; // [sp+3Ch] [bp-120Ch]@2
  char Dest; // [sp+23Ch] [bp-100Ch]@15
  int v24; // [sp+123Ch] [bp-Ch]@1
  int (*v25)(); // [sp+1240h] [bp-8h]@1
  int v26; // [sp+1244h] [bp-4h]@1

  v25 = _L33221;
  v24 = a2;
  v3 = alloca(4640);
  v4 = this;
  v21 = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)&this->vfptr, panel_name_in);
  v26 = 0;
  v4->vfptr = (TPanelVtbl *)&TribeAboutDialog::`vftable';
  v4->title_text = 0;
  v4->version_text = 0;
  v4->ms_copy_text1 = 0;
  v4->ms_copy_text2 = 0;
  v4->ens_copy_text = 0;
  v4->genie_copy_text = 0;
  v4->pid_label_text = 0;
  v4->pid_text = 0;
  v4->warning_text = 0;
  v4->credits_button = 0;
  v4->close_button = 0;
  v4->circle_p_pic = 0;
  v4->background = 0;
  v5 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)&parentPanel->vfptr);
  v6 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)&parentPanel->vfptr);
  v7 = TPanel::renderArea((TPanel *)&parentPanel->vfptr);
  if ( TDialogPanel::setup((TDialogPanel *)&v4->vfptr, v7, (TPanel *)&parentPanel->vfptr, 520, 412, v6, v5, 1) )
  {
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->background,
      message_in,
      10,
      10,
      500,
      350,
      4,
      0,
      0,
      0);
    ((void (__thiscall *)(TTextPanel *, signed int, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v4->background->vfptr[1].set_rect)(
      v4->background,
      3,
      v4->bevel_color1,
      v4->bevel_color2,
      v4->bevel_color3,
      v4->bevel_color4,
      v4->bevel_color5,
      v4->bevel_color6);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->title_text,
      9241,
      20,
      20,
      480,
      20,
      4,
      0,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->version_text,
      9242,
      20,
      40,
      480,
      20,
      11,
      0,
      0,
      0);
    TPanel::get_string(9252, &str, 512);
    if ( str )
    {
      strcpy(&str, TPanel::get_string(9243));
      strcat(&str, TPanel::get_string(9252));
      strcat(&str, text_in);
      strcat(&str, TPanel::get_string(9244));
      TEasy_Panel::create_text(
        (TEasy_Panel *)&v4->vfptr,
        (TPanel *)&v4->vfptr,
        &v4->ms_copy_text1,
        &str,
        20,
        65,
        480,
        20,
        10,
        0,
        0,
        0);
    }
    else
    {
      TEasy_Panel::create_text(
        (TEasy_Panel *)&v4->vfptr,
        (TPanel *)&v4->vfptr,
        &v4->ms_copy_text1,
        9243,
        20,
        65,
        480,
        20,
        10,
        0,
        0,
        0);
      v8 = v4->ms_copy_text1;
      if ( v8 && TTextPanel::get_text_rect(v8, &rect) )
      {
        v9 = (TPicturePanel *)operator new(0x11Cu);
        v20 = v9;
        LOBYTE(v26) = 1;
        if ( v9 )
          TPicturePanel::TPicturePanel(v9);
        else
          v10 = 0;
        LOBYTE(v26) = 0;
        v4->circle_p_pic = v10;
        if ( v10 )
        {
          TPicturePanel::setup(
            v10,
            v4->render_area,
            (TPanel *)&v4->vfptr,
            rect.right - v4->pnl_x + 3,
            66,
            15,
            14,
            pic_name_in,
            50400,
            0,
            1);
          v11 = TPanel::xPosition((TPanel *)&v4->circle_p_pic->vfptr) - v4->pnl_x;
          v12 = TPanel::width((TPanel *)&v4->circle_p_pic->vfptr);
          TEasy_Panel::create_text(
            (TEasy_Panel *)&v4->vfptr,
            (TPanel *)&v4->vfptr,
            &v4->ms_copy_text2,
            9244,
            v12 + v11,
            65,
            480,
            20,
            10,
            0,
            0,
            0);
        }
      }
    }
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->ens_copy_text,
      9245,
      20,
      85,
      480,
      20,
      10,
      0,
      0,
      0);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->genie_copy_text,
      9251,
      20,
      105,
      480,
      40,
      10,
      0,
      0,
      1);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->pid_label_text,
      9246,
      20,
      150,
      95,
      20,
      10,
      0,
      0,
      0);
    v13 = v4->pid_label_text;
    if ( v13 && TTextPanel::get_text_rect(v13, &rect) )
    {
      v14 = TRegistry::RegGetAscii(Regs, 0, aPid);
      if ( !v14 )
        v14 = a00000000000000;
      sprintf(&Dest, aS_2, v14);
      TEasy_Panel::create_text(
        (TEasy_Panel *)&v4->vfptr,
        (TPanel *)&v4->vfptr,
        &v4->pid_text,
        &Dest,
        rect.right - v4->pnl_x + 4,
        150,
        200,
        20,
        11,
        0,
        0,
        0);
    }
    TPanel::get_string(9247, &Dest, 4096);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->warning_text,
      &Dest,
      20,
      175,
      480,
      220,
      10,
      0,
      0,
      1);
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->credits_button,
      9248,
      0,
      70,
      370,
      170,
      30,
      0,
      0,
      0);
    TEasy_Panel::create_button(
      (TEasy_Panel *)&v4->vfptr,
      (TPanel *)&v4->vfptr,
      &v4->close_button,
      9249,
      0,
      280,
      370,
      170,
      30,
      0,
      0,
      0);
    v15 = v4->close_button;
    *((_DWORD *)v15 + 166) = 27;
    *((_DWORD *)v15 + 167) = 0;
    v16 = (int)v4->close_button;
    panel_list = (TPanel *)v4->credits_button;
    v18 = v16;
    TPanel::set_tab_order(&panel_list, 2);
    TPanel::set_curr_child((TPanel *)&v4->vfptr, (TPanel *)v4->credits_button);
  }
}
// 55CF89: using guessed type int _L33221();
// 56F610: using guessed type int (__thiscall *TribeAboutDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043B2E0) --------------------------------------------------------
TribeAboutDialog *__thiscall TribeAboutDialog::`vector deleting destructor'(TribeAboutDialog *this, unsigned int __flags)
{
  TribeAboutDialog *v2; // esi@1

  v2 = this;
  TribeAboutDialog::~TribeAboutDialog(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0043B300) --------------------------------------------------------
void __thiscall TribeAboutDialog::~TribeAboutDialog(TribeAboutDialog *this)
{
  TribeAboutDialog *v1; // esi@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TribeAboutDialog::`vftable';
  TPanel::delete_panel((TPanel **)&this->title_text);
  TPanel::delete_panel((TPanel **)&v1->version_text);
  TPanel::delete_panel((TPanel **)&v1->ms_copy_text1);
  TPanel::delete_panel((TPanel **)&v1->ms_copy_text2);
  TPanel::delete_panel((TPanel **)&v1->ens_copy_text);
  TPanel::delete_panel((TPanel **)&v1->genie_copy_text);
  TPanel::delete_panel((TPanel **)&v1->pid_label_text);
  TPanel::delete_panel((TPanel **)&v1->pid_text);
  TPanel::delete_panel((TPanel **)&v1->warning_text);
  TPanel::delete_panel((TPanel **)&v1->credits_button);
  TPanel::delete_panel((TPanel **)&v1->close_button);
  TPanel::delete_panel((TPanel **)&v1->circle_p_pic);
  TPanel::delete_panel((TPanel **)&v1->background);
  TDialogPanel::~TDialogPanel((TDialogPanel *)&v1->vfptr);
}
// 56F610: using guessed type int (__thiscall *TribeAboutDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043B400) --------------------------------------------------------
int __thiscall TribeAboutDialog::action(TribeAboutDialog *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TribeAboutDialog *v5; // esi@1
  TRIBE_Credits_Screen *v7; // eax@9

  v5 = this;
  if ( actionIn != 1 )
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, actionIn, a1, a2);
  if ( fromPanel != (TPanel *)this->close_button )
  {
    if ( fromPanel == (TPanel *)this->credits_button )
    {
      v7 = (TRIBE_Credits_Screen *)operator new(0x8B8u);
      if ( v7 )
        TRIBE_Credits_Screen::TRIBE_Credits_Screen(v7);
      TPanelSystem::setCurrentPanel(&panel_system, aCreditsScreen, 0);
      goto LABEL_12;
    }
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, actionIn, a1, a2);
  }
  if ( !TPanelSystem::panel(&panel_system, aGameScreen) )
  {
LABEL_12:
    TPanelSystem::destroyPanel(&panel_system, panel_name_in);
    return 1;
  }
  if ( RGE_Base_Game::singlePlayerGame(rge_base_game) == 1 && !rge_base_game->save_paused )
    RGE_Base_Game::set_paused(rge_base_game, 0, 0);
  TPanelSystem::setCurrentPanel(&panel_system, aGameScreen, 0);
  (*(void (__thiscall **)(TribeAboutDialog *, _DWORD))&v5->vfptr->gap10[4])(v5, 0);
  TPanelSystem::destroyPanel(&panel_system, panel_name_in);
  return 1;
}
