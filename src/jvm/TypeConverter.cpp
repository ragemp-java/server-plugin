#include "TypeConverter.hpp"


//#if _MSC_VER == 1900

//std::string utf16_to_utf8(std::u16string utf16_string)
//{
//    std::cout << "cast 1";
//    std::wstring_convert<std::codecvt_utf8_utf16<int16_t>, int16_t> convert;
//    std::cout << "cast 2";
//    auto p = reinterpret_cast<const int16_t *>(utf16_string.data());
//    std::cout << "cast 3";
//    return convert.to_bytes(p, p + utf16_string.size());
//}
//
//#else
//
//std::string utf16_to_utf8(std::u16string utf16_string)
//{
//    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
//    return convert.to_bytes(utf16_string);
//}
//
//#endif

std::u16string TypeConverter::fromJString(jstring input) {
    const char *jStringMessage = JVM::getJNIEnv()->GetStringUTFChars(input, NULL);
    const char16_t *stringMessage = (const char16_t *) jStringMessage;
    std::u16string outputString = stringMessage;
    return outputString;
}

jstring TypeConverter::toJString(std::u16string input) {
    std::wstring_convert<std::codecvt_utf8_utf16<int16_t>, int16_t> convert;
    auto p = reinterpret_cast<const int16_t *>(input.data());
    std::string convertedString = convert.to_bytes(p, p + input.size());
    return JVM::getJNIEnv()->NewStringUTF(convertedString.c_str());
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


