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
		void GUIUpdate();	//update for GUI shader

		//Individual uniform setters
		inline void SetMVP_U(const mat4& mvp)
		{
			glUniformMatrix4fv(m_uniforms[MVP_U], 1, GL_FALSE, &mvp[0][0]);
		}
		inline void SetM_U(const mat4& m)
		{
			glUniformMatrix4fv(m_uniforms[M_U], 1, GL_FALSE, &m[0][0]);
		}
		inline void SetV_U(const mat4& v)
		{
			glUniformMatrix4fv(m_uniforms[V_U], 1, GL_FALSE, &v[0][0]);
		}
		inline void SetP_U(const mat4& p)
		{
			glUniformMatrix4fv(m_uniforms[P_U], 1, GL_FALSE, &p[0][0]);
		}
		inline void SetColor_U(const vec4& color)
		{
			glUniform4fv(m_uniforms[Color_U], 1, &color[0]);
		}
		inline void SetSpecColor_U(const vec4& color)
		{
			glUniform4fv(m_uniforms[SpecColor_U], 1, &color[0]);
		}
		inline void SetAmbientColor_U(const vec4& color)
		{
			glUniform4fv(m_uniforms[AmbientColor_U], 1, &color[0]);
		}
		inline void SetLightDirection_U(const vec3& direction)
		{
			glUniform3fv(m_uniforms[LightDirection_U], 1, &direction[0]);
		}
		inline void SetCameraPosition_U(const vec3& position)
		{
			glUniform3fv(m_uniforms[CameraPosition_U], 1, &position[0]);
		}

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
			MVP_U,
			M_U,
			V_U,
			P_U,
			Color_U,
			SpecColor_U,
			AmbientColor_U,
			LightDirection_U,
			CameraPosition_U,
			

			NUM_UNIFORMS
		};

		
		GLuint m_shaders[NUM_SHADERS];
		GLuint m_uniforms[NUM_UNIFORMS];
		GLuint m_program;
	};

}