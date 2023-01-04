#pragma once
#include "Point.h"

class PointManager
{
public:
	static PointManager* GetInstance();
	~PointManager();

	void SpawnPoints(Vector2 _position);

	void Update();
	void Render();

	std::list<Point*> pointBag;

private:
	PointManager();
	static PointManager* instance;


};
