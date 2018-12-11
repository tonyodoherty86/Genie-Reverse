#pragma once

/**
 * @file    Engine\TRB\DialogAbout.hpp
 * @author  Yvan Burrie
 * @date    2018/08/05
 * @version 1.0
 */

#include <Panel_Dialog.hpp>


class TribeAboutDialog : public TDialogPanel
{
public:

    TTextPanel *title_text,
               *version_text,
               *ms_copy_text1,
               *ms_copy_text2,
               *ens_copy_text,
               *genie_copy_text,
               *pid_label_text,
               *pid_text,
               *warning_text,
               *background;

    TButtonPanel *credits_button,
                 *close_button;

    TPicturePanel *circle_p_pic;

    TribeAboutDialog( TScreenPanel *parentPanel );

    ~TribeAboutDialog();

    int action( TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );
};
