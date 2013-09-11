//used for rotational calculations, mainly for 3D
#define PI ((float)3.141592654f)
#define ToRadian(degree) ((degree) * (PI / 180.0f))
#define ToDegree(radian) ((radian) * (180.0f / PI))

//an example of the data structure we need to perform steering
struct Kinematics
{
	float orientation;
	float rotation;
	float position[3];//made for 3D, can be 2D
	float velocity[3];//made for 3D, can be 2D
}

class Steering
{
private:
	Kinematics targetAgent;	//object we perform steering operations in accordance too
	Kinematics currentAgent;	//object we are steering
public:
	void MatchVelocity();	//use to match velocity
	void RotationAlign();	//use to face target like a turret
	void Seek();
	void Flee();
}

//match velocity to that of the target, made for 3D, can be 2D
void Steering::MatchVelocity()
{
	currentAgent.velocity[0] = targetAgent.velocity[0];
	currentAgent.velocity[1] = targetAgent.velocity[1];
	currentAgent.velocity[2] = targetAgent.velocity[2];
}

//turn towards target, *****INCOMPLETE*****
void Steering::RotationAlign()
{
	currentAgent.rotation = targetAgent.orientation - currentAgent.orientation;
	//now need to put the rotation value in the range of -PI and PI
	
}

void Steering::Seek()
{

	bool xDirection = currentAgent.position[0] > targetAgent.position[0];
	bool yDirection = currentAgent.position[1] > targetAgent.position[1];
	bool zDirection = currentAgent.position[2] > targetAgent.position[2];

	((xDirection) ? currentAgent.position[0]-- : currentAgent.position[0]++); 
	((yDirection) ? currentAgent.position[1]-- : currentAgent.position[1]++);
	((zDirection) ? currentAgent.position[2]-- : currentAgent.position[2]++);
}

void Steering::Flee()
{

	bool xDirection = currentAgent.position[0] > targetAgent.position[0];
	bool yDirection = currentAgent.position[1] > targetAgent.position[1];
	bool zDirection = currentAgent.position[2] > targetAgent.position[2];

	((xDirection) ? currentAgent.position[0]++ : currentAgent.position[0]--); 
	((yDirection) ? currentAgent.position[1]++ : currentAgent.position[1]--);
	((zDirection) ? currentAgent.position[2]++ : currentAgent.position[2]--);
}

