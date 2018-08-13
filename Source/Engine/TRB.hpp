
/**
 * @file    Engine\TRB.hpp
 * @author  Yvan Burrie
 * @date    2018/08/08
 * @version 1.0
 */

#ifndef TRB_HPP
#define TRB_HPP

////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * Command-line options:
 * These are set to upper-case.
 */

#ifndef TRB_CMD_AUTO_EXIT
    /**
     * Automatically exit game after a certain time.
     */
    #define TRB_CMD_AUTO_EXIT "EXIT="
#endif

#ifndef TRB_CMD_STARTING_SAVE_GAME
    /**
     * Sets starting save game.
     */
    #define TRB_CMD_STARTING_SAVE_GAME "GAM="
#endif

#ifndef TRB_CMD_STARTING_SCENARIO
    /**
     * Sets startup scenario file.
     */
    #define TRB_CMD_STARTING_SCENARIO "SCN="
#endif

#ifndef TRB_CMD_NO_TERRAIN_SOUND
    /**
     * Turns off terrain sounds.
     */
    #define TRB_CMD_NO_TERRAIN_SOUND "NOTERRAINSOUND"
#endif

#ifndef TRB_CMD_QUICK_START_MODE
    /**
     * Sets quick start mode.
     */
    #define TRB_CMD_QUICK_START_MODE "QUICK1"
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Engine\TRB\Game.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Engine\TRB\World.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Engine\TRB\Map.hpp"

#include "Engine\TRB\RmmDbController.hpp"

class TRIBE_Player;

#include "Engine\TRB\Command.hpp"

#include "Engine\TRB\Scenario.hpp"

#include "Engine\TRB\Triggers.hpp"

#include "Engine\TRB\MasterPlayer.hpp"

#include "Engine\TRB\TaskList.hpp"

#include "Engine\TRB\MasterObject_Tree.hpp"
#include "Engine\TRB\MasterObject_Combat.hpp"
#include "Engine\TRB\MasterObject_Building.hpp"

#include "Engine\TRB\Technology.hpp"

class TribeMainDecisionAIModule;
#include "Engine\TRB\AiBuildModule.hpp"
#include "Engine\TRB\AiConstructionModule.hpp"
#include "Engine\TRB\AiPlay.hpp"
#include "Engine\TRB\AiTacticalModule.hpp"
#include "Engine\TRB\AiInformationModule.hpp"
#include "Engine\TRB\AiResourceModule.hpp"
#include "Engine\TRB\AiStrategyModule.hpp"
#include "Engine\TRB\AiMainDecisionModule.hpp"
#include "Engine\TRB\AiUnitModule.hpp"
#include "Engine\TRB\AiCombatRule.hpp"

class TRIBE_Tree_Object;
class TRIBE_Combat_Object;
class TRIBE_Building_Object;

#include "Engine\TRB\Player.hpp"
#include "Engine\TRB\History.hpp"
#include "Engine\TRB\VictoryConditions.hpp"
#include "Engine\TRB\ObjectList.hpp"

#include "Engine\TRB\ActionList.hpp"
#include "Engine\TRB\Action.hpp"
#include "Engine\TRB\ActionArtifact.hpp"
#include "Engine\TRB\ActionBuild.hpp"
#include "Engine\TRB\ActionConvert.hpp"
#include "Engine\TRB\ActionDiscovery.hpp"
#include "Engine\TRB\ActionHeal.hpp"
#include "Engine\TRB\ActionHunt.hpp"
#include "Engine\TRB\ActionMakeObj.hpp"
#include "Engine\TRB\ActionMakeTech.hpp"
#include "Engine\TRB\ActionRepair.hpp"
#include "Engine\TRB\ActionTrade.hpp"
#include "Engine\TRB\ActionWonder.hpp"

#include "Engine\TRB\Effects.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include Objects: */

#include "Engine\TRB\Object_Tree.hpp"
#include "Engine\TRB\Object_Combat.hpp"
#include "Engine\TRB\Object_Building.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include panels: */

#include "Engine\TRB\Panel_Button.hpp"
#include "Engine\TRB\Panel_Pop.hpp"
#include "Engine\TRB\Panel_Time.hpp"
#include "Engine\TRB\Panel_Inventory.hpp"
#include "Engine\TRB\Panel_Object.hpp"
#include "Engine\TRB\Panel_Object_ScenarioEditor.hpp"
#include "Engine\TRB\Panel_View_Main.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include dialogs: */

#include "Engine\TRB\Panel_Dialog_About.hpp"
#include "Engine\TRB\Panel_Dialog_Config.hpp"
#include "Engine\TRB\Panel_Dialog_Menu.hpp"
#include "Engine\TRB\Panel_Dialog_MultiPlayerCreate.hpp"
#include "Engine\TRB\Panel_Dialog_Diplomacy.hpp"
#include "Engine\TRB\Panel_Dialog_SendMessage.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include screens: */

#include "Engine\TRB\Panel_Screen_GameSettings.hpp"
#include "Engine\TRB\Panel_Screen_Name.hpp"
#include "Engine\TRB\Panel_Screen_CampaignEditor.hpp"
#include "Engine\TRB\Panel_Screen_CampaignSelection.hpp"
#include "Engine\TRB\Panel_Screen_SelectScenario.hpp"
#include "Engine\TRB\Panel_Screen_ScenarioEditorMenu.hpp"
#include "Engine\TRB\Panel_Screen_ScenarioEditorOpen.hpp"
#include "Engine\TRB\Panel_Screen_ScenarioEditor.hpp"
#include "Engine\TRB\Panel_Screen_SinglePlayerMenu.hpp"
#include "Engine\TRB\Panel_Screen_Join.hpp"
#include "Engine\TRB\Panel_Screen_Selection.hpp"
#include "Engine\TRB\Panel_Screen_Mission.hpp"
#include "Engine\TRB\Panel_Screen_SaveGame.hpp"
#include "Engine\TRB\Panel_Screen_Disconnect.hpp"
#include "Engine\TRB\Panel_Screen_StatusMessage.hpp"
#include "Engine\TRB\Panel_Screen_Achievements.hpp"
#include "Engine\TRB\Panel_Screen_End.hpp"
#include "Engine\TRB\Panel_Screen_Credits.hpp"
#include "Engine\TRB\Panel_Screen_Game.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TRB_HPP
