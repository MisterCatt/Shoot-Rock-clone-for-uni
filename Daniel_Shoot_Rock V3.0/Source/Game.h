#pragma once
#include "Core.h"
#include "GameManager.h"
#include "UI.h"
#include "Player.h"
#include "AsteroidFall.h"
#include "PointManager.h"

class Game
{
public:
	Game();
	~Game();

	void Run();

	void AddGameManager(GameManager);

private:

	void update();
	void render();

	void resetGame();

	UI* gameUI;
	AsteroidFall* asteroids;

	Player* player;

	PointManager* pointManager;

	GameManager gm;

};

