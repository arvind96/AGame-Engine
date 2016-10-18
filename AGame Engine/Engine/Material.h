#pragma once
#include "Object.h"
#include "Shader.h"
#include "Texture.h"

namespace AGameEngine {
	
	class Material : public Object
	{
	public:
		Material(Shader* shader = nullptr)
		{
			SetShader(shader);
		}
		~Material(){}

		void Update(GameObject* gameObject, Camera* camera)
		{
			this->shader->Bind();
			if (mainTexture)
			{
				mainTexture->Bind(0);
			}
			shader->Update(gameObject->transform, camera);
		}

		void SetShader(Shader* shader)
		{
			this->shader = shader;
		}
		void SetMainTexture(Texture* texture)
		{
			mainTexture = texture;
		}
	private:
		Shader* shader;	//Shader used by the material
		Texture* mainTexture;	//Main texture used by the material
	};

}