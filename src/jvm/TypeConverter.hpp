#pragma once

#include <string>
#include <iostream>
#include <codecvt>

#include <jni.h>
#include "JVM.hpp"

class TypeConverter {
public:
    static std::u16string fromJString(jstring input);
    static jstring toJString(std::u16string input);
    static jstring toJString(const char* input);
    static jint toJInt(int input);
    static int fromJInt(jint input);
};

