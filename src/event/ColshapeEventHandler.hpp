//
// Created by Fabian Jungwirth on 02.07.2017.
//

#ifndef RAGEJAVA_COLSHAPEEVENTHANDLER_HPP
#define RAGEJAVA_COLSHAPEEVENTHANDLER_HPP


#include "../sdk/rage.hpp"

class ColshapeEventHandler : public rage::IColshapeHandler, public rage::IEventHandler {
public:
    void OnPlayerEnterColshape(rage::IPlayer *player, rage::IColshape *colshape) override;

    void OnPlayerExitColshape(rage::IPlayer *player, rage::IColshape *colshape) override;

};


#endif //RAGEJAVA_COLSHAPEEVENTHANDLER_HPP
