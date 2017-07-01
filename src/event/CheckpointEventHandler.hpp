//
// Created by Fabian Jungwirth on 02.07.2017.
//

#ifndef RAGEJAVA_CHECKPOINTEVENTHANDLER_HPP
#define RAGEJAVA_CHECKPOINTEVENTHANDLER_HPP


#include "../sdk/rage.hpp"

class CheckpointEventHandler : public rage::ICheckpointHandler, public rage::IEventHandler {
public:
    void OnPlayerEnterCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) override;

    void OnPlayerExitCheckpoint(rage::IPlayer *player, rage::ICheckpoint *checkpoint) override;

};


#endif //RAGEJAVA_CHECKPOINTEVENTHANDLER_HPP
