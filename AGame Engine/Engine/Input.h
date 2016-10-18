#pragma once
#include <iostream>
#include <SDL\SDL.h>
#include <glm\glm.hpp>

using namespace glm;

namespace AGameEngine {

	class Input
	{
	public:
		Input();
		~Input();

		void ProcessInput();

		float GetXInput() { return xInput; }
		float GetYInput() { return yInput; }

		static vec2 GetMousePosition();
		static vec2 GetMousePositionDelta();

		static int SetRelativeMouseMode(SDL_bool enabled)
		{
			return SDL_SetRelativeMouseMode(enabled);
		}

		static bool GetKey(SDL_Scancode scancode);
		static bool GetKeyDown(SDL_Keycode keycode);
		static bool GetKeyUp(SDL_Keycode keycode);
		static bool Quit();
	private:
		float xInput;
		float yInput;


		static SDL_Event _singleHitKeyEvent;
		static const Uint8* _continuousKey;
	};

}