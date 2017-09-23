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
#include "../jvm/VM.hpp"

class CheckpointEventHandler : public rage::ICheckpointHandler, public rage::IEventHandler {
public:
    CheckpointEventHandler();

    rage::ICheckpointHandler *GetCheckpointHandler() override {
        return this;
    }

    void OnPlayerEnterCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) override;

    void OnPlayerExitCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) override;

private:
    jclass checkpointEventClass;
    jmethodID playerEnterCheckpointMethod;
    jmethodID playerExitCheckpointMethod;
};
