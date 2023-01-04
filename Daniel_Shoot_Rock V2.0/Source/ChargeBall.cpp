#include "ChargeBall.h"

ChargeBall::ChargeBall(Vector2 _pos)
{
	goingRight = false;

	position = _pos;
	position.y += 10;

	spacing = maxRadius = radius = 40;

	minRadius = 10;

	ballColor = WHITE;

	speed = 10;

	minX = _pos.x - spacing;
	maxX = _pos.x + spacing;

}

ChargeBall::~ChargeBall()
{
}

void ChargeBall::GoingRight(bool _right)
{
	goingRight = _right;
}

void ChargeBall::Update()
{
	if (IsKeyDown(KEY_A)) {
		minX -= speed;
		maxX -= speed;
	}
	if (IsKeyDown(KEY_D)) {
		minX += speed;
		maxX += speed;
	}
	if (IsKeyDown(KEY_W)) {
		position.y -= speed;
	}
	if (IsKeyDown(KEY_S)) {
		position.y += speed;
	}

	position.x += (goingRight) ? speed : -speed;

	if (position.x > maxX)
		goingRight = false;

	if (position.x < minX)
		goingRight = true;
	
}

void ChargeBall::Render()
{
	DrawCircle(position.x,position.y,radius,ballColor);
}

void ChargeBall::SetBallColor(Color _color)
{
	ballColor = _color;
}

void ChargeBall::SetPosition(Vector2 _position)
{
	position.x = _position.x;
	position.y = _position.y;
}

void ChargeBall::SetPosition(int _x, int _y)
{
	position.x = _x;
	position.y = _y;
}

void ChargeBall::SetYPos(int _y)
{
	position.y = _y;
}

void ChargeBall::SetXPos(int _x)
{
	position.x = _x;
}

void ChargeBall::SetSpeed(float _speed)
{
	speed = _speed;
}
