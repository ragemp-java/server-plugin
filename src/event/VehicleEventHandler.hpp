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

#include "../sdk/rage.hpp"

class VehicleEventHandler : public rage::IEventHandler, public rage::IVehicleHandler {
public:
    void OnVehicleDeath(rage::IVehicle *vehicle, rage::hash_t hash, rage::IPlayer *killer) override;

    rage::IVehicleHandler *GetVehicleHandler() override;
};