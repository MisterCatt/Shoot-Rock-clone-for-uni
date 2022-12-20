#include "Bullet.h"

Bullet::Bullet() : GameObject("Bullet")
{
}

Bullet::~Bullet()
{
}

void Bullet::Update() {
	//position.x = GetTime() * 5;
	position.y = GetTime() * 5;
}

void Bullet::Render() {
	DrawCircle(position.x, position.y, 10, WHITE);
}