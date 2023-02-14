#include "AsteroidFall.h"

AsteroidFall::AsteroidFall()
{
	player = Player::GetInstance();
	pointManager = PointManager::GetInstance();

	totalAsteroids = 20;
	spawnTimer = 1.0f;
	timerCurrent = 0;

	spawned = false;
	isActive = true;

	time = 0;
	spawnStopTime = seconds = 0;

	stopSpawning = false;
}

AsteroidFall::~AsteroidFall()
{
	for (Asteroid* a : asteroidBag) {
		delete a;
		a = nullptr;
	}
	asteroidBag.clear();
}

int AsteroidFall::PlayerCollision()
{
	for (Asteroid* a : asteroidBag) {
		
		if(a->IsActive())
			if (!((a->GetHitBox("Asteroid").x + a->GetHitBox("Asteroid").width / 2 < player->GetHitBox("Player").x - player->GetHitBox("Player").width / 2) ||
				(a->GetHitBox("Asteroid").x - a->GetHitBox("Asteroid").width / 2 > player->GetHitBox("Player").x + player->GetHitBox("Player").width / 2) ||
				(a->GetHitBox("Asteroid").y + a->GetHitBox("Asteroid").height / 2 < player->GetHitBox("Player").y - player->GetHitBox("Player").height / 2) ||
				(a->GetHitBox("Asteroid").y - a->GetHitBox("Asteroid").height / 2 > player->GetHitBox("Player").y + player->GetHitBox("Player").height / 2))) {
				if (!IsSoundPlaying(gm.sounds.at("Destruction")))
					gm.PlaySound("Destruction");
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
				pointManager->SpawnPoints(a->GetPosition());
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
		player->PlayerDied();
		
	}

	if (BulletCollision() == 1) {
		gm.PlaySound("Destruction");
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
		asteroidBag.back()->AddManager(gm);
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
			asteroidBag.back()->AddManager(gm);
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
}

void AsteroidFall::StopSpawning()
{
	if (seconds % 14 == 0 && !stopSpawning) {
		stopSpawning = true;
		if(spawnTimer >= 0.05)
		spawnTimer -= (spawnTimer / 10.0f);
	}
}

void AsteroidFall::AddManager(GameManager& _gm)
{
	gm = _gm;
}


