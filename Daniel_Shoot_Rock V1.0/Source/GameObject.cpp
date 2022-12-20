#include "GameObject.h"

GameObject::GameObject(std::string objName)
{
	name = objName;

	active = false;

}

GameObject::~GameObject()
{
}

bool GameObject::IsActive() {
	return active;
}

void GameObject::SetActive(bool status) {
	active = status;
}

void GameObject::SetName(std::string objName) {
	name = objName;
}

std::string GameObject::GetName()
{
	return name;
}



void GameObject::Destroy() {
	//IMPLEMENT LATER
}