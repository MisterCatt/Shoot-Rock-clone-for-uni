#pragma once

#include "raylib.h"
#include "Player.h"
#include "Rock.h"
#include "UI.h"

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
	/*Rock* r;*/
	UI ui;


};

