#include "PlayerEventHandler.hpp"

rage::IPlayerHandler *PlayerEventHandler::GetPlayerHandler() {
    return this;
}

PlayerEventHandler::PlayerEventHandler() {
    playerEventClass = JVM::getClass(playerEventClassName);
    playerJoinMethod = JVM::getStaticMethod(playerEventClass, "onPlayerJoin", "(I)V");
    playerCommandMethod = JVM::getStaticMethod(playerEventClass, "onPlayerCommand", "(ILjava/lang/String;)V");
    playerQuitMethod = JVM::getStaticMethod(playerEventClass, "onPlayerQuit", "(IILjava/lang/String;)V");
    playerSpawnMethod = JVM::getStaticMethod(playerEventClass, "onPlayerSpawn", "(I)V");
    playerChatMethod = JVM::getStaticMethod(playerEventClass, "onPlayerChat", "(ILjava/lang/String;)V");
    playerEnterVehicleMethod = JVM::getStaticMethod(playerEventClass, "onPlayerEnterVehicle", "(III)V");
    playerEnteredVehicleMethod = JVM::getStaticMethod(playerEventClass, "onPlayerEnteredVehicle", "(III)V");
    playerExitVehicleMethod = JVM::getStaticMethod(playerEventClass, "onPlayerExitVehicle", "(II)V");
    playerLeftVehicleMethod = JVM::getStaticMethod(playerEventClass, "onPlayerExitVehicle", "(II)V");
    playerDeathMethod = JVM::getStaticMethod(playerEventClass, "onPlayerDeath", "(III)V");
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
    jint playerId = TypeConverter::toJInt(player->GetId());
    jint jExitType = TypeConverter::toJInt((int)exitType);
    jstring jReason = TypeConverter::toJString(reason);
    JVM::callStaticMethod(playerEventClass, playerQuitMethod, playerId, jExitType, jReason);
}

void PlayerEventHandler::OnPlayerSpawn(rage::IPlayer *player) {
    jint playerId = TypeConverter::toJInt(player->GetId());
    JVM::callStaticMethod(playerEventClass, playerSpawnMethod, playerId);
}

void PlayerEventHandler::OnPlayerChat(rage::IPlayer *player, const std::u16string &text) {
    jint playerId = TypeConverter::toJInt(player->GetId());
    jstring jText = TypeConverter::toJString(text);
    JVM::callStaticMethod(playerEventClass, playerChatMethod, playerId, jText);
}

void PlayerEventHandler::OnPlayerEnterVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) {
    jint playerId = TypeConverter::toJInt(player->GetId());
    jint vehicleId = TypeConverter::toJInt(vehicle->GetId());
    jint jSeatId = TypeConverter::toJInt(seatId);
    JVM::callStaticMethod(playerEventClass, playerEnterVehicleMethod, playerId, vehicleId, jSeatId);
}

void PlayerEventHandler::OnPlayerEnteredVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) {
    jint playerId = TypeConverter::toJInt(player->GetId());
    jint vehicleId = TypeConverter::toJInt(vehicle->GetId());
    jint jSeatId = TypeConverter::toJInt(seatId);
    JVM::callStaticMethod(playerEventClass, playerEnteredVehicleMethod, playerId, vehicleId, jSeatId);
}

void PlayerEventHandler::OnPlayerExitVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) {
    jint playerId = TypeConverter::toJInt(player->GetId());
    jint vehicleId = TypeConverter::toJInt(vehicle->GetId());
    JVM::callStaticMethod(playerEventClass, playerExitVehicleMethod, playerId, vehicleId);
}

void PlayerEventHandler::OnPlayerLeftVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) {
    jint playerId = TypeConverter::toJInt(player->GetId());
    jint vehicleId = TypeConverter::toJInt(vehicle->GetId());
    JVM::callStaticMethod(playerEventClass, playerLeftVehicleMethod, playerId, vehicleId);
}

void PlayerEventHandler::OnPlayerDeath(rage::IPlayer *player, rage::hash_t reason, rage::IPlayer *killer) {
    jint playerId = TypeConverter::toJInt(player->GetId());
    jint jReason = TypeConverter::toJInt(reason);
    jint killerId = TypeConverter::toJInt(killer->GetId());
    JVM::callStaticMethod(playerEventClass, playerDeathMethod, playerId, jReason, killerId);
}

void PlayerEventHandler::OnPlayerRemoteEvent(rage::IPlayer *player, const std::string &eventName, const rage::args_t &args) {
    jint playerId = TypeConverter::toJInt(player->GetId());
}


