#include "UI.h"

UI::UI()
{
	starAmmount = 20;
	points = 0;

	for (int i = 0; i < starAmmount; i++) {
		stars.push_back(new Stars());
	}
}

UI::~UI()
{
	for (Stars* s : stars) {
		delete s;
		s = nullptr;
	}

	stars.clear();

}

void UI::Update() {
	for (Stars* s : stars) {
		s->Update();
	}
}

void UI::Render() {

	for (Stars* s : stars) {
		s->Render();
	}

	if (points == 0)
		DrawText("00", (GetScreenWidth() / 2) - (MeasureText("00", 25)/2), GetScreenHeight() / 50, 40, WHITE);
	else
		DrawText(std::to_string(points).c_str(), (GetScreenWidth() / 2) - (MeasureText(std::to_string(points).c_str(), 25) / 2), GetScreenHeight() / 50, 40, WHITE);
}

void UI::AddPoints(int pointValue) {
	points += pointValue;
}