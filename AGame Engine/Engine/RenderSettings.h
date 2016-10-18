#pragma once
#include "Object.h"
#include <glm\glm.hpp>

using namespace glm;

namespace AGameEngine {

	class RenderSettings : public Object
	{
	public:
		RenderSettings();
		~RenderSettings();

		static vec4 GetAmbientColor() { return _ambientColor * _ambientIntensity; }
		static void SetAmbientColor(vec4 color)
		{
			_ambientColor = color;
		}
		static float GetAmbientIntensity() { return _ambientIntensity; }
		static void SetAmbientIntensity(float intensity)
		{
			_ambientIntensity = intensity;
		}
	private:
		static vec4 _ambientColor;
		static float _ambientIntensity;
	};

}