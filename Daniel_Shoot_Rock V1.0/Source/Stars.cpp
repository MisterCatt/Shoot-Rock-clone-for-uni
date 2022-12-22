#include "Stars.h"

Stars::Stars() : GameObject("Star")
{
	position.SetY(GetRandomValue(0, GetScreenHeight()));
	position.SetX(GetRandomValue(0, GetScreenWidth()));
	jitterSpeed = 1;
	speed = 15;

	frameCount = 0;

	starSize = 8;

	angle = GetRandomValue(-5, 5);

	right = true;
}

Stars::~Stars()
{
}

void Stars::Update() {
	Move();

	if (frameCount >= 5) {
		frameCount = 0;

		if (jitterSpeed > 0)
			jitterSpeed = -1;
		else
			jitterSpeed = 1;
	}

	position.x += jitterSpeed;

	WorldWrap();
	frameCount++;
}

void Stars::Render() {
	DrawRectanglePro(Rectangle {position.x, position.y, starSize, starSize}, Vector2{2.5f,2.5f}, 0, GRAY);
	DrawRectanglePro(Rectangle {position.x, position.y, starSize, starSize}, Vector2{2.5f,2.5f}, 45, GRAY);

	
}

void Stars::WorldWrap() {
	if (position.y > GetScreenHeight()) {
		position.y = 0;
		position.SetX(GetRandomValue(0, GetScreenWidth()));


		angle = GetRandomValue(-5, 5);
	}

	if (position.x > GetScreenWidth()) {
		position.SetX(0);
	}
	if (position.x < 0) {
		position.SetX(GetScreenWidth());
	}
}

void Stars::Move() {
	float x_vec = (float)sin(angle * 3.14159265358979323846 / -180.0f);
	float y_vec = (float)cos(angle * 3.14159265358979323846 / 180.0f);

	float magnitude = (float)sqrt(x_vec * x_vec + y_vec * y_vec);

	position.SetX(position.x + x_vec / magnitude * speed);
	position.SetY(position.y + y_vec / magnitude * speed);
}