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

	std::deque<Bullet*> GetBullets();

	void BulletBag();

	Bullet* GetBulletFromBag();

private:

	float rotation, chargeTime, chargeCooldown;

	bool charging;

	std::deque<Bullet*> bulletsInMotion;
	std::list<ChargeBall*> cb;

	double newTime, oldTime, dif;


	//ANIMATION BALLS
	void BallMove();

	float ballRadius, ballSpeed, ballAngle, frameCount, jitterSpeed;

	bool goingRigth;

	struct B_Pos {
		float x, y;
	} ballPos;

};
