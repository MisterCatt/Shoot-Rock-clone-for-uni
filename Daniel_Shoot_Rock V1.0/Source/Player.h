#pragma once

#include "GameObject.h"
#include <iostream>

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Update();
	void Render();

	void Input();

	void Charging();

private:

	float rotation, chargeTime;

	bool charging;

};
