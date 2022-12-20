#include "ShootRock.h"

ShootRock::ShootRock()
{
	p = new Player();
	p->SetActive(true);
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