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

PlayerEventHandler::PlayerEventHandler() {
    playerEventClass = JVM::VM::getClass(JVM_LAUNCHER_MAIN_PACKAGE_NAME + "player/PlayerEvents");
    playerCreatedMethod = JVM::VM::getStaticMethodId(playerEventClass, "onPlayerCreated", "(I)V");
    playerDestroyedMethod = JVM::VM::getStaticMethodId(playerEventClass, "onPlayerDestroyed", "(I)V");
    playerJoinMethod = JVM::VM::getStaticMethodId(playerEventClass, "onPlayerJoin", "(I)V");
    playerCommandMethod = JVM::VM::getStaticMethodId(playerEventClass, "onPlayerCommand", "(ILjava/lang/String;)V");
    playerQuitMethod = JVM::VM::getStaticMethodId(playerEventClass, "onPlayerQuit", "(IILjava/lang/String;)V");
    playerSpawnMethod = JVM::VM::getStaticMethodId(playerEventClass, "onPlayerSpawn", "(I)V");
    playerChatMethod = JVM::VM::getStaticMethodId(playerEventClass, "onPlayerChat", "(ILjava/lang/String;)V");
    playerEnterVehicleMethod = JVM::VM::getStaticMethodId(playerEventClass, "onPlayerEnterVehicle", "(III)V");
    playerEnteredVehicleMethod = JVM::VM::getStaticMethodId(playerEventClass, "onPlayerEnteredVehicle", "(III)V");
    playerExitVehicleMethod = JVM::VM::getStaticMethodId(playerEventClass, "onPlayerExitVehicle", "(II)V");
    playerLeftVehicleMethod = JVM::VM::getStaticMethodId(playerEventClass, "onPlayerExitVehicle", "(II)V");
    playerDeathMethod = JVM::VM::getStaticMethodId(playerEventClass, "onPlayerDeath", "(III)V");
}

void PlayerEventHandler::OnPlayerJoin(rage::IPlayer *player) {
    jint playerId = JVM::Converter::toJInt(player->GetId());
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerJoinMethod, playerId);
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerCommand(rage::IPlayer *player, const std::u16string &command) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerCommandMethod,
                                               JVM::Converter::toJInt(player->GetId()),
                                               JVM::Converter::toJString(command));
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerQuit(rage::IPlayer *player, rage::exit_t exitType, const char *reason) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerQuitMethod,
                                               JVM::Converter::toJInt(player->GetId()),
                                               JVM::Converter::toJInt((int)exitType),
                                               JVM::Converter::toJString(reason));
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerSpawn(rage::IPlayer *player) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerSpawnMethod,
                                               JVM::Converter::toJInt(player->GetId()));
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerChat(rage::IPlayer *player, const std::u16string &text) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerChatMethod,
                                               JVM::Converter::toJInt(player->GetId()),
                                               JVM::Converter::toJString(text));
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerEnterVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerEnterVehicleMethod,
                                               JVM::Converter::toJInt(player->GetId()),
                                               JVM::Converter::toJInt(vehicle->GetId()),
                                               JVM::Converter::toJInt(seatId));
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerEnteredVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerEnteredVehicleMethod,
                                               JVM::Converter::toJInt(player->GetId()),
                                               JVM::Converter::toJInt(vehicle->GetId()),
                                               JVM::Converter::toJInt(seatId));
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerExitVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerExitVehicleMethod,
                                               JVM::Converter::toJInt(player->GetId()),
                                               JVM::Converter::toJInt(vehicle->GetId()));
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerLeftVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerLeftVehicleMethod,
                                               JVM::Converter::toJInt(player->GetId()),
                                               JVM::Converter::toJInt(vehicle->GetId()));
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerDeath(rage::IPlayer *player, rage::hash_t reason, rage::IPlayer *killer) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerDeathMethod,
                                               JVM::Converter::toJInt(player->GetId()),
                                               JVM::Converter::toJInt(reason),
                                               JVM::Converter::toJInt(killer->GetId()));
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnPlayerRemoteEvent(rage::IPlayer *player, const std::string &eventName, const rage::args_t &args) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerRemoteEventMethod,
                                               JVM::Converter::toJInt(player->GetId()));
    JVM::VM::checkForException();
}

void PlayerEventHandler::OnEntityCreated(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Player) {
        JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerCreatedMethod,
                                                   JVM::Converter::toJInt(entity->GetId()));
        JVM::VM::checkForException();
    }
}

void PlayerEventHandler::OnEntityDestroyed(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Player) {
        JVM::VM::getJNIEnv()->CallStaticVoidMethod(playerEventClass, playerDestroyedMethod,
                                                   JVM::Converter::toJInt(entity->GetId()));
        JVM::VM::checkForException();
    }
}
