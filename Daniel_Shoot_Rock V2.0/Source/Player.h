#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "UI.h"
#include "ChargeUpAnimation.h"

class Player : public GameObject
{
public:
	
	~Player();

	static Player* GetInstance();

	void Render();
	void Update();
	void Input();

	void Shoot();
	void SpawnPlayer();
	void PlayerDied();

	bool IsDead();

	void DrawHitbox();

	void Reset();

	std::list<Bullet*> BulletBag;

private:
	
	Player();
	
	static Player* instance;

	UI* ui;
	Sound chargeUpSound,ShootSound;
	
	ChargeUpAnimation* anim;

	bool charging, isDead, noBullets;

	double newTime, oldTime, dif, shootCoolDown, chargeTime;
};

