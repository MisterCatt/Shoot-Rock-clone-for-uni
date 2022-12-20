#pragma once
#include <raylib.h>

class Position
{
public:
	Position();
	~Position();
	
	void SetX(float x);
	void SetY(float y);

	Vector2 GetVector2();

private:

	Vector2 position;
};

