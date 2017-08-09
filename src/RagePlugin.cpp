#include "RagePlugin.hpp"
#include "RageJavaCore.hpp"

RAGE_API rage::IPlugin *InitializePlugin(rage::IMultiplayer *mp) {
    std::cout << "Initialize Rage MultiPlayer Java Runtime ... " << std::endl;

    if(!RageJavaCore::getInstance().initialize(mp)) {
        return false;
    }

    return new rage::IPlugin;
}
