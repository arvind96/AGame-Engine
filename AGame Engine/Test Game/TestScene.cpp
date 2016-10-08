#include "TestScene.h"



TestScene::TestScene(MainGame& mainGame)
{
	MonkeyScript *m = new MonkeyScript;
	_myMonkey = m;
	//delete _myMonkey;
}


TestScene::~TestScene()
{
}

void TestScene::Update()
{
	if (Input::GetKeyUp(SDLK_r))
	{
		Destroy(_myMonkey);
	}
}