#pragma once

/**
 * @file    Engine\TRB\DialogMultiCreate.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

#include <Panel_Dialog.hpp>

class TribeMPCreateDialog : public TDialogPanel
{
public:

    TTextPanel *title,
               *input_title,
               *inputGamename;

    TButtonPanel *okButton,
                 *cancelButton;

    TribeMPCreateDialog( TPanel *parentPanel );

    ~TribeMPCreateDialog();

    int action( TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );
};
