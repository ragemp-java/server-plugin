#include "Player.hpp"

rage::IPlayer* Player::getPlayerById(int playerId) {
    rage::IMultiplayer *mp = RageJavaCore::getInstance().getMultiPlayer();
    if(mp == nullptr) {
        return nullptr;
    }
    rage::IPlayer *player = mp->GetPlayerPool().GetAt((rage::entityId_t)TypeConverter::fromJInt(playerId));
    return player;
}
