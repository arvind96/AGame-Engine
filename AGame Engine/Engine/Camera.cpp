#include "Camera.h"
#include "Renderer.h"

namespace AGameEngine {

	list <Camera*> Camera::allCameras;
	Camera* Camera::nullCamera;

	Camera::Camera()
	{
		allCameras.push_back(this);
	}

	Camera::~Camera()
	{
		replace(allCameras.begin(), allCameras.end(), this, nullCamera);
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