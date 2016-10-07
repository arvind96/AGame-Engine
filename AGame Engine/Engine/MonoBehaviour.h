#pragma once
#include <vector>

class MonoBehaviour
{
public:
	MonoBehaviour();
	~MonoBehaviour();

	virtual void Start();
	virtual void Update();
	virtual void LateUpdate();
	virtual void FixedUpdate();

	static std::vector <MonoBehaviour*> allMonoBehaviors;
private:
};

