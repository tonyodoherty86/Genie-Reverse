
/**
 * @file    Engine\TRB.hpp
 * @author  Yvan Burrie
 * @date    2018/07/03
 * @version 1.0
 */

#include "Engine\TRB\Game.hpp"

#include "Engine\TRB\World.hpp"
#include "Engine\TRB\Map.hpp"

class TRIBE_Player;

#include "Engine\TRB\Scenario.hpp"

#if ENGINE_TRIGGERS_SYSTEM_EXISTS
#include "Engine\TRB\Triggers.hpp"
#endif

#include "Engine\TRB\MasterPlayer.hpp"
#include "Engine\TRB\TaskList.hpp"
#include "Engine\TRB\MasterTreeObject.hpp"
#include "Engine\TRB\MasterCombatObject.hpp"
#include "Engine\TRB\MasterBuildingObject.hpp"
#include "Engine\TRB\Technology.hpp"

class TribeMainDecisionAIModule;
#include "Engine\TRB\AiBuildModule.hpp"
#include "Engine\TRB\AiConstructionModule.hpp"
#include "Engine\TRB\AiTacticalModule.hpp"
#include "Engine\TRB\AiInformationModule.hpp"
#include "Engine\TRB\AiResourceModule.hpp"
#include "Engine\TRB\AiStrategyModule.hpp"
#include "Engine\TRB\AiMainDecisionModule.hpp"
#include "Engine\TRB\AiUnitModule.hpp"

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

/* Include Objects: */
#include "Engine\TRB\TreeObject.hpp"
#include "Engine\TRB\CombatObject.hpp"
#include "Engine\TRB\BuildingObject.hpp"

/* Include panels: */
#include "Engine\TRB\PanelScreenGame.hpp"
