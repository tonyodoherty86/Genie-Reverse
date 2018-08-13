
//----- (004A63D0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Name::TRIBE_Screen_Name(TRIBE_Screen_Name *this)
{
  TRIBE_Screen_Name *v1; // esi@1
  TPanel **v2; // edi@10
  TPanel *v3; // edi@11

  v1 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aNameSelectionS);
  v1->vfptr = (TPanelVtbl *)&TRIBE_Screen_Name::`vftable';
  TRIBE_Screen_Name::init_vars(v1);
  if ( TEasy_Panel::setup((TEasy_Panel *)&v1->vfptr, rge_base_game->draw_area, 0, aScr2, 50052, 1, 0, 0, 0, 0, 1) )
  {
    TEasy_Panel::setup_shadow_area((TEasy_Panel *)&v1->vfptr, 0);
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v1->vfptr, 640, 480);
    if ( TEasy_Panel::create_text(
           (TEasy_Panel *)&v1->vfptr,
           (TPanel *)&v1->vfptr,
           &v1->title,
           10750,
           20,
           20,
           600,
           30,
           1,
           1,
           0,
           0) )
    {
      if ( TEasy_Panel::create_text(
             (TEasy_Panel *)&v1->vfptr,
             (TPanel *)&v1->vfptr,
             &v1->name_text,
             10751,
             60,
             80,
             140,
             20,
             4,
             0,
             0,
             0) )
      {
        if ( TEasy_Panel::create_list(
               (TEasy_Panel *)&v1->vfptr,
               (TPanel *)&v1->vfptr,
               &v1->name_list,
               60,
               100,
               330,
               300,
               11) )
        {
          if ( TEasy_Panel::create_auto_scrollbar(
                 (TEasy_Panel *)&v1->vfptr,
                 &v1->name_scrollbar,
                 (TTextPanel *)&v1->name_list->vfptr,
                 20) )
          {
            TPanel::set_help_info((TPanel *)&v1->name_scrollbar->vfptr, 30300, -1);
            if ( TEasy_Panel::create_button(
                   (TEasy_Panel *)&v1->vfptr,
                   (TPanel *)&v1->vfptr,
                   &v1->new_button,
                   10752,
                   0,
                   400,
                   100,
                   180,
                   30,
                   0,
                   0,
                   0) )
            {
              TPanel::set_help_info((TPanel *)v1->new_button, 30301, -1);
              if ( TEasy_Panel::create_button(
                     (TEasy_Panel *)&v1->vfptr,
                     (TPanel *)&v1->vfptr,
                     &v1->remove_button,
                     10753,
                     0,
                     400,
                     140,
                     180,
                     30,
                     0,
                     0,
                     0) )
              {
                TPanel::set_help_info((TPanel *)v1->remove_button, 30302, -1);
                if ( TEasy_Panel::create_button(
                       (TEasy_Panel *)&v1->vfptr,
                       (TPanel *)&v1->vfptr,
                       &v1->ok_button,
                       4001,
                       0,
                       70,
                       440,
                       240,
                       30,
                       0,
                       0,
                       0) )
                {
                  TPanel::set_help_info((TPanel *)v1->ok_button, 30001, -1);
                  v2 = (TPanel **)&v1->cancel_button;
                  if ( TEasy_Panel::create_button(
                         (TEasy_Panel *)&v1->vfptr,
                         (TPanel *)&v1->vfptr,
                         &v1->cancel_button,
                         4002,
                         0,
                         330,
                         440,
                         240,
                         30,
                         0,
                         0,
                         0) )
                  {
                    TPanel::set_help_info(*v2, 30002, -1);
                    v3 = *v2;
                    v3[2].max_wid = 27;
                    v3[2].min_hgt = 0;
                    if ( TEasy_Panel::create_button(
                           (TEasy_Panel *)&v1->vfptr,
                           (TPanel *)&v1->vfptr,
                           &v1->close_button,
                           1002,
                           0,
                           0,
                           0,
                           0,
                           0,
                           -1,
                           -1,
                           0) )
                    {
                      (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))(*(_DWORD *)v1->close_button + 24))(
                        9,
                        4,
                        4,
                        4,
                        4,
                        17,
                        17,
                        17,
                        17,
                        0,
                        0,
                        0,
                        0);
                      TRIBE_Screen_Name::setup_tab_order(v1);
                      TRIBE_Screen_Name::get_player_names(v1);
                      v1->started_input = 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
    v1->error_code = 1;
  }
}
// 573640: using guessed type int (__thiscall *TRIBE_Screen_Name::`vftable')(void *Memory, unsigned int __flags);

//----- (004A66C0) --------------------------------------------------------
TRIBE_Screen_Name *__thiscall TRIBE_Screen_Name::`vector deleting destructor'(TRIBE_Screen_Name *this, unsigned int __flags)
{
  TRIBE_Screen_Name *v2; // esi@1

  v2 = this;
  TRIBE_Screen_Name::~TRIBE_Screen_Name(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004A66E0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Name::~TRIBE_Screen_Name(TRIBE_Screen_Name *this)
{
  TRIBE_Screen_Name *v1; // esi@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TRIBE_Screen_Name::`vftable';
  TPanelSystem::setCurrentPanel(&panel_system, aNewNameDialog, 0);
  TPanel::delete_panel((TPanel **)&v1->title);
  TPanel::delete_panel((TPanel **)&v1->name_text);
  TPanel::delete_panel((TPanel **)&v1->name_list);
  TPanel::delete_panel((TPanel **)&v1->name_scrollbar);
  TPanel::delete_panel((TPanel **)&v1->new_button);
  TPanel::delete_panel((TPanel **)&v1->remove_button);
  TPanel::delete_panel((TPanel **)&v1->ok_button);
  TPanel::delete_panel((TPanel **)&v1->cancel_button);
  TPanel::delete_panel((TPanel **)&v1->close_button);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 573640: using guessed type int (__thiscall *TRIBE_Screen_Name::`vftable')(void *Memory, unsigned int __flags);

//----- (004A67C0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Name::init_vars(TRIBE_Screen_Name *this)
{
  this->title = 0;
  this->name_text = 0;
  this->name_list = 0;
  this->name_scrollbar = 0;
  this->new_button = 0;
  this->remove_button = 0;
  this->ok_button = 0;
  this->cancel_button = 0;
  this->close_button = 0;
}

//----- (004A6800) --------------------------------------------------------
void __thiscall TRIBE_Screen_Name::get_player_names(TRIBE_Screen_Name *this)
{
  TRIBE_Screen_Name *v1; // ebx@1
  RGE_Game_Info *v2; // ecx@1
  int v3; // eax@1
  int v4; // edi@1
  int v5; // esi@2
  int v6; // eax@4
  int i; // esi@4
  char **players; // [sp+8h] [bp-8h]@1
  int curr_player; // [sp+Ch] [bp-4h]@1

  v1 = this;
  TTextPanel::empty_list((TTextPanel *)&this->name_list->vfptr);
  v2 = rge_base_game->player_game_info;
  players = 0;
  v3 = RGE_Game_Info::get_people_list(v2, &players, &curr_player);
  v4 = v3;
  if ( v3 )
  {
    v5 = 0;
    v1->name_list->sorted = 1;
    if ( v3 > 0 )
    {
      do
      {
        TTextPanel::append_line((TTextPanel *)&v1->name_list->vfptr, players[v5], v5);
        ++v5;
      }
      while ( v5 < v4 );
    }
    v6 = TTextPanel::get_line((TTextPanel *)&v1->name_list->vfptr, curr_player);
    TTextPanel::set_line((TTextPanel *)&v1->name_list->vfptr, v6);
    for ( i = 0; i < v4; ++i )
      free(players[i]);
    free(players);
  }
}

//----- (004A68C0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Name::setup_tab_order(TRIBE_Screen_Name *this)
{
  TRIBE_Screen_Name *v1; // esi@1
  int v2; // edi@1
  TPanel *v3; // ecx@3
  signed int v4; // eax@3
  TPanel *v5; // edx@4
  TPanelVtbl *v6; // edx@5
  TPanel *tab_list[5]; // [sp+8h] [bp-14h]@3

  v1 = this;
  v2 = 0;
  if ( !TTextPanel::numberLines((TTextPanel *)&this->name_list->vfptr) )
    v2 = 1;
  TButtonPanel::set_disabled(v1->remove_button, v2);
  TButtonPanel::set_disabled(v1->ok_button, v2);
  v3 = (TPanel *)v1->new_button;
  tab_list[0] = (TPanel *)&v1->name_list->vfptr;
  tab_list[1] = v3;
  v4 = 2;
  if ( !v2 )
  {
    v5 = (TPanel *)v1->remove_button;
    tab_list[3] = (TPanel *)v1->ok_button;
    tab_list[2] = v5;
    v4 = 4;
  }
  v6 = v1->vfptr;
  tab_list[v4] = (TPanel *)v1->cancel_button;
  v6->set_tab_order((TPanel *)v1, (TPanel *)tab_list, (TPanel *)(v4 + 1));
  if ( TTextPanel::numberLines((TTextPanel *)&v1->name_list->vfptr) )
    TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)&v1->name_list->vfptr);
  else
    TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)v1->new_button);
}

//----- (004A6980) --------------------------------------------------------
int __thiscall TRIBE_Screen_Name::handle_idle(TRIBE_Screen_Name *this)
{
  TRIBE_Screen_Name *v1; // esi@1

  v1 = this;
  if ( !rge_base_game->input_enabled )
    RGE_Base_Game::enable_input(rge_base_game);
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}

//----- (004A69B0) --------------------------------------------------------
int __thiscall TRIBE_Screen_Name::action(TRIBE_Screen_Name *this, TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2)
{
  TRIBE_Screen_Name *v5; // edi@1
  TButtonPanel *v6; // eax@2
  int result; // eax@5
  RGE_Game_Info *v8; // esi@6
  int v9; // eax@6
  TRIBE_Screen_Campaign_Selection *v10; // eax@6
  TribeSPMenuScreen *v11; // eax@11
  TListPanel *v12; // ecx@16
  TRIBE_Dialog_Name *v13; // eax@21
  char *v14; // ST0C_4@27
  char *v15; // eax@27
  int v16; // eax@36
  RGE_Game_Info *v17; // esi@37
  int v18; // eax@37
  char str[256]; // [sp+14h] [bp-10Ch]@27
  int v20; // [sp+11Ch] [bp-4h]@6

  v5 = this;
  if ( !from_panel )
    return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, from_panel, action_in, action_val1, action_val2);
  v6 = this->ok_button;
  if ( (TButtonPanel *)from_panel == v6 && action_in == 1 )
  {
    if ( TTextPanel::get_line((TTextPanel *)&this->name_list->vfptr) == -1 )
    {
      result = 1;
    }
    else
    {
      RGE_Base_Game::disable_input(rge_base_game);
      v8 = rge_base_game->player_game_info;
      v9 = TTextPanel::get_id((TTextPanel *)&v5->name_list->vfptr);
      RGE_Game_Info::set_current_person(v8, v9);
      v10 = (TRIBE_Screen_Campaign_Selection *)operator new(0x4CCu);
      v20 = 0;
      if ( v10 )
        TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection(v10);
      v20 = -1;
      TPanelSystem::setCurrentPanel(&panel_system, aCampaignSelect, 0);
      TPanelSystem::destroyPanel(&panel_system, aNameSelectionS);
      result = 1;
    }
    return result;
  }
  if ( from_panel == (TPanel *)this->cancel_button && action_in == 1 )
  {
    RGE_Base_Game::disable_input(rge_base_game);
    v11 = (TribeSPMenuScreen *)operator new(0x49Cu);
    v20 = 1;
    if ( v11 )
      TribeSPMenuScreen::TribeSPMenuScreen(v11);
    v20 = -1;
    TPanelSystem::setCurrentPanel(&panel_system, aSinglePlayerMe, 0);
    TPanelSystem::destroyPanel(&panel_system, aNameSelectionS);
    return 1;
  }
  if ( from_panel == (TPanel *)this->close_button )
  {
    RGE_Base_Game::close(rge_base_game);
    return 1;
  }
  v12 = this->name_list;
  if ( (TListPanel *)from_panel == v12 && action_in == 3 )
  {
    v5->vfptr->action((TPanel *)v5, (TPanel *)v6, 1, 0, 0);
    return 1;
  }
  if ( from_panel != (TPanel *)v5->new_button || action_in != 1 )
  {
    if ( from_panel == (TPanel *)v5->remove_button && action_in == 1 )
    {
      if ( TTextPanel::get_line((TTextPanel *)&v12->vfptr) != -1 )
      {
        v14 = TTextPanel::get_text((TTextPanel *)&v5->name_list->vfptr);
        v15 = TPanel::get_string(10754);
        sprintf(str, v15, v14);
        TEasy_Panel::popupYesNoDialog((TEasy_Panel *)&v5->vfptr, str, 0, 450, 100);
        return 1;
      }
      return 1;
    }
    if ( TPanel::panelName(from_panel) && !strcmp(TPanel::panelName(from_panel), aNewNameDialog) )
    {
      if ( action_in == 1 )
        TRIBE_Screen_Name::get_player_names(v5);
      TPanelSystem::setCurrentPanel(&panel_system, aNameSelectionS, 0);
      TPanelSystem::destroyPanel(&panel_system, aNewNameDialog);
LABEL_39:
      TRIBE_Screen_Name::setup_tab_order(v5);
      return 1;
    }
    if ( TPanel::panelName(from_panel) && !strcmp(TPanel::panelName(from_panel), aYesnodialog) )
    {
      if ( !action_in )
      {
        v16 = TTextPanel::get_line((TTextPanel *)&v5->name_list->vfptr);
        if ( v16 != -1 )
        {
          v17 = rge_base_game->player_game_info;
          v18 = TTextPanel::get_id((TTextPanel *)&v5->name_list->vfptr, v16);
          RGE_Game_Info::remove_player(v17, v18);
          TRIBE_Screen_Name::get_player_names(v5);
        }
      }
      TPanelSystem::destroyPanel(&panel_system, aYesnodialog);
      goto LABEL_39;
    }
    return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, from_panel, action_in, action_val1, action_val2);
  }
  v13 = (TRIBE_Dialog_Name *)operator new(0x4A4u);
  v20 = 2;
  if ( v13 )
    TRIBE_Dialog_Name::TRIBE_Dialog_Name(v13, (TScreenPanel *)&v5->vfptr);
  v20 = -1;
  TPanelSystem::setCurrentPanel(&panel_system, aNewNameDialog, 0);
  return 1;
}
