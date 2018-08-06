
/**
 * @file    Engine\TRB\ScreenEnd.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

class TribeEndScreen : public TScreenPanel
{
public:

    TPicturePanel *background;

    TTextPanel *title,
               *text;

    TButtonPanel *okButton;

    TribeEndScreen( char *titleText, char **textText, int textLineCount );

    ~TribeEndScreen();

    int action( TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );
};
