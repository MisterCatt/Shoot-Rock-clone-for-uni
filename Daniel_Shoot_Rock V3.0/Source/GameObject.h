#pragma once
#include "Core.h"
#include "GameManager.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual Vector2 GetPosition();
	virtual void SetPosition(Vector2 _position);
	virtual void SetPosition(float _x, float _y);

	virtual bool IsActive();
	virtual void SetActive(bool _activeStatus);

	virtual void SetAngle(float _angle);
	virtual float GetAngle();

	virtual void SetSpeed(float _speed);
	virtual float GetSpeed();

	virtual Rectangle GetHitBox(std::string);

	virtual void AddGameManager(GameManager&);
protected:

	GameManager gm;

	float _Angle, _Speed;

	bool _IsActive;

	Vector2 _Position;

};

