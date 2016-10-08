#include "MonkeyScript.h"

using namespace AGameEngine;

MonkeyScript::MonkeyScript()
{
}

MonkeyScript::~MonkeyScript()
{
	cout << "Monkey Destroyed" << endl;
}

void MonkeyScript::Start()
{
	std::cout << "Monkey start called!" << std::endl;
}

void MonkeyScript::Update()
{
	//std::cout << "Monkey update called!" << std::endl;
	
	if (Input::GetKeyDown(SDLK_e))
	{
		//std::cout << "E pressed down!" << std::endl;
	}
	else
	{

	}
	if (Input::GetKeyUp(SDLK_e))
	{
		//std::cout << "E pressed up!" << std::endl;
		Destroy(this);
	}
	else
	{

	}
}

void MonkeyScript::LateUpdate()
{
	//std::cout << "Monkey lateupdate called!" << std::endl;
}

void MonkeyScript::FixedUpdate()
{
	//std::cout << "Monkey fixedupdate called!" << std::endl;
}