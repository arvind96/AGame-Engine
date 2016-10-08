#include "Component.h"
#include "GameObject.h"

namespace AGameEngine {

	Component::Component()
	{
		if (gameObject)
		{
			gameObject->AddComponent(this);
		}
		else
		{
			cerr << "Please create a component by passing its parent gameobject." << endl;
		}
	}

	Component::Component(GameObject* gameObject)
	{
		this->gameObject = gameObject;
		Component();
	}

	Component::~Component()
	{
		if (gameObject)
		gameObject->RemoveComponent(this);
	}

}