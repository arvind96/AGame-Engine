#pragma once
#include "Renderer.h"
#include "MeshFilter.h"

namespace AGameEngine {

	class MeshRenderer : public Renderer
	{
	public:
		MeshRenderer();
		MeshRenderer(MeshFilter* meshFilter, Material* material)
		{
			this->meshFilter = meshFilter;
			this->material = material; 
		}
		~MeshRenderer();

		void UpdateRenderer(Camera* camera);

	private:
		MeshFilter* meshFilter;
	};

}