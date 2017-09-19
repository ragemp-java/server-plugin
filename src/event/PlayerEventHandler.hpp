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

#include <iostream>
#include <jni.h>
#include "../sdk/rage.hpp"
#include "../jvm/VM.hpp"
#include "../jvm/Converter.hpp"

const std::string playerEventClassName = JVM_LAUNCHER_MAIN_PACKAGE_NAME + "player/PlayerEvents";

class PlayerEventHandler : public rage::IEventHandler, public rage::IPlayerHandler
{
public:
    PlayerEventHandler();

    rage::IPlayerHandler *GetPlayerHandler() override;

    void OnPlayerJoin(rage::IPlayer *player) override;

    void OnPlayerCommand(rage::IPlayer *player, const std::u16string &command) override;

    void OnPlayerQuit(rage::IPlayer *player, rage::exit_t exitType, const char *reason) override;

    void OnPlayerSpawn(rage::IPlayer *player) override;

    void OnPlayerChat(rage::IPlayer *player, const std::u16string &text) override;

    void OnPlayerEnterVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) override;

    void OnPlayerEnteredVehicle(rage::IPlayer *player, rage::IVehicle *vehicle, uint8_t seatId) override;

    void OnPlayerExitVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) override;

    void OnPlayerLeftVehicle(rage::IPlayer *player, rage::IVehicle *vehicle) override;

    void OnPlayerDeath(rage::IPlayer *player, rage::hash_t reason, rage::IPlayer *killer) override;

    void OnPlayerRemoteEvent(rage::IPlayer *player, const std::string &eventName, const rage::args_t &args) override;

private:
    jclass playerEventClass;
    jmethodID playerJoinMethod;
    jmethodID playerCommandMethod;
    jmethodID playerQuitMethod;
    jmethodID playerSpawnMethod;
    jmethodID playerChatMethod;
    jmethodID playerEnterVehicleMethod;
    jmethodID playerEnteredVehicleMethod;
    jmethodID playerExitVehicleMethod;
    jmethodID playerLeftVehicleMethod;
    jmethodID playerDeathMethod;
    jmethodID playerRemoteEventMethod;
};