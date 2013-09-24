#include "AISystem.h"

AISystem::AISystem(Agent* playerAgent)
{	
	player = playerAgent;
	srand(time(NULL));
}

void AISystem::AI_Update()
{	// called during main update loop, causes all agents to update
	if(agents.size() > 0)
	{
		// loop through all the behaviors in the agents map, and 
		for(agentIterator = agents.begin(); agentIterator != agents.end(); agentIterator++)
		{
			Behavior* currentBehavior = agentIterator->second;
			currentBehavior->assessEnvironment(player);
			currentBehavior->behave();
		}
	}
}

void AISystem::registerAgent(int agentId, Behavior* behavior)
{	// add a new agent to the AI system
	agents[agentId] = behavior;
}

void AISystem::unRegisterAgent(int agentId)
{	//remove an agent, typically because it is destoryed
	agents.erase(agentId);
}