#include "ShootRock_Game.h"
ShootRock_Game::ShootRock_Game()
{
	player = Player::GetInstance();
	pointManager = PointManager::GetInstance();
	player->SpawnPlayer();

	gameUI = UI::GetInstance();
	gameUI->ResetScore();

}

ShootRock_Game::~ShootRock_Game()
{
	delete player;
	player = nullptr;
	delete gameUI;
	gameUI = nullptr;
	delete pointManager;
	pointManager = nullptr;
}

void ShootRock_Game::Run()
{
	update();
	render();
}

void ShootRock_Game::update()
{
	if (gameUI->GetMenuStatus())
		return;
	player->Update();
	asteroids.Update();
	gameUI->Update();

	pointManager->Update();

	if (player->IsDead() && IsKeyDown(KEY_X))
		resetGame();
}

void ShootRock_Game::render()
{
	if (gameUI->GetMenuStatus()) {
		gameUI->RenderMainMenu();
		gameUI->Render();
		return;
	}

	gameUI->Render();
	player->Render();
	asteroids.Render();

	pointManager->Render();

}

void ShootRock_Game::resetGame() {
	player->Reset();
	gameUI->Reset();
	pointManager->Reset();

	asteroids = AsteroidFall();
}
