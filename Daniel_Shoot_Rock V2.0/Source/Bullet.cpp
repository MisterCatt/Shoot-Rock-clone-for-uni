#include "Bullet.h"


Bullet::Bullet() : GameObject()
{
	radius = 10;
	SetSpeed(20);

	SetActive(true);
}

Bullet::~Bullet()
{
}

void Bullet::Update() 
{
	if (!IsActive())
		return;
	SetPosition(GetPosition().x, GetPosition().y-GetSpeed());
}

void Bullet::Render() 
{
	if (!IsActive())
		return;
	DrawCircle(GetPosition().x-5, GetPosition().y,radius, DARKBLUE);
	DrawCircle(GetPosition().x+5, GetPosition().y,radius, BLUE);
	DrawCircle(GetPosition().x, GetPosition().y,radius, WHITE);

}

void Bullet::SetSize(float _size)
{
	radius = _size;
}

void Bullet::DestroyBullet() 
{
	delete this;
}

void Bullet::Unload() {
	SetActive(false);
	SetPosition({ (float)INT_MAX ,(float)INT_MAX });
}
