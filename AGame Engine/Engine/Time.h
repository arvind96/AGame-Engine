#pragma once

namespace AGameEngine {

	class Time
	{
	public:
		Time();
		~Time();
		void Update();

		int GetRealTimeSinceStartUp();	//returns real time since game starting in milliseconds
		float GetTimeScale();	//return the main game time scale
		void SetTimeScale(float& value);	//Sets the main game time scale
		float GetDeltaTime();	//returns the time taken by previous frame in millisecons
		float GetUnscaledDeltaTime();	//returns the unscaled time taken by previous frame in millisecons
	private:
		float _realTimeSinceStartup;
		float _timeScale;
		float _deltaTime;
		float _unscaledDeltaTime;
	};

}