#include "Game.hpp"

void Game::Play()
{
	int game_tick{};
	while (!is_win())
	{
		for (size_t i = 0; i < scene.Size(); i++)
		{
			scene[i].Who()->Action(game_tick);
		}
		game_tick += 1;
	}
}
