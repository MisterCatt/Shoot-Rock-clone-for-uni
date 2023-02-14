#pragma once
#include "Core.h"
#include "GameManager.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

	void AddGameManager(GameManager);

private:

	void Update();
	void Render();

	GameManager gm;

};

