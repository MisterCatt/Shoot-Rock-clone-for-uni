#include "Player.h"

Player* Player::instance = 0;

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
	SetTexture("Assets/SpaceShip.png");
	SetSpeed(10);

	ui = UI::GetInstance();

	shootCoolDown = 0.8f;

	chargeTime = newTime = oldTime = dif = 0;

	isDead = charging = false;
	noBullets = true;

	anim = new ChargeUpAnimation(GetPosition());
	chargeUpSound = LoadSound("Assets/ChargeSound.wav");
	ShootSound = LoadSound("Assets/ShootSound.wav");
}

Player::~Player()
{
	delete anim;
	anim = nullptr;

	UnloadSound(chargeUpSound);
	UnloadSound(ShootSound);
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
		anim->Charge();

		PlaySoundMulti(chargeUpSound);

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
			PlaySoundMulti(ShootSound);
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
	for (Bullet* b : BulletBag)
		if (b->IsActive())
			b->SetActive(false);

	BulletBag.clear();
	SpawnPlayer();
}
