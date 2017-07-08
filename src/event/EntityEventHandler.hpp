#pragma once

#include "../sdk/rage.hpp"

class EntityEventHandler : public rage::IEventHandler, public rage::IEntityHandler {
public:
    void OnEntityCreated(rage::IEntity *entity) override;

    void OnEntityDestroyed(rage::IEntity *entity) override;
};
