#pragma once
#include <raylib.h>
#include <list>
#include"Stars.h"
#include <string>


class UI
{
public:
	UI();
	~UI();

	void Render();
	void Update();

	void AddPoints(int pointValue);



private:

	std::list<Stars*> stars;
	int starAmmount;

	int points;

};

