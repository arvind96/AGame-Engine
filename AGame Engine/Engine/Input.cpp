#include "Input.h"
#include <string>

namespace AGameEngine {

	SDL_Event Input::_singleHitKeyEvent;

	Input::Input()
	{
	}

	Input::~Input()
	{
	}

	void Input::ProcessInput()
	{
		const Uint8* keystate = SDL_GetKeyboardState(NULL);

		//Continuous response keys
		if (keystate[SDL_SCANCODE_LEFT])
		{
			xInput = -1.0f;
		}
		else if (keystate[SDL_SCANCODE_RIGHT])
		{
			xInput = 1.0f;
		}
		else
		{
			xInput = 0.0f;
		}
		if (keystate[SDL_SCANCODE_UP])
		{
			yInput = 1.0f;
		}
		else if (keystate[SDL_SCANCODE_DOWN])
		{
			yInput = -1.0f;
		}
		else
		{
			yInput = 0.0f;
		}

		//Single hit key event
		SDL_Event event;	//Create a new event to overide the older values
		SDL_PollEvent(&event);
		_singleHitKeyEvent = event;
		
		//if(_singleHitKeyEvent.type == SDL_MOUSEMOTION)
		//std::cout << "Motion: " << _singleHitKeyEvent.motion.y << std::endl;

		//if(_singleHitKeyEvent.type == SDL_MOUSEBUTTONDOWN)
		//	std::cout << "Mouse Button Down: " << _singleHitKeyEvent.button.button << std::endl;

		/*
		//Single hit keys, mouse, and other general SDL events (eg. windowing)
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			std::cout << "R pressed" << std::endl;
			switch (event.type)
			{
			case SDL_MOUSEMOTION:

				break;
			case SDL_QUIT:

				break;
			case SDL_KEYDOWN:
				std::cout << "Key pressed down" << std::endl;
				if (event.key.keysym.sym == SDLK_ESCAPE)
					std::cout << "R pressed" << std::endl;
					break;
			}
		}
		*/
	}

	bool Input::GetKeyDown(SDL_Keycode keycode)
	{
		if (_singleHitKeyEvent.type == SDL_KEYDOWN)
		{
			if (_singleHitKeyEvent.key.keysym.sym == keycode)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	bool Input::GetKeyUp(SDL_Keycode keycode)
	{
		if (_singleHitKeyEvent.type == SDL_KEYUP)
		{
			if (_singleHitKeyEvent.key.keysym.sym == keycode)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	bool Input::Quit()
	{
		if (_singleHitKeyEvent.type == SDL_QUIT)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}