#include "SkyDom.h"
#include "GameObject.h"

using namespace AGameEngine;

SkyDom::SkyDom()
{
}


SkyDom::~SkyDom()
{
}

void SkyDom::Update()
{
	gameObject->transform->SetPosition(cameraObject->transform->GetPosition());
}