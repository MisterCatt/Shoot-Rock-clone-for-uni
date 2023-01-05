#pragma once
#include "StarFall.h"
#include <iostream>

class UI
{
public:
	static UI* GetInstance();
	~UI();

	void Render();

	void RenderMainMenu();

	void AddScore(int _score);
	void ResetScore();
	int GetScore();

	bool GetMenuStatus();
	void SetMenu(bool _menuStatus);

	void Reset();

private:

	UI();
	static UI* instance;

	void drawScore();
	void drawStarFall();
	void drawBackground();

	StarFall backgroundStars;

	int score;

	bool isMenu;
	

};

