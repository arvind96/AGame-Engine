#pragma once

#include <SDL\SDL.h>
#include <string>

using namespace std;

namespace AGameEngine {

	class Display
	{
	public:
		Display();
		Display(const int& width, const int& height, const string& title);
		virtual ~Display();

		void Update();

		void Clear(float r, float g, float b, float a);

		static int GetWidth()
		{
			return _width;
		}
		static int GetHeight()
		{
			return _height;
		}
		static string GetTitle()
		{
			return _title;
		}
	private:
		static int _width;
		static int _height;
		static string _title;

		SDL_Window* m_window;
		SDL_GLContext m_glContext;

	};

}