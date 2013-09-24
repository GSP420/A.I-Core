#include "AISystem.h"

void main()
{
	Agent player = Agent();	// player object
	Agent enemy = Agent();	// enemy object

	AISystem ai_sys = AISystem(&player);	// init AI subsystem

	GenericEnemy behavior = GenericEnemy(&enemy);	// create the behavior for the enemy
	ai_sys.registerAgent(0,(Behavior*)&behavior);	// register the behavior

	// run a couple of updates, to make sure it is all working
	ai_sys.AI_Update();
	ai_sys.AI_Update();
	ai_sys.AI_Update();
}