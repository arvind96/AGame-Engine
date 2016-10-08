#pragma once
#include "GameObject.h"

using namespace std;

namespace AGameEngine {

	class Component : public GameObject
	{
	public:
		Component();
		~Component();
	};

}