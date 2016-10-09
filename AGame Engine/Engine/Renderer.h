#pragma once
#include <list>
#include <algorithm>
#include "Component.h"
#include "Material.h"
#include "Camera.h"

using namespace std;

namespace AGameEngine {

	class Renderer : public Component
	{
	public:
		Renderer();
		~Renderer();

		virtual inline void UpdateRenderer(Camera* camera) {}

		Material* material;
		static std::list <Renderer*> allRenderers;
		static Renderer* nullRenderer;
	};

}