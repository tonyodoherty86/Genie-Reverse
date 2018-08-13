
/**
 * @file    RGE.hpp
 * @author  Yvan Burrie
 * @date    2018/08/08
 * @version 1.0
 */

#ifndef RGE_HPP
#define RGE_HPP

////////////////////////////////////////////////////////////////////////////////////////////////////

/* Include core components: */
#include "RGE\FileIO.h"

////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * This defines the hard-coded number of players.
 * Many people have been enthusiastic on having more than 9 players.
 * Modders claim it would be very difficult to do so because the number is hard-coded frequently throughout the build.
 * Finally, this definition will override the traditional 9 player limit!
 */
#define RGE_PLAYERS_COUNT PLAYERS_ITERATIONS

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include game components: */

#include "RGE\GameInfo.hpp"
#include "RGE\Game.hpp"
#include "RGE\Campaign.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include communications components: */

#include "RGE\CommQueue.hpp"
#include "RGE\CommLobby.hpp"
#include "RGE\TimeSinceLastCall.hpp"
#include "RGE\CommSpeed.hpp"
#include "RGE\CommSync.hpp"
#include "RGE\CommAddresses.hpp"
#include "RGE\CommError.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include world components: */

#include "RGE\World.hpp"
#include "RGE\ColorTable.hpp"
#include "RGE\Sound.hpp"
#include "RGE\Sprite.hpp"
#include "RGE\Map.hpp"
#include "RGE\Path.hpp"
#include "RGE\PathingSystem.hpp"
#include "RGE\ZoneMap.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include Random-Map-Module components: */

#include "RGE\RmmBase.hpp"
#include "RGE\RmmController.hpp"
#include "RGE\RmmDbController.hpp"
#include "RGE\RmmLand.hpp"
#include "RGE\RmmElevation.hpp"
#include "RGE\RmmTerrain.hpp"
#include "RGE\RmmObject.hpp"
#include "RGE\RmmCliffs.hpp"
#include "RGE\RmmShallows.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include Master-Player components: */

class RGE_Static_Object;
class RGE_Animated_Object;
class RGE_Moving_Object;
class RGE_Action_Object;
class RGE_Combat_Object;
class RGE_Missile_Object;

struct RGE_Object_Node;

#include "RGE\MasterPlayer.hpp"

#include "RGE\Task.hpp"
#include "RGE\TaskList.hpp"

#include "RGE\MasterObject_Static.hpp"
#include "RGE\MasterObject_Animated.hpp"
#include "RGE\MasterObject_Dopple.hpp"
#include "RGE\MasterObject_Moving.hpp"
#include "RGE\MasterObject_Action.hpp"
#include "RGE\MasterObject_Combat.hpp"
#include "RGE\MasterObject_Missile.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "RGE\Player.hpp"
#include "RGE\VisibleMap.hpp"
#include "RGE\VictoryConditions.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include AI-Module components: */

#include "RGE\InfluenceMap.hpp"
#include "RGE\AiModule.hpp"
#include "RGE\AiMainDecisionModule.hpp"
#include "RGE\AiResourceItem.hpp"
#include "RGE\AiPlay.hpp"
#include "RGE\AiBaseItem.hpp"
#include "RGE\AiBaseObject.hpp"
#include "RGE\AiBuildItem.hpp"
#include "RGE\AiBuildModule.hpp"
#include "RGE\AiUnitModule.hpp"
#include "RGE\AiConstructionItem.hpp"
#include "RGE\AiConstructionModule.hpp"
#include "RGE\AiDiplomacyModule.hpp"
#include "RGE\AiEmotionalModule.hpp"
#include "RGE\AiInformationModule.hpp"
#include "RGE\AiResourceModule.hpp"
#include "RGE\AiTechnologyItem.hpp"
#include "RGE\AiResearchModule.hpp"
#include "RGE\AiStrategyModule.hpp"
#include "RGE\AiTacticalModule.hpp"
#include "RGE\AiTradeModule.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "RGE\Effects.hpp"

#include "RGE\Timeline.hpp"
#include "RGE\Scenario.hpp"
#include "RGE\Command.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "RGE\ActiveSprite.hpp"
#include "RGE\ActiveSpriteList.hpp"

#include "RGE\Object_Static.hpp"
#include "RGE\Object_Animated.hpp"
#include "RGE\Object_Moving.hpp"
#include "RGE\Object_Doppleganger.hpp"
#include "RGE\Object_Action.hpp"
#include "RGE\Object_Combat.hpp"
#include "RGE\Object_Missile.hpp"
#include "RGE\ObjectList.hpp"

#include "RGE\Action.hpp"
#include "RGE\ActionMove.hpp"
#include "RGE\ActionGather.hpp"
#include "RGE\ActionExplore.hpp"
#include "RGE\ActionEnter.hpp"
#include "RGE\ActionAttack.hpp"
#include "RGE\ActionBird.hpp"
#include "RGE\ActionMissile.hpp"
#include "RGE\ActionTransport.hpp"
#include "RGE\ActionList.hpp"

#include "RGE\DopplegangerCreator.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include Panels: */

#include "RGE\Panel_View.hpp"
#include "RGE\Panel_MainView.hpp"
#include "RGE\Panel_DiamondMap.hpp"
#include "RGE\Panel_DiamondMapView.hpp"
#include "RGE\Panel_ToolBox.hpp"
#include "RGE\Panel_ListDialog.hpp"
#include "RGE\Panel_Time.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // RGE_HPP
