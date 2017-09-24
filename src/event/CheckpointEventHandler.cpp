/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "CheckpointEventHandler.hpp"
#include "../jvm/Converter.hpp"

CheckpointEventHandler::CheckpointEventHandler() {
    checkpointEventClass = JVM::VM::getClass(JVM_LAUNCHER_MAIN_PACKAGE_NAME + "checkpoint/CheckpointEvents");
    playerEnterCheckpointMethod = JVM::VM::getStaticMethodId(checkpointEventClass, "onPlayerEnterCheckpoint", "(II)V");
    playerExitCheckpointMethod = JVM::VM::getStaticMethodId(checkpointEventClass, "onPlayerExitCheckpoint", "(II)V");
    checkpointCreatedMethodId = JVM::VM::getStaticMethodId(checkpointEventClass, "onCheckpointCreated", "(I)V");
    checkpointDestroyedMethodId = JVM::VM::getStaticMethodId(checkpointEventClass, "onCheckpointDestroyed", "(I)V");
}

void CheckpointEventHandler::OnPlayerEnterCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(checkpointEventClass, playerEnterCheckpointMethod, JVM::Converter::toJInt(player->GetId()), JVM::Converter::toJInt(checkpoint->GetId()));
    JVM::VM::checkForException();
}

void CheckpointEventHandler::OnPlayerExitCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(checkpointEventClass, playerExitCheckpointMethod, JVM::Converter::toJInt(player->GetId()), JVM::Converter::toJInt(checkpoint->GetId()));
    JVM::VM::checkForException();
}

void CheckpointEventHandler::OnEntityCreated(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Checkpoint) {
        JVM::VM::getJNIEnv()->CallStaticVoidMethod(checkpointEventClass, checkpointCreatedMethodId, JVM::Converter::toJInt(entity->GetId()));
        JVM::VM::checkForException();
    }
}

void CheckpointEventHandler::OnEntityDestroyed(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Checkpoint) {
        JVM::VM::getJNIEnv()->CallStaticVoidMethod(checkpointEventClass, checkpointDestroyedMethodId, JVM::Converter::toJInt(entity->GetId()));
        JVM::VM::checkForException();
    }
}
