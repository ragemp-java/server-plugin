/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#pragma once

#include <jni.h>
#include "../sdk/rage.hpp"

class VehicleEventHandler : public rage::IEventHandler, public rage::IVehicleHandler, public rage::IEntityHandler {
public:

    VehicleEventHandler(JNIEnv *env);

    rage::IVehicleHandler *GetVehicleHandler() override {
        return this;
    }

    rage::IEntityHandler *GetEntityHandler() override {
        return this;
    }

    void OnVehicleDeath(rage::IVehicle *vehicle, rage::hash_t hash, rage::IPlayer *killer) override;

    void OnEntityCreated(rage::IEntity *entity) override;

    void OnEntityDestroyed(rage::IEntity *entity) override;

    void OnEntityModelChange(rage::IEntity *entity, rage::hash_t oldModel) override;

    void OnVehicleSirenToggle(rage::IVehicle *vehicle, bool toggle) override;

    void OnVehicleHornToggle(rage::IVehicle *vehicle, bool toggle) override;

    void OnTrailerAttached(rage::IVehicle *vehicle, rage::IVehicle *trailer) override;

    void OnVehicleDamage(rage::IVehicle *vehicle, float bodyHealthLoss, float engineHealthLoss) override;

private:
    jclass vehicleEventClass;
    jmethodID vehicleDeathMethod;
    jmethodID vehicleCreatedMethod;
    jmethodID vehicleDestroyedMethod;
    jmethodID vehicleModelChangeMethod;
    jmethodID vehicleSirenToggleMethod;
    jmethodID vehicleHornToggleMethod;
    jmethodID vehicleTrailerAttachedMethod;
    jmethodID vehicleDamageMethod;
};