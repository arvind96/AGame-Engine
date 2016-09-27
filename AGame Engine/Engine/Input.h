#pragma once
class Input
{
public:
	Input();
	
	void GetInput();

	float GetXInput() { return xInput; }
	float GetYInput() { return yInput; }
	
	
	~Input();
private:
	float xInput;
	float yInput;
};

