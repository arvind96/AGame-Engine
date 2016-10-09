#pragma once
#include <MainGame.h>
#include "MonkeyScript.h"
#include "MonoBehaviour.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"
#include "TestScene.h"
#include "MeshFilter.h"
#include "MeshRenderer.h"
#include "Material.h"

using namespace AGameEngine;

class TestScene : public MonoBehaviour
{
public:
	TestScene(MainGame& mainGame);
	~TestScene();

	void Start();
	void Update();

	MonkeyScript* _myMonkey;
	
	GameObject* myObject;
	MeshFilter* myMeshFilter;
	MeshRenderer* myMeshRenderer;

	GameObject* cameraObject;
	Camera* camera;

	Shader* testShader;
	Material* testMaterial;
	Texture* testTexture;
	Mesh* testMesh;
	Transform* testTransform;
private:
};

