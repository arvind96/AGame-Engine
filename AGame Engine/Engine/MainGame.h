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
#include "GUI.h"

using namespace std;

namespace AGameEngine {

	enum class GameState { RUNNING, EXIT };

	class MainGame
	{
	public:
		MainGame(const int& screenWidth = 1024,const int& screenHeight = 576, const string& title = "Title");
		~MainGame();

		void run();
		void Quit();
	private:
		void GameLoop();
		void FixedUpdate();
		void FixedLoop();

		Display* _display;
		Input* _input;
		Time* _time;
		GameState _gameState;

		int _updateTimeCounter = 0;
		int _fixedTimeCounter = 0;
	};



}

