#pragma once
#include "Star.h"
class StarFall
{
public:
	StarFall();
	~StarFall();

	void Render();
	void Update();

private:

	int starAmmount;

	std::list<Star*> starList;

};