#pragma once
/*
* This is a derived class that would actually be used in the main core.
* the main team would include this header and at that point able to create an instance of
* this behavior, which is just a "Generic Enemy" that wanders.
*/

#include "Behavior.h"
#include "Wander.h"
#include <stdlib.h> 

class GenericEnemy : public Behavior
{
	private:
		Agent* self;
		State* currentState;
	public:
		GenericEnemy(Agent*);
		~GenericEnemy();
		void assessEnvironment(void* player);
		void behave();
};
