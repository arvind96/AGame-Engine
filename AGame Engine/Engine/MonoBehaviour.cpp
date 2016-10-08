#include "MonoBehaviour.h"

namespace AGameEngine {

	std::list <MonoBehaviour*> MonoBehaviour::allMonoBehaviors;
	MonoBehaviour* MonoBehaviour::nullMonoBehaviour;

	MonoBehaviour::MonoBehaviour()
	{
		allMonoBehaviors.push_back(this);
	}

	MonoBehaviour::~MonoBehaviour()
	{
		replace(allMonoBehaviors.begin(), allMonoBehaviors.end(), this, nullMonoBehaviour);
		//allMonoBehaviors.remove(this);
	}

}