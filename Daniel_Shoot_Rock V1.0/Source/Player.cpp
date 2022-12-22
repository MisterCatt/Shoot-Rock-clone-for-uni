#include "Player.h"

Player::Player() : GameObject("Player")
{
	cb.push_back(new ChargeBall(WHITE));
	cb.push_back(new ChargeBall(BLUE));
	cb.push_back(new ChargeBall(DARKBLUE));

	texture = LoadTexture("Assets/SpaceShip.png");

	rotation = 0;

	position.SetX((float)GetScreenWidth()/2);
	position.SetY((float)(GetScreenHeight()/3)*2);

	charging = false;
	chargeTime = 0;

	speed = 5;

	chargeCooldown = 1.4f;

	newTime = oldTime = dif = 0;

	ballSpeed = 8;
	ballAngle = 180;

	goingRigth = true;
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
	

	if (IsKeyDown(KEY_A)) {
		if(position.GetX() > (0 + texture.width / 2))
		position.x -= speed;
	}
	if (IsKeyDown(KEY_D)) {
		if (position.GetX() < (GetScreenWidth() - texture.width/2))
		position.x+=speed;
	}
	if (IsKeyDown(KEY_W)) {
		if(position.GetY() > 0)
		position.y-=speed;
	}
	if (IsKeyDown(KEY_S)) {
		if(position.y < GetScreenHeight())
		position.y+=speed;
	}

	if (IsKeyPressed(KEY_Z)) {
		oldTime = GetTime();
		charging = true;

		for (ChargeBall* c : cb) {
			c->SetUp(position.GetX(), 40);
		}

		ballRadius = 40;
		ballPos.x = position.GetX();
	}
	if (IsKeyReleased(KEY_Z)) {
		newTime = GetTime();

		dif = (newTime - oldTime) + 1;

		std::cout << dif << std::endl;

		charging = false;
		if(dif >= chargeCooldown)
		Shoot();
	}

}

void Player::Render() {
	if (IsActive()) {

		DrawTexturePro(
			texture,
			Rectangle{ 0.0f, 0.0f, (float)texture.width, (float)texture.height},
			Rectangle{ position.x,position.y,
			(float)texture.width, (float)texture.height },
			Vector2{ (float)texture.width / 2, (float)texture.height / 2 },
			rotation,
			WHITE);
	}

	for (Bullet* b : GetBullets()) {
		b->Render();
	}

	if (charging) {
		for (ChargeBall* c : cb) {
			c->Render();
		}
	}
		//DrawCircle((int)ballPos.x, (int)ballPos.y, ballRadius, BLUE);
}

void Player::Charging() {
	if (charging) {
		
		for (ChargeBall* c : cb) {
			c->Jitter();
		}

		
			
	}
}


void Player::BallMove() {
	float x_vec = (float)sin(ballAngle * 3.14159265358979323846 / -180.0f);
	float y_vec = (float)cos(ballAngle * 3.14159265358979323846 / 180.0f);

	float magnitude = (float)sqrt(x_vec * x_vec + y_vec * y_vec);

	ballPos.x = (ballPos.x + x_vec / magnitude * ballSpeed);
	ballPos.y =(ballPos.y + y_vec / magnitude * ballSpeed);
}

void Player::Shoot() {
	std::cout << "Shot" << std::endl;

	Bullet* b = GetBulletFromBag();
	b->position.SetX(position.GetX());
	b->position.SetY(position.GetY() - 5);
	b->RestartTimer();

	b->SetActive(true);
}

std::deque<Bullet*> Player::GetBullets() {
	return bulletsInMotion;
}

void Player::BulletBag() {

}

Bullet* Player::GetBulletFromBag() {
	if (bulletsInMotion.empty()) {
		bulletsInMotion.push_back(new Bullet());
		return bulletsInMotion.at(0);
	}
	else {
		for (int i = 0; i < bulletsInMotion.size(); i++) {
			if (!bulletsInMotion.at(i)->IsActive()) {
				return bulletsInMotion.at(i);
			}
		}
		bulletsInMotion.push_back(new Bullet());
		return bulletsInMotion.back();
	}
	return nullptr;
}