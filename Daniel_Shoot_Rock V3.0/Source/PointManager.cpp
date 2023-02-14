#include "PointManager.h"

PointManager* PointManager::instance = nullptr; //Need to make sure that PointManager have not been initialized before the first call. Remove this line and the game will crash.

PointManager::PointManager()
{
	player = Player::GetInstance();
	ui = UI::GetInstance();

	pickupPoint = 50;
	scoreMultiplier = 0;

	pickupTime = 100;
	
}

PointManager::~PointManager()
{
	for (Point* p : pointBag) {
		delete p;
		p = nullptr;
	}
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

int PointManager::GetPickupScore()
{
	return pickupPoint + scoreMultiplier;
}

void PointManager::Update()
{
	for (Point* p : pointBag) {
		p->Update();
	}
	PlayerCollision();

	pickupTime += GetFrameTime();

	if (pickupTime > 1) {
		scoreMultiplier = 0;
	}
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
		return instance;
	}
	else {
		return instance;
	}
}

void PointManager::PlayerCollision()
{
	for (Point* a : pointBag) {

		if (a->IsActive())
			if(player->IsActive())
			if (!((a->GetHitBox().x + a->GetHitBox().width < player->GetHitBox("Player").x - player->GetHitBox("Player").width) ||
				(a->GetHitBox().x - a->GetHitBox().width > player->GetHitBox("Player").x + player->GetHitBox("Player").width) ||
				(a->GetHitBox().y + a->GetHitBox().height/2 < player->GetHitBox("Player").y - player->GetHitBox("Player").height/2) ||
				(a->GetHitBox().y - a->GetHitBox().height/2> player->GetHitBox("Player").y + player->GetHitBox("Player").height/2))) {
				a->PickUpPoint();
				ui->AddScore(pickupPoint + scoreMultiplier, a->GetPosition());
				scoreMultiplier += 10;
				pickupTime = 0;				
			}
	}
}