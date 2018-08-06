
/**
 * @file    Engine\TRB\ScreenCampaignEditor.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */

class TRIBE_Campaign_Editor_Screen : public TScreenPanel
{
public:

    char need_to_save;

    TTextPanel *title,
               *filename_title,
               *scenarios_title,
               *campaign_scenarios_title;

    TListPanel *scenarios,
               *campaign_scenarios;

    TScrollBarPanel *scenarios_bar,
                    *campaign_scenarios_bar;

    TEditPanel *filename;

    TButtonPanel *ok_button,
                 *cancel_button,
                 *save_button,
                 *add_button,
                 *remove_button,
                 *move_scenario_up_button,
                 *move_scenario_down_button;

    TDropDownPanel *filename_drop;

    RGE_Campaign *campaign;

    TRIBE_Campaign_Editor_Screen();

    ~TRIBE_Campaign_Editor_Screen();

    void fill_campaign_drop();
    void fill_scenario_list();
    void fill_campaign_scenario_list();
    char check_lists();
    void load_campaign();
    void make_campaign();
    void add_scenario();
    void remove_scenario();
    void move_scenario_up();
    void move_scenario_down();

    int action( TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );
};
