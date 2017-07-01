//
// Created by Fabian Jungwirth on 02.07.2017.
//

#ifndef RAGEJAVA_VEHICLEEVENTHANDLER_HPP
#define RAGEJAVA_VEHICLEEVENTHANDLER_HPP


#include "../sdk/rage.hpp"

class VehicleEventHandler : public rage::IEventHandler, public rage::IVehicleHandler {
public:
    void OnVehicleDeath(rage::IVehicle *vehicle, rage::hash_t hash, rage::IPlayer *killer) override;

    rage::IVehicleHandler *GetVehicleHandler() override;
};


#endif //RAGEJAVA_VEHICLEEVENTHANDLER_HPP
