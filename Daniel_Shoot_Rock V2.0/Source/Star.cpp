#include "Star.h"

Star::Star()
{
	starPosition.x = GetRandomValue(0, GetScreenWidth());
	starPosition.y = (GetRandomValue(0, GetScreenHeight()));
	angle = GetRandomValue(-5, 5);

	speed = 15;

	jitterSpeed = 1;

	frameCount = 0;

	starSize = (GetScreenWidth() / 384 + GetScreenHeight() / 384);

	right = true;
}

Star::~Star()
{
}

void Star::Render()
{
	DrawRectanglePro(Rectangle{ starPosition.x, starPosition.y, starSize, starSize }, Vector2{ 2.5f,2.5f }, 0, GRAY);
	DrawRectanglePro(Rectangle{ starPosition.x, starPosition.y, starSize, starSize }, Vector2{ 2.5f,2.5f }, 45, GRAY);
}

void Star::Update()
{
	Move();

	if (frameCount >= 5) {
		frameCount = 0;

		if (jitterSpeed > 0)
			jitterSpeed = -1;
		else
			jitterSpeed = 1;
	}

	starPosition.x += jitterSpeed;

	WorldWrap();
	frameCount++;
}

void Star::Move()
{
	float x_vec = (float)sin(angle * 3.14159265358979323846 / -180.0f);
	float y_vec = (float)cos(angle * 3.14159265358979323846 / 180.0f);

	float magnitude = (float)sqrt(x_vec * x_vec + y_vec * y_vec);

	starPosition.x = starPosition.x + x_vec / magnitude * speed;
	starPosition.y = starPosition.y + y_vec / magnitude * speed;
}

void Star::WorldWrap()
{
	if (starPosition.y > GetScreenHeight()) {
		starPosition.y = 0;
		starPosition.x = GetRandomValue(0, GetScreenWidth());


		angle = GetRandomValue(-5, 5);
	}

	if (starPosition.x > GetScreenWidth()) {
		starPosition.x = 0;
	}
	if (starPosition.x < 0) {
		starPosition.x = GetScreenWidth();
	}
}
