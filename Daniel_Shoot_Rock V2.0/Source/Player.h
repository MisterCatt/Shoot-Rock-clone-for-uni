#pragma once
#include "GameObject.h"
#include <iostream>
#include "Bullet.h"
#include "UI.h"

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
	

	bool charging, isDead, noBullets;

	double newTime, oldTime, dif, shootCoolDown, chargeTime;
};

