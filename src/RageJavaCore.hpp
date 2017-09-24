/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#pragma once

#include "jvm/VM.hpp"
#include "jvm/Exception.hpp"
#include "event/PlayerEventHandler.hpp"
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
    rage::IMultiplayer *mp;
};

