#include "Asteroid.h"

Asteroid::Asteroid() : GameObject()
{
	SetTexture("Assets/Asteroid.png");

	SetSpeed(10);
	
	SetActive(false);

	SetPosition(Vector2{ (float)GetRandomValue(0, GetScreenWidth()), 100});
}

Asteroid::~Asteroid()
{
}

void Asteroid::Render()
{
	if (!IsActive())
		return;

	DrawTexturePro(
		_Texture,
		Rectangle{ 0.0f, 0.0f, (float)_Texture.width, (float)_Texture.height },
		Rectangle{ _Position.x,_Position.y,
		(float)_Texture.width, (float)_Texture.height },
		Vector2{ (float)_Texture.width / 2, (float)_Texture.height / 2 },
		GetAngle(),
		WHITE);
}

void Asteroid::Update()
{
	if (!IsActive())
		return;

	if (IsKeyDown(KEY_P)) {
		DrawHitbox();
	}
	
	SetAngle(GetAngle() - 5);

	_Position.y+=_Speed;

	WorldWrap();

	
}

void Asteroid::DrawHitbox()
{
	DrawRectangleRec(GetHitBox(), RED);
}

void Asteroid::SpawnAsteroid()
{
	SetPosition(Vector2{ (float)GetRandomValue(0, GetScreenWidth()), (float)GetRandomValue(-100, -400) });

	SetActive(true);
}

void Asteroid::DestroyAsteroid()
{
	//Play Animation


	SetActive(false);
}

void Asteroid::WorldWrap()
{
	if (_Position.y > GetScreenHeight() + 400)
		SetActive(false);
}
