#include "Time.h"

namespace AGameEngine {

	Uint32 Time::_realTimeSinceStartup = 0;
	float Time::_timeScale = 1.0;	//Set the timescale to 1.0
	int Time::_deltaTime = 0;
	float Time::_unscaledDeltaTime = 0;
	int Time::_fixedDeltaTime = 20;	//for 50Hz

	Time::Time()
	{
	}

	Time::~Time()
	{
	}

	void Time::UpdateDeltaTime(int value)
	{
		_deltaTime = value;
	}

}