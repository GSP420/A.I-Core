//used for rotational calculations, mainly for 3D
#define PI ((float)3.141592654f)
#define ToRadian(degree) ((degree) * (PI / 180.0f))
#define ToDegree(radian) ((radian) * (180.0f / PI))

//an example of the data structure we need to perform steering
struct Kinematics
{
	float orientation;
	float rotation;
	float postion[3];//made for 3D, can be 2D
	float velocity[3];//made for 3D, can be 2D
}

class Steering
{
private:
	Kinematics targetAgent;	//object we perform steering operations in accordance too
	Kinematics currAgent;	//object we are steering
public:
	void MatchVelocity();	//use to match velocity
	void RotationAlign();	//use to face target like a turret
}

//match velocity to that of the target, made for 3D, can be 2D
void Steering::MatchVelocity()
{
	currAgent.velocity[0] = targetAgent.velocity[0];
	currAgent.velocity[1] = targetAgent.velocity[1];
	currAgent.velocity[2] = targetAgent.velocity[2];
}

//turn towards target, *****INCOMPLETE*****
void Steering::RotationAlign()
{
	currAgent.rotation = targetAgent.orientation - currAgent.orientation;
	//now need to put the rotation value in the range of -PI and PI
	
}

