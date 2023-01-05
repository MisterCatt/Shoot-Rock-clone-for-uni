#pragma once
#include "GameObject.h"
#include "Point.h"

class Asteroid : public GameObject
{
public:
	Asteroid();
	~Asteroid();

	void Render();
	void Update();

	void DrawHitbox();

	void SpawnAsteroid();

	void DestroyAsteroid();

	void Move();

	void WorldWrap();
private:
	float angle;
};

