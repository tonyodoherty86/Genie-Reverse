
/**
 * @file    Engine\TRB\DialogSendMessage.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

class TribeSendMessageDialog : public TDialogPanel
{
    TTextPanel *title,
               *playerName[RGE_PLAYERS_COUNT - 1],
               *playerCivilization[RGE_PLAYERS_COUNT - 1];

    TButtonPanel *checkButton[RGE_PLAYERS_COUNT - 1];
    TTextPanel *radioTitle[4];
    TButtonPanel *radioButton[4];
    TShape *radioButtonShapes;
    TEditPanel *chatInput;
    TTextPanel *chatTitle;

    TButtonPanel *okButton,
                 *help_button;

    TShape *backgroundPics;

    int commPlayers[RGE_PLAYERS_COUNT - 1];

    TribeSendMessageDialog( TScreenPanel *parentPanel );

    ~TribeSendMessageDialog();

    int action( TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );

    void checkButtons();

    void draw();
};

class TribeSendQuickMessageDialog : public TDialogPanel
{
public:

    TEditPanel *chatInput,
               *chatTitle;

    enum Mode
    {
        AsChat    = 0x00,
        AsComment = 0x01,
    }
    modeValue;

    TribeSendQuickMessageDialog( TScreenPanel *parentPanel, Mode m );

    ~TribeSendQuickMessageDialog();

    int action( TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );

    int handle_mouse_down( int mouse_button_in, int x, int y, int ctrl_key, int shift_key );
};
