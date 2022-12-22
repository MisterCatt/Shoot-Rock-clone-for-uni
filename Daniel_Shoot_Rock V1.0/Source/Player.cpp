#include "Player.h"

Player::Player() : GameObject("Player")
{
	texture = LoadTexture("Assets/SpaceShip.png");

	rotation = 0;

	position.SetX((float)GetScreenWidth()/2);
	position.SetY((float)(GetScreenHeight()/3)*2);

	charging = false;
	chargeTime = 0;

	speed = 5;

	chargeCooldown = 1.4f;

	newTime = oldTime = dif = 0;

	cb.push_back(new ChargeBall(WHITE, speed, true));
	cb.push_back(new ChargeBall(BLUE, speed, true));
	cb.push_back(new ChargeBall(DARKBLUE, speed, false));
}

Player::~Player()
{
}

void Player::Update() {
	if (IsActive()) {
		Input();
		
		for (ChargeBall* c : cb)
			c->Update();
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
		
		for (ChargeBall* c : cb)
			c->Reset(position.x, position.y-40);
		
		charging = true;
	}
	if (IsKeyReleased(KEY_Z)) {
		newTime = GetTime();

		dif = (newTime - oldTime) + 1;

		std::cout << dif << std::endl;

		charging = false;
		if(dif >= chargeCooldown)
		Shoot();
		else
			for (ChargeBall* c : cb)
				c->SetActive(false);
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

	for(ChargeBall* c : cb)
		c->Render();
}

void Player::Charging() {
	
}


void Player::Shoot() {
	std::cout << "Shot" << std::endl;

	for (ChargeBall* c : cb)
		c->Launch();
}

