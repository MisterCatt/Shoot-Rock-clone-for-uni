#include "Asteroid.h"

Asteroid::Asteroid() : GameObject()
{
	SetSpeed(10);
	
	SetActive(false);

	SetPosition(Vector2{ (float)GetRandomValue(0, GetScreenWidth()), 100});

	angle = (float)GetRandomValue(315,405);
}

Asteroid::~Asteroid()
{
}

void Asteroid::Render()
{
	if (!IsActive())
		return;

	gm.DrawTexture("Asteroid", angle, (int)_Position.x, (int)_Position.y);
}

void Asteroid::Update()
{
	if (!IsActive())
		return;
	
	SetAngle(GetAngle() - 5);

	Move();

	WorldWrap();

	
}

void Asteroid::Move() {
	float x_vec = (float)sin(angle * 3.14159265358979323846 / -180.0f);
	float y_vec = (float)cos(angle * 3.14159265358979323846 / 180.0f);

	float magnitude = (float)sqrt(x_vec * x_vec + y_vec * y_vec);

	_Position = { GetPosition().x + x_vec / magnitude * GetSpeed(), GetPosition().y + y_vec / magnitude * GetSpeed() };

}

void Asteroid::SpawnAsteroid()
{
	SetPosition(Vector2{ (float)GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(-100, -400) });

	SetActive(true);
}

void Asteroid::DestroyAsteroid()
{
	SetActive(false);
}

void Asteroid::WorldWrap()
{
	if (_Position.y > (float)GetScreenHeight() + 400)
		SetActive(false);

	if (_Position.x > (float)GetScreenWidth() + 50)
		_Position.x = 0;
	if (_Position.x < 0)
		_Position.x = (float)GetScreenWidth();
}

void Asteroid::AddManager(GameManager& _gm)
{
	gm = _gm;
}
