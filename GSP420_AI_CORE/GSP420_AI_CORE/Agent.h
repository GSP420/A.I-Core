/*
* this is a placeholed agent class. The main core should use this, or provide us with one
* that has the same functionality. 
*/

#include <iostream>
using namespace std;

class Agent
{
	private:
		float orientation;
		float rotation;
		float position[3];	//made for 3D, can be 2D
		float velocity[3];	//made for 3D, can be 2D
	public:
		Agent();
		float getOrientation();
		float getRotation();
		void setRotation(float);
		void getPosition(float[3]);
		void setPosition(float[3]);
		void getVelocity(float[3]);
		void setVelocity(float[3]);
		
};

Agent::Agent()
{
	orientation = 0;
	rotation = 0;

	position[0] = 0;
	position[1] = 0;
	position[2] = 0;

	velocity[0] = 0;
	velocity[1] = 0;
	velocity[2] = 0;
}

float Agent::getOrientation()
{
	return orientation;
}

float Agent::getRotation()
{
	return rotation;
}

void Agent::setRotation(float source)
{
	rotation = source;
}

void Agent::getPosition(float destination[3])
{
	destination[0] = position[0];
	destination[1] = position[1];
	destination[2] = position[2];
}

void Agent::setPosition(float source[3])
{
	position[0] = source[0];
	position[1] = source[1];
	position[2] = source[2];
}

void Agent::getVelocity(float destination[3])
{
	destination[0] = velocity[0];
	destination[1] = velocity[1];
	destination[2] = velocity[2];
}

void Agent::setVelocity(float source[3])
{
	velocity[0] = source[0];
	velocity[1] = source[1];
	velocity[2] = source[2];
}