#include "PlayerNative.hpp"
#include <iostream>
#include "../RagePlugin.hpp"

void __stdcall Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_kick(JNIEnv *env, jobject, jint id, jstring reason) {
    std::cout << env->GetStringUTFChars(reason, NULL) << " JVM result" << std::endl;
}

void __stdcall Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_outputChatBox(JNIEnv *env, jobject, jint id, jstring message) {

}
