
/**
 * @file    Engine\PanelSlider.cpp
 * @author  Yvan Burrie
 * @date    2018/08/04
 * @version 1.0
 */

void TVerticalSliderPanel::TVerticalSliderPanel()
{
    TScrollBarPanel::TScrollBarPanel();

    this->drawBox = 1;
    this->spineWidth = 0;
}

TVerticalSliderPanel::~TVerticalSliderPanel()
{
    TScrollBarPanel::~TScrollBarPanel();
}

bool TVerticalSliderPanel::setup(
    TDrawArea *renderAreaIn,
    TPanel *parentPanelIn,
    int xIn,
    int yIn,
    int widthIn,
    int heightIn,
    char *backPictureIn,
    char *thumbPictureIn,
    int thumbHeightIn,
    int scaleIn,
    int one_step_in,
    int page_step_in,
    int drawBoxIn,
    int spineWidthIn )
{
    this->drawBox    = drawBoxIn;
    this->spineWidth = spineWidthIn;

    bool result = TScrollBarPanel::setup(
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

    if( result ){

        this->one_step  = one_step_in;
        this->page_step = page_step_in;

        return true;
    }else{
        return false;
    }
}

void TVerticalSliderPanel::set_rect( int x_in, int y_in, int wid_in, int hgt_in )
{
    TScrollBarPanel::set_rect(x_in, y_in, wid_in, hgt_in);
}

THorizontalSliderPanel::THorizontalSliderPanel()
{
    TVerticalSliderPanel::TVerticalSliderPanel();
}

THorizontalSliderPanel::~THorizontalSliderPanel()
{
    TVerticalSliderPanel::~TVerticalSliderPanel();
}

bool THorizontalSliderPanel::setup(
    TDrawArea *renderAreaIn,
    TPanel *parentPanelIn,
    int xIn,
    int yIn,
    int widthIn,
    int heightIn,
    char *backPictureIn,
    char *thumbPictureIn,
    int thumbWidthIn,
    int scaleIn,
    int one_step_in,
    int page_step_in,
    int drawBoxIn,
    int spineWidthIn )
{
    this->drawBox = drawBoxIn;
    this->spineWidth = spineWidthIn;

    bool result = TScrollBarPanel::setup(
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

    if( result ){

        this->one_step  = one_step_in;
        this->page_step = page_step_in;

        return true;
    }else{
        return false;
    }
}

void THorizontalSliderPanel::set_rect( int x_in, int y_in, int wid_in, int hgt_in )
{
    this->set_rect(x_in, y_in, wid_in, hgt_in);

    this->up_rect.left  = this->pnl_x;
    this->up_rect.right = this->pnl_x;

    int v8 = this->pnl_wid + this->pnl_x - 1;

    this->down_rect.left  = v8;
    this->down_rect.right = v8;

    int v6 = this->pnl_x + 1;

    this->tab_min_x = v6;
    this->tab_x     = v6;
    this->tab_max_x = v8 - this->pnl_hgt + 2;

    this->calc_item_rects();
}
