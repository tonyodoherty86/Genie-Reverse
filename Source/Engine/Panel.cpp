
//----- (00463BA0) --------------------------------------------------------
int _E4()
{
  _E1();
  return _E3();
}

//----- (00463BB0) --------------------------------------------------------
void _E1()
{
  TPanelSystem::TPanelSystem(&panel_system);
}

//----- (00463BC0) --------------------------------------------------------
int _E3()
{
  return atexit(_E2);
}

//----- (00463BD0) --------------------------------------------------------
void __cdecl _E2()
{
  TPanelSystem::~TPanelSystem(&panel_system);
}

//----- (00463BE0) --------------------------------------------------------
void __thiscall TPanelSystem::TPanelSystem(TPanelSystem *this)
{
  TPanelSystem *v1; // esi@1
  char *v2; // eax@1
  char *v3; // ecx@1
  signed int v4; // edi@1

  v1 = this;
  this->ImeEnabled = 1;
  this->InputEnabled = 1;
  this->mouseOwnerValue = 0;
  this->keyboardOwnerValue = 0;
  this->modalPanelValue = 0;
  this->currentPanelValue = 0;
  this->panelListValue = 0;
  this->numberActivePanelsValue = 0;
  this->prevCurrentChildValue = 0;
  this->Imc = 0;
  this->ImeOn = 0;
  this->saved_colors = 0;
  v2 = (char *)this->palette_use_count;
  v3 = (char *)this->palette_file;
  v4 = 10;
  do
  {
    *((_DWORD *)v2 - 660) = 0;
    *v3 = 0;
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 10) = 0;
    v2 += 4;
    v3 += 260;
    --v4;
  }
  while( v4 );
  TPanelSystem::setup(v1);
}

//----- (00463C50) --------------------------------------------------------
void __thiscall TPanelSystem::~TPanelSystem(TPanelSystem *this)
{
  TPanelSystem *v1; // ebp@1
  PanelNode *v2; // eax@1
  PanelNode *v3; // esi@2
  TPanel *v4; // ecx@3
  char (*v5)[260]; // edi@7
  int v6; // esi@7
  signed int v7; // [sp+10h] [bp-4h]@7

  v1 = this;
  TPanelSystem::restore_system_colors(this);
  v2 = v1->panelListValue;
  if( v2 )
  {
    v3 = v2->next_node;
    if( v3 != v2 )
    {
      do
      {
        v3 = v3->next_node;
        v4 = v3->prev_node->panel;
        if( v4 )
          ((void (__stdcall *)(_DWORD))v4->vfptr->__vecDelDtor)(1);
        free(v3->prev_node);
      }
      while( v3 != v1->panelListValue );
    }
    free(v1->panelListValue);
    v1->panelListValue = 0;
  }
  v5 = v1->palette_file;
  v6 = (int)v1->palette;
  v7 = 10;
  do
  {
    if( *(_DWORD *)v6 )
    {
      DeleteObject(*(HGDIOBJ *)v6);
      *(_DWORD *)v6 = 0;
      v5 = 0;
      *(_DWORD *)(v6 + 2640) = 0;
      v1->palette_id[0] = 0;
    }
    v6 += 4;
    ++v5;
    --v7;
  }
  while( v7 );
  TPanelSystem::EnableIME(v1);
}

//----- (00463D00) --------------------------------------------------------
TPanel *__thiscall TPanelSystem::currentPanel(TPanelSystem *this)
{
  return this->currentPanelValue;
}

//----- (00463D10) --------------------------------------------------------
TPanel *__thiscall TPanelSystem::previousPanel(TPanelSystem *this)
{
  TPanel *v1; // ecx@1
  TPanel *result; // eax@2

  v1 = this->currentPanelValue;
  if( v1 )
    result = TPanel::previousPanel(v1);
  else
    result = 0;
  return result;
}

//----- (00463D20) --------------------------------------------------------
TPanel *__thiscall TPanelSystem::mouseOwner(TPanelSystem *this)
{
  return this->mouseOwnerValue;
}

//----- (00463D30) --------------------------------------------------------
TPanel *__thiscall TPanelSystem::keyboardOwner(TPanelSystem *this)
{
  return this->keyboardOwnerValue;
}

//----- (00463D40) --------------------------------------------------------
TPanel *__thiscall TPanelSystem::modalPanel(TPanelSystem *this)
{
  return this->modalPanelValue;
}

//----- (00463D50) --------------------------------------------------------
TPanel *__thiscall TPanelSystem::panel(TPanelSystem *this, char *n)
{
  PanelNode *v2; // eax@1
  TPanel *result; // eax@2

  v2 = TPanelSystem::findPanelNode(this, n);
  if( v2 )
    result = v2->panel;
  else
    result = 0;
  return result;
}

//----- (00463D70) --------------------------------------------------------
int __thiscall TPanelSystem::numberActivePanels(TPanelSystem *this)
{
  return this->numberActivePanelsValue;
}

//----- (00463D80) --------------------------------------------------------
PanelNode *__thiscall TPanelSystem::addPanel(TPanelSystem *this, TPanel *p, int makeCurrent, int makeModal)
{
  TPanelSystem *v4; // edi@1
  char *v5; // eax@1
  PanelNode *result; // eax@2
  PanelNode *v7; // esi@2

  v4 = this;
  v5 = TPanel::panelName(p);
  if( !TPanelSystem::findPanelNode(v4, v5) )
  {
    result = (PanelNode *)calloc(1u, 0xCu);
    v7 = result;
    if( !result )
      return result;
    result->panel = p;
    TPanel::setPreviousPanel(p, 0);
    v7->prev_node = v4->panelListValue->prev_node;
    v7->next_node = v4->panelListValue;
    v4->panelListValue->prev_node = v7;
    v7->prev_node->next_node = v7;
    ++v4->numberActivePanelsValue;
  }
  if( makeCurrent )
    TPanelSystem::setCurrentPanel(v4, p, makeModal);
  return (PanelNode *)1;
}

//----- (00463E10) --------------------------------------------------------
char *__thiscall TPanelSystem::removePanel(TPanelSystem *this, char *n)
{
  char *result; // eax@1
  TPanelSystem *v3; // esi@1

  result = n;
  v3 = this;
  if( n )
  {
    result = (char *)TPanelSystem::findPanelNode(this, n);
    if( result )
    {
      --v3->numberActivePanelsValue;
      *(_DWORD *)(*((_DWORD *)result + 1) + 8) = *((_DWORD *)result + 2);
      *(_DWORD *)(*((_DWORD *)result + 2) + 4) = *((_DWORD *)result + 1);
      free(result);
      result = (char *)1;
    }
  }
  return result;
}

//----- (00463E60) --------------------------------------------------------
int __thiscall TPanelSystem::setCurrentPanel(TPanelSystem *this, char *n, int makeModal)
{
  TPanelSystem *v3; // esi@1
  PanelNode *v4; // edi@1
  int result; // eax@4

  v3 = this;
  v4 = TPanelSystem::findPanelNode(this, n);
  if( v4 )
  {
    if( v3->mouseOwnerValue )
      TPanel::release_mouse(v3->mouseOwnerValue);
    v3->modalPanelValue = 0;
    v3->keyboardOwnerValue = 0;
    TPanelSystem::setCurrentPanel(v3, v4->panel, makeModal);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00463EB0) --------------------------------------------------------
TPanel *__thiscall TPanelSystem::restorePreviousPanel(TPanelSystem *this, int destroyOldCurrentPanel)
{
  TPanelSystem *v2; // edi@1
  TPanel *v3; // ecx@1
  TPanel *result; // eax@2
  TPanel *v5; // esi@3
  TPanel *v6; // ebx@4
  char *v7; // eax@8
  TPanelVtbl *v8; // eax@9

  v2 = this;
  v3 = this->currentPanelValue;
  if( v3 )
  {
    result = TPanel::previousPanel(v3);
    v5 = result;
    if( result )
    {
      v6 = v2->currentPanelValue;
      if( destroyOldCurrentPanel )
      {
        if( TPanel::previousPanel(result) == v6 )
          TPanel::setPreviousPanel(v5, 0);
        v7 = TPanel::panelName(v6);
        TPanelSystem::destroyPanel(v2, v7);
      }
      else
      {
        TPanel::setPreviousPanel(result, v6);
      }
      v8 = v5->vfptr;
      v2->currentPanelValue = v5;
      v8->set_focus(v5, 1);
      ((void (__stdcall *)(signed int))v2->currentPanelValue->vfptr->set_redraw)(2);
      UpdateWindow(AppWnd);
      result = (TPanel *)1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00463F40) --------------------------------------------------------
void __thiscall TPanelSystem::setMouseOwner(TPanelSystem *this, TPanel *p)
{
  this->mouseOwnerValue = p;
}

//----- (00463F50) --------------------------------------------------------
void __thiscall TPanelSystem::setKeyboardOwner(TPanelSystem *this, TPanel *p)
{
  this->keyboardOwnerValue = p;
}

//----- (00463F60) --------------------------------------------------------
void __thiscall TPanelSystem::setModalPanel(TPanelSystem *this, TPanel *p)
{
  TPanelSystem *v2; // esi@1
  TPanel *v3; // eax@4
  TPanel *v4; // eax@5
  TPanel *v5; // ecx@6
  TPanel *v6; // eax@9
  TPanel *v7; // ecx@13
  TPanelVtbl *v8; // eax@15

  v2 = this;
  if( this->modalPanelValue && p )
    TPanel::setPreviousModalPanel(p, this->modalPanelValue);
  v3 = v2->modalPanelValue;
  if( v3 )
  {
    if( !v3->tab_stop )
    {
      v6 = v3->parent_panel;
      if( v6 )
        TPanel::set_curr_child(v6, v2->prevCurrentChildValue);
    }
  }
  else
  {
    v4 = v2->prevCurrentChildValue;
    if( v4 )
    {
      v5 = v4->parent_panel;
      if( v5 )
        TPanel::set_curr_child(v5, v2->prevCurrentChildValue);
    }
  }
  v2->prevCurrentChildValue = 0;
  v2->modalPanelValue = p;
  if( p && p != v2->currentPanelValue )
  {
    v7 = p->parent_panel;
    if( v7 )
    {
      v2->prevCurrentChildValue = v7->curr_child;
      TPanel::set_curr_child(v7, p);
    }
    else
    {
      v8 = p->vfptr;
      v2->prevCurrentChildValue = 0;
      v8->set_focus(p, 1);
    }
  }
}

//----- (00463FF0) --------------------------------------------------------
void __thiscall TPanelSystem::setCurrentPanelModal(TPanelSystem *this)
{
  TPanelSystem *v1; // esi@1
  TPanel *v2; // eax@1
  TPanel *v3; // ecx@2

  v1 = this;
  v2 = this->modalPanelValue;
  if( v2 )
  {
    v3 = this->currentPanelValue;
    if( v2 != v3 )
      TPanel::setPreviousModalPanel(v3, v2);
  }
  v1->modalPanelValue = v1->currentPanelValue;
}

//----- (00464010) --------------------------------------------------------
TPanel *__thiscall TPanelSystem::restorePreviousModalPanel(TPanelSystem *this)
{
  TPanelSystem *v1; // edi@1
  TPanel *v2; // ecx@1
  TPanel *result; // eax@2
  TPanel *v4; // esi@3

  v1 = this;
  v2 = this->modalPanelValue;
  if( v2 )
  {
    result = TPanel::previousModalPanel(v2);
    v4 = result;
    if( result )
    {
      result->vfptr->set_focus(result, 1);
      TPanelSystem::setMouseOwner(v1, v4);
      TPanelSystem::setKeyboardOwner(v1, v4);
      v1->modalPanelValue = v4;
      result = (TPanel *)1;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00464060) --------------------------------------------------------
char *__thiscall TPanelSystem::destroyPanel(TPanelSystem *this, char *n)
{
  char *result; // eax@1
  TPanelSystem *v3; // edi@1
  int v4; // esi@2
  TPanel *v5; // eax@3

  result = n;
  v3 = this;
  if( n )
  {
    result = (char *)TPanelSystem::findPanelNode(this, n);
    v4 = (int)result;
    if( result )
    {
      v5 = v3->currentPanelValue;
      --v3->numberActivePanelsValue;
      if( v5 == *(TPanel **)v4 )
        v3->currentPanelValue = 0;
      if( v3->mouseOwnerValue == *(TPanel **)v4 )
        v3->mouseOwnerValue = 0;
      if( v3->keyboardOwnerValue == *(TPanel **)v4 )
        v3->keyboardOwnerValue = 0;
      if( v3->modalPanelValue == *(TPanel **)v4 )
        v3->modalPanelValue = 0;
      *(_DWORD *)(*(_DWORD *)(v4 + 4) + 8) = *(_DWORD *)(v4 + 8);
      *(_DWORD *)(*(_DWORD *)(v4 + 8) + 4) = *(_DWORD *)(v4 + 4);
      if( *(_DWORD *)v4 )
        (***(void (__stdcall ****)(_DWORD))v4)(1);
      free((void *)v4);
      result = (char *)1;
    }
  }
  return result;
}

//----- (00464100) --------------------------------------------------------
BOOL __thiscall TPanelSystem::inSystem(TPanelSystem *this, char *n)
{
  return TPanelSystem::findPanelNode(this, n) != 0;
}

//----- (00464120) --------------------------------------------------------
int __thiscall TPanelSystem::inSystem(TPanelSystem *this, TPanel *p)
{
  TPanelSystem *v2; // esi@1
  char *v3; // eax@2
  int result; // eax@3

  v2 = this;
  result = 0;
  if( p )
  {
    v3 = TPanel::panelName(p);
    if( TPanelSystem::findPanelNode(v2, v3) )
      result = 1;
  }
  return result;
}

//----- (00464150) --------------------------------------------------------
PanelNode *__thiscall TPanelSystem::setup(TPanelSystem *this)
{
  TPanelSystem *v1; // esi@1
  PanelNode *result; // eax@1

  v1 = this;
  result = (PanelNode *)calloc(1u, 0xCu);
  v1->panelListValue = result;
  if( result )
  {
    result->panel = 0;
    v1->panelListValue->prev_node = v1->panelListValue;
    v1->panelListValue->next_node = v1->panelListValue;
    v1->save_back_color = GetSysColor(5);
    v1->save_text_color = GetSysColor(8);
    v1->saved_colors = 1;
    result = (PanelNode *)1;
  }
  return result;
}

//----- (004641B0) --------------------------------------------------------
PanelNode *__thiscall TPanelSystem::findPanelNode(TPanelSystem *this, char *n)
{
  PanelNode *v2; // eax@2
  PanelNode *v3; // edi@2
  PanelNode *result; // eax@7

  if( !n )
    goto LABEL_11;
  v2 = this->panelListValue;
  v3 = v2->next_node;
  if( v3 != v2 )
  {
    do
    {
      if( !strcmp(TPanel::panelName(v3->panel), n) )
        break;
      v3 = v3->next_node;
    }
    while( v3 != this->panelListValue );
  }
  if( v3 != this->panelListValue && !strcmp(TPanel::panelName(v3->panel), n) )
    result = v3;
  else
LABEL_11:
    result = 0;
  return result;
}

//----- (00464260) --------------------------------------------------------
void __thiscall TPanelSystem::setCurrentPanel(TPanelSystem *this, TPanel *p, int makeModal)
{
  TPanelSystem *v3; // esi@1
  TPanel *v4; // ecx@1
  TPanelVtbl *v5; // eax@3

  v3 = this;
  TPanel::setPreviousPanel(p, this->currentPanelValue);
  v4 = v3->currentPanelValue;
  if( v4 )
    ((void (__stdcall *)(_DWORD))v4->vfptr->set_focus)(0);
  v5 = p->vfptr;
  v3->currentPanelValue = p;
  v5->set_focus(p, 1);
  ((void (__stdcall *)(signed int))v3->currentPanelValue->vfptr->set_redraw)(2);
  UpdateWindow(AppWnd);
  if( makeModal )
    TPanelSystem::setCurrentPanelModal(v3);
}

//----- (004642C0) --------------------------------------------------------
void *__thiscall TPanelSystem::get_palette(TPanelSystem *this, char *file_name, int res_id)
{
  TPanelSystem *v3; // ebx@1
  signed int v4; // ebp@7
  signed int v5; // edi@7
  int *v6; // edx@7
  int v7; // eax@11
  void *result; // eax@17
  const char *v9; // [sp+10h] [bp-10Ch]@7
  TPanelSystem *v10; // [sp+14h] [bp-108h]@1
  char file_name2[260]; // [sp+18h] [bp-104h]@3

  v3 = this;
  v10 = this;
  if( file_name )
  {
    if( strchr(file_name, 46) )
      strcpy(file_name2, file_name);
    else
      sprintf(file_name2, aS_pal, file_name);
    strupr(file_name2);
  }
  else
  {
    file_name2[0] = 0;
  }
  v4 = -1;
  v9 = (const char *)v3->palette_file;
  v5 = 0;
  v6 = v3->palette_id;
  do
  {
    if( *(v6 - 670) )
    {
      if( res_id != -1 && *v6 == res_id || (v7 = strcmp(v9, file_name2), v3 = v10, !v7) )
      {
        ++v3->palette_use_count[v5];
        return v3->palette[v5];
      }
    }
    else if( v4 == -1 )
    {
      v4 = v5;
    }
    ++v5;
    ++v6;
    v9 += 260;
  }
  while( v5 < 10 );
  if( v4 == -1 )
  {
    result = 0;
  }
  else
  {
    result = ReadPalette(file_name2, res_id, 1);
    v3->palette[v4] = result;
    if( result )
    {
      ++v3->palette_use_count[v4];
      strcpy(v3->palette_file[v4], file_name2);
      v3->palette_id[v4] = res_id;
      result = v3->palette[v4];
    }
  }
  return result;
}

//----- (00464480) --------------------------------------------------------
void __thiscall TPanelSystem::release_palette(TPanelSystem *this, void *pal)
{
  TPanelSystem *v2; // edi@1
  signed int v3; // esi@1
  void **v4; // eax@1
  int v5; // eax@5

  v2 = this;
  v3 = 0;
  v4 = this->palette;
  while( *v4 != pal )
  {
    ++v3;
    ++v4;
    if( v3 >= 10 )
      return;
  }
  v5 = this->palette_use_count[v3] - 1;
  this->palette_use_count[v3] = v5;
  if( !v5 )
  {
    DeleteObject(this->palette[v3]);
    v2->palette[v3] = 0;
    v2->palette_file[v3][0] = 0;
  }
}

//----- (004644E0) --------------------------------------------------------
void __thiscall TPanelSystem::DisableIME(TPanelSystem *this)
{
  TPanelSystem *v1; // esi@1

  v1 = this;
  if( this->ImeEnabled )
  {
    this->Imc = ImmAssociateContext(AppWnd, 0);
    v1->ImeEnabled = 0;
  }
}

//----- (00464510) --------------------------------------------------------
void __thiscall TPanelSystem::EnableIME(TPanelSystem *this)
{
  if( this->Imc )
  {
    if( !this->ImeEnabled )
      ImmAssociateContext(AppWnd, this->Imc);
  }
}

//----- (00464540) --------------------------------------------------------
int __thiscall TPanelSystem::IsIMEEnabled(TPanelSystem *this)
{
  return this->ImeEnabled;
}

//----- (00464550) --------------------------------------------------------
void __thiscall TPanelSystem::TurnIMEOn(TPanelSystem *this)
{
  TPanelSystem *v1; // esi@1
  unsigned int v2; // eax@3

  v1 = this;
  if( !this->ImeOn && this->ImeEnabled )
  {
    v2 = this->Imc;
    if( v2 )
    {
      ImmSetOpenStatus(v2, 1);
      v1->ImeOn = 1;
    }
  }
}

//----- (00464590) --------------------------------------------------------
void __thiscall TPanelSystem::TurnIMEOff(TPanelSystem *this)
{
  TPanelSystem *v1; // esi@1
  unsigned int v2; // eax@3

  v1 = this;
  if( this->ImeOn && this->ImeEnabled )
  {
    v2 = this->Imc;
    if( v2 )
    {
      ImmSetOpenStatus(v2, 0);
      v1->ImeOn = 0;
    }
  }
}

//----- (004645D0) --------------------------------------------------------
int __thiscall TPanelSystem::IsIMEOn(TPanelSystem *this)
{
  return this->ImeOn;
}

//----- (004645E0) --------------------------------------------------------
int __thiscall TPanelSystem::GetInputEnabled(TPanelSystem *this)
{
  return this->InputEnabled;
}

//----- (004645F0) --------------------------------------------------------
void __thiscall TPanelSystem::EnableInput(TPanelSystem *this)
{
  this->InputEnabled = 1;
}

//----- (00464600) --------------------------------------------------------
void __thiscall TPanelSystem::DisableInput(TPanelSystem *this)
{
  this->InputEnabled = 0;
}

//----- (00464610) --------------------------------------------------------
void __thiscall TPanelSystem::stop_sound_system(TPanelSystem *this)
{
  TPanelSystem *v1; // edi@1
  PanelNode *i; // esi@1

  v1 = this;
  for( i = this->panelListValue->next_node; i; i = i->next_node )
  {
    if( i == v1->panelListValue )
      break;
    if( i->panel )
      ((void (*)(void))i->panel->vfptr->stop_sound_system)();
  }
}

//----- (00464640) --------------------------------------------------------
int __thiscall TPanelSystem::restart_sound_system(TPanelSystem *this)
{
  TPanelSystem *v1; // edi@1
  signed int v2; // ebx@1
  PanelNode *i; // esi@1

  v1 = this;
  v2 = 1;
  for( i = this->panelListValue->next_node; i; i = i->next_node )
  {
    if( i == v1->panelListValue )
      break;
    if( i->panel && !((int (*)(void))i->panel->vfptr->restart_sound_system)() )
      v2 = 0;
  }
  return v2;
}

//----- (00464680) --------------------------------------------------------
void __thiscall TPanelSystem::restore_system_colors(TPanelSystem *this)
{
  TPanelSystem *v1; // esi@1
  unsigned int v2; // ecx@4
  unsigned int colors[2]; // [sp+8h] [bp-10h]@4
  int elems[2]; // [sp+10h] [bp-8h]@4

  v1 = this;
  if( this->saved_colors && (GetSysColor(5) != this->save_back_color || GetSysColor(8) != v1->save_text_color) )
  {
    v2 = v1->save_text_color;
    colors[0] = v1->save_back_color;
    elems[0] = 5;
    elems[1] = 8;
    colors[1] = v2;
    SetSysColors(2, elems, colors);
  }
}

//----- (004646F0) --------------------------------------------------------
void __thiscall TPanelSystem::set_restore(TPanelSystem *this)
{
  PanelNode *v1; // edx@1
  PanelNode *v2; // eax@1

  v1 = this->panelListValue;
  v2 = v1->next_node;
  if( v2 != v1 )
  {
    do
    {
      if( v2->panel )
        v2->panel->need_restore = 1;
      v2 = v2->next_node;
    }
    while( v2 != this->panelListValue );
  }
}

//----- (00464720) --------------------------------------------------------
void __thiscall TPanel::TPanel(TPanel *this, char *name)
{
  TPanel *v2; // esi@1
  char *v3; // eax@1

  v2 = this;
  this->previousPanelValue = 0;
  this->previousModalPanelValue = 0;
  this->pnl_x = 0;
  this->pnl_y = 0;
  this->pnl_wid = 0;
  this->pnl_hgt = 0;
  this->panelNameValue = 0;
  this->render_area = 0;
  this->position_mode = 0;
  this->need_redraw = 2;
  this->curr_child = 0;
  this->parent_panel = 0;
  this->left_panel = 0;
  this->top_panel = 0;
  this->right_panel = 0;
  this->bottom_panel = 0;
  this->node = 0;
  this->first_child_node = 0;
  this->last_child_node = 0;
  this->tab_prev_panel = 0;
  this->tab_next_panel = 0;
  this->mouse_captured = 0;
  this->active = 1;
  this->visible = 0;
  this->tab_stop = 0;
  this->have_focus = 0;
  this->overlapping_children = 1;
  this->handle_mouse_input = 1;
  this->just_drawn = 0;
  this->clip_rgn = 0;
  this->left_border = 0;
  this->top_border = 0;
  this->right_border = 0;
  this->bottom_border = 0;
  this->min_wid = 0;
  this->max_wid = 0;
  this->min_hgt = 0;
  this->max_hgt = 0;
  this->mouse_hold_interval = 250;
  this->mouse_move_tolerance = 0;
  this->mouse_down_x = 0;
  this->mouse_down_y = 0;
  this->mouse_down_ctrl = 0;
  this->mouse_down_shift = 0;
  this->mouse_down_time = 0;
  this->error_code = 0;
  this->z_order = 0;
  this->display_changed_count = 0;
  this->mouse_action = 0;
  this->mouse_down_button = 0;
  this->panel_type = 0;
  this->color = 0;
  this->fill_in_background = 0;
  this->draw_rect2_flag = 0;
  this->vfptr = (TPanelVtbl *)&TPanel::`vftable';
  this->render_rect.left = 0;
  this->render_rect.top = 0;
  this->render_rect.right = 0;
  this->render_rect.bottom = 0;
  TPanel::setPanelName(this, name);
  v2->need_restore = 0;
  v2->help_string_id = -1;
  v2->help_page_id = -1;
  v3 = v2->panelNameValue;
  if( v3 )
  {
    if( *v3 )
      TPanelSystem::addPanel(&panel_system, v2, 0, 0);
  }
}
// 570C38: using guessed type int (__thiscall *TPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00464890) --------------------------------------------------------
TPanel *__thiscall TPanel::`vector deleting destructor'(TPanel *this, unsigned int __flags)
{
  TPanel *v2; // esi@1

  v2 = this;
  TPanel::~TPanel(this);
  if( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (004648B0) --------------------------------------------------------
void __thiscall TPanel::TPanel(TPanel *this)
{
  this->previousPanelValue = 0;
  this->previousModalPanelValue = 0;
  this->pnl_x = 0;
  this->pnl_y = 0;
  this->pnl_wid = 0;
  this->pnl_hgt = 0;
  this->panelNameValue = 0;
  this->render_area = 0;
  this->position_mode = 0;
  this->need_redraw = 2;
  this->curr_child = 0;
  this->parent_panel = 0;
  this->left_panel = 0;
  this->top_panel = 0;
  this->right_panel = 0;
  this->bottom_panel = 0;
  this->node = 0;
  this->first_child_node = 0;
  this->last_child_node = 0;
  this->tab_prev_panel = 0;
  this->tab_next_panel = 0;
  this->mouse_captured = 0;
  this->active = 1;
  this->visible = 0;
  this->tab_stop = 0;
  this->have_focus = 0;
  this->overlapping_children = 1;
  this->handle_mouse_input = 1;
  this->clip_rgn = 0;
  this->left_border = 0;
  this->top_border = 0;
  this->right_border = 0;
  this->bottom_border = 0;
  this->min_wid = 0;
  this->max_wid = 0;
  this->min_hgt = 0;
  this->max_hgt = 0;
  this->mouse_move_tolerance = 0;
  this->mouse_down_x = 0;
  this->mouse_down_y = 0;
  this->mouse_down_ctrl = 0;
  this->mouse_down_shift = 0;
  this->mouse_down_time = 0;
  this->error_code = 0;
  this->z_order = 0;
  this->display_changed_count = 0;
  this->mouse_action = 0;
  this->mouse_down_button = 0;
  this->panel_type = 0;
  this->color = 0;
  this->fill_in_background = 0;
  this->draw_rect2_flag = 0;
  this->render_rect.left = 0;
  this->render_rect.top = 0;
  this->render_rect.right = 0;
  this->render_rect.bottom = 0;
  this->mouse_hold_interval = 250;
  this->vfptr = (TPanelVtbl *)&TPanel::`vftable';
  this->help_string_id = -1;
  this->help_page_id = -1;
}
// 570C38: using guessed type int (__thiscall *TPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (004649E0) --------------------------------------------------------
void __thiscall TPanel::~TPanel(TPanel *this)
{
  TPanel *v1; // esi@1
  char *v2; // eax@3
  TPanel *v3; // ecx@5
  void *v4; // eax@8
  TPanel *v5; // ecx@10
  char *v6; // esi@12

  v1 = this;
  this->vfptr = (TPanelVtbl *)&TPanel::`vftable';
  TPanel::release_mouse(this);
  if( v1->panelNameValue && TPanelSystem::inSystem(&panel_system, v1) )
  {
    v2 = TPanel::panelName(v1);
    TPanelSystem::removePanel(&panel_system, v2);
  }
  if( v1->node )
  {
    v3 = v1->parent_panel;
    if( v3 )
      TPanel::remove_panel_node(v3, v1->node);
    free(v1->node);
    v1->node = 0;
  }
  v4 = v1->clip_rgn;
  v1->first_child_node = 0;
  if( v4 )
  {
    DeleteObject(v4);
    v1->clip_rgn = 0;
  }
  v5 = v1->parent_panel;
  if( v5 )
    ((void (__stdcall *)(signed int))v5->vfptr->set_redraw)(2);
  v6 = v1->panelNameValue;
  if( v6 )
    free(v6);
}
// 570C38: using guessed type int (__thiscall *TPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (00464A80) --------------------------------------------------------
int __thiscall TPanel::setup(TPanel *this, TDrawArea *render_area_in, TPanel *parent_panel_in, int x_in, int y_in, int wid_in, int hgt_in, int color_in)
{
  TPanel *v8; // esi@1
  TPanel::PositionMode v9; // ecx@1
  TPanelVtbl *v10; // edi@3
  PanelNode *v11; // eax@6
  PanelNode *v12; // eax@7
  TPanel *v14; // ecx@9

  v8 = this;
  this->parent_panel = parent_panel_in;
  v9 = this->position_mode;
  v8->render_area = render_area_in;
  if( v9 == PositionFixed )
  {
    v8->top_border = y_in;
    v8->min_wid = wid_in;
    v8->max_wid = wid_in;
    v8->left_border = x_in;
    v8->right_border = 0;
    v8->bottom_border = 0;
    v8->min_hgt = hgt_in;
    v8->max_hgt = hgt_in;
  }
  v10 = v8->vfptr;
  if( render_area_in )
    v10->handle_size(v8, render_area_in->Width, render_area_in->Height);
  else
    v10->handle_size(v8, 0, 0);
  (*(void (__thiscall **)(TPanel *, int))&v10->gap10[0])(v8, color_in);
  v11 = v8->node;
  v8->mouse_captured = 0;
  if( !v11 )
  {
    v12 = (PanelNode *)calloc(1u, 0xCu);
    v8->node = v12;
    if( !v12 )
      return 0;
    v12->panel = v8;
    v8->node->prev_node = 0;
    v8->node->next_node = 0;
    v14 = v8->parent_panel;
    if( v14 )
      TPanel::add_panel_node(v14, v8->node, 0, 0);
  }
  return 1;
}

//----- (00464B50) --------------------------------------------------------
void __thiscall TPanel::add_panel_node(TPanel *this, PanelNode *node_in, PanelNode *by_node, int add_after)
{
  PanelNode *v4; // edx@2
  PanelNode *v5; // eax@3
  PanelNode *i; // eax@4
  PanelNode *v7; // edx@8
  PanelNode *v8; // edi@10
  PanelNode *v9; // edx@10

  if( by_node )
  {
    v5 = node_in;
    if( add_after )
    {
      node_in->prev_node = by_node;
      node_in->next_node = by_node->next_node;
      by_node->next_node = node_in;
      v7 = node_in->next_node;
      if( v7 )
        v7->prev_node = node_in;
    }
    else
    {
      v8 = by_node->prev_node;
      node_in->next_node = by_node;
      node_in->prev_node = v8;
      by_node->prev_node = node_in;
      v9 = node_in->prev_node;
      if( v9 )
        v9->next_node = node_in;
    }
  }
  else
  {
    v4 = this->first_child_node;
    if( v4 )
    {
      for( i = v4->next_node; i; i = i->next_node )
        v4 = i;
      v5 = node_in;
      v4->next_node = node_in;
      node_in->prev_node = v4;
      node_in->next_node = 0;
    }
    else
    {
      v5 = node_in;
      node_in->prev_node = 0;
      node_in->next_node = 0;
    }
  }
  if( !v5->prev_node )
    this->first_child_node = v5;
  if( !v5->next_node )
    this->last_child_node = v5;
}

//----- (00464BF0) --------------------------------------------------------
void __thiscall TPanel::remove_panel_node(TPanel *this, PanelNode *node_in)
{
  PanelNode *v2; // edx@5
  PanelNode *v3; // edx@7
  TPanel *v4; // edi@9

  if( node_in == this->first_child_node )
    this->first_child_node = node_in->next_node;
  if( node_in == this->last_child_node )
    this->last_child_node = node_in->prev_node;
  v2 = node_in->prev_node;
  if( v2 )
    v2->next_node = node_in->next_node;
  v3 = node_in->next_node;
  if( v3 )
    v3->prev_node = node_in->prev_node;
  v4 = node_in->panel;
  node_in->prev_node = 0;
  node_in->next_node = 0;
  if( this->curr_child == v4 )
    this->curr_child = 0;
}

//----- (00464C50) --------------------------------------------------------
void __thiscall TPanel::set_rect(TPanel *this, int x_in, int y_in, int wid_in, int hgt_in)
{
  TPanel *v5; // esi@1
  TPanel *v6; // edx@1
  int v7; // edi@1
  int v8; // ebp@1
  int v9; // ebx@3
  int v10; // eax@5
  int v11; // eax@7
  int v12; // edx@9
  TDrawArea *v13; // eax@15
  int v14; // ecx@16
  int v15; // eax@19
  int v16; // edx@23
  int v17; // edi@23
  int v18; // ecx@24
  int v19; // ST0C_4@25

  v5 = this;
  v6 = this->parent_panel;
  this->pnl_wid = wid_in;
  this->pnl_hgt = hgt_in;
  v7 = wid_in + x_in - 1;
  v8 = hgt_in + y_in - 1;
  this->pnl_x = x_in;
  this->pnl_y = y_in;
  this->render_rect.left = x_in;
  this->render_rect.top = y_in;
  this->render_rect.right = v7;
  this->render_rect.bottom = v8;
  this->clip_rect.left = x_in;
  this->clip_rect.top = y_in;
  this->clip_rect.right = v7;
  this->clip_rect.bottom = v8;
  if( v6 && this->clip_to_parent )
  {
    v9 = v6->clip_rect.left;
    if( x_in < v9 )
      this->clip_rect.left = v9;
    v10 = v6->clip_rect.top;
    if( y_in < v10 )
      this->clip_rect.top = v10;
    v11 = v6->clip_rect.right;
    if( v7 > v11 )
      this->clip_rect.right = v11;
    v12 = v6->clip_rect.bottom;
    if( v8 > v12 )
      this->clip_rect.bottom = v12;
  }
  if( this->clip_rect.left < 0 )
    this->clip_rect.left = 0;
  if( this->clip_rect.top < 0 )
    this->clip_rect.top = 0;
  v13 = this->render_area;
  if( v13 )
  {
    v14 = v13->Width;
    if( v5->clip_rect.right >= v14 )
      v5->clip_rect.right = v14 - 1;
    if( v13 )
    {
      v15 = v13->Height;
      if( v5->clip_rect.bottom >= v15 )
        v5->clip_rect.bottom = v15 - 1;
    }
  }
  if( v5->clip_rgn )
  {
    DeleteObject(v5->clip_rgn);
    v5->clip_rgn = 0;
  }
  v16 = v5->clip_rect.right;
  v17 = v5->clip_rect.left;
  if( v16 < v17 || (v18 = v5->clip_rect.top, v5->clip_rect.bottom < v18) )
  {
    v5->visible = 0;
  }
  else
  {
    v19 = v5->clip_rect.bottom;
    v5->visible = 1;
    v5->clip_rgn = CreateRectRgn(v17, v18, v16, v19);
  }
  if( v5->active )
    v5->vfptr->set_redraw(v5, RedrawFull);
}

//----- (00464D70) --------------------------------------------------------
void __thiscall TPanel::set_rect(TPanel *this, tagRECT rect_in)
{
  ((void (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->vfptr->set_rect)(
    rect_in.left,
    rect_in.top,
    rect_in.right - rect_in.left + 1,
    rect_in.bottom - rect_in.top + 1);
}

//----- (00464DA0) --------------------------------------------------------
void __thiscall TPanel::set_color(TPanel *this, char color_in)
{
  this->color = color_in;
  if( this->active )
    ((void (__stdcall *)(_DWORD))this->vfptr->set_redraw)(2);
}

//----- (00464DC0) --------------------------------------------------------
void __thiscall TPanel::set_active(TPanel *this, int active_in)
{
  TPanel *v2; // esi@1
  TPanel *v3; // ecx@4

  v2 = this;
  if( this->active != active_in )
  {
    this->active = active_in;
    if( active_in )
    {
      ((void (__stdcall *)(_DWORD))this->vfptr->set_redraw)(1);
    }
    else
    {
      TPanel::release_mouse(this);
      v3 = v2->parent_panel;
      if( v3 )
        ((void (__stdcall *)(signed int))v3->vfptr->set_redraw)(1);
    }
  }
}

//----- (00464E00) --------------------------------------------------------
void __thiscall TPanel::set_positioning(TPanel *this, TPanel::PositionMode position_mode_in, int left_border_in, int top_border_in, int right_border_in, int bottom_border_in, int min_wid_in, int max_wid_in, int min_hgt_in, int max_hgt_in, TPanel *left_panel_in, TPanel *top_panel_in, TPanel *right_panel_in, TPanel *bottom_panel_in)
{
  TPanel *v14; // esi@1
  TPanelVtbl *v15; // edi@1
  TDrawArea *v16; // eax@1

  v14 = this;
  this->position_mode = position_mode_in;
  this->right_border = right_border_in;
  this->max_wid = max_wid_in;
  this->left_border = left_border_in;
  this->top_border = top_border_in;
  v15 = this->vfptr;
  this->left_panel = left_panel_in;
  this->bottom_border = bottom_border_in;
  this->min_wid = min_wid_in;
  this->bottom_panel = bottom_panel_in;
  v16 = this->render_area;
  this->min_hgt = min_hgt_in;
  this->max_hgt = max_hgt_in;
  this->top_panel = top_panel_in;
  this->right_panel = right_panel_in;
  if( v16 )
    v15->handle_size(this, v16->Width, v16->Height);
  else
    v15->handle_size(this, 0, 0);
  if( v14->active )
    v15->set_redraw(v14, RedrawFull);
}

//----- (00464EB0) --------------------------------------------------------
void __thiscall TPanel::set_fixed_position(TPanel *this, int left_border_in, int top_border_in, int wid_in, int hgt_in)
{
  (*(void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&this->vfptr->gap10[8])(
    0,
    left_border_in,
    top_border_in,
    0,
    0,
    wid_in,
    wid_in,
    hgt_in,
    hgt_in,
    0,
    0,
    0,
    0);
}

//----- (00464EE0) --------------------------------------------------------
void __thiscall TPanel::set_redraw(TPanel *this, TPanel::RedrawMode redraw_mode)
{
  TDrawArea *v2; // eax@4

  if( redraw_mode != 1 || this->need_redraw != 2 )
  {
    this->need_redraw = redraw_mode;
    if( redraw_mode )
    {
      v2 = this->render_area;
      if( v2 )
      {
        if( this->visible )
        {
          if( this->active )
            InvalidateRect(v2->Wnd, &this->clip_rect, 0);
        }
      }
    }
  }
}

//----- (00464F20) --------------------------------------------------------
void __thiscall TPanel::set_overlapped_redraw(TPanel *this, TPanel *redraw_panel, TPanel *calling_panel, TPanel::RedrawMode redraw_mode)
{
  TPanel *v4; // eax@1
  int v5; // ebx@1
  int v6; // ebp@1
  TPanel *v7; // ecx@4
  int v8; // eax@7
  int v9; // esi@7
  int v10; // edx@7
  int v11; // edi@7
  bool v12; // sf@11
  unsigned __int8 v13; // of@11
  PanelNode *temp_node; // [sp+Ch] [bp-14h]@1
  int this_rect_4; // [sp+14h] [bp-Ch]@1
  int this_rect_8; // [sp+18h] [bp-8h]@1
  int this_rect_12; // [sp+1Ch] [bp-4h]@1

  v4 = redraw_panel;
  v5 = redraw_panel->clip_rect.left;
  temp_node = this->first_child_node;
  this_rect_4 = redraw_panel->clip_rect.top;
  v6 = redraw_panel->clip_rect.right;
  this_rect_8 = redraw_panel->clip_rect.right;
  this_rect_12 = redraw_panel->clip_rect.bottom;
  if( temp_node )
  {
    while( 1 )
    {
      v7 = temp_node->panel;
      if( temp_node->panel == v4 || v7 == calling_panel || v7->z_order <= v4->z_order )
        goto LABEL_35;
      v8 = v7->clip_rect.left;
      v9 = v7->clip_rect.top;
      v10 = v7->clip_rect.right;
      v11 = v7->clip_rect.bottom;
      if( v8 >= v5 && v8 <= v6 || v10 >= v5 && v10 <= v6 )
        goto LABEL_38;
      v13 = __OFSUB__(v5, v8);
      v12 = v5 - v8 < 0;
      if( v5 <= v8 )
        goto LABEL_22;
      if( v10 > v6 )
      {
LABEL_38:
        if( v9 >= this_rect_4 && v9 <= this_rect_12
          || v11 >= this_rect_4 && v11 <= this_rect_12
          || v9 < this_rect_4 && v11 > this_rect_12 )
        {
          ((void (__stdcall *)(TPanel::RedrawMode))v7->vfptr->set_redraw)(redraw_mode);
          v6 = this_rect_8;
          goto LABEL_35;
        }
        v6 = this_rect_8;
      }
      v13 = __OFSUB__(v5, v8);
      v12 = v5 - v8 < 0;
LABEL_22:
      if( (!(v12 ^ v13) && v5 <= v10 || v6 >= v8 && v6 <= v10 || v5 < v8 && v6 > v10)
        && (this_rect_4 >= v9 && this_rect_4 <= v11
         || this_rect_12 >= v9 && this_rect_12 <= v11
         || this_rect_4 < v9 && this_rect_12 > v11) )
      {
        ((void (__stdcall *)(_DWORD))v7->vfptr->set_redraw)(redraw_mode);
      }
LABEL_35:
      temp_node = temp_node->next_node;
      if( !temp_node )
        return;
      v4 = redraw_panel;
    }
  }
}

//----- (00465050) --------------------------------------------------------
void __thiscall TPanel::set_any_overlapping_redraw(TPanel *this, TPanel *redraw_panel, TPanel::RedrawMode redraw_mode)
{
  int v3; // ebx@1
  int v4; // ebp@1
  TPanel *v5; // ecx@2
  int v6; // eax@3
  int v7; // esi@3
  int v8; // edx@3
  int v9; // edi@3
  bool v10; // sf@7
  unsigned __int8 v11; // of@7
  PanelNode *temp_node; // [sp+8h] [bp-14h]@1
  int this_rect_4; // [sp+10h] [bp-Ch]@1
  int this_rect_8; // [sp+14h] [bp-8h]@1
  int this_rect_12; // [sp+18h] [bp-4h]@1

  temp_node = this->first_child_node;
  v3 = redraw_panel->clip_rect.left;
  this_rect_4 = redraw_panel->clip_rect.top;
  v4 = redraw_panel->clip_rect.right;
  this_rect_8 = redraw_panel->clip_rect.right;
  this_rect_12 = redraw_panel->clip_rect.bottom;
  while( temp_node )
  {
    v5 = temp_node->panel;
    if( temp_node->panel != redraw_panel )
    {
      v6 = v5->clip_rect.left;
      v7 = v5->clip_rect.top;
      v8 = v5->clip_rect.right;
      v9 = v5->clip_rect.bottom;
      if( (v6 < v3 || v6 > v4) && (v8 < v3 || v8 > v4) )
      {
        v11 = __OFSUB__(v3, v6);
        v10 = v3 - v6 < 0;
        if( v3 <= v6 )
          goto LABEL_18;
        if( v8 <= v4 )
          goto LABEL_17;
      }
      if( (v7 < this_rect_4 || v7 > this_rect_12)
        && (v9 < this_rect_4 || v9 > this_rect_12)
        && (v7 >= this_rect_4 || v9 <= this_rect_12) )
      {
        v4 = this_rect_8;
LABEL_17:
        v11 = __OFSUB__(v3, v6);
        v10 = v3 - v6 < 0;
LABEL_18:
        if( (!(v10 ^ v11) && v3 <= v8 || v4 >= v6 && v4 <= v8 || v3 < v6 && v4 > v8)
          && (this_rect_4 >= v7 && this_rect_4 <= v9
           || this_rect_12 >= v7 && this_rect_12 <= v9
           || this_rect_4 < v7 && this_rect_12 > v9) )
        {
          ((void (__stdcall *)(TPanel::RedrawMode))v5->vfptr->set_redraw)(redraw_mode);
        }
        goto LABEL_31;
      }
      ((void (__stdcall *)(_DWORD))v5->vfptr->set_redraw)(redraw_mode);
      v4 = this_rect_8;
    }
LABEL_31:
    temp_node = temp_node->next_node;
  }
}

//----- (00465160) --------------------------------------------------------
void __thiscall TPanel::draw(TPanel *this)
{
  TPanel *v1; // eax@1
  TDrawArea *v2; // edx@1
  TPanel *v3; // ecx@5
  TPanelVtbl *v4; // edx@6

  v1 = this;
  v2 = this->render_area;
  this->need_redraw = 0;
  if( v2 && this->visible && this->active )
  {
    if( this->fill_in_background || (v3 = this->parent_panel) == 0 )
    {
      TDrawArea::Clear(v2, &v1->clip_rect, v1->color);
    }
    else
    {
      v4 = v3->vfptr;
      if( v1->draw_rect2_flag )
        ((void (__stdcall *)(int))v4->draw_rect2)((int)&v1->clip_rect);
      else
        ((void (__stdcall *)(int))v4->draw_rect)((int)&v1->clip_rect);
    }
  }
}

//----- (004651C0) --------------------------------------------------------
void __thiscall TPanel::draw_rect(TPanel *this, tagRECT *rect)
{
  char *v2; // esi@1
  int v3; // edi@1
  int v4; // ebx@1
  int save_rect_8; // ST18_4@1
  int save_rect_12; // ST1C_4@1

  v2 = (char *)&this->clip_rect;
  v3 = this->clip_rect.left;
  v4 = this->clip_rect.top;
  save_rect_8 = this->clip_rect.right;
  save_rect_12 = this->clip_rect.bottom;
  this->clip_rect = *rect;
  ((void (*)(void))this->vfptr->draw)();
  *(_DWORD *)v2 = v3;
  *((_DWORD *)v2 + 1) = v4;
  *((_DWORD *)v2 + 2) = save_rect_8;
  *((_DWORD *)v2 + 3) = save_rect_12;
}

//----- (00465220) --------------------------------------------------------
void __thiscall TPanel::draw_offset(TPanel *this, int x_offset, int y_offset, tagRECT *rect)
{
  TPanel *v4; // esi@1
  int v5; // edx@1
  tagRECT *v6; // edi@1
  int save_rect; // ST10_4@1
  int save_rect_4; // ST14_4@1
  int save_rect_8; // ST18_4@1
  int save_rect_12; // ST1C_4@1
  int v11; // ecx@1
  int v12; // eax@1

  v4 = this;
  v5 = this->pnl_y;
  this->pnl_x += x_offset;
  this->pnl_y = y_offset + v5;
  save_rect = this->clip_rect.left;
  save_rect_4 = this->clip_rect.top;
  save_rect_8 = this->clip_rect.right;
  v6 = &this->clip_rect;
  save_rect_12 = this->clip_rect.bottom;
  *v6 = *rect;
  ((void (*)(void))this->vfptr->draw)();
  v6->left = save_rect;
  v6->top = save_rect_4;
  v11 = v4->pnl_x;
  v6->right = save_rect_8;
  v6->bottom = save_rect_12;
  v12 = v4->pnl_y - y_offset;
  v4->pnl_x = v11 - x_offset;
  v4->pnl_y = v12;
}

//----- (004652C0) --------------------------------------------------------
void __thiscall TPanel::draw_rect2(TPanel *this, tagRECT *rect)
{
  TPanel *v2; // esi@1
  TPanelVtbl *v3; // eax@1

  v2 = this;
  v3 = this->vfptr;
  this->draw_rect2_flag = 1;
  ((void (__stdcall *)(tagRECT *))v3->draw_rect)(rect);
  v2->draw_rect2_flag = 0;
}

//----- (004652F0) --------------------------------------------------------
void __thiscall TPanel::draw_offset2(TPanel *this, int x_offset, int y_offset, tagRECT *rect)
{
  TPanel *v4; // esi@1
  TPanelVtbl *v5; // eax@1

  v4 = this;
  v5 = this->vfptr;
  this->draw_rect2_flag = 1;
  ((void (__stdcall *)(int, int, tagRECT *))v5->draw_offset)(x_offset, y_offset, rect);
  v4->draw_rect2_flag = 0;
}

//----- (00465320) --------------------------------------------------------
void __thiscall TPanel::draw_setup(TPanel *this, int clear)
{
  TPanel *v2; // esi@1
  void *v3; // eax@1

  v2 = this;
  v3 = this->render_area->DrawDc;
  if( v3 )
    SelectClipRgn(v3, this->clip_rgn);
  TDrawArea::SetClipRect(v2->render_area, &v2->clip_rect);
  if( clear )
    TDrawArea::Clear(v2->render_area, &v2->clip_rect, v2->color);
}

//----- (00465370) --------------------------------------------------------
void __thiscall TPanel::draw_finish(TPanel *this)
{
  TPanel *v1; // esi@1
  TDrawArea *v2; // eax@1
  void *v3; // eax@1

  v1 = this;
  v2 = this->render_area;
  this->need_redraw = 0;
  v3 = v2->DrawDc;
  if( v3 )
    SelectClipRgn(v3, 0);
  TDrawArea::SetClipRect(v1->render_area, 0);
  v1->need_restore = 0;
}

//----- (004653A0) --------------------------------------------------------
void __thiscall TPanel::paint(TPanel *this)
{
  TPanel *v1; // esi@1
  TDrawArea *v2; // eax@1

  v1 = this;
  v2 = this->render_area;
  if( v2 && this->visible )
  {
    if( this->active )
    {
      TDrawSystem::Paint(v2->DrawSystem, &this->clip_rect);
      ValidateRect(v1->render_area->Wnd, &v1->clip_rect);
    }
  }
}

//----- (004653E0) --------------------------------------------------------
int __thiscall TPanel::wnd_proc(TPanel *this, void *hwnd, unsigned int msg, unsigned int wParam, int lParam)
{
  unsigned int v5; // ebp@2
  int v6; // ebx@3
  PanelNode *v7; // esi@7
  int v8; // ebx@7
  unsigned int v9; // edi@7
  int result; // eax@8
  TPanel *v11; // ecx@23
  TPanel *v12; // esi@41
  int v13; // ebp@48
  SHORT v14; // ax@48
  TPanelVtbl *v15; // edx@48
  TPanel *v16; // [sp+10h] [bp-Ch]@1
  tagPOINT point; // [sp+14h] [bp-8h]@22

  v16 = this;
  if( !this->active )
    return 0;
  v5 = msg;
  if( msg <= 0x206 )
  {
    v6 = lParam;
    if( msg >= 0x200 )
    {
      if( hwnd == this->render_area->Wnd && TPanelSystem::GetInputEnabled(&panel_system) )
      {
        TPanel::get_mouse_info(wParam, v6, &point, &lParam, (int *)&msg);
        if( TPanelSystem::mouseOwner(&panel_system) )
        {
          v11 = TPanelSystem::mouseOwner(&panel_system);
        }
        else if( TPanelSystem::keyboardOwner(&panel_system) )
        {
          v11 = TPanelSystem::keyboardOwner(&panel_system);
        }
        else if( TPanelSystem::modalPanel(&panel_system) )
        {
          v11 = TPanelSystem::modalPanel(&panel_system);
        }
        else
        {
          v11 = v16;
        }
        switch ( v5 )
        {
          case 0x200u:
            result = ((int (__stdcall *)(int, int, int, unsigned int))v11->vfptr->handle_mouse_move)(
                       point.x,
                       point.y,
                       lParam,
                       msg);
            break;
          case 0x201u:
            result = ((int (__stdcall *)(signed int, int, int, int, unsigned int))v11->vfptr->handle_mouse_down)(
                       1,
                       point.x,
                       point.y,
                       lParam,
                       msg);
            break;
          case 0x202u:
            result = ((int (__stdcall *)(signed int, int, int, int, unsigned int))v11->vfptr->handle_mouse_up)(
                       1,
                       point.x,
                       point.y,
                       lParam,
                       msg);
            break;
          case 0x203u:
            result = ((int (__stdcall *)(signed int, int, int, int, unsigned int))v11->vfptr->handle_mouse_dbl_click)(
                       1,
                       point.x,
                       point.y,
                       lParam,
                       msg);
            break;
          case 0x204u:
            result = ((int (__stdcall *)(signed int, int, int, int, unsigned int))v11->vfptr->handle_mouse_down)(
                       2,
                       point.x,
                       point.y,
                       lParam,
                       msg);
            break;
          case 0x205u:
            result = ((int (__stdcall *)(signed int, int, int, int, unsigned int))v11->vfptr->handle_mouse_up)(
                       2,
                       point.x,
                       point.y,
                       lParam,
                       msg);
            break;
          case 0x206u:
            result = ((int (__stdcall *)(signed int, int, int, int, unsigned int))v11->vfptr->handle_mouse_dbl_click)(
                       2,
                       point.x,
                       point.y,
                       lParam,
                       msg);
            break;
          default:
            this = v16;
            goto LABEL_38;
        }
        return result;
      }
    }
    else
    {
      if( msg != 256 && msg != 258 && msg != 260 )
        goto LABEL_7;
LABEL_38:
      if( hwnd == this->render_area->Wnd && TPanelSystem::GetInputEnabled(&panel_system) )
      {
        if( TPanelSystem::keyboardOwner(&panel_system) )
        {
          v12 = TPanelSystem::keyboardOwner(&panel_system);
        }
        else if( TPanelSystem::modalPanel(&panel_system) )
        {
          v12 = TPanelSystem::modalPanel(&panel_system);
        }
        else
        {
          v12 = v16;
        }
        if( v5 == 256 || v5 == 260 )
        {
          v13 = GetKeyState(18) < 0;
          lParam = GetKeyState(17) < 0;
          v14 = GetKeyState(16);
          v15 = v12->vfptr;
          msg = v14 < 0;
          result = v15->handle_key_down(v12, wParam, v6, v13, lParam, msg);
        }
        else
        {
          result = v12->vfptr->handle_char(v12, wParam, v6);
        }
        return result;
      }
    }
    return 0;
  }
LABEL_7:
  v7 = this->last_child_node;
  v8 = lParam;
  v9 = wParam;
  if( !v7 )
  {
LABEL_11:
    if( v5 <= 0x400 )
    {
      if( v5 == 1024 )
      {
        result = ((int (__stdcall *)(unsigned int, int))this->vfptr->handle_user_command)(v9, v8);
      }
      else
      {
        switch ( v5 )
        {
          case 0x111u:
            result = ((int (__stdcall *)(unsigned int, int))this->vfptr->handle_command)(v9, v8);
            break;
          case 0x113u:
            result = ((int (__stdcall *)(unsigned int, int))this->vfptr->handle_timer_command)(v9, v8);
            break;
          case 0x114u:
          case 0x115u:
            result = ((int (__stdcall *)(_DWORD, unsigned int))this->vfptr->handle_scroll)(
                       (unsigned __int16)v9,
                       v9 >> 16);
            break;
          default:
            return 0;
        }
      }
      return result;
    }
    return 0;
  }
  while( 1 )
  {
    result = ((int (__stdcall *)(void *, unsigned int, unsigned int, int))v7->panel->vfptr->wnd_proc)(hwnd, v5, v9, v8);
    if( result )
      return result;
    v7 = v7->prev_node;
    if( !v7 )
    {
      this = v16;
      goto LABEL_11;
    }
  }
}

//----- (00465780) --------------------------------------------------------
int __thiscall TPanel::handle_idle(TPanel *this)
{
  TPanel *v1; // esi@1
  int v2; // edx@4
  bool v3; // zf@4
  TPanelVtbl *v4; // eax@4
  PanelNode *v5; // esi@7
  int result; // eax@8
  int v7; // [sp-Ch] [bp-10h]@4
  int v8; // [sp-8h] [bp-Ch]@4
  int v9; // [sp-4h] [bp-8h]@4

  v1 = this;
  if( this->active
    && this->mouse_action == 1
    && (signed int)(debug_timeGetTime() - this->mouse_down_time) >= this->mouse_hold_interval )
  {
    v9 = v1->mouse_down_shift;
    v8 = v1->mouse_down_ctrl;
    v2 = v1->mouse_down_x;
    v3 = v1->mouse_down_button == 1;
    v4 = v1->vfptr;
    v7 = v1->mouse_down_y;
    v1->mouse_action = 2;
    if( v3 )
      v4->mouse_left_hold_action(v1, v2, v7, v8, v9);
    else
      v4->mouse_right_hold_action(v1, v2, v7, v8, v9);
  }
  v5 = v1->last_child_node;
  if( v5 )
  {
    while( 1 )
    {
      result = ((int (*)(void))v5->panel->vfptr->handle_idle)();
      if( result )
        break;
      v5 = v5->prev_node;
      if( !v5 )
        goto LABEL_10;
    }
  }
  else
  {
LABEL_10:
    result = 0;
  }
  return result;
}

//----- (00465820) --------------------------------------------------------
int __thiscall TPanel::handle_size(TPanel *this, int win_wid, int win_hgt)
{
  TPanel *v3; // ebx@1
  TPanel *v4; // eax@1
  int v5; // edi@2
  int v6; // edx@2
  int v7; // ebp@2
  int v8; // ecx@2
  signed int v9; // ecx@5
  int v10; // esi@5
  int v11; // eax@5
  int v12; // edi@5
  TPanel *v13; // eax@6
  TPanel *v14; // eax@10
  TPanel *v15; // edx@14
  TPanel *v16; // edx@18
  int v17; // ecx@20
  int v18; // edx@22
  int v19; // ebp@22
  TPanel::PositionMode v20; // edx@26
  int v21; // edx@31
  TPanel::PositionMode v22; // ebp@35
  signed int v23; // edi@41
  TPanelVtbl *v24; // edx@48
  PanelNode *v25; // esi@49
  TPanel *v26; // ecx@50
  int result; // eax@50
  bool v28; // sf@52
  unsigned __int8 v29; // of@52
  int v30; // [sp-8h] [bp-24h]@48
  int v31; // [sp-4h] [bp-20h]@48
  int v32; // [sp+0h] [bp-1Ch]@48
  int v33; // [sp+4h] [bp-18h]@48
  int calc_hgt; // [sp+18h] [bp-4h]@22

  v3 = this;
  v4 = this->parent_panel;
  if( v4 )
  {
    v5 = v4->render_rect.right;
    v6 = v4->render_rect.left;
    v7 = v4->render_rect.top;
    v8 = v4->render_rect.bottom;
    win_wid = v4->render_rect.right - v6 + 1;
    win_hgt = v8 - v7 + 1;
  }
  else
  {
    v6 = 0;
    v7 = 0;
    v5 = win_wid - 1;
    v8 = win_hgt - 1;
  }
  if( v3->position_mode == PositionFixed )
  {
    v9 = v3->min_hgt;
    v10 = v6 + v3->left_border;
    v11 = v7 + v3->top_border;
    v12 = v3->min_wid + v10 - 1;
LABEL_47:
    v17 = v9 + v11 - 1;
    goto LABEL_48;
  }
  v13 = v3->left_panel;
  if( v13 && v13->active )
    v10 = v3->left_border + v13->render_rect.right + 1;
  else
    v10 = v6 + v3->left_border;
  v14 = v3->top_panel;
  if( v14 && v14->active )
    v11 = v3->top_border + v14->render_rect.bottom + 1;
  else
    v11 = v7 + v3->top_border;
  v15 = v3->right_panel;
  if( v15 && v15->active )
    v12 = v15->render_rect.left - v3->right_border - 1;
  else
    v12 = v5 - v3->right_border;
  v16 = v3->bottom_panel;
  if( v16 && v16->active )
    v17 = v16->render_rect.top - v3->bottom_border - 1;
  else
    v17 = v8 - v3->bottom_border;
  v18 = v12 - v10 + 1;
  calc_hgt = v17 - v11 + 1;
  v19 = v3->min_wid;
  if( v19 && v18 < v19 )
    goto LABEL_30;
  v19 = v3->max_wid;
  if( v19 && v18 > v19 )
  {
    v20 = v3->position_mode;
    if( v20 != 3 && v20 != 7 && v20 != 8 )
    {
      v10 = v12 - v19 + 1;
      goto LABEL_31;
    }
LABEL_30:
    v12 = v10 + v19 - 1;
  }
LABEL_31:
  v21 = v3->min_hgt;
  if( v21 && calc_hgt < v21 )
  {
LABEL_39:
    v17 = v11 + v21 - 1;
    goto LABEL_40;
  }
  v21 = v3->max_hgt;
  if( v21 && calc_hgt > v21 )
  {
    v22 = v3->position_mode;
    if( v22 != 4 && v22 != 7 && v22 != 9 )
    {
      v11 = v17 - v21 + 1;
      goto LABEL_40;
    }
    goto LABEL_39;
  }
LABEL_40:
  if( v3->position_mode == 2 )
  {
    v23 = v12 - v10 + 1;
    v9 = v17 - v11 + 1;
    if( v23 == win_wid )
      v10 = 0;
    else
      v10 = win_wid / 2 - v23 / 2;
    v12 = v23 + v10 - 1;
    if( v9 == win_hgt )
    {
      v11 = 0;
    }
    else
    {
      calc_hgt = v9 / 2;
      v11 = win_hgt / 2 - v9 / 2;
    }
    goto LABEL_47;
  }
LABEL_48:
  v24 = v3->vfptr;
  v30 = v10;
  v31 = v11;
  v32 = v12;
  v33 = v17;
  (*(void (__thiscall **)(TPanel *, int, int, int, int))&v24->gap4[4])(v3, v10, v11, v12, v17);
  calc_hgt = 0;
  while( 1 )
  {
    v25 = v3->first_child_node;
    if( v25 )
      break;
LABEL_52:
    v29 = __OFSUB__(calc_hgt + 1, 2);
    v28 = calc_hgt++ - 1 < 0;
    if( !(v28 ^ v29) )
      return 0;
  }
  while( 1 )
  {
    v26 = v25->panel;
    v33 = win_hgt;
    v32 = win_wid;
    result = ((int (__stdcall *)(int, int))v26->vfptr->handle_size)(win_wid, win_hgt);
    if( result )
      return result;
    v25 = v25->next_node;
    if( !v25 )
      goto LABEL_52;
  }
}

//----- (00465A70) --------------------------------------------------------
int __thiscall TPanel::handle_paint(TPanel *this)
{
  TPanel *v1; // edi@1
  TDrawArea *v2; // eax@1
  PanelNode *i; // esi@7
  TPanel *v4; // ecx@9
  PanelNode *j; // esi@13

  v1 = this;
  v2 = this->render_area;
  if( v2 && this->visible && this->active && rge_base_game->prog_active && !IsIconic(v2->Wnd) )
  {
    if( v1->need_redraw )
    {
      for( i = v1->first_child_node; i; i = i->next_node )
        ((void (__stdcall *)(TPanel::RedrawMode))i->panel->vfptr->set_redraw)(v1->need_redraw);
      v4 = v1->parent_panel;
      if( v4 && v4->overlapping_children )
        ((void (__stdcall *)(TPanel *, TPanel *, TPanel::RedrawMode))v4->vfptr->set_overlapped_redraw)(
          v1,
          v1,
          v1->need_redraw);
      v1->vfptr->draw(v1);
      v1->need_redraw = 0;
      v1->just_drawn = 1;
    }
    for( j = v1->first_child_node; j; j = j->next_node )
      ((void (*)(void))j->panel->vfptr->handle_paint)();
    v1->just_drawn = 0;
  }
  return 0;
}

//----- (00465B30) --------------------------------------------------------
int __thiscall TPanel::handle_key_down(TPanel *this, int key, int count, int alt_key, int ctrl_key, int shift_key)
{
  PanelNode *v6; // esi@2
  int result; // eax@3
  TPanel *v8; // ecx@11
  TPanel *v9; // eax@13
  TPanel *v10; // [sp+28h] [bp-4h]@1

  v10 = this;
  if( !this->have_focus )
    return 0;
  v6 = this->last_child_node;
  if( !v6 )
  {
LABEL_6:
    result = ((int (__stdcall *)(int, int, int, int, int))this->vfptr->key_down_action)(
               key,
               count,
               alt_key,
               ctrl_key,
               shift_key);
    if( result )
      return result;
    if( !alt_key && !ctrl_key && key == 9 )
    {
      if( v10->tab_stop )
      {
        v8 = v10->parent_panel;
        if( v8 )
        {
          v9 = shift_key ? v10->tab_prev_panel : v10->tab_next_panel;
          if( v9 )
          {
            TPanel::set_curr_child(v8, v9);
            return 1;
          }
        }
      }
    }
    return 0;
  }
  while( 1 )
  {
    result = ((int (__stdcall *)(int, int, int, int, int))v6->panel->vfptr->handle_key_down)(
               key,
               count,
               alt_key,
               ctrl_key,
               shift_key);
    if( result )
      return result;
    v6 = v6->prev_node;
    if( !v6 )
    {
      this = v10;
      goto LABEL_6;
    }
  }
}

//----- (00465BE0) --------------------------------------------------------
int __thiscall TPanel::handle_char(TPanel *this, int key, int count)
{
  TPanel *v3; // ebp@1
  int result; // eax@2
  PanelNode *v5; // esi@3

  v3 = this;
  if( this->have_focus )
  {
    v5 = this->last_child_node;
    if( v5 )
    {
      while( 1 )
      {
        result = ((int (__stdcall *)(int, int))v5->panel->vfptr->handle_char)(key, count);
        if( result )
          break;
        v5 = v5->prev_node;
        if( !v5 )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      result = v3->vfptr->char_action(v3, key, count);
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

//----- (00465C30) --------------------------------------------------------
int __stdcall TPanel::handle_command(unsigned int wParam, int lParam)
{
  return 0;
}

//----- (00465C40) --------------------------------------------------------
int __stdcall TPanel::handle_user_command(unsigned int wParam, int lParam)
{
  return 0;
}

//----- (00465C50) --------------------------------------------------------
int __stdcall TPanel::handle_timer_command(unsigned int wParam, int lParam)
{
  return 0;
}

//----- (00465C60) --------------------------------------------------------
int __stdcall TPanel::handle_scroll(int scroll_cmd, int line_num)
{
  return 0;
}

//----- (00465C70) --------------------------------------------------------
int __thiscall TPanel::handle_mouse_down(TPanel *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  TPanel *v6; // esi@1
  int result; // eax@2
  PanelNode *v8; // edi@5
  int v9; // edi@10
  int v10; // eax@10
  TPanel *v11; // ecx@11

  v6 = this;
  if( !this->active )
    return 0;
  if( this->mouse_captured )
  {
    v9 = shift_key;
LABEL_15:
    if( v6->handle_mouse_input )
    {
      if( v6->mouse_down_button == 1 )
      {
        v6->vfptr->mouse_left_down_action(v6, x, y, ctrl_key, v9);
        result = 1;
      }
      else
      {
        v6->vfptr->mouse_right_down_action(v6, x, y, ctrl_key, v9);
        result = 1;
      }
    }
    else
    {
      result = 0;
    }
    return result;
  }
  result = ((int (__stdcall *)(int, int))this->vfptr->is_inside)(x, y);
  if( !result )
    return result;
  v8 = v6->last_child_node;
  if( !v8 )
  {
LABEL_8:
    if( !v6->handle_mouse_input )
      return 0;
    v9 = shift_key;
    v6->mouse_down_button = mouse_button_in;
    v6->mouse_down_x = x;
    v6->mouse_down_y = y;
    v6->mouse_down_ctrl = ctrl_key;
    v6->mouse_down_shift = shift_key;
    v6->mouse_down_time = debug_timeGetTime();
    v10 = v6->tab_stop;
    v6->mouse_action = 1;
    if( v10 )
    {
      v11 = v6->parent_panel;
      if( v11 )
      {
        if( v6->mouse_down_button == 1 )
          TPanel::set_curr_child(v11, v6);
      }
    }
    goto LABEL_15;
  }
  while( 1 )
  {
    result = ((int (__stdcall *)(int, int, int, int, int))v8->panel->vfptr->handle_mouse_down)(
               mouse_button_in,
               x,
               y,
               ctrl_key,
               shift_key);
    if( result )
      return result;
    v8 = v8->prev_node;
    if( !v8 )
      goto LABEL_8;
  }
}

//----- (00465DC0) --------------------------------------------------------
int __thiscall TPanel::handle_mouse_move(TPanel *this, int x, int y, int ctrl_key, int shift_key)
{
  TPanel *v5; // edi@1
  int result; // eax@2
  PanelNode *v7; // esi@5
  char v8; // al@13
  int v9; // ecx@16
  char v10; // al@21
  bool v11; // zf@23
  TPanelVtbl *v12; // eax@23
  TPanelVtbl *v13; // [sp+18h] [bp-4h]@4

  v5 = this;
  if( !this->active )
    return 0;
  if( this->mouse_captured )
  {
    if( !this->handle_mouse_input )
      return 0;
    v8 = this->mouse_action;
    if( v8 == 1 || v8 == 2 )
    {
      if( this->mouse_down_button == 1 )
      {
        v9 = this->mouse_move_tolerance;
        if( abs(x - v5->mouse_down_x) <= v9 && abs(y - v5->mouse_down_y) <= v9 )
          return 1;
      }
      else if( abs(x - this->mouse_down_x) <= 10 && abs(y - this->mouse_down_y) <= 10 )
      {
        return 1;
      }
    }
    v10 = v5->mouse_down_button;
    v5->mouse_action = 3;
    if( v10 == 1 )
    {
      v5->vfptr->mouse_left_move_action(v5, x, y, ctrl_key, shift_key);
      return 1;
    }
    v11 = v10 == 2;
    v12 = v5->vfptr;
    if( v11 )
    {
      v12->mouse_right_move_action(v5, x, y, ctrl_key, shift_key);
      return 1;
    }
    v12->mouse_move_action(v5, x, y, ctrl_key, shift_key);
    return 1;
  }
  v13 = this->vfptr;
  result = ((int (__stdcall *)(int, int))this->vfptr->is_inside)(x, y);
  if( result )
  {
    v7 = v5->last_child_node;
    if( v7 )
    {
      while( 1 )
      {
        result = ((int (__stdcall *)(int, int, int, int))v7->panel->vfptr->handle_mouse_move)(x, y, ctrl_key, shift_key);
        if( result )
          break;
        v7 = v7->prev_node;
        if( !v7 )
          goto LABEL_8;
      }
    }
    else
    {
LABEL_8:
      if( v5->handle_mouse_input )
        result = v13->mouse_move_action(v5, x, y, ctrl_key, shift_key);
      else
        result = 0;
    }
  }
  return result;
}

//----- (00465F70) --------------------------------------------------------
int __thiscall TPanel::handle_mouse_up(TPanel *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  TPanel *v6; // esi@1
  int result; // eax@2
  PanelNode *v8; // esi@5
  TPanelVtbl *v9; // eax@11
  int v10; // eax@12

  v6 = this;
  if( !this->active )
    return 0;
  if( !this->mouse_captured )
  {
    result = ((int (__stdcall *)(int, int))this->vfptr->is_inside)(x, y);
    if( !result )
      return result;
    v8 = v6->last_child_node;
    if( v8 )
    {
      do
      {
        result = ((int (__stdcall *)(int, int, int, int, int))v8->panel->vfptr->handle_mouse_up)(
                   mouse_button_in,
                   x,
                   y,
                   ctrl_key,
                   shift_key);
        if( result )
          break;
        v8 = v8->prev_node;
      }
      while( v8 );
      return result;
    }
    return 0;
  }
  if( !this->handle_mouse_input )
    return 0;
  v9 = this->vfptr;
  if( this->mouse_down_button == 1 )
    v10 = ((int (__stdcall *)(int, int, int, int))v9->mouse_left_up_action)(x, y, ctrl_key, shift_key);
  else
    v10 = ((int (__stdcall *)(int, int, int, int))v9->mouse_right_up_action)(x, y, ctrl_key, shift_key);
  if( v10 )
    return 0;
  if( (_BYTE)mouse_button_in == v6->mouse_down_button )
  {
    v6->mouse_down_button = 0;
    v6->mouse_action = 0;
  }
  return 1;
}

//----- (00466060) --------------------------------------------------------
int __thiscall TPanel::handle_mouse_dbl_click(TPanel *this, int mouse_button_in, int x, int y, int ctrl_key, int shift_key)
{
  TPanel *v6; // esi@1
  int result; // eax@2
  int v8; // ebx@3
  PanelNode *v9; // esi@5
  TPanelVtbl *v10; // eax@11
  TPanel *v11; // [sp+24h] [bp-4h]@1
  int shift_keya; // [sp+3Ch] [bp+14h]@11

  v6 = this;
  v11 = this;
  if( !this->active )
    return 0;
  v8 = shift_key;
  if( this->mouse_captured )
    goto LABEL_9;
  result = ((int (__stdcall *)(int, int))this->vfptr->is_inside)(x, y);
  if( !result )
    return result;
  v9 = v6->last_child_node;
  if( !v9 )
  {
LABEL_8:
    v6 = v11;
LABEL_9:
    if( v6->handle_mouse_input )
    {
      v10 = v6->vfptr;
      shift_keya = (int)v6->vfptr;
      if( (_BYTE)mouse_button_in == 1 )
        result = v10->mouse_left_dbl_click_action(v6, x, y, ctrl_key, v8);
      else
        result = v10->mouse_right_dbl_click_action(v6, x, y, ctrl_key, v8);
      if( !result )
      {
        (*(void (__thiscall **)(TPanel *, int, int, int, int, int))(shift_keya + 112))(
          v6,
          mouse_button_in,
          x,
          y,
          ctrl_key,
          v8);
        result = 1;
      }
    }
    else
    {
      result = 0;
    }
    return result;
  }
  while( 1 )
  {
    result = ((int (__stdcall *)(int, int, int, int, int))v9->panel->vfptr->handle_mouse_dbl_click)(
               mouse_button_in,
               x,
               y,
               ctrl_key,
               shift_key);
    if( result )
      return result;
    v9 = v9->prev_node;
    if( !v9 )
      goto LABEL_8;
  }
}

//----- (00466140) --------------------------------------------------------
int __thiscall TPanel::action(TPanel *this, TPanel *from_panel, int action_in, unsigned int action_val1, unsigned int action_val2)
{
  TPanel *v5; // ecx@1
  int result; // eax@2

  v5 = this->parent_panel;
  if( v5 )
    result = ((int (__stdcall *)(TPanel *, int, unsigned int, unsigned int))v5->vfptr->action)(
               from_panel,
               action_in,
               action_val1,
               action_val2);
  else
    result = 0;
  return result;
}

//----- (00466170) --------------------------------------------------------
void __stdcall TPanel::get_mouse_info(unsigned int wParam, int lParam, tagPOINT *point, int *ctrl_key, int *shift_key)
{
  signed int v6; // ecx@1

  v6 = (unsigned int)lParam >> 16;
  point->x = (unsigned __int16)lParam;
  point->y = (unsigned int)lParam >> 16;
  if( (signed int)(unsigned __int16)lParam > 60000 )
    point->x = (unsigned __int16)lParam - 0x10000;
  if( v6 > 60000 )
    point->y = v6 - 0x10000;
  *ctrl_key = wParam & 8;
  *shift_key = wParam & 4;
}

//----- (004661D0) --------------------------------------------------------
void __thiscall TPanel::get_mouse_pos(TPanel *this, tagPOINT *point)
{
  TPanel *v2; // edi@1
  TDrawArea *v3; // eax@1
  int v4; // eax@4

  v2 = this;
  GetCursorPos(point);
  v3 = v2->render_area;
  if( v3->DrawSystem->ScreenMode != 2 )
  {
    ScreenToClient(v3->Wnd, point);
    if( point->x > 60000 )
      point->x -= 0x10000;
    v4 = point->y;
    if( v4 > 60000 )
      point->y = v4 - 0x10000;
  }
}

//----- (00466220) --------------------------------------------------------
int __thiscall TPanel::capture_mouse(TPanel *this)
{
  TPanel *v1; // esi@1
  int result; // eax@3

  v1 = this;
  if( TPanelSystem::mouseOwner(&panel_system) && TPanelSystem::mouseOwner(&panel_system) != v1 )
  {
    result = 0;
  }
  else if( TPanelSystem::mouseOwner(&panel_system) == v1 )
  {
    result = 1;
  }
  else
  {
    SetCapture(v1->render_area->Wnd);
    TPanelSystem::setMouseOwner(&panel_system, v1);
    result = 1;
    v1->mouse_captured = 1;
  }
  return result;
}

//----- (00466280) --------------------------------------------------------
void __thiscall TPanel::release_mouse(TPanel *this)
{
  TPanel *v1; // esi@1

  v1 = this;
  if( this->mouse_captured )
  {
    if( TPanelSystem::mouseOwner(&panel_system) == this )
    {
      TPanelSystem::setMouseOwner(&panel_system, 0);
      ReleaseCapture();
    }
    v1->mouse_captured = 0;
  }
}

//----- (004662C0) --------------------------------------------------------
char __thiscall TPanel::is_redraw_needed(TPanel *this)
{
  char result; // al@4

  if( this->render_area && this->visible && this->active )
    result = this->need_redraw;
  else
    result = 0;
  return result;
}

//----- (004662E0) --------------------------------------------------------
BOOL __thiscall TPanel::is_inside(TPanel *this, int x, int y)
{
  return this->active
      && x >= this->clip_rect.left
      && x <= this->clip_rect.right
      && y >= this->clip_rect.top
      && y <= this->clip_rect.bottom;
}

//----- (00466320) --------------------------------------------------------
BOOL __stdcall TPanel::is_inside_rect(int x, int y, tagRECT *rect)
{
  return x >= rect->left && x <= rect->right && y >= rect->top && y <= rect->bottom;
}

//----- (00466350) --------------------------------------------------------
int __thiscall TPanel::bound_point(TPanel *this, int *x, int *y)
{
  int result; // eax@1
  int v4; // edx@1
  int v5; // edx@4
  int v6; // ecx@6

  result = 0;
  v4 = this->clip_rect.left + 1;
  if( *x < v4 || (v4 = this->clip_rect.right - 1, *x > v4) )
  {
    *x = v4;
    result = 1;
  }
  v5 = this->clip_rect.top + 1;
  if( *y >= v5 )
  {
    v6 = this->clip_rect.bottom - 1;
    if( *y > v6 )
    {
      *y = v6;
      result = 1;
    }
  }
  else
  {
    *y = v5;
    result = 1;
  }
  return result;
}

//----- (004663A0) --------------------------------------------------------
void __thiscall TPanel::set_curr_child(TPanel *this, TPanel *curr_child_in)
{
  TPanel *v2; // esi@1
  TPanel *v3; // ecx@1

  v2 = this;
  v3 = this->curr_child;
  if( curr_child_in != v3 )
  {
    if( v3 && v2->have_focus )
      ((void (__stdcall *)(_DWORD))v3->vfptr->set_focus)(0);
    v2->curr_child = curr_child_in;
    if( curr_child_in )
    {
      if( v2->have_focus )
        curr_child_in->vfptr->set_focus(curr_child_in, 1);
    }
  }
}

//----- (004663F0) --------------------------------------------------------
void __thiscall TPanel::set_focus(TPanel *this, int have_focus_in)
{
  TPanel *v2; // esi@1
  TPanel *v3; // ecx@2

  v2 = this;
  if( have_focus_in != this->have_focus )
  {
    this->have_focus = have_focus_in;
    ((void (__stdcall *)(_DWORD))this->vfptr->set_redraw)(1);
    v3 = v2->curr_child;
    if( v3 )
      ((void (__stdcall *)(int))v3->vfptr->set_focus)(v2->have_focus);
  }
}

//----- (00466420) --------------------------------------------------------
int __thiscall TPanel::get_focus(TPanel *this)
{
  return this->have_focus;
}

//----- (00466430) --------------------------------------------------------
void __thiscall TPanel::set_z_order(TPanel *this, char z_order_type, __int16 z_order_in)
{
  TPanel *v3; // eax@1

  v3 = this->parent_panel;
  if( v3 )
  {
    TPanel::set_child_z_order(v3, this, z_order_type, z_order_in);
  }
  else if( z_order_type )
  {
    if( z_order_type == 1 )
    {
      this->z_order = 0;
    }
    else if( z_order_type == 2 )
    {
      this->z_order = 0;
    }
  }
  else
  {
    this->z_order = z_order_in;
  }
}

//----- (00466490) --------------------------------------------------------
void __thiscall TPanel::set_child_z_order(TPanel *this, TPanel *child_panel, char z_order_type, __int16 z_order_in)
{
  TPanel *v4; // ebp@1
  PanelNode *v5; // ecx@4
  __int16 j; // dx@4
  TPanel *v7; // eax@5
  PanelNode *v8; // ecx@10
  __int16 i; // dx@10
  TPanel *v10; // eax@11
  PanelNode *v11; // eax@16
  signed int v12; // esi@16
  PanelNode *v13; // eax@23
  signed int v14; // edx@24
  PanelNode *v15; // eax@28
  TPanel *v16; // edi@28
  PanelNode *v17; // esi@28
  PanelNode *v18; // eax@34
  signed int v19; // edx@34

  v4 = this;
  if( z_order_type )
  {
    if( z_order_type == 1 )
    {
      v8 = this->first_child_node;
      for( i = 0; v8; v8 = v8->next_node )
      {
        v10 = v8->panel;
        if( v8->panel != child_panel && v10->z_order > i )
          i = v10->z_order;
      }
      child_panel->z_order = i + 1;
    }
    else if( z_order_type == 2 )
    {
      v5 = this->first_child_node;
      for( j = 0; v5; v5 = v5->next_node )
      {
        v7 = v5->panel;
        if( v5->panel != child_panel && v7->z_order < j )
          j = v7->z_order;
      }
      child_panel->z_order = j - 1;
    }
  }
  else
  {
    v11 = this->first_child_node;
    v12 = 0;
    if( v11 )
    {
      while( v11->panel->z_order != z_order_in )
      {
        v11 = v11->next_node;
        if( !v11 )
          goto LABEL_21;
      }
      v12 = 1;
LABEL_21:
      v4 = this;
    }
    if( v12 )
    {
      v13 = this->first_child_node;
      if( this->first_child_node )
      {
        do
        {
          v14 = v13->panel->z_order;
          if( v14 >= z_order_in )
            v13->panel->z_order = v14 + 1;
          v13 = v13->next_node;
        }
        while( v13 );
      }
    }
    child_panel->z_order = z_order_in;
  }
  v15 = v4->first_child_node;
  v16 = v4->curr_child;
  v17 = 0;
  v4->curr_child = 0;
  if( v15 )
  {
    while( v15->panel != child_panel )
    {
      v15 = v15->next_node;
      if( !v15 )
        goto LABEL_33;
    }
    v17 = v15;
    TPanel::remove_panel_node(v4, v15);
  }
LABEL_33:
  if( v17 )
  {
    v18 = v4->first_child_node;
    v19 = 0;
    if( v18 )
    {
      while( v18->panel->z_order <= child_panel->z_order )
      {
        v18 = v18->next_node;
        if( !v18 )
          goto LABEL_39;
      }
      TPanel::add_panel_node(v4, v17, v18, 0);
      v19 = 1;
    }
LABEL_39:
    if( !v19 )
      TPanel::add_panel_node(v4, v17, v4->last_child_node, 1);
  }
  v4->curr_child = v16;
}

//----- (00466600) --------------------------------------------------------
void __stdcall TPanel::set_tab_order(TPanel **panel_list, __int16 panel_count)
{
  signed int i; // esi@1
  TPanel *v4; // edx@3
  TPanel *v5; // eax@6

  for( i = 0; i < panel_count; ++i )
  {
    if( i )
      v4 = panel_list[i - 1];
    else
      v4 = panel_list[panel_count - 1];
    if( i == panel_count - 1 )
      v5 = *panel_list;
    else
      v5 = panel_list[i + 1];
    (*((void (__stdcall **)(_DWORD, _DWORD))&panel_list[i]->vfptr->set_focus + 1))(v4, v5);
  }
}

//----- (00466650) --------------------------------------------------------
void __thiscall TPanel::set_tab_order(TPanel *this, TPanel *prev_panel, TPanel *next_panel)
{
  this->tab_prev_panel = prev_panel;
  this->tab_next_panel = next_panel;
  this->tab_stop = 1;
}

//----- (00466670) --------------------------------------------------------
TPanel *__thiscall TPanel::previousPanel(TPanel *this)
{
  return this->previousPanelValue;
}

//----- (00466680) --------------------------------------------------------
void __thiscall TPanel::setPreviousPanel(TPanel *this, TPanel *p)
{
  this->previousPanelValue = p;
}

//----- (00466690) --------------------------------------------------------
TPanel *__thiscall TPanel::previousModalPanel(TPanel *this)
{
  return this->previousModalPanelValue;
}

//----- (004666A0) --------------------------------------------------------
void __thiscall TPanel::setPreviousModalPanel(TPanel *this, TPanel *p)
{
  this->previousModalPanelValue = p;
}

//----- (004666B0) --------------------------------------------------------
char *__thiscall TPanel::panelName(TPanel *this)
{
  return this->panelNameValue;
}

//----- (004666C0) --------------------------------------------------------
void __thiscall TPanel::setPanelName(TPanel *this, char *v)
{
  TPanel *v2; // ebx@1
  char *v3; // edx@3

  v2 = this;
  if( v && strlen(v) != 0 )
  {
    v3 = v2->panelNameValue;
    if( v3 )
    {
      if( strlen(v2->panelNameValue) >= strlen(v) )
      {
LABEL_8:
        strcpy(v2->panelNameValue, v);
        return;
      }
      if( v3 )
        free(v2->panelNameValue);
    }
    v2->panelNameValue = (char *)malloc(strlen(v) + 1);
    goto LABEL_8;
  }
  if( v2->panelNameValue )
  {
    free(v2->panelNameValue);
    v2->panelNameValue = 0;
  }
}

//----- (00466770) --------------------------------------------------------
int __thiscall TPanel::xPosition(TPanel *this)
{
  return this->pnl_x;
}

//----- (00466780) --------------------------------------------------------
int __thiscall TPanel::yPosition(TPanel *this)
{
  return this->pnl_y;
}

//----- (00466790) --------------------------------------------------------
int __thiscall TPanel::width(TPanel *this)
{
  return this->pnl_wid;
}

//----- (004667A0) --------------------------------------------------------
int __thiscall TPanel::height(TPanel *this)
{
  return this->pnl_hgt;
}

//----- (004667B0) --------------------------------------------------------
TDrawArea *__thiscall TPanel::renderArea(TPanel *this)
{
  return this->render_area;
}

//----- (004667C0) --------------------------------------------------------
tagRECT *__thiscall TPanel::clipRectangle(TPanel *this, tagRECT *result)
{
  tagRECT *v2; // eax@1
  char *v3; // ecx@1

  v2 = result;
  v3 = (char *)&this->clip_rect;
  result->left = *(_DWORD *)v3;
  result->top = *((_DWORD *)v3 + 1);
  result->right = *((_DWORD *)v3 + 2);
  result->bottom = *((_DWORD *)v3 + 3);
  return v2;
}

//----- (004667F0) --------------------------------------------------------
void __thiscall TPanel::setClipRectangle(TPanel *this, tagRECT r)
{
  this->clip_rect = r;
}

//----- (00466820) --------------------------------------------------------
void __stdcall TPanel::delete_panel(TPanel **panel)
{
  if( *panel )
  {
    ((void (__stdcall *)(_DWORD))(*panel)->vfptr->__vecDelDtor)(1);
    *panel = 0;
  }
}

//----- (00466840) --------------------------------------------------------
BOOL __stdcall TPanel::get_string(int text_id, char *str, int size)
{
  (*(void (__stdcall **)(int, char *, int))&rge_base_game->vfptr->gap8[24])(text_id, str, size);
  return *str != 0;
}

//----- (00466870) --------------------------------------------------------
char *__stdcall TPanel::get_string(int text_id)
{
  TPanel::get_string(text_id, temp_string, 512);
  return temp_string;
}

//----- (00466890) --------------------------------------------------------
int __thiscall TPanel::get_help_message(TPanel *this)
{
  return this->help_string_id;
}

//----- (004668A0) --------------------------------------------------------
int __thiscall TPanel::get_help_page(TPanel *this)
{
  return this->help_page_id;
}

//----- (004668B0) --------------------------------------------------------
void __thiscall TPanel::set_help_info(TPanel *this, int string, int page)
{
  this->help_string_id = string;
  this->help_page_id = page;
}

//----- (004668D0) --------------------------------------------------------
char __thiscall TPanel::get_help_info(TPanel *this, char **string, int *page, int x, int y)
{
  TPanel *v5; // esi@1
  PanelNode *v6; // esi@3
  TPanel *v8; // [sp+18h] [bp-4h]@1

  v5 = this;
  v8 = this;
  if( this->active && ((int (__stdcall *)(int, int))this->vfptr->is_inside)(x, y) )
  {
    v6 = v5->last_child_node;
    if( v6 )
    {
      while( !(unsigned __int8)((int (__stdcall *)(char **, int *, int, int))v6->panel->vfptr->get_help_info)(
                                  string,
                                  page,
                                  x,
                                  y) )
      {
        v6 = v6->prev_node;
        if( !v6 )
          goto LABEL_6;
      }
      return 1;
    }
LABEL_6:
    if( v8->help_string_id >= 0 )
    {
      strcpy(*string, TPanel::get_string(v8->help_string_id));
      *page = v8->help_page_id;
      return 1;
    }
  }
  return 0;
}

//----- (00466980) --------------------------------------------------------
void __thiscall TPanel::stop_sound_system(TPanel *this)
{
  PanelNode *i; // esi@1

  for( i = this->first_child_node; i; i = i->next_node )
    ((void (*)(void))i->panel->vfptr->stop_sound_system)();
}

//----- (004669A0) --------------------------------------------------------
int __thiscall TPanel::restart_sound_system(TPanel *this)
{
  PanelNode *v1; // esi@1
  signed int i; // edi@1

  v1 = this->first_child_node;
  for( i = 1; v1; v1 = v1->next_node )
  {
    if( !((int (*)(void))v1->panel->vfptr->restart_sound_system)() )
      i = 0;
  }
  return i;
}

//----- (004669D0) --------------------------------------------------------
void __thiscall TPanel::handle_reactivate(TPanel *this)
{
  PanelNode *i; // esi@1

  for( i = this->first_child_node; i; i = i->next_node )
    ((void (*)(void))i->panel->vfptr->handle_reactivate)();
}

//----- (004669F0) --------------------------------------------------------
void __thiscall TPanel::get_true_render_rect(TPanel *this, tagRECT *drawRect)
{
  drawRect->left = this->render_rect.left;
  drawRect->top = this->render_rect.top;
  drawRect->right = this->render_rect.right;
  drawRect->bottom = this->render_rect.bottom;
}
