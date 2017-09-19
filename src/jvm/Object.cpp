/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "Object.hpp"

jobject JVM::Object::vector3(float x, float y, float z) {
    jclass clazz = VM::getJNIEnv()->FindClass("mp/rage/plugin/java/api/vector/Vector3");
    jmethodID methodId = VM::getJNIEnv()->GetMethodID(clazz, "<init>", "(FFF)V");
    return VM::getJNIEnv()->NewObject(clazz, methodId, x, y, z);
}

jobject JVM::Object::playerHeadBlend(int shape, int skin, float shapeMix, float skinMix, float thirdMix) {
    jclass clazz = VM::getJNIEnv()->FindClass("mp/rage/plugin/java/api/player/PlayerHeadBlend");
    jmethodID methodId = VM::getJNIEnv()->GetMethodID(clazz, "<init>", "(IIFFF)V");
    return VM::getJNIEnv()->NewObject(clazz, methodId, shape, skin, shapeMix, skinMix, thirdMix);
}
