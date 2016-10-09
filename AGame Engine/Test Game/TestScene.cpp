#include "TestScene.h"
#include "GameObject.h"

using namespace AGameEngine;

TestScene::TestScene(MainGame& mainGame)
{
	
}


TestScene::~TestScene()
{
	delete testShader;
	delete testTexture;
	delete testMesh;
}

void TestScene::Start()
{
	_myMonkey = new MonkeyScript;
	//delete _myMonkey;

	cameraObject = new GameObject("Camera");
	camera = new Camera();//(glm::vec3(0.0f, 0.0f, -5.0f), 70.0f, (float)1024 / (float)576, 0.01f, 1000.0f);
	camera->gameObject = cameraObject;
	cameraObject->AddComponent(camera);

	//Create assets
	testShader = new Shader("./Assets/Shaders/BasicShader");
	testTexture = new Texture("./Assets/Test/bricks.jpg");
	testMesh = new Mesh("./Assets/Test/monkey3.obj");
	testMaterial = new Material(testShader);
	testMaterial->mainTexture = testTexture;

	//Create test object, monkey
	myObject = new GameObject;
	testTransform = new Transform;

	myMeshFilter = new MeshFilter(testMesh);
	myMeshRenderer = new MeshRenderer(myMeshFilter, testMaterial);
	myMeshFilter->gameObject = myObject;
	myMeshRenderer->gameObject = myObject;
	myObject->AddComponent(myMeshFilter);
	myObject->AddComponent(myMeshRenderer);

}

void TestScene::Update()
{
	if (Input::GetKeyUp(SDLK_r))
	{
		//Destroy(_myMonkey);
	}
	if (Input::GetKeyUp(SDLK_y))
	{
		//Destroy(myObject);
	}
	if (Input::GetKey(SDL_SCANCODE_LEFT)) 
	{
		myObject->transform->SetPosition(myObject->transform->GetPosition() + vec3(-3 * Time::GetDeltaTime() / 1000.0f, 0, 0));
	}
	else if (Input::GetKey(SDL_SCANCODE_RIGHT))
	{
		myObject->transform->SetPosition(myObject->transform->GetPosition() + vec3(3 * Time::GetDeltaTime() / 1000.0f, 0, 0));
	}
	if (Input::GetKey(SDL_SCANCODE_UP))
	{
		myObject->transform->SetPosition(myObject->transform->GetPosition() + vec3(0, 0, -3 * Time::GetDeltaTime() / 1000.0f));
	}
	else if (Input::GetKey(SDL_SCANCODE_DOWN))
	{
		myObject->transform->SetPosition(myObject->transform->GetPosition() + vec3(0, 0, 3 * Time::GetDeltaTime() / 1000.0f));
	}
	if (Input::GetKey(SDL_SCANCODE_Z))
	{
		testShader->Bind();
		testTexture->Bind(0);
		testShader->Update(testTransform, camera);
		testMesh->Draw();
	}
}