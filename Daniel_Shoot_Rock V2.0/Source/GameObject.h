#pragma once
#include "Core.h"

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

	virtual void SetAngle(bool _angle);
	virtual float GetAngle();

	virtual void SetSpeed(float _speed);
	virtual float GetSpeed();

	virtual std::string ToString();
	virtual const char* ToChar();

	virtual void SetTexture(std::string _filePath);
	virtual void SetTexture(const char* _filePath);

	virtual Rectangle GetHitBox();
protected:

	float _Angle, _Speed;

	bool _IsActive;

	Vector2 _Position;

	Texture2D _Texture;

	std::string _Name;

};

