#include "MeshRenderer.h"
#include "GameObject.h"
#include "Input.h"

namespace AGameEngine {

	MeshRenderer::~MeshRenderer()
	{
	}

	void MeshRenderer::UpdateRenderer(Camera* camera)
	{
		material->Update(gameObject, camera);
		meshFilter->mesh->Draw();
	}

}