#pragma once
#include "Object.h"
#include "Shader.h"
#include "Texture.h"

namespace AGameEngine {
	
	class Material : public Object
	{
	public:
		Material();
		Material(Shader* shader) { this->shader = shader; }
		~Material();

		Shader* shader;	//Shader used by the material
		Texture* mainTexture;	//Main texture used by the material
	};

}