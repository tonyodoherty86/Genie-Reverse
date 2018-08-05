
/**
 * @file    Engine.cpp
 * @author  Yvan Burrie
 * @date    2018/07/07
 * @version 1.0
 */

#include "Engine\AsmDraw.c"

#include "Engine\DrawSystem.cpp"
#include "Engine\DIB.c"
#include "Engine\DrawArea.cpp"
#include "Engine\RGE\FileIO.c"
#include "Engine\ClipInfo.cpp"
#include "Engine\Picture.cpp"

TDebuggingLog *L;
//#include "Engine\DebuggingLog.cpp"

TSound_Driver *sound_driver,
              *sound_system;
#include "Engine\SoundDriver.cpp"

TChat *chat;
#include "Engine\Chat.cpp"

TCommunications_Handler *comm;
#include "Engine\CommHandler.cpp"

TRegistry *Regs;
//#include "Engine\Registry.cpp"

DriveInformation *driveInfo;
//#include "Engine\DriveInfo.cpp"

#include "Engine\RGE.cpp"
