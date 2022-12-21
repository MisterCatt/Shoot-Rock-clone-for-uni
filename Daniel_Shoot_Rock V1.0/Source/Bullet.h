#pragma once
#include "GameObject.h"
#include <raylib.h>

class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render();
	void Unload();

	void Destroy();

	void RestartTimer();

private:

	//void Move();

	int bulletTimer;

	float speed;
};
