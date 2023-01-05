#pragma once
#include "Core.h"

class ChargeUpAnimation
{
public:
	ChargeUpAnimation(Vector2 _position);
	~ChargeUpAnimation();

	void Render();
	void Update(Vector2 _position);
	void Charge();
	void Reset(Vector2 _position);

private:

	bool charging;

	float ballMaxRadius, ballMinRadius, minX, maxX, speed, dif;

	Vector2 middlePoint;
	
	struct ball {
		float radius,x,y;
		bool right;
		Color col;
	};


	std::list<ball*> balls;

};

