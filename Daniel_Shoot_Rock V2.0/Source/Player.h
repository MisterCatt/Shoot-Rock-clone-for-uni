#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	~Player();

	static Player *getInstance() {
		if (!instance)
			instance = new Player;
		return instance;
	}

	void Render();
	void Update();

private:
	static Player* instance;

	int i;

	Player();
	

};

