#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>

#include "Shader.h"
#include "GUISkin.h"

using namespace std;
using namespace glm;

namespace AGameEngine {

	class GUI
	{
	public:
		GUI();
		~GUI();

		static void Label(GUISkin* guiSkin, string text, vec2 pos, GLfloat scale, glm::vec4 color);
	private:
		
	};

}