#pragma once
#include "Position.h"
#include <iostream>
#include <raylib.h>

class GameObject
{

public:
	GameObject();
	~GameObject();

	virtual bool IsActive();
	virtual void SetActive(bool status);

	virtual void RotateCenter(float degrees);


	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Input() = 0;

	virtual void Destroy();

protected:

	Texture texture;

	Position pos;

	bool active;

	std::string name;

};

