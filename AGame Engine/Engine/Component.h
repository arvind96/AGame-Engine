#pragma once
#include "Object.h"

using namespace std;

namespace AGameEngine {

	class GameObject;
	class Component : public Object
	{
	public:
		Component();
		~Component();

		GameObject* gameObject = nullptr;
	};

}