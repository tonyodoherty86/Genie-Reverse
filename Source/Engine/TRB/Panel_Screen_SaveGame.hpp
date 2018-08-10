
/**
 * @file    Engine\TRB\Panel_Screen_SaveGame.hpp
 * @author  Yvan Burrie
 * @date    2018/08/10
 * @version 1.0
 */

class TribeSaveGameScreen : public TScreenPanel
{
public:

    TTextPanel *title;
    TEditPanel *input;
    TListPanel *list;
    TScrollBarPanel *scrollbar;

    TButtonPanel *okButton,
                 *cancelButton,
                 *deleteButton;

    char fileName[260];
    char fileNameNoExt[260];

    enum Mode
    {
        SaveGame         = 0x00,
        SaveScenario     = 0x01,
        SaveScenarioEdit = 0x02,
    }
    modeValue;

    int quit_after_save;

    TribeSaveGameScreen(Mode m, char *file_name, int quit_after_save_in);

    ~TribeSaveGameScreen();

    void fillList();

    int action(TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2);

    void save_for_scenario_editor();
};
