#include "AsteroidFall.h"

AsteroidFall::AsteroidFall()
{
	player = Player::GetInstance();

	totalAsteroids = 20;
	spawnTimer = 1.0f;
	timerCurrent = 0;

	//asteroidBag.front()->SpawnAsteroid();

	spawned = false;
	isActive = true;
}

AsteroidFall::~AsteroidFall()
{
	asteroidBag.clear();
}

int AsteroidFall::Collision()
{
	if (!IsActive())
		return;

	for (Asteroid* a : asteroidBag) {
		
		if(a->IsActive())
			if (!((a->GetHitBox().x + a->GetHitBox().width / 2 < player->GetHitBox().x - player->GetHitBox().width / 2) ||
				(a->GetHitBox().x - a->GetHitBox().width / 2 > player->GetHitBox().x + player->GetHitBox().width / 2) ||
				(a->GetHitBox().y + a->GetHitBox().height / 2 < player->GetHitBox().y - player->GetHitBox().height / 2) ||
				(a->GetHitBox().y - a->GetHitBox().height / 2 > player->GetHitBox().y + player->GetHitBox().height / 2))) {
				return 1;
		}
	}
	return 0;

}

void AsteroidFall::Update() 
{
	if (!IsActive())
		return;

	for (Asteroid* a : asteroidBag)
		a->Update();

	
	SpawnAsteroids();
	
	

	if (Collision() == 1) {
		std::cout << "HIT" << std::endl;
	}
}

void AsteroidFall::Render()
{
	for (Asteroid* a : asteroidBag)
		a->Render();
}

void AsteroidFall::SpawnAsteroids()
{
	if (asteroidBag.empty()) {
		asteroidBag.push_back(new Asteroid());
	}

	spawned = false;

	float temp = (float)GetTime() - GetFrameTime();

	timerCurrent += GetFrameTime();

	if (timerCurrent >= spawnTimer) {

		std::cout << temp << std::endl;

		for (Asteroid* a : asteroidBag) {
			if (!a->IsActive()) {
				a->SpawnAsteroid();
				spawned = true;
				break;
			}
		}
		if (!spawned) {
			asteroidBag.push_back(new Asteroid());
			asteroidBag.back()->SpawnAsteroid();
			spawned = true;
		}
		timerCurrent = 0;

		
	}

	
}

bool AsteroidFall::IsActive()
{
	return isActive;
}

void AsteroidFall::SetActive(bool _active)
{
	isActive = _active;
}

