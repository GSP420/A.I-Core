/*
*	This is the main class for the AI Core. As enemies (or other agents) are instantiated
*	in the main game loop, a distinct behavior object is created for each one and then
*	registered with this object. Also, when this AISystem object is instantiated, it will
*	take a reference to the player that it can use to help the agents make judgments about
*	what actions to take and what states to be in.
*
*	Author: Stephen Roebuck
*/
#include <list>
#include <vector>
#include <iostream>
#include <hash_map>

#include "Behavior.h"

using namespace std;
using namespace stdext;

class AISystem
{
	private:
		int player;
		hash_map<string, Behavior> agents;					// a list of registered behaviors for
		hash_map<string, Behavior>::iterator agentIterator;	// list iterator
	public:
		AISystem(int);							// constructor
		void AI_Update();						// called to update all agents
		void registerAgent(string, Behavior);	// register an agent with the AI system
		void unRegisterAgent(string);			// remove an agent from the AI system
};

AISystem::AISystem(int playerId)
{	//NOTE: the playerId argument is an int here as a place holder, it should be an actual player object

	player = playerId;
}

void AISystem::AI_Update()
{	// called during main update loop, causes all agents to update
	if(agents.size() > 0)
	{
		// loop through all the behaviors in the agents map, and 
		for(agentIterator = agents.begin(); agentIterator != agents.end(); agentIterator++)
		{
			Behavior currentBehavior = agentIterator->second;
			currentBehavior.assessEnvironment(id);
			currentBehavior.behave();
		}
	}
}

void AISystem::registerAgent(string agentId, Behavior behavior)
{	// add a new agent to the AI system
	agents[agentId] = behavior;
}

void AISystem::unRegisterAgent(string agentId)
{	//remove an agent, typically because it is destoryed
	agents.erase(agentId);
}

