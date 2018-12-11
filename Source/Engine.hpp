
/**
 * @file    Engine.hpp
 * @author  Yvan Burrie
 * @date    2018/08/06
 * @version 1.0
 */
#ifndef ENGINE_H

#define ENGINE_H


#define ENGINE_ROR 1
#define ENGINE_AOK 1
#define ENGINE_AOC 1

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include essential components: */

#include "Engine/ResFile.h"
#include "Engine/DIB.h"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include graphical components: */

#include "Engine/SpanList.hpp"
#include "Engine/DrawSystem.hpp"
#include "Engine/DrawArea.hpp"
#include "Engine/Shape.hpp"
#include "Engine/AsmDraw.h"
#include "Engine/MousePointer.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include audible components: */

#include "Engine/SoundDriver.hpp"
#include "Engine/Digital.hpp"
#include "Engine/Music.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include communication components: */
#include "Engine/CommHandler.hpp"
#include "Engine/CommSessions.hpp"
#include "Engine/CommServices.hpp"
#include "Engine/Chat.hpp"
#include "Engine/Taunt.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Engine/DriveInfo.hpp"
#include "Engine/DebuggingLog.hpp"
#include "Engine/Registry.hpp"
#include "Engine/ManagedArray.hpp"

#include "Engine/Picture.hpp"
#include "Engine/ClipInfo.hpp"
#include "Engine/Fractal.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include panel components: */

#include "Engine/Panel.hpp"
#include "Engine/Panel_ScrollBar.hpp"
#include "Engine/Panel_Text.hpp"
#include "Engine/Panel_Button.hpp"
#include "Engine/Panel_Input.hpp"
#include "Engine/Panel_Edit.hpp"
#include "Engine/Panel_List.hpp"
#include "Engine/Panel_DropDown.hpp"
#include "Engine/Panel_Slider.hpp"
#include "Engine/Panel_Picture.hpp"
#include "Engine/Panel_ScrollText.hpp"

#include "Engine/Panel_DropDownButton.hpp"
#include "Engine/Panel_Easy.hpp"
#include "Engine/Panel_Screen.hpp"
#include "Engine/Panel_Message.hpp"

#include "Engine/Panel_Dialog.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include RGE components: */

#include "Engine/RGE.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////
/* Include TRB components: */

#include "Engine/TRB.hpp"

////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // ENGINE_H
