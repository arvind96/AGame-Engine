#pragma once
#include <MainGame.h>
#include "MonkeyScript.h"
#include "MonoBehaviour.h"

using namespace AGameEngine;

class TestScene : public MonoBehaviour
{
public:
	TestScene(MainGame& mainGame);
	~TestScene();

	void Update();

	MonkeyScript *_myMonkey;
private:
};

