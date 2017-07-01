#include "PlayerNative.h"
#include <iostream>
#include "../RagePlugin.hpp"

void __stdcall Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_kick(JNIEnv* env, jobject, jint id, jstring reason)
{
	std::cout << env->GetStringUTFChars(reason, NULL) << " JVM result" << std::endl;
}


void __stdcall Java_de_demofire_ragemultiplayer_launcher_player_PlayerNative_outputChatBox(JNIEnv* env, jobject, jint id, jstring message)
{
//    rage::IMultiplayer *mp = RagePlugin::getMultiPlayer();
//    if(mp == NULL) {
//        std::cout << "mp is null";
//        return;
//    }
//    const rage::IPlayerPool pool = mp->GetPlayerPool();
//	rage::IPlayer *event = pool.GetAt(0);
//	if(event == NULL)
//	{
//		std::cout << "Player not found in pool. Id: " << id << std::endl;
//		return;
//	}
    std::cout << "native call at outputChatBox" << std::endl;
    const char* jStringMessage = env->GetStringUTFChars(message, NULL);
    const char16_t *stringMessage = (const char16_t*)jStringMessage;
    std::u16string outputString = stringMessage;
    rage::IPlayer *player = PlayerEventHandler::GetPlayer();
    if(player == NULL) {
        std::cout << "event is null" << std::endl;
    }
    PlayerEventHandler::GetPlayer()->OutputChatBox(u"test");
	PlayerEventHandler::GetPlayer()->OutputChatBox(stringMessage);
}
