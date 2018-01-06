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

CheckpointEventHandler::CheckpointEventHandler(JNIEnv *env) {
    checkpointEventClass = JVM::VM::getClass(env, JVM_LAUNCHER_MAIN_PACKAGE_NAME + "checkpoint/CheckpointEvents");
    playerEnterCheckpointMethod = JVM::VM::getStaticMethodId(env, checkpointEventClass, "onPlayerEnterCheckpoint", "(II)V");
    playerExitCheckpointMethod = JVM::VM::getStaticMethodId(env, checkpointEventClass, "onPlayerExitCheckpoint", "(II)V");
    checkpointCreatedMethodId = JVM::VM::getStaticMethodId(env, checkpointEventClass, "onCheckpointCreated", "(I)V");
    checkpointDestroyedMethodId = JVM::VM::getStaticMethodId(env, checkpointEventClass, "onCheckpointDestroyed", "(I)V");
}

void CheckpointEventHandler::OnPlayerEnterCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(checkpointEventClass, playerEnterCheckpointMethod,
                                               int(player->GetId()),
                                               int(checkpoint->GetId()));
    JVM::VM::checkForException(env);
}

void CheckpointEventHandler::OnPlayerExitCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(checkpointEventClass, playerExitCheckpointMethod,
                                               int(player->GetId()),
                                               int(checkpoint->GetId()));
    JVM::VM::checkForException(env);
}

void CheckpointEventHandler::OnEntityCreated(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Checkpoint) {
        JNIEnv *env = JVM::VM::attachCurrentThread();
        env->CallStaticVoidMethod(checkpointEventClass, checkpointCreatedMethodId,
                                                   int(entity->GetId()));
        JVM::VM::checkForException(env);
    }
}

void CheckpointEventHandler::OnEntityDestroyed(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Checkpoint) {
        JNIEnv *env = JVM::VM::attachCurrentThread();
        env->CallStaticVoidMethod(checkpointEventClass, checkpointDestroyedMethodId,
                                                   int(entity->GetId()));
        JVM::VM::checkForException(env);
    }
}
