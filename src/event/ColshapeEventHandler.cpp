/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "ColshapeEventHandler.hpp"
#include "../jvm/VM.hpp"
#include "../jvm/Converter.hpp"

ColshapeEventHandler::ColshapeEventHandler(JNIEnv *env) {
    colshapeEventClass = JVM::VM::getClass(env, JVM_LAUNCHER_MAIN_PACKAGE_NAME + "colshape/ColshapeEvents");
    colshapeCreatedMethod = JVM::VM::getStaticMethodId(env, colshapeEventClass, "onColshapeCreated", "(I)V");
    colshapeDestroyedMethod = JVM::VM::getStaticMethodId(env, colshapeEventClass, "onColshapeDestroyed", "(I)V");
    playerEnterColshapeMethod = JVM::VM::getStaticMethodId(env, colshapeEventClass, "onPlayerEnterColshape", "(II)V");
    playerExitColshapeMethod = JVM::VM::getStaticMethodId(env, colshapeEventClass, "onPlayerExitColshape", "(II)V");
}

void ColshapeEventHandler::OnPlayerEnterColshape(rage::IPlayer *player, rage::IColshape *colshape) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(colshapeEventClass, playerEnterColshapeMethod,
                                               int(player->GetId()),
                                               int(colshape->GetId()));
    JVM::VM::checkForException(env);
}

void ColshapeEventHandler::OnPlayerExitColshape(rage::IPlayer *player, rage::IColshape *colshape) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(colshapeEventClass, playerExitColshapeMethod,
                                               int(player->GetId()),
                                               int(colshape->GetId()));
    JVM::VM::checkForException(env);
}

void ColshapeEventHandler::OnEntityCreated(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Colshape) {
        JNIEnv *env = JVM::VM::attachCurrentThread();
        env->CallStaticVoidMethod(colshapeEventClass, colshapeCreatedMethod,
                                                   int(entity->GetId()));
        JVM::VM::checkForException(env);
    }
}

void ColshapeEventHandler::OnEntityDestroyed(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Colshape) {
        JNIEnv *env = JVM::VM::attachCurrentThread();
        env->CallStaticVoidMethod(colshapeEventClass, colshapeDestroyedMethod,
                                                   int(entity->GetId()));
        JVM::VM::checkForException(env);
    }
}
