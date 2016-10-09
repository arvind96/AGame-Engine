#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include "Display.h"
#include "Input.h"
#include "Time.h"
#include "MonoBehaviour.h"
#include <thread>
#include "windows.h"
#include "Renderer.h"

using namespace std;

namespace AGameEngine {

	enum class GameState { RUNNING, EXIT };

	class MainGame
	{
	public:
		MainGame();
		MainGame(int screenWidth, int screenHeight, const string& title);
		~MainGame();

		void init();
		void run();
		void Quit();
	private:
		void GameLoop();
		void FixedUpdate();
		void FixedLoop();

		Display* _display;
		int _displayWidth;
		int _displayHeight;
		string _displayTitle;
		Input _input;
		Time _time;
		GameState _gameState;

		int _updateTimeCounter = 0;
		int _fixedTimeCounter = 0;
	};



}

