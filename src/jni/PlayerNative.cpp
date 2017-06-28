#include "PlayerNative.h"
#include <iostream>
#include "../jvm/JVM.hpp"

void __stdcall Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_kick(JNIEnv*env, jobject, jstring reason)
{
	std::cout << env->GetStringUTFChars(reason, NULL) << " JVM result" << std::endl;
}
