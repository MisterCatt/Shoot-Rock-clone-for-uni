#include "Stars.h"

Stars::Stars() : GameObject("Star")
{
	position.SetY(GetRandomValue(0, GetScreenHeight()));
	position.SetX(GetRandomValue(0, GetScreenWidth()));
	jitterSpeed = 1;
	speed = 15;

	frameCount = 0;
}

Stars::~Stars()
{
}

void Stars::Update() {
	position.y += speed;
	if (frameCount >= 5) {
		frameCount = 0;

		if (jitterSpeed > 0)
			jitterSpeed = -1;
		else
			jitterSpeed= 1;
	}
	

	position.x += jitterSpeed;

	WorldWrap();
	frameCount++;
}

void Stars::Render() {
	DrawRectanglePro(Rectangle {position.x, position.y, 5, 5}, Vector2{2.5f,2.5f}, 0, GRAY);
	DrawRectanglePro(Rectangle {position.x, position.y, 5, 5}, Vector2{2.5f,2.5f}, 45, GRAY);

	
}

void Stars::WorldWrap() {
	if (position.y > GetScreenHeight()) {
		position.y = 0;
		position.SetX(GetRandomValue(0, GetScreenWidth()));
	}

	
}