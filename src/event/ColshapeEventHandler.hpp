#pragma once

#include "../sdk/rage.hpp"

class ColshapeEventHandler : public rage::IColshapeHandler, public rage::IEventHandler {
public:
    void OnPlayerEnterColshape(rage::IPlayer *player, rage::IColshape *colshape) override;

    void OnPlayerExitColshape(rage::IPlayer *player, rage::IColshape *colshape) override;

};