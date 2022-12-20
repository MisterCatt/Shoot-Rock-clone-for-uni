#pragma once
#include "Position.h"
#include <iostream>
#include <raylib.h>

class GameObject
{

public:
	GameObject(std::string objName);
	~GameObject();

	virtual bool IsActive();
	virtual void SetActive(bool status);

	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual void Destroy();

protected:

	Texture texture;

	Position position;

	bool active;

	std::string name;

};

