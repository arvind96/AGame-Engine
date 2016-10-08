#pragma once
#include "Object.h"
#include <list>

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
			attachedComponents.push_back(componentRef);
		}

		inline void RemoveComponent(Component* componentRef)
		{
			attachedComponents.remove(componentRef);
		}

		int layer;
		int tag;
		bool IsActive();
		void SetActive(bool value);
	protected:

	private:
		bool _isActive;

		Transform* transform;

		list<Component*> attachedComponents;
	};

}