/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "CheckpointNative.hpp"
#include "../RageJavaCore.hpp"

jint Java_mp_rage_launcher_checkpoint_CheckpointNative_create(JNIEnv *, jclass, jint type, jfloat x, jfloat y, jfloat z,
                                                                     jfloat nX, jfloat nY, jfloat nZ, jfloat radius, jint red, jint green, jint blue,
                                                                     jint alpha, jboolean visible, jint dimension) {
    rage::IMultiplayer *mp = RageJavaCore::getInstance().getMultiPlayer();
    if (mp == nullptr) {
        return -1;
    }
    rage::vector3 position = {x, y, z};
    rage::vector3 nextPosition = {nX, nY, nZ};
    rage::rgba_t color = {(uint8_t)red, (uint8_t)green, (uint8_t)blue, (uint8_t)alpha};
    return (jint)mp->GetCheckpointPool().New((uint8_t)type, position, nextPosition, radius, color, (bool)visible, (rage::dimensionId_t) dimension)->GetId();
}
