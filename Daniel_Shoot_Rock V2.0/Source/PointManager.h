#pragma once
#include "Point.h"
#include "Player.h"
#include "UI.h"

class PointManager
{
public:
	static PointManager* GetInstance();
	~PointManager();

	void SpawnPoints(Vector2 _position);

	int GetPickupScore();

	void Update();
	void Render();

	void Reset();

	std::list<Point*> pointBag;

private:
	PointManager();

	void PlayerCollision();

	int pickupPoint, scoreMultiplier;

	static PointManager* instance;

	Player* player;
	UI* ui;
};
