
/**
 * @file    Main.cpp
 * @author  Yvan Burrie
 * @date    2018/06/30
 * @version 1.0
 */

#include "Main.hpp"

HWND AppWnd;

HINSTANCE *AppInst;

#include "Engine\AsmDraw.c"
#include "Engine\DrawSystem.cpp"
#include "Engine\DIB.c"
#include "Engine\DrawArea.cpp"
#include "Engine\RGE\FileIO.c"
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

//#include "Engine\RGE\BaseGame.cpp"
//#include "Engine\RGE\GameWorld.cpp"
//#include "Engine\RGE\Sprite.cpp"
//#include "Engine\RGE\MasterCombatObject.cpp"
//#include "Engine\RGE\ActiveSpriteList.cpp"
//#include "Engine\RGE\ActiveSprite.cpp"
//#include "Engine\RGE\Map.cpp"

using namespace std;

int main()
{
    cout << "Initializing new GAME" << endl;

    //TRIBE_Game *Game = new TRIBE_Game();

    return 0;
}
