#pragma once
#include <iostream>
#include <string>
#include "Display.h"
#include "Input.h"
#include "Time.h"

using namespace std;

namespace AGameEngine {

	enum class GameState { RUNNING, EXIT };

	class MainGame
	{
	public:
		MainGame();
		MainGame(int screenWidth, int screenHeight, const string& title);
		~MainGame();

		void run();
		void Quit();
	private:
		void GameLoop();

		Display _display;
		int _displayWidth;
		int _displayHeight;
		string _displayTitle;
		Input _input;
		Time _time;
		GameState _gameState;
	};



}

