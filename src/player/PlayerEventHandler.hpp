#ifndef RAGEJAVA_PLAYEREVENTHANDLER_H
#define RAGEJAVA_PLAYEREVENTHANDLER_H
#include <iostream>
#include "../sdk/rage.hpp"

class PlayerEventHandler : public rage::IEventHandler, public rage::IPlayerHandler
{
public:
	virtual IPlayerHandler* GetPlayerHandler()
	{
		return this;
	}
	virtual void OnPlayerJoin(rage::IPlayer* player);
	virtual void OnPlayerCommand(rage::IPlayer* player, const std::wstring& command);
};

#endif //RAGEJAVA_PLAYEREVENTHANDLER_H
