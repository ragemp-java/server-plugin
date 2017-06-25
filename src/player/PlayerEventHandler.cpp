#include "PlayerEventHandler.hpp"

void PlayerEventHandler::OnPlayerJoin(rage::IPlayer* player)
{
	std::cout << player->GetId() << std::endl;
}

void PlayerEventHandler::OnPlayerCommand(rage::IPlayer* player, const std::wstring& command)
{
	std::wcout << player->GetId() << " " << command << std::endl;
}