#pragma once
#include "StarFall.h"

class UI
{
public:
	UI();
	~UI();

	void Render();

	void AddScore(int _score);
	void ResetScore();
	int GetScore();


private:

	void drawScore();
	void drawStarFall();
	void drawBackground();

	StarFall backgroundStars;

	int score;
	

};

