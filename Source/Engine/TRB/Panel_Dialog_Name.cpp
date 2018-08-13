
//----- (004A6D50) --------------------------------------------------------
void __thiscall TRIBE_Dialog_Name::TRIBE_Dialog_Name(TRIBE_Dialog_Name *this, TScreenPanel *parent_panel_in)
{
  TRIBE_Dialog_Name *v2; // esi@1
  TPanel **v3; // ebx@1
  int v4; // ST28_4@1
  char *v5; // ST24_4@1
  TDrawArea *v6; // eax@1
  TPanel **v7; // edi@6
  TPanel *v8; // eax@7
  TPanel *v9; // ecx@7
  TPanel *v10; // edx@7
  TPanel *tab_list[3]; // [sp+14h] [bp-18h]@7
  int v12; // [sp+28h] [bp-4h]@1

  v2 = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)&this->vfptr, aNewNameDialog);
  v3 = (TPanel **)&v2->name_input;
  v12 = 0;
  v2->vfptr = (TPanelVtbl *)&TRIBE_Dialog_Name::`vftable';
  v2->title = 0;
  v2->name_text = 0;
  v2->name_input = 0;
  v2->ok_button = 0;
  v2->cancel_button = 0;
  v4 = TEasy_Panel::get_popup_info_id((TEasy_Panel *)&parent_panel_in->vfptr);
  v5 = TEasy_Panel::get_popup_info_file((TEasy_Panel *)&parent_panel_in->vfptr);
  v6 = TPanel::renderArea((TPanel *)&parent_panel_in->vfptr);
  if ( TDialogPanel::setup((TDialogPanel *)&v2->vfptr, v6, (TPanel *)&parent_panel_in->vfptr, 500, 230, v5, v4, 1)
    && TEasy_Panel::create_text(
         (TEasy_Panel *)&v2->vfptr,
         (TPanel *)&v2->vfptr,
         &v2->title,
         10755,
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
         &v2->name_text,
         10756,
         40,
         85,
         420,
         20,
         4,
         0,
         1,
         0)
    && TEasy_Panel::create_edit(
         (TEasy_Panel *)&v2->vfptr,
         (TPanel *)&v2->vfptr,
         &v2->name_input,
         message_in,
         15,
         0,
         40,
         110,
         420,
         23,
         11,
         1,
         1)
    && TEasy_Panel::create_button(
         (TEasy_Panel *)&v2->vfptr,
         (TPanel *)&v2->vfptr,
         &v2->ok_button,
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
    v7 = (TPanel **)&v2->cancel_button;
    if ( TEasy_Panel::create_button(
           (TEasy_Panel *)&v2->vfptr,
           (TPanel *)&v2->vfptr,
           &v2->cancel_button,
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
      v9 = (TPanel *)v2->ok_button;
      v10 = *v7;
      tab_list[0] = *v3;
      tab_list[1] = v9;
      tab_list[2] = v10;
      TPanel::set_tab_order(tab_list, 3);
      TPanel::set_curr_child((TPanel *)&v2->vfptr, *v3);
    }
  }
}
// 573768: using guessed type int (__thiscall *TRIBE_Dialog_Name::`vftable')(void *Memory, unsigned int __flags);

//----- (004A6F40) --------------------------------------------------------
TRIBE_Dialog_Name *__thiscall TRIBE_Dialog_Name::`vector deleting destructor'(TRIBE_Dialog_Name *this, unsigned int __flags)
{
  TRIBE_Dialog_Name *v2; // esi@1

  v2 = this;
  TRIBE_Dialog_Name::~TRIBE_Dialog_Name(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004A6F60) --------------------------------------------------------
void __thiscall TRIBE_Dialog_Name::~TRIBE_Dialog_Name(TRIBE_Dialog_Name *this)
{
  TRIBE_Dialog_Name *v1; // esi@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TRIBE_Dialog_Name::`vftable';
  TPanel::delete_panel((TPanel **)&this->title);
  TPanel::delete_panel((TPanel **)&v1->name_text);
  TPanel::delete_panel((TPanel **)&v1->name_input);
  TPanel::delete_panel((TPanel **)&v1->ok_button);
  TPanel::delete_panel((TPanel **)&v1->cancel_button);
  TDialogPanel::~TDialogPanel((TDialogPanel *)&v1->vfptr);
}
// 573768: using guessed type int (__thiscall *TRIBE_Dialog_Name::`vftable')(void *Memory, unsigned int __flags);

//----- (004A6FF0) --------------------------------------------------------
int __thiscall TRIBE_Dialog_Name::action(TRIBE_Dialog_Name *this, TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2)
{
  TRIBE_Dialog_Name *v5; // esi@1
  TEditPanel *v6; // edx@4
  int result; // eax@7
  RGE_Game_Info *v8; // edi@8
  char *v9; // eax@8
  TRIBE_Screen_Campaign_Selection *v10; // eax@8
  TribeSPMenuScreen *v11; // eax@17
  char *v12; // [sp-8h] [bp-1Ch]@16

  v5 = this;
  if ( !from_panel )
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, from_panel, action_in, action_val1, action_val2);
  if ( from_panel == (TPanel *)this->ok_button && action_in == 1
    || (v6 = this->name_input, (TEditPanel *)from_panel == v6) && !action_in )
  {
    if ( *TEditPanel::get_text(this->name_input) )
    {
      v8 = rge_base_game->player_game_info;
      v9 = TEditPanel::get_text(v5->name_input);
      RGE_Game_Info::add_new_person(v8, v9);
      v10 = (TRIBE_Screen_Campaign_Selection *)operator new(0x4CCu);
      if ( v10 )
        TRIBE_Screen_Campaign_Selection::TRIBE_Screen_Campaign_Selection(v10);
      TPanelSystem::setCurrentPanel(&panel_system, aCampaignSelect, 0);
      TPanelSystem::destroyPanel(&panel_system, aNewNameDialog);
      TPanelSystem::destroyPanel(&panel_system, aNameSelectionS);
      result = 1;
    }
    else
    {
      TPanel::set_curr_child((TPanel *)&v5->vfptr, (TPanel *)&v5->name_input->vfptr);
      result = 1;
    }
    return result;
  }
  if ( (from_panel != (TPanel *)this->cancel_button || action_in != 1)
    && ((TEditPanel *)from_panel != v6 || action_in != 1) )
  {
    return TEasy_Panel::action((TEasy_Panel *)&this->vfptr, from_panel, action_in, action_val1, action_val2);
  }
  if ( TPanelSystem::panel(&panel_system, aNameSelectionS) )
  {
    v12 = aNameSelectionS;
  }
  else
  {
    v11 = (TribeSPMenuScreen *)operator new(0x49Cu);
    if ( v11 )
      TribeSPMenuScreen::TribeSPMenuScreen(v11);
    v12 = aSinglePlayerMe;
  }
  TPanelSystem::setCurrentPanel(&panel_system, v12, 0);
  TPanelSystem::destroyPanel(&panel_system, aNewNameDialog);
  return 1;
}

//----- (004A71D0) --------------------------------------------------------
int __thiscall TRIBE_Dialog_Name::wnd_proc(TRIBE_Dialog_Name *this, void *hwnd, unsigned int msg, unsigned int wParam, int lParam)
{
  return TPanel::wnd_proc((TPanel *)&this->vfptr, hwnd, msg, wParam, lParam);
}
