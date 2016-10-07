#include "MonoBehaviour.h"

std::vector <MonoBehaviour*> MonoBehaviour::allMonoBehaviors;

MonoBehaviour::MonoBehaviour()
{
	allMonoBehaviors.push_back(this);
}


MonoBehaviour::~MonoBehaviour()
{
}

void MonoBehaviour::Start()
{
}

void MonoBehaviour::Update()
{
}

void MonoBehaviour::LateUpdate()
{
}

void MonoBehaviour::FixedUpdate()
{
}