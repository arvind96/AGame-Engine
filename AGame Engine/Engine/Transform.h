#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Mathf.h"

using namespace std;
using namespace glm;

namespace AGameEngine {

	enum Space
	{
		Self,
		World
	};

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

		///<summary>Returns the model martix of the transform</summary>
		inline mat4 GetModel() const
		{
			mat4 positionMat = translate(_position);
			mat4 rotationMat = toMat4(_quaternion);
			mat4 scaleMat = scale(_scale);

			return positionMat * rotationMat * scaleMat;
		}

		void Translate(vec3 translation)
		{
			SetPosition(_position + translation);
		}

		///<summary>Rotates the transform about the axis by angle relative to the space</summary>
		void Rotate(vec3 axis, float angleDegrees, Space space)
		{
			angleDegrees *= Mathf::Deg2Rad / 2;
			axis = normalize(axis);
			float cosA = cos(angleDegrees);
			float sinA = sin(angleDegrees);
			quat newQuat = quat(cosA, axis.x * sinA, axis.y * sinA, axis.z * sinA);
			if (space == Space::World)
			{
				//float qMod = sqrt(_quaternion.x * _quaternion.x + _quaternion.y * _quaternion.y + _quaternion.z * _quaternion.z + _quaternion.w * _quaternion.w);
				//SetRotation(_quaternion * quat(_quaternion.w / qMod, -_quaternion.x / qMod, -_quaternion.y / qMod, -_quaternion.z / qMod) * newQuat * quat(_quaternion.w / qMod, _quaternion.x / qMod, _quaternion.y / qMod, _quaternion.z / qMod));
				SetRotation(newQuat * _quaternion);
			}
			else
			{
				//SetRotation(rotate(_quaternion, angle, axis));
				SetRotation(_quaternion * newQuat);
			}
		}

		///<summary>Rotates the transform about the axis by angle relative to the object's space</summary>
		void Rotate(vec3 axis, float angleDegrees)
		{
			angleDegrees *= Mathf::Deg2Rad;
			SetRotation(rotate(_quaternion, angleDegrees, axis));
		}

		inline vec3 GetPosition() { return _position; }
		inline vec3 GetEulerAngles() { return _eulerAngles; }
		inline vec3 GetScale() { return _scale; }
		inline quat GetRotation() { return _quaternion; }

		inline vec3 GetForwardVector() { return normalize(_quaternion * vec3(0, 0, 1)); }
		inline vec3 GetRightVector() { return normalize(_quaternion * vec3(1, 0, 0)); }
		inline vec3 GetUpVector() { return normalize(_quaternion * vec3(0, 1, 0)); }

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