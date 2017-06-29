#include "PlayerNative.h"
#include <iostream>
#include "../RagePlugin.hpp"

void __stdcall Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_kick(JNIEnv* env, jobject, jint id, jstring reason)
{
	std::cout << env->GetStringUTFChars(reason, NULL) << " JVM result" << std::endl;
}


void __stdcall Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_outputChatBox(JNIEnv* env, jobject, jint id, jstring message)
{
//	rage::IPlayer *player = RagePlugin::getMultiPlayer()->GetPlayerPool().GetAt(int(id));
//	if(player == NULL)
//	{
//		std::cout << "Player not found in pool. Id: " << id << std::endl;
//		return;
//	}
//	player->OutputChatBox(env->GetStringUTFChars(message, NULL));
}
