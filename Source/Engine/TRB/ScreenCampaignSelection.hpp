
/**
 * @file    Engine\TRB\ScreenCampaignSelection.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

class TRIBE_Screen_Campaign_Selection : public TScreenPanel
{
public:

    TTextPanel *title;

    int campaignListX,
        campaignListY,
        campaignListWidth,
        campaignListHeight;

    TTextPanel *campaignTitle,
               *campaignList;

    TScrollBarPanel *campaignScrollbar;

    int scenarioListX,
        scenarioListY,
        scenarioListWidth,
        scenarioListHeight;

    TTextPanel *scenarioTitle;

    TListPanel *scenarioList;

    TScrollBarPanel *scenarioScrollbar;

    TTextPanel *difficultyTitle;

    TDropDownPanel *difficultyDrop;

    TButtonPanel *okButton,
                 *cancelButton,
                 *close_button;

    int campaignsLoaded;

    TRIBE_Screen_Campaign_Selection();

    ~TRIBE_Screen_Campaign_Selection();

    void init_vars();
    int handle_idle();
    int action( TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );
    void fillCampaigns();
    void fillScenarios();
    void startGame();
};
