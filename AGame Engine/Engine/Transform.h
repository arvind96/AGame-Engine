#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

using namespace std;
using namespace glm;

namespace AGameEngine {

	class Transform : public Component
	{
	public:
		Transform(const vec3& position = vec3(), const vec3& eulerAngles = vec3(), const vec3& scale = vec3(1.0, 1.0, 1.0)) :
			_position(position),
			_eulerAngles(eulerAngles),
			_scale(scale)
		{
		}

		~Transform(){}

		inline mat4 GetModel() const
		{
			mat4 posMat = translate(_position);
			mat4 rotX = rotate(_eulerAngles.x, vec3(1.0, 0.0, 0.0));
			mat4 rotY = rotate(_eulerAngles.y, vec3(0.0, 1.0, 0.0));
			mat4 rotZ = rotate(_eulerAngles.z, vec3(0.0, 0.0, 1.0));
			mat4 rotMat = rotX * rotY * rotZ;
			mat4 scaleMat = scale(_scale);

			return posMat * rotMat * scaleMat;
		}


		inline vec3 GetPosition() { return _position; }
		inline vec3 GetEulerAngles() { return _eulerAngles; }
		inline vec3 GetScale() { return _scale; }

		inline void SetPosition(vec3& value) { _position = value; }
		inline void SetEulerAngles(vec3& value) { _eulerAngles = value; }
		inline void SetScale(vec3& value) { _scale = value; }
	protected:
	private:
		vec3 _position;
		vec3 _eulerAngles;
		vec3 _scale;
	};

}