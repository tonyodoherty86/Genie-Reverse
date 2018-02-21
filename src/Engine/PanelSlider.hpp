
/**
 * @file    Engine\PanelSlider.hpp
 * @author  Yvan Burrie
 * @date    2018/02/21
 * @version 1.0
 */

class TVerticalSliderPanel : public TScrollBarPanel
{
public:

    int drawBox;
    int spineWidth;

    TVerticalSliderPanel();

    ~TVerticalSliderPanel();

    int setup(TDrawArea *renderAreaIn, TPanel *parentPanelIn, int xIn, int yIn, int widthIn, int heightIn, char *backPictureIn, char *thumbPictureIn, int thumbHeightIn, int scaleIn, int one_step_in, int page_step_in, int drawBoxIn, int spineWidthIn);
    void set_rect(int x_in, int y_in, int wid_in, int hgt_in);
};

class THorizontalSliderPanel : public TVerticalSliderPanel
{
public:

    THorizontalSliderPanel();

    ~THorizontalSliderPanel();

    int setup(TDrawArea *renderAreaIn, TPanel *parentPanelIn, int xIn, int yIn, int widthIn, int heightIn, char *backPictureIn, char *thumbPictureIn, int thumbWidthIn, int scaleIn, int one_step_in, int page_step_in, int drawBoxIn, int spineWidthIn);
    void set_rect(int x_in, int y_in, int wid_in, int hgt_in);
};

//typedef TScrollBarPanel::ActionType TVerticalSliderPanel::SliderAction;
