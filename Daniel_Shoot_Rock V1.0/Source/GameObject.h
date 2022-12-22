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

	virtual void SetName(std::string ObjName);
	virtual std::string GetName();

	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual void Destroy();

	Position position;

protected:

	Texture texture;

	bool active;

	std::string name;

	float speed;

};

