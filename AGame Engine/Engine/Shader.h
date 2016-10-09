#pragma once

#include <string>
#include <GL/glew.h>
#include "Transform.h"
#include "Camera.h"

using namespace std;

namespace AGameEngine {

	class Shader : public Object
	{
	public:
		Shader(const std::string& fileName);	//Location of shader vert and frag files, eg. "./Assets/Shaders/BasicShader"

		void Bind();
		void Update(const Transform* transform, const Camera* camera);

		virtual ~Shader();
	private:
		static const unsigned int NUM_SHADERS = 2;
		//static const unsigned int NUM_UNIFORMS = 3;
		//void operator=(const Shader& shader) {}
		Shader(const Shader& shader) {}

		string LoadShader(const string& fileName);
		void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage);
		GLuint CreateShader(const std::string& text, unsigned int type);

		enum
		{
			TRANSFORM_U,
			COLOR_U,

			NUM_UNIFORMS
		};

		GLuint m_program;
		GLuint m_shaders[NUM_SHADERS];
		GLuint m_uniforms[NUM_UNIFORMS];
	};

}