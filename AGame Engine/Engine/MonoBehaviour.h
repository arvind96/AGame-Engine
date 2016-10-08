#pragma once
#include "Behaviour.h"
#include <list>
#include <algorithm>

using namespace std;

namespace AGameEngine {

	class MonoBehaviour : public Behaviour
	{
	public:
		MonoBehaviour();
		~MonoBehaviour();

		virtual inline void Start() {}
		virtual inline void Update() {}
		virtual inline void LateUpdate() {}
		virtual inline void FixedUpdate() {}

		static std::list <MonoBehaviour*> allMonoBehaviors;
		static MonoBehaviour* nullMonoBehaviour;
	private:
	};

}