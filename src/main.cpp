
/**
 * @file    main.cpp
 * @author  Yvan Burrie
 * @date    2018/02/19
 * @version 1.0
 */

#include <iostream>
#include <io.h>

/* Include Windows components: */
#include <windows.h>
#include <wingdi.h>

/* Include Direct-X components: */
#include <d3d9.h>
#include "dxsdk\Include\dsound.h"
#include "dxsdk\Include\ddraw.h"
#include "dxsdk\Include\dplay.h"
#include "dxsdk\Include\dplobby.h"

#include "ida.h"

#define ENGINE_ROR 1
#define ENGINE_AOK 1
#define ENGINE_AOC 1

#define ENGINE_TRB 1

class RGE_Base_Game *rge_base_game;

/* Inlcude core essential components: */
#include "Engine\ResFile.h"
#include "Engine\DIB.h"

/* Include core graphical components: */
#include "Engine\SpanList.hpp"
#include "Engine\DrawSystem.hpp"
#include "Engine\DrawArea.hpp"
#include "Engine\AsmDraw.h"
#include "Engine\Shape.hpp"
#include "Engine\MousePointer.hpp"

/* Include core audible components: */
#include "Engine\SoundDriver.hpp"
#include "Engine\Digital.hpp"
#include "Engine\Music.hpp"

/* Include core communication components: */
#include "Engine\CommHandler.hpp"
#include "Engine\Chat.hpp"
#include "Engine\Taunt.hpp"

#include "Engine\DebuggingLog.hpp"
#include "Engine\Registry.hpp"
#include "Engine\ManagedArray.hpp"

#include "Engine\Picture.hpp"
#include "Engine\ClipInfo.hpp"

/* Include core panel components: */
#include "Engine\Panel.hpp"
#include "Engine\ScrollBarPanel.hpp"
#include "Engine\TextPanel.hpp"
#include "Engine\ButtonPanel.hpp"
#include "Engine\InputPanel.hpp"
#include "Engine\EditPanel.hpp"
#include "Engine\ListPanel.hpp"
#include "Engine\PanelDropDown.hpp"
#include "Engine\PanelSlider.hpp"
#include "Engine\EasyPanel.hpp"

#include "Engine\PicturePanel.hpp"
#include "Engine\MessagePanel.hpp"

//typedef TDropDownPanel::ActionType TListPanel::ActionType;

#include "Engine\RGE\FileIO.h"
#include "Engine\RGE\BaseGame.hpp"
#include "Engine\RGE\GameInfo.hpp"
#include "Engine\RGE\Campaign.hpp"

/* Include RGE communications components: */
#include "Engine\RGE\CommQueue.hpp"
#include "Engine\RGE\CommLobby.hpp"
#include "Engine\RGE\TimeSinceLastCall.hpp"
#include "Engine\RGE\CommSpeed.hpp"
#include "Engine\RGE\CommSync.hpp"
#include "Engine\RGE\CommAddresses.hpp"
#include "Engine\RGE\CommError.hpp"

#include "Engine\RGE\GameWorld.hpp"
#include "Engine\RGE\ColorTable.hpp"
#include "Engine\RGE\Sound.hpp"
#include "Engine\RGE\Sprite.hpp"
#include "Engine\RGE\Map.hpp"
#include "Engine\RGE\RmmBase.hpp"
#include "Engine\RGE\RmmController.hpp"
#include "Engine\RGE\RmmDbController.hpp"

class RGE_Static_Object;
class RGE_Animated_Object;
class RGE_Moving_Object;
class RGE_Action_Object;
class RGE_Combat_Object;
class RGE_Missile_Object;

#include "Engine\RGE\MasterPlayer.hpp"
#include "Engine\RGE\MasterStaticObject.hpp"
#include "Engine\RGE\MasterAnimatedObject.hpp"
#include "Engine\RGE\MasterDoppleObject.hpp"
#include "Engine\RGE\MasterMovingObject.hpp"
#include "Engine\RGE\MasterActionObject.hpp"
#include "Engine\RGE\TaskList.hpp"
#include "Engine\RGE\Task.hpp"
#include "Engine\RGE\MasterCombatObject.hpp"
#include "Engine\RGE\MasterMissileObject.hpp"

#include "Engine\RGE\Path.hpp"
#include "Engine\RGE\Player.hpp"
#include "Engine\RGE\VisibleMap.hpp"
#include "Engine\RGE\AiResourceItem.hpp"
#include "Engine\RGE\AiPlay.hpp"
#include "Engine\RGE\AiUnitModule.hpp"
#include "Engine\RGE\Effects.hpp"
#include "Engine\RGE\VictoryConditions.hpp"

#include "Engine\RGE\Timeline.hpp"
#include "Engine\RGE\Scenario.hpp"
#include "Engine\RGE\Command.hpp"

#include "Engine\RGE\ObjectList.hpp"
#include "Engine\RGE\StaticObject.hpp"
#include "Engine\RGE\ActiveSpriteList.hpp"
#include "Engine\RGE\ActiveSprite.hpp"
#include "Engine\RGE\AnimatedObject.hpp"
#include "Engine\RGE\ZoneMap.hpp"
#include "Engine\RGE\MovingObject.hpp"
#include "Engine\RGE\DopplegangerObject.hpp"
#include "Engine\RGE\DopplegangerCreator.hpp"
#include "Engine\RGE\ActionObject.hpp"
#include "Engine\RGE\ActionList.hpp"
#include "Engine\RGE\Action.hpp"
#include "Engine\RGE\CombatObject.hpp"
#include "Engine\RGE\MissileObject.hpp"

#include "Engine\RGE\InfluenceMap.hpp"

#include "Engine\RGE\View.hpp"
#include "Engine\RGE\DiamondMap.hpp"
#include "Engine\RGE\DiamondMapView.hpp"

#if ENGINE_TRB

#include "Engine\TRB\Game.hpp"

//#include "Engine\TRB\ScreenGame.hpp"

#include "Engine\TRB\World.hpp"
#include "Engine\TRB\Map.hpp"
#include "Engine\TRB\MasterPlayer.hpp"
#include "Engine\TRB\TaskList.hpp"
#include "Engine\TRB\MasterTreeObject.hpp"
#include "Engine\TRB\MasterCombatObject.hpp"
#include "Engine\TRB\MasterBuildingObject.hpp"
#include "Engine\TRB\Effects.hpp"
#include "Engine\TRB\Technology.hpp"
class TRIBE_Tree_Object;
class TRIBE_Combat_Object;
class TRIBE_Building_Object;
#include "Engine\TRB\Player.hpp"
#include "Engine\TRB\Scenario.hpp"
#ifdef ENGINE_TRIGGERS_SYSTEM_EXISTS
#include "Engine\TRB\Triggers.hpp"
#endif
#include "Engine\TRB\History.hpp"
#include "Engine\TRB\VictoryConditions.hpp"
#include "Engine\TRB\ObjectList.hpp"
#include "Engine\TRB\ActionList.hpp"
#include "Engine\TRB\TreeObject.hpp"
#include "Engine\TRB\CombatObject.hpp"
#include "Engine\TRB\BuildingObject.hpp"

#include "Engine\TRB\DiamondMapView.hpp"

#endif

#include "Engine\AsmDraw.c"
#include "Engine\DrawSystem.cpp"
#include "Engine\DIB.c"
#include "Engine\DrawArea.cpp"
#include "Engine\Picture.cpp"

#include "Engine\RGE\FileIO.c"

#include "Engine\RGE\BaseGame.cpp"
#include "Engine\RGE\GameWorld.cpp"
#include "Engine\RGE\Map.cpp"

using namespace std;

int main()
{
    cout << "Initializing new GAME" << endl;

    //TRIBE_Game *Game = new TRIBE_Game();

    return 0;
}
