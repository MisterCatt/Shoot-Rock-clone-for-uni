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

	void Timer();

	void StopSpawning();

private:
	int totalAsteroids;
	float spawnTimer, timerCurrent;

	std::list<Asteroid*> asteroidBag;

	Player* player;
	bool spawned, isActive, stopSpawning;

	//Timer variables
	float time;
	int seconds, minutes, hours, spawnStopTime;
};

