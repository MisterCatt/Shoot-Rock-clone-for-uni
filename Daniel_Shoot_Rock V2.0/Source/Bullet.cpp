#include "Bullet.h"


Bullet::Bullet() : GameObject()
{
	radius = 10;
	secondsActive = 0;
	SetSpeed(20);

	SetActive(true);
}

Bullet::~Bullet()
{
}

void Bullet::Update() 
{
	if (IsKeyDown(KEY_P)) {
		DrawHitbox();
	}

	if (!IsActive())
		return;
	SetPosition(GetPosition().x, GetPosition().y-GetSpeed());

	secondsActive += GetFrameTime();
	if (secondsActive > 1) {
		SetActive(false);
	}
}

void Bullet::Render() 
{
	if (!IsActive())
		return;
	DrawCircle((int)GetPosition().x-5, (int)GetPosition().y,radius, DARKBLUE);
	DrawCircle((int)GetPosition().x+5, (int)GetPosition().y,radius, BLUE);
	DrawCircle((int)GetPosition().x, (int)GetPosition().y,radius, WHITE);

}

void Bullet::SetSize(float _size)
{
	radius = _size;
}

void Bullet::Reset()
{
	SetPosition(0,0);
	secondsActive = 0;
}

void Bullet::DestroyBullet() 
{
	delete this;
}

void Bullet::Unload() {
	SetActive(false);
	SetPosition({ (float)INT_MAX ,(float)INT_MAX });
}

Rectangle Bullet::GetHitBox()
{
	return Rectangle{ GetPosition().x - radius, GetPosition().y - radius, radius*2, radius * 2 };
}

void Bullet::DrawHitbox()
{
	DrawRectangleRec(GetHitBox(), RED);
}