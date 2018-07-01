
//----- (0047BCE0) --------------------------------------------------------
void __thiscall TVerticalSliderPanel::TVerticalSliderPanel(TVerticalSliderPanel *this)
{
  TVerticalSliderPanel *v1; // esi@1

  v1 = this;
  TScrollBarPanel::TScrollBarPanel((TScrollBarPanel *)&this->vfptr);
  v1->drawBox = 1;
  v1->spineWidth = 0;
  v1->vfptr = (TPanelVtbl *)&TVerticalSliderPanel::`vftable';
}
// 571A38: using guessed type int (__thiscall *TVerticalSliderPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (0047BD10) --------------------------------------------------------
TVerticalSliderPanel *__thiscall TVerticalSliderPanel::`scalar deleting destructor'(TVerticalSliderPanel *this, unsigned int __flags)
{
  TVerticalSliderPanel *v2; // esi@1

  v2 = this;
  TVerticalSliderPanel::~TVerticalSliderPanel(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0047BD30) --------------------------------------------------------
void __thiscall TVerticalSliderPanel::~TVerticalSliderPanel(TVerticalSliderPanel *this)
{
  this->vfptr = (TPanelVtbl *)&TVerticalSliderPanel::`vftable';
  TScrollBarPanel::~TScrollBarPanel((TScrollBarPanel *)&this->vfptr);
}
// 571A38: using guessed type int (__thiscall *TVerticalSliderPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (0047BD40) --------------------------------------------------------
int __thiscall TVerticalSliderPanel::setup(TVerticalSliderPanel *this, TDrawArea *renderAreaIn, TPanel *parentPanelIn, int xIn, int yIn, int widthIn, int heightIn, char *backPictureIn, char *thumbPictureIn, int thumbHeightIn, int scaleIn, int one_step_in, int page_step_in, int drawBoxIn, int spineWidthIn)
{
  TVerticalSliderPanel *v15; // esi@1
  int result; // eax@1

  v15 = this;
  this->drawBox = drawBoxIn;
  this->spineWidth = spineWidthIn;
  result = TScrollBarPanel::setup(
             (TScrollBarPanel *)&this->vfptr,
             renderAreaIn,
             parentPanelIn,
             xIn,
             yIn,
             widthIn,
             heightIn,
             backPictureIn,
             0,
             0,
             thumbPictureIn,
             0,
             thumbHeightIn,
             0,
             scaleIn,
             0);
  if ( result )
  {
    v15->one_step = one_step_in;
    v15->page_step = page_step_in;
    result = 1;
  }
  return result;
}

//----- (0047BDC0) --------------------------------------------------------
void __thiscall TVerticalSliderPanel::set_rect(TVerticalSliderPanel *this, int x_in, int y_in, int wid_in, int hgt_in)
{
  TScrollBarPanel::set_rect((TScrollBarPanel *)&this->vfptr, x_in, y_in, wid_in, hgt_in);
}

//----- (0047BDF0) --------------------------------------------------------
void __thiscall THorizontalSliderPanel::THorizontalSliderPanel(THorizontalSliderPanel *this)
{
  THorizontalSliderPanel *v1; // esi@1

  v1 = this;
  TVerticalSliderPanel::TVerticalSliderPanel((TVerticalSliderPanel *)&this->vfptr);
  v1->vfptr = (TPanelVtbl *)&THorizontalSliderPanel::`vftable';
}
// 571B18: using guessed type int (__thiscall *THorizontalSliderPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (0047BE10) --------------------------------------------------------
THorizontalSliderPanel *__thiscall THorizontalSliderPanel::`vector deleting destructor'(THorizontalSliderPanel *this, unsigned int __flags)
{
  THorizontalSliderPanel *v2; // esi@1

  v2 = this;
  THorizontalSliderPanel::~THorizontalSliderPanel(this);
  if ( __flags & 1 )
    operator delete(v2);
  return v2;
}

//----- (0047BE30) --------------------------------------------------------
void __thiscall THorizontalSliderPanel::~THorizontalSliderPanel(THorizontalSliderPanel *this)
{
  this->vfptr = (TPanelVtbl *)&THorizontalSliderPanel::`vftable';
  TVerticalSliderPanel::~TVerticalSliderPanel((TVerticalSliderPanel *)&this->vfptr);
}
// 571B18: using guessed type int (__thiscall *THorizontalSliderPanel::`vftable')(void *Memory, unsigned int __flags);

//----- (0047BE40) --------------------------------------------------------
int __thiscall THorizontalSliderPanel::setup(THorizontalSliderPanel *this, TDrawArea *renderAreaIn, TPanel *parentPanelIn, int xIn, int yIn, int widthIn, int heightIn, char *backPictureIn, char *thumbPictureIn, int thumbWidthIn, int scaleIn, int one_step_in, int page_step_in, int drawBoxIn, int spineWidthIn)
{
  THorizontalSliderPanel *v15; // esi@1
  int result; // eax@1

  v15 = this;
  this->drawBox = drawBoxIn;
  this->spineWidth = spineWidthIn;
  result = TScrollBarPanel::setup(
             (TScrollBarPanel *)&this->vfptr,
             renderAreaIn,
             parentPanelIn,
             xIn,
             yIn,
             widthIn,
             heightIn,
             backPictureIn,
             0,
             0,
             thumbPictureIn,
             0,
             thumbWidthIn,
             0,
             scaleIn,
             Horizontal);
  if ( result )
  {
    v15->one_step = one_step_in;
    v15->page_step = page_step_in;
    result = 1;
  }
  return result;
}

//----- (0047BEC0) --------------------------------------------------------
void __thiscall THorizontalSliderPanel::set_rect(THorizontalSliderPanel *this, int x_in, int y_in, int wid_in, int hgt_in)
{
  THorizontalSliderPanel *v5; // esi@1
  int v6; // ecx@1
  int v7; // edx@1
  int v8; // eax@1
  int v9; // edx@1

  v5 = this;
  TScrollBarPanel::set_rect((TScrollBarPanel *)&this->vfptr, x_in, y_in, wid_in, hgt_in);
  v6 = v5->pnl_x;
  v7 = v5->pnl_wid;
  v5->up_rect.left = v6;
  v5->up_rect.right = v6;
  v8 = v7 + v6 - 1;
  v9 = v5->pnl_hgt;
  v5->down_rect.left = v8;
  v5->down_rect.right = v8;
  v5->tab_min_x = ++v6;
  v5->tab_x = v6;
  v5->tab_max_x = v8 - v9 + 2;
  TScrollBarPanel::calc_item_rects((TScrollBarPanel *)&v5->vfptr);
}
