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

Persue::Persue(Agent* currentAgent, Agent* targetAgent)
{
	self	= currentAgent;
	target	= targetAgent;
}

void Persue::enter()
{
}

void Persue::enact()
{
	float selfCurrentPosition[3] = {0.0f, 0.0f, 0.0f};
	float targetVelocity[3] = {0.0f, 0.0f, 0.0f};
	float targetCurrentPosition[3] = {0.0f, 0.0f, 0.0f};
	float targetFuturePosition[3] = {0.0f, 0.0f, 0.0f};	

	self->getPosition(selfCurrentPosition);
	target->getVelocity(targetVelocity);
	target->getPosition(targetCurrentPosition);
	target->getPosition(targetFuturePosition);	// initialize target's future position with target's current position until for loop runs

	float updateTime = 1 / 20;													// need to figure out how many updates per second????????

	// calculate the future position of target in 3D
	for (int i = 0; i <3; i++)
	{
		if (targetFuturePosition[i] == selfCurrentPosition[i]) {targetFuturePosition[i] = targetCurrentPosition[i];}
		else targetFuturePosition[i] = targetCurrentPosition[i] + targetVelocity[i] * updateTime;
	}

	Steering.Seek(self, targetFuturePosition);
}

void Persue::exit()
{
}