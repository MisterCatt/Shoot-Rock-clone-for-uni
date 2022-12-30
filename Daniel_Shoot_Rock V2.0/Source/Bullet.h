#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render();

	void SetSize(float _size);

	void DestroyBullet();
	void Unload();

private:

	float radius;
};
