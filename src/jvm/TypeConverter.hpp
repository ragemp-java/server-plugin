#pragma once

#include <string>
#include <iostream>
#include <codecvt>

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

