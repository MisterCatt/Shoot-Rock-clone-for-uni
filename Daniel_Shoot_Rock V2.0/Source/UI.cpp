#include "UI.h"

UI* UI::instance = 0;

UI* UI::GetInstance()
{
	if (!instance) {
		instance = new UI();
		std::cout << "Created new Instance" << std::endl;
		return instance;
	}
	else {
		std::cout << "Instance exists, returning old UI instance" << std::endl;
		return instance;
	}
}

UI::UI()
{
	score = 0;
	winScore = 10000;
	win = false;
	isMenu = true;
}

UI::~UI()
{
	popupScore.clear();
}

void UI::Update()
{
	for (PopupScore* p : popupScore) {
		if(p->IsActive())
			p->Update();
	}
}

void UI::Render()
{
	drawBackground();
	drawStarFall();
	drawScore();

	for (PopupScore* p : popupScore) {
		p->DisplayScore();
	}
}

void UI::RenderMainMenu()
{
	DrawText("Daniels rockshooter!", (GetScreenWidth() / 2) - (MeasureText("Daniels rockshooter!", (GetScreenWidth() / 30 + GetScreenHeight() / 30)) / 2), GetScreenHeight() / 2, (GetScreenWidth() / 30 + GetScreenHeight() / 30), WHITE);
	DrawText("Press X to start", (GetScreenWidth() / 2) - (MeasureText("Press X to start", (GetScreenWidth() / 30 + GetScreenHeight() / 30)) / 2), GetScreenHeight() / 2+40, (GetScreenWidth() / 30 + GetScreenHeight() / 30), WHITE);

	if (IsKeyDown(KEY_X) && isMenu) {
		isMenu = false;
		ResetScore();
	}
}

void UI::drawScore()
{
	DrawText(std::to_string(score).c_str(), (GetScreenWidth() / 2) - (MeasureText(std::to_string(score).c_str(), (GetScreenWidth() / 30 + GetScreenHeight() / 30)) / 2), GetScreenHeight() / 50, (GetScreenWidth() / 30 + GetScreenHeight() / 30), WHITE);
}

void UI::drawStarFall()
{
	backgroundStars.Update();
	backgroundStars.Render();
}

void UI::drawBackground()
{
	ClearBackground(BLACK);
}

void UI::AddScore(int _score, Vector2 _position)
{
	score += _score;

	for (PopupScore* p : popupScore) {
		if (!p->IsActive()) {
			p->UpdatePopupText(_position, _score);
			return;
		}
	}
	
	popupScore.push_back(new PopupScore(_position, _score));
}

int UI::GetScore()
{
	return score;
}

int UI::GetWinScore()
{
	return winScore;
}

bool UI::GetMenuStatus()
{
	return isMenu;
}

void UI::SetMenu(bool _menuStatus)
{
	isMenu = _menuStatus;
}

bool UI::WinStatus()
{
	return win;
}

void UI::Reset()
{
	ResetScore();
	isMenu = true;
}

void UI::ResetScore()
{
	score = 0;
}
