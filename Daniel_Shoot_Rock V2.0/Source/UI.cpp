#include "UI.h"

UI::UI()
{
	score = 0;

}

UI::~UI()
{
}

void UI::Render()
{
	drawBackground();
	drawStarFall();
	drawScore();
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

void UI::AddScore(int _score)
{
	score += _score;
}

int UI::GetScore()
{
	return score;
}

void UI::ResetScore()
{
	score = 0;
}
