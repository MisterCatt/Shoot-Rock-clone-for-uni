#pragma once
#include "Core.h"
#include "GameObject.h"
#include <math.h>
#include <iostream>
class Point : public GameObject
{
public:
	Point();
	~Point();

	void Update();
	void Render();

	void SetPosition(Vector2 _position);
	void SetPosition(float _x, float _y);

	void Move();

private:

	float radius,angle, maxHeight;

	bool right, goingUp;

};
