#pragma once
#include "Component.h"
#include "Mesh.h"
#include "GameObject.h"

namespace AGameEngine {

	class MeshFilter : public Component
	{
	public:
		MeshFilter(GameObject* gameObject = nullptr, Mesh* mesh = nullptr)
		{
			gameObject->AddComponent(this);
			this->mesh = mesh;
		}
		~MeshFilter();

		Mesh* mesh;
	};

}