#pragma once
#include "Core.h"

class PopupScore
{
public:
	PopupScore(Vector2 _position, int _score);
	~PopupScore();

	void Update();
	void DisplayScore();

	void UpdatePopupText(Vector2 _position, int _score);

	bool IsActive();
private:


	Vector2 position;
	int score;
	float upTime;

	bool isActive;
};

