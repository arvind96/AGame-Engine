#include "TestScene.h"
#include "GameObject.h"


TestScene::TestScene(MainGame& mainGame)
{
	MonkeyScript *m = new MonkeyScript;
	_myMonkey = m;
	//delete _myMonkey;
	myObject = new GameObject;
}


TestScene::~TestScene()
{
}

void TestScene::Update()
{
	if (Input::GetKeyUp(SDLK_r))
	{
		//Destroy(_myMonkey);
	}
	if (Input::GetKeyUp(SDLK_y))
	{
		//Destroy(myObject);
	}
}