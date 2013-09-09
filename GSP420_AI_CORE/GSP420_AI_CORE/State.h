/*
*	This is a generic state class. this calls should be subclassed and have it's methods overridden.
*	for example, an idle state would essentially do nothing, a seek state could seek toward the player
*	a retreat state could move away from the player, etc. the behaviors of each would be defined in the
*	enact() method of the state.
*
*	Author: Stephen Roebuck
*/
#include <iostream>

using namespace std;

class State
{
	private:
		int self;
		int target;
	public:
		State(int,int);	// constructor, expects an agent (self) and target (player)
		void enter();	// called when this state is being entered
		void enact();	// behave according to the current state
		void exit();	// called when this state is being exited
};

State::State(int selfId, int targetId)
{	//NOTE: the agentId and targetId arguments are ints here as a place holder, they should be an agent and player objects

	self = selfId;
	target =  targetId;
}

void State::enter()
{
	// do any set up required for this state
}

void State::enact()
{
	// perform the actions that this state performs
}

void State::exit()
{
	// perform any teardown required for this state
}
