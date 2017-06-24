#include <windows.h>
#include <iostream>
#include "RagePlugin.hpp"


RAGE_API rage::IPlugin *InitializePlugin(rage::IMultiplayer *mp)
{
    std::cout << "Initialize Java RageMP Plugin..." << std::endl;

    return new rage::IPlugin;
}