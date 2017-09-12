#pragma once

#include "../sdk/rage.hpp"
#include "../sdk/Entities.hpp"
#include "../RageJavaCore.hpp"

class Player {
public:
    static rage::IPlayer* getPlayerById(int playerId);
};
