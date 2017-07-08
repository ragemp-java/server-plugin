#pragma once

#include "../sdk/rage.hpp"

class CheckpointEventHandler : public rage::ICheckpointHandler, public rage::IEventHandler {
public:
    void OnPlayerEnterCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) override;

    void OnPlayerExitCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) override;

};
