// Snake.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Game.h"

int main()
{
	Game game;
	while (!game.GetWindow().IsDone())
	{
		game.HandleInput();
		game.Update();
		game.Render();
		game.RestartClock();
	}
    return 0;
}

