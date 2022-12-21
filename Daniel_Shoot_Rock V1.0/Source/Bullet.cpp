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
		//Move();

		if (bulletTimer >= 0)
			bulletTimer--;

		if (bulletTimer <= 0) {
			Destroy();
		}
	}
}

void Bullet::Render() {
	if (active)
		DrawCircle(position.x, position.y, 5, WHITE);
		//DrawTextureEx(m_texture, GetPosition(), GetAngle(), 1, RAYWHITE);
}

//void Bullet::Move() {
//	float x_vec = (float)sin(m_angle * 3.14159265358979323846 / -180.0f);
//	float y_vec = (float)cos(m_angle * 3.14159265358979323846 / 180.0f);
//
//	float magnitude = (float)sqrt(x_vec * x_vec + y_vec * y_vec);
//
//	SetX(position.x + x_vec / magnitude * speed);
//	SetY(position.y + y_vec / magnitude * speed);
//}

void Bullet::Destroy() {
	SetActive(false);
}

void Bullet::Unload() {
	UnloadTexture(texture);
}

void Bullet::RestartTimer() {
	bulletTimer = 120;
}
