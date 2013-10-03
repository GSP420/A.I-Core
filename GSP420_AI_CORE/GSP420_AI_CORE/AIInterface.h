//#include"ICore.h"
#include"AISystem.h"
#include"Agent.h"



class AIInterface
{
public:
	void Startup(Agent* player);
	void Update();
	void Shutdown();
private:
	static AISystem*	AI;
}

void AIInterface::Startup(Agent* player)
{
	AI = new AISystem(player);	
}

void AIInterface::Update()
{
	AI->AI_Update();
}

void AIInterface::Shutdown()
{

}