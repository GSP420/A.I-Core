/*
* this is a placeholed agent class. The main core should use this, or provide us with one
* that has the same functionality. 
*/

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
