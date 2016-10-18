#include "RenderSettings.h"

namespace AGameEngine {

	vec4 RenderSettings::_ambientColor = vec4(0.2, 0.2, 0.2, 1.0);
	float RenderSettings::_ambientIntensity = 1.0;

	RenderSettings::RenderSettings()
	{
	}


	RenderSettings::~RenderSettings()
	{
	}

}