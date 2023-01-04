#pragma once
#include "Core.h"
#include "Player.h"

class ChargeUpAnimation
{
public:
	ChargeUpAnimation();
	~ChargeUpAnimation();

	void Render();
	void Update();
	void Charge();
	void Reset();

private:

	bool charging;

	float ballMaxRadius, ballMinRadius;
	
	struct ball {
		float radius,x,y;
	};


	ball ball1,ball2,ball3;

	Player* player;

};

