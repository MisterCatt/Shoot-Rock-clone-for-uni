#include "PointManager.h"

PointManager* PointManager::instance = 0;

PointManager::PointManager()
{
}

PointManager::~PointManager()
{
}

void PointManager::SpawnPoints(Vector2 _position)
{
	for (int i = 0; i < 5; i++) {
		Point* p = new Point();
		p->SetPosition(_position);
		pointBag.push_back(p);
	}
}

void PointManager::Update()
{
	for (Point* p : pointBag) {
		p->Update();
	}
}

void PointManager::Render()
{
	for (Point* p : pointBag) {
		p->Render();
	}
}

PointManager* PointManager::GetInstance()
{
	if (!instance) {
		instance = new PointManager();
		std::cout << "Created new Instance";
		return instance;
	}
	else {
		std::cout << "Instance exists, returning old instance";
		return instance;
	}
}

