/*
*	This is a generic behavior class the includes a very basic set of methods 
*	that are used to assess the agent's current environment and state, and then
*	act accordingly. This class is probably best used as a base class, with 
*	subclasses defining behavior specific to that behavior type. i.e., a genric
*	enemy would have basic idle, seek, evade type states, where a boss enemy
*	may include these, as well as more complex behaviors.
*
*	Author: Stephen Roebuck
*/
#include <iostream>
#include "state.h"

using namespace std;

class Behavior
{
	private:
		int agent;						// the agent this behavior belongs to
		State state;						// the current state of the ganet this behavior belongs to
	public:
		Behavior(int);					// constructor
		void assessEnvironment(int);	// decide what state to be in
		void behave();					// behave according to the current state
};

Behavior::Behavior(int agentId)
{	//NOTE: the agentId argument is an int here as a place holder, it should be an actual enemy object

	agent = agentId;
}

void Behavior::assessEnvironment(int player)
{	//NOTE: the player argument is an int here as a place holder, it should be an actual player object

	// check the position of the agent this behavior is attached to, relative to the player.
	
	// a check should be made to see if the current state should be changed. if so, the following happens:

		// current state is exited
		state.exit();

		// state is changed to the new state
		state = State(agent,player); // change the state based on assesment

		// the new state's enter method is called.
		state.enter();
}

void Behavior::behave()
{
	// perform action based on the state that this behavior is in
	// actions could return values if needed, but for now just call the current state's enact() method
	state.enact();
}
