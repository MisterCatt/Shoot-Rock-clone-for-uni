#pragma once
#include "Core.h"
#include "Asteroid.h"
#include "Player.h"

class AsteroidFall
{
public:
	AsteroidFall();
	~AsteroidFall();

	int PlayerCollision();

	void Update();
	void Render();

	void SpawnAsteroids();

	bool IsActive();
	void SetActive(bool _active);

private:
	int totalAsteroids;
	float spawnTimer;

	std::list<Asteroid*> asteroidBag;

	Player* player;
	bool spawned, isActive;

	float timerCurrent;
};

