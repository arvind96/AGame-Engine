#include "MeshRenderer.h"
#include "GameObject.h"
#include "Input.h"

namespace AGameEngine {

	MeshRenderer::MeshRenderer()
	{
	}


	MeshRenderer::~MeshRenderer()
	{
	}

	void MeshRenderer::UpdateRenderer(Camera* camera)
	{
		material->shader->Bind();
		if (material->mainTexture)
		{
			material->mainTexture->Bind(0);
		}
		material->shader->Update(gameObject->transform, camera);
		meshFilter->mesh->Draw();
	}

}