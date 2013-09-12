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
	public:
		virtual void enter();	// called when this state is being entered
		virtual void enact();	// behave according to the current state
		virtual void exit();	// called when this state is being exited
};