#pragma once
#ifdef WIN32
#include <windows.h>
#endif
#include <iostream>
#include "sdk/rage.hpp"
#include "event/PlayerEventHandler.hpp"
#include "event/EntityEventHandler.hpp"
#include "event/VehicleEventHandler.hpp"
#include "event/ColshapeEventHandler.hpp"
#include "event/CheckpointEventHandler.hpp"
#include "jvm/JVMException.hpp"
#include "jvm/JVM.hpp"

class RagePlugin
{
public:
	static rage::IMultiplayer *getMultiPlayer();
};
