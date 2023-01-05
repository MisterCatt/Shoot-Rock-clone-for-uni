#include "Point.h"

Point::Point()
{
	radius = 5.0f;
	SetSpeed(5);

	goingUp = true;

	maxHeight = 0;

	angle = GetRandomValue(135, 225);

	SetActive(false);
}

Point::~Point()
{
}

void Point::Update()
{
	if (!IsActive())
		return;

	if (goingUp)
		Move();
	else
		_Position = { GetPosition().x, GetPosition().y + GetSpeed() };

	if (_Position.y < maxHeight && goingUp) {
		goingUp = false;
		SetSpeed(GetSpeed()/2);
	}

	if (GetPosition().y > GetScreenHeight() + 50) {
		SetActive(false);
	}
}

void Point::Move() {
	float x_vec = (float)sin(angle * 3.14159265358979323846 / -180.0f);
	float y_vec = (float)cos(angle * 3.14159265358979323846 / 180.0f);

	float magnitude = (float)sqrt(x_vec * x_vec + y_vec * y_vec);

	_Position = { GetPosition().x + x_vec / magnitude * GetSpeed(), GetPosition().y + y_vec / magnitude * GetSpeed() };

}

void Point::PickUpPoint()
{
	SetActive(false);
}

void Point::Render()
{
	if (!IsActive())
		return;

	DrawCircle(_Position.x, _Position.y, radius, RED);

	if (IsKeyDown(KEY_P)) {
		DrawHitbox();
	}
}

void Point::SetPosition(Vector2 _position)
{
	_Position = _position;
	maxHeight = _Position.y - GetRandomValue(100,150);
}

void Point::SetPosition(float _x, float _y)
{
	_Position.x = _x;
	_Position.y = _y;

	maxHeight = _Position.y - GetRandomValue(100, 150);
}

Rectangle Point::GetHitBox()
{
	return Rectangle{ GetPosition().x - radius, GetPosition().y - radius, radius, radius };
}

void Point::DrawHitbox()
{
	DrawRectangleRec(GetHitBox(), BLUE);
}

void Point::Reset()
{
	angle = GetRandomValue(135, 225);
	goingUp = true;
	SetSpeed(5);
}
