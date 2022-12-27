#pragma once
#include "Core.h"

class Star
{
public:
	Star();
	~Star();

	void Render();
	void Update();

	void Move();

	void WorldWrap();

private:

	int frameCount;
	float jitterSpeed, starSize, angle, speed;

	bool right;

	Vector2 starPosition;

};