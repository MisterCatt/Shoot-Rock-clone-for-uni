#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "UI.h"
#include "ChargeUpAnimation.h"

//Player class is a singleton so I can find the players position and change important values where i need to instead of trying to find workarounds. Saves me time and makes it easier to code.
//I am aware of the issues with that the code could become very cluttered if you need to add or remove classes but as this is a university assignment. I doubt that im going to change much after it is done.
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

