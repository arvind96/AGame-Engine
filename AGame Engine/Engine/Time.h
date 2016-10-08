#pragma once
#include <SDL\SDL.h>
#include <cstdint>

namespace AGameEngine {

	class Time
	{
	public:
		Time();
		~Time();
		void UpdateDeltaTime(int value);	//to update the delta time per frame

		//returns real time since game starting in milliseconds
		static inline Uint32 GetRealTimeSinceStartUp() {
			_realTimeSinceStartup = SDL_GetTicks();
			return _realTimeSinceStartup;
		}
		static inline float GetTimeScale() { return _timeScale; }	//return the main game time scale
		static inline void SetTimeScale(float& value) { _timeScale = value; }	//Sets the main game time scale
		static inline int GetDeltaTime() { return _deltaTime; }	//returns the time taken by previous frame in millisecons
		static inline int GetUnscaledDeltaTime() { return _unscaledDeltaTime; }	//returns the unscaled time taken by previous frame in millisecons
		static inline int GetFixedDeltaTime() { return _fixedDeltaTime; }	//returns the fixed timestep
		static inline void SetFixedDeltaTime(int value) { _deltaTime = value; }	//sets the value of fixed timestep
	private:
		static Uint32 _realTimeSinceStartup;
		static float _timeScale;
		static int _deltaTime;
		static float _unscaledDeltaTime;
		static int _fixedDeltaTime;
	};

}