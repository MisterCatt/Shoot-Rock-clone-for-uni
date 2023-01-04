#include "ShootRock_Game.h"
ShootRock_Game::ShootRock_Game()
{
	player = Player::GetInstance();
	pointManager = PointManager::GetInstance();
	player->SpawnPlayer();

	

}

ShootRock_Game::~ShootRock_Game()
{
}

void ShootRock_Game::Run()
{
	update();
	render();
}

void ShootRock_Game::update()
{
	player->Update();
	asteroids.Update();

	pointManager->Update();
}

void ShootRock_Game::render()
{
	gameUI.Render();
	player->Render();
	asteroids.Render();

	pointManager->Render();

}
