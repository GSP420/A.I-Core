#include "Evade.h"
#include <stdlib.h> 

Wander::Wander(Agent* selfAgent, Agent* targetAgent)
{
	self	= selfAgent;
	target	= targetAgent;
}

void Wander::enter()
{
}

void Wander::enact()
{
	Steering.Flee(self, target);
}

void Wander::exit()
{
}

