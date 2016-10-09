#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "obj_loader.h"
#include "Object.h"

using namespace std;
using namespace glm;

namespace AGameEngine {

	class Vertex
	{
	public:
		Vertex(const vec3& pos, const vec2& texCoord, const vec3& normal = vec3(0, 0, 0))
		{
			this->pos = pos;
			this->texCoord = texCoord;
			this->normal = normal;
		}

		glm::vec3* GetPos() { return &pos; }
		glm::vec2* GetTexCoord() { return &texCoord; }
		glm::vec3* GetNormal() { return &normal; }
	private:
		glm::vec3 pos;
		glm::vec2 texCoord;
		glm::vec3 normal;
	};

	class Mesh : public Object
	{
	public:
		Mesh(){}
		Mesh(Vertex* vertices, unsigned int numVertices, unsigned int* indices, unsigned int numIndices);
		Mesh(const std::string& fileName);	//Filename is the location of the model, eg. "./Assets/Models/SimpleModel.obj"

		void Draw();

		virtual ~Mesh();
	protected:

	private:
		Mesh(const Mesh& other);
		//void operator = (const Mesh& other);

		void InitMesh(const IndexedModel& model);

		enum
		{
			POSITION_VB,
			TEXCOORD_VB,
			NORMAL_VB,

			INDEX_VB,

			NUM_BUFFERS
		};

		GLuint m_vertexArrayObject;
		GLuint m_vertexArrayBuffers[NUM_BUFFERS];

		unsigned int m_drawCount;
	};

}