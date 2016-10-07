#include "MonkeyScript.h"
#include <iostream>


MonkeyScript::MonkeyScript()
{
}


MonkeyScript::~MonkeyScript()
{
}


void MonkeyScript::Start()
{
	std::cout << "Monkey start called!" << std::endl;
}

void MonkeyScript::Update()
{
	//std::cout << "Monkey update called!" << std::endl;
}

void MonkeyScript::LateUpdate()
{
	//std::cout << "Monkey lateupdate called!" << std::endl;
}

void MonkeyScript::FixedUpdate()
{
	std::cout << "Monkey fixedupdate called!" << std::endl;
}