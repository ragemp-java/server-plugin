/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include <iostream>
#include "VehicleEventHandler.hpp"
#include "../jvm/VM.hpp"
#include "../jvm/Converter.hpp"

VehicleEventHandler::VehicleEventHandler(JNIEnv *env) {
    vehicleEventClass = JVM::VM::getClass(env, JVM_LAUNCHER_MAIN_PACKAGE_NAME + "vehicle/VehicleEvents");
    vehicleCreatedMethod = JVM::VM::getStaticMethodId(env, vehicleEventClass, "onVehicleCreated", "(I)V");
    vehicleDestroyedMethod = JVM::VM::getStaticMethodId(env, vehicleEventClass, "onVehicleDestroyed", "(I)V");
    vehicleDeathMethod = JVM::VM::getStaticMethodId(env, vehicleEventClass, "onVehicleDeath", "(III)V");
    vehicleModelChangeMethod = JVM::VM::getStaticMethodId(env, vehicleEventClass, "onVehicleModelChange", "(II)V");
    vehicleSirenToggleMethod = JVM::VM::getStaticMethodId(env, vehicleEventClass, "onVehicleSirenToggle", "(IZ)V");
    vehicleHornToggleMethod = JVM::VM::getStaticMethodId(env, vehicleEventClass, "onVehicleHornToggle", "(IZ)V");
    vehicleTrailerAttachedMethod = JVM::VM::getStaticMethodId(env, vehicleEventClass, "onVehicleTrailerAttached", "(II)V");
    vehicleDamageMethod = JVM::VM::getStaticMethodId(env, vehicleEventClass, "onVehicleDamage", "(IFF)V");
}

void VehicleEventHandler::OnVehicleDeath(rage::IVehicle *vehicle, rage::hash_t hash, rage::IPlayer *killer) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(vehicleEventClass, vehicleDeathMethod,
                                               int(vehicle->GetId()),
                                               int((uint32_t)hash),
                                               int(killer->GetId()));
    JVM::VM::checkForException(env);
}

void VehicleEventHandler::OnEntityCreated(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Vehicle) {
        JNIEnv *env = JVM::VM::attachCurrentThread();
        env->CallStaticVoidMethod(vehicleEventClass, vehicleCreatedMethod,
                                                   int(entity->GetId()));
        JVM::VM::checkForException(env);
    }
}

void VehicleEventHandler::OnEntityDestroyed(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Vehicle) {
        JNIEnv *env = JVM::VM::attachCurrentThread();
        env->CallStaticVoidMethod(vehicleEventClass, vehicleDestroyedMethod,
                                                   int(entity->GetId()));
        JVM::VM::checkForException(env);
    }
}

void VehicleEventHandler::OnEntityModelChange(rage::IEntity *entity, rage::hash_t oldModel) {
    if(entity->GetType() == rage::entity_t::Vehicle) {
        JNIEnv *env = JVM::VM::attachCurrentThread();
        env->CallStaticVoidMethod(vehicleEventClass, vehicleModelChangeMethod,
                                                   int(entity->GetId()),
                                                   int(oldModel));

        JVM::VM::checkForException(env);
    }
}

void VehicleEventHandler::OnVehicleSirenToggle(rage::IVehicle *vehicle, bool toggle) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(vehicleEventClass, vehicleSirenToggleMethod,
                                               int(vehicle->GetId()),
                                               toggle);

    JVM::VM::checkForException(env);
}

void VehicleEventHandler::OnVehicleHornToggle(rage::IVehicle *vehicle, bool toggle) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(vehicleEventClass, vehicleHornToggleMethod,
                                               int(vehicle->GetId()),
                                               toggle);
    JVM::VM::checkForException(env);
}

void VehicleEventHandler::OnTrailerAttached(rage::IVehicle *vehicle, rage::IVehicle *trailer) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(vehicleEventClass, vehicleHornToggleMethod,
                                               int(vehicle->GetId()),
                                               int(trailer->GetId()));

    JVM::VM::checkForException(env);
}

void VehicleEventHandler::OnVehicleDamage(rage::IVehicle *vehicle, float bodyHealthLoss, float engineHealthLoss) {
    JNIEnv *env = JVM::VM::attachCurrentThread();
    env->CallStaticVoidMethod(vehicleEventClass, vehicleDeathMethod,
                                               int(vehicle->GetId()),
                                               bodyHealthLoss,
                                               engineHealthLoss);
    JVM::VM::checkForException(env);
}
