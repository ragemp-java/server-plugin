#include "RagePlugin.hpp"

static rage::IMultiplayer *multiplayer = nullptr;

RAGE_API rage::IPlugin *InitializePlugin(rage::IMultiplayer *mp) {
    std::cout << "Initialize Rage Multiplayer Java Runtime ... ";
    multiplayer = mp;

    if (!JVM::createJavaVirtualMachine()) {
        return false;
    }

    std::cout << "Registering event handlers ...";
    mp->AddEventHandler(new PlayerEventHandler);
    mp->AddEventHandler(new EntityEventHandler);
    mp->AddEventHandler(new VehicleEventHandler);
    mp->AddEventHandler(new ColshapeEventHandler);
    mp->AddEventHandler(new CheckpointEventHandler);

    return new rage::IPlugin;
}

rage::IMultiplayer *RagePlugin::getMultiPlayer() {
    return multiplayer;
}
