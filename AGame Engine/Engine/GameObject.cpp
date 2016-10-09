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
		auto it = attachedComponents.begin();
		while(it != attachedComponents.end())
		{
			delete *it++;
		}
	}

	GameObject::GameObject(const string& name):
		_isActive(true),
		layer(0),
		tag(0)
	{
		this->name = name;
		transform = new Transform();
	}

	bool GameObject::IsActive()
	{
		return _isActive;
	}

	void GameObject::SetActive(bool value)
	{
		_isActive = value;
	}

	bool GameObject::CompareTag(int tag)
	{
		return this->tag == tag ? true : false;
	}

}