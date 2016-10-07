#include "Time.h"
#include <SDL\SDL.h>

namespace AGameEngine {

	int Time::_realTimeSinceStartup = 0;
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

	int Time::GetRealTimeSinceStartUp()
	{
		_realTimeSinceStartup = SDL_GetTicks();
		return _realTimeSinceStartup;
	}

	float Time::GetTimeScale()
	{
		return _timeScale;
	}

	void Time::SetTimeScale(float& value)
	{
		_timeScale = value;
	}
	
	int Time::GetDeltaTime()
	{
		return _deltaTime;
	}

	int Time::GetUnscaledDeltaTime()
	{
		return _unscaledDeltaTime;
	}

	int Time::GetFixedDeltaTime()
	{
		return _fixedDeltaTime;
	}

	void Time::SetFixedDeltaTime(int value)
	{
		_fixedDeltaTime = value;
	}

}