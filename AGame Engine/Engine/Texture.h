#pragma once
#include <string>
#include <GL/glew.h>
#include "Object.h"

namespace AGameEngine {

	class Texture : public Object
	{
	public:
		Texture(const std::string& fileName);

		void Bind(unsigned int unit);

		~Texture();
	protected:
	private:
		Texture(const Texture& other) {}
		void operator = (const Texture& other) {}

		GLuint m_texture;


	};

}