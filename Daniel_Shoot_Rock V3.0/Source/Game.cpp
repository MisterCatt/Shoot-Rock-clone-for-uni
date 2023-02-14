#include "Game.h"

#include "ShootRock_Game.h"
Game::Game()
{
	player = Player::GetInstance();
	pointManager = PointManager::GetInstance();
	player->SpawnPlayer();

	gameUI = UI::GetInstance();
	gameUI->ResetScore();

	asteroids = new AsteroidFall();
	

}

Game::~Game()
{
	delete player;
	player = nullptr;
	delete gameUI;
	gameUI = nullptr;
	delete pointManager;
	pointManager = nullptr;
	delete asteroids;
	asteroids = nullptr;
}

void Game::Run()
{
	update();
	render();
}

void Game::update()
{
	if (gameUI->GetMenuStatus())
		return;
	player->Update();
	asteroids->Update();
	gameUI->Update();

	pointManager->Update();

	if (player->IsDead() && IsKeyDown(KEY_X))
		resetGame();
}

void Game::render()
{
	if (gameUI->GetMenuStatus()) {
		gameUI->RenderMainMenu();
		gameUI->Render();
		return;
	}

	gameUI->Render();
	player->Render();
	asteroids->Render();

	pointManager->Render();

}

void Game::resetGame() {
	player->Reset();
	gameUI->Reset();
	pointManager->Reset();

	delete asteroids;
	asteroids = new AsteroidFall();
	asteroids->AddManager(gm);
}


void Game::AddGameManager(GameManager _gm)
{
	gm = _gm;
	player->AddGameManager(gm);
	asteroids->AddManager(gm);
}
