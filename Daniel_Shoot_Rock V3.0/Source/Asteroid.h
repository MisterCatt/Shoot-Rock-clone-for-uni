#pragma once
#include "GameObject.h"
#include "Point.h"
#include "GameManager.h"

class Asteroid : public GameObject
{
public:
	Asteroid();
	~Asteroid();

	void Render();
	void Update();

	void SpawnAsteroid();

	void DestroyAsteroid();

	void Move();

	void WorldWrap();

	void AddManager(GameManager&);
private:
	float angle;

	GameManager gm;
};

