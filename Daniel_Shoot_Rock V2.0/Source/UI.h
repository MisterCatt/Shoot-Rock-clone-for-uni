#pragma once
#include "StarFall.h"
#include "PopupScore.h"

//There is only going to be one UI throughout this project so I only have to worry about that. Thats why I made it a singleton, just so I can access the UI wherever and whenever throughout the game.
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

