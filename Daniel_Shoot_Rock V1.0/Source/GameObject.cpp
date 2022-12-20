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

void GameObject::Destroy() {
	//IMPLEMENT LATER
}