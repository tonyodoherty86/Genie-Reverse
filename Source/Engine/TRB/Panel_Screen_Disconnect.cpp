
//----- (004A61A0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Disconnect::TRIBE_Screen_Disconnect(TRIBE_Screen_Disconnect *this, int mode_in)
{
  TRIBE_Screen_Disconnect *v2; // esi@1

  v2 = this;
  TScreenPanel::TScreenPanel((TScreenPanel *)&this->vfptr, aMultiplayerDis);
  v2->vfptr = (TPanelVtbl *)&TRIBE_Screen_Disconnect::`vftable';
  v2->mode = mode_in;
  v2->message = 0;
  v2->cancel_button = 0;
  v2->close_button = 0;
  if ( TScreenPanel::setup((TScreenPanel *)&v2->vfptr, rge_base_game->draw_area, info_file_name_in, 50053, 0) )
  {
    TEasy_Panel::set_ideal_size((TEasy_Panel *)&v2->vfptr, 640, 480);
    TEasy_Panel::create_text(
      (TEasy_Panel *)&v2->vfptr,
      (TPanel *)&v2->vfptr,
      &v2->message,
      1216,
      40,
      40,
      560,
      400,
      4,
      1,
      1,
      1);
  }
  else
  {
    v2->error_code = 1;
  }
}
// 573518: using guessed type int (__thiscall *TRIBE_Screen_Disconnect::`vftable')(void *Memory, unsigned int __flags);

//----- (004A6270) --------------------------------------------------------
TRIBE_Screen_Disconnect *__thiscall TRIBE_Screen_Disconnect::`vector deleting destructor'(TRIBE_Screen_Disconnect *this, unsigned int __flags)
{
  TRIBE_Screen_Disconnect *v2; // esi@1

  v2 = this;
  TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconnect(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004A6290) --------------------------------------------------------
void __thiscall TRIBE_Screen_Disconnect::~TRIBE_Screen_Disconnect(TRIBE_Screen_Disconnect *this)
{
  TRIBE_Screen_Disconnect *v1; // esi@1

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TRIBE_Screen_Disconnect::`vftable';
  TPanel::delete_panel((TPanel **)&this->message);
  TScreenPanel::~TScreenPanel((TScreenPanel *)&v1->vfptr);
}
// 573518: using guessed type int (__thiscall *TRIBE_Screen_Disconnect::`vftable')(void *Memory, unsigned int __flags);

//----- (004A62F0) --------------------------------------------------------
void __thiscall TRIBE_Screen_Disconnect::set_text(TRIBE_Screen_Disconnect *this, char *message_in)
{
  (*(void (__stdcall **)(_DWORD))&this->message->vfptr[1].gap4[4])(message_in);
}

//----- (004A6310) --------------------------------------------------------
void __thiscall TRIBE_Screen_Disconnect::set_text(TRIBE_Screen_Disconnect *this, int message_in)
{
  (*(void (__stdcall **)(_DWORD))&this->message->vfptr[1].gap4[0])(message_in);
}

//----- (004A6330) --------------------------------------------------------
int __thiscall TRIBE_Screen_Disconnect::action(TRIBE_Screen_Disconnect *this, TPanel *from_panel, int action_in, unsigned int val1, unsigned int val2)
{
  int result; // eax@4

  if ( !from_panel )
    goto LABEL_11;
  if ( from_panel == (TPanel *)this->cancel_button && action_in == 1 )
  {
    TRIBE_Game::quit_game((TRIBE_Game *)rge_base_game);
    TPanelSystem::destroyPanel(&panel_system, aMultiplayerDis);
    TPanelSystem::destroyPanel(&panel_system, aStatusScreen);
    return 1;
  }
  if ( from_panel == (TPanel *)this->close_button && action_in == 1 )
  {
    RGE_Base_Game::close(rge_base_game);
    result = 1;
  }
  else
  {
LABEL_11:
    result = TEasy_Panel::action((TEasy_Panel *)&this->vfptr, from_panel, action_in, val1, val2);
  }
  return result;
}
