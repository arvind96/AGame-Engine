#include "MainGame.h"

namespace AGameEngine {

	MainGame::MainGame() :
		_displayWidth(1024),
		_displayHeight(576),
		_displayTitle("Game Title"),
		_gameState(GameState::RUNNING)
	{
	}

	MainGame::MainGame(int displayWidth, int displayHeight, const string& displayTitle)
	{
		_displayWidth = displayWidth;
		_displayHeight = displayHeight;
		_displayTitle = displayTitle;
		_gameState = GameState::RUNNING;
	}

	MainGame::~MainGame()
	{
		delete _display;
	}

	void MainGame::Quit()
	{
		_gameState = GameState::EXIT;
	}

	void MainGame::init()
	{
		_display = new Display(_displayWidth, _displayHeight, _displayTitle);
		_display->Clear(0.0f, 0.15f, 0.15f, 1.0f);
		_display->Update();
		cout << "Init time: " << SDL_GetTicks() << "ms" << endl;
	}

	void MainGame::run()
	{
		for each (MonoBehaviour* mb in MonoBehaviour::allMonoBehaviors)
		{
			if(mb)
			mb->Start();
		}
		cout << "Start completed in: " << SDL_GetTicks() << "ms" << endl;
		thread tFixed(&MainGame::FixedUpdate, this);
		tFixed.detach();
		while (_gameState == GameState::RUNNING)
		{
			GameLoop();
			if (Input::Quit())
			{
				Quit();
			}
		}
	}

	void MainGame::GameLoop()
	{
		_time.UpdateDeltaTime(SDL_GetTicks() - _updateTimeCounter);
		_updateTimeCounter = SDL_GetTicks();
		_input.ProcessInput();

		_display->Clear(0.0f, 0.15f, 0.15f, 1.0f);

		for each (MonoBehaviour* mb in MonoBehaviour::allMonoBehaviors)
		{
			if(mb)
				mb->Update();
		}
		for each (MonoBehaviour* mb in MonoBehaviour::allMonoBehaviors)
		{
			if(mb)
				mb->LateUpdate();
		}
		for each (Camera* cam in Camera::allCameras)
		{
			if(cam)
				cam->CameraLateUpdate();
		}

		_display->Update();
	}

	void MainGame::FixedUpdate()
	{
		while (_gameState == GameState::RUNNING)
		{
			_fixedTimeCounter = SDL_GetTicks();
			FixedLoop();
			if (SDL_GetTicks() - _fixedTimeCounter < Time::GetFixedDeltaTime())
			{
				Sleep(Time::GetFixedDeltaTime() - (SDL_GetTicks() - _fixedTimeCounter));
			}
			else
			{
				cerr << "Unable to gain the required fixed time step, either increase fixed time step or cpu power :D" << endl;
			}
		}
	}

	void MainGame::FixedLoop()
	{
		for each (MonoBehaviour* mb in MonoBehaviour::allMonoBehaviors)
		{
			if(mb)
				mb->FixedUpdate();
		}
	}

}
