#include "PointManager.h"

PointManager* PointManager::instance = 0;

PointManager::PointManager()
{
	player = Player::GetInstance();
	ui = UI::GetInstance();
}

PointManager::~PointManager()
{
	pointBag.clear();
}

void PointManager::SpawnPoints(Vector2 _position)
{
	int spawnedPoints = 0;
	if (pointBag.empty()) {
		for (int i = 0; i < 5; i++) {
			Point* p = new Point();
			p->SetPosition(_position);
			p->SetActive(true);
			pointBag.push_back(p);
		}
		spawnedPoints = 5;
	}

	for (Point* a : pointBag) {
		if (spawnedPoints == 5)
			break;
		if (!a->IsActive()) {
			a->SetPosition(_position);
			a->Reset();
			a->SetActive(true);
			spawnedPoints++;
		}
	}

	for (int i = spawnedPoints; i < 5; i++) {
		Point* p = new Point();
		p->SetPosition(_position);
		p->SetActive(true);
		pointBag.push_back(p);
	}
}

void PointManager::Update()
{
	for (Point* p : pointBag) {
		p->Update();
	}
	PlayerCollision();
}

void PointManager::Render()
{
	for (Point* p : pointBag) {
		p->Render();
	}
}

void PointManager::Reset()
{
	pointBag.clear();
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

void PointManager::PlayerCollision()
{
	for (Point* a : pointBag) {

		if (a->IsActive())
			if (!((a->GetHitBox().x + a->GetHitBox().width < player->GetHitBox().x - player->GetHitBox().width) ||
				(a->GetHitBox().x - a->GetHitBox().width > player->GetHitBox().x + player->GetHitBox().width) ||
				(a->GetHitBox().y + a->GetHitBox().height/2 < player->GetHitBox().y - player->GetHitBox().height/2) ||
				(a->GetHitBox().y - a->GetHitBox().height/2> player->GetHitBox().y + player->GetHitBox().height/2))) {
				a->PickUpPoint();
				ui->AddScore(25);
			}
	}
}