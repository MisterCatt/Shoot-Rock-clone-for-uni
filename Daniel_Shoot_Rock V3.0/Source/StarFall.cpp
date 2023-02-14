#include "StarFall.h"

StarFall::StarFall()
{
	starAmmount = 20;
	for (int i = 0; i < starAmmount; i++) {
		starList.push_back(new Star());
	}
}

StarFall::~StarFall()
{
	for (Star* s : starList) {
		delete s;
		s = nullptr;
	}
	starList.clear();
}

void StarFall::Render()
{
	for (Star* s : starList) {
		s->Render();
	}
}

void StarFall::Update()
{
	for (Star* s : starList) {
		s->Update();
	}
}
