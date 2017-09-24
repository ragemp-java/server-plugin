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

ColshapeEventHandler::ColshapeEventHandler() {
    colshapeEventClass = JVM::VM::getClass(JVM_LAUNCHER_MAIN_PACKAGE_NAME + "colshape/ColshapeEvents");
    colshapeCreatedMethod = JVM::VM::getStaticMethodId(colshapeEventClass, "onColshapeCreated", "(I)V");
    colshapeDestroyedMethod = JVM::VM::getStaticMethodId(colshapeEventClass, "onColshapeDestroyed", "(I)V");
    playerEnterColshapeMethod = JVM::VM::getStaticMethodId(colshapeEventClass, "onPlayerEnterColshape", "(II)V");
    playerExitColshapeMethod = JVM::VM::getStaticMethodId(colshapeEventClass, "onPlayerExitColshape", "(II)V");
}

void ColshapeEventHandler::OnPlayerEnterColshape(rage::IPlayer *player, rage::IColshape *colshape) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(colshapeEventClass, playerEnterColshapeMethod,
                                               JVM::Converter::toJInt(player->GetId()),
                                               JVM::Converter::toJInt(colshape->GetId()));
    JVM::VM::checkForException();
}

void ColshapeEventHandler::OnPlayerExitColshape(rage::IPlayer *player, rage::IColshape *colshape) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(colshapeEventClass, playerExitColshapeMethod,
                                               JVM::Converter::toJInt(player->GetId()),
                                               JVM::Converter::toJInt(colshape->GetId()));
    JVM::VM::checkForException();
}

void ColshapeEventHandler::OnEntityCreated(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Colshape) {
        JVM::VM::getJNIEnv()->CallStaticVoidMethod(colshapeEventClass, colshapeCreatedMethod,
                                                   JVM::Converter::toJInt(entity->GetId()));
        JVM::VM::checkForException();
    }
}

void ColshapeEventHandler::OnEntityDestroyed(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Colshape) {
        JVM::VM::getJNIEnv()->CallStaticVoidMethod(colshapeEventClass, colshapeDestroyedMethod,
                                                   JVM::Converter::toJInt(entity->GetId()));
        JVM::VM::checkForException();
    }
}
