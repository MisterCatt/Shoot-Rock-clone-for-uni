#include "Player.h"

Player* Player::instance = 0;

Player* Player::GetInstance()
{
	if (!instance) {
		instance = new Player();
		std::cout << "Created new Instance";
		return instance;
	}
	else {
		std::cout << "Instance exists, returning old instance";
		return instance;
	}
}

Player::Player() {
	SetTexture("Assets/SpaceShip.png");
	SetSpeed(10);

	ui = UI::GetInstance();

	shootCoolDown = 1;

	chargeTime = newTime = oldTime = dif = 0;

	isDead = charging = false;
	noBullets = true;

}

Player::~Player()
{
	
}

void Player::Render()
{
	if (!BulletBag.empty())
		for (Bullet* b : BulletBag)
			if(b->IsActive())
				b->Render();

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

void Player::Update()
{
	if (ui->GetScore() > ui->GetWinScore()) {
		PlayerDied();
	}

	if (!BulletBag.empty())
		for (Bullet* b : BulletBag)
			if (b->IsActive())
				b->Update();

	if (!IsActive())
		return;

	Input();
}

void Player::Input()
{
	if (IsKeyDown(KEY_A)) {
		if (_Position.x > (0 + _Texture.width / 2))
			_Position.x -= _Speed;
	}
	if (IsKeyDown(KEY_D)) {
		if (_Position.x < (GetScreenWidth() - _Texture.width / 2))
			_Position.x += _Speed;
	}
	if (IsKeyDown(KEY_W)) {
		if (_Position.y > 0)
			_Position.y -= _Speed;
	}
	if (IsKeyDown(KEY_S)) {
		if (_Position.y < GetScreenHeight())
			_Position.y += _Speed;
	}

	if (IsKeyPressed(KEY_Z)) {
		oldTime = GetTime();

		charging = true;
	}
	if (IsKeyReleased(KEY_Z)) {
		newTime = GetTime();

		dif = (newTime - oldTime);

		std::cout << dif << std::endl;

		charging = false;
		if (dif >= shootCoolDown)
			Shoot();
	}
	
}

void Player::Shoot()
{
	if (BulletBag.empty()) {
		Bullet* b = new Bullet();
		b->SetPosition(GetPosition());
		BulletBag.push_back(b);
		std::cout << "Shoot" << std::endl;
	}
	else {
		for (Bullet* b : BulletBag) {
			if (!b->IsActive()) {
				b->Reset();
				b->SetPosition(GetPosition());
				b->SetActive(true);
				return;
			}
			noBullets = true;
		}
		if (noBullets) {
			Bullet* b = new Bullet();
			b->SetPosition(GetPosition());
			BulletBag.push_back(b);
			std::cout << "Shoot" << std::endl;
		}

	}
}

void Player::SpawnPlayer()
{
	SetPosition((float)(GetScreenWidth() / 2), (float)(GetScreenHeight() - (GetScreenHeight() / 8)));
	isDead = false;
	SetActive(true);
}

void Player::PlayerDied()
{
	//Play death animation

	ui->SetMenu(true);

	isDead = true;
	SetPosition({ (float)INT_MAX,(float)INT_MAX });
	SetActive(false);
}

bool Player::IsDead()
{
	return isDead;
}

void Player::DrawHitbox()
{
	DrawRectangleRec(GetHitBox(), RED);
}

void Player::Reset()
{
	BulletBag.clear();
	SpawnPlayer();
}
