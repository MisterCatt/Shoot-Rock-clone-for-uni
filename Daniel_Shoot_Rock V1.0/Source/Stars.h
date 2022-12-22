#pragma once
#include <raylib.h>
#include "GameObject.h"
#include <math.h>

class Stars : GameObject
{
public:
	Stars();
	~Stars();

	void Render();
	void Update();

	void Move();

	void WorldWrap();

private:

	int frameCount;
	float jitterSpeed, starSize, angle;

	bool right;

};

