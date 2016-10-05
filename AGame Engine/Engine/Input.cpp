#include "Input.h"
#include <iostream>
#include <SDL\SDL.h>

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


	//Single hit keys, mouse, and other general SDL events (eg. windowing)
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_MOUSEMOTION:

				break;
			case SDL_QUIT:
			
				break;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE)
				
				break;
		}
	}
	
}
