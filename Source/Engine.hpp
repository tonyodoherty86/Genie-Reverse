
/**
 * @file    Engine.hpp
 * @author  Yvan Burrie
 * @date    2018/08/05
 * @version 1.0
 */

#define ENGINE_ROR 1
#define ENGINE_AOK 1
#define ENGINE_AOC 1

#ifndef ENGINE_H
#define ENGINE_H

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include essential components: */

#include "Engine\ResFile.h"
#include "Engine\DIB.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include graphical components: */

#include "Engine\SpanList.hpp"
#include "Engine\DrawSystem.hpp"
#include "Engine\DrawArea.hpp"
#include "Engine\Shape.hpp"
#include "Engine\AsmDraw.h"
#include "Engine\MousePointer.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include audible components: */

#include "Engine\SoundDriver.hpp"
#include "Engine\Digital.hpp"
#include "Engine\Music.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include communication components: */

#define PLAYERS_ITERATIONS 9

#include "Engine\CommHandler.hpp"
#include "Engine\CommSessions.hpp"
#include "Engine\CommServices.hpp"
#include "Engine\Chat.hpp"
#include "Engine\Taunt.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Engine\DriveInfo.hpp"
#include "Engine\DebuggingLog.hpp"
#include "Engine\Registry.hpp"
#include "Engine\ManagedArray.hpp"

#include "Engine\Picture.hpp"
#include "Engine\ClipInfo.hpp"
#include "Engine\Fractal.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include panel components: */

#include "Engine\Panel.hpp"
#include "Engine\ScrollBarPanel.hpp"
#include "Engine\TextPanel.hpp"
#include "Engine\ButtonPanel.hpp"
#include "Engine\InputPanel.hpp"
#include "Engine\EditPanel.hpp"
#include "Engine\ListPanel.hpp"
#include "Engine\PanelDropDown.hpp"
#include "Engine\PanelSlider.hpp"
#include "Engine\PanelEasy.hpp"
#include "Engine\PanelScreen.hpp"
#include "Engine\PicturePanel.hpp"
#include "Engine\MessagePanel.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include RGE components: */

#include "Engine\RGE.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include TRB components: */

#include "Engine\TRB.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // ENGINE_H
