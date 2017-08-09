#include "RageJavaCore.hpp"

bool RageJavaCore::initialize(rage::IMultiplayer *mp) {
    this->mp = mp;
    if(!this->initializeJVM()) {
        return false;
    }
    if(!this->initializeEventHandlers()) {
        return false;
    }

    return true;
}

bool RageJavaCore::initializeJVM() {
    if (!JVM::createJavaVirtualMachine()) {
        return false;
    }
    return true;
}

bool RageJavaCore::initializeEventHandlers() {
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
    return true;
}
