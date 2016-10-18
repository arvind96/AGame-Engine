#include "Camera.h"
#include "Renderer.h"

namespace AGameEngine {

	list <Camera*> Camera::allCameras;
	Camera* Camera::nullCamera;

	Camera::Camera()
	{
		allCameras.push_back(this);
		UpdateProjectionMatrix();
	}

	Camera::~Camera()
	{
		replace(allCameras.begin(), allCameras.end(), this, nullCamera);
	}

	void Camera::UpdateProjectionMatrix()
	{
		if (_orthographic)
		{
			_projection = ortho(-_orthographicSize * _aspectRatio, _orthographicSize * _aspectRatio, -_orthographicSize, _orthographicSize, _nearPlane, _farPlane);
		}
		else
		{
			_projection = perspective(_fieldOfView * Mathf::Deg2Rad, _aspectRatio, _nearPlane, _farPlane);
		}
	}

	void Camera::CameraLateUpdate()
	{
		for each (Renderer* rdr in Renderer::allRenderers)
		{
			if (rdr)
				rdr->UpdateRenderer(this);
		}
	}

}