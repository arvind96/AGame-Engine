#pragma once
#include <iostream>
#include <SDL\SDL.h>

namespace AGameEngine {

	class Input
	{
	public:
		Input();
		~Input();

		void ProcessInput();

		float GetXInput() { return xInput; }
		float GetYInput() { return yInput; }

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