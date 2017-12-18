/*
 * Copyright (c) 2017 Noxaro aka Fabian Jungwirth
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 * See the file COPYING included with this distribution for more information.
 */

#include "PlayerNative.hpp"
#include <iostream>
#include "../RagePlugin.hpp"
#include "../game/Player.hpp"
#include "../game/Vehicle.hpp"

jint Java_mp_rage_launcher_player_PlayerNative_getType(JNIEnv *, jclass, jint playerId) {
    return (jint)rage::entity_t::Player;
}

void Java_mp_rage_launcher_player_PlayerNative_destroy(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->Destroy();
    }
}

jint Java_mp_rage_launcher_player_PlayerNative_getDimension(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jint)player->GetDimension();
    }
    return -1;
}

void Java_mp_rage_launcher_player_PlayerNative_setDimension(JNIEnv *, jclass, jint playerId, jint dimension) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->SetDimension((uint32_t)dimension);
    }
}

jobject Java_mp_rage_launcher_player_PlayerNative_getPosition(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        rage::vector3 position = player->GetPosition();
        return JVM::Object::vector3(position.x, position.y, position.z);
    }
    return nullptr;
}

void Java_mp_rage_launcher_player_PlayerNative_setPosition(JNIEnv *, jclass, jint playerId, jfloat x, jfloat y, jfloat z) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        rage::vector3 position = {x, y, z};
        player->SetPosition(position);
    }
}

jobject Java_mp_rage_launcher_player_PlayerNative_getRotation(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        rage::vector3 position = player->GetRotation();
        return JVM::Object::vector3(position.x, position.y, position.z);
    }
    return nullptr;
}

void Java_mp_rage_launcher_player_PlayerNative_setRotation(JNIEnv *, jclass, jint playerId, jfloat x, jfloat y, jfloat z) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        rage::vector3 position = {x, y, z};
        player->SetRotation(position);
    }
}

jint Java_mp_rage_launcher_player_PlayerNative_getModel(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jint)player->GetModel();
    }
    return -1;
}

void Java_mp_rage_launcher_player_PlayerNative_setModel(JNIEnv *, jclass, jint playerId, jint model) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->SetModel((uint32_t)model);
    }
}

jobject Java_mp_rage_launcher_player_PlayerNative_getVelocity(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        rage::vector3 velocity = player->GetVelocity();
        return JVM::Object::vector3(velocity.x, velocity.y, velocity.x);
    }
    return nullptr;
}

jint Java_mp_rage_launcher_player_PlayerNative_getAlpha(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jint)player->GetAlpha();
    }
    return -1;
}

void Java_mp_rage_launcher_player_PlayerNative_setAlpha(JNIEnv *, jclass, jint playerId, jint alpha) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->SetAlpha((uint8_t)alpha);
    }
}

void Java_mp_rage_launcher_player_PlayerNative_kick(JNIEnv *, jclass, jint playerId, jstring reason) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->Kick(JVM::Converter::toString(reason).c_str());
    }
}

void Java_mp_rage_launcher_player_PlayerNative_ban(JNIEnv *, jclass, jint playerId, jstring reason) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->Ban(JVM::Converter::toString(reason).c_str());
    }
}

void Java_mp_rage_launcher_player_PlayerNative_outputChatBox(JNIEnv * env, jclass, jint playerId, jstring message) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->OutputChatBox(JVM::Converter::toString(message));
    }
}

void Java_mp_rage_launcher_player_PlayerNative_notify(JNIEnv *, jclass, jint playerId, jstring message) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->Notify(JVM::Converter::toString(message));
    }
}

void Java_mp_rage_launcher_player_PlayerNative_spawn(JNIEnv * env, jclass, jint playerId, jfloat x, jfloat y, jfloat z, jfloat heading) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        rage::vector3 position = {x, y, z};
        player->Spawn(position, heading);
    }
}

void Java_mp_rage_launcher_player_PlayerNative_playAnimation(JNIEnv *, jclass, jint playerId, jstring dict, jstring name, jfloat speed, jint flags) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        std::string convertedDict = JVM::Converter::toString(dict);
        std::string convertedName = JVM::Converter::toString(name);
        player->PlayAnimation(convertedDict, convertedName, speed, flags);
    }
}

void Java_mp_rage_launcher_player_PlayerNative_playScenario(JNIEnv *, jclass, jint playerId, jstring name) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        std::string convertedName = JVM::Converter::toString(name);
        player->PlayScenario(convertedName);
    }
}

void Java_mp_rage_launcher_player_PlayerNative_stopAnimation(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->StopAnimation();
    }
}

jobject Java_mp_rage_launcher_player_PlayerNative_getClothes(JNIEnv *, jclass, jint playerId, jint componentId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        rage::clothData_t clothes = player->GetClothes((uint8_t)componentId);
    }
    JVM::Exception::throwNotImplementedException("Player.getClothes is currently not implemented");
    return nullptr;
}

void Java_mp_rage_launcher_player_PlayerNative_setClothes(JNIEnv *, jclass, jint, jint, jobject) {
    JVM::Exception::throwNotImplementedException("Player.setClothes is currently not implemented");
}

jobject Java_mp_rage_launcher_player_PlayerNative_getProp(JNIEnv *, jclass, jint playerId, jint propId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        rage::propData_t props = player->GetProp((uint8_t)propId);
    }
    JVM::Exception::throwNotImplementedException("Player.getProp is currently not implemented");
    return nullptr;
}

void Java_mp_rage_launcher_player_PlayerNative_setProp(JNIEnv *, jclass, jint playerId, jint propId, jobject) {
    JVM::Exception::throwNotImplementedException("Player.getProp is currently not implemented");
}

void Java_mp_rage_launcher_player_PlayerNative_eval(JNIEnv *, jclass, jint playerId, jstring code) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->Eval(JVM::Converter::toString(code));
    }
}

jstring Java_mp_rage_launcher_player_PlayerNative_getName(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return JVM::Converter::toJString(player->GetName());
    }
    return nullptr;
}

void Java_mp_rage_launcher_player_PlayerNative_setName(JNIEnv *, jclass, jint playerId, jstring name) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->SetName(JVM::Converter::toString(name));
    }
}

jboolean Java_mp_rage_launcher_player_PlayerNative_isAiming(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jboolean)player->IsAiming();
    }
    return (jboolean)false;
}

jfloat Java_mp_rage_launcher_player_PlayerNative_getHeading(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jfloat)player->GetHeading();
    }
    return -1;
}

void Java_mp_rage_launcher_player_PlayerNative_setHeading(JNIEnv *, jclass, jint playerId, jfloat heading) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->SetHeading(heading);
    }
}

jfloat Java_mp_rage_launcher_player_PlayerNative_getMoveSpeed(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return player->GetMoveSpeed();
    }
    return 0;
}

jfloat Java_mp_rage_launcher_player_PlayerNative_getHealth(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return player->GetHealth();
    }
    return 0;
}

void Java_mp_rage_launcher_player_PlayerNative_setHealth(JNIEnv *, jclass, jint playerId, jfloat health) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->SetHealth(health);
    }
}

jfloat Java_mp_rage_launcher_player_PlayerNative_getArmor(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return player->GetArmour();
    }
    return 0;
}

void Java_mp_rage_launcher_player_PlayerNative_setArmor(JNIEnv *, jclass, jint playerId, jfloat armor) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->SetArmour(armor);
    }
}

jobject Java_mp_rage_launcher_player_PlayerNative_getAimingAt(JNIEnv* env, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        rage::vector3 pos = player->GetAimingAt();
        return JVM::Object::vector3(pos.x, pos.y, pos.z);
    }
    return nullptr;
}

jint Java_mp_rage_launcher_player_PlayerNative_getPing(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return player->GetPing();
    }
    return -1;
}

jstring Java_mp_rage_launcher_player_PlayerNative_getKickReason(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        std::string name = player->GetName();
        return JVM::Converter::toJString(name);
    }
    return nullptr;
}

jstring Java_mp_rage_launcher_player_PlayerNative_getIp(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        std::string ip = player->GetIp();
        return JVM::Converter::toJString(ip);
    }
    return nullptr;
}

jboolean Java_mp_rage_launcher_player_PlayerNative_isJumping(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jboolean)player->IsJumping();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_launcher_player_PlayerNative_isInCover(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jboolean)player->IsInCover();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_launcher_player_PlayerNative_isEnteringVehicle(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jboolean)player->IsEnteringVehicle();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_launcher_player_PlayerNative_isLeavingVehicle(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jboolean)player->IsLeavingVehicle();
    }
    return (jboolean)false;
}

jboolean Java_mp_rage_launcher_player_PlayerNative_isClimbing(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jboolean)player->IsClimbing();
    }
    return (jboolean)false;
}

jstring Java_mp_rage_launcher_player_PlayerNative_getActionString(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        std::string action = player->GetActionString();
        return JVM::Converter::toJString(action);
    }
    return nullptr;
}

jint Java_mp_rage_launcher_player_PlayerNative_getVehicle(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        rage::IVehicle *vehicle = player->GetVehicle();
        if(vehicle) {
            return vehicle->GetId();
        }
    }
    return -1;
}

void Java_mp_rage_launcher_player_PlayerNative_putIntoVehicle(JNIEnv *, jclass, jint playerId, jint vehicleId, jint seatId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        rage::IVehicle *vehicle = Game::Vehicle::getVehicleById(vehicleId);
        if(vehicle) {
            player->PutIntoVehicle(vehicle, (int8_t)seatId);
        }
    }
}

void Java_mp_rage_launcher_player_PlayerNative_removeFromVehicle(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->RemoveFromVehicle();
    }
}

jint Java_mp_rage_launcher_player_PlayerNative_getSeat(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jint)player->GetSeat();
    }
    return -1;
}

jint Java_mp_rage_launcher_player_PlayerNative_getEyeColor(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jint)player->GetEyeColour();
    }
    return -1;
}

void Java_mp_rage_launcher_player_PlayerNative_setEyeColor(JNIEnv *, jclass, jint playerId, jint eyeColor) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->SetEyeColour((uint8_t)eyeColor);
    }
}

jint Java_mp_rage_launcher_player_PlayerNative_getHairColor(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jint)player->GetHairColour();
    }
    return -1;
}

jint Java_mp_rage_launcher_player_PlayerNative_getHairHighlightColor(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jint)player->GetHairHighlightColour();
    }
    return -1;
}

void Java_mp_rage_launcher_player_PlayerNative_setHairColor(JNIEnv *, jclass, jint playerId, jint hairColor, jint hairHighlightColor) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->SetHairColour((uint8_t)hairColor, (uint8_t)hairHighlightColor);
    }
}

jfloat Java_mp_rage_launcher_player_PlayerNative_getFaceFeature(JNIEnv *, jclass, jint playerId, jint facePartId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return (jfloat)player->GetFaceFeature((uint8_t)facePartId);
    }
    return -1;
}

void Java_mp_rage_launcher_player_PlayerNative_setFaceFeature(JNIEnv *, jclass, jint playerId, jint faceId, jfloat scale) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->SetFaceFeature((uint8_t)faceId, (uint8_t)scale);
    }
}

jobject Java_mp_rage_launcher_player_PlayerNative_getHeadBlend(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        rage::headBlend_t headBlend = player->GetHeadBlend();
//        @TODO
//        VM::playerHeadBlend(headBlend.m_shape, headBlend.m_skin, headBlend.m_shapeMix, headBlend.m_skinMix, headBlend.m_thirdMix);
    }
    return nullptr;
}

void Java_mp_rage_launcher_player_PlayerNative_setHeadBlend(JNIEnv *, jclass, jint, jint, jint, jint, jint, jint, jint, jfloat, jfloat, jfloat) {
    JVM::Exception::throwNotImplementedException("Player.setHeadBlend is currently not implemented");
}

void Java_mp_rage_launcher_player_PlayerNative_updateHeadBlend(JNIEnv *, jclass, jint, jfloat, jfloat, jfloat) {
    JVM::Exception::throwNotImplementedException("Player.updateHeadBlend is currently not implemented");
}

jint Java_mp_rage_launcher_player_PlayerNative_getWeapon(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {

    }
    return -1;
}

void Java_mp_rage_launcher_player_PlayerNative_giveWeapon(JNIEnv *, jclass, jint playerId, jint hash, jint ammo) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        player->GiveWeapon((rage::hash_t)hash, (uint16_t)ammo);
    }
}

void Java_mp_rage_launcher_player_PlayerNative_giveWeapons(JNIEnv *env, jclass, jint playerId, jintArray weapons, jintArray ammo) {
    return JVM::Exception::throwNotImplementedException("player.giveWeapons is currently broken in the game sdk");
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        jsize weaponLength = env->GetArrayLength(weapons);
        jsize ammoLength = env->GetArrayLength(ammo);
        std::cout << weaponLength << " " << ammoLength << std::endl;

        if(weaponLength != ammoLength) {
            JVM::Exception::throwJNIExecutionException("weapon array length must equals ammo array length");
        }
        jint *weaponElements = env->GetIntArrayElements(weapons, JNI_FALSE);
        jint *ammoElements = env->GetIntArrayElements(ammo, JNI_FALSE);

        std::vector<std::pair<rage::hash_t, uint16_t>> weaponsToAdd;

        for(int i = 0; i < weaponLength; i++) {
            std::cout << weaponElements[i] << " " << ammoElements[i] << std::endl;
            std::pair<rage::hash_t, uint16_t> test = std::make_pair((rage::hash_t)weaponElements[i], (uint16_t)ammoElements[i]);
            weaponsToAdd.push_back(test);
        }

        player->GiveWeapons(weaponsToAdd);

        env->ReleaseIntArrayElements(weapons, weaponElements, 0);
        env->ReleaseIntArrayElements(ammo, ammoElements, 0);
    }

}

jstring Java_mp_rage_launcher_player_PlayerNative_getSerial(JNIEnv *, jclass, jint playerId) {
    rage::IPlayer* player = Game::Player::getPlayerById(JVM::Converter::toInt(playerId));
    if(player) {
        return JVM::Converter::toJString(player->GetSerial());
    }
    return nullptr;
}
