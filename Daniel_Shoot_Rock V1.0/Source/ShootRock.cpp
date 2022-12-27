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
	

	ui.Render();

}

void ShootRock::Update() {
	p->Update();
	
	ui.Update();

}

void ShootRock::Play() {
	Update();
	Render();
}