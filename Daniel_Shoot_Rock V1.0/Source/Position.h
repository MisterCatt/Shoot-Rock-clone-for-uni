#pragma once
#include <raylib.h>

class Position
{
public:
	Position();
	~Position();

	Position(float x, float y);
	
	void SetX(float x);
	void SetY(float y);

	float GetX();
	float GetY();

	Vector2 GetVector2();

	float x;
	float y;

};

