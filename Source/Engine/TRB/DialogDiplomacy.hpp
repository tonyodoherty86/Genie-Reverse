
/**
 * @file    Engine\TRB\DialogDiplomacy.hpp
 * @author  Yvan Burrie
 * @date    2018/08/05
 * @version 1.0
 */

class TribeDiplomacyDialog : public TDialogPanel
{
public:

    TTextPanel *title[RGE_PLAYERS_COUNT - 1],
               *playerName[RGE_PLAYERS_COUNT - 1],
               *playerVictoryScores[RGE_PLAYERS_COUNT - 1],
               *playerCivilization[RGE_PLAYERS_COUNT - 1],
               *needMarket;

    TButtonPanel *goldTributeButton[RGE_PLAYERS_COUNT - 1],
                 *woodTributeButton[RGE_PLAYERS_COUNT - 1],
                 *foodTributeButton[RGE_PLAYERS_COUNT - 1],
                 *stoneTributeButton[RGE_PLAYERS_COUNT - 1],
                 *allyButton[24],
                 *allianceButton,
                 *okButton,
                 *clearButton,
                 *cancelButton,
                 *help_button;

    TShape *buttonPics,
           *backgroundPics;

    float foodTotal,
          woodTotal,
          goldTotal,
          stoneTotal;

    TTextPanel *playerFood,
               *playerGold,
               *playerWood,
               *playerStone;

    float goldTributeAmount[RGE_PLAYERS_COUNT - 1],
          foodTributeAmount[RGE_PLAYERS_COUNT - 1],
          stoneTributeAmount[RGE_PLAYERS_COUNT - 1],
          woodTributeAmount[RGE_PLAYERS_COUNT - 1];

    int cur_player_row;

    int tribute_flag;

    TribeDiplomacyDialog( TScreenPanel *parentPanel );

    ~TribeDiplomacyDialog();

    int action( TPanel *fromPanel, int actionIn, unsigned int a1, unsigned int a2 );

    int check_gold();
    int check_wood();
    int check_food();
    int check_stone();

    void draw();
};
