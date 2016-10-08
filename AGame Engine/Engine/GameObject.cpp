#include "GameObject.h"
#include "Component.h"
#include "Transform.h"

namespace AGameEngine {

	GameObject::GameObject() :
		_isActive(true),
		layer(0),
		tag(0)
	{
		transform = new Transform();
	}

	GameObject::~GameObject()
	{
		delete transform;
		for each(Component* c in attachedComponents)
		{
			delete c;
		}
	}

	GameObject::GameObject(const string& name)
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