#include "PopupScore.h"

PopupScore::PopupScore(Vector2 _position, int _score)
{
	upTime = 0;
	position = _position;
	score = _score;

	isActive = true;
}

PopupScore::~PopupScore()
{
}

void PopupScore::DisplayScore()
{
	if(isActive)
		DrawText(std::to_string(score).c_str(), position.x, position.y, 25, YELLOW);
}

void PopupScore::UpdatePopupText(Vector2 _position, int _score)
{
	upTime = 0;
	position = _position;
	score = _score;

	isActive = true;
}

bool PopupScore::IsActive()
{
	return isActive;
}

void PopupScore::Update() {
	upTime += GetFrameTime();

	if (upTime > 1) {
		isActive = false;
	}
}
