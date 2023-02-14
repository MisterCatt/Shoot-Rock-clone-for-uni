#include "Player.h"

Player* Player::instance = nullptr; //Need to make sure that Player have not been initialized before the first call. Remove this line and the game will crash.

Player* Player::GetInstance()
{
	if (!instance) {
		instance = new Player();
		return instance;
	}
	else {
		return instance;
	}
}

Player::Player() {
	SetSpeed(10);

	ui = UI::GetInstance();

	shootCoolDown = 0.8f;

	chargeTime = newTime = oldTime = dif = 0;

	isDead = charging = false;
	noBullets = true;

	anim = new ChargeUpAnimation(GetPosition());
}

Player::~Player()
{
	delete anim;
	anim = nullptr;
}

void Player::Render()
{
	if (!BulletBag.empty())
		for (Bullet* b : BulletBag)
			if(b->IsActive())
				b->Render();

	if (!IsActive())
		return;

	gm.DrawTexture("SpaceShip",_Angle, (int)_Position.x, (int)_Position.y),


	anim->Render();
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
	anim->Update(GetPosition());
}

void Player::Input()
{
	if (IsKeyDown(KEY_LEFT)) {
		if (_Position.x > (0 + gm.textures.at("SpaceShip").width / 2))
			_Position.x -= _Speed;
	}
	if (IsKeyDown(KEY_RIGHT)) {
		if (_Position.x < (GetScreenWidth() - gm.textures.at("SpaceShip").width / 2))
			_Position.x += _Speed;
	}

	if (IsKeyPressed(KEY_Z)) {
		oldTime = GetTime();
		anim->Charge();

		gm.PlaySound("Charge");

		charging = true;
	}
	if (IsKeyReleased(KEY_Z) && IsActive()) {
		newTime = GetTime();
		
		dif = (newTime - oldTime);

		anim->Reset(GetPosition());
		charging = false;
		if (dif >= shootCoolDown) {
			if(!isDead)
			Shoot();
			gm.PlaySound("Shoot");
		}
	}
	
}

void Player::Shoot()
{
	if (BulletBag.empty()) {
		Bullet* b = new Bullet();
		if (!isDead)
			b->SetPosition(GetPosition());
		else
			b->SetPosition({ 0,0 });
		BulletBag.push_back(b);
	}
	else {
		for (Bullet* b : BulletBag) {
			if (!b->IsActive()) {
				b->Reset();
				if (!isDead)
					b->SetPosition(GetPosition());
				else
					b->SetPosition({0,0});
				b->SetActive(true);
				return;
			}
			noBullets = true;
		}
		if (noBullets) {
			Bullet* b = new Bullet();
			if (!isDead)
				b->SetPosition(GetPosition());
			else
				b->SetPosition({ 0,0 });
			BulletBag.push_back(b);
		}

	}
}

void Player::SpawnPlayer()
{
	SetPosition((float)(GetScreenWidth() / 2), (float)(GetScreenHeight() - (GetScreenHeight() / 8)));
	charging = false;
	anim->Reset(GetPosition());
	isDead = false;
	SetActive(true);
}

void Player::PlayerDied()
{
	ui->SetMenu(true);

	isDead = true;
	SetPosition({ (float)INT_MAX,(float)INT_MAX });
	SetActive(false);
}

bool Player::IsDead()
{
	return isDead;
}

void Player::Reset()
{
	for (Bullet* b : BulletBag)
		if (b->IsActive())
			b->SetActive(false);

	BulletBag.clear();
	SpawnPlayer();
}

void Player::AddGameManager(GameManager& _gm)
{
	gm = _gm;
}
