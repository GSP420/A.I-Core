/*
*	Persue takes a players location, predicts its position in a few frames, based on its velocity,
*	and current direction of movement and makes the enemy agent seek to that location.
*	written by Mark Kirol
*/

#include "State.h"
#include "Steering.h"

class Persue : public State
{
	private:
		Agent* self;
		Agent* target;	
	public:
		Persue(Agent*, Agent*);
		void enter();
		void enact();
		void exit();
};
