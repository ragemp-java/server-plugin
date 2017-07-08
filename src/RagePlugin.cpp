#include "RagePlugin.hpp"

static rage::IMultiplayer *multiplayer = nullptr;

RAGE_API rage::IPlugin *InitializePlugin(rage::IMultiplayer *mp) {
    std::cout << "Initialize Rage Multiplayer Java Runtime ... ";
    multiplayer = mp;

    if (!JVM::createJavaVirtualMachine()) {
        return false;
    }

    std::cout << "Registering event handlers ..." << std::endl;

    try {
        mp->AddEventHandler(new PlayerEventHandler);
        mp->AddEventHandler(new EntityEventHandler);
        mp->AddEventHandler(new VehicleEventHandler);
        mp->AddEventHandler(new ColshapeEventHandler);
        mp->AddEventHandler(new CheckpointEventHandler);
    } catch (ClassNotFoundException &e) {
        std::cout << "ClassNotFoundException: " << e.what() << std::endl;
        return false;
    } catch (MethodNotFoundException &e) {
        std::cout << "MethodNotFoundException: " << e.what() << std::endl;
        return false;
    }
    return new rage::IPlugin;
}

rage::IMultiplayer *RagePlugin::getMultiPlayer() {
    return multiplayer;
}
