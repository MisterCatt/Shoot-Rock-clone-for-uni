#pragma once
#include "Core.h"

class ChargeBall
{
public:
	ChargeBall(Vector2 _pos);
	~ChargeBall();

	void GoingRight(bool _right);

	void Update();
	void Render();

	void SetBallColor(Color _color);

	void SetPosition(Vector2 _position);
	void SetPosition(int _x, int _y);

	void SetYPos(int _y);
	void SetXPos(int _x);

	void SetSpeed(float _speed);



private:
	Vector2 position;

	float radius, maxRadius, minRadius, speed, spacing, minX, maxX;

	bool goingRight;

	Color ballColor;
};

