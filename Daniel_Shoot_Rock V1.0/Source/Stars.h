#pragma once
#include <raylib.h>
#include "GameObject.h"

class Stars : GameObject
{
public:
	Stars();
	~Stars();

	void Render();
	void Update();

	void WorldWrap();

private:

	int frameCount;
	float jitterSpeed;

};

