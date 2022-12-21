#include "Player.h"

Player::Player() : GameObject("Player")
{
	texture = LoadTexture("Assets/TestSpin.png");

	rotation = 0;

	position.SetX(GetScreenWidth()/2);
	position.SetY((GetScreenHeight()/3)*2);

	charging = false;
	chargeTime = 0;

	bulletBag = new BulletBag();
}

Player::~Player()
{
}

void Player::Update() {
	if (IsActive()) {
		Input();
		Charging();
	}

	for (Bullet* b : GetBullets()) {
		b->Update();
	}
}

void Player::Input() {
	/*if (IsKeyDown(KEY_E)) {
		rotation++;
	}
	if (IsKeyDown(KEY_Q)) {
		rotation--;
	}*/

	if (IsKeyDown(KEY_A)) {
		position.x--;
	}
	if (IsKeyDown(KEY_D)) {
		position.x++;
	}
	if (IsKeyDown(KEY_W)) {
		position.y--;
	}
	if (IsKeyDown(KEY_S)) {
		position.y++;
	}

	if (IsKeyDown(KEY_Z)) {
		charging = true;
	}
	if (IsKeyReleased(KEY_Z)) {
		charging = false;

		if (chargeTime >= 120) {
			Shoot();
		}
	}
}

void Player::Render() {
	if (IsActive()) {
		DrawTexturePro(
			texture,
			Rectangle{ 0.0f, 0.0f, 25, 50 },
			Rectangle{ position.x,position.y,
			(float)texture.width, (float)texture.height },
			Vector2{ (float)texture.width / 2, (float)texture.height / 2 },
			rotation,
			WHITE);
	}

	for (Bullet* b : GetBullets()) {
		b->Render();
	}
}

void Player::Charging() {
	if (charging == true) {
		chargeTime++;
		std::cout << "Charging" << std::endl;
	}
	else {
		chargeTime = 0;
	}
}

void Player::Shoot() {
	std::cout << "Shot" << std::endl;

	Bullet* b = new Bullet();
	b->position.SetX(position.GetX());
	b->position.SetY(position.GetY() - 5);

	b->SetActive(true);

	bulletsInMotion.push_back(b);
}

std::deque<Bullet*> Player::GetBullets() {
	return bulletsInMotion;
}