#include "Bullet.h"

Bullet::Bullet() : GameObject("Bullet")
{
	//texture = LoadTexture("assets/bullet.png");

	speed = 10;

	bulletTimer = 120;

	position.SetX(0);
	position.SetY(0);
	SetActive(false);
}

Bullet::~Bullet()
{
	Unload();
}

void Bullet::Update() {

	if (active) {
		position.y -= speed;

		if (bulletTimer >= 0)
			bulletTimer--;

		if (bulletTimer <= 0) {
			Destroy();
		}
	}
}

void Bullet::Render() {
	//if (active)
		
		//DrawCircle(position.x, position.y, 8, WHITE);
		//DrawTextureEx(m_texture, GetPosition(), GetAngle(), 1, RAYWHITE);
}

void Bullet::Destroy() {
	SetActive(false);
}

void Bullet::Unload() {
	UnloadTexture(texture);
}

void Bullet::RestartTimer() {
	bulletTimer = 120;
}
