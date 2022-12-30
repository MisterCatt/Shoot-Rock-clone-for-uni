#pragma once
#include "GameObject.h"
#include <iostream>

class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render();

	void SetSize(float _size);
	void Reset();

	void DestroyBullet();
	void Unload();

	Rectangle GetHitBox();

	void DrawHitbox();

private:

	float radius, secondsActive;
};
