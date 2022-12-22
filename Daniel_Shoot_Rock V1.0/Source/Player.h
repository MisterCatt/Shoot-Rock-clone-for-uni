#pragma once

#include "GameObject.h"
#include "Bullet.h"
#include "BulletBag.h"
#include <deque>
#include <list>
#include "ChargeBall.h"

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


private:

	float rotation, chargeTime, chargeCooldown;

	bool charging;

	std::list<ChargeBall*> cb;


	double newTime, oldTime, dif;

};
