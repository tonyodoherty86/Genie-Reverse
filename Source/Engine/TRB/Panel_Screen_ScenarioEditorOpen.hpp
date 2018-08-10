
/**
 * @file    Engine\TRB\Panel_Screen_ScenarioEditorOpen.hpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

class TRIBE_Screen_Sed_Open : public TScreenPanel
{
    TTextPanel *title;

    TListPanel *list;

    TScrollBarPanel *scrollbar;

    TButtonPanel *okButton,
                 *cancelButton,
                 *deleteButton;

    TRIBE_Screen_Sed_Open();

    ~TRIBE_Screen_Sed_Open();

    void fillList();

    int action( TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );
};
