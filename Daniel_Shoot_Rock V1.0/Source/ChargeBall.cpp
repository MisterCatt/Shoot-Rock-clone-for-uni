#include "ChargeBall.h"

ChargeBall::ChargeBall(Color col)
{
	colour = col;

	radius = 40;
	rightDir = GetRandomValue(0,1);

	ballPos = { 0,0 };
}

ChargeBall::~ChargeBall()
{
}

void ChargeBall::SetRightDir(bool goingRight)
{
	rightDir = goingRight;
}

void ChargeBall::Update()
{
	Jitter();
}

void ChargeBall::Render()
{
	DrawCircle((int)ballPos.x, (int)ballPos.y, radius, BLUE);

}

void ChargeBall::SetUp(float xPos, float rad) {
	ballPos.x = xPos;

	radius = rad;
}

void ChargeBall::Jitter()
{

	DrawCircle(100, 100, radius, BLUE);

	ballPos.y = ballPos.y - 40;

	if (rightDir)
		ballPos.x += speed;
	else
		ballPos.x -= speed;

	if (ballPos.x > ballPos.x + 10) {
		rightDir = false;
	}
	if (ballPos.x < ballPos.x - 10)
	{
		rightDir = true;
	}


	if (radius > 20) {
		radius -= 0.5f;
	}
}



