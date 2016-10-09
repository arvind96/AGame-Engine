#include "Renderer.h"

namespace AGameEngine {

	list <Renderer*> Renderer::allRenderers;
	Renderer* Renderer::nullRenderer;

	Renderer::Renderer()
	{
		allRenderers.push_back(this);
	}


	Renderer::~Renderer()
	{
		replace(allRenderers.begin(), allRenderers.end(), this, nullRenderer);
	}

}