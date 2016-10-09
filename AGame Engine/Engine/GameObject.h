#pragma once
#include "Object.h"
#include <list>
#include "Component.h"

using namespace std;

namespace AGameEngine {

	class Component;
	class Transform;
	class GameObject : public Object
	{
	public:
		GameObject();
		~GameObject();
		GameObject(const string& name);

		inline void AddComponent(Component* componentRef)
		{
			componentRef->gameObject = this;
			attachedComponents.push_back(componentRef);
		}

		inline void RemoveComponent(Component* componentRef)
		{
			attachedComponents.remove(componentRef);
		}

		bool IsActive();
		void SetActive(bool value);
		bool CompareTag(int tag);

		int layer;
		int tag;
		Transform* transform;
	protected:

	private:
		bool _isActive;

		list<Component*> attachedComponents;
	};

}