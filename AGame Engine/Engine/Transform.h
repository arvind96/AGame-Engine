#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>

using namespace std;
using namespace glm;

namespace AGameEngine {

	class Transform : public Component
	{
	public:
		Transform(vec3& position = vec3(), vec3& eulerAngles = vec3(), vec3& scale = vec3(1.0, 1.0, 1.0))
		{
			SetPosition(position);
			SetEulerAngles(eulerAngles);
			SetScale(scale);
		}

		~Transform(){}

		inline mat4 GetModel() const
		{
			mat4 positionMat = translate(_position);
			//mat4 rotX = rotate(_eulerAngles.x, vec3(1.0, 0.0, 0.0));
			//mat4 rotY = rotate(_eulerAngles.y, vec3(0.0, 1.0, 0.0));
			//mat4 rotZ = rotate(_eulerAngles.z, vec3(0.0, 0.0, 1.0));
			//mat4 rotMat = rotX * rotY * rotZ;
			mat4 rotationMat = mat4_cast(_quaternion);
			mat4 scaleMat = scale(_scale);

			return positionMat * rotationMat * scaleMat;
		}

		void RotateAround(vec3 axis, float angle)
		{
			normalize(axis);
			quat newQuat = quat(axis.x * sin(angle / 2), axis.y * sin(angle / 2), axis.z * sin(angle / 2), cos(angle / 2));
			SetRotation(_quaternion * newQuat);
		}

		inline vec3 GetPosition() { return _position; }
		inline vec3 GetEulerAngles() { return _eulerAngles; }
		inline vec3 GetScale() { return _scale; }
		inline quat GetRotation() { return _quaternion; }

		inline void SetPosition(vec3& value) { _position = value; }
		inline void SetEulerAngles(vec3& value) 
		{ 
			_eulerAngles = value;
			_quaternion = quat(_eulerAngles);
		}
		inline void SetScale(vec3& value) { _scale = value; }
		inline void SetRotation(quat rotation)
		{
			_quaternion = rotation;
		}
	protected:
	private:
		vec3 _position;
		vec3 _eulerAngles;
		vec3 _scale;
		quat _quaternion;
	};

}