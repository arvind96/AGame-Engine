#pragma once
#include <glm/glm.hpp>

using namespace glm;

namespace AGameEngine {

	struct Mathf
	{
	public:
		//Static Variables
		static constexpr float PI = 3.14159265359f;
		static constexpr float Deg2Rad = 0.01745329251f;	//PI/180
		static constexpr float Rad2Deg = 57.2957795131f;	//180/PI

		//Static Functions
		///<summary>Clamps a value between a minimum float and maximum float value.</summary>
		static float Clamp(float value, float min, float max)
		{
			if (value < min){ return min; }
			else if(value > max) { return max; }
			else { return value; }
		}
		///<summary>Clamps a value between a minimum int and maximum int value.</summary>
		static int Clamp(int value, int min, int max)
		{
			if (value < min) { return min; }
			else if (value > max) { return max; }
			else { return value; }
		}
		///<summary>Clamps a value between 0 and 1.</summary>
		static float Clamp01(float value)
		{
			return Clamp(value, 0.0f, 1.0f);
		}

		///<summary>Returns the absolute value of input float</summary>
		static float Absolute(float value)
		{
			return value < 0 ? -value : value;
		}
		///<summary>Returns the absolute value of input int</summary>
		static float Absolute(int value)
		{
			return value < 0 ? -value : value;
		}

	private:


	};

}