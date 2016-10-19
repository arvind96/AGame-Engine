#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>

#include "Shader.h"

using namespace std;

namespace AGameEngine {

	struct Character {
		GLuint     TextureID;  // ID handle of the glyph texture
		glm::ivec2 Size;       // Size of glyph
		glm::ivec2 Bearing;    // Offset from baseline to left/top of glyph
		GLuint     Advance;    // Offset to advance to next glyph
	};

	class GUISkin : public Object
	{
	public:
		GUISkin(Shader* textShader, const string& fontPath = NULL);	//fontPath ex: "./Assets/Fonts/CarterOne.ttf"
		~GUISkin();

		map<GLchar, Character> Characters;
		GLuint* VAO;
		GLuint* VBO;
		Shader* textShader;
	};

}