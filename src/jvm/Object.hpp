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
#include "VM.hpp"

namespace JVM {
    class Object {
    public:
        static jobject vector3(float x, float y, float z);
        static jobject playerHeadBlend(int shape, int skin, float shapeMix, float skinMix, float thirdMix);
    };
}