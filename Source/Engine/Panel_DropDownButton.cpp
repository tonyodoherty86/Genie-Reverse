
//----- (00475470) --------------------------------------------------------
void __thiscall TDropDownButtonPanel::TDropDownButtonPanel(TDropDownButtonPanel *this, TDropDownPanel *drop_down_panel_in)
{
  TDropDownButtonPanel *v2; // esi@1

  v2 = this;
  TButtonPanel::TButtonPanel((TButtonPanel *)this);
  *(_DWORD *)v2 = &TDropDownButtonPanel::`vftable';
  *((_DWORD *)v2 + 174) = drop_down_panel_in;
}
// 5712C0: using guessed type int (__thiscall *TDropDownButtonPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00475490) --------------------------------------------------------
TDropDownButtonPanel *__thiscall TDropDownButtonPanel::`scalar deleting destructor'(TDropDownButtonPanel *this, unsigned int __flags)
{
  TDropDownButtonPanel *v2; // esi@1

  v2 = this;
  TDropDownButtonPanel::~TDropDownButtonPanel(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004754C0) --------------------------------------------------------
int __thiscall TDropDownButtonPanel::handle_mouse_move(TDropDownButtonPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TPanel *v5; // esi@1
  int result; // eax@3
  int v7; // ebx@5
  int v8; // eax@5

  v5 = (TPanel *)this;
  if( !*((_DWORD *)this + 26) )
    goto LABEL_9;
  if( (*(int (__stdcall **)(int, int))(**(_DWORD **)(*((_DWORD *)this + 174) + 252) + 188))(x, y) )
  {
    v5->vfptr->handle_mouse_up(v5, 1, x, y, ctrl_key, shift_key);
    return (*(int (__stdcall **)(signed int, int, int, int, int))(**(_DWORD **)(v5[2].mouse_down_shift + 252) + 112))(
             1,
             x,
             y,
             ctrl_key,
             shift_key);
  }
  if( (*(int (__stdcall **)(int, int))(**(_DWORD **)(v5[2].mouse_down_shift + 256) + 188))(x, y) )
  {
    v5->vfptr->handle_mouse_up(v5, 1, x, y, ctrl_key, shift_key);
    v7 = TPanel::width(*(TPanel **)(v5[2].mouse_down_shift + 252));
    v8 = TPanel::xPosition(*(TPanel **)(v5[2].mouse_down_shift + 252));
    result = (*(int (__stdcall **)(signed int, int, int, int, int))(**(_DWORD **)(v5[2].mouse_down_shift + 252) + 112))(
               1,
               v7 + v8 - 1,
               y,
               ctrl_key,
               shift_key);
  }
  else
  {
LABEL_9:
    result = TPanel::handle_mouse_move(v5, x, y, ctrl_key, shift_key);
  }
  return result;
}
