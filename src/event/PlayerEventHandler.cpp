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

PlayerEventHandler::PlayerEventHandler(JNIEnv *env) {
    playerEventClass = JVM::VM::getClass(env, JVM_LAUNCHER_MAIN_PACKAGE_NAME + "player/PlayerEvents");
    playerCreatedMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerCreated", "(I)V");
    playerDestroyedMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerDestroyed", "(I)V");
    playerJoinMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerJoin", "(I)V");
    playerCommandMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerCommand", "(ILjava/lang/String;)V");
    playerQuitMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerQuit", "(IILjava/lang/String;)V");
    playerSpawnMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerSpawn", "(I)V");
    playerChatMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerChat", "(ILjava/lang/String;)V");
    playerEnterVehicleMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerEnterVehicle", "(III)V");
    playerStartEnterVehicleMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerStartEnterVehicle", "(III)V");
    playerExitVehicleMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerExitVehicle", "(II)V");
    playerStartExitVehicleMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerStartExitVehicle", "(II)V");
    playerDeathMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerDeath", "(III)V");
    playerReadyMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerReady", "(I)V");
    playerDamageMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerDamage", "(IFF)V");
    playerWeaponChangeMethod = JVM::VM::getStaticMethodId(env, playerEventClass, "onPlayerModelChange", "(II)V");
}

void PlayerEventHandler::OnPlayerJoin(rage::IPlayer *player) {
    jint playerId = int(player->GetId());
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(playerEventClass, playerJoinMethod, playerId);
    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnPlayerCommand(rage::IPlayer *player, const std::u16string &command) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(playerEventClass, playerCommandMethod,
                                               int(player->GetId()),
                                               JVM::Converter::toJString(env, command));
    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnPlayerQuit(rage::IPlayer *player, rage::exit_t exitType, const char *reason) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(playerEventClass, playerQuitMethod,
                                               int(player->GetId()),
                                               int((int)exitType),
                                               JVM::Converter::toJString(env, reason));
    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnPlayerSpawn(rage::IPlayer *player) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(playerEventClass, playerSpawnMethod, int(player->GetId()));
    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnPlayerChat(rage::IPlayer *player, const std::u16string &text) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    jstring jText = JVM::Converter::toJString(env, text);
    env->CallStaticVoidMethod(playerEventClass, playerChatMethod, int(player->GetId()), jText);
    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnPlayerEnterVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(playerEventClass, playerEnterVehicleMethod,
                                               int(player->GetId()),
                                               int(vehicle->GetId()),
                                               int(seatId));
    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnPlayerStartEnterVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(playerEventClass, playerStartEnterVehicleMethod,
                                               int(player->GetId()),
                                               int(vehicle->GetId()),
                                               int(seatId));
    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnPlayerExitVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(playerEventClass, playerExitVehicleMethod, int(player->GetId()), int(vehicle->GetId()));
    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnPlayerStartExitVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(playerEventClass, playerStartExitVehicleMethod, int(player->GetId()), int(vehicle->GetId()));
    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnPlayerDeath(rage::IPlayer *player, rage::hash_t reason, rage::IPlayer *killer) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(playerEventClass, playerDeathMethod,
                                               int(player->GetId()),
                                               int(reason),
                                               int(killer->GetId()));
    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnPlayerRemoteEvent(rage::IPlayer *player, const std::string &eventName, const rage::args_t &args) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(playerEventClass, playerRemoteEventMethod, int(player->GetId()));
    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnEntityCreated(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Player) {
        JNIEnv *env = JVM::VM::attachCurrentThread();
        env->CallStaticVoidMethod(playerEventClass, playerCreatedMethod, int(entity->GetId()));
        JVM::VM::checkForException(env);
    }
}

void PlayerEventHandler::OnEntityDestroyed(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Player) {
        JNIEnv *env = JVM::VM::attachCurrentThread();
        env->CallStaticVoidMethod(playerEventClass, playerDestroyedMethod, int(entity->GetId()));
        JVM::VM::checkForException(env);
    }
}

void PlayerEventHandler::OnPlayerReady(rage::IPlayer *player) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(playerEventClass, playerReadyMethod, int(player->GetId()));
    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnPlayerDamage(rage::IPlayer *player, float healthLoss, float armorLoss) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(playerEventClass, playerDamageMethod,
                                               int(player->GetId()),
                                               healthLoss,
                                               armorLoss);

    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnPlayerWeaponChange(rage::IPlayer *player, rage::hash_t oldWeapon, rage::hash_t newWeapon) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(playerEventClass, playerWeaponChangeMethod,
                                               int(player->GetId()),
                                               int(oldWeapon),
                                               int(newWeapon));

    JVM::VM::checkForException(env);
}

void PlayerEventHandler::OnEntityModelChange(rage::IEntity *entity, rage::hash_t oldModel) {
    if(entity->GetType() == rage::entity_t::Player) {
        JNIEnv *env = JVM::VM::attachCurrentThread();
        env->CallStaticVoidMethod(playerEventClass, playerModelChangeMethod,
                                                   int(entity->GetId()),
                                                   int(oldModel));
        JVM::VM::checkForException(env);
    }
}
