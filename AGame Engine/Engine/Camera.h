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

		inline mat4 GetProjectionMatrix() const
		{
			return _projection;
		}

		inline mat4 GetViewMatrix() const
		{
			return lookAt(gameObject->transform->GetPosition(), gameObject->transform->GetPosition() + gameObject->transform->GetForwardVector(), gameObject->transform->GetUpVector());
		}

		void UpdateProjectionMatrix();
		void CameraLateUpdate();

		inline float GetFieldOfView()
		{
			return _fieldOfView; 
		}
		inline void SetFieldOfView(float value) 
		{
			_fieldOfView = Mathf::Clamp(value, 1.0f, 179.0f);
			UpdateProjectionMatrix();
		}

		void SetOrthographic(bool value)
		{
			_orthographic = value;
			UpdateProjectionMatrix();
		}

		bool GetOrthographic()
		{
			return _orthographic;
		}

		void SetOrthographicSize(float value)
		{
			_orthographicSize = value;
			UpdateProjectionMatrix();
		}

		float GetOrthographicSize()
		{
			return _orthographicSize;
		}

		static list <Camera*> allCameras;	//all cameras in scene
		static Camera* nullCamera;	//null camera...
	private:
		float _fieldOfView = 60.0f;
		float _aspectRatio = 16.0f / 9.0f;
		float _nearPlane = 0.01f;
		float _farPlane = 1000.0f;

		bool _orthographic = false;
		float _orthographicSize = 60.0f;

		mat4 _projection;
	};

}