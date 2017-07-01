#include "PlayerEventHandler.hpp"
#include "../jvm/JVM.hpp"
#include "../RagePlugin.hpp"

static rage::IPlayer *splayer = nullptr;

rage::IPlayerHandler *PlayerEventHandler::GetPlayerHandler() {
    return this;
}

void PlayerEventHandler::OnPlayerJoin(rage::IPlayer *player) {
    splayer = player;
    std::cout << "Player with ID: " << player->GetId() << std::endl;
}

void PlayerEventHandler::OnPlayerCommand(rage::IPlayer *player, const std::u16string &command) {
    JNIEnv* env = JVM::getJNIEnv();
    jclass jcls = env->FindClass("de/demofire/ragemultiplayer/launcher/event/PlayerEvents");
    if(jcls == NULL)
    {
        std::cout << "class is null" << std::endl;
        return;
    }
    jmethodID methodId = env->GetStaticMethodID(jcls, "onPlayerCommand", "(ILjava/lang/String;)V");
    if (methodId == NULL)
    {
        std::cout << "method is null" << std::endl;
        return;
    }

    std::cout << player->GetId();
    uint16_t playerId = player->GetId();
    jint id = (jint) playerId;

    env->CallStaticVoidMethod(jcls, methodId, id, NULL);
    JVM::checkForException();
}

void PlayerEventHandler::OnPlayerQuit(rage::IPlayer *player, rage::exit_t exitType, const char *reason) {

}

void PlayerEventHandler::OnPlayerSpawn(rage::IPlayer *player) {

}

void PlayerEventHandler::OnPlayerChat(rage::IPlayer *player, const std::u16string &text) {
    std::cout << "playerChatEvent" << std::endl;
    player->OutputChatBox(text);
    player->OutputChatBox(u"hey");
}

void PlayerEventHandler::OnPlayerEnterVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) {

}

void PlayerEventHandler::OnPlayerEnteredVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) {

}

void PlayerEventHandler::OnPlayerExitVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) {

}

void PlayerEventHandler::OnPlayerLeftVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) {

}

void PlayerEventHandler::OnPlayerDeath(rage::IPlayer *player, rage::hash_t reason, rage::IPlayer *killer) {

}

void PlayerEventHandler::OnPlayerRemoteEvent(rage::IPlayer *player, const std::string &eventName, const rage::args_t &args) {

}

rage::IPlayer *PlayerEventHandler::GetPlayer() {
    return splayer;
}


