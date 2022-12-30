#pragma once
#include "GameObject.h"
#include <iostream>
#include "Bullet.h"

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

private:
	

	Player();
	
	static Player* instance;
	std::list<Bullet*> bulletBag;

	bool charging, isDead;

	double newTime, oldTime, dif, shootCoolDown, chargeTime;
};

