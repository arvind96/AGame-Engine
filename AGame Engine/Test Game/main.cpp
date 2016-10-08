#include <iostream>
#include <GL/glew.h>
#include <MainGame.h>
#include "Display.h"
#include "Input.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Transform.h"
#include "Camera.h"
#include "TestScene.h"

#define WIDTH 1024
#define HEIGHT 576

using namespace AGameEngine;

int main(int argc, char** argv)
{
	MainGame maingame;
	MonoBehaviour dummy;
	TestScene testScene(maingame);
	maingame.run();

	
	//Display display(WIDTH, HEIGHT, "Test Game");
	//display.Clear(0.0f, 0.15f, 0.15f, 1.0f);
	//display.Update();
	
	//Input input;
	//Camera camera(glm::vec3(0, 0, -5.0f), 70.0f, (float)WIDTH / (float)HEIGHT, 0.01f, 1000.0f);

	//Transform transform;
	//Mesh mesh2("./Assets/Test/monkey3.obj");
	//Shader shader("./Assets/Shaders/BasicShader");
	//Texture texture("./Assets/Test/bricks.jpg");

	//float timer = 0;

	//std::cout << "Loading Time: " << SDL_GetTicks();
	/*
	while (!display.IsClosed())
	{
		display.Clear(0.0f, 0.15f, 0.15f, 1.0f);
		//input.ProcessInput();

		//shader.Bind();
		//texture.Bind(0);
		//shader.Update(transform, camera);
		//mesh2.Draw();

		display.Update();
		//timer += 1.0f;
	}
	*/
	return 0;
}