#pragma once

#include "jvm/JVM.hpp"
#include "event/PlayerEventHandler.hpp"
#include "event/EntityEventHandler.hpp"
#include "event/VehicleEventHandler.hpp"
#include "event/CheckpointEventHandler.hpp"
#include "event/ColshapeEventHandler.hpp"

#include "sdk/rage.hpp"

class RageJavaCore {
public:
    static RageJavaCore& getInstance() {
        static RageJavaCore rageJavaCore;
        return rageJavaCore;
    }
    rage::IMultiplayer *getMultiPlayer() {
        return mp;
    }

    bool initialize(rage::IMultiplayer *mp);

private:
    bool initializeJVM();
    bool initializeEventHandlers();

    rage::IMultiplayer *mp;
};

