#pragma once
#include "UI.h"
#include "Player.h"
#include "AsteroidFall.h"
#include "PointManager.h"

class ShootRock_Game
{
public:
	ShootRock_Game();
	~ShootRock_Game();

	void Run();

private:

	void update();
	void render();

	void resetGame();

	UI* gameUI;
	AsteroidFall* asteroids;

	Player* player;

	PointManager* pointManager;

	Sound pickupCoinSound = LoadSound("Assets/CoinPickupSound.wav");

};

