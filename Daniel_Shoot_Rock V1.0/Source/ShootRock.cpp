#include "ShootRock.h"

ShootRock::ShootRock()
{
	p = new Player();

}

ShootRock::~ShootRock()
{
}

void ShootRock::Render() {
	p->Render();
}

void ShootRock::Update() {
	p->Update();
}

void ShootRock::Play() {
	Update();
	Render();
}