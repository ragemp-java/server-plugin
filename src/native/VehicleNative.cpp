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
#include "../rage/Vehicle.hpp"
#include "../jvm/Object.hpp"
#include "../rage/Player.hpp"

jint Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_create(JNIEnv *, jclass, jint model, jfloat x, jfloat y, jfloat z, jfloat heading, jint dimension) {
    rage::IMultiplayer *mp = RageJavaCore::getInstance().getMultiPlayer();
    if (mp == nullptr) {
        return -1;
    }
    rage::vector3 position = {x, y, z};
    rage::IVehicle *vehicle = mp->GetVehiclePool().New((uint32_t)model, position, heading, (rage::dimensionId_t)dimension);
    if(vehicle) {
        return (jint)vehicle->GetId();
    }
    return -1;
}

jint Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getType(JNIEnv *, jclass, jint) {
    return (jint)rage::entity_t::Vehicle;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_destroy(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        vehicle->Destroy();
    }
}

jint Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getDimension(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetDimension();
    }
    return -1;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_setDimension(JNIEnv *, jclass, jint vehicleId, jint dimension) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        vehicle->SetDimension((rage::dimensionId_t)dimension);
    }
}

jobject Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getPosition(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        rage::vector3 position = vehicle->GetPosition();
        return JVM::Object::vector3(position.x, position.y, position.z);
    }
    return nullptr;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_setPosition(JNIEnv *, jclass, jint vehicleId, jfloat x, jfloat y, jfloat z) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        rage::vector3 position = {x, y, z};
        vehicle->SetPosition(position);
    }
}

jobject Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getRotation(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        rage::vector3 rotation = vehicle->GetRotation();
        return JVM::Object::vector3(rotation.x, rotation.y, rotation.z);
    }
    return nullptr;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_setRotation(JNIEnv *, jclass, jint vehicleId, jfloat x, jfloat y, jfloat z) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        rage::vector3 rotation = {x, y, z};
        vehicle->SetRotation(rotation);
    }
}

jint Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getModel(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetModel();
    }
    return -1;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_setModel(JNIEnv *, jclass, jint vehicleId, jint model) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        vehicle->SetModel((uint32_t) model);
    }
}

jobject Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getVelocity(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        rage::vector3 velocity = vehicle->GetVelocity();
        return JVM::Object::vector3(velocity.x, velocity.y, velocity.z);
    }
    return nullptr;
}

jint Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getAlpha(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetAlpha();
    }
    return -1;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_setAlpha(JNIEnv *, jclass, jint vehicleId, jint alpha) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        vehicle->SetAlpha((uint8_t)alpha);
    }
}

jboolean Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_isSirenActive(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsSirenActive();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_isHornActive(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsHornActive();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_areHighbeamsActive(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->AreHighbeamsActive();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_areLightsActive(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->AreLightsActive();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_isEngineActive(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsEngineActive();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_isRocketBoostActive(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsRocketBoostActive();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_isBrakeActive(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsBrakeActive();
    }
    return (jboolean)false;
}

jfloat Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getSteerAngle(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jfloat)vehicle->GetSteerAngle();
    }
    return -1;
}

jfloat Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getGasPedalState(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jfloat)vehicle->GetGasPedalState();
    }
    return -1;
}

jfloat Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getEngineHealth(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jfloat)vehicle->GetEngineHealth();
    }
    return -1;
}

jfloat Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getBodyHealth(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jfloat)vehicle->GetBodyHealth();
    }
    return -1;
}

jint Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getOccupant(JNIEnv *, jclass, jint vehicleId, jint occupant) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        rage::IPlayer *player = vehicle->GetOccupant((uint8_t)occupant);
        if(player) {
            return (jint)player->GetId();
        }
    }
    return -1;
}

jobject Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getOccupants(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        std::vector<rage::IPlayer*> occupants = vehicle->GetOccupants();
        std::vector<int> playerIds;

        for(rage::IPlayer *player : occupants) {
            playerIds.push_back(player->GetId());
        }

        return JVM::Object::intArrayList(playerIds);
    }
    return nullptr;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_setOccupant(JNIEnv *, jclass, jint vehicleId, jint seat, jint playerId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    rage::IPlayer *player = Game::Player::getPlayerById(playerId);
    if(vehicle && player) {
        vehicle->SetOccupant((uint8_t)seat, player);
    }
}

jboolean Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_isLocked(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsLocked();
    }
    return (jboolean)false;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_lock(JNIEnv *, jclass, jint  vehicleId, jboolean state) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        vehicle->Lock((bool)state);
    }
}

jboolean Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_isDead(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->IsDead();
    }
    return (jboolean)false;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_explode(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        vehicle->Explode();
    }
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_spawn(JNIEnv *, jclass, jint vehicleId, jfloat x, jfloat y, jfloat z, jfloat heading) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        rage::vector3 position = {x, y, z};
        vehicle->Spawn(position, heading);
    }
}

jint Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getMod(JNIEnv *, jclass, jint vehicleId, jint id) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetMod((uint8_t)id);
    }
    return -1;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_setMod(JNIEnv *, jclass, jint vehicleId, jint id, jint mod) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        vehicle->SetMod((uint8_t)id, (uint8_t)mod);
    }
}

jboolean Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_areNeonsEnabled(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jboolean)vehicle->AreNeonsEnabled();
    }
    return (jboolean)false;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_enableNeons(JNIEnv *, jclass, jint vehicleId, jboolean state) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        vehicle->EnableNeons(state);
    }
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_setNeonsColour(JNIEnv *, jclass, jint vehicleId, jint r, jint g, jint b) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        vehicle->SetNeonsColour((uint8_t)r, (uint8_t)g, (uint8_t)b);
    }
}

jobject Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getNeonsColour(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        rage::rgb_t rgb = vehicle->GetNeonsColour();
        return JVM::Object::rgbColor(rgb.r, rgb.g, rgb.b);
    }
    return nullptr;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_repair(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return vehicle->Repair();
    }
}

jobject Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getColourRGB(JNIEnv *, jclass, jint vehicleId, jint id) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        rage::rgb_t rgb = vehicle->GetColourRGB((uint8_t)id);
        return JVM::Object::rgbColor(rgb.r, rgb.g, rgb.b);
    }
    return nullptr;
}

jint Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getColour(JNIEnv *, jclass, jint vehicleId, jint id) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetColour((uint8_t)id);
    }
    return -1;
}

jint Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getPaint(JNIEnv *, jclass, jint vehicleId, jint id) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetPaint((uint8_t)id);
    }
    return -1;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_setColourRGB(JNIEnv *, jclass, jint vehicleId, jint pR, jint pG, jint pB, jint sR, jint sG, jint sB) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        rage::rgb_t primary = {(uint8_t)pR, (uint8_t)pG, (uint8_t)pB};
        rage::rgb_t secondary = {(uint8_t)sR, (uint8_t)sG, (uint8_t)sB};
        vehicle->SetColourRGB(primary, secondary);
    }
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_setColour(JNIEnv *, jclass, jint vehicleId, jint primary, jint secondary) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        vehicle->SetColour((uint8_t)primary, (uint8_t)secondary);
    }
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_setPaint(JNIEnv *, jclass, jint vehicleId, jint pT, jint pC, jint sT, jint sC) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        rage::paintInfo_t primary = {(uint8_t)pT, (uint8_t)pC};
        rage::paintInfo_t secondary = {(uint8_t)sT, (uint8_t)sC};
        vehicle->SetPaint(primary, secondary);
    }
}

jint Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getMaterialType(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return (jint)vehicle->GetMaterialType();
    }
    return -1;
}

jstring Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_getNumberPlate(JNIEnv *, jclass, jint vehicleId) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        return JVM::Converter::toJString(vehicle->GetNumberPlate());
    }
    return nullptr;
}

void Java_mp_rage_plugin_java_launcher_vehicle_VehicleNative_setNumberPlate(JNIEnv *, jclass, jint vehicleId, jstring numberPlate) {
    rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
    if(vehicle) {
        vehicle->SetNumberPlate(JVM::Converter::toString(numberPlate));
    }
}
