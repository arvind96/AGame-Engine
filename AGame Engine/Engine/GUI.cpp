#include "GUI.h"

namespace AGameEngine {

	GUI::GUI()
	{	
	}

	GUI::~GUI()
	{
	}

	void GUI::Label(GUISkin* guiSkin, string text, vec2 pos, GLfloat scale, glm::vec4 color)
	{
		guiSkin->textShader->Bind();
		guiSkin->textShader->GUIUpdate();
		guiSkin->textShader->SetColor_U(color);

		glActiveTexture(GL_TEXTURE0);
		glBindVertexArray(*(guiSkin->VAO));

		// Iterate through all characters
		std::string::const_iterator c;
		for (c = text.begin(); c != text.end(); c++)
		{
			Character ch = guiSkin->Characters[*c];

			GLfloat xpos = pos.x + ch.Bearing.x * scale;
			GLfloat ypos = pos.y - (ch.Size.y - ch.Bearing.y) * scale;

			GLfloat w = ch.Size.x * scale;
			GLfloat h = ch.Size.y * scale;
			// Update VBO for each character
			GLfloat vertices[6][4] = {
				{ xpos,     ypos + h,   0.0, 0.0 },
				{ xpos,     ypos,       0.0, 1.0 },
				{ xpos + w, ypos,       1.0, 1.0 },

				{ xpos,     ypos + h,   0.0, 0.0 },
				{ xpos + w, ypos,       1.0, 1.0 },
				{ xpos + w, ypos + h,   1.0, 0.0 }
			};
			// Render glyph texture over quad
			glBindTexture(GL_TEXTURE_2D, ch.TextureID);
			// Update content of VBO memory
			glBindBuffer(GL_ARRAY_BUFFER, *(guiSkin->VBO));
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			// Render quad
			glDrawArrays(GL_TRIANGLES, 0, 6);
			// Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
			pos.x += (ch.Advance >> 6) * scale; // Bitshift by 6 to get value in pixels (2^6 = 64)
		}
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}