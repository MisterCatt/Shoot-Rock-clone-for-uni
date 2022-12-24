#pragma once

#include "GameObject.h"
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

	void Shoot();


private:

	float rotation, chargeTime, chargeCooldown;

	bool charging;

	std::list<ChargeBall*> cb;


	double newTime, oldTime, dif;

};
