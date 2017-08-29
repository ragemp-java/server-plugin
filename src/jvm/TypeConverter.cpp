#include "TypeConverter.hpp"
#include <iomanip>
#include <clocale>
#include <cuchar>
#include <cstring>

std::u16string TypeConverter::fromJStringU16(jstring input) {
    const char *jStringMessage = JVM::getJNIEnv()->GetStringUTFChars(input, nullptr);
    std::u16string wstr = u"";
    char16_t c16str[3] = u"\0";
    mbstate_t mbs;
    for (const auto& it: fromJString(input)){
        memset(&mbs, 0, sizeof (mbs));//set shift state to the initial state
        memmove(c16str, u"\0\0\0", 3);
        mbrtoc16(c16str, &it, 3, &mbs);
        wstr.append(std::u16string(c16str));
    }//for
    return wstr;
}

std::string TypeConverter::fromJString(jstring input) {
    const char *jStringMessage = JVM::getJNIEnv()->GetStringUTFChars(input, nullptr);
    std::string result(jStringMessage);
    return result;
}

jstring TypeConverter::toJString(std::u16string input) {
    std::wstring_convert<std::codecvt_utf8_utf16<int16_t>, int16_t> convert;
    auto p = reinterpret_cast<const int16_t *>(input.data());
    std::string convertedString = convert.to_bytes(p, p + input.size());
    return JVM::getJNIEnv()->NewStringUTF(convertedString.c_str());
}

jstring TypeConverter::toJString(std::string string) {
    return JVM::getJNIEnv()->NewStringUTF(string.c_str());
}

jstring TypeConverter::toJString(const char *input) {
    return JVM::getJNIEnv()->NewStringUTF(input);
}

int TypeConverter::fromJInt(jint input) {
    return (int) input;
}

jint TypeConverter::toJInt(int input) {
    return (jint) input;
}


