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
		for (int i = 0; i < MonoBehaviour::allMonoBehaviors.size(); i++)
		{
			MonoBehaviour::allMonoBehaviors[i]->Start();
		}
		thread tFixed(&MainGame::FixedUpdate, this);
		tFixed.detach();
		while (_gameState == GameState::RUNNING)
		{
			GameLoop();
			SDL_Event e;
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
				{
					_gameState = GameState::EXIT;
				}
			}
		}
	}

	void MainGame::GameLoop()
	{
		_time.UpdateDeltaTime(SDL_GetTicks() - _updateTimeCounter);
		_updateTimeCounter = SDL_GetTicks();
		_input.ProcessInput();

		for (int i = 0; i < MonoBehaviour::allMonoBehaviors.size(); i++)
		{
			MonoBehaviour::allMonoBehaviors[i]->Update();
		}
		for (int i = 0; i < MonoBehaviour::allMonoBehaviors.size(); i++)
		{
			MonoBehaviour::allMonoBehaviors[i]->LateUpdate();
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
		for (int i = 0; i < MonoBehaviour::allMonoBehaviors.size(); i++)
		{
			MonoBehaviour::allMonoBehaviors[i]->FixedUpdate();
		}
	}

}
