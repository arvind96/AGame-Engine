#include "TestScene.h"
#include "GameObject.h"
#include "RenderSettings.h"

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
	cameraObject->AddComponent(camera);
	cameraObject->transform->SetPosition(vec3(0.0f, 0.0f, -5.0f));

	RenderSettings::SetAmbientColor(vec4(0.0, 0.3, 0.0, 1.0));
	RenderSettings::SetAmbientIntensity(0.5);

	//Create assets
	testShader = new Shader("./Assets/Shaders/BasicShader");
	testTexture = new Texture("./Assets/Test/bricks.jpg");
	testMesh = new Mesh("./Assets/Test/testmodel.obj");
	testMaterial = new Material(testShader);
	testMaterial->SetMainTexture(testTexture);

	monkeyMesh = new Mesh("./Assets/Test/Monkey3.obj");

	skyShader = new Shader("./Assets/Shaders/UnlitTexture");
	skyTexture = new Texture("./Assets/Test/milkyway.png");
	skySphereMesh = new Mesh("./Assets/Test/insideSphere.obj");
	skyMat = new Material(skyShader);
	skyMat->SetMainTexture(skyTexture);

	//Setup scene
	skySphereObject = new GameObject;
	skyFilter = new MeshFilter(skySphereObject, skySphereMesh);
	skyRenderer = new MeshRenderer(skySphereObject, skyFilter, skyMat);
	skySphereObject->transform->SetScale(vec3(1, 1, 1) * 500.0f);

	skyDomScript = new SkyDom();
	skyDomScript->cameraObject = cameraObject;

	skySphereObject->AddComponent(skyDomScript);


	//Create test object, monkey
	myObject = new GameObject;
	testTransform = new Transform;

	myMeshFilter = new MeshFilter(myObject, testMesh);
	myMeshRenderer = new MeshRenderer(myObject, myMeshFilter, testMaterial);

	myObject->transform->SetScale(vec3(0.1f, 0.1f, 1.0f));

	myObject2 = new GameObject;
	myMeshFilter2 = new MeshFilter(myObject2, monkeyMesh);
	myMeshRenderer2 = new MeshRenderer(myObject2, myMeshFilter2, testMaterial);
	//myObject2->transform->SetScale(vec3(100.0f, 0.5f, 100.0f));
	//myObject2->transform->SetPosition(vec3(0, -10, 0));

	Input::SetRelativeMouseMode(SDL_TRUE);
}

void TestScene::Update()
{
	if (Input::GetKeyUp(SDLK_r))
	{
		//Destroy(_myMonkey);
	}
	if (Input::GetKeyUp(SDLK_y))
	{
		Destroy(cameraObject);
		//Destroy(myMeshRenderer);
		//Destroy(myMeshFilter);
	}
	
	if (Input::GetKey(SDL_SCANCODE_LEFT)) 
	{
		myObject->transform->Rotate(cameraObject->transform->GetForwardVector(), 150.0f * Time::GetDeltaTimeInSec());
	}
	else if (Input::GetKey(SDL_SCANCODE_RIGHT))
	{
		myObject->transform->Rotate(cameraObject->transform->GetUpVector(), -150.0f * Time::GetDeltaTimeInSec());
	}
	if (Input::GetKey(SDL_SCANCODE_UP))
	{
		myObject->transform->Translate(myObject->transform->GetForwardVector() * Time::GetDeltaTimeInSec() * 3.0f);
		//myObject->transform->SetEulerAngles(myObject->transform->GetEulerAngles() + vec3(0, 0, -3 * Time::GetDeltaTime() / 1000.0f));
	}
	else if (Input::GetKey(SDL_SCANCODE_DOWN))
	{
		myObject->transform->Translate(-myObject->transform->GetForwardVector() * Time::GetDeltaTimeInSec() * 3.0f);
		//myObject->transform->SetEulerAngles(myObject->transform->GetEulerAngles() + vec3(0, 0, 3 * Time::GetDeltaTime() / 1000.0f));
		//myObject->transform->Rotate(cameraObject->transform->GetForwardVector(), 45 * (Time::GetDeltaTime()/1000.0f));
	}
	
	if (Input::GetKey(SDL_SCANCODE_A))
	{
		cameraObject->transform->Rotate(vec3(0, 1, 0), 150.0f * Time::GetDeltaTimeInSec(), Space::World);
	}
	else if (Input::GetKey(SDL_SCANCODE_D))
	{
		cameraObject->transform->Rotate(vec3(0, 1, 0), -150.0f * Time::GetDeltaTimeInSec(), Space::World);
	}
	if (Input::GetKey(SDL_SCANCODE_W))
	{
		cameraObject->transform->Translate(cameraObject->transform->GetForwardVector() * (Time::GetDeltaTime() / 1000.0f) * 3.0f);
	}
	else if (Input::GetKey(SDL_SCANCODE_S))
	{
		cameraObject->transform->Translate(-cameraObject->transform->GetForwardVector() * (Time::GetDeltaTime() / 1000.0f) * 3.0f);
	}
	/*
	if (Input::GetKey(SDL_SCANCODE_A))
	{
		//myObject2->transform->Rotate(vec3(-myObject2->transform->GetUpVector().x, myObject2->transform->GetUpVector().y, -myObject2->transform->GetUpVector().z), 150.0f * Time::GetDeltaTimeInSec());
		myObject2->transform->Rotate(vec3(0, 1, 0), 150.0f * Time::GetDeltaTimeInSec(), Space::World);
	}
	else if (Input::GetKey(SDL_SCANCODE_D))
	{
		//myObject2->transform->Rotate(vec3(-myObject2->transform->GetUpVector().x, myObject2->transform->GetUpVector().y, -myObject2->transform->GetUpVector().z), -150.0f * Time::GetDeltaTimeInSec());
		myObject2->transform->Rotate(vec3(0, 1, 0), -150.0f * Time::GetDeltaTimeInSec(), Space::World);
	}
	if (Input::GetKey(SDL_SCANCODE_W))
	{
		myObject2->transform->Rotate(vec3(1, 0, 0), 150.0f * Time::GetDeltaTimeInSec(), Space::Self);
	}
	else if (Input::GetKey(SDL_SCANCODE_S))
	{
		myObject2->transform->Rotate(vec3(1, 0, 0), -150.0f * Time::GetDeltaTimeInSec(), Space::Self);
	}
	*/
	cameraObject->transform->Rotate(vec3(1, 0, 0), 30.0f * Time::GetDeltaTimeInSec() * Input::GetMousePositionDelta().y);
	cameraObject->transform->Rotate(vec3(0, 1, 0), -30.0f * Time::GetDeltaTimeInSec() * Input::GetMousePositionDelta().x, Space::World);

	if (Input::GetKey(SDL_SCANCODE_Q))
	{
		camera->SetFieldOfView(camera->GetFieldOfView() - Time::GetDeltaTime() / 5.0f);
		camera->SetOrthographicSize(camera->GetOrthographicSize() - Time::GetDeltaTime() / 5.0f);
	}
	else if (Input::GetKey(SDL_SCANCODE_E))
	{
		camera->SetFieldOfView(camera->GetFieldOfView() + Time::GetDeltaTime() / 5.0f);
		camera->SetOrthographicSize(camera->GetOrthographicSize() + Time::GetDeltaTime() / 5.0f);
	}

	if (Input::GetKeyUp(SDLK_t))
	{
		camera->SetOrthographic(!camera->GetOrthographic());
	}
}