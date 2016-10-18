#pragma once
#include "Behaviour.h"

namespace AGameEngine {

	enum LightType
	{
		Spot,
		Directional,
		Point,
		Area
	};

	class Light : public Behaviour
	{
	public:
		Light();
		~Light();
	};

}