#pragma once
#include "Core.h"
#include "UI.h"
#include "Player.h"
#include "AsteroidFall.h"

class ShootRock_Game
{
public:
	ShootRock_Game();
	~ShootRock_Game();

	void Run();

private:

	void update();
	void render();

	UI gameUI;
	AsteroidFall asteroids;

	Player* player;


};

