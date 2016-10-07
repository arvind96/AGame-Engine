#pragma once

namespace AGameEngine {

	class Time
	{
	public:
		Time();
		~Time();
		void UpdateDeltaTime(int value);	//to update the delta time per frame

		static int GetRealTimeSinceStartUp();	//returns real time since game starting in milliseconds
		static float GetTimeScale();	//return the main game time scale
		static void SetTimeScale(float& value);	//Sets the main game time scale
		static int GetDeltaTime();	//returns the time taken by previous frame in millisecons
		static int GetUnscaledDeltaTime();	//returns the unscaled time taken by previous frame in millisecons
		static int GetFixedDeltaTime();	//returns the fixed timestep
		static void SetFixedDeltaTime(int value);	//sets the value of fixed timestep
	private:
		static int _realTimeSinceStartup;
		static float _timeScale;
		static int _deltaTime;
		static float _unscaledDeltaTime;
		static int _fixedDeltaTime;
	};

}