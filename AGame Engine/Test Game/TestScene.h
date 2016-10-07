#pragma once
#include <MainGame.h>
#include "MonkeyScript.h"

using namespace AGameEngine;

class TestScene
{
public:
	TestScene(MainGame& mainGame);
	~TestScene();


	MonkeyScript _myMonkey;
private:
};

