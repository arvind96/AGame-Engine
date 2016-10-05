#pragma once
class Input
{
public:
	Input();
	
	void ProcessInput();

	float GetXInput() { return xInput; }
	float GetYInput() { return yInput; }
	
	
	~Input();
private:
	float xInput;
	float yInput;
};

