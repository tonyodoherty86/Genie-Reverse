
//----- (004B2EF0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed_Menu::TRIBE_Screen_Sed_Menu(TRIBE_Screen_Sed_Menu *this)
{
  TRIBE_Screen_Sed_Menu *v1; // esi@1
  TButtonPanel **v2; // ebp@1
  int v3; // ecx@1
  int v4; // edi@4
  TButtonPanel **v5; // ebx@4
  int v6; // edi@7
  TButtonPanel *v7; // eax@8

  v1 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aScenarioEditor);
  v2 = v1->button;
  v3 = (int)v1->button;
  v1->vfptr = (TPanelVtbl *)&TRIBE_Screen_Sed_Menu::`vftable';
  v1->title = 0;
  *(_DWORD *)v3 = 0;
  *(_DWORD *)(v3 + 4) = 0;
  *(_DWORD *)(v3 + 8) = 0;
  *(_DWORD *)(v3 + 12) = 0;
  v1->close_button = 0;
  if ( TScreenPanel::setup((TScreenPanel *)&v1->vfptr, rge_base_game->draw_area, info_file_name, 50054, 1) )
  {
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v1->vfptr, 640, 480);
    if ( TEasy_Panel::create_text(
           (TEasy_Panel *)&v1->vfptr,
           (TPanel *)&v1->vfptr,
           &v1->title,
           9261,
           20,
           20,
           600,
           30,
           1,
           1,
           0,
           0) )
    {
      v4 = 170;
      v5 = v1->button;
      while ( TEasy_Panel::create_button(
                (TEasy_Panel *)&v1->vfptr,
                (TPanel *)&v1->vfptr,
                v5,
                message_in,
                0,
                170,
                v4,
                300,
                40,
                0,
                0,
                0) )
      {
        v4 += 50;
        ++v5;
        if ( v4 >= 370 )
        {
          v6 = (int)&v1->close_button;
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
            (*(void (__stdcall **)(signed int))(**(_DWORD **)v6 + 20))(1);
            (*(void (__stdcall **)(signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, signed int, _DWORD, _DWORD, _DWORD, _DWORD))(**(_DWORD **)v6 + 24))(
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
            TButtonPanel::set_text(*v2, 0, 9262);
            TButtonPanel::set_text(v1->button[1], 0, 9263);
            TButtonPanel::set_text(v1->button[2], 0, 9265);
            TButtonPanel::set_text(v1->button[3], 0, 9264);
            v7 = v1->button[3];
            *((_DWORD *)v7 + 166) = 27;
            *((_DWORD *)v7 + 167) = 0;
            TPanel::set_tab_order((TPanel **)v1->button, 4);
            TPanel::set_curr_child((TPanel *)&v1->vfptr, (TPanel *)*v2);
          }
          return;
        }
      }
    }
  }
  else
  {
    v1->error_code = 1;
  }
}
// 573B00: using guessed type int (__thiscall *TRIBE_Screen_Sed_Menu::`vftable')(void *Memory, unsigned int __flags);

//----- (004B30F0) --------------------------------------------------------
TRIBE_Screen_Sed_Menu *__thiscall TRIBE_Screen_Sed_Menu::`scalar deleting destructor'(TRIBE_Screen_Sed_Menu *this, unsigned int __flags)
{
  TRIBE_Screen_Sed_Menu *v2; // esi@1

  v2 = this;
  TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004B3110) --------------------------------------------------------
void __thiscall TRIBE_Screen_Sed_Menu::~TRIBE_Screen_Sed_Menu(TRIBE_Screen_Sed_Menu *this)
{
  TRIBE_Screen_Sed_Menu *v1; // esi@1
  TPanel **v2; // edi@1
  signed int v3; // ebx@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TRIBE_Screen_Sed_Menu::`vftable';
  TPanel::delete_panel((TPanel **)&this->title);
  v2 = (TPanel **)v1->button;
  v3 = 4;
  do
  {
    TPanel::delete_panel(v2);
    ++v2;
    --v3;
  }
  while ( v3 );
  TPanel::delete_panel((TPanel **)&v1->close_button);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 573B00: using guessed type int (__thiscall *TRIBE_Screen_Sed_Menu::`vftable')(void *Memory, unsigned int __flags);

//----- (004B31A0) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed_Menu::handle_idle(TRIBE_Screen_Sed_Menu *this)
{
  TRIBE_Screen_Sed_Menu *v1; // esi@1

  v1 = this;
  if ( !rge_base_game->input_enabled )
    RGE_Base_Game::enable_input(rge_base_game);
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}

//----- (004B31D0) --------------------------------------------------------
int __thiscall TRIBE_Screen_Sed_Menu::action(TRIBE_Screen_Sed_Menu *this, TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2)
{
  TRIBE_Screen_Sed_Open *v6; // eax@6
  TRIBE_Campaign_Editor_Screen *v7; // eax@10
  TRIBE_Screen_Main_Menu *v8; // eax@14

  if ( !fromPanel || actionIn != 1 )
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, actionIn, a1, a2);
  if ( fromPanel == (TPanel *)this->button[0] )
  {
    TRIBE_Game::start_scenario_editor((TRIBE_Game *)rge_base_game, 0, 0);
    return 1;
  }
  if ( fromPanel == (TPanel *)this->button[1] )
  {
    v6 = (TRIBE_Screen_Sed_Open *)operator new(0x490u);
    if ( v6 )
      TRIBE_Screen_Sed_Open::TRIBE_Screen_Sed_Open(v6);
    TPanelSystem::setCurrentPanel(&panel_system, aScenarioEdit_2, 0);
    TPanelSystem::destroyPanel(&panel_system, aScenarioEditor);
    return 1;
  }
  if ( fromPanel == (TPanel *)this->button[2] )
  {
    v7 = (TRIBE_Campaign_Editor_Screen *)operator new(0x4C4u);
    if ( v7 )
      TRIBE_Campaign_Editor_Screen::TRIBE_Campaign_Editor_Screen(v7);
    TPanelSystem::setCurrentPanel(&panel_system, aCampaignEditor, 0);
    TPanelSystem::destroyPanel(&panel_system, aScenarioEditor);
    return 1;
  }
  if ( fromPanel != (TPanel *)this->button[3] )
  {
    if ( fromPanel == (TPanel *)this->close_button )
    {
      RGE_Base_Game::close(rge_base_game);
      return 1;
    }
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, fromPanel, actionIn, a1, a2);
  }
  RGE_Base_Game::disable_input(rge_base_game);
  v8 = (TRIBE_Screen_Main_Menu *)operator new(0x4B0u);
  if ( v8 )
    TRIBE_Screen_Main_Menu::TRIBE_Screen_Main_Menu(v8);
  TPanelSystem::setCurrentPanel(&panel_system, aMainMenu, 0);
  TPanelSystem::destroyPanel(&panel_system, aScenarioEditor);
  return 1;
}
