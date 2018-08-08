
/**
 * @file    Engine\TRB\DialogConfig.hpp
 * @author  Yvan Burrie
 * @date    2018/08/05
 * @version 1.0
 */

class TribeConfigDialog : public TDialogPanel
{
public:

    enum Mode
    {
        InGame    = 0x00,
        InPregame = 0x01,
    }
    modeValue;

    TTextPanel *title;
    TTextPanel *speedTitle[4];
    TButtonPanel *speedButton[3];
    TTextPanel *musicTitle[3];
    TVerticalSliderPanel *musicSlider;
    TTextPanel *soundTitle[3];
    TVerticalSliderPanel *soundSlider;
    TTextPanel *scrollSpeedTitle[3];
    TVerticalSliderPanel *scrollSpeedSlider;
    TTextPanel *sizeTitle[4];
    TButtonPanel *sizeButton[3];
    TTextPanel *mouseTitle[3];
    TButtonPanel *mouseButton[2];
    TTextPanel *rolloverTitle[3];
    TButtonPanel *rolloverButton[2];
    TTextPanel *pathFindingTitle[4];
    TButtonPanel *pathFindingButton[3];
    TButtonPanel *okButton;
    TButtonPanel *cancelButton;

    int musicVolume;
    int soundVolume;
    float gameSpeed;
    int scrollSpeed;
    int newMusicVolume;
    int newSoundVolume;

    TribeConfigDialog( TribeConfigDialog::Mode m, TScreenPanel *parentPanel );

    ~TribeConfigDialog();

    int action( TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );
};
