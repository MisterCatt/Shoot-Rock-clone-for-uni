#include "GameObject.h"

GameObject::GameObject()
{
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

void GameObject::RotateCenter(float degrees) {

}

void GameObject::Destroy() {
	//IMPLEMENT LATER
}