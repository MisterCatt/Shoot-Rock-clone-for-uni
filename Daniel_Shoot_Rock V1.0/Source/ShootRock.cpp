#include "ShootRock.h"

ShootRock::ShootRock()
{
	p = new Player();
	p->SetActive(true);

	/*r = new Rock();
	r->position.SetX(GetScreenWidth()/2);
	r->RestartTimer();
	r->SetActive(true);*/


}

ShootRock::~ShootRock()
{
}

void ShootRock::Render() {
	p->Render();
	r->Render();

	ui.Render();

}

void ShootRock::Update() {
	p->Update();
	r->Update();

	ui.Update();

}

void ShootRock::Play() {
	Update();
	Render();
}