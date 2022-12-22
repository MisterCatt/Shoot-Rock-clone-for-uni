#include "Rock.h"

Rock::Rock() : GameObject("Asteroid")
{
	//texture = LoadTexture("assets/bullet.png");

	speed = 1;
	acceleration = 0.015f;

	rockTimer = 120;

	position.SetX(0);
	position.SetY(0);
	SetActive(false);
}

Rock::~Rock()
{
}

void Rock::Update()
{
	if (active) {
		position.y += speed;

		if (rockTimer >= 0)
			rockTimer--;

		if (rockTimer <= 0) {
			Destroy();
		}

		speed += (speed * acceleration);
	}
}


void Rock::Render()
{
	if (active) {
		DrawCircle(position.x, position.y, 5, RED);
	}
}

void Rock::Unload()
{
	UnloadTexture(texture);
}

void Rock::Destroy()
{
	SetActive(false);
}

void Rock::RestartTimer()
{
	rockTimer = 1000000;
}


