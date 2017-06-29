#include "RagePlugin.hpp"

RAGE_API rage::IPlugin *InitializePlugin(rage::IMultiplayer *mp)
{
    std::cout << "Initialize Rage Multiplayer Java Runtime..." << std::endl;
//	RagePlugin::setMultiPlayer(mp);
	
	JVM::createJavaVirtualMachine();

	mp->AddEventHandler(new PlayerEventHandler);
	
    return new rage::IPlugin;
}

//rage::IMultiplayer* RagePlugin::getMultiPlayer()
//{
//	return RagePlugin::mp;
//}
//
//void RagePlugin::setMultiPlayer(rage::IMultiplayer* mp)
//{
//	RagePlugin::mp = mp;
//}
