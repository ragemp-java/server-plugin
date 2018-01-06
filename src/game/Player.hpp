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

#include "../sdk/rage.hpp"
#include "../sdk/Entities.hpp"
#include "../RageJavaCore.hpp"

namespace Game {
    class Player {
    public:
        static rage::IPlayer *getPlayerById(JNIEnv *env, int playerId);
    };
}
