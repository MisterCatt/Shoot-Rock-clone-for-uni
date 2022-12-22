#pragma once
#include <raylib.h>

class ChargeBall
{
public:
	ChargeBall(Color col);
	~ChargeBall();

	void SetRightDir(bool goingRight);
	void SetUp(float xPos, float rad);

	void Update();
	void Render();

	void Jitter();

private:

	Color colour;

	bool rightDir;

	float radius, speed;

	struct B_Pos {
		float x, y;
	} ballPos;

};

