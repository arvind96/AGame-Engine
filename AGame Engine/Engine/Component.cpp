#include "Component.h"
#include "GameObject.h"

namespace AGameEngine {

	Component::Component()
	{
	}

	Component::~Component()
	{
		if (gameObject)
		gameObject->RemoveComponent(this);
	}

}