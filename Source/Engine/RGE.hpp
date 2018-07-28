
/**
 * @file    RGE.hpp
 * @author  Yvan Burrie
 * @date    2018/07/01
 * @version 1.0
 */

/* Include core components: */
#include "RGE\FileIO.h"

/**
 * This defines the hard-coded number of players.
 * Many people have been enthusiastic on having more than 9 players.
 * Modders claim it would be very difficult to do so because the number is hard-coded frequently throughout the build.
 * Finally, this definition will override the traditional 9 player limit!
 */
#define RGE_PLAYERS_COUNT PLAYERS_ITERATIONS

/* Include game components: */
#include "RGE\BaseGame.hpp"
#include "RGE\GameInfo.hpp"
#include "RGE\Campaign.hpp"

/* Include communications components: */
#include "RGE\CommQueue.hpp"
#include "RGE\CommLobby.hpp"
#include "RGE\TimeSinceLastCall.hpp"
#include "RGE\CommSpeed.hpp"
#include "RGE\CommSync.hpp"
#include "RGE\CommAddresses.hpp"
#include "RGE\CommError.hpp"

/* Include world components: */
#include "RGE\GameWorld.hpp"
#include "RGE\ColorTable.hpp"
#include "RGE\Sound.hpp"
#include "RGE\Sprite.hpp"
#include "RGE\Map.hpp"
#include "RGE\Path.hpp"
#include "RGE\PathingSystem.hpp"
#include "RGE\ZoneMap.hpp"

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

class RGE_Static_Object;
class RGE_Animated_Object;
class RGE_Moving_Object;
class RGE_Action_Object;
class RGE_Combat_Object;
class RGE_Missile_Object;

/* Include Master-Player components: */
#include "RGE\MasterPlayer.hpp"
#include "RGE\MasterStaticObject.hpp"
#include "RGE\MasterAnimatedObject.hpp"
#include "RGE\MasterDoppleObject.hpp"
#include "RGE\MasterMovingObject.hpp"
#include "RGE\MasterActionObject.hpp"
#include "RGE\TaskList.hpp"
#include "RGE\Task.hpp"
#include "RGE\MasterCombatObject.hpp"
#include "RGE\MasterMissileObject.hpp"

#include "RGE\Player.hpp"
#include "RGE\VisibleMap.hpp"
#include "RGE\VictoryConditions.hpp"

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

#include "RGE\Effects.hpp"

#include "RGE\Timeline.hpp"
#include "RGE\Scenario.hpp"
#include "RGE\Command.hpp"

#include "RGE\ObjectList.hpp"
#include "RGE\StaticObject.hpp"
#include "RGE\ActiveSpriteList.hpp"
#include "RGE\ActiveSprite.hpp"
#include "RGE\AnimatedObject.hpp"
#include "RGE\MovingObject.hpp"
#include "RGE\DopplegangerObject.hpp"
#include "RGE\DopplegangerCreator.hpp"
#include "RGE\ActionObject.hpp"
#include "RGE\ActionList.hpp"
#include "RGE\Action.hpp"
#include "RGE\ActionMove.hpp"
#include "RGE\ActionGather.hpp"
#include "RGE\ActionExplore.hpp"
#include "RGE\ActionEnter.hpp"
#include "RGE\ActionAttack.hpp"
#include "RGE\ActionBird.hpp"
#include "RGE\ActionMissile.hpp"
#include "RGE\ActionTransport.hpp"
#include "RGE\CombatObject.hpp"
#include "RGE\MissileObject.hpp"

/* Include Panels: */
#include "RGE\View.hpp"
#include "RGE\MainView.hpp"
#include "RGE\DiamondMap.hpp"
#include "RGE\DiamondMapView.hpp"
#include "RGE\PanelToolBox.hpp"
