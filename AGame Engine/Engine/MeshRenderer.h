#pragma once
#include "Renderer.h"
#include "MeshFilter.h"
#include "GameObject.h"

namespace AGameEngine {

	class MeshRenderer : public Renderer
	{
	public:
		MeshRenderer(GameObject* gameObject = nullptr, MeshFilter* meshFilter = nullptr, Material* material = nullptr)
		{
			gameObject->AddComponent(this);
			this->meshFilter = meshFilter;
			SetMaterial(material);
		}
		~MeshRenderer();

		void UpdateRenderer(Camera* camera);

		void SetMaterial(Material* material)
		{
			this->material = material;
		}

	private:
		MeshFilter* meshFilter;
	};

}