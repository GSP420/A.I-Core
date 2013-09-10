#define PI ((float)3.141592654f)
#define ToRadian(degree) ((degree) * (PI / 180.0f))
#define ToDegree(radian) ((radian) * (180.0f / PI))

struct Kinematics
{
	float orientation;
	float rotation;
	float postion[3];
	float velocity[3];
}

class Steering
{
private:
	Kinematics targetAgent;
	Kinematics currAgent;
public:
	void MatchVelocity();
	void RotationAlign();
}

void Steering::MatchVelocity()
{
	currAgent.velocity[0] = targetAgent.velocity[0];
	currAgent.velocity[1] = targetAgent.velocity[1];
	currAgent.velocity[2] = targetAgent.velocity[2];
}

void Steering::RotationAlign()
{
	currAgent.rotation = targetAgent.orientation - currAgent.orientation;
	
}

