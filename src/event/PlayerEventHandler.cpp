/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "PlayerEventHandler.hpp"

rage::IPlayerHandler *PlayerEventHandler::GetPlayerHandler() {
    return this;
}

PlayerEventHandler::PlayerEventHandler() {
    playerEventClass = JVM::VM::getClass(playerEventClassName);
    playerJoinMethod = JVM::VM::getStaticMethod(playerEventClass, "onPlayerJoin", "(I)V");
    playerCommandMethod = JVM::VM::getStaticMethod(playerEventClass, "onPlayerCommand", "(ILjava/lang/String;)V");
    playerQuitMethod = JVM::VM::getStaticMethod(playerEventClass, "onPlayerQuit", "(IILjava/lang/String;)V");
    playerSpawnMethod = JVM::VM::getStaticMethod(playerEventClass, "onPlayerSpawn", "(I)V");
    playerChatMethod = JVM::VM::getStaticMethod(playerEventClass, "onPlayerChat", "(ILjava/lang/String;)V");
    playerEnterVehicleMethod = JVM::VM::getStaticMethod(playerEventClass, "onPlayerEnterVehicle", "(III)V");
    playerEnteredVehicleMethod = JVM::VM::getStaticMethod(playerEventClass, "onPlayerEnteredVehicle", "(III)V");
    playerExitVehicleMethod = JVM::VM::getStaticMethod(playerEventClass, "onPlayerExitVehicle", "(II)V");
    playerLeftVehicleMethod = JVM::VM::getStaticMethod(playerEventClass, "onPlayerExitVehicle", "(II)V");
    playerDeathMethod = JVM::VM::getStaticMethod(playerEventClass, "onPlayerDeath", "(III)V");
}

void PlayerEventHandler::OnPlayerJoin(rage::IPlayer *player) {
    jint playerId = JVM::Converter::toJInt(player->GetId());
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerJoinMethod, playerId);
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerCommand(rage::IPlayer *player, const std::u16string &command) {
    jint playerId = JVM::Converter::toJInt(player->GetId());
    jstring jCommand = JVM::Converter::toJString(command);
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerCommandMethod, playerId, jCommand);
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerQuit(rage::IPlayer *player, rage::exit_t exitType, const char *reason) {
    jint playerId = JVM::Converter::toJInt(player->GetId());
    jint jExitType = JVM::Converter::toJInt((int)exitType);
    jstring jReason = JVM::Converter::toJString(reason);
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerQuitMethod, playerId, jExitType, jReason);
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerSpawn(rage::IPlayer *player) {
    jint playerId = JVM::Converter::toJInt(player->GetId());
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerSpawnMethod, playerId);
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerChat(rage::IPlayer *player, const std::u16string &text) {
    jint playerId = JVM::Converter::toJInt(player->GetId());
    jstring jText = JVM::Converter::toJString(text);
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerChatMethod, playerId, jText);
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerEnterVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) {
    jint playerId = JVM::Converter::toJInt(player->GetId());
    jint vehicleId = JVM::Converter::toJInt(vehicle->GetId());
    jint jSeatId = JVM::Converter::toJInt(seatId);
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerEnterVehicleMethod, playerId, vehicleId, jSeatId);
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerEnteredVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) {
    jint playerId = JVM::Converter::toJInt(player->GetId());
    jint vehicleId = JVM::Converter::toJInt(vehicle->GetId());
    jint jSeatId = JVM::Converter::toJInt(seatId);
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerEnteredVehicleMethod, playerId, vehicleId, jSeatId);
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerExitVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) {
    jint playerId = JVM::Converter::toJInt(player->GetId());
    jint vehicleId = JVM::Converter::toJInt(vehicle->GetId());
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerExitVehicleMethod, playerId, vehicleId);
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerLeftVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) {
    jint playerId = JVM::Converter::toJInt(player->GetId());
    jint vehicleId = JVM::Converter::toJInt(vehicle->GetId());
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerLeftVehicleMethod, playerId, vehicleId);
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerDeath(rage::IPlayer *player, rage::hash_t reason, rage::IPlayer *killer) {
    jint playerId = JVM::Converter::toJInt(player->GetId());
    jint jReason = JVM::Converter::toJInt(reason);
    jint killerId = JVM::Converter::toJInt(killer->GetId());
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerDeathMethod, playerId, jReason, killerId);
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerRemoteEvent(rage::IPlayer *player, const std::string &eventName, const rage::args_t &args) {
    jint playerId = JVM::Converter::toJInt(player->GetId());
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerRemoteEventMethod, playerId);
    JVM::VM::checkForException();
}


