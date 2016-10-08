#include "GameObject.h"

namespace AGameEngine {

	GameObject::GameObject() :
		_isActive(true),
		layer(0),
		tag(0)
	{
	}

	GameObject::~GameObject()
	{
	}

	GameObject::GameObject(const string name)
	{
		GameObject();
		this->name = name;
	}

	bool GameObject::IsActive()
	{
		return _isActive;
	}

	void GameObject::SetActive(bool value)
	{
		_isActive = value;
	}

}