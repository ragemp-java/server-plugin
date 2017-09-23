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

CheckpointEventHandler::CheckpointEventHandler() {
    checkpointEventClass = JVM::VM::getClass(JVM_LAUNCHER_MAIN_PACKAGE_NAME + "checkpoint/CheckpointEvents");
    playerEnterCheckpointMethod = JVM::VM::getStaticMethodId(checkpointEventClass, "onPlayerEnterCheckpoint", "(II)V");
    playerExitCheckpointMethod = JVM::VM::getStaticMethodId(checkpointEventClass, "onPlayerExitCheckpoint", "(II)V");
}

void CheckpointEventHandler::OnPlayerEnterCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(checkpointEventClass, playerEnterCheckpointMethod, (jint)player->GetId(), (jint)checkpoint->GetId());
    JVM::VM::checkForException();
}

void CheckpointEventHandler::OnPlayerExitCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(checkpointEventClass, playerExitCheckpointMethod, (jint)player->GetId(), (jint)checkpoint->GetId());
    JVM::VM::checkForException();
}
