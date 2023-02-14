#pragma once
#include "GameObject.h"
#include "UI.h"

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

	void PickUpPoint( Sound& s);

	void Reset();

	Rectangle GetHitBox();

private:

	float radius,angle, maxHeight;

	bool goingUp;
	
};
