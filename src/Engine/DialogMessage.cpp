
//----- (0043FC70) --------------------------------------------------------
void __thiscall TMessageDialog::TMessageDialog(TMessageDialog *this, char *name)
{
  TMessageDialog *v2; // esi@1

  v2 = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)&this->vfptr, name);
  v2->dlg_type = 0;
  v2->text = 0;
  v2->vfptr = (TPanelVtbl *)&TMessageDialog::`vftable';
  v2->button[0] = 0;
  v2->button[1] = 0;
  v2->button[2] = 0;
}
// 56FD60: using guessed type int (__thiscall *TMessageDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043FCB0) --------------------------------------------------------
TMessageDialog *__thiscall TMessageDialog::`scalar deleting destructor'(TMessageDialog *this, unsigned int __flags)
{
  TMessageDialog *v2; // esi@1

  v2 = this;
  TMessageDialog::~TMessageDialog(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0043FCD0) --------------------------------------------------------
void __thiscall TMessageDialog::~TMessageDialog(TMessageDialog *this)
{
  TMessageDialog *v1; // ebx@1
  TTextPanel *v2; // ecx@1
  TButtonPanel **v3; // esi@3
  signed int v4; // edi@3

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TMessageDialog::`vftable';
  v2 = this->text;
  if ( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v3 = v1->button;
  v4 = 3;
  do
  {
    if ( *v3 )
      (**(void (__stdcall ***)(_DWORD))*v3)(1);
    ++v3;
    --v4;
  }
  while ( v4 );
  TDialogPanel::~TDialogPanel((TDialogPanel *)&v1->vfptr);
}
// 56FD60: using guessed type int (__thiscall *TMessageDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043FD50) --------------------------------------------------------
int __thiscall TMessageDialog::setup(TMessageDialog *this, TPanel *parent_panel_in, char *info_file_in, int info_id_in, int wid_in, int hgt_in, char dlg_type_in, char *text_in, int btn_wid_in, int btn_hgt_in)
{
  TMessageDialog *v10; // esi@1
  char *v11; // eax@1
  TDrawArea *v12; // eax@1
  TPanelVtbl *v13; // ebx@2
  int v14; // edx@2
  int v15; // ST2C_4@2
  int v16; // edi@10
  int v17; // eax@10
  void (__thiscall *v18)(TPanel *, int, int, int, int); // ecx@11
  int v19; // ebx@11
  TButtonPanel *v20; // eax@19
  char *info_file_ina; // [sp+58h] [bp+8h]@10
  int index; // [sp+5Ch] [bp+Ch]@8
  void (__thiscall *space)(TPanel *, int, int, int, int); // [sp+60h] [bp+10h]@11
  int hgt_ina; // [sp+64h] [bp+14h]@10
  int y; // [sp+68h] [bp+18h]@4

  v10 = this;
  v11 = (char *)this->button;
  *(_DWORD *)v11 = 0;
  *((_DWORD *)v11 + 1) = 0;
  *((_DWORD *)v11 + 2) = 0;
  v12 = TPanel::renderArea(parent_panel_in);
  if ( !TDialogPanel::setup(
          (TDialogPanel *)&v10->vfptr,
          v12,
          parent_panel_in,
          wid_in,
          hgt_in,
          info_file_in,
          info_id_in,
          1) )
    return 0;
  v13 = v10->vfptr;
  v14 = v10->pnl_wid - 3;
  v15 = v10->pnl_hgt - btn_hgt_in - 6;
  v10->dlg_type = dlg_type_in;
  if ( !((int (__thiscall *)(TMessageDialog *, TMessageDialog *, int, char *, signed int, signed int, int, int, signed int, signed int, signed int, signed int))v13[1].set_redraw)(
          v10,
          v10,
          (int)&v10->text,
          text_in,
          3,
          3,
          v14,
          v15,
          11,
          1,
          1,
          1) )
    return 0;
  switch ( v10->dlg_type )
  {
    case 0:
      y = 1;
      break;
    case 4:
      y = 3;
      break;
    case 1:
    case 2:
    case 3:
      y = 2;
      break;
    default:
      return 0;
  }
  if ( v10->pnl_wid - btn_wid_in * y > 0 )
    index = (v10->pnl_wid - btn_wid_in * y) / (y + 1);
  else
    index = 0;
  v16 = index;
  v17 = v10->pnl_hgt - btn_hgt_in - 7;
  info_file_ina = 0;
  hgt_ina = v10->pnl_hgt - btn_hgt_in - 7;
  if ( y > 0 )
  {
    v18 = v13[1].set_rect;
    v19 = (int)v10->button;
    space = v18;
    while ( ((int (__thiscall *)(TMessageDialog *, TMessageDialog *, int, char *, char *, int, int, int, int, signed int, _DWORD, _DWORD))space)(
              v10,
              v10,
              v19,
              message_in,
              message_in,
              v16,
              v17,
              btn_wid_in,
              btn_hgt_in,
              11,
              0,
              0) )
    {
      v19 += 4;
      v16 += btn_wid_in + index;
      if ( (signed int)++info_file_ina >= y )
        goto LABEL_15;
      v17 = hgt_ina;
    }
    return 0;
  }
LABEL_15:
  switch ( v10->dlg_type )
  {
    case 0:
      TButtonPanel::set_text(v10->button[0], 0, 4001);
      break;
    case 1:
      TButtonPanel::set_text(v10->button[0], 0, 4001);
      TButtonPanel::set_text(v10->button[1], 0, 4002);
      goto LABEL_21;
    case 2:
      TButtonPanel::set_text(v10->button[0], 0, 4003);
      TButtonPanel::set_text(v10->button[1], 0, 4004);
      goto LABEL_21;
    case 4:
      TButtonPanel::set_text(v10->button[0], 0, 4003);
      TButtonPanel::set_text(v10->button[1], 0, 4004);
      TButtonPanel::set_text(v10->button[2], 0, 4002);
      v20 = v10->button[2];
      goto LABEL_22;
    case 3:
      TButtonPanel::set_text(v10->button[0], 0, 4005);
      TButtonPanel::set_text(v10->button[1], 0, 4007);
LABEL_21:
      v20 = v10->button[1];
LABEL_22:
      *((_DWORD *)v20 + 166) = 27;
      *((_DWORD *)v20 + 167) = 0;
      break;
    default:
      break;
  }
  v10->vfptr->set_tab_order((TPanel *)v10, (TPanel *)v10->button, (TPanel *)y);
  TPanel::set_curr_child((TPanel *)&v10->vfptr, (TPanel *)v10->button[0]);
  return 1;
}

//----- (0043FFF0) --------------------------------------------------------
int __thiscall TMessageDialog::setup(TMessageDialog *this, TPanel *parent_panel_in, char *info_file_in, int info_id_in, int wid_in, int hgt_in, char dlg_type_in, int text_id, int btn_wid_in, int btn_hgt_in)
{
  TMessageDialog *v10; // esi@1
  char str[256]; // [sp+4h] [bp-100h]@1

  v10 = this;
  TPanel::get_string(text_id, str, 256);
  return TMessageDialog::setup(
           v10,
           parent_panel_in,
           info_file_in,
           info_id_in,
           wid_in,
           hgt_in,
           dlg_type_in,
           str,
           btn_wid_in,
           btn_hgt_in);
}

//----- (00440070) --------------------------------------------------------
int __thiscall TMessageDialog::action(TMessageDialog *this, TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2)
{
  TMessageDialog *v5; // eax@1
  TPanel *v6; // ecx@1
  int result; // eax@4

  v5 = this;
  v6 = this->parent_panel;
  if ( !v6 || action_in != 1 )
    goto LABEL_12;
  if ( from_panel == (TPanel *)v5->button[0] )
  {
    ((void (__stdcall *)(TMessageDialog *, _DWORD, _DWORD, _DWORD))v6->vfptr->action)(v5, 0, 0, 0);
    return 1;
  }
  if ( from_panel == (TPanel *)v5->button[1] )
  {
    ((void (__stdcall *)(TMessageDialog *, signed int, _DWORD, _DWORD))v6->vfptr->action)(v5, 1, 0, 0);
    return 1;
  }
  if ( from_panel == (TPanel *)v5->button[2] )
  {
    ((void (__stdcall *)(TMessageDialog *, signed int, _DWORD, _DWORD))v6->vfptr->action)(v5, 2, 0, 0);
    result = 1;
  }
  else
  {
LABEL_12:
    result = TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, from_panel, action_in, action_val1, action_val2);
  }
  return result;
}

//----- (00440100) --------------------------------------------------------
int __stdcall TMessageDialog::key_down_action(int key, __int16 count, int alt_key, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (00440110) --------------------------------------------------------
int __thiscall TMessageDialog::handle_idle(TMessageDialog *this)
{
  TMessageDialog *v1; // esi@1

  v1 = this;
  if ( !rge_base_game->input_enabled )
    RGE_Base_Game::enable_input(rge_base_game);
  return TPanel::handle_idle((TPanel *)&v1->vfptr);
}
