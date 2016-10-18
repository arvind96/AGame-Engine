#pragma once
#include "MonoBehaviour.h"
#include "Transform.h"

using namespace AGameEngine;

class SkyDom : public MonoBehaviour
{
public:
	SkyDom();
	~SkyDom();

	void Update();

	GameObject* cameraObject;
};

