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
	}

	void MainGame::Quit()
	{
		_gameState = GameState::EXIT;
	}

	void MainGame::run()
	{
		Display display(_displayWidth, _displayHeight, _displayTitle);
		_display = display;
		_display.Clear(0.0f, 0.15f, 0.15f, 1.0f);
		_display.Update();
		cout << "Loading Time: " << SDL_GetTicks() << "ms" << endl;
		for each (MonoBehaviour* mb in MonoBehaviour::allMonoBehaviors)
		{
			mb->Start();
		}
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
		/*
		auto it = MonoBehaviour::allMonoBehaviors.begin();
		while(it != MonoBehaviour::allMonoBehaviors.end())
		{
			(*it)->Update();
			it++;
		}
		*/
		for each (MonoBehaviour* mb in MonoBehaviour::allMonoBehaviors)
		{
			mb->Update();
		}
		for each (MonoBehaviour* mb in MonoBehaviour::allMonoBehaviors)
		{
			mb->LateUpdate();
		}

		_display.Clear(0.0f, 0.15f, 0.15f, 1.0f);
		_display.Update();
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
		}
	}

	void MainGame::FixedLoop()
	{
		for each (MonoBehaviour* mb in MonoBehaviour::allMonoBehaviors)
		{
			mb->FixedUpdate();
		}
	}

}
