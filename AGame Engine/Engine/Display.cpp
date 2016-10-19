#include "Display.h"
#include <GL\glew.h>
#include <iostream>

namespace AGameEngine {

	int Display::_width;
	int Display::_height;
	string Display::_title;

	Display::Display()
	{
	}

	Display::Display(const int& width, const int& height, const string& title)
	{
		_width = width;
		_height = height;
		_title = title;

		SDL_Init(SDL_INIT_EVERYTHING);

		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

		SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);

		glEnable(GL_MULTISAMPLE);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);

		m_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_OPENGL);
		m_glContext = SDL_GL_CreateContext(m_window);

		GLenum status = glewInit();

		if (status != GLEW_OK)
		{
			std::cerr << "Glew failed to initialize!" << std::endl;
		}

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glEnable(GL_BACK);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	Display::~Display()
	{
		SDL_GL_DeleteContext(m_glContext);
		SDL_DestroyWindow(m_window);
		SDL_Quit;
	}

	void Display::Clear(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Display::Update()
	{
		SDL_GL_SwapWindow(m_window);
	}

}