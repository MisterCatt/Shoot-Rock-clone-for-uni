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


Rectangle GameObject::GetHitBox(std::string type)
{
	return Rectangle{GetPosition().x - gm.textures.at(type).width / 2,GetPosition().y - gm.textures.at(type).height / 2, (float)gm.textures.at(type).width, (float)gm.textures.at(type).height };
	//return Rectangle{ GetPosition().x - _Texture.width / 2, GetPosition().y - _Texture.height / 2, (float)_Texture.width, (float)_Texture.height};
}

void GameObject::AddGameManager(GameManager& _gm)
{
	gm = _gm;
}
