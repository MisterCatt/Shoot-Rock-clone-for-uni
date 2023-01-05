#include "GameObject.h"

GameObject::GameObject()
{
	_Speed = _Angle = 0;

	_IsActive = false;

	_Position = { 0,0 };

	_Name = "name";
}

GameObject::~GameObject()
{
	UnloadTexture(_Texture);
}

Vector2 GameObject::GetPosition()
{
	return _Position;
}

void GameObject::SetPosition(Vector2 _position)
{
	_Position = _position;
}

void GameObject::SetPosition(float _x, float _y)
{
	_Position = { _x, _y };
}

bool GameObject::IsActive()
{
	return _IsActive;
}

void GameObject::SetActive(bool _activeStatus)
{
	_IsActive = _activeStatus;
}

void GameObject::SetAngle(float _angle)
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

float GameObject::GetSpeed()
{
	return _Speed;
}

std::string GameObject::ToString()
{
	return _Name;
}

const char* GameObject::ToChar()
{
	return _Name.c_str();
}

void GameObject::SetTexture(std::string _filePath)
{
	_Texture = LoadTexture(_filePath.c_str());
}

void GameObject::SetTexture(const char* _filePath)
{
	_Texture = LoadTexture(_filePath);
}

Rectangle GameObject::GetHitBox()
{
	return Rectangle{ GetPosition().x - _Texture.width / 2, GetPosition().y - _Texture.height / 2, (float)_Texture.width, (float)_Texture.height};
}