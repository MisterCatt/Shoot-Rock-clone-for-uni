#pragma once
#include "Core.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Update() = 0;
	virtual void Render() = 0;

	Vector2 GetPosition();

	bool IsActive();
	void SetActive(bool _activeStatus);

	void SetAngle(bool _angle);
	float GetAngle();

	void SetSpeed(float _speed);

protected:

	float _Angle, _Speed;

	bool _IsActive;

	Vector2 _Position;

	Texture2D _Texture;

};

