#include "ShootRock_Game.h"
ShootRock_Game::ShootRock_Game()
{
	
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

}

void ShootRock_Game::render()
{
	gameUI.Render();
}
