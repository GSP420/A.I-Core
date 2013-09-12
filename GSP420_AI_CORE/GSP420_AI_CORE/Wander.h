/*
* This is a basic wandering state. the agent moves a random number of pixels
* between 1 and 10 in all directions.
*/

#include "State.h"
#include "Steering.h"

class Wander : public State
{
	private:
		Agent self;
		Agent target;
	public:
		Wander(Agent, Agent);
		void enter();
		void enact();
		void exit();
		float getRandomPosition();
};

Wander::Wander(Agent selfAgent, Agent targetAgent)
{
	self	= selfAgent;
	target	= targetAgent;	// for this state, we don't actually use the target, which is the player.
							// but it is important to use it here just as an example, because most
							// states will actually care about the player
}

void Wander::enter()
{// we won't use this, but we need to override it because it is a virtual method
}

void Wander::enact()
{
	// generate a random spot to move too
	float randomOffset[3] = {getRandomPosition(),getRandomPosition(),getRandomPosition()};

	// seek to that spot
	Steering.Seek(self,randomOffset);
}

void Wander::exit()
{// we won't use this either, but we need to override it because it is a virtual method
}

float Wander::getRandomPosition()
{
	// get a random offset from 1 to 10 and then randmoly make it negative or positive
	return (float)(rand() % 10 + 1) * (((rand() % 2) > 0) ? 1 : -1);
}