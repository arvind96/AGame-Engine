#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <list>
#include <algorithm>
#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "Mathf.h"

using namespace glm;
using namespace std;

namespace AGameEngine {

	class Camera : public Component
	{
	public:
		Camera();
		~Camera();

		inline glm::mat4 GetViewProjection() const
		{
			return glm::perspective(_fieldOfView * Mathf::Deg2Rad, aspectRatio, nearPlane, farPlane) * glm::lookAt(gameObject->transform->GetPosition(), vec3(0, 0, 1), vec3(0, 1, 0));
		}

		//void MoveForward(float amt)
		//{
		//	pos += forward * amt;
		//}

		//void MoveRight(float amt)
		//{
		//	pos += glm::cross(up, forward) * amt;
		//}

		//void Pitch(float angle)
		//{
		//	glm::vec3 right = glm::normalize(glm::cross(up, forward));

		//	forward = glm::vec3(glm::normalize(glm::rotate(angle, right) * glm::vec4(forward, 0.0)));
		//	up = glm::normalize(glm::cross(forward, right));
		//}

		void RotateY(float angle)
		{
			static const glm::vec3 UP(0.0f, 1.0f, 0.0f);

			glm::mat4 rotation = glm::rotate(angle, UP);

			forward = glm::vec3(glm::normalize(rotation * glm::vec4(forward, 0.0)));
			up = glm::vec3(glm::normalize(rotation * glm::vec4(up, 0.0)));
		}

		void CameraLateUpdate();

		inline float GetFieldOfView() 
		{
			return _fieldOfView; 
		}
		inline void SetFieldOfView(float value) 
		{
			_fieldOfView = Mathf::Clamp(value, 1.0f, 179.0f);
		}

		float aspectRatio = 16.0f/9.0f;
		float nearPlane = 0.01f;
		float farPlane = 1000.0f;

		static list <Camera*> allCameras;	//all cameras in scene
		static Camera* nullCamera;	//null camera...
	private:
		float _fieldOfView = 60.0f;

		glm::vec3 pos;
		glm::vec3 forward;
		glm::vec3 up;
	};

}