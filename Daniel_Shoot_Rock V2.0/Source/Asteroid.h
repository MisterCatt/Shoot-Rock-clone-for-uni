#pragma once
#include "Core.h"
#include "GameObject.h"
#include <iostream>
#include<math.h>

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

	void WorldWrap();
private:
};

