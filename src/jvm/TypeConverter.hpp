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

#include <string>
#include <iostream>
#include <codecvt>
#include <iomanip>
#include <clocale>
#include <cuchar>
#include <cstring>

#include <jni.h>
#include "JVM.hpp"

class TypeConverter {
public:
    static std::u16string fromJStringU16(jstring input);
    static std::string fromJString(jstring input);
    static jstring toJString(std::u16string input);
    static jstring toJString(const char* input);
    static jstring toJString(std::string string);
    static jint toJInt(int input);
    static int fromJInt(jint input);
};

