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

#include <jni.h>
#include <vector>
#include "VM.hpp"

namespace JVM {
    class Object {
    public:
        static void initialize(JNIEnv *env);

        static jobject vector3(JNIEnv *env, float x, float y, float z);
        static jobject playerHeadBlend(JNIEnv *env, int shape, int skin, float shapeMix, float skinMix, float thirdMix);
        static jobject rgbColor(JNIEnv *env, int red, int green, int blue);
        static jobject rgbaColor(JNIEnv *env, int red, int green, int blue, int alpha);

        static jobject intArrayList(JNIEnv *env, std::vector<int> ids);
    };
}