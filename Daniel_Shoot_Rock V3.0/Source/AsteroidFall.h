#pragma once
#include "Core.h"
#include "Asteroid.h"
#include "Player.h"
#include "PointManager.h"

class AsteroidFall
{
public:
	AsteroidFall();
	~AsteroidFall();

	int PlayerCollision();
	int BulletCollision();

	void Update();
	void Render();

	void SpawnAsteroids();

	bool IsActive();
	void SetActive(bool _active);

	void Timer();

	void StopSpawning();

	void AddManager(GameManager& gm);

private:
	int totalAsteroids;
	float spawnTimer, timerCurrent;

	std::list<Asteroid*> asteroidBag;

	Player* player;
	bool spawned, isActive, stopSpawning;

	//Timer variables
	float time;
	int seconds, spawnStopTime;

	PointManager* pointManager;

	GameManager gm;
};

