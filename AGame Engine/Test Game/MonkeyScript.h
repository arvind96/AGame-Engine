#pragma once
#include "MonoBehaviour.h"
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

