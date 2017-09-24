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

class ColshapeEventHandler : public rage::IColshapeHandler, public rage::IEventHandler, public rage::IEntityHandler {
public:

    ColshapeEventHandler();

    rage::IEntityHandler *GetEntityHandler() override {
        return this;
    }

    rage::IColshapeHandler *GetColshapeHandler() override {
        return this;
    }

    void OnPlayerEnterColshape(rage::IPlayer *player, rage::IColshape *colshape) override;

    void OnPlayerExitColshape(rage::IPlayer *player, rage::IColshape *colshape) override;

    void OnEntityCreated(rage::IEntity *entity) override;

    void OnEntityDestroyed(rage::IEntity *entity) override;

private:
    jclass colshapeEventClass;
    jmethodID playerEnterColshapeMethod;
    jmethodID playerExitColshapeMethod;
    jmethodID colshapeCreatedMethod;
    jmethodID colshapeDestroyedMethod;
};