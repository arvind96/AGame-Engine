#include "Object.h"

namespace AGameEngine {

	Object::Object() :
		name("Object")
	{
	}


	Object::~Object()
	{
	}

	void Object::Destroy()
	{
		Destroy(this);
	}

	///<summary>Destroys the Object obj< / summary>
	void Object::Destroy(Object* obj)
	{
		delete obj;
	}

	///<summary>Destroys the Object obj after time t< / summary>
	void Object::Destroy(Object* obj, float t)
	{
		thread tFixed(&Object::DestroyAfterFun, this, obj, t);
		tFixed.detach();
	}

	///<summary>Destroys the Object obj after time t function for Destroy thread< / summary>
	void Object::DestroyAfterFun(Object* obj, float t)
	{
		Sleep(t);
		Destroy(obj);
	}

}