#pragma once
#include "GameObject.h"

class Rock : public GameObject
{
public:
	Rock();
	~Rock();

	void Update();
	void Render();
	void Unload();

	void Destroy();

private:

};

