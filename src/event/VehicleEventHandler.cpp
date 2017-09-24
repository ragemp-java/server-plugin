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

VehicleEventHandler::VehicleEventHandler() {
    vehicleEventClass = JVM::VM::getClass(JVM_LAUNCHER_MAIN_PACKAGE_NAME + "vehicle/VehicleEvents");
    vehicleCreatedMethod = JVM::VM::getStaticMethodId(vehicleEventClass, "onVehicleCreated", "(I)V");
    vehicleDestroyedMethod = JVM::VM::getStaticMethodId(vehicleEventClass, "onVehicleDestroyed", "(I)V");
    vehicleDeathMethod = JVM::VM::getStaticMethodId(vehicleEventClass, "onVehicleDeath", "(III)V");
}

void VehicleEventHandler::OnVehicleDeath(rage::IVehicle *vehicle, rage::hash_t hash, rage::IPlayer *killer) {
    JVM::VM::getJNIEnv()->CallStaticVoidMethod(vehicleEventClass, vehicleDeathMethod,
                                               JVM::Converter::toJInt(vehicle->GetId()),
                                               JVM::Converter::toJInt((uint32_t)hash),
                                               JVM::Converter::toJInt(killer->GetId()));
    JVM::VM::checkForException();
}

void VehicleEventHandler::OnEntityCreated(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Vehicle) {
        JVM::VM::getJNIEnv()->CallStaticVoidMethod(vehicleEventClass, vehicleCreatedMethod,
                                                   JVM::Converter::toJInt(entity->GetId()));
        JVM::VM::checkForException();
    }
}

void VehicleEventHandler::OnEntityDestroyed(rage::IEntity *entity) {
    if(entity->GetType() == rage::entity_t::Vehicle) {
        JVM::VM::getJNIEnv()->CallStaticVoidMethod(vehicleEventClass, vehicleDestroyedMethod,
                                                   JVM::Converter::toJInt(entity->GetId()));
        JVM::VM::checkForException();
    }
}
