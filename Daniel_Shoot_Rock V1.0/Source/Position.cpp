#include "Position.h"

Position::Position()
{
}

Position::~Position()
{
}

Vector2 Position::GetVector2() {
	return position;
}

void Position::SetX(float xpos) {
	position.x = xpos;
}

void Position::SetY(float ypos) {
	position.y = ypos;
}