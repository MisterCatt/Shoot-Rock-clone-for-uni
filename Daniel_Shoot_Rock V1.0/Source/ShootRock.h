#pragma once

#include "raylib.h"
#include "Player.h"

class ShootRock
{
public:
	ShootRock();
	~ShootRock();
	void Update();
	void Render();

	void Play();

private:

	Player* p;

};

