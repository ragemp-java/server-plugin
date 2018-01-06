/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "VehicleNative.hpp"
#include "../RageJavaCore.hpp"
#include "../game/Vehicle.hpp"
#include "../jvm/Object.hpp"
#include "../game/Player.hpp"

jint Java_mp_rage_launcher_vehicle_VehicleNative_getType(JNIEnv *env, jclass, jint) {
    return (jint)rage::entity_t::Vehicle;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_destroy(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->Destroy();
    }
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_getDimension(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetDimension();
    }
    return -1;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setDimension(JNIEnv *env, jclass, jint vehicleId, jint dimension) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetDimension((rage::dimensionId_t)dimension);
    }
}

jobject Java_mp_rage_launcher_vehicle_VehicleNative_getPosition(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        rage::vector3 position = vehicle->GetPosition();
        return JVM::Object::vector3(env, position.x, position.y, position.z);
    }
    return nullptr;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setPosition(JNIEnv *env, jclass, jint vehicleId, jfloat x, jfloat y, jfloat z) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        rage::vector3 position = {x, y, z};
        vehicle->SetPosition(position);
    }
}

jobject Java_mp_rage_launcher_vehicle_VehicleNative_getRotation(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        rage::vector3 rotation = vehicle->GetRotation();
        return JVM::Object::vector3(env, rotation.x, rotation.y, rotation.z);
    }
    return nullptr;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setRotation(JNIEnv *env, jclass, jint vehicleId, jfloat x, jfloat y, jfloat z) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        rage::vector3 rotation = {x, y, z};
        vehicle->SetRotation(rotation);
    }
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_getModel(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetModel();
    }
    return -1;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setModel(JNIEnv *env, jclass, jint vehicleId, jint model) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetModel((uint32_t) model);
    }
}

jobject Java_mp_rage_launcher_vehicle_VehicleNative_getVelocity(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        rage::vector3 velocity = vehicle->GetVelocity();
        return JVM::Object::vector3(env, velocity.x, velocity.y, velocity.z);
    }
    return nullptr;
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_getAlpha(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetAlpha();
    }
    return -1;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setAlpha(JNIEnv *env, jclass, jint vehicleId, jint alpha) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetAlpha((uint8_t)alpha);
    }
}

jboolean Java_mp_rage_launcher_vehicle_VehicleNative_isSirenActive(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsSirenActive();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_launcher_vehicle_VehicleNative_isHornActive(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsHornActive();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_launcher_vehicle_VehicleNative_areHighbeamsActive(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->AreHighbeamsActive();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_launcher_vehicle_VehicleNative_areLightsActive(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->AreLightsActive();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_launcher_vehicle_VehicleNative_isEngineActive(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsEngineActive();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_launcher_vehicle_VehicleNative_isRocketBoostActive(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsRocketBoostActive();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_launcher_vehicle_VehicleNative_isBrakeActive(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsBrakeActive();
    }
    return (jboolean)false;
}

jfloat Java_mp_rage_launcher_vehicle_VehicleNative_getSteerAngle(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jfloat)vehicle->GetSteerAngle();
    }
    return -1;
}

jfloat Java_mp_rage_launcher_vehicle_VehicleNative_getGasPedalState(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jfloat)vehicle->GetGasPedalState();
    }
    return -1;
}

jfloat Java_mp_rage_launcher_vehicle_VehicleNative_getEngineHealth(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jfloat)vehicle->GetEngineHealth();
    }
    return -1;
}

jfloat Java_mp_rage_launcher_vehicle_VehicleNative_getBodyHealth(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jfloat)vehicle->GetBodyHealth();
    }
    return -1;
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_getOccupant(JNIEnv *env, jclass, jint vehicleId, jint occupant) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        rage::IPlayer *player = vehicle->GetOccupant((uint8_t)occupant);
        if(player) {
            return (jint)player->GetId();
        }
    }
    return -1;
}

jobject Java_mp_rage_launcher_vehicle_VehicleNative_getOccupants(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        std::vector<rage::IPlayer*> occupants = vehicle->GetOccupants();
        std::vector<int> playerIds;

        for(size_t i=0; i < occupants.size(); i++) {
           playerIds.push_back(occupants[i]->GetId());
        }

        return JVM::Object::intArrayList(env, playerIds);
    }
    return nullptr;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setOccupant(JNIEnv *env, jclass, jint vehicleId, jint seat, jint playerId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    rage::IPlayer *player = Game::Player::getPlayerById(env, playerId);
    if(vehicle && player) {
        vehicle->SetOccupant((uint8_t)seat, player);
    }
}

jboolean Java_mp_rage_launcher_vehicle_VehicleNative_isLocked(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsLocked();
    }
    return (jboolean)false;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_lock(JNIEnv *env, jclass, jint  vehicleId, jboolean state) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->Lock((bool)state);
    }
}

jboolean Java_mp_rage_launcher_vehicle_VehicleNative_isDead(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsDead();
    }
    return (jboolean)false;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_explode(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->Explode();
    }
}

void Java_mp_rage_launcher_vehicle_VehicleNative_spawn(JNIEnv *env, jclass, jint vehicleId, jfloat x, jfloat y, jfloat z, jfloat heading) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        rage::vector3 position = {x, y, z};
        vehicle->Spawn(position, heading);
    }
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_getMod(JNIEnv *env, jclass, jint vehicleId, jint id) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetMod((uint8_t)id);
    }
    return -1;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setMod(JNIEnv *env, jclass, jint vehicleId, jint id, jint mod) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetMod((uint8_t)id, (uint8_t)mod);
    }
}

jboolean Java_mp_rage_launcher_vehicle_VehicleNative_areNeonsEnabled(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->AreNeonsEnabled();
    }
    return (jboolean)false;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_enableNeons(JNIEnv *env, jclass, jint vehicleId, jboolean state) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->EnableNeons(state);
    }
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setNeonsColour(JNIEnv *env, jclass, jint vehicleId, jint r, jint g, jint b) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetNeonsColour((uint8_t)r, (uint8_t)g, (uint8_t)b);
    }
}

jobject Java_mp_rage_launcher_vehicle_VehicleNative_getNeonsColour(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        rage::rgb_t rgb = vehicle->GetNeonsColour();
        return JVM::Object::rgbColor(env, rgb.rgba[0], rgb.rgba[1], rgb.rgba[2]);
    }
    return nullptr;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_repair(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return vehicle->Repair();
    }
}

jobject Java_mp_rage_launcher_vehicle_VehicleNative_getColourRGB(JNIEnv *env, jclass, jint vehicleId, jint id) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        rage::rgb_t rgb = vehicle->GetColourRGB((uint8_t)id);
        return JVM::Object::rgbColor(env, rgb.rgba[0], rgb.rgba[1], rgb.rgba[2]);
    }
    return nullptr;
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_getColour(JNIEnv *env, jclass, jint vehicleId, jint id) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetColour((uint8_t)id);
    }
    return -1;
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_getPaint(JNIEnv *env, jclass, jint vehicleId, jint id) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetPaint((uint8_t)id);
    }
    return -1;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setColourRGB(JNIEnv *env, jclass, jint vehicleId, jint pR, jint pG, jint pB, jint sR, jint sG, jint sB) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        rage::rgb_t primary = {(uint8_t)pR, (uint8_t)pG, (uint8_t)pB};
        rage::rgb_t secondary = {(uint8_t)sR, (uint8_t)sG, (uint8_t)sB};
        vehicle->SetColourRGB(primary, secondary);
    }
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setColour(JNIEnv *env, jclass, jint vehicleId, jint primary, jint secondary) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetColour((uint8_t)primary, (uint8_t)secondary);
    }
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setPaint(JNIEnv *env, jclass, jint vehicleId, jint pT, jint pC, jint sT, jint sC) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        rage::paintInfo_t primary = {(uint8_t)pT, (uint8_t)pC};
        rage::paintInfo_t secondary = {(uint8_t)sT, (uint8_t)sC};
        vehicle->SetPaint(primary, secondary);
    }
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_getMaterialType(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetMaterialType();
    }
    return -1;
}

jstring Java_mp_rage_launcher_vehicle_VehicleNative_getNumberPlate(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return JVM::Converter::toJString(env, vehicle->GetNumberPlate());
    }
    return nullptr;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setNumberPlate(JNIEnv *env, jclass, jint vehicleId, jstring numberPlate) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetNumberPlate(JVM::Converter::toString(env, numberPlate));
    }
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setSirenActive(JNIEnv *env, jclass, jint vehicleId, jboolean toggle) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetSirenActive(toggle);
    }
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setHighbeamsActive(JNIEnv *env, jclass, jint vehicleId, jboolean toggle) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetHighbeamsActive(toggle);
    }
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setLightsActive(JNIEnv *env, jclass, jint vehicleId, jboolean toggle) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetLightsActive(toggle);
    }
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setEngineActive(JNIEnv *env, jclass, jint vehicleId, jboolean toggle) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetEngineActive(toggle);
    }
}

jboolean Java_mp_rage_launcher_vehicle_VehicleNative_areTaxiLightsActive(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->AreTaxiLightsActive();
    }
    return (jboolean)false;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_setTaxiLightsActive(JNIEnv *env, jclass, jint vehicleId, jboolean toggle) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetTaxiLightsActive(toggle);
    }
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_GetLivery(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return vehicle->GetLivery();
    }
    return -1;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_SetLivery(JNIEnv *env, jclass, jint vehicleId, jint livery) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetLivery((uint8_t)livery);
    }
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_GetWheelColor(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return vehicle->GetWheelColor();
    }
    return -1;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_SetWheelColor(JNIEnv *env, jclass, jint vehicleId, jint color) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetWheelColor((uint8_t)color);
    }
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_GetWheelType(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return vehicle->GetWheelType();
    }
    return -1;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_SetWheelType(JNIEnv *env, jclass, jint vehicleId, jint type) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetWheelType((uint8_t)type);
    }
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_GetNumberPlateType(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return vehicle->GetNumberPlateType();
    }
    return -1;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_SetNumberPlateType(JNIEnv *env, jclass, jint vehicleId, jint type) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetNumberPlateType((uint8_t)type);
    }
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_GetPearlescentColor(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return vehicle->GetPearlescentColor();
    }
    return -1;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_SetPearlescentColor(JNIEnv *env, jclass, jint vehicleId, jint color) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetPearlescentColor((uint8_t)color);
    }
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_GetWindowTint(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return vehicle->GetWindowTint();
    }
    return -1;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_SetWindowTint(JNIEnv *env, jclass, jint vehicleId, jint tint) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetWindowTint((uint8_t)tint);
    }
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_GetDashboardColor(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return vehicle->GetDashboardColor();
    }
    return -1;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_SetDashboardColor(JNIEnv *env, jclass, jint vehicleId, jint color) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetDashboardColor((uint8_t)color);
    }
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_GetTrimColor(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return vehicle->GetTrimColor();
    }
    return -1;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_SetTrimColor(JNIEnv *env, jclass, jint vehicleId, jint color) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetTrimColor((uint8_t)color);
    }
}

jboolean Java_mp_rage_launcher_vehicle_VehicleNative_GetExtra(JNIEnv *env, jclass, jint vehicleId, jint extraId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->GetExtra((uint8_t)extraId);
    }
    return (jboolean)false;
}

void Java_mp_rage_launcher_vehicle_VehicleNative_SetExtra(JNIEnv *env, jclass, jint vehicleId, jint id, jboolean toggle) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        vehicle->SetExtra((uint8_t)id, toggle);
    }
}

jfloat Java_mp_rage_launcher_vehicle_VehicleNative_GetMovableState(JNIEnv *env, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(env, vehicleId);
    if(vehicle) {
        return (jfloat)vehicle->GetMovableState();
    }
    return -1;
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_create(JNIEnv *env, jclass, jint model, jfloat x , jfloat y, jfloat z, jfloat heading, jstring numberPlate,
                                                        jint alpha, jboolean locked, jboolean engine, jint dimension) {
    rage::IMultiplayer *mp = RageJavaCore::getInstance().getMultiPlayer();
    if (mp == nullptr) {
        return -1;
    }
    rage::vector3 position = {x, y, z};
    rage::IVehicle *vehicle = mp->GetVehiclePool().New(
            (uint32_t)model,
            position,
            heading,
            JVM::Converter::toString(env, numberPlate),
            uint8_t(alpha),
            locked,
            engine,
            (rage::dimensionId_t)dimension);
    if(vehicle) {
        return (jint)vehicle->GetId();
    }
    return -1;
}


jint Java_mp_rage_launcher_vehicle_VehicleNative_length(JNIEnv *env, jclass) {
    return (jint)RageJavaCore::getInstance().getMultiPlayer()->GetVehiclePool().Length();
}

jint Java_mp_rage_launcher_vehicle_VehicleNative_count(JNIEnv *env, jclass) {
    return (jint)RageJavaCore::getInstance().getMultiPlayer()->GetVehiclePool().Count();
}

jobject Java_mp_rage_launcher_vehicle_VehicleNative_getInRange(JNIEnv *env, jclass, jfloat x, jfloat y, jfloat z, jfloat range, jint dimensionId) {
    rage::vector3 position = {x, y, z};
    std::vector<rage::IVehicle*> vehicles = RageJavaCore::getInstance().getMultiPlayer()->GetVehiclePool()
            .GetInRange(position, range, (rage::dimensionId_t)dimensionId);
//    JVM::Object::intArrayList()
    return nullptr;
}

jobject Java_mp_rage_launcher_vehicle_VehicleNative_getInDimension(JNIEnv *env, jclass, jint) {
    return nullptr;
}
