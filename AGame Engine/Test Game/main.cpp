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

using namespace AGameEngine;

int main(int argc, char** argv)
{
	MainGame maingame;
	TestScene testScene(maingame);
	maingame.run();

	return 0;
}