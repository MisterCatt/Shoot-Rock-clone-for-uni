#pragma once
#include "Point.h"
#include "Player.h"
#include "UI.h"

//It takes care of the current points in the game (and overall) making this a singleton gives me an easier access to it and I can add points wherever and whenever I want.
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

	float pickupTime;

	static PointManager* instance;

	Player* player;
	UI* ui;

	
};
