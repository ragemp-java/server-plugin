#include <windows.h>
#include <iostream>
#include "sdk/rage.hpp"
#include "player/PlayerEventHandler.hpp"
//#include "jvm/JVM.hpp"

RAGE_API rage::IPlugin *InitializePlugin(rage::IMultiplayer *mp)
{
    std::cout << "Initialize Rage Multiplayer Java Runtime..." << std::endl;
	//JVM::createJavaVirtualMachine();
	mp->AddEventHandler(new PlayerEventHandler);
    return new rage::IPlugin;
}
