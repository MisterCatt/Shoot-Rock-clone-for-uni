#include "ChargeUpAnimation.h"

ChargeUpAnimation::ChargeUpAnimation(Vector2 _position)
{

	middlePoint = _position;

	speed = 20;

	dif = 50.0f;

	minX = middlePoint.x - dif;
	maxX = middlePoint.x + dif;

	charging = false;

	ballMinRadius = 20;
	ballMaxRadius = 40;

	balls.push_back(new ball{ ballMaxRadius, (float)GetRandomValue(minX, maxX) , _position.y - ballMaxRadius, (bool)GetRandomValue(0,1), WHITE});
	balls.push_back(new ball{ ballMaxRadius, (float)GetRandomValue(minX, maxX) , _position.y - ballMaxRadius, false, BLUE});
	balls.push_back(new ball{ ballMaxRadius, (float)GetRandomValue(minX, maxX) , _position.y - ballMaxRadius, true, DARKBLUE});
}

ChargeUpAnimation::~ChargeUpAnimation()
{
	balls.clear();
}

void ChargeUpAnimation::Render()
{
	if (!charging)
		return;
	for (ball* b : balls) {
		DrawCircle(b->x, b->y, b->radius, b->col);
	}
}

void ChargeUpAnimation::Update(Vector2 _position)
{
	

	for (ball* b : balls) {
		if (b->x < minX && !b->right) {
			b->right = true;
		}
		if (b->x > maxX && b->right) {
			b->right = false;
		}

		if (b->right) 
			b->x += speed;
		else
			b->x -= speed;

		b->y = _position.y - 40;
	}

	middlePoint = _position;
	minX = middlePoint.x - dif;
	maxX = middlePoint.x + dif;

	if (charging)
	{
		if (dif > 5) {
			dif-=0.5f;
		}

		for (ball* b : balls) {
			if (b->radius > ballMinRadius) {
				b->radius-=0.5f;
			}
		}
	}
}

void ChargeUpAnimation::Charge()
{
	charging = true;
}

void ChargeUpAnimation::Reset(Vector2 _position)
{
	charging = false;

	balls.clear();

	middlePoint = _position;

	dif = 50;

	minX = middlePoint.x - dif;
	maxX = middlePoint.x + dif;

	balls.push_back(new ball{ ballMaxRadius, (float)GetRandomValue(minX, maxX) , _position.y - ballMaxRadius, (bool)GetRandomValue(0,1), WHITE });
	balls.push_back(new ball{ ballMaxRadius, minX , _position.y - ballMaxRadius, false, BLUE });
	balls.push_back(new ball{ ballMaxRadius, maxX , _position.y - ballMaxRadius, true, DARKBLUE });

	
}
