
/**
 * @file    Engine\TRB.hpp
 * @author  Yvan Burrie
 * @date    2018/08/05
 * @version 1.0
 */

#ifndef TRB_HPP
#define TRB_HPP

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
#include "Engine\TRB\MasterTreeObject.hpp"
#include "Engine\TRB\MasterCombatObject.hpp"
#include "Engine\TRB\MasterBuildingObject.hpp"
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

#include "Engine\TRB\TreeObject.hpp"
#include "Engine\TRB\CombatObject.hpp"
#include "Engine\TRB\BuildingObject.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include panels: */

#include "Engine\TRB\PanelScreenGame.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include dialogs: */

#include "Engine\TRB\DialogAbout.hpp"
#include "Engine\TRB\DialogConfig.hpp"
#include "Engine\TRB\DialogDiplomacy.hpp"
#include "Engine\TRB\DialogMenu.hpp"
#include "Engine\TRB\DialogMultiCreate.hpp"
#include "Engine\TRB\DialogSendMessage.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include screens: */

#include "Engine\TRB\ScreenAchievements.hpp"
#include "Engine\TRB\ScreenCampaignEditor.hpp"
#include "Engine\TRB\ScreenCampaignSelection.hpp"
#include "Engine\TRB\ScreenCampaignCredits.hpp"
#include "Engine\TRB\ScreenCampaignJoin.hpp"
#include "Engine\TRB\ScreenCampaignEnd.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // TRB_HPP
