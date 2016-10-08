#pragma once
#include "MonoBehaviour.h"
#include <iostream>
#include "Input.h"
#include <SDL\SDL.h>

using namespace AGameEngine;

class MonkeyScript : public MonoBehaviour
{
public:
	MonkeyScript();
	~MonkeyScript();

	void Start();
	void Update();
	void LateUpdate();
	void FixedUpdate();
};

