#pragma once
#include "StarFall.h"
#include <iostream>
#include "PopupScore.h"

class UI
{
public:
	static UI* GetInstance();
	~UI();

	void Update();
	void Render();

	void RenderMainMenu();

	void AddScore(int _score, Vector2 _position);
	void ResetScore();
	int GetScore();
	int GetWinScore();

	bool GetMenuStatus();
	void SetMenu(bool _menuStatus);

	bool WinStatus();

	void Reset();

private:

	UI();
	static UI* instance;

	void drawScore();
	void drawStarFall();
	void drawBackground();

	StarFall backgroundStars;

	int score, winScore;

	bool isMenu, win;

	std::list<PopupScore*> popupScore;
	

};

