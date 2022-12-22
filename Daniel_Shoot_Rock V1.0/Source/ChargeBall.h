#pragma once
#include <raylib.h>
#include "GameObject.h"

class ChargeBall : public GameObject
{
public:
	ChargeBall(Color col, float playerSpeed, bool right);
	~ChargeBall();

	void SetRightDir(bool goingRight);

	void Update();
	void Render();

	void Reset(float xPos, float yPos);

	void Launch();

	void Destroy();

	void Jitter();

private:

	Color colour;

	bool rightDir,startDir,upDir,launching;

	float radius;

	float baseX, baseY, spacing, timer;

};

