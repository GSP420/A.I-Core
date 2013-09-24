/*
* This is a derived class that would actually be used in the main core.
* the main team would include this header and at that point able to create an instance of
* this behavior, which is just a "Generic Enemy" that wanders.
*/

#include "Behavior.h"
#include "Wander.h"

class GenericEnemy : public Behavior
{
	private:
		Agent* self;
		State currentState;
	public:
		GenericEnemy(Agent*);
		void assessEnvironment(Agent*);
		void behave();
};

GenericEnemy::GenericEnemy(Agent* selfAgent)
{
	self = selfAgent;
}

void GenericEnemy::assessEnvironment(Agent* player)
{
	// here you would check things like distance to player and decide what type of state to change to
	// because we only have one state for now, we'll just switch to that state. the enter and exit
	// methods are also currently superfluous, but are still used to show how the pattern would look
	// like for more comlex behavior assesments.

	currentState.exit();
	currentState = Wander(self, player);
	currentState.enter();
}

void GenericEnemy::behave()
{
	// whatever state we chose, perform the actions associated with it
	currentState.enact();
}