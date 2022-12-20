#include "Position.h"

Position::Position()
{
	x = 0;
	y = 0;
}

Position::Position(float xPos, float yPos) {
	x = xPos;
	y = yPos;
}

Position::~Position()
{
}

Vector2 Position::GetVector2() {
	return Vector2 {x, y};
}

void Position::SetX(float xpos) {
	x = xpos;
}

void Position::SetY(float ypos) {
	y = ypos;
}

float Position::GetX() {
	return x;
}

float Position::GetY() {
	return y;
}