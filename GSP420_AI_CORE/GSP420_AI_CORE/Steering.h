//used for rotational calculations, mainly for 3D
#define PI ((float)3.141592654f)
#define ToRadian(degree) ((degree) * (PI / 180.0f))
#define ToDegree(radian) ((radian) * (180.0f / PI))

#include "Agent.h"

class Steering
{
public:
	static void MatchVelocity(Agent, Agent);	//use to match velocity
	static void RotationAlign(Agent, Agent);	//use to face target like a turret
	static void Seek(Agent, Agent);
	static void Seek(Agent, float[3]);
	static void Flee(Agent, Agent);
};

//match velocity to that of the target, made for 3D, can be 2D
void Steering::MatchVelocity(Agent currentAgent, Agent targetAgent)
{
	float targetVelocity[3];
	targetAgent.getVelocity(targetVelocity);
	currentAgent.setVelocity(targetVelocity);
}

//turn towards target, *****INCOMPLETE*****
void Steering::RotationAlign(Agent currentAgent, Agent targetAgent)
{
	currentAgent.setRotation(targetAgent.getOrientation() - currentAgent.getOrientation());
	//now need to put the rotation value in the range of -PI and PI
	
}

void Steering::Seek(Agent currentAgent, Agent targetAgent)
{
	float targetPosition[3];
	targetAgent.getPostion(targetPosition);
	currentAgent.setPostion(targetPosition);
}

void Steering::Seek(Agent currentAgent, float targetPosition[3])
{
	currentAgent.setPostion(targetPosition);
}

void Steering::Flee(Agent currentAgent, Agent targetAgent)
{
	float selfPosition[3];
	float playerPosition[3];

	currentAgent.getPostion(selfPosition);
	targetAgent.getPostion(playerPosition);

	bool xDirection = selfPosition[0] > playerPosition[0];
	bool yDirection = selfPosition[1] > playerPosition[1];
	bool zDirection = selfPosition[2] > playerPosition[2];

	float fleeVector[3];

	fleeVector[0] = ((xDirection) ? currentAgent[0] + 5 : currentAgent[0] - 5); 
	fleeVector[1] = ((yDirection) ? currentAgent[1] + 5 : currentAgent[1] - 5);
	fleeVector[2] = ((zDirection) ? currentAgent[2] + 5 : currentAgent[2] - 5);

	currentAgent.setPostion(fleeVector);
}

