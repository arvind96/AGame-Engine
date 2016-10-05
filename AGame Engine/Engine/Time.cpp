#include "Time.h"
#include <SDL\SDL.h>

namespace AGameEngine {

	Time::Time() :
		_timeScale(1.0)
	{
	}


	Time::~Time()
	{
	}

	void Time::Update()
	{
		_deltaTime = SDL_GetTicks() - _realTimeSinceStartup;
		_realTimeSinceStartup = SDL_GetTicks();
	}

	int Time::GetRealTimeSinceStartUp()
	{
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
	
	float Time::GetDeltaTime()
	{
		return _deltaTime;
	}

	float Time::GetUnscaledDeltaTime()
	{
		return _unscaledDeltaTime;
	}


}