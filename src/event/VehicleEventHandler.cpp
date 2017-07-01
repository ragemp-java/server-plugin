#include "VehicleEventHandler.hpp"

rage::IVehicleHandler *VehicleEventHandler::GetVehicleHandler() {
    return this;
}

void VehicleEventHandler::OnVehicleDeath(rage::IVehicle *vehicle, rage::hash_t hash, rage::IPlayer *killer) {

}
