#pragma once
#include <iostream>
#include <string>
#include <thread>
#include "windows.h"

using namespace std;

namespace AGameEngine {

	//Base class of everything in the engine
	class Object
	{
	public:
		Object();
		virtual ~Object();

		string name;	//name of the object

		void Destroy();
		void Destroy(Object* obj);
		void Destroy(Object* obj, float t);
	protected:
		
	private:
		void DestroyAfterFun(Object* obj, float t);
	};

}