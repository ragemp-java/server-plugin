#pragma once

#include "../sdk/rage.hpp"

class VehicleEventHandler : public rage::IEventHandler, public rage::IVehicleHandler {
public:
    void OnVehicleDeath(rage::IVehicle *vehicle, rage::hash_t hash, rage::IPlayer *killer) override;

    rage::IVehicleHandler *GetVehicleHandler() override;
};