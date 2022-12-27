#include "GameObject.h"

GameObject::GameObject()
{
	_Speed = _Angle = 0;

	_IsActive = false;

	_Position = { 0,0 };
}

GameObject::~GameObject()
{
}

Vector2 GameObject::GetPosition()
{
	return _Position;
}

bool GameObject::IsActive()
{
	return _IsActive;
}

void GameObject::SetActive(bool _activeStatus)
{
	_IsActive = _activeStatus;
}

void GameObject::SetAngle(bool _angle)
{
	_Angle = _angle;
}

float GameObject::GetAngle()
{
	return _Angle;
}

void GameObject::SetSpeed(float _speed)
{
	_Speed = _speed;
}
