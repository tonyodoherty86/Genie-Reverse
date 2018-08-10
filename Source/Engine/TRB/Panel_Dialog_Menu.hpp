
/**
 * @file    Engine\TRB\DialogMenu.hpp
 * @author  Yvan Burrie
 * @date    2018/08/05
 * @version 1.0
 */

class TribeMenuDialog : public TDialogPanel
{
public:

    TButtonPanel *button[11];

    TribeMenuDialog( TScreenPanel *parentPanel );

    ~TribeMenuDialog();

    int action(TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );
};
