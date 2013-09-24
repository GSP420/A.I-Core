#include "GenericEnemy.h"

GenericEnemy::GenericEnemy(Agent* selfAgent)
{
	self = selfAgent;
	currentState = NULL;
}

GenericEnemy::~GenericEnemy()
{
	if(currentState != NULL) delete currentState;
}

void GenericEnemy::assessEnvironment(void* player)
{
	// here you would check things like distance to player and decide what type of state to change to
	// because we only have one state for now, we'll just switch to that state. the enter and exit
	// methods are also currently superfluous, but are still used to show how the pattern would look
	// like for more comlex behavior assesments.

	if(currentState != NULL) 
	{
		currentState->exit();
		delete currentState;
	}

	currentState = new Wander(self, (Agent*)player);
	currentState->enter();
}

void GenericEnemy::behave()
{
	// whatever state we chose, perform the actions associated with it
	currentState->enact();
}