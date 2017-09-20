/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "VehicleNative.hpp"
#include "../RageJavaCore.hpp"

jint Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_create(JNIEnv *, jclass, jint model, jfloat x, jfloat y, jfloat z, jfloat heading, jint dimension) {
    rage::IMultiplayer *mp = RageJavaCore::getInstance().getMultiPlayer();
    if (mp == nullptr) {
        return -1;
    }
    rage::vector3 position = {x, y, z};
    rage::IVehicle *vehicle = mp->GetVehiclePool().New((uint32_t)model, position, heading, (rage::dimensionId_t)dimension);
    if(vehicle) {
        return (jint)vehicle->GetId();
    }
    return -1;
}
