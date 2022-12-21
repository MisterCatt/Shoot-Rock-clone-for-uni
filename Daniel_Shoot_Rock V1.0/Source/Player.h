#pragma once
#include "GameObject.h"
#include <iostream>
#include "Bullet.h"
#include "BulletBag.h"
#include <deque>

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Update();
	void Render();

	void Input();

	void Charging();

	void Shoot();

	std::deque<Bullet*> GetBullets();

private:

	float rotation, chargeTime;

	bool charging;

	std::deque<Bullet*> bulletsInMotion;

	BulletBag* bulletBag;

};
