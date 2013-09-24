#include "State.h"
#include "Steering.h"

class Wander : public State
{
	private:
		Agent* self;
		Agent* target;
	public:
		Wander(Agent*, Agent*);
		void enter();
		void enact();
		void exit();
		float getRandomPosition();
};