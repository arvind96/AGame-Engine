#pragma once
#include "Object.h"

using namespace std;

namespace AGameEngine {

	class GameObject : public Object
	{
	public:
		GameObject();
		~GameObject();
		GameObject(const string name);

		int layer;
		int tag;
		bool IsActive();
		void SetActive(bool value);
	protected:

	private:
		bool _isActive;
	};

}