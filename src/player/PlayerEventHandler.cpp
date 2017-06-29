#include "PlayerEventHandler.hpp"

rage::IPlayerHandler *PlayerEventHandler::GetPlayerHandler() {
    return this;
}

void PlayerEventHandler::OnPlayerJoin(rage::IPlayer *player) {

}

void PlayerEventHandler::OnPlayerCommand(rage::IPlayer *player, const std::u16string &command) {

}

void PlayerEventHandler::OnPlayerQuit(rage::IPlayer *player, rage::exit_t exitType, const char *reason) {

}

void PlayerEventHandler::OnPlayerSpawn(rage::IPlayer *player) {

}

void PlayerEventHandler::OnPlayerChat(rage::IPlayer *player, const std::u16string &text) {

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
