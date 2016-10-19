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
#include "SkyDom.h"
#include "GUISkin.h"

using namespace AGameEngine;

class TestScene : public MonoBehaviour
{
public:
	TestScene(MainGame& mainGame);
	~TestScene();

	void Start();
	void Update();
	void OnGUI();

	//Loaded Assets
	Shader* testShader;
	Material* testMaterial;
	Texture* testTexture;
	Mesh* testMesh;

	Mesh* monkeyMesh;

	Mesh* skySphereMesh;
	Texture* skyTexture;
	Shader* skyShader;
	Material* skyMat;

	//Scene
	GameObject* skySphereObject;
	MeshFilter* skyFilter;
	MeshRenderer* skyRenderer;
	SkyDom* skyDomScript;

	GameObject* cameraObject;
	Camera* camera;

	MonkeyScript* _myMonkey;
	
	GameObject* myObject;
	MeshFilter* myMeshFilter;
	MeshRenderer* myMeshRenderer;

	GameObject* myObject2;
	MeshFilter* myMeshFilter2;
	MeshRenderer* myMeshRenderer2;

	Transform* testTransform;

	Shader* textShader;
	GUISkin* guiSkin;
	GUISkin* guiSkin2;
private:
};

