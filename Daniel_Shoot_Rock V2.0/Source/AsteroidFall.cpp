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

	time = 0;
	spawnStopTime = seconds = minutes = hours = 0;

	stopSpawning = false;
}

AsteroidFall::~AsteroidFall()
{
	asteroidBag.clear();
}

int AsteroidFall::PlayerCollision()
{
	for (Asteroid* a : asteroidBag) {
		
		if(a->IsActive())
			if (!((a->GetHitBox().x + a->GetHitBox().width / 2 < player->GetHitBox().x - player->GetHitBox().width / 2) ||
				(a->GetHitBox().x - a->GetHitBox().width / 2 > player->GetHitBox().x + player->GetHitBox().width / 2) ||
				(a->GetHitBox().y + a->GetHitBox().height / 2 < player->GetHitBox().y - player->GetHitBox().height / 2) ||
				(a->GetHitBox().y - a->GetHitBox().height / 2 > player->GetHitBox().y + player->GetHitBox().height / 2))) {
				a->DestroyAsteroid();
				return 1;
		}
	}
	return 0;

}

int AsteroidFall::BulletCollision()
{
	for (Asteroid* a : asteroidBag) {

		if (a->IsActive())
			for(Bullet* b : player->BulletBag)
			if (!((a->GetHitBox().x + a->GetHitBox().width / 2 < b->GetHitBox().x - b->GetHitBox().width / 2) ||
				(a->GetHitBox().x - a->GetHitBox().width / 2 > b->GetHitBox().x + b->GetHitBox().width / 2) ||
				(a->GetHitBox().y + a->GetHitBox().height / 2 < b->GetHitBox().y - b->GetHitBox().height / 2) ||
				(a->GetHitBox().y - a->GetHitBox().height / 2 > b->GetHitBox().y + b->GetHitBox().height / 2))) {
				a->DestroyAsteroid();
				return 1;
			}
	}
	return 0;
}



void AsteroidFall::Update() 
{
	if (!IsActive())
		return;

	Timer();
	StopSpawning();

	for (Asteroid* a : asteroidBag)
		a->Update();

	
	SpawnAsteroids();
	
	

	if (PlayerCollision() == 1) {
		std::cout << "ded!" << std::endl;
		player->PlayerDied();
	}

	//SPAWN POINTS
	if (BulletCollision() == 1) {
		std::cout << "BULLETS AND SO ON AND SO FORTH" << std::endl;
	}
}

void AsteroidFall::Render()
{
	if (!IsActive())
		return;
	for (Asteroid* a : asteroidBag)
		a->Render();
}

void AsteroidFall::SpawnAsteroids()
{
	if (stopSpawning)
		return;

	if (asteroidBag.empty()) {
		asteroidBag.push_back(new Asteroid());
	}

	spawned = false;

	timerCurrent += GetFrameTime();

	if (timerCurrent >= spawnTimer) {
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

void AsteroidFall::Timer()
{
	time += GetFrameTime();

	if (time >= 1) {
		seconds++;
		time = 0;

		if (stopSpawning) {
			spawnStopTime++;
			if (spawnStopTime >= 4) {
				stopSpawning = false;
				spawnStopTime = 0;
			}
		}
	}
	if (seconds >= 60) {
		minutes++;
		seconds = 0;
	}
	if (minutes >= 60) {
		hours++;
		minutes = 0;
	}
}

void AsteroidFall::StopSpawning()
{
	if (seconds % 14 == 0 && !stopSpawning) {
		stopSpawning = true;
		if(spawnTimer >= 0.05)
		spawnTimer -= (spawnTimer / 10.0f);
	}
}


