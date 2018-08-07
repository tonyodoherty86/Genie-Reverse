
//----- (0043EE70) --------------------------------------------------------
void __thiscall TListDialog::TListDialog(TListDialog *this, char *name)
{
  TListDialog *v2; // esi@1

  v2 = this;
  TDialogPanel::TDialogPanel((TDialogPanel *)&this->vfptr, name);
  v2->list_id = -1;
  v2->title = 0;
  v2->list = 0;
  v2->scroll_bar = 0;
  v2->ok_btn = 0;
  v2->cancel_btn = 0;
  v2->list_name = 0;
  v2->vfptr = (TPanelVtbl *)&TListDialog::`vftable';
}
// 56FAF8: using guessed type int (__thiscall *TListDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043EEC0) --------------------------------------------------------
TListDialog *__thiscall TListDialog::`scalar deleting destructor'(TListDialog *this, unsigned int __flags)
{
  TListDialog *v2; // esi@1

  v2 = this;
  TListDialog::~TListDialog(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0043EEE0) --------------------------------------------------------
void __thiscall TListDialog::~TListDialog(TListDialog *this)
{
  TListDialog *v1; // esi@1
  TTextPanel *v2; // ecx@1
  TListPanel *v3; // ecx@3
  TScrollBarPanel *v4; // ecx@5
  TButtonPanel *v5; // ecx@7
  TButtonPanel *v6; // ecx@9

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TListDialog::`vftable';
  v2 = this->title;
  if( v2 )
    ((void (__stdcall *)(_DWORD))v2->vfptr->__vecDelDtor)(1);
  v3 = v1->list;
  if( v3 )
    ((void (__stdcall *)(_DWORD))v3->vfptr->__vecDelDtor)(1);
  v4 = v1->scroll_bar;
  if( v4 )
    ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
  v5 = v1->ok_btn;
  if( v5 )
    (**(void (__stdcall ***)(_DWORD))v5)(1);
  v6 = v1->cancel_btn;
  if( v6 )
    (**(void (__stdcall ***)(_DWORD))v6)(1);
  TDialogPanel::~TDialogPanel((TDialogPanel *)&v1->vfptr);
}
// 56FAF8: using guessed type int (__thiscall *TListDialog::`vftable')(void *Memory, unsigned int __flags);

//----- (0043EF80) --------------------------------------------------------
int __thiscall TListDialog::setup(TListDialog *this, TPanel *parent_panel_in, char *info_file_in, int info_id_in, int wid_in, int hgt_in, int title_x_in, int title_y_in, int title_wid_in, int title_hgt_in, char *title_in, int list_x_in, int list_y_in, int list_wid_in, int list_hgt_in, char **list_in, int list_num_lines_in, __int16 list_id_in, int ok_btn_x_in, int cancel_btn_x_in, int btn_y_in, int btn_wid_in, int btn_hgt_in)
{
  TListDialog *v23; // esi@1
  TDrawArea *v24; // eax@1
  int result; // eax@1
  TPanelVtbl *v26; // edi@5
  TPanel **v27; // ebx@5
  TListPanel *v28; // ecx@9
  int (__thiscall *v29)(TListDialog *, TListDialog *, TButtonPanel **, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD); // edi@9
  TButtonPanel *v30; // ebp@11

  v23 = this;
  v24 = TPanel::renderArea(parent_panel_in);
  result = TDialogPanel::setup(
             (TDialogPanel *)&v23->vfptr,
             v24,
             parent_panel_in,
             wid_in,
             hgt_in,
             info_file_in,
             info_id_in,
             1);
  if( result )
  {
    if( !title_in
      || !*title_in
      || (result = ((int (__thiscall *)(TListDialog *, TListDialog *, int, char *, int, int, int, int, signed int, signed int, signed int, signed int))v23->vfptr[1].set_redraw)(
                     v23,
                     v23,
                     (int)&v23->title,
                     title_in,
                     title_x_in,
                     title_y_in,
                     title_wid_in,
                     title_hgt_in,
                     4,
                     1,
                     1,
                     1)) != 0 )
    {
      v26 = v23->vfptr;
      v27 = (TPanel **)&v23->list;
      result = ((int (__thiscall *)(TListDialog *, TListDialog *, int, int, int, int, int, signed int))v23->vfptr[1].draw)(
                 v23,
                 v23,
                 (int)&v23->list,
                 list_x_in,
                 list_y_in,
                 list_wid_in,
                 list_hgt_in,
                 11);
      if( result )
      {
        result = ((int (__thiscall *)(TListDialog *, int, TPanel *, signed int))v26[1].draw_offset)(
                   v23,
                   (int)&v23->scroll_bar,
                   *v27,
                   20);
        if( result )
        {
          if( list_in )
            ((void (__stdcall *)(char **, int))(*v27)->vfptr[1].__vecDelDtor)(list_in, list_num_lines_in);
          v28 = (TListPanel *)*v27;
          v23->list_id = list_id_in;
          TListPanel::scroll_cur_line(v28, 1, list_id_in, 1);
          v29 = *(int (__thiscall **)(TListDialog *, TListDialog *, TButtonPanel **, signed int, _DWORD, int, int, int, int, _DWORD, _DWORD, _DWORD))&v26[1].gap4[4];
          result = v29(v23, v23, &v23->ok_btn, 4001, 0, ok_btn_x_in, btn_y_in, btn_wid_in, btn_hgt_in, 0, 0, 0);
          if( result )
          {
            result = v29(
                       v23,
                       v23,
                       &v23->cancel_btn,
                       4002,
                       0,
                       cancel_btn_x_in,
                       btn_y_in,
                       btn_wid_in,
                       btn_hgt_in,
                       0,
                       0,
                       0);
            if( result )
            {
              v30 = v23->cancel_btn;
              *((_DWORD *)v30 + 166) = 27;
              *((_DWORD *)v30 + 167) = 0;
              TPanel::set_curr_child((TPanel *)&v23->vfptr, *v27);
              result = 1;
            }
          }
        }
      }
    }
  }
  return result;
}

//----- (0043F130) --------------------------------------------------------
int __thiscall TListDialog::setup(TListDialog *this, TPanel *parent_panel_in, char *info_file_in, int info_id_in, int wid_in, int hgt_in, int title_x_in, int title_y_in, int title_wid_in, int title_hgt_in, int title_string_id, int list_x_in, int list_y_in, int list_wid_in, int list_hgt_in, char **list_in, int list_num_lines_in, __int16 list_id_in, int ok_btn_x_in, int cancel_btn_x_in, int btn_y_in, int btn_wid_in, int btn_hgt_in)
{
  TListDialog *v23; // esi@1
  char str[256]; // [sp+4h] [bp-100h]@1

  v23 = this;
  TPanel::get_string(title_string_id, str, 256);
  return TListDialog::setup(
           v23,
           parent_panel_in,
           info_file_in,
           info_id_in,
           wid_in,
           hgt_in,
           title_x_in,
           title_y_in,
           title_wid_in,
           title_hgt_in,
           str,
           list_x_in,
           list_y_in,
           list_wid_in,
           list_hgt_in,
           list_in,
           list_num_lines_in,
           list_id_in,
           ok_btn_x_in,
           cancel_btn_x_in,
           btn_y_in,
           btn_wid_in,
           btn_hgt_in);
}

//----- (0043F210) --------------------------------------------------------
int __stdcall TListDialog::key_down_action(int key, __int16 count, int alt_key, int ctrl_key, int shift_key)
{
  return 0;
}

//----- (0043F220) --------------------------------------------------------
int __thiscall TListDialog::action(TListDialog *this, TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2)
{
  TListDialog *v5; // esi@1
  __int16 v6; // ax@4
  TTextPanel *v7; // ecx@4
  char *v8; // eax@4
  TPanel *v9; // ecx@4
  TPanel *v11; // ecx@8
  TListPanel *v12; // ecx@10
  __int16 v13; // ax@12
  TTextPanel *v14; // ecx@12
  char *v15; // eax@12
  TPanel *v16; // ecx@12

  v5 = this;
  if( from_panel )
  {
    if( from_panel == (TPanel *)this->ok_btn )
    {
      if( action_in == 1 )
      {
        v6 = TTextPanel::currentLineNumber((TTextPanel *)&this->list->vfptr);
        v7 = (TTextPanel *)&v5->list->vfptr;
        v5->list_id = v6;
        v8 = TTextPanel::currentLine(v7);
        v9 = v5->parent_panel;
        v5->list_name = v8;
        if( v9 )
        {
          ((void (__stdcall *)(TListDialog *, signed int, _DWORD, _DWORD))v9->vfptr->action)(v5, 1, 0, 0);
          return 1;
        }
        return 1;
      }
    }
    else if( from_panel == (TPanel *)this->cancel_btn )
    {
      if( action_in == 1 )
      {
        v11 = this->parent_panel;
        if( v11 )
        {
          ((void (__stdcall *)(TListDialog *, signed int, _DWORD, _DWORD))v11->vfptr->action)(v5, 2, 0, 0);
          return 1;
        }
        return 1;
      }
    }
    else
    {
      v12 = this->list;
      if( (TListPanel *)from_panel == v12 && action_in == 3 )
      {
        v13 = TTextPanel::currentLineNumber((TTextPanel *)&v12->vfptr);
        v14 = (TTextPanel *)&v5->list->vfptr;
        v5->list_id = v13;
        v15 = TTextPanel::currentLine(v14);
        v16 = v5->parent_panel;
        v5->list_name = v15;
        if( v16 )
          ((void (__stdcall *)(TListDialog *, signed int, _DWORD, _DWORD))v16->vfptr->action)(v5, 1, 0, 0);
        return 1;
      }
    }
  }
  return TEasy_Panel::action((TEasy_Panel *)&v5->vfptr, from_panel, action_in, action_val1, action_val2);
}

//----- (0043F320) --------------------------------------------------------
__int16 __thiscall TListDialog::get_list_id(TListDialog *this)
{
  return this->list_id;
}

//----- (0043F330) --------------------------------------------------------
char *__thiscall TListDialog::get_list_name(TListDialog *this)
{
  return this->list_name;
}
