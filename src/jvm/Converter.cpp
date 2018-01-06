/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "Converter.hpp"

//std::u16string JVM::Converter::toU16string(JNIEnv *env, jstring input) {
//    const char *jStringMessage = VM::getJNIEnv()->GetStringUTFChars(input, nullptr);
//    std::u16string wstr = u"";
//    char16_t c16str[3] = u"\0";
//    mbstate_t mbs;
//    for (const auto &it: toString(input)) {
//        memset(&mbs, 0, sizeof(mbs));
//        memmove(c16str, u"\0\0\0", 3);
//        mbrtoc16(c16str, &it, 3, &mbs);
//        wstr.append(std::u16string(c16str));
//    }
//    return wstr;
//}

std::string JVM::Converter::toString(JNIEnv *env, jstring input) {
    const char *jStringMessage = env->GetStringUTFChars(input, nullptr);
    std::string result(jStringMessage);
    env->ReleaseStringUTFChars(input, jStringMessage);
    return result;
}

jstring JVM::Converter::toJString(JNIEnv *env, std::u16string input) {
    std::wstring_convert<std::codecvt_utf8_utf16<int16_t>, int16_t> convert;
    auto p = reinterpret_cast<const int16_t *>(input.data());
    std::string convertedString = convert.to_bytes(p, p + input.size());
    return env->NewStringUTF(convertedString.c_str());
}

jstring JVM::Converter::toJString(JNIEnv *env, std::string string) {
    return env->NewStringUTF(string.c_str());
}

jstring JVM::Converter::toJString(JNIEnv *env, const char *input) {
    return env->NewStringUTF(input);
}

std::vector<int> JVM::Converter::toIntVector(JNIEnv *env, jintArray array) {
    std::vector<int> playerIds;
    int length = env->GetArrayLength(array);
    jint *body = env->GetIntArrayElements(array, nullptr);
    for (int i = 0; i < length; i++) {
        playerIds.push_back(body[i]);
    }
    env->ReleaseIntArrayElements(array, body, JNI_ABORT);
    return playerIds;
}
