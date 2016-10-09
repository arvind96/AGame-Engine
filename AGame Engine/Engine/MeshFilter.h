#pragma once
#include "Component.h"
#include "Mesh.h"

namespace AGameEngine {

	class MeshFilter : public Component
	{
	public:
		MeshFilter();
		MeshFilter(Mesh* mesh) { this->mesh = mesh; }
		~MeshFilter();

		Mesh* mesh;
	};

}