/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "RagePlugin.hpp"
#include "RageJavaCore.hpp"

RAGE_API rage::IPlugin *InitializePlugin(rage::IMultiplayer *mp) {
    std::cout << "Initialize Rage MultiPlayer Java Runtime ... " << std::endl;

    if(!RageJavaCore::getInstance().initialize(mp)) {
        return nullptr;
    }

    return new rage::IPlugin;
}
