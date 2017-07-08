#include "PlayerEventHandler.hpp"



PlayerEventHandler::PlayerEventHandler() {
    playerEventClass = JVM::getClass(playerEventClassName);
    playerJoinMethod = JVM::getStaticMethod(playerEventClass, "onPlayerJoin", "(I)V");
    playerCommandMethod = JVM::getStaticMethod(playerEventClass, "onPlayerCommand", "(ILjava/lang/String;)V");
}

rage::IPlayerHandler *PlayerEventHandler::GetPlayerHandler() {
    return this;
}

void PlayerEventHandler::OnPlayerJoin(rage::IPlayer *player) {
    jint playerId = TypeConverter::toJInt(player->GetId());
    JVM::callStaticMethod(playerEventClass, playerJoinMethod, playerId);
}

void PlayerEventHandler::OnPlayerCommand(rage::IPlayer *player, const std::u16string &command) {
    jint playerId = TypeConverter::toJInt(player->GetId());
    jstring jCommand = TypeConverter::toJString(command);
    JVM::callStaticMethod(playerEventClass, playerCommandMethod, playerId, jCommand);
}

void PlayerEventHandler::OnPlayerQuit(rage::IPlayer *player, rage::exit_t exitType, const char *reason) {

}

void PlayerEventHandler::OnPlayerSpawn(rage::IPlayer *player) {

}

void PlayerEventHandler::OnPlayerChat(rage::IPlayer *player, const std::u16string &text) {
    std::cout << "playerChatEvent" << std::endl;
    player->OutputChatBox(u"Tobias ist ein Kek");
    player->OutputChatBox(text);
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


